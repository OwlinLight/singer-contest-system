#include <iostream>
#include <windows.h>
#include <fstream>
#include "ContestList.h"
#include "Panel.h"
using namespace std;

void test_singer(){
    Singer singer(22298, "仝卓");
    double grade;
    while(1){
        cout << "mark" << endl;
        cin>>grade;
        if(grade == -1) break;
        singer.addMark(grade);
    }
    cout << singer;
}

Singer judge_singer(){
    Singer singer(22298, "同桌");
    double grade;
    int n;
    cout << "输入评委的人数" << endl;
    cin >> n;
    while(n--){
        cout << "mark" << endl;
        cin>>grade;
        singer.addMark(grade);
    }
    return singer;
}

void test_Search(){
    Contest contest(101, "Chengdu");
    Singer s1(1, "wang"), s2(2, "trump"), s3(3, "sanders");
    contest.addSinger(s1);
    contest.addSinger(s2);
    contest.addSinger(s3);
    cout << "查找" << endl;
    cout << contest.findById(2);
    cout << contest;
}

void test_delete(){
    Contest contest(101, "Chengdu");
    Singer s1(1, "wang"), s2(2, "trump"), s3(3, "sanders");
    Singer s(1, "zhang");
    contest.addSinger(s1);
    contest.addSinger(s2);
    contest.addSinger(s3);
    contest.addSinger(s3);
    cout << "删除" << endl;
    contest.setSinger(s);
    cout << contest;
}

void test_Contest(){
    Contest contest(101, "Chengdu");
    int n = 3;
    cout << "输入评委数" << endl;
    cin >> n;
    while(n--){
        contest.addSinger(judge_singer());
    }
    contest.getSingers().sortByGradeI(3);
    cout << contest;
}

void test_ContestList(){
    ContestList cl;
    Contest c1(101, "Chengdu"), c2(102, "hangzhou"), c3(103, "guangdong");
    cl.addContest(c1);
    cl.addContest(c2);
    cl.addContest(c3);
    cl.display();
}

void test_ignore(){
    string s;
    int y, m, d;
    cin.ignore(0, '/');
    cin >> y >> m >> d;
    cout << y << m << d;
}

void test_Load(){
    ContestList cl;
    string s;
    ifstream  ifs ("data.txt");
    ofstream ofs("data_out.txt");
    cl.loadContests(ifs);
    Contest c1(101, "Chengdu", Date(1999, 11, 26));
    cl.addContest(c1);
    cl.display();
    cl.saveContests(ofs);
    ifs.close();
    ofs.close();
}

void test_search(){
    ContestList cl;
    string s;
    ifstream  ifs ("data_out.txt");
    cl.loadContests(ifs);
    ifs.close();
    Date d(2011);
    vector<Contest> v = cl.findByDate(d);
    cout << v.size();
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
}

void test_Date(){
    Date d1(2011, 0, 0), d2(2011, 1, 1);
    cout << (d1 == d2);
}

int main()
{
    Panel p;
    p.P0();
//    test_search();
    return 0;
}
