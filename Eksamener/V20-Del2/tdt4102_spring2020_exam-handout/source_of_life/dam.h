/** dam.h

   This file is part of the handout for the TDT4102 spring 2020 exam.

   No changes to this file is required but declarations but
   declarations for assignments D1, D2, D3 and P3 are made here.

   This is the header file for dam.cpp

**/

#ifndef _DAM_H
#define _DAM_H

#include <memory>
#include <string>

#include "sensors.h"

class Dam
{
private:
  string name; // name of the sensor

  int water_level_min;  // minimum possible water level for a functioning dam
  int water_level_max;  // maximum possible water level before the dam gets
                        // damaged
  int outflow_capacity; // The maximum outflow capacity
  int inflow_capacity;  // The maximum inflow capacity (l/min)
  int water_level;      // current water level in the dam

  int inflow_value; // Current inflow (l/min)

  int outflow_value; // The maximum inflow capacity

  int ideal_level; // The ideal level of the dam

  Sensors &sensors;

  const bool verbose;

public:
  Dam(string name, int water_level_min, int water_level_max,
      int water_outlet_capacity, int water_inlet_capacity, int water_level,
      Sensors &sensors, bool verbose = false);

  // Used in Assignment D2 and P5
  enum WaterAlarm { WaterLevelLow, WaterLevelHigh, NoAlarm };

  void do_timestep(unsigned long timestep);

  // Function declaration for assignment D2 in dam.cpp
  WaterAlarm get_alarm() const;

  const string &get_name() const;
  int get_water_level() const;
  int get_critical_high() const;
  int get_critical_low() const;

private:
  // Function declaration for assignment D1 in dam.cpp
  int water_level_delta() const;

  // Function declaration for assignment D3 in dam.cpp
  void restore_water_level();
};

#endif //_DAM_H
