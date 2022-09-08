/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The Reaction Rates File                                          */
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
/* File                 : cbm4_mp_Rates.c                           */
/* Time                 : Fri Sep  2 14:40:52 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/cbm4_mp */
/* Equation file        : cbm4_mp.kpp                               */
/* Output root filename : cbm4_mp                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "cbm4_mp_Parameters.h"
#include "cbm4_mp_Global.h"
#include "cbm4_mp_Sparse.h"



/* Begin Rate Law Functions from KPP_HOME/util/UserRateLaws         */

/*  User-defined Rate Law functions
    Note: the default argument type for rate laws, as read from the equations file, is single precision
         but all the internal calculations are performed in double precision
*/
/* Arrhenius */
float  ARR( float A0, float B0, float C0 )
      {
      float ARR_RES;
                 
      ARR_RES = A0 * expf( -B0/TEMP ) 
                * powf( (TEMP/300.0), C0 );   
           
      return ARR_RES;
      }           


/* Simplified Arrhenius, with two arguments */
/* Note that the argument B0 has a changed sign when compared to ARR */
float  ARR2(  float A0, float B0 )
      {
      float ARR_RES;           

      ARR_RES =  A0 * expf( B0/TEMP );   
           
      return ARR_RES;
      }           


float  EP2( float A0, float C0, float A2, float C2, float A3, float C3)
      {                       
      float K0, K2, K3, EP2_RES;
      
      K0 = A0 * expf( -C0/TEMP );
      K2 = A2 * expf( -C2/TEMP );
      K3 = A3 * expf( -C3/TEMP );
      K3 = K3*CFACTOR*1.0e+6;
      EP2_RES = K0 + K3/( 1.0+K3/K2 );
        
      return EP2_RES;
      }  


float  EP3( float A1, float C1, float A2, float C2) 
      {               
      float K1, K2, EP3_RES;
      
      K1 = A1 * expf(-C1/TEMP);
      K2 = A2 * expf(-C2/TEMP);
      EP3_RES = K1 + K2*(1.0e+6*CFACTOR);
      
      return EP3_RES;
      }    


float  FALL (  float A0, float B0, float C0, float A1, float B1, float C1, float CF)
      {                      
      float K0, K1, FALL_RES;
      
      K0 = A0 * expf(-B0/TEMP)* powf( (TEMP/300.0), C0 );
      K1 = A1 * expf(-B1/TEMP)* powf( (TEMP/300.0), C1 );
      K0 = K0*CFACTOR*1.0e+6;
      K1 = K0/K1;
      FALL_RES = (K0/(1.0+K1))*
           powf( CF, ( 1.0/( 1.0+powf( (log10f(K1)),2 ) ) ) );
        
      return FALL_RES;
      }

/* End Rate Law Functions from KPP_HOME/util/UserRateLaws           */


/* Begin INLINED Rate Law Functions                                 */


/* End INLINED Rate Law Functions                                   */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Update_SUN - update SUN light using TIME                         */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Update_SUN()
{
float SunRise, SunSet;
float Thour, Tlocal, Ttmp; 
const float PI = 3.14159265358979;  

  SunRise = 4.5;
  SunSet  = 19.5;
  Thour = TIME/3600.0;
  Tlocal = Thour - ((int)Thour/24)*24;

  if ( (Tlocal >= SunRise) && (Tlocal <= SunSet) ) {
    Ttmp = (2.0*Tlocal-SunRise-SunSet)/(SunSet-SunRise);
    if (Ttmp > 0) Ttmp =  Ttmp*Ttmp;
             else Ttmp = -Ttmp*Ttmp;
    SUN = ( 1.0 + cos(PI*Ttmp) )/2.0; 
  } else {
    SUN=0.0;
  }
}

#if defined(__MIXEDPREC)
void Update_SUN_D()
{
double SunRise, SunSet;
double Thour, Tlocal, Ttmp; 
const double PI = 3.14159265358979;  

  SunRise = 4.5;
  SunSet  = 19.5;
  Thour = FUNTIME/(double)3600.0;
  Tlocal = Thour - ((int)Thour/24)*24;

  if ( (Tlocal >= SunRise) && (Tlocal <= SunSet) ) {
    Ttmp = ((double)2.0*Tlocal-SunRise-SunSet)/(SunSet-SunRise);
    if (Ttmp > 0) Ttmp =  Ttmp*Ttmp;
             else Ttmp = -Ttmp*Ttmp;
    SUN = ( 1.0 + cos(PI*Ttmp) )/2.0; 
  } else {
    SUN=0.0;
  }
}
#endif
/* End of Update_SUN function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Update_RCONST - function to update rate constants                */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Update_RCONST( 
)
{


/* Begin INLINED RCONST                                             */


/* End INLINED RCONST                                               */

  RCONST[0] = (8.89E-3*SUN);
  RCONST[1] = (ARR2(1.4E+3,1175.0));
  RCONST[2] = (ARR2(1.8E-12,-1370.0));
  RCONST[4] = (ARR2(1.6E-13,687.0));
  RCONST[5] = (ARR2(2.2E-13,602.0));
  RCONST[6] = (ARR2(1.2E-13,-2450.0));
  RCONST[7] = (3.556E-04*SUN);
  RCONST[8] = (2.489E-05*SUN);
  RCONST[9] = (ARR2(1.9E+8,390.0));
  RCONST[11] = (ARR2(1.6E-12,-940.0));
  RCONST[12] = (ARR2(1.4E-14,-580.0));
  RCONST[13] = (1.378E-01*SUN);
  RCONST[14] = (ARR2(1.3E-11,250.0));
  RCONST[15] = (ARR2(2.5E-14,-1230.0));
  RCONST[16] = (ARR2(5.3E-13,256.0));
  RCONST[18] = (ARR2(3.5E+14,-10897.0));
  RCONST[19] = (ARR2(1.8E-20,530.0));
  RCONST[21] = (ARR2(4.5E-13,806.0));
  RCONST[22] = (1.511e-03*SUN);
  RCONST[25] = (ARR2(1.0E-12,713.0));
  RCONST[26] = (ARR2(5.1E-15,1000.0));
  RCONST[27] = (ARR2(3.7E-12,240.0));
  RCONST[28] = (ARR2(1.2E-13,749.0));
  RCONST[29] = (ARR2(4.8E+13,-10121.0));
  RCONST[30] = (ARR2(1.3E-12,380.0));
  RCONST[31] = (ARR2(5.9E-14,1150.0));
  RCONST[32] = (ARR2(2.2E-38,5800.0));
  RCONST[33] = (6.312E-06*SUN);
  RCONST[34] = (ARR2(3.1E-12,-187.0));
  RCONST[37] = (2.845E-05*SUN);
  RCONST[38] = (3.734E-05*SUN);
  RCONST[39] = (ARR2(3.0E-11,-1550.0));
  RCONST[41] = (ARR2(1.2E-11,-986.0));
  RCONST[42] = (ARR2(7.0E-12,250.0));
  RCONST[44] = (4.00E-06*SUN);
  RCONST[45] = (ARR2(5.4E-12,250.0));
  RCONST[46] = (ARR2(8.0E-20,5500.0));
  RCONST[47] = (ARR2(9.4E+16,-14000.0));
  RCONST[50] = (ARR2(1.1E+2,-1710.0));
  RCONST[52] = (ARR2(1.0E+15,-8000.0));
  RCONST[55] = (ARR2(1.2E-11,-324.0));
  RCONST[56] = (ARR2(5.2E-12,504.0));
  RCONST[57] = (ARR2(1.4E-14,-2105.0));
  RCONST[59] = (ARR2(1.0E-11,-792.0));
  RCONST[60] = (ARR2(2.0E-12,411.0));
  RCONST[61] = (ARR2(1.3E-14,-2633.0));
  RCONST[62] = (ARR2(2.1E-12,322.0));
  RCONST[68] = (ARR2(1.7E-11,116.0));
  RCONST[70] = (5.334E-05*SUN);
  RCONST[71] = (ARR2(5.4E-17,-500.0));
  RCONST[73] = (1.654E-04*SUN);
  RCONST[79] = (ARR2(1.7E-14,1300.0));
}

/* End of Update_RCONST function                                    */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Update_PHOTO - function to update photolytical rate constants    */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Update_PHOTO( 
)
{

  RCONST[0] = (8.89E-3*SUN);
  RCONST[7] = (3.556E-04*SUN);
  RCONST[8] = (2.489E-05*SUN);
  RCONST[13] = (1.378E-01*SUN);
  RCONST[22] = (1.511e-03*SUN);
  RCONST[33] = (6.312E-06*SUN);
  RCONST[37] = (2.845E-05*SUN);
  RCONST[38] = (3.734E-05*SUN);
  RCONST[44] = (4.00E-06*SUN);
  RCONST[70] = (5.334E-05*SUN);
  RCONST[73] = (1.654E-04*SUN);
}

/* End of Update_PHOTO function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


