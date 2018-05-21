//
// Created by yanchunlan on 2018/5/21.
//

#ifndef CPLUSPLUSDEMO_JET_H
#define CPLUSPLUSDEMO_JET_H

#endif //CPLUSPLUSDEMO_JET_H


#pragma once

#include "Plane.h"

// 直升飞机
class Jet: public Plane {

    virtual  void fly();

    virtual void land();
};