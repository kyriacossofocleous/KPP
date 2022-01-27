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
/* File                 : cbm4_Parameters.h                         */
/* Time                 : Thu Jan 27 11:36:40 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/cbm4   */
/* Equation file        : cbm4.kpp                                  */
/* Output root filename : cbm4                                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                33          /* Number of chemical species */
#define NVAR                 32          /* Number of Variable species */
#define NVARACT              32          /* Number of Active species */
#define NFIX                 1           /* Number of Fixed species */
#define NREACT               81          /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               32          /* Starting of fixed in conc. vect. */
#define NONZERO              276         /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           300         /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                33          /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                82          /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                258         /* Length of Sparse Hessian */
#define NLOOKAT              33          /* Number of species to look at */
#define NMONITOR             1           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_O1D              0          
#define ind_H2O2             1          
#define ind_PAN              2          
#define ind_CRO              3          
#define ind_TOL              4          
#define ind_N2O5             5          
#define ind_XYL              6          
#define ind_XO2N             7          
#define ind_HONO             8          
#define ind_PNA              9          
#define ind_TO2              10         
#define ind_HNO3             11         
#define ind_ROR              12         
#define ind_CRES             13         
#define ind_MGLY             14         
#define ind_CO               15         
#define ind_ETH              16         
#define ind_XO2              17         
#define ind_OPEN             18         
#define ind_PAR              19         
#define ind_HCHO             20         
#define ind_ISOP             21         
#define ind_OLE              22         
#define ind_ALD2             23         
#define ind_O3               24         
#define ind_NO2              25         
#define ind_OH               26         
#define ind_HO2              27         
#define ind_O                28         
#define ind_NO3              29         
#define ind_NO               30         
#define ind_C2O3             31         

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_H2O              32         

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_H2O             0          

#define NJVRP                134         /* Length of sparse Jacobian JVRP */

#define NSTOICM              329         /* Length of Sparse Stoichiometric Matrix */
