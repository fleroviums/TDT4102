/** damsim.h

   This file is part of the handout for the TDT4102 spring 2020 exam.

   You do not need to understand or change this file in order to
   complete the assignment.

   This file is the heaer for damsim.h.
**/

#ifndef _DAMSIM_H
#define _DAMSIM_H

#include <fstream>
#include <map>
#include <memory>

#include "csv.h"
#include "dam.h"
#include "plotter.h"
#include "sensors.h"

// Exceptions
class UndefinedDam : public exception
{
};

template <typename SensorProvider>
class DamSim
{
  // Path to CSV file containing dam definitions
  const string dam_def_file;
  // Stream for writing measurement outputs
  ofstream output_file;
  // Path to CSV output file
  const string output_file_name;
  // Are we verbose?
  const bool verbose;

  // The current simulation timestep
  unsigned long cur_timestep;
  // The number of timesteps to simulate for
  const unsigned long num_timesteps;

  // Sensor reading instance
  SensorProvider sensors;

  // Map for maintaining dam instances
  map<string, unique_ptr<Dam>> dams;

  // Should we show the plot window?
  const bool plotter;

  // Handle to the plotting window
  unique_ptr<Plotter> plot_win;

public:
  DamSim(const string dam_def_file, const string measurement_file,
         const string output_file, const bool verbose,
         const unsigned long timesteps, const bool plotter);
  void start();

private:
  void init_dams();
  void write_data(Dam &v, int cur_timestep);
  void do_timesteps();
};

#endif //_DAMSIM_H
