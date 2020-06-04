//
//  avionics_component.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "avionics_component.h"

void CPU_ctor(AvionicsComponent * const me) {
    AvionicsComponent_ctor(&me->super, "CPU");
}

void SD_ctor(AvionicsComponent * const me) {
    AvionicsComponent_ctor(&me->super, "SD");
}
