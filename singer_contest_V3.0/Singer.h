#ifndef SINGER_H_INCLUDED
#define SINGER_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Singer{
public:
    Singer(long long _Sid = 0, string _Sname = "$", vector<double> _grades = vector<double>());
    Singer(int){Sid = -1;}
    Singer(const Singer& _s);

    void saveSinger(ostream &os);

    long long getSid(){return Sid;}
    string getSname(){return Sname;}
    vector<double> getGrades(){return grades;}

    void setSid(long long id){Sid = id;}
    void setSname(string name){Sname = name;}
    void setGrades(double mark, int i){grades[i] = mark;}

    double getGradeSum() const;
    double getGradeAvg() const;
    double getGradeAvgP() const;//改良的平均分（去掉最高分，最低分）
    double getGrade(int i) const {return grades[i];}

    void addMark(double grade);//增加评委评分
    bool operator<(Singer obj){return Sid < obj.Sid;}
    bool operator>(Singer obj){return Sid > obj.Sid;}
    bool operator==(Singer obj){return Sid == obj.Sid;}
    Singer& operator=(const Singer& _s);

    friend ostream& operator<<(ostream& os, Singer s);//输出流

    void display() const;

private:
    long long Sid;//id
    string Sname;//歌手姓名
    vector<double> grades;//歌手成绩
};

//
//bool (*cmp_array[])(Singer x, Singer y) = {
//    CompareByGradeAVG, CompareById
//};

#endif // SINGER_H_INCLUDED
