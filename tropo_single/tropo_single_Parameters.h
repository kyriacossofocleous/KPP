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
/* File                 : tropo_single_Parameters.h                 */
/* Time                 : Wed Mar  9 12:17:07 2022                  */
/* Working directory    : /home/kyriacos/CyprusInstitute/kpp/tropo_single */
/* Equation file        : tropo_single.kpp                          */
/* Output root filename : tropo_single                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#define NSPEC                88          /* Number of chemical species */
#define NVAR                 84          /* Number of Variable species */
#define NVARACT              74          /* Number of Active species */
#define NFIX                 4           /* Number of Fixed species */
#define NREACT               178         /* Number of reactions */
#define NVARST               0           /* Starting of variables in conc. vect. */
#define NFIXST               84          /* Starting of fixed in conc. vect. */
#define NONZERO              674         /* Number of nonzero entries in Jacobian */
#define LU_NONZERO           768         /* Number of nonzero entries in LU factoriz. of Jacobian */
#define CNVAR                85          /* (NVAR+1) Number of elements in compressed row format */
#define CNEQN                179         /* (NREACT+1) Number stoicm elements in compressed col format */
#define NHESS                548         /* Length of Sparse Hessian */
#define NLOOKAT              88          /* Number of species to look at */
#define NMONITOR             1           /* Number of species to monitor */
#define NMASS                1           /* Number of atoms to check mass balance */

/* Index declaration for variable species in C and VAR              */
/*   VAR(ind_spc) = C(ind_spc)                                      */

#define ind_SO4              0          
#define ind_ACTA             1          
#define ind_R3N2             2          
#define ind_SUCA             3          
#define ind_GLUA             4          
#define ind_ADIA             5          
#define ind_PRN2             6          
#define ind_PRPN             7          
#define ind_OZID             8          
#define ind_MSA              9          
#define ind_DOL6             10         
#define ind_DOL7             11         
#define ind_DOL8             12         
#define ind_CPET             13         
#define ind_CHEX             14         
#define ind_MACA             15         
#define ind_PYVA             16         
#define ind_DMS              17         
#define ind_C2H6             18         
#define ind_C3H8             19         
#define ind_MPAN             20         
#define ind_IPAN             21         
#define ind_H2O2             22         
#define ind_AROM             23         
#define ind_TPAN             24         
#define ind_N2O5             25         
#define ind_HONO             26         
#define ind_RAN2             27         
#define ind_CH4              28         
#define ind_ALKA             29         
#define ind_HNO4             30         
#define ind_PAN              31         
#define ind_ACO2             32         
#define ind_DIAL             33         
#define ind_GLYX             34         
#define ind_CRES             35         
#define ind_AHO2             36         
#define ind_RAN1             37         
#define ind_ZO2              38         
#define ind_ETHE             39         
#define ind_CO               40         
#define ind_MGLY             41         
#define ind_MAN2             42         
#define ind_TO2              43         
#define ind_HAC              44         
#define ind_R3O2             45         
#define ind_EO2              46         
#define ind_PO2              47         
#define ind_MRO2             48         
#define ind_MVN2             49         
#define ind_ETO2             50         
#define ind_PRN1             51         
#define ind_RIO2             52         
#define ind_TCO3             53         
#define ind_INO2             54         
#define ind_HACO             55         
#define ind_HNO3             56         
#define ind_MGGY             57         
#define ind_VRO2             58         
#define ind_ALKE             59         
#define ind_RAO2             60         
#define ind_KET              61         
#define ind_KO2              62         
#define ind_ISOP             63         
#define ind_MO2              64         
#define ind_MAO3             65         
#define ind_CRO2             66         
#define ind_MCRG             67         
#define ind_MVKO             68         
#define ind_MAOO             69         
#define ind_ROOH             70         
#define ind_MCO3             71         
#define ind_MACR             72         
#define ind_O3               73         
#define ind_MVK              74         
#define ind_NO2              75         
#define ind_HCHO             76         
#define ind_SO2              77         
#define ind_ALD2             78         
#define ind_CHO2             79         
#define ind_NO               80         
#define ind_HO2              81         
#define ind_NO3              82         
#define ind_OH               83         

/* Index declaration for fixed species in C                         */
/*   C(ind_spc)                                                     */

#define ind_O2               84         
#define ind_H2O              85         
#define ind_CO2              86         
#define ind_H2               87         

/* Index declaration for fixed species in FIX                       */
/*    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)                 */

#define indf_O2              0          
#define indf_H2O             1          
#define indf_CO2             2          
#define indf_H2              3          

#define NJVRP                316         /* Length of sparse Jacobian JVRP */

#define NSTOICM              645         /* Length of Sparse Stoichiometric Matrix */
