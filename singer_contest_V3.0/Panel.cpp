#include "Panel.h"
#include <fstream>

void Panel::P0()
{
    while(1){
        system("cls");
        cout<<"    ------------------------------------------------------\n";
		cout<<"    |           欢迎进入歌手比赛管理系统                     |"<<endl;
	    cout<<"    |           1.进入系统                                   |"<<endl;
		cout<<"    |           0.登出系统              版权所有侵权必究 |"<<endl;
		cout<<"    ------------------------------------------------------\n";
    	cout<<"               请选择（1/0）：";

        cin >> c;//为什么在错过一次过后就不执行了？->因为每次都会reload()
        system("cls");
        if(c == '1'){
            ifstream  ifs ("data.txt");
            contestList.loadContests(ifs);
            ifs.close();
            cout << "加载文件内容成功" << endl;
            P();
        }
        else if(c == '0'){
            ofstream ofs("data.txt");
            contestList.saveContests(ofs);
            ofs.close();
            cout << "保存更改成功" << endl;
            break;
        }
        else{
            cerr << "错误：非法输入！" << endl;
        }
    }
}

void Panel::P()
{
        while(1){
        system("cls");
        cout << "--------比赛列表面板--------"<< endl;
        cout << "----press 1 进行新比赛"<< endl;
        cout << "----press 2 查找/操作比赛记录"<< endl;
        cout << "----press 0 登出"<< endl;
    	cout<<"               请选择：";
        cin >> c;
        switch(c){
        case '1':
            P1();
            break;
        case '2':
            P2();
            break;
        case '0':
            break;
        default:
            cerr <<"非法输入!"<<endl;
        }
        if(c == '0'){
            break;
        }
        system("pause");
        system("cls");
        c = '$';
    }
}

void Panel::P1()
{
    contest = Contest();
    cout << "输入新的比赛信息" << endl;
    cout << "输入比赛id" << endl;
    long long id;
    cin >> id;
    while(contestList.idExists(id)){
        cout << "id已存在，请重新输入!" << endl;
        cin >> id;
    }
    cout << "输入地点"<<endl;
    cin >> s;
    cout << "输入时间(年 月 日)" <<endl;
    Date d;
    cin >> d;
    contest = Contest(id, s, d);
    system("cls");
    cout << "当前比赛信息" << endl;
    cout << contest;
    cout << "比赛开始" << endl;
    new_Contest();
}

void Panel::new_Contest(){
    int n;
    int m;
    while(1){
        cout << "输入评委的人数" << endl;
        cin >> m;
        if(m > 0) break;
        else cout << "请输入正数" << endl;
    }
    while(1){
        cout << "选手的个数" << endl;
        cin >> n;
        if(n > 0) break;
        else cout << "请输入正数" << endl;
    }
    for(int i = 1; i <= n; i++){
        contest.addSinger(judge_singer(m));
    }
    cout << "按平均分（改良）排名" << endl;
    contest.sortByAvg();
    cout << "比赛结果" << endl;
    cout << contest;
    contestList.addContest(contest);
    contest = Contest();
}

Singer Panel::judge_singer(int n){
    long long id;
    string name;
    cout << "输入选手编号(正整数): " << endl;
    cin >> id;
    cout << "输入选手姓名: " << endl;
    cin >> name;
    Singer singer1(id, name);
    double grade;
    for(int i = 1; i <= n; i++){
        cout << "评委 " << i<<" 号" << endl;
        cin>>grade;
        singer1.addMark(grade);
    }
    return singer1;
}


void Panel::P2()
{
    cout << "按(1-ID, 2-日期, 3-场地查找)" << endl;
    cin >> c;
    vector<Contest> v;
    switch(c){
        case '1':
            cout << "输入id" <<endl;
            long long id;
            cin >> id;
            //TODO
            if(contestList.idExists(id)){
                contest = contestList.findById(id);
                v.push_back(contest);
            }
            break;
        case '2':
            {
            cout << "输入日期(0为通配符)" <<endl;
            int year, month, day;
            cout << "输入年"<<endl;
            cin >> year;
            cout << "输入月"<<endl;
            cin >> month;
            cout << "输入日"<<endl;
            cin >> day;
            Date date(year, month, day);
            v = contestList.findByDate(date);
            break;
            }
        case '3':
            {
            cout << "输入场地" <<endl;
            string loc;
            cin>>loc;
            v = contestList.findByLoc(loc);
            break;
            }
        case '0':
            break;
        default:
            cout << "错误：非法输入！"<< endl;
    }
    if(v.size()==0) cout << "未查找到相应比赛"<<endl;
    else{
        for(int i = 0; i < v.size(); i++){
            cout << "编号" << i+1 << ": " << endl;
            cout << v[i];
        }
        cout << "输入编号以查看详情"<< endl;
        int num;
        cin >> num;
        num--;
        if(num >= 0 && num < v.size()){
            contest = v[num];
            P2_();
        }
        else{
            cout << "错误：非法输入！"<< endl;
        }
    }
}

void Panel::P2_()
{
    while(1){
        system("cls");
        cout << "----当前选中的比赛："<< endl;
        cout << contest;
        cout << "--------对当前比赛进行操作--------"<< endl;
        cout << "----press 1 更改比赛基本信息"<< endl;
        cout << "----press 2 删除比赛"<< endl;
        cout << "----press 3 查询/操作选手"<< endl;
        cout << "----press 4 查看选手排名"<< endl;
        cout << "----press 0 登出"<< endl;
    	cout<<"               请选择：";
        cin >> c;
        switch(c){
        case '1':
            P2_1();
            break;
        case '2':
            P2_2();
            break;
        case '3':
            P2_3();
            contestList.deleteContest(contest);
            contestList.addContest(contest);
            break;
        case '4':
            P2_4();
        case '0':
            break;
        default:
            cerr <<"非法输入, 请重选!"<<endl;
        }
        if(c == '0' || c == '2'){
            break;
        }
        system("pause");
        system("cls");
    }
    c = '$';
}

void Panel::P2_1()
{
    cout << "输入比赛信息" << endl;
    cout << "输入id" << endl;
    long long id;
    if(contestList.idExists(id) && id != contest.getCid()){
        cout << "id已存在，无法更改!" << endl;
        return;
    }
    cin >> id;
    cout << "输入地点"<<endl;
    cin >> s;
    cout << "输入时间(年 月 日)" <<endl;
    Date d;
    cin >> d;
    contestList.deleteContest(contest);
    contest = Contest(id, s, d, contest.getSingers());
    contestList.addContest(contest);
}

void Panel::P2_2()
{
    contestList.deleteContest(contest);
    cout << "比赛已删除"<<endl;
}

void Panel::P2_3()
{
    cout << "按(1-ID, 2-姓名, 3-前X名)" << endl;
    cin >> c;
    vector<Singer> v;
    switch(c){
        case '1':
            cout << "输入id" <<endl;
            long long id;
            cin >> id;
            if(contest.idExists(id)){
                singer = contest.findById(id);
                v.push_back(singer);
            }
            break;
        case '2':
            {
            cout << "输入姓名" <<endl;
            string name;
            cin>>name;
            v = contest.findByName(name);
            break;
            }
        case '3':
            {
            cout << "输入X" <<endl;
            int x;
            cin>>x;
            v = contest.findByX(x);
            break;
            }
        case '0':
            break;
        default:
            cout << "错误：非法输入！"<< endl;
    }
    if(v.size()==0) cout << "未查找到相应选手"<<endl;
    else{
        for(int i = 0; i < v.size(); i++){
            cout << "编号" << i+1 << ": " << endl;
            cout << v[i];
        }
        cout << "输入编号以查看详情"<< endl;
        int num;
        cin >> num;
        num--;
        if(num >= 0 && num < v.size()){
            singer = v[num];
            P2_3_2();
        }
        else{
            cout << "错误：非法输入！"<< endl;
        }
    }
    c = '$';
}

void Panel::P2_4()
{
    cout << "按(1-id, 2-改良平均分, 3-第i号评委)排名" << endl;
    cin >> c;
    vector<Singer> v;
    switch(c){
        case '1':
            contest.sortById();
            break;
        case '2':
            {
            contest.sortByAvg();
            break;
            }
        case '3':
            {
            cout << "输入i" <<endl;
            int x;
            cin>>x;
            contest.sortByGradeI(x-1);
            break;
            }
        case '0':
            break;
        default:
            cout << "错误：非法输入！"<< endl;
    }
    v = contest.findByX(contest.getSize());
    if(v.size()==0) cout << "未查找到相应选手"<<endl;
    else{
        for(int i = 0; i < v.size(); i++){
            cout << "编号" << i+1 << ": " << endl;
            cout << v[i];
        }
        cout << "输入编号以查看详情(0退出)"<< endl;
        int num;
        cin >> num;
        num--;
        if(num >= 0 && num < v.size()){
            singer = v[num];
            P2_3_2();
        }
        else if(num == -1);
        else{
            cout << "错误：非法输入！"<< endl;
        }
    }
}



void Panel::P2_3_2()
{
    while(1){
        system("cls");
        cout << "当前选手"<< endl;
        cout << singer;
        cout << "--------选手面板--------"<< endl;
        cout << "----press 1 更改选手基本信息"<< endl;
        cout << "----press 2 删除选手"<< endl;
        cout << "----press 3 更改选手成绩"<< endl;
        cout << "----press 4 增加选手成绩"<< endl;
        cout << "----press 0 登出"<< endl;
    	cout<<"               请选择：";
        cin >> c;
        switch(c){
        case '1':
            P2_3_2_1();
            break;
        case '2':
            P2_3_2_2();
            break;
        case '3':
            P2_3_2_3();
            break;
        case '4':
            P2_3_2_4();
            break;
        case '0':
            break;
        default:
            cerr <<"非法输入!"<<endl;
        }
        if(c == '0' || c == '2'){
            break;
        }
        system("pause");
        system("cls");
    }
    c = '$';
}

void Panel::P2_3_2_1()
{
    cout << "输入选手信息" <<endl;
    cout << "输入选手编号" <<endl;
    long long id;
    cin >> id;
    if(contest.idExists(id) && id != contest.getCid()){
        cout << "id已存在，无法更改!" << endl;
        return;
    }
    cout << "输入选手姓名" <<endl;
    cin >> s;
//    cout << "评判选手成绩？(Y/N)" << endl;
//    cin >> c;
//    if(c == 'Y' || c == 'y');
//        judge();
//    else if (c == 'N' || c == 'n') return;
//    else cout << "非法字符，结束当前操作" << endl;
    contest.deleteSinger(singer);
    singer = Singer(id, s, singer.getGrades());
    contest.addSinger(singer);
}

void Panel::P2_3_2_2()
{
    contest.deleteSinger(singer);
}

void Panel::P2_3_2_3()
{
    vector<double> v = singer.getGrades();
    if(v.size()==0) cout << "未查找到成绩"<<endl;
    else{
        for(int i = 0; i < v.size(); i++){
            cout << "评委编号" << i+1 << ": " << v[i];
        }
        cout << endl;
        cout << "输入修改的评委编号(0退出)"<< endl;
        int num;
        cin >> num;
        cout << "将" << num << "号修改为";
        int x;
        cin >> x;
        num--;
        if(num > 0 && num < v.size()){
            contest.deleteSinger(singer);
            singer.setGrades(x, num);
            contest.addSinger(singer);
        }
        else if (num == 0) ;
        else{
            cout << "错误：非法输入！"<< endl;
        }
    }
}

void Panel::P2_3_2_4()
{
    cout << "输入评委数" << endl;
    int n;
    cin >> n;
    double grade;
    for(int i = 1; i <= n; i++){
        cout << "新增评委 " << i<<" 号" << endl;
        cin>>grade;
        singer.addMark(grade);
    }
    contestList.deleteContest(contest);
    contest.addSinger(singer);
    contestList.addContest(contest);
}
