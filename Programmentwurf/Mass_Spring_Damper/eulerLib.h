#ifndef EULERLIB_H_
#define EULERLIB_H_
/** 
    \STRUCT: simHandle
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: definition of handle to simulate first order ode-system as struct

    \CONTAINS:  [void* f] rhs-function

                [double* stateVec] states-array for all timesteps (t_0 ... t_end)

                [double* stateVecInit] states-array with initial states (t = 0)

                [double* derivStateVec] derivative-array for all timesteps (t_0 ... t_end)

                [int numOfStates]: number of states in ode-system (two for mass-spring-damper-system)

                [double stepSize]: timestepsize in seconds seconds for explicit euler method

                [double simTime]: simTime in seconds for explicit euler method

*/
struct SimHandle {
    void(*f)(double*, double*);
    double* stateVec;
    double* stateVecInit;
    double* derivStateVec;
    int numOfStates;
    double stepSize;
    double simTime;
};
typedef struct SimHandle simHandle;

/** 
    \FUNCTION: RHS_MSD
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: right-hand-side of mass spring damper system
 
    \param[in]  reference to current state vector for 2D first oder ode

    \param[in]  reference to storage vector for derivatives [out]
*/
void RHS_MSD(double*, double*);

/** 
    \FUNCTION: eulerForward
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: explicit euler function to solve first order ode-system
 
    \param[in]  reference to simHandle 

*/
void eulerForward(simHandle*);

/** 
    \FUNCTION: showResults_MSD
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: visualize the results of given ode-system solved by given used sim method
 
    \param[in]  reference to simHandle 

*/
void showResults_MSD(simHandle*);

/** 
    \FUNCTION: eulerSettings_MSD
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: initialize simHandle by user defined specs
 
    \param[in]  reference to simHandle 

*/
void eulerSettings_MSD(simHandle*);

#endif