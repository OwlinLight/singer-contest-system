#include "Singer.h"
Singer::Singer(long long _Sid, string _Sname, vector<double> _grades): Sid(_Sid), Sname(_Sname), grades(_grades)
{}

Singer::Singer(const Singer& _s)
{
    Sid = _s.Sid;
    Sname = _s.Sname;
    grades = _s.grades;
}

Singer& Singer::operator=(const Singer& _s)
{
    Sid = _s.Sid;
    Sname = _s.Sname;
    grades = _s.grades;
    return *this;
}

void Singer::saveSinger(ostream &os)
{
    os << Sid << endl;
    os << Sname << endl;
    os << grades.size() << endl;
    for(int i = 0; i < grades.size(); i++){
        os << grades[i] << endl;
    }
}


double Singer::getGradeSum() const
{
    double sum = 0;
    int n = grades.size();
    for(int i = 0; i < n; i++){
        sum += grades[i];
    }
    return sum;
}

double Singer::getGradeAvgP() const
{
    double sum = 0;
    if(grades.size()<= 2){
        cerr<<"MESSAGE: 小于两个成绩，不再去除最高分和最低分!" << endl;
        return getGradeAvg();
    }
    vector<double> g = grades;
    g.pop_back();
    g.erase(g.begin());
    int n = g.size();
    for(int i = 0; i < n; i++){
        sum += grades[i];
    }
    return sum/n;
}

double Singer::getGradeAvg() const
{
    double avg = 0;
    avg = getGradeSum()/grades.size();
    return avg;
}

void Singer::addMark(double grade)
{
    grades.push_back(grade);
}

void Singer::display() const
{
    cout << *this;
}

ostream& operator<<(ostream& os, Singer s)
{
    os << "选手姓名: " << s.Sname << endl;
    os << "选手ID: " << s.Sid << endl;
    for(int i = 0; i < s.grades.size(); i++){
        os << "评委打分" << i+1 << ": " << s.grades[i] << endl;
    }
    double result;
    result = s.getGradeSum();
    os <<"总分数: " << result << endl;
    os << "平均分: " << s.getGradeAvgP() << endl;
    return os;
}
