#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

#include "../include/mathProbabilitiesLib.hpp"

// -------- Math utilities -------------

long factorial(const int n){
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}

int binomialCoefficient(int n, int k){
   if(k == 0 || k == n)
   return 1;
   return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}


// ---------- Probability distributions -----------

// Basic random number generator, between 0 and 1 (prerequisite)
double sampleRandomBetweenZeroAndOne(){
    // std::random_device rd; // obtain a random number from hardware
    // std::mt19937 gen(rd()); // seed the generator
    // std::uniform_real_distribution<> distr(0., 1.); // define the range
    // return distr(gen); // generate numbers
    return float(rand()%10000) / 10000;
} 

// Uniform CONTINUOUS generator
float sampleUniformContinuous(float min, float max){
    return sampleRandomBetweenZeroAndOne() * (max - min) + min;
} 

// Poisson
float poisson(float lambda, float k){ // probability P(X=k)
    return exp(-lambda) * pow(lambda,k)/factorial(k);
}

float samplePoisson(float lambda){ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    double k = 0;

    while(i <= randNb){
        i += poisson(lambda, k);
        k += 1;
    }

    return k;
}

// Bernoulli
int sampleBernoulli(float p){
    double randNb = sampleRandomBetweenZeroAndOne();
    if(randNb <= p){
        return 1;
    }
    return 0;
}

// Geometric
float geometric(float p, float k){ // probability P(X=k)
    return p * (pow(1-p, k-1));
}

float sampleGeometric(float p){ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    double k = 1;

    while(i <= randNb){
        i += geometric(p, k);   
        k += 1;
    }

    return k;
}

// Binomial
float binomial(int n, float p, int k){ // probability P(X=k)
    return binomialCoefficient(n,k) * pow(p,k) * pow(1-p, n-k);
}

int sampleBinomial(int n, float p){ // sample generator
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    int k = 0;

    while(i <= randNb && k < n){
        i += binomial(n, p, k);
        k += 1;
    }

    return k;
}


// TESTS
// g++ mathProbabilitiesLib.cpp -o testsProbas2.exe
// .\testsProbas2.exe
/*
int main(){
    std::cout << "uniforme entre 0 et 1 : " << sampleRandomBetweenZeroAndOne() << std::endl;
    std::cout << "uniforme entre 2 et 5 : " << sampleUniformContinuous(2,5) << std::endl;
    std::cout << "Poisson de param lambda = 9,2 : " << samplePoisson(9.2) << std::endl;
    std::cout << "Bernoulli de param p = 0,2 : " << sampleBernoulli(0.2) << std::endl;
    std::cout << "Geometrique de param p = 0,2 : " << sampleGeometric(0.2) << std::endl;
    std::cout << "Binomiale de params p = 0,2 et n = 20 : " << sampleBinomial(20, 0.2) << std::endl;
}
*/