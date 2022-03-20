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
/* File                 : cbm4_enh_HessianSP.c                      */
/* Time                 : Fri Mar 18 18:58:28 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/cbm4_enh */
/* Equation file        : cbm4_enh.kpp                              */
/* Output root filename : cbm4_enh                                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <xmmintrin.h>
#include <float.h>
#include "cbm4_enh_Parameters.h"
#include "cbm4_enh_Global.h"
#include "cbm4_enh_Sparse.h"



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       1,  1,  2,  3,  3,  3,  4,  5,  6,  7,  7,  7,
       7,  7,  7,  8,  8,  8,  8,  9,  9, 10, 10, 10,
      11, 11, 11, 11, 11, 12, 12, 13, 13, 13, 13, 14,
      14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
      15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 17, 17,
      17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
      17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19,
      19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20,
      20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21,
      21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23,
      23, 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24,
      24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25,
      25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
      25, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29,
      29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30,
      30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31,
      31, 31, 31, 31, 31, 31 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
       1, 27, 25,  3, 13, 13,  4, 25,  6,  7, 19, 21,
      21, 22, 22,  8,  8, 25, 26,  9, 25,  4,  6, 10,
      11, 13, 20, 23, 25, 12, 19,  4,  6, 13, 13,  6,
      14, 18, 21, 21, 15, 16, 16, 18, 18, 20, 20, 20,
      21, 21, 22, 22, 16, 16, 16, 21, 21, 21,  4,  6,
      13, 14, 16, 16, 17, 17, 18, 18, 19, 21, 21, 22,
      22, 22, 22, 27, 30, 31, 10, 13, 18, 18,  6, 19,
      21, 21, 22, 22, 22, 22, 16, 16, 16, 18, 18, 20,
      20, 20, 21, 21, 22, 22, 22, 22, 27, 30, 31, 21,
      21, 21, 21, 21, 22, 22, 22, 22, 16, 18, 19, 21,
      21, 21, 22, 22, 22, 22, 23, 23, 23, 16, 18, 21,
      22, 24, 24, 24, 24,  3,  8,  8,  9, 10, 12, 17,
      22, 24, 24, 25, 25, 25, 25, 25, 25, 27, 28, 29,
      30, 30,  1,  4,  6,  8,  9, 11, 13, 14, 15, 16,
      16, 18, 18, 19, 20, 20, 21, 21, 22, 22, 22, 23,
      23, 24, 24, 25, 26, 27, 27,  1,  4,  6, 10, 13,
      15, 16, 16, 16, 18, 18, 19, 20, 20, 20, 21, 21,
      21, 22, 22, 22, 24, 24, 25, 27, 27, 27, 30, 31,
      16, 20, 21, 22, 23, 25, 28, 11, 13, 20, 21, 22,
      23, 24, 25, 25, 29,  7,  8, 10, 17, 24, 25, 25,
      25, 26, 27, 28, 29, 30, 30, 14, 18, 18, 21, 23,
      23, 23, 25, 27, 30, 31 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
      26, 27, 31, 25, 26, 29, 26, 29, 26, 30, 26, 26,
      29, 28, 29,  8, 26, 30, 30, 26, 27, 26, 26, 30,
      26, 29, 29, 29, 26, 25, 26, 26, 26, 26, 29, 26,
      26, 24, 24, 26, 26, 24, 28, 24, 26, 26, 28, 29,
      24, 28, 24, 28, 24, 26, 28, 24, 26, 28, 26, 26,
      26, 26, 26, 28, 17, 30, 24, 26, 26, 26, 28, 24,
      26, 28, 29, 31, 31, 31, 30, 26, 24, 26, 26, 26,
      24, 28, 24, 26, 28, 29, 24, 26, 28, 24, 26, 26,
      28, 29, 24, 26, 24, 26, 28, 29, 31, 31, 31, 24,
      26, 28, 29, 28, 24, 26, 28, 29, 26, 24, 26, 24,
      26, 28, 24, 26, 28, 29, 26, 28, 29, 24, 24, 24,
      24, 25, 26, 27, 30, 25,  8, 26, 26, 30, 25, 30,
      29, 25, 30, 26, 27, 28, 29, 30, 31, 30, 30, 30,
      30, 31, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
      28, 24, 26, 26, 26, 28, 24, 26, 24, 26, 28, 26,
      28, 26, 27, 26, 30, 30, 31, 26, 26, 26, 30, 26,
      26, 24, 26, 28, 24, 26, 26, 26, 28, 29, 24, 26,
      28, 24, 26, 28, 26, 27, 27, 27, 30, 31, 31, 31,
      28, 28, 28, 28, 28, 28, 30, 26, 29, 29, 29, 29,
      29, 25, 28, 29, 30, 30,  8, 30, 30, 30, 28, 29,
      30, 30, 30, 30, 30, 30, 31, 26, 24, 26, 26, 26,
      28, 29, 31, 31, 31, 31 }; 


