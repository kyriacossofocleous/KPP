/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The Stoichiometric Chemical Model File                           */
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
/* File                 : tropo_single_Stoichiom.c                  */
/* Time                 : Wed Mar  9 12:17:07 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/tropo_single */
/* Equation file        : tropo_single.kpp                          */
/* Output root filename : tropo_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "tropo_single_Parameters.h"
#include "tropo_single_Global.h"
#include "tropo_single_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* ReactantProd - Reactant Products in each equation                */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      ARP       - Reactant product in each equation               */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void ReactantProd( 
  float V[],                             /* Concentrations of variable species (local) */
  float F[],                             /* Concentrations of fixed species (local) */
  float ARP[]                            /* Reactant product in each equation */
)
{

/* Reactant Products in each equation are useful in the             */
/*     stoichiometric formulation of mass action law                */
  ARP[0] = V[75];
  ARP[1] = V[73]*V[80];
  ARP[2] = V[73]*V[75];
  ARP[3] = V[80]*V[82];
  ARP[4] = V[75]*V[82];
  ARP[5] = V[25];
  ARP[6] = V[75]*V[82];
  ARP[7] = V[82];
  ARP[8] = V[81]*V[82];
  ARP[9] = V[73];
  ARP[10] = V[80]*V[83];
  ARP[11] = V[26];
  ARP[12] = V[75]*V[83];
  ARP[13] = V[56];
  ARP[14] = V[56]*V[83];
  ARP[15] = V[25]*F[1];
  ARP[16] = V[40]*V[83];
  ARP[17] = V[73]*V[83];
  ARP[18] = V[80]*V[81];
  ARP[19] = V[75]*V[81];
  ARP[20] = V[30];
  ARP[21] = V[73]*V[81];
  ARP[22] = V[81]*V[81];
  ARP[23] = V[22];
  ARP[24] = V[22]*V[83];
  ARP[25] = V[75]*F[1];
  ARP[26] = V[30];
  ARP[27] = V[30]*V[83];
  ARP[28] = V[77]*V[83];
  ARP[29] = V[76];
  ARP[30] = V[76];
  ARP[31] = V[76]*V[83];
  ARP[32] = V[76]*V[81];
  ARP[33] = V[36]*V[80];
  ARP[34] = V[36]*V[81];
  ARP[35] = V[36]*V[36];
  ARP[36] = V[32]*V[83];
  ARP[37] = V[76]*V[82];
  ARP[38] = V[78]*V[83];
  ARP[39] = V[78]*V[82];
  ARP[40] = V[78];
  ARP[41] = V[78];
  ARP[42] = V[71]*V[75];
  ARP[43] = V[31];
  ARP[44] = V[71]*V[80];
  ARP[45] = V[64]*V[80];
  ARP[46] = V[28]*V[83];
  ARP[47] = V[18]*V[83];
  ARP[48] = V[50]*V[80];
  ARP[49] = V[19]*V[83];
  ARP[50] = V[45]*V[80];
  ARP[51] = V[29]*V[83];
  ARP[52] = V[60]*V[80];
  ARP[53] = V[29]*V[82];
  ARP[54] = V[27]*V[83];
  ARP[55] = V[37]*V[80];
  ARP[56] = V[64]*V[64];
  ARP[57] = V[50]*V[50];
  ARP[58] = V[45]*V[45];
  ARP[59] = V[64]*V[81];
  ARP[60] = V[50]*V[81];
  ARP[61] = V[45]*V[81];
  ARP[62] = V[60]*V[81];
  ARP[63] = V[71]*V[81];
  ARP[64] = V[61]*V[83];
  ARP[65] = V[62]*V[80];
  ARP[66] = V[61];
  ARP[67] = V[61]*V[82];
  ARP[68] = V[62]*V[81];
  ARP[69] = V[39]*V[83];
  ARP[70] = V[46]*V[80];
  ARP[71] = V[59]*V[83];
  ARP[72] = V[47]*V[80];
  ARP[73] = V[39]*V[73];
  ARP[74] = V[59]*V[73];
  ARP[75] = V[79]*V[80];
  ARP[76] = V[75]*V[79];
  ARP[77] = V[79]*F[1];
  ARP[78] = V[66]*V[80];
  ARP[79] = V[66]*V[75];
  ARP[80] = V[66]*F[1];
  ARP[81] = V[46]*V[46];
  ARP[82] = V[47]*V[47];
  ARP[83] = V[46]*V[81];
  ARP[84] = V[47]*V[81];
  ARP[85] = V[77]*V[79];
  ARP[86] = V[66]*V[77];
  ARP[87] = V[59]*V[82];
  ARP[88] = V[51]*V[75];
  ARP[89] = V[51]*V[81];
  ARP[90] = V[51]*V[80];
  ARP[91] = V[76]*V[79];
  ARP[92] = V[78]*V[79];
  ARP[93] = V[66]*V[76];
  ARP[94] = V[66]*V[78];
  ARP[95] = V[23]*V[83];
  ARP[96] = V[43]*V[80];
  ARP[97] = V[34];
  ARP[98] = V[34]*V[83];
  ARP[99] = V[41];
  ARP[100] = V[41]*V[83];
  ARP[101] = V[35]*V[83];
  ARP[102] = V[35]*V[82];
  ARP[103] = V[33]*V[83];
  ARP[104] = V[53]*V[75];
  ARP[105] = V[24];
  ARP[106] = V[53]*V[80];
  ARP[107] = V[38]*V[80];
  ARP[108] = V[33];
  ARP[109] = V[43]*V[81];
  ARP[110] = V[53]*V[81];
  ARP[111] = V[38]*V[81];
  ARP[112] = V[36];
  ARP[113] = V[63]*V[83];
  ARP[114] = V[52]*V[80];
  ARP[115] = V[52]*V[81];
  ARP[116] = V[74]*V[83];
  ARP[117] = V[58]*V[80];
  ARP[118] = V[58]*V[81];
  ARP[119] = V[72]*V[83];
  ARP[120] = V[65]*V[75];
  ARP[121] = V[20];
  ARP[122] = V[65]*V[80];
  ARP[123] = V[65]*V[81];
  ARP[124] = V[72]*V[83];
  ARP[125] = V[48]*V[80];
  ARP[126] = V[48]*V[81];
  ARP[127] = V[44]*V[83];
  ARP[128] = V[55]*V[75];
  ARP[129] = V[21];
  ARP[130] = V[55]*V[80];
  ARP[131] = V[55]*V[81];
  ARP[132] = V[63]*V[73];
  ARP[133] = V[73]*V[74];
  ARP[134] = V[72]*V[73];
  ARP[135] = V[68]*V[80];
  ARP[136] = V[68]*V[75];
  ARP[137] = V[68]*F[1];
  ARP[138] = V[69]*V[80];
  ARP[139] = V[69]*V[75];
  ARP[140] = V[69]*F[1];
  ARP[141] = V[67]*V[80];
  ARP[142] = V[67]*V[75];
  ARP[143] = V[67]*F[1];
  ARP[144] = V[44];
  ARP[145] = V[57];
  ARP[146] = V[57]*V[83];
  ARP[147] = V[63]*V[82];
  ARP[148] = V[54]*V[80];
  ARP[149] = V[54]*V[75];
  ARP[150] = V[54]*V[81];
  ARP[151] = V[74]*V[82];
  ARP[152] = V[49]*V[80];
  ARP[153] = V[49]*V[81];
  ARP[154] = V[72]*V[82];
  ARP[155] = V[72]*V[82];
  ARP[156] = V[42]*V[80];
  ARP[157] = V[42]*V[81];
  ARP[158] = V[44]*V[82];
  ARP[159] = V[69]*V[81];
  ARP[160] = V[68]*V[81];
  ARP[161] = V[68]*V[77];
  ARP[162] = V[69]*V[77];
  ARP[163] = V[67]*V[77];
  ARP[164] = V[15]*V[83];
  ARP[165] = V[16]*V[83];
  ARP[166] = V[10]*V[73];
  ARP[167] = V[11]*V[73];
  ARP[168] = V[12]*V[73];
  ARP[169] = V[13]*V[73];
  ARP[170] = V[14]*V[73];
  ARP[171] = V[81]*V[83];
  ARP[172] = V[70];
  ARP[173] = V[70]*V[83];
  ARP[174] = V[17]*V[83];
  ARP[175] = V[82]*V[82];
  ARP[176] = V[31]*V[83];
  ARP[177] = V[81]*V[82];
}

/* End of ReactantProd function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* JacReactantProd - Jacobian of Reactant Products vector           */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      JVRP      - d ARP(1:NREACT)/d VAR (1:NVAR)                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void JacReactantProd( 
  float V[],                             /* Concentrations of variable species (local) */
  float F[],                             /* Concentrations of fixed species (local) */
  float JVRP[]                           /* d ARP(1:NREACT)/d VAR (1:NVAR) */
)
{

/* Reactant Products in each equation are useful in the             */
/*    stoichiometric formulation of mass action law                 */
/* Below we compute the Jacobian of the Reactant Products vector    */
/*    w.r.t. variable species: d ARP(1:NREACT) / d Var(1:NVAR)      */

/* JVRP(0) = dARP(0)/dV(75)                                         */
  JVRP[0] = 1;
/* JVRP(1) = dARP(1)/dV(73)                                         */
  JVRP[1] = V[80];
/* JVRP(2) = dARP(1)/dV(80)                                         */
  JVRP[2] = V[73];
/* JVRP(3) = dARP(2)/dV(73)                                         */
  JVRP[3] = V[75];
/* JVRP(4) = dARP(2)/dV(75)                                         */
  JVRP[4] = V[73];
/* JVRP(5) = dARP(3)/dV(80)                                         */
  JVRP[5] = V[82];
/* JVRP(6) = dARP(3)/dV(82)                                         */
  JVRP[6] = V[80];
/* JVRP(7) = dARP(4)/dV(75)                                         */
  JVRP[7] = V[82];
/* JVRP(8) = dARP(4)/dV(82)                                         */
  JVRP[8] = V[75];
/* JVRP(9) = dARP(5)/dV(25)                                         */
  JVRP[9] = 1;
/* JVRP(10) = dARP(6)/dV(75)                                        */
  JVRP[10] = V[82];
/* JVRP(11) = dARP(6)/dV(82)                                        */
  JVRP[11] = V[75];
/* JVRP(12) = dARP(7)/dV(82)                                        */
  JVRP[12] = 1;
/* JVRP(13) = dARP(8)/dV(81)                                        */
  JVRP[13] = V[82];
/* JVRP(14) = dARP(8)/dV(82)                                        */
  JVRP[14] = V[81];
/* JVRP(15) = dARP(9)/dV(73)                                        */
  JVRP[15] = 1;
/* JVRP(16) = dARP(10)/dV(80)                                       */
  JVRP[16] = V[83];
/* JVRP(17) = dARP(10)/dV(83)                                       */
  JVRP[17] = V[80];
/* JVRP(18) = dARP(11)/dV(26)                                       */
  JVRP[18] = 1;
/* JVRP(19) = dARP(12)/dV(75)                                       */
  JVRP[19] = V[83];
/* JVRP(20) = dARP(12)/dV(83)                                       */
  JVRP[20] = V[75];
/* JVRP(21) = dARP(13)/dV(56)                                       */
  JVRP[21] = 1;
/* JVRP(22) = dARP(14)/dV(56)                                       */
  JVRP[22] = V[83];
/* JVRP(23) = dARP(14)/dV(83)                                       */
  JVRP[23] = V[56];
/* JVRP(24) = dARP(15)/dV(25)                                       */
  JVRP[24] = F[1];
/* JVRP(25) = dARP(16)/dV(40)                                       */
  JVRP[25] = V[83];
/* JVRP(26) = dARP(16)/dV(83)                                       */
  JVRP[26] = V[40];
/* JVRP(27) = dARP(17)/dV(73)                                       */
  JVRP[27] = V[83];
/* JVRP(28) = dARP(17)/dV(83)                                       */
  JVRP[28] = V[73];
/* JVRP(29) = dARP(18)/dV(80)                                       */
  JVRP[29] = V[81];
/* JVRP(30) = dARP(18)/dV(81)                                       */
  JVRP[30] = V[80];
/* JVRP(31) = dARP(19)/dV(75)                                       */
  JVRP[31] = V[81];
/* JVRP(32) = dARP(19)/dV(81)                                       */
  JVRP[32] = V[75];
/* JVRP(33) = dARP(20)/dV(30)                                       */
  JVRP[33] = 1;
/* JVRP(34) = dARP(21)/dV(73)                                       */
  JVRP[34] = V[81];
/* JVRP(35) = dARP(21)/dV(81)                                       */
  JVRP[35] = V[73];
/* JVRP(36) = dARP(22)/dV(81)                                       */
  JVRP[36] = 2*V[81];
/* JVRP(37) = dARP(23)/dV(22)                                       */
  JVRP[37] = 1;
/* JVRP(38) = dARP(24)/dV(22)                                       */
  JVRP[38] = V[83];
/* JVRP(39) = dARP(24)/dV(83)                                       */
  JVRP[39] = V[22];
/* JVRP(40) = dARP(25)/dV(75)                                       */
  JVRP[40] = F[1];
/* JVRP(41) = dARP(26)/dV(30)                                       */
  JVRP[41] = 1;
/* JVRP(42) = dARP(27)/dV(30)                                       */
  JVRP[42] = V[83];
/* JVRP(43) = dARP(27)/dV(83)                                       */
  JVRP[43] = V[30];
/* JVRP(44) = dARP(28)/dV(77)                                       */
  JVRP[44] = V[83];
/* JVRP(45) = dARP(28)/dV(83)                                       */
  JVRP[45] = V[77];
/* JVRP(46) = dARP(29)/dV(76)                                       */
  JVRP[46] = 1;
/* JVRP(47) = dARP(30)/dV(76)                                       */
  JVRP[47] = 1;
/* JVRP(48) = dARP(31)/dV(76)                                       */
  JVRP[48] = V[83];
/* JVRP(49) = dARP(31)/dV(83)                                       */
  JVRP[49] = V[76];
/* JVRP(50) = dARP(32)/dV(76)                                       */
  JVRP[50] = V[81];
/* JVRP(51) = dARP(32)/dV(81)                                       */
  JVRP[51] = V[76];
/* JVRP(52) = dARP(33)/dV(36)                                       */
  JVRP[52] = V[80];
/* JVRP(53) = dARP(33)/dV(80)                                       */
  JVRP[53] = V[36];
/* JVRP(54) = dARP(34)/dV(36)                                       */
  JVRP[54] = V[81];
/* JVRP(55) = dARP(34)/dV(81)                                       */
  JVRP[55] = V[36];
/* JVRP(56) = dARP(35)/dV(36)                                       */
  JVRP[56] = 2*V[36];
/* JVRP(57) = dARP(36)/dV(32)                                       */
  JVRP[57] = V[83];
/* JVRP(58) = dARP(36)/dV(83)                                       */
  JVRP[58] = V[32];
/* JVRP(59) = dARP(37)/dV(76)                                       */
  JVRP[59] = V[82];
/* JVRP(60) = dARP(37)/dV(82)                                       */
  JVRP[60] = V[76];
/* JVRP(61) = dARP(38)/dV(78)                                       */
  JVRP[61] = V[83];
/* JVRP(62) = dARP(38)/dV(83)                                       */
  JVRP[62] = V[78];
/* JVRP(63) = dARP(39)/dV(78)                                       */
  JVRP[63] = V[82];
/* JVRP(64) = dARP(39)/dV(82)                                       */
  JVRP[64] = V[78];
/* JVRP(65) = dARP(40)/dV(78)                                       */
  JVRP[65] = 1;
/* JVRP(66) = dARP(41)/dV(78)                                       */
  JVRP[66] = 1;
/* JVRP(67) = dARP(42)/dV(71)                                       */
  JVRP[67] = V[75];
/* JVRP(68) = dARP(42)/dV(75)                                       */
  JVRP[68] = V[71];
/* JVRP(69) = dARP(43)/dV(31)                                       */
  JVRP[69] = 1;
/* JVRP(70) = dARP(44)/dV(71)                                       */
  JVRP[70] = V[80];
/* JVRP(71) = dARP(44)/dV(80)                                       */
  JVRP[71] = V[71];
/* JVRP(72) = dARP(45)/dV(64)                                       */
  JVRP[72] = V[80];
/* JVRP(73) = dARP(45)/dV(80)                                       */
  JVRP[73] = V[64];
/* JVRP(74) = dARP(46)/dV(28)                                       */
  JVRP[74] = V[83];
/* JVRP(75) = dARP(46)/dV(83)                                       */
  JVRP[75] = V[28];
/* JVRP(76) = dARP(47)/dV(18)                                       */
  JVRP[76] = V[83];
/* JVRP(77) = dARP(47)/dV(83)                                       */
  JVRP[77] = V[18];
/* JVRP(78) = dARP(48)/dV(50)                                       */
  JVRP[78] = V[80];
/* JVRP(79) = dARP(48)/dV(80)                                       */
  JVRP[79] = V[50];
/* JVRP(80) = dARP(49)/dV(19)                                       */
  JVRP[80] = V[83];
/* JVRP(81) = dARP(49)/dV(83)                                       */
  JVRP[81] = V[19];
/* JVRP(82) = dARP(50)/dV(45)                                       */
  JVRP[82] = V[80];
/* JVRP(83) = dARP(50)/dV(80)                                       */
  JVRP[83] = V[45];
/* JVRP(84) = dARP(51)/dV(29)                                       */
  JVRP[84] = V[83];
/* JVRP(85) = dARP(51)/dV(83)                                       */
  JVRP[85] = V[29];
/* JVRP(86) = dARP(52)/dV(60)                                       */
  JVRP[86] = V[80];
/* JVRP(87) = dARP(52)/dV(80)                                       */
  JVRP[87] = V[60];
/* JVRP(88) = dARP(53)/dV(29)                                       */
  JVRP[88] = V[82];
/* JVRP(89) = dARP(53)/dV(82)                                       */
  JVRP[89] = V[29];
/* JVRP(90) = dARP(54)/dV(27)                                       */
  JVRP[90] = V[83];
/* JVRP(91) = dARP(54)/dV(83)                                       */
  JVRP[91] = V[27];
/* JVRP(92) = dARP(55)/dV(37)                                       */
  JVRP[92] = V[80];
/* JVRP(93) = dARP(55)/dV(80)                                       */
  JVRP[93] = V[37];
/* JVRP(94) = dARP(56)/dV(64)                                       */
  JVRP[94] = 2*V[64];
/* JVRP(95) = dARP(57)/dV(50)                                       */
  JVRP[95] = 2*V[50];
/* JVRP(96) = dARP(58)/dV(45)                                       */
  JVRP[96] = 2*V[45];
/* JVRP(97) = dARP(59)/dV(64)                                       */
  JVRP[97] = V[81];
/* JVRP(98) = dARP(59)/dV(81)                                       */
  JVRP[98] = V[64];
/* JVRP(99) = dARP(60)/dV(50)                                       */
  JVRP[99] = V[81];
/* JVRP(100) = dARP(60)/dV(81)                                      */
  JVRP[100] = V[50];
/* JVRP(101) = dARP(61)/dV(45)                                      */
  JVRP[101] = V[81];
/* JVRP(102) = dARP(61)/dV(81)                                      */
  JVRP[102] = V[45];
/* JVRP(103) = dARP(62)/dV(60)                                      */
  JVRP[103] = V[81];
/* JVRP(104) = dARP(62)/dV(81)                                      */
  JVRP[104] = V[60];
/* JVRP(105) = dARP(63)/dV(71)                                      */
  JVRP[105] = V[81];
/* JVRP(106) = dARP(63)/dV(81)                                      */
  JVRP[106] = V[71];
/* JVRP(107) = dARP(64)/dV(61)                                      */
  JVRP[107] = V[83];
/* JVRP(108) = dARP(64)/dV(83)                                      */
  JVRP[108] = V[61];
/* JVRP(109) = dARP(65)/dV(62)                                      */
  JVRP[109] = V[80];
/* JVRP(110) = dARP(65)/dV(80)                                      */
  JVRP[110] = V[62];
/* JVRP(111) = dARP(66)/dV(61)                                      */
  JVRP[111] = 1;
/* JVRP(112) = dARP(67)/dV(61)                                      */
  JVRP[112] = V[82];
/* JVRP(113) = dARP(67)/dV(82)                                      */
  JVRP[113] = V[61];
/* JVRP(114) = dARP(68)/dV(62)                                      */
  JVRP[114] = V[81];
/* JVRP(115) = dARP(68)/dV(81)                                      */
  JVRP[115] = V[62];
/* JVRP(116) = dARP(69)/dV(39)                                      */
  JVRP[116] = V[83];
/* JVRP(117) = dARP(69)/dV(83)                                      */
  JVRP[117] = V[39];
/* JVRP(118) = dARP(70)/dV(46)                                      */
  JVRP[118] = V[80];
/* JVRP(119) = dARP(70)/dV(80)                                      */
  JVRP[119] = V[46];
/* JVRP(120) = dARP(71)/dV(59)                                      */
  JVRP[120] = V[83];
/* JVRP(121) = dARP(71)/dV(83)                                      */
  JVRP[121] = V[59];
/* JVRP(122) = dARP(72)/dV(47)                                      */
  JVRP[122] = V[80];
/* JVRP(123) = dARP(72)/dV(80)                                      */
  JVRP[123] = V[47];
/* JVRP(124) = dARP(73)/dV(39)                                      */
  JVRP[124] = V[73];
/* JVRP(125) = dARP(73)/dV(73)                                      */
  JVRP[125] = V[39];
/* JVRP(126) = dARP(74)/dV(59)                                      */
  JVRP[126] = V[73];
/* JVRP(127) = dARP(74)/dV(73)                                      */
  JVRP[127] = V[59];
/* JVRP(128) = dARP(75)/dV(79)                                      */
  JVRP[128] = V[80];
/* JVRP(129) = dARP(75)/dV(80)                                      */
  JVRP[129] = V[79];
/* JVRP(130) = dARP(76)/dV(75)                                      */
  JVRP[130] = V[79];
/* JVRP(131) = dARP(76)/dV(79)                                      */
  JVRP[131] = V[75];
/* JVRP(132) = dARP(77)/dV(79)                                      */
  JVRP[132] = F[1];
/* JVRP(133) = dARP(78)/dV(66)                                      */
  JVRP[133] = V[80];
/* JVRP(134) = dARP(78)/dV(80)                                      */
  JVRP[134] = V[66];
/* JVRP(135) = dARP(79)/dV(66)                                      */
  JVRP[135] = V[75];
/* JVRP(136) = dARP(79)/dV(75)                                      */
  JVRP[136] = V[66];
/* JVRP(137) = dARP(80)/dV(66)                                      */
  JVRP[137] = F[1];
/* JVRP(138) = dARP(81)/dV(46)                                      */
  JVRP[138] = 2*V[46];
/* JVRP(139) = dARP(82)/dV(47)                                      */
  JVRP[139] = 2*V[47];
/* JVRP(140) = dARP(83)/dV(46)                                      */
  JVRP[140] = V[81];
/* JVRP(141) = dARP(83)/dV(81)                                      */
  JVRP[141] = V[46];
/* JVRP(142) = dARP(84)/dV(47)                                      */
  JVRP[142] = V[81];
/* JVRP(143) = dARP(84)/dV(81)                                      */
  JVRP[143] = V[47];
/* JVRP(144) = dARP(85)/dV(77)                                      */
  JVRP[144] = V[79];
/* JVRP(145) = dARP(85)/dV(79)                                      */
  JVRP[145] = V[77];
/* JVRP(146) = dARP(86)/dV(66)                                      */
  JVRP[146] = V[77];
/* JVRP(147) = dARP(86)/dV(77)                                      */
  JVRP[147] = V[66];
/* JVRP(148) = dARP(87)/dV(59)                                      */
  JVRP[148] = V[82];
/* JVRP(149) = dARP(87)/dV(82)                                      */
  JVRP[149] = V[59];
/* JVRP(150) = dARP(88)/dV(51)                                      */
  JVRP[150] = V[75];
/* JVRP(151) = dARP(88)/dV(75)                                      */
  JVRP[151] = V[51];
/* JVRP(152) = dARP(89)/dV(51)                                      */
  JVRP[152] = V[81];
/* JVRP(153) = dARP(89)/dV(81)                                      */
  JVRP[153] = V[51];
/* JVRP(154) = dARP(90)/dV(51)                                      */
  JVRP[154] = V[80];
/* JVRP(155) = dARP(90)/dV(80)                                      */
  JVRP[155] = V[51];
/* JVRP(156) = dARP(91)/dV(76)                                      */
  JVRP[156] = V[79];
/* JVRP(157) = dARP(91)/dV(79)                                      */
  JVRP[157] = V[76];
/* JVRP(158) = dARP(92)/dV(78)                                      */
  JVRP[158] = V[79];
/* JVRP(159) = dARP(92)/dV(79)                                      */
  JVRP[159] = V[78];
/* JVRP(160) = dARP(93)/dV(66)                                      */
  JVRP[160] = V[76];
/* JVRP(161) = dARP(93)/dV(76)                                      */
  JVRP[161] = V[66];
/* JVRP(162) = dARP(94)/dV(66)                                      */
  JVRP[162] = V[78];
/* JVRP(163) = dARP(94)/dV(78)                                      */
  JVRP[163] = V[66];
/* JVRP(164) = dARP(95)/dV(23)                                      */
  JVRP[164] = V[83];
/* JVRP(165) = dARP(95)/dV(83)                                      */
  JVRP[165] = V[23];
/* JVRP(166) = dARP(96)/dV(43)                                      */
  JVRP[166] = V[80];
/* JVRP(167) = dARP(96)/dV(80)                                      */
  JVRP[167] = V[43];
/* JVRP(168) = dARP(97)/dV(34)                                      */
  JVRP[168] = 1;
/* JVRP(169) = dARP(98)/dV(34)                                      */
  JVRP[169] = V[83];
/* JVRP(170) = dARP(98)/dV(83)                                      */
  JVRP[170] = V[34];
/* JVRP(171) = dARP(99)/dV(41)                                      */
  JVRP[171] = 1;
/* JVRP(172) = dARP(100)/dV(41)                                     */
  JVRP[172] = V[83];
/* JVRP(173) = dARP(100)/dV(83)                                     */
  JVRP[173] = V[41];
/* JVRP(174) = dARP(101)/dV(35)                                     */
  JVRP[174] = V[83];
/* JVRP(175) = dARP(101)/dV(83)                                     */
  JVRP[175] = V[35];
/* JVRP(176) = dARP(102)/dV(35)                                     */
  JVRP[176] = V[82];
/* JVRP(177) = dARP(102)/dV(82)                                     */
  JVRP[177] = V[35];
/* JVRP(178) = dARP(103)/dV(33)                                     */
  JVRP[178] = V[83];
/* JVRP(179) = dARP(103)/dV(83)                                     */
  JVRP[179] = V[33];
/* JVRP(180) = dARP(104)/dV(53)                                     */
  JVRP[180] = V[75];
/* JVRP(181) = dARP(104)/dV(75)                                     */
  JVRP[181] = V[53];
/* JVRP(182) = dARP(105)/dV(24)                                     */
  JVRP[182] = 1;
/* JVRP(183) = dARP(106)/dV(53)                                     */
  JVRP[183] = V[80];
/* JVRP(184) = dARP(106)/dV(80)                                     */
  JVRP[184] = V[53];
/* JVRP(185) = dARP(107)/dV(38)                                     */
  JVRP[185] = V[80];
/* JVRP(186) = dARP(107)/dV(80)                                     */
  JVRP[186] = V[38];
/* JVRP(187) = dARP(108)/dV(33)                                     */
  JVRP[187] = 1;
/* JVRP(188) = dARP(109)/dV(43)                                     */
  JVRP[188] = V[81];
/* JVRP(189) = dARP(109)/dV(81)                                     */
  JVRP[189] = V[43];
/* JVRP(190) = dARP(110)/dV(53)                                     */
  JVRP[190] = V[81];
/* JVRP(191) = dARP(110)/dV(81)                                     */
  JVRP[191] = V[53];
/* JVRP(192) = dARP(111)/dV(38)                                     */
  JVRP[192] = V[81];
/* JVRP(193) = dARP(111)/dV(81)                                     */
  JVRP[193] = V[38];
/* JVRP(194) = dARP(112)/dV(36)                                     */
  JVRP[194] = 1;
/* JVRP(195) = dARP(113)/dV(63)                                     */
  JVRP[195] = V[83];
/* JVRP(196) = dARP(113)/dV(83)                                     */
  JVRP[196] = V[63];
/* JVRP(197) = dARP(114)/dV(52)                                     */
  JVRP[197] = V[80];
/* JVRP(198) = dARP(114)/dV(80)                                     */
  JVRP[198] = V[52];
/* JVRP(199) = dARP(115)/dV(52)                                     */
  JVRP[199] = V[81];
/* JVRP(200) = dARP(115)/dV(81)                                     */
  JVRP[200] = V[52];
/* JVRP(201) = dARP(116)/dV(74)                                     */
  JVRP[201] = V[83];
/* JVRP(202) = dARP(116)/dV(83)                                     */
  JVRP[202] = V[74];
/* JVRP(203) = dARP(117)/dV(58)                                     */
  JVRP[203] = V[80];
/* JVRP(204) = dARP(117)/dV(80)                                     */
  JVRP[204] = V[58];
/* JVRP(205) = dARP(118)/dV(58)                                     */
  JVRP[205] = V[81];
/* JVRP(206) = dARP(118)/dV(81)                                     */
  JVRP[206] = V[58];
/* JVRP(207) = dARP(119)/dV(72)                                     */
  JVRP[207] = V[83];
/* JVRP(208) = dARP(119)/dV(83)                                     */
  JVRP[208] = V[72];
/* JVRP(209) = dARP(120)/dV(65)                                     */
  JVRP[209] = V[75];
/* JVRP(210) = dARP(120)/dV(75)                                     */
  JVRP[210] = V[65];
/* JVRP(211) = dARP(121)/dV(20)                                     */
  JVRP[211] = 1;
/* JVRP(212) = dARP(122)/dV(65)                                     */
  JVRP[212] = V[80];
/* JVRP(213) = dARP(122)/dV(80)                                     */
  JVRP[213] = V[65];
/* JVRP(214) = dARP(123)/dV(65)                                     */
  JVRP[214] = V[81];
/* JVRP(215) = dARP(123)/dV(81)                                     */
  JVRP[215] = V[65];
/* JVRP(216) = dARP(124)/dV(72)                                     */
  JVRP[216] = V[83];
/* JVRP(217) = dARP(124)/dV(83)                                     */
  JVRP[217] = V[72];
/* JVRP(218) = dARP(125)/dV(48)                                     */
  JVRP[218] = V[80];
/* JVRP(219) = dARP(125)/dV(80)                                     */
  JVRP[219] = V[48];
/* JVRP(220) = dARP(126)/dV(48)                                     */
  JVRP[220] = V[81];
/* JVRP(221) = dARP(126)/dV(81)                                     */
  JVRP[221] = V[48];
/* JVRP(222) = dARP(127)/dV(44)                                     */
  JVRP[222] = V[83];
/* JVRP(223) = dARP(127)/dV(83)                                     */
  JVRP[223] = V[44];
/* JVRP(224) = dARP(128)/dV(55)                                     */
  JVRP[224] = V[75];
/* JVRP(225) = dARP(128)/dV(75)                                     */
  JVRP[225] = V[55];
/* JVRP(226) = dARP(129)/dV(21)                                     */
  JVRP[226] = 1;
/* JVRP(227) = dARP(130)/dV(55)                                     */
  JVRP[227] = V[80];
/* JVRP(228) = dARP(130)/dV(80)                                     */
  JVRP[228] = V[55];
/* JVRP(229) = dARP(131)/dV(55)                                     */
  JVRP[229] = V[81];
/* JVRP(230) = dARP(131)/dV(81)                                     */
  JVRP[230] = V[55];
/* JVRP(231) = dARP(132)/dV(63)                                     */
  JVRP[231] = V[73];
/* JVRP(232) = dARP(132)/dV(73)                                     */
  JVRP[232] = V[63];
/* JVRP(233) = dARP(133)/dV(73)                                     */
  JVRP[233] = V[74];
/* JVRP(234) = dARP(133)/dV(74)                                     */
  JVRP[234] = V[73];
/* JVRP(235) = dARP(134)/dV(72)                                     */
  JVRP[235] = V[73];
/* JVRP(236) = dARP(134)/dV(73)                                     */
  JVRP[236] = V[72];
/* JVRP(237) = dARP(135)/dV(68)                                     */
  JVRP[237] = V[80];
/* JVRP(238) = dARP(135)/dV(80)                                     */
  JVRP[238] = V[68];
/* JVRP(239) = dARP(136)/dV(68)                                     */
  JVRP[239] = V[75];
/* JVRP(240) = dARP(136)/dV(75)                                     */
  JVRP[240] = V[68];
/* JVRP(241) = dARP(137)/dV(68)                                     */
  JVRP[241] = F[1];
/* JVRP(242) = dARP(138)/dV(69)                                     */
  JVRP[242] = V[80];
/* JVRP(243) = dARP(138)/dV(80)                                     */
  JVRP[243] = V[69];
/* JVRP(244) = dARP(139)/dV(69)                                     */
  JVRP[244] = V[75];
/* JVRP(245) = dARP(139)/dV(75)                                     */
  JVRP[245] = V[69];
/* JVRP(246) = dARP(140)/dV(69)                                     */
  JVRP[246] = F[1];
/* JVRP(247) = dARP(141)/dV(67)                                     */
  JVRP[247] = V[80];
/* JVRP(248) = dARP(141)/dV(80)                                     */
  JVRP[248] = V[67];
/* JVRP(249) = dARP(142)/dV(67)                                     */
  JVRP[249] = V[75];
/* JVRP(250) = dARP(142)/dV(75)                                     */
  JVRP[250] = V[67];
/* JVRP(251) = dARP(143)/dV(67)                                     */
  JVRP[251] = F[1];
/* JVRP(252) = dARP(144)/dV(44)                                     */
  JVRP[252] = 1;
/* JVRP(253) = dARP(145)/dV(57)                                     */
  JVRP[253] = 1;
/* JVRP(254) = dARP(146)/dV(57)                                     */
  JVRP[254] = V[83];
/* JVRP(255) = dARP(146)/dV(83)                                     */
  JVRP[255] = V[57];
/* JVRP(256) = dARP(147)/dV(63)                                     */
  JVRP[256] = V[82];
/* JVRP(257) = dARP(147)/dV(82)                                     */
  JVRP[257] = V[63];
/* JVRP(258) = dARP(148)/dV(54)                                     */
  JVRP[258] = V[80];
/* JVRP(259) = dARP(148)/dV(80)                                     */
  JVRP[259] = V[54];
/* JVRP(260) = dARP(149)/dV(54)                                     */
  JVRP[260] = V[75];
/* JVRP(261) = dARP(149)/dV(75)                                     */
  JVRP[261] = V[54];
/* JVRP(262) = dARP(150)/dV(54)                                     */
  JVRP[262] = V[81];
/* JVRP(263) = dARP(150)/dV(81)                                     */
  JVRP[263] = V[54];
/* JVRP(264) = dARP(151)/dV(74)                                     */
  JVRP[264] = V[82];
/* JVRP(265) = dARP(151)/dV(82)                                     */
  JVRP[265] = V[74];
/* JVRP(266) = dARP(152)/dV(49)                                     */
  JVRP[266] = V[80];
/* JVRP(267) = dARP(152)/dV(80)                                     */
  JVRP[267] = V[49];
/* JVRP(268) = dARP(153)/dV(49)                                     */
  JVRP[268] = V[81];
/* JVRP(269) = dARP(153)/dV(81)                                     */
  JVRP[269] = V[49];
/* JVRP(270) = dARP(154)/dV(72)                                     */
  JVRP[270] = V[82];
/* JVRP(271) = dARP(154)/dV(82)                                     */
  JVRP[271] = V[72];
/* JVRP(272) = dARP(155)/dV(72)                                     */
  JVRP[272] = V[82];
/* JVRP(273) = dARP(155)/dV(82)                                     */
  JVRP[273] = V[72];
/* JVRP(274) = dARP(156)/dV(42)                                     */
  JVRP[274] = V[80];
/* JVRP(275) = dARP(156)/dV(80)                                     */
  JVRP[275] = V[42];
/* JVRP(276) = dARP(157)/dV(42)                                     */
  JVRP[276] = V[81];
/* JVRP(277) = dARP(157)/dV(81)                                     */
  JVRP[277] = V[42];
/* JVRP(278) = dARP(158)/dV(44)                                     */
  JVRP[278] = V[82];
/* JVRP(279) = dARP(158)/dV(82)                                     */
  JVRP[279] = V[44];
/* JVRP(280) = dARP(159)/dV(69)                                     */
  JVRP[280] = V[81];
/* JVRP(281) = dARP(159)/dV(81)                                     */
  JVRP[281] = V[69];
/* JVRP(282) = dARP(160)/dV(68)                                     */
  JVRP[282] = V[81];
/* JVRP(283) = dARP(160)/dV(81)                                     */
  JVRP[283] = V[68];
/* JVRP(284) = dARP(161)/dV(68)                                     */
  JVRP[284] = V[77];
/* JVRP(285) = dARP(161)/dV(77)                                     */
  JVRP[285] = V[68];
/* JVRP(286) = dARP(162)/dV(69)                                     */
  JVRP[286] = V[77];
/* JVRP(287) = dARP(162)/dV(77)                                     */
  JVRP[287] = V[69];
/* JVRP(288) = dARP(163)/dV(67)                                     */
  JVRP[288] = V[77];
/* JVRP(289) = dARP(163)/dV(77)                                     */
  JVRP[289] = V[67];
/* JVRP(290) = dARP(164)/dV(15)                                     */
  JVRP[290] = V[83];
/* JVRP(291) = dARP(164)/dV(83)                                     */
  JVRP[291] = V[15];
/* JVRP(292) = dARP(165)/dV(16)                                     */
  JVRP[292] = V[83];
/* JVRP(293) = dARP(165)/dV(83)                                     */
  JVRP[293] = V[16];
/* JVRP(294) = dARP(166)/dV(10)                                     */
  JVRP[294] = V[73];
/* JVRP(295) = dARP(166)/dV(73)                                     */
  JVRP[295] = V[10];
/* JVRP(296) = dARP(167)/dV(11)                                     */
  JVRP[296] = V[73];
/* JVRP(297) = dARP(167)/dV(73)                                     */
  JVRP[297] = V[11];
/* JVRP(298) = dARP(168)/dV(12)                                     */
  JVRP[298] = V[73];
/* JVRP(299) = dARP(168)/dV(73)                                     */
  JVRP[299] = V[12];
/* JVRP(300) = dARP(169)/dV(13)                                     */
  JVRP[300] = V[73];
/* JVRP(301) = dARP(169)/dV(73)                                     */
  JVRP[301] = V[13];
/* JVRP(302) = dARP(170)/dV(14)                                     */
  JVRP[302] = V[73];
/* JVRP(303) = dARP(170)/dV(73)                                     */
  JVRP[303] = V[14];
/* JVRP(304) = dARP(171)/dV(81)                                     */
  JVRP[304] = V[83];
/* JVRP(305) = dARP(171)/dV(83)                                     */
  JVRP[305] = V[81];
/* JVRP(306) = dARP(172)/dV(70)                                     */
  JVRP[306] = 1;
/* JVRP(307) = dARP(173)/dV(70)                                     */
  JVRP[307] = V[83];
/* JVRP(308) = dARP(173)/dV(83)                                     */
  JVRP[308] = V[70];
/* JVRP(309) = dARP(174)/dV(17)                                     */
  JVRP[309] = V[83];
/* JVRP(310) = dARP(174)/dV(83)                                     */
  JVRP[310] = V[17];
/* JVRP(311) = dARP(175)/dV(82)                                     */
  JVRP[311] = 2*V[82];
/* JVRP(312) = dARP(176)/dV(31)                                     */
  JVRP[312] = V[83];
/* JVRP(313) = dARP(176)/dV(83)                                     */
  JVRP[313] = V[31];
/* JVRP(314) = dARP(177)/dV(81)                                     */
  JVRP[314] = V[82];
/* JVRP(315) = dARP(177)/dV(82)                                     */
  JVRP[315] = V[81];
}

/* End of JacReactantProd function                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



/* Begin Derivative w.r.t. Rate Coefficients                        */


/* End Derivative w.r.t. Rate Coefficients                          */


/* Begin Jacobian Derivative w.r.t. Rate Coefficients               */


/* End Jacobian Derivative w.r.t. Rate Coefficients                 */

