#include "utilities.h"
#include "std_lib_facilities.h"

double randomWithLimits(int nedre, int ovre){
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(nedre, ovre);

    double number = distribution(generator);
    return number;
} 

