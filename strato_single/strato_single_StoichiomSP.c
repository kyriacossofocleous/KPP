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
/* File                 : strato_single_StoichiomSP.c               */
/* Time                 : Thu Jan 27 10:54:15 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_single */
/* Equation file        : strato_single.kpp                         */
/* Output root filename : strato_single                             */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strato_single_Parameters.h"
#include "strato_single_Global.h"
#include "strato_single_Sparse.h"



/* Row-compressed sparse data for the Jacobian of reaction products JVRP */
 /* Beginning of rows in JVRP */

  int  CROW_JVRP[] = {
       0,  1,  3,  4,  5,  7,  8,  9, 10, 11, 12, 14,
      15, 17, 19, 20, 22, 24, 26, 28, 29, 30, 32, 34,
      36, 38, 40, 42, 44, 46, 48, 50, 51, 53, 55, 56,
      57, 58, 60, 61, 63, 65, 67, 69, 71, 73, 75, 77,
      79, 80, 81, 82, 83, 84, 85, 87, 89, 91, 93, 95,
      96, 98,100,102,104,106,108,110,112,114,116,117,
     119,120,121,123,125,126,128,129,130,131,133,135,
     137,137,138,139,140,141,142,143,144,145,146,147,
     148,149,150,151,152,153,154,155,156,157,158,159,
     160,161 }; 

 /* Column indices in JVRP */

  int  ICOL_JVRP[] = {
      31, 28, 31, 10, 10, 10, 28, 10, 10, 10, 10, 19,
      19, 28, 25, 25, 28, 25, 31, 25, 31, 32, 28, 32,
      19, 32, 25, 32, 32, 32, 16, 25, 28, 29, 29, 32,
      31, 33, 28, 33, 25, 33, 32, 33, 22, 31, 22, 29,
      22, 33, 11, 18, 25, 14, 25, 14, 11, 26, 26, 28,
      26, 26, 32, 26, 32, 16, 26, 27, 31, 25, 27, 25,
      27, 27, 32, 27, 29, 27, 33, 27, 27, 27, 27,  3,
       2, 15, 25, 17, 25, 21, 31, 21, 25, 21, 26, 21,
      24, 28, 24, 32, 23, 24, 30, 31, 30, 32, 29, 30,
      30, 33, 27, 30, 27, 30, 27, 30, 30, 12, 25, 25,
      25, 23, 25, 23, 31, 26, 23, 26,  8,  0,  9, 20,
      29, 20, 32, 13, 25, 28, 28, 32, 16, 33, 22, 22,
      11, 18, 14, 14,  1,  4,  2, 17, 21, 21,  5, 30,
       6,  7, 23, 23, 13 }; 

 /* Row indices in JVRP */

  int  IROW_JVRP[] = {
       0,  1,  1,  2,  3,  4,  4,  5,  6,  7,  8,  9,
      10, 10, 11, 12, 12, 13, 13, 14, 15, 15, 16, 16,
      17, 17, 18, 18, 19, 20, 21, 21, 22, 22, 23, 23,
      24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29,
      30, 30, 31, 32, 32, 33, 33, 34, 35, 36, 37, 37,
      38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44,
      44, 45, 45, 46, 46, 47, 47, 48, 49, 50, 51, 52,
      53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59,
      60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65,
      66, 66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72,
      73, 74, 74, 75, 75, 76, 77, 77, 78, 79, 80, 81,
      81, 82, 82, 83, 83, 85, 86, 87, 88, 89, 90, 91,
      92, 93, 94, 95, 96, 97, 98, 99,100,101,102,103,
     104,105,106,107,108 }; 




/*  Stoichiometric Matrix in Compressed Column Sparse Format        */

 /* Beginning of columns in STOICM */

  int  CCOL_STOICM[] = {
       0,  2,  4,  6,  8, 10, 12, 15, 17, 20, 22, 25,
      27, 30, 33, 35, 38, 41, 44, 46, 48, 50, 53, 56,
      60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93,
      95, 97,100,103,106,110,114,117,121,124,127,131,
     134,137,140,142,144,146,148,151,154,158,162,166,
     169,172,175,179,182,185,189,192,196,200,203,205,
     208,210,212,215,219,222,226,228,230,233,237,240,
     243,244,246,248,251,253,256,259,261,264,267,270,
     273,275,278,281,284,287,291,294,297,300,303,306,
     307,310 }; 

 /* Row indices in STOICM */

  int  IROW_STOICM[] = {
      28, 31, 28, 31, 10, 31, 10, 31, 10, 28, 10, 25,
      10, 19, 25, 10, 23,  0, 10, 25, 19, 32, 19, 25,
      28, 19, 25, 25, 28, 32, 19, 25, 31, 25, 31, 25,
      31, 32, 25, 28, 32, 19, 25, 32, 25, 32, 16, 32,
      16, 32, 16, 25, 32, 28, 29, 33, 25, 29, 32, 33,
      29, 31, 33, 22, 28, 33, 18, 25, 33, 14, 32, 33,
      22, 31, 33, 22, 29, 33, 11, 22, 33, 11, 22, 33,
      18, 22, 25, 14, 25, 33, 14, 32, 33, 11, 18,  3,
      26, 26, 27, 28, 15, 19, 26, 15, 26, 32, 25, 26,
      27, 32, 15, 16, 26, 32, 26, 27, 31, 25, 26, 27,
      32, 15, 25, 27, 17, 27, 32, 26, 27, 29, 33, 21,
      27, 33,  4, 26, 27,  3, 26, 27,  1, 27,  2, 27,
       3, 26,  2, 27, 15, 25, 26, 17, 25, 27, 21, 22,
      27, 31, 17, 21, 22, 25,  1, 21, 22, 26, 17, 18,
      21, 24, 28, 30, 12, 24, 32,  8, 12, 23, 24, 24,
      30, 31,  6, 30, 32, 24, 29, 30, 33,  7, 30, 33,
       4, 24, 27, 30,  3, 24, 27, 30,  5, 27, 30, 24,
      30, 12, 24, 25, 19, 25,  0, 25,  8, 23, 25,  8,
      23, 25, 31,  0, 15, 26,  8, 15, 23, 26,  8, 32,
       0, 20,  9, 23, 32,  9, 20, 29, 33, 13, 20, 32,
      13, 20, 25, 31, 28, 31, 10, 28, 25, 31, 32, 16,
      25, 29, 31, 33, 22, 31, 33, 22, 29, 11, 22, 33,
      18, 25, 33, 14, 22, 25, 14, 32, 33,  1, 26,  4,
      27, 31,  2,  3, 26, 17, 25, 26, 21, 22, 26, 21,
      26, 31, 33,  5, 24, 26, 24, 30, 31,  6, 24, 25,
       7, 22, 24,  8, 19, 23, 23,  9, 13, 25 }; 

 /* Column indices in STOICM */

  int  ICOL_STOICM[] = {
       0,  0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,
       6,  6,  6,  7,  7,  8,  8,  8,  9,  9, 10, 10,
      10, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 15,
      15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 19, 19,
      20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 23,
      24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27,
      28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31,
      32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 36,
      36, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 40,
      40, 40, 41, 41, 41, 41, 42, 42, 42, 43, 43, 43,
      43, 44, 44, 44, 45, 45, 45, 46, 46, 46, 46, 47,
      47, 47, 48, 48, 48, 49, 49, 49, 50, 50, 51, 51,
      52, 52, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56,
      56, 56, 57, 57, 57, 57, 58, 58, 58, 58, 59, 59,
      59, 60, 60, 60, 61, 61, 61, 62, 62, 62, 62, 63,
      63, 63, 64, 64, 64, 65, 65, 65, 65, 66, 66, 66,
      67, 67, 67, 67, 68, 68, 68, 68, 69, 69, 69, 70,
      70, 71, 71, 71, 72, 72, 73, 73, 74, 74, 74, 75,
      75, 75, 75, 76, 76, 76, 77, 77, 77, 77, 78, 78,
      79, 79, 80, 80, 80, 81, 81, 81, 81, 82, 82, 82,
      83, 83, 83, 84, 85, 85, 86, 86, 87, 87, 87, 88,
      88, 89, 89, 89, 90, 90, 90, 91, 91, 92, 92, 92,
      93, 93, 93, 94, 94, 94, 95, 95, 95, 96, 96, 97,
      97, 97, 98, 98, 98, 99, 99, 99,100,100,100,101,
     101,101,101,102,102,102,103,103,103,104,104,104,
     105,105,105,106,106,106,107,108,108,108 }; 

 /* Stoichiometric Matrix in compressed column format */

  float  STOICM[] = {
         1,   -1,   -1,   -1,   -1,    1,   -1,    1,
        -1,   -1,   -1,    2,   -1,    1,    1,   -1,
         1,    1,   -1,    1,   -1,    1,   -1,    1,
        -1,    1,   -1,   -1,   -1,    1,    1,   -1,
        -1,   -2,    1,    1,   -1,   -1,    1,   -1,
        -1,   -1,    2,   -1,   -1,   -1,    1,   -2,
         1,   -2,   -1,   -1,    1,   -1,   -1,    1,
         1,   -1,   -1,    1,    1,   -1,   -1,    1,
        -1,   -1,    1,   -1,   -1,    1,   -1,   -1,
        -1,   -1,    1,   -1,   -1,    2,    1,   -1,
        -1,   -1,    1,    1,   -1,    1,   -1,   -1,
        -1,    1,   -1,    1,    1,   -1,    2,    1,
        -1,   -1,    1,   -1,    1,    1,   -1,    1,
        -1,   -1,    1,   -1,    1,   -1,    1,   -1,
        -1,    1,    1,   -1,   -1,   -1,    1,   -1,
         1,    1,   -1,   -1,    1,   -1,   -1,    1,
        -1,   -1,    1,    1,   -1,   -1,    1,    1,
        -2,    1,    1,   -2,    1,   -2,    1,   -2,
        -1,    1,   -1,    2,   -1,   -1,    1,   -1,
        -1,    1,   -1,    1,    1,   -1,    1,   -1,
         1,   -1,    1,   -1,    1,   -1,    1,    1,
        -1,   -1,   -1,    1,    1,   -1,   -1,    1,
         1,   -1,   -1,    1,   -1,   -1,    1,   -1,
        -1,    1,   -1,   -1,    1,    1,   -1,   -1,
         1,    1,   -1,   -1,    1,    1,   -1,   -1,
         1,   -1,   -1,    2,   -2,   -1,    1,   -1,
         1,   -1,    1,   -1,    1,   -1,   -1,    1,
        -1,    1,   -1,    1,    1,   -1,    1,    1,
        -1,   -1,   -1,    1,   -1,    1,   -1,    1,
         1,    1,   -1,   -1,    1,    1,   -1,   -1,
        -1,    1,   -1,    2,   -1,    1,    1,   -1,
         1,    1,   -1,   -1,    2,    1,    1,   -1,
        -1,    1,    1,   -1,    1,   -1,    1,    1,
        -1,    1,    1,   -1,    1,    1,   -1,    1,
         1,   -1,    2,   -1,    1,    1,   -1,    1,
         1,   -1,    1,    1,   -1,    1,    1,   -1,
         1,    1,    1,   -1,    1,    1,    1,   -1,
         1,   -1,    1,    1,   -1,    1,    1,    1,
         1,   -1,   -1,    1,   -1,    1 }; 

