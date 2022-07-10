#pragma once

template<typename T>
class uniquePtr {
private :
    T* ptr;

public :
    uniquePtr() = delete;

    uniquePtr(T* p) {
        ptr = p;
    }

    uniquePtr(T& p) {
        ptr = p;
    }

    uniquePtr(const uniquePtr<T>& p) = delete;

    ~uniquePtr() {
        delete ptr;
    }

    T* operator -> () {
        return ptr;
    }

    T* operator * () {
        return &ptr;
    }
};

template<typename T>
class shared_pointer {
private:
    int * count;
    T* ptr;

public:
    shared_pointer() {

    }

    shared_pointer(T* p) {
        ptr = p;
        count = new int(1);
    }

    shared_pointer(const shared_pointer<T>& other) {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    ~shared_pointer() {
        (*count)--;
        if((*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    T* operator * () {
        return ptr;
    }

    T* operator -> () {
        return ptr;
    }

    int getCount() const {
        return *count;
    }

};
