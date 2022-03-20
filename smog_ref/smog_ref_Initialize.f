C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Initialization File                                              
C                                                                  
C Generated by KPP-2.2.3 symbolic chemistry Kinetics PreProcessor  
C       (http://www.cs.vt.edu/~asandu/Software/KPP)                
C KPP is distributed under GPL, the general public licence         
C       (http://www.gnu.org/copyleft/gpl.html)                     
C (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa           
C (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech            
C     With important contributions from:                           
C        M. Damian, Villanova University, USA                      
C        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany
C                                                                  
C File                 : smog_ref_Initialize.f                     
C Time                 : Fri Mar 18 18:12:32 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/smog_ref
C Equation file        : smog_ref.kpp                              
C Output root filename : smog_ref                                  
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Initialize - function to initialize concentrations               
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Initialize ( )

      IMPLICIT NONE
      INCLUDE 'smog_ref_Parameters.h'


      INCLUDE 'smog_ref_Global.h'
      INTEGER i
      REAL*8 x

      CFACTOR = 1.000000d+00

      x = (1.0E-8)*CFACTOR
      DO i = 1, NVAR
        VAR(i) = x
      END DO

      x = (1.0E-8)*CFACTOR
      DO i = 1, NFIX
        FIX(i) = x
      END DO

      VAR(3) = (2.0)*CFACTOR
      VAR(8) = (2.0)*CFACTOR
      VAR(10) = (0.5)*CFACTOR
      VAR(11) = (0.1)*CFACTOR
      FIX(1) = (1.3E+4)*CFACTOR
      FIX(2) = (2.0E+5)*CFACTOR
C constant rate coefficients                                       
      RCONST(2) = 2.183e-05
      RCONST(3) = 26.59
      RCONST(4) = 3775
      RCONST(5) = 23410
      RCONST(7) = 12140
      RCONST(8) = 11270
      RCONST(9) = 11270
      RCONST(10) = 16130
      RCONST(11) = 6893
      RCONST(12) = 0.02143
C END constant rate coefficients                                   

C INLINED initializations                                          

	TSTART = 0
	TEND = TSTART + 600
	DT = 60.0
        TEMP = 298

        STEPMIN=0.0001
        STEPMAX=3600.
        STEPSTART=STEPMIN

C End INLINED initializations                                      

      RETURN
      END

C End of Initialize function                                       
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


