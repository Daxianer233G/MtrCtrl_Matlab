/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CurLpCtrl.c
 *
 * Code generated for Simulink model 'CurLpCtrl'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 11 03:20:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "CurLpCtrl.h"
#include <math.h>
#include "rtwtypes.h"
#include "multiword_types.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern uint32_T rt_sqrt_Uu32En32_Yu32E_Om5WnAx7(uint32_T u);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
static uint32_T look1_iu32lu32n32_pbinlcase(uint32_T u0, const uint32_T bp0[],
  const uint32_T table[], uint32_T prevIndex[], uint32_T maxIndex);
static int64_T MultiWord2sLong(const uint64_T u[]);
static void sMultiWordShr(const uint64_T u1[], int32_T n1, uint32_T n2, uint64_T
  y[], int32_T n);
static void ssuMultiWordMul(const uint64_T u1[], int32_T n1, const uint64_T u2[],
  int32_T n2, uint64_T y[], int32_T n);
static void uMultiWordMul(const uint64_T u1[], int32_T n1, const uint64_T u2[],
  int32_T n2, uint64_T y[], int32_T n);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

static uint32_T look1_iu32lu32n32_pbinlcase(uint32_T u0, const uint32_T bp0[],
  const uint32_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T found;
  uint32_T frac;
  uint32_T iLeft;
  uint32_T y;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    frac = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        frac = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + frac) + 1U) >> 1U;
      }
    }

    iLeft = bp0[bpIdx];
    frac = (uint32_T)(((uint64_T)(u0 - iLeft) << 32) / (bp0[bpIdx + 1U] - iLeft));
  } else {
    bpIdx = maxIndex;
    frac = 0U;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    found = table[bpIdx + 1U];
    iLeft = table[bpIdx];
    if (found >= iLeft) {
      y = (uint32_T)(((uint64_T)(found - iLeft) * frac) >> 32) + iLeft;
    } else {
      y = iLeft - (uint32_T)(((uint64_T)(iLeft - found) * frac) >> 32);
    }
  }

  return y;
}

static int64_T MultiWord2sLong(const uint64_T u[])
{
  return (int64_T)u[0];
}

static void sMultiWordShr(const uint64_T u1[], int32_T n1, uint32_T n2, uint64_T
  y[], int32_T n)
{
  uint64_T ys;
  int32_T i;
  int32_T i1;
  int32_T nb;
  nb = (int32_T)(n2 >> 6);
  i = 0;
  ys = (u1[n1 - 1] & 9223372036854775808ULL) != 0ULL ? MAX_uint64_T : 0ULL;
  if (nb < n1) {
    int32_T nc;
    uint32_T nr;
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 6);
    if (nr > 0U) {
      uint64_T u1i;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        uint64_T yi;
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (64U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (64U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

static void ssuMultiWordMul(const uint64_T u1[], int32_T n1, const uint64_T u2[],
  int32_T n2, uint64_T y[], int32_T n)
{
  uint64_T cb;
  uint64_T cb1;
  uint64_T yk;
  int32_T i;
  int32_T j;
  int32_T k;
  boolean_T isNegative1;
  isNegative1 = ((u1[n1 - 1] & 9223372036854775808ULL) != 0ULL);
  cb1 = 1ULL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0ULL;
  }

  for (i = 0; i < n1; i++) {
    uint64_T a0;
    uint64_T a1;
    uint64_T u1i;
    int32_T ni;
    cb = 0ULL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint64_T)(u1i < cb1);
    }

    a1 = u1i >> 32U;
    a0 = u1i & 4294967295ULL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      uint64_T b1;
      uint64_T w01;
      uint64_T w10;
      u1i = u2[j];
      b1 = u1i >> 32U;
      u1i &= 4294967295ULL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint64_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      u1i = w10 << 32U;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      u1i = w01 << 32U;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 32U;
      cb += w01 >> 32U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1) {
    cb = 1ULL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint64_T)(yk < cb);
    }
  }
}

static void uMultiWordMul(const uint64_T u1[], int32_T n1, const uint64_T u2[],
  int32_T n2, uint64_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0ULL;
  }

  for (i = 0; i < n1; i++) {
    uint64_T a0;
    uint64_T a1;
    uint64_T cb;
    uint64_T u1i;
    int32_T ni;
    cb = 0ULL;
    u1i = u1[i];
    a1 = u1i >> 32U;
    a0 = u1i & 4294967295ULL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      uint64_T b1;
      uint64_T w01;
      uint64_T w10;
      uint64_T yk;
      u1i = u2[j];
      b1 = u1i >> 32U;
      u1i &= 4294967295ULL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint64_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      u1i = w10 << 32U;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      u1i = w01 << 32U;
      yk += u1i;
      cb += (uint64_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 32U;
      cb += w01 >> 32U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

uint32_T rt_sqrt_Uu32En32_Yu32E_Om5WnAx7(uint32_T u)
{
  int32_T iBit;
  uint32_T y;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0U) {
    uint64_T tmp03_u;
    uint32_T shiftMask;
    y = 0U;
    shiftMask = 2147483648U;
    tmp03_u = (uint64_T)u << 32;
    for (iBit = 0; iBit < 32; iBit++) {
      uint32_T tmp01_y;
      tmp01_y = y | shiftMask;
      if ((uint64_T)tmp01_y * tmp01_y <= tmp03_u) {
        y = tmp01_y;
      }

      shiftMask >>= 1U;
    }
  } else {
    y = 0U;
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void CurLpCtrl_step(void)
{
  int128m_T tmp_1;
  int128m_T tmp_2;
  uint128m_T tmp_4;
  int64_T tmp;
  int64_T tmp_0;
  real_T rtb_Sum2_tmp;
  real_T rtb_Switch_f_idx_0_tmp;
  uint64_T tmp_3;
  uint64_T tmp_5;
  uint64_T tmp_6;
  int32_T DiscreteTimeIntegrator;
  int32_T rtb_Add2;
  int32_T rtb_Add_m;
  int32_T rtb_Saturation;
  int32_T rtb_Sum2_0;
  int32_T rtb_Switch_f_idx_0;
  int32_T rtb_Switch_f_idx_1;
  int32_T rtb_qcos;
  int32_T rtb_sqrt3_by_two;
  int32_T rtb_sum_alpha;
  uint32_T CurLpCtrl_ELAPS_T_idx_0;
  uint32_T qY;
  uint32_T rtb_Switch1_p;
  uint8_T rtb_Sector;
  boolean_T rtb_NOT;

  /* Outputs for Triggered SubSystem: '<Root>/CurLpCtrl' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  /* Inport: '<Root>/Trigger' */
  if (rtU.Trigger && (rtPrevZCX.CurLpCtrl_Trig_ZCE != POS_ZCSIG)) {
    if (rtDW.CurLpCtrl_RESET_ELAPS_T) {
      CurLpCtrl_ELAPS_T_idx_0 = 0U;
    } else {
      CurLpCtrl_ELAPS_T_idx_0 = rtM->Timing.clockTick0 - rtDW.CurLpCtrl_PREV_T[0];
    }

    rtDW.CurLpCtrl_PREV_T[0] = rtM->Timing.clockTick0;
    rtDW.CurLpCtrl_PREV_T[1] = rtM->Timing.clockTickH0;
    rtDW.CurLpCtrl_RESET_ELAPS_T = false;

    /* Sum: '<S3>/Subtract' incorporates:
     *  Inport: '<Root>/CurA'
     *  Inport: '<Root>/CurC'
     *  Product: '<S5>/qcos'
     */
    rtb_qcos = -rtU.CurA - rtU.CurC;

    /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     *  DataTypeConversion: '<S2>/Data Type Conversion1'
     *  Inport: '<Root>/CurA'
     *  Product: '<S2>/Product'
     *  Product: '<S5>/qcos'
     *  Sum: '<S2>/Add'
     */
    rtb_qcos = ((((rtU.CurA + rtb_qcos) + rtb_qcos) >> 16) * 18918) << 1;

    /* Math: '<S33>/Math Function' incorporates:
     *  UnitDelay: '<S1>/Unit Delay'
     */
    tmp_0 = ((int64_T)rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[0]) >> 30;
    if (tmp_0 < 0LL) {
      tmp_0 = 0LL;
    } else if (tmp_0 > 4294967295LL) {
      tmp_0 = 4294967295LL;
    }

    tmp = ((int64_T)rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[1]) >> 30;
    if (tmp < 0LL) {
      tmp = 0LL;
    } else if (tmp > 4294967295LL) {
      tmp = 4294967295LL;
    }

    /* Product: '<S33>/Product' incorporates:
     *  Inport: '<Root>/Udc'
     *  Switch: '<S17>/Switch1'
     */
    rtb_Switch1_p = (uint32_T)((rtU.Udc * 619925131LL) >> 30);

    /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S30>/Modulation index threshold'
     *  Gain: '<S30>/Gain'
     *  Gain: '<S30>/Gain1'
     *  Gain: '<S30>/Gain2'
     *  Math: '<S33>/Math Function'
     *  Product: '<S33>/Product1'
     *  Sqrt: '<S33>/Sqrt'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum4'
     *  Sum: '<S33>/Sum of Elements'
     *  Switch: '<S17>/Switch1'
     *  Switch: '<S36>/Switch'
     *  UnitDelay: '<S30>/Unit Delay'
     */
    if (rtDW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
      /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
      DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;
    } else {
      if (rtb_Switch1_p <= 429496730U) {
        /* Switch: '<S36>/Switch' incorporates:
         *  Constant: '<S36>/Constant2'
         */
        rtb_Switch1_p = 429496730U;
      }

      tmp_3 = (uint64_T)((int32_T)(((1239850262 - (int32_T)((uint32_T)
        (((uint64_T)rt_sqrt_Uu32En32_Yu32E_Om5WnAx7((uint32_T)tmp_0 + (uint32_T)
        tmp) << 31) / rtb_Switch1_p) >> 1)) * 25LL) >> 4) + (int32_T)((5LL *
        rtDW.UnitDelay_DSTATE_c) >> 2));
      tmp_5 = 368934881474191ULL;
      tmp_6 = CurLpCtrl_ELAPS_T_idx_0;
      uMultiWordMul(&tmp_5, 1, &tmp_6, 1, &tmp_4.chunks[0U], 2);
      ssuMultiWordMul(&tmp_3, 1, &tmp_4.chunks[0U], 2, &tmp_2.chunks[0U], 2);
      sMultiWordShr(&tmp_2.chunks[0U], 2, 63U, &tmp_1.chunks[0U], 2);

      /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S30>/Modulation index threshold'
       *  Gain: '<S30>/Gain'
       *  Gain: '<S30>/Gain1'
       *  Gain: '<S30>/Gain2'
       *  Math: '<S33>/Math Function'
       *  Product: '<S33>/Product1'
       *  Sqrt: '<S33>/Sqrt'
       *  Sum: '<S30>/Sum'
       *  Sum: '<S30>/Sum4'
       *  Sum: '<S33>/Sum of Elements'
       *  Switch: '<S36>/Switch'
       *  UnitDelay: '<S30>/Unit Delay'
       */
      DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE + (int32_T)
        MultiWord2sLong(&tmp_1.chunks[0U]);
    }

    /* End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */

    /* Saturate: '<S30>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
     */
    if (DiscreteTimeIntegrator > 268435456) {
      rtb_Saturation = 268435456;
    } else if (DiscreteTimeIntegrator < 0) {
      rtb_Saturation = 0;
    } else {
      rtb_Saturation = DiscreteTimeIntegrator;
    }

    /* End of Saturate: '<S30>/Saturation' */

    /* Switch: '<S1>/Switch' incorporates:
     *  DataTypeConversion: '<S32>/DTC_input_1'
     *  DataTypeConversion: '<S32>/DTC_input_2'
     *  DataTypeConversion: '<S32>/DTC_output_1'
     *  DataTypeConversion: '<S32>/DTC_output_2'
     *  DataTypeConversion: '<S37>/DTC_output_1'
     *  Fcn: '<S35>/r->x'
     *  Fcn: '<S35>/theta->y'
     *  Gain: '<S1>/Gain1'
     *  Inport: '<Root>/IsSet'
     *  Inport: '<Root>/wm'
     *  Product: '<S10>/Product'
     */
    if ((uint32_T)((640889651LL * rtU.wm) >> 27) > 341782638U) {
      /* DataTypeConversion: '<S31>/DTC_input_2' incorporates:
       *  Inport: '<Root>/IsSet'
       */
      rtb_Sum2_tmp = (real_T)rtU.IsSet * 4.6566128730773926E-10;

      /* DataTypeConversion: '<S32>/DTC_input_1' incorporates:
       *  DataTypeConversion: '<S31>/DTC_input_1'
       *  DataTypeConversion: '<S31>/DTC_output_1'
       *  DataTypeConversion: '<S37>/DTC_output_1'
       *  Fcn: '<S34>/x->r'
       *  Product: '<S10>/Product'
       */
      rtb_Switch_f_idx_0_tmp = (real_T)(uint32_T)(rt_hypotd_snf(0.0,
        rtb_Sum2_tmp) * 4.294967296E+9) * 2.3283064365386963E-10;

      /* DataTypeConversion: '<S32>/DTC_input_2' incorporates:
       *  Constant: '<S30>/Constant'
       *  DataTypeConversion: '<S31>/DTC_input_1'
       *  DataTypeConversion: '<S31>/DTC_input_2'
       *  DataTypeConversion: '<S31>/DTC_output_2'
       *  DataTypeConversion: '<S37>/DTC_output_1'
       *  Fcn: '<S34>/x->theta'
       *  Product: '<S10>/Product'
       *  Product: '<S30>/Product'
       *  Saturate: '<S30>/Saturation'
       *  Sum: '<S30>/Sum1'
       *  Sum: '<S30>/Sum2'
       */
      rtb_Sum2_tmp = (real_T)(843314856 - (int32_T)(((int64_T)(843314856 -
        (int32_T)floor(rt_atan2d_snf(rtb_Sum2_tmp, 0.0) * 2.68435456E+8)) *
        rtb_Saturation) >> 28)) * 3.7252902984619141E-9;
      rtb_Switch_f_idx_0 = (int32_T)floor(rtb_Switch_f_idx_0_tmp * cos
        (rtb_Sum2_tmp) * 2.147483648E+9);
      rtb_Switch_f_idx_1 = (int32_T)floor(rtb_Switch_f_idx_0_tmp * sin
        (rtb_Sum2_tmp) * 2.147483648E+9);
    } else {
      rtb_Switch_f_idx_0 = 0;
      rtb_Switch_f_idx_1 = rtU.IsSet;
    }

    /* End of Switch: '<S1>/Switch' */

    /* Switch: '<S1>/Switch1' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read'
     *  Inport: '<Root>/Posn_rad'
     *  Inport: '<Root>/VirPosn'
     *  Logic: '<S1>/OR'
     */
    if (rtDW.VoltMode_null) {
      rtb_Sum2_0 = rtU.VirPosn;
    } else {
      rtb_Sum2_0 = rtU.Posn_rad;
    }

    /* Chart: '<S11>/Chart' incorporates:
     *  Switch: '<S1>/Switch1'
     */
    rtb_Switch_f_idx_0_tmp = ((real_T)rtb_Sum2_0 * 1.4901161193847656E-8 -
      (real_T)((rtb_Sum2_0 == MIN_int32_T) && (rtDW.TwoPi == -1) ? MAX_int32_T :
               rtb_Sum2_0 / rtDW.TwoPi) * ((real_T)rtDW.TwoPi *
      1.4901161193847656E-8)) * 5.36870912E+8;
    if (rtb_Switch_f_idx_0_tmp < 4.294967296E+9) {
      if (rtb_Switch_f_idx_0_tmp >= 0.0) {
        CurLpCtrl_ELAPS_T_idx_0 = (uint32_T)rtb_Switch_f_idx_0_tmp;
      } else {
        CurLpCtrl_ELAPS_T_idx_0 = 0U;
      }
    } else {
      CurLpCtrl_ELAPS_T_idx_0 = MAX_uint32_T;
    }

    if (CurLpCtrl_ELAPS_T_idx_0 <= rtDW.PiOverTow) {
      if (CurLpCtrl_ELAPS_T_idx_0 > 1073741823U) {
        rtDW.SinAngle = MAX_uint32_T;
      } else {
        rtDW.SinAngle = CurLpCtrl_ELAPS_T_idx_0 << 2;
      }

      rtDW.SinSign = rtDW.Pos;
      rtb_Switch1_p = rtDW.PiOverTow - /*MW:OvSatOk*/ CurLpCtrl_ELAPS_T_idx_0;
      if (rtb_Switch1_p > rtDW.PiOverTow) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.CosAngle = MAX_uint32_T;
      } else {
        rtDW.CosAngle = rtb_Switch1_p << 2;
      }

      rtDW.CosSign = rtDW.Pos;
    }

    if ((CurLpCtrl_ELAPS_T_idx_0 > rtDW.PiOverTow) && (CurLpCtrl_ELAPS_T_idx_0 <=
         rtDW.Pi)) {
      rtb_Switch1_p = rtDW.Pi - /*MW:OvSatOk*/ CurLpCtrl_ELAPS_T_idx_0;
      if (rtb_Switch1_p > rtDW.Pi) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.SinAngle = MAX_uint32_T;
      } else {
        rtDW.SinAngle = rtb_Switch1_p << 2;
      }

      rtDW.SinSign = rtDW.Pos;
      rtb_Switch1_p = CurLpCtrl_ELAPS_T_idx_0 - /*MW:OvSatOk*/ rtDW.PiOverTow;
      if (rtb_Switch1_p > CurLpCtrl_ELAPS_T_idx_0) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.CosAngle = MAX_uint32_T;
      } else {
        rtDW.CosAngle = rtb_Switch1_p << 2;
      }

      rtDW.CosSign = rtDW.Neg;
    }

    if ((CurLpCtrl_ELAPS_T_idx_0 > rtDW.Pi) && (CurLpCtrl_ELAPS_T_idx_0 <=
         rtDW.PiTimeThreeOverTwo)) {
      rtb_Switch1_p = CurLpCtrl_ELAPS_T_idx_0 - /*MW:OvSatOk*/ rtDW.Pi;
      if (rtb_Switch1_p > CurLpCtrl_ELAPS_T_idx_0) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.SinAngle = MAX_uint32_T;
      } else {
        rtDW.SinAngle = rtb_Switch1_p << 2;
      }

      rtDW.SinSign = rtDW.Neg;
      rtb_Switch1_p = rtDW.PiTimeThreeOverTwo - /*MW:OvSatOk*/
        CurLpCtrl_ELAPS_T_idx_0;
      if (rtb_Switch1_p > rtDW.PiTimeThreeOverTwo) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.CosAngle = MAX_uint32_T;
      } else {
        rtDW.CosAngle = rtb_Switch1_p << 2;
      }

      rtDW.CosSign = rtDW.Neg;
    }

    if (CurLpCtrl_ELAPS_T_idx_0 > rtDW.PiTimeThreeOverTwo) {
      rtb_Switch1_p = rtDW.Pi + /*MW:OvSatOk*/ rtDW.Pi;
      if (rtb_Switch1_p < rtDW.Pi) {
        rtb_Switch1_p = MAX_uint32_T;
      }

      qY = rtb_Switch1_p - /*MW:OvSatOk*/ CurLpCtrl_ELAPS_T_idx_0;
      if (qY > rtb_Switch1_p) {
        qY = 0U;
      }

      if (qY > 1073741823U) {
        rtDW.SinAngle = MAX_uint32_T;
      } else {
        rtDW.SinAngle = qY << 2;
      }

      rtDW.SinSign = rtDW.Neg;
      rtb_Switch1_p = CurLpCtrl_ELAPS_T_idx_0 - /*MW:OvSatOk*/
        rtDW.PiTimeThreeOverTwo;
      if (rtb_Switch1_p > CurLpCtrl_ELAPS_T_idx_0) {
        rtb_Switch1_p = 0U;
      }

      if (rtb_Switch1_p > 1073741823U) {
        rtDW.CosAngle = MAX_uint32_T;
      } else {
        rtDW.CosAngle = rtb_Switch1_p << 2;
      }

      rtDW.CosSign = rtDW.Pos;
    }

    /* End of Chart: '<S11>/Chart' */

    /* Lookup_n-D: '<S11>/1-D Lookup Table1' incorporates:
     *  Switch: '<S17>/Switch'
     */
    CurLpCtrl_ELAPS_T_idx_0 = look1_iu32lu32n32_pbinlcase(rtDW.CosAngle,
      rtConstP.pooled10, rtConstP.pooled9, &rtDW.m_bpIndex, 1023U);

    /* Product: '<S11>/Product1' incorporates:
     *  Gain: '<S18>/sqrt3_by_two'
     *  Switch: '<S17>/Switch'
     */
    rtb_sqrt3_by_two = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 *
      rtDW.CosSign) >> 1);

    /* Lookup_n-D: '<S11>/1-D Lookup Table' incorporates:
     *  Switch: '<S17>/Switch'
     */
    CurLpCtrl_ELAPS_T_idx_0 = look1_iu32lu32n32_pbinlcase(rtDW.SinAngle,
      rtConstP.pooled10, rtConstP.pooled9, &rtDW.m_bpIndex_a, 1023U);

    /* Product: '<S11>/Product' incorporates:
     *  Sum: '<S5>/sum_alpha'
     *  Switch: '<S17>/Switch'
     */
    rtb_sum_alpha = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 * rtDW.SinSign) >>
      1);

    /* Sum: '<S6>/Add' incorporates:
     *  Gain: '<S18>/sqrt3_by_two'
     *  Inport: '<Root>/CurA'
     *  Product: '<S5>/qcos'
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product1'
     *  Sum: '<S5>/sum_alpha'
     */
    rtb_Add_m = (int32_T)(((int64_T)rtU.CurA * rtb_sqrt3_by_two) >> 30) +
      (int32_T)(((int64_T)rtb_qcos * rtb_sum_alpha) >> 30);

    /* Sum: '<S14>/Add2' incorporates:
     *  Sum: '<S6>/Add'
     */
    rtb_Add2 = rtb_Switch_f_idx_0 - rtb_Add_m;

    /* Gain: '<S14>/Gain' incorporates:
     *  Gain: '<S15>/Gain'
     *  Inport: '<Root>/Udc'
     */
    CurLpCtrl_ELAPS_T_idx_0 = (uint32_T)((2863311531ULL * rtU.Udc) >> 32);

    /* Sum: '<S14>/Add' incorporates:
     *  Constant: '<S14>/Kp'
     *  Product: '<S14>/Product1'
     *  Product: '<S5>/dsin'
     *  Sum: '<S14>/Add2'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    rtb_Switch_f_idx_0 = (int32_T)((2677524669LL * rtb_Add2) >> 27) +
      rtDW.UnitDelay_DSTATE_d;

    /* Switch: '<S14>/Switch' incorporates:
     *  Gain: '<S14>/Gain'
     *  Product: '<S5>/dsin'
     *  RelationalOperator: '<S14>/Relational Operator'
     */
    if (((int64_T)rtb_Switch_f_idx_0 << 1) <= CurLpCtrl_ELAPS_T_idx_0) {
      rtb_Sum2_0 = rtb_Switch_f_idx_0;
    } else {
      rtb_Sum2_0 = (int32_T)(CurLpCtrl_ELAPS_T_idx_0 >> 1);
    }

    /* End of Switch: '<S14>/Switch' */

    /* Logic: '<S4>/NOT' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read'
     *  Logic: '<S4>/OR'
     */
    rtb_NOT = !rtDW.VoltMode_null;

    /* Sum: '<S6>/Add1' incorporates:
     *  Gain: '<S18>/sqrt3_by_two'
     *  Inport: '<Root>/CurA'
     *  Product: '<S5>/qcos'
     *  Product: '<S6>/Product2'
     *  Product: '<S6>/Product3'
     *  Sum: '<S5>/sum_alpha'
     */
    rtb_qcos = (int32_T)(((int64_T)rtb_qcos * rtb_sqrt3_by_two) >> 30) -
      (int32_T)(((int64_T)rtU.CurA * rtb_sum_alpha) >> 30);

    /* Outputs for Enabled SubSystem: '<S4>/Subsystem' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* Switch: '<S4>/Switch' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Sum: '<S14>/Add1'
     *  Switch: '<S14>/Switch'
     *  Switch: '<S14>/Switch1'
     */
    if (rtb_NOT) {
      /* Product: '<S14>/Product' incorporates:
       *  Sum: '<S14>/Add2'
       *  Switch: '<S14>/Switch1'
       */
      rtb_Add2 = (int32_T)((rtb_Add2 * 82355LL) >> 19);

      /* Switch: '<S14>/Switch1' incorporates:
       *  Gain: '<S14>/Gain'
       *  RelationalOperator: '<S14>/Relational Operator1'
       */
      if (((int64_T)rtb_Add2 << 1) > CurLpCtrl_ELAPS_T_idx_0) {
        rtb_Add2 = (int32_T)(CurLpCtrl_ELAPS_T_idx_0 >> 1);
      }

      rtb_Add2 = (rtb_Add2 + rtb_Sum2_0) << 1;

      /* Gain: '<S13>/Gain' incorporates:
       *  Gain: '<S18>/one_by_two'
       *  Inport: '<Root>/wm'
       *  Product: '<S5>/dsin'
       *  Sum: '<S14>/Add1'
       *  Switch: '<S14>/Switch'
       *  Switch: '<S14>/Switch1'
       */
      rtb_Switch_f_idx_0 = rtU.wm << 2;

      /* Product: '<S13>/Product' incorporates:
       *  Constant: '<S13>/Flux'
       *  Gain: '<S13>/Ld'
       *  Product: '<S5>/dsin'
       *  Sum: '<S13>/Add'
       *  Sum: '<S6>/Add'
       */
      rtDW.Product = (int32_T)(((int64_T)((int32_T)((428403947LL * rtb_Add_m) >>
        32) + 412316860) * rtb_Switch_f_idx_0) >> 31);

      /* Product: '<S13>/Product1' incorporates:
       *  Gain: '<S13>/Lq'
       *  Product: '<S5>/dsin'
       *  Sum: '<S6>/Add1'
       */
      rtDW.Product1 = (int32_T)(((int64_T)(int32_T)((428403947LL * rtb_qcos) >>
        31) * rtb_Switch_f_idx_0) >> 31);
    } else {
      rtb_Add2 = 0;
    }

    /* End of Switch: '<S4>/Switch' */
    /* End of Outputs for SubSystem: '<S4>/Subsystem' */

    /* Sum: '<S4>/Add' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Product: '<S13>/Product1'
     */
    rtb_Add_m = (rtb_Add2 >> 1) - rtDW.Product1;

    /* Sum: '<S15>/Add2' incorporates:
     *  Sum: '<S6>/Add1'
     */
    rtb_Add2 = rtb_Switch_f_idx_1 - rtb_qcos;

    /* Sum: '<S15>/Add' incorporates:
     *  Product: '<S15>/Product1'
     *  Sum: '<S15>/Add2'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    rtb_qcos = (int32_T)((82355LL * rtb_Add2) >> 19) + rtDW.UnitDelay_DSTATE_o;

    /* Abs: '<S15>/Abs1' incorporates:
     *  Sum: '<S15>/Add'
     */
    if (rtb_qcos < 0) {
      rtb_Switch_f_idx_1 = -rtb_qcos;
    } else {
      rtb_Switch_f_idx_1 = rtb_qcos;
    }

    /* Switch: '<S15>/Switch' incorporates:
     *  Abs: '<S15>/Abs1'
     *  Product: '<S15>/Product3'
     *  RelationalOperator: '<S15>/Relational Operator'
     *  Signum: '<S15>/Sign1'
     */
    if (((int64_T)rtb_Switch_f_idx_1 << 1) > CurLpCtrl_ELAPS_T_idx_0) {
      /* Signum: '<S15>/Sign1' incorporates:
       *  Sum: '<S15>/Add'
       */
      if (rtb_qcos < 0) {
        rtb_Switch_f_idx_1 = -1;
      } else {
        rtb_Switch_f_idx_1 = (rtb_qcos > 0);
      }

      rtb_qcos = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 *
                            rtb_Switch_f_idx_1) >> 1);
    }

    /* End of Switch: '<S15>/Switch' */

    /* Switch: '<S4>/Switch1' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Product: '<S16>/Product'
     *  Sum: '<S15>/Add1'
     *  Switch: '<S15>/Switch'
     *  Switch: '<S15>/Switch1'
     */
    if (rtb_NOT) {
      /* Product: '<S15>/Product' incorporates:
       *  Constant: '<S15>/Kp'
       *  Sum: '<S15>/Add2'
       */
      rtb_Add2 = (int32_T)((rtb_Add2 * 2677524669LL) >> 27);

      /* Abs: '<S15>/Abs' incorporates:
       *  Product: '<S15>/Product'
       */
      if (rtb_Add2 < 0) {
        rtb_Switch_f_idx_1 = -rtb_Add2;
      } else {
        rtb_Switch_f_idx_1 = rtb_Add2;
      }

      /* Switch: '<S15>/Switch1' incorporates:
       *  Abs: '<S15>/Abs'
       *  Product: '<S15>/Product2'
       *  RelationalOperator: '<S15>/Relational Operator1'
       *  Signum: '<S15>/Sign'
       */
      if (((int64_T)rtb_Switch_f_idx_1 << 1) > CurLpCtrl_ELAPS_T_idx_0) {
        /* Signum: '<S15>/Sign' incorporates:
         *  Product: '<S15>/Product'
         */
        if (rtb_Add2 < 0) {
          rtb_Switch_f_idx_1 = -1;
        } else {
          rtb_Switch_f_idx_1 = (rtb_Add2 > 0);
        }

        rtb_Add2 = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 *
                              rtb_Switch_f_idx_1) >> 1);
      }

      /* End of Switch: '<S15>/Switch1' */
      rtb_Add2 += rtb_qcos;
    } else {
      rtb_Add2 = 357913900;
    }

    /* End of Switch: '<S4>/Switch1' */

    /* Sum: '<S4>/Add1' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Product: '<S13>/Product'
     */
    rtb_Add2 += rtDW.Product;

    /* Product: '<S12>/Divide' incorporates:
     *  Gain: '<S12>/Gain'
     *  Inport: '<Root>/Udc'
     *  Product: '<S12>/Product'
     *  Product: '<S12>/Product1'
     *  Sqrt: '<S12>/Sqrt'
     *  Sum: '<S12>/Add'
     *  Sum: '<S4>/Add'
     *  Sum: '<S4>/Add1'
     */
    CurLpCtrl_ELAPS_T_idx_0 = (uint32_T)(((uint64_T)(uint32_T)((3908420239ULL *
      rtU.Udc) >> 32) << 21) / rt_sqrt_Uu32En32_Yu32E_Om5WnAx7(((uint32_T)
      (((int64_T)rtb_Add_m * rtb_Add_m) >> 27) >> 3) + ((uint32_T)(((int64_T)
      rtb_Add2 * rtb_Add2) >> 29) >> 1)));

    /* Switch: '<S12>/Switch' incorporates:
     *  Product: '<S12>/Divide'
     *  Product: '<S12>/Product2'
     *  Product: '<S12>/Product3'
     *  RelationalOperator: '<S39>/Compare'
     *  Sum: '<S4>/Add'
     *  Sum: '<S4>/Add1'
     */
    if (CurLpCtrl_ELAPS_T_idx_0 >= 2097152U) {
      rtb_Switch_f_idx_0 = rtb_Add_m;
      rtb_Switch_f_idx_1 = rtb_Add2;
    } else {
      rtb_Switch_f_idx_0 = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 *
        rtb_Add_m) >> 21);
      rtb_Switch_f_idx_1 = (int32_T)(((int64_T)CurLpCtrl_ELAPS_T_idx_0 *
        rtb_Add2) >> 21);
    }

    /* End of Switch: '<S12>/Switch' */

    /* Sum: '<S5>/sum_beta' incorporates:
     *  Gain: '<S18>/sqrt3_by_two'
     *  Product: '<S5>/dsin'
     *  Product: '<S5>/qcos'
     *  Sum: '<S5>/sum_alpha'
     */
    rtDW.sum_beta = (int32_T)(((int64_T)rtb_Switch_f_idx_1 * rtb_sqrt3_by_two) >>
      30) + (int32_T)(((int64_T)rtb_Switch_f_idx_0 * rtb_sum_alpha) >> 30);

    /* Gain: '<S18>/one_by_two' incorporates:
     *  Sum: '<S5>/sum_beta'
     */
    rtb_Add2 = rtDW.sum_beta >> 1;

    /* Gain: '<S18>/sqrt3_by_two' incorporates:
     *  Product: '<S5>/dcos'
     *  Product: '<S5>/qsin'
     *  Sum: '<S5>/sum_alpha'
     */
    rtb_sqrt3_by_two = (int32_T)((((int32_T)(((int64_T)rtb_Switch_f_idx_0 *
      rtb_sqrt3_by_two) >> 30) - (int32_T)(((int64_T)rtb_Switch_f_idx_1 *
      rtb_sum_alpha) >> 30)) * 1859775393LL) >> 31);

    /* Sum: '<S18>/Add' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Gain: '<S18>/sqrt3_by_two'
     */
    rtb_sum_alpha = rtb_sqrt3_by_two - rtb_Add2;

    /* Sum: '<S18>/Add1' incorporates:
     *  Gain: '<S18>/one_by_two'
     *  Gain: '<S18>/sqrt3_by_two'
     */
    rtb_sqrt3_by_two = -rtb_Add2 - rtb_sqrt3_by_two;

    /* Sum: '<S18>/Add2' incorporates:
     *  Gain: '<S18>/Gain'
     *  Gain: '<S18>/Gain1'
     *  RelationalOperator: '<S27>/Compare'
     *  RelationalOperator: '<S28>/Compare'
     *  RelationalOperator: '<S29>/Compare'
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Add1'
     *  Sum: '<S5>/sum_beta'
     */
    CurLpCtrl_ELAPS_T_idx_0 = ((((uint32_T)(rtb_sum_alpha > 0) << 31) >> 1) +
      ((uint32_T)(rtDW.sum_beta > 0) << 29)) + ((uint32_T)(rtb_sqrt3_by_two > 0)
      << 31);

    /* Chart: '<S18>/Chart' incorporates:
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Add1'
     *  Sum: '<S18>/Add2'
     *  Sum: '<S5>/sum_beta'
     */
    rtb_Sector = 1U;
    tmp_3 = (uint64_T)rtDW.SqrtThreeOverSix * rtDW.Udc_pu;
    tmp_5 = tmp_3;
    if (tmp_3 > 4294967295ULL) {
      tmp_5 = 4294967295ULL;
      tmp_3 = 4294967295ULL;
    }

    rtb_Add2 = (int32_T)((uint32_T)tmp_5 >> 31);
    rtb_Add_m = (int32_T)((uint32_T)tmp_3 >> 31);
    if (CurLpCtrl_ELAPS_T_idx_0 == 1610612736U) {
      rtb_Sector = 3U;
      rtb_Add2 = rtb_sum_alpha;
      rtb_Add_m = rtDW.sum_beta;
    } else if (CurLpCtrl_ELAPS_T_idx_0 == 536870912U) {
      if (rtb_sum_alpha <= MIN_int32_T) {
        rtb_Add2 = MAX_int32_T;
      } else {
        rtb_Add2 = -rtb_sum_alpha;
      }

      if (rtb_sqrt3_by_two <= MIN_int32_T) {
        rtb_Add_m = MAX_int32_T;
      } else {
        rtb_Add_m = -rtb_sqrt3_by_two;
      }
    } else if (CurLpCtrl_ELAPS_T_idx_0 == 2684354560U) {
      rtb_Sector = 5U;
      rtb_Add2 = rtDW.sum_beta;
      rtb_Add_m = rtb_sqrt3_by_two;
    } else if (CurLpCtrl_ELAPS_T_idx_0 == 2147483648U) {
      rtb_Sector = 4U;
      if (rtDW.sum_beta <= MIN_int32_T) {
        rtb_Add2 = MAX_int32_T;
      } else {
        rtb_Add2 = -rtDW.sum_beta;
      }

      if (rtb_sum_alpha <= MIN_int32_T) {
        rtb_Add_m = MAX_int32_T;
      } else {
        rtb_Add_m = -rtb_sum_alpha;
      }
    } else if (CurLpCtrl_ELAPS_T_idx_0 == 3221225472U) {
      rtb_Sector = 6U;
      rtb_Add2 = rtb_sqrt3_by_two;
      rtb_Add_m = rtb_sum_alpha;
    } else if (CurLpCtrl_ELAPS_T_idx_0 == 1073741824U) {
      rtb_Sector = 2U;
      if (rtb_sqrt3_by_two <= MIN_int32_T) {
        rtb_Add2 = MAX_int32_T;
      } else {
        rtb_Add2 = -rtb_sqrt3_by_two;
      }

      if (rtDW.sum_beta <= MIN_int32_T) {
        rtb_Add_m = MAX_int32_T;
      } else {
        rtb_Add_m = -rtDW.sum_beta;
      }
    }

    /* End of Chart: '<S18>/Chart' */

    /* Sum: '<S20>/Add2' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion'
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     *  Sum: '<S20>/Add1'
     *  Switch: '<S17>/Switch'
     *  Switch: '<S17>/Switch1'
     *  Switch: '<S24>/Switch'
     *  Switch: '<S24>/Switch1'
     */
    CurLpCtrl_ELAPS_T_idx_0 = ((uint32_T)(rtb_Add2 >> 1) << 3) >> 2;
    rtb_Switch1_p = ((uint32_T)(rtb_Add_m >> 1) << 3) >> 2;

    /* Sum: '<S20>/Add1' incorporates:
     *  Sum: '<S20>/Add'
     */
    qY = CurLpCtrl_ELAPS_T_idx_0 + rtb_Switch1_p;

    /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
     *  Switch: '<S7>/Switch2'
     */
    switch (rtb_Sector) {
     case 1:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch2 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch3 = 2147483648U - qY;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch4 = qY + 2147483648U;
      break;

     case 2:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch2 = 2147483648U - qY;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch3 = qY + 2147483648U;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch4 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;
      break;

     case 3:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch2 = 2147483648U - qY;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch3 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch4 = qY + 2147483648U;
      break;

     case 4:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch2 = qY + 2147483648U;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch3 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch4 = 2147483648U - qY;
      break;

     case 5:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch2 = qY + 2147483648U;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch3 = 2147483648U - qY;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch4 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;
      break;

     default:
      /* Switch: '<S7>/Switch2' incorporates:
       *  Constant: '<S20>/Constant'
       *  Sum: '<S20>/Add2'
       */
      rtDW.Switch2 = (CurLpCtrl_ELAPS_T_idx_0 - rtb_Switch1_p) + 2147483648U;

      /* Switch: '<S7>/Switch3' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch1'
       *  Sum: '<S20>/Add'
       */
      rtDW.Switch3 = qY + 2147483648U;

      /* Switch: '<S7>/Switch4' incorporates:
       *  Constant: '<S20>/Constant'
       *  MultiPortSwitch: '<S20>/Multiport Switch2'
       *  Sum: '<S20>/Add1'
       */
      rtDW.Switch4 = 2147483648U - qY;
      break;
    }

    /* End of MultiPortSwitch: '<S20>/Multiport Switch' */

    /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
     *  Switch: '<S12>/Switch'
     */
    rtDW.UnitDelay_DSTATE[0] = rtb_Switch_f_idx_0;
    rtDW.UnitDelay_DSTATE[1] = rtb_Switch_f_idx_1;

    /* Update for UnitDelay: '<S30>/Unit Delay' incorporates:
     *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
     *  Saturate: '<S30>/Saturation'
     *  Sum: '<S30>/Sum3'
     */
    rtDW.UnitDelay_DSTATE_c = rtb_Saturation - DiscreteTimeIntegrator;

    /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    rtDW.DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator;

    /* Update for UnitDelay: '<S14>/Unit Delay' incorporates:
     *  Switch: '<S14>/Switch'
     */
    rtDW.UnitDelay_DSTATE_d = rtb_Sum2_0;

    /* Update for UnitDelay: '<S15>/Unit Delay' incorporates:
     *  Switch: '<S15>/Switch'
     */
    rtDW.UnitDelay_DSTATE_o = rtb_qcos;
  }

  rtPrevZCX.CurLpCtrl_Trig_ZCE = rtU.Trigger;

  /* End of Inport: '<Root>/Trigger' */
  /* End of Outputs for SubSystem: '<Root>/CurLpCtrl' */

  /* Outport: '<Root>/S' */
  rtY.S[0] = rtDW.Switch2;
  rtY.S[1] = rtDW.Switch3;
  rtY.S[2] = rtDW.Switch4;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0E-6, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  rtM->Timing.clockTick0++;
  if (!rtM->Timing.clockTick0) {
    rtM->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void CurLpCtrl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.CurLpCtrl_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/CurLpCtrl' */
  /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = 268435456;

  /* SystemInitialize for Chart: '<S11>/Chart' */
  rtDW.PiTimeThreeOverTwo = 2529944570U;
  rtDW.Pi = 1686629713U;
  rtDW.PiOverTow = 843314857U;
  rtDW.Neg = -1;
  rtDW.Pos = 1;
  rtDW.TwoPi = 421657428;

  /* SystemInitialize for Chart: '<S18>/Chart' */
  rtDW.Udc_pu = 48318382U;
  rtDW.SqrtThreeOverSix = 619925131U;

  /* SystemInitialize for Chart: '<S17>/Chart' */
  rtDW.TwoTimeSqrtThreeOverThree = 1239850262U;

  /* End of SystemInitialize for SubSystem: '<Root>/CurLpCtrl' */

  /* Enable for Triggered SubSystem: '<Root>/CurLpCtrl' */
  rtDW.CurLpCtrl_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for SubSystem: '<Root>/CurLpCtrl' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
