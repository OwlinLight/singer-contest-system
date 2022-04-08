#ifndef CONTESTLIST_H_INCLUDED
#define CONTESTLIST_H_INCLUDED
#include "Contest.h"
class ContestList{
public:
    ContestList(){}
    ContestList(const ContestList &_cl){contests = _cl.contests;}

    void addContest(Contest contest);//添加比赛
    void loadContests(istream &is);//加载比赛
    void saveContests(ostream &os);//增添比赛
    bool idExists(long long id);//判断id是否存在
    Contest findById(long long id);//按id查找
    vector<Contest> findByDate(Date date);//按日期查找
    vector<Contest> findByLoc(string loc);//按位置查找
    void deleteContest(Contest contest);//删除比赛
    void display();

private:
    linkedList<Contest> contests;
};



#endif // CONTESTLIST_H_INCLUDED
