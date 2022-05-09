#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "worldVar.hpp"
#include "World.hpp"

World::World() {

    _initPos = _current.getInitPos();
}
        
void World::loopWorld(p6::Context &ctx) {

    if(!_current.getState()){
        updateVar();
        _current = ParticuleList(_initPos, _nbParticule, _initAngle);
        _listIterator ++;
    }

    _current.loopList(ctx);
}

void World::updateVar() {

    _initPos = glm::vec2(_initPos[0] + perlin.noise1D(FRAMECOUNT * INITSMOOTHRATIO * 0.03)*0.1, _initPos[1] - _listIterator * _listIterator * _listIterator * HEIGHTRATIO - 0.008);
    if (_initPos[1] < - 1) _initPos[1] = 0;
    if (_initPos[0] > 1) _initPos[0] = -0.85;
}

bool World::getState() { return _listIterator < NBLIST;}
