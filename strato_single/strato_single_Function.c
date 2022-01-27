/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The ODE Function of Chemical Model File                          */
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
/* File                 : strato_single_Function.c                  */
/* Time                 : Thu Jan 27 12:47:03 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_single */
/* Equation file        : strato_single.kpp                         */
/* Output root filename : strato_single                             */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "strato_single_Parameters.h"
#include "strato_single_Global.h"
#include "strato_single_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Fun - time derivatives of variables - Agregate form              */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      Vdot      - Time derivative of variable species concentrations */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Fun( 
  float V[],                             /* Concentrations of variable species (local) */
  float F[],                             /* Concentrations of fixed species (local) */
  float RCT[],                           /* Rate constants (local) */
  float Vdot[]                           /* Time derivative of variable species concentrations */
)
{

/* Local variables                                                  */
float A[NREACT];                         /* Rate for each equation */

/* Computation of equation rates                                    */
  A[0] = 8.01822e-17*V[31]*F[2];
  A[1] = 1.57571e-15*V[28]*V[31];
  A[2] = 2.83887e-11*V[10]*F[3];
  A[3] = 4.27631e-11*V[10]*F[2];
  A[4] = 1.2e-10*V[10]*V[28];
  A[5] = 2.2e-10*V[10]*F[0];
  A[6] = 1e-10*V[10]*F[1];
  A[7] = 7.5e-12*V[10]*F[4];
  A[8] = 1.425e-10*V[10]*F[4];
  A[9] = 6.35388e-15*V[19]*F[2];
  A[10] = 1.99835e-11*V[19]*V[28];
  A[11] = 1.38892e-15*V[25]*F[1];
  A[12] = 3.25993e-14*V[25]*V[28];
  A[13] = 3.61646e-11*V[25]*V[31];
  A[14] = 1.55427e-12*V[25]*V[25];
  A[15] = 6.86894e-11*V[31]*V[32];
  A[16] = 1.38667e-15*V[28]*V[32];
  A[17] = 7e-11*V[19]*V[32];
  A[18] = 1.35192e-10*V[25]*V[32];
  A[19] = 2.76946e-12*V[32]*V[32];
  A[20] = 3.51541e-29*V[32]*V[32]*F[0];
  A[21] = 1.4948e-12*V[16]*V[25];
  A[22] = 6.06249e-15*V[28]*V[29];
  A[23] = 1.04211e-11*V[29]*V[32];
  A[24] = 1.0685e-11*V[31]*V[33];
  A[25] = 4.69913e-18*V[28]*V[33];
  A[26] = 3.72413e-13*V[25]*V[33];
  A[27] = 2.69029e-14*V[32]*V[33];
  A[28] = 1e-11*V[22]*V[31];
  A[29] = 3.03315e-11*V[22]*V[29];
  A[30] = 2.32597e-13*V[22]*V[33];
  A[31] = 1.40599e-06*V[11];
  A[32] = 1.89006e-13*V[18]*V[25];
  A[33] = 6.27341e-12*V[14]*V[25];
  A[34] = 3.1633e-07*V[14];
  A[35] = 0;
  A[36] = 3.03268e-16*V[26]*F[2];
  A[37] = 9.87868e-12*V[26]*V[28];
  A[38] = 2.6969e-15*V[26]*F[1];
  A[39] = 3.63979e-11*V[26]*V[32];
  A[40] = 6.35777e-12*V[26]*V[32];
  A[41] = 1.89901e-13*V[16]*V[26];
  A[42] = 4.00904e-11*V[27]*V[31];
  A[43] = 1.80823e-11*V[25]*V[27];
  A[44] = 0;
  A[45] = 8.71828e-12*V[27]*V[32];
  A[46] = 2.12738e-11*V[27]*V[29];
  A[47] = 2.88645e-14*V[27]*V[33];
  A[48] = 1.20131e-15*V[27]*V[27];
  A[49] = 1.17478e-15*V[27]*V[27];
  A[50] = 1.37988e-15*V[27]*V[27];
  A[51] = 3.33034e-15*V[27]*V[27];
  A[52] = 16948.7*V[3];
  A[53] = 0.000477396*V[2];
  A[54] = 6.10068e-13*V[15]*V[25];
  A[55] = 3.78181e-13*V[17]*V[25];
  A[56] = 1.05517e-13*V[21]*V[31];
  A[57] = 3.02111e-13*V[21]*V[25];
  A[58] = 1.31924e-11*V[21]*V[26];
  A[59] = 0;
  A[60] = 6.18551e-13*V[24]*V[28];
  A[61] = 1.24964e-12*V[24]*V[32];
  A[62] = 6.18551e-13*V[23]*V[24];
  A[63] = 4.99054e-11*V[30]*V[31];
  A[64] = 4.91828e-11*V[30]*V[32];
  A[65] = 2.58334e-11*V[29]*V[30];
  A[66] = 7.68422e-14*V[30]*V[33];
  A[67] = 9.49778e-12*V[27]*V[30];
  A[68] = 7.21345e-12*V[27]*V[30];
  A[69] = 1.17282e-12*V[27]*V[30];
  A[70] = 2.46725e-12*V[30]*V[30];
  A[71] = 1.1e-11*V[12]*V[25];
  A[72] = 1.5024e-13*V[25]*F[5];
  A[73] = 1.53225e-15*V[25]*F[4];
  A[74] = 1e-11*V[23]*V[25];
  A[75] = 4.50123e-14*V[23]*V[31];
  A[76] = 3.33437e-14*V[26]*F[4];
  A[77] = 7.15352e-11*V[23]*V[26];
  A[78] = 6.25037e-12*V[8]*F[2];
  A[79] = 5.88365e-14*V[0]*F[2];
  A[80] = 9.37792e-16*V[9]*F[2];
  A[81] = 8.85199e-12*V[20]*V[29];
  A[82] = 1.04438e-11*V[20]*V[32];
  A[83] = 6.18205e-12*V[13]*V[25];
  A[84] = RCT[84]*F[2];
  A[85] = RCT[85]*V[28];
  A[86] = RCT[86]*V[28];
  A[87] = RCT[87]*V[32];
  A[88] = RCT[88]*V[16];
  A[89] = RCT[89]*V[33];
  A[90] = RCT[90]*V[22];
  A[91] = RCT[91]*V[22];
  A[92] = RCT[92]*V[11];
  A[93] = RCT[93]*V[18];
  A[94] = RCT[94]*V[14];
  A[95] = RCT[95]*V[14];
  A[96] = RCT[96]*V[1];
  A[97] = RCT[97]*V[4];
  A[98] = RCT[98]*V[2];
  A[99] = RCT[99]*V[17];
  A[100] = RCT[100]*V[21];
  A[101] = RCT[101]*V[21];
  A[102] = RCT[102]*V[5];
  A[103] = RCT[103]*V[30];
  A[104] = RCT[104]*V[6];
  A[105] = RCT[105]*V[7];
  A[106] = RCT[106]*V[23];
  A[107] = RCT[107]*V[23];
  A[108] = RCT[108]*V[13];

/* Aggregate function                                               */
  Vdot[0] = A[8]+A[73]+A[76]-A[79];
  Vdot[1] = A[50]+A[58]-A[96];
  Vdot[2] = A[51]-A[53]-A[98];
  Vdot[3] = A[36]+A[49]-A[52]+A[68]+A[98];
  Vdot[4] = A[48]+A[67]-A[97];
  Vdot[5] = A[69]-A[102];
  Vdot[6] = A[64]-A[104];
  Vdot[7] = A[66]-A[105];
  Vdot[8] = A[62]+A[74]+A[75]+A[77]-A[78]+A[106];
  Vdot[9] = -A[80]+A[81]+A[108];
  Vdot[10] = -A[2]-A[3]-A[4]-A[5]-A[6]-A[7]-A[8]+A[86];
  Vdot[11] = A[30]-A[31]-A[35]-A[92];
  Vdot[12] = A[61]+A[62]-A[71];
  Vdot[13] = A[82]-A[83]-A[108];
  Vdot[14] = A[27]-A[33]-A[34]-A[94]-A[95];
  Vdot[15] = A[38]+A[39]+A[41]+A[44]-A[54]+A[76]+A[77];
  Vdot[16] = A[19]+A[20]-A[21]-A[41]-A[88];
  Vdot[17] = A[45]-A[55]+A[57]+A[59]-A[99];
  Vdot[18] = A[26]-A[32]+2*A[35]+A[59]-A[93];
  Vdot[19] = A[6]-A[9]-A[10]+A[11]+A[13]-A[17]+A[38]+A[72]+A[106];
  Vdot[20] = A[79]-A[81]-A[82]+A[83];
  Vdot[21] = A[47]-A[56]-A[57]-A[58]-A[59]-A[100]-A[101];
  Vdot[22] = A[25]-A[28]-A[29]-A[30]+A[31]+A[32]+A[56]+A[57]+A[58]
            -A[90]-A[91]+A[92]+A[94]+A[100]+A[105];
  Vdot[23] = A[7]-A[62]-A[74]-A[75]-A[77]+A[80]-A[106]-A[107];
  Vdot[24] = -A[60]-A[61]-A[62]+A[63]+A[65]+A[67]+A[68]+2*A[70]+A[71]
            +A[102]+A[103]+A[104]+A[105];
  Vdot[25] = 2*A[5]+A[6]+A[8]+A[10]-A[11]-A[12]-A[13]-2*A[14]+A[15]
            +A[16]+2*A[17]-A[18]-A[21]+A[23]-A[26]-A[32]-A[33]+A[40]
            -A[43]-A[44]-A[54]-A[55]-A[57]-A[71]-A[72]-A[73]-A[74]
            +A[75]-A[83]+A[87]+2*A[88]+A[93]+A[94]+A[99]+A[104]+A[108];
  Vdot[26] = -A[36]-A[37]-A[38]-A[39]-A[40]-A[41]+A[42]+A[43]+A[46]
            +A[48]+A[49]+A[52]+A[54]-A[58]-A[76]-A[77]+2*A[96]+A[98]
            +A[99]+A[100]+A[101]+A[102];
  Vdot[27] = A[37]+A[40]-A[42]-A[43]-A[44]-A[45]-A[46]-A[47]-2*A[48]-2
            *A[49]-2*A[50]-2*A[51]+2*A[53]+A[55]+A[56]-A[67]-A[68]
            -A[69]+A[97];
  Vdot[28] = A[0]-A[1]-A[4]-A[10]-A[12]-A[16]-A[22]-A[25]-A[37]-A[60]
            -A[85]-A[86];
  Vdot[29] = -A[22]-A[23]+A[24]-A[29]-A[46]-A[65]-A[81]+A[89]+A[91];
  Vdot[30] = A[60]-A[63]-A[64]-A[65]-A[66]-A[67]-A[68]-A[69]-2*A[70]
            -A[103];
  Vdot[31] = -A[0]-A[1]+A[2]+A[3]-A[13]+A[14]-A[15]-A[24]-A[28]-A[42]
            -A[56]-A[63]-A[75]+2*A[84]+A[85]+A[87]+A[89]+A[90]+A[97]
            +A[101]+A[103];
  Vdot[32] = A[9]+A[12]-A[15]-A[16]-A[17]-A[18]-2*A[19]-2*A[20]+A[21]
            -A[23]-A[27]+A[34]-A[39]-A[40]+A[41]+A[43]-A[45]-A[61]
            -A[64]+A[78]+A[80]-A[82]-A[87]+A[95];
  Vdot[33] = A[22]+A[23]-A[24]-A[25]-A[26]-A[27]+A[28]+2*A[29]-A[30]
            +A[31]+A[33]+A[34]+A[46]-A[47]+A[65]-A[66]+A[81]-A[89]
            +A[90]+A[92]+A[93]+A[95]+A[101];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


