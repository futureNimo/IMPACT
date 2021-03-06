#ifndef _ROCBLAS_H_
#define _ROCBLAS_H_

class RocBlas {
public:
  RocBlas() = default;

public:
  static void init();
  static void initHandles();

public:
  static int copy;
  static int add;
  static int sub;
  static int limit1;
  static int mul;
  static int div;
  static int neg;
  static int axpy;
  static int nrm2;
  static int copy_scalar;
  static int sub_scalar;
  static int axpy_scalar;
  static int div_scalar;
  static int mul_scalar;
  static int max_scalar_MPI;
  static int min_scalar_MPI;
  static int sum_scalar_MPI;
  static int nrm2_scalar_MPI;
  static int maxof_scalar;
};

#endif //_ROCBLAS_H_
