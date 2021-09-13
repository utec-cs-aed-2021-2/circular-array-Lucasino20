#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
private:
    T *array;
    int capacity;
    int size;

public:
    QueueArray();
    void enqueue(int data){};
    int dequeue();
    void display();
};

template < class T>
QueueArray<T>::QueueArray() {
    QueueArray(0);
}

template < class T>
QueueArray<T>::void enqueue(int data){
    QueueArray<T>::push_front(data);
}

template < class T>
QueueArray<T>::int dequeue(){
    QueueArray<T>::pop_back();
}

template < class T>
QueueArray<T> void display(){
    for (int i = 0; i < array.size(); ++i)
        cout << array[i] << " ";
    cout << "\n";
}
