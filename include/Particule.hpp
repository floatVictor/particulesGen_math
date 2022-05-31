#pragma once

#include <iostream>
#include <vector>
#include <p6/p6.h>

#include "worldVar.hpp"
#include "../include/mathProbabilitiesLib.hpp"

#ifndef __PARTICULE__HPP
#define __PARTICULE__HPP

class Particule {

    private :

        int _index;

        glm::vec2 _pos;
        float _size = 0.001;
        float _angle; //0-360
        float _speed = 0.0015;
        p6::Color _color;
        bool _state = true;
        float _life = 1;
        float _lifeIterator =  sampleUniformContinuous(0.001, 0.01); //vitesse de viellissement

        // float _timedEventAngle = 30; //angle de la mutation périodique
        // int _timedEventTime = 300;   //temps de la période
        // float _timedEventLuck = 0.01; // X% chance to trig event (every frame)

        // bool _noiseEventGo = false;
        // float _noiseRatio = INITNOISERATIO; //noise amplitutde
        // float _noiseSize = INITNOISESIZE; 

        // bool _sizeEventGo = false;
        // float _sizeEventSize = 0.002; //modulation sur la taille
        // int _sizeEventTime = 120;
        // float _sizeEventLuck = 80; // X% chance to trig event (every frame)
    
    public :

        Particule();
        Particule(int index, const glm::vec2 &pos, const float angle);

        //Basic functions
        
        void updateParticule();

        void displayParticule(p6::Context &ctx);

        void printParticule();

        bool getState();

        //event functions
        void timedEvent();

        void noiseEvent();

        void sizeEvent();
};

#endif