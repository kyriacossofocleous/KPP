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
/* File                 : saprc_JacobianSP.c                        */
/* Time                 : Wed Mar  9 12:16:43 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc  */
/* Equation file        : saprc.kpp                                 */
/* Output root filename : saprc                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "saprc_Parameters.h"
#include "saprc_Global.h"
#include "saprc_Sparse.h"



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,
       1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
       2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
       3,  3,  3,  3,  4,  4,  4,  5,  5,  5,  5,  5,
       6,  6,  6,  7,  7,  7,  7,  8,  8,  9,  9, 10,
      10, 11, 11, 11, 11, 11, 12, 12, 12, 13, 13, 13,
      14, 14, 14, 15, 15, 15, 16, 16, 16, 17, 17, 17,
      18, 18, 18, 19, 19, 20, 20, 21, 21, 21, 21, 22,
      22, 23, 23, 24, 24, 24, 24, 25, 25, 25, 25, 26,
      26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28,
      28, 29, 29, 30, 30, 31, 31, 31, 31, 32, 32, 32,
      32, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34, 35,
      35, 35, 35, 35, 35, 36, 36, 36, 36, 36, 37, 37,
      37, 37, 37, 37, 37, 38, 38, 38, 38, 38, 38, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 40, 40,
      40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 41, 41,
      41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41,
      42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,
      42, 42, 42, 42, 42, 42, 42, 42, 42, 43, 43, 43,
      43, 43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
      44, 44, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45,
      45, 45, 45, 45, 45, 45, 45, 46, 46, 46, 46, 46,
      47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
      47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
      47, 47, 47, 47, 47, 48, 48, 48, 48, 48, 49, 49,
      49, 49, 49, 49, 49, 50, 50, 50, 50, 50, 51, 51,
      51, 51, 51, 51, 51, 52, 52, 52, 52, 52, 53, 53,
      53, 53, 53, 53, 53, 54, 54, 54, 54, 54, 54, 54,
      54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
      54, 54, 54, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
      55, 55, 55, 56, 56, 56, 56, 56, 56, 56, 56, 56,
      56, 56, 56, 56, 57, 57, 57, 57, 57, 57, 57, 57,
      57, 57, 57, 57, 57, 57, 58, 58, 58, 58, 58, 58,
      58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
      58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 59, 59,
      59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59,
      59, 59, 59, 59, 59, 59, 60, 60, 60, 60, 60, 60,
      60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
      60, 60, 60, 60, 60, 61, 61, 61, 61, 61, 61, 61,
      61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61,
      61, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
      62, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65,
      65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
      65, 65, 65, 65, 65, 65, 65, 65, 66, 66, 66, 66,
      66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
      67, 67, 67, 67, 67, 68, 68, 68, 68, 68, 68, 68,
      68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
      68, 68, 68, 68, 68, 68, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
      72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
      72, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73 }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0,  8, 73,  1, 19, 26, 43, 46, 48, 49, 50, 51,
      52, 53, 61, 68, 73,  2, 50, 52, 61, 62, 63, 65,
      67, 71,  3, 46, 48, 50, 51, 52, 61, 62, 63, 64,
      65, 66, 67, 72,  4, 62, 71,  5, 62, 64, 66, 72,
       6, 27, 69,  7, 27, 37, 69,  8, 73,  9, 61, 10,
      73, 11, 23, 48, 61, 73, 12, 69, 71, 13, 69, 72,
      14, 66, 69, 15, 64, 69, 16, 62, 73, 17, 69, 70,
      18, 68, 73, 19, 73, 20, 73, 20, 21, 69, 73, 22,
      73, 23, 73, 24, 62, 69, 73, 25, 62, 65, 73, 26,
      55, 62, 68, 27, 35, 62, 69, 70, 28, 63, 65, 67,
      73, 29, 73, 30, 73, 23, 30, 31, 73, 23, 30, 32,
      73, 23, 30, 33, 70, 73, 23, 30, 34, 61, 73, 27,
      35, 45, 62, 69, 70, 36, 62, 63, 67, 73, 23, 30,
      37, 52, 61, 70, 73, 30, 38, 45, 62, 70, 73, 19,
      29, 31, 32, 34, 39, 40, 43, 44, 46, 48, 49, 50,
      51, 52, 53, 54, 55, 57, 58, 61, 70, 73, 23, 30,
      31, 32, 33, 40, 49, 51, 53, 61, 70, 73, 19, 20,
      21, 22, 29, 41, 48, 50, 52, 56, 61, 69, 70, 73,
      17, 33, 35, 37, 38, 40, 42, 44, 45, 49, 51, 52,
      53, 54, 55, 58, 61, 62, 69, 70, 73, 43, 57, 61,
      70, 73, 19, 23, 30, 31, 32, 34, 38, 43, 44, 45,
      48, 51, 57, 61, 62, 70, 73, 33, 38, 45, 62, 64,
      66, 68, 69, 70, 71, 72, 73, 46, 57, 61, 70, 73,
      20, 22, 29, 31, 32, 41, 46, 47, 48, 50, 52, 53,
      56, 57, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
      69, 70, 71, 72, 73, 48, 57, 61, 70, 73, 46, 49,
      52, 57, 61, 70, 73, 50, 57, 61, 70, 73, 46, 51,
      52, 57, 61, 70, 73, 52, 57, 61, 70, 73, 46, 52,
      53, 57, 61, 70, 73, 10, 20, 22, 29, 43, 50, 51,
      52, 54, 56, 57, 58, 59, 60, 61, 64, 66, 68, 70,
      71, 72, 73, 19, 20, 22, 25, 26, 28, 29, 41, 43,
      44, 45, 46, 48, 49, 50, 51, 52, 53, 55, 56, 57,
      59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
      71, 72, 73, 21, 48, 50, 51, 52, 56, 57, 61, 63,
      68, 69, 70, 73,  9, 43, 46, 48, 49, 50, 52, 53,
      57, 61, 68, 69, 70, 73, 19, 20, 22, 29, 31, 32,
      34, 36, 43, 48, 49, 50, 51, 52, 53, 56, 57, 58,
      59, 60, 61, 62, 63, 67, 68, 69, 70, 73, 20, 22,
      29, 49, 50, 51, 52, 53, 56, 57, 59, 60, 61, 63,
      65, 67, 68, 69, 70, 73, 22, 29, 30, 46, 48, 50,
      51, 52, 53, 56, 57, 60, 61, 63, 65, 66, 67, 68,
      69, 70, 71, 72, 73, 34, 43, 46, 48, 49, 50, 51,
      52, 53, 57, 61, 62, 64, 66, 68, 69, 70, 71, 72,
      73,  8, 16, 18, 19, 23, 24, 25, 26, 27, 28, 30,
      31, 32, 34, 35, 36, 39, 40, 43, 44, 45, 46, 48,
      49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
      61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
      73, 19, 20, 22, 23, 29, 30, 46, 48, 50, 51, 52,
      53, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
      67, 68, 69, 70, 71, 72, 73, 15, 46, 49, 51, 52,
      53, 57, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
      71, 72, 73, 21, 25, 29, 41, 43, 46, 48, 50, 52,
      53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 72, 73, 14, 37, 52, 57,
      61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
      73, 10, 19, 20, 22, 23, 29, 30, 31, 32, 33, 34,
      36, 38, 43, 45, 46, 48, 49, 50, 51, 52, 53, 56,
      57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
      69, 70, 71, 72, 73, 18, 26, 47, 48, 50, 52, 53,
      55, 56, 57, 59, 60, 61, 62, 63, 64, 65, 66, 67,
      68, 69, 70, 71, 72, 73, 12, 13, 14, 15, 17, 18,
      21, 24, 26, 27, 35, 42, 44, 45, 46, 47, 48, 49,
      50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
      62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
      17, 24, 33, 35, 37, 38, 40, 42, 43, 44, 45, 46,
      47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
      59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
      71, 72, 73, 11, 12, 23, 29, 31, 32, 40, 41, 48,
      49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61,
      62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
      13, 44, 45, 48, 49, 51, 52, 53, 57, 58, 59, 60,
      61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
      73,  8,  9, 10, 16, 18, 19, 20, 22, 23, 24, 25,
      28, 29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40,
      41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53,
      54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 72, 73 }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  3, 17, 26, 40, 43, 48, 51, 55, 57, 59, 61,
      66, 69, 72, 75, 78, 81, 84, 87, 89, 91, 95, 97,
      99,103,107,111,116,121,123,125,129,133,138,143,
     149,154,161,167,190,202,216,237,242,259,271,276,
     305,310,317,322,329,334,341,363,399,412,426,454,
     474,497,517,565,595,615,644,661,701,726,768,807,
     840,865,920 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  3, 17, 26, 40, 43, 48, 51, 55, 57, 59, 61,
      66, 69, 72, 75, 78, 81, 84, 87, 89, 92, 95, 97,
      99,103,107,111,116,121,123,127,131,135,140,144,
     149,156,162,172,195,207,222,237,250,261,271,283,
     305,311,317,323,329,336,349,381,404,420,443,464,
     485,507,553,584,605,635,653,694,720,763,803,837,
     863,919,920 }; 


