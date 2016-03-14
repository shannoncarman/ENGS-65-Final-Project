/* Final project for Engs 65
 * Ecosystem simulation
 * Driver portion of the program
 * March 2016
 *
 */

#include <iostream>

#include "soluteclass.h"
#include "otters.h"
#include "kelp.h"
#include "species.h"
#include "urchins.h"

using namespace std;


int main() {

    // Initialize populations

    int N_kelp = 100;
    int N_otters = 100;
    int N_urchins = 100;

    /////////////////////
    // TIME VARIABLES  //
    /////////////////////

    // Initialize length of simulation
    int t_total = 100;
    // Current time
    int t = 0;
    // Time of system shocks
    int t_shock1 = 0;
    int t_shock2 = 0;
    int t_shock3 = 0;

    //////////////////////
    // SHOCK VARIABLES  //
    //////////////////////

    // Temporary type of shock
    int shocktypetemp = 0;
    // Hold type of shock
    string shock1 = "none";
    string shock2 = "none";
    string shock3 = "none";
    // Number of shocks
    int numshocks = 0;

    /////////////////////////////////////////////
    // object holding concentration of solutes //
    /////////////////////////////////////////////
    solutes soluteconc;
    float nitrogen = 90;
    float DO = 80;
    float sealevel = 9;

    //////////////////////////
    // Population variables //
    //////////////////////////
    kelp_spec   kelp(500, 5000, 0.02, 0.05); // N, K, r, Puk
    urchin_spec urchins(10, 0.4, 0.5, 0.06);  // N, bu, Pou, du)
    otter_spec otters(5000, 0.05, 0.1);  // initial biomass (N), bo, dott


    // Check to run simulation
    int runsim = 1;

    // User input choice
    int userchoice = 0;


    /**************************************************************************************************/
    ///////////////////////////
    // MAIN SIMULATION LOOP  //
    ///////////////////////////

    while (runsim == 1)  {
        cout << "__________________________________________" << endl<<endl;

        cout << "Simulation initial parameters:" << endl << endl;
        cout << "Kelp population    : " << N_kelp << endl;
        cout << "Otter population   : " << N_otters << endl;
        cout << "Urchin population  : " << N_urchins << endl;

        // If there are shocks, display them
        if (numshocks > 0)  {
            if (shock1 != "none") {
                cout << endl << "Shock 1 type       : " << shock1 << endl;
                cout << "Shock 1 time       : " << t_shock1 << endl;
            }
            if (shock2 != "none") {
                cout << endl << "Shock 2 type       : " << shock2 << endl;
                cout << "Shock 2 time       : " << t_shock2 << endl;
            }
            if (shock3 != "none") {
                cout << endl << "Shock 3 type       : " << shock3 << endl;
                cout << "Shock 3 time       : " << t_shock3 << endl;
            }

            cout << endl << "Abiotic conditions:" << endl;
            cout << "Nitrogen           : " << nitrogen << endl;
            cout << "Sea level rise     : " << sealevel << endl;
            cout << "DO concentration   : " << DO << endl << endl;

        }
        cout << "Total length of simulation : " << t_total << " months" << endl << endl;

        cout << "__________________________________________" << endl <<endl;

        cout << "Would you like to... " << endl;
        cout << "   [1] Enter new initial populations" << endl;
        cout << "   [2] Enter new simulation time" << endl;
        cout << "   [3] Add system shock" << endl;
        cout << "   [4] Run simulation" << endl;
        cout << "   [5] Exit simulation"<< endl << endl;

        cout << "Enter choice and press return: ";

        cin >> userchoice;

        cout << endl;

        switch (userchoice) {

            /////////////////////////////////////////
            // User enter new initial populations  //
            /////////////////////////////////////////
            case 1:
                cout << "Enter otter population: ";
                cin >> N_otters;
                cout << "Enter kelp population: ";
                cin >> N_kelp;
                cout << "Enter urchin population: ";
                cin >> N_urchins;

                cout <<endl << "Initial populations changed. Ready for next simulation." << endl;

                break;


                ///////////////////////////////////////////
                // User enter new total simulation time  //
                ///////////////////////////////////////////
            case 2:
                cout << "Enter simulation runtime in years (1-100): ";
                cin >> t_total;
                break;


                //////////////////////////////
                // User enter system shock  //
                //////////////////////////////
            case 3:
                cout << "DIRECTIONS: Up to three desperate system shocks may be added to the simulation. Add one at a time." << endl << endl;

                // If there have been fewer than three shocks added, allow user to add another shock
                if (numshocks < 3) {


                    cout << endl << "Types of system shocks" << endl;
                    cout << "[1] Dump nutrients into ecosystem" << endl;
                    cout << "[2] ??????" << endl;
                    cout << "[3] Increase sea level" << endl;
                    cout << "[4] Done added shocks" << endl << endl;

                    cout << "Enter choice: ";

                    cin >> shocktypetemp;

                    // Save the type of shock
                    if (numshocks == 0) {

                        for (int check = 0; check == 0;) {
                            cout << "Enter time of system shock (between 1 and " << t_total << "): ";
                            cin >> t_shock1;

                            if (t_shock1 > t_total) {
                                cout << "Invalid time." << endl;
                            }
                            else    {
                                check ++;
                            }
                        }

                        switch (shocktypetemp)  {
                            case 1:
                                shock1 = "Nitrogen addition";
                                cout << "Enter concentration of nitrogen entering system (between 0 and 90: ";
                                cin >> nitrogen;
                                break;
                            case 2:
                                shock1 = "?????????";
                                break;
                            case 3:
                                shock1 = "sealevel";
                                cout << "Enter rise in sealevel (between 0 and 300 cm): ";
                                cin >> sealevel;
                                break;
                            default:
                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
                                numshocks--;
                                break;
                        }
                    }

                    if (numshocks == 1) {

                        for (int check = 0; check == 0;) {
                            cout << "Enter time of system shock (between 1 and " << t_total << "): ";
                            cin >> t_shock2;

                            if (t_shock1 > t_total) {
                                cout << "Invalid time." << endl;
                            }
                            else    {
                                check ++;
                            }
                        }


                        switch (shocktypetemp)  {
                            case 1:
                                shock2 = "nutrients";
                                cout << "Enter concentration of nitrogen entering system (between 0 and 90: ";
                                cin >> nitrogen;
                                break;
                            case 2:
                                shock2 = "??????";
                                break;
                            case 3:
                                shock2 = "Sealevel";
                                cout << "Enter rise in sea level (between 0 and 300 cm): ";
                                cin >> sealevel;
                                break;
                            default:
                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
                                numshocks--;
                                break;
                        }
                    }

                    if (numshocks == 2) {

                        for (int check = 0; check == 0;) {
                            cout << "Enter time of system shock (between 1 and " << t_total << "): ";
                            cin >> t_shock3;

                            if (t_shock1 > t_total) {
                                cout << "Invalid time." << endl;
                            }
                            else    {
                                check ++;
                            }
                        }

                        switch (shocktypetemp)  {
                            case 1:
                                shock3 = "nutrients";
                                cout << "Enter concentration of nitrogen entering system (between 0 and 90: ";
                                cin >> nitrogen;
                                break;
                            case 2:
                                shock3 = "???????";
                                break;
                            case 3:
                                shock3 = "Sealevel";
                                cout << "Enter rise in sealevel (between 0 and 300 cm): ";
                                cin >> sealevel;
                                break;
                            default:
                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
                                numshocks--;
                                break;
                        }
                    }
                    numshocks++;
                }

                    // If three system shocks have already been added
                else    {
                    cout << "Only three shocks may be added per simulation. Three shocks have already been added." << endl;
                }
                break;


                /////////////////////////
                // Run the simulation  //
                /////////////////////////
            case 4:
                cout << "Running simulation" << endl;

                // Print header for output table
                cout << " Year          Otter Pop           Urchin Pop          Kelp Pop            Nutrient conc           Toxin conc" << endl;
                cout << "--------------------------------------------------------------------------------------------------------------" << endl;

                for (;t <= t_total; t++) {

                    // Check for shock
                    if (numshocks > 0)  {
                        // Update abiotic
                        if (t_shock1 == t || t_shock2 == t || t_shock3==t)  {
                            soluteconc.update_concentration(nitrogen,DO,sealevel);
                        }
                    }

                    // Update change in populations
                    kelp.calcDeriv(urchins);


                    urchins.calcDeriv(kelp,otters);


                    otters.calcPupDeriv(urchins);
                    otters.calcAdultDeriv();

                    cout << t << "              " << otters.updatePopulation() << "                 " << urchins.updatePopulation() << "                " <<  kelp.updatePopulation() << endl;


                }

                cout << "Simulation has finished running. The final parameters will be saved if you would like to continue with a new simulation." << endl <<endl;
                break;


                //////////////////////
                // Exit simulation  //
                //////////////////////
            case 5:
                runsim = 0;
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

    cout << "You have exited the otter simulation." << endl;

    return 0;
}
