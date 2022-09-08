/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
            Matlab Gateway for the Jacobian Jac_SP 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "mex.h"
#define min( x, y ) (x) < (y) ? (x) : (y)
#define max( x, y ) (x) > (y) ? (x) : (y)

void mexFunction( int nlhs, mxArray *plhs[], 
                int nrhs, const mxArray *prhs[] )
{
 int mrows, mcols;
 float *V, *F, *RCT, *JVS;

/* Check for the right number and size of input arguments */
 if ( nrhs != 3 ) {
   mexErrMsgTxt("tropo_sp_Jac_SP requires 3 input vectors: V(84), F(4), RCT(178)");
 }
 mrows =  mxGetM(prhs[0]); mcols = mxGetN(prhs[0]);
 if ( ( mrows != 84 )||( mcols != 1 ) ) {
   mexPrintf("First tropo_sp_Jac_SP input argument is of size V(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("First tropo_sp_Jac_SP input argument should be a column vector V(84,1)");
 }
 mrows =  mxGetM(prhs[1]); mcols = mxGetN(prhs[1]);
 if ( ( mrows != 4 )||( mcols != 1 ) ) {
   mexPrintf("Second tropo_sp_Jac_SP input argument is of size F(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Second tropo_sp_Jac_SP input argument should be a column vector F(4,1)");
 }
 mrows =  mxGetM(prhs[2]); mcols = mxGetN(prhs[2]);
 if ( (  mrows != 178 )||( mcols != 1 ) ) {
   mexPrintf("Third tropo_sp_Jac_SP input argument is of size RCT(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Third tropo_sp_Jac_SP input argument should be a column vector RCT(178,1)");
 }
 
/* Check for the right number of output arguments */
 if ( nlhs != 1 ) {
   mexErrMsgTxt("tropo_sp_Jac_SP requires 1 output column vector: JVS(768)");
 }


 V   = mxGetPr(prhs[0]);
 F   = mxGetPr(prhs[1]);
 RCT = mxGetPr(prhs[2]);

 plhs[0] = mxCreateDoubleMatrix(768,1,mxREAL);
 JVS = mxGetPr(plhs[0]);

 Jac_SP( V, F, RCT, JVS );

}
