/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Send_DCM.c
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

#include "text_types.h"
#include "Send_DCM_private.h"
#include "text.h"
#include "Send_DCM.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void text_SystemCore_setup(freedomk64f_SCIWrite_text_T *obj);
static void text_SystemCore_setup(freedomk64f_SCIWrite_text_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM_Init(void)
{
  /* Start for MATLABSystem: '<S2>/Serial Transmit' */
  text_DW.obj_h.isInitialized = 0;
  text_DW.obj_h.matlabCodegenIsDeleted = false;
  text_SystemCore_setup(&text_DW.obj_h);
}

/* Output and update for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S2>/MODE' */
  text_B.MODE = text_B.MODE_n;

  /* SignalConversion generated from: '<S2>/LOWER_RATE_LIMIT' */
  text_B.LOWER_RATE_LIMIT = text_B.LOWER_RATE_LIMIT_e;

  /* SignalConversion generated from: '<S2>/UPPER_RATE_LIMIT' */
  text_B.UPPER_RATE_LIMIT = text_B.UPPER_RATE_LIMIT_g;

  /* SignalConversion generated from: '<S2>/ATR_AMP_REG' */
  text_B.ATR_AMP_REG = text_B.ATR_AMP_REG_f;

  /* SignalConversion generated from: '<S2>/VENT_AMP_REG' */
  text_B.VENT_AMP_REG = text_B.VENT_AMP_REG_o;

  /* SignalConversion generated from: '<S2>/ATR_PW' */
  text_B.ATR_PW = text_B.ATR_PW_n;

  /* SignalConversion generated from: '<S2>/VENT_PW' */
  text_B.VENT_PW = text_B.VENT_PW_n;

  /* SignalConversion generated from: '<S2>/ATR_SENSITIVITY' */
  text_B.ATR_SENSITIVITY = text_B.ATR_SENSITIVITY_l;

  /* SignalConversion generated from: '<S2>/VENT_SENSITIVITY' */
  text_B.VENT_SENSITIVITY = text_B.VENT_SENSITIVITY_b;

  /* SignalConversion generated from: '<S2>/VENT_REF_PERIOD' */
  text_B.VENT_REF_PERIOD = text_B.VENT_REF_PERIOD_j;

  /* SignalConversion generated from: '<S2>/ATR_REF_PERIOD' */
  text_B.ATR_REF_PERIOD = text_B.ATR_REF_PERIOD_h;

  /* SignalConversion generated from: '<S2>/PVARP' */
  text_B.PVARP = text_B.PVARP_c;

  /* SignalConversion generated from: '<S2>/HYSTERESIS_RATE_LIMIT' */
  text_B.HYSTERESIS_RATE_LIMIT = text_B.HYSTERESIS_RATE_LIMIT_c;

  /* SignalConversion generated from: '<S2>/RATE_SMOOTHING' */
  text_B.RATE_SMOOTHING = text_B.RATE_SMOOTHING_d;

  /* SignalConversion generated from: '<S2>/ATR_SIGNAL' */
  text_B.TmpLatchAtATR_SIGNALOutport1 = text_B.ATR_SIGNAL;

  /* SignalConversion generated from: '<S2>/VENT_SIGNAL' */
  text_B.TmpLatchAtVENT_SIGNALOutport1 = text_B.VENT_SIGNAL;

  /* S-Function (any2byte): '<S2>/Byte Pack' */

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&text_B.BytePack[0], &text_B.MODE,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  (void) memcpy(&text_B.BytePack1[0], &text_B.LOWER_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack7' */

  /* Pack: <S2>/Byte Pack7 */
  (void) memcpy(&text_B.BytePack7[0], &text_B.UPPER_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack2' */

  /* Pack: <S2>/Byte Pack2 */
  (void) memcpy(&text_B.BytePack2[0], &text_B.ATR_AMP_REG,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack3' */

  /* Pack: <S2>/Byte Pack3 */
  (void) memcpy(&text_B.BytePack3[0], &text_B.VENT_AMP_REG,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack4' */

  /* Pack: <S2>/Byte Pack4 */
  (void) memcpy(&text_B.BytePack4[0], &text_B.ATR_PW,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack5' */

  /* Pack: <S2>/Byte Pack5 */
  (void) memcpy(&text_B.BytePack5[0], &text_B.VENT_PW,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack6' */

  /* Pack: <S2>/Byte Pack6 */
  (void) memcpy(&text_B.BytePack6[0], &text_B.ATR_SENSITIVITY,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack8' */

  /* Pack: <S2>/Byte Pack8 */
  (void) memcpy(&text_B.BytePack8[0], &text_B.VENT_SENSITIVITY,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack9' */

  /* Pack: <S2>/Byte Pack9 */
  (void) memcpy(&text_B.BytePack9[0], &text_B.VENT_REF_PERIOD,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack10' */

  /* Pack: <S2>/Byte Pack10 */
  (void) memcpy(&text_B.BytePack10[0], &text_B.ATR_REF_PERIOD,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack11' */

  /* Pack: <S2>/Byte Pack11 */
  (void) memcpy(&text_B.BytePack11[0], &text_B.PVARP,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack12' */

  /* Pack: <S2>/Byte Pack12 */
  (void) memcpy(&text_B.BytePack12[0], &text_B.HYSTERESIS_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack13' */

  /* Pack: <S2>/Byte Pack13 */
  (void) memcpy(&text_B.BytePack13[0], &text_B.RATE_SMOOTHING,
                2);

  /* SignalConversion generated from: '<S2>/Serial Transmit' */
  text_B.TmpSignalConversionAtSerial[0] = text_B.BytePack[0];
  text_B.TmpSignalConversionAtSerial[2] = text_B.BytePack1[0];
  text_B.TmpSignalConversionAtSerial[4] = text_B.BytePack7[0];
  text_B.TmpSignalConversionAtSerial[1] = text_B.BytePack[1];
  text_B.TmpSignalConversionAtSerial[3] = text_B.BytePack1[1];
  text_B.TmpSignalConversionAtSerial[5] = text_B.BytePack7[1];
  for (i = 0; i < 8; i++) {
    text_B.TmpSignalConversionAtSerial[i + 6] = text_B.BytePack2[i];
    text_B.TmpSignalConversionAtSerial[i + 14] = text_B.BytePack3[i];
    text_B.TmpSignalConversionAtSerial[i + 22] = text_B.BytePack4[i];
    text_B.TmpSignalConversionAtSerial[i + 30] = text_B.BytePack5[i];
    text_B.TmpSignalConversionAtSerial[i + 38] = text_B.BytePack6[i];
    text_B.TmpSignalConversionAtSerial[i + 46] = text_B.BytePack8[i];
  }

  text_B.TmpSignalConversionAtSerial[54] = text_B.BytePack9[0];
  text_B.TmpSignalConversionAtSerial[56] = text_B.BytePack10[0];
  text_B.TmpSignalConversionAtSerial[58] = text_B.BytePack11[0];
  text_B.TmpSignalConversionAtSerial[60] = text_B.BytePack12[0];
  text_B.TmpSignalConversionAtSerial[62] = text_B.BytePack13[0];
  text_B.TmpSignalConversionAtSerial[55] = text_B.BytePack9[1];
  text_B.TmpSignalConversionAtSerial[57] = text_B.BytePack10[1];
  text_B.TmpSignalConversionAtSerial[59] = text_B.BytePack11[1];
  text_B.TmpSignalConversionAtSerial[61] = text_B.BytePack12[1];
  text_B.TmpSignalConversionAtSerial[63] = text_B.BytePack13[1];

  /* End of SignalConversion generated from: '<S2>/Serial Transmit' */

  /* MATLABSystem: '<S2>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&text_B.TxDataLocChar[0], (void *)
           &text_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)64 *
            sizeof(uint8_T)));
    status = MW_SCI_Transmit(text_DW.obj_h.MW_SCIHANDLE, &text_B.TxDataLocChar[0],
      64U);
  }

  /* End of MATLABSystem: '<S2>/Serial Transmit' */

  /* S-Function (any2byte): '<S2>/Byte Pack14' */

  /* Pack: <S2>/Byte Pack14 */
  (void) memcpy(&text_B.BytePack14[0], &text_B.TmpLatchAtATR_SIGNALOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack15' */

  /* Pack: <S2>/Byte Pack15 */
  (void) memcpy(&text_B.BytePack15[0], &text_B.TmpLatchAtVENT_SIGNALOutport1,
                8);
}

/* Termination for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM_Term(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  if (!text_DW.obj_h.matlabCodegenIsDeleted) {
    text_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((text_DW.obj_h.isInitialized == 1) && text_DW.obj_h.isSetupComplete) {
      MW_SCI_Close(text_DW.obj_h.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
