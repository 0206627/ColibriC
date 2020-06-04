//
//  component_report.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef component_report_h
#define component_report_h

#include <stdio.h>
#include <stdbool.h>
#include<time.h>
#include "enums.h"

typedef struct {
    enum ComponentStatus status;
    enum ComponentHealth component_health;
    float battery_charge;
    float storage_free_percentage;
    float performance_percentage;
    bool comms_check;
    float temp;
    time_t time;
} ComponentReport;

void ComponentReport_ctor(ComponentReport * const me);

/* ------------------------------------------------------- */
 
 typedef struct {
     ComponentReport super;
     float battery_charge;
 } PowerReport;

 void PowerReport_ctor(PowerReport * const me);

/* -------------------------------------------------------- */

typedef struct {
    ComponentReport super;
    float storage_free_percentage;
    float performance_percentage;
} AvionicsReport;

void AvionicsReport_ctor(AvionicsReport * const me);

/* -------------------------------------------------------- */

typedef struct {
    ComponentReport super;
    bool comms_check;
} CommsReport;

void CommsReport_ctor(CommsReport * const me);

/* -------------------------------------------------------- */

typedef struct {
    ComponentReport super;
    float temp;
} ThermalReport;

void ThermalReport_ctor(ThermalReport * const me);

#endif /* component_report_h */

