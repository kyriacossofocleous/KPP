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
/* File                 : small_Jacobian.c                          */
/* Time                 : Sat Jan 29 14:54:10 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small  */
/* Equation file        : small.kpp                                 */
/* Output root filename : small                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "small_Parameters.h"
#include "small_Global.h"
#include "small_Sparse.h"


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
  double V[],                            /* Concentrations of variable species (local) */
  double F[],                            /* Concentrations of fixed species (local) */
  double RCT[],                          /* Rate constants (local) */
  double JVS[]                           /* sparse Jacobian of variables */
)
{

/* Local variables                                                  */
double B[16];                            /* Temporary array */

/* B(1) = dA(1)/dV(1)                                               */
  B[1] = RCT[1]*F[1];
/* B(3) = dA(2)/dV(2)                                               */
  B[3] = RCT[2];
/* B(4) = dA(3)/dV(1)                                               */
  B[4] = RCT[3]*V[2];
/* B(5) = dA(3)/dV(2)                                               */
  B[5] = RCT[3]*V[1];
/* B(6) = dA(4)/dV(2)                                               */
  B[6] = RCT[4];
/* B(7) = dA(5)/dV(0)                                               */
  B[7] = RCT[5]*F[0];
/* B(9) = dA(6)/dV(0)                                               */
  B[9] = RCT[6]*V[2];
/* B(10) = dA(6)/dV(2)                                              */
  B[10] = RCT[6]*V[0];
/* B(11) = dA(7)/dV(2)                                              */
  B[11] = RCT[7]*V[3];
/* B(12) = dA(7)/dV(3)                                              */
  B[12] = RCT[7]*V[2];
/* B(13) = dA(8)/dV(1)                                              */
  B[13] = RCT[8]*V[4];
/* B(14) = dA(8)/dV(4)                                              */
  B[14] = RCT[8]*V[1];
/* B(15) = dA(9)/dV(4)                                              */
  B[15] = RCT[9];

/* Construct the Jacobian terms from B's                            */
/* JVS(0) = Jac_FULL(0,0)                                           */
  JVS[0] = -B[7]-B[9];
/* JVS(1) = Jac_FULL(0,2)                                           */
  JVS[1] = B[6]-B[10];
/* JVS(2) = Jac_FULL(1,0)                                           */
  JVS[2] = B[7];
/* JVS(3) = Jac_FULL(1,1)                                           */
  JVS[3] = -B[1]-B[4]-B[13];
/* JVS(4) = Jac_FULL(1,2)                                           */
  JVS[4] = B[3]-B[5];
/* JVS(5) = Jac_FULL(1,4)                                           */
  JVS[5] = -B[14]+B[15];
/* JVS(6) = Jac_FULL(2,0)                                           */
  JVS[6] = -B[9];
/* JVS(7) = Jac_FULL(2,1)                                           */
  JVS[7] = B[1]-B[4];
/* JVS(8) = Jac_FULL(2,2)                                           */
  JVS[8] = -B[3]-B[5]-B[6]-B[10]-B[11];
/* JVS(9) = Jac_FULL(2,3)                                           */
  JVS[9] = -B[12];
/* JVS(10) = Jac_FULL(2,4)                                          */
  JVS[10] = 0;
/* JVS(11) = Jac_FULL(3,1)                                          */
  JVS[11] = B[13];
/* JVS(12) = Jac_FULL(3,2)                                          */
  JVS[12] = -B[11];
/* JVS(13) = Jac_FULL(3,3)                                          */
  JVS[13] = -B[12];
/* JVS(14) = Jac_FULL(3,4)                                          */
  JVS[14] = B[14]+B[15];
/* JVS(15) = Jac_FULL(4,1)                                          */
  JVS[15] = -B[13];
/* JVS(16) = Jac_FULL(4,2)                                          */
  JVS[16] = B[11];
/* JVS(17) = Jac_FULL(4,3)                                          */
  JVS[17] = B[12];
/* JVS(18) = Jac_FULL(4,4)                                          */
  JVS[18] = -B[14]-B[15];
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
  double JVS[],                          /* sparse Jacobian of variables */
  double UV[],                           /* User vector for variables */
  double JUV[]                           /* Jacobian times user vector */
)
{
  JUV[0] = JVS[0]*UV[0]+JVS[1]*UV[2];
  JUV[1] = JVS[2]*UV[0]+JVS[3]*UV[1]+JVS[4]*UV[2]+JVS[5]*UV[4];
  JUV[2] = JVS[6]*UV[0]+JVS[7]*UV[1]+JVS[8]*UV[2]+JVS[9]*UV[3];
  JUV[3] = JVS[11]*UV[1]+JVS[12]*UV[2]+JVS[13]*UV[3]+JVS[14]*UV[4];
  JUV[4] = JVS[15]*UV[1]+JVS[16]*UV[2]+JVS[17]*UV[3]+JVS[18]*UV[4];
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
  double JVS[],                          /* sparse Jacobian of variables */
  double UV[],                           /* User vector for variables */
  double JTUV[]                          /* Jacobian transposed times user vector */
)
{
  JTUV[0] = JVS[0]*UV[0]+JVS[2]*UV[1]+JVS[6]*UV[2];
  JTUV[1] = JVS[3]*UV[1]+JVS[7]*UV[2]+JVS[11]*UV[3]+JVS[15]*UV[4];
  JTUV[2] = JVS[1]*UV[0]+JVS[4]*UV[1]+JVS[8]*UV[2]+JVS[12]*UV[3]
           +JVS[16]*UV[4];
  JTUV[3] = JVS[9]*UV[2]+JVS[13]*UV[3]+JVS[17]*UV[4];
  JTUV[4] = JVS[5]*UV[1]+JVS[14]*UV[3]+JVS[18]*UV[4];
}

/* End of JacTR_SP_Vec function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


