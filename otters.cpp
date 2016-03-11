//  otters.cpp
//  ENGS 65 Final Project


#include <iostream>
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"
using namespace std;


////////////////////////////////////
//        AgeQue Funtions         //
////////////////////////////////////


// AgeQueue constructor
otter_spec::AgeQueue::AgeQueue() {
    
    front = 4;                      // initialize front index at end of array
    back = 0;                       // initialize back index at front of array
}

// AgeQue shift: models pups becoming juveniles, juveniles becoming adults
float otter_spec::AgeQueue::shift(float pup_pop) {
    
    float new_adults = age_group[front];           // oldest juveniles are "new adults"
    
    back = front;                                  // back of queue moves to 'freed' space
    if (front == 0) {                              // front of queue is now at the 2nd oldest juveniles
        front = 4;                                 // make array circular
    }
    else {
        front -=1;
    }
    
    age_group[back] = pup_pop;                     // pups inserted into back of the queue, youngest juveniles
    
    return new_adults;                             // return value originally at the front of the queue
}

// Sum all elements in queue
float otter_spec::AgeQueue::sum() {
    
    float juv_sum;
    for (int i=0; i<5; i++) {
        juv_sum += age_group[i];
    };
    
    return juv_sum;
}

// Print out juvenile populations in queue
void otter_spec::AgeQueue::print_queue() {
    cout << "Juveniles: ";
    for (int i=0; i<5; i++) {
        cout << age_group[i] << " ";
    }
    cout << '\n';
}



////////////////////////////////////
//     Otter Class Funtions       //
////////////////////////////////////


// Otter class constructor
otter_spec::otter_spec(float pop, float a, float b): Species(pop), bo(a), dott(b) {
    
    // initialize population derivatives to 0
    pup_deriv = 0;
    ad_deriv = 0;

    // initialize age distribution of otter population (pups, juveniles, adults)
    pup_N = 0.25*N;
    ad_N = 0.50*N;
    int i=0;
    while (i<5) {
        juv_queue.shift(0.05*N);
        i++;
    }
}

// Calculate derivative of pup population
float otter_spec::calcPupDeriv(Species &urch) {
    pup_deriv = bo * urch.N * ad_N;
    return pup_deriv;
    
    // bo = efficiency of converting prey (urchins) to new offspring (otters)
    // urch.N = sea urchin population
    // ad_N = population of adult otters (reproducing age cohort)
    
};


// Calculate derivative of adult population

float otter_spec::calcAdultDeriv() {
    ad_deriv= -dott * ad_N;
    return ad_deriv;
    
    // dott = natural death rate of otters (only adults)
    // ad_N = population of adult otters
};


// Calculate all pup, juvenile, adult, and total populations
float otter_spec::updatePopulation() {
    
    float new_pups = pup_deriv*t_step;              // new otters born
    float new_adults = juv_queue.shift(pup_N);      // all current pups become juveniles, oldest juveniles become newest adults

    pup_N = new_pups;                               // pup population: new births
    ad_N += (new_adults + (ad_deriv*t_step));       // adult population: add newest adults, changedue to natural deaths
    juv_N = juv_queue.sum();                        // juvenile population: sum of all queue elements
    N = pup_N + juv_N + ad_N;                       // total population is sum of all age cohorts

    return N;
};


// Print out otter population information
void otter_spec::print() {
    cout << "Total N: " << N << endl;
    cout << "Pup N: " << pup_N << "  pup dNdt: " << pup_deriv << endl;
    float juv_sum = juv_queue.sum();
    cout << "Juvenile N: " << juv_sum << endl;
    cout << "Adult N: " << ad_N << "  adult dNdt: " << ad_deriv << endl;
}




