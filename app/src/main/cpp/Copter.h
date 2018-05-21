//
// Created by yanchunlan on 2018/5/21.
//

#ifndef CPLUSPLUSDEMO_COPTER_H
#define CPLUSPLUSDEMO_COPTER_H

#endif //CPLUSPLUSDEMO_COPTER_H


#pragma once

#include "Plane.h"

// 喷气飞机
class Copter: public Plane {

    virtual void fly();

    virtual void land();
};