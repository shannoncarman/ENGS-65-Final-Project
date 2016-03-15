//  species.cpp
//  ENGS 65 Final Project
//
//  Created by Shannon Carman on 2/28/16.
//  Copyright (c) 2016 Shannon Carman. All rights reserved.
//


#include <iostream>
#include "species.h"
using namespace std;


// Species class constructor
Species::Species(float pop) {
    N = pop;                                // initial population
    dNdt = 0;                               // initialize derivative to 0
}

// Calculate new population after 1 time step (6 months)
float Species:: updatePopulation() {
    N += dNdt*t_step;
    if (N<0) {
        N = 0;
    }
    return N;
}

// Return species population
float Species::getPopulation() {
    return N;
}

// Return species population time derivative
float Species::getDeriv() {
    return dNdt;
}











