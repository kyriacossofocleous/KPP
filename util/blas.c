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