#include <iostream>
#include <iomanip>
#include "constants.h"

void printConstants()
{
    std::cout << "Ellipsoid constants: " << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;
    std::cout << std::setprecision(16);
    std::cout << "GRS80 Semi Major Axis (m):\tff" << GRS80.mSemiMajorAxis << std::endl;
    std::cout << "GRS80 Inverse Flattening ratio:\t" << GRS80.ratioInverseFlattening << std::endl << std::endl;
    std::cout << "WGS84 Semi Major Axis (m):\t" << WGS84.mSemiMajorAxis << std::endl;
    std::cout << "WGS84 Inverse Flattening ratio:\t" << WGS84.ratioInverseFlattening << std::endl << std::endl;
    std::cout << "ANS Semi Major Axis (m):\t" << ANS.mSemiMajorAxis << std::endl;
    std::cout << "ANS Inverse Flattening ratio:\t" << ANS.ratioInverseFlattening << std::endl << std::endl;
    std::cout << "Clarke 1858 Semi Major Axis (m):\t" << CLARKE.mSemiMajorAxis << std::endl;
    std::cout << "Clarke 1858 Inverse Flattening ratio:\t" << CLARKE.ratioInverseFlattening << std::endl << std::endl;
}

void printInvalidInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input, please check and try again." << std::endl;
}

void runEastNorth2LatLong();
void runLatLong2EastNorth();

int main()
{
    //printConstants();
    //runEastNorth2LatLong();
    runLatLong2EastNorth();
    return 0;
}
