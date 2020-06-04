//
//  con_op_manager.h
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#ifndef con_op_manager_h
#define con_op_manager_h

#include <stdio.h>
#include "enums.h"

typedef struct {
    enum ConOp status;
} ConOpManager;

void ConOpManager_ctor(ConOpManager * const me);

enum ConOp ConOpManager_get_current_conop(ConOpManager * const me);

void ConOpManager_set_current_conop(ConOpManager * const me, enum ConOp conop);

#endif /* con_op_manager_h */

