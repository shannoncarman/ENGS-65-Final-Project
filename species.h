//  species.h
//  ENGS 65 Final Project
//
//  Created by Shannon Carman on 2/28/16.
//  Copyright (c) 2016 Shannon Carman. All rights reserved.
//


#ifndef SPECIES.H
#define SPECIES.H

#include <iostream>
using namespace std;


class Species {        /* This is an abstract class, a generic species may not be instantiated. */
public:
    float N;                               // population
    float dNdt;                            // time derivative of population
    
    Species(float population);             // constructor
    float getPopulation();                 // return population
    float getDeriv();                      // return derivative of population
    
    float updatePopulation();              // update population N = N + dN/dt * t_step
    virtual void print() = 0;                  // all species will print out differently depending on species attributes
    
protected:
    const float t_step = 1;                 // time step of 1 year for each population update calculation
    
};


#endif






/*
 
 To Do: 
 

 - Default values in constructors!
 - reevaluate whether we need all gets/sets
 
Questions:

 // nested classes: http://www.oopweb.com/CPP/Documents/CPPAnnotations/Volume/cplusplus16.html
 
 - Public, private, protected types needed, see http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
 - separate header/cpp files for each subclass definition and subclass function definitions or all in same cpp?
 - Should species constructor be private - user won't instantiate species, program does  with default values?
 

*/