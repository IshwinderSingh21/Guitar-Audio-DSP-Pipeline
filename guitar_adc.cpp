
//
// File: guitar_adc.cpp
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
#include "guitar_adc.h"
#include <math.h>
#include <float.h>
#include "guitar_adc_types.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include <emmintrin.h>
#include "guitar_adc_private.h"

void guitar_adc::reverberator_setPlateClassRever(audio_simulink_Reverberator_g_T
  *obj)
{
  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.PreDelay = obj->PreDelay;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.InputDiffusion1 = obj->Diffusion;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.InputDiffusion2 = obj->Diffusion;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.DecayDiffusion1 = obj->Diffusion;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.DecayDiffusion2 = obj->Diffusion;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.Decay = 1.0 - obj->DecayFactor;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.Damping = obj->HighFrequencyDamping;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (obj->pcr.isInitialized == 1) {
    obj->pcr.TunablePropsChanged = true;
  }

  obj->pcr.WetDryMix = obj->WetDryMix;
}

void guitar_adc::PlateClassReverberator_setSRInd(e_audio_internal_PlateClassRe_T
  *obj)
{
  obj->pSRIndependentProperties.PreDelay = obj->PreDelay;
  obj->pSRIndependentProperties.Bandwidth = obj->Bandwidth;
  obj->pSRIndependentProperties.InputDiffusion1 = obj->InputDiffusion1;
  obj->pSRIndependentProperties.InputDiffusion2 = obj->InputDiffusion2;
  obj->pSRIndependentProperties.Decay = obj->Decay;
  obj->pSRIndependentProperties.DecayDiffusion1 = obj->DecayDiffusion1;
  obj->pSRIndependentProperties.DecayDiffusion2 = obj->DecayDiffusion2;
  obj->pSRIndependentProperties.Damping = obj->Damping;
}

void guitar_adc::PlateClassReverberator_setSRDep(e_audio_internal_PlateClassRe_T
  *obj, real_T SR)
{
  obj->pSRDependentProperties.SampleRate = SR;

  // Start for MATLABSystem: '<Root>/Reverberator'
  obj->pSRDependentProperties.Excursion = std::round(0.00026880817176842174 * SR);
  obj->pSRDependentProperties.AP5DelayLength = std::round(0.02284869460031585 *
    SR);
  obj->pSRDependentProperties.AP7DelayLength = std::round(0.030778535667484293 *
    SR);
  obj->pSRDependentProperties.LtapD4_1 = std::round(0.008937871711300024 * SR);
  obj->pSRDependentProperties.LtapD4_2 = std::round(0.09992943785491079 * SR);
  obj->pSRDependentProperties.LtapAP8 = std::round(0.06427875407412385 * SR);
  obj->pSRDependentProperties.LtapD5 = std::round(0.06706763885622123 * SR);
  obj->pSRDependentProperties.LtapD2 = std::round(0.06686603272739491 * SR);
  obj->pSRDependentProperties.LtapAP6 = std::round(0.006283391015086859 * SR);
  obj->pSRDependentProperties.LtapD3 = std::round(0.0358186888881422 * SR);
  obj->pSRDependentProperties.RtapD2_1 = std::round(0.01186116057928161 * SR);
  obj->pSRDependentProperties.RtapD2_2 = std::round(0.12187090487550821 * SR);
  obj->pSRDependentProperties.RtapAP6 = std::round(0.04126205436645274 * SR);
  obj->pSRDependentProperties.RtapD3 = std::round(0.08981553039212392 * SR);
  obj->pSRDependentProperties.RtapD4 = std::round(0.0709317563253923 * SR);
  obj->pSRDependentProperties.RtapAP8 = std::round(0.011256342192802662 * SR);
  obj->pSRDependentProperties.RtapD5 = std::round(0.004065723597997379 * SR);
}

void guitar_adc::PlateClassReverberator_processT(e_audio_internal_PlateClassRe_T
  *obj)
{
  real_T ptr;
  PlateClassReverberator_setSRInd(obj);

  // Start for MATLABSystem: '<Root>/Reverberator'
  ptr = obj->pStates.D1WritePtr - std::round(obj->PreDelay * obj->SampleRate);
  obj->pStates.D1ReadPtr = ptr;

  // Start for MATLABSystem: '<Root>/Reverberator'
  if (ptr < 1.0) {
    obj->pStates.D1ReadPtr = ptr + 192000.0;
  }

  if (obj->pSampleRateCache != obj->SampleRate) {
    PlateClassReverberator_setSRDep(obj, obj->SampleRate);

    // Start for MATLABSystem: '<Root>/Reverberator'
    ptr = obj->pStates.D2WritePtr - std::round(0.14962534861059776 *
      obj->SampleRate);
    obj->pStates.D2ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.D2ReadPtr = ptr + 28728.0;
    }

    ptr = obj->pStates.D3WritePtr - std::round(0.12499579987231611 *
      obj->SampleRate);
    obj->pStates.D3ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.D3ReadPtr = ptr + 23999.0;
    }

    ptr = obj->pStates.D4WritePtr - std::round(0.14169550754342933 *
      obj->SampleRate);
    obj->pStates.D4ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.D4ReadPtr = ptr + 27206.0;
    }

    ptr = obj->pStates.D5WritePtr - std::round(0.10628003091293975 *
      obj->SampleRate);
    obj->pStates.D5ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.D5ReadPtr = ptr + 20406.0;
    }

    ptr = obj->pStates.AP1WritePtr - std::round(0.004771345048889486 *
      obj->SampleRate);
    obj->pStates.AP1ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.AP1ReadPtr = ptr + 916.0;
    }

    ptr = obj->pStates.AP2WritePtr - std::round(0.0035953092974026412 *
      obj->SampleRate);
    obj->pStates.AP2ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
      obj->pStates.AP2ReadPtr = ptr + 690.0;
    }

    ptr = obj->pStates.AP3WritePtr - std::round(0.01273478713752898 *
      obj->SampleRate);
    obj->pStates.AP3ReadPtr = ptr;

    // Start for MATLABSystem: '<Root>/Reverberator'
    if (ptr < 1.0) {
has popup
