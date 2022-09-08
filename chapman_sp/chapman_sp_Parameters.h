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
/* File                 : chapman_sp_Parameters.h                   */
/* Time                 : Fri Sep  2 14:40:34 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/chapman_sp */
/* Equation file        : chapman_sp.kpp                            */
/* Output root filename : chapman_sp                                */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                5           /* Number of chemical species */
#define NVAR                 4           /* Number of Variable species */
#define NVARACT              4           /* Number of Active species */
#define NFIX                 1           /* Number of Fixed species */
#define NREACT               7           /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               4           /* Starting of fixed in conc. vect. */
#define NONZERO              14          /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           15          /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                5           /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                8           /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                8           /* Length of Sparse Hessian */
#define NLOOKAT              5           /* Number of species to look at */
#define NMONITOR             5           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_O                0          
#define ind_O3               1          
#define ind_NO               2          
#define ind_NO2              3          

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_O2               4          

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_O2              0          

#define NJVRP                9           /* Length of sparse Jacobian JVRP */

#define NSTOICM              16          /* Length of Sparse Stoichiometric Matrix */
