/** sensors.h

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file are required for assignments S1

   This is the header file for sensors.cpp

**/

#ifndef _SENSORS_H
#define _SENSORS_H

#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

/**
   Struct returned from the get_reading function
   Used in assignment S2
 */
struct Reading {
  int inflow;
  int outflow;
};

class Sensors
{
protected:
  const bool verbose;

public:
  Sensors(const string, bool verbose = false) : verbose(verbose){};

public:
  virtual Reading get_reading(unsigned long timestep, string name) = 0;
  virtual ~Sensors() = default;
};

/** Assignment S1
    Write a class declaration named SensorsRandom which declares the
    functions of the abstract class Sensors. Implement a delegate
    constructor which calls the constructor of the virtual class Sensors.
**/
// BEGIN: S1

class SensorsRandom : public Sensors {
  public:
    SensorsRandom(const string s, bool verbose=false) : Sensors(s, verbose) {}
    Reading get_reading(unsigned long timestep, string name) override;
};
// END: S1

class SensorsFile : public Sensors
{
private:

  struct SensorReading {
    // Struct for holding a CSV reading
    unsigned long timestep;
    string name;
    int inflow;
    int outflow;
  };

  map<unsigned int, map<string, Reading>> readings;

public:
  SensorsFile(string fname, bool verbose = false);

  Reading get_reading(unsigned long timestep, const string name);

  ~SensorsFile() = default;

private:
  void insert_reading(unsigned int timestep, const string dam, int inflow,
                      int outflow);
};

#endif
