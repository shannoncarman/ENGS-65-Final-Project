// species.cpp
//  Final Project
//
//  Created by Shannon Carman on 2/28/16.
//  Copyright (c) 2016 Shannon Carman. All rights reserved.
//


#include <iostream>
#include "species.h"
using namespace std;

//////////////////////////////////////////////////
///           General species functions        ///
//////////////////////////////////////////////////
Species::Species(float pop) {        // Species class constructor
    N = pop;                                    // assign initial biomass
    dNdt = 0;                                       // assign initial derivative
}

void Species:: updatePopulation() {                    // calculate new population after 1 time step (6 months)
    N = N + dNdt*t_step;
}

float Species::getPopulation() {                       // return species population
    return N;
}

float Species::getDeriv() {                         // return species population time derivative
    return dNdt;
}

void Species::print() {
    cout << "N: " << N << "  dNdt: " << dNdt << endl;
}


//////////////////////////////////////////////////
///              Kelp functions                ///
//////////////////////////////////////////////////


// Kelp growth equation (derivative)
void kelp_spec::calcDeriv(float old_urch_N) {

   dNdt = (r * N * (1 - (N/K))) - (Puk * N * old_urch_N);
}

//////////////////////////////////////////////////
///            Sea urchin functions            ///
//////////////////////////////////////////////////

// Urchin growth equation (derivative)
void urchin_spec::calcDeriv(float old_kelp_N, float old_otter_N) {
    
    dNdt = -(du * N) + (bu * N * old_kelp_N) - (Pou * N * old_otter_N);     //********** change this to only juvenile + adult N
}


// Get sea urchin population
float urchin_spec::getPopulation() {
    return population;
}



//////////////////////////////////////////////////
///            Sea otter functions             ///
//////////////////////////////////////////////////


/////// Juvenile AgeQueue fuctions ///////////////

otter_spec::AgeQueue::AgeQueue() {

    front = 4;
    back = 0;
}

float otter_spec::AgeQueue::shift(float pup_pop) {
    
    float new_adults = age_group[front];                // store front value - goes to adult population
//    cout << "new adult pop: " << new_adults << endl;

    back = front;                   // shift back index to recently 'freed' space
    
    if (front == 0) {               // move front index back, circular
        front = 4;
    }
    else {
        front -=1;
    }
    
    age_group[back] = pup_pop;      // insert value from pup population into the back of the queue
    
    return new_adults;
}

float otter_spec::AgeQueue::sum() {
    
    float juv_sum;
    for (int i=0; i<5; i++) {
        juv_sum += age_group[i];
        i++;
    };
    
    return juv_sum;
}


// Otter class constructor

otter_spec::otter_spec(float pop, float a, float b): Species(pop), bo(a), dott(b) {
    total_pop = pop;
    pup_pop = 0.25*total_pop;
    ad_pop = 0.50*total_pop;
    int i=0;
    while (i<5) {
        juv_pop.shift(0.05*total_pop);
        i++;
    }

}

// Calculate derivative of pup population
float otter_spec::calcPupDeriv(float old_urch_N, float old_adult_N) {
    
    return dNdt = bo * old_urch_N * old_adult_N;
    
};


// Calculate derivative of adult population
float otter_spec::calcAdultDeriv(float old_adult_N) {
    
    return dNdt = -dott * old_adult_N;
    
};


// Calculate all pup, juvenile, adult, and total populations
float otter_spec::updatePopulations() {
    
    float pup_change = pup_deriv*t_step;
    pup_pop += pup_change;
    float new_adults = juv_pop.shift(pup_change);
    ad_pop += (new_adults + (ad_deriv*t_step));
    
    return total_pop = pup_pop + juv_pop.sum() + ad_pop;
    
};


float otter_spec::getTotalPop() {
    return total_pop;
};














