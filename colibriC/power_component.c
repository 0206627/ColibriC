//
//  power_component.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "power_component.h"

void Batteries_ctor(PowerComponent * const me) {
    PowerComponent_ctor(&me->super, "Batteries");
}

void EPS_ctor(PowerComponent * const me) {
    PowerComponent_ctor(&me->super, "EPS");
}
