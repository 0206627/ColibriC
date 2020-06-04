//
//  thermal_component.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef thermal_component_h
#define thermal_component_h

#include <stdio.h>
#include "component.h"

typedef struct {
    ThermalComponent super;
} TempSensor;

void TempSensor_ctor(ThermalComponent * const me);

#endif /* thermal_component_h */
