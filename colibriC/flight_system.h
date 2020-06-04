//
//  flight_system.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef flight_system_h
#define flight_system_h

#include <stdio.h>
#include "component.h"
#include "conop_switcher_input.h"
#include "enums.h"

typedef struct {
    Component component_list[20];
    int list_count;
    ConOpSwitcherInput conop_switcher_input;
} FlightSystem;

void FlightSystem_ctor(FlightSystem * const me);

void FlightSystem_add_component(FlightSystem * const me, Component component);

void FlightSystem_list_all_components(FlightSystem * const me);

void FlightSystem_print_flight_conditions(FlightSystem * const me);

enum ConOp FlightSystem_decide_con_op_mode(FlightSystem * const me, ConOpSwitcherInput conop_switcher_input, enum ConOp current_conop);

static ConOpSwitcherInput FlightSystem_report_handler(ConOpSwitcherInput conop_switcher_input, ComponentReport report, char *component_id);

ConOpSwitcherInput FlightSystem_retrieve_flight_conditions(FlightSystem * const me);

#endif /* flight_system_h */
