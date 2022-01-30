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
/* File                 : small_single_Function.c                   */
/* Time                 : Sun Jan 30 10:24:16 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_single */
/* Equation file        : small_single.kpp                          */
/* Output root filename : small_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "small_single_Parameters.h"
#include "small_single_Global.h"
#include "small_single_Sparse.h"


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
  A[0] = RCT[0]*F[1];
  A[1] = RCT[1]*V[1]*F[1];
  A[2] = RCT[2]*V[2];
  A[3] = RCT[3]*V[1]*V[2];
  A[4] = RCT[4]*V[2];
  A[5] = RCT[5]*V[0]*F[0];
  A[6] = RCT[6]*V[0]*V[2];
  A[7] = RCT[7]*V[2]*V[3];
  A[8] = RCT[8]*V[1]*V[4];
  A[9] = RCT[9]*V[4];

/* Aggregate function                                               */
  Vdot[0] = A[4]-A[5]-A[6];
  Vdot[1] = 2*A[0]-A[1]+A[2]-A[3]+A[5]-A[8]+A[9];
  Vdot[2] = A[1]-A[2]-A[3]-A[4]-A[6]-A[7];
  Vdot[3] = -A[7]+A[8]+A[9];
  Vdot[4] = A[7]-A[8]-A[9];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


