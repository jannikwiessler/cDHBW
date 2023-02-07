#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

    simHandle myHandle;
    simHandle *handle = &myHandle;
    eulerSettings_MSD(handle);
    eulerForward(handle);
    showResults_MSD(handle);

    return 0;
}