#include <iostream>
#include <utility>
using namespace std;

template <typename T>
struct MyVec
{
    T *arr;
    int size;
    int capacity;
    MyVec()
    {
        capacity = 2;
        size = 0;
        arr = new T[capacity];
    }
    ~MyVec()
    {
        delete[] arr;
    }
    MyVec(const MyVec &obj)
    {
        size = obj.size;
        capacity = obj.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    T &operator[](int index)
    {
        return arr[index];
    }

    MyVec &operator=(MyVec other)
    {
        swap(arr, other.arr);
        swap(size, other.size);
        swap(capacity, other.capacity);
        return *this;
    }
    void push_back(const T &element)
    {
        if (!(size < capacity))
        {
            capacity *= 2;
            T *newArr = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size] = element;
        size++;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyVec<char> arr;
    arr.push_back('d');
    arr.push_back('a');
    arr.push_back('g');
    arr.push_back('d');
    arr.push_back('w');
    arr.print();
    MyVec<char> brr;
    brr = arr;
    brr.push_back('t');
    brr.print();
}