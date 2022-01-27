/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Parameter Header File                                            */
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
/* File                 : chapman_Parameters.h                      */
/* Time                 : Thu Jan 27 11:36:43 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman */
/* Equation file        : chapman.kpp                               */
/* Output root filename : chapman                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                7           /* Number of chemical species */
#define NVAR                 5           /* Number of Variable species */
#define NVARACT              5           /* Number of Active species */
#define NFIX                 2           /* Number of Fixed species */
#define NREACT               10          /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               5           /* Starting of fixed in conc. vect. */
#define NONZERO              18          /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           19          /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                6           /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                11          /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                10          /* Length of Sparse Hessian */
#define NLOOKAT              7           /* Number of species to look at */
#define NMONITOR             6           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_O1D              0          
#define ind_O                1          
#define ind_O3               2          
#define ind_NO               3          
#define ind_NO2              4          

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_M                5          
#define ind_O2               6          

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_M               0          
#define indf_O2              1          

#define NJVRP                13          /* Length of sparse Jacobian JVRP */

#define NSTOICM              22          /* Length of Sparse Stoichiometric Matrix */
