#ifndef FUNCTION
#define FUNCTION

#include <limits>
#include <iomanip>
#include <iostream>
#include <string>

namespace Lab1 {
    struct Line
    {
        int callback = 0;
        int n = 0; // ���������� ��������� ������� � 
        int* a = nullptr; // ������ ���������
    };
    struct Matrix
    {
        int m = 0; // ���������� ����� � �������� ������� � ���������� ��������� ������� �
        Line* lines = nullptr; // ������ �����
    };

    template<class T> //���������� ��������� �������  � ������� ������ ������
    T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {   //�������� ���������� ��������
        T a;
        while (true) {
            std::cin >> a;
            if (std::cin.eof()) // ��������� ����� �����
                throw std::runtime_error("�� ������� ��������� ����� EOF");
            else if (std::cin.bad()) // ���������� ��������������� ������ �������� ������
                throw std::runtime_error(std::string("�� ������� ��������� �����: "));
            // ������ ������ (������������ ������ �����) ���� ����� �� ������ � �������� ��������
            else if (std::cin.fail() || a < min || a > max) {
                std::cin.clear(); // ������� ����� ��������� ������
                // ���������� ��� ������� �� ����� ������
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "������ �����. ��������� ���� " << std::endl;
            }
            else // �������� ����
                return a;
        }
    }

    Matrix input();
    void freeMemoryMatrix(Matrix& matrix);
    void freeMemoryVector(Line& vector);
    Line GenerateVector_B(const Matrix& matrix);
    int callback(const Matrix& matrix,int i,int callback);
    void outputMatrix(const Matrix& matrix);
    void outputVectorB(const Line& vector);


}

#endif
