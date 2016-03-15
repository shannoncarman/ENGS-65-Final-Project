//  urchins.cpp
//  ENGS 65 Final Project


#include <iostream>
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"
using namespace std;




// Urchin population growth equation (time derivative)

float urchin_spec::calcDeriv(Species &kelp, Species &otter) {
    
    dNdt = -(du * N) + (bu * N * kelp.N) - (Pou * N * otter.N);     //********** change this to only juvenile + adult N
    return dNdt;
}

void urchin_spec::print() {
    cout << "Sea urchin population\n\n";
    cout << "N: " << N << endl;
    cout << "Population growth parameters:\n";
    cout << "Natural death rate, du = " << du << endl;
    cout << "Prey to offspring efficiency, bu = : " << bu << endl;
    cout << "Rate urchins eaten by otters, Pou: " << Pou << endl;

}


// du = natural death rate of sea urchins
// N = population of sea urchins
// bu = efficiency of converting prey (kelp) into new offspring (urchins)
// kelp.N = population of kelp
// Pou = rate at which sea urchins are eaten by otters
// otter.N = population of otters