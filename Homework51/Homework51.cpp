#include <iostream>
#include <cmath> 
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
        cout << "DynArr copy constructed for " << size << " elements, for " << this << '\n';
    }
    ~DynArray()
    {
        cout << "Try to free memory from DynArray for" << arr << " pointer\n";
        delete[] arr;
        cout << "DynArr destructed for " << size << " elements, for " << this << '\n';
    }

    T getElem(int idx)
    {
        return arr[idx];
    }

    void setElem(int idx, T val)
    {
        arr[idx] = val;
    }


    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    void randomize()
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = static_cast<T>(rand() % 10);
        }
    }
    T sum()
    {
        T sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum = sum + arr[i];
        }
        return sum;
    }
};
class Point
{
public:
    int x;
    int y;


    Point() : x(0), y(0) {}

    Point(int l)
    {
        x = l;
        y = l;
    }

    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    Point& operator =(int& a)
    {
        x = a;
        y = a;
        return *this;
    }
    operator int() const
    {
        return static_cast<int>(sqrt(x * x + y * y));
    }
};

int main()
{
    DynArray<int> intArray(5);  
    intArray.randomize();
    intArray.print();
    cout << "Сумма: " << intArray.sum() << "\n";
    
    DynArray<double> doubleArray(5);
    doubleArray.randomize();
    doubleArray.print();
    cout << "Сумма: " << doubleArray.sum() << "\n";
    
    DynArray<char> charArray(5);
    charArray.randomize();
    charArray.print();
    cout << "Сумма: " << charArray.sum() << "\n";

    DynArray<Point> pointArray(5);
    pointArray.randomize();
    pointArray.print();
    cout << "Сумма: " << pointArray.sum() << "\n";
}
