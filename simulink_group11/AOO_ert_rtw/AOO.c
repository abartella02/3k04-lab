/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AOO.c
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

#include "AOO.h"
#include "rtwtypes.h"
#include <math.h>
#include "AOO_types.h"

/* Named constants for Chart: '<Root>/AAI' */
#define AOO_IN_Charging_C22            ((uint8_T)1U)
#define AOO_IN_Pacing                  ((uint8_T)2U)

/* Block signals (default storage) */
B_AOO_T AOO_B;

/* Block states (default storage) */
DW_AOO_T AOO_DW;

/* Real-time model */
static RT_MODEL_AOO_T AOO_M_;
RT_MODEL_AOO_T *const AOO_M = &AOO_M_;

/* Forward declaration for local functions */
static void AOO_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL);

/* Function for Chart: '<Root>/AAI' */
static void AOO_enter_atomic_Charging_C22(boolean_T *VENT_PACE_CTRL, boolean_T
  *ATR_PACE_CTRL, boolean_T *Z_VENT_CTRL, boolean_T *Z_ATR_CTRL, boolean_T
  *PACE_CHARGE_CTRL, boolean_T *VENT_GND_CTRL)
{
  /* Constant: '<Root>/PWM' */
  AOO_B.PACING_REF_PWM = AOO_P.PWM_Value;
  *PACE_CHARGE_CTRL = true;
  AOO_B.PACE_GND_CTRL = true;
  *ATR_PACE_CTRL = false;
  *Z_ATR_CTRL = false;
  *Z_VENT_CTRL = false;
  *VENT_PACE_CTRL = false;
  *VENT_GND_CTRL = false;
  AOO_B.ATR_GND_CTRL = true;
  AOO_B.IS_CHARGING = true;

  /* Constant: '<Root>/Constant1' */
  AOO_B.ATR_CMP_REF_PWM = AOO_P.Constant1_Value;
}

/* Model step function */
void AOO_step(void)
{
  boolean_T ATR_PACE_CTRL;
  boolean_T PACE_CHARGE_CTRL;
  boolean_T VENT_GND_CTRL;
  boolean_T VENT_PACE_CTRL;
  boolean_T Z_ATR_CTRL;
  boolean_T Z_VENT_CTRL;

  /* Chart: '<Root>/AAI' incorporates:
   *  Constant: '<Root>/BPM'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/msec'
   *  Product: '<Root>/Divide'
   */
  if (AOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    AOO_DW.temporalCounter_i1++;
  }

  if (AOO_DW.is_active_c3_AOO == 0U) {
    AOO_DW.is_active_c3_AOO = 1U;
    AOO_DW.is_c3_AOO = AOO_IN_Charging_C22;
    AOO_DW.temporalCounter_i1 = 0U;
    AOO_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL, &Z_VENT_CTRL,
      &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
  } else if (AOO_DW.is_c3_AOO == AOO_IN_Charging_C22) {
    PACE_CHARGE_CTRL = true;
    AOO_B.PACE_GND_CTRL = true;
    ATR_PACE_CTRL = false;
    Z_ATR_CTRL = false;
    Z_VENT_CTRL = false;
    VENT_PACE_CTRL = false;
    VENT_GND_CTRL = false;
    AOO_B.ATR_GND_CTRL = true;
    AOO_B.IS_CHARGING = true;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(AOO_P.msec_Value /
         AOO_P.BPM_Value - AOO_P.Constant_Value)) {
      AOO_DW.is_c3_AOO = AOO_IN_Pacing;
      AOO_DW.temporalCounter_i1 = 0U;
      PACE_CHARGE_CTRL = false;
      AOO_B.ATR_GND_CTRL = false;
      ATR_PACE_CTRL = true;
      AOO_B.IS_CHARGING = false;
    }
  } else {
    /* case IN_Pacing: */
    PACE_CHARGE_CTRL = false;
    AOO_B.PACE_GND_CTRL = true;
    VENT_PACE_CTRL = false;
    VENT_GND_CTRL = false;
    Z_ATR_CTRL = false;
    Z_VENT_CTRL = false;
    AOO_B.ATR_GND_CTRL = false;
    ATR_PACE_CTRL = true;
    AOO_B.IS_CHARGING = false;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(AOO_P.Constant_Value)) {
      AOO_DW.is_c3_AOO = AOO_IN_Charging_C22;
      AOO_DW.temporalCounter_i1 = 0U;
      AOO_enter_atomic_Charging_C22(&VENT_PACE_CTRL, &ATR_PACE_CTRL,
        &Z_VENT_CTRL, &Z_ATR_CTRL, &PACE_CHARGE_CTRL, &VENT_GND_CTRL);
    }
  }

  /* End of Chart: '<Root>/AAI' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AOO_DW.obj_hb.MW_DIGITALIO_HANDLE, AOO_B.IS_CHARGING);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AOO_DW.obj_m.MW_DIGITALIO_HANDLE, AOO_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(AOO_DW.obj_ii.MW_DIGITALIO_HANDLE, AOO_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(AOO_DW.obj_nv.MW_DIGITALIO_HANDLE, VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write12' */
  MW_digitalIO_write(AOO_DW.obj_l.MW_DIGITALIO_HANDLE, AOO_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(AOO_DW.obj_h.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AOO_DW.obj_b.MW_DIGITALIO_HANDLE, Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(AOO_DW.obj_i.MW_DIGITALIO_HANDLE, Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(AOO_DW.obj_n.MW_DIGITALIO_HANDLE, ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(AOO_DW.obj.MW_DIGITALIO_HANDLE, VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(AOO_DW.obj_d.MW_PWM_HANDLE, AOO_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(AOO_DW.obj_bs.MW_PWM_HANDLE, AOO_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(AOO_DW.obj_a.MW_PWM_HANDLE, AOO_B.PACING_REF_PWM);

  /* Requirements Table: '<Root>/Requirements Table' */
  AOO_DW.doneDoubleBufferReInit = true;

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
void AOO_initialize(void)
{
  {
    freedomk64f_DigitalWrite_AOO_T *obj;
    freedomk64f_PWMOutput_AOO_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    AOO_DW.obj_hb.matlabCodegenIsDeleted = true;
    AOO_DW.obj_hb.isInitialized = 0;
    AOO_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_hb;
    AOO_DW.obj_hb.isSetupComplete = false;
    AOO_DW.obj_hb.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    AOO_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    AOO_DW.obj_m.matlabCodegenIsDeleted = true;
    AOO_DW.obj_m.isInitialized = 0;
    AOO_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_m;
    AOO_DW.obj_m.isSetupComplete = false;
    AOO_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AOO_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    AOO_DW.obj_ii.matlabCodegenIsDeleted = true;
    AOO_DW.obj_ii.isInitialized = 0;
    AOO_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_ii;
    AOO_DW.obj_ii.isSetupComplete = false;
    AOO_DW.obj_ii.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AOO_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    AOO_DW.obj_nv.matlabCodegenIsDeleted = true;
    AOO_DW.obj_nv.isInitialized = 0;
    AOO_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_nv;
    AOO_DW.obj_nv.isSetupComplete = false;
    AOO_DW.obj_nv.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AOO_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write12' */
    AOO_DW.obj_l.matlabCodegenIsDeleted = true;
    AOO_DW.obj_l.isInitialized = 0;
    AOO_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_l;
    AOO_DW.obj_l.isSetupComplete = false;
    AOO_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AOO_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    AOO_DW.obj_h.matlabCodegenIsDeleted = true;
    AOO_DW.obj_h.isInitialized = 0;
    AOO_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_h;
    AOO_DW.obj_h.isSetupComplete = false;
    AOO_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AOO_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    AOO_DW.obj_b.matlabCodegenIsDeleted = true;
    AOO_DW.obj_b.isInitialized = 0;
    AOO_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_b;
    AOO_DW.obj_b.isSetupComplete = false;
    AOO_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    AOO_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    AOO_DW.obj_i.matlabCodegenIsDeleted = true;
    AOO_DW.obj_i.isInitialized = 0;
    AOO_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_i;
    AOO_DW.obj_i.isSetupComplete = false;
    AOO_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    AOO_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    AOO_DW.obj_n.matlabCodegenIsDeleted = true;
    AOO_DW.obj_n.isInitialized = 0;
    AOO_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj_n;
    AOO_DW.obj_n.isSetupComplete = false;
    AOO_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AOO_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    AOO_DW.obj.matlabCodegenIsDeleted = true;
    AOO_DW.obj.isInitialized = 0;
    AOO_DW.obj.matlabCodegenIsDeleted = false;
    obj = &AOO_DW.obj;
    AOO_DW.obj.isSetupComplete = false;
    AOO_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AOO_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    AOO_DW.obj_d.matlabCodegenIsDeleted = true;
    AOO_DW.obj_d.isInitialized = 0;
    AOO_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &AOO_DW.obj_d;
    AOO_DW.obj_d.isSetupComplete = false;
    AOO_DW.obj_d.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(AOO_DW.obj_d.MW_PWM_HANDLE);
    AOO_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    AOO_DW.obj_bs.matlabCodegenIsDeleted = true;
    AOO_DW.obj_bs.isInitialized = 0;
    AOO_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_0 = &AOO_DW.obj_bs;
    AOO_DW.obj_bs.isSetupComplete = false;
    AOO_DW.obj_bs.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(AOO_DW.obj_bs.MW_PWM_HANDLE);
    AOO_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    AOO_DW.obj_a.matlabCodegenIsDeleted = true;
    AOO_DW.obj_a.isInitialized = 0;
    AOO_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &AOO_DW.obj_a;
    AOO_DW.obj_a.isSetupComplete = false;
    AOO_DW.obj_a.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(AOO_DW.obj_a.MW_PWM_HANDLE);
    AOO_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void AOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AOO_DW.obj_hb.matlabCodegenIsDeleted) {
    AOO_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_hb.isInitialized == 1) && AOO_DW.obj_hb.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_hb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AOO_DW.obj_m.matlabCodegenIsDeleted) {
    AOO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_m.isInitialized == 1) && AOO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!AOO_DW.obj_ii.matlabCodegenIsDeleted) {
    AOO_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_ii.isInitialized == 1) && AOO_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!AOO_DW.obj_nv.matlabCodegenIsDeleted) {
    AOO_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_nv.isInitialized == 1) && AOO_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write12' */
  if (!AOO_DW.obj_l.matlabCodegenIsDeleted) {
    AOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_l.isInitialized == 1) && AOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write12' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!AOO_DW.obj_h.matlabCodegenIsDeleted) {
    AOO_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_h.isInitialized == 1) && AOO_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AOO_DW.obj_b.matlabCodegenIsDeleted) {
    AOO_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_b.isInitialized == 1) && AOO_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!AOO_DW.obj_i.matlabCodegenIsDeleted) {
    AOO_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_i.isInitialized == 1) && AOO_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!AOO_DW.obj_n.matlabCodegenIsDeleted) {
    AOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_n.isInitialized == 1) && AOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!AOO_DW.obj.matlabCodegenIsDeleted) {
    AOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj.isInitialized == 1) && AOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!AOO_DW.obj_d.matlabCodegenIsDeleted) {
    AOO_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_d.isInitialized == 1) && AOO_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(AOO_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(AOO_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!AOO_DW.obj_bs.matlabCodegenIsDeleted) {
    AOO_DW.obj_bs.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_bs.isInitialized == 1) && AOO_DW.obj_bs.isSetupComplete) {
      MW_PWM_Stop(AOO_DW.obj_bs.MW_PWM_HANDLE);
      MW_PWM_Close(AOO_DW.obj_bs.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  if (!AOO_DW.obj_a.matlabCodegenIsDeleted) {
    AOO_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_a.isInitialized == 1) && AOO_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(AOO_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(AOO_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
