/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Sparse Hessian Data Structures File                              */
/*                                                                  */
/* Generated by KPP-2.2.3 symbolic chemistry Kinetics PreProcessor  */
/*       (http://www.cs.vt.edu/~asandu/Software/KPP)                */
/* KPP is distributed under GPL, the general public licence         */
/*       (http://www.gnu.org/copyleft/gpl.html)                     */
/* (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa           */
/* (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech            */
/*     With important contributions from:                           */
/*        M. Damian, Villanova University, USA                      */
/*        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany */
/*                                                                  */
/* File                 : saprc_HessianSP.c                         */
/* Time                 : Wed Apr  6 15:24:57 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/saprc  */
/* Equation file        : saprc.kpp                                 */
/* Output root filename : saprc                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "saprc_Parameters.h"
#include "saprc_Global.h"
#include "saprc_Sparse.h"



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,
       2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,
       3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  5,
       5,  5,  6,  7,  8, 10, 11, 11, 12, 13, 14, 15,
      16, 16, 17, 18, 18, 19, 20, 21, 21, 22, 23, 24,
      24, 25, 25, 26, 26, 27, 27, 27, 28, 28, 28, 28,
      29, 30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33,
      34, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37,
      37, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 40,
      40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 41,
      41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41,
      42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,
      42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 44, 44,
      44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 45, 45,
      45, 45, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47,
      47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
      47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
      47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 48, 48,
      48, 48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 50,
      50, 50, 50, 51, 51, 51, 51, 51, 51, 52, 52, 52,
      52, 53, 53, 53, 53, 53, 53, 53, 54, 54, 54, 54,
      54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
      54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 56, 56,
      56, 56, 56, 56, 56, 57, 57, 57, 57, 57, 57, 57,
      57, 57, 57, 58, 58, 58, 58, 58, 58, 58, 58, 58,
      58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
      58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 59, 59,
      59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59,
      59, 59, 59, 59, 59, 60, 60, 60, 60, 60, 60, 60,
      60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
      60, 60, 60, 61, 61, 61, 61, 61, 61, 61, 61, 61,
      61, 61, 61, 61, 61, 61, 61, 61, 61, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 65, 65, 65, 65,
      65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
      65, 65, 65, 65, 65, 65, 65, 66, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 68, 68, 68, 68, 68, 68, 68, 68, 68,
      68, 68, 68, 68, 68, 68, 68, 68, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
      72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
       8, 19, 26, 43, 46, 48, 49, 50, 51, 52, 53, 50,
      52, 62, 63, 65, 67, 46, 48, 50, 51, 52, 62, 62,
      62, 63, 63, 63, 64, 64, 65, 65, 66, 67, 62, 62,
      62, 62, 27, 27,  8, 10, 23, 48, 69, 69, 66, 64,
      16, 62, 69, 18, 68, 19, 20, 20, 21, 22, 23, 24,
      62, 25, 62, 26, 55, 27, 27, 35, 28, 63, 65, 65,
      29, 30, 23, 30, 31, 23, 30, 32, 23, 30, 33, 33,
      23, 30, 34, 34, 27, 35, 45, 36, 62, 62, 23, 30,
      37, 37, 52, 52, 52, 30, 38, 38, 45, 19, 29, 34,
      34, 39, 40, 40, 43, 43, 44, 44, 46, 48, 49, 49,
      49, 50, 51, 51, 51, 52, 52, 53, 55, 55, 58, 23,
      30, 33, 40, 40, 49, 49, 51, 51, 51, 53, 53, 19,
      20, 22, 29, 41, 48, 50, 50, 50, 52, 52, 52, 56,
      33, 35, 37, 38, 40, 42, 44, 49, 51, 54, 55, 58,
      62, 69, 43, 43, 43, 43, 19, 23, 30, 34, 38, 43,
      44, 44, 48, 51, 51, 33, 33, 38, 38, 45, 45, 64,
      66, 66, 66, 66, 66, 46, 46, 46, 46, 20, 22, 29,
      31, 32, 41, 46, 46, 46, 46, 47, 47, 47, 47, 47,
      47, 47, 47, 47, 47, 48, 48, 48, 50, 50, 52, 52,
      52, 53, 56, 59, 64, 66, 66, 66, 66, 66, 48, 48,
      48, 48, 46, 46, 49, 49, 49, 49, 52, 52, 52, 50,
      50, 50, 50, 46, 46, 51, 51, 51, 52, 52, 52, 52,
      52, 46, 46, 52, 52, 53, 53, 53, 10, 20, 22, 29,
      43, 43, 50, 50, 50, 51, 51, 52, 52, 52, 54, 54,
      56, 58, 59, 60, 64, 66, 68, 70, 71, 72, 19, 20,
      22, 25, 28, 29, 41, 43, 43, 43, 46, 46, 46, 48,
      48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 52, 53,
      53, 55, 55, 55, 56, 59, 60, 63, 64, 64, 64, 64,
      64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 21, 48,
      50, 51, 52, 56, 63, 43, 46, 48, 49, 50, 52, 53,
      57, 57, 57, 19, 20, 22, 29, 31, 32, 34, 36, 43,
      48, 48, 48, 48, 49, 50, 50, 50, 50, 51, 51, 52,
      52, 52, 52, 53, 53, 56, 58, 58, 59, 60, 20, 22,
      29, 49, 50, 51, 51, 52, 52, 52, 52, 53, 56, 59,
      60, 63, 63, 63, 63, 22, 29, 30, 46, 46, 48, 48,
      48, 50, 50, 50, 51, 52, 52, 56, 60, 63, 63, 63,
      63, 63, 63, 34, 43, 46, 48, 49, 50, 51, 52, 53,
      57, 61, 61, 61, 61, 62, 62, 62, 62,  8, 16, 19,
      23, 26, 27, 28, 30, 34, 39, 43, 43, 44, 44, 45,
      48, 49, 50, 51, 52, 52, 53, 55, 55, 55, 56, 60,
      61, 61, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 63, 63, 63, 63, 65, 65, 65, 65, 67, 67,
      67, 70, 19, 20, 22, 23, 29, 30, 46, 46, 46, 46,
      48, 48, 48, 50, 50, 50, 51, 51, 52, 52, 52, 52,
      53, 56, 58, 59, 60, 62, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 46, 46, 49, 49, 51, 51, 62, 63, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 25, 29, 43, 46,
      50, 52, 52, 62, 63, 64, 64, 65, 65, 65, 65, 65,
      65, 65, 66, 68, 70, 71, 71, 37, 37, 62, 63, 64,
      65, 66, 66, 66, 66, 66, 66, 66, 10, 19, 20, 22,
      23, 29, 30, 33, 34, 36, 38, 43, 43, 43, 46, 46,
      46, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51,
      51, 52, 52, 52, 52, 53, 53, 56, 58, 59, 60, 62,
      63, 64, 64, 65, 66, 66, 67, 67, 67, 67, 67, 68,
      70, 71, 72, 26, 47, 57, 57, 61, 62, 63, 64, 65,
      66, 67, 68, 68, 68, 68, 68, 69, 18, 21, 24, 26,
      27, 45, 46, 47, 47, 48, 52, 56, 57, 57, 61, 61,
      62, 62, 62, 63, 64, 64, 64, 65, 65, 66, 66, 66,
      67, 67, 68, 68, 68, 68, 69, 69, 69, 69, 70, 70,
      70, 70, 33, 35, 37, 38, 40, 42, 43, 44, 46, 47,
      48, 49, 50, 51, 52, 54, 55, 57, 58, 61, 62, 63,
      64, 65, 66, 67, 68, 69, 70, 70, 70, 70, 29, 31,
      32, 40, 40, 41, 48, 52, 53, 54, 54, 59, 60, 62,
      63, 64, 64, 64, 64, 64, 65, 66, 67, 68, 69, 70,
      71, 71, 44, 44, 48, 49, 51, 52, 53, 58, 58, 59,
      60, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
       8, 10, 16, 18, 19, 20, 22, 23, 24, 25, 28, 29,
      30, 31, 32, 33, 34, 34, 36, 37, 38, 39, 40, 41,
      42, 43, 43, 44, 46, 46, 48, 48, 49, 49, 50, 50,
      51, 51, 52, 52, 53, 53, 54, 55, 56, 58, 59, 60,
      61, 61, 62, 62, 62, 68, 69, 70 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
      73, 73, 68, 61, 61, 61, 61, 61, 61, 61, 61, 61,
      61, 71, 71, 71, 71, 61, 61, 61, 61, 61, 64, 66,
      72, 64, 66, 72, 65, 67, 66, 72, 67, 72, 71, 64,
      66, 72, 69, 69, 73, 73, 73, 61, 71, 72, 69, 69,
      73, 62, 70, 73, 73, 73, 73, 73, 69, 73, 73, 73,
      69, 73, 65, 68, 62, 62, 69, 70, 73, 65, 65, 67,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 70, 73,
      73, 73, 61, 73, 62, 70, 69, 73, 63, 67, 73, 73,
      70, 73, 61, 70, 73, 73, 70, 73, 62, 73, 73, 61,
      73, 73, 70, 73, 57, 61, 70, 73, 61, 61, 61, 70,
      73, 61, 61, 70, 73, 57, 61, 61, 70, 73, 73, 73,
      73, 73, 70, 73, 61, 73, 61, 70, 73, 61, 73, 73,
      73, 73, 73, 73, 61, 61, 70, 73, 61, 70, 73, 73,
      70, 70, 70, 70, 70, 73, 70, 70, 70, 70, 70, 70,
      70, 73, 57, 61, 70, 73, 73, 73, 73, 61, 73, 57,
      70, 73, 61, 61, 73, 70, 73, 70, 73, 62, 69, 66,
      66, 68, 70, 71, 72, 57, 61, 70, 73, 73, 73, 73,
      73, 73, 73, 57, 61, 70, 73, 62, 63, 64, 65, 66,
      67, 68, 70, 71, 72, 61, 70, 73, 70, 73, 61, 70,
      73, 73, 73, 73, 66, 66, 68, 70, 71, 72, 57, 61,
      70, 73, 61, 73, 57, 61, 70, 73, 57, 61, 73, 57,
      61, 70, 73, 70, 73, 61, 70, 73, 73, 57, 61, 70,
      73, 61, 73, 61, 70, 57, 61, 73, 73, 73, 73, 73,
      57, 73, 61, 70, 73, 61, 73, 61, 70, 73, 70, 73,
      73, 73, 73, 73, 72, 72, 72, 72, 72, 72, 73, 73,
      73, 73, 73, 73, 73, 57, 61, 73, 57, 61, 73, 61,
      73, 61, 73, 61, 73, 61, 70, 73, 61, 70, 73, 61,
      73, 62, 70, 73, 73, 73, 73, 65, 64, 65, 66, 68,
      70, 71, 72, 65, 66, 67, 68, 70, 71, 72, 69, 70,
      70, 70, 70, 73, 68, 57, 57, 57, 57, 57, 57, 57,
      61, 68, 69, 73, 73, 73, 73, 73, 73, 73, 73, 70,
      57, 61, 70, 73, 57, 57, 61, 70, 73, 70, 73, 57,
      61, 70, 73, 57, 73, 73, 70, 73, 73, 73, 73, 73,
      73, 73, 57, 61, 73, 57, 61, 70, 73, 57, 73, 73,
      73, 63, 65, 67, 70, 73, 73, 73, 57, 61, 57, 61,
      73, 57, 61, 73, 73, 57, 61, 73, 73, 63, 65, 66,
      67, 71, 72, 61, 61, 61, 61, 61, 61, 61, 61, 61,
      61, 62, 68, 69, 73, 64, 66, 71, 72, 73, 73, 73,
      73, 68, 62, 73, 73, 61, 73, 57, 61, 70, 73, 62,
      61, 61, 61, 61, 57, 61, 61, 62, 70, 73, 73, 73,
      62, 73, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
      72, 73, 63, 65, 67, 70, 65, 67, 68, 70, 67, 68,
      70, 73, 73, 73, 73, 73, 73, 73, 57, 61, 70, 73,
      61, 70, 73, 61, 70, 73, 70, 73, 57, 61, 70, 73,
      73, 73, 73, 73, 73, 63, 63, 64, 65, 66, 67, 68,
      70, 71, 72, 57, 61, 70, 73, 70, 73, 64, 64, 64,
      65, 66, 67, 68, 69, 70, 71, 72, 73, 73, 57, 57,
      61, 61, 70, 65, 65, 65, 71, 65, 66, 67, 68, 70,
      71, 72, 71, 71, 71, 71, 72, 70, 73, 66, 66, 66,
      66, 66, 67, 68, 69, 70, 71, 72, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 57, 70, 73, 61, 70,
      73, 61, 70, 73, 61, 70, 73, 61, 70, 73, 61, 70,
      73, 57, 61, 70, 73, 61, 73, 73, 73, 73, 73, 67,
      67, 67, 72, 67, 67, 72, 67, 68, 70, 71, 72, 72,
      72, 72, 72, 68, 68, 68, 69, 68, 68, 68, 68, 68,
      68, 68, 68, 70, 71, 72, 73, 70, 73, 69, 73, 68,
      69, 69, 70, 68, 70, 70, 70, 73, 68, 69, 68, 69,
      68, 69, 70, 70, 68, 69, 70, 68, 70, 68, 69, 70,
      68, 70, 68, 70, 71, 72, 70, 71, 72, 73, 70, 71,
      72, 73, 70, 70, 70, 70, 70, 73, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 69, 70, 69, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 71, 72, 73, 73, 73,
      73, 70, 73, 73, 61, 61, 73, 70, 73, 73, 73, 71,
      71, 64, 66, 68, 70, 72, 71, 71, 71, 71, 71, 71,
      71, 72, 70, 73, 61, 61, 61, 61, 61, 70, 73, 73,
      73, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 61, 73, 73, 73, 73, 73, 73, 73,
      73, 61, 73, 73, 61, 73, 61, 73, 61, 73, 61, 73,
      61, 73, 61, 73, 61, 73, 73, 73, 73, 73, 73, 73,
      62, 73, 68, 70, 73, 73, 73, 73 }; 


