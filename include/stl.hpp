#pragma once
using namespace std;

template<typename T>
class vectors {

private:
    T* arr;
    int curr;
    int cap;

public:
    vectors() {
        arr = new T[1];
        curr = 0;
        cap = 1;
    }

    ~vectors() {
        delete [] arr;
    }
    
    vectors(T* a, size_t s) {
        arr = new T[1];
        curr = 0;                                                                                                                           
        cap = 1;
        for (int i = 0 ; i < s ; i++) {
            push(a[i]);
        }
    }

    void push(T data) {
        if(curr == cap) {
            cap *= 2;
            T* temp = new T[cap];
            for(int i = 0; i < curr ; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[curr] = data;
        curr++;
    }

    void pop () {
        curr--;
    }

    unsigned int getSize() {
        return curr;
    }

    unsigned int getCap() {
        return cap;
    }

    void push(int index, T data) {
        if(index == curr)
            push(data);
        else if(index > curr){
            LOG("accessing illegal index, current size is", getSize());
        }
        else
            arr[index] = data;
    }

    void print () {
         for(int i = 0; i < curr; i++) {
             cout << arr[i] << " ";
         } cout<< endl;
    }
};

//linked list
class node {
    int data;
    node* next;

public:
    node(int n) {
        data = n;
        next = nullptr;
    }

    int getData() const {
        return data;
    }

    node* getNext() const {
        return next;
    }

    void setData(const int& d) {
        data = d;
    }

    void setNext(node* node) {
        next = node;
    }

};

void insertAtHead(node* &head, int n) {
    cout << "inserting value " << n << " at head" << endl;
    //new node
    node* temp = new node(n);
    temp->setNext(head);
    head = temp;
}

void inserAtTail(node* &tail, int n) {
    cout << "inserting value " << n << " at tail" << endl;

    //new node
    node* temp = new node(n);
    tail->setNext(temp);
    tail = temp;
}

void insertAtPosition(node* &head, int pos, int n) {
    cout << "inserting value " << n << " at position " << pos << endl;

    if(pos == 1) {
        insertAtHead(head, n);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt < pos-1) {
        temp = temp->getNext();
        cnt++;
        //cout << "count " << cnt << " temp data val " << temp->getData()<<endl ;
    }

    if(temp->getNext() == NULL) {
        inserAtTail(temp, n);
        return;
    }

    //new node
    node* nodeInsert = new node(n);
    nodeInsert->setNext(temp->getNext());
    temp->setNext(nodeInsert);
}

void print(node* &head) {
    node* temp = head;
    while(temp != NULL){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout  <<  endl;
}



