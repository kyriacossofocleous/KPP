C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Auxiliary Routines File                                          
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
C File                 : strato_ref_Util.f                         
C Time                 : Wed Mar  9 12:16:26 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_ref
C Equation file        : strato_ref.kpp                            
C Output root filename : strato_ref                                
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




C User INLINED Utility Functions                                   

C End INLINED Utility Functions                                    

C Utility Functions from KPP_HOME/util/util                        
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C UTIL - Utility functions                                         
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

C ****************************************************************
C                            
C InitSaveData - Opens the data file for writing
C   Parameters :                                                  
C
C ****************************************************************

      SUBROUTINE InitSaveData ()

      INCLUDE 'strato_ref_Parameters.h'

      open(10, file='strato_ref.dat')

      RETURN
      END

C End of InitSaveData function
C ****************************************************************

C ****************************************************************
C                            
C SaveData - Write LOOKAT species in the data file 
C   Parameters :                                                  
C
C ****************************************************************

      SUBROUTINE SaveData ()

      INCLUDE 'strato_ref_Parameters.h'
      INCLUDE 'strato_ref_Global.h'

      INTEGER i

      WRITE(10,999) (TIME-TSTART)/3600.D0,
     *              (C(LOOKAT(i))/CFACTOR, i=1,NLOOKAT)
999   FORMAT(E24.16E3,100(1X,E24.16E3))
      RETURN
      END

C End of SaveData function
C ****************************************************************

C ****************************************************************
C                            
C CloseSaveData - Close the data file 
C   Parameters :                                                  
C
C ****************************************************************

      SUBROUTINE CloseSaveData ()

      INCLUDE 'strato_ref_Parameters.h'

      CLOSE(10)

      RETURN
      END

C End of CloseSaveData function
C ****************************************************************

C ****************************************************************
C                            
C GenerateMatlab - Generates MATLAB file to load the data file 
C   Parameters : 
C                It will have a character string to prefix each 
C                species name with.                                                 
C
C ****************************************************************

      SUBROUTINE GenerateMatlab ( PREFIX )

      INCLUDE 'strato_ref_Parameters.h'
      INCLUDE 'strato_ref_Global.h'
      
      CHARACTER*8 PREFIX 
      INTEGER i

      open(20, file='strato_ref.m')
      write(20,*) 'load strato_ref.dat;'
      write(20,990) PREFIX
990   FORMAT(A1,'c = strato_ref;')
      write(20,*) 'clear strato_ref;'
      write(20,991) PREFIX, PREFIX
991   FORMAT(A1,'t=',A1,'c(:,1);')
      write(20,992) PREFIX
992   FORMAT(A1,'c(:,1)=[];')

      do i=1,NLOOKAT
        write(20,993) PREFIX, SPC_NAMES(LOOKAT(i)), PREFIX, i
993     FORMAT(A1,A6,' = ',A1,'c(:,',I2,');')
      end do
      
      CLOSE(20)

      RETURN
      END

C End of GenerateMatlab function
C ****************************************************************

C End Utility Functions from KPP_HOME/util/util                    
C End of UTIL function                                             
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Shuffle_user2kpp - function to copy concentrations from USER to KPP
C   Arguments :                                                    
C      V_USER    - Concentration of variable species in USER's order
C      V         - Concentrations of variable species (local)      
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Shuffle_user2kpp ( V_USER, V )

      IMPLICIT NONE
      INCLUDE 'strato_ref_Parameters.h'

C V_USER - Concentration of variable species in USER's order       
      REAL*8 V_USER(NVAR)
C V - Concentrations of variable species (local)                   
      REAL*8 V(NVAR)

      V(32) = V_USER(1)
      V(11) = V_USER(2)
      V(29) = V_USER(3)
      V(30) = V_USER(4)
      V(34) = V_USER(5)
      V(23) = V_USER(6)
      V(12) = V_USER(7)
      V(19) = V_USER(8)
      V(15) = V_USER(9)
      V(20) = V_USER(10)
      V(26) = V_USER(11)
      V(33) = V_USER(12)
      V(17) = V_USER(13)
      V(1) = V_USER(14)
      V(10) = V_USER(15)
      V(21) = V_USER(16)
      V(14) = V_USER(17)
      V(9) = V_USER(18)
      V(24) = V_USER(19)
      V(27) = V_USER(20)
      V(2) = V_USER(21)
      V(28) = V_USER(22)
      V(4) = V_USER(23)
      V(5) = V_USER(24)
      V(3) = V_USER(25)
      V(16) = V_USER(26)
      V(18) = V_USER(27)
      V(22) = V_USER(28)
      V(25) = V_USER(29)
      V(6) = V_USER(30)
      V(31) = V_USER(31)
      V(13) = V_USER(32)
      V(7) = V_USER(33)
      V(8) = V_USER(34)
      RETURN
      END

C End of Shuffle_user2kpp function                                 
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Shuffle_kpp2user - function to restore concentrations from KPP to USER
C   Arguments :                                                    
C      V         - Concentrations of variable species (local)      
C      V_USER    - Concentration of variable species in USER's order
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Shuffle_kpp2user ( V, V_USER )

      IMPLICIT NONE
      INCLUDE 'strato_ref_Parameters.h'

C V - Concentrations of variable species (local)                   
      REAL*8 V(NVAR)
C V_USER - Concentration of variable species in USER's order       
      REAL*8 V_USER(NVAR)

      V_USER(1) = V(32)
      V_USER(2) = V(11)
      V_USER(3) = V(29)
      V_USER(4) = V(30)
      V_USER(5) = V(34)
      V_USER(6) = V(23)
      V_USER(7) = V(12)
      V_USER(8) = V(19)
      V_USER(9) = V(15)
      V_USER(10) = V(20)
      V_USER(11) = V(26)
      V_USER(12) = V(33)
      V_USER(13) = V(17)
      V_USER(14) = V(1)
      V_USER(15) = V(10)
      V_USER(16) = V(21)
      V_USER(17) = V(14)
      V_USER(18) = V(9)
      V_USER(19) = V(24)
      V_USER(20) = V(27)
      V_USER(21) = V(2)
      V_USER(22) = V(28)
      V_USER(23) = V(4)
      V_USER(24) = V(5)
      V_USER(25) = V(3)
      V_USER(26) = V(16)
      V_USER(27) = V(18)
      V_USER(28) = V(22)
      V_USER(29) = V(25)
      V_USER(30) = V(6)
      V_USER(31) = V(31)
      V_USER(32) = V(13)
      V_USER(33) = V(7)
      V_USER(34) = V(8)
      RETURN
      END

C End of Shuffle_kpp2user function                                 
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C GetMass - compute total mass of selected atoms                   
C   Arguments :                                                    
C      CL        - Concentration of all species (local)            
C      Mass      - value of mass balance                           
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE GetMass ( CL, Mass )

      IMPLICIT NONE
      INCLUDE 'strato_ref_Parameters.h'

C CL - Concentration of all species (local)                        
      REAL*8 CL(NSPEC)
C Mass - value of mass balance                                     
      REAL*8 Mass(1)

      RETURN
      END

C End of GetMass function                                          
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


