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
   mexErrMsgTxt("small_mp_Hessian requires 3 input vectors: V(5), F(2), RCT(10)");
 }
 mrows =  mxGetM(prhs[0]); mcols = mxGetN(prhs[0]);
 if ( ( mrows != 5 )||( mcols != 1 ) ) {
   mexPrintf("First small_mp_Hessian input argument is of size V(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("First small_mp_Hessian input argument should be a column vector V(5,1)");
 }
 mrows =  mxGetM(prhs[1]); mcols = mxGetN(prhs[1]);
 if ( ( mrows != 2 )||( mcols != 1 ) ) {
   mexPrintf("Second small_mp_Hessian input argument is of size F(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Second small_mp_Hessian input argument should be a column vector F(2,1)");
 }
 mrows =  mxGetM(prhs[2]); mcols = mxGetN(prhs[2]);
 if ( (  mrows != 10 )||( mcols != 1 ) ) {
   mexPrintf("Third small_mp_Hessian input argument is of size RCT(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Third small_mp_Hessian input argument should be a column vector RCT(10,1)");
 }
 
/* Check for the right number of output arguments */
 if ( nlhs != 1 ) {
   mexErrMsgTxt("small_mp_Hessian requires 1 output column vector: HESS(10)");
 }


 V   = mxGetPr(prhs[0]);
 F   = mxGetPr(prhs[1]);
 RCT = mxGetPr(prhs[2]);

 plhs[0] = mxCreateDoubleMatrix(10,1,mxREAL);
 HESS = mxGetPr(plhs[0]);

 Hessian( V, F, RCT, HESS );

}
