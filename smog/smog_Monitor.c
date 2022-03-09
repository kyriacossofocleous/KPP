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
/* File                 : smog_Monitor.c                            */
/* Time                 : Wed Mar  9 12:16:49 2022                  */
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
#include "smog_Parameters.h"
#include "smog_Global.h"
#include "smog_Sparse.h"



 /* Names of chemical species */

  char *  SPC_NAMES[] = {
     "HNO3","O","RH","RCOO2NO2","O3","HO2","RCOO2","RCHO",
     "RO2","NO","NO2","OH","H2O","O2","CO","CO2"
      }; 

 /* Indexes of species to look at */

  int  LOOKAT[] = {
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
      12, 13, 14, 15 }; 

 /* Indexes of species to monitor */

  int  MONITOR[] = {
       4 }; 

 /* Names of atoms for mass balance */

  char *  SMASS[] = {
     0 }; 

 /* Equation names */

  char *  EQN_NAMES[] = {
     "        NO2 --> O + NO     ",
     "     O + O2 --> O3         ",
     "    O3 + NO --> NO2 + O2   ",
     "    RH + OH --> RO2 + H2O  ",
     "  RCHO + OH --> RCOO2 + H2O",
     "       RCHO --> HO2 + RO2 + CO",
     "   HO2 + NO --> NO2 + OH   ",
     "   RO2 + NO --> HO2 + RCHO + NO2",
     " RCOO2 + NO --> RO2 + NO2 + CO2",
     "   NO2 + OH --> HNO3       ",
     "RCOO2 + NO2 --> RCOO2NO2   ",
     "   RCOO2NO2 --> RCOO2 + NO2"
      }; 


/* INLINED global variables                                         */

/* End INLINED global variables                                     */

