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
/* File                 : smog_mp_Parameters.h                      */
/* Time                 : Fri Sep  2 14:41:04 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/KPP/smog_mp */
/* Equation file        : smog_mp.kpp                               */
/* Output root filename : smog_mp                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                16          /* Number of chemical species */
#define NVAR                 12          /* Number of Variable species */
#define NVARACT              11          /* Number of Active species */
#define NFIX                 4           /* Number of Fixed species */
#define NREACT               12          /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               12          /* Starting of fixed in conc. vect. */
#define NONZERO              53          /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           59          /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                13          /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                13          /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                28          /* Length of Sparse Hessian */
#define NLOOKAT              16          /* Number of species to look at */
#define NMONITOR             1           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_HNO3             0          
#define ind_O                1          
#define ind_RH               2          
#define ind_RCOO2NO2         3          
#define ind_O3               4          
#define ind_HO2              5          
#define ind_RCOO2            6          
#define ind_RCHO             7          
#define ind_RO2              8          
#define ind_NO               9          
#define ind_NO2              10         
#define ind_OH               11         

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_H2O              12         
#define ind_O2               13         
#define ind_CO               14         
#define ind_CO2              15         

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_H2O             0          
#define indf_O2              1          
#define indf_CO              2          
#define indf_CO2             3          

#define NJVRP                20          /* Length of sparse Jacobian JVRP */

#define NSTOICM              39          /* Length of Sparse Stoichiometric Matrix */
