/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hessian File                                                     */
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
/* File                 : smog_single_Hessian.c                     */
/* Time                 : Wed Mar  9 12:17:04 2022                  */
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
#include "smog_single_Parameters.h"
#include "smog_single_Global.h"
#include "smog_single_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hessian - function for Hessian (Jac derivative w.r.t. variables) */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Hessian( 
  float V[],                             /* Concentrations of variable species (local) */
  float F[],                             /* Concentrations of fixed species (local) */
  float RCT[],                           /* Rate constants (local) */
  float HESS[]                           /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
)
{
/* --------------------------------------------------------         */
/* Note: HESS is represented in coordinate sparse format:           */
/*       HESS(m) = d^2 f_i / dv_j dv_k = d Jac_{i,j} / dv_k         */
/*       where i = IHESS_I(m), j = IHESS_J(m), k = IHESS_K(m).      */
/* --------------------------------------------------------         */
/* Note: d^2 f_i / dv_j dv_k = d^2 f_i / dv_k dv_j,                 */
/*       therefore only the terms d^2 f_i / dv_j dv_k               */
/*       with j <= k are computed and stored in HESS.               */
/* --------------------------------------------------------         */

/* Local variables                                                  */
float D2A[8];                            /* Second derivatives of equation rates */

/* Computation of the second derivatives of equation rates          */
/* D2A(0) = d^2 A(2) / dV(4)dV(9)                                   */
  D2A[0] = 26.59;
/* D2A(1) = d^2 A(3) / dV(2)dV(11)                                  */
  D2A[1] = 3775;
/* D2A(2) = d^2 A(4) / dV(7)dV(11)                                  */
  D2A[2] = 23410;
/* D2A(3) = d^2 A(6) / dV(5)dV(9)                                   */
  D2A[3] = 12140;
/* D2A(4) = d^2 A(7) / dV(8)dV(9)                                   */
  D2A[4] = 11270;
/* D2A(5) = d^2 A(8) / dV(6)dV(9)                                   */
  D2A[5] = 11270;
/* D2A(6) = d^2 A(9) / dV(10)dV(11)                                 */
  D2A[6] = 16130;
/* D2A(7) = d^2 A(10) / dV(6)dV(10)                                 */
  D2A[7] = 6893;

/* Computation of the Jacobian derivative                           */
/* HESS(0) = d^2 Vdot(0)/{dV(10)dV(11)} = d^2 Vdot(0)/{dV(11)dV(10)} */
  HESS[0] = D2A[6];
/* HESS(1) = d^2 Vdot(2)/{dV(2)dV(11)} = d^2 Vdot(2)/{dV(11)dV(2)}  */
  HESS[1] = -D2A[1];
/* HESS(2) = d^2 Vdot(3)/{dV(6)dV(10)} = d^2 Vdot(3)/{dV(10)dV(6)}  */
  HESS[2] = D2A[7];
/* HESS(3) = d^2 Vdot(4)/{dV(4)dV(9)} = d^2 Vdot(4)/{dV(9)dV(4)}    */
  HESS[3] = -D2A[0];
/* HESS(4) = d^2 Vdot(5)/{dV(5)dV(9)} = d^2 Vdot(5)/{dV(9)dV(5)}    */
  HESS[4] = -D2A[3];
/* HESS(5) = d^2 Vdot(5)/{dV(8)dV(9)} = d^2 Vdot(5)/{dV(9)dV(8)}    */
  HESS[5] = D2A[4];
/* HESS(6) = d^2 Vdot(6)/{dV(6)dV(9)} = d^2 Vdot(6)/{dV(9)dV(6)}    */
  HESS[6] = -D2A[5];
/* HESS(7) = d^2 Vdot(6)/{dV(6)dV(10)} = d^2 Vdot(6)/{dV(10)dV(6)}  */
  HESS[7] = -D2A[7];
/* HESS(8) = d^2 Vdot(6)/{dV(7)dV(11)} = d^2 Vdot(6)/{dV(11)dV(7)}  */
  HESS[8] = D2A[2];
/* HESS(9) = d^2 Vdot(7)/{dV(7)dV(11)} = d^2 Vdot(7)/{dV(11)dV(7)}  */
  HESS[9] = -D2A[2];
/* HESS(10) = d^2 Vdot(7)/{dV(8)dV(9)} = d^2 Vdot(7)/{dV(9)dV(8)}   */
  HESS[10] = D2A[4];
/* HESS(11) = d^2 Vdot(8)/{dV(2)dV(11)} = d^2 Vdot(8)/{dV(11)dV(2)} */
  HESS[11] = D2A[1];
/* HESS(12) = d^2 Vdot(8)/{dV(6)dV(9)} = d^2 Vdot(8)/{dV(9)dV(6)}   */
  HESS[12] = D2A[5];
/* HESS(13) = d^2 Vdot(8)/{dV(8)dV(9)} = d^2 Vdot(8)/{dV(9)dV(8)}   */
  HESS[13] = -D2A[4];
/* HESS(14) = d^2 Vdot(9)/{dV(4)dV(9)} = d^2 Vdot(9)/{dV(9)dV(4)}   */
  HESS[14] = -D2A[0];
/* HESS(15) = d^2 Vdot(9)/{dV(5)dV(9)} = d^2 Vdot(9)/{dV(9)dV(5)}   */
  HESS[15] = -D2A[3];
/* HESS(16) = d^2 Vdot(9)/{dV(6)dV(9)} = d^2 Vdot(9)/{dV(9)dV(6)}   */
  HESS[16] = -D2A[5];
/* HESS(17) = d^2 Vdot(9)/{dV(8)dV(9)} = d^2 Vdot(9)/{dV(9)dV(8)}   */
  HESS[17] = -D2A[4];
/* HESS(18) = d^2 Vdot(10)/{dV(4)dV(9)} = d^2 Vdot(10)/{dV(9)dV(4)} */
  HESS[18] = D2A[0];
/* HESS(19) = d^2 Vdot(10)/{dV(5)dV(9)} = d^2 Vdot(10)/{dV(9)dV(5)} */
  HESS[19] = D2A[3];
/* HESS(20) = d^2 Vdot(10)/{dV(6)dV(9)} = d^2 Vdot(10)/{dV(9)dV(6)} */
  HESS[20] = D2A[5];
/* HESS(21) = d^2 Vdot(10)/{dV(6)dV(10)} = d^2 Vdot(10)/{dV(10)dV(6)} */
  HESS[21] = -D2A[7];
/* HESS(22) = d^2 Vdot(10)/{dV(8)dV(9)} = d^2 Vdot(10)/{dV(9)dV(8)} */
  HESS[22] = D2A[4];
/* HESS(23) = d^2 Vdot(10)/{dV(10)dV(11)} = d^2 Vdot(10)/{dV(11)dV(10)} */
  HESS[23] = -D2A[6];
/* HESS(24) = d^2 Vdot(11)/{dV(2)dV(11)} = d^2 Vdot(11)/{dV(11)dV(2)} */
  HESS[24] = -D2A[1];
/* HESS(25) = d^2 Vdot(11)/{dV(5)dV(9)} = d^2 Vdot(11)/{dV(9)dV(5)} */
  HESS[25] = D2A[3];
/* HESS(26) = d^2 Vdot(11)/{dV(7)dV(11)} = d^2 Vdot(11)/{dV(11)dV(7)} */
  HESS[26] = -D2A[2];
/* HESS(27) = d^2 Vdot(11)/{dV(10)dV(11)} = d^2 Vdot(11)/{dV(11)dV(10)} */
  HESS[27] = -D2A[6];
}

/* End of Hessian function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* HessTR_Vec - Hessian transposed times user vectors               */
/*   Arguments :                                                    */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*      U1        - User vector                                     */
/*      U2        - User vector                                     */
/*      HTU       - Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void HessTR_Vec( 
  float HESS[],                          /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
  float U1[],                            /* User vector */
  float U2[],                            /* User vector */
  float HTU[]                            /* Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2  */
)
{
/* Compute the vector HTU =(Hess x U2)^T * U1 = d (Jac^T*U1)/d Var * U2  */
  HTU[0] = 0;
  HTU[1] = 0;
  HTU[2] = HESS[1]*(U1[2]*U2[11])+HESS[11]*(U1[8]*U2[11])+HESS[24]
          *(U1[11]*U2[11]);
  HTU[3] = 0;
  HTU[4] = HESS[3]*(U1[4]*U2[9])+HESS[14]*(U1[9]*U2[9])+HESS[18]
          *(U1[10]*U2[9]);
  HTU[5] = HESS[4]*(U1[5]*U2[9])+HESS[15]*(U1[9]*U2[9])+HESS[19]
          *(U1[10]*U2[9])+HESS[25]*(U1[11]*U2[9]);
  HTU[6] = HESS[2]*(U1[3]*U2[10])+HESS[6]*(U1[6]*U2[9])+HESS[7]*(U1[6]
          *U2[10])+HESS[12]*(U1[8]*U2[9])+HESS[16]*(U1[9]*U2[9])
          +HESS[20]*(U1[10]*U2[9])+HESS[21]*(U1[10]*U2[10]);
  HTU[7] = HESS[8]*(U1[6]*U2[11])+HESS[9]*(U1[7]*U2[11])+HESS[26]
          *(U1[11]*U2[11]);
  HTU[8] = HESS[5]*(U1[5]*U2[9])+HESS[10]*(U1[7]*U2[9])+HESS[13]*(U1[8]
          *U2[9])+HESS[17]*(U1[9]*U2[9])+HESS[22]*(U1[10]*U2[9]);
  HTU[9] = HESS[3]*(U1[4]*U2[4])+HESS[4]*(U1[5]*U2[5])+HESS[5]*(U1[5]
          *U2[8])+HESS[6]*(U1[6]*U2[6])+HESS[10]*(U1[7]*U2[8])+HESS[12]
          *(U1[8]*U2[6])+HESS[13]*(U1[8]*U2[8])+HESS[14]*(U1[9]*U2[4])
          +HESS[15]*(U1[9]*U2[5])+HESS[16]*(U1[9]*U2[6])+HESS[17]
          *(U1[9]*U2[8])+HESS[18]*(U1[10]*U2[4])+HESS[19]*(U1[10]
          *U2[5])+HESS[20]*(U1[10]*U2[6])+HESS[22]*(U1[10]*U2[8])
          +HESS[25]*(U1[11]*U2[5]);
  HTU[10] = HESS[0]*(U1[0]*U2[11])+HESS[2]*(U1[3]*U2[6])+HESS[7]*(U1[6]
           *U2[6])+HESS[21]*(U1[10]*U2[6])+HESS[23]*(U1[10]*U2[11])
           +HESS[27]*(U1[11]*U2[11]);
  HTU[11] = HESS[0]*(U1[0]*U2[10])+HESS[1]*(U1[2]*U2[2])+HESS[8]*(U1[6]
           *U2[7])+HESS[9]*(U1[7]*U2[7])+HESS[11]*(U1[8]*U2[2])
           +HESS[23]*(U1[10]*U2[10])+HESS[24]*(U1[11]*U2[2])+HESS[26]
           *(U1[11]*U2[7])+HESS[27]*(U1[11]*U2[10]);
}

/* End of HessTR_Vec function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hess_Vec - Hessian times user vectors                            */
/*   Arguments :                                                    */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*      U1        - User vector                                     */
/*      U2        - User vector                                     */
/*      HU        - Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2 */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Hess_Vec( 
  float HESS[],                          /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
  float U1[],                            /* User vector */
  float U2[],                            /* User vector */
  float HU[]                             /* Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2 */
)
{
/* Compute the vector HU =(Hess x U2) * U1 = d (Jac*U1)/d Var * U2  */
  HU[0] = HESS[0]*(U1[10]*U2[11])+HESS[0]*(U1[11]*U2[10]);
  HU[1] = 0;
  HU[2] = HESS[1]*(U1[2]*U2[11])+HESS[1]*(U1[11]*U2[2]);
  HU[3] = HESS[2]*(U1[6]*U2[10])+HESS[2]*(U1[10]*U2[6]);
  HU[4] = HESS[3]*(U1[4]*U2[9])+HESS[3]*(U1[9]*U2[4]);
  HU[5] = HESS[4]*(U1[5]*U2[9])+HESS[4]*(U1[9]*U2[5])+HESS[5]*(U1[8]
         *U2[9])+HESS[5]*(U1[9]*U2[8]);
  HU[6] = HESS[6]*(U1[6]*U2[9])+HESS[6]*(U1[9]*U2[6])+HESS[7]*(U1[6]
         *U2[10])+HESS[7]*(U1[10]*U2[6])+HESS[8]*(U1[7]*U2[11])+HESS[8]
         *(U1[11]*U2[7]);
  HU[7] = HESS[9]*(U1[7]*U2[11])+HESS[9]*(U1[11]*U2[7])+HESS[10]*(U1[8]
         *U2[9])+HESS[10]*(U1[9]*U2[8]);
  HU[8] = HESS[11]*(U1[2]*U2[11])+HESS[11]*(U1[11]*U2[2])+HESS[12]
         *(U1[6]*U2[9])+HESS[12]*(U1[9]*U2[6])+HESS[13]*(U1[8]*U2[9])
         +HESS[13]*(U1[9]*U2[8]);
  HU[9] = HESS[14]*(U1[4]*U2[9])+HESS[14]*(U1[9]*U2[4])+HESS[15]*(U1[5]
         *U2[9])+HESS[15]*(U1[9]*U2[5])+HESS[16]*(U1[6]*U2[9])+HESS[16]
         *(U1[9]*U2[6])+HESS[17]*(U1[8]*U2[9])+HESS[17]*(U1[9]*U2[8]);
  HU[10] = HESS[18]*(U1[4]*U2[9])+HESS[18]*(U1[9]*U2[4])+HESS[19]
          *(U1[5]*U2[9])+HESS[19]*(U1[9]*U2[5])+HESS[20]*(U1[6]*U2[9])
          +HESS[20]*(U1[9]*U2[6])+HESS[21]*(U1[6]*U2[10])+HESS[21]
          *(U1[10]*U2[6])+HESS[22]*(U1[8]*U2[9])+HESS[22]*(U1[9]*U2[8])
          +HESS[23]*(U1[10]*U2[11])+HESS[23]*(U1[11]*U2[10]);
  HU[11] = HESS[24]*(U1[2]*U2[11])+HESS[24]*(U1[11]*U2[2])+HESS[25]
          *(U1[5]*U2[9])+HESS[25]*(U1[9]*U2[5])+HESS[26]*(U1[7]*U2[11])
          +HESS[26]*(U1[11]*U2[7])+HESS[27]*(U1[10]*U2[11])+HESS[27]
          *(U1[11]*U2[10]);
}

/* End of Hess_Vec function                                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


