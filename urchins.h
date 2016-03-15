//  urchins.h
//  ENGS 65 Final Project


#ifndef URCHINS_H
#define URCHINS_H


#include <iostream>
#include "species.h"
using namespace std;



class urchin_spec: public Species {

public:
    
    // Sea urchin population parameters
    const float bu = 0.001;              // efficiency of prey to new offspring
    const float Pou = 0.01;              // rate of getting eaten by otters)
    float du;                            // natural death rate of urchins
    
    void print();
    
    // Constructor
    urchin_spec(float biomass): Species(biomass) {
        du = 0.01;
    }
    
    // Calculate dNdt
    float calcDeriv(Species &kelp, Species &otter);
    
};


#endif