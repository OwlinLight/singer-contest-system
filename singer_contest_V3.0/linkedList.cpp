#include "linkedList.h"

template <typename T>
void linkedList<T>::operator=(const linkedList& o)
{
    head = tail = new node<T>();
    for(node<T>* p = o.head->next; p; p = p->next){
        tail->next = new node<T>(p->data);
        tail = tail->next;
    }
    size = o.size;
}

template <typename T>
linkedList<T>::linkedList(const linkedList &o)
{
    head = tail = new node<T>();
    for(node<T>* p = o.head->next; p; p = p->next){
        tail->next = new node<T>(p->data);
        tail = tail->next;
    }
    size = o.size;
}

template <typename T>
linkedList<T>::~linkedList()
{
    node<T>* p;
    while(head){
        p = head;
        head = head->next;
        delete p;
    }
}

template <typename T>
vector<T> linkedList<T>::findByDate(Date data)
{
    node<T>* p = head->next;
    vector<T> v;
    if(p == NULL) return v;
    while(p != tail){
        if(p->data.getDate() == data) v.push_back(p->data);
        p = p->next;
    }
    if(p->data.getDate() == data) v.push_back(p->data);
    return v;
}

template <typename T>
node<T>* linkedList<T>::find(T data)
{
    node<T>* p = head->next;
    if(p == NULL) return p;
    while(p != tail){
        if(p->data == data) return p;
        p = p->next;
    }
    if(p->data == data) return p;
    else return NULL;
}

template <typename T>
bool linkedList<T>::find(T data, node<T>*& pre, node<T>*& pos)
{
    pos = head->next, pre = head;
    while(pos != tail){
        if(pos->data == data) return true;
        pre = pos;
        pos = pos->next;
    }
    if(pos->data == data) return true;
    else{
        pre = NULL;
        pos = NULL;
        return false;
    }
}

template <typename T>
void linkedList<T>::sort()
{
    head = bubbleSort(head);
}

template <typename T>
void linkedList<T>::sortByAvg()
{
    head = bubbleSortByAvg(head);
}

template <typename T>
void linkedList<T>::sortByGradeI(int i)
{
    head = bubbleSortByGradeI(head, i);
}


template <typename T>
void linkedList<T>::reverse()
{
    node<T>* p = head->next;
    node<T>* pre = NULL;
    tail = head->next;
    delete head;
    while(p){
        node<T>* t = p;
        p = p->next;
        t->next = pre;
        pre = t;
    }
    p = new node<T>(0, pre);
    head = p;
}
template <typename T>
double linkedList<T>::calSum()
{
    double sum = 0;
    linkedList<T> *pos, *pre;
    pos = head->next, pre = head;
    while(pos != tail){
        sum += pos->data;
        pre = pos;
        pos = pos->next;
    }
    pre = NULL;
    pos = NULL;
    return false;
}

template <typename T>
void linkedList<T>::inputList()
{
    T tmp;
    node<T>* Nnode;
    while(cin >> tmp && tmp != -1){
        Nnode = new node<T>(tmp, head);
        head = Nnode;
    }
}

template <typename T>
void linkedList<T>::add_front(T value){
    head->next = new node<T>(value, head->next);
    size++;
    if(size == 1) tail = head->next;
}

template <typename T>
void linkedList<T>::add_tail(T value){
    tail->next = new node<T>(value);
    tail = tail->next;
    size++;
}

//next
template <typename T>
void linkedList<T>::Delete(T value){
    bool result;
    node<T>* pre, *p;
    result=find(value, pre, p);
    if(result == false) return;
    pre->next = p->next;
    delete p;
    size--;
    if(pre->next == NULL) tail = pre;
}

template <typename T>
void linkedList<T>::delete_pos_after(node<T>* pos){
    node<T>* p;
    if(pos==NULL) return;
    if(pos!=tail){
        p = pos->next;
        pos->next = p->next;
        delete p;
        size--;
        if(pos->next== NULL) tail = pos;
    }
}

template <typename T>
void linkedList<T>::delete_pos_before(node<T>* pos){
    node<T>* prepre = head->next, *pre;
    if(pos==NULL) return;
    while(prepre->next->next != pos){prepre = prepre->next;}
    if(pos!=head){
        pre = prepre->next;
        prepre->next = pos;
        delete pre;
        size--;
    }
}

template <typename T>
void linkedList<T>::add_pos_before(T data, node<T>* pos){
    if(pos == NULL || pos == head) return;
    node<T>* pre = head->next;
    while(pre->next != pos){pre = pre->next;}
    pre->next = new node<T>(data, pre->next);
    size++;
}

template <typename T>
void linkedList<T>::add_pos_after(T data, node<T>* pos){
    pos->next = new node<T>(data, pos->next);
    if(pos == tail)
        tail = tail->next;
    size++;
}

template <typename T>
bool linkedList<T>::set_data(T data){
    node<T>* d;
    if((d = find(data))!=NULL){
        d->data = data;
        return true;
    }
    return false;
}



template <typename T>
void linkedList<T>::delete_all(){
    node<T>* p;
    while(head){
        p = head->next;
        head = head->next;
        delete p;
    }
}


template <typename T>
void linkedList<T>::display()
{
    node<T>* p = head->next;
    while(p != NULL){
        cout << p->data<<endl;
        p = p->next;
    }
    cout << endl;
}

template <typename T>
node<T>* linkedList<T>::bubbleSort(node<T>* head){
    node<T>* pos = head->next;
    node<T>* pp, *p;
    T tmp;
    bool flag;
    while(pos->next){
        pp = pos;
        p = pos->next;
        flag = false;
        while(p){
            if(pp->data > p->data){
                tmp = pp->data;
                pp->data = p->data;
                p->data = tmp;
                flag = true;
            }
            pp = p;
            p = p->next;
        }
        if(flag == false) break;
    }
    return head;
}

template <typename T>
node<T>* linkedList<T>::bubbleSortByAvg(node<T>* head){
    node<T>* pos = head->next;
    node<T>* pp, *p;
    T tmp;
    bool flag;
    while(pos->next){
        pp = pos;
        p = pos->next;
        flag = false;
        while(p){
            if(cmp.avg(pp->data, p->data)){
                tmp = pp->data;
                pp->data = p->data;
                p->data = tmp;
                flag = true;
            }
            pp = p;
            p = p->next;
        }
        if(flag == false) break;
    }
    return head;
}

template <typename T>
node<T>* linkedList<T>::bubbleSortByGradeI(node<T>* head, int i){
    node<T>* pos = head->next;
    node<T>* pp, *p;
    T tmp;
    bool flag;
    while(pos->next){
        pp = pos;
        p = pos->next;
        flag = false;
        while(p){
            if(cmp.gradeI(pp->data, p->data, i)){
                tmp = pp->data;
                pp->data = p->data;
                p->data = tmp;
                flag = true;
            }
            pp = p;
            p = p->next;
        }
        if(flag == false) break;
    }
    return head;
}
template <typename T>
linkedList<T> operator+(linkedList<T>& L1, linkedList<T>& L2)
{
    L1.sort();
    L2.sort();
    linkedList<T> L3;
    node<T>* tail3;
    node<T>* p;

    L3.head = new node<T>;
    tail3 = L3.head;
    node<T>* p1 = L1.head, *p2 = L2.head;
    while(p1 && p2){
        if(p1->data < p2->data){
            tail3->next = new node<T>(p1->data);
            p1 = p1->next;
            tail3 = tail3->next;
        }
        else if(p1->data > p2->data){
            tail3->next = new node<T>(p2->data);
            p2 = p2->next;
            tail3 = tail3->next;
        }
        else{
            tail3->next = new node<T>(p1->data);
            p1 = p1->next;
            tail3 = tail3->next;
            p2 = p2->next;
        }
    }
    while(p1){
        tail3->next = new node<T>(p1->data);
        p1 = p1->next;
        tail3 = tail3->next;
    }
    while(p2){
        tail3->next = new node<T>(p2->data);
        p2 = p2->next;
        tail3 = tail3->next;
    }
    L3.head = L3.head->next;
    return L3;
}


template <class T>
linkedList<T> operator-(linkedList<T>& L1, linkedList<T>& L2)
{
    L1.sort();
    L2.sort();
    linkedList<T> L3;
    node<T>* tail3;
    node<T>* p;

    L3.head = new node<T>;
    tail3 = L3.head;
    node<T>* p1 = L1.head, *p2 = L2.head;
    while(p1 && p2){
        if(p1->data < p2->data){
            tail3->next = new node<T>(p1->data);
            p1 = p1->next;
            tail3 = tail3->next;
        }
        else if(p1->data > p2->data){
            p2 = p2->next;
        }
        else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1){
        tail3->next = new node<T>(p1->data);
        p1 = p1->next;
        tail3 = tail3->next;
    }
    L3.head = L3.head->next;
    return L3;
}
