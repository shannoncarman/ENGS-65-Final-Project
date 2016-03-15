///* Final project for Engs 65
// * Ecosystem simulation
// * Driver portion of the program
// * March 2016
// *
// */
//
#include <iostream>
#include <string>
#include "soluteclass.h"
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"
#include "shockfactors.h"

using namespace std;


int main() {
    

    // Instantiate species populations and shock factors
   
    kelp_spec kelp(50000);
    urchin_spec urchins(10000);
    otter_spec otters(500);
    ShockFactors systemshocks;
    
    
    /////////////////////
    // TIME VARIABLES  //
    /////////////////////

    // Initialize length of simulation
    int t_total = 10;

    // Initial year
    int t = 0;
    // Time of system shocks
    int t_shocks[3] = {0}; // initialize array for years of system shocks, if any
    
    //////////////////////
    // SHOCK VARIABLES  //
    //////////////////////

    
    // Temporary type of shock
    int shocktypetemp = 0;
    
    char shocks[3] = {'0','0','0'};     // array of shock types (none, nutrients, toxins, sealevel)
    
    // Number of shocks
    int numshocks = 0;

    // Check to run simulation
    int runsim = 1;
    

    // User input choice
    int userchoice = 0;


    /**************************************************************************************************/
    
    ///////////////////////////
    // MAIN SIMULATION LOOP  //
    ///////////////////////////


    cout << "__________________________________________" << endl<<endl;
    cout << "Welcome!" << endl << endl;
    cout << "Iinitial system parameters:" << endl << endl;
    cout << "Kelp population    : " << kelp.N << endl;
    cout << "Urchin population  : " << urchins.N << endl;
    cout << "Otter population   : " << otters.N << endl;
    
    cout << "Total length of simulation : " << t_total << " years" << endl << endl;
    
    cout << "__________________________________________" << endl <<endl;
    
    
    while (runsim == 1)  {
        
        cout << "Would you like to... " << endl;
        cout << "   [1] Change initial populations" << endl;
        cout << "   [2] Change simulation time" << endl;
        cout << "   [3] Add system shock (up to 3)" << endl;
        cout << "   [4] Run simulation" << endl;
        cout << "   [5] Exit" << endl << endl;

        cout << "Enter choice and press return: ";

        cin >> userchoice;

        cout << endl;

        switch (userchoice) {

            /////////////////////////////////////////
            // User enter new initial populations  //
            /////////////////////////////////////////
            case 1:
                cout << "Enter kelp population: ";
                cin >> kelp.N;
                cout << "Enter urchin population: ";
                cin >> urchins.N;
                cout << "Enter otter population: ";
                cin >> otters.N;

                cout <<endl << "Initial populations changed." << endl;

                break;


            ///////////////////////////////////////////
            // User enter new total simulation time  //
            ///////////////////////////////////////////
            case 2:
                cout << "Enter simulation runtime in years (1-10) ";
                cin >> t_total;
                break;


            //////////////////////////////
            // User enter system shock  //
            //////////////////////////////
            case 3:
                
                // If there have been fewer than three shocks added, allow user to add another shock
                if (numshocks > 2) {
                    cout << "Maximum number of shocks added." << endl << endl;
                    
                }
                else {

                    cout << "Enter time of system shock (between 1 and "<< t_total << "): ";
                    cin >> t_shocks[numshocks]; // if 0 shocks already -> add time for 1st shock in t_shocks[0]
                                                // if 1 shock already -> add time for 2nd shock in t_shocks[1]
                                                // if 2 shocks already -> add time for 3rd shock in t_shocks[2]

                    cout << endl << "Types of system shocks" << endl;
                    cout << "[1] Nutrient enrichment" << endl;
                    cout << "[2] Introduce toxins" << endl;
                    cout << "[3] Change sea level" << endl;
                    // add fourth shock to kill otters
                    cout << "[4] Back" << endl << endl;

                    cout << "Enter choice: ";
                    cin >> shocktypetemp;
                    
                    cout << "numshocks: " << numshocks << endl;
                    cout << "t_shocks: " << t_shocks[0] << t_shocks[1] << t_shocks[2] << endl;
                    
                    
                    
                    // Save the type of shock
//                    if (numshocks == 1) {
//                    
//                        int end_shocks = 1;
                    
                            switch (shocktypetemp)  {
                                case 1:
                                    shocks[numshocks] = 'n';
                                    break;
                                case 2:
                                    shocks[numshocks] = 't';
                                    break;
                                case 3:
                                    shocks[numshocks] = 's';
                                    float sea_temp;
                                    cout << "Enter change in sea level (+/- 20 cm): ";
                                    cin >> sea_temp;
                                    systemshocks.setSeaLevelChange(sea_temp);
                                    break;
                                default:
                                    cout << "Invalid choice. Choose an option between 1 and 3." << endl;
//                                    numshocks--;
                                    break;
                            }
                    cout << "shocks: " << shocks[0] << shocks[1] << shocks[2] << endl;

//                    if (numshocks == 2) {
//                        switch (shocktypetemp)  {
//                            case 1:
//                                shock2 = "nutrients";
//                                break;
//                            case 2:
//                                shock2 = "toxins";
//                                break;
//                            case 3:
//                                shock2 = "sealevel";
//                                break;
//                            default:
//                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
//                                numshocks--;
//                                break;
//                        }
//                    }
//
//                    if (numshocks == 3) {
//                        switch (shocktypetemp)  {
//                            case 1:
//                                shock3 = "nutrients";
//                                break;
//                            case 2:
//                                shock3 = "toxins";
//                                break;
//                            case 3:
//                                shock3 = "sealevel";
//                                break;
//                            default:
//                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
//                                numshocks--;
//                                break;
//                        }
//                    }
                   
                    
                    numshocks++;                // increment # of shocks added
                    
                }
                    

            break;


            /////////////////////////
            // Run the simulation  //
            /////////////////////////
            case 4:
               
                cout << "Simulation Conditions" << endl;
                cout << "Kelp population    : " << kelp.N << endl;
                cout << "Urchin population  : " << urchins.N << endl;
                cout << "Otter population   : " << otters.N << endl;
                
                cout << "Total length of simulation : " << t_total << " years" << endl;
                
                cout << "__________________________________________" <<endl;
                
                // If there are shocks, display them
                if (numshocks > 0)  {
                    
                    for (int i=0; i<3; i++) {
                        if (shocks[i] != '0') {
                            cout << endl << "Shock " << i+1 << " type: " << shocks[i] << endl;
                            cout << "Shock " << i+1 << " time : " << t_shocks[i] << endl;
                        }
                    }
                    
                } // end printing shocks
                
                cout << "Simulation output" << endl;
                t = 0;  // reset t to 0 at the start
                // Print header for output table
                cout << " Year  Otters         Urchins        Kelp          Nutrients         Toxins" << endl;
                cout << "----------------------------------------------------------------------------------------" << endl;
                cout << "  " << t << "    " << otters.N << "    " << urchins.N  << "    " << kelp.N << "    " << endl;
                
                for (t = 1; t <= t_total; t++) {
                    // Check for shock
                    if (numshocks > 0)  {
                        // Update abiotic parameters
                        for (int i=0; i<3; i++) {
                            if (t == t_shocks[i]) {
                                cout << "shock time" << endl;
                                char shock_temp = shocks[i];
                                switch (shock_temp) {
                                    case 'n' :
                                        // statements
                                        break;
                                
                                    case 't' :
                                        // statements
                                        break;
                                    
                                    case 's' :
                                        kelp.changeGrowth(systemshocks);
                                        break;
                                
                                }
                            }
                        
                        
                        
                        } // end of for loop to check shock times
                
                        
                    } // end of if statement to check shocks
                    
                    // Calculate derivatives
                    kelp.calcDeriv(urchins);
                    urchins.calcDeriv(kelp, otters);
                    otters.calcAdultDeriv();
                    otters.calcPupDeriv(urchins);
                    
                    // Calculate new populations
                    kelp.updatePopulation();
                    urchins.updatePopulation();
                    otters.updatePopulation();
                    
                    cout << "  " << t << "   " << otters.N << "    " << urchins.N  << "    " << kelp.N << "    " << endl;
                
            
                } // end of main time loop

                cout << "----------------------------------------------------------------------------------------" << endl << endl;
                    runsim = 1;
                break;


            //////////////////////
            // Exit simulation  //
            //////////////////////
            case 5:
                runsim = 0;
                cout << "You have exited the program." << endl;
                break;

           ////////////////////////////////////
           // User inputs invalid selection  //
           ////////////////////////////////////
            default:
                cout << "Invalid selection." <<endl;
                break;
        }
    }

        /**********************************************************************************************/

    cout << "You have exited the simulation." << endl;

    return 0;
}

