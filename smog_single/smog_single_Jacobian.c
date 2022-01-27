/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The ODE Jacobian of Chemical Model File                          */
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
/* File                 : smog_single_Jacobian.c                    */
/* Time                 : Thu Jan 27 12:47:01 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/smog_single */
/* Equation file        : smog_single.kpp                           */
/* Output root filename : smog_single                               */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "smog_single_Parameters.h"
#include "smog_single_Global.h"
#include "smog_single_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Jac_SP - the Jacobian of Variables in sparse matrix representation */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      JVS       - sparse Jacobian of variables                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Jac_SP( 
  float V[],                             /* Concentrations of variable species (local) */
  float F[],                             /* Concentrations of fixed species (local) */
  float RCT[],                           /* Rate constants (local) */
  float JVS[]                            /* sparse Jacobian of variables */
)
{

/* Local variables                                                  */
float B[21];                             /* Temporary array */

/* B(0) = dA(0)/dV(10)                                              */
  B[0] = RCT[0];
/* B(1) = dA(1)/dV(1)                                               */
  B[1] = 2.183e-05*F[1];
/* B(3) = dA(2)/dV(4)                                               */
  B[3] = 26.59*V[9];
/* B(4) = dA(2)/dV(9)                                               */
  B[4] = 26.59*V[4];
/* B(5) = dA(3)/dV(2)                                               */
  B[5] = 3775*V[11];
/* B(6) = dA(3)/dV(11)                                              */
  B[6] = 3775*V[2];
/* B(7) = dA(4)/dV(7)                                               */
  B[7] = 23410*V[11];
/* B(8) = dA(4)/dV(11)                                              */
  B[8] = 23410*V[7];
/* B(9) = dA(5)/dV(7)                                               */
  B[9] = RCT[5];
/* B(10) = dA(6)/dV(5)                                              */
  B[10] = 12140*V[9];
/* B(11) = dA(6)/dV(9)                                              */
  B[11] = 12140*V[5];
/* B(12) = dA(7)/dV(8)                                              */
  B[12] = 11270*V[9];
/* B(13) = dA(7)/dV(9)                                              */
  B[13] = 11270*V[8];
/* B(14) = dA(8)/dV(6)                                              */
  B[14] = 11270*V[9];
/* B(15) = dA(8)/dV(9)                                              */
  B[15] = 11270*V[6];
/* B(16) = dA(9)/dV(10)                                             */
  B[16] = 16130*V[11];
/* B(17) = dA(9)/dV(11)                                             */
  B[17] = 16130*V[10];
/* B(18) = dA(10)/dV(6)                                             */
  B[18] = 6893*V[10];
/* B(19) = dA(10)/dV(10)                                            */
  B[19] = 6893*V[6];
/* B(20) = dA(11)/dV(3)                                             */
  B[20] = 0.02143;

/* Construct the Jacobian terms from B's                            */
/* JVS(0) = Jac_FULL(0,0)                                           */
  JVS[0] = 0;
/* JVS(1) = Jac_FULL(0,10)                                          */
  JVS[1] = B[16];
/* JVS(2) = Jac_FULL(0,11)                                          */
  JVS[2] = B[17];
/* JVS(3) = Jac_FULL(1,1)                                           */
  JVS[3] = -B[1];
/* JVS(4) = Jac_FULL(1,10)                                          */
  JVS[4] = B[0];
/* JVS(5) = Jac_FULL(2,2)                                           */
  JVS[5] = -B[5];
/* JVS(6) = Jac_FULL(2,11)                                          */
  JVS[6] = -B[6];
/* JVS(7) = Jac_FULL(3,3)                                           */
  JVS[7] = -B[20];
/* JVS(8) = Jac_FULL(3,6)                                           */
  JVS[8] = B[18];
/* JVS(9) = Jac_FULL(3,10)                                          */
  JVS[9] = B[19];
/* JVS(10) = Jac_FULL(4,1)                                          */
  JVS[10] = B[1];
/* JVS(11) = Jac_FULL(4,4)                                          */
  JVS[11] = -B[3];
/* JVS(12) = Jac_FULL(4,9)                                          */
  JVS[12] = -B[4];
/* JVS(13) = Jac_FULL(4,10)                                         */
  JVS[13] = 0;
/* JVS(14) = Jac_FULL(5,5)                                          */
  JVS[14] = -B[10];
/* JVS(15) = Jac_FULL(5,7)                                          */
  JVS[15] = B[9];
/* JVS(16) = Jac_FULL(5,8)                                          */
  JVS[16] = B[12];
/* JVS(17) = Jac_FULL(5,9)                                          */
  JVS[17] = -B[11]+B[13];
/* JVS(18) = Jac_FULL(6,3)                                          */
  JVS[18] = B[20];
/* JVS(19) = Jac_FULL(6,6)                                          */
  JVS[19] = -B[14]-B[18];
/* JVS(20) = Jac_FULL(6,7)                                          */
  JVS[20] = B[7];
/* JVS(21) = Jac_FULL(6,9)                                          */
  JVS[21] = -B[15];
/* JVS(22) = Jac_FULL(6,10)                                         */
  JVS[22] = -B[19];
/* JVS(23) = Jac_FULL(6,11)                                         */
  JVS[23] = B[8];
/* JVS(24) = Jac_FULL(7,7)                                          */
  JVS[24] = -B[7]-B[9];
/* JVS(25) = Jac_FULL(7,8)                                          */
  JVS[25] = B[12];
/* JVS(26) = Jac_FULL(7,9)                                          */
  JVS[26] = B[13];
/* JVS(27) = Jac_FULL(7,11)                                         */
  JVS[27] = -B[8];
/* JVS(28) = Jac_FULL(8,2)                                          */
  JVS[28] = B[5];
/* JVS(29) = Jac_FULL(8,6)                                          */
  JVS[29] = B[14];
/* JVS(30) = Jac_FULL(8,7)                                          */
  JVS[30] = B[9];
/* JVS(31) = Jac_FULL(8,8)                                          */
  JVS[31] = -B[12];
/* JVS(32) = Jac_FULL(8,9)                                          */
  JVS[32] = -B[13]+B[15];
/* JVS(33) = Jac_FULL(8,10)                                         */
  JVS[33] = 0;
/* JVS(34) = Jac_FULL(8,11)                                         */
  JVS[34] = B[6];
/* JVS(35) = Jac_FULL(9,4)                                          */
  JVS[35] = -B[3];
/* JVS(36) = Jac_FULL(9,5)                                          */
  JVS[36] = -B[10];
/* JVS(37) = Jac_FULL(9,6)                                          */
  JVS[37] = -B[14];
/* JVS(38) = Jac_FULL(9,7)                                          */
  JVS[38] = 0;
/* JVS(39) = Jac_FULL(9,8)                                          */
  JVS[39] = -B[12];
/* JVS(40) = Jac_FULL(9,9)                                          */
  JVS[40] = -B[4]-B[11]-B[13]-B[15];
/* JVS(41) = Jac_FULL(9,10)                                         */
  JVS[41] = B[0];
/* JVS(42) = Jac_FULL(9,11)                                         */
  JVS[42] = 0;
/* JVS(43) = Jac_FULL(10,3)                                         */
  JVS[43] = B[20];
/* JVS(44) = Jac_FULL(10,4)                                         */
  JVS[44] = B[3];
/* JVS(45) = Jac_FULL(10,5)                                         */
  JVS[45] = B[10];
/* JVS(46) = Jac_FULL(10,6)                                         */
  JVS[46] = B[14]-B[18];
/* JVS(47) = Jac_FULL(10,7)                                         */
  JVS[47] = 0;
/* JVS(48) = Jac_FULL(10,8)                                         */
  JVS[48] = B[12];
/* JVS(49) = Jac_FULL(10,9)                                         */
  JVS[49] = B[4]+B[11]+B[13]+B[15];
/* JVS(50) = Jac_FULL(10,10)                                        */
  JVS[50] = -B[0]-B[16]-B[19];
/* JVS(51) = Jac_FULL(10,11)                                        */
  JVS[51] = -B[17];
/* JVS(52) = Jac_FULL(11,2)                                         */
  JVS[52] = -B[5];
/* JVS(53) = Jac_FULL(11,5)                                         */
  JVS[53] = B[10];
/* JVS(54) = Jac_FULL(11,7)                                         */
  JVS[54] = -B[7];
/* JVS(55) = Jac_FULL(11,8)                                         */
  JVS[55] = 0;
/* JVS(56) = Jac_FULL(11,9)                                         */
  JVS[56] = B[11];
/* JVS(57) = Jac_FULL(11,10)                                        */
  JVS[57] = -B[16];
/* JVS(58) = Jac_FULL(11,11)                                        */
  JVS[58] = -B[6]-B[8]-B[17];
}

/* End of Jac_SP function                                           */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Jac_SP_Vec - function for sparse multiplication: sparse Jacobian times vector */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      UV        - User vector for variables                       */
/*      JUV       - Jacobian times user vector                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Jac_SP_Vec( 
  float JVS[],                           /* sparse Jacobian of variables */
  float UV[],                            /* User vector for variables */
  float JUV[]                            /* Jacobian times user vector */
)
{
  JUV[0] = JVS[0]*UV[0]+JVS[1]*UV[10]+JVS[2]*UV[11];
  JUV[1] = JVS[3]*UV[1]+JVS[4]*UV[10];
  JUV[2] = JVS[5]*UV[2]+JVS[6]*UV[11];
  JUV[3] = JVS[7]*UV[3]+JVS[8]*UV[6]+JVS[9]*UV[10];
  JUV[4] = JVS[10]*UV[1]+JVS[11]*UV[4]+JVS[12]*UV[9];
  JUV[5] = JVS[14]*UV[5]+JVS[15]*UV[7]+JVS[16]*UV[8]+JVS[17]*UV[9];
  JUV[6] = JVS[18]*UV[3]+JVS[19]*UV[6]+JVS[20]*UV[7]+JVS[21]*UV[9]
          +JVS[22]*UV[10]+JVS[23]*UV[11];
  JUV[7] = JVS[24]*UV[7]+JVS[25]*UV[8]+JVS[26]*UV[9]+JVS[27]*UV[11];
  JUV[8] = JVS[28]*UV[2]+JVS[29]*UV[6]+JVS[30]*UV[7]+JVS[31]*UV[8]
          +JVS[32]*UV[9]+JVS[34]*UV[11];
  JUV[9] = JVS[35]*UV[4]+JVS[36]*UV[5]+JVS[37]*UV[6]+JVS[39]*UV[8]
          +JVS[40]*UV[9]+JVS[41]*UV[10];
  JUV[10] = JVS[43]*UV[3]+JVS[44]*UV[4]+JVS[45]*UV[5]+JVS[46]*UV[6]
           +JVS[48]*UV[8]+JVS[49]*UV[9]+JVS[50]*UV[10]+JVS[51]*UV[11];
  JUV[11] = JVS[52]*UV[2]+JVS[53]*UV[5]+JVS[54]*UV[7]+JVS[56]*UV[9]
           +JVS[57]*UV[10]+JVS[58]*UV[11];
}

/* End of Jac_SP_Vec function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* JacTR_SP_Vec - sparse multiplication: sparse Jacobian transposed times vector */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      UV        - User vector for variables                       */
/*      JTUV      - Jacobian transposed times user vector           */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void JacTR_SP_Vec( 
  float JVS[],                           /* sparse Jacobian of variables */
  float UV[],                            /* User vector for variables */
  float JTUV[]                           /* Jacobian transposed times user vector */
)
{
  JTUV[0] = JVS[0]*UV[0];
  JTUV[1] = JVS[3]*UV[1]+JVS[10]*UV[4];
  JTUV[2] = JVS[5]*UV[2]+JVS[28]*UV[8]+JVS[52]*UV[11];
  JTUV[3] = JVS[7]*UV[3]+JVS[18]*UV[6]+JVS[43]*UV[10];
  JTUV[4] = JVS[11]*UV[4]+JVS[35]*UV[9]+JVS[44]*UV[10];
  JTUV[5] = JVS[14]*UV[5]+JVS[36]*UV[9]+JVS[45]*UV[10]+JVS[53]*UV[11];
  JTUV[6] = JVS[8]*UV[3]+JVS[19]*UV[6]+JVS[29]*UV[8]+JVS[37]*UV[9]
           +JVS[46]*UV[10];
  JTUV[7] = JVS[15]*UV[5]+JVS[20]*UV[6]+JVS[24]*UV[7]+JVS[30]*UV[8]
           +JVS[54]*UV[11];
  JTUV[8] = JVS[16]*UV[5]+JVS[25]*UV[7]+JVS[31]*UV[8]+JVS[39]*UV[9]
           +JVS[48]*UV[10];
  JTUV[9] = JVS[12]*UV[4]+JVS[17]*UV[5]+JVS[21]*UV[6]+JVS[26]*UV[7]
           +JVS[32]*UV[8]+JVS[40]*UV[9]+JVS[49]*UV[10]+JVS[56]*UV[11];
  JTUV[10] = JVS[1]*UV[0]+JVS[4]*UV[1]+JVS[9]*UV[3]+JVS[22]*UV[6]
            +JVS[41]*UV[9]+JVS[50]*UV[10]+JVS[57]*UV[11];
  JTUV[11] = JVS[2]*UV[0]+JVS[6]*UV[2]+JVS[23]*UV[6]+JVS[27]*UV[7]
            +JVS[34]*UV[8]+JVS[51]*UV[10]+JVS[58]*UV[11];
}

/* End of JacTR_SP_Vec function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


