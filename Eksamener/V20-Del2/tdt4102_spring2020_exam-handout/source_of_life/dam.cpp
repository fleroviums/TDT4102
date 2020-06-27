/** dam.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file is required for assignment D1, D2 and D3.

   This file implements the functionality of the Dam class which
   represents a single simulated dam

   This is the header file for dam.cpp

**/

#include <cassert>
#include <iostream>
#include <memory.h>
#include <string>

#include "dam.h"
#include "sensors.h"

/** Assignment D1

    Implement the function get_water_level_delta which returns the
    difference between the current and ideal water level. The function
    should return the absolute value of the delta. You can use the
    function abs for this. Recall that the current water level and the
    ideal water level are stored in the member variables water_level and
    ideal_level of the Dam class respectively. The Dam class is defined in
    dam.h.
 */

int Dam::water_level_delta() const
{
  // BEGIN: D1
  return abs(water_level-ideal_level);
  // END: D1
}

/** Assignment D2

Implement the function get_alarm which indicates to the caller if the
water level of the dam is above the critical high level or below the
critical low level. The function should return one of the values
defined in the WaterAlarm enum in dam.h. If the water level is within
the critical bounds, return the appropriate value from the enum.

Recall that the current water level, critical high and critical low
levels are stored in the water_level, water_level_max and
water_level_min private member variables respectively. The variables are defined
in dam.h

 */

Dam::WaterAlarm Dam::get_alarm() const
{
  // BEGIN: D2
  if(water_level > water_level_max) return WaterAlarm::WaterLevelHigh;
  else if(water_level < water_level_min) return WaterAlarm::WaterLevelLow;
  else return WaterAlarm::NoAlarm;
  // END: D2
}

/** Assignment D3
    If the water level goes outside the critical bounds of the dam the
    system must take action to restore the water level to ideal.

    Implement the function restore_water_level which restores the
    water level in the dam if it is over or under the ideal level.

    As per the physical limitations of a dam, the amount of water
    which can flow in or out of the dam per timestep is given by the
    outflow_capacity and inflow_capacity class member variables. This means that
    it takes time for the water level to return to normal. Note that if the
    difference between actual and ideal water level are less than the inflow or
    outflow capacity you can simply set the water level to ideal. You can use
   the water_level_delta function defined in assignment D1 to check this.
 */

void Dam::restore_water_level()
{
  // BEGIN: D3

  if(water_level_delta() < inflow_capacity || water_level_delta() < outflow_capacity) water_level = ideal_level;
  //assume this is called for every tick/timestep, so task is asking us to increment or decrement water level??
  //also task didnt really say what value we should change, but it's logical to assume we're changing the inflow/outflow values?
  else if(water_level < ideal_level){
    if(inflow_value<inflow_capacity) inflow_value++;
    if(outflow_value>0) outflow_value--; //assuming we can do this...
  }
  else if(water_level > ideal_level){
    if(inflow_value>0) inflow_value--;
    if(outflow_value<outflow_capacity) outflow_value++;
  }
  // END: D3
}

Dam::Dam(string name, int water_level_min, int water_level_max,
         int outflow_capacity, int inflow_capacity, int water_level,
         Sensors &sensors, bool verbose)
    : name(name), water_level_min(water_level_min),
      water_level_max(water_level_max), outflow_capacity(outflow_capacity),
      inflow_capacity(inflow_capacity), water_level(water_level),
      inflow_value(0), outflow_value(0), ideal_level(water_level),
      sensors(sensors), verbose(verbose)
{
}

const string &Dam::get_name() const
{
  return name;
}

int Dam::get_water_level() const
{
  return water_level;
}

int Dam::get_critical_high() const
{
  return water_level_max;
}

int Dam::get_critical_low() const
{
  return water_level_min;
}

void Dam::do_timestep(unsigned long timestep)
{
  auto res = sensors.get_reading(timestep, name);
  if (res.inflow != 0 || res.outflow != 0) {
    if (verbose) {
      cout << "Got reading inflow " << res.inflow << " outflow " << res.outflow
           << endl;
    }
    water_level += res.inflow;
    water_level -= res.outflow;
  }

  if (verbose) {
    cout << "Running timestep " << timestep << " for dam " << name
         << " current water level: " << water_level << endl;
  }

  if (water_level != ideal_level) {
    restore_water_level();
  }

  // Update water level based on current inflow and outflow
  water_level += inflow_value;
  water_level -= outflow_value;
}
