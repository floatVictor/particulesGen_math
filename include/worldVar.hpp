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
extern const int NBLIST;
extern const int NBPARTICULE;
extern const float INITANGLE;

extern const float HEIGHTRATIO;
extern const float INITSMOOTHRATIO;
extern const float INITNOISERATIO;
extern const float INITNOISESIZE;

extern const siv::PerlinNoise::seed_type seed;
extern const siv::PerlinNoise perlin;

#endif