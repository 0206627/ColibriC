//
//  comms_component.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef comms_component_h
#define comms_component_h

#include <stdio.h>
#include "component.h"

typedef struct {
    CommsComponent super;
} Antenna;

void Antenna_ctor(CommsComponent * const me);

#endif /* comms_component_h */
