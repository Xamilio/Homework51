#include <iostream>
using namespace std;
template<typename T>
class DynArray
{
    T* arr;
    int size;
public:
    DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
    {
        cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
    }

    DynArray() : DynArray(5) {}

    DynArray(const DynArray& object) : arr{ new T[object.size] }, size{ object.size }
    {
        for (int i{ 0 }; i < size; ++i)
        {
            arr[i] = object.arr[i];
        };
         cout << "DynArr copy constructed for " << size << " elements, for " << this<< '\n';
    }
    ~DynArray()
    {
        cout << "Try to free memory from DynArray for" << arr << " pointer\n";
        delete[] arr;
        cout << "DynArr destructed for " << size << " elements, for " << this << '\n';
    }

    T getElem(int idx) { return arr[idx]; }

    void setElem(int idx, T val) { arr[idx] = val; }
    void print()
    {
        for (int i{ 0 }; i < size; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    void randomize()
    {
        for (int i{ 0 }; i < size; ++i)
        {
            arr[i] = static_cast<T>(rand() % 10);
        }
    }
    T sum()
    {
        T sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += arr[i];
        }
        return sum;
    }
};
class Point 
{
    int x;
    int y;
};

int main()
{
    DynArray<int> intArray(5);
    DynArray<double> doubleArray(5);
    DynArray<char> charArray(5);
    DynArray<Point> pointArray(5);

    intArray.randomize();
    doubleArray.randomize();
    charArray.randomize();
}