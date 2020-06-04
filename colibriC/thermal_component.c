//
//  thermal_component.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "thermal_component.h"

void TempSensor_ctor(ThermalComponent * const me) {
    ThermalComponent_ctor(&me->super, "Temperature Sensor");
}
