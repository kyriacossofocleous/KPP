/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Initialization File                                              */
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
/* File                 : strato_single_Initialize.c                */
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


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Initialize - function to initialize concentrations               */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Initialize( 
)
{
int i;                                  
float x;                                

  CFACTOR = 8.120000e+16;

  x = (0.)*CFACTOR;
  for( i = 0; i < NVAR; i++ )
    VAR[i] = x;

  x = (0.)*CFACTOR;
  for( i = 0; i < NFIX; i++ )
    FIX[i] = x;

  VAR[0] = (3.984427E-17)*CFACTOR;
  VAR[1] = (8.665679E-14)*CFACTOR;
  VAR[2] = (7.103997E-14)*CFACTOR;
  VAR[3] = (2.659306E-15)*CFACTOR;
  VAR[4] = (7.193558E-14)*CFACTOR;
  VAR[5] = (5.843046E-14)*CFACTOR;
  VAR[6] = (5.066596E-12)*CFACTOR;
  VAR[7] = (9.405408E-14)*CFACTOR;
  VAR[8] = (3.010774E-19)*CFACTOR;
  VAR[9] = (2.496504E-15)*CFACTOR;
  VAR[10] = (2.773328E-15)*CFACTOR;
  VAR[11] = (6.905712E-12)*CFACTOR;
  VAR[12] = (4.349534E-13)*CFACTOR;
  VAR[13] = (4.587317E-12)*CFACTOR;
  VAR[14] = (3.827485E-12)*CFACTOR;
  VAR[15] = (2.157657E-09)*CFACTOR;
  VAR[16] = (7.227409E-11)*CFACTOR;
  VAR[17] = (2.196369E-10)*CFACTOR;
  VAR[18] = (3.486344E-10)*CFACTOR;
  VAR[19] = (4.190815E-14)*CFACTOR;
  VAR[20] = (5.130799E-12)*CFACTOR;
  VAR[21] = (2.166934E-11)*CFACTOR;
  VAR[22] = (5.667175E-14)*CFACTOR;
  VAR[23] = (9.913988E-11)*CFACTOR;
  VAR[24] = (4.025093E-12)*CFACTOR;
  VAR[25] = (2.041165E-10)*CFACTOR;
  VAR[26] = (8.756027E-12)*CFACTOR;
  VAR[27] = (1.011874E-09)*CFACTOR;
  VAR[28] = (6.560000E-06)*CFACTOR;
  VAR[29] = (1.074516E-08)*CFACTOR;
  VAR[30] = (1.132088E-11)*CFACTOR;
  VAR[31] = (8.158574E-09)*CFACTOR;
  VAR[32] = (1.439703E-10)*CFACTOR;
  VAR[33] = (2.758840E-09)*CFACTOR;
  FIX[0] = (6.100000E-06)*CFACTOR;
  FIX[1] = (3.700000E-07)*CFACTOR;
  FIX[2] = (0.209)*CFACTOR;
  FIX[3] = (0.781)*CFACTOR;
  FIX[4] = (4.900000E-07)*CFACTOR;
  FIX[5] = (2.000000E-08)*CFACTOR;
/* constant rate coefficients                                       */
  RCONST[0] = 8.01822e-17;
  RCONST[1] = 1.57571e-15;
  RCONST[2] = 2.83887e-11;
  RCONST[3] = 4.27631e-11;
  RCONST[4] = 1.2e-10;
  RCONST[5] = 2.2e-10;
  RCONST[6] = 1e-10;
  RCONST[7] = 7.5e-12;
  RCONST[8] = 1.425e-10;
  RCONST[9] = 6.35388e-15;
  RCONST[10] = 1.99835e-11;
  RCONST[11] = 1.38892e-15;
  RCONST[12] = 3.25993e-14;
  RCONST[13] = 3.61646e-11;
  RCONST[14] = 1.55427e-12;
  RCONST[15] = 6.86894e-11;
  RCONST[16] = 1.38667e-15;
  RCONST[17] = 7e-11;
  RCONST[18] = 1.35192e-10;
  RCONST[19] = 2.76946e-12;
  RCONST[20] = 3.51541e-29;
  RCONST[21] = 1.4948e-12;
  RCONST[22] = 6.06249e-15;
  RCONST[23] = 1.04211e-11;
  RCONST[24] = 1.0685e-11;
  RCONST[25] = 4.69913e-18;
  RCONST[26] = 3.72413e-13;
  RCONST[27] = 2.69029e-14;
  RCONST[28] = 1e-11;
  RCONST[29] = 3.03315e-11;
  RCONST[30] = 2.32597e-13;
  RCONST[31] = 1.40599e-06;
  RCONST[32] = 1.89006e-13;
  RCONST[33] = 6.27341e-12;
  RCONST[34] = 3.1633e-07;
  RCONST[35] = 0;
  RCONST[36] = 3.03268e-16;
  RCONST[37] = 9.87868e-12;
  RCONST[38] = 2.6969e-15;
  RCONST[39] = 3.63979e-11;
  RCONST[40] = 6.35777e-12;
  RCONST[41] = 1.89901e-13;
  RCONST[42] = 4.00904e-11;
  RCONST[43] = 1.80823e-11;
  RCONST[44] = 0;
  RCONST[45] = 8.71828e-12;
  RCONST[46] = 2.12738e-11;
  RCONST[47] = 2.88645e-14;
  RCONST[48] = 1.20131e-15;
  RCONST[49] = 1.17478e-15;
  RCONST[50] = 1.37988e-15;
  RCONST[51] = 3.33034e-15;
  RCONST[52] = 16948.7;
  RCONST[53] = 0.000477396;
  RCONST[54] = 6.10068e-13;
  RCONST[55] = 3.78181e-13;
  RCONST[56] = 1.05517e-13;
  RCONST[57] = 3.02111e-13;
  RCONST[58] = 1.31924e-11;
  RCONST[59] = 0;
  RCONST[60] = 6.18551e-13;
  RCONST[61] = 1.24964e-12;
  RCONST[62] = 6.18551e-13;
  RCONST[63] = 4.99054e-11;
  RCONST[64] = 4.91828e-11;
  RCONST[65] = 2.58334e-11;
  RCONST[66] = 7.68422e-14;
  RCONST[67] = 9.49778e-12;
  RCONST[68] = 7.21345e-12;
  RCONST[69] = 1.17282e-12;
  RCONST[70] = 2.46725e-12;
  RCONST[71] = 1.1e-11;
  RCONST[72] = 1.5024e-13;
  RCONST[73] = 1.53225e-15;
  RCONST[74] = 1e-11;
  RCONST[75] = 4.50123e-14;
  RCONST[76] = 3.33437e-14;
  RCONST[77] = 7.15352e-11;
  RCONST[78] = 6.25037e-12;
  RCONST[79] = 5.88365e-14;
  RCONST[80] = 9.37792e-16;
  RCONST[81] = 8.85199e-12;
  RCONST[82] = 1.04438e-11;
  RCONST[83] = 6.18205e-12;
/* END constant rate coefficients                                   */

/* INLINED initializations                                          */

   TSTART = 12.0*3600.0;
   TEND = TSTART + 24.0*3600.0 * 3;
   DT = 3600.0;
   TEMP = 241.42;

/* End INLINED initializations                                      */

}

/* End of Initialize function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


