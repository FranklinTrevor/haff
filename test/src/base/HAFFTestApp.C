//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "HAFFTestApp.h"
#include "HAFFApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
HAFFTestApp::validParams()
{
  InputParameters params = HAFFApp::validParams();
  return params;
}

HAFFTestApp::HAFFTestApp(InputParameters parameters) : MooseApp(parameters)
{
  HAFFTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

HAFFTestApp::~HAFFTestApp() {}

void
HAFFTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  HAFFApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"HAFFTestApp"});
    Registry::registerActionsTo(af, {"HAFFTestApp"});
  }
}

void
HAFFTestApp::registerApps()
{
  registerApp(HAFFApp);
  registerApp(HAFFTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
HAFFTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HAFFTestApp::registerAll(f, af, s);
}
extern "C" void
HAFFTestApp__registerApps()
{
  HAFFTestApp::registerApps();
}
