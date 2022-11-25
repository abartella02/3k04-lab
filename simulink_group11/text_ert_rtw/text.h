/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: text.h
 *
 * Code generated for Simulink model 'text'.
 *
 * Model version                  : 1.98
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 25 07:28:28 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_text_h_
#define RTW_HEADER_text_h_
#ifndef text_COMMON_INCLUDES_
#define text_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_AnalogIn.h"
#include "MW_digitalIO.h"
#include "MW_SCI.h"
#endif                                 /* text_COMMON_INCLUDES_ */

#include "text_types.h"
#include <stddef.h>
#include "Send_DCM.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[66];
  uint8_T RxDataLocChar[66];
  uint8_T TxDataLocChar[64];
  uint8_T TmpSignalConversionAtSerial[64];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  real_T ATR_AMP_REG;
  real_T VENT_AMP_REG;
  real_T ATR_PW;
  real_T VENT_PW;
  real_T ATR_SENSITIVITY;
  real_T VENT_SENSITIVITY;
  real_T TmpLatchAtATR_SIGNALOutport1;
  real_T TmpLatchAtVENT_SIGNALOutport1;
  real_T VENT_SIGNAL;                  /* '<Root>/VENT_SIGNAL' */
  real_T ATR_AMP_REG_f;                /* '<Root>/Serial Communication1' */
  real_T ATR_PW_n;                     /* '<Root>/Serial Communication1' */
  real_T VENT_SENSITIVITY_b;           /* '<Root>/Serial Communication1' */
  real_T VENT_AMP_REG_o;               /* '<Root>/Serial Communication1' */
  real_T VENT_PW_n;                    /* '<Root>/Serial Communication1' */
  real_T ATR_SENSITIVITY_l;            /* '<Root>/Serial Communication1' */
  real_T ATR_SIGNAL;                   /* '<Root>/ATR_SIGNAL' */
  uint16_T MODE;
  uint16_T LOWER_RATE_LIMIT;
  uint16_T UPPER_RATE_LIMIT;
  uint16_T VENT_REF_PERIOD;
  uint16_T ATR_REF_PERIOD;
  uint16_T PVARP;
  uint16_T HYSTERESIS_RATE_LIMIT;
  uint16_T RATE_SMOOTHING;
  uint16_T MODE_n;                     /* '<Root>/Serial Communication1' */
  uint16_T LOWER_RATE_LIMIT_e;         /* '<Root>/Serial Communication1' */
  uint16_T UPPER_RATE_LIMIT_g;         /* '<Root>/Serial Communication1' */
  uint16_T VENT_REF_PERIOD_j;          /* '<Root>/Serial Communication1' */
  uint16_T PVARP_c;                    /* '<Root>/Serial Communication1' */
  uint16_T RATE_SMOOTHING_d;           /* '<Root>/Serial Communication1' */
  uint16_T HYSTERESIS_RATE_LIMIT_c;    /* '<Root>/Serial Communication1' */
  uint16_T ATR_REF_PERIOD_h;           /* '<Root>/Serial Communication1' */
  uint8_T BytePack[2];                 /* '<S2>/Byte Pack' */
  uint8_T BytePack1[2];                /* '<S2>/Byte Pack1' */
  uint8_T BytePack7[2];                /* '<S2>/Byte Pack7' */
  uint8_T BytePack2[8];                /* '<S2>/Byte Pack2' */
  uint8_T BytePack3[8];                /* '<S2>/Byte Pack3' */
  uint8_T BytePack4[8];                /* '<S2>/Byte Pack4' */
  uint8_T BytePack5[8];                /* '<S2>/Byte Pack5' */
  uint8_T BytePack6[8];                /* '<S2>/Byte Pack6' */
  uint8_T BytePack8[8];                /* '<S2>/Byte Pack8' */
  uint8_T BytePack9[2];                /* '<S2>/Byte Pack9' */
  uint8_T BytePack10[2];               /* '<S2>/Byte Pack10' */
  uint8_T BytePack11[2];               /* '<S2>/Byte Pack11' */
  uint8_T BytePack12[2];               /* '<S2>/Byte Pack12' */
  uint8_T BytePack13[2];               /* '<S2>/Byte Pack13' */
  uint8_T BytePack14[8];               /* '<S2>/Byte Pack14' */
  uint8_T BytePack15[8];               /* '<S2>/Byte Pack15' */
} B_text_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_text_T obj;  /* '<Root>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_text_T obj_n;/* '<Root>/ATR_SIGNAL' */
  freedomk64f_DigitalRead_text_T obj_o;/* '<Root>/Digital Read1' */
  freedomk64f_DigitalRead_text_T obj_a;/* '<Root>/Digital Read' */
  freedomk64f_SCIRead_text_T obj_k;    /* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_text_T obj_h;   /* '<S2>/Serial Transmit' */
  uint8_T is_active_c1_text;           /* '<Root>/Serial Communication1' */
  uint8_T is_c1_text;                  /* '<Root>/Serial Communication1' */
} DW_text_T;

/* Parameters (default storage) */
struct P_text_T_ {
  real_T ATR_SIGNAL_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<Root>/ATR_SIGNAL'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T VENT_SIGNAL_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/VENT_SIGNAL'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_text_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_text_T text_P;

/* Block signals (default storage) */
extern B_text_T text_B;

/* Block states (default storage) */
extern DW_text_T text_DW;

/* Model entry point functions */
extern void text_initialize(void);
extern void text_step(void);
extern void text_terminate(void);

/* Real-time Model object */
extern RT_MODEL_text_T *const text_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Switch' : Unused code path elimination
 */

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
 * '<Root>' : 'text'
 * '<S1>'   : 'text/Serial Communication1'
 * '<S2>'   : 'text/Serial transmit'
 */
#endif                                 /* RTW_HEADER_text_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
