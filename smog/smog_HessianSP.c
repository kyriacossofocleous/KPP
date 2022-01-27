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
/* File                 : smog_HessianSP.c                          */
/* Time                 : Thu Jan 27 12:46:18 2022                  */
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



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       0,  2,  3,  4,  5,  5,  6,  6,  6,  7,  7,  8,
       8,  8,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10,
      11, 11, 11, 11 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
      10,  2,  6,  4,  5,  8,  6,  6,  7,  7,  8,  2,
       6,  8,  4,  5,  6,  8,  4,  5,  6,  6,  8, 10,
       2,  5,  7, 10 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
      11, 11, 10,  9,  9,  9,  9, 10, 11, 11,  9, 11,
       9,  9,  9,  9,  9,  9,  9,  9,  9, 10,  9, 11,
      11,  9, 11, 11 }; 


