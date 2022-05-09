#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#ifndef __PARTICULELIST__HPP
#define __PARTICULELIST__HPP

class ParticuleList {

    private :

        glm::vec2 _initPos;
        int _nbParticules;
        int _nbAlive;
        std::vector<Particule> _tab;
        bool _state = true;
        
    public :

        ParticuleList(const glm::vec2 &initPos, const int nbParticules, const float angle);

        void loopList(p6::Context &ctx);

        int getNbAlive();

        bool getState();

        glm::vec2 getInitPos();

        void printList();

        Particule *getParticule(const int index);
};   

#endif