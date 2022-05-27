//#include "../include/mathProbabilitiesLib.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

//DEBUG
#include <iostream>

// Math utilities

long factorial(const int n){
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}



// ---------- Probability distributions -----------
// Functions to calculate P(X = k) or to sample from the distributions

// Basic random number generator, between 0 and 1 (prerequisite)
double sampleRandomBetweenZeroAndOne(){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0., 1.); // define the range
    return distr(gen); // generate numbers
}

// Uniform generator
float sampleUniformContinuous(float min, float max){
    return sampleRandomBetweenZeroAndOne() * (max - min) + min;
}

// Poisson probability
float poisson(float lambda, float k){
    float Sum_ln_k = 0;
    for(int i=0; i<k; i++){
        Sum_ln_k += log(k);
    }

    float X = ((exp(-lambda))*(pow(lambda,k)))/factorial(k);
    float lnX = -lambda + k*log(lambda) - Sum_ln_k;
    return exp(X);
}

// Poisson probability v2
float poisson_v2(float lambda, float k){
    return exp(-lambda) * pow(lambda,k)/factorial(k);
}

// Poisson generator DISCRETE
float samplePoisson(float lambda){
    double randNb = sampleRandomBetweenZeroAndOne();
    double i = 0;
    double k = 0;

    while(i <= randNb){
        i += poisson_v2(lambda, k);
        k += 1;
    }

    return k;
}

// TESTS
// g++ mathProbabilitiesLib.cpp -o testsProbas2.exe
// .\testsProbas2.exe
int main(){
    std::cout << "uniforme entre 0 et 1 : " << sampleRandomBetweenZeroAndOne() << std::endl;
    std::cout << "uniforme entre 2 et 5 : " << sampleUniformContinuous(2,5) << std::endl;
    std::cout << "Poisson de param lambda = 9,2 : " << samplePoisson(9.2) << std::endl;
}