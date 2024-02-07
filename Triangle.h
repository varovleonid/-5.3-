#include <iostream>
#include <windows.h>
class Triangle {
    static int counter;
public:
    // 1 задание
    Triangle() {
        counter++; // увеличиваем счетчик при каждом создании объекта
    }
    ~Triangle() {
        counter--; // уменьшаем счетчик при каждом удалении объекта
    }
    static int getCounter() {
        return counter; // метод для получения текущего значения счетчика
    }
    double a;
    double b;
    double c;

    double square() {
        double p = (a + b + c) / 2;
        return (sqrt(p * (p - a) * (p - b) * (p - c)));
    }

    // Унарные операции
    void PlusOperator() {
        a++;
        b++;
        c++;
    }
    void MinusOperator() {
        a--;
        b--;
        c--;
    }
    // Операции приведения типа
    double Existence(double a, double b, double c) {
        if (a + b > c && b + c > a && a + c > b)
        {
            return square();
        }
        return -1;
    }
    bool Existence() {
        return (a + b > c && b + c > a && a + c > b);
    }


    // Бинарные операции
    void BinOperator(Triangle t1, Triangle t2) {
        if (t1.square() >= t2.square())
        {
            if (t1.square() == t2.square())
            {
                std::cout << "Площади треугольников равны";
            }
            std::cout << "Площадь первого треугольника больше на " << (t1.square() - t2.square());
        }
        std::cout << "Площадь второго треугольника больше на " << (t2.square() - t1.square());
    }

};
int Triangle::counter = 0;

double square(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

