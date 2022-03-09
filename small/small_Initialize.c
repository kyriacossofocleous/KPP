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
/* File                 : small_Initialize.c                        */
/* Time                 : Wed Mar  9 12:16:49 2022                  */
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
#include "small_Parameters.h"
#include "small_Global.h"
#include "small_Sparse.h"


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

  x = (0.)*CFACTOR;
  for( i = 0; i < NVAR; i++ )
    VAR[i] = x;

  x = (0.)*CFACTOR;
  for( i = 0; i < NFIX; i++ )
    FIX[i] = x;

  VAR[0] = (9.906E+01)*CFACTOR;
  VAR[1] = (6.624E+08)*CFACTOR;
  VAR[2] = (5.326E+11)*CFACTOR;
  VAR[3] = (8.725E+08)*CFACTOR;
  VAR[4] = (2.240E+08)*CFACTOR;
  FIX[0] = (8.120E+16)*CFACTOR;
  FIX[1] = (1.697E+16)*CFACTOR;
/* constant rate coefficients                                       */
/* END constant rate coefficients                                   */

/* INLINED initializations                                          */

        TSTART = (12*3600);
        TEND = TSTART + (3*24*3600);
        DT = 0.25*3600;
        TEMP = 270;

/* End INLINED initializations                                      */

}

/* End of Initialize function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


