
C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      SUBROUTINE mexFunction( nlhs, plhs, nrhs, prhs )
C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C             Matlab Gateway for the Derivative Function Fun
C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      INTEGER nlhs, nrhs
      INTEGER plhs(*), prhs(*)
      INTEGER mxGetPr, mxCreateFull, mxGetM, mxgetN
      INTEGER VPtr, FPtr, RPtr, VdotPtr
      REAL*8 V(32), F(1), RCT(81)
      REAL*8 Vdot(32)

C Check for the right number of input arguments
      IF ( nrhs .ne. 3 ) THEN
         CALL mexErrMsgTxt('Fun requires 3 input vectors: 
     &V(32), F(1), RCT(81)')
      END IF 
C Check for the right number of output arguments
      IF ( nlhs .ne. 1 ) THEN
         CALL mexErrMsgTxt('Fun requires 1 output vector: 
     &Vdot(32)')
      END IF 

      plhs(1) = mxCreateDoubleMatrix(32,1,0)

      VPtr = mxGetPr(prhs(1))
      CALL mxCopyPtrToReal8(VPtr,V,32)
      
      FPtr = mxGetPr(prhs(2))
      CALL mxCopyPtrToReal8(FPtr,F,1)
      
      RPtr = mxGetPr(prhs(3))
      CALL mxCopyPtrToReal8(RPtr,RCT,81)

      VdotPtr = mxGetPr(plhs(1))

      CALL Fun( V, F, RCT, Vdot )

      CALL mxCopyReal8ToPtr(Vdot, VdotPtr, 32)

      RETURN 
      END
