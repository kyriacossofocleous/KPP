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
void WCOPY(int N, double X[], int incX, double Y[], int incY)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    copies a vector, x, to a vector, y:  y <- x
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL  SCOPY(N,X,1,Y,1)   or   CALL  DCOPY(N,X,1,Y,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
  int i, M;
  register __m128d x0;

  if (N <= 0)
    return;

  M = MOD(N, 2);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
      Y[i] = X[i];
    if (N < 2)
      return;
  } /* end if */
  for (i = M; i < N; i += 2)
  {
    x0 = _mm_loadu_pd((double *)&X[i]);
    _mm_storeu_pd((double *)&Y[i], x0);
  } /* end for */

} /* end function WCOPY */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WAXPY(int N, double Alpha,
           double X[], int incX,
           double Y[], int incY)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    constant times a vector plus a vector: y <- y + Alpha*x
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL SAXPY(N,Alpha,X,1,Y,1) or  CALL DAXPY(N,Alpha,X,1,Y,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
  int i, M;

  if (Alpha == ZERO)
    return;
  if (N <= 0)
    return;

  M = MOD(N, 4);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
      Y[i] = Y[i] + Alpha * X[i];
    if (N < 4)
      return;
  } /* end if */

  for (i = M; i < N; i += 4)
  {
    Y[i] = Y[i] + Alpha * X[i];
    Y[i + 1] = Y[i + 1] + Alpha * X[i + 1];
    Y[i + 2] = Y[i + 2] + Alpha * X[i + 2];
    Y[i + 3] = Y[i + 3] + Alpha * X[i + 3];
  } /* end for */

} /* end function  WAXPY */

void WAXPYIDU(int L, double a, double *x, double *y)
{

  int i, M;
  double av[] = {a, a};
  register __m128d va = _mm_load_pd(av);
  register __m128d x0, y0;

  if (a == 0)
    return;
  if (L <= 0)
    return;

  M = MOD(L, 2);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
      y[i] = y[i] + a * x[i];
    if (L < 2)
      return;
  } /* end if */

  #pragma code_align 8
  for (int i = M; i < L; i += 2)
  {
    y0 = _mm_loadu_pd((double *)&y[i]);
    x0 = _mm_loadu_pd((double *)&x[i]);
    x0 = _mm_mul_pd(va, x0);
    y0 = _mm_add_pd(y0, x0);
    _mm_storeu_pd((double *)&y[i], y0);
  }
  return;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WSCAL(int N, double Alpha, double X[], int incX)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    constant times a vector: x(1:N) <- Alpha*x(1:N) 
    only for incX=incY=1
    after BLAS
    replace this by the function from the optimized BLAS implementation:
        CALL SSCAL(N,Alpha,X,1) or  CALL DSCAL(N,Alpha,X,1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
  int i, M;
  double av[] = {Alpha, Alpha};
  register __m128d va = _mm_load_pd(av);
  register __m128d x0;

  if (Alpha == ONE)
    return;
  if (N <= 0)
    return;

  M = MOD(N, 2);
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
    if (N < 2)
      return;
  } /* end if */

  if (Alpha == (-ONE))
    for (i = M; i < N; i += 2)
    {
      x0 = _mm_loadu_pd((double *)&X[i]);
      x0 = _mm_sub_pd(_mm_set1_pd(0.0), x0);
      _mm_storeu_pd((double *)&X[i], x0);

    } /* end for */
  else
  {
    if (Alpha == ZERO)
      for (i = M; i < N; i += 2)
      {
        x0 = _mm_loadu_pd((double *)&X[i]);
        x0 = _mm_setzero_pd();
        _mm_storeu_pd((double *)&X[i], x0);
      } /* end for */
    else
      for (i = M; i < N; i += 2)
      {
        x0 = _mm_loadu_pd((double *)&X[i]);
        x0 = _mm_mul_pd(va, x0);
        _mm_storeu_pd((double *)&X[i], x0);
      } /* end for */
  }     /* else  */

} /* end function WSCAL */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double WLAMCH_ADD(double A, double B)
{
  return (A + B);
} /* end function  WLAMCH_ADD */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double WLAMCH(char C)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    returns epdilon machine
    after LAPACK
    replace this by the function from the optimized LAPACK implementation:
         CALL SLAMCH('E') or CALL DLAMCH('E')
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
{
  int i;
  double Suma;
  static double Eps;
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
void Set2Zero(int N, double Y[])
{
  int i, M;
  register __m128d y0;

  if (N <= 0)
    return;

  M = MOD(N, 2);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
    {
      Y[i] = ZERO;
    }
    if (N < 2)
      return;
  } /* end if */
  for (i = M; i < N; i += 2)
  {
    y0 = _mm_setzero_pd();
    _mm_storeu_pd((double *)&Y[i], y0);
  } /* end for */
} /* end function Set2Zero */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	adds two vectors: z <- x + y     BLAS - like
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void WADD(int N, double X[], double Y[], double Z[])
{
  int i, M;
  register __m128d x0, y0;

  if (N <= 0)
    return;

  M = MOD(N, 2);
  if (M != 0)
  {
    for (i = 0; i < M; i++)
    {
      Z[i] = X[i] + Y[i];
    }
    if (N < 2)
      return;
  } /* end if */
  for (i = M; i < N; i += 2)
  {
    x0 = _mm_loadu_pd((double *)&X[i]);
    y0 = _mm_loadu_pd((double *)&Y[i]);
    x0 = _mm_add_pd(x0, y0);
    _mm_storeu_pd((double *)&Z[i], x0);
  } /* end for */
} /* end function WADD */
/* End of BLAS_UTIL function                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */