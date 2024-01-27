#include "Function.h"

namespace Lab1 {

        Matrix input() { // ���� � �������� ������������ ����� � ��������� ������ 
            Matrix matrix1;  //������ 

            std::cout << "������� ����� ������� �������� �� ���������� ����� � �������� " << std::endl;

            try
            {
                matrix1.m = getNum<int>(1); // matrix1.m ��� ���������� ����� � ��������    ������� ������ ������ ������� (���������� ����� � ��������).
                matrix1.lines = new Line[matrix1.m]; //������ ����� �������.  
                for (int i = 0; i < matrix1.m; i++) {
                    matrix1.lines[i].a = new int[(matrix1.m - i)];  //����������� 
                }
            }
            catch (const std::bad_alloc& ba) // 
            {
                throw std::runtime_error("������ ��������� ������ ��� ������� ");
            }

            for (int i = 0; i < matrix1.m; i++) { // ���� ������� ( ���� ������ ������� ��������� � �� ��� ���� ���� ) 
                for (int j = 0; j < (matrix1.m - i); j++) {   //���������� �������� ������ ������� ������ �������. j - ������ �������� ��������

                    std::cout << "������� �������  ������� A" << i << "." << (j + i) << ":" << std::endl;
                    matrix1.lines[i].a[j] = getNum<int>();  //��� ����� � ���������� �������� ������� � ������ matrix1.lines.
                }
            }

            return matrix1; 

        }

        int callback(const Matrix& matrix,int i,int callback) {
            int element=0;
            int j = 0;          //�� ������� �� ��������� �������.
                while (j < matrix.m) {
                    if (j < (matrix.m - i) && matrix.lines[i].a[j] != callback) {  // if(callback(matrix.lines[i].a[j]))
                        element += matrix.lines[i].a[j];
                    }
                    if (j >= (matrix.m - i)) {
                        if (i >= j && matrix.lines[(i - j)].a[j] != callback) {
                            element += matrix.lines[(i - j)].a[j];
                        }
                        if (i < j && matrix.lines[(i - (matrix.m - j))].a[(matrix.m - j)] != callback) {
                            element += matrix.lines[(i - (matrix.m - j))].a[(matrix.m - j)];
                        }
                    }         
                    j++;
                }     
                return element;
            
  
        }

     


        Line GenerateVector_B(const Matrix& matrix) {
            Line vector;
            try
            {
                vector.a = new int[matrix.m]; // ��������� ������ ������� �.����� �������� 
                vector.n = matrix.m; // ���������� ��������� ������� �   .��������� �������� vector.n ������ ���������� ��������� ������� �,
                std::cout << " ����� ����� �� ������ ���� " << std::endl;
                int m = getNum<int>();
                for (int i = 0; i < vector.n; i++) {  // ���������� �������� ������� �. 

                    vector.a[i] = callback(matrix,i,m);              //��������� ��������� ������� �         
                }
                

            }
            catch (const std::bad_alloc& ba) // � ������ ������ ����������  ��� ��������� ������������ ������.
            {
                throw std::runtime_error("������ ��������� ������ ��� ������� ");
            }


            return vector;



        }

        void outputMatrix(const Matrix& matrix) { // ����� ������� � ������� 
            std::cout << "�������� �������" << std::endl;
            for (int i = 0; i < matrix.m; i++) {

                for (int j = 0; j < (matrix.m - (matrix.m - i)); j++) {  //������������ ��� ������ ��������� ��� ������� ���������� �������
                    std::cout << std::setw(6) << std::setprecision(8) << " A" << i << j << " = " << matrix.lines[j].a[(i - j)] << " ";

                }
                for (int j = 0; j < (matrix.m - i); j++) {  //������������ ��� ������ ��������� �� ������� ��������� � ���� ���.

                    std::cout << std::setw(6) << std::setprecision(8) << " A" << i << (j + i) << " = " << matrix.lines[i].a[j] << " ";
                    //setw ������������� ������ ����  ��� ������� �������� setprecision ������������� �������� ������ 
                }   // ����� ������� ���� �������� ��� ���� 
                std::cout << std::endl;
            }
        }

        void outputVectorB(const Line& vector) {
            std::cout << "������ �" << std::endl;
            for (int i = 0; i < vector.n; i++) {     //���������� �������� ������� B. 
                std::cout << std::setw(6) << std::setprecision(8) << " �" << i << " = " << vector.a[i] << " ";  // ������ ���� ������ ������ 6 ��������, 
            }
            std::cout << std::endl;
        }

        void freeMemoryMatrix(Matrix& matrix) {
            if (matrix.lines != nullptr) {     //�������� �� ��������� ������ 
                for (int i = 0; i < (matrix.m - i); i++)
                    delete[] matrix.lines[i].a;   // ����������� ������ ��� ������� ��������� ������ a.
            }
            delete[] matrix.lines;
            matrix.lines = nullptr;
            matrix.m = 0;
        }

        void freeMemoryVector(Line& vector) {
            if (vector.a != nullptr) {
                delete[] vector.a;
            }
            vector.a = nullptr;
            vector.n = 0;
        }

}

