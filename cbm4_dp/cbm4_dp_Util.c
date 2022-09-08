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
/* File                 : cbm4_dp_Util.c                            */
/* Time                 : Fri Sep  2 14:40:14 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/cbm4_dp */
/* Equation file        : cbm4_dp.kpp                               */
/* Output root filename : cbm4_dp                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <xmmintrin.h>
#include "cbm4_dp_Parameters.h"
#include "cbm4_dp_Global.h"
#include "cbm4_dp_Sparse.h"



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
  return (double)t.tv_sec + (double)t.tv_usec / (double)1e6 - t0;
}

static FILE *fpDat = 0;
static FILE *fpErr = 0;
static FILE *fpE = 0;

int InitSaveData()
{
  fpDat = fopen("cbm4_dp.dat", "w");
  if( fpDat == 0 ) {
    printf("\n Can't create file : cbm4_dp.dat");
    exit(1);
  }
  return 0;
}

int InitSaveError()
{
  fpErr = fopen("cbm4_dp_Err.dat", "w");
  if( fpErr == 0 ) {
    printf("\n Can't create file : cbm4_dp_Err.dat");
    exit(1);
  }
  return 0;
}

int InitSaveE()
{
  fpE = fopen("cbm4_dp_E.dat","w");
  if ( fpE == 0 ){
    printf("\n Can't create file: cbm4_dp_E.dat");
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
  
  fpMatlab = fopen("cbm4_dp.m", "w");
  if( fpMatlab == 0 ) {
    printf("\n Can't create file : cbm4_dp.m");
    exit(1);
  }

  fprintf(fpMatlab, "load cbm4_dp.dat;\n");
  fprintf(fpMatlab, "%sc = cbm4_dp;\n", prefix);
  fprintf(fpMatlab, "clear cbm4_dp;\n");
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
  V[30] = V_USER[0];
  V[25] = V_USER[1];
  V[29] = V_USER[2];
  V[5] = V_USER[3];
  V[8] = V_USER[4];
  V[11] = V_USER[5];
  V[9] = V_USER[6];
  V[0] = V_USER[7];
  V[28] = V_USER[8];
  V[26] = V_USER[9];
  V[24] = V_USER[10];
  V[27] = V_USER[11];
  V[1] = V_USER[12];
  V[20] = V_USER[13];
  V[23] = V_USER[14];
  V[31] = V_USER[15];
  V[2] = V_USER[16];
  V[19] = V_USER[17];
  V[12] = V_USER[18];
  V[22] = V_USER[19];
  V[16] = V_USER[20];
  V[4] = V_USER[21];
  V[13] = V_USER[22];
  V[10] = V_USER[23];
  V[3] = V_USER[24];
  V[18] = V_USER[25];
  V[6] = V_USER[26];
  V[14] = V_USER[27];
  V[21] = V_USER[28];
  V[17] = V_USER[29];
  V[7] = V_USER[30];
  V[15] = V_USER[31];
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
  V_USER[0] = V[30];
  V_USER[1] = V[25];
  V_USER[2] = V[29];
  V_USER[3] = V[5];
  V_USER[4] = V[8];
  V_USER[5] = V[11];
  V_USER[6] = V[9];
  V_USER[7] = V[0];
  V_USER[8] = V[28];
  V_USER[9] = V[26];
  V_USER[10] = V[24];
  V_USER[11] = V[27];
  V_USER[12] = V[1];
  V_USER[13] = V[20];
  V_USER[14] = V[23];
  V_USER[15] = V[31];
  V_USER[16] = V[2];
  V_USER[17] = V[19];
  V_USER[18] = V[12];
  V_USER[19] = V[22];
  V_USER[20] = V[16];
  V_USER[21] = V[4];
  V_USER[22] = V[13];
  V_USER[23] = V[10];
  V_USER[24] = V[3];
  V_USER[25] = V[18];
  V_USER[26] = V[6];
  V_USER[27] = V[14];
  V_USER[28] = V[21];
  V_USER[29] = V[17];
  V_USER[30] = V[7];
  V_USER[31] = V[15];
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
}

/* End of GetMass function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


