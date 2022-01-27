! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Initialization File
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
! File                 : small_f90_Initialize.f90
! Time                 : Thu Jan 27 14:18:18 2022
! Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_fortran_double
! Equation file        : small_f90.kpp
! Output root filename : small_f90
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



MODULE small_f90_Initialize

  USE small_f90_Parameters, ONLY: sp, dp, NVAR, NFIX
  IMPLICIT NONE

CONTAINS


! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Initialize - function to initialize concentrations
!   Arguments :
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SUBROUTINE Initialize ( )


  USE small_f90_Global

  INTEGER :: i
  REAL(kind=dp) :: x

  CFACTOR = 1.000000e+00_dp

  x = (0.)*CFACTOR
  DO i = 1, NVAR
    VAR(i) = x
  END DO

  x = (0.)*CFACTOR
  DO i = 1, NFIX
    FIX(i) = x
  END DO

  VAR(1) = (9.906E+01)*CFACTOR
  VAR(2) = (6.624E+08)*CFACTOR
  VAR(3) = (5.326E+11)*CFACTOR
  VAR(4) = (8.725E+08)*CFACTOR
  VAR(5) = (2.240E+08)*CFACTOR
  FIX(1) = (8.120E+16)*CFACTOR
  FIX(2) = (1.697E+16)*CFACTOR
! constant rate coefficients
! END constant rate coefficients

! INLINED initializations

        TSTART = (12*3600)
        TEND = TSTART + (3*24*3600)
        DT = 0.25*3600  
        TEMP = 270

! End INLINED initializations

      
END SUBROUTINE Initialize

! End of Initialize function
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



END MODULE small_f90_Initialize

