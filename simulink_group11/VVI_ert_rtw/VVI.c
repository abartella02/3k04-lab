/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VVI.c
 *
 * Code generated for Simulink model 'VVI'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Oct 21 05:24:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VVI.h"
#include "rtwtypes.h"
#include <math.h>
#include "VVI_types.h"

/* Named constants for Chart: '<Root>/vvI' */
#define VVI_IN_Charging_C22            ((uint8_T)1U)
#define VVI_IN_Pacing                  ((uint8_T)2U)
#define VVI_IN_Proxy                   ((uint8_T)3U)

/* Block signals (default storage) */
B_VVI_T VVI_B;

/* Block states (default storage) */
DW_VVI_T VVI_DW;

/* Real-time model */
static RT_MODEL_VVI_T VVI_M_;
RT_MODEL_VVI_T *const VVI_M = &VVI_M_;

/* Forward declaration for local functions */
static void VVI_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);
static void VVI_enter_atomic_Proxy(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);

/* Function for Chart: '<Root>/vvI' */
static void VVI_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  VVI_B.PACING_REF_PWM = VVI_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  VVI_B.PACE_GND_CTRL = true;
  *VENT_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *ATR_PACE_CTRL = false;
  VVI_B.ATR_GND_CTRL = false;
  *VENT_GND_CTRL = true;
  VVI_B.IS_CHARGING = true;

  /* Constant: '<Root>/PWM' */
  VVI_B.VENT_CMP_REF_PWM = VVI_P.PWM_Value;
  VVI_B.FRONTEND_CTRL = true;
}

/* Function for Chart: '<Root>/vvI' */
static void VVI_enter_atomic_Proxy(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  VVI_B.PACING_REF_PWM = VVI_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  VVI_B.PACE_GND_CTRL = true;
  *VENT_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *ATR_PACE_CTRL = false;
  VVI_B.ATR_GND_CTRL = false;
  *VENT_GND_CTRL = true;
  VVI_B.IS_CHARGING = true;

  /* Constant: '<Root>/PWM' */
  VVI_B.VENT_CMP_REF_PWM = VVI_P.PWM_Value;
}

/* Model step function */
void VVI_step(void)
{
  boolean_T ATR_PACE_CTRL;
  boolean_T PACE_CHARGE_CTRL;
  boolean_T VENT_GND_CTRL;
  boolean_T VENT_PACE_CTRL;
  boolean_T Z_ATR_CTRL;
  boolean_T Z_VENT_CTRL;
  boolean_T tmp;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (VVI_DW.obj.SampleTime != VVI_P.DigitalRead_SampleTime) {
    VVI_DW.obj.SampleTime = VVI_P.DigitalRead_SampleTime;
  }

  tmp = MW_digitalIO_read(VVI_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/vvI' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/msec'
   *  MATLABSystem: '<Root>/Digital Read'
   *  Product: '<Root>/Divide'
   */
  if (VVI_DW.temporalCounter_i1 < MAX_uint32_T) {
    VVI_DW.temporalCounter_i1++;
  }

  if (VVI_DW.is_active_c3_VVI == 0U) {
    VVI_DW.is_active_c3_VVI = 1U;
    VVI_DW.is_c3_VVI = VVI_IN_Charging_C22;
    VVI_DW.temporalCounter_i1 = 0U;
    VVI_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
      &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
  } else {
    switch (VVI_DW.is_c3_VVI) {
     case VVI_IN_Charging_C22:
      PACE_CHARGE_CTRL = true;
      VVI_B.PACE_GND_CTRL = true;
      VENT_PACE_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      ATR_PACE_CTRL = false;
      VVI_B.ATR_GND_CTRL = false;
      VENT_GND_CTRL = true;
      VVI_B.IS_CHARGING = true;
      VVI_B.FRONTEND_CTRL = true;
      if (tmp) {
        VVI_DW.DELAY = VVI_P.Constant4_Value;
        VVI_DW.is_c3_VVI = VVI_IN_Proxy;
        VVI_DW.temporalCounter_i1 = 0U;
        VVI_enter_atomic_Proxy(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
          &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      } else if (VVI_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_P.msec_Value /
                  VVI_P.BPM_Value - VVI_P.Constant4_Value)) {
        VVI_DW.is_c3_VVI = VVI_IN_Pacing;
        VVI_DW.temporalCounter_i1 = 0U;
        PACE_CHARGE_CTRL = false;
        VENT_GND_CTRL = false;
        VENT_PACE_CTRL = true;
        VVI_B.IS_CHARGING = false;
      }
      break;

     case VVI_IN_Pacing:
      PACE_CHARGE_CTRL = false;
      VVI_B.PACE_GND_CTRL = true;
      ATR_PACE_CTRL = false;
      VVI_B.ATR_GND_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      VENT_GND_CTRL = false;
      VENT_PACE_CTRL = true;
      VVI_B.IS_CHARGING = false;
      if (VVI_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_P.Constant_Value)) {
        VVI_DW.DELAY = VVI_P.Constant4_Value - VVI_P.Constant_Value;
        VVI_DW.is_c3_VVI = VVI_IN_Proxy;
        VVI_DW.temporalCounter_i1 = 0U;
        VVI_enter_atomic_Proxy(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
          &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      }
      break;

     default:
      /* case IN_Proxy: */
      PACE_CHARGE_CTRL = true;
      VVI_B.PACE_GND_CTRL = true;
      VENT_PACE_CTRL = false;
      Z_ATR_CTRL = false;
      Z_VENT_CTRL = false;
      ATR_PACE_CTRL = false;
      VVI_B.ATR_GND_CTRL = false;
      VENT_GND_CTRL = true;
      VVI_B.IS_CHARGING = true;
      if (VVI_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_DW.DELAY)) {
        VVI_DW.is_c3_VVI = VVI_IN_Charging_C22;
        VVI_DW.temporalCounter_i1 = 0U;
        VVI_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL,
          &Z_VENT_CTRL, &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/vvI' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(VVI_DW.obj_hb.MW_DIGITALIO_HANDLE, VVI_B.IS_CHARGING);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VVI_DW.obj_m.MW_DIGITALIO_HANDLE, VVI_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(VVI_DW.obj_ii.MW_DIGITALIO_HANDLE, VVI_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(VVI_DW.obj_nv.MW_DIGITALIO_HANDLE, VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write12' */
  MW_digitalIO_write(VVI_DW.obj_l.MW_DIGITALIO_HANDLE, VVI_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VVI_DW.obj_h.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VVI_DW.obj_b.MW_DIGITALIO_HANDLE, Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VVI_DW.obj_i.MW_DIGITALIO_HANDLE, Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(VVI_DW.obj_n.MW_DIGITALIO_HANDLE, ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(VVI_DW.obj_j.MW_DIGITALIO_HANDLE, VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(VVI_DW.obj_d.MW_PWM_HANDLE, VVI_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(VVI_DW.obj_bs.MW_PWM_HANDLE, VVI_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(VVI_DW.obj_a.MW_PWM_HANDLE, VVI_B.PACING_REF_PWM);
}

/* Model initialize function */
void VVI_initialize(void)
{
  {
    freedomk64f_DigitalRead_VVI_T *obj;
    freedomk64f_DigitalWrite_VVI_T *obj_0;
    freedomk64f_PWMOutput_VVI_T *obj_1;

    /* SystemInitialize for Chart: '<Root>/vvI' */
    VVI_B.FRONTEND_CTRL = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    VVI_DW.obj.matlabCodegenIsDeleted = true;
    VVI_DW.obj.isInitialized = 0;
    VVI_DW.obj.SampleTime = -1.0;
    VVI_DW.obj.matlabCodegenIsDeleted = false;
    VVI_DW.obj.SampleTime = VVI_P.DigitalRead_SampleTime;
    obj = &VVI_DW.obj;
    VVI_DW.obj.isSetupComplete = false;
    VVI_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    VVI_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    VVI_DW.obj_hb.matlabCodegenIsDeleted = true;
    VVI_DW.obj_hb.isInitialized = 0;
    VVI_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_hb;
    VVI_DW.obj_hb.isSetupComplete = false;
    VVI_DW.obj_hb.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    VVI_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    VVI_DW.obj_m.matlabCodegenIsDeleted = true;
    VVI_DW.obj_m.isInitialized = 0;
    VVI_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_m;
    VVI_DW.obj_m.isSetupComplete = false;
    VVI_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VVI_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    VVI_DW.obj_ii.matlabCodegenIsDeleted = true;
    VVI_DW.obj_ii.isInitialized = 0;
    VVI_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_ii;
    VVI_DW.obj_ii.isSetupComplete = false;
    VVI_DW.obj_ii.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VVI_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    VVI_DW.obj_nv.matlabCodegenIsDeleted = true;
    VVI_DW.obj_nv.isInitialized = 0;
    VVI_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_nv;
    VVI_DW.obj_nv.isSetupComplete = false;
    VVI_DW.obj_nv.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VVI_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write12' */
    VVI_DW.obj_l.matlabCodegenIsDeleted = true;
    VVI_DW.obj_l.isInitialized = 0;
    VVI_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_l;
    VVI_DW.obj_l.isSetupComplete = false;
    VVI_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    VVI_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    VVI_DW.obj_h.matlabCodegenIsDeleted = true;
    VVI_DW.obj_h.isInitialized = 0;
    VVI_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_h;
    VVI_DW.obj_h.isSetupComplete = false;
    VVI_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VVI_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    VVI_DW.obj_b.matlabCodegenIsDeleted = true;
    VVI_DW.obj_b.isInitialized = 0;
    VVI_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_b;
    VVI_DW.obj_b.isSetupComplete = false;
    VVI_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    VVI_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    VVI_DW.obj_i.matlabCodegenIsDeleted = true;
    VVI_DW.obj_i.isInitialized = 0;
    VVI_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_i;
    VVI_DW.obj_i.isSetupComplete = false;
    VVI_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    VVI_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    VVI_DW.obj_n.matlabCodegenIsDeleted = true;
    VVI_DW.obj_n.isInitialized = 0;
    VVI_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_n;
    VVI_DW.obj_n.isSetupComplete = false;
    VVI_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VVI_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    VVI_DW.obj_j.matlabCodegenIsDeleted = true;
    VVI_DW.obj_j.isInitialized = 0;
    VVI_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_DW.obj_j;
    VVI_DW.obj_j.isSetupComplete = false;
    VVI_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VVI_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    VVI_DW.obj_d.matlabCodegenIsDeleted = true;
    VVI_DW.obj_d.isInitialized = 0;
    VVI_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_1 = &VVI_DW.obj_d;
    VVI_DW.obj_d.isSetupComplete = false;
    VVI_DW.obj_d.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(VVI_DW.obj_d.MW_PWM_HANDLE);
    VVI_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    VVI_DW.obj_bs.matlabCodegenIsDeleted = true;
    VVI_DW.obj_bs.isInitialized = 0;
    VVI_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_1 = &VVI_DW.obj_bs;
    VVI_DW.obj_bs.isSetupComplete = false;
    VVI_DW.obj_bs.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(VVI_DW.obj_bs.MW_PWM_HANDLE);
    VVI_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    VVI_DW.obj_a.matlabCodegenIsDeleted = true;
    VVI_DW.obj_a.isInitialized = 0;
    VVI_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &VVI_DW.obj_a;
    VVI_DW.obj_a.isSetupComplete = false;
    VVI_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(VVI_DW.obj_a.MW_PWM_HANDLE);
    VVI_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void VVI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!VVI_DW.obj.matlabCodegenIsDeleted) {
    VVI_DW.obj.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj.isInitialized == 1) && VVI_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VVI_DW.obj_hb.matlabCodegenIsDeleted) {
    VVI_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_hb.isInitialized == 1) && VVI_DW.obj_hb.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_hb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VVI_DW.obj_m.matlabCodegenIsDeleted) {
    VVI_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_m.isInitialized == 1) && VVI_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!VVI_DW.obj_ii.matlabCodegenIsDeleted) {
    VVI_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_ii.isInitialized == 1) && VVI_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!VVI_DW.obj_nv.matlabCodegenIsDeleted) {
    VVI_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_nv.isInitialized == 1) && VVI_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write12' */
  if (!VVI_DW.obj_l.matlabCodegenIsDeleted) {
    VVI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_l.isInitialized == 1) && VVI_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write12' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VVI_DW.obj_h.matlabCodegenIsDeleted) {
    VVI_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_h.isInitialized == 1) && VVI_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VVI_DW.obj_b.matlabCodegenIsDeleted) {
    VVI_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_b.isInitialized == 1) && VVI_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VVI_DW.obj_i.matlabCodegenIsDeleted) {
    VVI_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_i.isInitialized == 1) && VVI_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!VVI_DW.obj_n.matlabCodegenIsDeleted) {
    VVI_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_n.isInitialized == 1) && VVI_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!VVI_DW.obj_j.matlabCodegenIsDeleted) {
    VVI_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_j.isInitialized == 1) && VVI_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(VVI_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!VVI_DW.obj_d.matlabCodegenIsDeleted) {
    VVI_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_d.isInitialized == 1) && VVI_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(VVI_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!VVI_DW.obj_bs.matlabCodegenIsDeleted) {
    VVI_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_bs.isInitialized == 1) && VVI_DW.obj_bs.isSetupComplete) {
      MW_PWM_Stop(VVI_DW.obj_bs.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_DW.obj_bs.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  if (!VVI_DW.obj_a.matlabCodegenIsDeleted) {
    VVI_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((VVI_DW.obj_a.isInitialized == 1) && VVI_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(VVI_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
