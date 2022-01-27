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
/* File                 : chapman_Rates.c                           */
/* Time                 : Thu Jan 27 12:48:22 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman */
/* Equation file        : chapman.kpp                               */
/* Output root filename : chapman                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "chapman_Parameters.h"
#include "chapman_Global.h"
#include "chapman_Sparse.h"



/* Begin Rate Law Functions from KPP_HOME/util/UserRateLaws         */

/*  User-defined Rate Law functions
    Note: the default argument type for rate laws, as read from the equations file, is single precision
         but all the internal calculations are performed in double precision
*/
/* Arrhenius */
double  ARR( float A0, float B0, float C0 )
      {
      double ARR_RES;
                 
      ARR_RES = (double)A0 * exp( -(double)B0/TEMP ) 
                * pow( (TEMP/300.0), (double)C0 );   
           
      return (double)ARR_RES;
      }           


/* Simplified Arrhenius, with two arguments */
/* Note that the argument B0 has a changed sign when compared to ARR */
double  ARR2(  float A0, float B0 )
      {
      double ARR_RES;           

      ARR_RES =  (double)A0 * exp( (double)B0/TEMP );   
           
      return (double)ARR_RES;
      }           


double  EP2( float A0, float C0, float A2, float C2, float A3, float C3)
      {                       
      double K0, K2, K3, EP2_RES;
      
      K0 = (double)A0 * exp( -(double)C0/TEMP );
      K2 = (double)A2 * exp( -(double)C2/TEMP );
      K3 = (double)A3 * exp( -(double)C3/TEMP );
      K3 = K3*CFACTOR*1.0e+6;
      EP2_RES = K0 + K3/( 1.0+K3/K2 );
        
      return (double)EP2_RES;
      }  


double  EP3( float A1, float C1, float A2, float C2) 
      {               
      double K1, K2, EP3_RES;
      
      K1 = (double)A1 * exp(-(double)C1/TEMP);
      K2 = (double)A2 * exp(-(double)C2/TEMP);
      EP3_RES = K1 + K2*(1.0e+6*CFACTOR);
      
      return (double)EP3_RES;
      }    


double  FALL (  float A0, float B0, float C0, float A1, float B1, float C1, float CF)
      {                      
      double K0, K1, FALL_RES;
      
      K0 = (double)A0 * exp(-(double)B0/TEMP)* pow( (TEMP/300.0), (double)C0 );
      K1 = (double)A1 * exp(-(double)B1/TEMP)* pow( (TEMP/300.0), (double)C1 );
      K0 = K0*CFACTOR*1.0e+6;
      K1 = K0/K1;
      FALL_RES = (K0/(1.0+K1))*
           pow( (double)CF, ( 1.0/( 1.0+pow( (log10(K1)),2 ) ) ) );
        
      return (double)FALL_RES;
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

  RCONST[0] = ((2.643E-10)*SUN*SUN*SUN);
  RCONST[1] = ((8.018E-17));
  RCONST[2] = ((6.120E-04)*SUN);
  RCONST[3] = ((1.576E-15));
  RCONST[4] = ((1.070E-03)*SUN*SUN);
  RCONST[5] = ((7.110E-11));
  RCONST[6] = ((1.200E-10));
  RCONST[7] = ((6.062E-15));
  RCONST[8] = ((1.069E-11));
  RCONST[9] = ((1.289E-02)*SUN);
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

  RCONST[0] = ((2.643E-10)*SUN*SUN*SUN);
  RCONST[2] = ((6.120E-04)*SUN);
  RCONST[4] = ((1.070E-03)*SUN*SUN);
  RCONST[9] = ((1.289E-02)*SUN);
}

/* End of Update_PHOTO function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


