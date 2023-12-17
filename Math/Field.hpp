#ifndef _Math_FIELD_H_
#define _Math_FIELD_H_

#pragma once
#include <complex>

using complex = std::complex<double>;

template <typename T>
class Field {
 public:
  using ObjectType = T;

  virtual ObjectType GetPrimitiveRoot(int64_t power) = 0;
};

 class ComplexField: public Field<complex> {
 public:
  ObjectType GetPrimitiveRoot(int64_t power) override;
};


#endif //_Math_FIELD_H_
