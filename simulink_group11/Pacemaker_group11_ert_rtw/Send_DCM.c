/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Send_DCM.c
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

#include "Pacemaker_group11_types.h"
#include "Send_DCM_private.h"
#include "Pacemaker_group11.h"
#include "Send_DCM.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Pacemaker_grou_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj);
static void Pacemaker_grou_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj)
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
  Pacemaker_group11_DW.obj_h.isInitialized = 0;
  Pacemaker_group11_DW.obj_h.matlabCodegenIsDeleted = false;
  Pacemaker_grou_SystemCore_setup(&Pacemaker_group11_DW.obj_h);
}

/* Output and update for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S2>/MODE' */
  Pacemaker_group11_B.MODE = Pacemaker_group11_B.MODE_n;

  /* SignalConversion generated from: '<S2>/LOWER_RATE_LIMIT' */
  Pacemaker_group11_B.LOWER_RATE_LIMIT = Pacemaker_group11_B.LOWER_RATE_LIMIT_e;

  /* SignalConversion generated from: '<S2>/UPPER_RATE_LIMIT' */
  Pacemaker_group11_B.UPPER_RATE_LIMIT = Pacemaker_group11_B.UPPER_RATE_LIMIT_g;

  /* SignalConversion generated from: '<S2>/ATR_AMP_REG' */
  Pacemaker_group11_B.ATR_AMP_REG = Pacemaker_group11_B.ATR_AMP_REG_f;

  /* SignalConversion generated from: '<S2>/VENT_AMP_REG' */
  Pacemaker_group11_B.VENT_AMP_REG = Pacemaker_group11_B.VENT_AMP_REG_o;

  /* SignalConversion generated from: '<S2>/ATR_PW' */
  Pacemaker_group11_B.ATR_PW = Pacemaker_group11_B.ATR_PW_n;

  /* SignalConversion generated from: '<S2>/VENT_PW' */
  Pacemaker_group11_B.VENT_PW = Pacemaker_group11_B.VENT_PW_n;

  /* SignalConversion generated from: '<S2>/ATR_SENSITIVITY' */
  Pacemaker_group11_B.ATR_SENSITIVITY = Pacemaker_group11_B.ATR_SENSITIVITY_l;

  /* SignalConversion generated from: '<S2>/VENT_SENSITIVITY' */
  Pacemaker_group11_B.VENT_SENSITIVITY = Pacemaker_group11_B.VENT_SENSITIVITY_b;

  /* SignalConversion generated from: '<S2>/VENT_REF_PERIOD' */
  Pacemaker_group11_B.VENT_REF_PERIOD = Pacemaker_group11_B.VENT_REF_PERIOD_j;

  /* SignalConversion generated from: '<S2>/ATR_REF_PERIOD' */
  Pacemaker_group11_B.ATR_REF_PERIOD = Pacemaker_group11_B.ATR_REF_PERIOD_h;

  /* SignalConversion generated from: '<S2>/PVARP' */
  Pacemaker_group11_B.PVARP = Pacemaker_group11_B.PVARP_c;

  /* SignalConversion generated from: '<S2>/HYSTERESIS_RATE_LIMIT' */
  Pacemaker_group11_B.HYSTERESIS_RATE_LIMIT =
    Pacemaker_group11_B.HYSTERESIS_RATE_LIMIT_c;

  /* SignalConversion generated from: '<S2>/RATE_SMOOTHING' */
  Pacemaker_group11_B.RATE_SMOOTHING = Pacemaker_group11_B.RATE_SMOOTHING_d;

  /* SignalConversion generated from: '<S2>/ATR_SIGNAL' */
  Pacemaker_group11_B.TmpLatchAtATR_SIGNALOutport1 =
    Pacemaker_group11_B.ATR_SIGNAL;

  /* SignalConversion generated from: '<S2>/VENT_SIGNAL' */
  Pacemaker_group11_B.TmpLatchAtVENT_SIGNALOutport1 =
    Pacemaker_group11_B.VENT_SIGNAL;

  /* S-Function (any2byte): '<S2>/Byte Pack' */

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&Pacemaker_group11_B.BytePack[0], &Pacemaker_group11_B.MODE,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  (void) memcpy(&Pacemaker_group11_B.BytePack1[0],
                &Pacemaker_group11_B.LOWER_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack7' */

  /* Pack: <S2>/Byte Pack7 */
  (void) memcpy(&Pacemaker_group11_B.BytePack7[0],
                &Pacemaker_group11_B.UPPER_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack2' */

  /* Pack: <S2>/Byte Pack2 */
  (void) memcpy(&Pacemaker_group11_B.BytePack2[0],
                &Pacemaker_group11_B.ATR_AMP_REG,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack3' */

  /* Pack: <S2>/Byte Pack3 */
  (void) memcpy(&Pacemaker_group11_B.BytePack3[0],
                &Pacemaker_group11_B.VENT_AMP_REG,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack4' */

  /* Pack: <S2>/Byte Pack4 */
  (void) memcpy(&Pacemaker_group11_B.BytePack4[0], &Pacemaker_group11_B.ATR_PW,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack5' */

  /* Pack: <S2>/Byte Pack5 */
  (void) memcpy(&Pacemaker_group11_B.BytePack5[0], &Pacemaker_group11_B.VENT_PW,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack6' */

  /* Pack: <S2>/Byte Pack6 */
  (void) memcpy(&Pacemaker_group11_B.BytePack6[0],
                &Pacemaker_group11_B.ATR_SENSITIVITY,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack8' */

  /* Pack: <S2>/Byte Pack8 */
  (void) memcpy(&Pacemaker_group11_B.BytePack8[0],
                &Pacemaker_group11_B.VENT_SENSITIVITY,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack9' */

  /* Pack: <S2>/Byte Pack9 */
  (void) memcpy(&Pacemaker_group11_B.BytePack9[0],
                &Pacemaker_group11_B.VENT_REF_PERIOD,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack10' */

  /* Pack: <S2>/Byte Pack10 */
  (void) memcpy(&Pacemaker_group11_B.BytePack10[0],
                &Pacemaker_group11_B.ATR_REF_PERIOD,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack11' */

  /* Pack: <S2>/Byte Pack11 */
  (void) memcpy(&Pacemaker_group11_B.BytePack11[0], &Pacemaker_group11_B.PVARP,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack12' */

  /* Pack: <S2>/Byte Pack12 */
  (void) memcpy(&Pacemaker_group11_B.BytePack12[0],
                &Pacemaker_group11_B.HYSTERESIS_RATE_LIMIT,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack13' */

  /* Pack: <S2>/Byte Pack13 */
  (void) memcpy(&Pacemaker_group11_B.BytePack13[0],
                &Pacemaker_group11_B.RATE_SMOOTHING,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack14' */

  /* Pack: <S2>/Byte Pack14 */
  (void) memcpy(&Pacemaker_group11_B.BytePack14[0],
                &Pacemaker_group11_B.TmpLatchAtATR_SIGNALOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack15' */

  /* Pack: <S2>/Byte Pack15 */
  (void) memcpy(&Pacemaker_group11_B.BytePack15[0],
                &Pacemaker_group11_B.TmpLatchAtVENT_SIGNALOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack16' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack16 */
  (void) memcpy(&Pacemaker_group11_B.BytePack16[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack17' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack17 */
  (void) memcpy(&Pacemaker_group11_B.BytePack17[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack18' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack18 */
  (void) memcpy(&Pacemaker_group11_B.BytePack18[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack19' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack19 */
  (void) memcpy(&Pacemaker_group11_B.BytePack19[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack20' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack20 */
  (void) memcpy(&Pacemaker_group11_B.BytePack20[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack21' incorporates:
   *  Constant: '<S2>/empty'
   */

  /* Pack: <S2>/Byte Pack21 */
  (void) memcpy(&Pacemaker_group11_B.BytePack21[0],
                &Pacemaker_group11_P.empty_Value,
                8);

  /* Switch: '<S2>/Switch' incorporates:
   *  SignalConversion generated from: '<S2>/Type'
   */
  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[0] = Pacemaker_group11_B.BytePack[0];
    Pacemaker_group11_B.Switch[2] = Pacemaker_group11_B.BytePack1[0];
    Pacemaker_group11_B.Switch[4] = Pacemaker_group11_B.BytePack7[0];
    Pacemaker_group11_B.Switch[6] = Pacemaker_group11_B.BytePack2[0];
    Pacemaker_group11_B.Switch[1] = Pacemaker_group11_B.BytePack[1];
    Pacemaker_group11_B.Switch[3] = Pacemaker_group11_B.BytePack1[1];
    Pacemaker_group11_B.Switch[5] = Pacemaker_group11_B.BytePack7[1];
    Pacemaker_group11_B.Switch[7] = Pacemaker_group11_B.BytePack2[1];
  } else {
    Pacemaker_group11_B.Switch[0] = Pacemaker_group11_B.BytePack14[0];
    Pacemaker_group11_B.Switch[2] = Pacemaker_group11_B.BytePack14[2];
    Pacemaker_group11_B.Switch[4] = Pacemaker_group11_B.BytePack14[4];
    Pacemaker_group11_B.Switch[6] = Pacemaker_group11_B.BytePack14[6];
    Pacemaker_group11_B.Switch[1] = Pacemaker_group11_B.BytePack14[1];
    Pacemaker_group11_B.Switch[3] = Pacemaker_group11_B.BytePack14[3];
    Pacemaker_group11_B.Switch[5] = Pacemaker_group11_B.BytePack14[5];
    Pacemaker_group11_B.Switch[7] = Pacemaker_group11_B.BytePack14[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 8] = Pacemaker_group11_B.BytePack2[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 8] = Pacemaker_group11_B.BytePack15[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[14] = Pacemaker_group11_B.BytePack3[0];
    Pacemaker_group11_B.Switch[15] = Pacemaker_group11_B.BytePack3[1];
  } else {
    Pacemaker_group11_B.Switch[14] = Pacemaker_group11_B.BytePack15[6];
    Pacemaker_group11_B.Switch[15] = Pacemaker_group11_B.BytePack15[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 16] = Pacemaker_group11_B.BytePack3[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 16] = Pacemaker_group11_B.BytePack16[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[22] = Pacemaker_group11_B.BytePack4[0];
    Pacemaker_group11_B.Switch[23] = Pacemaker_group11_B.BytePack4[1];
  } else {
    Pacemaker_group11_B.Switch[22] = Pacemaker_group11_B.BytePack16[6];
    Pacemaker_group11_B.Switch[23] = Pacemaker_group11_B.BytePack16[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 24] = Pacemaker_group11_B.BytePack4[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 24] = Pacemaker_group11_B.BytePack17[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[30] = Pacemaker_group11_B.BytePack5[0];
    Pacemaker_group11_B.Switch[31] = Pacemaker_group11_B.BytePack5[1];
  } else {
    Pacemaker_group11_B.Switch[30] = Pacemaker_group11_B.BytePack17[6];
    Pacemaker_group11_B.Switch[31] = Pacemaker_group11_B.BytePack17[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 32] = Pacemaker_group11_B.BytePack5[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 32] = Pacemaker_group11_B.BytePack18[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[38] = Pacemaker_group11_B.BytePack6[0];
    Pacemaker_group11_B.Switch[39] = Pacemaker_group11_B.BytePack6[1];
  } else {
    Pacemaker_group11_B.Switch[38] = Pacemaker_group11_B.BytePack18[6];
    Pacemaker_group11_B.Switch[39] = Pacemaker_group11_B.BytePack18[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 40] = Pacemaker_group11_B.BytePack6[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 40] = Pacemaker_group11_B.BytePack19[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[46] = Pacemaker_group11_B.BytePack8[0];
    Pacemaker_group11_B.Switch[47] = Pacemaker_group11_B.BytePack8[1];
  } else {
    Pacemaker_group11_B.Switch[46] = Pacemaker_group11_B.BytePack19[6];
    Pacemaker_group11_B.Switch[47] = Pacemaker_group11_B.BytePack19[7];
  }

  for (i = 0; i < 6; i++) {
    if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
      Pacemaker_group11_B.Switch[i + 48] = Pacemaker_group11_B.BytePack8[i + 2];
    } else {
      Pacemaker_group11_B.Switch[i + 48] = Pacemaker_group11_B.BytePack20[i];
    }
  }

  if (Pacemaker_group11_B.Type > Pacemaker_group11_P.Switch_Threshold) {
    Pacemaker_group11_B.Switch[54] = Pacemaker_group11_B.BytePack9[0];
    Pacemaker_group11_B.Switch[56] = Pacemaker_group11_B.BytePack10[0];
    Pacemaker_group11_B.Switch[58] = Pacemaker_group11_B.BytePack11[0];
    Pacemaker_group11_B.Switch[60] = Pacemaker_group11_B.BytePack12[0];
    Pacemaker_group11_B.Switch[62] = Pacemaker_group11_B.BytePack13[0];
    Pacemaker_group11_B.Switch[55] = Pacemaker_group11_B.BytePack9[1];
    Pacemaker_group11_B.Switch[57] = Pacemaker_group11_B.BytePack10[1];
    Pacemaker_group11_B.Switch[59] = Pacemaker_group11_B.BytePack11[1];
    Pacemaker_group11_B.Switch[61] = Pacemaker_group11_B.BytePack12[1];
    Pacemaker_group11_B.Switch[63] = Pacemaker_group11_B.BytePack13[1];
  } else {
    Pacemaker_group11_B.Switch[54] = Pacemaker_group11_B.BytePack20[6];
    Pacemaker_group11_B.Switch[56] = Pacemaker_group11_B.BytePack21[0];
    Pacemaker_group11_B.Switch[58] = Pacemaker_group11_B.BytePack21[2];
    Pacemaker_group11_B.Switch[60] = Pacemaker_group11_B.BytePack21[4];
    Pacemaker_group11_B.Switch[62] = Pacemaker_group11_B.BytePack21[6];
    Pacemaker_group11_B.Switch[55] = Pacemaker_group11_B.BytePack20[7];
    Pacemaker_group11_B.Switch[57] = Pacemaker_group11_B.BytePack21[1];
    Pacemaker_group11_B.Switch[59] = Pacemaker_group11_B.BytePack21[3];
    Pacemaker_group11_B.Switch[61] = Pacemaker_group11_B.BytePack21[5];
    Pacemaker_group11_B.Switch[63] = Pacemaker_group11_B.BytePack21[7];
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Pacemaker_group11_B.TxDataLocChar[0], (void *)
           &Pacemaker_group11_B.Switch[0], (uint32_T)((size_t)64 * sizeof
            (uint8_T)));
    status = MW_SCI_Transmit(Pacemaker_group11_DW.obj_h.MW_SCIHANDLE,
      &Pacemaker_group11_B.TxDataLocChar[0], 64U);
  }

  /* End of MATLABSystem: '<S2>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM_Term(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  if (!Pacemaker_group11_DW.obj_h.matlabCodegenIsDeleted) {
    Pacemaker_group11_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Pacemaker_group11_DW.obj_h.isInitialized == 1) &&
        Pacemaker_group11_DW.obj_h.isSetupComplete) {
      MW_SCI_Close(Pacemaker_group11_DW.obj_h.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
