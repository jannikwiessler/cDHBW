#include "eulerLib.h"
/*******************************************************
* NAME: main.c (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2021-01-10
*
* DESCRIPTION:  implementation of simple explicit euler method to solve first order ode system
*               mass spring damper system
*
* DEPENDENCIES: eulerLib.h
                gnuplot in PATH
*
* INFO: For DHBW use only.
*   >> Practice of explicit euler method
*
**/
int main()
{

    SimulationHandle handle = getHandle();
    calculateSimulation(&handle);
    plotSimulation(&handle);

    return 0;
}
