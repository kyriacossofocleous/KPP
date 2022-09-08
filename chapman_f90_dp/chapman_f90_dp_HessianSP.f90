! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Sparse Hessian Data Structures File
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
! File                 : chapman_f90_dp_HessianSP.f90
! Time                 : Thu Sep  8 14:11:20 2022
! Working directory    : /home/kyriacos/CyprusInstitute/KPP/chapman_f90_dp
! Equation file        : chapman_f90_dp.kpp
! Output root filename : chapman_f90_dp
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



MODULE chapman_f90_dp_HessianSP

  PUBLIC
  SAVE


! Hessian Sparse Data
! 

  INTEGER, PARAMETER, DIMENSION(8) :: IHESS_I = (/ &
       1,  1,  2,  2,  3,  3,  4,  4 /)

  INTEGER, PARAMETER, DIMENSION(8) :: IHESS_J = (/ &
       1,  1,  1,  2,  1,  2,  1,  2 /)

  INTEGER, PARAMETER, DIMENSION(8) :: IHESS_K = (/ &
       2,  4,  2,  3,  4,  3,  4,  3 /)


END MODULE chapman_f90_dp_HessianSP

