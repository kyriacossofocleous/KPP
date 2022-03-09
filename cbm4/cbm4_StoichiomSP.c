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
/* File                 : cbm4_StoichiomSP.c                        */
/* Time                 : Wed Mar  9 12:16:40 2022                  */
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
#include "cbm4_Parameters.h"
#include "cbm4_Global.h"
#include "cbm4_Sparse.h"



/* Row-compressed sparse data for the Jacobian of reaction products JVRP */
 /* Beginning of rows in JVRP */

  int  CROW_JVRP[] = {
       0,  1,  2,  4,  6,  8, 10, 12, 13, 14, 15, 16,
      18, 20, 21, 23, 25, 27, 28, 29, 30, 32, 34, 35,
      37, 38, 40, 42, 44, 46, 47, 49, 50, 51, 52, 54,
      56, 58, 59, 60, 62, 64, 66, 68, 70, 71, 73, 75,
      76, 77, 79, 80, 82, 83, 84, 86, 88, 90, 92, 94,
      96, 98,100,102,104,105,107,109,111,113,115,116,
     118,120,121,123,125,127,129,131,132,134 }; 

 /* Column indices in JVRP */

  int  ICOL_JVRP[] = {
      25, 28, 24, 30, 25, 28, 25, 28, 28, 30, 24, 25,
      24, 24,  0,  0, 24, 26, 24, 27, 29, 29, 30, 25,
      29, 25, 29,  5,  5, 30, 25, 30, 26, 30,  8,  8,
      26,  8, 25, 26, 11, 26, 27, 30, 25, 27,  9,  9,
      26, 27, 27,  1,  1, 26, 15, 26, 20, 26, 20, 20,
      20, 28, 20, 29, 23, 28, 23, 26, 23, 29, 23, 30,
      31, 25, 31,  2, 31, 27, 31, 26, 19, 26, 12, 12,
      12, 25, 22, 28, 22, 26, 22, 24, 22, 29, 16, 28,
      16, 26, 16, 24,  4, 26, 10, 30, 10, 13, 26, 13,
      29,  3, 25,  6, 26, 18, 26, 18, 18, 24, 14, 26,
      14, 21, 28, 21, 26, 21, 24, 21, 29, 17, 30, 17,
       7, 30 }; 

 /* Row indices in JVRP */

  int  IROW_JVRP[] = {
       0,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,
       7,  8,  9, 10, 11, 11, 12, 12, 13, 14, 14, 15,
      15, 16, 16, 17, 18, 19, 20, 20, 21, 21, 22, 23,
      23, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 30,
      30, 31, 32, 33, 34, 34, 35, 35, 36, 36, 37, 38,
      39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 45,
      45, 46, 46, 47, 48, 49, 49, 50, 51, 51, 52, 53,
      54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59,
      60, 60, 61, 61, 62, 62, 63, 63, 64, 65, 65, 66,
      66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72,
      73, 74, 74, 75, 75, 76, 76, 77, 77, 78, 78, 79,
      80, 80 }; 




/*  Stoichiometric Matrix in Compressed Column Sparse Format        */

 /* Beginning of columns in STOICM */

  int  CCOL_STOICM[] = {
       0,  3,  5,  8, 11, 14, 17, 20, 22, 24, 26, 28,
      31, 34, 38, 41, 43, 46, 48, 51, 53, 56, 59, 62,
      65, 68, 71, 74, 78, 81, 84, 87, 89, 91, 93, 96,
      99,103,106,108,113,118,122,125,129,134,140,143,
     146,150,155,159,166,172,174,176,186,193,202,210,
     217,223,228,234,239,242,248,252,254,262,269,273,
     283,287,291,300,310,320,323,326,327,329 }; 

 /* Row indices in STOICM */

  int  IROW_STOICM[] = {
      25, 28, 30, 24, 28, 24, 25, 30, 25, 28, 30, 25,
      28, 29, 25, 28, 30, 24, 25, 29, 24, 28,  0, 24,
       0, 28,  0, 26, 24, 26, 27, 24, 26, 27, 25, 28,
      29, 30, 25, 29, 30, 29, 30,  5, 25, 29,  5, 11,
       5, 25, 29, 25, 30,  8, 25, 30,  8, 26, 30,  8,
      26, 30,  8, 25, 26,  8, 25, 30, 11, 25, 26, 11,
      26, 29, 25, 26, 27, 30,  9, 25, 27,  9, 25, 27,
       9, 25, 26,  1, 27,  1, 27,  1, 26,  1, 26, 27,
      15, 26, 27, 15, 20, 26, 27, 15, 20, 27, 15, 20,
      15, 20, 26, 27, 28, 11, 15, 20, 27, 29, 23, 26,
      28, 31, 23, 26, 31, 11, 23, 29, 31, 15, 17, 20,
      23, 27, 17, 20, 25, 27, 30, 31,  2, 25, 31,  2,
      25, 31, 17, 20, 27, 31, 17, 20, 26, 27, 31, 17,
      20, 26, 27,  7, 12, 17, 19, 23, 26, 27,  7, 12,
      17, 19, 23, 27, 12, 27, 12, 25,  7, 15, 17, 19,
      20, 22, 23, 26, 27, 28, 17, 19, 20, 22, 23, 26,
      27, 15, 17, 19, 20, 22, 23, 24, 26, 27,  7, 17,
      19, 20, 22, 23, 25, 29, 15, 16, 17, 20, 26, 27,
      28, 16, 17, 20, 23, 26, 27, 15, 16, 20, 24, 27,
       4, 10, 13, 17, 26, 27, 10, 18, 25, 27, 30, 10,
      13, 27,  3, 13, 17, 18, 26, 27,  3, 11, 13, 29,
       3, 25,  6, 10, 13, 14, 17, 19, 26, 27, 15, 17,
      18, 20, 26, 27, 31, 15, 18, 27, 31, 14, 15, 17,
      18, 20, 23, 24, 26, 27, 31, 14, 17, 26, 31, 14,
      15, 27, 31, 15, 16, 17, 19, 21, 22, 23, 27, 28,
       7, 14, 16, 17, 20, 21, 23, 26, 27, 31, 14, 15,
      16, 19, 20, 21, 23, 24, 26, 27,  7, 21, 29, 17,
      25, 30, 17,  7, 30 }; 

 /* Column indices in STOICM */

  int  ICOL_STOICM[] = {
       0,  0,  0,  1,  1,  2,  2,  2,  3,  3,  3,  4,
       4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  8,  8,
       9,  9, 10, 10, 11, 11, 11, 12, 12, 12, 13, 13,
      13, 13, 14, 14, 14, 15, 15, 16, 16, 16, 17, 17,
      18, 18, 18, 19, 19, 20, 20, 20, 21, 21, 21, 22,
      22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26,
      26, 26, 27, 27, 27, 27, 28, 28, 28, 29, 29, 29,
      30, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 34,
      35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 38, 38,
      39, 39, 39, 39, 39, 40, 40, 40, 40, 40, 41, 41,
      41, 41, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44,
      44, 44, 45, 45, 45, 45, 45, 45, 46, 46, 46, 47,
      47, 47, 48, 48, 48, 48, 49, 49, 49, 49, 49, 50,
      50, 50, 50, 51, 51, 51, 51, 51, 51, 51, 52, 52,
      52, 52, 52, 52, 53, 53, 54, 54, 55, 55, 55, 55,
      55, 55, 55, 55, 55, 55, 56, 56, 56, 56, 56, 56,
      56, 57, 57, 57, 57, 57, 57, 57, 57, 57, 58, 58,
      58, 58, 58, 58, 58, 58, 59, 59, 59, 59, 59, 59,
      59, 60, 60, 60, 60, 60, 60, 61, 61, 61, 61, 61,
      62, 62, 62, 62, 62, 62, 63, 63, 63, 63, 63, 64,
      64, 64, 65, 65, 65, 65, 65, 65, 66, 66, 66, 66,
      67, 67, 68, 68, 68, 68, 68, 68, 68, 68, 69, 69,
      69, 69, 69, 69, 69, 70, 70, 70, 70, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 72, 72, 72, 72, 73,
      73, 73, 73, 74, 74, 74, 74, 74, 74, 74, 74, 74,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 76, 76,
      76, 76, 76, 76, 76, 76, 76, 76, 77, 77, 77, 78,
      78, 78, 79, 80, 80 }; 

 /* Stoichiometric Matrix in compressed column format */

  double  STOICM[] = {
        -1,    1,    1,    1,   -1,   -1,    1,   -1,
        -1,   -1,    1,   -1,   -1,    1,    1,   -1,
        -1,   -1,   -1,    1,   -1,    1,    1,   -1,
        -1,    1,   -1,    2,   -1,   -1,    1,   -1,
         1,   -1, 0.89, 0.89,   -1, 0.11,    2,   -1,
        -1,   -1,    1,    1,   -1,   -1,   -1,    2,
        -1,    1,    1,    2,   -2,    2,   -1,   -1,
         1,   -1,   -1,   -1,    1,    1,   -1,    1,
        -1,   -2,    1,    1,    1,   -1,   -1,   -1,
        -1,    1,    1,    1,   -1,   -1,    1,   -1,
        -1,   -1,    1,    1,   -1,    1,   -1,    1,
        -2,    1,   -2,   -1,    2,   -1,   -1,    1,
        -1,   -1,    1,    1,   -1,   -1,    1,    1,
        -1,    2,    1,   -1,    1,   -1,    1,    1,
        -1,    1,    1,   -1,    1,   -1,   -1,    1,
        -1,    1,   -1,   -1,    1,    1,   -1,   -1,
         1,    1,    1,    1,   -1,    2,    1,    1,
         1,    1,   -1,   -1,    1,   -1,   -1,   -1,
         1,    1,    2,    2,    2,   -2, 0.79, 0.79,
      0.79,-0.21,   -1,    1,    1,   -1,    1, 0.13,
      0.76, 0.87,-1.11, 0.11,   -1, 0.11, 0.04,-0.98,
      0.96, -2.1,  1.1, 0.94,   -1,    1,   -1,   -1,
      0.02,  0.3, 0.28, 0.22,  0.2,   -1, 0.63,  0.2,
      0.38,   -1,    1,   -1,    1,   -1,    1,   -1,
         1, 0.33, 0.22,   -1, 0.74,   -1,  0.5,   -1,
       0.1, 0.44, 0.09, 0.91,   -1,    1,   -1,    1,
         1,   -1,    1,   -1,  0.7,    1,  0.3,  1.7,
        -1,   -1,    1, 1.56, 0.22,   -1,    1, 0.42,
        -1,    1,   -1, 0.12,   -1, 0.56, 0.36, 0.08,
        -1, 0.44,   -1,  0.9,  0.9,  0.9,   -1,   -1,
         1,    1,  0.4,   -1,  0.6,  0.3,   -1,  0.6,
         1,    1,   -1,   -1,   -1,   -1,   -1,  0.3,
       0.2,  0.8,  0.5,  1.1,   -1,  0.7,    2,    1,
        -1,    1,   -1,    2,    1,    1,   -1,    1,
         1,  0.2, 0.69, 0.03,   -1,  0.7, 0.03,   -1,
      0.08, 0.76, 0.62,   -1,    1,   -1,    1,   -1,
         1,    1,    1,  0.5, 0.45,  0.5,  0.9,   -1,
      0.55,  0.8,  0.6,   -1, 0.13,  0.4,    1,    1,
         1,   -1,  0.2,   -1, 0.67,  0.2,  0.2, 0.06,
      0.55,  0.1,    1,   -1,  0.4,   -1,  0.1, 0.44,
         1,   -1,   -1,   -1,    1,   -1,   -2,   -1,
        -1 }; 


