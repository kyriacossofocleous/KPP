
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 SUBROUTINE mexFunction( nlhs, plhs, nrhs, prhs )
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!                 Matlab Gateway for the Derivative Function Fun
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 USE chapman_f90_mp_Model

      INTEGER nlhs, nrhs
      INTEGER plhs(*), prhs(*)
      INTEGER mxGetPr, mxCreateFull, mxGetM, mxgetN
      INTEGER VPtr, FPtr, RPtr, VdotPtr
      REAL(kind=sp) V(4), F(1), RCT(7)
      REAL(kind=sp) Vdot(4)

! Check for the right number of input arguments
      IF ( nrhs .ne. 3 ) THEN
         CALL mexErrMsgTxt('Fun requires 3 input vectors: &
     &V(4), F(1), RCT(7)')
      END IF 
! Check for the right number of output arguments
      IF ( nlhs .ne. 1 ) THEN
         CALL mexErrMsgTxt('Fun requires 1 output vector: &
     &Vdot(4)')
      END IF 

      plhs(1) = mxCreateDoubleMatrix(4,1,0)

      VPtr = mxGetPr(prhs(1))
      CALL mxCopyPtrToReal8(VPtr,V,4)
      
      FPtr = mxGetPr(prhs(2))
      CALL mxCopyPtrToReal8(FPtr,F,1)
      
      RPtr = mxGetPr(prhs(3))
      CALL mxCopyPtrToReal8(RPtr,RCT,7)

      VdotPtr = mxGetPr(plhs(1))

      CALL Fun( V, F, RCT, Vdot )

      CALL mxCopyReal8ToPtr(Vdot, VdotPtr, 4)

 END SUBROUTINE mexFunction
