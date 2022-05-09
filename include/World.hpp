#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "ParticuleList.hpp"
#include "worldVar.hpp"

#ifndef __WORLD__HPP
#define __WORLD__HPP

class World {

    private :

        int _listIterator = 0;
        int _nbParticule = NBPARTICULE;
        float _initAngle = INITANGLE;

        glm::vec2 _initPos;;

        ParticuleList _current = ParticuleList(glm::vec2(0,0), NBPARTICULE, INITANGLE);
        bool _state = true;

    public : 

        World();
        
        void loopWorld(p6::Context &ctx);

        void createList();

        void updateVar();

        bool getState();

};

#endif