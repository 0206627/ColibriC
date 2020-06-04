//
//  flight_system.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "flight_system.h"
#include <string.h>

void FlightSystem_ctor(FlightSystem * const me) {
    me->list_count = -1;
    ConOpSwitcherInput switcher;
    ConOpSwitcherInput_ctor(&switcher);
    me->conop_switcher_input = switcher;
}

void FlightSystem_add_component(FlightSystem * const me, Component component) {
    if (me->list_count == -1) me->list_count = 0;
    me->component_list[me->list_count] = component;
    me->list_count++;
}

void FlightSystem_list_all_components(FlightSystem * const me) {
    for (int cont = 0; cont < me->list_count; cont++) {
        printf(me->component_list[cont].component_name);
        printf("\n");
    }
}

void FlightSystem_print_flight_conditions(FlightSystem * const me) {
    ConOpSwitcherInput_print_flight_conditions(&(me->conop_switcher_input));
}

enum ConOp FlightSystem_decide_con_op_mode(FlightSystem * const me, ConOpSwitcherInput conop_switcher_input, enum ConOp current_conop) {
    
    if (!conop_switcher_input.antenna_comms_ok||!conop_switcher_input.temp_ok) return CONTINGENCY;
    if (!conop_switcher_input.power_ok||!conop_switcher_input.cpu_performance_ok||!conop_switcher_input.sd_storage_ok) return NOMINAL;
    if (conop_switcher_input.power_ok && current_conop == NOMINAL) return PAYLOAD_OPERATIONS;
    
    return current_conop;
}

ConOpSwitcherInput FlightSystem_retrieve_flight_conditions(FlightSystem * const me) {
    for (int cont = 0; cont < me->list_count; cont++) {
        ComponentReport report;
        report = Component_report_status(&(me->component_list[cont]));
        char *component_id = me->component_list[cont].component_name;
        me->conop_switcher_input = FlightSystem_report_handler(me->conop_switcher_input, report, component_id);
    }

    return me->conop_switcher_input;
}

static ConOpSwitcherInput FlightSystem_report_handler(ConOpSwitcherInput conop_switcher_input, ComponentReport report, char *component_id) {
    
    if (strcmp(component_id, "Batteries") == 0) {
        if (report.battery_charge > 0.5) conop_switcher_input.power_ok = true;
        else conop_switcher_input.power_ok = false;
    } else if (strcmp(component_id, "CPU") == 0) {
        if (report.performance_percentage > 0.7) conop_switcher_input.cpu_performance_ok = true;
        else conop_switcher_input.cpu_performance_ok = false;
    } else if (strcmp(component_id, "SD") == 0) {
        if (report.storage_free_percentage > 0.1) conop_switcher_input.sd_storage_ok = true;
        else conop_switcher_input.sd_storage_ok = false;
    } else if (strcmp(component_id, "Antenna") == 0) {
        if (report.comms_check) conop_switcher_input.antenna_comms_ok = true;
        else conop_switcher_input.antenna_comms_ok = false;
    } else if (strcmp(component_id, "Temperature Sensor") == 0) {
        if (report.temp < 100||report.temp>0) conop_switcher_input.temp_ok = true;
        else conop_switcher_input.temp_ok = false;
    }
    
    return conop_switcher_input;
}

