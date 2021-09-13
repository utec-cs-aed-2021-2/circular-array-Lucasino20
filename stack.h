#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {

private:
    T *array;
    int capacity;
    int size;

public:
    StackArray();
    void push(int data){};
    int pop();
    void display();
};

template < class T>
StackArray<T>::StackArray() {
    StackArray(0);
}

template < class T>
StackArray<>::void push(int data){
    StackArray<T>::push_front(data);
}

template < class T>
StackArray<T>::int pop(){
    StackArray<T>::pop_front();
}

template < class T>
StackArray<T> void display(){
    for (int i = 0; i < array.size(); ++i)
        cout << array[i] << " ";
    cout << "\n";
}