//  urchins.h
//  ENGS 65 Final Project


#include <iostream>
#include "species.h"
using namespace std;



class urchin_spec: public Species {

public:
    
    // Sea urchin population parameters
    float bu;                            // efficiency of prey to new offspring
    float Pou;                           // rate of getting eaten by otters)
    float du;                            // natural death rate of urchins
    
    // Constructor
    urchin_spec(float biomass, float a, float b, float c): Species(biomass), bu(a), Pou(b), du(c) {}
    
    // Calculate dNdt
    float calcDeriv(Species &kelp, Species &otter);
    
};

