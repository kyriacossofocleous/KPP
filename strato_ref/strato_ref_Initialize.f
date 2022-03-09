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
C File                 : strato_ref_Initialize.f                   
C Time                 : Wed Mar  9 11:42:03 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/strato_ref
C Equation file        : strato_ref.kpp                            
C Output root filename : strato_ref                                
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
      INCLUDE 'strato_ref_Parameters.h'


      INCLUDE 'strato_ref_Global.h'
      INTEGER i
      REAL*8 x

      CFACTOR = 8.120000d+16

      x = (0.)*CFACTOR
      DO i = 1, NVAR
        VAR(i) = x
      END DO

      x = (0.)*CFACTOR
      DO i = 1, NFIX
        FIX(i) = x
      END DO

      VAR(1) = (3.984427E-17)*CFACTOR
      VAR(2) = (8.665679E-14)*CFACTOR
      VAR(3) = (7.103997E-14)*CFACTOR
      VAR(4) = (2.659306E-15)*CFACTOR
      VAR(5) = (7.193558E-14)*CFACTOR
      VAR(6) = (5.843046E-14)*CFACTOR
      VAR(7) = (5.066596E-12)*CFACTOR
      VAR(8) = (9.405408E-14)*CFACTOR
      VAR(9) = (3.010774E-19)*CFACTOR
      VAR(10) = (2.496504E-15)*CFACTOR
      VAR(11) = (2.773328E-15)*CFACTOR
      VAR(12) = (6.905712E-12)*CFACTOR
      VAR(13) = (4.349534E-13)*CFACTOR
      VAR(14) = (4.587317E-12)*CFACTOR
      VAR(15) = (3.827485E-12)*CFACTOR
      VAR(16) = (2.157657E-09)*CFACTOR
      VAR(17) = (7.227409E-11)*CFACTOR
      VAR(18) = (2.196369E-10)*CFACTOR
      VAR(19) = (3.486344E-10)*CFACTOR
      VAR(20) = (4.190815E-14)*CFACTOR
      VAR(21) = (5.130799E-12)*CFACTOR
      VAR(22) = (2.166934E-11)*CFACTOR
      VAR(23) = (5.667175E-14)*CFACTOR
      VAR(24) = (9.913988E-11)*CFACTOR
      VAR(25) = (4.025093E-12)*CFACTOR
      VAR(26) = (2.041165E-10)*CFACTOR
      VAR(27) = (8.756027E-12)*CFACTOR
      VAR(28) = (1.011874E-09)*CFACTOR
      VAR(29) = (6.560000E-06)*CFACTOR
      VAR(30) = (1.074516E-08)*CFACTOR
      VAR(31) = (1.132088E-11)*CFACTOR
      VAR(32) = (8.158574E-09)*CFACTOR
      VAR(33) = (1.439703E-10)*CFACTOR
      VAR(34) = (2.758840E-09)*CFACTOR
      FIX(1) = (6.100000E-06)*CFACTOR
      FIX(2) = (3.700000E-07)*CFACTOR
      FIX(3) = (0.209)*CFACTOR
      FIX(4) = (0.781)*CFACTOR
      FIX(5) = (4.900000E-07)*CFACTOR
      FIX(6) = (2.000000E-08)*CFACTOR
C constant rate coefficients                                       
      RCONST(1) = 8.01822e-17
      RCONST(2) = 1.57571e-15
      RCONST(3) = 2.83887e-11
      RCONST(4) = 4.27631e-11
      RCONST(5) = 1.2e-10
      RCONST(6) = 2.2e-10
      RCONST(7) = 1e-10
      RCONST(8) = 7.5e-12
      RCONST(9) = 1.425e-10
      RCONST(10) = 6.35388e-15
      RCONST(11) = 1.99835e-11
      RCONST(12) = 1.38892e-15
      RCONST(13) = 3.25993e-14
      RCONST(14) = 3.61646e-11
      RCONST(15) = 1.55427e-12
      RCONST(16) = 6.86894e-11
      RCONST(17) = 1.38667e-15
      RCONST(18) = 7e-11
      RCONST(19) = 1.35192e-10
      RCONST(20) = 2.76946e-12
      RCONST(21) = 3.51541e-29
      RCONST(22) = 1.4948e-12
      RCONST(23) = 6.06249e-15
      RCONST(24) = 1.04211e-11
      RCONST(25) = 1.0685e-11
      RCONST(26) = 4.69913e-18
      RCONST(27) = 3.72413e-13
      RCONST(28) = 2.69029e-14
      RCONST(29) = 1e-11
      RCONST(30) = 3.03315e-11
      RCONST(31) = 2.32597e-13
      RCONST(32) = 1.40599e-06
      RCONST(33) = 1.89006e-13
      RCONST(34) = 6.27341e-12
      RCONST(35) = 3.1633e-07
      RCONST(36) = 0
      RCONST(37) = 3.03268e-16
      RCONST(38) = 9.87868e-12
      RCONST(39) = 2.6969e-15
      RCONST(40) = 3.63979e-11
      RCONST(41) = 6.35777e-12
      RCONST(42) = 1.89901e-13
      RCONST(43) = 4.00904e-11
      RCONST(44) = 1.80823e-11
      RCONST(45) = 0
      RCONST(46) = 8.71828e-12
      RCONST(47) = 2.12738e-11
      RCONST(48) = 2.88645e-14
      RCONST(49) = 1.20131e-15
      RCONST(50) = 1.17478e-15
      RCONST(51) = 1.37988e-15
      RCONST(52) = 3.33034e-15
      RCONST(53) = 16948.7
      RCONST(54) = 0.000477396
      RCONST(55) = 6.10068e-13
      RCONST(56) = 3.78181e-13
      RCONST(57) = 1.05517e-13
      RCONST(58) = 3.02111e-13
      RCONST(59) = 1.31924e-11
      RCONST(60) = 0
      RCONST(61) = 6.18551e-13
      RCONST(62) = 1.24964e-12
      RCONST(63) = 6.18551e-13
      RCONST(64) = 4.99054e-11
      RCONST(65) = 4.91828e-11
      RCONST(66) = 2.58334e-11
      RCONST(67) = 7.68422e-14
      RCONST(68) = 9.49778e-12
      RCONST(69) = 7.21345e-12
      RCONST(70) = 1.17282e-12
      RCONST(71) = 2.46725e-12
      RCONST(72) = 1.1e-11
      RCONST(73) = 1.5024e-13
      RCONST(74) = 1.53225e-15
      RCONST(75) = 1e-11
      RCONST(76) = 4.50123e-14
      RCONST(77) = 3.33437e-14
      RCONST(78) = 7.15352e-11
      RCONST(79) = 6.25037e-12
      RCONST(80) = 5.88365e-14
      RCONST(81) = 9.37792e-16
      RCONST(82) = 8.85199e-12
      RCONST(83) = 1.04438e-11
      RCONST(84) = 6.18205e-12
C END constant rate coefficients                                   

C INLINED initializations                                          

        TSTART = 12.D0*3600.D0
        TEND = TSTART + 24.D0*3600.D0 * 3
        DT = 3600.D0
        TEMP = 241.42

        STEPMIN=0.0001
        STEPMAX=3600.
        STEPSTART=STEPMIN

C End INLINED initializations                                      

      RETURN
      END

C End of Initialize function                                       
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


