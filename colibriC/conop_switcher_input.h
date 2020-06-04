//
//  conop_switcher_input.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef conop_switcher_input_h
#define conop_switcher_input_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool power_ok;
    bool eps_temp;
    float eps_temp_value;
    bool cpu_performance_ok;
    bool sd_storage_ok;
    bool antenna_comms_ok;
    bool temp_ok;
} ConOpSwitcherInput;

void ConOpSwitcherInput_ctor(ConOpSwitcherInput * const me);

void ConOpSwitcherInput_print_flight_conditions(ConOpSwitcherInput * const me);

#endif /* conop_switcher_input_h */
