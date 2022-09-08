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
/* File                 : saprc_sp_Monitor.c                        */
/* Time                 : Fri Sep  2 14:40:35 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/saprc_sp */
/* Equation file        : saprc_sp.kpp                              */
/* Output root filename : saprc_sp                                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "saprc_sp_Parameters.h"
#include "saprc_sp_Global.h"
#include "saprc_sp_Sparse.h"



 /* Names of chemical species */

  char *  SPC_NAMES[] = {
     "H2SO4","HCOOH","CCO_OH","RCO_OH","CCO_OOH","RCO_OOH","XN","XC",
     "SO2","O1D","ALK1","BACL","PAN","PAN2","PBZN","MA_PAN",
     "H2O2","N2O5","HONO","ALK2","ALK3","TBU_O","ALK5","ARO2",
     "HNO4","COOH","HOCOO","BZNO2_O","MEOH","ALK4","ARO1","DCB2",
     "DCB3","CRES","DCB1","NPHE","ROOH","BALD","PHEN","CO",
     "MGLY","ACET","HNO3","ETHENE","GLY","BZ_O","ISOPRENE","R2O2",
     "TERP","METHACRO","OLE1","ISOPROD","OLE2","MVK","CCHO","HCHO",
     "RNO3","O3P","RCHO","MEK","PROD2","O3","HO2","RO2_N",
     "MA_RCO3","C_O2","BZCO_O2","RO2_R","NO","NO2","NO3","CCO_O2",
     "RCO_O2","OH","AIR","O2","H2O","H2","CH4" }; 

 /* Indexes of species to look at */

  int  LOOKAT[] = {
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
      12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
      24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
      36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
      48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
      60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
      72, 73, 74, 75, 76, 77, 78 }; 

 /* Indexes of species to monitor */

  int  MONITOR[] = {
      43, 61, 68, 69 }; 

 /* Names of atoms for mass balance */

  char *  SMASS[] = {
     0 }; 

 /* Equation names */

  char *  EQN_NAMES[] = {
     "              NO2 --> O3P + NO                                                                 ",
     "   O3P + AIR + O2 --> O3                                                                       ",
     "         O3P + O3 --> 2 O2                                                                     ",
     "   O3P + NO + AIR --> NO2                                                                      ",
     "        O3P + NO2 --> NO                                                                       ",
     "        O3P + NO2 --> NO3                                                                      ",
     "          O3 + NO --> NO2                                                                      ",
     "         O3 + NO2 --> NO3                                                                      ",
     "         NO + NO3 --> 2 NO2                                                                    ",
     "        2 NO + O2 --> 2 NO2                                                                    ",
     "        NO2 + NO3 --> N2O5                                                                     ",
     "             N2O5 --> NO2 + NO3                                                                ",
     "       N2O5 + H2O --> 2 HNO3                                                                   ",
     "        NO2 + NO3 --> NO + NO2                                                                 ",
     "              NO3 --> NO                                                                       ",
     "              NO3 --> O3P + NO2                                                                ",
     "               O3 --> O3P                                                                      ",
     "               O3 --> O1D                                                                      ",
     "        O1D + H2O --> 2 OH                                                                     ",
     "        O1D + AIR --> O3P                                                                      ",
     "          NO + OH --> HONO                                                                     ",
     "             HONO --> NO + OH                                                                  ",
     "             HONO --> HO2 + NO2                                                                ",
     "        HONO + OH --> NO2                                                                      ",
     "         NO2 + OH --> HNO3                                                                     ",
     "         NO3 + OH --> HO2 + NO2                                                                ",
     "        HNO3 + OH --> NO3                                                                      ",
     "             HNO3 --> NO2 + OH                                                                 ",
     "          CO + OH --> HO2                                                                      ",
     "          O3 + OH --> HO2                                                                      ",
     "         HO2 + NO --> NO2 + OH                                                                 ",
     "        HO2 + NO2 --> HNO4                                                                     ",
     "             HNO4 --> HO2 + NO2                                                                ",
     "             HNO4 --> 0.61 HO2 + 0.61 NO2 + 0.39 NO3 + 0.39 OH                                 ",
     "        HNO4 + OH --> NO2                                                                      ",
     "         O3 + HO2 --> OH                                                                       ",
     "            2 HO2 --> H2O2                                                                     ",
     "      2 HO2 + H2O --> H2O2                                                                     ",
     "        HO2 + NO3 --> 0.2 HNO3 + 0.8 NO2 + 0.8 OH                                              ",
     "            2 NO3 --> 2 NO2                                                                    ",
     "             H2O2 --> 2 OH                                                                     ",
     "        H2O2 + OH --> HO2                                                                      ",
     "         HO2 + OH --> O2 + H2O                                                                 ",
     "         SO2 + OH --> H2SO4 + HO2                                                              ",
     "          OH + H2 --> HO2                                                                      ",
     "        C_O2 + NO --> HCHO + HO2 + NO2                                                         ",
     "       HO2 + C_O2 --> COOH                                                                     ",
     "       C_O2 + NO3 --> HCHO + HO2 + NO2                                                         ",
     "           2 C_O2 --> MEOH + HCHO                                                              ",
     "           2 C_O2 --> 2 HCHO + 2 HO2                                                           ",
     "       RO2_R + NO --> HO2 + NO2                                                                ",
     "      HO2 + RO2_R --> ROOH                                                                     ",
     "      RO2_R + NO3 --> HO2 + NO2                                                                ",
     "     C_O2 + RO2_R --> 0.25 MEOH + 0.75 HCHO + HO2                                              ",
     "          2 RO2_R --> HO2                                                                      ",
     "        R2O2 + NO --> NO2                                                                      ",
     "       R2O2 + HO2 --> HO2                                                                      ",
     "       R2O2 + NO3 --> NO2                                                                      ",
     "      R2O2 + C_O2 --> C_O2                                                                     ",
     "     R2O2 + RO2_R --> RO2_R                                                                    ",
     "           2 R2O2 --> 2 R2O2                                                                   ",
     "       RO2_N + NO --> RNO3                                                                     ",
     "      HO2 + RO2_N --> ROOH                                                                     ",
     "     RO2_N + C_O2 --> 0.25 MEOH + 0.75 HCHO + 0.5 MEK + 0.5 PROD2 + HO2                        ",
     "      RO2_N + NO3 --> MEK + HO2 + NO2                                                          ",
     "    RO2_N + RO2_R --> 0.5 MEK + 0.5 PROD2 + HO2                                                ",
     "     R2O2 + RO2_N --> RO2_N                                                                    ",
     "          2 RO2_N --> MEK + PROD2 + HO2                                                        ",
     "     NO2 + CCO_O2 --> PAN                                                                      ",
     "              PAN --> NO2 + CCO_O2                                                             ",
     "      NO + CCO_O2 --> C_O2 + NO2                                                               ",
     "     HO2 + CCO_O2 --> 0.25 CCO_OH + 0.75 CCO_OOH + 0.25 O3                                     ",
     "     NO3 + CCO_O2 --> C_O2 + NO2                                                               ",
     "    C_O2 + CCO_O2 --> CCO_OH + HCHO                                                            ",
     "   RO2_R + CCO_O2 --> CCO_OH                                                                   ",
     "    R2O2 + CCO_O2 --> CCO_O2                                                                   ",
     "   RO2_N + CCO_O2 --> CCO_OH + PROD2                                                           ",
     "         2 CCO_O2 --> 2 C_O2                                                                   ",
     "     NO2 + RCO_O2 --> PAN2                                                                     ",
     "             PAN2 --> NO2 + RCO_O2                                                             ",
     "      NO + RCO_O2 --> CCHO + RO2_R + NO2                                                       ",
     "     HO2 + RCO_O2 --> 0.25 RCO_OH + 0.75 RCO_OOH + 0.25 O3                                     ",
     "     NO3 + RCO_O2 --> CCHO + RO2_R + NO2                                                       ",
     "    C_O2 + RCO_O2 --> RCO_OH + HCHO                                                            ",
     "   RO2_R + RCO_O2 --> RCO_OH                                                                   ",
     "    R2O2 + RCO_O2 --> RCO_O2                                                                   ",
     "   RO2_N + RCO_O2 --> RCO_OH + PROD2                                                           ",
     "  CCO_O2 + RCO_O2 --> CCHO + C_O2 + RO2_R                                                      ",
     "         2 RCO_O2 --> 2 CCHO + 2 RO2_R                                                         ",
     "    BZCO_O2 + NO2 --> PBZN                                                                     ",
     "             PBZN --> BZCO_O2 + NO2                                                            ",
     "     BZCO_O2 + NO --> BZ_O + R2O2 + NO2                                                        ",
     "    HO2 + BZCO_O2 --> 0.25 RCO_OH + 0.75 RCO_OOH + 0.25 O3                                     ",
     "    BZCO_O2 + NO3 --> BZ_O + R2O2 + NO2                                                        ",
     "   C_O2 + BZCO_O2 --> RCO_OH + HCHO                                                            ",
     "  BZCO_O2 + RO2_R --> RCO_OH                                                                   ",
     "   R2O2 + BZCO_O2 --> BZCO_O2                                                                  ",
     "  RO2_N + BZCO_O2 --> RCO_OH + PROD2                                                           ",
     " BZCO_O2 + CCO_O2 --> BZ_O + R2O2 + C_O2                                                       ",
     " BZCO_O2 + RCO_O2 --> BZ_O + R2O2 + CCHO + RO2_R                                               ",
     "        2 BZCO_O2 --> 2 BZ_O + 2 R2O2                                                          ",
     "    MA_RCO3 + NO2 --> MA_PAN                                                                   ",
     "           MA_PAN --> MA_RCO3 + NO2                                                            ",
     "     MA_RCO3 + NO --> HCHO + NO2 + CCO_O2                                                      ",
     "    HO2 + MA_RCO3 --> 0.25 RCO_OH + 0.75 RCO_OOH + 0.25 O3                                     ",
     "    MA_RCO3 + NO3 --> HCHO + NO2 + CCO_O2                                                      ",
     "   MA_RCO3 + C_O2 --> RCO_OH + HCHO                                                            ",
     "  MA_RCO3 + RO2_R --> RCO_OH                                                                   ",
     "   R2O2 + MA_RCO3 --> MA_RCO3                                                                  ",
     "  RO2_N + MA_RCO3 --> 2 RCO_OH                                                                 ",
     " MA_RCO3 + CCO_O2 --> HCHO + C_O2 + CCO_O2                                                     ",
     " MA_RCO3 + RCO_O2 --> CCHO + HCHO + RO2_R + CCO_O2                                             ",
     "MA_RCO3 + BZCO_O2 --> BZ_O + R2O2 + HCHO + CCO_O2                                              ",
     "        2 MA_RCO3 --> 2 HCHO + 2 CCO_O2                                                        ",
     "      TBU_O + NO2 --> RNO3                                                                     ",
     "            TBU_O --> ACET + C_O2                                                              ",
     "       BZ_O + NO2 --> NPHE                                                                     ",
     "       BZ_O + HO2 --> PHEN                                                                     ",
     "             BZ_O --> PHEN                                                                     ",
     "    BZNO2_O + NO2 --> 2 XN + 6 XC                                                              ",
     "    BZNO2_O + HO2 --> NPHE                                                                     ",
     "          BZNO2_O --> NPHE                                                                     ",
     "             HCHO --> CO + 2 HO2                                                               ",
     "             HCHO --> CO                                                                       ",
     "        HCHO + OH --> CO + HO2                                                                 ",
     "       HCHO + HO2 --> HOCOO                                                                    ",
     "            HOCOO --> HCHO + HO2                                                               ",
     "       HOCOO + NO --> HCOOH + HO2 + NO2                                                        ",
     "       HCHO + NO3 --> CO + HNO3 + HO2                                                          ",
     "        CCHO + OH --> CCO_O2                                                                   ",
     "             CCHO --> CO + HO2 + C_O2                                                          ",
     "       CCHO + NO3 --> HNO3 + CCO_O2                                                            ",
     "        RCHO + OH --> 0.034 CO + 0.034 CCHO + 0.001 RO2_N + 0.034 RO2_R + 0.965 RCO_O2 ... etc.",
     "             RCHO --> CO + CCHO + HO2 + RO2_R                                                  ",
     "       RCHO + NO3 --> HNO3 + RCO_O2                                                            ",
     "        ACET + OH --> R2O2 + HCHO + CCO_O2                                                     ",
     "             ACET --> C_O2 + CCO_O2                                                            ",
     "         MEK + OH --> 0.616 R2O2 + 0.482 CCHO + 0.115 HCHO + 0.37 RCHO + 0.042 RO2_N ... etc.  ",
     "              MEK --> CCHO + RO2_R + CCO_O2                                                    ",
     "        MEOH + OH --> HCHO + HO2                                                               ",
     "        COOH + OH --> 0.35 HCHO + 0.65 C_O2 + 0.35 OH                                          ",
     "             COOH --> HCHO + HO2 + OH                                                          ",
     "        ROOH + OH --> RCHO + 0.34 RO2_R + 0.66 OH                                              ",
     "             ROOH --> RCHO + HO2 + OH                                                          ",
     "              GLY --> 2 CO + 2 HO2                                                             ",
     "              GLY --> CO + HCHO                                                                ",
     "         GLY + OH --> 1.26 CO + 0.63 HO2 + 0.37 RCO_O2                                         ",
     "        GLY + NO3 --> 1.26 CO + HNO3 + 0.63 HO2 + 0.37 RCO_O2                                  ",
     "             MGLY --> CO + HO2 + CCO_O2                                                        ",
     "        MGLY + OH --> CO + CCO_O2                                                              ",
     "       MGLY + NO3 --> CO + HNO3 + CCO_O2                                                       ",
     "             BACL --> 2 CCO_O2                                                                 ",
     "        PHEN + OH --> 0.23 GLY + 0.24 BZ_O + 0.76 RO2_R                                        ",
     "       PHEN + NO3 --> HNO3 + BZ_O                                                              ",
     "        CRES + OH --> 0.23 MGLY + 0.24 BZ_O + 0.76 RO2_R                                       ",
     "       CRES + NO3 --> HNO3 + BZ_O                                                              ",
     "       NPHE + NO3 --> BZNO2_O + HNO3                                                           ",
     "        BALD + OH --> BZCO_O2                                                                  ",
     "             BALD --> 7 XC                                                                     ",
     "       BALD + NO3 --> HNO3 + BZCO_O2                                                           ",
     "    METHACRO + OH --> 0.416 CO + 0.084 MGLY + 0.084 HCHO + 0.416 MEK + 0.5 MA_RCO3 ... etc.    ",
     "    METHACRO + O3 --> 0.333 HCOOH + 0.45 CO + 0.9 MGLY + 0.2 HCHO + 0.008 HO2 ... etc.         ",
     "   METHACRO + NO3 --> 0.5 CO + 0.5 HNO3 + 0.5 MA_RCO3 + 0.5 RO2_R                              ",
     "   METHACRO + O3P --> RCHO                                                                     ",
     "         METHACRO --> 0.67 CO + 0.67 HCHO + 0.34 HO2 + 0.33 MA_RCO3 + 0.33 RO2_R ... etc.      ",
     "         MVK + OH --> 0.3 MGLY + 0.675 R2O2 + 0.3 HCHO + 0.675 RCHO + 0.025 RO2_N ... etc.     ",
     "         MVK + O3 --> 0.351 HCOOH + 0.475 CO + 0.95 MGLY + 0.1 HCHO + 0.064 HO2 ... etc.       ",
     "        MVK + O3P --> 0.45 RCHO + 0.55 MEK                                                     ",
     "              MVK --> 0.7 CO + 0.7 PROD2 + 0.3 MA_RCO3 + 0.3 C_O2                              ",
     "     ISOPROD + OH --> 0.336 CO + 0.174 MGLY + 0.15 GLY + 0.129 CCHO + 0.055 HCHO ... etc.      ",
     "     ISOPROD + O3 --> 0.1 HCOOH + 0.372 RCO_OH + 0.498 CO + 0.742 MGLY + 0.023 GLY ... etc.    ",
     "    ISOPROD + NO3 --> 0.572 CO + 0.008 MGLY + 0.15 HNO3 + 0.227 HCHO + 0.572 RNO3 ... etc.     ",
     "          ISOPROD --> 1.233 CO + 0.467 CCHO + 0.3 HCHO + 0.233 MEK + 1.233 HO2 ... etc.        ",
     "       PROD2 + OH --> 0.084 CCHO + 0.213 HCHO + 0.558 RCHO + 0.115 MEK + 0.329 PROD2 ... etc.  ",
     "            PROD2 --> 0.515 R2O2 + 0.246 CCHO + 0.506 HCHO + 0.71 RCHO + 0.04 RO2_N ... etc.   ",
     "        RNO3 + OH --> 0.006 ACET + 0.596 R2O2 + 0.439 CCHO + 0.01 HCHO + 0.31 RNO3 ... etc.    ",
     "             RNO3 --> 0.02 ACET + 0.152 R2O2 + 0.431 CCHO + 0.134 HCHO + 0.147 RCHO ... etc.   ",
     "        DCB1 + OH --> CO + RCHO + RO2_R                                                        ",
     "        DCB1 + O3 --> 1.5 CO + GLY + 1.5 HO2 + 0.5 OH                                          ",
     "        DCB2 + OH --> R2O2 + RCHO + CCO_O2                                                     ",
     "             DCB2 --> CO + 0.5 MGLY + 0.5 GLY + R2O2 + 0.5 HO2 + RO2_R + 0.5 CCO_O2 ... etc.   ",
     "        DCB3 + OH --> R2O2 + RCHO + CCO_O2                                                     ",
     "             DCB3 --> CO + 0.5 MGLY + 0.5 GLY + R2O2 + 0.5 HO2 + RO2_R + 0.5 CCO_O2 ... etc.   ",
     "         OH + CH4 --> C_O2                                                                     ",
     "      ETHENE + OH --> 0.195 CCHO + 1.61 HCHO + RO2_R                                           ",
     "      ETHENE + O3 --> 0.37 HCOOH + 0.5 CO + HCHO + 0.12 HO2 + 0.12 OH                          ",
     "     ETHENE + NO3 --> RCHO + RO2_R                                                             ",
     "     ETHENE + O3P --> 0.491 CO + 0.009 GLY + 0.25 CCHO + 0.191 HCHO + 0.5 HO2 ... etc.         ",
     "    ISOPRENE + OH --> 0.079 R2O2 + 0.23 METHACRO + 0.357 ISOPROD + 0.32 MVK ... etc.           ",
     "    ISOPRENE + O3 --> 0.204 HCOOH + 0.15 RCO_OH + 0.275 CO + 0.126 R2O2 + 0.39 METHACRO ... etc.",
     "   ISOPRENE + NO3 --> 0.187 R2O2 + 0.936 ISOPROD + 0.064 RO2_N + 0.749 RO2_R ... etc.          ",
     "   ISOPRENE + O3P --> 0.24 R2O2 + 0.24 HCHO + 0.75 PROD2 + 0.01 RO2_N + 0.24 MA_RCO3 ... etc.  ",
     "        TERP + OH --> 0.5 R2O2 + 0.276 HCHO + 0.474 RCHO + 0.276 PROD2 + 0.25 RO2_N ... etc.   ",
     "        TERP + O3 --> 0.103 HCOOH + 0.189 RCO_OH + 0.031 BACL + 0.157 CO + 0.13 ACET ... etc.  ",
     "       TERP + NO3 --> 0.75 R2O2 + 0.276 RNO3 + 0.474 RCHO + 0.25 RO2_N + 0.276 RO2_R ... etc.  ",
     "       TERP + O3P --> 0.147 RCHO + 0.853 PROD2                                                 ",
     "        ALK1 + OH --> CCHO + RO2_R                                                             ",
     "        ALK2 + OH --> 0.121 HCOOH + 0.16 CO + 0.417 ACET + 0.248 GLY + 0.039 HCHO ... etc.     ",
     "        ALK3 + OH --> 0.236 TBU_O + 0.024 ACET + 0.559 R2O2 + 0.445 CCHO + 0.026 HCHO ... etc. ",
     "        ALK4 + OH --> 0.002 CO + 0.452 ACET + 0.936 R2O2 + 0.455 CCHO + 0.024 HCHO ... etc.    ",
     "        ALK5 + OH --> 0.072 ACET + 0.948 R2O2 + 0.099 CCHO + 0.026 HCHO + 0.204 RCHO ... etc.  ",
     "        ARO1 + OH --> 0.108 DCB2 + 0.051 DCB3 + 0.207 CRES + 0.491 DCB1 + 0.059 BALD ... etc.  ",
     "        ARO2 + OH --> 0.087 BACL + 0.099 DCB2 + 0.093 DCB3 + 0.187 CRES + 0.561 DCB1 ... etc.  ",
     "        OLE1 + OH --> 0.005 ACET + 0.205 R2O2 + 0.294 CCHO + 0.732 HCHO + 0.497 RCHO ... etc.  ",
     "        OLE1 + O3 --> 0.185 HCOOH + 0.05 CCO_OH + 0.119 RCO_OH + 0.345 CO ... etc.             ",
     "       OLE1 + NO3 --> 0.024 ACET + 0.488 R2O2 + 0.009 CCHO + 0.511 RNO3 + 0.037 RCHO ... etc.  ",
     "       OLE1 + O3P --> 0.45 RCHO + 0.437 MEK + 0.113 PROD2                                      ",
     "        OLE2 + OH --> 0.061 BALD + 0.127 ACET + 0.001 R2O2 + 0.025 METHACRO ... etc.           ",
     "        OLE2 + O3 --> 0.073 HCOOH + 0.129 CCO_OH + 0.247 RCO_OH + 0.042 BALD ... etc.          ",
     "       OLE2 + NO3 --> 0.015 BALD + 0.102 ACET + 0.711 R2O2 + 0.048 MVK + 0.507 CCHO ... etc.   ",
     "       OLE2 + O3P --> 0.012 CO + 0.012 METHACRO + 0.069 RCHO + 0.659 MEK + 0.259 PROD2 ... etc."
      }; 


/* INLINED global variables                                         */

/* End INLINED global variables                                     */

