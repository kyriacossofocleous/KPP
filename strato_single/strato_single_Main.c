/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Main Program File                                                */
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
/* File                 : strato_single_Main.c                      */
/* Time                 : Thu Jan 27 12:39:39 2022                  */
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
#include <float.h>
#include "strato_single_Parameters.h"
#include "strato_single_Global.h"
#include "strato_single_Sparse.h"



float C[NSPEC];                          /* Concentration of all species */
float * VAR = & C[0];
float * FIX = & C[34];
float E[NSPEC];                          /* Error of all species */
float RCONST[NREACT];                    /* Rate constants (global) */
double TIME;                             /* Current integration time */
float SUN;                               /* Sunlight intensity between [0,1] */
float TEMP;                              /* Temperature */
float RTOLS;                             /* (scalar) Relative tolerance */
float TSTART;                            /* Integration start time */
float TEND;                              /* Integration end time */
float DT;                                /* Integration step */
float ATOL[NVAR];                        /* Absolute tolerance */
float RTOL[NVAR];                        /* Relative tolerance */
float STEPMIN;                           /* Lower bound for integration step */
float STEPMAX;                           /* Upper bound for integration step */
float CFACTOR;                           /* Conversion factor for concentration units */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* MAIN - Main program - driver routine                             */
/*   Arguments :                                                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int  InitSaveData();
int  InitSaveError();
int  InitSaveE();
void Initialize();
int  SaveData();
int  CloseSaveData();
int  CloseSaveError();
int  CloseSaveE();
int  GenerateMatlab( char * prefix );
void GetMass( float CL[], float Mass[] );
void INTEGRATE( float TIN, float TOUT );
double Stopwatch(double t);

int main()
{
float dval[NSPEC];
int i;
double t; 
/* ---- TIME VARIABLES ------------------ */

  RTOLS = 1e-3;
  TSTART = 3600*12;
  TEND = TSTART + 3600*24*5;
  DT = 3600.;
  TEMP = 236.21;

  Initialize();
  t = Stopwatch(0);
  for( i = 0; i < NVAR; i++ ) {
    RTOL[i] = RTOLS;
    ATOL[i] = 1.0;
  }
  STEPMIN = 0.01;
  STEPMAX = 900;
      
/* ********** TIME LOOP **************************** */

  InitSaveData();
  InitSaveError();
  InitSaveE();

  printf("\n%7s %7s   ", "done[%]", "Time[h]");
  for( i = 0; i < NMONITOR; i++ )  
    printf( "%8s  ", SPC_NAMES[MONITOR[i]] );
  for( i = 0; i < NMASS; i++ )  
    printf( "(%6s)  ", SMASS[i] );
  
  TIME = TSTART;
  while (TIME <= TEND) {
    GetMass( C, dval );
    printf("\n%6.1f%% %7.2f   ", (TIME-TSTART)/(TEND-TSTART)*100, TIME/3600 );
    for( i = 0; i < NMONITOR; i++ ) 
      printf( "%9.3e  ", C[ MONITOR[i] ]/CFACTOR );
    for( i = 0; i < NMASS; i++ ) 
      printf( "%9.3e  ", dval[i]/CFACTOR );
    
    // SaveData();

    INTEGRATE( TIME , TIME+DT );
    TIME += DT;
  }

/* *********** END TIME LOOP *********************** */
  t = Stopwatch(t);
  printf("Simulation Time: %10.6f", t);
  printf("\n");
  CloseSaveData();
  CloseSaveError();
  CloseSaveE();

    return 0; /*didnt return anything initially */

}
/* End of MAIN function                                             */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


