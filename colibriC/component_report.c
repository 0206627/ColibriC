//
//  component_report.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "component_report.h"
#include "enums.h"
#include <time.h>

void ComponentReport_ctor(ComponentReport * const me) {
    me->component_health = HEALTHY;
    me->status = OPERATIONAL;
    me->time = time(0);
    me->battery_charge = 1.0;
    me->storage_free_percentage = 1.0;
    me->performance_percentage = 1.0;
    me->comms_check = true;
    me->temp = 60.0;
}

/* ------------------------------------------------------ */

void PowerReport_ctor(PowerReport * const me) {
    ComponentReport_ctor(&me->super);
    me->super.battery_charge = 1.0;
}

/* ------------------------------------------------------ */

void AvionicsReport_ctor(AvionicsReport * const me) {
    ComponentReport_ctor(&me->super);
    me->super.storage_free_percentage = 1.0;
    me->super.performance_percentage = 1.0;
}

/* ------------------------------------------------------ */

void CommsReport_ctor(CommsReport * const me) {
    ComponentReport_ctor(&me->super);
    me->super.comms_check = true;
}

/* ------------------------------------------------------ */

void ThermalReport_ctor(ThermalReport * const me) {
    ComponentReport_ctor(&me->super);
    me->super.temp = 60.0;
}

