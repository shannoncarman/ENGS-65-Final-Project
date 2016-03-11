//  kelp.cpp
//  ENGS 65 Final Project


#include <iostream>
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"
using namespace std;



// Kelp population growth equation  (time derivative)

float kelp_spec::calcDeriv(Species &urch) {
    
    dNdt = (r * N * (1 - (N/K))) - (Puk * N * urch.N);
    return dNdt;
}


// r = natural growth rate of kelp
// N = kelp population
// K = kelp carrying capacity of the community (logistic growth)
// Puk = rate at which kelp is eaten by sea urchins
// urch.N = sea urchin population