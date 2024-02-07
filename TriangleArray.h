#include <iostream>
#include <windows.h>
#include <time.h>
#include "Triangle.h"
using namespace std;
class TriangleArray {
    static int count;
    double minSquare = DBL_MAX;
public:
    int SizeArr;
    Triangle* arr;

    TriangleArray() {
        count++;
    }

    TriangleArray(int size) {
        count++;
        SizeArr = size;
        arr = new Triangle[SizeArr];
        for (int i = 0; i < size; i++)
        {
            bool b;
            do
            {
                b = false;
                cout << "\n“реугольник " << i + 1 << ":\n"
                    << "¬ведите длину стороны a: ";
                cin >> arr[i].a;
                cout << "¬ведите длину стороны b: ";
                cin >> arr[i].b;
                cout << "¬ведите длину стороны c: ";
                cin >> arr[i].c;
                if (arr[i].a <= 0)
                {
                    cout << "ƒлина не может быть <= 0\n";
                    b = true;
                }
            } while (b);
        }
    }
    TriangleArray(int size, int min, int max) {
        count++;
        SizeArr = size;
        arr = new Triangle[SizeArr];
        for (int i = 0; i < size; i++)
        {
            arr[i].a = rand() % (max - min) + min;
            arr[i].b = rand() % (max - min) + min;
            arr[i].c = rand() % (max - min) + min;
        }
    }
    ~TriangleArray() {
        count--;
    }
    Triangle MinTriangle() {
        int index;
        for (int i = 0; i < SizeArr; i++)
        {
            if (minSquare > arr[i].square()) {
                minSquare = arr[i].square();
                index = i;
            }
        }
        return arr[index];
    }

    Triangle NumOut(int i) {
        return arr[i];
    }
    void ArrayOut() {
        for (int i = 0; i < SizeArr; i++)
        {
            cout << "“реугольник " << i + 1 << ": a=" << arr[i].a
                << ", b=" << arr[i].b
                << ", c=" << arr[i].c << '\n';
        }
    }
    static int GetCount() {
        return count;
    }
};
int TriangleArray::count = 0;
