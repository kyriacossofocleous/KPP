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
/* File                 : strato_Rates.c                            */
/* Time                 : Wed Mar  9 12:16:50 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato */
/* Equation file        : strato.kpp                                */
/* Output root filename : strato                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "strato_Parameters.h"
#include "strato_Global.h"
#include "strato_Sparse.h"



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

  RCONST[84] = (2.643E-10*SUN*SUN*SUN);
  RCONST[85] = (6.120E-04*SUN);
  RCONST[86] = (1.070E-03*SUN*SUN);
  RCONST[87] = (1.817E-04*SUN*SUN);
  RCONST[88] = (3.537E-05*SUN);
  RCONST[89] = (1.289E-02*SUN);
  RCONST[90] = (2.359E-01*SUN);
  RCONST[91] = (2.883E-02*SUN);
  RCONST[92] = (2.594E-04*SUN*SUN);
  RCONST[93] = (5.269E-05*SUN*SUN);
  RCONST[94] = (4.557E-05*SUN*SUN);
  RCONST[95] = (9.113E-05*SUN*SUN);
  RCONST[96] = (3.692E-03*SUN);
  RCONST[97] = (1.243E-01*SUN);
  RCONST[98] = (3.421E-03*SUN);
  RCONST[99] = (4.606E-04*SUN);
  RCONST[100] = (2.254E-04*SUN*SUN);
  RCONST[101] = (2.505E-05*SUN*SUN);
  RCONST[102] = (1.867E-02*SUN);
  RCONST[103] = (5.950E-02*SUN);
  RCONST[104] = (1.284E-03*SUN);
  RCONST[105] = (2.074E-03*SUN);
  RCONST[106] = (7.553E-05*SUN);
  RCONST[107] = (8.303E-05*SUN);
  RCONST[108] = (2.285E-05*SUN);
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

  RCONST[84] = (2.643E-10*SUN*SUN*SUN);
  RCONST[85] = (6.120E-04*SUN);
  RCONST[86] = (1.070E-03*SUN*SUN);
  RCONST[87] = (1.817E-04*SUN*SUN);
  RCONST[88] = (3.537E-05*SUN);
  RCONST[89] = (1.289E-02*SUN);
  RCONST[90] = (2.359E-01*SUN);
  RCONST[91] = (2.883E-02*SUN);
  RCONST[92] = (2.594E-04*SUN*SUN);
  RCONST[93] = (5.269E-05*SUN*SUN);
  RCONST[94] = (4.557E-05*SUN*SUN);
  RCONST[95] = (9.113E-05*SUN*SUN);
  RCONST[96] = (3.692E-03*SUN);
  RCONST[97] = (1.243E-01*SUN);
  RCONST[98] = (3.421E-03*SUN);
  RCONST[99] = (4.606E-04*SUN);
  RCONST[100] = (2.254E-04*SUN*SUN);
  RCONST[101] = (2.505E-05*SUN*SUN);
  RCONST[102] = (1.867E-02*SUN);
  RCONST[103] = (5.950E-02*SUN);
  RCONST[104] = (1.284E-03*SUN);
  RCONST[105] = (2.074E-03*SUN);
  RCONST[106] = (7.553E-05*SUN);
  RCONST[107] = (8.303E-05*SUN);
  RCONST[108] = (2.285E-05*SUN);
}

/* End of Update_PHOTO function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


