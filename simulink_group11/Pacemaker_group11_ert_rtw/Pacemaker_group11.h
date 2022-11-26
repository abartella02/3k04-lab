/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_group11.h
 *
 * Code generated for Simulink model 'Pacemaker_group11'.
 *
 * Model version                  : 1.99
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Nov 26 05:47:22 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_group11_h_
#define RTW_HEADER_Pacemaker_group11_h_
#ifndef Pacemaker_group11_COMMON_INCLUDES_
#define Pacemaker_group11_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_AnalogIn.h"
#include "MW_digitalIO.h"
#include "MW_SCI.h"
#include "MW_PWM.h"
#endif                                 /* Pacemaker_group11_COMMON_INCLUDES_ */

#include "Pacemaker_group11_types.h"
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
  uint8_T Switch[64];                  /* '<S2>/Switch' */
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  real_T ATR_AMP_REG;
  real_T VENT_AMP_REG;
  real_T ATR_PW;
  real_T VENT_PW;
  real_T ATR_SENSITIVITY;
  real_T VENT_SENSITIVITY;
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T PACING_REF_PWM;               /* '<Root>/eight model stateflow' */
  real_T VENT_SIGNAL;                  /* '<Root>/VENT_SIGNAL' */
  real_T ATR_AMP_REG_f;                /* '<Root>/Serial Communication1' */
  real_T ATR_PW_n;                     /* '<Root>/Serial Communication1' */
  real_T VENT_SENSITIVITY_b;           /* '<Root>/Serial Communication1' */
  real_T VENT_AMP_REG_o;               /* '<Root>/Serial Communication1' */
  real_T VENT_PW_n;                    /* '<Root>/Serial Communication1' */
  real_T ATR_SENSITIVITY_l;            /* '<Root>/Serial Communication1' */
  real_T Type;                         /* '<Root>/Serial Communication1' */
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
  uint8_T BytePack22[8];               /* '<S2>/Byte Pack22' */
  uint8_T BytePack23[8];               /* '<S2>/Byte Pack23' */
  uint8_T BytePack24[8];               /* '<S2>/Byte Pack24' */
  boolean_T IS_CHARGING;               /* '<Root>/eight model stateflow' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/eight model stateflow' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/eight model stateflow' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/eight model stateflow' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/eight model stateflow' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/eight model stateflow' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/eight model stateflow' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/eight model stateflow' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/eight model stateflow' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/eight model stateflow' */
} B_Pacemaker_group11_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_Pacem_T obj; /* '<Root>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_Pacem_T obj_n;/* '<Root>/ATR_SIGNAL' */
  freedomk64f_DigitalRead_Pacem_T obj_o;/* '<Root>/Digital Read1' */
  freedomk64f_DigitalRead_Pacem_T obj_a;/* '<Root>/Digital Read' */
  freedomk64f_SCIRead_Pacemaker_T obj_k;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Pacemake_T obj_h;/* '<S2>/Serial Transmit' */
  freedomk64f_DigitalWrite_Pace_T obj_j;/* '<S3>/Digital Write9' */
  freedomk64f_DigitalWrite_Pace_T obj_n2;/* '<S3>/Digital Write8' */
  freedomk64f_DigitalWrite_Pace_T obj_i;/* '<S3>/Digital Write7' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_Pace_T obj_hy;/* '<S3>/Digital Write2' */
  freedomk64f_DigitalWrite_Pace_T obj_l;/* '<S3>/Digital Write12' */
  freedomk64f_DigitalWrite_Pace_T obj_nv;/* '<S3>/Digital Write11' */
  freedomk64f_DigitalWrite_Pace_T obj_ii;/* '<S3>/Digital Write10' */
  freedomk64f_DigitalWrite_Pace_T obj_m;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_Pace_T obj_hb;/* '<S3>/Digital Write' */
  freedomk64f_PWMOutput_Pacemak_T obj_ac;/* '<S3>/PWM Output2' */
  freedomk64f_PWMOutput_Pacemak_T obj_bs;/* '<S3>/PWM Output1' */
  freedomk64f_PWMOutput_Pacemak_T obj_d;/* '<S3>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/eight model stateflow' */
  uint16_T DELAY;                      /* '<Root>/eight model stateflow' */
  uint8_T is_active_c3_Pacemaker_group11;/* '<Root>/eight model stateflow' */
  uint8_T is_c3_Pacemaker_group11;     /* '<Root>/eight model stateflow' */
  uint8_T is_active_c1_Pacemaker_group11;/* '<Root>/Serial Communication1' */
  uint8_T is_c1_Pacemaker_group11;     /* '<Root>/Serial Communication1' */
} DW_Pacemaker_group11_T;

/* Parameters (default storage) */
struct P_Pacemaker_group11_T_ {
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
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T empty1_Value;                 /* Expression: 0
                                        * Referenced by: '<S2>/empty1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Voltage_Value;                /* Expression: 5
                                        * Referenced by: '<S4>/Voltage'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S4>/Multiply1'
                                        */
  real_T msecmin_Value;                /* Expression: 60000
                                        * Referenced by: '<S4>/msec//min'
                                        */
  real_T Multiply_Gain;                /* Expression: 100
                                        * Referenced by: '<S4>/Multiply'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value_i;             /* Expression: 3.3
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 100
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_group11_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Pacemaker_group11_T Pacemaker_group11_P;

/* Block signals (default storage) */
extern B_Pacemaker_group11_T Pacemaker_group11_B;

/* Block states (default storage) */
extern DW_Pacemaker_group11_T Pacemaker_group11_DW;

/* Model entry point functions */
extern void Pacemaker_group11_initialize(void);
extern void Pacemaker_group11_step(void);
extern void Pacemaker_group11_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_group11_T *const Pacemaker_group11_M;

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
 * '<Root>' : 'Pacemaker_group11'
 * '<S1>'   : 'Pacemaker_group11/Serial Communication1'
 * '<S2>'   : 'Pacemaker_group11/Serial transmit'
 * '<S3>'   : 'Pacemaker_group11/Subsystem'
 * '<S4>'   : 'Pacemaker_group11/Subsystem1'
 * '<S5>'   : 'Pacemaker_group11/eight model stateflow'
 */
#endif                                 /* RTW_HEADER_Pacemaker_group11_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
