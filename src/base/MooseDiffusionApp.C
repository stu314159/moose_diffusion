#include "MooseDiffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<MooseDiffusionApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MooseDiffusionApp::MooseDiffusionApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseDiffusionApp::registerAll(_factory, _action_factory, _syntax);
}

MooseDiffusionApp::~MooseDiffusionApp() {}

void
MooseDiffusionApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MooseDiffusionApp"});
  Registry::registerActionsTo(af, {"MooseDiffusionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MooseDiffusionApp::registerApps()
{
  registerApp(MooseDiffusionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MooseDiffusionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseDiffusionApp::registerAll(f, af, s);
}
extern "C" void
MooseDiffusionApp__registerApps()
{
  MooseDiffusionApp::registerApps();
}
