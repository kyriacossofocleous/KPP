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
/* File                 : chapman_single_HessianSP.c                */
/* Time                 : Thu Jan 27 11:06:18 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman_single */
/* Equation file        : chapman_single.kpp                        */
/* Output root filename : chapman_single                            */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "chapman_single_Parameters.h"
#include "chapman_single_Global.h"
#include "chapman_single_Sparse.h"



/* Hessian Sparse Data                                              */
/*                                                                  */
 /* Index i of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_I[] = {
       0,  1,  1,  2,  2,  2,  3,  3,  4,  4 }; 

 /* Index j of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_J[] = {
       0,  1,  1,  0,  1,  2,  1,  2,  1,  2 }; 

 /* Index k of Hessian element d^2 f_i/dv_j.dv_k */

  int  IHESS_K[] = {
       2,  2,  4,  2,  2,  3,  4,  3,  4,  3 }; 


