// eigen headers for handling the R input data
#include <RcppEigen.h>

#include "gpuR/eigen_templates.hpp"
#include "gpuR/dynEigen.hpp"
#include "gpuR/dynEigenVec.hpp"

// Use OpenCL with ViennaCL
#define VIENNACL_WITH_OPENCL 1

// Use ViennaCL algorithms on Eigen objects
#define VIENNACL_WITH_EIGEN 1

// ViennaCL headers
#include "viennacl/ocl/device.hpp"
#include "viennacl/ocl/platform.hpp"
#include "viennacl/matrix.hpp"
#include "viennacl/linalg/sum.hpp"

using namespace Rcpp;

template <typename T>
void cpp_vienna_colmean(
    MapMat<T> &Am, 
    MapVec<T> &colMeans,
    int device_flag)
{    
    //use only GPUs:
    if(device_flag == 0){
        long id = 0;
        viennacl::ocl::set_context_device_type(id, viennacl::ocl::gpu_tag());
    }
    
    int M = Am.cols();
    int K = Am.rows();
    int V = colMeans.size();
    
    viennacl::matrix<T> vcl_A(K,M);
    viennacl::vector<T> vcl_colMeans(V);
    
    viennacl::copy(Am, vcl_A); 
    
    vcl_colMeans = viennacl::linalg::column_sum(vcl_A);
    vcl_colMeans *= (T)(1)/(T)(K);
    
    viennacl::copy(vcl_colMeans, colMeans);
}

template <typename T>
void cpp_vienna_colsum(
    MapMat<T> &Am, 
    MapVec<T> &colSums,
    int device_flag)
{    
        //use only GPUs:
    if(device_flag == 0){
        long id = 0;
        viennacl::ocl::set_context_device_type(id, viennacl::ocl::gpu_tag());
    }
    
    int M = Am.cols();
    int K = Am.rows();
    int V = colSums.size();
    
    viennacl::matrix<T> vcl_A(K,M);
    viennacl::vector<T> vcl_colSums(V);
    
    viennacl::copy(Am, vcl_A); 
    
    vcl_colSums = viennacl::linalg::column_sum(vcl_A);
    
    viennacl::copy(vcl_colSums, colSums);
}

template <typename T>
void cpp_vienna_rowmean(
    MapMat<T> &Am, 
    MapVec<T> &rowMeans,
    int device_flag)
{    
    //use only GPUs:
    if(device_flag == 0){
        long id = 0;
        viennacl::ocl::set_context_device_type(id, viennacl::ocl::gpu_tag());
    }
    
    int M = Am.cols();
    int K = Am.rows();
    int V = rowMeans.size();
    
    viennacl::matrix<T> vcl_A(K,M);
    viennacl::vector<T> vcl_rowMeans(V);
    
    viennacl::copy(Am, vcl_A); 
    
    vcl_rowMeans = viennacl::linalg::row_sum(vcl_A);
    vcl_rowMeans *= (T)(1)/(T)(M);
    
    viennacl::copy(vcl_rowMeans, rowMeans);
}

template <typename T>
void cpp_vienna_rowsum(
    MapMat<T> &Am, 
    MapVec<T> &rowSums,
    int device_flag)
{    
    //use only GPUs:
    if(device_flag == 0){
        long id = 0;
        viennacl::ocl::set_context_device_type(id, viennacl::ocl::gpu_tag());
    }
    
    int M = Am.cols();
    int K = Am.rows();
    int V = rowSums.size();
    
    viennacl::matrix<T> vcl_A(K,M);
    viennacl::vector<T> vcl_rowSums(V);
    
    viennacl::copy(Am, vcl_A); 
    
    vcl_rowSums = viennacl::linalg::row_sum(vcl_A);
    
    viennacl::copy(vcl_rowSums, rowSums);
}


//[[Rcpp::export]]
void cpp_vienna_fgpuMatrix_colmean(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<float> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<float> > ptrC(ptrC_);
    
    MapMat<float> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<float> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_colmean<float>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_dgpuMatrix_colmean(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<double> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<double> > ptrC(ptrC_);
    
    MapMat<double> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<double> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_colmean<double>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_fgpuMatrix_colsum(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<float> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<float> > ptrC(ptrC_);
    
    MapMat<float> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<float> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_colsum<float>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_dgpuMatrix_colsum(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<double> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<double> > ptrC(ptrC_);
    
    MapMat<double> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<double> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_colsum<double>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_fgpuMatrix_rowmean(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<float> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<float> > ptrC(ptrC_);
    
    MapMat<float> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<float> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_rowmean<float>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_dgpuMatrix_rowmean(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<double> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<double> > ptrC(ptrC_);
    
    MapMat<double> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<double> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_rowmean<double>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_fgpuMatrix_rowsum(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<float> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<float> > ptrC(ptrC_);
    
    MapMat<float> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<float> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_rowsum<float>(Am, Cm, device_flag);
}

//[[Rcpp::export]]
void cpp_vienna_dgpuMatrix_rowsum(
    SEXP ptrA_, SEXP ptrC_,
    int device_flag)
{
    
    Rcpp::XPtr<dynEigen<double> > ptrA(ptrA_);
    Rcpp::XPtr<dynEigenVec<double> > ptrC(ptrC_);
    
    MapMat<double> Am(ptrA->ptr(), ptrA->nrow(), ptrA->ncol());
    MapVec<double> Cm(ptrC->ptr(), ptrC->length());

    cpp_vienna_rowsum<double>(Am, Cm, device_flag);
}
