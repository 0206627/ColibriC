//
//  avionics_component.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef avionics_component_h
#define avionics_component_h

#include <stdio.h>
#include "component.h"

typedef struct {
    AvionicsComponent super;
} CPU;

void CPU_ctor(AvionicsComponent * const me);

typedef struct {
    AvionicsComponent super;
} SD;

void SD_ctor(AvionicsComponent * const me);


#endif /* avionics_component_h */
