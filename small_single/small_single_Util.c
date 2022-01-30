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
/* File                 : small_single_Util.c                       */
/* Time                 : Sun Jan 30 10:24:16 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_single */
/* Equation file        : small_single.kpp                          */
/* Output root filename : small_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include "small_single_Parameters.h"
#include "small_single_Global.h"
#include "small_single_Sparse.h"



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
float min( float x, float y )
{
  return ( x <= y ) ? x : y;
}

float max( float x, float y )
{
  return ( x >= y ) ? x : y;
}

double
Stopwatch(double t0)
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec / (double)1e6 - t0;
}

static FILE *fpDat = 0;
static FILE *fpErr = 0;
static FILE *fpE = 0;

int InitSaveData()
{
  fpDat = fopen("small_single.dat", "w");
  if( fpDat == 0 ) {
    printf("\n Can't create file : small_single.dat");
    exit(1);
  }
  return 0;
}

int InitSaveError()
{
  fpErr = fopen("small_single_Err.dat", "w");
  if( fpErr == 0 ) {
    printf("\n Can't create file : small_single_Err.dat");
    exit(1);
  }
  return 0;
}

int InitSaveE()
{
  fpE = fopen("small_single_E.dat","w");
  if ( fpE == 0 ){
    printf("\n Can't create file: small_single_E.dat");
    exit(1);
  }
  return 0;
}

int SaveE(float Err, int s)
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
  
  fpMatlab = fopen("small_single.m", "w");
  if( fpMatlab == 0 ) {
    printf("\n Can't create file : small_single.m");
    exit(1);
  }

  fprintf(fpMatlab, "load small_single.dat;\n");
  fprintf(fpMatlab, "%sc = small_single;\n", prefix);
  fprintf(fpMatlab, "clear small_single;\n");
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
  float V_USER[],                        /* Concentration of variable species in USER's order */
  float V[]                              /* Concentrations of variable species (local) */
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
  float V[],                             /* Concentrations of variable species (local) */
  float V_USER[]                         /* Concentration of variable species in USER's order */
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
  float CL[],                            /* Concentration of all species (local) */
  float Mass[]                           /* value of mass balance */
)
{
  Mass[0] = CL[3]+CL[4]+CL[5]+CL[5];
}

/* End of GetMass function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


