#pragma once  // find out what, exactly, this does
#include "Kernel.h" // so I can inherit from it

// Forward Declarations
class StuConvection;

// declare a validParams object suitable for my class
template<>
InputParameters validParams<StuConvection>();

// actual class declaration
class StuConvection : public Kernel
{
  // constructor
  StuConvection(const InputParameters & parameters);
  
protected:
  virtual Real computeQpResidual() override;
  
  virtual Real computeQpJacobian() override;
  
private:
  RealVectorValue _velocity; // convecting velocity

};//<-- don't forget this!!!
