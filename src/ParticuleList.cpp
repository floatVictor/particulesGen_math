#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iterator>
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"

extern int FRAMECOUNT;

ParticuleList::ParticuleList(const glm::vec2 &initPos, const int nbParticules, const float angle){
    _initPos = initPos;
    _nbParticules = nbParticules;

    for (int i = 0; i < nbParticules; i++){
        _tab.push_back(Particule(initPos, angle));
    }
    std::cout << "new list created" << std::endl;
    std::cout << "initPos : " << _initPos[0] << ";" << _initPos[1] << std::endl;
}

void ParticuleList::loopList(p6::Context &ctx){
    for (Particule &p : _tab){
        p.updateParticule();
        p.displayParticule(ctx);
    }
}

int ParticuleList::getNbAlive(){
    int temp = 0;
    for (Particule p : _tab){
        if (p.getState()) temp++;
    }
    _nbAlive = temp;
    return _nbAlive;
}

bool ParticuleList::getState(){
    if (getNbAlive() <= 0) {
        _state = false;
        std::cout << "list is dead" << std::endl;
    }
    return _state;
}

glm::vec2 ParticuleList::getInitPos() { return glm::vec2(_initPos[0], _initPos[1]);}

void ParticuleList::printList(){
    std::cout << "nbAlive : " << getNbAlive() << std::endl << std::endl;
}

Particule *ParticuleList::getParticule(const int index){
    return &_tab[index];
}