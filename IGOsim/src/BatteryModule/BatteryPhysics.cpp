﻿#include "BatteryPhysics.h"
#include "Module.h"

using namespace std;


BatteryPhysics::BatteryPhysics(shared_ptr<Module> m) : Physics(m)
{
}


BatteryPhysics::~BatteryPhysics()
{
}


void BatteryPhysics::clock(int t){
    module->setParamValueByName("voltage", module->getParamValueByName("voltage")-1);
}