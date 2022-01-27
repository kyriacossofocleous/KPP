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
/* File                 : smog_single_Stoichiom.c                   */
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
  ARP[0] = V[10];
  ARP[1] = V[1]*F[1];
  ARP[2] = V[4]*V[9];
  ARP[3] = V[2]*V[11];
  ARP[4] = V[7]*V[11];
  ARP[5] = V[7];
  ARP[6] = V[5]*V[9];
  ARP[7] = V[8]*V[9];
  ARP[8] = V[6]*V[9];
  ARP[9] = V[10]*V[11];
  ARP[10] = V[6]*V[10];
  ARP[11] = V[3];
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

/* JVRP(0) = dARP(0)/dV(10)                                         */
  JVRP[0] = 1;
/* JVRP(1) = dARP(1)/dV(1)                                          */
  JVRP[1] = F[1];
/* JVRP(2) = dARP(2)/dV(4)                                          */
  JVRP[2] = V[9];
/* JVRP(3) = dARP(2)/dV(9)                                          */
  JVRP[3] = V[4];
/* JVRP(4) = dARP(3)/dV(2)                                          */
  JVRP[4] = V[11];
/* JVRP(5) = dARP(3)/dV(11)                                         */
  JVRP[5] = V[2];
/* JVRP(6) = dARP(4)/dV(7)                                          */
  JVRP[6] = V[11];
/* JVRP(7) = dARP(4)/dV(11)                                         */
  JVRP[7] = V[7];
/* JVRP(8) = dARP(5)/dV(7)                                          */
  JVRP[8] = 1;
/* JVRP(9) = dARP(6)/dV(5)                                          */
  JVRP[9] = V[9];
/* JVRP(10) = dARP(6)/dV(9)                                         */
  JVRP[10] = V[5];
/* JVRP(11) = dARP(7)/dV(8)                                         */
  JVRP[11] = V[9];
/* JVRP(12) = dARP(7)/dV(9)                                         */
  JVRP[12] = V[8];
/* JVRP(13) = dARP(8)/dV(6)                                         */
  JVRP[13] = V[9];
/* JVRP(14) = dARP(8)/dV(9)                                         */
  JVRP[14] = V[6];
/* JVRP(15) = dARP(9)/dV(10)                                        */
  JVRP[15] = V[11];
/* JVRP(16) = dARP(9)/dV(11)                                        */
  JVRP[16] = V[10];
/* JVRP(17) = dARP(10)/dV(6)                                        */
  JVRP[17] = V[10];
/* JVRP(18) = dARP(10)/dV(10)                                       */
  JVRP[18] = V[6];
/* JVRP(19) = dARP(11)/dV(3)                                        */
  JVRP[19] = 1;
}

/* End of JacReactantProd function                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



/* Begin Derivative w.r.t. Rate Coefficients                        */


/* End Derivative w.r.t. Rate Coefficients                          */


/* Begin Jacobian Derivative w.r.t. Rate Coefficients               */


/* End Jacobian Derivative w.r.t. Rate Coefficients                 */

