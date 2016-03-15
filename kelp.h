//  kelp.h
//  ENGS 65 Final Project

#ifndef KELP_H
#define KELP_H


#include <iostream>
#include "species.h"
#include "shockfactors.h"

using namespace std;


class kelp_spec: public Species {
public:
    
    
    // Calculate new growth rate r, based on sea level (system shock)
    void changeGrowth(ShockFactors &shocks);

    
    // Kelp population parameters
    //nutrient uptake constant?
    const float K = 100000;             // carrying capacity of kelp population
    const float Puk = 0.001;            // rate of getting eaten by sea urchins
    float r;                            // intrinsic growth rate
    
    void print();
    
    // Constructor
    kelp_spec(float biomass)
    : Species(biomass) {
        r = 0.45;
    };
    
    // Calculate population
    float calcDeriv(Species &urch);
    
    
};

    /*
     using namespace std;
     
     float sealevel;
     float irradiance_change;
     float r_temp;
     solutes temp;
     
     Kelp population growth equation  (time derivative)
     
     float kelp_spec::calcDeriv(Species &urch) {
     r_temp = r;
     
     sealevel = temp.get_sealevel() + 400;           // in cm
     irradiance_change = exp(0.035*sealevel);
     r = irradiance_change*r_temp;
     
     dNdt = (r * N * (1 - (N/K))) - (Puk * N * urch.N);
     return dNdt;
     } */


#endif







