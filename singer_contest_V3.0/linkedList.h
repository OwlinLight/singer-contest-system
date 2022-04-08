#include <iostream>
#include <vector>
#include "Singer.h"
#include "Date.h"
using namespace std;

template <class T>
class node{
public:
    node(T d = 0, node<T>* ptr = NULL): data(d), next(ptr){}
    T data;
    node<T>* next;
};

class Cmp{
public:
    bool id(Singer x, Singer y){return x.getSid() < y.getSid();}
    bool value(int x, int y){return x < y;}
    bool gradeI(Singer x, Singer y, int i){return x.getGrade(i) < y.getGrade(i);}
    bool avg(Singer x, Singer y){return x.getGradeAvg() < y.getGradeAvg();}
};

template <class T>
class linkedList{
public:
    class MyIterator//迭代器类
    {
        node<T>* p;
    public:
        MyIterator(node<T>* x) :p(x) {}
        MyIterator(const MyIterator& mit) : p(mit.p) {}
        MyIterator& operator++() {p = p->next;return *this;}
        MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}//后置++
        bool isNull(){return (p == NULL) ? true : false;}//判断是否到达末尾
        bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
        bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
        T& operator*() {return p->data;}//更改定义，直接返回node中的值
    };

    linkedList(){head = tail = new node<T>(); size = 0;}
    linkedList(const linkedList& o);
    ~linkedList();

    void sort();//按照默认值比较符重载排序
    void sortByAvg();
    void sortByGradeI(int i);
    //不同标准的排序
    node<T>* bubbleSort(node<T>* head);
    node<T>* bubbleSortByAvg(node<T>* head);//平均分排序
    node<T>* bubbleSortByGradeI(node<T>* head, int i);//成绩排序
    node<T>* bubbleSortByCmp(node<T>* head, bool (*cmp_ptr)(T A, T B));//其他方式排序

    void reverse();//链表逆置
    void inputList();
    double calSum();

    MyIterator begin(){return MyIterator(head->next);}//返回第一个迭代器

    vector<T> findByDate(Date data);//按照日期查找（已废弃）
    node<T>* find(T data);//找结点
    bool find(T data, node<T>*& pre, node<T>*& p);//找结点是否存在
    void display();//展示所有结点

    void add_front(T value);//添加（前）
    void add_tail(T value);//添加（后）
    void Delete(T value);//删除
    void delete_pos_before(node<T>* pos);
    void delete_pos_after(node<T>* pos);
    void add_pos_before(T data, node<T>* pos);
    void add_pos_after(T data, node<T>* pos);
    bool set_data(T data);
    void delete_all();//删除所有结点
    void delete_repeat();//删除重复的结点

    void operator=(const linkedList& o);
    int list_size() const{return size;};

    template <class X>
    friend linkedList<X> operator+(linkedList<X>& L1, linkedList<X>& L2);//交
    template <class X>
    friend linkedList<X> operator-(linkedList<X>& L1, linkedList<X>& L2);//减

private:
    node<T>* head, *tail;//头/尾
    int size;
    Cmp cmp;
};
