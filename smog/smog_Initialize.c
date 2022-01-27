/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Initialization File                                              */
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
/* File                 : smog_Initialize.c                         */
/* Time                 : Thu Jan 27 11:36:56 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/smog   */
/* Equation file        : smog.kpp                                  */
/* Output root filename : smog                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "smog_Parameters.h"
#include "smog_Global.h"
#include "smog_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Initialize - function to initialize concentrations               */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Initialize( 
)
{
int i;                                  
double x;                               

  CFACTOR = 1.000000e+00;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NVAR; i++ )
    VAR[i] = x;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NFIX; i++ )
    FIX[i] = x;

  VAR[2] = (2.0)*CFACTOR;
  VAR[7] = (2.0)*CFACTOR;
  VAR[9] = (0.5)*CFACTOR;
  VAR[10] = (0.1)*CFACTOR;
  FIX[0] = (1.3E+4)*CFACTOR;
  FIX[1] = (2.0E+5)*CFACTOR;
/* constant rate coefficients                                       */
  RCONST[1] = 2.183e-05;
  RCONST[2] = 26.59;
  RCONST[3] = 3775;
  RCONST[4] = 23410;
  RCONST[6] = 12140;
  RCONST[7] = 11270;
  RCONST[8] = 11270;
  RCONST[9] = 16130;
  RCONST[10] = 6893;
  RCONST[11] = 0.02143;
/* END constant rate coefficients                                   */

/* INLINED initializations                                          */

   TSTART = 0;
   TEND = TSTART + 600;
   DT = 60.0;
   TEMP = 298;

/* End INLINED initializations                                      */

}

/* End of Initialize function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


