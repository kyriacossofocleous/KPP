C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Sparse Hessian Data Structures File                              
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
C File                 : chapman_ref_HessianSP.f                   
C Time                 : Wed Mar  9 11:41:39 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/kpp/chapman_ref
C Equation file        : chapman_ref.kpp                           
C Output root filename : chapman_ref                               
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




C Hessian Sparse Data                                              
C                                                                  
      BLOCK DATA HESSIAN_SPARSE_DATA

      INCLUDE 'chapman_ref_Sparse.h'
      INTEGER i

      DATA IHESS_I /
     *  1,  2,  2,  3,  3,  3,  4,  4,  5,  5 / 


      DATA IHESS_J /
     *  1,  2,  2,  1,  2,  3,  2,  3,  2,  3 / 


      DATA IHESS_K /
     *  3,  3,  5,  3,  3,  4,  5,  4,  5,  4 / 


      END


