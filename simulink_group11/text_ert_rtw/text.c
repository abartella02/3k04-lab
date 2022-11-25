/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: text.c
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

#include "text.h"
#include "text_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "Send_DCM.h"
#include "Send_DCM_private.h"

/* Named constants for Chart: '<Root>/Serial Communication1' */
#define text_IN_ECHO_PARAM             ((uint8_T)1U)
#define text_IN_ECHO_PARAM1            ((uint8_T)2U)
#define text_IN_Init                   ((uint8_T)3U)
#define text_IN_STANDBY                ((uint8_T)4U)
#define text_IN_SettingParameters      ((uint8_T)5U)

/* Block signals (default storage) */
B_text_T text_B;

/* Block states (default storage) */
DW_text_T text_DW;

/* Real-time model */
static RT_MODEL_text_T text_M_;
RT_MODEL_text_T *const text_M = &text_M_;

/* Forward declaration for local functions */
static void text_SystemCore_setup_m(freedomk64f_SCIRead_text_T *obj);
static void text_SystemCore_setup_m(freedomk64f_SCIRead_text_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  text_B.TxPinLoc = MW_UNDEFINED_VALUE;
  text_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&text_B.SCIModuleLoc, false, 10U,
    text_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void text_step(void)
{
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (text_DW.obj_k.SampleTime != text_P.SerialReceive_SampleTime) {
    text_DW.obj_k.SampleTime = text_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(text_DW.obj_k.MW_SCIHANDLE, &text_B.RxDataLocChar[0],
    66U);
  memcpy((void *)&text_B.RxData[0], (void *)&text_B.RxDataLocChar[0], (uint32_T)
         ((size_t)66 * sizeof(uint8_T)));

  /* MATLABSystem: '<Root>/ATR_SIGNAL' */
  if (text_DW.obj_n.SampleTime != text_P.ATR_SIGNAL_SampleTime) {
    text_DW.obj_n.SampleTime = text_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(text_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(text_DW.obj_n.MW_ANALOGIN_HANDLE,
    &text_B.ATR_SIGNAL, 7);

  /* End of MATLABSystem: '<Root>/ATR_SIGNAL' */

  /* MATLABSystem: '<Root>/VENT_SIGNAL' */
  if (text_DW.obj.SampleTime != text_P.VENT_SIGNAL_SampleTime) {
    text_DW.obj.SampleTime = text_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(text_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(text_DW.obj.MW_ANALOGIN_HANDLE,
    &text_B.VENT_SIGNAL, 7);

  /* End of MATLABSystem: '<Root>/VENT_SIGNAL' */

  /* Chart: '<Root>/Serial Communication1' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (text_DW.is_active_c1_text == 0U) {
    text_DW.is_active_c1_text = 1U;
    text_DW.is_c1_text = text_IN_Init;
    text_B.MODE_n = 2U;
    text_B.LOWER_RATE_LIMIT_e = 60U;
    text_B.UPPER_RATE_LIMIT_g = 120U;
    text_B.ATR_AMP_REG_f = 3.5;
    text_B.VENT_AMP_REG_o = 3.5;
    text_B.ATR_PW_n = 0.4;
    text_B.VENT_PW_n = 0.4;
    text_B.ATR_SENSITIVITY_l = 0.75;
    text_B.VENT_SENSITIVITY_b = 2.5;
    text_B.ATR_REF_PERIOD_h = 250U;
    text_B.VENT_REF_PERIOD_j = 320U;
    text_B.PVARP_c = 250U;
    text_B.HYSTERESIS_RATE_LIMIT_c = 0U;
    text_B.RATE_SMOOTHING_d = 0U;
  } else {
    switch (text_DW.is_c1_text) {
     case text_IN_ECHO_PARAM:
      text_DW.is_c1_text = text_IN_STANDBY;
      break;

     case text_IN_ECHO_PARAM1:
      text_DW.is_c1_text = text_IN_STANDBY;
      break;

     case text_IN_Init:
      text_DW.is_c1_text = text_IN_STANDBY;
      break;

     case text_IN_STANDBY:
      if (status == 0) {
        if (text_B.RxData[0] == 22) {
          switch (text_B.RxData[1]) {
           case 85:
            text_DW.is_c1_text = text_IN_SettingParameters;
            memcpy((void *)&text_B.MODE_n, (void *)&text_B.RxData[2], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.LOWER_RATE_LIMIT_e, (void *)&text_B.RxData[4],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.UPPER_RATE_LIMIT_g, (void *)&text_B.RxData[6],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.ATR_AMP_REG_f, (void *)&text_B.RxData[8],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.VENT_AMP_REG_o, (void *)&text_B.RxData[16],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.ATR_PW_n, (void *)&text_B.RxData[24],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.VENT_PW_n, (void *)&text_B.RxData[32],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.ATR_SENSITIVITY_l, (void *)&text_B.RxData[40],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.VENT_SENSITIVITY_b, (void *)&text_B.RxData[48],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&text_B.ATR_REF_PERIOD_h, (void *)&text_B.RxData[56],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.VENT_REF_PERIOD_j, (void *)&text_B.RxData[58],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.PVARP_c, (void *)&text_B.RxData[60],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.HYSTERESIS_RATE_LIMIT_c, (void *)
                   &text_B.RxData[62], (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&text_B.RATE_SMOOTHING_d, (void *)&text_B.RxData[64],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            break;

           case 34:
            text_DW.is_c1_text = text_IN_ECHO_PARAM;
            Send_DCM();
            break;

           case 51:
            text_DW.is_c1_text = text_IN_ECHO_PARAM1;
            Send_DCM();
            break;

           default:
            text_DW.is_c1_text = text_IN_STANDBY;
            break;
          }
        } else {
          text_DW.is_c1_text = text_IN_STANDBY;
        }
      }
      break;

     default:
      /* case IN_SettingParameters: */
      text_DW.is_c1_text = text_IN_STANDBY;
      break;
    }
  }

  /* End of Chart: '<Root>/Serial Communication1' */

  /* MATLABSystem: '<Root>/Digital Read' */
  if (text_DW.obj_a.SampleTime != text_P.DigitalRead_SampleTime) {
    text_DW.obj_a.SampleTime = text_P.DigitalRead_SampleTime;
  }

  MW_digitalIO_read(text_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<Root>/Digital Read' */

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (text_DW.obj_o.SampleTime != text_P.DigitalRead1_SampleTime) {
    text_DW.obj_o.SampleTime = text_P.DigitalRead1_SampleTime;
  }

  MW_digitalIO_read(text_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<Root>/Digital Read1' */
}

/* Model initialize function */
void text_initialize(void)
{
  {
    freedomk64f_AnalogInput_text_T *obj;
    freedomk64f_DigitalRead_text_T *obj_0;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
     *  SubSystem: '<Root>/Serial transmit'
     */
    Send_DCM_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    text_DW.obj_k.isInitialized = 0;
    text_DW.obj_k.matlabCodegenIsDeleted = false;
    text_DW.obj_k.SampleTime = text_P.SerialReceive_SampleTime;
    text_SystemCore_setup_m(&text_DW.obj_k);

    /* Start for MATLABSystem: '<Root>/ATR_SIGNAL' */
    text_DW.obj_n.matlabCodegenIsDeleted = true;
    text_DW.obj_n.isInitialized = 0;
    text_DW.obj_n.SampleTime = -1.0;
    text_DW.obj_n.matlabCodegenIsDeleted = false;
    text_DW.obj_n.SampleTime = text_P.ATR_SIGNAL_SampleTime;
    obj = &text_DW.obj_n;
    text_DW.obj_n.isSetupComplete = false;
    text_DW.obj_n.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    text_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(text_DW.obj_n.MW_ANALOGIN_HANDLE,
      text_B.trigger_val, 0U);
    text_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VENT_SIGNAL' */
    text_DW.obj.matlabCodegenIsDeleted = true;
    text_DW.obj.isInitialized = 0;
    text_DW.obj.SampleTime = -1.0;
    text_DW.obj.matlabCodegenIsDeleted = false;
    text_DW.obj.SampleTime = text_P.VENT_SIGNAL_SampleTime;
    obj = &text_DW.obj;
    text_DW.obj.isSetupComplete = false;
    text_DW.obj.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    text_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(text_DW.obj.MW_ANALOGIN_HANDLE,
      text_B.trigger_val, 0U);
    text_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    text_DW.obj_a.matlabCodegenIsDeleted = true;
    text_DW.obj_a.isInitialized = 0;
    text_DW.obj_a.SampleTime = -1.0;
    text_DW.obj_a.matlabCodegenIsDeleted = false;
    text_DW.obj_a.SampleTime = text_P.DigitalRead_SampleTime;
    obj_0 = &text_DW.obj_a;
    text_DW.obj_a.isSetupComplete = false;
    text_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    text_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    text_DW.obj_o.matlabCodegenIsDeleted = true;
    text_DW.obj_o.isInitialized = 0;
    text_DW.obj_o.SampleTime = -1.0;
    text_DW.obj_o.matlabCodegenIsDeleted = false;
    text_DW.obj_o.SampleTime = text_P.DigitalRead1_SampleTime;
    obj_0 = &text_DW.obj_o;
    text_DW.obj_o.isSetupComplete = false;
    text_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    text_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void text_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!text_DW.obj_k.matlabCodegenIsDeleted) {
    text_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((text_DW.obj_k.isInitialized == 1) && text_DW.obj_k.isSetupComplete) {
      MW_SCI_Close(text_DW.obj_k.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/ATR_SIGNAL' */
  if (!text_DW.obj_n.matlabCodegenIsDeleted) {
    text_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((text_DW.obj_n.isInitialized == 1) && text_DW.obj_n.isSetupComplete) {
      MW_AnalogIn_Stop(text_DW.obj_n.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(text_DW.obj_n.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<Root>/VENT_SIGNAL' */
  if (!text_DW.obj.matlabCodegenIsDeleted) {
    text_DW.obj.matlabCodegenIsDeleted = true;
    if ((text_DW.obj.isInitialized == 1) && text_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(text_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(text_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/VENT_SIGNAL' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
   *  SubSystem: '<Root>/Serial transmit'
   */
  Send_DCM_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!text_DW.obj_a.matlabCodegenIsDeleted) {
    text_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((text_DW.obj_a.isInitialized == 1) && text_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(text_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!text_DW.obj_o.matlabCodegenIsDeleted) {
    text_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((text_DW.obj_o.isInitialized == 1) && text_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(text_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
