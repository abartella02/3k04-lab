/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI.c
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

#include "AAI.h"
#include "rtwtypes.h"
#include <math.h>
#include "AAI_types.h"

/* Named constants for Chart: '<Root>/AAI' */
#define AAI_IN_Charging_C22            ((uint8_T)1U)
#define AAI_IN_Pacing                  ((uint8_T)2U)
#define AAI_IN_Proxy                   ((uint8_T)3U)

/* Block signals (default storage) */
B_AAI_T AAI_B;

/* Block states (default storage) */
DW_AAI_T AAI_DW;

/* Real-time model */
static RT_MODEL_AAI_T AAI_M_;
RT_MODEL_AAI_T *const AAI_M = &AAI_M_;

/* Forward declaration for local functions */
static void AAI_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);
static void AAI_enter_atomic_Proxy(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);

/* Function for Chart: '<Root>/AAI' */
static void AAI_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  AAI_B.PACING_REF_PWM = AAI_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  AAI_B.PACE_GND_CTRL = true;
  *ATR_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *VENT_PACE_CTRL = false;
  *VENT_GND_CTRL = false;
  AAI_B.ATR_GND_CTRL = true;
  AAI_B.IS_CHARGING = true;

  /* Constant: '<Root>/PWM1' */
  AAI_B.ATR_CMP_REF_PWM = AAI_P.PWM1_Value;
  AAI_B.FRONTEND_CTRL = true;
}

/* Function for Chart: '<Root>/AAI' */
static void AAI_enter_atomic_Proxy(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  AAI_B.PACING_REF_PWM = AAI_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  AAI_B.PACE_GND_CTRL = true;
  *ATR_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *VENT_PACE_CTRL = false;
  *VENT_GND_CTRL = false;
  AAI_B.ATR_GND_CTRL = true;
  AAI_B.IS_CHARGING = true;

  /* Constant: '<Root>/PWM1' */
  AAI_B.ATR_CMP_REF_PWM = AAI_P.PWM1_Value;
}

/* Model step function */
void AAI_step(void)
{
  boolean_T ATR_PACE_CTRL;
  boolean_T PACE_CHARGE_CTRL;
  boolean_T VENT_GND_CTRL;
  boolean_T VENT_PACE_CTRL;
  boolean_T Z_ATR_CTRL;
  boolean_T Z_VENT_CTRL;
  boolean_T tmp;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (AAI_DW.obj.SampleTime != AAI_P.DigitalRead_SampleTime) {
    AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
  }

  tmp = MW_digitalIO_read(AAI_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/AAI' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/msec'
   *  MATLABSystem: '<Root>/Digital Read'
   *  Product: '<Root>/Divide'
   */
  if (AAI_DW.temporalCounter_i1 < MAX_uint32_T) {
    AAI_DW.temporalCounter_i1++;
  }

  if (AAI_DW.is_active_c3_AAI == 0U) {
    AAI_DW.is_active_c3_AAI = 1U;
    AAI_DW.is_c3_AAI = AAI_IN_Charging_C22;
    AAI_DW.temporalCounter_i1 = 0U;
    AAI_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
      &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
  } else {
    switch (AAI_DW.is_c3_AAI) {
     case AAI_IN_Charging_C22:
      PACE_CHARGE_CTRL = true;
      AAI_B.PACE_GND_CTRL = true;
      ATR_PACE_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      VENT_PACE_CTRL = false;
      VENT_GND_CTRL = false;
      AAI_B.ATR_GND_CTRL = true;
      AAI_B.IS_CHARGING = true;
      AAI_B.FRONTEND_CTRL = true;
      if (tmp) {
        AAI_DW.DELAY = AAI_P.Constant4_Value;
        AAI_DW.is_c3_AAI = AAI_IN_Proxy;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_enter_atomic_Proxy(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
          &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      } else if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.msec_Value /
                  AAI_P.BPM_Value - AAI_P.Constant4_Value)) {
        AAI_DW.is_c3_AAI = AAI_IN_Pacing;
        AAI_DW.temporalCounter_i1 = 0U;
        PACE_CHARGE_CTRL = false;
        AAI_B.ATR_GND_CTRL = false;
        ATR_PACE_CTRL = true;
        AAI_B.IS_CHARGING = false;
      }
      break;

     case AAI_IN_Pacing:
      PACE_CHARGE_CTRL = false;
      AAI_B.PACE_GND_CTRL = true;
      VENT_PACE_CTRL = false;
      VENT_GND_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      AAI_B.ATR_GND_CTRL = false;
      ATR_PACE_CTRL = true;
      AAI_B.IS_CHARGING = false;
      if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.Constant_Value)) {
        AAI_DW.DELAY = AAI_P.Constant4_Value - AAI_P.Constant_Value;
        AAI_DW.is_c3_AAI = AAI_IN_Proxy;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_enter_atomic_Proxy(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
          &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      }
      break;

     default:
      /* case IN_Proxy: */
      PACE_CHARGE_CTRL = true;
      AAI_B.PACE_GND_CTRL = true;
      ATR_PACE_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      VENT_PACE_CTRL = false;
      VENT_GND_CTRL = false;
      AAI_B.ATR_GND_CTRL = true;
      AAI_B.IS_CHARGING = true;
      if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_DW.DELAY)) {
        AAI_DW.is_c3_AAI = AAI_IN_Charging_C22;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL,
          &Z_VENT_CTRL, &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AAI' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AAI_DW.obj_hb.MW_DIGITALIO_HANDLE, AAI_B.IS_CHARGING);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AAI_DW.obj_m.MW_DIGITALIO_HANDLE, AAI_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(AAI_DW.obj_ii.MW_DIGITALIO_HANDLE, AAI_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(AAI_DW.obj_nv.MW_DIGITALIO_HANDLE, VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write12' */
  MW_digitalIO_write(AAI_DW.obj_l.MW_DIGITALIO_HANDLE, AAI_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(AAI_DW.obj_h.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AAI_DW.obj_b.MW_DIGITALIO_HANDLE, Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(AAI_DW.obj_i.MW_DIGITALIO_HANDLE, Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(AAI_DW.obj_n.MW_DIGITALIO_HANDLE, ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(AAI_DW.obj_j.MW_DIGITALIO_HANDLE, VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_d.MW_PWM_HANDLE, AAI_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_bs.MW_PWM_HANDLE, AAI_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_a.MW_PWM_HANDLE, AAI_B.PACING_REF_PWM);

  /* Requirements Table: '<Root>/Requirements Table1' */
  AAI_DW.doneDoubleBufferReInit = true;

  /*  SF_REQ_REV_07 */
  /*  HEADER_ASSIGNMENTS */
  /*  START_A_4 */
  /*  END_A_4 */
  /*  START_R_1 */
  /*  START_R_7 */
  /*  END_R_7 */
  /*  START_R_13 */
  /*  END_R_13 */
  /*  START_R_10 */
  /*  END_R_10 */
  /*  END_R_1 */
}

/* Model initialize function */
void AAI_initialize(void)
{
  {
    freedomk64f_DigitalRead_AAI_T *obj;
    freedomk64f_DigitalWrite_AAI_T *obj_0;
    freedomk64f_PWMOutput_AAI_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/AAI' */
    AAI_B.FRONTEND_CTRL = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    AAI_DW.obj.matlabCodegenIsDeleted = true;
    AAI_DW.obj.isInitialized = 0;
    AAI_DW.obj.SampleTime = -1.0;
    AAI_DW.obj.matlabCodegenIsDeleted = false;
    AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
    obj = &AAI_DW.obj;
    AAI_DW.obj.isSetupComplete = false;
    AAI_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    AAI_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    AAI_DW.obj_hb.matlabCodegenIsDeleted = true;
    AAI_DW.obj_hb.isInitialized = 0;
    AAI_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_hb;
    AAI_DW.obj_hb.isSetupComplete = false;
    AAI_DW.obj_hb.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    AAI_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    AAI_DW.obj_m.matlabCodegenIsDeleted = true;
    AAI_DW.obj_m.isInitialized = 0;
    AAI_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_m;
    AAI_DW.obj_m.isSetupComplete = false;
    AAI_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AAI_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    AAI_DW.obj_ii.matlabCodegenIsDeleted = true;
    AAI_DW.obj_ii.isInitialized = 0;
    AAI_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_ii;
    AAI_DW.obj_ii.isSetupComplete = false;
    AAI_DW.obj_ii.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AAI_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    AAI_DW.obj_nv.matlabCodegenIsDeleted = true;
    AAI_DW.obj_nv.isInitialized = 0;
    AAI_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_nv;
    AAI_DW.obj_nv.isSetupComplete = false;
    AAI_DW.obj_nv.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AAI_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write12' */
    AAI_DW.obj_l.matlabCodegenIsDeleted = true;
    AAI_DW.obj_l.isInitialized = 0;
    AAI_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_l;
    AAI_DW.obj_l.isSetupComplete = false;
    AAI_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AAI_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    AAI_DW.obj_h.matlabCodegenIsDeleted = true;
    AAI_DW.obj_h.isInitialized = 0;
    AAI_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_h;
    AAI_DW.obj_h.isSetupComplete = false;
    AAI_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AAI_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    AAI_DW.obj_b.matlabCodegenIsDeleted = true;
    AAI_DW.obj_b.isInitialized = 0;
    AAI_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_b;
    AAI_DW.obj_b.isSetupComplete = false;
    AAI_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    AAI_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    AAI_DW.obj_i.matlabCodegenIsDeleted = true;
    AAI_DW.obj_i.isInitialized = 0;
    AAI_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_i;
    AAI_DW.obj_i.isSetupComplete = false;
    AAI_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    AAI_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    AAI_DW.obj_n.matlabCodegenIsDeleted = true;
    AAI_DW.obj_n.isInitialized = 0;
    AAI_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_n;
    AAI_DW.obj_n.isSetupComplete = false;
    AAI_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AAI_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    AAI_DW.obj_j.matlabCodegenIsDeleted = true;
    AAI_DW.obj_j.isInitialized = 0;
    AAI_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_DW.obj_j;
    AAI_DW.obj_j.isSetupComplete = false;
    AAI_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AAI_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    AAI_DW.obj_d.matlabCodegenIsDeleted = true;
    AAI_DW.obj_d.isInitialized = 0;
    AAI_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_1 = &AAI_DW.obj_d;
    AAI_DW.obj_d.isSetupComplete = false;
    AAI_DW.obj_d.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(AAI_DW.obj_d.MW_PWM_HANDLE);
    AAI_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    AAI_DW.obj_bs.matlabCodegenIsDeleted = true;
    AAI_DW.obj_bs.isInitialized = 0;
    AAI_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_1 = &AAI_DW.obj_bs;
    AAI_DW.obj_bs.isSetupComplete = false;
    AAI_DW.obj_bs.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(AAI_DW.obj_bs.MW_PWM_HANDLE);
    AAI_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    AAI_DW.obj_a.matlabCodegenIsDeleted = true;
    AAI_DW.obj_a.isInitialized = 0;
    AAI_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &AAI_DW.obj_a;
    AAI_DW.obj_a.isSetupComplete = false;
    AAI_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(AAI_DW.obj_a.MW_PWM_HANDLE);
    AAI_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void AAI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!AAI_DW.obj.matlabCodegenIsDeleted) {
    AAI_DW.obj.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj.isInitialized == 1) && AAI_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AAI_DW.obj_hb.matlabCodegenIsDeleted) {
    AAI_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_hb.isInitialized == 1) && AAI_DW.obj_hb.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_hb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AAI_DW.obj_m.matlabCodegenIsDeleted) {
    AAI_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_m.isInitialized == 1) && AAI_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!AAI_DW.obj_ii.matlabCodegenIsDeleted) {
    AAI_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_ii.isInitialized == 1) && AAI_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!AAI_DW.obj_nv.matlabCodegenIsDeleted) {
    AAI_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_nv.isInitialized == 1) && AAI_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write12' */
  if (!AAI_DW.obj_l.matlabCodegenIsDeleted) {
    AAI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_l.isInitialized == 1) && AAI_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write12' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!AAI_DW.obj_h.matlabCodegenIsDeleted) {
    AAI_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_h.isInitialized == 1) && AAI_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AAI_DW.obj_b.matlabCodegenIsDeleted) {
    AAI_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_b.isInitialized == 1) && AAI_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!AAI_DW.obj_i.matlabCodegenIsDeleted) {
    AAI_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_i.isInitialized == 1) && AAI_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!AAI_DW.obj_n.matlabCodegenIsDeleted) {
    AAI_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_n.isInitialized == 1) && AAI_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!AAI_DW.obj_j.matlabCodegenIsDeleted) {
    AAI_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_j.isInitialized == 1) && AAI_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!AAI_DW.obj_d.matlabCodegenIsDeleted) {
    AAI_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_d.isInitialized == 1) && AAI_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!AAI_DW.obj_bs.matlabCodegenIsDeleted) {
    AAI_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_bs.isInitialized == 1) && AAI_DW.obj_bs.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_bs.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_bs.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  if (!AAI_DW.obj_a.matlabCodegenIsDeleted) {
    AAI_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_a.isInitialized == 1) && AAI_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
