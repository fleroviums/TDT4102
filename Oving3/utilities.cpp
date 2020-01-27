#include "std_lib_facilities.h"


int randomWithLimits(int lowerLim, int upperLim){
    int rNum = 0;
    rNum = rand() % (upperLim+1-lowerLim) + lowerLim; //Should produce between lowerLim and upperlim
    return rNum; // The +1 makes it closed set, so that upperLim may be returned as well
}