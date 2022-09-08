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
C File                 : tropo_ref_Util.f                          
C Time                 : Fri Sep  2 14:40:09 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/KPP/tropo_ref
C Equation file        : tropo_ref.kpp                             
C Output root filename : tropo_ref                                 
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

      INCLUDE 'tropo_ref_Parameters.h'

      open(10, file='tropo_ref.dat')

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

      INCLUDE 'tropo_ref_Parameters.h'
      INCLUDE 'tropo_ref_Global.h'

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

      INCLUDE 'tropo_ref_Parameters.h'

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

      INCLUDE 'tropo_ref_Parameters.h'
      INCLUDE 'tropo_ref_Global.h'
      
      CHARACTER*8 PREFIX 
      INTEGER i

      open(20, file='tropo_ref.m')
      write(20,*) 'load tropo_ref.dat;'
      write(20,990) PREFIX
990   FORMAT(A1,'c = tropo_ref;')
      write(20,*) 'clear tropo_ref;'
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
C ****************************************************************C End Utility Functions from KPP_HOME/util/util                    
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
      INCLUDE 'tropo_ref_Parameters.h'

C V_USER - Concentration of variable species in USER's order       
      REAL*8 V_USER(NVAR)
C V - Concentrations of variable species (local)                   
      REAL*8 V(NVAR)

      V(81) = V_USER(1)
      V(76) = V_USER(2)
      V(57) = V_USER(3)
      V(78) = V_USER(5)
      V(1) = V_USER(6)
      V(74) = V_USER(7)
      V(29) = V_USER(8)
      V(19) = V_USER(9)
      V(20) = V_USER(10)
      V(30) = V_USER(11)
      V(40) = V_USER(12)
      V(60) = V_USER(13)
      V(24) = V_USER(14)
      V(33) = V_USER(15)
      V(2) = V_USER(16)
      V(77) = V_USER(17)
      V(79) = V_USER(18)
      V(23) = V_USER(19)
      V(71) = V_USER(20)
      V(27) = V_USER(21)
      V(32) = V_USER(22)
      V(25) = V_USER(23)
      V(62) = V_USER(24)
      V(36) = V_USER(25)
      V(34) = V_USER(26)
      V(35) = V_USER(27)
      V(42) = V_USER(28)
      V(3) = V_USER(31)
      V(38) = V_USER(32)
      V(28) = V_USER(33)
      V(26) = V_USER(34)
      V(31) = V_USER(35)
      V(83) = V_USER(36)
      V(64) = V_USER(37)
      V(75) = V_USER(38)
      V(73) = V_USER(39)
      V(45) = V_USER(40)
      V(58) = V_USER(41)
      V(21) = V_USER(42)
      V(22) = V_USER(43)
      V(55) = V_USER(44)
      V(43) = V_USER(45)
      V(50) = V_USER(46)
      V(16) = V_USER(47)
      V(17) = V_USER(48)
      V(11) = V_USER(49)
      V(12) = V_USER(50)
      V(13) = V_USER(51)
      V(14) = V_USER(52)
      V(15) = V_USER(53)
      V(4) = V_USER(54)
      V(5) = V_USER(55)
      V(6) = V_USER(56)
      V(7) = V_USER(57)
      V(8) = V_USER(58)
      V(9) = V_USER(59)
      V(18) = V_USER(60)
      V(10) = V_USER(61)
      V(41) = V_USER(62)
      V(84) = V_USER(63)
      V(82) = V_USER(64)
      V(37) = V_USER(65)
      V(72) = V_USER(66)
      V(65) = V_USER(67)
      V(51) = V_USER(68)
      V(63) = V_USER(69)
      V(46) = V_USER(70)
      V(61) = V_USER(71)
      V(44) = V_USER(72)
      V(54) = V_USER(73)
      V(39) = V_USER(74)
      V(47) = V_USER(75)
      V(48) = V_USER(76)
      V(80) = V_USER(77)
      V(67) = V_USER(78)
      V(52) = V_USER(79)
      V(53) = V_USER(80)
      V(59) = V_USER(81)
      V(66) = V_USER(82)
      V(49) = V_USER(83)
      V(56) = V_USER(84)
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
      INCLUDE 'tropo_ref_Parameters.h'

C V - Concentrations of variable species (local)                   
      REAL*8 V(NVAR)
C V_USER - Concentration of variable species in USER's order       
      REAL*8 V_USER(NVAR)

      V_USER(1) = V(81)
      V_USER(2) = V(76)
      V_USER(3) = V(57)
      V_USER(5) = V(78)
      V_USER(6) = V(1)
      V_USER(7) = V(74)
      V_USER(8) = V(29)
      V_USER(9) = V(19)
      V_USER(10) = V(20)
      V_USER(11) = V(30)
      V_USER(12) = V(40)
      V_USER(13) = V(60)
      V_USER(14) = V(24)
      V_USER(15) = V(33)
      V_USER(16) = V(2)
      V_USER(17) = V(77)
      V_USER(18) = V(79)
      V_USER(19) = V(23)
      V_USER(20) = V(71)
      V_USER(21) = V(27)
      V_USER(22) = V(32)
      V_USER(23) = V(25)
      V_USER(24) = V(62)
      V_USER(25) = V(36)
      V_USER(26) = V(34)
      V_USER(27) = V(35)
      V_USER(28) = V(42)
      V_USER(31) = V(3)
      V_USER(32) = V(38)
      V_USER(33) = V(28)
      V_USER(34) = V(26)
      V_USER(35) = V(31)
      V_USER(36) = V(83)
      V_USER(37) = V(64)
      V_USER(38) = V(75)
      V_USER(39) = V(73)
      V_USER(40) = V(45)
      V_USER(41) = V(58)
      V_USER(42) = V(21)
      V_USER(43) = V(22)
      V_USER(44) = V(55)
      V_USER(45) = V(43)
      V_USER(46) = V(50)
      V_USER(47) = V(16)
      V_USER(48) = V(17)
      V_USER(49) = V(11)
      V_USER(50) = V(12)
      V_USER(51) = V(13)
      V_USER(52) = V(14)
      V_USER(53) = V(15)
      V_USER(54) = V(4)
      V_USER(55) = V(5)
      V_USER(56) = V(6)
      V_USER(57) = V(7)
      V_USER(58) = V(8)
      V_USER(59) = V(9)
      V_USER(60) = V(18)
      V_USER(61) = V(10)
      V_USER(62) = V(41)
      V_USER(63) = V(84)
      V_USER(64) = V(82)
      V_USER(65) = V(37)
      V_USER(66) = V(72)
      V_USER(67) = V(65)
      V_USER(68) = V(51)
      V_USER(69) = V(63)
      V_USER(70) = V(46)
      V_USER(71) = V(61)
      V_USER(72) = V(44)
      V_USER(73) = V(54)
      V_USER(74) = V(39)
      V_USER(75) = V(47)
      V_USER(76) = V(48)
      V_USER(77) = V(80)
      V_USER(78) = V(67)
      V_USER(79) = V(52)
      V_USER(80) = V(53)
      V_USER(81) = V(59)
      V_USER(82) = V(66)
      V_USER(83) = V(49)
      V_USER(84) = V(56)
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
      INCLUDE 'tropo_ref_Parameters.h'

C CL - Concentration of all species (local)                        
      REAL*8 CL(NSPEC)
C Mass - value of mass balance                                     
      REAL*8 Mass(1)

      RETURN
      END

C End of GetMass function                                          
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


