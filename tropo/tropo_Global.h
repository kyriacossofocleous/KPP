/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Global Data Header File                                          */
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
/* File                 : tropo_Global.h                            */
/* Time                 : Wed Apr  6 15:25:07 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/tropo  */
/* Equation file        : tropo.kpp                                 */
/* Output root filename : tropo                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




/* Declaration of global variables                                  */

extern float C[NSPEC];                          /* Concentration of all species */
  extern float * VAR;
  extern float * FIX;
extern float E[NSPEC];                          /* Error of all species */
extern float RCONST[NREACT];                    /* Rate constants (global) */
extern float TIME;                              /* Current integration time */
extern double FUNTIME;                          /* Function Evaluation time */
extern double SUN;                              /* Sunlight intensity between [0,1] */
extern float TEMP;                              /* Temperature */
extern float RTOLS;                             /* (scalar) Relative tolerance */
extern double TSTART;                           /* Integration start time */
extern double TEND;                             /* Integration end time */
extern double DT;                               /* Integration step */
extern float ATOL[NVAR];                        /* Absolute tolerance */
extern float RTOL[NVAR];                        /* Relative tolerance */
extern float STEPMIN;                           /* Lower bound for integration step */
extern float STEPMAX;                           /* Upper bound for integration step */
extern float CFACTOR;                           /* Conversion factor for concentration units */
extern int DDMTYPE;                             /* DDM sensitivity w.r.t.: 0=init.val., 1=params */
extern int LOOKAT[NLOOKAT];                     /* Indexes of species to look at */
extern int MONITOR[NMONITOR];                   /* Indexes of species to monitor */
extern char * SPC_NAMES[NSPEC];                 /* Names of chemical species */
extern char * SMASS[NMASS];                     /* Names of atoms for mass balance */
extern char * EQN_NAMES[NREACT];                /* Equation names */
extern char * EQN_TAGS[NREACT];                 /* Equation tags */

/* INLINED global variable declarations                             */

/* INLINED global variable declarations                             */

