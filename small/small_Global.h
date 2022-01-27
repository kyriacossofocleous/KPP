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
/* File                 : small_Global.h                            */
/* Time                 : Thu Jan 27 10:53:53 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/small  */
/* Equation file        : small.kpp                                 */
/* Output root filename : small                                     */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




/* Declaration of global variables                                  */

extern double C[NSPEC];                         /* Concentration of all species */
  extern double * VAR;
  extern double * FIX;
extern double RCONST[NREACT];                   /* Rate constants (global) */
extern double TIME;                             /* Current integration time */
extern double SUN;                              /* Sunlight intensity between [0,1] */
extern double TEMP;                             /* Temperature */
extern double RTOLS;                            /* (scalar) Relative tolerance */
extern double TSTART;                           /* Integration start time */
extern double TEND;                             /* Integration end time */
extern double DT;                               /* Integration step */
extern double ATOL[NVAR];                       /* Absolute tolerance */
extern double RTOL[NVAR];                       /* Relative tolerance */
extern double STEPMIN;                          /* Lower bound for integration step */
extern double STEPMAX;                          /* Upper bound for integration step */
extern double CFACTOR;                          /* Conversion factor for concentration units */
extern int DDMTYPE;                             /* DDM sensitivity w.r.t.: 0=init.val., 1=params */
extern int LOOKAT[NLOOKAT];                     /* Indexes of species to look at */
extern int MONITOR[NMONITOR];                   /* Indexes of species to monitor */
extern char * SPC_NAMES[NSPEC];                 /* Names of chemical species */
extern char * SMASS[NMASS];                     /* Names of atoms for mass balance */
extern char * EQN_NAMES[NREACT];                /* Equation names */
extern char * EQN_TAGS[NREACT];                 /* Equation tags */

/* INLINED global variable declarations                             */

/* INLINED global variable declarations                             */
