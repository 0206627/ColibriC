//
//  main.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "component.h"
#include "power_component.h"
#include "flight_system.h"
#include "comms_component.h"
#include "avionics_component.h"
#include "thermal_component.h"
#include "con_op_manager.h"
#include <stdio.h>
#include <string.h>

int main(int argc) {
    
    FlightSystem flight_system;
    FlightSystem_ctor(&flight_system);
    
    Antenna antenna;
    Antenna_ctor(&antenna);
    Batteries battery;
    Batteries_ctor(&battery);
    CPU cpu;
    CPU_ctor(&cpu);
    SD sd;
    SD_ctor(&sd);
    TempSensor temp_sensor;
    TempSensor_ctor(&temp_sensor);
    
    FlightSystem_add_component(&flight_system, antenna.super.super);
    FlightSystem_add_component(&flight_system, battery.super.super);
    FlightSystem_add_component(&flight_system, cpu.super.super);
    FlightSystem_add_component(&flight_system, sd.super.super);
    FlightSystem_add_component(&flight_system, temp_sensor.super.super);
    
    ConOpManager conOp;
    ConOpManager_ctor(&conOp);
    
    while(true) {
        printf( "Battery charge % [0.0, 1.0]: ");
        scanf("%f", &battery.super.battery_charge);
        printf( "Antenna communication [True, False]: ");
        char aux[100];
        scanf("%s", aux);
        if (strcmp(aux,"True") == 0) antenna.super.comms_check = true;
        else antenna.super.comms_check = false;
        printf( "CPU performance % [0.0, 1.0]: ");
        scanf("%f", &cpu.super.performance_percentage);
        printf( "SD storage free % [0.0, 1.0]: ");
        scanf("%f", &sd.super.storage_free_percentage);
        printf( "Temperature sensor temp ºC [-10, 150]: ");
        scanf("%f", &temp_sensor.super.temp);
        
        enum ConOp current_conop = ConOpManager_get_current_conop(&conOp);
        ConOpSwitcherInput flight_conditions;
        flight_conditions = FlightSystem_retrieve_flight_conditions(&flight_system);
        enum ConOp new_conop = FlightSystem_decide_con_op_mode(&flight_system, flight_conditions, current_conop);
        printf("\n");
        printf("Before: %d\n\n", (int)current_conop);
        FlightSystem_print_flight_conditions(&flight_system);
        printf("\nAfter: %d\n\n", (int)new_conop);
        printf("");
        printf("------------------------------");
        printf("\n\n");
    }
    
    return 0;
}

