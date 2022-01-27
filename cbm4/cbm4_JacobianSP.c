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
/* File                 : cbm4_JacobianSP.c                         */
/* Time                 : Thu Jan 27 12:48:12 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/cbm4   */
/* Equation file        : cbm4.kpp                                  */
/* Output root filename : cbm4                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "cbm4_Parameters.h"
#include "cbm4_Global.h"
#include "cbm4_Sparse.h"



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  1,  1,  1,  2,  2,  2,  3,  3,  3,  3,
       3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  7,  7,
       7,  7,  7,  7,  7,  8,  8,  8,  8,  9,  9,  9,
       9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11,
      11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13,
      13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15,
      15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16,
      17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
      17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18,
      18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19,
      19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
      20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22,
      22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
      23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
      24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
      25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
      28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30,
      30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31,
      31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31
      }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0, 24,  1, 26, 27,  2, 25, 31,  3, 13, 25, 26,
      29,  4, 26,  5, 25, 29,  6, 26,  7, 12, 19, 21,
      22, 26, 28, 29, 30,  8, 25, 26, 30,  9, 25, 26,
      27,  4,  6, 10, 26, 30,  5, 11, 13, 20, 23, 25,
      26, 29, 12, 19, 25, 26,  4,  6, 10, 13, 26, 29,
      30,  6, 14, 18, 21, 24, 26, 14, 15, 16, 18, 20,
      21, 22, 23, 24, 26, 28, 29, 16, 21, 24, 26, 28,
       4,  6, 12, 13, 14, 16, 17, 18, 19, 21, 22, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 10, 13, 18, 24,
      26, 29, 30,  6, 12, 19, 21, 22, 24, 25, 26, 28,
      29, 16, 18, 20, 21, 22, 23, 24, 26, 27, 28, 29,
      30, 31, 21, 24, 26, 28, 29, 21, 22, 24, 26, 28,
      29, 12, 16, 18, 19, 21, 22, 23, 24, 25, 26, 28,
      29, 30, 16, 18, 21, 22, 24, 25, 26, 27, 28, 29,
      30,  2,  3,  5,  8,  9, 10, 12, 13, 17, 18, 19,
      21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,  0,
       1,  4,  6,  8,  9, 11, 13, 14, 15, 16, 18, 19,
      20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
       1,  4,  6,  9, 10, 12, 13, 14, 15, 16, 18, 19,
      20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
       0, 16, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
      30, 31,  5, 11, 13, 20, 21, 22, 23, 24, 25, 26,
      27, 28, 29, 30, 31,  7,  8, 10, 12, 17, 18, 19,
      21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,  2,
      14, 18, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31
      }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  2,  5,  8, 13, 15, 18, 20, 29, 33, 37, 42,
      50, 54, 61, 67, 79, 84,104,111,121,134,139,145,
     158,169,191,216,240,254,269,287,300 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  2,  5,  8, 13, 15, 18, 20, 29, 33, 39, 43,
      50, 57, 62, 68, 79, 90,106,113,123,134,140,151,
     162,184,210,235,250,266,285,299,300 }; 


