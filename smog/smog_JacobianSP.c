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
/* File                 : smog_JacobianSP.c                         */
/* Time                 : Thu Jan 27 12:39:11 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/smog   */
/* Equation file        : smog.kpp                                  */
/* Output root filename : smog                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "smog_Parameters.h"
#include "smog_Global.h"
#include "smog_Sparse.h"



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  0,  1,  1,  2,  2,  3,  3,  3,  4,  4,
       4,  4,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,
       7,  7,  7,  7,  8,  8,  8,  8,  8,  8,  8,  9,
       9,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10,
      10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11 }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0, 10, 11,  1, 10,  2, 11,  3,  6, 10,  1,  4,
       9, 10,  5,  7,  8,  9,  3,  6,  7,  9, 10, 11,
       7,  8,  9, 11,  2,  6,  7,  8,  9, 10, 11,  4,
       5,  6,  7,  8,  9, 10, 11,  3,  4,  5,  6,  7,
       8,  9, 10, 11,  2,  5,  7,  8,  9, 10, 11 }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  3,  5,  7, 10, 14, 18, 24, 28, 35, 43, 52,
      59 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  3,  5,  7, 11, 14, 19, 24, 31, 40, 50, 58,
      59 }; 


