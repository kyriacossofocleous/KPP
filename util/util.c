/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
*/
KPP_REAL min( KPP_REAL x, KPP_REAL y )
{
  return ( x <= y ) ? x : y;
}

KPP_REAL max( KPP_REAL x, KPP_REAL y )
{
  return ( x >= y ) ? x : y;
}

double
Stopwatch(double t0)
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec / 1e6 - t0;
}

static FILE *fpDat = 0;
static FILE *fpErr = 0;
static FILE *fpE = 0;

int InitSaveData()
{
  fpDat = fopen("KPP_ROOT.dat", "w");
  if( fpDat == 0 ) {
    printf("\n Can't create file : KPP_ROOT.dat");
    exit(1);
  }
  return 0;
}

int InitSaveError()
{
  fpErr = fopen("KPP_ROOT_Err.dat", "w");
  if( fpErr == 0 ) {
    printf("\n Can't create file : KPP_ROOT_Err.dat");
    exit(1);
  }
  return 0;
}

int InitSaveE()
{
  fpE = fopen("KPP_ROOT_E.dat","w");
  if ( fpE == 0 ){
    printf("\n Can't create file: KPP_ROOT_E.dat");
    exit(1);
  }
  return 0;
}

int SaveE(KPP_REAL Err, int s)
{
  fprintf( fpE, "%6.3f ", TIME/3600.0);
  fprintf( fpE, "%e ", Err);
  fprintf( fpE, "%e ", SUN);
  fprintf( fpE, "%d ", s);
  fprintf( fpE, "\n");
  return 0;
}


int SaveData()
{
int i;

  fprintf( fpDat, "%6.1f ", TIME/3600.0 );
  for( i = 0; i < NLOOKAT; i++ )
    fprintf( fpDat, "%24.16e ", C[ LOOKAT[i] ]/CFACTOR );
  // fprintf( fpDat, "%d ", s);
  fprintf( fpDat, "\n");
  return 0;
}

int SaveError(int s)
{
int i;

  fprintf( fpErr, "%6.1f ", TIME/3600.0 );
  for( i = 0; i < NLOOKAT; i++ )
    fprintf( fpErr, "%24.16e ", E[ LOOKAT[i] ] );
  fprintf( fpErr, "%d ", s);
  fprintf( fpErr, "\n");
  return 0;
}

int CloseSaveData()
{
  fclose( fpDat );
  return 0;
}

int CloseSaveError()
{
  fclose( fpErr );
  return 0;
}

int CloseSaveE()
{
  fclose( fpE );
  return 0;
}

int GenerateMatlab( char * prefix )
{
int i;
FILE *fpMatlab;
  
  fpMatlab = fopen("KPP_ROOT.m", "w");
  if( fpMatlab == 0 ) {
    printf("\n Can't create file : KPP_ROOT.m");
    exit(1);
  }

  fprintf(fpMatlab, "load KPP_ROOT.dat;\n");
  fprintf(fpMatlab, "%sc = KPP_ROOT;\n", prefix);
  fprintf(fpMatlab, "clear KPP_ROOT;\n");
  fprintf(fpMatlab, "%st=%sc(:,1);\n", prefix, prefix);
  fprintf(fpMatlab, "%sc(:,1)=[];\n", prefix);
  
  for( i = 0; i < NLOOKAT; i++ )
    fprintf( fpMatlab, "%s%s = %sc(:,%d);\n", 
            prefix, SPC_NAMES[LOOKAT[i]], 
            prefix, i+1 );
  
  fclose( fpMatlab );
  return 0;
}
