#ifndef EULERLIB_H_
#define EULERLIB_H_
/** 
    \STRUCT: SimulationHandle
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: definition of handle to simulate first order ode-system as struct

    \CONTAINS:  [void* function] rhs-function

                [double* stateVec] states-array for all timesteps (t_0 ... t_end)

                [double* stateVecInit] states-array with initial states (t = 0)

                [double* derivationStateVec] derivative-array for all timesteps (t_0 ... t_end)

                [int numOfStates]: number of states in ode-system (two for mass-spring-damper-system)

                [double stepSize]: timestepsize in seconds seconds for explicit euler method

                [double simTime]: duration in seconds for explicit euler method

*/

typedef void(*SimulationCalculation)(double *, double*);

typedef struct {
    SimulationCalculation function;
    double* stateVec;
    double* stateVecInit;
    double* derivationStateVec;
    int numOfStates;
    double stepSize;
    double duration;
} SimulationHandle;

/** 
    \FUNCTION: massSpringDamperCalculation
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: right-hand-side of mass spring damper system
 
    \param[in]  reference to current state vector for 2D first oder ode

    \param[in]  reference to storage vector for derivatives [out]
*/
void massSpringDamperCalculation(double*, double*);

/** 
    \FUNCTION: calculateSimulation
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: explicit euler function to solve first order ode-system
 
    \param[in]  reference to SimulationHandle

*/
void calculateSimulation(SimulationHandle*);

/** 
    \FUNCTION: plotSimulation
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: visualize the results of given ode-system solved by given used sim method
 
    \param[in]  reference to SimulationHandle

*/
void plotSimulation(SimulationHandle*);

/** 
    \FUNCTION: getHandle
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: initialize SimulationHandle by user defined specs
 
    \param[in]  reference to SimulationHandle

*/
SimulationHandle getHandle();

#endif
