#include "StuConvection.h"

registerMooseObject("MooseDiffusion",StuConvection);

template<>
InputParameters
validParams<StuConvection>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<RealVectorValue>("velocity","Velocity Vector");
  return params;
}

StuConvection::StuConvection(const InputParameters & parameters)
  : Kernel(parameters), _velocity(getParam<RealVectorValue>("velocity"))
{

}

Real
StuConvection::computeQpResidual()
{
  return _test[_i][_qp] * (_velocity * _grad_u[_qp]);
}

Real
StuConvection::computeQpJacobian()
{
  return _test[_i][_qp] * (_velocity * _grad_phi[_j][_qp]);
}
