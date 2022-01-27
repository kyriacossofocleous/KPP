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
/* File                 : cbm4_Function.c                           */
/* Time                 : Thu Jan 27 12:38:55 2022                  */
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
  double V[],                            /* Concentrations of variable species (local) */
  double F[],                            /* Concentrations of fixed species (local) */
  double RCT[],                          /* Rate constants (local) */
  double Vdot[]                          /* Time derivative of variable species concentrations */
)
{

/* Local variables                                                  */
double A[NREACT];                        /* Rate for each equation */

/* Computation of equation rates                                    */
  A[0] = RCT[0]*V[25];
  A[1] = RCT[1]*V[28];
  A[2] = RCT[2]*V[24]*V[30];
  A[3] = 9.3e-12*V[25]*V[28];
  A[4] = RCT[4]*V[25]*V[28];
  A[5] = RCT[5]*V[28]*V[30];
  A[6] = RCT[6]*V[24]*V[25];
  A[7] = RCT[7]*V[24];
  A[8] = RCT[8]*V[24];
  A[9] = RCT[9]*V[0];
  A[10] = 2.2e-10*V[0]*F[0];
  A[11] = RCT[11]*V[24]*V[26];
  A[12] = RCT[12]*V[24]*V[27];
  A[13] = RCT[13]*V[29];
  A[14] = RCT[14]*V[29]*V[30];
  A[15] = RCT[15]*V[25]*V[29];
  A[16] = RCT[16]*V[25]*V[29];
  A[17] = 1.3e-21*V[5]*F[0];
  A[18] = RCT[18]*V[5];
  A[19] = RCT[19]*V[30]*V[30];
  A[20] = 4.39999e-40*V[25]*V[30]*F[0];
  A[21] = RCT[21]*V[26]*V[30];
  A[22] = RCT[22]*V[8];
  A[23] = 6.6e-12*V[8]*V[26];
  A[24] = 1e-20*V[8]*V[8];
  A[25] = RCT[25]*V[25]*V[26];
  A[26] = RCT[26]*V[11]*V[26];
  A[27] = RCT[27]*V[27]*V[30];
  A[28] = RCT[28]*V[25]*V[27];
  A[29] = RCT[29]*V[9];
  A[30] = RCT[30]*V[9]*V[26];
  A[31] = RCT[31]*V[27]*V[27];
  A[32] = RCT[32]*V[27]*V[27]*F[0];
  A[33] = RCT[33]*V[1];
  A[34] = RCT[34]*V[1]*V[26];
  A[35] = 2.2e-13*V[15]*V[26];
  A[36] = 1e-11*V[20]*V[26];
  A[37] = RCT[37]*V[20];
  A[38] = RCT[38]*V[20];
  A[39] = RCT[39]*V[20]*V[28];
  A[40] = 6.3e-16*V[20]*V[29];
  A[41] = RCT[41]*V[23]*V[28];
  A[42] = RCT[42]*V[23]*V[26];
  A[43] = 2.5e-15*V[23]*V[29];
  A[44] = RCT[44]*V[23];
  A[45] = RCT[45]*V[30]*V[31];
  A[46] = RCT[46]*V[25]*V[31];
  A[47] = RCT[47]*V[2];
  A[48] = 2e-12*V[31]*V[31];
  A[49] = 6.5e-12*V[27]*V[31];
  A[50] = RCT[50]*V[26];
  A[51] = 8.1e-13*V[19]*V[26];
  A[52] = RCT[52]*V[12];
  A[53] = 1600*V[12];
  A[54] = 1.5e-11*V[12]*V[25];
  A[55] = RCT[55]*V[22]*V[28];
  A[56] = RCT[56]*V[22]*V[26];
  A[57] = RCT[57]*V[22]*V[24];
  A[58] = 7.7e-15*V[22]*V[29];
  A[59] = RCT[59]*V[16]*V[28];
  A[60] = RCT[60]*V[16]*V[26];
  A[61] = RCT[61]*V[16]*V[24];
  A[62] = RCT[62]*V[4]*V[26];
  A[63] = 8.1e-12*V[10]*V[30];
  A[64] = 4.2*V[10];
  A[65] = 4.1e-11*V[13]*V[26];
  A[66] = 2.2e-11*V[13]*V[29];
  A[67] = 1.4e-11*V[3]*V[25];
  A[68] = RCT[68]*V[6]*V[26];
  A[69] = 3e-11*V[18]*V[26];
  A[70] = RCT[70]*V[18];
  A[71] = RCT[71]*V[18]*V[24];
  A[72] = 1.7e-11*V[14]*V[26];
  A[73] = RCT[73]*V[14];
  A[74] = 1.8e-11*V[21]*V[28];
  A[75] = 9.6e-11*V[21]*V[26];
  A[76] = 1.2e-17*V[21]*V[24];
  A[77] = 3.2e-13*V[21]*V[29];
  A[78] = 8.1e-12*V[17]*V[30];
  A[79] = RCT[79]*V[17]*V[17];
  A[80] = 6.8e-13*V[7]*V[30];

/* Aggregate function                                               */
  Vdot[0] = A[8]-A[9]-A[10];
  Vdot[1] = A[31]+A[32]-A[33]-A[34];
  Vdot[2] = A[46]-A[47];
  Vdot[3] = 0.4*A[65]+A[66]-A[67];
  Vdot[4] = -A[62];
  Vdot[5] = A[16]-A[17]-A[18];
  Vdot[6] = -A[68];
  Vdot[7] = 0.13*A[51]+0.04*A[52]+0.02*A[55]+0.09*A[58]+0.13*A[75]
           +A[77]-A[80];
  Vdot[8] = 2*A[20]+A[21]-A[22]-A[23]-2*A[24];
  Vdot[9] = A[28]-A[29]-A[30];
  Vdot[10] = 0.56*A[62]-A[63]-A[64]+0.3*A[68];
  Vdot[11] = 2*A[17]+A[25]-A[26]+A[40]+A[43]+A[66];
  Vdot[12] = 0.76*A[51]-0.98*A[52]-A[53]-A[54];
  Vdot[13] = 0.36*A[62]+A[64]-A[65]-A[66]+0.2*A[68];
  Vdot[14] = 0.8*A[68]+0.2*A[71]-A[72]-A[73]+0.4*A[75]+0.2*A[76];
  Vdot[15] = -A[35]+A[36]+A[37]+A[38]+A[39]+A[40]+A[44]+0.3*A[55]+0.33
            *A[57]+A[59]+0.42*A[61]+2*A[69]+A[70]+0.69*A[71]+A[73]+0.5
            *A[74]+0.06*A[76];
  Vdot[16] = -A[59]-A[60]-A[61]+0.45*A[74]+A[75]+0.55*A[76];
  Vdot[17] = A[44]+A[45]+2*A[48]+0.79*A[49]+A[50]+0.87*A[51]+0.96*A[52]
            +0.28*A[55]+A[56]+0.22*A[57]+0.91*A[58]+0.7*A[59]+A[60]
            +0.08*A[62]+0.6*A[65]+0.5*A[68]+A[69]+0.03*A[71]+A[72]+0.5
            *A[74]+A[75]-A[78]-2*A[79];
  Vdot[18] = 0.9*A[63]+0.3*A[65]-A[69]-A[70]-A[71];
  Vdot[19] = -1.11*A[51]-2.1*A[52]+0.22*A[55]-A[56]-A[57]-A[58]+1.1
            *A[68]+0.9*A[74]+0.1*A[76];
  Vdot[20] = -A[36]-A[37]-A[38]-A[39]-A[40]+A[44]+A[45]+2*A[48]+0.79
            *A[49]+A[50]+0.2*A[55]+A[56]+0.74*A[57]+A[58]+A[59]+1.56
            *A[60]+A[61]+A[69]+0.7*A[71]+A[75]+A[76];
  Vdot[21] = -A[74]-A[75]-A[76]-A[77];
  Vdot[22] = -A[55]-A[56]-A[57]-A[58]+0.55*A[74];
  Vdot[23] = -A[41]-A[42]-A[43]-A[44]+0.11*A[51]+1.1*A[52]+0.63*A[55]
            +A[56]+0.5*A[57]+A[58]+0.22*A[60]+0.03*A[71]+0.8*A[74]+0.2
            *A[75]+0.4*A[76];
  Vdot[24] = A[1]-A[2]-A[6]-A[7]-A[8]-A[11]-A[12]-A[57]-A[61]-A[71]
            -A[76];
  Vdot[25] = -A[0]+A[2]-A[3]-A[4]+A[5]-A[6]+0.89*A[13]+2*A[14]-A[16]
            +A[18]+2*A[19]-A[20]+A[23]+A[24]-A[25]+A[27]-A[28]+A[29]
            +A[30]+A[45]-A[46]+A[47]-A[54]+A[58]+0.9*A[63]-A[67]+A[78];
  Vdot[26] = 2*A[10]-A[11]+A[12]-A[21]+A[22]-A[23]-A[25]-A[26]+A[27]
            -A[30]+2*A[33]-A[34]-A[35]-A[36]+A[39]+A[41]-A[42]+0.79
            *A[49]-A[50]-A[51]+0.2*A[55]-A[56]+0.1*A[57]+0.3*A[59]
            -A[60]-A[62]-A[65]-A[68]-A[69]+0.08*A[71]-A[72]-A[75]+0.1
            *A[76];
  Vdot[27] = A[11]-A[12]-A[27]-A[28]+A[29]-2*A[31]-2*A[32]+A[34]+A[35]
            +A[36]+2*A[37]+A[39]+A[40]+2*A[44]+A[45]+2*A[48]-0.21*A[49]
            +A[50]+0.11*A[51]+0.94*A[52]+A[53]+0.38*A[55]+A[56]+0.44
            *A[57]+1.7*A[59]+A[60]+0.12*A[61]+0.44*A[62]+0.9*A[63]
            +A[64]+0.6*A[65]+0.7*A[68]+2*A[69]+A[70]+0.76*A[71]+A[73]
            +0.6*A[74]+0.67*A[75]+0.44*A[76];
  Vdot[28] = A[0]-A[1]-A[3]-A[4]-A[5]+A[7]+A[9]+0.89*A[13]-A[39]-A[41]
            -A[55]-A[59]-A[74];
  Vdot[29] = A[4]+A[6]-A[13]-A[14]-A[15]-A[16]+A[18]+A[26]-A[40]-A[43]
            -A[58]-A[66]-A[77];
  Vdot[30] = A[0]-A[2]+A[3]-A[5]+0.11*A[13]-A[14]+A[15]-2*A[19]-A[20]
            -A[21]+A[22]+A[24]-A[27]-A[45]-A[63]-A[78]-A[80];
  Vdot[31] = A[41]+A[42]+A[43]-A[45]-A[46]+A[47]-2*A[48]-A[49]+A[69]
            +A[70]+0.62*A[71]+A[72]+A[73]+0.2*A[75];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


