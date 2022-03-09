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
/* File                 : saprc_single_Util.c                       */
/* Time                 : Wed Mar  9 12:16:57 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc_single */
/* Equation file        : saprc_single.kpp                          */
/* Output root filename : saprc_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "saprc_single_Parameters.h"
#include "saprc_single_Global.h"
#include "saprc_single_Sparse.h"



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
  return (double)t.tv_sec + (double)t.tv_usec / 1e6 - t0;
}

static FILE *fpDat = 0;
static FILE *fpErr = 0;
static FILE *fpE = 0;

int InitSaveData()
{
  fpDat = fopen("saprc_single.dat", "w");
  if( fpDat == 0 ) {
    printf("\n Can't create file : saprc_single.dat");
    exit(1);
  }
  return 0;
}

int InitSaveError()
{
  fpErr = fopen("saprc_single_Err.dat", "w");
  if( fpErr == 0 ) {
    printf("\n Can't create file : saprc_single_Err.dat");
    exit(1);
  }
  return 0;
}

int InitSaveE()
{
  fpE = fopen("saprc_single_E.dat","w");
  if ( fpE == 0 ){
    printf("\n Can't create file: saprc_single_E.dat");
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
  
  fpMatlab = fopen("saprc_single.m", "w");
  if( fpMatlab == 0 ) {
    printf("\n Can't create file : saprc_single.m");
    exit(1);
  }

  fprintf(fpMatlab, "load saprc_single.dat;\n");
  fprintf(fpMatlab, "%sc = saprc_single;\n", prefix);
  fprintf(fpMatlab, "clear saprc_single;\n");
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
  V[61] = V_USER[0];
  V[16] = V_USER[1];
  V[68] = V_USER[2];
  V[69] = V_USER[3];
  V[70] = V_USER[4];
  V[17] = V_USER[5];
  V[18] = V_USER[6];
  V[42] = V_USER[7];
  V[24] = V_USER[8];
  V[8] = V_USER[9];
  V[0] = V_USER[10];
  V[39] = V_USER[11];
  V[55] = V_USER[12];
  V[54] = V_USER[13];
  V[58] = V_USER[14];
  V[41] = V_USER[15];
  V[59] = V_USER[16];
  V[1] = V_USER[17];
  V[28] = V_USER[18];
  V[2] = V_USER[19];
  V[3] = V_USER[20];
  V[44] = V_USER[21];
  V[40] = V_USER[22];
  V[11] = V_USER[23];
  V[33] = V_USER[24];
  V[37] = V_USER[25];
  V[51] = V_USER[26];
  V[49] = V_USER[27];
  V[53] = V_USER[28];
  V[60] = V_USER[29];
  V[34] = V_USER[30];
  V[31] = V_USER[31];
  V[32] = V_USER[32];
  V[43] = V_USER[33];
  V[46] = V_USER[34];
  V[10] = V_USER[35];
  V[19] = V_USER[36];
  V[20] = V_USER[37];
  V[29] = V_USER[38];
  V[22] = V_USER[39];
  V[30] = V_USER[40];
  V[23] = V_USER[41];
  V[50] = V_USER[42];
  V[52] = V_USER[43];
  V[48] = V_USER[44];
  V[56] = V_USER[45];
  V[35] = V_USER[46];
  V[38] = V_USER[47];
  V[12] = V_USER[48];
  V[13] = V_USER[49];
  V[14] = V_USER[50];
  V[15] = V_USER[51];
  V[4] = V_USER[52];
  V[72] = V_USER[53];
  V[5] = V_USER[54];
  V[6] = V_USER[55];
  V[7] = V_USER[56];
  V[57] = V_USER[57];
  V[9] = V_USER[58];
  V[73] = V_USER[59];
  V[62] = V_USER[60];
  V[65] = V_USER[61];
  V[25] = V_USER[62];
  V[36] = V_USER[63];
  V[67] = V_USER[64];
  V[47] = V_USER[65];
  V[63] = V_USER[66];
  V[26] = V_USER[67];
  V[71] = V_USER[68];
  V[66] = V_USER[69];
  V[27] = V_USER[70];
  V[45] = V_USER[71];
  V[64] = V_USER[72];
  V[21] = V_USER[73];
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
  V_USER[0] = V[61];
  V_USER[1] = V[16];
  V_USER[2] = V[68];
  V_USER[3] = V[69];
  V_USER[4] = V[70];
  V_USER[5] = V[17];
  V_USER[6] = V[18];
  V_USER[7] = V[42];
  V_USER[8] = V[24];
  V_USER[9] = V[8];
  V_USER[10] = V[0];
  V_USER[11] = V[39];
  V_USER[12] = V[55];
  V_USER[13] = V[54];
  V_USER[14] = V[58];
  V_USER[15] = V[41];
  V_USER[16] = V[59];
  V_USER[17] = V[1];
  V_USER[18] = V[28];
  V_USER[19] = V[2];
  V_USER[20] = V[3];
  V_USER[21] = V[44];
  V_USER[22] = V[40];
  V_USER[23] = V[11];
  V_USER[24] = V[33];
  V_USER[25] = V[37];
  V_USER[26] = V[51];
  V_USER[27] = V[49];
  V_USER[28] = V[53];
  V_USER[29] = V[60];
  V_USER[30] = V[34];
  V_USER[31] = V[31];
  V_USER[32] = V[32];
  V_USER[33] = V[43];
  V_USER[34] = V[46];
  V_USER[35] = V[10];
  V_USER[36] = V[19];
  V_USER[37] = V[20];
  V_USER[38] = V[29];
  V_USER[39] = V[22];
  V_USER[40] = V[30];
  V_USER[41] = V[23];
  V_USER[42] = V[50];
  V_USER[43] = V[52];
  V_USER[44] = V[48];
  V_USER[45] = V[56];
  V_USER[46] = V[35];
  V_USER[47] = V[38];
  V_USER[48] = V[12];
  V_USER[49] = V[13];
  V_USER[50] = V[14];
  V_USER[51] = V[15];
  V_USER[52] = V[4];
  V_USER[53] = V[72];
  V_USER[54] = V[5];
  V_USER[55] = V[6];
  V_USER[56] = V[7];
  V_USER[57] = V[57];
  V_USER[58] = V[9];
  V_USER[59] = V[73];
  V_USER[60] = V[62];
  V_USER[61] = V[65];
  V_USER[62] = V[25];
  V_USER[63] = V[36];
  V_USER[64] = V[67];
  V_USER[65] = V[47];
  V_USER[66] = V[63];
  V_USER[67] = V[26];
  V_USER[68] = V[71];
  V_USER[69] = V[66];
  V_USER[70] = V[27];
  V_USER[71] = V[45];
  V_USER[72] = V[64];
  V_USER[73] = V[21];
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
}

/* End of GetMass function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


