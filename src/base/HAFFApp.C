#include "HAFFApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
HAFFApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

HAFFApp::HAFFApp(InputParameters parameters) : MooseApp(parameters)
{
  HAFFApp::registerAll(_factory, _action_factory, _syntax);
}

HAFFApp::~HAFFApp() {}

void
HAFFApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"HAFFApp"});
  Registry::registerActionsTo(af, {"HAFFApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
HAFFApp::registerApps()
{
  registerApp(HAFFApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
HAFFApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HAFFApp::registerAll(f, af, s);
}
extern "C" void
HAFFApp__registerApps()
{
  HAFFApp::registerApps();
}
