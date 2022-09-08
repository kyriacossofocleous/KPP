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
/* File                 : tropo_dp_Rates.c                          */
/* Time                 : Fri Sep  2 14:40:27 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/tropo_dp */
/* Equation file        : tropo_dp.kpp                              */
/* Output root filename : tropo_dp                                  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "tropo_dp_Parameters.h"
#include "tropo_dp_Global.h"
#include "tropo_dp_Sparse.h"



/* Begin Rate Law Functions from KPP_HOME/util/UserRateLaws         */

/*  User-defined Rate Law functions
    Note: the default argument type for rate laws, as read from the equations file, is single precision
         but all the internal calculations are performed in double precision
*/
/* Arrhenius */
double  ARR( double A0, double B0, double C0 )
      {
      double ARR_RES;
                 
      ARR_RES = A0 * expf( -B0/TEMP ) 
                * powf( (TEMP/300.0), C0 );   
           
      return ARR_RES;
      }           


/* Simplified Arrhenius, with two arguments */
/* Note that the argument B0 has a changed sign when compared to ARR */
double  ARR2(  double A0, double B0 )
      {
      double ARR_RES;           

      ARR_RES =  A0 * expf( B0/TEMP );   
           
      return ARR_RES;
      }           


double  EP2( double A0, double C0, double A2, double C2, double A3, double C3)
      {                       
      double K0, K2, K3, EP2_RES;
      
      K0 = A0 * expf( -C0/TEMP );
      K2 = A2 * expf( -C2/TEMP );
      K3 = A3 * expf( -C3/TEMP );
      K3 = K3*CFACTOR*1.0e+6;
      EP2_RES = K0 + K3/( 1.0+K3/K2 );
        
      return EP2_RES;
      }  


double  EP3( double A1, double C1, double A2, double C2) 
      {               
      double K1, K2, EP3_RES;
      
      K1 = A1 * expf(-C1/TEMP);
      K2 = A2 * expf(-C2/TEMP);
      EP3_RES = K1 + K2*(1.0e+6*CFACTOR);
      
      return EP3_RES;
      }    


double  FALL (  double A0, double B0, double C0, double A1, double B1, double C1, double CF)
      {                      
      double K0, K1, FALL_RES;
      
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
double SunRise, SunSet;
double Thour, Tlocal, Ttmp; 
const double PI = 3.14159265358979;  

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

  RCONST[0] = (1.765E-2*SUN);
  RCONST[1] = (ARR2(2.2E-12,-1430.0));
  RCONST[2] = (ARR2(1.2E-13,-2450.0));
  RCONST[3] = (ARR2(1.7E-11,150.0));
  RCONST[6] = (ARR2(2.5E-14,-1230.0));
  RCONST[7] = (3.29*RCONST[1]);
  RCONST[9] = (1.5796E-7*SUN);
  RCONST[11] = (0.205*RCONST[1]);
  RCONST[13] = (7.8E-7*SUN);
  RCONST[14] = (ARR2(9.4E-15,778.0));
  RCONST[17] = (ARR2(1.6E-12,-1000.0));
  RCONST[18] = (ARR2(3.7E-12,240.0));
  RCONST[21] = (ARR2(1.4E-14,-600.0));
  RCONST[23] = (1.366E-5*SUN);
  RCONST[24] = (ARR2(3.3E-12,-200.0));
  RCONST[26] = (1E-4*RCONST[1]);
  RCONST[27] = (ARR2(1.3E-12,380.0));
  RCONST[29] = (2.7E-5*SUN);
  RCONST[30] = (1.1182E-4*SUN);
  RCONST[33] = (ARR2(4.2E-12,180.0));
  RCONST[38] = (ARR2(6.9E-12,250.0));
  RCONST[40] = (4.556E-6*SUN);
  RCONST[41] = (1.118E-4*SUN);
  RCONST[43] = (ARR2(2.2E16,-13435.0));
  RCONST[44] = (ARR2(4.2E-12,180.0));
  RCONST[45] = (ARR2(4.2E-12,180.0));
  RCONST[46] = (ARR2(2.4E-12,1710.0));
  RCONST[47] = (ARR2(1.7E-11,-1232.0));
  RCONST[48] = (ARR2(4.2E-12,180.0));
  RCONST[49] = (ARR2(1.18E-11,-679.0));
  RCONST[50] = (ARR2(4.2E-12,180.0));
  RCONST[51] = (ARR2(2E-11,-500.0));
  RCONST[52] = (ARR2(4.2E-12,180.0));
  RCONST[55] = (ARR2(4.2E-12,180.0));
  RCONST[56] = (ARR2(1.5E-13,220.0));
  RCONST[64] = (ARR2(1.2E-11,-890.0));
  RCONST[65] = (ARR2(4.2E-12,180.0));
  RCONST[66] = (2.6E-4*RCONST[1]);
  RCONST[69] = (ARR2(1.66E-12,474.0));
  RCONST[70] = (ARR2(4.2E-12,180.0));
  RCONST[71] = (ARR2(4.1E-12,537.0));
  RCONST[72] = (ARR2(4.2E-12,180.0));
  RCONST[73] = (ARR2(1.2E-14,-2633.0));
  RCONST[74] = (ARR2(7.8E-14,-2105.0));
  RCONST[90] = (ARR2(4.2E-12,180.0));
  RCONST[96] = (ARR2(4.2E-12,180.0));
  RCONST[97] = (8.0E-3*RCONST[1]);
  RCONST[99] = (1.9E-2*RCONST[1]);
  RCONST[105] = (ARR2(2.2E16,-13435.0));
  RCONST[106] = (ARR2(4.2E-12,180.0));
  RCONST[107] = (ARR2(4.2E-12,180.0));
  RCONST[108] = (1E-2*RCONST[1]);
  RCONST[112] = (1.5*1.);
  RCONST[113] = (ARR2(2.5E-11,409.0));
  RCONST[114] = (ARR2(4.2E-12,180.0));
  RCONST[116] = (ARR2(3.0E-12,500.0));
  RCONST[117] = (ARR2(4.2E-12,180.0));
  RCONST[121] = (ARR2(2.2E+16,-13435.0));
  RCONST[122] = (ARR2(4.2E-12,180.0));
  RCONST[124] = (ARR2(3.86E-12,500.0));
  RCONST[125] = (ARR2(4.2E-12,180.0));
  RCONST[129] = (ARR2(2.2E+16,-13435.0));
  RCONST[130] = (ARR2(4.2E-12,180.0));
  RCONST[132] = (ARR2(7.0E-15,-1900.0));
  RCONST[133] = (ARR2(4.0E-15,-2000.0));
  RCONST[134] = (ARR2(4.4E-15,-2500.0));
  RCONST[135] = (ARR2(4.2E-12,180.0));
  RCONST[136] = (ARR2(4.2E-13,180.0));
  RCONST[138] = (ARR2(4.2E-12,180.0));
  RCONST[139] = (ARR2(4.2E-13,180.0));
  RCONST[141] = (ARR2(4.2E-12,180.0));
  RCONST[142] = (ARR2(4.2E-13,180.0));
  RCONST[144] = (5E-4*RCONST[1]);
  RCONST[145] = (0.15*RCONST[1]);
  RCONST[147] = (ARR2(3.00E-12,-450.0));
  RCONST[148] = (ARR2(4.2E-12,180.0));
  RCONST[149] = (ARR2(4.2E-13,180.0));
  RCONST[152] = (ARR2(4.2E-12,180.0));
  RCONST[156] = (ARR2(4.2E-12,180.0));
  RCONST[164] = (ARR2(1.2E-11,500.0));
  RCONST[171] = (ARR2(4.6E-11,230.0));
  RCONST[172] = (5.00E-4*RCONST[1]);
  RCONST[175] = (ARR2(8.5E-13,-2450.0));
  RCONST[176] = (ARR2(1.23E-12,-651.0));
  RCONST[177] = (ARR2(2.3E-12,170.0));
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

  RCONST[0] = (1.765E-2*SUN);
  RCONST[7] = (3.29*RCONST[1]);
  RCONST[9] = (1.5796E-7*SUN);
  RCONST[11] = (0.205*RCONST[1]);
  RCONST[13] = (7.8E-7*SUN);
  RCONST[23] = (1.366E-5*SUN);
  RCONST[26] = (1E-4*RCONST[1]);
  RCONST[29] = (2.7E-5*SUN);
  RCONST[30] = (1.1182E-4*SUN);
  RCONST[40] = (4.556E-6*SUN);
  RCONST[41] = (1.118E-4*SUN);
  RCONST[66] = (2.6E-4*RCONST[1]);
  RCONST[97] = (8.0E-3*RCONST[1]);
  RCONST[99] = (1.9E-2*RCONST[1]);
  RCONST[108] = (1E-2*RCONST[1]);
  RCONST[144] = (5E-4*RCONST[1]);
  RCONST[145] = (0.15*RCONST[1]);
  RCONST[172] = (5.00E-4*RCONST[1]);
}

/* End of Update_PHOTO function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


