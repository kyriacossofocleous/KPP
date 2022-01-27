/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Sparse Jacobian Data Structures File                             */
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
/* File                 : tropo_JacobianSP.c                        */
/* Time                 : Thu Jan 27 11:37:00 2022                  */
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



/* Sparse Jacobian Data                                             */

 /* Row indexes of the LU Jacobian of variables */

  int  LU_IROW[] = {
       0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,
       2,  3,  3,  3,  4,  4,  4,  4,  5,  5,  5,  5,
       6,  6,  6,  7,  7,  7,  8,  8,  8,  8,  8,  9,
       9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14,
      15, 15, 15, 16, 16, 16, 17, 17, 18, 18, 19, 19,
      20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 24,
      24, 24, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27,
      27, 27, 28, 28, 28, 28, 28, 29, 29, 29, 30, 30,
      30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 32, 32,
      33, 33, 33, 33, 34, 34, 34, 34, 34, 35, 35, 35,
      35, 36, 36, 36, 36, 37, 37, 37, 37, 37, 37, 38,
      38, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 40,
      40, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 41,
      41, 41, 41, 42, 42, 42, 42, 42, 43, 43, 43, 43,
      43, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 45,
      46, 46, 46, 46, 46, 46, 47, 47, 47, 47, 47, 48,
      48, 48, 48, 48, 49, 49, 49, 49, 49, 50, 50, 50,
      50, 50, 50, 50, 51, 51, 51, 51, 51, 51, 52, 52,
      52, 52, 52, 53, 53, 53, 53, 53, 53, 53, 53, 53,
      53, 54, 54, 54, 54, 54, 54, 55, 55, 55, 55, 55,
      55, 55, 55, 55, 56, 56, 56, 56, 56, 56, 56, 56,
      56, 56, 56, 56, 56, 56, 56, 57, 57, 57, 57, 57,
      57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 58, 58,
      58, 58, 58, 59, 59, 59, 59, 60, 60, 60, 60, 60,
      60, 61, 61, 61, 61, 61, 61, 61, 62, 62, 62, 62,
      62, 62, 63, 63, 63, 63, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 65, 65, 65, 65,
      65, 65, 65, 65, 66, 66, 66, 66, 66, 66, 66, 66,
      66, 66, 67, 67, 67, 67, 67, 67, 67, 68, 68, 68,
      68, 68, 68, 68, 68, 68, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71,
      71, 71, 71, 71, 71, 71, 71, 71, 71, 72, 72, 72,
      72, 72, 72, 72, 72, 72, 72, 72, 72, 73, 73, 73,
      73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
      73, 73, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74,
      74, 74, 74, 74, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 76, 76, 76, 76, 76, 76,
      76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76,
      76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76,
      76, 76, 76, 76, 77, 77, 77, 77, 77, 77, 77, 77,
      77, 77, 77, 77, 77, 77, 77, 77, 77, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 79, 79, 79, 79, 79,
      79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
      80, 80, 80, 80, 80, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
      81, 81, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82,
      82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,
      82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83,
      83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83
      }; 

 /* Column indexes of the LU Jacobian of variables */

  int  LU_ICOL[] = {
       0, 66, 67, 68, 69, 77, 79, 83,  1, 66,  2, 45,
      80,  3, 10, 73,  4, 11, 13, 73,  5, 12, 14, 73,
       6, 51, 75,  7, 51, 81,  8, 66, 76, 78, 79,  9,
      17, 83, 10, 73, 11, 73, 12, 73, 13, 73, 14, 73,
      15, 69, 83, 16, 67, 83, 17, 83, 18, 83, 19, 83,
      20, 65, 75, 21, 55, 75, 22, 81, 83, 23, 83, 24,
      53, 75, 25, 75, 82, 26, 75, 80, 83, 27, 60, 62,
      80, 83, 28, 39, 73, 78, 83, 29, 82, 83, 30, 75,
      81, 83, 31, 71, 75, 83, 32, 36, 79, 80, 81, 83,
      33, 43, 80, 83, 34, 43, 53, 80, 83, 23, 35, 82,
      83, 36, 76, 80, 81, 27, 37, 60, 62, 80, 83, 35,
      38, 80, 81, 82, 83, 39, 73, 83, 34, 39, 40, 41,
      43, 53, 73, 76, 78, 80, 82, 83, 41, 43, 53, 62,
      80, 81, 83, 42, 72, 80, 81, 82, 23, 43, 80, 81,
      83, 44, 58, 80, 82, 83, 19, 45, 60, 80, 81, 83,
      39, 46, 73, 80, 81, 83, 47, 59, 80, 81, 83, 48,
      72, 80, 81, 83, 49, 74, 80, 81, 82, 18, 50, 60,
      61, 80, 81, 83, 51, 59, 75, 80, 81, 82, 52, 63,
      80, 81, 83, 24, 33, 35, 43, 53, 75, 80, 81, 82,
      83, 54, 63, 75, 80, 81, 82, 21, 44, 55, 58, 75,
      80, 81, 82, 83, 25, 29, 35, 44, 56, 58, 61, 72,
      75, 76, 78, 80, 81, 82, 83, 42, 48, 49, 57, 58,
      65, 67, 72, 73, 74, 75, 80, 81, 82, 83, 58, 74,
      80, 81, 83, 59, 73, 82, 83, 29, 60, 80, 81, 82,
      83, 45, 60, 61, 80, 81, 82, 83, 61, 62, 80, 81,
      82, 83, 63, 73, 82, 83, 28, 39, 59, 60, 62, 64,
      70, 71, 73, 78, 80, 81, 82, 83, 20, 65, 72, 75,
      80, 81, 82, 83, 59, 66, 73, 75, 76, 77, 78, 80,
      82, 83, 67, 72, 73, 74, 75, 77, 80, 63, 68, 73,
      75, 77, 80, 81, 82, 83, 63, 69, 73, 75, 77, 80,
      81, 82, 83, 38, 43, 45, 46, 47, 48, 50, 52, 53,
      55, 58, 59, 60, 61, 63, 64, 65, 68, 69, 70, 71,
      72, 73, 74, 75, 77, 78, 80, 81, 82, 83, 31, 33,
      41, 43, 49, 53, 57, 58, 61, 62, 65, 67, 71, 72,
      73, 74, 75, 77, 78, 80, 81, 82, 83, 52, 54, 63,
      69, 72, 73, 75, 77, 80, 81, 82, 83, 10, 11, 12,
      13, 14, 39, 59, 63, 72, 73, 74, 75, 77, 80, 81,
      82, 83, 52, 54, 63, 67, 68, 72, 73, 74, 75, 77,
      80, 81, 82, 83, 20, 21, 24, 25, 30, 31, 35, 36,
      37, 38, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52,
      53, 54, 55, 56, 58, 59, 60, 61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
      78, 79, 80, 81, 82, 83, 36, 37, 39, 42, 44, 46,
      47, 48, 49, 51, 52, 54, 55, 58, 59, 60, 62, 63,
      64, 66, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
      80, 81, 82, 83, 17, 66, 67, 68, 69, 72, 73, 74,
      75, 76, 77, 78, 79, 80, 81, 82, 83, 37, 45, 46,
      47, 50, 51, 59, 60, 61, 62, 66, 73, 74, 75, 76,
      77, 78, 79, 80, 81, 82, 83, 39, 59, 63, 72, 73,
      74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 26, 36,
      37, 38, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52,
      53, 54, 55, 58, 59, 60, 61, 62, 63, 64, 65, 66,
      67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
      79, 80, 81, 82, 83, 22, 23, 30, 32, 33, 34, 35,
      36, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
      49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61,
      62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74,
      75, 76, 77, 78, 79, 80, 81, 82, 83, 25, 29, 35,
      44, 56, 58, 59, 61, 63, 65, 66, 67, 68, 69, 72,
      73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 15,
      16, 17, 18, 19, 22, 23, 26, 27, 28, 29, 30, 31,
      32, 33, 34, 35, 36, 39, 40, 41, 43, 44, 53, 56,
      57, 58, 59, 60, 61, 62, 63, 65, 67, 69, 70, 71,
      72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83
      }; 

 /* Compressed row indexes of the LU Jacobian of variables */

  int  LU_CROW[] = {
       0,  8, 10, 13, 16, 20, 24, 27, 30, 35, 38, 40,
      42, 44, 46, 48, 51, 54, 56, 58, 60, 63, 66, 69,
      71, 74, 77, 81, 86, 91, 94, 98,102,108,112,117,
     121,125,131,137,140,152,159,164,169,174,180,186,
     191,196,201,208,214,219,229,235,244,259,274,279,
     283,289,296,302,306,320,328,338,345,354,363,394,
     417,429,446,460,510,544,561,583,598,641,693,719,
     768 }; 

 /* Diagonal indexes of the LU Jacobian of variables */

  int  LU_DIAG[] = {
       0,  8, 10, 13, 16, 20, 24, 27, 30, 35, 38, 40,
      42, 44, 46, 48, 51, 54, 56, 58, 60, 63, 66, 69,
      71, 74, 77, 81, 86, 91, 94, 98,102,108,112,118,
     121,126,132,137,142,152,159,165,169,175,181,186,
     191,196,202,208,214,223,229,237,248,262,274,279,
     284,291,297,302,311,321,329,338,346,355,382,406,
     421,438,453,501,536,554,577,593,637,690,717,767,
     768 }; 


