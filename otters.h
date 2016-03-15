//  otters.h
//  ENGS 65 Final Project


#ifndef OTTERS_H
#define OTTERS_H

#include <iostream>
#include "species.h"
#include "shockfactors.h"
using namespace std;



class otter_spec: public Species {
    
private:
    
    // Nested class for 5-element queue, used to model 5 years otters spend in 'juvenile' stage
    class AgeQueue {
        public:
            float age_group[5];         // array of 5 juvenile population values
            int front;                  // index of front of the queue (OLDEST otters)
            int back;                   // index of back of the queue (YOUNGEST otters)
        
            AgeQueue();                 // queue constructor
            float shift(float val);     // insert new value into back of queue, return 'oldest' value from front of queue
            float sum();                // sums all elements in queue
            void print_queue();         // print all elements in queue
    };
    
public:
    
    // Otter population parameters
    const float bo = 0.00001;               // efficiency of prey to new offspring
    float dott;                // natural death rate of adult otters
    
    // Derivatives
    float pup_deriv;                        // time derivative of pup population (dN/dt)
    float ad_deriv;                         // time derivative of adult population (dN/dt)
    
    // Populations - total and by age
    float pup_N;                            // population of pups (age < 1 year)
    AgeQueue juv_queue;                     // queue of juvenile populations
    float juv_N;                            // population of juveniles (1 <= age < 6 years)
    float ad_N;                             // population of adults (6 <= age < 14 years)
    
    // Updating derivatives and populations
    float calcPupDeriv(Species &urch);
    float calcAdultDeriv();
    float updatePopulation();
    void toxinDeath(ShockFactors &shocks);  // updates death rate of otters due to toxins
    
    
    // Constructor/destructor
    otter_spec(float pop);    // initial biomass, bo, dott
    //~otter_spec();
    
    // Print out otter populations by age cohort
    void print();
    
    
};


#endif

