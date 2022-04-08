#include "ContestList.h"

void ContestList::addContest(Contest contest)
{
    if(contests.find(contest)== NULL)
        contests.add_tail(contest);
    else
        cerr<<"ERROR: 已经存在比赛!"<<endl;
}

void ContestList::loadContests(istream &is)
{
    int n;
    long long id;
    Date date;
    string loc;
    is>>n;
    while(n--){
        is>>id;
        is>>loc;
        is>>date;
        Contest contest(id, loc, date);
        contest.loadSingers(is);
        contests.add_tail(contest);
    }
}

void ContestList::deleteContest(Contest contest)
{
    if(contests.find(contest)!= NULL)
        contests.Delete(contest);
    else
        cerr<<"ERROR: 没有可以删除的比赛!"<<endl;
}

bool ContestList::idExists(long long id)
{
    node<Contest>* sptr;
    Contest contest(id);
    sptr = contests.find(contest);
    if(sptr!=NULL){
        return true;
    }
    else return false;
}

Contest ContestList::findById(long long id)
{
    node<Contest>* sptr;
    Contest contest(id);
    sptr = contests.find(contest);
    if(sptr!=NULL){
        contest = sptr->data;
        return contest;
    }
    else return Contest(-1);
}

vector<Contest> ContestList::findByDate(Date date)
{
    vector<Contest> v;
    linkedList<Contest>::MyIterator it = contests.begin();
    while(!it.isNull()){
        if(date == (*it).getDate()) v.push_back(*it);
        it++;
    }
    return v;
}

vector<Contest> ContestList::findByLoc(string loc)
{
    vector<Contest> v;
    linkedList<Contest>::MyIterator it = contests.begin();
    while(!it.isNull()){
        if(loc == (*it).getCloc()) v.push_back(*it);
        it++;
    }
    return v;
}

void ContestList::saveContests(ostream &os)
{
    os << contests.list_size()<<endl;
    linkedList<Contest>::MyIterator it = contests.begin();
    for(int i = 0; i < contests.list_size(); i++){
        (*it).saveContest(os << '\t');
        it++;
    }
}

void ContestList::display()
{
    contests.display();
}
