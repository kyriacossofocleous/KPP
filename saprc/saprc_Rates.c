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
/* File                 : saprc_Rates.c                             */
/* Time                 : Thu Jan 27 12:48:33 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc  */
/* Equation file        : saprc.kpp                                 */
/* Output root filename : saprc                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "saprc_Parameters.h"
#include "saprc_Global.h"
#include "saprc_Sparse.h"



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

  RCONST[0] = (6.69e-1*(SUN/60.0e0));
  RCONST[1] = (ARR(5.68e-34,0.0e0,-2.80e0));
  RCONST[2] = (ARR(8.00e-12,2060.0e0,0.0e0));
  RCONST[3] = (ARR(1.00e-31,0.0e0,-1.60e0));
  RCONST[4] = (ARR(6.50e-12,-120.0e0,0.0e0));
  RCONST[5] = (FALL(9.00e-32,0.0e0,-2.00e0,2.20e-11,0.0e0,0.0e0,
             0.80e0));
  RCONST[6] = (ARR(1.80e-12,1370.0e0,0.0e0));
  RCONST[7] = (ARR(1.40e-13,2470.0e0,0.0e0));
  RCONST[8] = (ARR(1.80e-11,-110.0e0,0.0e0));
  RCONST[9] = (ARR(3.30e-39,-530.0e0,0.0e0));
  RCONST[10] = (FALL(2.80e-30,0.0e0,-3.50e0,2.00e-12,0.0e0,0.20e0,
              0.45e0));
  RCONST[11] = (FALL(1.e-3,11000.0e0,-3.5e0,9.7e+14,11080.0e0,0.1e0,
              0.45e0));
  RCONST[12] = ((2.60e-22));
  RCONST[13] = (ARR(4.50e-14,1260.0e0,0.0e0));
  RCONST[14] = (1.59e0*(SUN/60.0e0));
  RCONST[15] = (1.50e+1*(SUN/60.0e0));
  RCONST[16] = (3.76e-2*(SUN/60.0e0));
  RCONST[17] = (4.19e-3*(SUN/60.0e0));
  RCONST[18] = ((2.20e-10));
  RCONST[19] = (ARR(2.09e-11,-95.0e0,0.0e0));
  RCONST[20] = (FALL(7.00e-31,0.0e0,-2.60e0,3.60e-11,0.0e0,-0.10e0,
              0.60e0));
  RCONST[21] = (1.27e-1*(SUN/60.0e0));
  RCONST[22] = (1.60e-2*(SUN/60.0e0));
  RCONST[23] = (ARR(2.70e-12,-260.0e0,0.0e0));
  RCONST[24] = (FALL(2.43e-30,0.0e0,-3.10e0,1.67e-11,0.0e0,-2.10e0,
              0.60e0));
  RCONST[25] = ((2.00e-11));
  RCONST[26] = (EP2(7.20e-15,-785.0e0,4.10e-16,-1440.0e0,1.90e-33,
              -725.0e0));
  RCONST[27] = (5.40e-5*(SUN/60.0e0));
  RCONST[28] = (EP3(1.30e-13,0.0e0,3.19e-33,0.0e0));
  RCONST[29] = (ARR(1.90e-12,1000.0e0,0.0e0));
  RCONST[30] = (ARR(3.40e-12,-270.0e0,0.0e0));
  RCONST[31] = (FALL(1.80e-31,0.0,-3.20,4.70e-12,0.0e0,0.0,0.6));
  RCONST[32] = (FALL(4.10e-05,10650.0,0.0,5.7e+15,11170.0,0.0,0.5));
  RCONST[33] = (4.69e-4*(SUN/60.0e0));
  RCONST[34] = (ARR(1.50e-12,-360.0e0,0.0e0));
  RCONST[35] = (ARR(1.40e-14,600.0e0,0.0e0));
  RCONST[36] = (EP3(2.20e-13,-600.0e0,1.85e-33,-980.0e0));
  RCONST[37] = (EP3(3.08e-34,-2800.0e0,2.59e-54,-3180.0e0));
  RCONST[38] = ((4.00e-12));
  RCONST[39] = (ARR(8.50e-13,2450.0e0,0.0e0));
  RCONST[40] = (5.64e-4*(SUN/60.0e0));
  RCONST[41] = (ARR(2.90e-12,160.0e0,0.0e0));
  RCONST[42] = (ARR(4.80e-11,-250.0e0,0.0e0));
  RCONST[43] = (FALL(4.00e-31,0.0e0,-3.30e0,2.00e-12,0.0e0,0.0e0,
              0.45e0));
  RCONST[44] = (ARR(7.70e-12,2100.0e0,0.0e0));
  RCONST[45] = (ARR(2.80e-12,-285.0e0,0.0e0));
  RCONST[46] = (ARR(3.80e-13,-780.0e0,0.0e0));
  RCONST[47] = ((1.30e-12));
  RCONST[48] = (ARR(2.45e-14,-710.0e0,0.0e0));
  RCONST[49] = (ARR(5.90e-13,509.0e0,0.0e0));
  RCONST[50] = (ARR(2.70e-12,-360.0e0,0.0e0));
  RCONST[51] = (ARR(1.90e-13,-1300.0e0,0.0e0));
  RCONST[52] = ((2.30e-12));
  RCONST[53] = ((2.00e-13));
  RCONST[54] = ((3.50e-14));
  RCONST[55] = (ARR(2.70e-12,-360.0e0,0.0e0));
  RCONST[56] = (ARR(1.90e-13,-1300.0e0,0.0e0));
  RCONST[57] = ((2.30e-12));
  RCONST[58] = ((2.00e-13));
  RCONST[59] = ((3.50e-14));
  RCONST[60] = ((0.0e0));
  RCONST[61] = (ARR(2.70e-12,-360.0e0,0.0e0));
  RCONST[62] = (ARR(1.90e-13,-1300.0e0,0.0e0));
  RCONST[63] = ((2.00e-13));
  RCONST[64] = ((2.30e-12));
  RCONST[65] = ((3.50e-14));
  RCONST[66] = ((3.50e-14));
  RCONST[67] = ((3.50e-14));
  RCONST[68] = (FALL(2.70e-28,0.0e0,-7.10e0,1.20e-11,0.0e0,-0.90e0,
              0.30e0));
  RCONST[69] = (FALL(4.90e-3,12100.0e0,0.0e0,4.0e+16,13600.0e0,0.e0,
              0.3e0));
  RCONST[70] = (ARR(7.80e-12,-300.0e0,0.0e0));
  RCONST[71] = (ARR(4.30e-13,-1040.0e0,0.0e0));
  RCONST[72] = ((4.00e-12));
  RCONST[73] = (ARR(1.80e-12,-500.0e0,0.0e0));
  RCONST[74] = ((7.50e-12));
  RCONST[75] = ((7.50e-12));
  RCONST[76] = ((7.50e-12));
  RCONST[77] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[78] = (ARR(1.20e-11,0.0e0,-0.90e0));
  RCONST[79] = (ARR(2.00e+15,12800.0e0,0.0e0));
  RCONST[80] = (ARR(1.25e-11,-240.0e0,0.0e0));
  RCONST[81] = (ARR(4.30e-13,-1040.0e0,0.0e0));
  RCONST[82] = ((4.00e-12));
  RCONST[83] = (ARR(1.80e-12,-500.0e0,0.0e0));
  RCONST[84] = ((7.50e-12));
  RCONST[85] = ((7.50e-12));
  RCONST[86] = ((7.50e-12));
  RCONST[87] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[88] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[89] = ((1.37e-11));
  RCONST[90] = (ARR(7.90e+16,14000.0e0,0.0e0));
  RCONST[91] = (ARR(1.25e-11,-240.0e0,0.0e0));
  RCONST[92] = (ARR(4.30e-13,-1040.0e0,0.0e0));
  RCONST[93] = ((4.00e-12));
  RCONST[94] = (ARR(1.80e-12,-500.0e0,0.0e0));
  RCONST[95] = ((7.50e-12));
  RCONST[96] = ((7.50e-12));
  RCONST[97] = ((7.50e-12));
  RCONST[98] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[99] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[100] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[101] = (ARR(1.20e-11,0.0e0,-0.90e0));
  RCONST[102] = (ARR(1.60e+16,13486.0e0,0.0e0));
  RCONST[103] = (ARR(1.25e-11,-240.0e0,0.0e0));
  RCONST[104] = (ARR(4.30e-13,-1040.0e0,0.0e0));
  RCONST[105] = ((4.00e-12));
  RCONST[106] = (ARR(1.80e-12,-500.0e0,0.0e0));
  RCONST[107] = ((7.50e-12));
  RCONST[108] = ((7.50e-12));
  RCONST[109] = ((7.50e-12));
  RCONST[110] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[111] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[112] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[113] = (ARR(2.90e-12,-500.0e0,0.0e0));
  RCONST[114] = ((2.40e-11));
  RCONST[115] = (ARR(7.50e+14,8152.0e0,0.0e0));
  RCONST[116] = (ARR(2.30e-11,-150.0e0,0.0e0));
  RCONST[117] = (ARR(1.90e-13,-1300.0e0,0.0e0));
  RCONST[118] = ((1.00e-03));
  RCONST[119] = (ARR(7.50e+14,8152.0e0,0.0e0));
  RCONST[120] = (ARR(2.30e-11,-150.0e0,0.0e0));
  RCONST[121] = (ARR(1.90e-13,-1300.0e0,0.0e0));
  RCONST[122] = (2.32e-3*(SUN/60.0e0));
  RCONST[123] = (3.15e-3*(SUN/60.0e0));
  RCONST[124] = (ARR(8.60e-12,-20.0e0,0.0e0));
  RCONST[125] = (ARR(9.70e-15,-625.0e0,0.0e0));
  RCONST[126] = (ARR(2.40e+12,7000.0e0,0.0e0));
  RCONST[127] = (ARR(2.80e-12,-285.0e0,0.0e0));
  RCONST[128] = (ARR(2.00e-12,2431.0e0,0.0e0));
  RCONST[129] = (ARR(5.60e-12,-310.0e0,0.0e0));
  RCONST[130] = (4.16e-4*(SUN/60.0e0));
  RCONST[131] = (ARR(1.40e-12,1860.0e0,0.0e0));
  RCONST[132] = ((2.00e-11));
  RCONST[133] = (1.40e-3*(SUN/60.0e0));
  RCONST[134] = (ARR(1.40e-12,1771.0e0,0.0e0));
  RCONST[135] = (ARR(1.10e-12,520.0e0,0.0e0));
  RCONST[136] = (4.16e-5*(SUN/60.0e0));
  RCONST[137] = (ARR(1.30e-12,25.0e0,2.0e0));
  RCONST[138] = (9.49e-4*(1.50e-1*SUN/60.0e0));
  RCONST[139] = (ARR(3.10e-12,360.0e0,2.0e0));
  RCONST[140] = (ARR(2.90e-12,-190.0e0,0.0e0));
  RCONST[141] = (3.94e-4*(SUN/60.0e0));
  RCONST[142] = ((1.10e-11));
  RCONST[143] = (3.94e-4*(SUN/60.0e0));
  RCONST[144] = (8.93e-3*(SUN/60.0e0));
  RCONST[145] = (1.81e-1*(6.00e-3*SUN/60.0e0));
  RCONST[146] = ((1.10e-11));
  RCONST[147] = (ARR(2.80e-12,2376.0e0,0.0e0));
  RCONST[148] = (1.10e-2*(SUN/60.0e0));
  RCONST[150] = (ARR(1.40e-12,1895.0e0,0.0e0));
  RCONST[151] = (1.90e-2*(SUN/60.0e0));
  RCONST[152] = ((2.63e-11));
  RCONST[153] = ((3.78e-12));
  RCONST[154] = ((4.20e-11));
  RCONST[155] = ((1.37e-11));
  RCONST[156] = ((3.78e-12));
  RCONST[157] = ((1.29e-11));
  RCONST[158] = (6.22e-2*(5.00e-2*SUN/60.0e0));
  RCONST[159] = (ARR(1.40e-12,1872.0e0,0.0e0));
  RCONST[160] = (ARR(1.86e-11,-176.0e0,0.0e0));
  RCONST[161] = (ARR(1.36e-15,2114.0e0,0.0e0));
  RCONST[162] = (ARR(1.50e-12,1726.0e0,0.0e0));
  RCONST[163] = ((6.34e-12));
  RCONST[164] = (3.32e-2*(4.10e-3*SUN/60.0e0));
  RCONST[165] = (ARR(4.14e-12,-453.0e0,0.0e0));
  RCONST[166] = (ARR(7.51e-16,1520.0e0,0.0e0));
  RCONST[167] = ((4.32e-12));
  RCONST[168] = (3.32e-2*(2.10e-3*SUN/60.0e0));
  RCONST[169] = ((6.19e-11));
  RCONST[170] = ((4.18e-18));
  RCONST[171] = ((1.00e-13));
  RCONST[172] = (3.32e-2*(4.10e-3*SUN/60.0e0));
  RCONST[173] = ((1.50e-11));
  RCONST[174] = (9.49e-4*(2.00e-2*SUN/60.0e0));
  RCONST[175] = ((7.80e-12));
  RCONST[176] = (2.35e-4*(SUN/60.0e0));
  RCONST[177] = ((5.00e-11));
  RCONST[178] = ((2.00e-18));
  RCONST[179] = ((5.00e-11));
  RCONST[180] = (2.06e-1*(3.65e-1*SUN/60.0e0));
  RCONST[181] = ((5.00e-11));
  RCONST[182] = (3.32e-2*(7.28e0*SUN/60.0e0));
  RCONST[183] = (ARR(2.15e-12,1735.0e0,0.0e0));
  RCONST[184] = (ARR(1.96e-12,-438.0e0,0.0e0));
  RCONST[185] = (ARR(9.14e-15,2580.0e0,0.0e0));
  RCONST[186] = (ARR(4.39e-13,2282.0e0,2.0e0));
  RCONST[187] = (ARR(1.04e-11,792.0e0,0.0e0));
  RCONST[188] = (ARR(2.50e-11,-408.0e0,0.0e0));
  RCONST[189] = (ARR(7.86e-15,1912.0e0,0.0e0));
  RCONST[190] = (ARR(3.03e-12,448.0e0,0.0e0));
  RCONST[191] = ((3.60e-11));
  RCONST[192] = (ARR(1.83e-11,-449.0e0,0.0e0));
  RCONST[193] = (ARR(1.08e-15,821.0e0,0.0e0));
  RCONST[194] = (ARR(3.66e-12,-175.e00,0.0e0));
  RCONST[195] = ((3.27e-11));
  RCONST[196] = (ARR(1.37e-12,498.0e0,2.0e0));
  RCONST[197] = (ARR(9.87e-12,671.0e0,0.0e0));
  RCONST[198] = (ARR(1.019e-11,434.0e0,0.0e0));
  RCONST[199] = (ARR(5.946e-12,91.0e0,0.0e0));
  RCONST[200] = (ARR(1.112e-11,52.0e0,0.0e0));
  RCONST[201] = (ARR(1.81e-12,-355.0e0,0.0e0));
  RCONST[202] = ((2.640e-11));
  RCONST[203] = (ARR(7.095e-12,-451.0e0,0.0e0));
  RCONST[204] = (ARR(2.617e-15,1640.0e0,0.0e0));
  RCONST[205] = (ARR(4.453e-14,376.0e0,0.0e0));
  RCONST[206] = (ARR(1.074e-11,234.0e0,0.0e0));
  RCONST[207] = (ARR(1.743e-11,-384.0e0,0.0e0));
  RCONST[208] = (ARR(5.022e-16,461.0e0,0.0e0));
  RCONST[209] = ((7.265e-13));
  RCONST[210] = ((2.085e-11));
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

  RCONST[0] = (6.69e-1*(SUN/60.0e0));
  RCONST[14] = (1.59e0*(SUN/60.0e0));
  RCONST[15] = (1.50e+1*(SUN/60.0e0));
  RCONST[16] = (3.76e-2*(SUN/60.0e0));
  RCONST[17] = (4.19e-3*(SUN/60.0e0));
  RCONST[21] = (1.27e-1*(SUN/60.0e0));
  RCONST[22] = (1.60e-2*(SUN/60.0e0));
  RCONST[27] = (5.40e-5*(SUN/60.0e0));
  RCONST[33] = (4.69e-4*(SUN/60.0e0));
  RCONST[40] = (5.64e-4*(SUN/60.0e0));
  RCONST[122] = (2.32e-3*(SUN/60.0e0));
  RCONST[123] = (3.15e-3*(SUN/60.0e0));
  RCONST[130] = (4.16e-4*(SUN/60.0e0));
  RCONST[133] = (1.40e-3*(SUN/60.0e0));
  RCONST[136] = (4.16e-5*(SUN/60.0e0));
  RCONST[138] = (9.49e-4*(1.50e-1*SUN/60.0e0));
  RCONST[141] = (3.94e-4*(SUN/60.0e0));
  RCONST[143] = (3.94e-4*(SUN/60.0e0));
  RCONST[144] = (8.93e-3*(SUN/60.0e0));
  RCONST[145] = (1.81e-1*(6.00e-3*SUN/60.0e0));
  RCONST[148] = (1.10e-2*(SUN/60.0e0));
  RCONST[151] = (1.90e-2*(SUN/60.0e0));
  RCONST[158] = (6.22e-2*(5.00e-2*SUN/60.0e0));
  RCONST[164] = (3.32e-2*(4.10e-3*SUN/60.0e0));
  RCONST[168] = (3.32e-2*(2.10e-3*SUN/60.0e0));
  RCONST[172] = (3.32e-2*(4.10e-3*SUN/60.0e0));
  RCONST[174] = (9.49e-4*(2.00e-2*SUN/60.0e0));
  RCONST[176] = (2.35e-4*(SUN/60.0e0));
  RCONST[180] = (2.06e-1*(3.65e-1*SUN/60.0e0));
  RCONST[182] = (3.32e-2*(7.28e0*SUN/60.0e0));
}

/* End of Update_PHOTO function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


