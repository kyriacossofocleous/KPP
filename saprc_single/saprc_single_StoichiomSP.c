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
/* File                 : saprc_single_StoichiomSP.c                */
/* Time                 : Thu Jan 27 12:39:25 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc_single */
/* Equation file        : saprc_single.kpp                          */
/* Output root filename : saprc_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "saprc_single_Parameters.h"
#include "saprc_single_Global.h"
#include "saprc_single_Sparse.h"



/* Row-compressed sparse data for the Jacobian of reaction products JVRP */
 /* Beginning of rows in JVRP */

  int  CROW_JVRP[] = {
       0,  1,  2,  4,  6,  8, 10, 12, 14, 16, 17, 19,
      20, 21, 23, 24, 25, 26, 27, 28, 29, 31, 32, 33,
      35, 37, 39, 41, 42, 44, 46, 48, 50, 51, 52, 54,
      56, 57, 58, 60, 61, 62, 64, 66, 68, 69, 71, 73,
      75, 76, 77, 79, 81, 83, 85, 86, 88, 90, 92, 94,
      96, 97, 99,101,103,105,107,109,110,112,113,115,
     117,119,121,123,125,127,128,130,131,133,135,137,
     139,141,143,145,147,148,150,151,153,155,157,159,
     161,163,165,167,169,170,172,173,175,177,179,181,
     183,185,187,189,191,193,194,196,197,199,201,202,
     204,206,207,208,209,211,213,214,216,218,220,221,
     223,225,226,228,230,231,233,234,236,238,239,241,
     242,243,244,246,248,249,251,253,254,256,258,260,
     262,264,266,267,269,271,273,275,277,278,280,282,
     284,285,287,289,291,292,294,295,297,298,300,302,
     304,305,307,308,309,311,313,315,317,319,321,323,
     325,327,329,331,333,335,337,339,341,343,345,347,
     349,351,353,355,357,359,361,363 }; 

 /* Column indices in JVRP */

  int  ICOL_JVRP[] = {
      69, 57, 57, 61, 57, 68, 57, 69, 57, 69, 61, 68,
      61, 69, 68, 70, 68, 69, 70, 17, 17, 69, 70, 70,
      70, 61, 61,  9,  9, 68, 73, 18, 18, 18, 73, 69,
      73, 70, 73, 42, 73, 42, 39, 73, 61, 73, 62, 68,
      62, 69, 24, 24, 24, 73, 61, 62, 62, 62, 62, 70,
      70, 16, 16, 73, 62, 73,  8, 73, 73, 65, 68, 62,
      65, 65, 70, 65, 65, 67, 68, 62, 67, 67, 70, 65,
      67, 67, 47, 68, 47, 62, 47, 70, 47, 65, 47, 67,
      47, 63, 68, 62, 63, 63, 65, 63, 70, 63, 67, 47,
      63, 63, 69, 71, 12, 68, 71, 62, 71, 70, 71, 65,
      71, 67, 71, 47, 71, 63, 71, 71, 69, 72, 13, 68,
      72, 62, 72, 70, 72, 65, 72, 67, 72, 47, 72, 63,
      72, 71, 72, 72, 66, 69, 14, 66, 68, 62, 66, 66,
      70, 65, 66, 66, 67, 47, 66, 63, 66, 66, 71, 66,
      72, 66, 64, 69, 15, 64, 68, 62, 64, 64, 70, 64,
      65, 64, 67, 47, 64, 63, 64, 64, 71, 64, 72, 64,
      66, 64, 21, 69, 21, 45, 69, 45, 62, 45, 27, 69,
      27, 62, 27, 55, 55, 55, 73, 55, 62, 26, 26, 68,
      55, 70, 54, 73, 54, 54, 70, 58, 73, 58, 58, 70,
      41, 73, 41, 59, 73, 59, 28, 73, 25, 73, 25, 36,
      73, 36, 44, 44, 44, 73, 44, 70, 40, 40, 73, 40,
      70, 11, 38, 73, 38, 70, 33, 73, 33, 70, 35, 70,
      37, 73, 37, 37, 70, 49, 73, 49, 61, 49, 70, 49,
      57, 49, 53, 73, 53, 61, 53, 57, 53, 51, 73, 51,
      61, 51, 70, 51, 60, 73, 60, 56, 73, 56, 34, 73,
      34, 61, 31, 73, 31, 32, 73, 32, 73, 43, 73, 43,
      61, 43, 70, 43, 57, 46, 73, 46, 61, 46, 70, 46,
      57, 48, 73, 48, 61, 48, 70, 48, 57, 10, 73, 19,
      73, 20, 73, 29, 73, 22, 73, 30, 73, 23, 73, 50,
      73, 50, 61, 50, 70, 50, 57, 52, 73, 52, 61, 52,
      70, 52, 57 }; 

 /* Row indices in JVRP */

  int  IROW_JVRP[] = {
       0,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,
       7,  7,  8,  8,  9, 10, 10, 11, 12, 13, 13, 14,
      15, 16, 17, 18, 19, 20, 20, 21, 22, 23, 23, 24,
      24, 25, 25, 26, 26, 27, 28, 28, 29, 29, 30, 30,
      31, 31, 32, 33, 34, 34, 35, 35, 36, 37, 38, 38,
      39, 40, 41, 41, 42, 42, 43, 43, 44, 45, 45, 46,
      46, 47, 47, 48, 49, 50, 50, 51, 51, 52, 52, 53,
      53, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59,
      60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66,
      66, 67, 68, 68, 69, 70, 70, 71, 71, 72, 72, 73,
      73, 74, 74, 75, 75, 76, 76, 77, 78, 78, 79, 80,
      80, 81, 81, 82, 82, 83, 83, 84, 84, 85, 85, 86,
      86, 87, 87, 88, 89, 89, 90, 91, 91, 92, 92, 93,
      93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99,
      99,100,101,101,102,103,103,104,104,105,105,106,
     106,107,107,108,108,109,109,110,110,111,111,112,
     112,113,114,114,115,116,116,117,117,118,119,119,
     120,120,121,122,123,124,124,125,125,126,127,127,
     128,128,129,129,130,131,131,132,132,133,134,134,
     135,135,136,137,137,138,139,139,140,140,141,142,
     142,143,144,145,146,146,147,147,148,149,149,150,
     150,151,152,152,153,153,154,154,155,155,156,156,
     157,157,158,159,159,160,160,161,161,162,162,163,
     163,164,165,165,166,166,167,167,168,169,169,170,
     170,171,171,172,173,173,174,175,175,176,177,177,
     178,178,179,179,180,181,181,182,183,184,184,185,
     185,186,186,187,187,188,188,189,189,190,190,191,
     191,192,192,193,193,194,194,195,195,196,196,197,
     197,198,198,199,199,200,200,201,201,202,202,203,
     203,204,204,205,205,206,206,207,207,208,208,209,
     209,210,210 }; 




/*  Stoichiometric Matrix in Compressed Column Sparse Format        */

 /* Beginning of columns in STOICM */

  int  CCOL_STOICM[] = {
       0,  3,  5,  7, 10, 13, 16, 19, 22, 25, 27, 30,
      33, 35, 37, 39, 42, 44, 46, 48, 50, 53, 56, 59,
      62, 65, 69, 72, 75, 78, 81, 85, 88, 91, 96, 99,
     102,104,106,111,113,115,118,120,124,126,131,134,
     139,142,145,149,152,156,161,163,166,167,170,171,
     172,172,175,178,185,190,195,196,200,203,206,210,
     215,219,223,226,227,231,233,236,239,244,249,254,
     258,261,262,266,271,274,277,280,285,290,295,299,
     302,303,307,312,318,321,324,327,332,337,342,346,
     349,350,353,356,362,368,371,374,377,380,383,385,
     389,392,394,397,399,403,406,409,414,419,422,426,
     430,437,442,446,451,454,464,468,472,476,480,484,
     488,491,494,499,505,509,513,518,520,525,529,534,
     538,542,545,547,551,559,569,575,578,586,595,605,
     609,614,627,641,652,660,671,680,693,705,710,716,
     721,729,734,742,744,749,756,760,769,778,792,799,
     807,815,833,841,845,849,860,871,885,896,910,923,
     933,949,958,963,976,999,1014,1024 }; 

 /* Row indices in STOICM */

  int  IROW_STOICM[] = {
      57, 68, 69, 57, 61, 57, 61, 57, 68, 69, 57, 68,
      69, 57, 69, 70, 61, 68, 69, 61, 69, 70, 68, 69,
      70, 68, 69, 17, 69, 70, 17, 69, 70, 17, 42, 68,
      70, 68, 70, 57, 69, 70, 57, 61,  9, 61,  9, 73,
       9, 57, 18, 68, 73, 18, 68, 73, 18, 62, 69, 18,
      69, 73, 42, 69, 73, 62, 69, 70, 73, 42, 70, 73,
      42, 69, 73, 39, 62, 73, 61, 62, 73, 62, 68, 69,
      73, 24, 62, 69, 24, 62, 69, 24, 62, 69, 70, 73,
      24, 69, 73, 61, 62, 73, 16, 62, 16, 62, 42, 62,
      69, 70, 73, 69, 70, 16, 73, 16, 62, 73, 62, 73,
       0,  8, 62, 73, 62, 73, 55, 62, 65, 68, 69, 25,
      62, 65, 55, 62, 65, 69, 70, 28, 55, 65, 55, 62,
      65, 62, 67, 68, 69, 36, 62, 67, 62, 67, 69, 70,
      28, 55, 62, 65, 67, 62, 67, 47, 68, 69, 47, 47,
      69, 70, 47, 47, 56, 63, 68, 36, 62, 63, 28, 55,
      59, 60, 62, 63, 65, 59, 62, 63, 69, 70, 59, 60,
      62, 63, 67, 47, 59, 60, 62, 63, 12, 69, 71, 12,
      69, 71, 65, 68, 69, 71,  2,  4, 61, 62, 71, 65,
      69, 70, 71,  2, 55, 65, 71,  2, 67, 71, 47,  2,
      60, 63, 71, 65, 71, 13, 69, 72, 13, 69, 72, 54,
      67, 68, 69, 72,  3,  5, 61, 62, 72, 54, 67, 69,
      70, 72,  3, 55, 65, 72,  3, 67, 72, 47,  3, 60,
      63, 72, 54, 65, 67, 71, 72, 54, 67, 72, 14, 66,
      69, 14, 66, 69, 45, 47, 66, 68, 69,  3,  5, 61,
      62, 66, 45, 47, 66, 69, 70,  3, 55, 65, 66,  3,
      66, 67, 47,  3, 60, 63, 66, 45, 47, 65, 66, 71,
      45, 47, 54, 66, 67, 72, 45, 47, 66, 15, 64, 69,
      15, 64, 69, 55, 64, 68, 69, 71,  3,  5, 61, 62,
      64, 55, 64, 69, 70, 71,  3, 55, 64, 65,  3, 64,
      67, 47,  3, 63, 64, 55, 64, 65, 54, 55, 64, 67,
      71, 72, 45, 47, 55, 64, 66, 71, 55, 64, 71, 21,
      56, 69, 21, 41, 65, 35, 45, 69, 38, 45, 62, 38,
      45,  6,  7, 27, 69, 27, 35, 62, 27, 35, 39, 55,
      62, 39, 55, 39, 55, 62, 73, 26, 55, 62, 26, 55,
      62,  1, 26, 62, 68, 69, 39, 42, 55, 62, 70, 54,
      71, 73, 39, 54, 62, 65, 42, 54, 70, 71, 39, 54,
      58, 63, 67, 72, 73, 39, 54, 58, 62, 67, 42, 58,
      70, 72, 41, 47, 55, 71, 73, 41, 65, 71, 47, 54,
      55, 58, 59, 63, 67, 71, 72, 73, 54, 59, 67, 71,
      28, 55, 62, 73, 25, 55, 65, 73, 25, 55, 62, 73,
      36, 58, 67, 73, 36, 58, 62, 73, 39, 44, 62, 39,
      44, 55, 39, 44, 62, 72, 73, 39, 42, 44, 62, 70,
      72, 39, 40, 62, 71, 39, 40, 71, 73, 39, 40, 42,
      70, 71, 11, 71, 38, 44, 45, 67, 73, 38, 42, 45,
      70, 33, 40, 45, 67, 73, 33, 42, 45, 70, 27, 35,
      42, 70, 37, 66, 73,  7, 37, 37, 42, 66, 70, 39,
      40, 49, 55, 59, 64, 67, 73,  1, 39, 40, 49, 55,
      61, 62, 67, 72, 73, 39, 42, 49, 64, 67, 70, 49,
      57, 58, 39, 49, 55, 62, 64, 67, 71, 73, 40, 47,
      53, 55, 58, 63, 67, 71, 73,  1, 39, 40, 53, 55,
      61, 62, 67, 72, 73, 53, 57, 58, 59, 39, 53, 60,
      64, 65, 39, 40, 44, 51, 54, 55, 58, 59, 60, 63,
      64, 67, 73,  1,  3, 39, 40, 44, 51, 54, 55, 59,
      61, 62, 67, 72, 73, 39, 40, 42, 51, 55, 56, 58,
      63, 64, 67, 70, 39, 51, 54, 55, 59, 62, 71, 72,
      54, 55, 58, 59, 60, 62, 63, 67, 71, 72, 73, 47,
      54, 55, 58, 60, 63, 67, 71, 72, 41, 47, 54, 55,
      56, 58, 59, 60, 62, 63, 67, 69, 73, 41, 47, 54,
      55, 56, 58, 59, 60, 62, 63, 67, 69, 34, 39, 58,
      67, 73, 34, 39, 44, 61, 62, 73, 31, 47, 58, 71,
      73, 31, 39, 40, 44, 47, 62, 67, 71, 32, 47, 58,
      71, 73, 32, 39, 40, 44, 47, 62, 67, 71, 65, 73,
      43, 54, 55, 67, 73,  1, 39, 43, 55, 61, 62, 73,
      43, 58, 67, 70, 39, 43, 44, 54, 55, 57, 62, 65,
      67, 46, 47, 49, 51, 53, 55, 63, 67, 73,  1,  3,
      39, 46, 47, 49, 53, 55, 60, 61, 63, 64, 67, 73,
      46, 47, 51, 63, 67, 69, 70, 46, 47, 55, 57, 60,
      63, 64, 65, 47, 48, 55, 58, 60, 63, 67, 73,  1,
       3, 11, 39, 41, 44, 47, 48, 55, 58, 60, 61, 62,
      63, 67, 71, 72, 73, 47, 48, 56, 58, 63, 67, 69,
      70, 48, 57, 58, 60, 10, 54, 67, 73,  1, 19, 39,
      41, 44, 55, 58, 62, 63, 67, 73, 20, 21, 41, 47,
      54, 55, 58, 59, 63, 67, 73, 29, 39, 41, 47, 54,
      55, 58, 59, 60, 63, 65, 67, 71, 73, 22, 41, 47,
      54, 55, 58, 59, 60, 63, 67, 73, 30, 31, 32, 33,
      34, 37, 38, 40, 44, 60, 62, 63, 67, 73, 11, 23,
      31, 32, 33, 34, 37, 40, 44, 62, 63, 67, 73, 41,
      47, 50, 54, 55, 58, 60, 63, 67, 73,  1,  2,  3,
      39, 41, 50, 54, 55, 58, 60, 61, 62, 63, 65, 67,
      73, 41, 47, 50, 54, 56, 58, 63, 67, 70, 50, 57,
      58, 59, 60, 37, 41, 47, 49, 51, 52, 54, 55, 58,
      59, 63, 67, 73,  1,  2,  3, 37, 39, 41, 47, 49,
      52, 53, 54, 55, 58, 59, 60, 61, 62, 63, 65, 67,
      71, 72, 73, 37, 41, 47, 52, 53, 54, 55, 56, 58,
      59, 63, 65, 67, 69, 70, 39, 49, 52, 57, 58, 59,
      60, 62, 63, 67 }; 

 /* Column indices in STOICM */

  int  ICOL_STOICM[] = {
       0,  0,  0,  1,  1,  2,  2,  3,  3,  3,  4,  4,
       4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,
       8,  9,  9, 10, 10, 10, 11, 11, 11, 12, 12, 13,
      13, 14, 14, 15, 15, 15, 16, 16, 17, 17, 18, 18,
      19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23,
      23, 23, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26,
      27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30,
      30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 33,
      34, 34, 34, 35, 35, 35, 36, 36, 37, 37, 38, 38,
      38, 38, 38, 39, 39, 40, 40, 41, 41, 41, 42, 42,
      43, 43, 43, 43, 44, 44, 45, 45, 45, 45, 45, 46,
      46, 46, 47, 47, 47, 47, 47, 48, 48, 48, 49, 49,
      49, 50, 50, 50, 50, 51, 51, 51, 52, 52, 52, 52,
      53, 53, 53, 53, 53, 54, 54, 55, 55, 55, 56, 57,
      57, 57, 58, 59, 61, 61, 61, 62, 62, 62, 63, 63,
      63, 63, 63, 63, 63, 64, 64, 64, 64, 64, 65, 65,
      65, 65, 65, 66, 67, 67, 67, 67, 68, 68, 68, 69,
      69, 69, 70, 70, 70, 70, 71, 71, 71, 71, 71, 72,
      72, 72, 72, 73, 73, 73, 73, 74, 74, 74, 75, 76,
      76, 76, 76, 77, 77, 78, 78, 78, 79, 79, 79, 80,
      80, 80, 80, 80, 81, 81, 81, 81, 81, 82, 82, 82,
      82, 82, 83, 83, 83, 83, 84, 84, 84, 85, 86, 86,
      86, 86, 87, 87, 87, 87, 87, 88, 88, 88, 89, 89,
      89, 90, 90, 90, 91, 91, 91, 91, 91, 92, 92, 92,
      92, 92, 93, 93, 93, 93, 93, 94, 94, 94, 94, 95,
      95, 95, 96, 97, 97, 97, 97, 98, 98, 98, 98, 98,
      99, 99, 99, 99, 99, 99,100,100,100,101,101,101,
     102,102,102,103,103,103,103,103,104,104,104,104,
     104,105,105,105,105,105,106,106,106,106,107,107,
     107,108,109,109,109,110,110,110,111,111,111,111,
     111,111,112,112,112,112,112,112,113,113,113,114,
     114,114,115,115,115,116,116,116,117,117,117,118,
     118,119,119,119,119,120,120,120,121,121,122,122,
     122,123,123,124,124,124,124,125,125,125,126,126,
     126,127,127,127,127,127,128,128,128,128,128,129,
     129,129,130,130,130,130,131,131,131,131,132,132,
     132,132,132,132,132,133,133,133,133,133,134,134,
     134,134,135,135,135,135,135,136,136,136,137,137,
     137,137,137,137,137,137,137,137,138,138,138,138,
     139,139,139,139,140,140,140,140,141,141,141,141,
     142,142,142,142,143,143,143,143,144,144,144,145,
     145,145,146,146,146,146,146,147,147,147,147,147,
     147,148,148,148,148,149,149,149,149,150,150,150,
     150,150,151,151,152,152,152,152,152,153,153,153,
     153,154,154,154,154,154,155,155,155,155,156,156,
     156,156,157,157,157,158,158,159,159,159,159,160,
     160,160,160,160,160,160,160,161,161,161,161,161,
     161,161,161,161,161,162,162,162,162,162,162,163,
     163,163,164,164,164,164,164,164,164,164,165,165,
     165,165,165,165,165,165,165,166,166,166,166,166,
     166,166,166,166,166,167,167,167,167,168,168,168,
     168,168,169,169,169,169,169,169,169,169,169,169,
     169,169,169,170,170,170,170,170,170,170,170,170,
     170,170,170,170,170,171,171,171,171,171,171,171,
     171,171,171,171,172,172,172,172,172,172,172,172,
     173,173,173,173,173,173,173,173,173,173,173,174,
     174,174,174,174,174,174,174,174,175,175,175,175,
     175,175,175,175,175,175,175,175,175,176,176,176,
     176,176,176,176,176,176,176,176,176,177,177,177,
     177,177,178,178,178,178,178,178,179,179,179,179,
     179,180,180,180,180,180,180,180,180,181,181,181,
     181,181,182,182,182,182,182,182,182,182,183,183,
     184,184,184,184,184,185,185,185,185,185,185,185,
     186,186,186,186,187,187,187,187,187,187,187,187,
     187,188,188,188,188,188,188,188,188,188,189,189,
     189,189,189,189,189,189,189,189,189,189,189,189,
     190,190,190,190,190,190,190,191,191,191,191,191,
     191,191,191,192,192,192,192,192,192,192,192,193,
     193,193,193,193,193,193,193,193,193,193,193,193,
     193,193,193,193,193,194,194,194,194,194,194,194,
     194,195,195,195,195,196,196,196,196,197,197,197,
     197,197,197,197,197,197,197,197,198,198,198,198,
     198,198,198,198,198,198,198,199,199,199,199,199,
     199,199,199,199,199,199,199,199,199,200,200,200,
     200,200,200,200,200,200,200,200,201,201,201,201,
     201,201,201,201,201,201,201,201,201,201,202,202,
     202,202,202,202,202,202,202,202,202,202,202,203,
     203,203,203,203,203,203,203,203,203,204,204,204,
     204,204,204,204,204,204,204,204,204,204,204,204,
     204,205,205,205,205,205,205,205,205,205,206,206,
     206,206,206,207,207,207,207,207,207,207,207,207,
     207,207,207,207,208,208,208,208,208,208,208,208,
     208,208,208,208,208,208,208,208,208,208,208,208,
     208,208,208,209,209,209,209,209,209,209,209,209,
     209,209,209,209,209,209,210,210,210,210,210,210,
     210,210,210,210 }; 

 /* Stoichiometric Matrix in compressed column format */

  float  STOICM[] = {
         1,    1,   -1,   -1,    1,   -1,   -1,   -1,
        -1,    1,   -1,    1,   -1,   -1,   -1,    1,
        -1,   -1,    1,   -1,   -1,    1,   -1,    2,
        -1,   -2,    2,    1,   -1,   -1,   -1,    1,
         1,   -1,    2,    1,   -1,    1,   -1,    1,
         1,   -1,    1,   -1,    1,   -1,   -1,    2,
        -1,    1,    1,   -1,   -1,   -1,    1,    1,
        -1,    1,    1,   -1,    1,   -1,    1,   -1,
        -1,    1,    1,   -1,   -1,   -1,    1,   -1,
        -1,    1,    1,   -1,    1,   -1,   -1,    1,
        -1,   -1,   -1,    1,    1,    1,   -1,   -1,
        -1,    1,    1,   -1, 0.61, 0.61, 0.39, 0.39,
        -1,    1,   -1,   -1,   -1,    1,    1,   -2,
         1,   -2,  0.2,   -1,  0.8,   -1,  0.8,    2,
        -2,   -1,    2,   -1,    1,   -1,   -1,   -1,
         1,   -1,    1,   -1,    1,   -1,    1,    1,
        -1,   -1,    1,    1,   -1,   -1,    1,    1,
        -1,    1,   -1,    1,    1,   -2,    2,    2,
        -2,    1,   -1,   -1,    1,    1,   -1,   -1,
         1,   -1,    1,   -1, 0.25, 0.75,    1,   -1,
        -1,    1,   -2,   -1,   -1,    1,   -1,   -1,
         1,   -1,   -1,   -1,    1,   -1,   -1,    1,
        -1,   -1, 0.25, 0.75,  0.5,  0.5,    1,   -1,
        -1,    1,    1,   -1,    1,   -1,  0.5,  0.5,
         1,   -1,   -1,   -1,    1,    1,    1,   -2,
         1,   -1,   -1,   -1,    1,    1,    1,   -1,
         1,   -1, 0.25, 0.75, 0.25,   -1,   -1,    1,
         1,   -1,   -1,    1,    1,   -1,   -1,    1,
        -1,   -1,   -1,    1,    1,   -1,   -1,    2,
        -2,    1,   -1,   -1,   -1,    1,    1,    1,
         1,   -1,    1,   -1, 0.25, 0.75, 0.25,   -1,
        -1,    1,    1,    1,   -1,   -1,    1,    1,
        -1,   -1,    1,   -1,   -1,   -1,    1,    1,
        -1,   -1,    1,    1,    1,   -1,   -1,    2,
         2,   -2,    1,   -1,   -1,   -1,    1,    1,
         1,    1,   -1,   -1,    1, 0.25, 0.75, 0.25,
        -1,   -1,    1,    1,   -1,    1,   -1,    1,
         1,   -1,   -1,    1,   -1,   -1,   -1,    1,
         1,   -1,   -1,    1,    1,    1,   -1,   -1,
         1,    1,    1,   -1,    1,   -1,    2,    2,
        -2,    1,   -1,   -1,   -1,    1,    1,    1,
        -1,   -1,    1,    1, 0.25, 0.75, 0.25,   -1,
        -1,    1,   -1,    1,   -1,    1,    1,    1,
        -1,   -1,    1,   -1,   -1,   -1,    2,   -1,
        -1,    1,   -1,    1,    1,    1,   -1,    1,
         1,   -1,    1,    1,    1,   -1,   -1,    1,
         2,   -2,    2,   -1,    1,   -1,   -1,    1,
         1,    1,   -1,   -1,    1,   -1,   -1,    1,
        -1,    2,    6,   -1,   -1,   -1,    1,   -1,
        -1,    1,    1,   -1,    2,    1,   -1,    1,
        -1,    1,   -1,    1,   -1,   -1,   -1,    1,
         1,    1,   -1,    1,   -1,    1,    1,    1,
        -1,    1,   -1,   -1,    1,   -1,    1,   -1,
         1,    1,    1,   -1,   -1,    1,0.034,0.034,
        -1,0.001,0.034,0.965,   -1,    1,    1,   -1,
         1,    1,    1,   -1,   -1,    1,   -1,    1,
         1,    1,   -1,   -1,    1,    1,0.616,0.482,
     0.115, 0.37,   -1,0.042, 0.37,0.492,0.096,   -1,
         1,   -1,    1,    1,   -1,    1,    1,   -1,
        -1, 0.35, 0.65,-0.65,   -1,    1,    1,    1,
        -1,    1, 0.34,-0.34,   -1,    1,    1,    1,
         2,   -1,    2,    1,   -1,    1, 1.26,   -1,
      0.63, 0.37,   -1, 1.26,    1,   -1, 0.63,   -1,
      0.37,    1,   -1,    1,    1,    1,   -1,    1,
        -1,    1,   -1,    1,   -1,    1,   -1,    2,
        -1, 0.23, 0.24, 0.76,   -1,   -1,    1,    1,
        -1,   -1, 0.23, 0.24, 0.76,   -1,   -1,    1,
         1,   -1,    1,   -1,    1,   -1,   -1,    1,
        -1,    7,   -1,   -1,    1,    1,   -1,0.416,
     0.084,   -1,0.084,0.416,  0.5,  0.5,   -1,0.333,
      0.45,  0.9,   -1,  0.2,   -1,0.008,  0.1,  0.1,
     0.208,  0.5,  0.5,   -1,  0.5,  0.5,   -1,   -1,
        -1,    1, 0.67,   -1, 0.67, 0.34, 0.33, 0.33,
      0.67, 0.33,  0.3,0.675,   -1,  0.3,0.675,0.025,
       0.3,0.675,   -1,0.351,0.475, 0.95,   -1,  0.1,
        -1,0.064, 0.05, 0.05,0.164,   -1,   -1, 0.45,
      0.55,  0.7,   -1,  0.7,  0.3,  0.3,0.336,0.174,
      0.15,   -1,0.129,0.055,0.013, 0.15,0.332,0.041,
     0.289, 0.67,   -1,  0.1,0.372,0.498,0.742,0.023,
        -1,0.047,0.125, 0.21,   -1,  0.4,0.048,0.048,
     0.285,0.572,0.008, 0.15,   -1,0.227,0.572,0.218,
     0.051, 0.15,0.799,   -1,1.233,   -1,0.467,  0.3,
     0.233,1.233,0.467,  0.3,0.084,0.213,0.558,0.115,
     -0.671,0.379, 0.07,0.473,0.029,0.049,   -1,0.515,
     0.246,0.506, 0.71,   -1, 0.04, 0.96,0.667,0.333,
     0.006,0.596,0.439, 0.01,-0.69,0.213,0.177,0.048,
     0.113,0.173,0.376,0.338,   -1, 0.02,0.152,0.431,
     0.134,   -1,0.147,0.243,0.435,0.341,0.095,0.564,
         1,   -1,    1,    1,    1,   -1,   -1,  1.5,
         1,   -1,  1.5,  0.5,   -1,    1,    1,    1,
        -1,   -1,    1,  0.5,  0.5,    1,  0.5,    1,
       0.5,   -1,    1,    1,    1,   -1,   -1,    1,
       0.5,  0.5,    1,  0.5,    1,  0.5,    1,   -1,
        -1,0.195, 1.61,    1,   -1, 0.37,  0.5,   -1,
         1,   -1, 0.12, 0.12,   -1,    1,    1,   -1,
     0.491,   -1,0.009, 0.25,0.191,   -1,  0.5,  0.3,
       0.2,   -1,0.079, 0.23,0.357, 0.32,0.624,0.093,
     0.907,   -1,0.204, 0.15,0.275,   -1,0.126, 0.39,
      0.16,0.592,  0.1,   -1,0.008,0.192,0.066,0.266,
        -1,0.187,0.936,0.064,0.749,0.187,   -1,   -1,
      0.24, 0.24,   -1, 0.75, 0.01, 0.24, 0.25,  0.5,
        -1,0.276,0.474,0.276, 0.25, 0.75,   -1,0.103,
     0.189,0.031,0.157, 0.13,0.001,0.729,   -1,0.235,
     0.205,0.276,   -1,0.033, 0.18,0.031,0.123,0.201,
     0.567, 0.75,   -1,0.276,0.474, 0.25,0.276,0.474,
        -1,   -1,   -1,0.147,0.853,   -1,    1,    1,
        -1,0.121,   -1, 0.16,0.417,0.248,0.039,0.155,
     0.121,0.021,0.612,-0.754,   -1,0.236,0.024,0.559,
     0.445,0.026,0.122,0.332, 0.07,0.695,   -1,   -1,
     0.002,0.452,0.936,0.455,0.024,0.244, 0.11,0.125,
     0.143,0.011,0.835,0.011,   -1,   -1,0.072,0.948,
     0.099,0.026,0.204,0.089,0.417,0.347,0.653,   -1,
        -1,0.108,0.051,0.207,0.491,0.059,0.017,0.119,
     0.118,0.055,0.224,0.011,0.765,   -1,0.087,   -1,
     0.099,0.093,0.187,0.561, 0.05,0.287,0.097,0.187,
     0.009,0.804,   -1,0.005,0.205,   -1,0.294,0.732,
     0.497,0.119, 0.09, 0.91,   -1,0.185, 0.05,0.119,
     0.345,0.001,   -1,0.154,  0.5,0.363,0.215,   -1,
     0.056,0.001,0.076,0.022,0.155,0.024,0.488,   -1,
     0.009,0.511,0.037,0.176,0.824,   -1,   -1,   -1,
      0.45,0.437,0.113,0.061,0.127,0.001,0.025,0.025,
        -1,0.732,0.244,0.511,0.072,0.082,0.918,   -1,
     0.073,0.129,0.247,0.042,0.265,0.045,0.137,0.026,
        -1,0.019,0.456,0.269,0.305,0.026,0.043,   -1,
     0.003,0.002,0.197,0.033,0.137,0.006,0.378,0.015,
     0.102,0.711,   -1,0.048,0.507,0.079,0.321,0.151,
     0.001,0.136, 0.03,0.442,0.391,   -1,0.012,0.012,
        -1,   -1,0.069,0.659,0.259,0.013,0.001,0.012
      }; 


