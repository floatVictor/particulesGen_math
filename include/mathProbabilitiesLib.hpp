// -------- Math utilities -------------

long factorial(const int n);

int binomialCoefficient(int n, int k);


// ---------- Probability distributions -----------
// Functions to calculate P(X = k) or to sample from the distributions
// Requirements: lambda > 0; p is a float between 0 and 1; n is a strictly positive integer;

// Basic random number generator, between 0 and 1 (prerequisite)
double sampleRandomBetweenZeroAndOne();

// Uniform CONTINUOUS generator
float sampleUniformContinuous(float min, float max);

// Poisson
float poisson(float lambda, float k); // probability P(X=k)
float samplePoisson(float lambda); // sample generator

// Bernoulli
int sampleBernoulli(float p);

// Geometric
float geometric(float p, float k); // probability P(X=k)
float sampleGeometric(float p); // sample generator

// Binomial
float binomial(int n, float p, int k); // probability P(X=k)
int sampleBinomial(int n, float p); // sample generator