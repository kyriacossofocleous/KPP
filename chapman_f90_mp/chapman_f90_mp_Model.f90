MODULE chapman_f90_mp_Model

!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!  Completely defines the model chapman_f90_mp
!    by using all the associated modules
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  USE chapman_f90_mp_Precision
  USE chapman_f90_mp_Parameters
  USE chapman_f90_mp_Global
  USE chapman_f90_mp_Function
  USE chapman_f90_mp_Integrator
  USE chapman_f90_mp_Rates
  USE chapman_f90_mp_Jacobian
  USE chapman_f90_mp_Hessian
  USE chapman_f90_mp_Stoichiom
  USE chapman_f90_mp_LinearAlgebra
  USE chapman_f90_mp_Monitor
  USE chapman_f90_mp_Util

END MODULE chapman_f90_mp_Model

