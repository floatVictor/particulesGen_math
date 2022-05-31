#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "PerlinNoise.hpp"

#ifndef WORLD_H
#define WORLD_H

extern int FRAMECOUNT;

extern float SIZERATIO;
extern int NBLIST;
extern int NBPARTICULE;
extern float INITANGLE;

extern float HEIGHTRATIO;
extern float INITSMOOTHRATIO;
extern float INITNOISERATIO;
extern float INITNOISESIZE;

extern siv::PerlinNoise::seed_type seed;
extern siv::PerlinNoise perlin;

extern float POISSON_LAMBDA;
extern float BERNOUILLI_P;
extern float GEOMETRIC_P;
extern float BINO_P; 
extern int BINO_N;

extern float BERNOUILLI_AMP;
extern float GEOMETRIC_AMP;

extern float UNIFORM_AMP;
#endif