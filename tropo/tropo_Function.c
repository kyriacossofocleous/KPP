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
/* File                 : tropo_Function.c                          */
/* Time                 : Thu Jan 27 12:39:16 2022                  */
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
#include <float.h>
#include "tropo_Parameters.h"
#include "tropo_Global.h"
#include "tropo_Sparse.h"


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
  A[0] = RCT[0]*V[75];
  A[1] = RCT[1]*V[73]*V[80];
  A[2] = RCT[2]*V[73]*V[75];
  A[3] = RCT[3]*V[80]*V[82];
  A[4] = 1.45e-12*V[75]*V[82];
  A[5] = 5e-06*V[25];
  A[6] = RCT[6]*V[75]*V[82];
  A[7] = RCT[7]*V[82];
  A[8] = 2.5e-12*V[81]*V[82];
  A[9] = RCT[9]*V[73];
  A[10] = 7.218e-12*V[80]*V[83];
  A[11] = RCT[11]*V[26];
  A[12] = 1.2794e-11*V[75]*V[83];
  A[13] = RCT[13]*V[56];
  A[14] = RCT[14]*V[56]*V[83];
  A[15] = 1.3e-21*V[25]*F[1];
  A[16] = 1.7823e-13*V[40]*V[83];
  A[17] = RCT[17]*V[73]*V[83];
  A[18] = RCT[18]*V[80]*V[81];
  A[19] = 1.7851e-12*V[75]*V[81];
  A[20] = 6.8868e-06*V[30];
  A[21] = RCT[21]*V[73]*V[81];
  A[22] = 4.7165e-12*V[81]*V[81];
  A[23] = RCT[23]*V[22];
  A[24] = RCT[24]*V[22]*V[83];
  A[25] = 4e-24*V[75]*F[1];
  A[26] = RCT[26]*V[30];
  A[27] = RCT[27]*V[30]*V[83];
  A[28] = 1e-20*V[77]*V[83];
  A[29] = RCT[29]*V[76];
  A[30] = RCT[30]*V[76];
  A[31] = 1e-11*V[76]*V[83];
  A[32] = 1e-14*V[76]*V[81];
  A[33] = RCT[33]*V[36]*V[80];
  A[34] = 2e-12*V[36]*V[81];
  A[35] = 1e-13*V[36]*V[36];
  A[36] = 3.2e-13*V[32]*V[83];
  A[37] = 6e-16*V[76]*V[82];
  A[38] = RCT[38]*V[78]*V[83];
  A[39] = 2.7e-15*V[78]*V[82];
  A[40] = RCT[40]*V[78];
  A[41] = RCT[41]*V[78];
  A[42] = 4.7e-12*V[71]*V[75];
  A[43] = RCT[43]*V[31];
  A[44] = RCT[44]*V[71]*V[80];
  A[45] = RCT[45]*V[64]*V[80];
  A[46] = RCT[46]*V[28]*V[83];
  A[47] = RCT[47]*V[18]*V[83];
  A[48] = RCT[48]*V[50]*V[80];
  A[49] = RCT[49]*V[19]*V[83];
  A[50] = RCT[50]*V[45]*V[80];
  A[51] = RCT[51]*V[29]*V[83];
  A[52] = RCT[52]*V[60]*V[80];
  A[53] = 4e-17*V[29]*V[82];
  A[54] = 2e-12*V[27]*V[83];
  A[55] = RCT[55]*V[37]*V[80];
  A[56] = RCT[56]*V[64]*V[64];
  A[57] = 5e-14*V[50]*V[50];
  A[58] = 5e-14*V[45]*V[45];
  A[59] = 3e-12*V[64]*V[81];
  A[60] = 3e-12*V[50]*V[81];
  A[61] = 3e-12*V[45]*V[81];
  A[62] = 3e-12*V[60]*V[81];
  A[63] = 3e-12*V[71]*V[81];
  A[64] = RCT[64]*V[61]*V[83];
  A[65] = RCT[65]*V[62]*V[80];
  A[66] = RCT[66]*V[61];
  A[67] = 7e-16*V[61]*V[82];
  A[68] = 3e-12*V[62]*V[81];
  A[69] = RCT[69]*V[39]*V[83];
  A[70] = RCT[70]*V[46]*V[80];
  A[71] = RCT[71]*V[59]*V[83];
  A[72] = RCT[72]*V[47]*V[80];
  A[73] = RCT[73]*V[39]*V[73];
  A[74] = RCT[74]*V[59]*V[73];
  A[75] = 7e-12*V[79]*V[80];
  A[76] = 7e-13*V[75]*V[79];
  A[77] = 4e-18*V[79]*F[1];
  A[78] = 7e-12*V[66]*V[80];
  A[79] = 7e-13*V[66]*V[75];
  A[80] = 4e-18*V[66]*F[1];
  A[81] = 5e-14*V[46]*V[46];
  A[82] = 5e-14*V[47]*V[47];
  A[83] = 3e-12*V[46]*V[81];
  A[84] = 3e-12*V[47]*V[81];
  A[85] = 7e-14*V[77]*V[79];
  A[86] = 7e-14*V[66]*V[77];
  A[87] = 1.26e-13*V[59]*V[82];
  A[88] = 6.8e-12*V[51]*V[75];
  A[89] = 3e-12*V[51]*V[81];
  A[90] = RCT[90]*V[51]*V[80];
  A[91] = 1.36e-14*V[76]*V[79];
  A[92] = 1.36e-14*V[78]*V[79];
  A[93] = 1.36e-14*V[66]*V[76];
  A[94] = 1.36e-14*V[66]*V[78];
  A[95] = 1.52e-11*V[23]*V[83];
  A[96] = RCT[96]*V[43]*V[80];
  A[97] = RCT[97]*V[34];
  A[98] = 1.15e-11*V[34]*V[83];
  A[99] = RCT[99]*V[41];
  A[100] = 1.73e-11*V[41]*V[83];
  A[101] = 4.25e-11*V[35]*V[83];
  A[102] = 1e-11*V[35]*V[82];
  A[103] = 2.8e-11*V[33]*V[83];
  A[104] = 4.7e-12*V[53]*V[75];
  A[105] = RCT[105]*V[24];
  A[106] = RCT[106]*V[53]*V[80];
  A[107] = RCT[107]*V[38]*V[80];
  A[108] = RCT[108]*V[33];
  A[109] = 4e-12*V[43]*V[81];
  A[110] = 4e-12*V[53]*V[81];
  A[111] = 1e-12*V[38]*V[81];
  A[112] = RCT[112]*V[36];
  A[113] = RCT[113]*V[63]*V[83];
  A[114] = RCT[114]*V[52]*V[80];
  A[115] = 3e-12*V[52]*V[81];
  A[116] = RCT[116]*V[74]*V[83];
  A[117] = RCT[117]*V[58]*V[80];
  A[118] = 3e-12*V[58]*V[81];
  A[119] = 1.02e-11*V[72]*V[83];
  A[120] = 4.7e-12*V[65]*V[75];
  A[121] = RCT[121]*V[20];
  A[122] = RCT[122]*V[65]*V[80];
  A[123] = 3e-12*V[65]*V[81];
  A[124] = RCT[124]*V[72]*V[83];
  A[125] = RCT[125]*V[48]*V[80];
  A[126] = 3e-12*V[48]*V[81];
  A[127] = 1.5e-11*V[44]*V[83];
  A[128] = 4.7e-12*V[55]*V[75];
  A[129] = RCT[129]*V[21];
  A[130] = RCT[130]*V[55]*V[80];
  A[131] = 3e-12*V[55]*V[81];
  A[132] = RCT[132]*V[63]*V[73];
  A[133] = RCT[133]*V[73]*V[74];
  A[134] = RCT[134]*V[72]*V[73];
  A[135] = RCT[135]*V[68]*V[80];
  A[136] = RCT[136]*V[68]*V[75];
  A[137] = 3.4e-18*V[68]*F[1];
  A[138] = RCT[138]*V[69]*V[80];
  A[139] = RCT[139]*V[69]*V[75];
  A[140] = 3.4e-18*V[69]*F[1];
  A[141] = RCT[141]*V[67]*V[80];
  A[142] = RCT[142]*V[67]*V[75];
  A[143] = 3.4e-18*V[67]*F[1];
  A[144] = RCT[144]*V[44];
  A[145] = RCT[145]*V[57];
  A[146] = 1.7e-11*V[57]*V[83];
  A[147] = RCT[147]*V[63]*V[82];
  A[148] = RCT[148]*V[54]*V[80];
  A[149] = RCT[149]*V[54]*V[75];
  A[150] = 3e-12*V[54]*V[81];
  A[151] = 6e-14*V[74]*V[82];
  A[152] = RCT[152]*V[49]*V[80];
  A[153] = 3e-12*V[49]*V[81];
  A[154] = 3.3e-15*V[72]*V[82];
  A[155] = 6.7e-15*V[72]*V[82];
  A[156] = RCT[156]*V[42]*V[80];
  A[157] = 3e-12*V[42]*V[81];
  A[158] = 5.2e-16*V[44]*V[82];
  A[159] = 3e-12*V[69]*V[81];
  A[160] = 3e-12*V[68]*V[81];
  A[161] = 7e-14*V[68]*V[77];
  A[162] = 7e-14*V[69]*V[77];
  A[163] = 7e-14*V[67]*V[77];
  A[164] = RCT[164]*V[15]*V[83];
  A[165] = 5e-14*V[16]*V[83];
  A[166] = 5.44e-17*V[10]*V[73];
  A[167] = 3.46e-17*V[11]*V[73];
  A[168] = 2.21e-17*V[12]*V[73];
  A[169] = 1.03e-15*V[13]*V[73];
  A[170] = 2.16e-16*V[14]*V[73];
  A[171] = RCT[171]*V[81]*V[83];
  A[172] = RCT[172]*V[70];
  A[173] = 1e-11*V[70]*V[83];
  A[174] = 8.3e-12*V[17]*V[83];
  A[175] = RCT[175]*V[82]*V[82];
  A[176] = RCT[176]*V[31]*V[83];
  A[177] = RCT[177]*V[81]*V[82];

/* Aggregate function                                               */
  Vdot[0] = A[28]+A[85]+A[86]+A[161]+A[162]+A[163];
  Vdot[1] = A[80];
  Vdot[2] = 0.03*A[50];
  Vdot[3] = 0.11*A[166];
  Vdot[4] = 0.19*A[167]+0.39*A[169];
  Vdot[5] = 0.15*A[168]+0.15*A[170];
  Vdot[6] = A[88];
  Vdot[7] = A[89];
  Vdot[8] = A[91]+A[92]+A[93]+A[94];
  Vdot[9] = A[174];
  Vdot[10] = -A[166];
  Vdot[11] = -A[167];
  Vdot[12] = -A[168];
  Vdot[13] = -A[169];
  Vdot[14] = -A[170];
  Vdot[15] = A[140]-A[164];
  Vdot[16] = A[143]-A[165];
  Vdot[17] = -A[174];
  Vdot[18] = -A[47];
  Vdot[19] = -A[49];
  Vdot[20] = A[120]-A[121];
  Vdot[21] = A[128]-A[129];
  Vdot[22] = A[22]-A[23]-A[24];
  Vdot[23] = -A[95];
  Vdot[24] = A[104]-A[105];
  Vdot[25] = A[4]-A[5]-A[15];
  Vdot[26] = A[10]-A[11]+A[25];
  Vdot[27] = 0.263*A[52]-A[54]+0.05*A[65];
  Vdot[28] = A[41]-A[46]+0.06*A[73];
  Vdot[29] = -A[51]-A[53];
  Vdot[30] = A[19]-A[20]-A[26]-A[27];
  Vdot[31] = A[42]-A[43]-A[176];
  Vdot[32] = A[33]+A[34]+A[35]-A[36]+A[77];
  Vdot[33] = A[96]-A[103]-A[108];
  Vdot[34] = 0.18*A[96]-A[97]-A[98]+0.89*A[106];
  Vdot[35] = 0.16*A[95]-A[101]-A[102];
  Vdot[36] = A[32]-A[33]-A[34]-2*A[35]-A[112];
  Vdot[37] = A[54]-A[55];
  Vdot[38] = 0.9*A[101]-A[107]-A[111];
  Vdot[39] = -A[69]-A[73];
  Vdot[40] = -A[16]+A[29]+A[30]+A[31]+A[37]+A[40]+A[41]+0.42*A[73]+2
            *A[98]+A[99]+A[100];
  Vdot[41] = A[68]+0.72*A[96]-A[99]-A[100]+0.11*A[106];
  Vdot[42] = A[155]-A[156]-A[157];
  Vdot[43] = 0.84*A[95]-A[96]-A[109];
  Vdot[44] = 0.6*A[117]-A[127]-A[144]-A[158];
  Vdot[45] = A[49]-A[50]+0.1057*A[52]-2*A[58]-A[61];
  Vdot[46] = A[69]-A[70]-2*A[81]-A[83];
  Vdot[47] = A[71]-A[72]-2*A[82]-A[84];
  Vdot[48] = A[124]-A[125]-A[126];
  Vdot[49] = A[151]-A[152]-A[153];
  Vdot[50] = A[47]-A[48]+0.1879*A[52]-2*A[57]-A[60]+A[66];
  Vdot[51] = A[87]-A[88]-A[89]-A[90];
  Vdot[52] = A[113]-A[114]-A[115];
  Vdot[53] = 0.9*A[101]+A[103]-A[104]+A[105]-A[106]+A[108]-A[110];
  Vdot[54] = A[147]-A[148]-A[149]-A[150];
  Vdot[55] = A[127]-A[128]+A[129]-A[130]-A[131]+A[158];
  Vdot[56] = A[8]+A[12]-A[13]-A[14]+2*A[15]+A[25]+A[37]+A[39]+A[53]
            +A[67]+A[102]+A[154]+A[158]+0.4*A[177];
  Vdot[57] = 0.3*A[117]+A[122]+0.9*A[125]+0.5*A[133]+0.5*A[134]+A[141]
            +A[142]-A[145]-A[146]+0.5*A[152]+A[156];
  Vdot[58] = A[116]-A[117]-A[118];
  Vdot[59] = -A[71]-A[74]-A[87];
  Vdot[60] = A[51]-0.94*A[52]+A[53]-A[62];
  Vdot[61] = 0.49*A[50]+0.3*A[52]+0.28*A[58]-A[64]-A[66]-A[67];
  Vdot[62] = A[64]-A[65]+A[67]-A[68];
  Vdot[63] = -A[113]-A[132]-A[147];
  Vdot[64] = A[40]+A[44]-A[45]+A[46]+0.1116*A[52]-2*A[56]-A[59]+A[68]
            +0.215*A[74]+0.5*A[173];
  Vdot[65] = A[119]-A[120]+A[121]-A[122]-A[123]+A[154];
  Vdot[66] = 0.2*A[74]-A[78]-A[79]-A[80]-A[86]-A[93]-A[94];
  Vdot[67] = 0.2*A[133]+0.2*A[134]-A[141]-A[142]-A[143]-A[163];
  Vdot[68] = 0.2*A[132]-A[135]-A[136]-A[137]-A[160]-A[161];
  Vdot[69] = 0.3*A[132]-A[138]-A[139]-A[140]-A[159]-A[162];
  Vdot[70] = A[59]+A[60]+A[61]+A[62]+A[63]+A[83]+A[84]+A[109]+A[110]
            +A[111]+A[115]+A[118]+A[123]+A[126]+A[131]+A[159]+A[160]
            -A[172]-A[173];
  Vdot[71] = A[38]+A[39]-A[42]+A[43]-A[44]-A[63]+0.94*A[65]+A[66]+A[99]
            +A[100]+0.05*A[106]+0.02*A[108]+0.6*A[117]+0.15*A[133]
            +A[145]+A[146]+0.5*A[152];
  Vdot[72] = 0.45*A[114]-A[119]-A[124]+0.3*A[132]-A[134]+A[138]+A[139]
            +0.5*A[148]-A[154]-A[155]+A[162];
  Vdot[73] = A[0]-A[1]-A[2]+0.85*A[7]-A[9]-A[17]-A[21]-A[73]-A[74]
            -A[132]-A[133]-A[134]-A[166]-A[167]-A[168]-A[169]-A[170];
  Vdot[74] = 0.45*A[114]-A[116]+0.2*A[132]-A[133]+A[135]+A[136]+0.5
            *A[148]-A[151]+A[161]+A[163];
  Vdot[75] = -A[0]+A[1]-A[2]+2*A[3]-A[4]+A[5]+0.85*A[7]-A[12]+A[13]
            +A[18]-A[19]+A[20]-2*A[25]+A[26]+A[27]+A[33]-A[42]+A[43]
            +A[44]+A[45]+A[48]+0.97*A[50]+0.9261*A[52]+2.5*A[55]+0.95
            *A[65]+A[70]+A[72]+A[75]-A[76]+A[78]-A[79]-A[88]+2*A[90]
            +A[96]-0.0315*A[101]-A[104]+A[105]+A[106]+A[107]+0.9*A[114]
            +0.9*A[117]-A[120]+A[121]+0.9*A[125]-A[128]+A[129]+A[130]
            +0.15*A[134]+A[135]-A[136]+A[138]-A[139]+A[141]-A[142]+2
            *A[148]-A[149]+2*A[152]+2*A[156]+2*A[175]+0.6*A[177];
  Vdot[76] = -A[29]-A[30]-A[31]-A[32]-A[37]+A[45]+0.8*A[55]+1.4*A[56]+2
            *A[70]+A[72]+A[73]+0.525*A[74]+A[75]+A[76]+2.4*A[81]+A[85]
            +A[90]-A[91]-A[93]+A[112]+0.9*A[114]+0.3*A[117]+0.9*A[125]
            +A[130]+0.5*A[132]+0.5*A[133]+0.65*A[134]+A[144]+A[148]
            +A[152]+A[156]+A[172]+0.5*A[173];
  Vdot[77] = -A[28]-A[85]-A[86]-A[161]-A[162]-A[163]+A[174];
  Vdot[78] = -A[38]-A[39]-A[40]-A[41]+A[48]+0.46*A[50]+1.0482*A[52]+2.1
            *A[55]+1.6*A[57]+1.9*A[58]+0.94*A[65]+A[72]+0.5*A[74]+A[78]
            +A[79]+0.4*A[81]+2.2*A[82]+A[86]+A[90]-A[92]-A[94]+0.15
            *A[133];
  Vdot[79] = 0.4*A[73]+0.2*A[74]-A[75]-A[76]-A[77]-A[85]-A[91]-A[92]
            +0.2*A[132]+0.2*A[133]+0.2*A[134];
  Vdot[80] = A[0]-A[1]-A[3]+A[6]+0.15*A[7]-A[10]+A[11]-A[18]-A[33]
            -A[44]-A[45]-A[48]-A[50]-1.1892*A[52]-1.5*A[55]-A[65]-A[70]
            -A[72]-A[75]-A[78]-A[90]-A[96]-A[106]-A[107]-A[114]-A[117]
            -3*A[122]-A[125]-A[130]-0.15*A[134]-A[135]-A[138]-A[141]
            -A[148]-A[152]-A[156];
  Vdot[81] = -A[8]+A[16]+A[17]-A[18]-A[19]+A[20]-A[21]-2*A[22]+A[24]
            +A[26]+A[28]+2*A[29]+A[31]-A[32]+A[33]-A[34]+2*A[35]+A[36]
            +A[37]+A[40]+A[45]+A[48]+0.97*A[50]+0.28*A[52]+0.8*A[56]
            +1.2*A[57]+0.37*A[58]-A[59]-A[60]-A[61]-A[62]-A[63]-A[68]
            +A[70]+A[72]+0.12*A[73]+0.23*A[74]+1.2*A[81]+1.2*A[82]
            -A[83]-A[84]-A[89]+0.16*A[95]+A[96]+A[98]+A[99]+0.83*A[101]
            +0.92*A[106]+0.98*A[108]-A[109]-A[110]-A[111]+A[112]+0.9
            *A[114]-A[115]+0.3*A[117]-A[118]+A[122]-A[123]+0.9*A[125]
            -A[126]+A[130]-A[131]+0.06*A[132]+0.21*A[133]+0.36*A[134]+2
            *A[144]+A[145]-A[150]+0.5*A[152]-A[153]-A[157]-A[159]
            -A[160]-A[171]+A[172]-A[177];
  Vdot[82] = A[2]-A[3]-A[4]+A[5]-A[6]-A[7]-A[8]+A[14]-A[37]-A[39]-A[53]
            -A[67]+A[76]+A[79]-A[87]-A[102]+3*A[122]+A[136]+A[139]
            +A[142]-A[147]-A[151]-A[154]-A[155]-A[158]-2*A[175]-A[177];
  Vdot[83] = 2*A[9]-A[10]+A[11]-A[12]+A[13]-A[14]-A[16]-A[17]+A[18]
            +A[21]+2*A[23]-A[24]-A[27]-A[28]-A[31]-A[36]-A[38]-A[46]
            -A[47]-A[49]-A[51]-A[54]-A[64]-A[69]-A[71]-A[95]-A[98]
            -A[100]-1.9*A[101]-A[103]-A[113]-A[116]-A[119]-A[124]
            -A[127]-A[146]-A[164]-A[165]-A[171]+A[172]-0.5*A[173]
            -A[174]-A[176]+0.6*A[177];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


