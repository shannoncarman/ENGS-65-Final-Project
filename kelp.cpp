//  kelp.cpp
//  ENGS 65 Final Project


#include <iostream>
#include <cmath>
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"
#include "shockfactors.h"
using namespace std;



// Kelp population growth equation  (time derivative)

float kelp_spec::calcDeriv(Species &urch) {
    
    dNdt = (r * N * (1 - (N/K))) - (Puk * N * urch.N);
    return dNdt;
}


void kelp_spec::print() {
    cout << "Kelp population\n\n";
    cout << "N: " << N << endl;
    cout << "Growth parameters:\n";
    cout << "Natural growth rate, r = " << r << endl;
    cout << "Carrying capacity, K = : " << K << endl;
    cout << "Rate kelp eaten by urchins, Puk: " << Puk << endl;
}

// r = natural growth rate of kelp
// N = kelp population
// K = kelp carrying capacity of the community (logistic growth)
// Puk = rate at which kelp is eaten by sea urchins
// urch.N = sea urchin population

void kelp_spec::changeGrowth(ShockFactors &shocks) {
    float r_temp = r;
    float sealevel = shocks.getIRratio();
    float irradiance_change = exp(0.035*sealevel);
    r = r_temp * irradiance_change;
    cout << "r changed " << r << endl;
    
}

