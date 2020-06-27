/** sensors.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file are required for assignments S2 and F2

   This file contains the mechanics for generating sensor readings for
   the dam simulation.

**/

#include <cassert>
#include <utility>

#include "damsim.h"
#include "sensors.h"

/** Assignment S2
    Implement the function get_reading defined in the SensorsRandom class. The
    function gets the current timestep and the name of the dam as arguments and
    returns the struct Readings (defined in sensors.h) containing the sensor
    values.

    You are free to decide the logic for this function, however, it
    must return sensible values for inflow and outflow generated using
    the rand() function. For example, a simple approach would be to
    return random values between 0 and 100 for inflow and outflow
    every 10th timestep.

    When you have completed this task, change the template argument
    used to instantiate DamSim from SensorsFile to SensorsFile to test
    your implementation. Also, uncomment the line at the bottom of
    damsim.h as directed.


 */
// BEGIN: S2

Reading SensorsRandom::get_reading(unsigned long timestep, string name){
  //not sure if i understood assignment, but im assuming:
  //"Generate random numbers for every 10th timestep" => 90% of function calls returns 0,0
  Reading currRead;
  currRead.inflow = 0; currRead.outflow = 0;
  int calcThreshold = rand()%101; //[0,100]
  if(calcThreshold >=90){
    currRead.inflow = rand()%101; currRead.outflow = rand()%101;
  }
  return currRead;
}
// END: S2

/** Assignment F2

    Currently, the sensor readings used for the simulation are hard
    coded in the constructor of the SensorsFile class in sensors.cpp.

    In this assignment, we make the dam simulator more flexible by
    extending it with the ability to read sensor data from simple CSV
    files (Note that the CSV files you encounter in the wild may be
    more complicated than this). Several of these files are provided
    with this assignment in the data/ directory. The sensor data files
    are named sensor_dataX.csv where X is an integer.

    Below you can see the first few lines of the file
    sensor_data1.csv.

    timestep,dam,inflow,outflow
    10,dam02,0,40
    10,dam01,40,0
    20,dam01,300,0
    20,dam02,0,300
    25,dam01,300,0
    25,dam02,0,300
    ...

    As you can see, the format is as follows. The first line of the
    file contains the names of the fields. In this case the first
    field is timestep, the second is dam, etc. The subsequent lines
    contains the actual readings. In this example, the first reading
    occurs on timestep 10 for dam02 registering an inflow of 0 and an
    outflow of 40.

    Implement the constructor of the SensorsFile class in the
    sensors.cpp file to read the file name passed as the fname
    parameter taken by the constructor. For every line you read, you
    should call the insert_reading function to register the
    readings. We do not expect you to gracefully handle exceptional
    conditions, e.g., file format errors. You may, therefore, assume
    that your function will only be used to parse files conforming to
    the format described above.

    As the default sensor readings correspond to the readings found in
    the sensor_data1.csv file, the plot should not change if you
    implemented the function correctly. If you wish, feel free to try
    plotting some of the other sensor reading files by changing the
    measurement_file variable in the main function in the file
    main.cpp.

 */
SensorsFile::SensorsFile(const string fname, bool verbose)
    : Sensors(fname, verbose)

{
  // BEGIN: F2

  ifstream ifs{fname};
  if(!ifs) throw "Unable to read file" + fname ;
  int lineNo = 0;
  string cl; string t; string d; string infl; string outfl;
  while(getline(ifs, cl, ',')){
    if(lineNo!=0){ // we want to ignore column titles
          ifs >> t >> d >> infl >> outfl;
          int t_i = static_cast<unsigned int>(stoi(t));
          int inflo = stoi(infl);
          int outflo = stoi(outfl);
          insert_reading(t_i, d, inflo, outflo);
    }
    lineNo++;
  }

  

  // END: F2

}

// Used for assignment F2
void SensorsFile::insert_reading(unsigned int timestep, const string dam,
                                 int inflow, int outflow)
{
  if (readings.find(timestep) == readings.end()) {
    // readings.emplace(make_pair(get<0>(d), map<string, Reading>()));
    readings[timestep] = map<string, Reading>();
  }

  Reading r = {inflow, outflow};
  readings[timestep][dam] = r;
}


/**
 * Return the next reading from the sensors
 */
Reading SensorsFile::get_reading(unsigned long timestep, const string name)
{
  if (readings.find(timestep) != readings.end()) {
    if (readings[timestep].find(name) != readings[timestep].end()) {
      return readings[timestep][name];
    }
  }
  return {0, 0};
}
