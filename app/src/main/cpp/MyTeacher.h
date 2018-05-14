//
// Created by yanchunlan on 2018/5/15.
//

#ifndef CPLUSPLUSDEMO_MYTEACHER_H
#define CPLUSPLUSDEMO_MYTEACHER_H

#endif //CPLUSPLUSDEMO_MYTEACHER_H

#pragma once // 防止循环引用

class MyTeacher1 {
public:
    int age;
    char* name;

public:
    void setAge(int age);

    int getAge();

    void setName(char *name);

    char *getName();
};


