/* Final project for Engs 65
 * Ecosystem simulation
 * Driver portion of the program
 * March 2016
 *
 */

#include <iostream>
#include "soluteclass.h"
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
                cout << "Shock 3 type       : " << shock3 << endl;
                cout << "Shock 3 time       : " << t_shock3 << endl;
            }

        }
        cout << "Total length of simulation :" << t_total << " months" << endl << endl;

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
                cout << "Enter simulation runtime in years (1-10)";
                cin >> t_total;
                break;


            //////////////////////////////
            // User enter system shock  //
            //////////////////////////////
            case 3:
                cout << "Up to three desperate system shocks may be added." << endl;

                // If there have been fewer than three shocks added, allow user to add another shock
                if (numshocks < 3) {

                    cout << "Enter time of system shock (between 1 and "<< t_total << "): ";
                    cin >> t_shock1;

                    cout << endl << "Types of system shocks" << endl;
                    cout << "[1] Dump nutrients into ecosystem" << endl;
                    cout << "[2] Introduce toxins to ecosystem" << endl;
                    cout << "[3] Increase sea temperature" << endl;
                    cout << "[4] Done added shocks" << endl << endl;

                    cout << "Enter choice: ";

                    cin >> shocktypetemp;

                    // Save the type of shock
                    if (numshocks == 0) {

                        switch (shocktypetemp)  {
                            case 1:
                                shock1 = "nutrients";
                                break;
                            case 2:
                                shock1 = "toxins";
                                break;
                            case 3:
                                shock1 = "seatemp";
                                break;
                            default:
                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
                                numshocks--;
                                break;
                        }
                    }

                    if (numshocks == 1) {
                        switch (shocktypetemp)  {
                            case 1:
                                shock2 = "nutrients";
                                break;
                            case 2:
                                shock2 = "toxins";
                                break;
                            case 3:
                                shock2 = "seatemp";
                                break;
                            default:
                                cout << "Invalid choice. Choose an option between 1 and 3." << endl;
                                numshocks--;
                                break;
                        }
                    }

                    if (numshocks == 2) {
                        switch (shocktypetemp)  {
                            case 1:
                                shock3 = "nutrients";
                                break;
                            case 2:
                                shock3 = "toxins";
                                break;
                            case 3:
                                shock3 = "seatemp";
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
                    cout << "Only three shocks may be added per simulation." << endl;
                }
                break;


            /////////////////////////
            // Run the simulation  //
            /////////////////////////
            case 4:
                cout << "Running simulation" << endl;

                // Print header for output table
                cout << " Year      Otter Pop       Urchin Pop      Kelp Pop        Nutrient conc       Toxin conc" << endl;
                cout << "-----------------------------------------------------------------------------------------" << endl;

                for (;t <= t_total; t++) {
                    // Check for shock
                    if (numshocks > 0)  {
                        // Update abiotic
                        if (t_shock1 != 0)  {

                            // do something
                        }
                    }
                }


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