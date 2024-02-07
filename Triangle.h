#include <iostream>
#include <windows.h>
class Triangle {
    static int counter;
public:
    // 1 �������
    Triangle() {
        counter++; // ����������� ������� ��� ������ �������� �������
    }
    ~Triangle() {
        counter--; // ��������� ������� ��� ������ �������� �������
    }
    static int getCounter() {
        return counter; // ����� ��� ��������� �������� �������� ��������
    }
    double a;
    double b;
    double c;

    double square() {
        double p = (a + b + c) / 2;
        return (sqrt(p * (p - a) * (p - b) * (p - c)));
    }

    // ������� ��������
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
    // �������� ���������� ����
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


    // �������� ��������
    void BinOperator(Triangle t1, Triangle t2) {
        if (t1.square() >= t2.square())
        {
            if (t1.square() == t2.square())
            {
                std::cout << "������� ������������� �����";
            }
            std::cout << "������� ������� ������������ ������ �� " << (t1.square() - t2.square());
        }
        std::cout << "������� ������� ������������ ������ �� " << (t2.square() - t1.square());
    }

};
int Triangle::counter = 0;

double square(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

