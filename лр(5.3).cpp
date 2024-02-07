#include <iostream>
#include "TriangleArray.h"
using namespace std;
TriangleArray Arr1(int size);
TriangleArray ArrRand(int size, int min, int max);
int main()
{
    srand(time(0));
    setlocale(0, "");

    Triangle D;
    bool b;
    int index, size, choice, max = 1, min = 1;
    TriangleArray arr;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Выберите тип заполнения массива:\n"
        "1. Вручную\n"
        "2. Рандомными числами в выбраном диапазоне\n"
        "Ваш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        arr = Arr1(size);
        break;
    case 2:
        do
        {
            b = false;
            cout << "Введите желаемую, минимально возможную длину стороны треугольника: ";
            cin >> min;
            cout << "Введите желаемую, максимально возможную длину стороны треугольника: ";
            cin >> max;
            if (max <= 0 || min <= 0)
            {
                cout << "Длина не может быть <= 0\n";
                b = true;
            }
        } while (b);
        arr = ArrRand(size, min, max);
        break;
    default:
        return 0;
        break;
    }
    cout << "\nВаш массив сторон треугольников:\n";
    arr.ArrayOut();

    cout << "\nВведите номер треугольника для просмотра его сторон: ";
    cin >> index;
    D = arr.NumOut(index - 1);
    cout << "Треугольник " << index << ": a=" << D.a
        << ", b=" << D.b
        << ", c=" << D.c << '\n';

    D = arr.MinTriangle();
    cout << "\nРазмеры треугольника с минимальной площадью: "
        "a=" << D.a << ", b=" << D.b << ", c=" << D.c;
    cout << "\nПлощадь этого треугольника: " << D.square();
    cout << "\n\nКоличество созданных объектов класса: "
        << TriangleArray::GetCount() << "\n";
}

TriangleArray Arr1(int size) {
    TriangleArray arr(size);
    return arr;
}
TriangleArray ArrRand(int size, int min, int max) {
    TriangleArray arr(size, min, max);
    return arr;
}
