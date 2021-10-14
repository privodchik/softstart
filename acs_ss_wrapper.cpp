
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
#include "ss_file.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
const int NUM_PHASE = 3; 

iq_t meandr[NUM_PHASE];
iq_t& meandrA = meandr[0];
iq_t& meandrB = meandr[1];
iq_t& meandrC = meandr[2];

CDifferentiator* diff[NUM_PHASE];
CIntegrator* triangle[NUM_PHASE];
CIntegrator* refQ;

iq_t Uy[NUM_PHASE]{0};
CUabc uABC;
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
void acs_ss_Outputs_wrapper(const real_T *Vabc,
			real_T *gains,
			real_T *out,
			real_T *out2,
			const real_T *Ts_, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
uABC = v2u( Vabc[0], Vabc[1], Vabc[2] );

meandrA = uABC.uA;
meandrB = uABC.uB;
meandrC = uABC.uC;

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
    
    meandr[i] = sin2meandr(meandr[i], IQ(20));
    
    if ( 0 == meandr[i] ) triangle[i]->reset();
    
    meandr[i] *= 10000;
    
    triangle[i]->out_est(meandr[i]);
    
    Uy[i] = Uo - refQ->out_get();
    
    out[i] = Uy[i];
    out2[i] = std::abs(triangle[i]->out_get());
    
    gains[2*i] = (std::abs(triangle[i]->out_get()) - Uy[i] > 0) && (meandr[i] > 0);
    gains[2*i+1] = (std::abs(triangle[i]->out_get()) - Uy[i] > 0) && (meandr[i] < 0);
        
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


