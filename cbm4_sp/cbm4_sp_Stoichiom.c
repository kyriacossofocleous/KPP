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
/* File                 : cbm4_sp_Stoichiom.c                       */
/* Time                 : Fri Sep  2 14:40:32 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/cbm4_sp */
/* Equation file        : cbm4_sp.kpp                               */
/* Output root filename : cbm4_sp                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "cbm4_sp_Parameters.h"
#include "cbm4_sp_Global.h"
#include "cbm4_sp_Sparse.h"


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
  ARP[0] = V[25];
  ARP[1] = V[28];
  ARP[2] = V[24]*V[30];
  ARP[3] = V[25]*V[28];
  ARP[4] = V[25]*V[28];
  ARP[5] = V[28]*V[30];
  ARP[6] = V[24]*V[25];
  ARP[7] = V[24];
  ARP[8] = V[24];
  ARP[9] = V[0];
  ARP[10] = V[0]*F[0];
  ARP[11] = V[24]*V[26];
  ARP[12] = V[24]*V[27];
  ARP[13] = V[29];
  ARP[14] = V[29]*V[30];
  ARP[15] = V[25]*V[29];
  ARP[16] = V[25]*V[29];
  ARP[17] = V[5]*F[0];
  ARP[18] = V[5];
  ARP[19] = V[30]*V[30];
  ARP[20] = V[25]*V[30]*F[0];
  ARP[21] = V[26]*V[30];
  ARP[22] = V[8];
  ARP[23] = V[8]*V[26];
  ARP[24] = V[8]*V[8];
  ARP[25] = V[25]*V[26];
  ARP[26] = V[11]*V[26];
  ARP[27] = V[27]*V[30];
  ARP[28] = V[25]*V[27];
  ARP[29] = V[9];
  ARP[30] = V[9]*V[26];
  ARP[31] = V[27]*V[27];
  ARP[32] = V[27]*V[27]*F[0];
  ARP[33] = V[1];
  ARP[34] = V[1]*V[26];
  ARP[35] = V[15]*V[26];
  ARP[36] = V[20]*V[26];
  ARP[37] = V[20];
  ARP[38] = V[20];
  ARP[39] = V[20]*V[28];
  ARP[40] = V[20]*V[29];
  ARP[41] = V[23]*V[28];
  ARP[42] = V[23]*V[26];
  ARP[43] = V[23]*V[29];
  ARP[44] = V[23];
  ARP[45] = V[30]*V[31];
  ARP[46] = V[25]*V[31];
  ARP[47] = V[2];
  ARP[48] = V[31]*V[31];
  ARP[49] = V[27]*V[31];
  ARP[50] = V[26];
  ARP[51] = V[19]*V[26];
  ARP[52] = V[12];
  ARP[53] = V[12];
  ARP[54] = V[12]*V[25];
  ARP[55] = V[22]*V[28];
  ARP[56] = V[22]*V[26];
  ARP[57] = V[22]*V[24];
  ARP[58] = V[22]*V[29];
  ARP[59] = V[16]*V[28];
  ARP[60] = V[16]*V[26];
  ARP[61] = V[16]*V[24];
  ARP[62] = V[4]*V[26];
  ARP[63] = V[10]*V[30];
  ARP[64] = V[10];
  ARP[65] = V[13]*V[26];
  ARP[66] = V[13]*V[29];
  ARP[67] = V[3]*V[25];
  ARP[68] = V[6]*V[26];
  ARP[69] = V[18]*V[26];
  ARP[70] = V[18];
  ARP[71] = V[18]*V[24];
  ARP[72] = V[14]*V[26];
  ARP[73] = V[14];
  ARP[74] = V[21]*V[28];
  ARP[75] = V[21]*V[26];
  ARP[76] = V[21]*V[24];
  ARP[77] = V[21]*V[29];
  ARP[78] = V[17]*V[30];
  ARP[79] = V[17]*V[17];
  ARP[80] = V[7]*V[30];
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

/* JVRP(0) = dARP(0)/dV(25)                                         */
  JVRP[0] = 1;
/* JVRP(1) = dARP(1)/dV(28)                                         */
  JVRP[1] = 1;
/* JVRP(2) = dARP(2)/dV(24)                                         */
  JVRP[2] = V[30];
/* JVRP(3) = dARP(2)/dV(30)                                         */
  JVRP[3] = V[24];
/* JVRP(4) = dARP(3)/dV(25)                                         */
  JVRP[4] = V[28];
/* JVRP(5) = dARP(3)/dV(28)                                         */
  JVRP[5] = V[25];
/* JVRP(6) = dARP(4)/dV(25)                                         */
  JVRP[6] = V[28];
/* JVRP(7) = dARP(4)/dV(28)                                         */
  JVRP[7] = V[25];
/* JVRP(8) = dARP(5)/dV(28)                                         */
  JVRP[8] = V[30];
/* JVRP(9) = dARP(5)/dV(30)                                         */
  JVRP[9] = V[28];
/* JVRP(10) = dARP(6)/dV(24)                                        */
  JVRP[10] = V[25];
/* JVRP(11) = dARP(6)/dV(25)                                        */
  JVRP[11] = V[24];
/* JVRP(12) = dARP(7)/dV(24)                                        */
  JVRP[12] = 1;
/* JVRP(13) = dARP(8)/dV(24)                                        */
  JVRP[13] = 1;
/* JVRP(14) = dARP(9)/dV(0)                                         */
  JVRP[14] = 1;
/* JVRP(15) = dARP(10)/dV(0)                                        */
  JVRP[15] = F[0];
/* JVRP(16) = dARP(11)/dV(24)                                       */
  JVRP[16] = V[26];
/* JVRP(17) = dARP(11)/dV(26)                                       */
  JVRP[17] = V[24];
/* JVRP(18) = dARP(12)/dV(24)                                       */
  JVRP[18] = V[27];
/* JVRP(19) = dARP(12)/dV(27)                                       */
  JVRP[19] = V[24];
/* JVRP(20) = dARP(13)/dV(29)                                       */
  JVRP[20] = 1;
/* JVRP(21) = dARP(14)/dV(29)                                       */
  JVRP[21] = V[30];
/* JVRP(22) = dARP(14)/dV(30)                                       */
  JVRP[22] = V[29];
/* JVRP(23) = dARP(15)/dV(25)                                       */
  JVRP[23] = V[29];
/* JVRP(24) = dARP(15)/dV(29)                                       */
  JVRP[24] = V[25];
/* JVRP(25) = dARP(16)/dV(25)                                       */
  JVRP[25] = V[29];
/* JVRP(26) = dARP(16)/dV(29)                                       */
  JVRP[26] = V[25];
/* JVRP(27) = dARP(17)/dV(5)                                        */
  JVRP[27] = F[0];
/* JVRP(28) = dARP(18)/dV(5)                                        */
  JVRP[28] = 1;
/* JVRP(29) = dARP(19)/dV(30)                                       */
  JVRP[29] = 2*V[30];
/* JVRP(30) = dARP(20)/dV(25)                                       */
  JVRP[30] = V[30]*F[0];
/* JVRP(31) = dARP(20)/dV(30)                                       */
  JVRP[31] = V[25]*F[0];
/* JVRP(32) = dARP(21)/dV(26)                                       */
  JVRP[32] = V[30];
/* JVRP(33) = dARP(21)/dV(30)                                       */
  JVRP[33] = V[26];
/* JVRP(34) = dARP(22)/dV(8)                                        */
  JVRP[34] = 1;
/* JVRP(35) = dARP(23)/dV(8)                                        */
  JVRP[35] = V[26];
/* JVRP(36) = dARP(23)/dV(26)                                       */
  JVRP[36] = V[8];
/* JVRP(37) = dARP(24)/dV(8)                                        */
  JVRP[37] = 2*V[8];
/* JVRP(38) = dARP(25)/dV(25)                                       */
  JVRP[38] = V[26];
/* JVRP(39) = dARP(25)/dV(26)                                       */
  JVRP[39] = V[25];
/* JVRP(40) = dARP(26)/dV(11)                                       */
  JVRP[40] = V[26];
/* JVRP(41) = dARP(26)/dV(26)                                       */
  JVRP[41] = V[11];
/* JVRP(42) = dARP(27)/dV(27)                                       */
  JVRP[42] = V[30];
/* JVRP(43) = dARP(27)/dV(30)                                       */
  JVRP[43] = V[27];
/* JVRP(44) = dARP(28)/dV(25)                                       */
  JVRP[44] = V[27];
/* JVRP(45) = dARP(28)/dV(27)                                       */
  JVRP[45] = V[25];
/* JVRP(46) = dARP(29)/dV(9)                                        */
  JVRP[46] = 1;
/* JVRP(47) = dARP(30)/dV(9)                                        */
  JVRP[47] = V[26];
/* JVRP(48) = dARP(30)/dV(26)                                       */
  JVRP[48] = V[9];
/* JVRP(49) = dARP(31)/dV(27)                                       */
  JVRP[49] = 2*V[27];
/* JVRP(50) = dARP(32)/dV(27)                                       */
  JVRP[50] = 2*V[27]*F[0];
/* JVRP(51) = dARP(33)/dV(1)                                        */
  JVRP[51] = 1;
/* JVRP(52) = dARP(34)/dV(1)                                        */
  JVRP[52] = V[26];
/* JVRP(53) = dARP(34)/dV(26)                                       */
  JVRP[53] = V[1];
/* JVRP(54) = dARP(35)/dV(15)                                       */
  JVRP[54] = V[26];
/* JVRP(55) = dARP(35)/dV(26)                                       */
  JVRP[55] = V[15];
/* JVRP(56) = dARP(36)/dV(20)                                       */
  JVRP[56] = V[26];
/* JVRP(57) = dARP(36)/dV(26)                                       */
  JVRP[57] = V[20];
/* JVRP(58) = dARP(37)/dV(20)                                       */
  JVRP[58] = 1;
/* JVRP(59) = dARP(38)/dV(20)                                       */
  JVRP[59] = 1;
/* JVRP(60) = dARP(39)/dV(20)                                       */
  JVRP[60] = V[28];
/* JVRP(61) = dARP(39)/dV(28)                                       */
  JVRP[61] = V[20];
/* JVRP(62) = dARP(40)/dV(20)                                       */
  JVRP[62] = V[29];
/* JVRP(63) = dARP(40)/dV(29)                                       */
  JVRP[63] = V[20];
/* JVRP(64) = dARP(41)/dV(23)                                       */
  JVRP[64] = V[28];
/* JVRP(65) = dARP(41)/dV(28)                                       */
  JVRP[65] = V[23];
/* JVRP(66) = dARP(42)/dV(23)                                       */
  JVRP[66] = V[26];
/* JVRP(67) = dARP(42)/dV(26)                                       */
  JVRP[67] = V[23];
/* JVRP(68) = dARP(43)/dV(23)                                       */
  JVRP[68] = V[29];
/* JVRP(69) = dARP(43)/dV(29)                                       */
  JVRP[69] = V[23];
/* JVRP(70) = dARP(44)/dV(23)                                       */
  JVRP[70] = 1;
/* JVRP(71) = dARP(45)/dV(30)                                       */
  JVRP[71] = V[31];
/* JVRP(72) = dARP(45)/dV(31)                                       */
  JVRP[72] = V[30];
/* JVRP(73) = dARP(46)/dV(25)                                       */
  JVRP[73] = V[31];
/* JVRP(74) = dARP(46)/dV(31)                                       */
  JVRP[74] = V[25];
/* JVRP(75) = dARP(47)/dV(2)                                        */
  JVRP[75] = 1;
/* JVRP(76) = dARP(48)/dV(31)                                       */
  JVRP[76] = 2*V[31];
/* JVRP(77) = dARP(49)/dV(27)                                       */
  JVRP[77] = V[31];
/* JVRP(78) = dARP(49)/dV(31)                                       */
  JVRP[78] = V[27];
/* JVRP(79) = dARP(50)/dV(26)                                       */
  JVRP[79] = 1;
/* JVRP(80) = dARP(51)/dV(19)                                       */
  JVRP[80] = V[26];
/* JVRP(81) = dARP(51)/dV(26)                                       */
  JVRP[81] = V[19];
/* JVRP(82) = dARP(52)/dV(12)                                       */
  JVRP[82] = 1;
/* JVRP(83) = dARP(53)/dV(12)                                       */
  JVRP[83] = 1;
/* JVRP(84) = dARP(54)/dV(12)                                       */
  JVRP[84] = V[25];
/* JVRP(85) = dARP(54)/dV(25)                                       */
  JVRP[85] = V[12];
/* JVRP(86) = dARP(55)/dV(22)                                       */
  JVRP[86] = V[28];
/* JVRP(87) = dARP(55)/dV(28)                                       */
  JVRP[87] = V[22];
/* JVRP(88) = dARP(56)/dV(22)                                       */
  JVRP[88] = V[26];
/* JVRP(89) = dARP(56)/dV(26)                                       */
  JVRP[89] = V[22];
/* JVRP(90) = dARP(57)/dV(22)                                       */
  JVRP[90] = V[24];
/* JVRP(91) = dARP(57)/dV(24)                                       */
  JVRP[91] = V[22];
/* JVRP(92) = dARP(58)/dV(22)                                       */
  JVRP[92] = V[29];
/* JVRP(93) = dARP(58)/dV(29)                                       */
  JVRP[93] = V[22];
/* JVRP(94) = dARP(59)/dV(16)                                       */
  JVRP[94] = V[28];
/* JVRP(95) = dARP(59)/dV(28)                                       */
  JVRP[95] = V[16];
/* JVRP(96) = dARP(60)/dV(16)                                       */
  JVRP[96] = V[26];
/* JVRP(97) = dARP(60)/dV(26)                                       */
  JVRP[97] = V[16];
/* JVRP(98) = dARP(61)/dV(16)                                       */
  JVRP[98] = V[24];
/* JVRP(99) = dARP(61)/dV(24)                                       */
  JVRP[99] = V[16];
/* JVRP(100) = dARP(62)/dV(4)                                       */
  JVRP[100] = V[26];
/* JVRP(101) = dARP(62)/dV(26)                                      */
  JVRP[101] = V[4];
/* JVRP(102) = dARP(63)/dV(10)                                      */
  JVRP[102] = V[30];
/* JVRP(103) = dARP(63)/dV(30)                                      */
  JVRP[103] = V[10];
/* JVRP(104) = dARP(64)/dV(10)                                      */
  JVRP[104] = 1;
/* JVRP(105) = dARP(65)/dV(13)                                      */
  JVRP[105] = V[26];
/* JVRP(106) = dARP(65)/dV(26)                                      */
  JVRP[106] = V[13];
/* JVRP(107) = dARP(66)/dV(13)                                      */
  JVRP[107] = V[29];
/* JVRP(108) = dARP(66)/dV(29)                                      */
  JVRP[108] = V[13];
/* JVRP(109) = dARP(67)/dV(3)                                       */
  JVRP[109] = V[25];
/* JVRP(110) = dARP(67)/dV(25)                                      */
  JVRP[110] = V[3];
/* JVRP(111) = dARP(68)/dV(6)                                       */
  JVRP[111] = V[26];
/* JVRP(112) = dARP(68)/dV(26)                                      */
  JVRP[112] = V[6];
/* JVRP(113) = dARP(69)/dV(18)                                      */
  JVRP[113] = V[26];
/* JVRP(114) = dARP(69)/dV(26)                                      */
  JVRP[114] = V[18];
/* JVRP(115) = dARP(70)/dV(18)                                      */
  JVRP[115] = 1;
/* JVRP(116) = dARP(71)/dV(18)                                      */
  JVRP[116] = V[24];
/* JVRP(117) = dARP(71)/dV(24)                                      */
  JVRP[117] = V[18];
/* JVRP(118) = dARP(72)/dV(14)                                      */
  JVRP[118] = V[26];
/* JVRP(119) = dARP(72)/dV(26)                                      */
  JVRP[119] = V[14];
/* JVRP(120) = dARP(73)/dV(14)                                      */
  JVRP[120] = 1;
/* JVRP(121) = dARP(74)/dV(21)                                      */
  JVRP[121] = V[28];
/* JVRP(122) = dARP(74)/dV(28)                                      */
  JVRP[122] = V[21];
/* JVRP(123) = dARP(75)/dV(21)                                      */
  JVRP[123] = V[26];
/* JVRP(124) = dARP(75)/dV(26)                                      */
  JVRP[124] = V[21];
/* JVRP(125) = dARP(76)/dV(21)                                      */
  JVRP[125] = V[24];
/* JVRP(126) = dARP(76)/dV(24)                                      */
  JVRP[126] = V[21];
/* JVRP(127) = dARP(77)/dV(21)                                      */
  JVRP[127] = V[29];
/* JVRP(128) = dARP(77)/dV(29)                                      */
  JVRP[128] = V[21];
/* JVRP(129) = dARP(78)/dV(17)                                      */
  JVRP[129] = V[30];
/* JVRP(130) = dARP(78)/dV(30)                                      */
  JVRP[130] = V[17];
/* JVRP(131) = dARP(79)/dV(17)                                      */
  JVRP[131] = 2*V[17];
/* JVRP(132) = dARP(80)/dV(7)                                       */
  JVRP[132] = V[30];
/* JVRP(133) = dARP(80)/dV(30)                                      */
  JVRP[133] = V[7];
}

/* End of JacReactantProd function                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



/* Begin Derivative w.r.t. Rate Coefficients                        */


/* End Derivative w.r.t. Rate Coefficients                          */


/* Begin Jacobian Derivative w.r.t. Rate Coefficients               */


/* End Jacobian Derivative w.r.t. Rate Coefficients                 */

