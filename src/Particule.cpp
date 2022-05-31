#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "PerlinNoise.hpp"
#include "worldVar.hpp"

Particule::Particule(){};

Particule::Particule(int index, const glm::vec2 &pos, const float angle) {
    _index = index;
    _pos = pos;
    _angle = angle;
    if (rand() % 100 > 50) _angle += 180;
}

//Basic functions

void Particule::updateParticule() {
    _pos[0] += cos(glm::radians(_angle)) * _speed;
    _pos[1] += sin(glm::radians(_angle)) * _speed;

    _life -= _lifeIterator;
    if(_life < 0) _state = false;

    _angle += (sampleBernoulli(BERNOUILLI_P)) * BERNOUILLI_AMP;
    _angle += (sampleGeometric(GEOMETRIC_P) - 0.5) * GEOMETRIC_AMP;

    _pos[0] += sampleUniformContinuous(-UNIFORM_AMP, UNIFORM_AMP);
    _pos[1] += sampleUniformContinuous(-UNIFORM_AMP, UNIFORM_AMP);

    if(sampleBinomial(BINO_P, BINO_N)) {
        if(sampleBinomial(BINO_P, BINO_N)) _size++;
        else _size--;
    }
        
}

void Particule::displayParticule(p6::Context &ctx) {
    ctx.use_stroke = false;

    ctx.fill = p6::Color{1, 1, 1, float(_life * 0.25)};
    if (rand() % 100 > 75) 
        ctx.fill = p6::Color{0, 0, 1};

    ctx.circle(p6::Center(_pos[0] + 2 * _size, _pos[1]), _size);
    
    ctx.fill = p6::Color{0, 0, 0, float(_life * 0.18)};
    ctx.use_fill = true;

    ctx.circle(p6::Center(_pos), _size);
}

void Particule::printParticule() {
    std::cout << "INDEX : " << _index << std::endl
              << "POS : " << _pos[0] << ";" << _pos[1] << std::endl
              << "SIZE : " << _size
              << "| SPEED : " << _speed
              << "| ANGLE : " << _angle << std::endl
              << "LIFE : " << _life << std::endl << std::endl;
}

bool Particule::getState(){return _state;}

//Event functions

// void Particule::timedEvent() {
//     if(sampleUniformContinuous(0, 100) < 76) _angle -= _timedEventAngle;
//     _timedEventAngle = 180 - _timedEventAngle;
// }

// void Particule::noiseEvent() {
//     _pos[0] += (perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT * _noiseSize)) * _noiseRatio;
//     _pos[1] += (perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT * _noiseSize + 10000)) *_noiseRatio;
//     //_angle += perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT*10) * 25;
//     //std::cout << perlin.noise2D(_pos[0], FRAMECOUNT * _noiseSize) * _noiseRatio << std::endl;
// }

// void Particule::sizeEvent() {
//     if (_sizeEventGo) _size += _sizeEventSize;
//     else _size -= _sizeEventSize;
//     if(perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT) *10> 0.6) {
//         if (perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT) *10 > 0) _sizeEventSize += _sizeEventSize;
//         else _sizeEventSize -= _sizeEventSize;
//     }
// }

// void Particule::updateParticule() {

//     _pos[0] += cos(glm::radians(_angle)) * _speed;
//     _pos[1] += sin(glm::radians(_angle)) * _speed;

//     _life -= _lifeIterator;
//     if(_life < 0) _state = false;

//     if(FRAMECOUNT % _timedEventTime == 0) { 
//         timedEvent();
//         _noiseEventGo = !_noiseEventGo;
//     }

//     else if (rand() % 100 < _timedEventLuck) { 
//         timedEvent();
//         _noiseEventGo = !_noiseEventGo;
//     }

//     if (_noiseEventGo) noiseEvent();

//     if (FRAMECOUNT % _sizeEventTime == 0) {
//         if (rand() % 100 < _sizeEventLuck) {
//             _sizeEventGo = !_sizeEventGo;
//             sizeEvent();
//         }
//     }

//     _noiseSize += perlin.noise1D(FRAMECOUNT * _noiseRatio) * 0.001; //extra shit
//     _noiseRatio += perlin.noise1D(FRAMECOUNT * _noiseSize) * 0.001;
//     //std::cout << perlin.noise3D(_pos[0], _pos[1], FRAMECOUNT) << std::endl;
// }