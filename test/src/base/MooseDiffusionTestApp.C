//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MooseDiffusionTestApp.h"
#include "MooseDiffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<MooseDiffusionTestApp>()
{
  InputParameters params = validParams<MooseDiffusionApp>();
  return params;
}

MooseDiffusionTestApp::MooseDiffusionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseDiffusionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MooseDiffusionTestApp::~MooseDiffusionTestApp() {}

void
MooseDiffusionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MooseDiffusionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MooseDiffusionTestApp"});
    Registry::registerActionsTo(af, {"MooseDiffusionTestApp"});
  }
}

void
MooseDiffusionTestApp::registerApps()
{
  registerApp(MooseDiffusionApp);
  registerApp(MooseDiffusionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MooseDiffusionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseDiffusionTestApp::registerAll(f, af, s);
}
extern "C" void
MooseDiffusionTestApp__registerApps()
{
  MooseDiffusionTestApp::registerApps();
}
