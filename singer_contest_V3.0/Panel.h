#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED

#include <windows.h>
#include <string>
#include "ContestList.h"
#include <iostream>


using namespace std;

class Panel{
public:
    void P();//主面板
    void P0();
    void P1();//新比赛
    void P2();//查找/操作记录
    void P2_();
    void P2_1();//增加比赛
    void P2_2();//删除比赛
    void P2_3();//比赛中选手详情
    void P2_4();//查看选手排名第
    void P2_3_();
    void P2_3_1();//更改比赛信息
    void P2_3_2();//查找/操作选手
    void P2_3_2_1();//增加选手
    void P2_3_2_2();//删除选手
    void P2_3_2_3();//更改选手
    void P2_3_2_4();//更改选手

    Singer judge_singer(int n);//给选手评分
    void new_Contest();

    char c;
    string s;
    Contest contest;
    Singer singer;

private:
    ContestList contestList;
};

#endif // PANEL_H_INCLUDED
