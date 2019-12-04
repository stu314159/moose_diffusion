[Mesh]
  [gen]
    type = GeneratedMeshGenerator
    dim = 2
    xmin = -5
    xmax = 5
    ymin = -1
    ymax = 1
    nx = 300
    ny = 100
    elem_type = QUAD9
  []
[]

[Variables]
  [convected]
    order= SECOND
    family = LAGRANGE
  []
[]

[Functions]
  [ic]
    type = ParsedFunction
    value = exp(-(x*x))
  []
[]

[ICs]
  [ic]
    type = FunctionIC
    variable = convected
    function = ic
  []
[]

[BCs]
  [Periodic]
    [x]
    variable = convected
    primary = 'left'
    secondary = 'right'
    translation = '10 0 0'
    []
  []
[]

[Kernels]
  [diff]
    type = Diffusion
    variable = convected
  []
  
  [conv]
    type = StuConvection
    variable = convected
    velocity = '1.0 0.0 0.0'
  []
  
  [trans]
    type = TimeDerivative
    variable = convected
  []
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'
  dt = 1E-1
  end_time = 3.0
[]

[Outputs]
  file_base = test
  exodus = true
  execute_on = 'timestep_end'
[]
