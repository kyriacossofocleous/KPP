! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Parameter Module File
! 
! Generated by KPP-2.2.3 symbolic chemistry Kinetics PreProcessor
!       (http://www.cs.vt.edu/~asandu/Software/KPP)
! KPP is distributed under GPL, the general public licence
!       (http://www.gnu.org/copyleft/gpl.html)
! (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa
! (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech
!     With important contributions from:
!        M. Damian, Villanova University, USA
!        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany
! 
! File                 : chapman_f90_mp_Parameters.f90
! Time                 : Thu Sep  8 14:55:46 2022
! Working directory    : /home/kyriacos/CyprusInstitute/KPP/chapman_f90_mp
! Equation file        : chapman_f90_mp.kpp
! Output root filename : chapman_f90_mp
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



MODULE chapman_f90_mp_Parameters

  USE chapman_f90_mp_Precision
  PUBLIC
  SAVE


! NSPEC - Number of chemical species
  INTEGER, PARAMETER :: NSPEC = 5 
! NVAR - Number of Variable species
  INTEGER, PARAMETER :: NVAR = 4 
! NVARACT - Number of Active species
  INTEGER, PARAMETER :: NVARACT = 4 
! NFIX - Number of Fixed species
  INTEGER, PARAMETER :: NFIX = 1 
! NREACT - Number of reactions
  INTEGER, PARAMETER :: NREACT = 7 
! NVARST - Starting of variables in conc. vect.
  INTEGER, PARAMETER :: NVARST = 1 
! NFIXST - Starting of fixed in conc. vect.
  INTEGER, PARAMETER :: NFIXST = 5 
! NONZERO - Number of nonzero entries in Jacobian
  INTEGER, PARAMETER :: NONZERO = 14 
! LU_NONZERO - Number of nonzero entries in LU factoriz. of Jacobian
  INTEGER, PARAMETER :: LU_NONZERO = 15 
! CNVAR - (NVAR+1) Number of elements in compressed row format
  INTEGER, PARAMETER :: CNVAR = 5 
! CNEQN - (NREACT+1) Number stoicm elements in compressed col format
  INTEGER, PARAMETER :: CNEQN = 8 
! NHESS - Length of Sparse Hessian
  INTEGER, PARAMETER :: NHESS = 8 
! NLOOKAT - Number of species to look at
  INTEGER, PARAMETER :: NLOOKAT = 5 
! NMONITOR - Number of species to monitor
  INTEGER, PARAMETER :: NMONITOR = 5 
! NMASS - Number of atoms to check mass balance
  INTEGER, PARAMETER :: NMASS = 1 

! Index declaration for variable species in C and VAR
!   VAR(ind_spc) = C(ind_spc)

  INTEGER, PARAMETER :: ind_O = 1 
  INTEGER, PARAMETER :: ind_O3 = 2 
  INTEGER, PARAMETER :: ind_NO = 3 
  INTEGER, PARAMETER :: ind_NO2 = 4 

! Index declaration for fixed species in C
!   C(ind_spc)

  INTEGER, PARAMETER :: ind_O2 = 5 

! Index declaration for fixed species in FIX
!    FIX(indf_spc) = C(ind_spc) = C(NVAR+indf_spc)

  INTEGER, PARAMETER :: indf_O2 = 1 

! NJVRP - Length of sparse Jacobian JVRP
  INTEGER, PARAMETER :: NJVRP = 9 

! NSTOICM - Length of Sparse Stoichiometric Matrix
  INTEGER, PARAMETER :: NSTOICM = 16 

END MODULE chapman_f90_mp_Parameters

