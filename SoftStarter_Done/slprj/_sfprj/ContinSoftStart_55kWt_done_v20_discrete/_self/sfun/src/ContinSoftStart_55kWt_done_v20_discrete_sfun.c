/* Include files */

#include "ContinSoftStart_55kWt_done_v20_discrete_sfun.h"
#include "ContinSoftStart_55kWt_done_v20_discrete_sfun_debug_macros.h"
#include "c4_ContinSoftStart_55kWt_done_v20_discrete.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ContinSoftStart_55kWt_done_v20_discreteMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void ContinSoftStart_55kWt_done_v20_discrete_initializer(void)
{
}

void ContinSoftStart_55kWt_done_v20_discrete_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ContinSoftStart_55kWt_done_v20_discrete_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  if (chartFileNumber==4) {
    c4_ContinSoftStart_55kWt_done_v20_discrete_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ContinSoftStart_55kWt_done_v20_discrete_process_check_sum_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2855536562U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3288069566U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1287145819U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4013329821U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(231783257U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(68708775U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1419931538U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4058842258U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 4:
        {
          extern void
            sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_check_sum(mxArray *
            plhs[]);
          sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2004189108U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1605497660U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(545526104U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(197773630U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ContinSoftStart_55kWt_done_v20_discrete_autoinheritance_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(aiChksum, "DyVLIVookqmxFt6XRxkN4B") == 0) {
          extern mxArray
            *sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_ContinSoftStart_55kWt_done_v20_discrete_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        extern const mxArray
          *sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ContinSoftStart_55kWt_done_v20_discrete_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ContinSoftStart_55kWt_done_v20_discrete_third_party_uses_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(tpChksum, "MvgQTP4ADUXY0xYk5LmO9G") == 0) {
          extern mxArray
            *sf_c4_ContinSoftStart_55kWt_done_v20_discrete_third_party_uses_info
            (void);
          plhs[0] =
            sf_c4_ContinSoftStart_55kWt_done_v20_discrete_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int
  sf_ContinSoftStart_55kWt_done_v20_discrete_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(tpChksum, "MvgQTP4ADUXY0xYk5LmO9G") == 0) {
          extern mxArray
            *sf_c4_ContinSoftStart_55kWt_done_v20_discrete_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c4_ContinSoftStart_55kWt_done_v20_discrete_updateBuildInfo_args_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void ContinSoftStart_55kWt_done_v20_discrete_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _ContinSoftStart_55kWt_done_v20_discreteMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "ContinSoftStart_55kWt_done_v20_discrete","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _ContinSoftStart_55kWt_done_v20_discreteMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _ContinSoftStart_55kWt_done_v20_discreteMachineNumber_,0);
}

void ContinSoftStart_55kWt_done_v20_discrete_register_exported_symbols(SimStruct*
  S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ContinSoftStart_55kWt_done_v20_discrete_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "ContinSoftStart_55kWt_done_v20_discrete",
      "ContinSoftStart_55kWt_done_v20_discrete");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ContinSoftStart_55kWt_done_v20_discrete_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}