/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
                   Matlab Gateway for the Hessian 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "mex.h"
#define min( x, y ) (x) < (y) ? (x) : (y)
#define max( x, y ) (x) > (y) ? (x) : (y)

void mexFunction( int nlhs, mxArray *plhs[], 
                     int nrhs, const mxArray *prhs[] )
{
 int mrows, mcols;
 float *V, *F, *RCT, *HESS;


/* Check for the right number and size of input arguments */
 if ( nrhs != 3 ) {
   mexErrMsgTxt("cbm4_sp_Hessian requires 3 input vectors: V(32), F(1), RCT(81)");
 }
 mrows =  mxGetM(prhs[0]); mcols = mxGetN(prhs[0]);
 if ( ( mrows != 32 )||( mcols != 1 ) ) {
   mexPrintf("First cbm4_sp_Hessian input argument is of size V(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("First cbm4_sp_Hessian input argument should be a column vector V(32,1)");
 }
 mrows =  mxGetM(prhs[1]); mcols = mxGetN(prhs[1]);
 if ( ( mrows != 1 )||( mcols != 1 ) ) {
   mexPrintf("Second cbm4_sp_Hessian input argument is of size F(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Second cbm4_sp_Hessian input argument should be a column vector F(1,1)");
 }
 mrows =  mxGetM(prhs[2]); mcols = mxGetN(prhs[2]);
 if ( (  mrows != 81 )||( mcols != 1 ) ) {
   mexPrintf("Third cbm4_sp_Hessian input argument is of size RCT(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Third cbm4_sp_Hessian input argument should be a column vector RCT(81,1)");
 }
 
/* Check for the right number of output arguments */
 if ( nlhs != 1 ) {
   mexErrMsgTxt("cbm4_sp_Hessian requires 1 output column vector: HESS(258)");
 }


 V   = mxGetPr(prhs[0]);
 F   = mxGetPr(prhs[1]);
 RCT = mxGetPr(prhs[2]);

 plhs[0] = mxCreateDoubleMatrix(258,1,mxREAL);
 HESS = mxGetPr(plhs[0]);

 Hessian( V, F, RCT, HESS );

}
