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
   mexErrMsgTxt("chapman_enh_Jac_SP requires 3 input vectors: V(4), F(1), RCT(7)");
 }
 mrows =  mxGetM(prhs[0]); mcols = mxGetN(prhs[0]);
 if ( ( mrows != 4 )||( mcols != 1 ) ) {
   mexPrintf("First chapman_enh_Jac_SP input argument is of size V(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("First chapman_enh_Jac_SP input argument should be a column vector V(4,1)");
 }
 mrows =  mxGetM(prhs[1]); mcols = mxGetN(prhs[1]);
 if ( ( mrows != 1 )||( mcols != 1 ) ) {
   mexPrintf("Second chapman_enh_Jac_SP input argument is of size F(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Second chapman_enh_Jac_SP input argument should be a column vector F(1,1)");
 }
 mrows =  mxGetM(prhs[2]); mcols = mxGetN(prhs[2]);
 if ( (  mrows != 7 )||( mcols != 1 ) ) {
   mexPrintf("Third chapman_enh_Jac_SP input argument is of size RCT(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Third chapman_enh_Jac_SP input argument should be a column vector RCT(7,1)");
 }
 
/* Check for the right number of output arguments */
 if ( nlhs != 1 ) {
   mexErrMsgTxt("chapman_enh_Jac_SP requires 1 output column vector: JVS(15)");
 }


 V   = mxGetPr(prhs[0]);
 F   = mxGetPr(prhs[1]);
 RCT = mxGetPr(prhs[2]);

 plhs[0] = mxCreateDoubleMatrix(15,1,mxREAL);
 JVS = mxGetPr(plhs[0]);

 Jac_SP( V, F, RCT, JVS );

}
