C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C The ODE Function of Chemical Model File                          
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
C File                 : saprc_ref_Function.f                      
C Time                 : Wed Mar  9 12:16:09 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/saprc_ref
C Equation file        : saprc_ref.kpp                             
C Output root filename : saprc_ref                                 
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Fun - time derivatives of variables - Agregate form              
C   Arguments :                                                    
C      V         - Concentrations of variable species (local)      
C      F         - Concentrations of fixed species (local)         
C      RCT       - Rate constants (local)                          
C      Vdot      - Time derivative of variable species concentrations
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      SUBROUTINE Fun ( V, F, RCT, Vdot )

      IMPLICIT NONE
      INCLUDE 'saprc_ref_Parameters.h'

C V - Concentrations of variable species (local)                   
      REAL*8 V(NVAR)
C F - Concentrations of fixed species (local)                      
      REAL*8 F(NFIX)
C RCT - Rate constants (local)                                     
      REAL*8 RCT(NREACT)
C Vdot - Time derivative of variable species concentrations        
      REAL*8 Vdot(NVAR)


C Local variables                                                  
C A - Rate for each equation                                       
      REAL*8 A(NREACT)

C Computation of equation rates                                    
      A(1) = RCT(1)*V(70)
      A(2) = RCT(2)*V(58)*F(1)*F(2)
      A(3) = RCT(3)*V(58)*V(62)
      A(4) = RCT(4)*V(58)*V(69)*F(1)
      A(5) = RCT(5)*V(58)*V(70)
      A(6) = RCT(6)*V(58)*V(70)
      A(7) = RCT(7)*V(62)*V(69)
      A(8) = RCT(8)*V(62)*V(70)
      A(9) = RCT(9)*V(69)*V(71)
      A(10) = RCT(10)*V(69)*V(69)*F(2)
      A(11) = RCT(11)*V(70)*V(71)
      A(12) = RCT(12)*V(18)
      A(13) = RCT(13)*V(18)*F(3)
      A(14) = RCT(14)*V(70)*V(71)
      A(15) = RCT(15)*V(71)
      A(16) = RCT(16)*V(71)
      A(17) = RCT(17)*V(62)
      A(18) = RCT(18)*V(62)
      A(19) = RCT(19)*V(10)*F(3)
      A(20) = RCT(20)*V(10)*F(1)
      A(21) = RCT(21)*V(69)*V(74)
      A(22) = RCT(22)*V(19)
      A(23) = RCT(23)*V(19)
      A(24) = RCT(24)*V(19)*V(74)
      A(25) = RCT(25)*V(70)*V(74)
      A(26) = RCT(26)*V(71)*V(74)
      A(27) = RCT(27)*V(43)*V(74)
      A(28) = RCT(28)*V(43)
      A(29) = RCT(29)*V(40)*V(74)
      A(30) = RCT(30)*V(62)*V(74)
      A(31) = RCT(31)*V(63)*V(69)
      A(32) = RCT(32)*V(63)*V(70)
      A(33) = RCT(33)*V(25)
      A(34) = RCT(34)*V(25)
      A(35) = RCT(35)*V(25)*V(74)
      A(36) = RCT(36)*V(62)*V(63)
      A(37) = RCT(37)*V(63)*V(63)
      A(38) = RCT(38)*V(63)*V(63)*F(3)
      A(39) = RCT(39)*V(63)*V(71)
      A(40) = RCT(40)*V(71)*V(71)
      A(41) = RCT(41)*V(17)
      A(42) = RCT(42)*V(17)*V(74)
      A(43) = RCT(43)*V(63)*V(74)
      A(44) = RCT(44)*V(9)*V(74)
      A(45) = RCT(45)*V(74)*F(4)
      A(46) = RCT(46)*V(66)*V(69)
      A(47) = RCT(47)*V(63)*V(66)
      A(48) = RCT(48)*V(66)*V(71)
      A(49) = RCT(49)*V(66)*V(66)
      A(50) = RCT(50)*V(66)*V(66)
      A(51) = RCT(51)*V(68)*V(69)
      A(52) = RCT(52)*V(63)*V(68)
      A(53) = RCT(53)*V(68)*V(71)
      A(54) = RCT(54)*V(66)*V(68)
      A(55) = RCT(55)*V(68)*V(68)
      A(56) = RCT(56)*V(48)*V(69)
      A(57) = RCT(57)*V(48)*V(63)
      A(58) = RCT(58)*V(48)*V(71)
      A(59) = RCT(59)*V(48)*V(66)
      A(60) = RCT(60)*V(48)*V(68)
      A(62) = RCT(62)*V(64)*V(69)
      A(63) = RCT(63)*V(63)*V(64)
      A(64) = RCT(64)*V(64)*V(66)
      A(65) = RCT(65)*V(64)*V(71)
      A(66) = RCT(66)*V(64)*V(68)
      A(67) = RCT(67)*V(48)*V(64)
      A(68) = RCT(68)*V(64)*V(64)
      A(69) = RCT(69)*V(70)*V(72)
      A(70) = RCT(70)*V(13)
      A(71) = RCT(71)*V(69)*V(72)
      A(72) = RCT(72)*V(63)*V(72)
      A(73) = RCT(73)*V(71)*V(72)
      A(74) = RCT(74)*V(66)*V(72)
      A(75) = RCT(75)*V(68)*V(72)
      A(76) = RCT(76)*V(48)*V(72)
      A(77) = RCT(77)*V(64)*V(72)
      A(78) = RCT(78)*V(72)*V(72)
      A(79) = RCT(79)*V(70)*V(73)
      A(80) = RCT(80)*V(14)
      A(81) = RCT(81)*V(69)*V(73)
      A(82) = RCT(82)*V(63)*V(73)
      A(83) = RCT(83)*V(71)*V(73)
      A(84) = RCT(84)*V(66)*V(73)
      A(85) = RCT(85)*V(68)*V(73)
      A(86) = RCT(86)*V(48)*V(73)
      A(87) = RCT(87)*V(64)*V(73)
      A(88) = RCT(88)*V(72)*V(73)
      A(89) = RCT(89)*V(73)*V(73)
      A(90) = RCT(90)*V(67)*V(70)
      A(91) = RCT(91)*V(15)
      A(92) = RCT(92)*V(67)*V(69)
      A(93) = RCT(93)*V(63)*V(67)
      A(94) = RCT(94)*V(67)*V(71)
      A(95) = RCT(95)*V(66)*V(67)
      A(96) = RCT(96)*V(67)*V(68)
      A(97) = RCT(97)*V(48)*V(67)
      A(98) = RCT(98)*V(64)*V(67)
      A(99) = RCT(99)*V(67)*V(72)
      A(100) = RCT(100)*V(67)*V(73)
      A(101) = RCT(101)*V(67)*V(67)
      A(102) = RCT(102)*V(65)*V(70)
      A(103) = RCT(103)*V(16)
      A(104) = RCT(104)*V(65)*V(69)
      A(105) = RCT(105)*V(63)*V(65)
      A(106) = RCT(106)*V(65)*V(71)
      A(107) = RCT(107)*V(65)*V(66)
      A(108) = RCT(108)*V(65)*V(68)
      A(109) = RCT(109)*V(48)*V(65)
      A(110) = RCT(110)*V(64)*V(65)
      A(111) = RCT(111)*V(65)*V(72)
      A(112) = RCT(112)*V(65)*V(73)
      A(113) = RCT(113)*V(65)*V(67)
      A(114) = RCT(114)*V(65)*V(65)
      A(115) = RCT(115)*V(22)*V(70)
      A(116) = RCT(116)*V(22)
      A(117) = RCT(117)*V(46)*V(70)
      A(118) = RCT(118)*V(46)*V(63)
      A(119) = RCT(119)*V(46)
      A(120) = RCT(120)*V(28)*V(70)
      A(121) = RCT(121)*V(28)*V(63)
      A(122) = RCT(122)*V(28)
      A(123) = RCT(123)*V(56)
      A(124) = RCT(124)*V(56)
      A(125) = RCT(125)*V(56)*V(74)
      A(126) = RCT(126)*V(56)*V(63)
      A(127) = RCT(127)*V(27)
      A(128) = RCT(128)*V(27)*V(69)
      A(129) = RCT(129)*V(56)*V(71)
      A(130) = RCT(130)*V(55)*V(74)
      A(131) = RCT(131)*V(55)
      A(132) = RCT(132)*V(55)*V(71)
      A(133) = RCT(133)*V(59)*V(74)
      A(134) = RCT(134)*V(59)
      A(135) = RCT(135)*V(59)*V(71)
      A(136) = RCT(136)*V(42)*V(74)
      A(137) = RCT(137)*V(42)
      A(138) = RCT(138)*V(60)*V(74)
      A(139) = RCT(139)*V(60)
      A(140) = RCT(140)*V(29)*V(74)
      A(141) = RCT(141)*V(26)*V(74)
      A(142) = RCT(142)*V(26)
      A(143) = RCT(143)*V(37)*V(74)
      A(144) = RCT(144)*V(37)
      A(145) = RCT(145)*V(45)
      A(146) = RCT(146)*V(45)
      A(147) = RCT(147)*V(45)*V(74)
      A(148) = RCT(148)*V(45)*V(71)
      A(149) = RCT(149)*V(41)
      A(150) = 1.5e-11*V(41)*V(74)
      A(151) = RCT(151)*V(41)*V(71)
      A(152) = RCT(152)*V(12)
      A(153) = RCT(153)*V(39)*V(74)
      A(154) = RCT(154)*V(39)*V(71)
      A(155) = RCT(155)*V(34)*V(74)
      A(156) = RCT(156)*V(34)*V(71)
      A(157) = RCT(157)*V(36)*V(71)
      A(158) = RCT(158)*V(38)*V(74)
      A(159) = RCT(159)*V(38)
      A(160) = RCT(160)*V(38)*V(71)
      A(161) = RCT(161)*V(50)*V(74)
      A(162) = RCT(162)*V(50)*V(62)
      A(163) = RCT(163)*V(50)*V(71)
      A(164) = RCT(164)*V(50)*V(58)
      A(165) = RCT(165)*V(50)
      A(166) = RCT(166)*V(54)*V(74)
      A(167) = RCT(167)*V(54)*V(62)
      A(168) = RCT(168)*V(54)*V(58)
      A(169) = RCT(169)*V(54)
      A(170) = RCT(170)*V(52)*V(74)
      A(171) = RCT(171)*V(52)*V(62)
      A(172) = RCT(172)*V(52)*V(71)
      A(173) = RCT(173)*V(52)
      A(174) = RCT(174)*V(61)*V(74)
      A(175) = RCT(175)*V(61)
      A(176) = RCT(176)*V(57)*V(74)
      A(177) = RCT(177)*V(57)
      A(178) = RCT(178)*V(35)*V(74)
      A(179) = RCT(179)*V(35)*V(62)
      A(180) = RCT(180)*V(32)*V(74)
      A(181) = RCT(181)*V(32)
      A(182) = RCT(182)*V(33)*V(74)
      A(183) = RCT(183)*V(33)
      A(184) = RCT(184)*V(74)*F(5)
      A(185) = RCT(185)*V(44)*V(74)
      A(186) = RCT(186)*V(44)*V(62)
      A(187) = RCT(187)*V(44)*V(71)
      A(188) = RCT(188)*V(44)*V(58)
      A(189) = RCT(189)*V(47)*V(74)
      A(190) = RCT(190)*V(47)*V(62)
      A(191) = RCT(191)*V(47)*V(71)
      A(192) = RCT(192)*V(47)*V(58)
      A(193) = RCT(193)*V(49)*V(74)
      A(194) = RCT(194)*V(49)*V(62)
      A(195) = RCT(195)*V(49)*V(71)
      A(196) = RCT(196)*V(49)*V(58)
      A(197) = RCT(197)*V(11)*V(74)
      A(198) = RCT(198)*V(20)*V(74)
      A(199) = RCT(199)*V(21)*V(74)
      A(200) = RCT(200)*V(30)*V(74)
      A(201) = RCT(201)*V(23)*V(74)
      A(202) = RCT(202)*V(31)*V(74)
      A(203) = RCT(203)*V(24)*V(74)
      A(204) = RCT(204)*V(51)*V(74)
      A(205) = RCT(205)*V(51)*V(62)
      A(206) = RCT(206)*V(51)*V(71)
      A(207) = RCT(207)*V(51)*V(58)
      A(208) = RCT(208)*V(53)*V(74)
      A(209) = RCT(209)*V(53)*V(62)
      A(210) = RCT(210)*V(53)*V(71)
      A(211) = RCT(211)*V(53)*V(58)

C Aggregate function                                               
      Vdot(1) = A(44)
      Vdot(2) = A(128)+0.333*A(162)+0.351*A(167)+0.1*A(171)+0.37
     &         *A(186)+0.204*A(190)+0.103*A(194)+0.121*A(198)+0.185
     &         *A(205)+0.073*A(209)
      Vdot(3) = 0.25*A(72)+A(74)+A(75)+A(77)+0.05*A(205)+0.129*A(209)
      Vdot(4) = 0.25*A(82)+A(84)+A(85)+A(87)+0.25*A(93)+A(95)+A(96)
     &         +A(98)+0.25*A(105)+A(107)+A(108)+2*A(110)+0.372*A(171)
     &         +0.15*A(190)+0.189*A(194)+0.119*A(205)+0.247*A(209)
      Vdot(5) = 0.75*A(72)
      Vdot(6) = 0.75*A(82)+0.75*A(93)+0.75*A(105)
      Vdot(7) = 2*A(120)
      Vdot(8) = 6*A(120)+7*A(159)
      Vdot(9) = -A(44)
      Vdot(10) = A(18)-A(19)-A(20)
      Vdot(11) = -A(197)
      Vdot(12) = -A(152)+0.031*A(194)+0.087*A(203)
      Vdot(13) = A(69)-A(70)
      Vdot(14) = A(79)-A(80)
      Vdot(15) = A(90)-A(91)
      Vdot(16) = A(102)-A(103)
      Vdot(17) = A(37)+A(38)-A(41)-A(42)
      Vdot(18) = A(11)-A(12)-A(13)
      Vdot(19) = A(21)-A(22)-A(23)-A(24)
      Vdot(20) = -A(198)
      Vdot(21) = -A(199)
      Vdot(22) = -A(115)-A(116)+0.236*A(199)
      Vdot(23) = -A(201)
      Vdot(24) = -A(203)
      Vdot(25) = A(32)-A(33)-A(34)-A(35)
      Vdot(26) = A(47)-A(141)-A(142)
      Vdot(27) = A(126)-A(127)-A(128)
      Vdot(28) = -A(120)-A(121)-A(122)+A(157)
      Vdot(29) = A(49)+0.25*A(54)+0.25*A(64)-A(140)
      Vdot(30) = -A(200)
      Vdot(31) = -A(202)
      Vdot(32) = -A(180)-A(181)+0.108*A(202)+0.099*A(203)
      Vdot(33) = -A(182)-A(183)+0.051*A(202)+0.093*A(203)
      Vdot(34) = -A(155)-A(156)+0.207*A(202)+0.187*A(203)
      Vdot(35) = -A(178)-A(179)+0.491*A(202)+0.561*A(203)
      Vdot(36) = A(117)+A(121)+A(122)-A(157)
      Vdot(37) = A(52)+A(63)-A(143)-A(144)
      Vdot(38) = -A(158)-A(159)-A(160)+0.059*A(202)+0.05*A(203)+0.061
     &          *A(208)+0.042*A(209)+0.015*A(210)
      Vdot(39) = A(118)+A(119)-A(153)-A(154)+0.017*A(202)
      Vdot(40) = -A(29)+A(123)+A(124)+A(125)+A(129)+A(131)+0.034
     &          *A(133)+A(134)+2*A(145)+A(146)+1.26*A(147)+1.26*A(148)
     &          +A(149)+A(150)+A(151)+0.416*A(161)+0.45*A(162)+0.5
     &          *A(163)+0.67*A(165)+0.475*A(167)+0.7*A(169)+0.336
     &          *A(170)+0.498*A(171)+0.572*A(172)+1.233*A(173)+A(178)
     &          +1.5*A(179)+A(181)+A(183)+0.5*A(186)+0.491*A(188)
     &          +0.275*A(190)+0.157*A(194)+0.16*A(198)+0.002*A(200)
     &          +0.345*A(205)+0.265*A(209)+0.012*A(211)
      Vdot(41) = -A(149)-A(150)-A(151)+0.23*A(155)+0.084*A(161)+0.9
     &          *A(162)+0.3*A(166)+0.95*A(167)+0.174*A(170)+0.742
     &          *A(171)+0.008*A(172)+0.5*A(181)+0.5*A(183)+0.119
     &          *A(202)+0.287*A(203)
      Vdot(42) = A(116)-A(136)-A(137)+0.006*A(176)+0.02*A(177)+0.13
     &          *A(194)+0.417*A(198)+0.024*A(199)+0.452*A(200)+0.072
     &          *A(201)+0.005*A(204)+0.001*A(205)+0.024*A(206)+0.127
     &          *A(208)+0.045*A(209)+0.102*A(210)
      Vdot(43) = 2*A(13)+A(25)-A(27)-A(28)+0.2*A(39)+A(129)+A(132)
     &          +A(135)+A(148)+A(151)+A(154)+A(156)+A(157)+A(160)+0.5
     &          *A(163)+0.15*A(172)
      Vdot(44) = -A(185)-A(186)-A(187)-A(188)
      Vdot(45) = -A(145)-A(146)-A(147)-A(148)+0.23*A(153)+0.15*A(170)
     &          +0.023*A(171)+A(179)+0.5*A(181)+0.5*A(183)+0.009
     &          *A(188)+0.001*A(194)+0.248*A(198)+0.118*A(202)+0.097
     &          *A(203)
      Vdot(46) = A(92)+A(94)+A(99)+A(100)+2*A(101)+A(113)-A(117)
     &          -A(118)-A(119)+0.24*A(153)+A(154)+0.24*A(155)+A(156)
      Vdot(47) = -A(189)-A(190)-A(191)-A(192)
      Vdot(48) = -A(56)-A(57)-A(58)-A(59)-A(60)-A(67)-A(76)-A(86)
     &          +A(92)+A(94)-A(97)+A(99)+A(100)+2*A(101)-A(109)+A(113)
     &          +A(136)+0.616*A(138)+0.675*A(166)+0.515*A(175)+0.596
     &          *A(176)+0.152*A(177)+A(180)+A(181)+A(182)+A(183)+0.079
     &          *A(189)+0.126*A(190)+0.187*A(191)+0.24*A(192)+0.5
     &          *A(193)+0.729*A(194)+0.75*A(195)+0.559*A(199)+0.936
     &          *A(200)+0.948*A(201)+0.205*A(204)+0.488*A(206)+0.001
     &          *A(208)+0.137*A(209)+0.711*A(210)
      Vdot(49) = -A(193)-A(194)-A(195)-A(196)
      Vdot(50) = -A(161)-A(162)-A(163)-A(164)-A(165)+0.23*A(189)+0.39
     &          *A(190)+0.025*A(208)+0.026*A(209)+0.012*A(211)
      Vdot(51) = -A(204)-A(205)-A(206)-A(207)
      Vdot(52) = -A(170)-A(171)-A(172)-A(173)+0.357*A(189)+0.936
     &          *A(191)+0.025*A(208)
      Vdot(53) = -A(208)-A(209)-A(210)-A(211)
      Vdot(54) = -A(166)-A(167)-A(168)-A(169)+0.32*A(189)+0.16*A(190)
     &          +0.019*A(209)+0.048*A(210)
      Vdot(55) = A(81)+A(83)+A(88)+2*A(89)+A(100)+A(112)-A(130)-A(131)
     &          -A(132)+0.034*A(133)+A(134)+0.482*A(138)+A(139)+0.129
     &          *A(170)+0.047*A(171)+0.467*A(173)+0.084*A(174)+0.246
     &          *A(175)+0.439*A(176)+0.431*A(177)+0.195*A(185)+0.25
     &          *A(188)+A(197)+0.445*A(199)+0.455*A(200)+0.099*A(201)
     &          +0.294*A(204)+0.154*A(205)+0.009*A(206)+0.732*A(208)
     &          +0.456*A(209)+0.507*A(210)
      Vdot(56) = A(46)+A(48)+A(49)+2*A(50)+0.75*A(54)+0.75*A(64)+A(74)
     &          +A(84)+A(95)+A(104)+A(106)+A(107)+A(111)+A(112)+A(113)
     &          +2*A(114)-A(123)-A(124)-A(125)-A(126)+A(127)-A(129)
     &          +A(136)+0.115*A(138)+A(140)+0.35*A(141)+A(142)+A(146)
     &          +0.084*A(161)+0.2*A(162)+0.67*A(165)+0.3*A(166)+0.1
     &          *A(167)+0.055*A(170)+0.125*A(171)+0.227*A(172)+0.3
     &          *A(173)+0.213*A(174)+0.506*A(175)+0.01*A(176)+0.134
     &          *A(177)+1.61*A(185)+A(186)+0.191*A(188)+0.624*A(189)
     &          +0.592*A(190)+0.24*A(192)+0.276*A(193)+0.235*A(194)
     &          +0.039*A(198)+0.026*A(199)+0.024*A(200)+0.026*A(201)
     &          +0.732*A(204)+0.5*A(205)+0.244*A(208)+0.269*A(209)
     &          +0.079*A(210)
      Vdot(57) = A(62)+A(115)+0.572*A(172)-0.69*A(176)-A(177)+0.276
     &          *A(195)+0.511*A(206)+0.321*A(210)
      Vdot(58) = A(1)-A(2)-A(3)-A(4)-A(5)-A(6)+A(16)+A(17)+A(20)
     &          -A(164)-A(168)-A(188)-A(192)-A(196)-A(207)-A(211)
      Vdot(59) = -A(133)-A(134)-A(135)+0.37*A(138)+A(143)+A(144)
     &          +A(164)+0.675*A(166)+0.45*A(168)+0.013*A(170)+0.218
     &          *A(172)+0.558*A(174)+0.71*A(175)+0.213*A(176)+0.147
     &          *A(177)+A(178)+A(180)+A(182)+A(187)+0.474*A(193)+0.205
     &          *A(194)+0.474*A(195)+0.147*A(196)+0.155*A(198)+0.122
     &          *A(199)+0.244*A(200)+0.204*A(201)+0.497*A(204)+0.363
     &          *A(205)+0.037*A(206)+0.45*A(207)+0.511*A(208)+0.305
     &          *A(209)+0.151*A(210)+0.069*A(211)
      Vdot(60) = 0.5*A(64)+A(65)+0.5*A(66)+A(68)-A(138)-A(139)+0.416
     &          *A(161)+0.55*A(168)+0.15*A(170)+0.21*A(171)+0.233
     &          *A(173)+0.115*A(174)+0.177*A(176)+0.243*A(177)+0.332
     &          *A(199)+0.11*A(200)+0.089*A(201)+0.437*A(207)+0.072
     &          *A(208)+0.026*A(209)+0.001*A(210)+0.659*A(211)
      Vdot(61) = 0.5*A(64)+0.5*A(66)+A(68)+A(77)+A(87)+A(98)+0.7
     &          *A(169)+0.332*A(170)-0.671*A(174)-A(175)+0.048*A(176)
     &          +0.435*A(177)+0.1*A(190)+0.75*A(192)+0.276*A(193)
     &          +0.276*A(194)+0.853*A(196)+0.125*A(200)+0.417*A(201)
     &          +0.055*A(202)+0.119*A(204)+0.215*A(205)+0.113*A(207)
     &          +0.043*A(209)+0.259*A(211)
      Vdot(62) = A(2)-A(3)-A(7)-A(8)-A(17)-A(18)-A(30)-A(36)+0.25
     &          *A(72)+0.25*A(82)+0.25*A(93)+0.25*A(105)-A(162)-A(167)
     &          -A(171)-A(179)-A(186)-A(190)-A(194)-A(205)-A(209)
      Vdot(63) = A(23)+A(26)+A(29)+A(30)-A(31)-A(32)+A(33)+0.61*A(34)
     &          -A(36)-2*A(37)-2*A(38)-A(39)+A(42)-A(43)+A(44)+A(45)
     &          +A(46)-A(47)+A(48)+2*A(50)+A(51)-A(52)+A(53)+A(54)
     &          +A(55)-A(63)+A(64)+A(65)+A(66)+A(68)-A(72)-A(82)-A(93)
     &          -A(105)-A(118)-A(121)+2*A(123)+A(125)-A(126)+A(127)
     &          +A(128)+A(129)+A(131)+A(134)+A(140)+A(142)+A(144)+2
     &          *A(145)+0.63*A(147)+0.63*A(148)+A(149)+0.008*A(162)
     &          +0.34*A(165)+0.064*A(167)+0.4*A(171)+1.233*A(173)
     &          +0.379*A(174)+0.113*A(176)+0.341*A(177)+1.5*A(179)+0.5
     &          *A(181)+0.5*A(183)+0.12*A(186)+0.5*A(188)+0.033*A(194)
     &          +0.121*A(198)+0.224*A(202)+0.187*A(203)+0.056*A(205)
     &          +0.003*A(209)+0.013*A(211)
      Vdot(64) = -A(62)-A(63)-A(64)-A(65)-A(66)-2*A(68)-A(77)-A(87)
     &          -A(98)-A(110)+0.001*A(133)+0.042*A(138)+0.025*A(166)
     &          +0.041*A(170)+0.051*A(172)+0.07*A(174)+0.04*A(175)
     &          +0.173*A(176)+0.095*A(177)+0.093*A(189)+0.008*A(190)
     &          +0.064*A(191)+0.01*A(192)+0.25*A(193)+0.18*A(194)+0.25
     &          *A(195)+0.021*A(198)+0.07*A(199)+0.143*A(200)+0.347
     &          *A(201)+0.011*A(202)+0.009*A(203)+0.09*A(204)+0.001
     &          *A(205)+0.176*A(206)+0.082*A(208)+0.002*A(209)+0.136
     &          *A(210)+0.001*A(211)
      Vdot(65) = -A(102)+A(103)-A(104)-A(105)-A(106)-A(107)-A(108)
     &          -A(110)-A(111)-A(112)-A(113)-2*A(114)+0.5*A(161)+0.5
     &          *A(163)+0.33*A(165)+0.3*A(169)+0.289*A(170)+0.15
     &          *A(172)+0.192*A(190)+0.24*A(192)
      Vdot(66) = -A(46)-A(47)-A(48)-2*A(49)-2*A(50)-A(54)-A(64)+A(71)
     &          +A(73)-A(74)+2*A(78)-A(84)+A(88)-A(95)+A(99)-A(107)
     &          +A(111)+A(116)+A(131)+A(137)+0.65*A(141)+0.3*A(169)
     &          +A(184)+0.3*A(188)+0.25*A(192)+0.011*A(200)+0.076
     &          *A(205)+0.197*A(209)+0.03*A(210)
      Vdot(67) = -A(90)+A(91)-A(92)-A(93)-A(94)-A(95)-A(96)-A(98)
     &          -A(99)-A(100)-2*A(101)-A(113)+A(158)+A(160)
      Vdot(68) = -A(51)-A(52)-A(53)-A(54)-2*A(55)-A(66)-A(75)+A(81)
     &          +A(83)-A(85)+A(88)+2*A(89)-A(96)+A(100)-A(108)+A(112)
     &          +0.034*A(133)+A(134)+0.37*A(138)+A(139)+0.34*A(143)
     &          +0.76*A(153)+0.76*A(155)+0.5*A(161)+0.1*A(162)+0.5
     &          *A(163)+0.33*A(165)+0.3*A(166)+0.05*A(167)+0.67*A(170)
     &          +0.048*A(171)+0.799*A(172)+0.473*A(174)+0.96*A(175)
     &          +0.376*A(176)+0.564*A(177)+A(178)+A(181)+A(183)+A(185)
     &          +A(187)+0.2*A(188)+0.907*A(189)+0.066*A(190)+0.749
     &          *A(191)+0.75*A(193)+0.031*A(194)+0.276*A(195)+A(197)
     &          +0.612*A(198)+0.695*A(199)+0.835*A(200)+0.653*A(201)
     &          +0.765*A(202)+0.804*A(203)+0.91*A(204)+0.022*A(205)
     &          +0.824*A(206)+0.918*A(208)+0.033*A(209)+0.442*A(210)
     &          +0.012*A(211)
      Vdot(69) = A(1)-A(4)+A(5)-A(7)-A(9)-2*A(10)+A(14)+A(15)-A(21)
     &          +A(22)-A(31)-A(46)-A(51)-A(56)-A(62)-A(71)-A(81)-A(92)
     &          -A(104)-A(128)
      Vdot(70) = -A(1)+A(4)-A(5)-A(6)+A(7)-A(8)+2*A(9)+2*A(10)-A(11)
     &          +A(12)+A(16)+A(23)+A(24)-A(25)+A(26)+A(28)+A(31)-A(32)
     &          +A(33)+0.61*A(34)+A(35)+0.8*A(39)+2*A(40)+A(46)+A(48)
     &          +A(51)+A(53)+A(56)+A(58)+A(65)-A(69)+A(70)+A(71)+A(73)
     &          -A(79)+A(80)+A(81)+A(83)-A(90)+A(91)+A(92)+A(94)
     &          -A(102)+A(103)+A(104)+A(106)-A(115)-A(117)-A(120)
     &          +A(128)+0.338*A(176)+A(177)+0.187*A(191)+0.474*A(195)
     &          +0.391*A(210)
      Vdot(71) = A(6)+A(8)-A(9)-A(11)+A(12)-A(14)-A(15)-A(16)-A(26)
     &          +A(27)+0.39*A(34)-A(39)-2*A(40)-A(48)-A(53)-A(58)
     &          -A(65)-A(73)-A(83)-A(94)-A(106)-A(129)-A(132)-A(135)
     &          -A(148)-A(151)-A(154)-A(156)-A(157)-A(160)-A(163)
     &          -A(172)-A(187)-A(191)-A(195)-A(206)-A(210)
      Vdot(72) = -A(69)+A(70)-A(71)-A(72)-A(73)-A(74)-A(75)-A(77)-2
     &          *A(78)-A(88)-A(99)+A(104)+A(106)+A(112)+A(113)+2
     &          *A(114)+A(130)+A(132)+A(136)+A(137)+0.492*A(138)
     &          +A(139)+A(149)+A(150)+A(151)+2*A(152)+0.67*A(165)
     &          +0.675*A(166)+0.467*A(173)+0.029*A(174)+0.667*A(175)
     &          +A(180)+0.5*A(181)+A(182)+0.5*A(183)+0.123*A(194)
     &          +0.011*A(200)+0.137*A(209)
      Vdot(73) = -A(79)+A(80)-A(81)-A(82)-A(83)-A(84)-A(85)-A(87)
     &          -A(88)-2*A(89)-A(100)-A(112)+0.965*A(133)+A(135)+0.096
     &          *A(138)+0.37*A(147)+0.37*A(148)+0.1*A(162)+0.05*A(167)
     &          +0.048*A(171)+0.3*A(173)+0.049*A(174)+0.333*A(175)
     &          +0.201*A(194)+0.006*A(209)
      Vdot(74) = 2*A(19)-A(21)+A(22)-A(24)-A(25)-A(26)-A(27)+A(28)
     &          -A(29)-A(30)+A(31)+0.39*A(34)-A(35)+A(36)+0.8*A(39)+2
     &          *A(41)-A(42)-A(43)-A(44)-A(45)-A(125)-A(130)-A(133)
     &          -A(136)-A(138)-A(140)-0.65*A(141)+A(142)-0.34*A(143)
     &          +A(144)-A(147)-A(150)-A(153)-A(155)-A(158)-A(161)
     &          +0.208*A(162)+0.33*A(165)-A(166)+0.164*A(167)-A(170)
     &          +0.285*A(171)-A(174)-A(176)-A(178)+0.5*A(179)-A(180)
     &          -A(182)-A(184)-A(185)+0.12*A(186)-A(189)+0.266*A(190)
     &          -A(193)+0.567*A(194)-A(197)-0.754*A(198)-A(199)-A(200)
     &          -A(201)-A(202)-A(203)-A(204)+0.155*A(205)-A(208)+0.378
     &          *A(209)
      RETURN
      END

C End of Fun function                                              
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


