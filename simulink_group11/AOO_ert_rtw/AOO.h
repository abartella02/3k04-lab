/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AOO.h
 *
 * Code generated for Simulink model 'AOO'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 23 15:10:12 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AOO_h_
#define RTW_HEADER_AOO_h_
#ifndef AOO_COMMON_INCLUDES_
#define AOO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* AOO_COMMON_INCLUDES_ */

#include "AOO_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T VENT_CMP_REF_PWM;             /* '<Root>/AAI' */
  real_T PACING_REF_PWM;               /* '<Root>/AAI' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/AAI' */
  boolean_T IS_CHARGING;               /* '<Root>/AAI' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/AAI' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/AAI' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/AAI' */
} B_AOO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_AOO_T obj;  /* '<Root>/Digital Write9' */
  freedomk64f_DigitalWrite_AOO_T obj_n;/* '<Root>/Digital Write8' */
  freedomk64f_DigitalWrite_AOO_T obj_i;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_AOO_T obj_b;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_AOO_T obj_h;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_AOO_T obj_l;/* '<Root>/Digital Write12' */
  freedomk64f_DigitalWrite_AOO_T obj_nv;/* '<Root>/Digital Write11' */
  freedomk64f_DigitalWrite_AOO_T obj_ii;/* '<Root>/Digital Write10' */
  freedomk64f_DigitalWrite_AOO_T obj_m;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_AOO_T obj_hb;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_AOO_T obj_a;   /* '<Root>/PWM Output2' */
  freedomk64f_PWMOutput_AOO_T obj_bs;  /* '<Root>/PWM Output1' */
  freedomk64f_PWMOutput_AOO_T obj_d;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/AAI' */
  uint8_T is_active_c3_AOO;            /* '<Root>/AAI' */
  uint8_T is_c3_AOO;                   /* '<Root>/AAI' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/Requirements Table' */
} DW_AOO_T;

/* Parameters (default storage) */
struct P_AOO_T_ {
  real_T PWM_Value;                    /* Expression: 80
                                        * Referenced by: '<Root>/PWM'
                                        */
  real_T Constant1_Value;              /* Expression: 54
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T msec_Value;                   /* Expression: 60000
                                        * Referenced by: '<Root>/msec'
                                        */
  real_T BPM_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/BPM'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AOO_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_AOO_T AOO_P;

/* Block signals (default storage) */
extern B_AOO_T AOO_B;

/* Block states (default storage) */
extern DW_AOO_T AOO_DW;

/* Model entry point functions */
extern void AOO_initialize(void);
extern void AOO_step(void);
extern void AOO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AOO_T *const AOO_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AOO'
 * '<S1>'   : 'AOO/AAI'
 * '<S2>'   : 'AOO/Requirements Table'
 */
#endif                                 /* RTW_HEADER_AOO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
