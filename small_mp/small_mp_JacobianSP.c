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
/* File                 : small_mp_JacobianSP.c                     */
/* Time                 : Fri Sep  2 14:41:03 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/small_mp */
/* Equation file        : small_mp.kpp                              */
/* Output root filename : small_mp                                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "small_mp_Parameters.h"
#include "small_mp_Global.h"
#include "small_mp_Sparse.h"



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  1,  1,  1,  1,  2,  2,  2,  2,  2,  3,
       3,  3,  3,  4,  4,  4,  4 }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0,  2,  0,  1,  2,  4,  0,  1,  2,  3,  4,  1,
       2,  3,  4,  1,  2,  3,  4 }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  2,  6, 11, 15, 19 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  3,  8, 13, 18, 19 }; 


