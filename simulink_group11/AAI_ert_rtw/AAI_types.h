/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI_types.h
 *
 * Code generated for Simulink model 'AAI'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 23 15:07:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AAI_types_h_
#define RTW_HEADER_AAI_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_slTestResult_
#define DEFINED_TYPEDEF_FOR_slTestResult_

typedef enum {
  slTestResult_Untested = -1,          /* Default value */
  slTestResult_Pass,
  slTestResult_Fail
} slTestResult;

#endif

/* Custom Type definition for MATLABSystem: '<Root>/PWM Output2' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_AAI_T
#define typedef_b_freedomk64f_Hardware_AAI_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_AAI_T;

#endif                                /* typedef_b_freedomk64f_Hardware_AAI_T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_AAI_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_AAI_T
#define typedef_freedomk64f_DigitalRead_AAI_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_AAI_T;

#endif                               /* typedef_freedomk64f_DigitalRead_AAI_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_AAI_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_AAI_T
#define typedef_freedomk64f_DigitalWrite_AAI_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_AAI_T;

#endif                              /* typedef_freedomk64f_DigitalWrite_AAI_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_AAI_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_AAI_T
#define typedef_freedomk64f_PWMOutput_AAI_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_AAI_T;

#endif                                 /* typedef_freedomk64f_PWMOutput_AAI_T */

/* Parameters (default storage) */
typedef struct P_AAI_T_ P_AAI_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AAI_T RT_MODEL_AAI_T;

#endif                                 /* RTW_HEADER_AAI_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
