# generates a Disc Mesh
# Radius of outside circle = 5
# solves the diffusion equation with u = -5 at the origin, and u=0 on outside
[Mesh]
 type = AnnularMesh
 nr = 10
 nt = 12
 rmin = 0
 rmax = 5
 growth_r = 1.3
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./inner] 
    type = PresetBC
    variable = u
    value = -5.0
    boundary = rmin
  [../]
  [./outer]
    type = PresetBC
    variable = u
    value = 0.0
    boundary = rmax
   [../]
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
[]
