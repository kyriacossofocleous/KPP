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
/* File                 : strato_HessianSP.c                        */
/* Time                 : Wed Mar  9 11:42:29 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato */
/* Equation file        : strato.kpp                                */
/* Output root filename : strato                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "strato_Parameters.h"
#include "strato_Global.h"
#include "strato_Sparse.h"



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       1,  1,  2,  3,  3,  4,  4,  5,  6,  7,  8,  8,
       8,  8,  9, 10, 11, 12, 12, 12, 13, 13, 14, 14,
      15, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18,
      18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 21, 22,
      22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 24,
      24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25,
      25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
      25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26,
      26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 29,
      29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30,
      30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 32,
      32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
      32, 32, 32, 33, 33, 33, 33, 33, 33, 33, 33, 33,
      33, 33, 33, 33, 33, 33 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
      21, 27, 27, 27, 27, 27, 27, 27, 30, 30, 23, 23,
      23, 23, 20, 10, 22, 12, 23, 24, 13, 20, 14, 32,
      15, 16, 23, 25, 26, 16, 16, 32, 17, 21, 27, 18,
      25, 19, 19, 25, 13, 20, 20, 21, 21, 21, 27, 18,
      21, 21, 21, 22, 22, 22, 28, 23, 23, 23, 23, 12,
      23, 24, 24, 27, 29, 30, 30, 12, 13, 14, 15, 16,
      17, 18, 19, 19, 21, 23, 23, 25, 25, 25, 25, 25,
      25, 26, 28, 29, 31, 15, 16, 21, 23, 25, 26, 26,
      27, 27, 27, 17, 21, 25, 26, 26, 27, 27, 27, 27,
      27, 27, 10, 19, 24, 25, 26, 28, 28, 28, 28, 20,
      22, 27, 28, 29, 29, 31, 24, 27, 29, 30, 30, 30,
      30, 21, 22, 23, 25, 25, 27, 28, 30, 31, 31, 16,
      16, 19, 20, 24, 25, 25, 25, 26, 27, 28, 29, 30,
      31, 32, 32, 14, 20, 22, 22, 22, 25, 27, 27, 28,
      28, 29, 29, 30, 31, 32 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
      26, 27, 27, 27, 30, 27, 30, 30, 32, 33, 24, 25,
      26, 31, 29, 28, 33, 25, 24, 32, 25, 32, 25, 33,
      25, 26, 26, 27, 32, 25, 26, 32, 25, 25, 32, 25,
      33, 28, 32, 31, 25, 29, 32, 25, 26, 31, 33, 25,
      25, 26, 31, 29, 31, 33, 33, 24, 25, 26, 31, 25,
      24, 28, 32, 30, 30, 30, 31, 25, 25, 25, 25, 25,
      25, 25, 28, 32, 25, 25, 31, 25, 27, 28, 31, 32,
      33, 32, 32, 32, 32, 25, 26, 26, 26, 27, 28, 32,
      27, 29, 31, 25, 31, 27, 28, 32, 27, 29, 30, 31,
      32, 33, 28, 28, 28, 28, 28, 29, 31, 32, 33, 29,
      29, 29, 29, 30, 32, 33, 28, 30, 30, 30, 31, 32,
      33, 31, 31, 31, 25, 31, 31, 31, 31, 32, 33, 25,
      26, 32, 32, 32, 27, 28, 32, 32, 32, 32, 32, 32,
      32, 32, 33, 25, 29, 29, 31, 33, 33, 29, 33, 29,
      33, 30, 32, 33, 33, 33 }; 


