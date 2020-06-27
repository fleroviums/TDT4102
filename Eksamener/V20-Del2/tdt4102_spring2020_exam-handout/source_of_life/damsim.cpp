/** damsim.cpp

   This file is part of the handout for the TDT4102 spring 2020 exam.

   Changes to this file is required for assignment F1. Apart from
   that, you do not need to understand the code here.

   This file implements the DamSim class which ties the other
   components together and manages the progression of the
   simulation. Particularly, it calls the simulated dams to progress
   the simulation and calls the plotting library to plot the result
   of the simulation.

**/

#include "damsim.h"

/* Assignment F1
  Write function which writes simulation data in comma separated
  value (CSV) format to the file stream output_file.

  To the file stream, you should write a line in the following format
    <dam name>,<current timestep>,<current water level>

  You can get the name of the dam and the current water level from the
  get_name and get_water_level methods of the Dam object passed to the
  function as a reference. Examine the declaration of the Dam
  class in dam.h for more details. The current timestep is passed directly
  through the cur_timestep parameter.

 */
template <typename SensorProvider>
void DamSim<SensorProvider>::write_data(Dam &v, int cur_timestep)
{
  // BEGIN: F1
  ofstream ost{"output_file.csv"};
  if(!ost) throw "Unable to open output_file.csv";
  ost << v.get_name() << "," << cur_timestep << "," << v.get_water_level() << endl;
  // END: F1
}

//
// Everything below this line is not needed for the assignment
//

template <typename SensorProvider>
void DamSim<SensorProvider>::do_timesteps()
{
  for (; cur_timestep < num_timesteps; cur_timestep++) {
    for (auto i = dams.begin(); i != dams.end(); ++i) {
      i->second->do_timestep(cur_timestep);
      // Write output to CSV file
      write_data(*(i->second), cur_timestep);
      // Update plot
      if (plotter) {
        plot_win->plot_point(i->second->get_name(), cur_timestep,
                             i->second->get_water_level());
        plot_win->plot_alarm(i->second->get_name(), cur_timestep,
                             i->second->get_alarm());
      }
    }
  }
}

template <typename SensorProvider>
DamSim<SensorProvider>::DamSim(const string dam_def_file,
                               const string measurement_file,
                               const string output_file_name, bool verbose,
                               unsigned long timesteps, bool plotter)
    : dam_def_file(dam_def_file), output_file(output_file_name),
      output_file_name(output_file_name), verbose(verbose), cur_timestep(0),
      num_timesteps(timesteps), sensors(measurement_file, verbose),
      plotter(plotter)
{

  if (!this->output_file.good()) {
    throw runtime_error("Unable to open output log file " + output_file_name);
  }

  // Initialize dams from dam definition CSV file
  init_dams();

  int max_capacity = 0;
  for (auto d = dams.begin(); d != dams.end(); ++d) {
    auto high = d->second->get_critical_high();
    if (max_capacity < high) {
      max_capacity = high;
    }
  }

  // Initialize plotter window
  if (plotter) {
    plot_win =
        make_unique<Plotter>(1000, 550, timesteps, max_capacity, verbose);

    // Call draw_limit to draw dam thresholds
    for (auto d = dams.begin(); d != dams.end(); ++d) {
      auto &dam = d->second;

      // Plot extreme limits for the dam
      plot_win->plot_limit(dam->get_name(), dam->get_critical_low());
      plot_win->plot_limit(dam->get_name(), dam->get_critical_high());

      // Plot a legend for the dam
      plot_win->add_legend(dam->get_name());
    }
  }
}

template <typename SensorProvider>
void DamSim<SensorProvider>::init_dams()
{
  // Initialize the dams

  // Open the CSV file containing the definitions of the dams
  ifstream f(dam_def_file);

  csv::CsvParser parser(f);
  auto it =
      csv::init_csv(parser, dam_def_file,
                    {"dam_name", "ideal_level", "critical_high", "critical_low",
                     "outlet_capacity", "inlet_capacity"});

  while (it != parser.end()) {

    auto row = *it;
    auto dam_name = row[0];
    int ideal_level = stoi(row[1]);
    int critical_high = stoi(row[2]);
    int critical_low = stoi(row[3]);
    int outlet_capacity = stoi(row[4]);
    int inlet_capacity = stoi(row[5]);

    cout << "Creating dam " << dam_name << " with ideal_level: " << ideal_level
         << ", critical_high: " << critical_high
         << " critical_low: " << critical_low
         << " outlet_capacity: " << outlet_capacity
         << " inlet_capacity: " << inlet_capacity << endl;

    dams[dam_name] =
        make_unique<Dam>(dam_name, critical_low, critical_high, outlet_capacity,
                         inlet_capacity, ideal_level, sensors, verbose);

    // Push back dam c
    it++;
  }

  // Write out measurement file header
  output_file << "dam_name, timetsep, water_level" << endl;
}

template <typename SensorProvider>
void DamSim<SensorProvider>::start()
{
  if (verbose) {
    cout << "I'm verbose " << dam_def_file << endl;
  }

  cout << "Staring simulation for " << num_timesteps << " timesteps" << endl;

  do_timesteps();

  cout << "Simualtion ended after " << num_timesteps << " timesteps" << endl;

  // Keep plot window visible after simulation is done
  if (plotter) {
    gui_main();
  }
}

// For testing Assignment S1 and S2, uncomment the line below
template class DamSim<SensorsRandom>;
template class DamSim<SensorsFile>;
