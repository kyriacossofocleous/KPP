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
/* File                 : tropo_single_Monitor.c                    */
/* Time                 : Thu Jan 27 12:47:07 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/tropo_single */
/* Equation file        : tropo_single.kpp                          */
/* Output root filename : tropo_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "tropo_single_Parameters.h"
#include "tropo_single_Global.h"
#include "tropo_single_Sparse.h"



 /* Names of chemical species */

  char *  SPC_NAMES[] = {
     "SO4","ACTA","R3N2","SUCA","GLUA","ADIA","PRN2","PRPN",
     "OZID","MSA","DOL6","DOL7","DOL8","CPET","CHEX","MACA",
     "PYVA","DMS","C2H6","C3H8","MPAN","IPAN","H2O2","AROM",
     "TPAN","N2O5","HONO","RAN2","CH4","ALKA","HNO4","PAN",
     "ACO2","DIAL","GLYX","CRES","AHO2","RAN1","ZO2","ETHE",
     "CO","MGLY","MAN2","TO2","HAC","R3O2","EO2","PO2",
     "MRO2","MVN2","ETO2","PRN1","RIO2","TCO3","INO2","HACO",
     "HNO3","MGGY","VRO2","ALKE","RAO2","KET","KO2","ISOP",
     "MO2","MAO3","CRO2","MCRG","MVKO","MAOO","ROOH","MCO3",
     "MACR","O3","MVK","NO2","HCHO","SO2","ALD2","CHO2",
     "NO","HO2","NO3","OH","O2","H2O","CO2","H2"
      }; 

 /* Indexes of species to look at */

  int  LOOKAT[] = {
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
      12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
      36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
      60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
      72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
      84, 85, 86, 87 }; 

 /* Indexes of species to monitor */

  int  MONITOR[] = {
      73 }; 

 /* Names of atoms for mass balance */

  char *  SMASS[] = {
     0 }; 

 /* Equation names */

  char *  EQN_NAMES[] = {
     "        NO2 --> O3 + NO                    ",
     "    O3 + NO --> NO2 + O2                   ",
     "   O3 + NO2 --> NO3 + O2                   ",
     "   NO + NO3 --> 2 NO2                      ",
     "  NO2 + NO3 --> N2O5                       ",
     "       N2O5 --> NO2 + NO3                  ",
     "  NO2 + NO3 --> NO2 + NO + O2              ",
     "        NO3 --> 0.85 O3 + 0.85 NO2 + 0.15 NO + O2",
     "  HO2 + NO3 --> HNO3 + O2                  ",
     "         O3 --> 2 OH                       ",
     "    NO + OH --> HONO                       ",
     "       HONO --> NO + OH                    ",
     "   NO2 + OH --> HNO3                       ",
     "       HNO3 --> NO2 + OH                   ",
     "  HNO3 + OH --> NO3 + H2O                  ",
     " N2O5 + H2O --> 2 HNO3                     ",
     "    CO + OH --> HO2 + CO2                  ",
     "    O3 + OH --> HO2 + O2                   ",
     "   NO + HO2 --> NO2 + OH                   ",
     "  NO2 + HO2 --> HNO4                       ",
     "       HNO4 --> NO2 + HO2                  ",
     "   O3 + HO2 --> OH + 2 O2                  ",
     "      2 HO2 --> H2O2 + O2                  ",
     "       H2O2 --> 2 OH                       ",
     "  H2O2 + OH --> HO2 + H2O                  ",
     "  NO2 + H2O --> HONO + HNO3 - NO2          ",
     "       HNO4 --> NO2 + HO2                  ",
     "  HNO4 + OH --> NO2 + O2 + H2O             ",
     "   SO2 + OH --> SO4 + HO2                  ",
     "       HCHO --> CO + 2 HO2                 ",
     "       HCHO --> CO + H2                    ",
     "  HCHO + OH --> CO + HO2 + H2O             ",
     " HCHO + HO2 --> AHO2                       ",
     "  AHO2 + NO --> ACO2 + NO2 + HO2           ",
     " AHO2 + HO2 --> ACO2 + O2 + H2O            ",
     "     2 AHO2 --> ACO2 + 2 HO2 + 2 O2        ",
     "  ACO2 + OH --> HO2 + H2O + CO2            ",
     " HCHO + NO3 --> CO + HNO3 + HO2            ",
     "  ALD2 + OH --> MCO3 + H2O                 ",
     " ALD2 + NO3 --> HNO3 + MCO3                ",
     "       ALD2 --> CO + MO2 + HO2             ",
     "       ALD2 --> CH4 + CO                   ",
     " MCO3 + NO2 --> PAN                        ",
     "        PAN --> MCO3 + NO2                 ",
     "  MCO3 + NO --> MO2 + NO2 + CO2            ",
     "   MO2 + NO --> NO2 + HCHO + HO2           ",
     "   CH4 + OH --> MO2 + H2O                  ",
     "  C2H6 + OH --> ETO2 + H2O                 ",
     "  ETO2 + NO --> NO2 + ALD2 + HO2           ",
     "  C3H8 + OH --> R3O2                       ",
     "  R3O2 + NO --> 0.03 R3N2 + 0.49 KET + 0.97 NO2 + 0.46 ALD2 + 0.97 HO2 ... etc.",
     "  ALKA + OH --> RAO2                       ",
     "  RAO2 + NO --> 0.263 RAN2 + 0.1057 R3O2 + 0.1879 ETO2 + 0.06 RAO2 + 0.3 KET ... etc.",
     " ALKA + NO3 --> HNO3 + RAO2                ",
     "  RAN2 + OH --> RAN1 + H2O                 ",
     "  RAN1 + NO --> 2.5 NO2 + 0.8 HCHO + 2.1 ALD2 - -0.5 NO",
     "      2 MO2 --> 1.4 HCHO + 0.8 HO2 + O2    ",
     "     2 ETO2 --> 1.6 ALD2 + 1.2 HO2         ",
     "     2 R3O2 --> 0.28 KET + 1.9 ALD2 + 0.37 HO2",
     "  MO2 + HO2 --> ROOH + O2                  ",
     " ETO2 + HO2 --> ROOH + O2                  ",
     " R3O2 + HO2 --> ROOH + O2                  ",
     " RAO2 + HO2 --> ROOH + O2                  ",
     " MCO3 + HO2 --> ROOH + O2                  ",
     "   KET + OH --> KO2                        ",
     "   KO2 + NO --> 0.05 RAN2 + 0.94 MCO3 + 0.95 NO2 + 0.94 ALD2",
     "        KET --> ETO2 + MCO3 + H2O          ",
     "  KET + NO3 --> HNO3 + KO2                 ",
     "  KO2 + HO2 --> MGLY + MO2 + H2O           ",
     "  ETHE + OH --> EO2                        ",
     "   EO2 + NO --> NO2 + 2 HCHO + HO2         ",
     "  ALKE + OH --> PO2                        ",
     "   PO2 + NO --> NO2 + HCHO + ALD2 + HO2    ",
     "  ETHE + O3 --> 0.06 CH4 + 0.42 CO + HCHO + 0.4 CHO2 + 0.12 HO2",
     "  ALKE + O3 --> 0.215 MO2 + 0.2 CRO2 + 0.525 HCHO + 0.5 ALD2 + 0.2 CHO2 ... etc.",
     "  CHO2 + NO --> NO2 + HCHO                 ",
     " NO2 + CHO2 --> HCHO + NO3                 ",
     " CHO2 + H2O --> ACO2                       ",
     "  CRO2 + NO --> NO2 + ALD2                 ",
     " CRO2 + NO2 --> ALD2 + NO3                 ",
     " CRO2 + H2O --> ACTA                       ",
     "      2 EO2 --> 2.4 HCHO + 0.4 ALD2 + 1.2 HO2",
     "      2 PO2 --> 2.2 ALD2 + 1.2 HO2         ",
     "  EO2 + HO2 --> ROOH + O2                  ",
     "  PO2 + HO2 --> ROOH + O2                  ",
     " SO2 + CHO2 --> SO4 + HCHO                 ",
     " CRO2 + SO2 --> SO4 + ALD2                 ",
     " ALKE + NO3 --> PRN1                       ",
     " PRN1 + NO2 --> PRN2                       ",
     " PRN1 + HO2 --> PRPN + O2                  ",
     "  PRN1 + NO --> 2 NO2 + HCHO + ALD2        ",
     "HCHO + CHO2 --> OZID                       ",
     "ALD2 + CHO2 --> OZID                       ",
     "CRO2 + HCHO --> OZID                       ",
     "CRO2 + ALD2 --> OZID                       ",
     "  AROM + OH --> 0.16 CRES + 0.84 TO2 + 0.16 HO2",
     "   TO2 + NO --> DIAL + 0.18 GLYX + 0.72 MGLY + NO2 + HO2",
     "       GLYX -->                            ",
     "  GLYX + OH --> 2 CO + HO2 + H2O           ",
     "       MGLY --> CO + MCO3 + HO2            ",
     "  MGLY + OH --> CO + MCO3 + H2O            ",
     "  CRES + OH --> 0.9 ZO2 + 0.9 TCO3 - -0.0315 NO2 + 0.83 HO2 - -0.9 OH ... etc.",
     " CRES + NO3 --> HNO3                       ",
     "  DIAL + OH --> TCO3                       ",
     " TCO3 + NO2 --> TPAN                       ",
     "       TPAN --> TCO3 + NO2                 ",
     "  TCO3 + NO --> 0.89 GLYX + 0.11 MGLY + 0.05 MCO3 + NO2 + 0.92 HO2",
     "   ZO2 + NO --> NO2                        ",
     "       DIAL --> TCO3 + 0.02 MCO3 + 0.98 HO2",
     "  TO2 + HO2 --> ROOH + O2                  ",
     " TCO3 + HO2 --> ROOH + O2                  ",
     "  ZO2 + HO2 --> ROOH + O2                  ",
     "       AHO2 --> HCHO + HO2                 ",
     "  ISOP + OH --> RIO2                       ",
     "  RIO2 + NO --> 0.45 MACR + 0.45 MVK + 0.9 NO2 + 0.9 HCHO + 0.9 HO2 ... etc.",
     " RIO2 + HO2 --> ROOH                       ",
     "   MVK + OH --> VRO2                       ",
     "  VRO2 + NO --> 0.6 HAC + 0.3 MGGY + 0.6 MCO3 + 0.9 NO2 + 0.3 HCHO + 0.3 HO2 ... etc.",
     " VRO2 + HO2 --> ROOH                       ",
     "  MACR + OH --> MAO3                       ",
     " MAO3 + NO2 --> MPAN                       ",
     "       MPAN --> MAO3 + NO2                 ",
     "  MAO3 + NO --> MGGY - -2 NO + HO2 + 3 NO3 ",
     " MAO3 + HO2 --> ROOH                       ",
     "  MACR + OH --> MRO2                       ",
     "  MRO2 + NO --> 0.9 MGGY + 0.9 NO2 + 0.9 HCHO + 0.9 HO2",
     " MRO2 + HO2 --> ROOH                       ",
     "   HAC + OH --> HACO                       ",
     " HACO + NO2 --> IPAN                       ",
     "       IPAN --> HACO + NO2                 ",
     "  HACO + NO --> NO2 + HCHO + HO2           ",
     " HACO + HO2 --> ROOH                       ",
     "  ISOP + O3 --> 0.2 MVKO + 0.3 MAOO + 0.3 MACR + 0.2 MVK + 0.5 HCHO ... etc.",
     "   O3 + MVK --> 0.5 MGGY + 0.2 MCRG + 0.15 MCO3 + 0.5 HCHO + 0.15 ALD2 ... etc.",
     "  MACR + O3 --> 0.5 MGGY + 0.2 MCRG + 0.15 NO2 + 0.65 HCHO + 0.2 CHO2 ... etc.",
     "  MVKO + NO --> MVK + NO2                  ",
     " MVKO + NO2 --> MVK + NO3                  ",
     " MVKO + H2O -->                            ",
     "  MAOO + NO --> MACR + NO2                 ",
     " MAOO + NO2 --> MACR + NO3                 ",
     " MAOO + H2O --> MACA                       ",
     "  MCRG + NO --> MGGY + NO2                 ",
     " MCRG + NO2 --> MGGY + NO3                 ",
     " MCRG + H2O --> PYVA                       ",
     "        HAC --> HCHO + 2 HO2               ",
     "       MGGY --> MCO3 + HO2                 ",
     "  MGGY + OH --> MCO3                       ",
     " ISOP + NO3 --> INO2                       ",
     "  INO2 + NO --> 0.5 MACR + 0.5 MVK + 2 NO2 + HCHO",
     " INO2 + NO2 -->                            ",
     " INO2 + HO2 -->                            ",
     "  MVK + NO3 --> MVN2                       ",
     "  MVN2 + NO --> 0.5 MGGY + 0.5 MCO3 + 2 NO2 + HCHO + 0.5 HO2",
     " MVN2 + HO2 -->                            ",
     " MACR + NO3 --> HNO3 + MAO3                ",
     " MACR + NO3 --> MAN2                       ",
     "  MAN2 + NO --> MGGY + 2 NO2 + HCHO        ",
     " MAN2 + HO2 -->                            ",
     "  HAC + NO3 --> HACO + HNO3                ",
     " MAOO + HO2 --> ROOH                       ",
     " MVKO + HO2 --> ROOH                       ",
     " MVKO + SO2 --> SO4 + MVK                  ",
     " MAOO + SO2 --> SO4 + MACR                 ",
     " MCRG + SO2 --> SO4 + MVK                  ",
     "  MACA + OH -->                            ",
     "  PYVA + OH -->                            ",
     "  DOL6 + O3 --> 0.11 SUCA                  ",
     "  DOL7 + O3 --> 0.19 GLUA                  ",
     "  DOL8 + O3 --> 0.15 ADIA                  ",
     "  CPET + O3 --> 0.39 GLUA                  ",
     "  CHEX + O3 --> 0.15 ADIA                  ",
     "   HO2 + OH --> O2 + H2O                   ",
     "       ROOH --> HCHO + HO2 + OH            ",
     "  ROOH + OH --> 0.5 MO2 + 0.5 HCHO + 0.5 OH",
     "   DMS + OH --> MSA + SO2                  ",
     "      2 NO3 --> 2 NO2 + O2                 ",
     "   PAN + OH -->                            ",
     "  HO2 + NO3 --> 0.4 HNO3 + 0.6 NO2 + 0.6 OH"
      }; 


/* INLINED global variables                                         */

/* End INLINED global variables                                     */

