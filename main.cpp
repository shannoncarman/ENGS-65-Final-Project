//
//  main.cpp
//  Final Project
//
//  Created by Shannon Carman on 2/28/16.
//  Copyright (c) 2016 Shannon Carman. All rights reserved.
//

#include <iostream>
#include "species.h"
using namespace std;

int main() {
    

    kelp_spec kelp(500, 5000, 0.02, 0.05); // N, K, r, Puk
    
    urchin_spec urchins(10, 0.4, 0.5, 0.06);  // N, bu, Pou, du
//
//    cout << "kelp ";
//    kelp.print();
//    cout << "urchins ";
//    urchins.print();
//    
//    kelp.calcDeriv(urchins);
//    kelp.updateBiomass();
//  
    cout << "kelp ";
    kelp.print();
//
//    urchins.calcDeriv(kelp, kelp);
//    urchins.updateBiomass();
//    
    cout << "urchins ";
    urchins.print();

    
//    AgeQueue queue(1.1, 2.2, 3.3, 4.4, 5.5);
//    queue.shift(6.6);
//    queue.shift(7.7);
//    queue.shift(8.8);
//    queue.shift(9.9);
//    queue.shift(10);
//    queue.shift(11);
    
  
    otter_spec otters(5000, 0.05, 0.1);  // initial biomass (N), bo, dott
    
    cout << "total pop: " << otters.total_pop << endl;
    cout << "pup pop: " << otters.pup_pop << endl;
    cout << "adult pop: " << otters.ad_pop << endl;
    
    otters.juv_pop.shift(4);
    otters.juv_pop.shift(5);
    otters.juv_pop.shift(6);
    otters.juv_pop.shift(7);
    otters.juv_pop.shift(8);
    otters.juv_pop.shift(9);
    otters.juv_pop.shift(10);
    otters.juv_pop.shift(11);
    otters.juv_pop.shift(12);
    otters.juv_pop.shift(13);
 
    kelp.calcDeriv(10);
    kelp.updatePopulation();
    kelp.print();
    
    
    
    return 0;
}
