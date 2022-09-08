C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
C                                                                  
C Sparse Data Header File                                          
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
C File                 : small_ref_Sparse.h                        
C Time                 : Fri Sep  2 14:40:04 2022                  
C Working directory    : /home/kyriacos/CyprusInstitute/KPP/small_ref
C Equation file        : small_ref.kpp                             
C Output root filename : small_ref                                 
C                                                                  
C ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




C  ----------> Sparse Hessian Data                                 

C IHESS_I - Index i of Hessian element d^2 f_i/dv_j.dv_k           
      INTEGER IHESS_I(10)
      COMMON /HESSDATA/ IHESS_I
C IHESS_J - Index j of Hessian element d^2 f_i/dv_j.dv_k           
      INTEGER IHESS_J(10)
      COMMON /HESSDATA/ IHESS_J
C IHESS_K - Index k of Hessian element d^2 f_i/dv_j.dv_k           
      INTEGER IHESS_K(10)
      COMMON /HESSDATA/ IHESS_K


C  ----------> Sparse Stoichiometric Matrix                        

C STOICM - Stoichiometric Matrix in compressed column format       
      REAL*8 STOICM(22)
      COMMON /STOICM_VALUES/ STOICM
C IROW_STOICM - Row indices in STOICM                              
      INTEGER IROW_STOICM(22)
      COMMON /STOICM_DATA/ IROW_STOICM
C CCOL_STOICM - Beginning of columns in STOICM                     
      INTEGER CCOL_STOICM(11)
      COMMON /STOICM_DATA/ CCOL_STOICM
C ICOL_STOICM - Column indices in STOICM                           
      INTEGER ICOL_STOICM(22)
      COMMON /STOICM_DATA/ ICOL_STOICM


C  ----------> Sparse Data for Jacobian of Reactant Products       

C ICOL_JVRP - Column indices in JVRP                               
      INTEGER ICOL_JVRP(13)
      COMMON /JVRP/ ICOL_JVRP
C IROW_JVRP - Row indices in JVRP                                  
      INTEGER IROW_JVRP(13)
      COMMON /JVRP/ IROW_JVRP
C CROW_JVRP - Beginning of rows in JVRP                            
      INTEGER CROW_JVRP(11)
      COMMON /JVRP/ CROW_JVRP

