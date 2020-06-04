//
//  con_op_manager.c
//  colibriC
//
//  Created by Mariana De la Vega on 6/3/20.
//  Copyright © 2020 Mariana De la Vega. All rights reserved.
//

#include "con_op_manager.h"

void ConOpManager_ctor(ConOpManager * const me) {
    me->status = NOMINAL;
}

enum ConOp ConOpManager_get_current_conop(ConOpManager * const me) {
    return me->status;
}

void ConOpManager_set_current_conop(ConOpManager * const me, enum ConOp conop) {
    me->status = conop;
}
