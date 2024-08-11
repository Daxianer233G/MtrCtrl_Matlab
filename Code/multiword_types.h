/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: multiword_types.h
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

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

/*
 * MultiWord supporting definitions
 */
typedef long long longlong_T;

/*
 * MultiWord types
 */
typedef struct {
  uint64_T chunks[2];
} int128m_T;

typedef struct {
  uint64_T chunks[2];
} uint128m_T;

typedef struct {
  uint64_T chunks[3];
} int192m_T;

typedef struct {
  uint64_T chunks[3];
} uint192m_T;

typedef struct {
  uint64_T chunks[4];
} int256m_T;

typedef struct {
  uint64_T chunks[4];
} uint256m_T;

#endif                                 /* MULTIWORD_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
