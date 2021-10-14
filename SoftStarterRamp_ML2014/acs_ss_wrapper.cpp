
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "TF/integrator.h"
#include "TF/differentiator.h"
#include <memory>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
const int NUM_PHASE = 3; 

int meandr[NUM_PHASE];
int& meandrA = meandr[0];
int& meandrB = meandr[1];
int& meandrC = meandr[2];

CDifferentiator* diff[NUM_PHASE];
CIntegrator* triangle[NUM_PHASE];
CIntegrator* refQ;

iq_t Uy[NUM_PHASE]{0};
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void acs_ss_Start_wrapper(const real_T *Ts_, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
for (int i = 0; i < NUM_PHASE; i++){
    diff[i] = new CDifferentiator(IQ(Ts_[0]), IQ(10000), -IQ(10000));
    triangle[i] = new CIntegrator(IQ(Ts_[0]), IQ(1), IQ(100), -IQ(100));
}

refQ = new CIntegrator(IQ(Ts_[0]), IQ(0.025), IQ(66.7), IQ(0));
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void acs_ss_Outputs_wrapper(const real_T *uABC,
			real_T *gains,
			real_T *outUy,
			real_T *outMeandr,
			const real_T *Ts_, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
double uA = -uABC[2];
double uB = -uABC[1];
double uC = -uABC[0];

meandrA = int(uA);
meandrB = int(uB);
meandrC = int(uC);

static const iq_t Uo = IQ(66.7);

static double timer = 0;
timer += Ts_[0];

auto lmbd = [](){
    static bool _isReconfig = false;
    
    if (timer >= 0.5 && !_isReconfig){
        refQ->Ti_set(IQ((3.0 - 0.5)/(66.7-20.0)));
        refQ->config_set();
        _isReconfig = true;
    }
    return refQ->out_est(IQ(1.0)); 
};

lmbd();

for (int i = 0; i < NUM_PHASE; i++){
    if (meandr[i] > 1) meandr[i] = 1;
    else if (meandr[i] < -1) meandr[i] = -1;
    
    diff[i]->out_est(meandr[i]);
    meandr[i] *= 10000;
    
    if ( diff[i]->out_get() > IQ(1) ||  diff[i]->out_get() < -IQ(1)){
        triangle[i]->reset();
    }
    triangle[i]->out_est(meandr[i]);
    
    Uy[i] = Uo - refQ->out_get();
    
    gains[2*i] = (std::abs(triangle[i]->out_get()) - Uy[i] > 0) && (meandr[i] > 0);
    gains[2*i+1] = (std::abs(triangle[i]->out_get() - Uy[i]) > 0) && (meandr[i] < 0);
    
    outUy[i] = (std::abs(triangle[i]->out_get()) - Uy[i] > 0);
    outMeandr[i] = meandr[i];
    
}


/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


