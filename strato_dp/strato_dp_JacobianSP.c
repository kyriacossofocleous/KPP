/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Sparse Jacobian Data Structures File                             */
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
/* File                 : strato_dp_JacobianSP.c                    */
/* Time                 : Fri Sep  2 14:40:25 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/strato_dp */
/* Equation file        : strato_dp.kpp                             */
/* Output root filename : strato_dp                                 */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "strato_dp_Parameters.h"
#include "strato_dp_Global.h"
#include "strato_dp_Sparse.h"



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  0,  0,  1,  1,  1,  1,  2,  2,  3,  3,
       3,  3,  3,  4,  4,  4,  5,  5,  5,  6,  6,  6,
       7,  7,  7,  8,  8,  8,  8,  8,  8,  9,  9,  9,
       9, 10, 10, 11, 11, 11, 12, 12, 12, 12, 12, 13,
      13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 15,
      15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 17, 18,
      18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19,
      19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21,
      21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23,
      23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24,
      24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 25,
      25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
      25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28,
      28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30,
      30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31, 31, 32, 32, 32, 32, 32,
      32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
      32, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33,
      33, 33, 33, 33 }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0, 10, 25, 26,  1, 21, 26, 27,  2, 27,  2,  3,
      26, 27, 30,  4, 27, 30,  5, 27, 30,  6, 30, 32,
       7, 30, 33,  8, 23, 24, 25, 26, 31,  9, 13, 20,
      29, 10, 28, 11, 22, 33, 12, 23, 24, 25, 32, 13,
      20, 25, 32, 14, 25, 32, 33, 15, 16, 23, 25, 26,
      27, 32, 16, 25, 26, 32, 17, 21, 25, 27, 32, 11,
      18, 21, 22, 25, 33, 10, 19, 23, 25, 26, 28, 31,
      32,  0, 10, 13, 20, 25, 26, 28, 29, 32, 21, 25,
      26, 27, 31, 33,  7, 11, 14, 18, 21, 22, 25, 26,
      27, 28, 29, 30, 31, 32, 33,  9, 10, 13, 20, 23,
      24, 25, 26, 28, 29, 31, 32,  5,  6,  7, 12, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 32, 33,  6, 10,
      12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 32, 33,  1,  2,
       3,  5, 15, 16, 17, 21, 23, 24, 25, 26, 27, 28,
      29, 30, 31, 32, 33,  2,  4, 17, 21, 25, 26, 27,
      28, 29, 30, 31, 32, 33, 10, 19, 23, 24, 25, 26,
      27, 28, 29, 30, 31, 32, 33, 20, 22, 25, 26, 27,
      28, 29, 30, 31, 32, 33, 24, 25, 26, 27, 28, 29,
      30, 31, 32, 33,  4, 10, 21, 22, 23, 24, 25, 26,
      27, 28, 29, 30, 31, 32, 33,  8,  9, 13, 14, 16,
      19, 20, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
      33, 11, 14, 18, 20, 21, 22, 25, 26, 27, 28, 29,
      30, 31, 32, 33 }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  4,  8, 10, 15, 18, 21, 24, 27, 33, 37, 39,
      42, 47, 51, 55, 62, 66, 71, 77, 85, 94,100,115,
     127,142,166,185,198,211,222,232,247,265,280 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  4,  8, 11, 15, 18, 21, 24, 27, 33, 37, 39,
      42, 47, 51, 55, 62, 66, 72, 78, 88, 94,105,119,
     132,157,177,191,205,217,228,244,263,279,280 }; 


