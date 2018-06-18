//
// Created by Administrator on 2018/6/17.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

//队列（没有迭代器）
void main() {
    queue<int> q;
    q.push(78);
    q.push(18);
    q.push(20);
    q.push(33);

    while (!q.empty()) {
        int tmp = q.front();
        cout << tmp << endl;
        q.pop();
    }
}

#include <functional>

void main1(){


};