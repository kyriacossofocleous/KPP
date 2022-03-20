C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C The Reaction Rates File                                          
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
C File                 : smog_ref_Rates.f                          
C Time                 : Fri Mar 18 18:12:32 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/smog_ref
C Equation file        : smog_ref.kpp                              
C Output root filename : smog_ref                                  
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




C Begin Rate Law Functions from KPP_HOME/util/UserRateLaws         

C  User-defined Rate Law functions
C  Note: the default argument type for rate laws, as read from the equations file, is single precision
C        but all the internal calculations are performed in REAL*8

C Arrhenius
      REAL*8 FUNCTION ARR( A0,B0,C0 )
      INCLUDE 'smog_ref_Parameters.h'
      INCLUDE 'smog_ref_Global.h'
                 
      REAL A0,B0,C0      
      ARR =  DBLE(A0) * EXP(-DBLE(B0)/TEMP) * (TEMP/300.0D0)**DBLE(C0)   
           
      RETURN
      END           


C Simplified Arrhenius, with two arguments
C Note: The argument B0 has a changed sign when compared to ARR
      REAL*8 FUNCTION ARR2( A0,B0 )
      INCLUDE 'smog_ref_Parameters.h'
      INCLUDE 'smog_ref_Global.h'
                 
      REAL A0,B0     
      ARR2 =  DBLE(A0) * EXP( DBLE(B0)/TEMP )   
           
      RETURN
      END           

      REAL*8 FUNCTION EP2(A0,C0,A2,C2,A3,C3)
      INCLUDE 'smog_ref_Parameters.h'                       
      INCLUDE 'smog_ref_Global.h'
      
      REAL A0,C0,A2,C2,A3,C3
      REAL*8 K0,K2,K3
      
      K0 = DBLE(A0) * EXP(-DBLE(C0)/TEMP)
      K2 = DBLE(A2) * EXP(-DBLE(C2)/TEMP)
      K3 = DBLE(A3) * EXP(-DBLE(C3)/TEMP)
      K3 = K3*CFACTOR*1.0d6
      EP2 = K0 + K3/(1.0d0+K3/K2 )
        
      RETURN
      END  


      REAL*8 FUNCTION EP3(A1,C1,A2,C2) 
      INCLUDE 'smog_ref_Parameters.h'               
      INCLUDE 'smog_ref_Global.h'
      
      REAL A1, C1, A2, C2
      REAL*8 K1, K2
      
      K1 = DBLE(A1) * EXP(-DBLE(C1)/TEMP)
      K2 = DBLE(A2) * EXP(-DBLE(C2)/TEMP)
      EP3 = K1 + K2*(1.0d6*CFACTOR)
      
      RETURN
      END    


      REAL*8 FUNCTION FALL ( A0,B0,C0,A1,B1,C1,CF)
      INCLUDE 'smog_ref_Parameters.h'                      
      INCLUDE 'smog_ref_Global.h'
      
      REAL A0,B0,C0,A1,B1,C1,CF
      REAL*8 K0, K1
      
      K0 = DBLE(A0) * EXP(-DBLE(B0)/TEMP)* (TEMP/300.0D0)**DBLE(C0)
      K1 = DBLE(A1) * EXP(-DBLE(B1)/TEMP)* (TEMP/300.0D0)**DBLE(C1)
      K0 = K0*CFACTOR*1.0D6
      K1 = K0/K1
      FALL = (K0/(1.0d0+K1))*
     *      DBLE(CF)**(1.0d0/(1.0d0+(DLOG10(K1))**2))
        
      RETURN
      END

C End Rate Law Functions from KPP_HOME/util/UserRateLaws           


C Begin INLINED Rate Law Functions                                 


C End INLINED Rate Law Functions                                   

C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Update_SUN - update SUN light using TIME                         
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Update_SUN()

      IMPLICIT NONE
      INCLUDE 'smog_ref_Parameters.h'
      INCLUDE 'smog_ref_Global.h'

      REAL*8 SunRise, SunSet
      REAL*8 Thour, Tlocal, Ttmp, PI
      PARAMETER (PI = 3.14159265358979d0) 
   
      SunRise = 4.5
      SunSet  = 19.5
      Thour = TIME/3600.
      Tlocal = Thour - (INT(Thour)/24)*24

      IF ((Tlocal.GE.SunRise).AND.(Tlocal.LE.SunSet)) THEN
        Ttmp = (2.0*Tlocal-SunRise-SunSet)/(SunSet-SunRise)
        IF (Ttmp.GT.0) THEN
          Ttmp =  Ttmp*Ttmp
        ELSE
          Ttmp = -Ttmp*Ttmp
        END IF
        SUN = ( 1.0 + COS(PI*Ttmp) )/2.0 
      ELSE
        SUN = 0.0
      END IF

      RETURN
      END

C End of Update_SUN function                                       
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Update_RCONST - function to update rate constants                
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Update_RCONST ( )

      IMPLICIT NONE
      INCLUDE 'smog_ref_Parameters.h'


      INCLUDE 'smog_ref_Global.h'
C  Definitions for User-defined Rate Law functions
C  To be inserted in funcions that call rate laws

      REAL*8 ARR, ARR2
      REAL*8 EP2, EP3, FALL
      EXTERNAL ARR, ARR2, EP2, EP3, FALL


C Begin INLINED RCONST                                             


C End INLINED RCONST                                               

      RCONST(1) = (0.533)
      RCONST(6) = (1.91E-4)
      RETURN
      END

C End of Update_RCONST function                                    
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Update_PHOTO - function to update photolytical rate constants    
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Update_PHOTO ( )

      IMPLICIT NONE
      INCLUDE 'smog_ref_Parameters.h'


      INCLUDE 'smog_ref_Global.h'

      RCONST(1) = (0.533)
      RCONST(6) = (1.91E-4)
      RETURN
      END

C End of Update_PHOTO function                                     
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


