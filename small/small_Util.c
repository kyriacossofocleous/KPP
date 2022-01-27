/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Auxiliary Routines File                                          */
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
/* File                 : small_Util.c                              */
/* Time                 : Thu Jan 27 12:39:10 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small  */
/* Equation file        : small.kpp                                 */
/* Output root filename : small                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "small_Parameters.h"
#include "small_Global.h"
#include "small_Sparse.h"



/* User INLINED Utility Functions                                   */

/* End INLINED Utility Functions                                    */

/* Utility Functions from KPP_HOME/util/util                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* UTIL - Utility functions                                         */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
*/
double min( double x, double y )
{
  return ( x <= y ) ? x : y;
}

double max( double x, double y )
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
  fpDat = fopen("small.dat", "w");
  if( fpDat == 0 ) {
    printf("\n Can't create file : small.dat");
    exit(1);
  }
  return 0;
}

int InitSaveError()
{
  fpErr = fopen("small_Err.dat", "w");
  if( fpErr == 0 ) {
    printf("\n Can't create file : small_Err.dat");
    exit(1);
  }
  return 0;
}

int InitSaveE()
{
  fpE = fopen("small_E.dat","w");
  if ( fpE == 0 ){
    printf("\n Can't create file: small_E.dat");
    exit(1);
  }
  return 0;
}

int SaveE(double Err, int s)
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
  
  fpMatlab = fopen("small.m", "w");
  if( fpMatlab == 0 ) {
    printf("\n Can't create file : small.m");
    exit(1);
  }

  fprintf(fpMatlab, "load small.dat;\n");
  fprintf(fpMatlab, "%sc = small;\n", prefix);
  fprintf(fpMatlab, "clear small;\n");
  fprintf(fpMatlab, "%st=%sc(:,1);\n", prefix, prefix);
  fprintf(fpMatlab, "%sc(:,1)=[];\n", prefix);
  
  for( i = 0; i < NLOOKAT; i++ )
    fprintf( fpMatlab, "%s%s = %sc(:,%d);\n", 
            prefix, SPC_NAMES[LOOKAT[i]], 
            prefix, i+1 );
  
  fclose( fpMatlab );
  return 0;
}
/* End Utility Functions from KPP_HOME/util/util                    */
/* End of UTIL function                                             */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Shuffle_user2kpp - function to copy concentrations from USER to KPP */
/*   Arguments :                                                    */
/*      V_USER    - Concentration of variable species in USER's order */
/*      V         - Concentrations of variable species (local)      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Shuffle_user2kpp( 
  double V_USER[],                       /* Concentration of variable species in USER's order */
  double V[]                             /* Concentrations of variable species (local) */
)
{
  V[1] = V_USER[0];
  V[0] = V_USER[1];
  V[2] = V_USER[2];
  V[3] = V_USER[3];
  V[4] = V_USER[4];
}

/* End of Shuffle_user2kpp function                                 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Shuffle_kpp2user - function to restore concentrations from KPP to USER */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      V_USER    - Concentration of variable species in USER's order */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Shuffle_kpp2user( 
  double V[],                            /* Concentrations of variable species (local) */
  double V_USER[]                        /* Concentration of variable species in USER's order */
)
{
  V_USER[0] = V[1];
  V_USER[1] = V[0];
  V_USER[2] = V[2];
  V_USER[3] = V[3];
  V_USER[4] = V[4];
}

/* End of Shuffle_kpp2user function                                 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* GetMass - compute total mass of selected atoms                   */
/*   Arguments :                                                    */
/*      CL        - Concentration of all species (local)            */
/*      Mass      - value of mass balance                           */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void GetMass( 
  double CL[],                           /* Concentration of all species (local) */
  double Mass[]                          /* value of mass balance */
)
{
  Mass[0] = CL[3]+CL[4]+CL[5]+CL[5];
}

/* End of GetMass function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


