#include <stdio.h>
#include <math.h>
#include "eulerLib.h"

SimulationState massSpringDamperCalculation(SimulationState state, double duration)
{ // mass spring damper

    double m = 1.0;  // mass of object
    double c = 5;    // spring constant
    double d = 0.25; // damper constant

    double x = state.position;
    double v = state.velocity;

    /*calc derivatives and store in rhs*/

    /* YOUR CODE HERE */
    /* ---------------*/
}

SimulationHandle getHandle()
{

    /*num of states*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*right hand site*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*reserve storage for init state vec*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get user defined simulation time*/
    printf("Simulation time (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get user defined step size*/
    printf("Step size (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state position*/
    printf("position(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state speed*/
    printf("speed(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*reserve storage for states and derivatives*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*init states and derivatives with zero*/

    /* YOUR CODE HERE */
    /* ---------------*/
}

void calculateSimulation(const SimulationHandle *handle)
{ // this is called only once
    int integratorSteps = (int)ceil(handle->duration / handle->stepSize);

    /*write init states*/
    for (int i = 0; i < handle->stateCount; i++)
    {
        handle->states[i] = handle->initialState;
    }

    for (int i = 0; i < integratorSteps; i++)
    {
        /*get derivatives*/

        /* YOUR CODE HERE */
        /* ---------------*/
    }
}

void plotSimulation(SimulationHandle *)
{

    /*print data to text file*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*call gnuplot*/

    /* YOUR CODE HERE */
    /* ---------------*/
}
