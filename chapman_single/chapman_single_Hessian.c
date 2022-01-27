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
/* File                 : chapman_single_Hessian.c                  */
/* Time                 : Thu Jan 27 11:06:18 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman_single */
/* Equation file        : chapman_single.kpp                        */
/* Output root filename : chapman_single                            */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "chapman_single_Parameters.h"
#include "chapman_single_Global.h"
#include "chapman_single_Sparse.h"


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
float D2A[4];                            /* Second derivatives of equation rates */

/* Computation of the second derivatives of equation rates          */
/* D2A(0) = d^2 A(3) / dV(1)dV(2)                                   */
  D2A[0] = RCT[3];
/* D2A(1) = d^2 A(6) / dV(0)dV(2)                                   */
  D2A[1] = RCT[6];
/* D2A(2) = d^2 A(7) / dV(2)dV(3)                                   */
  D2A[2] = RCT[7];
/* D2A(3) = d^2 A(8) / dV(1)dV(4)                                   */
  D2A[3] = RCT[8];

/* Computation of the Jacobian derivative                           */
/* HESS(0) = d^2 Vdot(0)/{dV(0)dV(2)} = d^2 Vdot(0)/{dV(2)dV(0)}    */
  HESS[0] = -D2A[1];
/* HESS(1) = d^2 Vdot(1)/{dV(1)dV(2)} = d^2 Vdot(1)/{dV(2)dV(1)}    */
  HESS[1] = -D2A[0];
/* HESS(2) = d^2 Vdot(1)/{dV(1)dV(4)} = d^2 Vdot(1)/{dV(4)dV(1)}    */
  HESS[2] = -D2A[3];
/* HESS(3) = d^2 Vdot(2)/{dV(0)dV(2)} = d^2 Vdot(2)/{dV(2)dV(0)}    */
  HESS[3] = -D2A[1];
/* HESS(4) = d^2 Vdot(2)/{dV(1)dV(2)} = d^2 Vdot(2)/{dV(2)dV(1)}    */
  HESS[4] = -D2A[0];
/* HESS(5) = d^2 Vdot(2)/{dV(2)dV(3)} = d^2 Vdot(2)/{dV(3)dV(2)}    */
  HESS[5] = -D2A[2];
/* HESS(6) = d^2 Vdot(3)/{dV(1)dV(4)} = d^2 Vdot(3)/{dV(4)dV(1)}    */
  HESS[6] = D2A[3];
/* HESS(7) = d^2 Vdot(3)/{dV(2)dV(3)} = d^2 Vdot(3)/{dV(3)dV(2)}    */
  HESS[7] = -D2A[2];
/* HESS(8) = d^2 Vdot(4)/{dV(1)dV(4)} = d^2 Vdot(4)/{dV(4)dV(1)}    */
  HESS[8] = -D2A[3];
/* HESS(9) = d^2 Vdot(4)/{dV(2)dV(3)} = d^2 Vdot(4)/{dV(3)dV(2)}    */
  HESS[9] = D2A[2];
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
  HTU[0] = HESS[0]*(U1[0]*U2[2])+HESS[3]*(U1[2]*U2[2]);
  HTU[1] = HESS[1]*(U1[1]*U2[2])+HESS[2]*(U1[1]*U2[4])+HESS[4]*(U1[2]
          *U2[2])+HESS[6]*(U1[3]*U2[4])+HESS[8]*(U1[4]*U2[4]);
  HTU[2] = HESS[0]*(U1[0]*U2[0])+HESS[1]*(U1[1]*U2[1])+HESS[3]*(U1[2]
          *U2[0])+HESS[4]*(U1[2]*U2[1])+HESS[5]*(U1[2]*U2[3])+HESS[7]
          *(U1[3]*U2[3])+HESS[9]*(U1[4]*U2[3]);
  HTU[3] = HESS[5]*(U1[2]*U2[2])+HESS[7]*(U1[3]*U2[2])+HESS[9]*(U1[4]
          *U2[2]);
  HTU[4] = HESS[2]*(U1[1]*U2[1])+HESS[6]*(U1[3]*U2[1])+HESS[8]*(U1[4]
          *U2[1]);
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
  HU[0] = HESS[0]*(U1[0]*U2[2])+HESS[0]*(U1[2]*U2[0]);
  HU[1] = HESS[1]*(U1[1]*U2[2])+HESS[1]*(U1[2]*U2[1])+HESS[2]*(U1[1]
         *U2[4])+HESS[2]*(U1[4]*U2[1]);
  HU[2] = HESS[3]*(U1[0]*U2[2])+HESS[3]*(U1[2]*U2[0])+HESS[4]*(U1[1]
         *U2[2])+HESS[4]*(U1[2]*U2[1])+HESS[5]*(U1[2]*U2[3])+HESS[5]
         *(U1[3]*U2[2]);
  HU[3] = HESS[6]*(U1[1]*U2[4])+HESS[6]*(U1[4]*U2[1])+HESS[7]*(U1[2]
         *U2[3])+HESS[7]*(U1[3]*U2[2]);
  HU[4] = HESS[8]*(U1[1]*U2[4])+HESS[8]*(U1[4]*U2[1])+HESS[9]*(U1[2]
         *U2[3])+HESS[9]*(U1[3]*U2[2]);
}

/* End of Hess_Vec function                                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


