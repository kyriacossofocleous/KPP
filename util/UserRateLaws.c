/*  User-defined Rate Law functions
    Note: the default argument type for rate laws, as read from the equations file, is single precision
         but all the internal calculations are performed in double precision
*/
/* Arrhenius */
KPP_REAL  ARR( KPP_REAL A0, KPP_REAL B0, KPP_REAL C0 )
      {
      KPP_REAL ARR_RES;
                 
      ARR_RES = A0 * expf( -B0/TEMP ) 
                * powf( (TEMP/300.0), C0 );   
           
      return ARR_RES;
      }           


/* Simplified Arrhenius, with two arguments */
/* Note that the argument B0 has a changed sign when compared to ARR */
KPP_REAL  ARR2(  KPP_REAL A0, KPP_REAL B0 )
      {
      KPP_REAL ARR_RES;           

      ARR_RES =  A0 * expf( B0/TEMP );   
           
      return ARR_RES;
      }           


KPP_REAL  EP2( KPP_REAL A0, KPP_REAL C0, KPP_REAL A2, KPP_REAL C2, KPP_REAL A3, KPP_REAL C3)
      {                       
      KPP_REAL K0, K2, K3, EP2_RES;
      
      K0 = A0 * expf( -C0/TEMP );
      K2 = A2 * expf( -C2/TEMP );
      K3 = A3 * expf( -C3/TEMP );
      K3 = K3*CFACTOR*1.0e+6;
      EP2_RES = K0 + K3/( 1.0+K3/K2 );
        
      return EP2_RES;
      }  


KPP_REAL  EP3( KPP_REAL A1, KPP_REAL C1, KPP_REAL A2, KPP_REAL C2) 
      {               
      KPP_REAL K1, K2, EP3_RES;
      
      K1 = A1 * expf(-C1/TEMP);
      K2 = A2 * expf(-C2/TEMP);
      EP3_RES = K1 + K2*(1.0e+6*CFACTOR);
      
      return EP3_RES;
      }    


KPP_REAL  FALL (  KPP_REAL A0, KPP_REAL B0, KPP_REAL C0, KPP_REAL A1, KPP_REAL B1, KPP_REAL C1, KPP_REAL CF)
      {                      
      KPP_REAL K0, K1, FALL_RES;
      
      K0 = A0 * expf(-B0/TEMP)* powf( (TEMP/300.0), C0 );
      K1 = A1 * expf(-B1/TEMP)* powf( (TEMP/300.0), C1 );
      K0 = K0*CFACTOR*1.0e+6;
      K1 = K0/K1;
      FALL_RES = (K0/(1.0+K1))*
           powf( CF, ( 1.0/( 1.0+powf( (log10f(K1)),2 ) ) ) );
        
      return FALL_RES;
      }
