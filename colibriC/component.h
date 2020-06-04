//
//  component.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef component_h
#define component_h

#include <stdio.h>
#include <stdbool.h>
#include "component_report.h"

typedef struct {
    char * component_name;
    char * component_subsystem;
    float storage_free_percentage;
    float performance_percentage;
    bool comms_check;
    float battery_charge;
    float temp;
    ComponentReport report;
} Component;

void Component_ctor(Component * const me, char *component_name, char *component_subsystem);

ComponentReport Component_report_status(Component * const me);

void Component_set_conop_mode(Component * const me);

void Component_start_behaviour(Component* const me, enum ConOp conop);

const char* Component_get_name(Component * const me);

const char* Component_get_subsystem(Component * const me);

/* ------------------------------------------------------- */
 
 typedef struct {
     Component super;
     float battery_charge;
 } PowerComponent;

 void PowerComponent_ctor(PowerComponent * const me, char *component_name);

 PowerReport PowerComponent_report_status(PowerComponent * const me);

/* -------------------------------------------------------- */

typedef struct {
    Component super;
    float storage_free_percentage;
    float performance_percentage;
} AvionicsComponent;

void AvionicsComponent_ctor(AvionicsComponent * const me, char *component_name);

AvionicsReport AvionicsComponent_report_status(AvionicsComponent * const me);

/* -------------------------------------------------------- */

typedef struct {
    Component super;
    bool comms_check;
} CommsComponent;

void CommsComponent_ctor(CommsComponent * const me, char *component_name);

CommsReport CommsComponent_report_status(CommsComponent * const me);

/* -------------------------------------------------------- */

typedef struct {
    Component super;
    float temp;
} ThermalComponent;

void ThermalComponent_ctor(ThermalComponent * const me, char *component_name);

ThermalReport ThermalComponent_report_status(ThermalComponent * const me);

#endif /* component_h */
