/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOO.c
 *
 * Code generated for Simulink model 'VOO'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 23 15:12:48 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VOO.h"
#include "rtwtypes.h"
#include <math.h>
#include "VOO_types.h"

/* Named constants for Chart: '<Root>/VOO' */
#define VOO_IN_Charging_C22            ((uint8_T)1U)
#define VOO_IN_Pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_VOO_T VOO_B;

/* Block states (default storage) */
DW_VOO_T VOO_DW;

/* Real-time model */
static RT_MODEL_VOO_T VOO_M_;
RT_MODEL_VOO_T *const VOO_M = &VOO_M_;

/* Forward declaration for local functions */
static void VOO_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);

/* Function for Chart: '<Root>/VOO' */
static void VOO_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  VOO_B.PACING_REF_PWM = VOO_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  VOO_B.PACE_GND_CTRL = true;
  *VENT_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *ATR_PACE_CTRL = false;
  VOO_B.ATR_GND_CTRL = false;
  *VENT_GND_CTRL = true;
  VOO_B.IS_CHARGING = true;

  /* Constant: '<Root>/PWM1' */
  VOO_B.VENT_CMP_REF_PWM = VOO_P.PWM1_Value;
}

/* Model step function */
void VOO_step(void)
{
  boolean_T ATR_PACE_CTRL;
  boolean_T PACE_CHARGE_CTRL;
  boolean_T VENT_GND_CTRL;
  boolean_T VENT_PACE_CTRL;
  boolean_T Z_ATR_CTRL;
  boolean_T Z_VENT_CTRL;

  /* Chart: '<Root>/VOO' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/msec'
   *  Product: '<Root>/Divide'
   */
  if (VOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    VOO_DW.temporalCounter_i1++;
  }

  if (VOO_DW.is_active_c3_VOO == 0U) {
    VOO_DW.is_active_c3_VOO = 1U;
    VOO_DW.is_c3_VOO = VOO_IN_Charging_C22;
    VOO_DW.temporalCounter_i1 = 0U;
    VOO_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
      &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
  } else if (VOO_DW.is_c3_VOO == VOO_IN_Charging_C22) {
    PACE_CHARGE_CTRL = true;
    VOO_B.PACE_GND_CTRL = true;
    VENT_PACE_CTRL = false;
    Z_ATR_CTRL = false;
    Z_VENT_CTRL = false;
    ATR_PACE_CTRL = false;
    VOO_B.ATR_GND_CTRL = false;
    VENT_GND_CTRL = true;
    VOO_B.IS_CHARGING = true;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(VOO_P.msec_Value /
         VOO_P.BPM_Value - VOO_P.Constant_Value)) {
      VOO_DW.is_c3_VOO = VOO_IN_Pacing;
      VOO_DW.temporalCounter_i1 = 0U;
      PACE_CHARGE_CTRL = false;
      VENT_GND_CTRL = false;
      VENT_PACE_CTRL = true;
      VOO_B.IS_CHARGING = false;
    }
  } else {
    /* case IN_Pacing: */
    PACE_CHARGE_CTRL = false;
    VOO_B.PACE_GND_CTRL = true;
    ATR_PACE_CTRL = false;
    VOO_B.ATR_GND_CTRL = false;
    Z_ATR_CTRL = false;
    Z_VENT_CTRL = false;
    VENT_GND_CTRL = false;
    VENT_PACE_CTRL = true;
    VOO_B.IS_CHARGING = false;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(VOO_P.Constant_Value)) {
      VOO_DW.is_c3_VOO = VOO_IN_Charging_C22;
      VOO_DW.temporalCounter_i1 = 0U;
      VOO_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL,
        &Z_VENT_CTRL, &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
    }
  }

  /* End of Chart: '<Root>/VOO' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(VOO_DW.obj_hb.MW_DIGITALIO_HANDLE, VOO_B.IS_CHARGING);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VOO_DW.obj_m.MW_DIGITALIO_HANDLE, VOO_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(VOO_DW.obj_ii.MW_DIGITALIO_HANDLE, VOO_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(VOO_DW.obj_nv.MW_DIGITALIO_HANDLE, VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write12' */
  MW_digitalIO_write(VOO_DW.obj_l.MW_DIGITALIO_HANDLE, VOO_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VOO_DW.obj_h.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VOO_DW.obj_b.MW_DIGITALIO_HANDLE, Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VOO_DW.obj_i.MW_DIGITALIO_HANDLE, Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(VOO_DW.obj_n.MW_DIGITALIO_HANDLE, ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(VOO_DW.obj.MW_DIGITALIO_HANDLE, VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(VOO_DW.obj_d.MW_PWM_HANDLE, VOO_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(VOO_DW.obj_bs.MW_PWM_HANDLE, VOO_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(VOO_DW.obj_a.MW_PWM_HANDLE, VOO_B.PACING_REF_PWM);

  /* Requirements Table: '<Root>/Requirements Table' */
  VOO_DW.doneDoubleBufferReInit = true;

  /*  SF_REQ_REV_07 */
  /*  HEADER_ASSIGNMENTS */
  /*  START_A_4 */
  /*  END_A_4 */
  /*  START_R_1 */
  /*  START_R_7 */
  /*  END_R_7 */
  /*  START_R_10 */
  /*  END_R_10 */
  /*  END_R_1 */
}

/* Model initialize function */
void VOO_initialize(void)
{
  {
    freedomk64f_DigitalWrite_VOO_T *obj;
    freedomk64f_PWMOutput_VOO_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    VOO_DW.obj_hb.matlabCodegenIsDeleted = true;
    VOO_DW.obj_hb.isInitialized = 0;
    VOO_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_hb;
    VOO_DW.obj_hb.isSetupComplete = false;
    VOO_DW.obj_hb.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    VOO_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    VOO_DW.obj_m.matlabCodegenIsDeleted = true;
    VOO_DW.obj_m.isInitialized = 0;
    VOO_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_m;
    VOO_DW.obj_m.isSetupComplete = false;
    VOO_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VOO_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    VOO_DW.obj_ii.matlabCodegenIsDeleted = true;
    VOO_DW.obj_ii.isInitialized = 0;
    VOO_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_ii;
    VOO_DW.obj_ii.isSetupComplete = false;
    VOO_DW.obj_ii.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VOO_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    VOO_DW.obj_nv.matlabCodegenIsDeleted = true;
    VOO_DW.obj_nv.isInitialized = 0;
    VOO_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_nv;
    VOO_DW.obj_nv.isSetupComplete = false;
    VOO_DW.obj_nv.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VOO_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write12' */
    VOO_DW.obj_l.matlabCodegenIsDeleted = true;
    VOO_DW.obj_l.isInitialized = 0;
    VOO_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_l;
    VOO_DW.obj_l.isSetupComplete = false;
    VOO_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    VOO_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    VOO_DW.obj_h.matlabCodegenIsDeleted = true;
    VOO_DW.obj_h.isInitialized = 0;
    VOO_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_h;
    VOO_DW.obj_h.isSetupComplete = false;
    VOO_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VOO_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    VOO_DW.obj_b.matlabCodegenIsDeleted = true;
    VOO_DW.obj_b.isInitialized = 0;
    VOO_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_b;
    VOO_DW.obj_b.isSetupComplete = false;
    VOO_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    VOO_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    VOO_DW.obj_i.matlabCodegenIsDeleted = true;
    VOO_DW.obj_i.isInitialized = 0;
    VOO_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_i;
    VOO_DW.obj_i.isSetupComplete = false;
    VOO_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    VOO_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    VOO_DW.obj_n.matlabCodegenIsDeleted = true;
    VOO_DW.obj_n.isInitialized = 0;
    VOO_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_n;
    VOO_DW.obj_n.isSetupComplete = false;
    VOO_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VOO_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    VOO_DW.obj.matlabCodegenIsDeleted = true;
    VOO_DW.obj.isInitialized = 0;
    VOO_DW.obj.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj;
    VOO_DW.obj.isSetupComplete = false;
    VOO_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VOO_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    VOO_DW.obj_d.matlabCodegenIsDeleted = true;
    VOO_DW.obj_d.isInitialized = 0;
    VOO_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &VOO_DW.obj_d;
    VOO_DW.obj_d.isSetupComplete = false;
    VOO_DW.obj_d.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(VOO_DW.obj_d.MW_PWM_HANDLE);
    VOO_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    VOO_DW.obj_bs.matlabCodegenIsDeleted = true;
    VOO_DW.obj_bs.isInitialized = 0;
    VOO_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_0 = &VOO_DW.obj_bs;
    VOO_DW.obj_bs.isSetupComplete = false;
    VOO_DW.obj_bs.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(VOO_DW.obj_bs.MW_PWM_HANDLE);
    VOO_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    VOO_DW.obj_a.matlabCodegenIsDeleted = true;
    VOO_DW.obj_a.isInitialized = 0;
    VOO_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &VOO_DW.obj_a;
    VOO_DW.obj_a.isSetupComplete = false;
    VOO_DW.obj_a.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(VOO_DW.obj_a.MW_PWM_HANDLE);
    VOO_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void VOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VOO_DW.obj_hb.matlabCodegenIsDeleted) {
    VOO_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_hb.isInitialized == 1) && VOO_DW.obj_hb.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_hb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VOO_DW.obj_m.matlabCodegenIsDeleted) {
    VOO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_m.isInitialized == 1) && VOO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!VOO_DW.obj_ii.matlabCodegenIsDeleted) {
    VOO_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_ii.isInitialized == 1) && VOO_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!VOO_DW.obj_nv.matlabCodegenIsDeleted) {
    VOO_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_nv.isInitialized == 1) && VOO_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write12' */
  if (!VOO_DW.obj_l.matlabCodegenIsDeleted) {
    VOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_l.isInitialized == 1) && VOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write12' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VOO_DW.obj_h.matlabCodegenIsDeleted) {
    VOO_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_h.isInitialized == 1) && VOO_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VOO_DW.obj_b.matlabCodegenIsDeleted) {
    VOO_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_b.isInitialized == 1) && VOO_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VOO_DW.obj_i.matlabCodegenIsDeleted) {
    VOO_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_i.isInitialized == 1) && VOO_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!VOO_DW.obj_n.matlabCodegenIsDeleted) {
    VOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_n.isInitialized == 1) && VOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!VOO_DW.obj.matlabCodegenIsDeleted) {
    VOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj.isInitialized == 1) && VOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!VOO_DW.obj_d.matlabCodegenIsDeleted) {
    VOO_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_d.isInitialized == 1) && VOO_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(VOO_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(VOO_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!VOO_DW.obj_bs.matlabCodegenIsDeleted) {
    VOO_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_bs.isInitialized == 1) && VOO_DW.obj_bs.isSetupComplete) {
      MW_PWM_Stop(VOO_DW.obj_bs.MW_PWM_HANDLE);
      MW_PWM_Close(VOO_DW.obj_bs.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  if (!VOO_DW.obj_a.matlabCodegenIsDeleted) {
    VOO_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_a.isInitialized == 1) && VOO_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(VOO_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(VOO_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
