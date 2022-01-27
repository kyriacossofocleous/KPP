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
/* File                 : tropo_single_Initialize.c                 */
/* Time                 : Thu Jan 27 12:39:42 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/tropo_single */
/* Equation file        : tropo_single.kpp                          */
/* Output root filename : tropo_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "tropo_single_Parameters.h"
#include "tropo_single_Global.h"
#include "tropo_single_Sparse.h"


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

  CFACTOR = 1.000000e+00;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NVAR; i++ )
    VAR[i] = x;

  x = (1.0E-8)*CFACTOR;
  for( i = 0; i < NFIX; i++ )
    FIX[i] = x;

  VAR[0] = (1.0)*CFACTOR;
  VAR[22] = (2.0)*CFACTOR;
  VAR[28] = (1700)*CFACTOR;
  VAR[30] = (1E-8)*CFACTOR;
  VAR[40] = (100.0)*CFACTOR;
  VAR[73] = (100.0)*CFACTOR;
  VAR[75] = (0.05)*CFACTOR;
  VAR[77] = (5.0)*CFACTOR;
  VAR[80] = (0.05)*CFACTOR;
  VAR[82] = (0.1)*CFACTOR;
  FIX[0] = (2.E+8)*CFACTOR;
  FIX[1] = (500.0)*CFACTOR;
  FIX[2] = (5.E+7)*CFACTOR;
  FIX[3] = (500)*CFACTOR;
/* constant rate coefficients                                       */
  RCONST[4] = 1.45e-12;
  RCONST[5] = 5e-06;
  RCONST[8] = 2.5e-12;
  RCONST[10] = 7.218e-12;
  RCONST[12] = 1.2794e-11;
  RCONST[15] = 1.3e-21;
  RCONST[16] = 1.7823e-13;
  RCONST[19] = 1.7851e-12;
  RCONST[20] = 6.8868e-06;
  RCONST[22] = 4.7165e-12;
  RCONST[25] = 4e-24;
  RCONST[28] = 1e-20;
  RCONST[31] = 1e-11;
  RCONST[32] = 1e-14;
  RCONST[34] = 2e-12;
  RCONST[35] = 1e-13;
  RCONST[36] = 3.2e-13;
  RCONST[37] = 6e-16;
  RCONST[39] = 2.7e-15;
  RCONST[42] = 4.7e-12;
  RCONST[53] = 4e-17;
  RCONST[54] = 2e-12;
  RCONST[57] = 5e-14;
  RCONST[58] = 5e-14;
  RCONST[59] = 3e-12;
  RCONST[60] = 3e-12;
  RCONST[61] = 3e-12;
  RCONST[62] = 3e-12;
  RCONST[63] = 3e-12;
  RCONST[67] = 7e-16;
  RCONST[68] = 3e-12;
  RCONST[75] = 7e-12;
  RCONST[76] = 7e-13;
  RCONST[77] = 4e-18;
  RCONST[78] = 7e-12;
  RCONST[79] = 7e-13;
  RCONST[80] = 4e-18;
  RCONST[81] = 5e-14;
  RCONST[82] = 5e-14;
  RCONST[83] = 3e-12;
  RCONST[84] = 3e-12;
  RCONST[85] = 7e-14;
  RCONST[86] = 7e-14;
  RCONST[87] = 1.26e-13;
  RCONST[88] = 6.8e-12;
  RCONST[89] = 3e-12;
  RCONST[91] = 1.36e-14;
  RCONST[92] = 1.36e-14;
  RCONST[93] = 1.36e-14;
  RCONST[94] = 1.36e-14;
  RCONST[95] = 1.52e-11;
  RCONST[98] = 1.15e-11;
  RCONST[100] = 1.73e-11;
  RCONST[101] = 4.25e-11;
  RCONST[102] = 1e-11;
  RCONST[103] = 2.8e-11;
  RCONST[104] = 4.7e-12;
  RCONST[109] = 4e-12;
  RCONST[110] = 4e-12;
  RCONST[111] = 1e-12;
  RCONST[115] = 3e-12;
  RCONST[118] = 3e-12;
  RCONST[119] = 1.02e-11;
  RCONST[120] = 4.7e-12;
  RCONST[123] = 3e-12;
  RCONST[126] = 3e-12;
  RCONST[127] = 1.5e-11;
  RCONST[128] = 4.7e-12;
  RCONST[131] = 3e-12;
  RCONST[137] = 3.4e-18;
  RCONST[140] = 3.4e-18;
  RCONST[143] = 3.4e-18;
  RCONST[146] = 1.7e-11;
  RCONST[150] = 3e-12;
  RCONST[151] = 6e-14;
  RCONST[153] = 3e-12;
  RCONST[154] = 3.3e-15;
  RCONST[155] = 6.7e-15;
  RCONST[157] = 3e-12;
  RCONST[158] = 5.2e-16;
  RCONST[159] = 3e-12;
  RCONST[160] = 3e-12;
  RCONST[161] = 7e-14;
  RCONST[162] = 7e-14;
  RCONST[163] = 7e-14;
  RCONST[165] = 5e-14;
  RCONST[166] = 5.44e-17;
  RCONST[167] = 3.46e-17;
  RCONST[168] = 2.21e-17;
  RCONST[169] = 1.03e-15;
  RCONST[170] = 2.16e-16;
  RCONST[173] = 1e-11;
  RCONST[174] = 8.3e-12;
/* END constant rate coefficients                                   */

/* INLINED initializations                                          */

   TSTART = 12.0*3600.0;
   TEND = TSTART + 24.0*3600.0 * 5;
   DT = 3600.0;
   TEMP = 288.15;

/* End INLINED initializations                                      */

}

/* End of Initialize function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


