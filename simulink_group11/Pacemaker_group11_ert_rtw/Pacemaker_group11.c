/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_group11.c
 *
 * Code generated for Simulink model 'Pacemaker_group11'.
 *
 * Model version                  : 1.99
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Nov 26 03:40:39 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker_group11.h"
#include "Pacemaker_group11_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "Send_DCM.h"
#include "Send_DCM_private.h"

/* Named constants for Chart: '<Root>/Serial Communication1' */
#define Pacemaker__IN_SettingParameters ((uint8_T)5U)
#define Pacemaker_group11_IN_ECHO_PARAM ((uint8_T)1U)
#define Pacemaker_group11_IN_Init      ((uint8_T)3U)
#define Pacemaker_group11_IN_STANDBY   ((uint8_T)4U)
#define Pacemaker_group1_IN_ECHO_PARAM1 ((uint8_T)2U)

/* Named constants for Chart: '<Root>/eight model stateflow' */
#define Pacemak_IN_Charging_C22_nfjgbhx ((uint8_T)19U)
#define Pacemake_IN_Charging_C22_nfjgbh ((uint8_T)16U)
#define Pacemaker_IN_Charging_C22_nfjgb ((uint8_T)14U)
#define Pacemaker__IN_Charging_C22_nfjg ((uint8_T)12U)
#define Pacemaker_g_IN_Charging_C22_nfj ((uint8_T)9U)
#define Pacemaker_gr_IN_Charging_C22_nf ((uint8_T)7U)
#define Pacemaker_gro_IN_Charging_C22_n ((uint8_T)4U)
#define Pacemaker_gro_IN_Pacing_mqtejgx ((uint8_T)20U)
#define Pacemaker_grou_IN_Pacing_mqtejg ((uint8_T)17U)
#define Pacemaker_group11_IN_Pacing    ((uint8_T)2U)
#define Pacemaker_group11_IN_Pacing_m  ((uint8_T)5U)
#define Pacemaker_group11_IN_Pacing_mq ((uint8_T)8U)
#define Pacemaker_group11_IN_Pacing_mqt ((uint8_T)10U)
#define Pacemaker_group11_IN_Proxy     ((uint8_T)3U)
#define Pacemaker_group11_IN_Proxy_p   ((uint8_T)6U)
#define Pacemaker_group11_IN_Proxy_pv  ((uint8_T)18U)
#define Pacemaker_group11_IN_Proxy_pvm ((uint8_T)21U)
#define Pacemaker_group11_IN_Start     ((uint8_T)11U)
#define Pacemaker_group1_IN_Pacing_mqte ((uint8_T)13U)
#define Pacemaker_group_IN_Charging_C22 ((uint8_T)1U)
#define Pacemaker_group_IN_Pacing_mqtej ((uint8_T)15U)

/* Block signals (default storage) */
B_Pacemaker_group11_T Pacemaker_group11_B;

/* Block states (default storage) */
DW_Pacemaker_group11_T Pacemaker_group11_DW;

/* Real-time model */
static RT_MODEL_Pacemaker_group11_T Pacemaker_group11_M_;
RT_MODEL_Pacemaker_group11_T *const Pacemaker_group11_M = &Pacemaker_group11_M_;

/* Forward declaration for local functions */
static void Pa_enter_atomic_Charging_C22_f3(const real_T *Multiply1);
static void Pacemaker_group11_Charging_C22(const real_T *Multiply, const
  boolean_T *DigitalRead1, const real_T *Divide1);
static void Pacem_enter_atomic_Charging_C22(const real_T *Multiply);
static void Pacemaker_group1_Charging_C22_h(const real_T *Multiply, const
  boolean_T *DigitalRead1);
static void Pacemaker_group11_Pacing(const real_T *Multiply);
static void Pacemaker_group_Charging_C22_hw(const real_T *Divide1);
static void Pacemaker_grou_Charging_C22_hwp(void);
static void Pacemaker_group11_Start(const real_T *Multiply, const real_T
  *Multiply1);
static void Pacemaker_gro_Charging_C22_hwpq(const real_T *Divide1);
static void Pacemaker_gr_Charging_C22_hwpqo(void);
static void Pacemaker_g_Charging_C22_hwpqoa(const real_T *Multiply1, const
  boolean_T *DigitalRead, const real_T *Divide1);
static void Pacemaker_group11_Pacing_i(const real_T *Multiply1);
static void Pacemaker__Charging_C22_hwpqoa5(const real_T *Multiply1, const
  boolean_T *DigitalRead);
static void Pacemaker_group11_Pacing_iu(const real_T *Multiply1);
static void Pacemaker_gr_SystemCore_setup_d(freedomk64f_SCIRead_Pacemaker_T *obj);

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pa_enter_atomic_Charging_C22_f3(const real_T *Multiply1)
{
  Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group11_Charging_C22(const real_T *Multiply, const
  boolean_T *DigitalRead1, const real_T *Divide1)
{
  real_T tmp;
  uint16_T tmp_0;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
  if (*DigitalRead1) {
    Pacemaker_group11_DW.DELAY = Pacemaker_group11_B.ATR_REF_PERIOD_h;
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Proxy;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
  } else {
    tmp = rt_roundd_snf(*Divide1 - (real_T)Pacemaker_group11_B.ATR_REF_PERIOD_h);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint16_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (Pacemaker_group11_DW.temporalCounter_i1 >= tmp_0) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Pacing;
      Pacemaker_group11_DW.temporalCounter_i1 = 0U;
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
    } else if (Pacemaker_group11_B.MODE_n != 3) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
    }
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacem_enter_atomic_Charging_C22(const real_T *Multiply)
{
  Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group1_Charging_C22_h(const real_T *Multiply, const
  boolean_T *DigitalRead1)
{
  real_T tmp;
  uint16_T tmp_0;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
  if (*DigitalRead1) {
    Pacemaker_group11_DW.DELAY = Pacemaker_group11_B.ATR_REF_PERIOD_h;
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Proxy_p;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
  } else {
    /* Constant: '<Root>/Constant1' */
    tmp = rt_roundd_snf(Pacemaker_group11_P.Constant1_Value - (real_T)
                        Pacemaker_group11_B.ATR_REF_PERIOD_h);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint16_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (Pacemaker_group11_DW.temporalCounter_i1 >= tmp_0) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
        Pacemaker_group11_IN_Pacing_m;
      Pacemaker_group11_DW.temporalCounter_i1 = 0U;
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
    } else if (Pacemaker_group11_B.MODE_n != 7) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
    }
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group11_Pacing(const real_T *Multiply)
{
  real_T tmp;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = false;
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Pacemaker_group11_B.ATR_PW_n)) {
    tmp = rt_roundd_snf((real_T)Pacemaker_group11_B.ATR_REF_PERIOD_h -
                        Pacemaker_group11_B.ATR_PW_n);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        Pacemaker_group11_DW.DELAY = (uint16_T)tmp;
      } else {
        Pacemaker_group11_DW.DELAY = 0U;
      }
    } else {
      Pacemaker_group11_DW.DELAY = MAX_uint16_T;
    }

    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Proxy_p;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.ATR_PACE_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group_Charging_C22_hw(const real_T *Divide1)
{
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil(*Divide1 -
       Pacemaker_group11_B.ATR_PW_n)) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group11_IN_Pacing_mq;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = false;
    Pacemaker_group11_B.ATR_PACE_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = false;
  } else if (Pacemaker_group11_B.MODE_n != 1) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_grou_Charging_C22_hwp(void)
{
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;

  /* Constant: '<Root>/Constant1' */
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Pacemaker_group11_P.Constant1_Value - Pacemaker_group11_B.ATR_PW_n)) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group11_IN_Pacing_mqt;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = false;
    Pacemaker_group11_B.ATR_PACE_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = false;
  } else if (Pacemaker_group11_B.MODE_n != 5) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
  }

  /* End of Constant: '<Root>/Constant1' */
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group11_Start(const real_T *Multiply, const real_T
  *Multiply1)
{
  switch (Pacemaker_group11_B.MODE_n) {
   case 2:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker__IN_Charging_C22_nfjg;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.PACE_GND_CTRL = true;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.Z_ATR_CTRL = false;
    Pacemaker_group11_B.Z_VENT_CTRL = false;
    Pacemaker_group11_B.ATR_PACE_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
    break;

   case 1:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_gr_IN_Charging_C22_nf;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.PACE_GND_CTRL = true;
    Pacemaker_group11_B.ATR_PACE_CTRL = false;
    Pacemaker_group11_B.Z_ATR_CTRL = false;
    Pacemaker_group11_B.Z_VENT_CTRL = false;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
    break;

   case 3:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group_IN_Charging_C22;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacem_enter_atomic_Charging_C22(Multiply);
    break;

   case 5:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_g_IN_Charging_C22_nfj;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.PACE_GND_CTRL = true;
    Pacemaker_group11_B.ATR_PACE_CTRL = false;
    Pacemaker_group11_B.Z_ATR_CTRL = false;
    Pacemaker_group11_B.Z_VENT_CTRL = false;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
    break;

   case 7:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_gro_IN_Charging_C22_n;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacem_enter_atomic_Charging_C22(Multiply);
    break;

   case 8:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemak_IN_Charging_C22_nfjgbhx;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pa_enter_atomic_Charging_C22_f3(Multiply1);
    break;

   case 4:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemake_IN_Charging_C22_nfjgbh;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pa_enter_atomic_Charging_C22_f3(Multiply1);
    break;

   case 6:
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_IN_Charging_C22_nfjgb;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.PACE_GND_CTRL = true;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.Z_ATR_CTRL = false;
    Pacemaker_group11_B.Z_VENT_CTRL = false;
    Pacemaker_group11_B.ATR_PACE_CTRL = false;
    Pacemaker_group11_B.ATR_GND_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
    break;
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_gro_Charging_C22_hwpq(const real_T *Divide1)
{
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil(*Divide1 -
       Pacemaker_group11_B.VENT_PW_n)) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group1_IN_Pacing_mqte;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = false;
    Pacemaker_group11_B.VENT_PACE_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = false;
  } else if (Pacemaker_group11_B.MODE_n != 2) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_gr_Charging_C22_hwpqo(void)
{
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;

  /* Constant: '<Root>/Constant1' */
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Pacemaker_group11_P.Constant1_Value - Pacemaker_group11_B.VENT_PW_n)) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group_IN_Pacing_mqtej;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = false;
    Pacemaker_group11_B.VENT_PACE_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = false;
  } else if (Pacemaker_group11_B.MODE_n != 6) {
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
  }

  /* End of Constant: '<Root>/Constant1' */
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_g_Charging_C22_hwpqoa(const real_T *Multiply1, const
  boolean_T *DigitalRead, const real_T *Divide1)
{
  real_T tmp;
  uint16_T tmp_0;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
  if (*DigitalRead) {
    Pacemaker_group11_DW.DELAY = Pacemaker_group11_B.VENT_REF_PERIOD_j;
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Proxy_pv;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
  } else {
    tmp = rt_roundd_snf(*Divide1 - (real_T)Pacemaker_group11_B.VENT_REF_PERIOD_j);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint16_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (Pacemaker_group11_DW.temporalCounter_i1 >= tmp_0) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
        Pacemaker_grou_IN_Pacing_mqtejg;
      Pacemaker_group11_DW.temporalCounter_i1 = 0U;
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
    } else if (Pacemaker_group11_B.MODE_n != 4) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
    }
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group11_Pacing_i(const real_T *Multiply1)
{
  real_T tmp;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = false;
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Pacemaker_group11_B.VENT_PW_n)) {
    tmp = rt_roundd_snf((real_T)Pacemaker_group11_B.VENT_REF_PERIOD_j -
                        Pacemaker_group11_B.VENT_PW_n);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        Pacemaker_group11_DW.DELAY = (uint16_T)tmp;
      } else {
        Pacemaker_group11_DW.DELAY = 0U;
      }
    } else {
      Pacemaker_group11_DW.DELAY = MAX_uint16_T;
    }

    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Proxy_pv;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker__Charging_C22_hwpqoa5(const real_T *Multiply1, const
  boolean_T *DigitalRead)
{
  real_T tmp;
  uint16_T tmp_0;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.VENT_PACE_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = true;
  Pacemaker_group11_B.FRONTEND_CTRL = true;
  if (*DigitalRead) {
    Pacemaker_group11_DW.DELAY = Pacemaker_group11_B.VENT_REF_PERIOD_j;
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group11_IN_Proxy_pvm;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
  } else {
    /* Constant: '<Root>/Constant1' */
    tmp = rt_roundd_snf(Pacemaker_group11_P.Constant1_Value - (real_T)
                        Pacemaker_group11_B.VENT_REF_PERIOD_j);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint16_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint16_T;
    }

    if (Pacemaker_group11_DW.temporalCounter_i1 >= tmp_0) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
        Pacemaker_gro_IN_Pacing_mqtejgx;
      Pacemaker_group11_DW.temporalCounter_i1 = 0U;
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
    } else if (Pacemaker_group11_B.MODE_n != 8) {
      Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
    }
  }
}

/* Function for Chart: '<Root>/eight model stateflow' */
static void Pacemaker_group11_Pacing_iu(const real_T *Multiply1)
{
  real_T tmp;
  Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
  Pacemaker_group11_B.PACE_GND_CTRL = true;
  Pacemaker_group11_B.ATR_PACE_CTRL = false;
  Pacemaker_group11_B.ATR_GND_CTRL = false;
  Pacemaker_group11_B.Z_ATR_CTRL = false;
  Pacemaker_group11_B.Z_VENT_CTRL = false;
  Pacemaker_group11_B.VENT_GND_CTRL = false;
  Pacemaker_group11_B.VENT_PACE_CTRL = true;
  Pacemaker_group11_B.IS_CHARGING = false;
  if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Pacemaker_group11_B.VENT_PW_n)) {
    tmp = rt_roundd_snf((real_T)Pacemaker_group11_B.VENT_REF_PERIOD_j -
                        Pacemaker_group11_B.VENT_PW_n);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        Pacemaker_group11_DW.DELAY = (uint16_T)tmp;
      } else {
        Pacemaker_group11_DW.DELAY = 0U;
      }
    } else {
      Pacemaker_group11_DW.DELAY = MAX_uint16_T;
    }

    Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
      Pacemaker_group11_IN_Proxy_pvm;
    Pacemaker_group11_DW.temporalCounter_i1 = 0U;
    Pacemaker_group11_B.PACING_REF_PWM = *Multiply1;
    Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
    Pacemaker_group11_B.VENT_PACE_CTRL = false;
    Pacemaker_group11_B.VENT_GND_CTRL = true;
    Pacemaker_group11_B.IS_CHARGING = true;
  }
}

static void Pacemaker_gr_SystemCore_setup_d(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pacemaker_group11_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Pacemaker_group11_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Pacemaker_group11_B.SCIModuleLoc, false, 10U,
    Pacemaker_group11_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Pacemaker_group11_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Pacemaker_group11_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Pacemaker_group11_B.ParityValue,
                        Pacemaker_group11_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void Pacemaker_group11_step(void)
{
  real_T Divide1;
  real_T Multiply;
  real_T Multiply1;
  uint8_T status;
  boolean_T DigitalRead;
  boolean_T DigitalRead1;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Pacemaker_group11_DW.obj_k.SampleTime !=
      Pacemaker_group11_P.SerialReceive_SampleTime) {
    Pacemaker_group11_DW.obj_k.SampleTime =
      Pacemaker_group11_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Pacemaker_group11_DW.obj_k.MW_SCIHANDLE,
    &Pacemaker_group11_B.RxDataLocChar[0], 66U);
  memcpy((void *)&Pacemaker_group11_B.RxData[0], (void *)
         &Pacemaker_group11_B.RxDataLocChar[0], (uint32_T)((size_t)66 * sizeof
          (uint8_T)));

  /* MATLABSystem: '<Root>/ATR_SIGNAL' */
  if (Pacemaker_group11_DW.obj_n.SampleTime !=
      Pacemaker_group11_P.ATR_SIGNAL_SampleTime) {
    Pacemaker_group11_DW.obj_n.SampleTime =
      Pacemaker_group11_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_group11_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Pacemaker_group11_DW.obj_n.MW_ANALOGIN_HANDLE,
    &Pacemaker_group11_B.ATR_SIGNAL, 7);

  /* End of MATLABSystem: '<Root>/ATR_SIGNAL' */

  /* MATLABSystem: '<Root>/VENT_SIGNAL' */
  if (Pacemaker_group11_DW.obj.SampleTime !=
      Pacemaker_group11_P.VENT_SIGNAL_SampleTime) {
    Pacemaker_group11_DW.obj.SampleTime =
      Pacemaker_group11_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_group11_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Pacemaker_group11_DW.obj.MW_ANALOGIN_HANDLE,
    &Pacemaker_group11_B.VENT_SIGNAL, 7);

  /* End of MATLABSystem: '<Root>/VENT_SIGNAL' */

  /* Chart: '<Root>/Serial Communication1' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Pacemaker_group11_DW.is_active_c1_Pacemaker_group11 == 0U) {
    Pacemaker_group11_DW.is_active_c1_Pacemaker_group11 = 1U;
    Pacemaker_group11_DW.is_c1_Pacemaker_group11 = Pacemaker_group11_IN_Init;
    Pacemaker_group11_B.MODE_n = 2U;
    Pacemaker_group11_B.LOWER_RATE_LIMIT_e = 60U;
    Pacemaker_group11_B.UPPER_RATE_LIMIT_g = 120U;
    Pacemaker_group11_B.ATR_AMP_REG_f = 3.5;
    Pacemaker_group11_B.VENT_AMP_REG_o = 3.5;
    Pacemaker_group11_B.ATR_PW_n = 0.4;
    Pacemaker_group11_B.VENT_PW_n = 0.4;
    Pacemaker_group11_B.ATR_SENSITIVITY_l = 0.75;
    Pacemaker_group11_B.VENT_SENSITIVITY_b = 2.5;
    Pacemaker_group11_B.ATR_REF_PERIOD_h = 250U;
    Pacemaker_group11_B.VENT_REF_PERIOD_j = 320U;
    Pacemaker_group11_B.PVARP_c = 250U;
    Pacemaker_group11_B.HYSTERESIS_RATE_LIMIT_c = 0U;
    Pacemaker_group11_B.RATE_SMOOTHING_d = 0U;
  } else {
    switch (Pacemaker_group11_DW.is_c1_Pacemaker_group11) {
     case Pacemaker_group11_IN_ECHO_PARAM:
      Pacemaker_group11_B.Type = 1.0;
      Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
        Pacemaker_group11_IN_STANDBY;
      break;

     case Pacemaker_group1_IN_ECHO_PARAM1:
      Pacemaker_group11_B.Type = 0.0;
      Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
        Pacemaker_group11_IN_STANDBY;
      break;

     case Pacemaker_group11_IN_Init:
      Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
        Pacemaker_group11_IN_STANDBY;
      break;

     case Pacemaker_group11_IN_STANDBY:
      if (status == 0) {
        if (Pacemaker_group11_B.RxData[0] == 22) {
          switch (Pacemaker_group11_B.RxData[1]) {
           case 34:
            Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
              Pacemaker_group11_IN_ECHO_PARAM;
            Pacemaker_group11_B.Type = 1.0;
            Send_DCM();
            break;

           case 51:
            Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
              Pacemaker_group1_IN_ECHO_PARAM1;
            Pacemaker_group11_B.Type = 0.0;
            Send_DCM();
            break;

           case 85:
            Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
              Pacemaker__IN_SettingParameters;
            memcpy((void *)&Pacemaker_group11_B.MODE_n, (void *)
                   &Pacemaker_group11_B.RxData[2], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.LOWER_RATE_LIMIT_e, (void *)
                   &Pacemaker_group11_B.RxData[4], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.UPPER_RATE_LIMIT_g, (void *)
                   &Pacemaker_group11_B.RxData[6], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.ATR_AMP_REG_f, (void *)
                   &Pacemaker_group11_B.RxData[8], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            memcpy((void *)&Pacemaker_group11_B.VENT_AMP_REG_o, (void *)
                   &Pacemaker_group11_B.RxData[16], (uint32_T)((size_t)1 *
                    sizeof(real_T)));
            memcpy((void *)&Pacemaker_group11_B.ATR_PW_n, (void *)
                   &Pacemaker_group11_B.RxData[24], (uint32_T)((size_t)1 *
                    sizeof(real_T)));
            memcpy((void *)&Pacemaker_group11_B.VENT_PW_n, (void *)
                   &Pacemaker_group11_B.RxData[32], (uint32_T)((size_t)1 *
                    sizeof(real_T)));
            memcpy((void *)&Pacemaker_group11_B.ATR_SENSITIVITY_l, (void *)
                   &Pacemaker_group11_B.RxData[40], (uint32_T)((size_t)1 *
                    sizeof(real_T)));
            memcpy((void *)&Pacemaker_group11_B.VENT_SENSITIVITY_b, (void *)
                   &Pacemaker_group11_B.RxData[48], (uint32_T)((size_t)1 *
                    sizeof(real_T)));
            memcpy((void *)&Pacemaker_group11_B.ATR_REF_PERIOD_h, (void *)
                   &Pacemaker_group11_B.RxData[56], (uint32_T)((size_t)1 *
                    sizeof(uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.VENT_REF_PERIOD_j, (void *)
                   &Pacemaker_group11_B.RxData[58], (uint32_T)((size_t)1 *
                    sizeof(uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.PVARP_c, (void *)
                   &Pacemaker_group11_B.RxData[60], (uint32_T)((size_t)1 *
                    sizeof(uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.HYSTERESIS_RATE_LIMIT_c, (void *)
                   &Pacemaker_group11_B.RxData[62], (uint32_T)((size_t)1 *
                    sizeof(uint16_T)));
            memcpy((void *)&Pacemaker_group11_B.RATE_SMOOTHING_d, (void *)
                   &Pacemaker_group11_B.RxData[64], (uint32_T)((size_t)1 *
                    sizeof(uint16_T)));
            break;

           default:
            Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
              Pacemaker_group11_IN_STANDBY;
            break;
          }
        } else {
          Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
            Pacemaker_group11_IN_STANDBY;
        }
      }
      break;

     default:
      /* case IN_SettingParameters: */
      Pacemaker_group11_DW.is_c1_Pacemaker_group11 =
        Pacemaker_group11_IN_STANDBY;
      break;
    }
  }

  /* End of Chart: '<Root>/Serial Communication1' */

  /* Gain: '<S4>/Multiply1' incorporates:
   *  Constant: '<S4>/Voltage'
   *  Product: '<S4>/VENT_CYCLE'
   */
  Multiply1 = Pacemaker_group11_B.VENT_AMP_REG_o /
    Pacemaker_group11_P.Voltage_Value * Pacemaker_group11_P.Multiply1_Gain;

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/msec//min'
   */
  Divide1 = Pacemaker_group11_P.msecmin_Value / (real_T)
    Pacemaker_group11_B.LOWER_RATE_LIMIT_e;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (Pacemaker_group11_DW.obj_a.SampleTime !=
      Pacemaker_group11_P.DigitalRead_SampleTime) {
    Pacemaker_group11_DW.obj_a.SampleTime =
      Pacemaker_group11_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  DigitalRead = MW_digitalIO_read(Pacemaker_group11_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* Gain: '<S4>/Multiply' incorporates:
   *  Constant: '<S4>/Voltage'
   *  Product: '<S4>/ATR_CYCLE'
   */
  Multiply = Pacemaker_group11_B.ATR_AMP_REG_f /
    Pacemaker_group11_P.Voltage_Value * Pacemaker_group11_P.Multiply_Gain;

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (Pacemaker_group11_DW.obj_o.SampleTime !=
      Pacemaker_group11_P.DigitalRead1_SampleTime) {
    Pacemaker_group11_DW.obj_o.SampleTime =
      Pacemaker_group11_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read1' */
  DigitalRead1 = MW_digitalIO_read
    (Pacemaker_group11_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/eight model stateflow' */
  if (Pacemaker_group11_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_group11_DW.temporalCounter_i1++;
  }

  if (Pacemaker_group11_DW.is_active_c3_Pacemaker_group11 == 0U) {
    Pacemaker_group11_DW.is_active_c3_Pacemaker_group11 = 1U;
    Pacemaker_group11_DW.is_c3_Pacemaker_group11 = Pacemaker_group11_IN_Start;
  } else {
    switch (Pacemaker_group11_DW.is_c3_Pacemaker_group11) {
     case Pacemaker_group_IN_Charging_C22:
      Pacemaker_group11_Charging_C22(&Multiply, &DigitalRead1, &Divide1);
      break;

     case Pacemaker_group11_IN_Pacing:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_group11_B.ATR_PW_n)) {
        Multiply1 = rt_roundd_snf((real_T)Pacemaker_group11_B.ATR_REF_PERIOD_h -
          Pacemaker_group11_B.ATR_PW_n);
        if (Multiply1 < 65536.0) {
          if (Multiply1 >= 0.0) {
            Pacemaker_group11_DW.DELAY = (uint16_T)Multiply1;
          } else {
            Pacemaker_group11_DW.DELAY = 0U;
          }
        } else {
          Pacemaker_group11_DW.DELAY = MAX_uint16_T;
        }

        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_group11_IN_Proxy;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacemaker_group11_B.PACING_REF_PWM = Multiply;
        Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
        Pacemaker_group11_B.ATR_PACE_CTRL = false;
        Pacemaker_group11_B.ATR_GND_CTRL = true;
        Pacemaker_group11_B.IS_CHARGING = true;
      }
      break;

     case Pacemaker_group11_IN_Proxy:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = true;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= Pacemaker_group11_DW.DELAY)
      {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_group_IN_Charging_C22;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacem_enter_atomic_Charging_C22(&Multiply);
      }
      break;

     case Pacemaker_gro_IN_Charging_C22_n:
      Pacemaker_group1_Charging_C22_h(&Multiply, &DigitalRead1);
      break;

     case Pacemaker_group11_IN_Pacing_m:
      Pacemaker_group11_Pacing(&Multiply);
      break;

     case Pacemaker_group11_IN_Proxy_p:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = true;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= Pacemaker_group11_DW.DELAY)
      {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_gro_IN_Charging_C22_n;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacem_enter_atomic_Charging_C22(&Multiply);
      }
      break;

     case Pacemaker_gr_IN_Charging_C22_nf:
      Pacemaker_group_Charging_C22_hw(&Divide1);
      break;

     case Pacemaker_group11_IN_Pacing_mq:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_group11_B.ATR_PW_n)) {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_gr_IN_Charging_C22_nf;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacemaker_group11_B.PACING_REF_PWM = Multiply;
        Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
        Pacemaker_group11_B.ATR_PACE_CTRL = false;
        Pacemaker_group11_B.ATR_GND_CTRL = true;
        Pacemaker_group11_B.IS_CHARGING = true;
      }
      break;

     case Pacemaker_g_IN_Charging_C22_nfj:
      Pacemaker_grou_Charging_C22_hwp();
      break;

     case Pacemaker_group11_IN_Pacing_mqt:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_group11_B.ATR_PW_n)) {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_g_IN_Charging_C22_nfj;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacemaker_group11_B.PACING_REF_PWM = Multiply;
        Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
        Pacemaker_group11_B.ATR_PACE_CTRL = false;
        Pacemaker_group11_B.ATR_GND_CTRL = true;
        Pacemaker_group11_B.IS_CHARGING = true;
      }
      break;

     case Pacemaker_group11_IN_Start:
      Pacemaker_group11_Start(&Multiply, &Multiply1);
      break;

     case Pacemaker__IN_Charging_C22_nfjg:
      Pacemaker_gro_Charging_C22_hwpq(&Divide1);
      break;

     case Pacemaker_group1_IN_Pacing_mqte:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_group11_B.VENT_PW_n)) {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker__IN_Charging_C22_nfjg;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacemaker_group11_B.PACING_REF_PWM = Multiply1;
        Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
        Pacemaker_group11_B.VENT_PACE_CTRL = false;
        Pacemaker_group11_B.VENT_GND_CTRL = true;
        Pacemaker_group11_B.IS_CHARGING = true;
      }
      break;

     case Pacemaker_IN_Charging_C22_nfjgb:
      Pacemaker_gr_Charging_C22_hwpqo();
      break;

     case Pacemaker_group_IN_Pacing_mqtej:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = false;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = false;
      Pacemaker_group11_B.VENT_PACE_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = false;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_group11_B.VENT_PW_n)) {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemaker_IN_Charging_C22_nfjgb;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pacemaker_group11_B.PACING_REF_PWM = Multiply1;
        Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
        Pacemaker_group11_B.VENT_PACE_CTRL = false;
        Pacemaker_group11_B.VENT_GND_CTRL = true;
        Pacemaker_group11_B.IS_CHARGING = true;
      }
      break;

     case Pacemake_IN_Charging_C22_nfjgbh:
      Pacemaker_g_Charging_C22_hwpqoa(&Multiply1, &DigitalRead, &Divide1);
      break;

     case Pacemaker_grou_IN_Pacing_mqtejg:
      Pacemaker_group11_Pacing_i(&Multiply1);
      break;

     case Pacemaker_group11_IN_Proxy_pv:
      Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = true;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= Pacemaker_group11_DW.DELAY)
      {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemake_IN_Charging_C22_nfjgbh;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pa_enter_atomic_Charging_C22_f3(&Multiply1);
      }
      break;

     case Pacemak_IN_Charging_C22_nfjgbhx:
      Pacemaker__Charging_C22_hwpqoa5(&Multiply1, &DigitalRead);
      break;

     case Pacemaker_gro_IN_Pacing_mqtejgx:
      Pacemaker_group11_Pacing_iu(&Multiply1);
      break;

     default:
      /* case IN_Proxy: */
      Pacemaker_group11_B.PACE_CHARGE_CTRL = true;
      Pacemaker_group11_B.PACE_GND_CTRL = true;
      Pacemaker_group11_B.VENT_PACE_CTRL = false;
      Pacemaker_group11_B.Z_ATR_CTRL = false;
      Pacemaker_group11_B.Z_VENT_CTRL = false;
      Pacemaker_group11_B.ATR_PACE_CTRL = false;
      Pacemaker_group11_B.ATR_GND_CTRL = false;
      Pacemaker_group11_B.VENT_GND_CTRL = true;
      Pacemaker_group11_B.IS_CHARGING = true;
      if (Pacemaker_group11_DW.temporalCounter_i1 >= Pacemaker_group11_DW.DELAY)
      {
        Pacemaker_group11_DW.is_c3_Pacemaker_group11 =
          Pacemak_IN_Charging_C22_nfjgbhx;
        Pacemaker_group11_DW.temporalCounter_i1 = 0U;
        Pa_enter_atomic_Charging_C22_f3(&Multiply1);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/eight model stateflow' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_hb.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.IS_CHARGING);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_hy.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_group11_DW.obj_ac.MW_PWM_HANDLE,
                      Pacemaker_group11_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_n2.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/Digital Write9' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S3>/Digital Write10' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_ii.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S3>/Digital Write11' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S3>/Digital Write12' */
  MW_digitalIO_write(Pacemaker_group11_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Pacemaker_group11_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S3>/PWM Output1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Product: '<Root>/Divide3'
   */
  MW_PWM_SetDutyCycle(Pacemaker_group11_DW.obj_bs.MW_PWM_HANDLE,
                      Pacemaker_group11_P.Gain1_Gain *
                      (Pacemaker_group11_B.ATR_SENSITIVITY_l /
                       Pacemaker_group11_P.Constant_Value));

  /* MATLABSystem: '<S3>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   *  Product: '<Root>/Divide2'
   */
  MW_PWM_SetDutyCycle(Pacemaker_group11_DW.obj_d.MW_PWM_HANDLE,
                      Pacemaker_group11_P.Gain_Gain *
                      (Pacemaker_group11_B.VENT_SENSITIVITY_b /
                       Pacemaker_group11_P.Constant_Value));
}

/* Model initialize function */
void Pacemaker_group11_initialize(void)
{
  {
    freedomk64f_AnalogInput_Pacem_T *obj;
    freedomk64f_DigitalRead_Pacem_T *obj_0;
    freedomk64f_DigitalWrite_Pace_T *obj_1;
    freedomk64f_PWMOutput_Pacemak_T *obj_2;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
     *  SubSystem: '<Root>/Serial transmit'
     */
    Send_DCM_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

    /* SystemInitialize for Chart: '<Root>/eight model stateflow' */
    Pacemaker_group11_B.FRONTEND_CTRL = true;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Pacemaker_group11_DW.obj_k.isInitialized = 0;
    Pacemaker_group11_DW.obj_k.matlabCodegenIsDeleted = false;
    Pacemaker_group11_DW.obj_k.SampleTime =
      Pacemaker_group11_P.SerialReceive_SampleTime;
    Pacemaker_gr_SystemCore_setup_d(&Pacemaker_group11_DW.obj_k);

    /* Start for MATLABSystem: '<Root>/ATR_SIGNAL' */
    Pacemaker_group11_DW.obj_n.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_n.isInitialized = 0;
    Pacemaker_group11_DW.obj_n.SampleTime = -1.0;
    Pacemaker_group11_DW.obj_n.matlabCodegenIsDeleted = false;
    Pacemaker_group11_DW.obj_n.SampleTime =
      Pacemaker_group11_P.ATR_SIGNAL_SampleTime;
    obj = &Pacemaker_group11_DW.obj_n;
    Pacemaker_group11_DW.obj_n.isSetupComplete = false;
    Pacemaker_group11_DW.obj_n.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    Pacemaker_group11_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Pacemaker_group11_DW.obj_n.MW_ANALOGIN_HANDLE,
      Pacemaker_group11_B.trigger_val, 0U);
    Pacemaker_group11_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VENT_SIGNAL' */
    Pacemaker_group11_DW.obj.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj.isInitialized = 0;
    Pacemaker_group11_DW.obj.SampleTime = -1.0;
    Pacemaker_group11_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_group11_DW.obj.SampleTime =
      Pacemaker_group11_P.VENT_SIGNAL_SampleTime;
    obj = &Pacemaker_group11_DW.obj;
    Pacemaker_group11_DW.obj.isSetupComplete = false;
    Pacemaker_group11_DW.obj.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    Pacemaker_group11_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Pacemaker_group11_DW.obj.MW_ANALOGIN_HANDLE,
      Pacemaker_group11_B.trigger_val, 0U);
    Pacemaker_group11_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    Pacemaker_group11_DW.obj_a.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_a.isInitialized = 0;
    Pacemaker_group11_DW.obj_a.SampleTime = -1.0;
    Pacemaker_group11_DW.obj_a.matlabCodegenIsDeleted = false;
    Pacemaker_group11_DW.obj_a.SampleTime =
      Pacemaker_group11_P.DigitalRead_SampleTime;
    obj_0 = &Pacemaker_group11_DW.obj_a;
    Pacemaker_group11_DW.obj_a.isSetupComplete = false;
    Pacemaker_group11_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_group11_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    Pacemaker_group11_DW.obj_o.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_o.isInitialized = 0;
    Pacemaker_group11_DW.obj_o.SampleTime = -1.0;
    Pacemaker_group11_DW.obj_o.matlabCodegenIsDeleted = false;
    Pacemaker_group11_DW.obj_o.SampleTime =
      Pacemaker_group11_P.DigitalRead1_SampleTime;
    obj_0 = &Pacemaker_group11_DW.obj_o;
    Pacemaker_group11_DW.obj_o.isSetupComplete = false;
    Pacemaker_group11_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_group11_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Pacemaker_group11_DW.obj_hb.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_hb.isInitialized = 0;
    Pacemaker_group11_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_hb;
    Pacemaker_group11_DW.obj_hb.isSetupComplete = false;
    Pacemaker_group11_DW.obj_hb.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_group11_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    Pacemaker_group11_DW.obj_hy.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_hy.isInitialized = 0;
    Pacemaker_group11_DW.obj_hy.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_hy;
    Pacemaker_group11_DW.obj_hy.isSetupComplete = false;
    Pacemaker_group11_DW.obj_hy.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_group11_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    Pacemaker_group11_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_b.isInitialized = 0;
    Pacemaker_group11_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_b;
    Pacemaker_group11_DW.obj_b.isSetupComplete = false;
    Pacemaker_group11_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Pacemaker_group11_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    Pacemaker_group11_DW.obj_ac.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_ac.isInitialized = 0;
    Pacemaker_group11_DW.obj_ac.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_group11_DW.obj_ac;
    Pacemaker_group11_DW.obj_ac.isSetupComplete = false;
    Pacemaker_group11_DW.obj_ac.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_group11_DW.obj_ac.MW_PWM_HANDLE);
    Pacemaker_group11_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    Pacemaker_group11_DW.obj_i.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_i.isInitialized = 0;
    Pacemaker_group11_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_i;
    Pacemaker_group11_DW.obj_i.isSetupComplete = false;
    Pacemaker_group11_DW.obj_i.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Pacemaker_group11_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    Pacemaker_group11_DW.obj_n2.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_n2.isInitialized = 0;
    Pacemaker_group11_DW.obj_n2.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_n2;
    Pacemaker_group11_DW.obj_n2.isSetupComplete = false;
    Pacemaker_group11_DW.obj_n2.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_group11_DW.obj_n2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write9' */
    Pacemaker_group11_DW.obj_j.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_j.isInitialized = 0;
    Pacemaker_group11_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_j;
    Pacemaker_group11_DW.obj_j.isSetupComplete = false;
    Pacemaker_group11_DW.obj_j.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_group11_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Pacemaker_group11_DW.obj_m.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_m.isInitialized = 0;
    Pacemaker_group11_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_m;
    Pacemaker_group11_DW.obj_m.isSetupComplete = false;
    Pacemaker_group11_DW.obj_m.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_group11_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write10' */
    Pacemaker_group11_DW.obj_ii.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_ii.isInitialized = 0;
    Pacemaker_group11_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_ii;
    Pacemaker_group11_DW.obj_ii.isSetupComplete = false;
    Pacemaker_group11_DW.obj_ii.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_group11_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write11' */
    Pacemaker_group11_DW.obj_nv.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_nv.isInitialized = 0;
    Pacemaker_group11_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_nv;
    Pacemaker_group11_DW.obj_nv.isSetupComplete = false;
    Pacemaker_group11_DW.obj_nv.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_group11_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write12' */
    Pacemaker_group11_DW.obj_l.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_l.isInitialized = 0;
    Pacemaker_group11_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_group11_DW.obj_l;
    Pacemaker_group11_DW.obj_l.isSetupComplete = false;
    Pacemaker_group11_DW.obj_l.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_group11_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    Pacemaker_group11_DW.obj_bs.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_bs.isInitialized = 0;
    Pacemaker_group11_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_group11_DW.obj_bs;
    Pacemaker_group11_DW.obj_bs.isSetupComplete = false;
    Pacemaker_group11_DW.obj_bs.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_group11_DW.obj_bs.MW_PWM_HANDLE);
    Pacemaker_group11_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Pacemaker_group11_DW.obj_d.matlabCodegenIsDeleted = true;
    Pacemaker_group11_DW.obj_d.isInitialized = 0;
    Pacemaker_group11_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_group11_DW.obj_d;
    Pacemaker_group11_DW.obj_d.isSetupComplete = false;
    Pacemaker_group11_DW.obj_d.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_group11_DW.obj_d.MW_PWM_HANDLE);
    Pacemaker_group11_DW.obj_d.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_group11_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Pacemaker_group11_DW.obj_k.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_k.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_k.isSetupComplete) {
      MW_SCI_Close(Pacemaker_group11_DW.obj_k.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/ATR_SIGNAL' */
  if (!Pacemaker_group11_DW.obj_n.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_n.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_n.isSetupComplete) {
      MW_AnalogIn_Stop(Pacemaker_group11_DW.obj_n.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Pacemaker_group11_DW.obj_n.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<Root>/VENT_SIGNAL' */
  if (!Pacemaker_group11_DW.obj.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj.isInitialized == 1) &&
        Pacemaker_group11_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(Pacemaker_group11_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Pacemaker_group11_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/VENT_SIGNAL' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
   *  SubSystem: '<Root>/Serial transmit'
   */
  Send_DCM_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!Pacemaker_group11_DW.obj_a.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_a.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!Pacemaker_group11_DW.obj_o.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_o.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  if (!Pacemaker_group11_DW.obj_hb.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_hb.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_hb.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_hb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  if (!Pacemaker_group11_DW.obj_hy.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_hy.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_hy.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_hy.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  if (!Pacemaker_group11_DW.obj_b.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_b.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  if (!Pacemaker_group11_DW.obj_ac.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_ac.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_ac.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_ac.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_group11_DW.obj_ac.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_group11_DW.obj_ac.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  if (!Pacemaker_group11_DW.obj_i.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_i.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  if (!Pacemaker_group11_DW.obj_n2.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_n2.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write9' */
  if (!Pacemaker_group11_DW.obj_j.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_j.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  if (!Pacemaker_group11_DW.obj_m.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_m.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write10' */
  if (!Pacemaker_group11_DW.obj_ii.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_ii.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write11' */
  if (!Pacemaker_group11_DW.obj_nv.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_nv.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write11' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write12' */
  if (!Pacemaker_group11_DW.obj_l.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_l.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_group11_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write12' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  if (!Pacemaker_group11_DW.obj_bs.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_bs.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_bs.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_group11_DW.obj_bs.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_group11_DW.obj_bs.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  if (!Pacemaker_group11_DW.obj_d.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_d.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_group11_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_group11_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
