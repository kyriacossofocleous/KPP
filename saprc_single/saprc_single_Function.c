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
/* File                 : saprc_single_Function.c                   */
/* Time                 : Wed Mar  9 11:42:36 2022                  */
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
#include "saprc_single_Parameters.h"
#include "saprc_single_Global.h"
#include "saprc_single_Sparse.h"


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
  A[0] = RCT[0]*V[69];
  A[1] = RCT[1]*V[57]*F[0]*F[1];
  A[2] = RCT[2]*V[57]*V[61];
  A[3] = RCT[3]*V[57]*V[68]*F[0];
  A[4] = RCT[4]*V[57]*V[69];
  A[5] = RCT[5]*V[57]*V[69];
  A[6] = RCT[6]*V[61]*V[68];
  A[7] = RCT[7]*V[61]*V[69];
  A[8] = RCT[8]*V[68]*V[70];
  A[9] = RCT[9]*V[68]*V[68]*F[1];
  A[10] = RCT[10]*V[69]*V[70];
  A[11] = RCT[11]*V[17];
  A[12] = RCT[12]*V[17]*F[2];
  A[13] = RCT[13]*V[69]*V[70];
  A[14] = RCT[14]*V[70];
  A[15] = RCT[15]*V[70];
  A[16] = RCT[16]*V[61];
  A[17] = RCT[17]*V[61];
  A[18] = RCT[18]*V[9]*F[2];
  A[19] = RCT[19]*V[9]*F[0];
  A[20] = RCT[20]*V[68]*V[73];
  A[21] = RCT[21]*V[18];
  A[22] = RCT[22]*V[18];
  A[23] = RCT[23]*V[18]*V[73];
  A[24] = RCT[24]*V[69]*V[73];
  A[25] = RCT[25]*V[70]*V[73];
  A[26] = RCT[26]*V[42]*V[73];
  A[27] = RCT[27]*V[42];
  A[28] = RCT[28]*V[39]*V[73];
  A[29] = RCT[29]*V[61]*V[73];
  A[30] = RCT[30]*V[62]*V[68];
  A[31] = RCT[31]*V[62]*V[69];
  A[32] = RCT[32]*V[24];
  A[33] = RCT[33]*V[24];
  A[34] = RCT[34]*V[24]*V[73];
  A[35] = RCT[35]*V[61]*V[62];
  A[36] = RCT[36]*V[62]*V[62];
  A[37] = RCT[37]*V[62]*V[62]*F[2];
  A[38] = RCT[38]*V[62]*V[70];
  A[39] = RCT[39]*V[70]*V[70];
  A[40] = RCT[40]*V[16];
  A[41] = RCT[41]*V[16]*V[73];
  A[42] = RCT[42]*V[62]*V[73];
  A[43] = RCT[43]*V[8]*V[73];
  A[44] = RCT[44]*V[73]*F[3];
  A[45] = RCT[45]*V[65]*V[68];
  A[46] = RCT[46]*V[62]*V[65];
  A[47] = RCT[47]*V[65]*V[70];
  A[48] = RCT[48]*V[65]*V[65];
  A[49] = RCT[49]*V[65]*V[65];
  A[50] = RCT[50]*V[67]*V[68];
  A[51] = RCT[51]*V[62]*V[67];
  A[52] = RCT[52]*V[67]*V[70];
  A[53] = RCT[53]*V[65]*V[67];
  A[54] = RCT[54]*V[67]*V[67];
  A[55] = RCT[55]*V[47]*V[68];
  A[56] = RCT[56]*V[47]*V[62];
  A[57] = RCT[57]*V[47]*V[70];
  A[58] = RCT[58]*V[47]*V[65];
  A[59] = RCT[59]*V[47]*V[67];
  A[61] = RCT[61]*V[63]*V[68];
  A[62] = RCT[62]*V[62]*V[63];
  A[63] = RCT[63]*V[63]*V[65];
  A[64] = RCT[64]*V[63]*V[70];
  A[65] = RCT[65]*V[63]*V[67];
  A[66] = RCT[66]*V[47]*V[63];
  A[67] = RCT[67]*V[63]*V[63];
  A[68] = RCT[68]*V[69]*V[71];
  A[69] = RCT[69]*V[12];
  A[70] = RCT[70]*V[68]*V[71];
  A[71] = RCT[71]*V[62]*V[71];
  A[72] = RCT[72]*V[70]*V[71];
  A[73] = RCT[73]*V[65]*V[71];
  A[74] = RCT[74]*V[67]*V[71];
  A[75] = RCT[75]*V[47]*V[71];
  A[76] = RCT[76]*V[63]*V[71];
  A[77] = RCT[77]*V[71]*V[71];
  A[78] = RCT[78]*V[69]*V[72];
  A[79] = RCT[79]*V[13];
  A[80] = RCT[80]*V[68]*V[72];
  A[81] = RCT[81]*V[62]*V[72];
  A[82] = RCT[82]*V[70]*V[72];
  A[83] = RCT[83]*V[65]*V[72];
  A[84] = RCT[84]*V[67]*V[72];
  A[85] = RCT[85]*V[47]*V[72];
  A[86] = RCT[86]*V[63]*V[72];
  A[87] = RCT[87]*V[71]*V[72];
  A[88] = RCT[88]*V[72]*V[72];
  A[89] = RCT[89]*V[66]*V[69];
  A[90] = RCT[90]*V[14];
  A[91] = RCT[91]*V[66]*V[68];
  A[92] = RCT[92]*V[62]*V[66];
  A[93] = RCT[93]*V[66]*V[70];
  A[94] = RCT[94]*V[65]*V[66];
  A[95] = RCT[95]*V[66]*V[67];
  A[96] = RCT[96]*V[47]*V[66];
  A[97] = RCT[97]*V[63]*V[66];
  A[98] = RCT[98]*V[66]*V[71];
  A[99] = RCT[99]*V[66]*V[72];
  A[100] = RCT[100]*V[66]*V[66];
  A[101] = RCT[101]*V[64]*V[69];
  A[102] = RCT[102]*V[15];
  A[103] = RCT[103]*V[64]*V[68];
  A[104] = RCT[104]*V[62]*V[64];
  A[105] = RCT[105]*V[64]*V[70];
  A[106] = RCT[106]*V[64]*V[65];
  A[107] = RCT[107]*V[64]*V[67];
  A[108] = RCT[108]*V[47]*V[64];
  A[109] = RCT[109]*V[63]*V[64];
  A[110] = RCT[110]*V[64]*V[71];
  A[111] = RCT[111]*V[64]*V[72];
  A[112] = RCT[112]*V[64]*V[66];
  A[113] = RCT[113]*V[64]*V[64];
  A[114] = RCT[114]*V[21]*V[69];
  A[115] = RCT[115]*V[21];
  A[116] = RCT[116]*V[45]*V[69];
  A[117] = RCT[117]*V[45]*V[62];
  A[118] = RCT[118]*V[45];
  A[119] = RCT[119]*V[27]*V[69];
  A[120] = RCT[120]*V[27]*V[62];
  A[121] = RCT[121]*V[27];
  A[122] = RCT[122]*V[55];
  A[123] = RCT[123]*V[55];
  A[124] = RCT[124]*V[55]*V[73];
  A[125] = RCT[125]*V[55]*V[62];
  A[126] = RCT[126]*V[26];
  A[127] = RCT[127]*V[26]*V[68];
  A[128] = RCT[128]*V[55]*V[70];
  A[129] = RCT[129]*V[54]*V[73];
  A[130] = RCT[130]*V[54];
  A[131] = RCT[131]*V[54]*V[70];
  A[132] = RCT[132]*V[58]*V[73];
  A[133] = RCT[133]*V[58];
  A[134] = RCT[134]*V[58]*V[70];
  A[135] = RCT[135]*V[41]*V[73];
  A[136] = RCT[136]*V[41];
  A[137] = RCT[137]*V[59]*V[73];
  A[138] = RCT[138]*V[59];
  A[139] = RCT[139]*V[28]*V[73];
  A[140] = RCT[140]*V[25]*V[73];
  A[141] = RCT[141]*V[25];
  A[142] = RCT[142]*V[36]*V[73];
  A[143] = RCT[143]*V[36];
  A[144] = RCT[144]*V[44];
  A[145] = RCT[145]*V[44];
  A[146] = RCT[146]*V[44]*V[73];
  A[147] = RCT[147]*V[44]*V[70];
  A[148] = RCT[148]*V[40];
  A[149] = 1.5e-11*V[40]*V[73];
  A[150] = RCT[150]*V[40]*V[70];
  A[151] = RCT[151]*V[11];
  A[152] = RCT[152]*V[38]*V[73];
  A[153] = RCT[153]*V[38]*V[70];
  A[154] = RCT[154]*V[33]*V[73];
  A[155] = RCT[155]*V[33]*V[70];
  A[156] = RCT[156]*V[35]*V[70];
  A[157] = RCT[157]*V[37]*V[73];
  A[158] = RCT[158]*V[37];
  A[159] = RCT[159]*V[37]*V[70];
  A[160] = RCT[160]*V[49]*V[73];
  A[161] = RCT[161]*V[49]*V[61];
  A[162] = RCT[162]*V[49]*V[70];
  A[163] = RCT[163]*V[49]*V[57];
  A[164] = RCT[164]*V[49];
  A[165] = RCT[165]*V[53]*V[73];
  A[166] = RCT[166]*V[53]*V[61];
  A[167] = RCT[167]*V[53]*V[57];
  A[168] = RCT[168]*V[53];
  A[169] = RCT[169]*V[51]*V[73];
  A[170] = RCT[170]*V[51]*V[61];
  A[171] = RCT[171]*V[51]*V[70];
  A[172] = RCT[172]*V[51];
  A[173] = RCT[173]*V[60]*V[73];
  A[174] = RCT[174]*V[60];
  A[175] = RCT[175]*V[56]*V[73];
  A[176] = RCT[176]*V[56];
  A[177] = RCT[177]*V[34]*V[73];
  A[178] = RCT[178]*V[34]*V[61];
  A[179] = RCT[179]*V[31]*V[73];
  A[180] = RCT[180]*V[31];
  A[181] = RCT[181]*V[32]*V[73];
  A[182] = RCT[182]*V[32];
  A[183] = RCT[183]*V[73]*F[4];
  A[184] = RCT[184]*V[43]*V[73];
  A[185] = RCT[185]*V[43]*V[61];
  A[186] = RCT[186]*V[43]*V[70];
  A[187] = RCT[187]*V[43]*V[57];
  A[188] = RCT[188]*V[46]*V[73];
  A[189] = RCT[189]*V[46]*V[61];
  A[190] = RCT[190]*V[46]*V[70];
  A[191] = RCT[191]*V[46]*V[57];
  A[192] = RCT[192]*V[48]*V[73];
  A[193] = RCT[193]*V[48]*V[61];
  A[194] = RCT[194]*V[48]*V[70];
  A[195] = RCT[195]*V[48]*V[57];
  A[196] = RCT[196]*V[10]*V[73];
  A[197] = RCT[197]*V[19]*V[73];
  A[198] = RCT[198]*V[20]*V[73];
  A[199] = RCT[199]*V[29]*V[73];
  A[200] = RCT[200]*V[22]*V[73];
  A[201] = RCT[201]*V[30]*V[73];
  A[202] = RCT[202]*V[23]*V[73];
  A[203] = RCT[203]*V[50]*V[73];
  A[204] = RCT[204]*V[50]*V[61];
  A[205] = RCT[205]*V[50]*V[70];
  A[206] = RCT[206]*V[50]*V[57];
  A[207] = RCT[207]*V[52]*V[73];
  A[208] = RCT[208]*V[52]*V[61];
  A[209] = RCT[209]*V[52]*V[70];
  A[210] = RCT[210]*V[52]*V[57];

/* Aggregate function                                               */
  Vdot[0] = A[43];
  Vdot[1] = A[127]+0.333*A[161]+0.351*A[166]+0.1*A[170]+0.37*A[185]
           +0.204*A[189]+0.103*A[193]+0.121*A[197]+0.185*A[204]+0.073
           *A[208];
  Vdot[2] = 0.25*A[71]+A[73]+A[74]+A[76]+0.05*A[204]+0.129*A[208];
  Vdot[3] = 0.25*A[81]+A[83]+A[84]+A[86]+0.25*A[92]+A[94]+A[95]+A[97]
           +0.25*A[104]+A[106]+A[107]+2*A[109]+0.372*A[170]+0.15*A[189]
           +0.189*A[193]+0.119*A[204]+0.247*A[208];
  Vdot[4] = 0.75*A[71];
  Vdot[5] = 0.75*A[81]+0.75*A[92]+0.75*A[104];
  Vdot[6] = 2*A[119];
  Vdot[7] = 6*A[119]+7*A[158];
  Vdot[8] = -A[43];
  Vdot[9] = A[17]-A[18]-A[19];
  Vdot[10] = -A[196];
  Vdot[11] = -A[151]+0.031*A[193]+0.087*A[202];
  Vdot[12] = A[68]-A[69];
  Vdot[13] = A[78]-A[79];
  Vdot[14] = A[89]-A[90];
  Vdot[15] = A[101]-A[102];
  Vdot[16] = A[36]+A[37]-A[40]-A[41];
  Vdot[17] = A[10]-A[11]-A[12];
  Vdot[18] = A[20]-A[21]-A[22]-A[23];
  Vdot[19] = -A[197];
  Vdot[20] = -A[198];
  Vdot[21] = -A[114]-A[115]+0.236*A[198];
  Vdot[22] = -A[200];
  Vdot[23] = -A[202];
  Vdot[24] = A[31]-A[32]-A[33]-A[34];
  Vdot[25] = A[46]-A[140]-A[141];
  Vdot[26] = A[125]-A[126]-A[127];
  Vdot[27] = -A[119]-A[120]-A[121]+A[156];
  Vdot[28] = A[48]+0.25*A[53]+0.25*A[63]-A[139];
  Vdot[29] = -A[199];
  Vdot[30] = -A[201];
  Vdot[31] = -A[179]-A[180]+0.108*A[201]+0.099*A[202];
  Vdot[32] = -A[181]-A[182]+0.051*A[201]+0.093*A[202];
  Vdot[33] = -A[154]-A[155]+0.207*A[201]+0.187*A[202];
  Vdot[34] = -A[177]-A[178]+0.491*A[201]+0.561*A[202];
  Vdot[35] = A[116]+A[120]+A[121]-A[156];
  Vdot[36] = A[51]+A[62]-A[142]-A[143];
  Vdot[37] = -A[157]-A[158]-A[159]+0.059*A[201]+0.05*A[202]+0.061
            *A[207]+0.042*A[208]+0.015*A[209];
  Vdot[38] = A[117]+A[118]-A[152]-A[153]+0.017*A[201];
  Vdot[39] = -A[28]+A[122]+A[123]+A[124]+A[128]+A[130]+0.034*A[132]
            +A[133]+2*A[144]+A[145]+1.26*A[146]+1.26*A[147]+A[148]
            +A[149]+A[150]+0.416*A[160]+0.45*A[161]+0.5*A[162]+0.67
            *A[164]+0.475*A[166]+0.7*A[168]+0.336*A[169]+0.498*A[170]
            +0.572*A[171]+1.233*A[172]+A[177]+1.5*A[178]+A[180]+A[182]
            +0.5*A[185]+0.491*A[187]+0.275*A[189]+0.157*A[193]+0.16
            *A[197]+0.002*A[199]+0.345*A[204]+0.265*A[208]+0.012*A[210];
  Vdot[40] = -A[148]-A[149]-A[150]+0.23*A[154]+0.084*A[160]+0.9*A[161]
            +0.3*A[165]+0.95*A[166]+0.174*A[169]+0.742*A[170]+0.008
            *A[171]+0.5*A[180]+0.5*A[182]+0.119*A[201]+0.287*A[202];
  Vdot[41] = A[115]-A[135]-A[136]+0.006*A[175]+0.02*A[176]+0.13*A[193]
            +0.417*A[197]+0.024*A[198]+0.452*A[199]+0.072*A[200]+0.005
            *A[203]+0.001*A[204]+0.024*A[205]+0.127*A[207]+0.045*A[208]
            +0.102*A[209];
  Vdot[42] = 2*A[12]+A[24]-A[26]-A[27]+0.2*A[38]+A[128]+A[131]+A[134]
            +A[147]+A[150]+A[153]+A[155]+A[156]+A[159]+0.5*A[162]+0.15
            *A[171];
  Vdot[43] = -A[184]-A[185]-A[186]-A[187];
  Vdot[44] = -A[144]-A[145]-A[146]-A[147]+0.23*A[152]+0.15*A[169]+0.023
            *A[170]+A[178]+0.5*A[180]+0.5*A[182]+0.009*A[187]+0.001
            *A[193]+0.248*A[197]+0.118*A[201]+0.097*A[202];
  Vdot[45] = A[91]+A[93]+A[98]+A[99]+2*A[100]+A[112]-A[116]-A[117]
            -A[118]+0.24*A[152]+A[153]+0.24*A[154]+A[155];
  Vdot[46] = -A[188]-A[189]-A[190]-A[191];
  Vdot[47] = -A[55]-A[56]-A[57]-A[58]-A[59]-A[66]-A[75]-A[85]+A[91]
            +A[93]-A[96]+A[98]+A[99]+2*A[100]-A[108]+A[112]+A[135]
            +0.616*A[137]+0.675*A[165]+0.515*A[174]+0.596*A[175]+0.152
            *A[176]+A[179]+A[180]+A[181]+A[182]+0.079*A[188]+0.126
            *A[189]+0.187*A[190]+0.24*A[191]+0.5*A[192]+0.729*A[193]
            +0.75*A[194]+0.559*A[198]+0.936*A[199]+0.948*A[200]+0.205
            *A[203]+0.488*A[205]+0.001*A[207]+0.137*A[208]+0.711*A[209];
  Vdot[48] = -A[192]-A[193]-A[194]-A[195];
  Vdot[49] = -A[160]-A[161]-A[162]-A[163]-A[164]+0.23*A[188]+0.39
            *A[189]+0.025*A[207]+0.026*A[208]+0.012*A[210];
  Vdot[50] = -A[203]-A[204]-A[205]-A[206];
  Vdot[51] = -A[169]-A[170]-A[171]-A[172]+0.357*A[188]+0.936*A[190]
            +0.025*A[207];
  Vdot[52] = -A[207]-A[208]-A[209]-A[210];
  Vdot[53] = -A[165]-A[166]-A[167]-A[168]+0.32*A[188]+0.16*A[189]+0.019
            *A[208]+0.048*A[209];
  Vdot[54] = A[80]+A[82]+A[87]+2*A[88]+A[99]+A[111]-A[129]-A[130]
            -A[131]+0.034*A[132]+A[133]+0.482*A[137]+A[138]+0.129
            *A[169]+0.047*A[170]+0.467*A[172]+0.084*A[173]+0.246*A[174]
            +0.439*A[175]+0.431*A[176]+0.195*A[184]+0.25*A[187]+A[196]
            +0.445*A[198]+0.455*A[199]+0.099*A[200]+0.294*A[203]+0.154
            *A[204]+0.009*A[205]+0.732*A[207]+0.456*A[208]+0.507*A[209];
  Vdot[55] = A[45]+A[47]+A[48]+2*A[49]+0.75*A[53]+0.75*A[63]+A[73]
            +A[83]+A[94]+A[103]+A[105]+A[106]+A[110]+A[111]+A[112]+2
            *A[113]-A[122]-A[123]-A[124]-A[125]+A[126]-A[128]+A[135]
            +0.115*A[137]+A[139]+0.35*A[140]+A[141]+A[145]+0.084*A[160]
            +0.2*A[161]+0.67*A[164]+0.3*A[165]+0.1*A[166]+0.055*A[169]
            +0.125*A[170]+0.227*A[171]+0.3*A[172]+0.213*A[173]+0.506
            *A[174]+0.01*A[175]+0.134*A[176]+1.61*A[184]+A[185]+0.191
            *A[187]+0.624*A[188]+0.592*A[189]+0.24*A[191]+0.276*A[192]
            +0.235*A[193]+0.039*A[197]+0.026*A[198]+0.024*A[199]+0.026
            *A[200]+0.732*A[203]+0.5*A[204]+0.244*A[207]+0.269*A[208]
            +0.079*A[209];
  Vdot[56] = A[61]+A[114]+0.572*A[171]-0.69*A[175]-A[176]+0.276*A[194]
            +0.511*A[205]+0.321*A[209];
  Vdot[57] = A[0]-A[1]-A[2]-A[3]-A[4]-A[5]+A[15]+A[16]+A[19]-A[163]
            -A[167]-A[187]-A[191]-A[195]-A[206]-A[210];
  Vdot[58] = -A[132]-A[133]-A[134]+0.37*A[137]+A[142]+A[143]+A[163]
            +0.675*A[165]+0.45*A[167]+0.013*A[169]+0.218*A[171]+0.558
            *A[173]+0.71*A[174]+0.213*A[175]+0.147*A[176]+A[177]+A[179]
            +A[181]+A[186]+0.474*A[192]+0.205*A[193]+0.474*A[194]+0.147
            *A[195]+0.155*A[197]+0.122*A[198]+0.244*A[199]+0.204*A[200]
            +0.497*A[203]+0.363*A[204]+0.037*A[205]+0.45*A[206]+0.511
            *A[207]+0.305*A[208]+0.151*A[209]+0.069*A[210];
  Vdot[59] = 0.5*A[63]+A[64]+0.5*A[65]+A[67]-A[137]-A[138]+0.416*A[160]
            +0.55*A[167]+0.15*A[169]+0.21*A[170]+0.233*A[172]+0.115
            *A[173]+0.177*A[175]+0.243*A[176]+0.332*A[198]+0.11*A[199]
            +0.089*A[200]+0.437*A[206]+0.072*A[207]+0.026*A[208]+0.001
            *A[209]+0.659*A[210];
  Vdot[60] = 0.5*A[63]+0.5*A[65]+A[67]+A[76]+A[86]+A[97]+0.7*A[168]
            +0.332*A[169]-0.671*A[173]-A[174]+0.048*A[175]+0.435*A[176]
            +0.1*A[189]+0.75*A[191]+0.276*A[192]+0.276*A[193]+0.853
            *A[195]+0.125*A[199]+0.417*A[200]+0.055*A[201]+0.119*A[203]
            +0.215*A[204]+0.113*A[206]+0.043*A[208]+0.259*A[210];
  Vdot[61] = A[1]-A[2]-A[6]-A[7]-A[16]-A[17]-A[29]-A[35]+0.25*A[71]
            +0.25*A[81]+0.25*A[92]+0.25*A[104]-A[161]-A[166]-A[170]
            -A[178]-A[185]-A[189]-A[193]-A[204]-A[208];
  Vdot[62] = A[22]+A[25]+A[28]+A[29]-A[30]-A[31]+A[32]+0.61*A[33]-A[35]
            -2*A[36]-2*A[37]-A[38]+A[41]-A[42]+A[43]+A[44]+A[45]-A[46]
            +A[47]+2*A[49]+A[50]-A[51]+A[52]+A[53]+A[54]-A[62]+A[63]
            +A[64]+A[65]+A[67]-A[71]-A[81]-A[92]-A[104]-A[117]-A[120]+2
            *A[122]+A[124]-A[125]+A[126]+A[127]+A[128]+A[130]+A[133]
            +A[139]+A[141]+A[143]+2*A[144]+0.63*A[146]+0.63*A[147]
            +A[148]+0.008*A[161]+0.34*A[164]+0.064*A[166]+0.4*A[170]
            +1.233*A[172]+0.379*A[173]+0.113*A[175]+0.341*A[176]+1.5
            *A[178]+0.5*A[180]+0.5*A[182]+0.12*A[185]+0.5*A[187]+0.033
            *A[193]+0.121*A[197]+0.224*A[201]+0.187*A[202]+0.056*A[204]
            +0.003*A[208]+0.013*A[210];
  Vdot[63] = -A[61]-A[62]-A[63]-A[64]-A[65]-2*A[67]-A[76]-A[86]-A[97]
            -A[109]+0.001*A[132]+0.042*A[137]+0.025*A[165]+0.041*A[169]
            +0.051*A[171]+0.07*A[173]+0.04*A[174]+0.173*A[175]+0.095
            *A[176]+0.093*A[188]+0.008*A[189]+0.064*A[190]+0.01*A[191]
            +0.25*A[192]+0.18*A[193]+0.25*A[194]+0.021*A[197]+0.07
            *A[198]+0.143*A[199]+0.347*A[200]+0.011*A[201]+0.009*A[202]
            +0.09*A[203]+0.001*A[204]+0.176*A[205]+0.082*A[207]+0.002
            *A[208]+0.136*A[209]+0.001*A[210];
  Vdot[64] = -A[101]+A[102]-A[103]-A[104]-A[105]-A[106]-A[107]-A[109]
            -A[110]-A[111]-A[112]-2*A[113]+0.5*A[160]+0.5*A[162]+0.33
            *A[164]+0.3*A[168]+0.289*A[169]+0.15*A[171]+0.192*A[189]
            +0.24*A[191];
  Vdot[65] = -A[45]-A[46]-A[47]-2*A[48]-2*A[49]-A[53]-A[63]+A[70]+A[72]
            -A[73]+2*A[77]-A[83]+A[87]-A[94]+A[98]-A[106]+A[110]+A[115]
            +A[130]+A[136]+0.65*A[140]+0.3*A[168]+A[183]+0.3*A[187]
            +0.25*A[191]+0.011*A[199]+0.076*A[204]+0.197*A[208]+0.03
            *A[209];
  Vdot[66] = -A[89]+A[90]-A[91]-A[92]-A[93]-A[94]-A[95]-A[97]-A[98]
            -A[99]-2*A[100]-A[112]+A[157]+A[159];
  Vdot[67] = -A[50]-A[51]-A[52]-A[53]-2*A[54]-A[65]-A[74]+A[80]+A[82]
            -A[84]+A[87]+2*A[88]-A[95]+A[99]-A[107]+A[111]+0.034*A[132]
            +A[133]+0.37*A[137]+A[138]+0.34*A[142]+0.76*A[152]+0.76
            *A[154]+0.5*A[160]+0.1*A[161]+0.5*A[162]+0.33*A[164]+0.3
            *A[165]+0.05*A[166]+0.67*A[169]+0.048*A[170]+0.799*A[171]
            +0.473*A[173]+0.96*A[174]+0.376*A[175]+0.564*A[176]+A[177]
            +A[180]+A[182]+A[184]+A[186]+0.2*A[187]+0.907*A[188]+0.066
            *A[189]+0.749*A[190]+0.75*A[192]+0.031*A[193]+0.276*A[194]
            +A[196]+0.612*A[197]+0.695*A[198]+0.835*A[199]+0.653*A[200]
            +0.765*A[201]+0.804*A[202]+0.91*A[203]+0.022*A[204]+0.824
            *A[205]+0.918*A[207]+0.033*A[208]+0.442*A[209]+0.012*A[210];
  Vdot[68] = A[0]-A[3]+A[4]-A[6]-A[8]-2*A[9]+A[13]+A[14]-A[20]+A[21]
            -A[30]-A[45]-A[50]-A[55]-A[61]-A[70]-A[80]-A[91]-A[103]
            -A[127];
  Vdot[69] = -A[0]+A[3]-A[4]-A[5]+A[6]-A[7]+2*A[8]+2*A[9]-A[10]+A[11]
            +A[15]+A[22]+A[23]-A[24]+A[25]+A[27]+A[30]-A[31]+A[32]+0.61
            *A[33]+A[34]+0.8*A[38]+2*A[39]+A[45]+A[47]+A[50]+A[52]
            +A[55]+A[57]+A[64]-A[68]+A[69]+A[70]+A[72]-A[78]+A[79]
            +A[80]+A[82]-A[89]+A[90]+A[91]+A[93]-A[101]+A[102]+A[103]
            +A[105]-A[114]-A[116]-A[119]+A[127]+0.338*A[175]+A[176]
            +0.187*A[190]+0.474*A[194]+0.391*A[209];
  Vdot[70] = A[5]+A[7]-A[8]-A[10]+A[11]-A[13]-A[14]-A[15]-A[25]+A[26]
            +0.39*A[33]-A[38]-2*A[39]-A[47]-A[52]-A[57]-A[64]-A[72]
            -A[82]-A[93]-A[105]-A[128]-A[131]-A[134]-A[147]-A[150]
            -A[153]-A[155]-A[156]-A[159]-A[162]-A[171]-A[186]-A[190]
            -A[194]-A[205]-A[209];
  Vdot[71] = -A[68]+A[69]-A[70]-A[71]-A[72]-A[73]-A[74]-A[76]-2*A[77]
            -A[87]-A[98]+A[103]+A[105]+A[111]+A[112]+2*A[113]+A[129]
            +A[131]+A[135]+A[136]+0.492*A[137]+A[138]+A[148]+A[149]
            +A[150]+2*A[151]+0.67*A[164]+0.675*A[165]+0.467*A[172]
            +0.029*A[173]+0.667*A[174]+A[179]+0.5*A[180]+A[181]+0.5
            *A[182]+0.123*A[193]+0.011*A[199]+0.137*A[208];
  Vdot[72] = -A[78]+A[79]-A[80]-A[81]-A[82]-A[83]-A[84]-A[86]-A[87]-2
            *A[88]-A[99]-A[111]+0.965*A[132]+A[134]+0.096*A[137]+0.37
            *A[146]+0.37*A[147]+0.1*A[161]+0.05*A[166]+0.048*A[170]+0.3
            *A[172]+0.049*A[173]+0.333*A[174]+0.201*A[193]+0.006*A[208];
  Vdot[73] = 2*A[18]-A[20]+A[21]-A[23]-A[24]-A[25]-A[26]+A[27]-A[28]
            -A[29]+A[30]+0.39*A[33]-A[34]+A[35]+0.8*A[38]+2*A[40]-A[41]
            -A[42]-A[43]-A[44]-A[124]-A[129]-A[132]-A[135]-A[137]
            -A[139]-0.65*A[140]+A[141]-0.34*A[142]+A[143]-A[146]-A[149]
            -A[152]-A[154]-A[157]-A[160]+0.208*A[161]+0.33*A[164]
            -A[165]+0.164*A[166]-A[169]+0.285*A[170]-A[173]-A[175]
            -A[177]+0.5*A[178]-A[179]-A[181]-A[183]-A[184]+0.12*A[185]
            -A[188]+0.266*A[189]-A[192]+0.567*A[193]-A[196]-0.754
            *A[197]-A[198]-A[199]-A[200]-A[201]-A[202]-A[203]+0.155
            *A[204]-A[207]+0.378*A[208];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


