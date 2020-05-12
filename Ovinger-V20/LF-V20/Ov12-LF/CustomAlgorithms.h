#pragma once
#include "utilities.h"
#include <FL/fl_draw.H>

using drivingAlgorithm = std::pair<double, double> (const PhysicsState & ps, const std::vector<std::pair<double, double>> & goals, int currentGoal);

drivingAlgorithm control;
drivingAlgorithm control2;

// Dette er berre eksemplar ulik algoritmer, og er ikkje relevante

drivingAlgorithm dumb;
drivingAlgorithm simple;
drivingAlgorithm better;
drivingAlgorithm another;