#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <p6/p6.h>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "PerlinNoise.hpp"
#include "World.hpp"
#include "worldVar.hpp"

int FRAMECOUNT = rand()%100;

const int NBLIST = 200;
const int NBPARTICULE = 30;
const float INITANGLE = 30;

const float HEIGHTRATIO = 0.00001;
const float INITSMOOTHRATIO = 0.00003;
const float INITNOISERATIO = 0.005;
const float INITNOISESIZE = 0.08;

const siv::PerlinNoise::seed_type seed = float(rand())/float((RAND_MAX)) * 2000;
const siv::PerlinNoise perlin{ seed };

int main() {

    //----------------SETUP---------------//
    auto ctx = p6::Context{{1920,1080, "My p6 project"}}; // Create a context with a window
    ctx.background({0});
    ctx.set_time_mode_fixedstep(6000);
    World w = World();
    //ParticuleList list = ParticuleList(glm::vec2(float(rand())/float((RAND_MAX)) * 2 - 1,(float(rand())/float((RAND_MAX)) -0.5)),50, 90);

    //----------------DRAW----------------//
    ctx.update = [&]() {

        if(w.getState()){
            w.loopWorld(ctx);
        }
        else std::cout << "end" << std::endl;

        FRAMECOUNT++;
        srand(FRAMECOUNT);
    };

    ctx.start(); 
}
    /*
    ctx.update = [&]() {
        if(list.getState()) {
            list.updateDisplayList(ctx);
            //if (FRAMECOUNT%10 == 0) list.printList();
        }
        else {
            list = ParticuleList(glm::vec2(float(rand())/float((RAND_MAX)) * 2 - 1,(float(rand())/float((RAND_MAX)) -0.5)),50, 90);
        }
        
        if (FRAMECOUNT%50 == 0) std::srand(FRAMECOUNT);
        FRAMECOUNT++;
        //std::cout << float(rand())/float((RAND_MAX)) * 2 << std::endl;
        //std::cout << perlin.octave2D_01((FRAMECOUNT * 0.01), (0 * 0.01), 4) << std::endl;
        srand(FRAMECOUNT);

        // ctx.mouse_pressed = [&](p6::MouseButton button) {
        // const auto color = ctx.read_pixel(button.position);
        // std::cout << std::to_string(color.r()) << " "
        //           << std::to_string(color.g()) << " "
        //           << std::to_string(color.b()) << " "
        //           << std::to_string(color.a()) << " "
        //           << "\n";
        // };
    };

    ctx.start();                                          // Start the p6 application
}*/
