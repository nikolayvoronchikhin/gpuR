// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// cpp_detectGPUs
SEXP cpp_detectGPUs(SEXP platform_idx);
RcppExport SEXP gpuR_cpp_detectGPUs(SEXP platform_idxSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type platform_idx(platform_idxSEXP);
    __result = Rcpp::wrap(cpp_detectGPUs(platform_idx));
    return __result;
END_RCPP
}
// detectPlatforms
SEXP detectPlatforms();
RcppExport SEXP gpuR_detectPlatforms() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(detectPlatforms());
    return __result;
END_RCPP
}
// cpp_device_has_double
bool cpp_device_has_double(SEXP platform_idx_, SEXP gpu_idx_);
RcppExport SEXP gpuR_cpp_device_has_double(SEXP platform_idx_SEXP, SEXP gpu_idx_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type platform_idx_(platform_idx_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type gpu_idx_(gpu_idx_SEXP);
    __result = Rcpp::wrap(cpp_device_has_double(platform_idx_, gpu_idx_));
    return __result;
END_RCPP
}
// cpp_gpuBigMatrix_iaxpy
void cpp_gpuBigMatrix_iaxpy(SEXP alpha_, SEXP A_, SEXP B_, SEXP sourceCode_, SEXP kernel_function_);
RcppExport SEXP gpuR_cpp_gpuBigMatrix_iaxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP, SEXP sourceCode_SEXP, SEXP kernel_function_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sourceCode_(sourceCode_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type kernel_function_(kernel_function_SEXP);
    cpp_gpuBigMatrix_iaxpy(alpha_, A_, B_, sourceCode_, kernel_function_);
    return R_NilValue;
END_RCPP
}
// cpp_gpuBigMatrix_igemm
void cpp_gpuBigMatrix_igemm(SEXP A_, SEXP B_, SEXP C_, SEXP sourceCode_, SEXP kernel_function_);
RcppExport SEXP gpuR_cpp_gpuBigMatrix_igemm(SEXP A_SEXP, SEXP B_SEXP, SEXP C_SEXP, SEXP sourceCode_SEXP, SEXP kernel_function_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type C_(C_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sourceCode_(sourceCode_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type kernel_function_(kernel_function_SEXP);
    cpp_gpuBigMatrix_igemm(A_, B_, C_, sourceCode_, kernel_function_);
    return R_NilValue;
END_RCPP
}
// cpp_gpuInfo
List cpp_gpuInfo(SEXP platform_idx_, SEXP gpu_idx_);
RcppExport SEXP gpuR_cpp_gpuInfo(SEXP platform_idx_SEXP, SEXP gpu_idx_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type platform_idx_(platform_idx_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type gpu_idx_(gpu_idx_SEXP);
    __result = Rcpp::wrap(cpp_gpuInfo(platform_idx_, gpu_idx_));
    return __result;
END_RCPP
}
// cpp_gpuMatrix_iaxpy
SEXP cpp_gpuMatrix_iaxpy(SEXP alpha_, SEXP A_, SEXP B_, SEXP sourceCode_, SEXP kernel_function_);
RcppExport SEXP gpuR_cpp_gpuMatrix_iaxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP, SEXP sourceCode_SEXP, SEXP kernel_function_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sourceCode_(sourceCode_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type kernel_function_(kernel_function_SEXP);
    __result = Rcpp::wrap(cpp_gpuMatrix_iaxpy(alpha_, A_, B_, sourceCode_, kernel_function_));
    return __result;
END_RCPP
}
// cpp_gpuMatrix_igemm
SEXP cpp_gpuMatrix_igemm(SEXP A_, SEXP B_, SEXP sourceCode_, SEXP kernel_function_);
RcppExport SEXP gpuR_cpp_gpuMatrix_igemm(SEXP A_SEXP, SEXP B_SEXP, SEXP sourceCode_SEXP, SEXP kernel_function_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sourceCode_(sourceCode_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type kernel_function_(kernel_function_SEXP);
    __result = Rcpp::wrap(cpp_gpuMatrix_igemm(A_, B_, sourceCode_, kernel_function_));
    return __result;
END_RCPP
}
// cpp_gpu_two_vec
IntegerVector cpp_gpu_two_vec(IntegerVector A_, IntegerVector B_, IntegerVector C_, SEXP sourceCode_, SEXP kernel_function_);
RcppExport SEXP gpuR_cpp_gpu_two_vec(SEXP A_SEXP, SEXP B_SEXP, SEXP C_SEXP, SEXP sourceCode_SEXP, SEXP kernel_function_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< IntegerVector >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type C_(C_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sourceCode_(sourceCode_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type kernel_function_(kernel_function_SEXP);
    __result = Rcpp::wrap(cpp_gpu_two_vec(A_, B_, C_, sourceCode_, kernel_function_));
    return __result;
END_RCPP
}
// cpp_platformInfo
List cpp_platformInfo(SEXP platform_idx_);
RcppExport SEXP gpuR_cpp_platformInfo(SEXP platform_idx_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type platform_idx_(platform_idx_SEXP);
    __result = Rcpp::wrap(cpp_platformInfo(platform_idx_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuMatrix_daxpy
SEXP cpp_vienna_gpuMatrix_daxpy(SEXP alpha_, SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuMatrix_daxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuMatrix_daxpy(alpha_, A_, B_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuMatrix_saxpy
SEXP cpp_vienna_gpuMatrix_saxpy(SEXP alpha_, SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuMatrix_saxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuMatrix_saxpy(alpha_, A_, B_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuBigMatrix_daxpy
void cpp_vienna_gpuBigMatrix_daxpy(SEXP alpha_, SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuBigMatrix_daxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    cpp_vienna_gpuBigMatrix_daxpy(alpha_, A_, B_);
    return R_NilValue;
END_RCPP
}
// cpp_vienna_gpuBigMatrix_saxpy
void cpp_vienna_gpuBigMatrix_saxpy(SEXP alpha_, SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuBigMatrix_saxpy(SEXP alpha_SEXP, SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type alpha_(alpha_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    cpp_vienna_gpuBigMatrix_saxpy(alpha_, A_, B_);
    return R_NilValue;
END_RCPP
}
// cpp_vienna_gpuBigMatrix_dgemm
SEXP cpp_vienna_gpuBigMatrix_dgemm(SEXP A_, SEXP B_, SEXP C_);
RcppExport SEXP gpuR_cpp_vienna_gpuBigMatrix_dgemm(SEXP A_SEXP, SEXP B_SEXP, SEXP C_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type C_(C_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuBigMatrix_dgemm(A_, B_, C_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuBigMatrix_sgemm
SEXP cpp_vienna_gpuBigMatrix_sgemm(SEXP A_, SEXP B_, SEXP C_);
RcppExport SEXP gpuR_cpp_vienna_gpuBigMatrix_sgemm(SEXP A_SEXP, SEXP B_SEXP, SEXP C_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type C_(C_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuBigMatrix_sgemm(A_, B_, C_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuMatrix_dgemm
SEXP cpp_vienna_gpuMatrix_dgemm(SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuMatrix_dgemm(SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuMatrix_dgemm(A_, B_));
    return __result;
END_RCPP
}
// cpp_vienna_gpuMatrix_sgemm
SEXP cpp_vienna_gpuMatrix_sgemm(SEXP A_, SEXP B_);
RcppExport SEXP gpuR_cpp_vienna_gpuMatrix_sgemm(SEXP A_SEXP, SEXP B_SEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type A_(A_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type B_(B_SEXP);
    __result = Rcpp::wrap(cpp_vienna_gpuMatrix_sgemm(A_, B_));
    return __result;
END_RCPP
}
