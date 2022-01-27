/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Sparse Stoichiometric Data Structures File                       */
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
/* File                 : small_single_StoichiomSP.c                */
/* Time                 : Thu Jan 27 10:54:13 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_single */
/* Equation file        : small_single.kpp                          */
/* Output root filename : small_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "small_single_Parameters.h"
#include "small_single_Global.h"
#include "small_single_Sparse.h"



/* Row-compressed sparse data for the Jacobian of reaction products JVRP */
 /* Beginning of rows in JVRP */

  int  CROW_JVRP[] = {
       0,  0,  1,  2,  4,  5,  6,  8, 10, 12, 13 }; 

 /* Column indices in JVRP */

  int  ICOL_JVRP[] = {
       1,  2,  1,  2,  2,  0,  0,  2,  2,  3,  1,  4,
       4 }; 

 /* Row indices in JVRP */

  int  IROW_JVRP[] = {
       1,  2,  3,  3,  4,  5,  6,  6,  7,  7,  8,  8,
       9 }; 




/*  Stoichiometric Matrix in Compressed Column Sparse Format        */

 /* Beginning of columns in STOICM */

  int  CCOL_STOICM[] = {
       0,  1,  3,  5,  7,  9, 11, 13, 16, 19, 22 }; 

 /* Row indices in STOICM */

  int  IROW_STOICM[] = {
       1,  1,  2,  1,  2,  1,  2,  0,  2,  0,  1,  0,
       2,  2,  3,  4,  1,  3,  4,  1,  3,  4 }; 

 /* Column indices in STOICM */

  int  ICOL_STOICM[] = {
       0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,
       6,  7,  7,  7,  8,  8,  8,  9,  9,  9 }; 

 /* Stoichiometric Matrix in compressed column format */

  float  STOICM[] = {
         2,   -1,    1,    1,   -1,   -1,   -1,    1,
        -1,   -1,    1,   -1,   -1,   -1,   -1,    1,
        -1,    1,   -1,    1,    1,   -1 }; 


