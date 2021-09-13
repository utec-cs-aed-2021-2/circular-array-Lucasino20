#include <iostream>
#include <heapsort.h>
using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](const int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

protected:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template<class T>
void CircularArray<T>::push_front(T data){
    if( array == nullptr){
        array = new int[1];
        array[1] = data;
    }
    else if(size() == capacity){
        int newsize = 0;
        newsize = capacity + 1;
        int *array2 = new int[newsize];
        for(int i = 0 ; i < size(); i++)
            array2[i] = array[i];
        delete[] array;
        array = array2;
        array[newsize] = data;
        this->back = array[newsize];
        }
}

template <class T>
void CircularArray<T>::push_back(T data ){
    if(is_full())
        throw ("empty");

    if(is_empty()) {
        front = back = 0;
    }
    else
        back = next(back);
    array[back] = data;
        }




template <class T>
void CircularArray<T>::insert(T data , int pos){

}

template <class T>
T CircularArray<T>::pop_front(){
    if(is_empty()){
        throw ("empty");
    }
    int temp = front;
    return front = next(temp);

}


template<class T>
T CircularArray<T>::pop_back() {
    if(is_empty()){
        throw ("empty");
    }
    int temp = back;
    return back = prev(temp);

}

template < class T>
bool CircularArray<T>::is_full(){
    return next(back) == front;
}

template <class T>
bool CircularArray<T>::is_empty(){
    return (front == back && back == - 1);
}


template<class T>
int CircularArray<T>::size(){
    return size_t(array);

}

template< class T>
void CircularArray<T>::clear(){
    delete[] array;

    this->array = new T[capacity];
    this->front = this->back = -1;

}

template<class T>
T  &CircularArray<T>::operator[](const int a){
    return array[a];

}

template < class T>
void CircularArray<T>::sort(){
    heap_sort(array , size());
}

template < class T>
bool CircularArray<T>::is_sorted(){
    do {
        for (int i = 0; i < size(); i++) {
            if (array[i] > array[i - 1])
                return true;
        }
    } while (false);
    return false;
}


template < class T>
void CircularArray<T>::reverse(){
    T *array2 = new T[capacity];

    for (int i = 0; i < size(); ++i) {
        for (int j = 0; j > size(); ++j) {
            array2[j] = array[i];
        }
    }

    array = array2;

}



