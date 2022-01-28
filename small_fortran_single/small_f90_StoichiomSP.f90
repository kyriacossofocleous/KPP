! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Sparse Stoichiometric Data Structures File
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
! File                 : small_f90_StoichiomSP.f90
! Time                 : Thu Jan 27 17:32:38 2022
! Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_fortran_single
! Equation file        : small_f90.kpp
! Output root filename : small_f90
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



MODULE small_f90_StoichiomSP

  USE small_f90_Precision
  PUBLIC
  SAVE


! Row-compressed sparse data for the Jacobian of reaction products JVRP

  INTEGER, PARAMETER, DIMENSION(11) :: CROW_JVRP = (/ &
       1,  1,  2,  3,  5,  6,  7,  9, 11, 13, 14 /)

  INTEGER, PARAMETER, DIMENSION(13) :: ICOL_JVRP = (/ &
       2,  3,  2,  3,  3,  1,  1,  3,  3,  4,  2,  5, &
       5 /)

  INTEGER, PARAMETER, DIMENSION(13) :: IROW_JVRP = (/ &
       2,  3,  4,  4,  5,  6,  7,  7,  8,  8,  9,  9, &
      10 /)



!  Stoichiometric Matrix in Compressed Column Sparse Format


  INTEGER, PARAMETER, DIMENSION(11) :: CCOL_STOICM = (/ &
       1,  2,  4,  6,  8, 10, 12, 14, 17, 20, 23 /)

  INTEGER, PARAMETER, DIMENSION(22) :: IROW_STOICM = (/ &
       2,  2,  3,  2,  3,  2,  3,  1,  3,  1,  2,  1, &
       3,  3,  4,  5,  2,  4,  5,  2,  4,  5 /)

  INTEGER, PARAMETER, DIMENSION(22) :: ICOL_STOICM = (/ &
       1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7, &
       7,  8,  8,  8,  9,  9,  9, 10, 10, 10 /)

  REAL(kind=sp), PARAMETER, DIMENSION(22) :: STOICM = (/ &
     2.000000e+00,-1.000000e+00,1.000000e+00,1.000000e+00,-1.000000e+00, &
     -1.000000e+00,-1.000000e+00,1.000000e+00,-1.000000e+00,-1.000000e+00, &
     1.000000e+00,-1.000000e+00,-1.000000e+00,-1.000000e+00,-1.000000e+00, &
     1.000000e+00,-1.000000e+00,1.000000e+00,-1.000000e+00,1.000000e+00, &
     1.000000e+00,-1.000000e+00 /)


END MODULE small_f90_StoichiomSP

