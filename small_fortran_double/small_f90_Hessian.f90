! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Hessian File
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
! File                 : small_f90_Hessian.f90
! Time                 : Thu Jan 27 14:18:18 2022
! Working directory    : /home/kyriacos/CyprusInstitute/kpp/small_fortran_double
! Equation file        : small_f90.kpp
! Output root filename : small_f90
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



MODULE small_f90_Hessian

  USE small_f90_Parameters
  USE small_f90_HessianSP

  IMPLICIT NONE

CONTAINS


! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Hessian - function for Hessian (Jac derivative w.r.t. variables)
!   Arguments :
!      V         - Concentrations of variable species (local)
!      F         - Concentrations of fixed species (local)
!      RCT       - Rate constants (local)
!      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SUBROUTINE Hessian ( V, F, RCT, HESS )

! V - Concentrations of variable species (local)
  REAL(kind=dp) :: V(NVAR)
! F - Concentrations of fixed species (local)
  REAL(kind=dp) :: F(NFIX)
! RCT - Rate constants (local)
  REAL(kind=dp) :: RCT(NREACT)
! HESS - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
  REAL(kind=dp) :: HESS(NHESS)

! --------------------------------------------------------
! Note: HESS is represented in coordinate sparse format:
!       HESS(m) = d^2 f_i / dv_j dv_k = d Jac_{i,j} / dv_k
!       where i = IHESS_I(m), j = IHESS_J(m), k = IHESS_K(m).
! --------------------------------------------------------
! Note: d^2 f_i / dv_j dv_k = d^2 f_i / dv_k dv_j,
!       therefore only the terms d^2 f_i / dv_j dv_k
!       with j <= k are computed and stored in HESS.
! --------------------------------------------------------

! Local variables
! D2A - Second derivatives of equation rates
  REAL(kind=dp) :: D2A(4)

! Computation of the second derivatives of equation rates
! D2A(1) = d^2 A(4) / dV(2)dV(3)
  D2A(1) = RCT(4)
! D2A(2) = d^2 A(7) / dV(1)dV(3)
  D2A(2) = RCT(7)
! D2A(3) = d^2 A(8) / dV(3)dV(4)
  D2A(3) = RCT(8)
! D2A(4) = d^2 A(9) / dV(2)dV(5)
  D2A(4) = RCT(9)

! Computation of the Jacobian derivative
! HESS(1) = d^2 Vdot(1)/{dV(1)dV(3)} = d^2 Vdot(1)/{dV(3)dV(1)}
  HESS(1) = -D2A(2)
! HESS(2) = d^2 Vdot(2)/{dV(2)dV(3)} = d^2 Vdot(2)/{dV(3)dV(2)}
  HESS(2) = -D2A(1)
! HESS(3) = d^2 Vdot(2)/{dV(2)dV(5)} = d^2 Vdot(2)/{dV(5)dV(2)}
  HESS(3) = -D2A(4)
! HESS(4) = d^2 Vdot(3)/{dV(1)dV(3)} = d^2 Vdot(3)/{dV(3)dV(1)}
  HESS(4) = -D2A(2)
! HESS(5) = d^2 Vdot(3)/{dV(2)dV(3)} = d^2 Vdot(3)/{dV(3)dV(2)}
  HESS(5) = -D2A(1)
! HESS(6) = d^2 Vdot(3)/{dV(3)dV(4)} = d^2 Vdot(3)/{dV(4)dV(3)}
  HESS(6) = -D2A(3)
! HESS(7) = d^2 Vdot(4)/{dV(2)dV(5)} = d^2 Vdot(4)/{dV(5)dV(2)}
  HESS(7) = D2A(4)
! HESS(8) = d^2 Vdot(4)/{dV(3)dV(4)} = d^2 Vdot(4)/{dV(4)dV(3)}
  HESS(8) = -D2A(3)
! HESS(9) = d^2 Vdot(5)/{dV(2)dV(5)} = d^2 Vdot(5)/{dV(5)dV(2)}
  HESS(9) = -D2A(4)
! HESS(10) = d^2 Vdot(5)/{dV(3)dV(4)} = d^2 Vdot(5)/{dV(4)dV(3)}
  HESS(10) = D2A(3)
      
END SUBROUTINE Hessian

! End of Hessian function
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! HessTR_Vec - Hessian transposed times user vectors
!   Arguments :
!      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
!      U1        - User vector
!      U2        - User vector
!      HTU       - Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SUBROUTINE HessTR_Vec ( HESS, U1, U2, HTU )

! HESS - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
  REAL(kind=dp) :: HESS(NHESS)
! U1 - User vector
  REAL(kind=dp) :: U1(NVAR)
! U2 - User vector
  REAL(kind=dp) :: U2(NVAR)
! HTU - Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2
  REAL(kind=dp) :: HTU(NVAR)

! Compute the vector HTU =(Hess x U2)^T * U1 = d (Jac^T*U1)/d Var * U2
  HTU(1) = HESS(1)*(U1(1)*U2(3))+HESS(4)*(U1(3)*U2(3))
  HTU(2) = HESS(2)*(U1(2)*U2(3))+HESS(3)*(U1(2)*U2(5))+HESS(5)*(U1(3)*U2(3))+HESS(7)*(U1(4)*U2(5))+HESS(9)*(U1(5)*U2(5))
  HTU(3) = HESS(1)*(U1(1)*U2(1))+HESS(2)*(U1(2)*U2(2))+HESS(4)*(U1(3)*U2(1))+HESS(5)*(U1(3)*U2(2))+HESS(6)*(U1(3)*U2(4))&
             &+HESS(8)*(U1(4)*U2(4))+HESS(10)*(U1(5)*U2(4))
  HTU(4) = HESS(6)*(U1(3)*U2(3))+HESS(8)*(U1(4)*U2(3))+HESS(10)*(U1(5)*U2(3))
  HTU(5) = HESS(3)*(U1(2)*U2(2))+HESS(7)*(U1(4)*U2(2))+HESS(9)*(U1(5)*U2(2))
      
END SUBROUTINE HessTR_Vec

! End of HessTR_Vec function
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Hess_Vec - Hessian times user vectors
!   Arguments :
!      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
!      U1        - User vector
!      U2        - User vector
!      HU        - Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SUBROUTINE Hess_Vec ( HESS, U1, U2, HU )

! HESS - Hessian of Var (i.e. the 3-tensor d Jac / d Var)
  REAL(kind=dp) :: HESS(NHESS)
! U1 - User vector
  REAL(kind=dp) :: U1(NVAR)
! U2 - User vector
  REAL(kind=dp) :: U2(NVAR)
! HU - Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2
  REAL(kind=dp) :: HU(NVAR)

! Compute the vector HU =(Hess x U2) * U1 = d (Jac*U1)/d Var * U2
  HU(1) = HESS(1)*(U1(1)*U2(3))+HESS(1)*(U1(3)*U2(1))
  HU(2) = HESS(2)*(U1(2)*U2(3))+HESS(2)*(U1(3)*U2(2))+HESS(3)*(U1(2)*U2(5))+HESS(3)*(U1(5)*U2(2))
  HU(3) = HESS(4)*(U1(1)*U2(3))+HESS(4)*(U1(3)*U2(1))+HESS(5)*(U1(2)*U2(3))+HESS(5)*(U1(3)*U2(2))+HESS(6)*(U1(3)*U2(4))&
            &+HESS(6)*(U1(4)*U2(3))
  HU(4) = HESS(7)*(U1(2)*U2(5))+HESS(7)*(U1(5)*U2(2))+HESS(8)*(U1(3)*U2(4))+HESS(8)*(U1(4)*U2(3))
  HU(5) = HESS(9)*(U1(2)*U2(5))+HESS(9)*(U1(5)*U2(2))+HESS(10)*(U1(3)*U2(4))+HESS(10)*(U1(4)*U2(3))
      
END SUBROUTINE Hess_Vec

! End of Hess_Vec function
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



END MODULE small_f90_Hessian

