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
/* File                 : strato_single_Parameters.h                */
/* Time                 : Wed Mar  9 12:17:05 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_single */
/* Equation file        : strato_single.kpp                         */
/* Output root filename : strato_single                             */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                40          /* Number of chemical species */
#define NVAR                 34          /* Number of Variable species */
#define NVARACT              34          /* Number of Active species */
#define NFIX                 6           /* Number of Fixed species */
#define NREACT               109         /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               34          /* Starting of fixed in conc. vect. */
#define NONZERO              246         /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           280         /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                35          /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                110         /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                174         /* Length of Sparse Hessian */
#define NLOOKAT              40          /* Number of species to look at */
#define NMONITOR             1           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_CH3              0          
#define ind_Cl2              1          
#define ind_Cl2O2            2          
#define ind_ClOO             3          
#define ind_OClO             4          
#define ind_BrCl             5          
#define ind_HOBr             6          
#define ind_BrONO2           7          
#define ind_HCO              8          
#define ind_CH3O             9          
#define ind_O1D              10         
#define ind_N2O5             11         
#define ind_HBr              12         
#define ind_CH3OOH           13         
#define ind_HNO4             14         
#define ind_HCl              15         
#define ind_H2O2             16         
#define ind_HOCl             17         
#define ind_HNO3             18         
#define ind_H                19         
#define ind_CH3O2            20         
#define ind_ClONO2           21         
#define ind_NO3              22         
#define ind_CH2O             23         
#define ind_Br               24         
#define ind_OH               25         
#define ind_Cl               26         
#define ind_ClO              27         
#define ind_O3               28         
#define ind_NO               29         
#define ind_BrO              30         
#define ind_O                31         
#define ind_HO2              32         
#define ind_NO2              33         

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_H2O              34         
#define ind_H2               35         
#define ind_O2               36         
#define ind_N2               37         
#define ind_CH4              38         
#define ind_CO               39         

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_H2O             0          
#define indf_H2              1          
#define indf_O2              2          
#define indf_N2              3          
#define indf_CH4             4          
#define indf_CO              5          

#define NJVRP                161         /* Length of sparse Jacobian JVRP */

#define NSTOICM              310         /* Length of Sparse Stoichiometric Matrix */
