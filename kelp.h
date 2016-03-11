//  kelp.h
//  ENGS 65 Final Project


#include <iostream>
#include "species.h"

using namespace std;


class kelp_spec: public Species {
public:
    
    // Kelp population parameters
    //nutrient uptake constant?
    float K;                            // carrying capacity of kelp population
    float r;                            // intrinsic growth rate
    float Puk;                          // rate of getting eaten by sea urchins
    
    // Constructor
    kelp_spec(float biomass, float a, float b, float c)
    : Species(biomass), K(a), r(b), Puk(c) {};
    
    // Calculate dNdt
    float calcDeriv(Species &urch);

};
