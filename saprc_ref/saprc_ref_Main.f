C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Main Program File                                                
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
C File                 : saprc_ref_Main.f                          
C Time                 : Wed Mar  9 12:16:09 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc_ref
C Equation file        : saprc_ref.kpp                             
C Output root filename : saprc_ref                                 
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C MAIN - Main program - driver routine                             
C   Arguments :                                                    
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      PROGRAM driver

      INCLUDE 'saprc_ref_Parameters.h'
      INCLUDE 'saprc_ref_Global.h'

      REAL*8 DVAL(NSPEC)
      INTEGER i
  
C ---- TIME VARIABLES ------------------      

      TSTART = 0
      TEND = TSTART + 600
      DT = 60.
      TEMP = 298

      STEPMIN = 0.01
      STEPMAX = 900

      RTOLS = 1e-10
      DO i=1,NVAR
        RTOL(i) = RTOLS
        ATOL(i) = 1
      END DO
     
      CALL Initialize()

C ********** TIME LOOP *************************

      CALL InitSaveData()

      WRITE(6,990) (SPC_NAMES(MONITOR(i)), i=1,NMONITOR), 
     *             (SMASS(i), i=1,NMASS )
990   FORMAT('Done[%] Time[h] ',20(4X,A6))

      TIME = TSTART
      DO WHILE (TIME .lt. TEND)

        CALL GetMass( C, DVAL )
        WRITE(6,991) (TIME-TSTART)/(TEND-TSTART)*100, TIME/3600.,
     *               (C(MONITOR(i))/CFACTOR, i=1,NMONITOR),
     *               (DVAL(i)/CFACTOR, i=1,NMASS)
991   FORMAT(F6.1,'% ',F7.2,3X,20(E10.4,2X))

        CALL SaveData()

        CALL Update_SUN() 
        CALL Update_RCONST()

        CALL INTEGRATE( TIME, TIME+DT )

      END DO

      CALL GetMass( C, DVAL )
      WRITE(6,991) (TIME-TSTART)/(TEND-TSTART)*100, TIME/3600.,
     *               (C(MONITOR(i))/CFACTOR, i=1,NMONITOR),
     *               (DVAL(i)/CFACTOR, i=1,NMASS)

      CALL SaveData()

C *********** END TIME LOOP ********

      CALL CloseSaveData()

      open(75, file='reference.data')
      do i=1,74
        write(75,75) VAR(i)
      end do
75    FORMAT(100(E24.14,1X))      

      STOP
      END

C End of MAIN function                                             
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


