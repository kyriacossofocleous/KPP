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
/* File                 : chapman_single_Stoichiom.c                */
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
  ARP[0] = F[1];
  ARP[1] = V[1]*F[1];
  ARP[2] = V[2];
  ARP[3] = V[1]*V[2];
  ARP[4] = V[2];
  ARP[5] = V[0]*F[0];
  ARP[6] = V[0]*V[2];
  ARP[7] = V[2]*V[3];
  ARP[8] = V[1]*V[4];
  ARP[9] = V[4];
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

/* JVRP(0) = dARP(1)/dV(1)                                          */
  JVRP[0] = F[1];
/* JVRP(1) = dARP(2)/dV(2)                                          */
  JVRP[1] = 1;
/* JVRP(2) = dARP(3)/dV(1)                                          */
  JVRP[2] = V[2];
/* JVRP(3) = dARP(3)/dV(2)                                          */
  JVRP[3] = V[1];
/* JVRP(4) = dARP(4)/dV(2)                                          */
  JVRP[4] = 1;
/* JVRP(5) = dARP(5)/dV(0)                                          */
  JVRP[5] = F[0];
/* JVRP(6) = dARP(6)/dV(0)                                          */
  JVRP[6] = V[2];
/* JVRP(7) = dARP(6)/dV(2)                                          */
  JVRP[7] = V[0];
/* JVRP(8) = dARP(7)/dV(2)                                          */
  JVRP[8] = V[3];
/* JVRP(9) = dARP(7)/dV(3)                                          */
  JVRP[9] = V[2];
/* JVRP(10) = dARP(8)/dV(1)                                         */
  JVRP[10] = V[4];
/* JVRP(11) = dARP(8)/dV(4)                                         */
  JVRP[11] = V[1];
/* JVRP(12) = dARP(9)/dV(4)                                         */
  JVRP[12] = 1;
}

/* End of JacReactantProd function                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



/* Begin Derivative w.r.t. Rate Coefficients                        */


/* End Derivative w.r.t. Rate Coefficients                          */


/* Begin Jacobian Derivative w.r.t. Rate Coefficients               */


/* End Jacobian Derivative w.r.t. Rate Coefficients                 */

