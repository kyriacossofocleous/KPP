MODULE chapman_f90_dp_Model

!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!  Completely defines the model chapman_f90_dp
!    by using all the associated modules
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  USE chapman_f90_dp_Precision
  USE chapman_f90_dp_Parameters
  USE chapman_f90_dp_Global
  USE chapman_f90_dp_Function
  USE chapman_f90_dp_Integrator
  USE chapman_f90_dp_Rates
  USE chapman_f90_dp_Jacobian
  USE chapman_f90_dp_Hessian
  USE chapman_f90_dp_Stoichiom
  USE chapman_f90_dp_LinearAlgebra
  USE chapman_f90_dp_Monitor
  USE chapman_f90_dp_Util

END MODULE chapman_f90_dp_Model

