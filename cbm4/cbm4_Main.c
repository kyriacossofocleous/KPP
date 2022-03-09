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
/* File                 : cbm4_Main.c                               */
/* Time                 : Wed Mar  9 11:42:18 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/cbm4   */
/* Equation file        : cbm4.kpp                                  */
/* Output root filename : cbm4                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include "cbm4_Parameters.h"
#include "cbm4_Global.h"
#include "cbm4_Sparse.h"



double C[NSPEC];                         /* Concentration of all species */
double * VAR = & C[0];
double * FIX = & C[32];
double E[NSPEC];                         /* Error of all species */
double RCONST[NREACT];                   /* Rate constants (global) */
double TIME;                             /* Current integration time */
double SUN;                              /* Sunlight intensity between [0,1] */
double TEMP;                             /* Temperature */
double RTOLS;                            /* (scalar) Relative tolerance */
double TSTART;                           /* Integration start time */
double TEND;                             /* Integration end time */
double DT;                               /* Integration step */
double ATOL[NVAR];                       /* Absolute tolerance */
double RTOL[NVAR];                       /* Relative tolerance */
double STEPMIN;                          /* Lower bound for integration step */
double STEPMAX;                          /* Upper bound for integration step */
double CFACTOR;                          /* Conversion factor for concentration units */

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
void GetMass( double CL[], double Mass[] );
void INTEGRATE( double TIN, double TOUT );
double Stopwatch(double t);

int main()
{
double dval[NSPEC];
int i;
double t; 
/* ---- TIME VARIABLES ------------------ */

  RTOLS = 1e-1;
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
    
    SaveData();

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


