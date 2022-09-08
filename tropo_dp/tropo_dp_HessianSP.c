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
/* File                 : tropo_dp_HessianSP.c                      */
/* Time                 : Fri Sep  2 14:40:27 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/tropo_dp */
/* Equation file        : tropo_dp.kpp                              */
/* Output root filename : tropo_dp                                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "tropo_dp_Parameters.h"
#include "tropo_dp_Global.h"
#include "tropo_dp_Sparse.h"



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       0,  0,  0,  0,  0,  0,  2,  3,  4,  4,  5,  5,
       6,  7,  8,  8,  8,  8,  9, 10, 11, 12, 13, 14,
      15, 16, 17, 18, 19, 20, 21, 22, 22, 23, 24, 25,
      26, 27, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31,
      32, 32, 32, 32, 33, 33, 34, 34, 34, 35, 35, 35,
      36, 36, 36, 36, 37, 37, 38, 38, 38, 39, 39, 40,
      40, 40, 40, 40, 40, 41, 41, 41, 41, 42, 42, 42,
      43, 43, 43, 44, 44, 44, 45, 45, 45, 45, 45, 46,
      46, 46, 46, 47, 47, 47, 47, 48, 48, 48, 49, 49,
      49, 50, 50, 50, 50, 50, 51, 51, 51, 51, 52, 52,
      52, 53, 53, 53, 53, 53, 54, 54, 54, 54, 55, 55,
      55, 55, 55, 56, 56, 56, 56, 56, 56, 56, 56, 56,
      56, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 58,
      58, 58, 59, 59, 59, 60, 60, 60, 60, 61, 61, 61,
      61, 61, 62, 62, 62, 62, 63, 63, 63, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 65, 65, 65, 65, 65, 66,
      66, 66, 66, 66, 66, 67, 67, 67, 67, 67, 68, 68,
      68, 68, 68, 69, 69, 69, 69, 69, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 72, 72, 72, 72, 72, 72, 72, 72, 72, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76,
      76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76,
      76, 76, 76, 76, 77, 77, 77, 77, 77, 77, 77, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 79, 79, 79, 79, 79,
      79, 79, 79, 79, 79, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82,
      82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,
      82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
      66, 67, 68, 69, 77, 77, 45, 10, 11, 13, 12, 14,
      51, 51, 66, 66, 76, 78, 17, 10, 11, 12, 13, 14,
      15, 16, 17, 18, 19, 65, 55, 22, 81, 23, 53, 75,
      80, 27, 60, 62, 28, 39, 29, 29, 30, 75, 31, 71,
      32, 36, 36, 36, 33, 43, 34, 43, 53, 23, 35, 35,
      36, 36, 36, 76, 27, 37, 35, 38, 38, 39, 39, 34,
      39, 40, 41, 76, 76, 41, 43, 53, 62, 42, 42, 72,
      23, 43, 43, 44, 44, 58, 19, 45, 45, 45, 60, 39,
      46, 46, 46, 47, 47, 47, 59, 48, 48, 72, 49, 49,
      74, 18, 50, 50, 50, 60, 51, 51, 51, 59, 52, 52,
      63, 33, 35, 53, 53, 53, 54, 54, 54, 63, 44, 44,
      55, 55, 55, 29, 35, 44, 56, 61, 72, 75, 76, 78,
      81, 42, 48, 49, 57, 58, 65, 67, 67, 72, 73, 58,
      58, 74, 59, 59, 59, 29, 29, 60, 60, 45, 45, 60,
      61, 61, 61, 61, 62, 62, 63, 63, 63, 28, 59, 60,
      62, 64, 64, 64, 70, 71, 65, 65, 65, 72, 72, 59,
      66, 66, 66, 66, 66, 67, 67, 67, 72, 73, 63, 68,
      68, 68, 68, 63, 69, 69, 69, 69, 38, 43, 45, 46,
      47, 48, 50, 52, 53, 55, 58, 60, 64, 65, 68, 69,
      70, 71, 41, 49, 53, 57, 58, 62, 71, 71, 71, 73,
      78, 78, 52, 54, 63, 69, 69, 69, 72, 72, 72, 10,
      11, 12, 13, 14, 39, 59, 63, 72, 73, 73, 73, 73,
      73, 52, 54, 63, 67, 68, 68, 68, 73, 74, 74, 30,
      35, 36, 37, 38, 42, 43, 45, 46, 47, 48, 49, 50,
      51, 51, 52, 53, 53, 54, 54, 55, 55, 58, 60, 62,
      64, 65, 66, 66, 67, 67, 68, 68, 69, 69, 71, 71,
      72, 73, 73, 75, 75, 75, 75, 79, 80, 80, 81, 82,
      37, 39, 42, 46, 46, 47, 48, 49, 51, 52, 54, 55,
      58, 59, 63, 64, 64, 66, 70, 72, 73, 75, 76, 76,
      76, 76, 77, 79, 17, 66, 67, 68, 69, 77, 77, 37,
      45, 45, 46, 47, 47, 50, 50, 51, 59, 60, 62, 66,
      66, 66, 66, 73, 78, 78, 78, 39, 59, 63, 72, 73,
      75, 76, 77, 78, 79, 36, 37, 38, 42, 43, 45, 46,
      47, 48, 49, 50, 51, 52, 53, 54, 55, 58, 60, 62,
      64, 65, 66, 67, 68, 69, 71, 72, 73, 75, 79, 80,
      80, 80, 22, 23, 32, 34, 35, 36, 36, 36, 38, 39,
      40, 42, 43, 43, 45, 45, 45, 46, 46, 46, 47, 47,
      47, 48, 48, 49, 49, 50, 50, 50, 51, 52, 52, 53,
      53, 54, 55, 55, 58, 58, 59, 60, 60, 62, 63, 64,
      64, 64, 65, 65, 68, 69, 71, 72, 73, 73, 73, 75,
      76, 76, 76, 77, 80, 81, 81, 81, 29, 35, 44, 56,
      59, 61, 63, 65, 66, 67, 68, 69, 72, 73, 74, 75,
      75, 76, 78, 80, 81, 82, 15, 16, 17, 18, 19, 22,
      23, 27, 28, 29, 30, 31, 32, 33, 34, 35, 39, 40,
      41, 44, 56, 57, 59, 61, 63, 70, 72, 73, 73, 74,
      75, 76, 77, 78, 80, 80, 81, 81 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
      77, 77, 77, 77, 79, 83, 80, 73, 73, 73, 73, 73,
      75, 81, 76, 78, 79, 79, 83, 73, 73, 73, 73, 73,
      83, 83, 83, 83, 83, 75, 75, 83, 81, 83, 75, 82,
      83, 83, 80, 80, 83, 73, 82, 83, 83, 81, 83, 75,
      83, 36, 80, 81, 83, 80, 83, 80, 80, 83, 82, 83,
      36, 80, 81, 81, 83, 80, 83, 80, 81, 73, 83, 83,
      73, 83, 83, 82, 83, 83, 80, 80, 81, 80, 81, 82,
      83, 80, 81, 82, 83, 80, 83, 45, 80, 81, 80, 83,
      46, 80, 81, 47, 80, 81, 83, 80, 81, 83, 80, 81,
      82, 83, 50, 80, 81, 80, 75, 80, 81, 82, 80, 81,
      83, 83, 83, 75, 80, 81, 75, 80, 81, 82, 82, 83,
      75, 80, 81, 82, 82, 82, 83, 82, 82, 83, 82, 82,
      82, 80, 80, 80, 83, 80, 80, 75, 80, 73, 74, 80,
      81, 83, 73, 82, 83, 82, 83, 80, 81, 45, 80, 80,
      82, 83, 82, 83, 80, 81, 73, 82, 83, 83, 73, 80,
      81, 64, 80, 81, 83, 80, 75, 80, 81, 82, 83, 73,
      75, 76, 77, 78, 80, 75, 77, 80, 73, 74, 73, 75,
      77, 80, 81, 73, 75, 77, 80, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      83, 81, 83, 80, 80, 83, 80, 80, 75, 80, 81, 74,
      82, 83, 80, 80, 73, 75, 77, 80, 73, 82, 83, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 74, 75, 80, 81,
      83, 80, 80, 73, 77, 75, 77, 80, 74, 82, 83, 83,
      83, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      75, 80, 80, 75, 80, 75, 80, 75, 80, 80, 80, 80,
      80, 75, 75, 80, 75, 80, 75, 80, 75, 80, 75, 80,
      73, 75, 80, 79, 81, 82, 83, 80, 81, 82, 82, 82,
      80, 73, 80, 46, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 73, 73, 64, 80, 76, 83, 73, 74, 79, 79, 81,
      82, 83, 79, 80, 83, 77, 77, 77, 77, 79, 83, 80,
      45, 80, 46, 47, 80, 50, 80, 80, 73, 80, 80, 75,
      77, 78, 80, 74, 79, 82, 83, 73, 73, 73, 73, 74,
      79, 79, 79, 79, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 73, 80, 82, 80, 81,
      82, 83, 83, 83, 83, 83, 83, 36, 80, 81, 81, 73,
      83, 81, 80, 81, 45, 80, 81, 46, 80, 81, 47, 80,
      81, 80, 81, 80, 81, 50, 80, 81, 81, 80, 81, 80,
      81, 81, 80, 81, 80, 81, 73, 80, 81, 81, 73, 64,
      80, 81, 80, 81, 81, 81, 81, 73, 74, 81, 83, 81,
      81, 82, 83, 83, 81, 81, 82, 83, 82, 82, 82, 83,
      82, 82, 82, 80, 75, 75, 75, 75, 82, 75, 82, 79,
      82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 81, 83, 83,
      83, 83, 83, 83, 81, 83, 82, 83 }; 


