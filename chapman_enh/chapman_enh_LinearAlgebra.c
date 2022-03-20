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
/* File                 : chapman_enh_LinearAlgebra.c               */
/* Time                 : Sun Mar 20 10:54:49 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman_enh */
/* Equation file        : chapman_enh.kpp                           */
/* Output root filename : chapman_enh                               */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "chapman_enh_Parameters.h"
#include "chapman_enh_Global.h"
#include "chapman_enh_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* SPARSE_UTIL - SPARSE utility functions                           */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


int KppDecomp( float *JVS )
{
float W[4];
float a;
int k, kk, j, jj;

  for( k = 0; k < 4; k++ ) {
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
  X[1] = X[1]-JVS[3]*X[0];
  X[2] = X[2]-JVS[7]*X[0]-JVS[8]*X[1];
  X[3] = X[3]-JVS[11]*X[0]-JVS[12]*X[1]-JVS[13]*X[2];
  X[3] = X[3]/JVS[14];
  X[2] = (X[2]-JVS[10]*X[3])/(JVS[9]);
  X[1] = (X[1]-JVS[5]*X[2]-JVS[6]*X[3])/(JVS[4]);
  X[0] = (X[0]-JVS[1]*X[1]-JVS[2]*X[3])/(JVS[0]);
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
  XX[1] = (X[1]-JVS[1]*XX[0])/(JVS[4]);
  XX[2] = (X[2]-JVS[5]*XX[1])/(JVS[9]);
  XX[3] = (X[3]-JVS[2]*XX[0]-JVS[6]*XX[1]-JVS[10]*XX[2])/(JVS[14]);
  XX[3] = XX[3];
  XX[2] = XX[2]-JVS[13]*XX[3];
  XX[1] = XX[1]-JVS[8]*XX[2]-JVS[12]*XX[3];
  XX[0] = XX[0]-JVS[3]*XX[1]-JVS[7]*XX[2]-JVS[11]*XX[3];
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

#define ZERO (float)0.0
#define ONE (float)1.0
#define HALF (float)0.5
#define TWO (float)2.0
#define MOD(A, B) (int)((A) % (B))

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
  register __m128 x0;

  if (N <= 0)
    return;

  M = MOD(N, 4);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
      Y[i] = X[i];
    if (N < 4)
      return;
  } /* end if */
  for (i = M; i < N; i += 4)
  {
    x0 = _mm_loadu_ps((float *)&X[i]);
    _mm_storeu_ps((float *)&Y[i], x0);
  } /* end for */

} /* end function WCOPY */

// /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// void WAXPY(int N, float Alpha,
//            float X[], int incX,
//            float Y[], int incY)
// /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//     constant times a vector plus a vector: y <- y + Alpha*x
//     only for incX=incY=1
//     after BLAS
//     replace this by the function from the optimized BLAS implementation:
//         CALL SAXPY(N,Alpha,X,1,Y,1) or  CALL DAXPY(N,Alpha,X,1,Y,1)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// {
//   int i, M;

//   if (Alpha == ZERO)
//     return;
//   if (N <= 0)
//     return;

//   M = MOD(N, 4);
//   if (M != 0)
//   {
//     for (i = 0; i < M; i++)
//       Y[i] = Y[i] + Alpha * X[i];
//     if (N < 4)
//       return;
//   } /* end if */

//   for (i = M; i < N; i += 4)
//   {
//     Y[i] = Y[i] + Alpha * X[i];
//     Y[i + 1] = Y[i + 1] + Alpha * X[i + 1];
//     Y[i + 2] = Y[i + 2] + Alpha * X[i + 2];
//     Y[i + 3] = Y[i + 3] + Alpha * X[i + 3];
//   } /* end for */

// } /* end function  WAXPY */

void WAXPY(int L, float a, float *x, int incX, float *y, int incY)
{

  int i, M;
  float av[] = {a, a, a, a};
  register __m128 va = _mm_load_ps(av);
  register __m128 x0, y0;

  if (a == 0)
    return;
  if (L <= 0)
    return;

  M = L % 4;
  if (M != 0)
  {
    for (i = 0; i < M; i++)
      y[i] = y[i] + a * x[i];
    if (L < 4)
      return;
  } /* end if */

  for (int i = M; i < L; i += 4)
  {
    y0 = _mm_loadu_ps((float *)&y[i]);
    x0 = _mm_loadu_ps((float *)&x[i]);
    x0 = _mm_mul_ps(va, x0);
    y0 = _mm_add_ps(y0, x0);
    _mm_storeu_ps((float *)&y[i], y0);
  }
  return;
}

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
  float av[] = {Alpha, Alpha, Alpha, Alpha};
  register __m128 va = _mm_load_ps(av);
  register __m128 x0;

  if (Alpha == ONE)
    return;
  if (N <= 0)
    return;

  M = MOD(N, 4);
  if (M != 0)
  {
    if (Alpha == (-ONE))
      for (i = 0; i < M; i++)
        X[i] = -X[i];
    else
    {
      if (Alpha == ZERO)
        for (i = 0; i < M; i++)
          X[i] = ZERO;
      else
        for (i = 0; i < M; i++)
          X[i] = Alpha * X[i];
    } /* end else */
    if (N < 4)
      return;
  } /* end if */

  if (Alpha == (-ONE))
    for (i = M; i < N; i += 4)
    {
      x0 = _mm_loadu_ps((float *)&X[i]);
      x0 = _mm_sub_ps(_mm_set1_ps(0.0), x0);
      _mm_storeu_ps((float *)&X[i], x0);

    } /* end for */
  else
  {
    if (Alpha == ZERO)
      for (i = M; i < N; i += 4)
      {
        x0 = _mm_loadu_ps((float *)&X[i]);
        x0 = _mm_setzero_ps();
        _mm_storeu_ps((float *)&X[i], x0);
      } /* end for */
    else
      for (i = M; i < N; i += 4)
      {
        x0 = _mm_loadu_ps((float *)&X[i]);
        x0 = _mm_mul_ps(va, x0);
        _mm_storeu_ps((float *)&X[i], x0);
      } /* end for */
  }     /* else  */

} /* end function WSCAL */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float WLAMCH_ADD(float A, float B)
{
  return (A + B);
} /* end function  WLAMCH_ADD */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float WLAMCH(char C)
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

  if (First)
  {
    First = 0;
    Eps = pow(HALF, 16);
    for (i = 17; i <= 80; i++)
    {
      Eps = Eps * HALF;
      Suma = WLAMCH_ADD(ONE, Eps);
      if (Suma <= ONE)
        break;
    } /* end for */
    if (i == 80)
    {
      printf("\nERROR IN WLAMCH. Very small EPS = %g\n", Eps);
      return (double)2.2e-16;
    }
    Eps *= TWO;
    i--;
  } /* end if First */

  return Eps;

} /* end function WLAMCH */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 	copies zeros into the vector y:  y <- 0 after BLAS
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Set2Zero(int N, float Y[])
{
  int i, M;
  register __m128 y0;

  if (N <= 0)
    return;

  M = MOD(N, 4);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
    {
      Y[i] = ZERO;
    }
    if (N < 4)
      return;
  } /* end if */
  for (i = M; i < N; i += 4)
  {
    y0 = _mm_setzero_ps();
    _mm_storeu_ps((float *)&Y[i], y0);
  } /* end for */
} /* end function Set2Zero */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	adds two vectors: z <- x + y     BLAS - like
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WADD(int N, float X[], float Y[], float Z[])
{
  int i, M;
  register __m128 x0, y0;

  if (N <= 0)
    return;

  M = MOD(N, 4);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
    {
      Z[i] = X[i] + Y[i];
    }
    if (N < 4)
      return;
  } /* end if */
  for (i = M; i < N; i += 4)
  {
    x0 = _mm_loadu_ps((float *)&X[i]);
    y0 = _mm_loadu_ps((float *)&Y[i]);
    x0 = _mm_add_ps(x0,y0);
    _mm_storeu_ps((float *)&Z[i], x0);
  } /* end for */
} /* end function WADD */
/* End of BLAS_UTIL function                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* End of BLAS_UTIL function                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


