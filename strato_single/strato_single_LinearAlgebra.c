/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Linear Algebra Data and Routines File                            */
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
/* File                 : strato_single_LinearAlgebra.c             */
/* Time                 : Thu Jan 27 11:06:30 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_single */
/* Equation file        : strato_single.kpp                         */
/* Output root filename : strato_single                             */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "strato_single_Parameters.h"
#include "strato_single_Global.h"
#include "strato_single_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* SPARSE_UTIL - SPARSE utility functions                           */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


int KppDecomp( float *JVS )
{
float W[34];
float a;
int k, kk, j, jj;

  for( k = 0; k < 34; k++ ) {
    if( JVS[ LU_DIAG[k] ] == 0.0 ) return k+1;
    for( kk = LU_CROW[k]; kk < LU_CROW[k+1]; kk++ )
      W[ LU_ICOL[kk] ] = JVS[kk];
    for( kk = LU_CROW[k]; kk < LU_DIAG[k]; kk++ ) {
      j = LU_ICOL[kk];
      a = -W[j] / JVS[ LU_DIAG[j] ];
      W[j] = -a;
      for( jj = LU_DIAG[j]+1; jj < LU_CROW[j+1]; jj++ )
        W[ LU_ICOL[jj] ] += a*JVS[jj];
    }
    for( kk = LU_CROW[k]; kk < LU_CROW[k+1]; kk++ )
      JVS[kk] = W[ LU_ICOL[kk] ];
  }
  return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Sparse LU factorization, complex
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int KppDecompCmplxR( float JVSR[], float JVSI[] )
{
   float WR[NVAR], WI[NVAR];
   float ar, ai, den;
   int k, kk, j, jj;

   for( k = 0; k < NVAR; k++ ) {
	if( JVSR[ LU_DIAG[k] ] == 0.0 ) return k+1;
	if( JVSI[ LU_DIAG[k] ] == 0.0 ) return k+1;
	for( kk = LU_CROW[k]; kk < LU_CROW[k+1]; kk++ ) {
		WR[ LU_ICOL[kk] ] = JVSR[kk];
		WI[ LU_ICOL[kk] ] = JVSI[kk];
	}
	for( kk = LU_CROW[k]; kk < LU_DIAG[k]; kk++ ) {
	   j = LU_ICOL[kk];
	   den = JVSR[LU_DIAG[j]]*JVSR[LU_DIAG[j]] + JVSI[LU_DIAG[j]]*JVSI[LU_DIAG[j]];
	   ar = -(WR[j]*JVSR[LU_DIAG[j]] + WI[j]*JVSI[LU_DIAG[j]])/den;
	   ai = -(WI[j]*JVSR[LU_DIAG[j]] - WR[j]*JVSI[LU_DIAG[j]])/den;
	   WR[j] = -ar;
	   WI[j] = -ai;
	   for( jj = LU_DIAG[j]+1; jj < LU_CROW[j+1]; jj++ ) {
		   WR[ LU_ICOL[jj] ] = WR[ LU_ICOL[jj] ] + ar*JVSR[jj] - ai*JVSI[jj];
		   WI[ LU_ICOL[jj] ] = WI[ LU_ICOL[jj] ] + ar*JVSI[jj] + ai*JVSR[jj];
	   }
	}
	for( kk = LU_CROW[k]; kk < LU_CROW[k+1]; kk++ ) {
	   JVSR[kk] = WR[ LU_ICOL[kk] ];
	   JVSI[kk] = WI[ LU_ICOL[kk] ];
	}
   }
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Complex sparse solve subroutine using indirect addressing
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void KppSolveCmplxR(float JVSR[], float JVSI[], float XR[], float XI[])
{
   int i, j;
   float sumr, sumi, den;

   for ( i = 0; i < NVAR; i++ ) {
	for ( j = LU_CROW[i]; j < LU_DIAG[i]; j++ ) {
	   XR[i] = XR[i] - (JVSR[j]*XR[LU_ICOL[j]] - JVSI[j]*XI[LU_ICOL[j]]);
	   XI[i] = XI[i] - (JVSR[j]*XI[LU_ICOL[j]] + JVSI[j]*XR[LU_ICOL[j]]);
	}
   }
   
   for ( i = NVAR-1; i >= 0; i-- ) {
	sumr = XR[i];
	sumi = XI[i];
	for ( j = LU_DIAG[i]+1; j < LU_CROW[i+1]; j++) {
	   sumr = sumr - (JVSR[j]*XR[LU_ICOL[j]] - JVSI[j]*XI[LU_ICOL[j]]);
	   sumi = sumi - (JVSR[j]*XI[LU_ICOL[j]] + JVSI[j]*XR[LU_ICOL[j]]);
	}
	den = JVSR[LU_DIAG[i]]*JVSR[LU_DIAG[i]] + JVSI[LU_DIAG[i]]*JVSI[LU_DIAG[i]];
  	XR[i] = (sumr*JVSR[LU_DIAG[i]] + sumi*JVSI[LU_DIAG[i]])/den; 
  	XI[i] = (sumi*JVSR[LU_DIAG[i]] - sumr*JVSI[LU_DIAG[i]])/den;
   }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	END FUNCTION KppSolveCmplxR
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* End of SPARSE_UTIL function                                      */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* KppSolve - sparse back substitution                              */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      X         - Vector for variables                            */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void KppSolve( 
  float JVS[],                           /* sparse Jacobian of variables */
  float X[]                              /* Vector for variables */
)
{
  X[3] = X[3]-JVS[10]*X[2];
  X[18] = X[18]-JVS[71]*X[11];
  X[19] = X[19]-JVS[77]*X[10];
  X[20] = X[20]-JVS[85]*X[0]-JVS[86]*X[10]-JVS[87]*X[13];
  X[22] = X[22]-JVS[100]*X[7]-JVS[101]*X[11]-JVS[102]*X[14]-JVS[103]
         *X[18]-JVS[104]*X[21];
  X[23] = X[23]-JVS[115]*X[9]-JVS[116]*X[10]-JVS[117]*X[13]-JVS[118]
         *X[20];
  X[24] = X[24]-JVS[127]*X[5]-JVS[128]*X[6]-JVS[129]*X[7]-JVS[130]
         *X[12]-JVS[131]*X[23];
  X[25] = X[25]-JVS[142]*X[6]-JVS[143]*X[10]-JVS[144]*X[12]-JVS[145]
         *X[13]-JVS[146]*X[14]-JVS[147]*X[15]-JVS[148]*X[16]-JVS[149]
         *X[17]-JVS[150]*X[18]-JVS[151]*X[19]-JVS[152]*X[20]-JVS[153]
         *X[21]-JVS[154]*X[22]-JVS[155]*X[23]-JVS[156]*X[24];
  X[26] = X[26]-JVS[166]*X[1]-JVS[167]*X[2]-JVS[168]*X[3]-JVS[169]*X[5]
         -JVS[170]*X[15]-JVS[171]*X[16]-JVS[172]*X[17]-JVS[173]*X[21]
         -JVS[174]*X[23]-JVS[175]*X[24]-JVS[176]*X[25];
  X[27] = X[27]-JVS[185]*X[2]-JVS[186]*X[4]-JVS[187]*X[17]-JVS[188]
         *X[21]-JVS[189]*X[25]-JVS[190]*X[26];
  X[28] = X[28]-JVS[198]*X[10]-JVS[199]*X[19]-JVS[200]*X[23]-JVS[201]
         *X[24]-JVS[202]*X[25]-JVS[203]*X[26]-JVS[204]*X[27];
  X[29] = X[29]-JVS[211]*X[20]-JVS[212]*X[22]-JVS[213]*X[25]-JVS[214]
         *X[26]-JVS[215]*X[27]-JVS[216]*X[28];
  X[30] = X[30]-JVS[222]*X[24]-JVS[223]*X[25]-JVS[224]*X[26]-JVS[225]
         *X[27]-JVS[226]*X[28]-JVS[227]*X[29];
  X[31] = X[31]-JVS[232]*X[4]-JVS[233]*X[10]-JVS[234]*X[21]-JVS[235]
         *X[22]-JVS[236]*X[23]-JVS[237]*X[24]-JVS[238]*X[25]-JVS[239]
         *X[26]-JVS[240]*X[27]-JVS[241]*X[28]-JVS[242]*X[29]-JVS[243]
         *X[30];
  X[32] = X[32]-JVS[247]*X[8]-JVS[248]*X[9]-JVS[249]*X[13]-JVS[250]
         *X[14]-JVS[251]*X[16]-JVS[252]*X[19]-JVS[253]*X[20]-JVS[254]
         *X[23]-JVS[255]*X[24]-JVS[256]*X[25]-JVS[257]*X[26]-JVS[258]
         *X[27]-JVS[259]*X[28]-JVS[260]*X[29]-JVS[261]*X[30]-JVS[262]
         *X[31];
  X[33] = X[33]-JVS[265]*X[11]-JVS[266]*X[14]-JVS[267]*X[18]-JVS[268]
         *X[20]-JVS[269]*X[21]-JVS[270]*X[22]-JVS[271]*X[25]-JVS[272]
         *X[26]-JVS[273]*X[27]-JVS[274]*X[28]-JVS[275]*X[29]-JVS[276]
         *X[30]-JVS[277]*X[31]-JVS[278]*X[32];
  X[33] = X[33]/JVS[279];
  X[32] = (X[32]-JVS[264]*X[33])/(JVS[263]);
  X[31] = (X[31]-JVS[245]*X[32]-JVS[246]*X[33])/(JVS[244]);
  X[30] = (X[30]-JVS[229]*X[31]-JVS[230]*X[32]-JVS[231]*X[33])
         /(JVS[228]);
  X[29] = (X[29]-JVS[218]*X[30]-JVS[219]*X[31]-JVS[220]*X[32]-JVS[221]
         *X[33])/(JVS[217]);
  X[28] = (X[28]-JVS[206]*X[29]-JVS[207]*X[30]-JVS[208]*X[31]-JVS[209]
         *X[32]-JVS[210]*X[33])/(JVS[205]);
  X[27] = (X[27]-JVS[192]*X[28]-JVS[193]*X[29]-JVS[194]*X[30]-JVS[195]
         *X[31]-JVS[196]*X[32]-JVS[197]*X[33])/(JVS[191]);
  X[26] = (X[26]-JVS[178]*X[27]-JVS[179]*X[28]-JVS[180]*X[29]-JVS[181]
         *X[30]-JVS[182]*X[31]-JVS[183]*X[32]-JVS[184]*X[33])
         /(JVS[177]);
  X[25] = (X[25]-JVS[158]*X[26]-JVS[159]*X[27]-JVS[160]*X[28]-JVS[161]
         *X[29]-JVS[162]*X[30]-JVS[163]*X[31]-JVS[164]*X[32]-JVS[165]
         *X[33])/(JVS[157]);
  X[24] = (X[24]-JVS[133]*X[25]-JVS[134]*X[26]-JVS[135]*X[27]-JVS[136]
         *X[28]-JVS[137]*X[29]-JVS[138]*X[30]-JVS[139]*X[31]-JVS[140]
         *X[32]-JVS[141]*X[33])/(JVS[132]);
  X[23] = (X[23]-JVS[120]*X[24]-JVS[121]*X[25]-JVS[122]*X[26]-JVS[123]
         *X[28]-JVS[124]*X[29]-JVS[125]*X[31]-JVS[126]*X[32])
         /(JVS[119]);
  X[22] = (X[22]-JVS[106]*X[25]-JVS[107]*X[26]-JVS[108]*X[27]-JVS[109]
         *X[28]-JVS[110]*X[29]-JVS[111]*X[30]-JVS[112]*X[31]-JVS[113]
         *X[32]-JVS[114]*X[33])/(JVS[105]);
  X[21] = (X[21]-JVS[95]*X[25]-JVS[96]*X[26]-JVS[97]*X[27]-JVS[98]
         *X[31]-JVS[99]*X[33])/(JVS[94]);
  X[20] = (X[20]-JVS[89]*X[25]-JVS[90]*X[26]-JVS[91]*X[28]-JVS[92]
         *X[29]-JVS[93]*X[32])/(JVS[88]);
  X[19] = (X[19]-JVS[79]*X[23]-JVS[80]*X[25]-JVS[81]*X[26]-JVS[82]
         *X[28]-JVS[83]*X[31]-JVS[84]*X[32])/(JVS[78]);
  X[18] = (X[18]-JVS[73]*X[21]-JVS[74]*X[22]-JVS[75]*X[25]-JVS[76]
         *X[33])/(JVS[72]);
  X[17] = (X[17]-JVS[67]*X[21]-JVS[68]*X[25]-JVS[69]*X[27]-JVS[70]
         *X[32])/(JVS[66]);
  X[16] = (X[16]-JVS[63]*X[25]-JVS[64]*X[26]-JVS[65]*X[32])/(JVS[62]);
  X[15] = (X[15]-JVS[56]*X[16]-JVS[57]*X[23]-JVS[58]*X[25]-JVS[59]
         *X[26]-JVS[60]*X[27]-JVS[61]*X[32])/(JVS[55]);
  X[14] = (X[14]-JVS[52]*X[25]-JVS[53]*X[32]-JVS[54]*X[33])/(JVS[51]);
  X[13] = (X[13]-JVS[48]*X[20]-JVS[49]*X[25]-JVS[50]*X[32])/(JVS[47]);
  X[12] = (X[12]-JVS[43]*X[23]-JVS[44]*X[24]-JVS[45]*X[25]-JVS[46]
         *X[32])/(JVS[42]);
  X[11] = (X[11]-JVS[40]*X[22]-JVS[41]*X[33])/(JVS[39]);
  X[10] = (X[10]-JVS[38]*X[28])/(JVS[37]);
  X[9] = (X[9]-JVS[34]*X[13]-JVS[35]*X[20]-JVS[36]*X[29])/(JVS[33]);
  X[8] = (X[8]-JVS[28]*X[23]-JVS[29]*X[24]-JVS[30]*X[25]-JVS[31]*X[26]
        -JVS[32]*X[31])/(JVS[27]);
  X[7] = (X[7]-JVS[25]*X[30]-JVS[26]*X[33])/(JVS[24]);
  X[6] = (X[6]-JVS[22]*X[30]-JVS[23]*X[32])/(JVS[21]);
  X[5] = (X[5]-JVS[19]*X[27]-JVS[20]*X[30])/(JVS[18]);
  X[4] = (X[4]-JVS[16]*X[27]-JVS[17]*X[30])/(JVS[15]);
  X[3] = (X[3]-JVS[12]*X[26]-JVS[13]*X[27]-JVS[14]*X[30])/(JVS[11]);
  X[2] = (X[2]-JVS[9]*X[27])/(JVS[8]);
  X[1] = (X[1]-JVS[5]*X[21]-JVS[6]*X[26]-JVS[7]*X[27])/(JVS[4]);
  X[0] = (X[0]-JVS[1]*X[10]-JVS[2]*X[25]-JVS[3]*X[26])/(JVS[0]);
}

/* End of KppSolve function                                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* KppSolveTR - sparse, transposed back substitution                */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      X         - Vector for variables                            */
/*      XX        - Vector for output variables                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void KppSolveTR( 
  float JVS[],                           /* sparse Jacobian of variables */
  float X[],                             /* Vector for variables */
  float XX[]                             /* Vector for output variables */
)
{
  XX[0] = X[0]/JVS[0];
  XX[1] = X[1]/JVS[4];
  XX[2] = X[2]/JVS[8];
  XX[3] = X[3]/JVS[11];
  XX[4] = X[4]/JVS[15];
  XX[5] = X[5]/JVS[18];
  XX[6] = X[6]/JVS[21];
  XX[7] = X[7]/JVS[24];
  XX[8] = X[8]/JVS[27];
  XX[9] = X[9]/JVS[33];
  XX[10] = (X[10]-JVS[1]*XX[0])/(JVS[37]);
  XX[11] = X[11]/JVS[39];
  XX[12] = X[12]/JVS[42];
  XX[13] = (X[13]-JVS[34]*XX[9])/(JVS[47]);
  XX[14] = X[14]/JVS[51];
  XX[15] = X[15]/JVS[55];
  XX[16] = (X[16]-JVS[56]*XX[15])/(JVS[62]);
  XX[17] = X[17]/JVS[66];
  XX[18] = X[18]/JVS[72];
  XX[19] = X[19]/JVS[78];
  XX[20] = (X[20]-JVS[35]*XX[9]-JVS[48]*XX[13])/(JVS[88]);
  XX[21] = (X[21]-JVS[5]*XX[1]-JVS[67]*XX[17]-JVS[73]*XX[18])/(JVS[94]);
  XX[22] = (X[22]-JVS[40]*XX[11]-JVS[74]*XX[18])/(JVS[105]);
  XX[23] = (X[23]-JVS[28]*XX[8]-JVS[43]*XX[12]-JVS[57]*XX[15]-JVS[79]
          *XX[19])/(JVS[119]);
  XX[24] = (X[24]-JVS[29]*XX[8]-JVS[44]*XX[12]-JVS[120]*XX[23])
          /(JVS[132]);
  XX[25] = (X[25]-JVS[2]*XX[0]-JVS[30]*XX[8]-JVS[45]*XX[12]-JVS[49]
          *XX[13]-JVS[52]*XX[14]-JVS[58]*XX[15]-JVS[63]*XX[16]-JVS[68]
          *XX[17]-JVS[75]*XX[18]-JVS[80]*XX[19]-JVS[89]*XX[20]-JVS[95]
          *XX[21]-JVS[106]*XX[22]-JVS[121]*XX[23]-JVS[133]*XX[24])
          /(JVS[157]);
  XX[26] = (X[26]-JVS[3]*XX[0]-JVS[6]*XX[1]-JVS[12]*XX[3]-JVS[31]*XX[8]
          -JVS[59]*XX[15]-JVS[64]*XX[16]-JVS[81]*XX[19]-JVS[90]*XX[20]
          -JVS[96]*XX[21]-JVS[107]*XX[22]-JVS[122]*XX[23]-JVS[134]
          *XX[24]-JVS[158]*XX[25])/(JVS[177]);
  XX[27] = (X[27]-JVS[7]*XX[1]-JVS[9]*XX[2]-JVS[13]*XX[3]-JVS[16]*XX[4]
          -JVS[19]*XX[5]-JVS[60]*XX[15]-JVS[69]*XX[17]-JVS[97]*XX[21]
          -JVS[108]*XX[22]-JVS[135]*XX[24]-JVS[159]*XX[25]-JVS[178]
          *XX[26])/(JVS[191]);
  XX[28] = (X[28]-JVS[38]*XX[10]-JVS[82]*XX[19]-JVS[91]*XX[20]-JVS[109]
          *XX[22]-JVS[123]*XX[23]-JVS[136]*XX[24]-JVS[160]*XX[25]
          -JVS[179]*XX[26]-JVS[192]*XX[27])/(JVS[205]);
  XX[29] = (X[29]-JVS[36]*XX[9]-JVS[92]*XX[20]-JVS[110]*XX[22]-JVS[124]
          *XX[23]-JVS[137]*XX[24]-JVS[161]*XX[25]-JVS[180]*XX[26]
          -JVS[193]*XX[27]-JVS[206]*XX[28])/(JVS[217]);
  XX[30] = (X[30]-JVS[14]*XX[3]-JVS[17]*XX[4]-JVS[20]*XX[5]-JVS[22]
          *XX[6]-JVS[25]*XX[7]-JVS[111]*XX[22]-JVS[138]*XX[24]-JVS[162]
          *XX[25]-JVS[181]*XX[26]-JVS[194]*XX[27]-JVS[207]*XX[28]
          -JVS[218]*XX[29])/(JVS[228]);
  XX[31] = (X[31]-JVS[32]*XX[8]-JVS[83]*XX[19]-JVS[98]*XX[21]-JVS[112]
          *XX[22]-JVS[125]*XX[23]-JVS[139]*XX[24]-JVS[163]*XX[25]
          -JVS[182]*XX[26]-JVS[195]*XX[27]-JVS[208]*XX[28]-JVS[219]
          *XX[29]-JVS[229]*XX[30])/(JVS[244]);
  XX[32] = (X[32]-JVS[23]*XX[6]-JVS[46]*XX[12]-JVS[50]*XX[13]-JVS[53]
          *XX[14]-JVS[61]*XX[15]-JVS[65]*XX[16]-JVS[70]*XX[17]-JVS[84]
          *XX[19]-JVS[93]*XX[20]-JVS[113]*XX[22]-JVS[126]*XX[23]
          -JVS[140]*XX[24]-JVS[164]*XX[25]-JVS[183]*XX[26]-JVS[196]
          *XX[27]-JVS[209]*XX[28]-JVS[220]*XX[29]-JVS[230]*XX[30]
          -JVS[245]*XX[31])/(JVS[263]);
  XX[33] = (X[33]-JVS[26]*XX[7]-JVS[41]*XX[11]-JVS[54]*XX[14]-JVS[76]
          *XX[18]-JVS[99]*XX[21]-JVS[114]*XX[22]-JVS[141]*XX[24]
          -JVS[165]*XX[25]-JVS[184]*XX[26]-JVS[197]*XX[27]-JVS[210]
          *XX[28]-JVS[221]*XX[29]-JVS[231]*XX[30]-JVS[246]*XX[31]
          -JVS[264]*XX[32])/(JVS[279]);
  XX[33] = XX[33];
  XX[32] = XX[32]-JVS[278]*XX[33];
  XX[31] = XX[31]-JVS[262]*XX[32]-JVS[277]*XX[33];
  XX[30] = XX[30]-JVS[243]*XX[31]-JVS[261]*XX[32]-JVS[276]*XX[33];
  XX[29] = XX[29]-JVS[227]*XX[30]-JVS[242]*XX[31]-JVS[260]*XX[32]
          -JVS[275]*XX[33];
  XX[28] = XX[28]-JVS[216]*XX[29]-JVS[226]*XX[30]-JVS[241]*XX[31]
          -JVS[259]*XX[32]-JVS[274]*XX[33];
  XX[27] = XX[27]-JVS[204]*XX[28]-JVS[215]*XX[29]-JVS[225]*XX[30]
          -JVS[240]*XX[31]-JVS[258]*XX[32]-JVS[273]*XX[33];
  XX[26] = XX[26]-JVS[190]*XX[27]-JVS[203]*XX[28]-JVS[214]*XX[29]
          -JVS[224]*XX[30]-JVS[239]*XX[31]-JVS[257]*XX[32]-JVS[272]
          *XX[33];
  XX[25] = XX[25]-JVS[176]*XX[26]-JVS[189]*XX[27]-JVS[202]*XX[28]
          -JVS[213]*XX[29]-JVS[223]*XX[30]-JVS[238]*XX[31]-JVS[256]
          *XX[32]-JVS[271]*XX[33];
  XX[24] = XX[24]-JVS[156]*XX[25]-JVS[175]*XX[26]-JVS[201]*XX[28]
          -JVS[222]*XX[30]-JVS[237]*XX[31]-JVS[255]*XX[32];
  XX[23] = XX[23]-JVS[131]*XX[24]-JVS[155]*XX[25]-JVS[174]*XX[26]
          -JVS[200]*XX[28]-JVS[236]*XX[31]-JVS[254]*XX[32];
  XX[22] = XX[22]-JVS[154]*XX[25]-JVS[212]*XX[29]-JVS[235]*XX[31]
          -JVS[270]*XX[33];
  XX[21] = XX[21]-JVS[104]*XX[22]-JVS[153]*XX[25]-JVS[173]*XX[26]
          -JVS[188]*XX[27]-JVS[234]*XX[31]-JVS[269]*XX[33];
  XX[20] = XX[20]-JVS[118]*XX[23]-JVS[152]*XX[25]-JVS[211]*XX[29]
          -JVS[253]*XX[32]-JVS[268]*XX[33];
  XX[19] = XX[19]-JVS[151]*XX[25]-JVS[199]*XX[28]-JVS[252]*XX[32];
  XX[18] = XX[18]-JVS[103]*XX[22]-JVS[150]*XX[25]-JVS[267]*XX[33];
  XX[17] = XX[17]-JVS[149]*XX[25]-JVS[172]*XX[26]-JVS[187]*XX[27];
  XX[16] = XX[16]-JVS[148]*XX[25]-JVS[171]*XX[26]-JVS[251]*XX[32];
  XX[15] = XX[15]-JVS[147]*XX[25]-JVS[170]*XX[26];
  XX[14] = XX[14]-JVS[102]*XX[22]-JVS[146]*XX[25]-JVS[250]*XX[32]
          -JVS[266]*XX[33];
  XX[13] = XX[13]-JVS[87]*XX[20]-JVS[117]*XX[23]-JVS[145]*XX[25]
          -JVS[249]*XX[32];
  XX[12] = XX[12]-JVS[130]*XX[24]-JVS[144]*XX[25];
  XX[11] = XX[11]-JVS[71]*XX[18]-JVS[101]*XX[22]-JVS[265]*XX[33];
  XX[10] = XX[10]-JVS[77]*XX[19]-JVS[86]*XX[20]-JVS[116]*XX[23]
          -JVS[143]*XX[25]-JVS[198]*XX[28]-JVS[233]*XX[31];
  XX[9] = XX[9]-JVS[115]*XX[23]-JVS[248]*XX[32];
  XX[8] = XX[8]-JVS[247]*XX[32];
  XX[7] = XX[7]-JVS[100]*XX[22]-JVS[129]*XX[24];
  XX[6] = XX[6]-JVS[128]*XX[24]-JVS[142]*XX[25];
  XX[5] = XX[5]-JVS[127]*XX[24]-JVS[169]*XX[26];
  XX[4] = XX[4]-JVS[186]*XX[27]-JVS[232]*XX[31];
  XX[3] = XX[3]-JVS[168]*XX[26];
  XX[2] = XX[2]-JVS[10]*XX[3]-JVS[167]*XX[26]-JVS[185]*XX[27];
  XX[1] = XX[1]-JVS[166]*XX[26];
  XX[0] = XX[0]-JVS[85]*XX[20];
}

/* End of KppSolveTR function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* BLAS_UTIL - BLAS-LIKE utility functions                          */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*--------------------------------------------------------------
 
  BLAS/LAPACK-like subroutines used by the integration algorithms
  It is recommended to replace them by calls to the optimized
       BLAS/LAPACK library for your machine
 
   (C) Adrian Sandu, Aug. 2004
 
--------------------------------------------------------------*/

#define ZERO  (float)0.0
#define ONE   (float)1.0
#define HALF  (float)0.5
#define TWO   (float)2.0
#define MOD(A,B) (int)((A)%(B))

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WCOPY(int N, float X[], int incX, float Y[], int incY)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    copies a vector, x, to a vector, y:  y <- x
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL  SCOPY(N,X,1,Y,1)   or   CALL  DCOPY(N,X,1,Y,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
      int i, M;
      if (N <= 0) return;

      M = MOD(N,8);
      if( M != 0 ) {
        for ( i = 0; i < M; i++ )
          Y[i] = X[i];
        if( N < 8 ) return;
      } /* end if */	
      for ( i = M; i<N; i+=8 ) {
        Y[i] = X[i];
        Y[i + 1] = X[i + 1];
        Y[i + 2] = X[i + 2];
        Y[i + 3] = X[i + 3];
        Y[i + 4] = X[i + 4];
        Y[i + 5] = X[i + 5];
        Y[i + 6] = X[i + 6];
        Y[i + 7] = X[i + 7];
      } /* end for */

} /* end function WCOPY */


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WAXPY(int N, float Alpha, 
         float X[], int incX, 
	 float Y[], int incY )
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    constant times a vector plus a vector: y <- y + Alpha*x
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL SAXPY(N,Alpha,X,1,Y,1) or  CALL DAXPY(N,Alpha,X,1,Y,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
      int i, M;

      if (Alpha == ZERO) return;
      if (N  <=  0) return;

      M = MOD(N,4);
      if( M != 0 ) {
        for ( i = 0; i < M; i++ )
          Y[i] = Y[i] + Alpha*X[i];
        if ( N < 4 ) return;
      } /* end if */
      
      for ( i = M; i < N; i += 4 ) {
        Y[i] = Y[i] + Alpha*X[i];
        Y[i + 1] = Y[i + 1] + Alpha*X[i + 1];
        Y[i + 2] = Y[i + 2] + Alpha*X[i + 2];
        Y[i + 3] = Y[i + 3] + Alpha*X[i + 3];
      } /* end for */

} /* end function  WAXPY */



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WSCAL(int N, float Alpha, float X[], int incX)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    constant times a vector: x(1:N) <- Alpha*x(1:N) 
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL SSCAL(N,Alpha,X,1) or  CALL DSCAL(N,Alpha,X,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
      int i, M;
      
      if (Alpha == ONE) return;
      if (N  <=  0) return;

      M = MOD(N,5);
      if( M  !=  0 ) {
        if (Alpha == (-ONE))
          for ( i = 0; i < M; i++ )  X[i] = -X[i];
        else {
	  if (Alpha == ZERO)
            for ( i = 0; i < M; i++ ) X[i] = ZERO;
          else
            for ( i = 0; i < M; i++ ) X[i] = Alpha*X[i];
        } /* end else */
        if( N < 5 ) return;
      } /* end if */
      
      if (Alpha == (-ONE))
        for ( i = M; i<N; i+=5 ) {
          X[i]     = -X[i];
          X[i + 1] = -X[i + 1];
          X[i + 2] = -X[i + 2];
          X[i + 3] = -X[i + 3];
          X[i + 4] = -X[i + 4];
        } /* end for */
      else {
        if (Alpha == ZERO)
          for ( i = M; i < N; i += 5 ) {
            X[i]     = ZERO;
            X[i + 1] = ZERO;
            X[i + 2] = ZERO;
            X[i + 3] = ZERO;
            X[i + 4] = ZERO;
          } /* end for */
        else
          for ( i = M; i < N; i += 5 ) {
            X[i]     = Alpha*X[i];
            X[i + 1] = Alpha*X[i + 1];
            X[i + 2] = Alpha*X[i + 2];
            X[i + 3] = Alpha*X[i + 3];
            X[i + 4] = Alpha*X[i + 4];
           } /* end for */
      }  /* else  */
      
} /* end function WSCAL */
   
     
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float WLAMCH_ADD( float  A, float  B )
{
      return (A + B);
} /* end function  WLAMCH_ADD */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float WLAMCH( char C )
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    returns epsilon machine
    after LAPACK
    replace this by the function from the optimized LAPACK implementation:
         CALL SLAMCH('E') or CALL DLAMCH('E')
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
      int i;
      float Suma;
      static float Eps;
      static char First = 1;
      
      if (First) {
        First = 0;
        Eps = pow(HALF,16);
        for ( i = 17; i <= 80; i++ ) {
          Eps = Eps*HALF;
	  Suma = WLAMCH_ADD(ONE,Eps);
	  if (Suma <= ONE) break;
        } /* end for */
        if (i==80) {
	   printf("\nERROR IN WLAMCH. Very small EPS = %g\n",Eps);
           return (double)2.2e-16;
	}
        Eps *= TWO; i--;      
      } /* end if First */

      return Eps;

} /* end function WLAMCH */


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 	copies zeros into the vector y:  y <- 0 after BLAS
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Set2Zero(int N, float Y[])
{
   int i,M;
	
   if (N <= 0) return;

   M = MOD(N,8);
   if  (M != 0)
   {
	for (i = 0; i < M; i++)
	{
	   Y[i] = ZERO;
	}
	if (N < 8) 
	   return;
   } /* end if */
   for (i = M; i < N; i += 8)
   {
   	Y[i] = ZERO;
	Y[i + 1] = ZERO;
        Y[i + 2] = ZERO;
	Y[i + 3] = ZERO;
	Y[i + 4] = ZERO;
	Y[i + 5] = ZERO;
	Y[i + 6] = ZERO;
	Y[i + 7] = ZERO;
   } /* end for */
} /* end function Set2Zero */


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	adds two vectors: z <- x + y     BLAS - like
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WADD(int N, float X[], float Y[], float Z[])
{
	int i, M;

	if ( N <= 0 ) return;
	
	M = MOD(N,5);
	if ( M != 0 )
	{
	   for(i = 0; i < M; i++)
	   {
		Z[i] = X[i] + Y[i];
	   }
	   if ( N < 5 ) return;
	} /* end if */
	for (i = M; i < N; i += 5)
	{
	   Z[i] = X[i] + Y[i];
	   Z[i + 1] = X[i + 1] + Y[i + 1];
	   Z[i + 2] = X[i + 2] + Y[i + 2];
	   Z[i + 3] = X[i + 3] + Y[i + 3];
	   Z[i + 4] = X[i + 4] + Y[i + 4];
	} /* end for */
} /* end function WADD */
/* End of BLAS_UTIL function                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


