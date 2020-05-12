#include "utilities.h"

int randomWithLimits(int lower, int upper) {
	return lower + (rand() % (upper - lower + 1));
}
