/** main.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Except for changes required to test Assignment S1, S2 and
   optionally F2, you do not need to change or understand this file in
   order solve the assignment.

   This file contains the main function which launches the simulator
   Its only purpose is to parse the command line parameters passed to
   the program and invoke the simulation.

**/

#include <fstream>
#include <iostream>

#include "damsim.h"
#include "plotter.h"

int main()
{

  // Be verbose
  bool verbose = false;
  // Show plot window
  bool plot = true;
  // How many timesteps to simulate for
  unsigned long timesteps = 500;
  // CSV file containing dam definitions
  string dam_def_file{"data/dam_def.csv"};
  // CSV file containing dam measurement
  // Optionally used for assignment F2
  string measurement_file{"data/sensor_data1.csv"};
  // CSV file for output
  string output_file{"out.csv"};

  try {
    // Assignment S1 and S2
    // Change <SensorsFile> to <SensorsRandom> below in order to test
    // your implementation. Uncomment the line at the bottom of
    // damsim.cpp as directed.
    DamSim<SensorsFileRandom>(dam_def_file, measurement_file, output_file, verbose,
                        timesteps, plot)
        .start();

  } catch (const ifstream::failure &e) {
    cout << e.what();
  }

  return 0;

}
