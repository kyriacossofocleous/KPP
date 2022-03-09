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
/* File                 : tropo_StoichiomSP.c                       */
/* Time                 : Wed Mar  9 11:42:31 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/tropo  */
/* Equation file        : tropo.kpp                                 */
/* Output root filename : tropo                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "tropo_Parameters.h"
#include "tropo_Global.h"
#include "tropo_Sparse.h"



/* Row-compressed sparse data for the Jacobian of reaction products JVRP */
 /* Beginning of rows in JVRP */

  int  CROW_JVRP[] = {
       0,  1,  3,  5,  7,  9, 10, 12, 13, 15, 16, 18,
      19, 21, 22, 24, 25, 27, 29, 31, 33, 34, 36, 37,
      38, 40, 41, 42, 44, 46, 47, 48, 50, 52, 54, 56,
      57, 59, 61, 63, 65, 66, 67, 69, 70, 72, 74, 76,
      78, 80, 82, 84, 86, 88, 90, 92, 94, 95, 96, 97,
      99,101,103,105,107,109,111,112,114,116,118,120,
     122,124,126,128,130,132,133,135,137,138,139,140,
     142,144,146,148,150,152,154,156,158,160,162,164,
     166,168,169,171,172,174,176,178,180,182,183,185,
     187,188,190,192,194,195,197,199,201,203,205,207,
     209,211,212,214,216,218,220,222,224,226,227,229,
     231,233,235,237,239,241,242,244,246,247,249,251,
     252,253,254,256,258,260,262,264,266,268,270,272,
     274,276,278,280,282,284,286,288,290,292,294,296,
     298,300,302,304,306,307,309,311,312,314,316 }; 

 /* Column indices in JVRP */

  int  ICOL_JVRP[] = {
      75, 73, 80, 73, 75, 80, 82, 75, 82, 25, 75, 82,
      82, 81, 82, 73, 80, 83, 26, 75, 83, 56, 56, 83,
      25, 40, 83, 73, 83, 80, 81, 75, 81, 30, 73, 81,
      81, 22, 22, 83, 75, 30, 30, 83, 77, 83, 76, 76,
      76, 83, 76, 81, 36, 80, 36, 81, 36, 32, 83, 76,
      82, 78, 83, 78, 82, 78, 78, 71, 75, 31, 71, 80,
      64, 80, 28, 83, 18, 83, 50, 80, 19, 83, 45, 80,
      29, 83, 60, 80, 29, 82, 27, 83, 37, 80, 64, 50,
      45, 64, 81, 50, 81, 45, 81, 60, 81, 71, 81, 61,
      83, 62, 80, 61, 61, 82, 62, 81, 39, 83, 46, 80,
      59, 83, 47, 80, 39, 73, 59, 73, 79, 80, 75, 79,
      79, 66, 80, 66, 75, 66, 46, 47, 46, 81, 47, 81,
      77, 79, 66, 77, 59, 82, 51, 75, 51, 81, 51, 80,
      76, 79, 78, 79, 66, 76, 66, 78, 23, 83, 43, 80,
      34, 34, 83, 41, 41, 83, 35, 83, 35, 82, 33, 83,
      53, 75, 24, 53, 80, 38, 80, 33, 43, 81, 53, 81,
      38, 81, 36, 63, 83, 52, 80, 52, 81, 74, 83, 58,
      80, 58, 81, 72, 83, 65, 75, 20, 65, 80, 65, 81,
      72, 83, 48, 80, 48, 81, 44, 83, 55, 75, 21, 55,
      80, 55, 81, 63, 73, 73, 74, 72, 73, 68, 80, 68,
      75, 68, 69, 80, 69, 75, 69, 67, 80, 67, 75, 67,
      44, 57, 57, 83, 63, 82, 54, 80, 54, 75, 54, 81,
      74, 82, 49, 80, 49, 81, 72, 82, 72, 82, 42, 80,
      42, 81, 44, 82, 69, 81, 68, 81, 68, 77, 69, 77,
      67, 77, 15, 83, 16, 83, 10, 73, 11, 73, 12, 73,
      13, 73, 14, 73, 81, 83, 70, 70, 83, 17, 83, 82,
      31, 83, 81, 82 }; 

 /* Row indices in JVRP */

  int  IROW_JVRP[] = {
       0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  6,  6,
       7,  8,  8,  9, 10, 10, 11, 12, 12, 13, 14, 14,
      15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 21, 21,
      22, 23, 24, 24, 25, 26, 27, 27, 28, 28, 29, 30,
      31, 31, 32, 32, 33, 33, 34, 34, 35, 36, 36, 37,
      37, 38, 38, 39, 39, 40, 41, 42, 42, 43, 44, 44,
      45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50,
      51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 57,
      58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64,
      64, 65, 65, 66, 67, 67, 68, 68, 69, 69, 70, 70,
      71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76,
      77, 78, 78, 79, 79, 80, 81, 82, 83, 83, 84, 84,
      85, 85, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90,
      91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96,
      97, 98, 98, 99,100,100,101,101,102,102,103,103,
     104,104,105,106,106,107,107,108,109,109,110,110,
     111,111,112,113,113,114,114,115,115,116,116,117,
     117,118,118,119,119,120,120,121,122,122,123,123,
     124,124,125,125,126,126,127,127,128,128,129,130,
     130,131,131,132,132,133,133,134,134,135,135,136,
     136,137,138,138,139,139,140,141,141,142,142,143,
     144,145,146,146,147,147,148,148,149,149,150,150,
     151,151,152,152,153,153,154,154,155,155,156,156,
     157,157,158,158,159,159,160,160,161,161,162,162,
     163,163,164,164,165,165,166,166,167,167,168,168,
     169,169,170,170,171,171,172,173,173,174,174,175,
     176,176,177,177 }; 




/*  Stoichiometric Matrix in Compressed Column Sparse Format        */

 /* Beginning of columns in STOICM */

  int  CCOL_STOICM[] = {
       0,  3,  6,  9, 12, 15, 18, 20, 24, 27, 29, 32,
      35, 38, 41, 44, 46, 49, 52, 56, 59, 62, 65, 67,
      69, 72, 75, 78, 81, 85, 88, 90, 94, 97,102,105,
     108,111,116,119,123,127,130,133,136,140,145,148,
     151,156,159,166,169,179,183,186,191,194,197,201,
     204,207,210,213,216,219,225,228,232,236,239,244,
     247,253,260,268,272,276,278,282,286,288,292,295,
     298,301,305,309,312,315,318,323,326,329,332,335,
     340,347,348,352,356,360,366,369,372,375,378,385,
     388,392,395,398,401,404,407,414,417,420,428,431,
     434,437,440,445,448,451,457,460,463,466,469,474,
     477,486,495,504,508,512,513,517,521,523,527,531,
     533,536,539,542,545,551,553,555,558,565,567,571,
     574,579,581,585,588,591,595,599,603,605,607,610,
     613,616,619,622,624,628,632,636,638,640,645 }; 

 /* Row indices in STOICM */

  int  IROW_STOICM[] = {
      73, 75, 80, 73, 75, 80, 73, 75, 82, 75, 80, 82,
      25, 75, 82, 25, 75, 82, 80, 82, 73, 75, 80, 82,
      56, 81, 82, 73, 83, 26, 80, 83, 26, 80, 83, 56,
      75, 83, 56, 75, 83, 56, 82, 83, 25, 56, 40, 81,
      83, 73, 81, 83, 75, 80, 81, 83, 30, 75, 81, 30,
      75, 81, 73, 81, 83, 22, 81, 22, 83, 22, 81, 83,
      26, 56, 75, 30, 75, 81, 30, 75, 83,  0, 77, 81,
      83, 40, 76, 81, 40, 76, 40, 76, 81, 83, 36, 76,
      81, 32, 36, 75, 80, 81, 32, 36, 81, 32, 36, 81,
      32, 81, 83, 40, 56, 76, 81, 82, 71, 78, 83, 56,
      71, 78, 82, 40, 64, 78, 81, 28, 40, 78, 31, 71,
      75, 31, 71, 75, 64, 71, 75, 80, 64, 75, 76, 80,
      81, 28, 64, 83, 18, 50, 83, 50, 75, 78, 80, 81,
      19, 45, 83,  2, 45, 61, 75, 78, 80, 81, 29, 60,
      83, 27, 45, 50, 60, 61, 64, 75, 78, 80, 81, 29,
      56, 60, 82, 27, 37, 83, 37, 75, 76, 78, 80, 64,
      76, 81, 50, 78, 81, 45, 61, 78, 81, 64, 70, 81,
      50, 70, 81, 45, 70, 81, 60, 70, 81, 70, 71, 81,
      61, 62, 83, 27, 62, 71, 75, 78, 80, 50, 61, 71,
      56, 61, 62, 82, 41, 62, 64, 81, 39, 46, 83, 46,
      75, 76, 80, 81, 47, 59, 83, 47, 75, 76, 78, 80,
      81, 28, 39, 40, 73, 76, 79, 81, 59, 64, 66, 73,
      76, 78, 79, 81, 75, 76, 79, 80, 75, 76, 79, 82,
      32, 79, 66, 75, 78, 80, 66, 75, 78, 82,  1, 66,
      46, 76, 78, 81, 47, 78, 81, 46, 70, 81, 47, 70,
      81,  0, 76, 77, 79,  0, 66, 77, 78, 51, 59, 82,
       6, 51, 75,  7, 51, 81, 51, 75, 76, 78, 80,  8,
      76, 79,  8, 78, 79,  8, 66, 76,  8, 66, 78, 23,
      35, 43, 81, 83, 33, 34, 41, 43, 75, 80, 81, 34,
      34, 40, 81, 83, 40, 41, 71, 81, 40, 41, 71, 83,
      35, 38, 53, 75, 81, 83, 35, 56, 82, 33, 53, 83,
      24, 53, 75, 24, 53, 75, 34, 41, 53, 71, 75, 80,
      81, 38, 75, 80, 33, 53, 71, 81, 43, 70, 81, 53,
      70, 81, 38, 70, 81, 36, 76, 81, 52, 63, 83, 52,
      72, 74, 75, 76, 80, 81, 52, 70, 81, 58, 74, 83,
      44, 57, 58, 71, 75, 76, 80, 81, 58, 70, 81, 65,
      72, 83, 20, 65, 75, 20, 65, 75, 57, 65, 80, 81,
      82, 65, 70, 81, 48, 72, 83, 48, 57, 75, 76, 80,
      81, 48, 70, 81, 44, 55, 83, 21, 55, 75, 21, 55,
      75, 55, 75, 76, 80, 81, 55, 70, 81, 63, 68, 69,
      72, 73, 74, 76, 79, 81, 57, 67, 71, 73, 74, 76,
      78, 79, 81, 57, 67, 72, 73, 75, 76, 79, 80, 81,
      68, 74, 75, 80, 68, 74, 75, 82, 68, 69, 72, 75,
      80, 69, 72, 75, 82, 15, 69, 57, 67, 75, 80, 57,
      67, 75, 82, 16, 67, 44, 76, 81, 57, 71, 81, 57,
      71, 83, 54, 63, 82, 54, 72, 74, 75, 76, 80, 54,
      75, 54, 81, 49, 74, 82, 49, 57, 71, 75, 76, 80,
      81, 49, 81, 56, 65, 72, 82, 42, 72, 82, 42, 57,
      75, 76, 80, 42, 81, 44, 55, 56, 82, 69, 70, 81,
      68, 70, 81,  0, 68, 74, 77,  0, 69, 72, 77,  0,
      67, 74, 77, 15, 83, 16, 83,  3, 10, 73,  4, 11,
      73,  5, 12, 73,  4, 13, 73,  5, 14, 73, 81, 83,
      70, 76, 81, 83, 64, 70, 76, 83,  9, 17, 77, 83,
      75, 82, 31, 83, 56, 75, 81, 82, 83 }; 

 /* Column indices in STOICM */

  int  ICOL_STOICM[] = {
       0,  0,  0,  1,  1,  1,  2,  2,  2,  3,  3,  3,
       4,  4,  4,  5,  5,  5,  6,  6,  7,  7,  7,  7,
       8,  8,  8,  9,  9, 10, 10, 10, 11, 11, 11, 12,
      12, 12, 13, 13, 13, 14, 14, 14, 15, 15, 16, 16,
      16, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 20,
      20, 20, 21, 21, 21, 22, 22, 23, 23, 24, 24, 24,
      25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28,
      28, 29, 29, 29, 30, 30, 31, 31, 31, 31, 32, 32,
      32, 33, 33, 33, 33, 33, 34, 34, 34, 35, 35, 35,
      36, 36, 36, 37, 37, 37, 37, 37, 38, 38, 38, 39,
      39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42,
      42, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 45,
      45, 46, 46, 46, 47, 47, 47, 48, 48, 48, 48, 48,
      49, 49, 49, 50, 50, 50, 50, 50, 50, 50, 51, 51,
      51, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 53,
      53, 53, 53, 54, 54, 54, 55, 55, 55, 55, 55, 56,
      56, 56, 57, 57, 57, 58, 58, 58, 58, 59, 59, 59,
      60, 60, 60, 61, 61, 61, 62, 62, 62, 63, 63, 63,
      64, 64, 64, 65, 65, 65, 65, 65, 65, 66, 66, 66,
      67, 67, 67, 67, 68, 68, 68, 68, 69, 69, 69, 70,
      70, 70, 70, 70, 71, 71, 71, 72, 72, 72, 72, 72,
      72, 73, 73, 73, 73, 73, 73, 73, 74, 74, 74, 74,
      74, 74, 74, 74, 75, 75, 75, 75, 76, 76, 76, 76,
      77, 77, 78, 78, 78, 78, 79, 79, 79, 79, 80, 80,
      81, 81, 81, 81, 82, 82, 82, 83, 83, 83, 84, 84,
      84, 85, 85, 85, 85, 86, 86, 86, 86, 87, 87, 87,
      88, 88, 88, 89, 89, 89, 90, 90, 90, 90, 90, 91,
      91, 91, 92, 92, 92, 93, 93, 93, 94, 94, 94, 95,
      95, 95, 95, 95, 96, 96, 96, 96, 96, 96, 96, 97,
      98, 98, 98, 98, 99, 99, 99, 99,100,100,100,100,
     101,101,101,101,101,101,102,102,102,103,103,103,
     104,104,104,105,105,105,106,106,106,106,106,106,
     106,107,107,107,108,108,108,108,109,109,109,110,
     110,110,111,111,111,112,112,112,113,113,113,114,
     114,114,114,114,114,114,115,115,115,116,116,116,
     117,117,117,117,117,117,117,117,118,118,118,119,
     119,119,120,120,120,121,121,121,122,122,122,122,
     122,123,123,123,124,124,124,125,125,125,125,125,
     125,126,126,126,127,127,127,128,128,128,129,129,
     129,130,130,130,130,130,131,131,131,132,132,132,
     132,132,132,132,132,132,133,133,133,133,133,133,
     133,133,133,134,134,134,134,134,134,134,134,134,
     135,135,135,135,136,136,136,136,137,138,138,138,
     138,139,139,139,139,140,140,141,141,141,141,142,
     142,142,142,143,143,144,144,144,145,145,145,146,
     146,146,147,147,147,148,148,148,148,148,148,149,
     149,150,150,151,151,151,152,152,152,152,152,152,
     152,153,153,154,154,154,154,155,155,155,156,156,
     156,156,156,157,157,158,158,158,158,159,159,159,
     160,160,160,161,161,161,161,162,162,162,162,163,
     163,163,163,164,164,165,165,166,166,166,167,167,
     167,168,168,168,169,169,169,170,170,170,171,171,
     172,172,172,172,173,173,173,173,174,174,174,174,
     175,175,176,176,177,177,177,177,177 }; 

 /* Stoichiometric Matrix in compressed column format */

  double  STOICM[] = {
         1,   -1,    1,   -1,    1,   -1,   -1,   -1,
         1,    2,   -1,   -1,    1,   -1,   -1,   -1,
         1,    1,    1,   -1, 0.85, 0.85, 0.15,   -1,
         1,   -1,   -1,   -1,    2,    1,   -1,   -1,
        -1,    1,    1,    1,   -1,   -1,   -1,    1,
         1,   -1,    1,   -1,   -1,    2,   -1,    1,
        -1,   -1,    1,   -1,    1,   -1,   -1,    1,
         1,   -1,   -1,   -1,    1,    1,   -1,   -1,
         1,    1,   -2,   -1,    2,   -1,    1,   -1,
         1,    1,   -2,   -1,    1,    1,   -1,    1,
        -1,    1,   -1,    1,   -1,    1,   -1,    2,
         1,   -1,    1,   -1,    1,   -1,    1,   -1,
        -1,    1,   -1,    1,   -1,    1,    1,   -1,
        -1,    1,   -2,    2,   -1,    1,   -1,    1,
         1,   -1,    1,   -1,    1,   -1,   -1,    1,
         1,   -1,   -1,    1,    1,   -1,    1,    1,
         1,   -1,    1,   -1,   -1,   -1,    1,    1,
         1,   -1,    1,   -1,   -1,    1,    1,   -1,
         1,   -1,    1,   -1,   -1,    1,   -1,   -1,
         1,    1,   -1,    1,   -1,    1,   -1, 0.03,
        -1, 0.49, 0.97, 0.46,   -1, 0.97,   -1,    1,
        -1,0.263,0.1057,0.1879,-0.94,  0.3,0.1116,0.9261,
     1.0482,-1.1892, 0.28,   -1,    1,    1,   -1,   -1,
         1,   -1,   -1,  2.5,  0.8,  2.1, -1.5,   -2,
       1.4,  0.8,   -2,  1.6,  1.2,   -2, 0.28,  1.9,
      0.37,   -1,    1,   -1,   -1,    1,   -1,   -1,
         1,   -1,   -1,    1,   -1,    1,   -1,   -1,
        -1,    1,   -1, 0.05,   -1, 0.94, 0.95, 0.94,
        -1,    1,   -1,    1,    1,   -1,    1,   -1,
         1,   -1,    1,   -1,   -1,    1,   -1,   -1,
         1,    2,   -1,    1,    1,   -1,   -1,   -1,
         1,    1,    1,   -1,    1, 0.06,   -1, 0.42,
        -1,    1,  0.4, 0.12,   -1,0.215,  0.2,   -1,
     0.525,  0.5,  0.2, 0.23,    1,    1,   -1,   -1,
        -1,    1,   -1,    1,    1,   -1,   -1,    1,
         1,   -1,   -1,   -1,    1,    1,    1,   -1,
        -2,  2.4,  0.4,  1.2,   -2,  2.2,  1.2,   -1,
         1,   -1,   -1,    1,   -1,    1,    1,   -1,
        -1,    1,   -1,   -1,    1,    1,   -1,   -1,
         1,   -1,   -1,    1,   -1,   -1,   -1,    2,
         1,    1,   -1,    1,   -1,   -1,    1,   -1,
        -1,    1,   -1,   -1,    1,   -1,   -1,   -1,
      0.16, 0.84, 0.16,   -1,    1, 0.18, 0.72,   -1,
         1,   -1,    1,   -1,   -1,    2,    1,   -1,
         1,   -1,    1,    1,    1,   -1,    1,   -1,
        -1,  0.9,  0.9,-0.0315, 0.83, -1.9,   -1,    1,
        -1,   -1,    1,   -1,    1,   -1,   -1,   -1,
         1,    1, 0.89, 0.11,   -1, 0.05,    1,   -1,
      0.92,   -1,    1,   -1,   -1,    1, 0.02, 0.98,
        -1,    1,   -1,   -1,    1,   -1,   -1,    1,
        -1,   -1,    1,    1,    1,   -1,   -1,   -1,
      0.45, 0.45,  0.9,  0.9,   -1,  0.9,   -1,    1,
        -1,    1,   -1,   -1,  0.6,  0.3,   -1,  0.6,
       0.9,  0.3,   -1,  0.3,   -1,    1,   -1,    1,
        -1,   -1,    1,   -1,   -1,   -1,    1,    1,
         1,   -1,   -3,    1,    3,   -1,    1,   -1,
         1,   -1,   -1,   -1,  0.9,  0.9,  0.9,   -1,
       0.9,   -1,    1,   -1,   -1,    1,   -1,    1,
        -1,   -1,   -1,    1,    1,   -1,    1,    1,
        -1,    1,   -1,    1,   -1,   -1,  0.2,  0.3,
       0.3,   -1,  0.2,  0.5,  0.2, 0.06,  0.5,  0.2,
      0.15,   -1,   -1,  0.5, 0.15,  0.2, 0.21,  0.5,
       0.2,   -1,   -1, 0.15, 0.65,  0.2,-0.15, 0.36,
        -1,    1,    1,   -1,   -1,    1,   -1,    1,
        -1,   -1,    1,    1,   -1,   -1,    1,   -1,
         1,    1,   -1,    1,   -1,    1,   -1,    1,
        -1,   -1,    1,    1,   -1,   -1,    1,    2,
        -1,    1,    1,   -1,    1,   -1,    1,   -1,
        -1,   -1,  0.5,  0.5,    2,    1,   -1,   -1,
        -1,   -1,   -1,    1,   -1,   -1,   -1,  0.5,
       0.5,    2,    1,   -1,  0.5,   -1,   -1,    1,
         1,   -1,   -1,    1,   -1,   -1,   -1,    1,
         2,    1,   -1,   -1,   -1,   -1,    1,    1,
        -1,   -1,    1,   -1,   -1,    1,   -1,    1,
        -1,    1,   -1,    1,   -1,    1,   -1,    1,
        -1,    1,   -1,   -1,   -1,   -1,   -1, 0.11,
        -1,   -1, 0.19,   -1,   -1, 0.15,   -1,   -1,
      0.39,   -1,   -1, 0.15,   -1,   -1,   -1,   -1,
        -1,    1,    1,    1,  0.5,   -1,  0.5, -0.5,
         1,   -1,    1,   -1,    2,   -2,   -1,   -1,
       0.4,  0.6,   -1,   -1,  0.6 }; 


