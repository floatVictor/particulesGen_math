#include <iostream>
#include <vector>
#include <stdio.h>
#include <p6/p6.h>
#include <map>

#include "Particule.hpp"
#include "ParticuleList.hpp"
#include "PerlinNoise.hpp"
#include "World.hpp"
#include "worldVar.hpp"
#include "../include/mathProbabilitiesLib.hpp"

int FRAMECOUNT = 0;

int NBLIST = 200;
int NBPARTICULE = 30;
float INITANGLE = sampleUniformContinuous(0, 360);

float HEIGHTRATIO = 0.00001;
float INITSMOOTHRATIO = 0.00003;
float INITNOISERATIO = 0.003;
float INITNOISESIZE = 0.002;

siv::PerlinNoise::seed_type seed = sampleUniformContinuous(0, 1000);
siv::PerlinNoise perlin{ seed };

float POISSON_LAMBDA = 9.2;
float BERNOUILLI_P = 0.2; 
float GEOMETRIC_P = 0.2;
float BINO_P = 0.2;
int BINO_N = 20;

float BERNOUILLI_AMP = 0.1;
float GEOMETRIC_AMP  = -0.02;

float UNIFORM_AMP = 0;

int main() {

    //----------------SETUP---------------//
    
    //srand(time(NULL));
    auto ctx = p6::Context{{1920,1080, "My p6 project"}}; // Create a context with a window
    ctx.background({0});
    ctx.framerate_as_high_as_possible();
    World w = World();


    //----------------DRAW----------------//
    //for(int i = 0;i<15;i++) std::cout << sampleRandomBetweenZeroAndOne() << std::endl;
    ctx.update = [&]() {

        if(w.getState()){
            w.loopWorld(ctx);
        }
        else std::cout << "end" << std::endl;

        // FRAMECOUNT++;
        // std::cout << sampleRandomBetweenZeroAndOne() << std::endl;
        // std::cout << "uniforme entre 0 et 1 : " << sampleRandomBetweenZeroAndOne() << std::endl;
        // std::cout << "uniforme entre 2 et 5 : " << sampleUniformContinuous(2,5) << std::endl;
        // std::cout << "Poisson de param lambda = 9,2 : " << samplePoisson(9.2) << std::endl;
        // std::cout << "Bernoulli de param p = 0,2 : " << sampleBernoulli(0.2) << std::endl;
        // std::cout << "Geometrique de param p = 0,2 : " << sampleGeometric(0.2) << std::endl;
        // std::cout << "Binomiale de params p = 0,2 et n = 20 : " << sampleBinomial(20, 0.2) << std::endl;

    };

    ctx.imgui = [&](){
        ImGui::Begin("infos");
        ImGui::Text("frameRate : %d", ctx.delta_time() * 1000.f);
        ImGui::Text("particule count : %d", w.getParticuleList().getNbAlive());
        ImGui::End();
        ImGui::Begin("probaControls");
        ImGui::SliderFloat("uniform amp",&UNIFORM_AMP, -0.1, 0.1);
        ImGui::SliderFloat("poisson lambda",&POISSON_LAMBDA, 0.f,20.f);
        ImGui::SliderFloat("bernouilli p",&BERNOUILLI_P, 0.f,1.f);
        ImGui::SliderFloat("bernouilli amp",&BERNOUILLI_AMP, -1.f,1.f);
        ImGui::SliderFloat("geometric p",&GEOMETRIC_P, 0.01f,1.f);
        ImGui::SliderFloat("geometric amp",&GEOMETRIC_AMP, -.3,.3);
        ImGui::SliderFloat("binomial p",&BINO_P, 0.f,1.f);
        ImGui::SliderInt("binomial p",&BINO_N, 5, 30);
        ImGui::End();
    };

    ctx.start(); 
}
