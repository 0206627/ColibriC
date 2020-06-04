//
//  conop_switcher_input.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "conop_switcher_input.h"

void ConOpSwitcherInput_ctor(ConOpSwitcherInput * const me) {
    me->power_ok = false;
    me->eps_temp = false;
    me->eps_temp_value = 0.0;
    me->cpu_performance_ok = false;
    me->sd_storage_ok = false;
    me->antenna_comms_ok = false;
    me->temp_ok = false;
}

void ConOpSwitcherInput_print_flight_conditions(ConOpSwitcherInput * const me) {
    printf("Flight conditions:\n");
    printf("power_ok: %s\n", me->power_ok ? "true" : "false");
    printf("cpu_performance_ok: %s\n", me->cpu_performance_ok ? "true" : "false");
    printf("sd_storage_ok: %s\n", me->sd_storage_ok ? "true" : "false");
    printf("antenna_comms_ok: %s\n", me->antenna_comms_ok ? "true" : "false");
    printf("temp_ok: %s\n", me->temp_ok ? "true" : "false");
}

