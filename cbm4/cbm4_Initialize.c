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
/* File                 : cbm4_Initialize.c                         */
/* Time                 : Wed Apr  6 15:24:54 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/cbm4   */
/* Equation file        : cbm4.kpp                                  */
/* Output root filename : cbm4                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "cbm4_Parameters.h"
#include "cbm4_Global.h"
#include "cbm4_Sparse.h"


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
float x;                                

  CFACTOR = 2.550000e+10;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NVAR; i++ )
    VAR[i] = x;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NFIX; i++ )
    FIX[i] = x;

  VAR[2] = (1.0)*CFACTOR;
  VAR[4] = (10.0)*CFACTOR;
  VAR[6] = (10.0)*CFACTOR;
  VAR[8] = (1.0)*CFACTOR;
  VAR[15] = (300.0)*CFACTOR;
  VAR[16] = (10.0)*CFACTOR;
  VAR[19] = (50.0)*CFACTOR;
  VAR[20] = (10.0)*CFACTOR;
  VAR[21] = (10.0)*CFACTOR;
  VAR[22] = (10.0)*CFACTOR;
  VAR[23] = (10)*CFACTOR;
  VAR[24] = (100.0)*CFACTOR;
  VAR[25] = (20.0)*CFACTOR;
  VAR[30] = (50.0)*CFACTOR;
  FIX[0] = (1.25E+8)*CFACTOR;
/* constant rate coefficients                                       */
  RCONST[3] = 9.3e-12;
  RCONST[10] = 2.2e-10;
  RCONST[17] = 1.3e-21;
  RCONST[20] = 4.39999e-40;
  RCONST[23] = 6.6e-12;
  RCONST[24] = 1e-20;
  RCONST[35] = 2.2e-13;
  RCONST[36] = 1e-11;
  RCONST[40] = 6.3e-16;
  RCONST[43] = 2.5e-15;
  RCONST[48] = 2e-12;
  RCONST[49] = 6.5e-12;
  RCONST[51] = 8.1e-13;
  RCONST[53] = 1600;
  RCONST[54] = 1.5e-11;
  RCONST[58] = 7.7e-15;
  RCONST[63] = 8.1e-12;
  RCONST[64] = 4.2;
  RCONST[65] = 4.1e-11;
  RCONST[66] = 2.2e-11;
  RCONST[67] = 1.4e-11;
  RCONST[69] = 3e-11;
  RCONST[72] = 1.7e-11;
  RCONST[74] = 1.8e-11;
  RCONST[75] = 9.6e-11;
  RCONST[76] = 1.2e-17;
  RCONST[77] = 3.2e-13;
  RCONST[78] = 8.1e-12;
  RCONST[80] = 6.8e-13;
/* END constant rate coefficients                                   */

/* INLINED initializations                                          */

   TSTART = 12.0*3600.0;
   TEND = TSTART + 24.0*3600.0*5;
   DT = 3600.0;
   TEMP = 288.15;

/* End INLINED initializations                                      */

}

/* End of Initialize function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


