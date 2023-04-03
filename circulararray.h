#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(int _capacity = 10);
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
    T& operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}

template <class T>
void CircularArray<T>::clear(){
    this->front = this->back = -1;
}

template <class T>
void CircularArray<T>::push_front(T data){
    int pos;
    if (this->is_full()){
        //mandar mensaje de error por superación de capacidad
    }
    else if (this->is_empty()){
        this->array[0] = data;
        this->front = this->back = 0;
    }
    else {
        if (this->back == (this->capacity-1)){
            pos = 0;
        }
        else {pos = this->back + 1;}

        this->array[pos] = data;
        this->back = pos;
    }
}

template <class T>
void CircularArray<T>::push_back(T data){
    int pos;
    if (this->CircularArray.is_full()){
        //mandar mensaje de error por superación de capacidad
    }
    else if(this->CircularArray.is_empty()){
        this->array[0] = data;
        this->front = this->back = 0;
    }
    else{
        if (this->front == 0){
                pos = this->capacity - 1;
            }
        else{
            pos = front-1;
        }

        this->array[pos] = data;
        this->front = pos;
    }
}

template <class T>
T& CircularArray<T>::operator[](int _pos){
    int _posn = this->front+_pos;
    if (_posn > this->capacity-1){
        _posn = _posn - this->capacity;
    }

    if (_posn > this->back){
        //mensaje de indice superior al tamaño
    }
    return array[_posn];
}

template <class T>
bool CircularArray<T>::is_empty(){
    if (this->front == -1 && this->back ==-1){
        return true;
    } else { return false;}
}

template <class T>
int CircularArray<T>::size(){
    if (this->is_empty()){
        return 0;
    }
    if (this->back >= this->front){
        return (this->back - this->front + 1);
    }
    else {return (this->capacity - this->front + this->back + 1);}
}

template <class T>
bool CircularArray<T>::is_full(){
    if (this->size() == this->capacity) {
        return true;
    }
    else {return false;}
}

template <class T>
T CircularArray<T>::pop_front(){
//
}

template <class T>
T CircularArray<T>::pop_back(){
    //
}
