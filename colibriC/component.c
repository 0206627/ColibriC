//
//  component.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "component.h"

void Component_ctor(Component * const me, char component_name[], char component_subsystem[]) {
    me -> component_name = component_name;
    me -> component_subsystem = component_subsystem;
}

ComponentReport Component_report_status(Component * const me) {
    ComponentReport report;
    ComponentReport_ctor(&report);
    report.battery_charge = me->battery_charge;
    report.comms_check = me->comms_check;
    report.performance_percentage = me->performance_percentage;
    report.storage_free_percentage = me->storage_free_percentage;
    report.temp = me->temp;
    me->report = report;
    return me->report;
}

void Component_set_conop_mode(Component * const me) {
    printf("Not implemented");
}

void Component_start_behaviour(Component* const me, enum ConOp conop) {
    printf("Not implemented");
}

const char* Component_get_name(Component * const me) {
    return me->component_name;
}
const char* Component_get_subsystem(Component * const me) {
    return me->component_subsystem;
}

/* ------------------------------------------------------ */

void PowerComponent_ctor(PowerComponent * const me, char *component_name) {
    Component_ctor(&me->super, component_name, "Power");
    me->super.battery_charge = 1.0;
}

PowerReport PowerComponent_report_status(PowerComponent * const me) {
    PowerReport report;
    PowerReport_ctor(&report);
    report.super.battery_charge = me->battery_charge;
    return report;
}

/* ------------------------------------------------------ */

void AvionicsComponent_ctor(AvionicsComponent * const me, char *component_name) {
    Component_ctor(&me->super, component_name, "Avionics");
    me->super.storage_free_percentage = 1.0;
    me->super.performance_percentage = 1.0;
}

AvionicsReport AvionicsComponent_report_status(AvionicsComponent * const me) {
    AvionicsReport report;
    AvionicsReport_ctor(&report);
    report.super.storage_free_percentage = me->storage_free_percentage;
    report.super.performance_percentage = me->performance_percentage;
    return report;
}

/* ------------------------------------------------------ */

void CommsComponent_ctor(CommsComponent * const me, char *component_name) {
    Component_ctor(&me->super, component_name, "Comms");
    me->super.comms_check = true;
}

CommsReport CommsComponent_report_status(CommsComponent * const me) {
    CommsReport report;
    CommsReport_ctor(&report);
    report.super.comms_check = me->comms_check;
    return report;
}

/* ------------------------------------------------------ */

void ThermalComponent_ctor(ThermalComponent * const me, char *component_name) {
    Component_ctor(&me->super, component_name, "Thermal");
    me->super.temp = 60.0;
}

ThermalReport ThermalComponent_report_status(ThermalComponent * const me) {
    ThermalReport report;
    ThermalReport_ctor(&report);
    report.super.temp = me->temp;
    return report;
}


