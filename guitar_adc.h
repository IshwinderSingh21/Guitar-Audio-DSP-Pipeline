
//
// File: guitar_adc.h
//
// Code generated for Simulink model 'guitar_adc'.
//
// Model version                  : 1.5
// Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
// C/C++ source code generated on : Tue Jun 30 18:02:45 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef GUITAR_ADC_H_
#define GUITAR_ADC_H_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "guitar_adc_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

// Class declaration for model guitar_adc
class guitar_adc final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_guitar_adc_T {
    real_T D1DelayLine[192000];
    real_T D2DelayLine[28728];
    real_T z[28728];
    real_T D4DelayLine[27206];
    real_T z_m[27206];
    real_T D3DelayLine[23999];
    real_T z_c[23999];
    real_T D5DelayLine[20406];
    real_T AP8DelayLine[17135];
    real_T z_k[17135];
    real_T AP6DelayLine[11613];
    real_T z_cx[11613];
    real_T z_b[2445];
    real_T z_p[916];
    real_T z_cv[690];
    real_T FromWorkspace;              // '<Root>/From Workspace'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_guitar_adc_T {
    audio_simulink_Reverberator_g_T obj;// '<Root>/Reverberator'
    struct {
      void *TimePtr;
      void *DataPtr;
      void *RSimInfoPtr;
    } FromWorkspace_PWORK;             // '<Root>/From Workspace'

    struct {
      int_T PrevIndex;
    } FromWorkspace_IWORK;             // '<Root>/From Workspace'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_guitar_adc_T {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
has popup
