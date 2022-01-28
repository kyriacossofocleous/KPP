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
/* File                 : cbm4_Monitor.c                            */
/* Time                 : Fri Jan 28 10:55:36 2022                  */
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



 /* Names of chemical species */

  char *  SPC_NAMES[] = {
     "O1D","H2O2","PAN","CRO","TOL","N2O5","XYL","XO2N",
     "HONO","PNA","TO2","HNO3","ROR","CRES","MGLY","CO",
     "ETH","XO2","OPEN","PAR","HCHO","ISOP","OLE","ALD2",
     "O3","NO2","OH","HO2","O","NO3","NO","C2O3",
     "H2O" }; 

 /* Indexes of species to look at */

  int  LOOKAT[] = {
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
      12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 32 }; 

 /* Indexes of species to monitor */

  int  MONITOR[] = {
      24 }; 

 /* Names of atoms for mass balance */

  char *  SMASS[] = {
     0 }; 

 /* Equation names */

  char *  EQN_NAMES[] = {
     "           NO2 --> O + NO        ",
     "             O --> O3            ",
     "       O3 + NO --> NO2           ",
     "       NO2 + O --> NO            ",
     "       NO2 + O --> NO3           ",
     "        O + NO --> NO2           ",
     "      O3 + NO2 --> NO3           ",
     "            O3 --> O             ",
     "            O3 --> O1D           ",
     "           O1D --> O             ",
     "     O1D + H2O --> 2 OH          ",
     "       O3 + OH --> HO2           ",
     "      O3 + HO2 --> OH            ",
     "           NO3 --> 0.89 NO2 + 0.89 O + 0.11 NO",
     "      NO3 + NO --> 2 NO2         ",
     "     NO2 + NO3 --> NO2 + NO      ",
     "     NO2 + NO3 --> N2O5          ",
     "    N2O5 + H2O --> 2 HNO3        ",
     "          N2O5 --> NO2 + NO3     ",
     "          2 NO --> 2 NO2         ",
     "NO2 + NO + H2O --> 2 HONO        ",
     "       OH + NO --> HONO          ",
     "          HONO --> OH + NO       ",
     "     HONO + OH --> NO2           ",
     "        2 HONO --> NO2 + NO      ",
     "      NO2 + OH --> HNO3          ",
     "     HNO3 + OH --> NO3           ",
     "      HO2 + NO --> NO2 + OH      ",
     "     NO2 + HO2 --> PNA           ",
     "           PNA --> NO2 + HO2     ",
     "      PNA + OH --> NO2           ",
     "         2 HO2 --> H2O2          ",
     "   2 HO2 + H2O --> H2O2          ",
     "          H2O2 --> 2 OH          ",
     "     H2O2 + OH --> HO2           ",
     "       CO + OH --> HO2           ",
     "     HCHO + OH --> CO + HO2      ",
     "          HCHO --> CO + 2 HO2    ",
     "          HCHO --> CO            ",
     "      HCHO + O --> CO + OH + HO2 ",
     "    HCHO + NO3 --> HNO3 + CO + HO2",
     "      ALD2 + O --> OH + C2O3     ",
     "     ALD2 + OH --> C2O3          ",
     "    ALD2 + NO3 --> HNO3 + C2O3   ",
     "          ALD2 --> CO + XO2 + HCHO + 2 HO2",
     "     NO + C2O3 --> XO2 + HCHO + NO2 + HO2",
     "    NO2 + C2O3 --> PAN           ",
     "           PAN --> NO2 + C2O3    ",
     "        2 C2O3 --> 2 XO2 + 2 HCHO + 2 HO2",
     "    HO2 + C2O3 --> 0.79 XO2 + 0.79 HCHO + 0.79 OH + 0.79 HO2",
     "            OH --> XO2 + HCHO + HO2",
     "      PAR + OH --> 0.13 XO2N + 0.76 ROR + 0.87 XO2 - -0.11 PAR + 0.11 ALD2 ... etc.",
     "           ROR --> 0.04 XO2N + 0.02 ROR + 0.96 XO2 - -2.1 PAR + 1.1 ALD2 ... etc.",
     "           ROR --> HO2           ",
     "     ROR + NO2 -->               ",
     "       OLE + O --> 0.02 XO2N + 0.3 CO + 0.28 XO2 + 0.22 PAR + 0.2 HCHO ... etc.",
     "      OLE + OH --> XO2 - PAR + HCHO + ALD2 + HO2",
     "      OLE + O3 --> 0.33 CO + 0.22 XO2 - PAR + 0.74 HCHO + 0.5 ALD2 + 0.1 OH ... etc.",
     "     OLE + NO3 --> 0.09 XO2N + 0.91 XO2 - PAR + HCHO + ALD2 + NO2",
     "       ETH + O --> CO + 0.7 XO2 + HCHO + 0.3 OH + 1.7 HO2",
     "      ETH + OH --> XO2 + 1.56 HCHO + 0.22 ALD2 + HO2",
     "      ETH + O3 --> 0.42 CO + HCHO + 0.12 HO2",
     "      TOL + OH --> 0.56 TO2 + 0.36 CRES + 0.08 XO2 + 0.44 HO2",
     "      TO2 + NO --> 0.9 OPEN + 0.9 NO2 + 0.9 HO2",
     "           TO2 --> CRES + HO2    ",
     "     CRES + OH --> 0.4 CRO + 0.6 XO2 + 0.3 OPEN + 0.6 HO2",
     "    CRES + NO3 --> CRO + HNO3    ",
     "     CRO + NO2 -->               ",
     "      XYL + OH --> 0.3 TO2 + 0.2 CRES + 0.8 MGLY + 0.5 XO2 + 1.1 PAR + 0.7 HO2 ... etc.",
     "     OPEN + OH --> 2 CO + XO2 + HCHO + 2 HO2 + C2O3",
     "          OPEN --> CO + HO2 + C2O3",
     "     OPEN + O3 --> 0.2 MGLY + 0.69 CO + 0.03 XO2 + 0.7 HCHO + 0.03 ALD2 ... etc.",
     "     MGLY + OH --> XO2 + C2O3    ",
     "          MGLY --> CO + HO2 + C2O3",
     "      ISOP + O --> 0.5 CO + 0.45 ETH + 0.5 XO2 + 0.9 PAR + 0.55 OLE + 0.8 ALD2 ... etc.",
     "     ISOP + OH --> 0.13 XO2N + 0.4 MGLY + ETH + XO2 + HCHO + 0.2 ALD2 + 0.67 HO2 ... etc.",
     "     ISOP + O3 --> 0.2 MGLY + 0.06 CO + 0.55 ETH + 0.1 PAR + HCHO + 0.4 ALD2 ... etc.",
     "    ISOP + NO3 --> XO2N          ",
     "      XO2 + NO --> NO2           ",
     "         2 XO2 -->               ",
     "     XO2N + NO -->               "
      }; 


/* INLINED global variables                                         */

/* End INLINED global variables                                     */

