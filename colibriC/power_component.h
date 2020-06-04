//
//  power_component.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef power_component_h
#define power_component_h

#include <stdio.h>
#include "component.h"

typedef struct {
    PowerComponent super;
} Batteries;

void Batteries_ctor(PowerComponent * const me);

typedef struct {
    PowerComponent super;
} EPS;

void EPS_ctor(PowerComponent * const me);

#endif /* power_component_h */
