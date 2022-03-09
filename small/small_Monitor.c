/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Utility Data Initialization                                      */
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
/* File                 : small_Monitor.c                           */
/* Time                 : Wed Mar  9 11:42:27 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small  */
/* Equation file        : small.kpp                                 */
/* Output root filename : small                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "small_Parameters.h"
#include "small_Global.h"
#include "small_Sparse.h"



 /* Names of chemical species */

  char *  SPC_NAMES[] = {
     "O1D","O","O3","NO","NO2","M","O2" }; 

 /* Indexes of species to look at */

  int  LOOKAT[] = {
       0,  1,  2,  3,  4,  5,  6 }; 

 /* Indexes of species to monitor */

  int  MONITOR[] = {
       0,  1,  2,  3,  4,  6 }; 

 /* Names of atoms for mass balance */

  char *  SMASS[] = {
     "N" }; 

 /* Equation names */

  char *  EQN_NAMES[] = {
     "      O2 --> 2 O     ",
     "  O + O2 --> O3      ",
     "      O3 --> O + O2  ",
     "  O + O3 --> 2 O2    ",
     "      O3 --> O1D + O2",
     " O1D + M --> O + M   ",
     "O1D + O3 --> 2 O2    ",
     " O3 + NO --> NO2 + O2",
     " O + NO2 --> NO + O2 ",
     "     NO2 --> O + NO  "
      }; 


/* INLINED global variables                                         */

/* End INLINED global variables                                     */

