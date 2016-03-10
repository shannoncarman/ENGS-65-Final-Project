// Shannon Carmna & Rachel Margolese
// ENGS 65 Final Project

// species.h
//  Final Project
//
//  Created by Shannon Carman on 2/28/16.
//  Copyright (c) 2016 Shannon Carman. All rights reserved.
//


#include <iostream>
using namespace std;


class Species {
public:
    float N;            // population
    float dNdt;         // time derivative of population
    
    Species(float population);             // constructor
    
    void updatePopulation();               // calculate the updated population N += dN/dt*time_step
    
    float getPopulation();                 // return population
    float getDeriv();                   // return derivative of population
    void setPopulation(float pop);          // set population value
    void setDeriv(float deriv);         // set derivative of population value
    void print();
    
protected:
    const float t_step = 0.5;           // time step of 6 months (0.5 years) for each population update calculation
    
};



class kelp_spec: public Species {
public:
    
    //nutrient uptake constant
    float K;        // carrying capacity of kelp population
    float r;        // intrinsic growth rate
    float Puk;      // feeding efficiency of sea urchins on kelp (rate of getting eaten by sea urchins)
 
    kelp_spec(float biomass, float a, float b, float c)
    : Species(biomass), K(a), r(b), Puk(c) {};
    
//private:
    void calcDeriv(float old_urch_N);   // calculate dNdt based on predator/prey relationships
};



class urchin_spec: public Species {
public:
    float population;
    float bu;           // efficiency of prey to new offspring
    float Pou;          // feeding efficiency of otters on sea urchins (rate of getting eaten by otters)
    float du;           // natural death rate of urchins
    
    // Constructor
    urchin_spec(float biomass, float a, float b, float c): Species(biomass), bu(a), Pou(b), du(c) {}
   
    void calcDeriv(float old_kelp_N, float old_otter_N);       // calculate dNdt
    float getPopulation();  // return population
    
};



class otter_spec: public Species {

private:
    
    class AgeQueue {
    private:
        float age_group[5];  // array of 5 population values, holds populations of juvenile otters for 5 years
        int front;           // index of front of the queue (OLDEST otters)
        int back;            // index of back of the queue (YOUNGEST otters)
        
    public:
        AgeQueue();                 // create new queue with initial juvenile populations
        float shift(float val);     // insert new value into back of queue, return 'oldest' value from front of queue
        float sum();                // sums population of all juveniles in queue
    };
    
public:
    
// Basic otter population parameters
    float bo;                       // efficiency of prey to new offspring
    float dott;                     // natural death rate of adult otters
//    const float avgmass = 35;       // average mass of sea otter (kg)

// Derivatives
    float pup_deriv;          // time derivative of pup population  (dN/dt)
    float ad_deriv;           // time derivative of adult population (dN/dt)

// Populations - total and by age
    float total_pop;          // combined population of pups, juveniles, and adults
    float pup_pop;            // population of pups (age < 1 year)
    float ad_pop;             // population of adults (6 <= age < 14 years)
    AgeQueue juv_pop;         // population of juveniles, stored in AgeQueue class (1 <= age < 6 years)

    
// Updating derivatives and populations
    float calcPupDeriv(float old_urch_N, float old_adult_N);
    float calcAdultDeriv(float old_adult_N);
    float updatePopulations();
    float getTotalPop();

    
// Constructor/destructor
    otter_spec(float pop, float a, float b);    // initial biomass, bo, dott
    //~otter_spec();

};







/*

 Major Changes
 3/9: made derivative not-initialized (it's always calculated from other parameters)
 
 
 To Do
 

 - Default values in constructors
 - reevaluate whether we need all gets/sets
 
 -------------Update functions take in floats, not actual population parameters from different classes -------
 
 ----------------Make derivative and population update/calculation one function!-------------------------
 

Questions

CODING
 
 // nested classes: http://www.oopweb.com/CPP/Documents/CPPAnnotations/Volume/cplusplus16.html
 
 x Public, private, protected types needed, see http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
 - calcDeriv: should it be in the Species class and inherited/redefined or just defined in each subclass?
 - separate header/cpp files for each subclass definition and subclass function definitions or all in same cpp?
 - Should species constructor be private - user won't instantiate species, program does  with default values?
 

MODEL
 
 - values for rates, initial values for derivatives and biomasses
 - Where are we using K carrying capacity for kelp?


 
 
*/