#include "Contest.h"


Contest::Contest(long long _Cid, string _Cloc, Date _Cdate, linkedList<Singer> _singers):Cid(_Cid), Cloc(_Cloc), Cdate(_Cdate), singers(_singers){}
Contest::Contest(const Contest& _c){
    Cid = _c.Cid;
    Cdate = _c.Cdate;
    Cloc = _c.Cloc;
    singers = _c.singers;
}

void Contest::addSinger(Singer singer)
{
    if(singers.find(singer)== NULL)
        singers.add_tail(singer);
    else
        cerr<<"ERROR: 插入失败!"<<endl;
}
void Contest::loadSingers(istream &is)
{
    int n,m;
    long long id;
    string name;
    double grade;
    is>>n;
    while(n--){
        is>>id;
        is>>name;
        is>>m;
        vector<double> grades;
        while(m--){
            is>>grade;
            grades.push_back(grade);
        }
        Singer singer(id, name, grades);
        singers.add_tail(singer);
    }
}

void Contest::deleteSinger(Singer singer)
{
    if(singers.find(singer)!= NULL)
        singers.Delete(singer);
    else
        cerr<<"ERROR:选手不存在!"<<endl;
}

bool Contest::setSinger(Singer singer)
{
    return singers.set_data(singer);
}

Singer Contest::findById(long long id)
{
    node<Singer>* sptr;
    Singer singer(id);
    sptr = singers.find(singer);
    singer = sptr->data;
    return singer;
}

bool Contest::idExists(long long id)
{
    node<Singer>* sptr;
    Singer singer(id);
    sptr = singers.find(singer);
    if(sptr != NULL){
        singer = sptr->data;
        return true;
    }
    else
        return false;
}

vector<Singer> Contest::findByName(string name)
{
    vector<Singer> v;
    linkedList<Singer>::MyIterator it = singers.begin();
    while(!it.isNull()){
        if(name == (*it).getSname()) v.push_back(*it);
        it++;
    }
    return v;
}
vector<Singer> Contest::findByX(int x)
{
    vector<Singer> v;
    linkedList<Singer>::MyIterator it = singers.begin();
    while(!it.isNull()&&x>0){
        v.push_back(*it);
        it++;
        x--;
    }
    return v;
}


Contest& Contest::operator=(const Contest& _c)
{
    Cid = _c.Cid;
    Cdate = _c.Cdate;
    Cloc = _c.Cloc;
    singers = _c.singers;
    return *this;
}

ostream& operator<<(ostream& os, Contest con)
{
    os << "比赛地点: " << con.Cloc << endl;
    os << "比赛ID: " << con.Cid << endl;
    os << "比赛日期: " << con.Cdate << endl;
    linkedList<Singer> singers = con.singers;
    int n = singers.list_size();
    linkedList<Singer>::MyIterator it = singers.begin();
    for(int i = 1; i <= n && i < 3; i++){
        os <<'\t'<< "" << i << ": "<<endl;
        os <<'\t'<< "选手ID: " << (*it).getSid() << endl;
        os <<'\t'<< "选手姓名: " << (*it).getSname() << endl;
        it++;
    }
    os << "..." << "共" << n << "人" << endl;
    return os;
}

void Contest::saveContest(ostream &os)
{
    os << Cid << endl;
    os << Cloc << endl;
    os << Cdate << endl;
    os << singers.list_size()<<endl;
    linkedList<Singer>::MyIterator it = singers.begin();
    for(int i = 0; i < singers.list_size(); i++){
        (*it).saveSinger(os << '\t');
        it++;
    }
}

void Contest::display()
{
    cout << *this;
}
