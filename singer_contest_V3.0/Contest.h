#ifndef CONTEST_H_INCLUDED
#define CONTEST_H_INCLUDED
#include <iostream>
#include <time.h>
#include <vector>
#include "linkedList.cpp"
#include "Singer.h"
#include "Date.h"
class Contest{
public:
    Contest(long long _Cid = 0, string _Cloc = "", Date _Cdate = Date(), linkedList<Singer> _singers = linkedList<Singer>());
    Contest(const Contest& _c);

    long long getCid(){return Cid;}
    string getCloc(){return Cloc;}
    Date getDate(){return Cdate;}
    int getSize(){return singers.list_size();}
    linkedList<Singer>& getSingers(){return singers;}

    void addSinger(Singer singer);//增加歌手
    void loadSingers(istream &is);//加载歌手
    void saveContest(ostream &os);//保存比赛
    Singer findById(long long id);//按id寻找
    vector<Singer> findByName(string name);//按姓名寻找
    vector<Singer> findByX(int x);//查找前X位

    bool idExists(long long id);//判断是否存在id
    void deleteSinger(Singer singer);//删除歌手
    bool setSinger(Singer singer);//更改歌手信息
    void display();

    void sortById(){singers.sort();}//按歌手id排序
    void sortByAvg(){singers.sortByAvg();}//按均分排序
    void sortByGradeI(int i){singers.sortByGradeI(i);}//按第i个评委的评分排序

    bool operator<(Contest obj){return Cid < obj.Cid;}
    bool operator>(Contest obj){return Cid > obj.Cid;}
    bool operator==(Contest obj){return Cid == obj.Cid;}
    Contest& operator=(const Contest& _c);

    friend ostream& operator<<(ostream& os, Contest con);

private:
    long long Cid;
    string Cloc;
    Date Cdate;
    linkedList<Singer> singers;
};

/*
class ContestUtil{
public:
    void newContest();
    bool searchContestById(long long contestID);
private:
    List<Contest> contests;
};
*/

#endif // CONTEST_H_INCLUDED
