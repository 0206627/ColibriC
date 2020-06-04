//
//  enums.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef enums_h
#define enums_h

#include <stdio.h>

enum ConOp {
    NOMINAL = 0,
    COMMS = 1,
    LOW_ENERGY = 2,
    PAYLOAD_OPERATIONS = 3,
    CONTINGENCY = 4
};

enum ComponentStatus {
    OPERATIONAL = 0,
    NEEDS_MAINTENANCE = 1,
    ERROR = 2
};

enum ComponentHealth {
    HEALTHY = 0,
    DAMAGED = 1,
    FATAL = 2
};

#endif /* enums_h */
