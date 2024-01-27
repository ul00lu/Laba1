#include "Function.h"

namespace Lab1 {

        Matrix input() { // ввод и проверка корректности ввода и выделения памяти 
            Matrix matrix1;  //объект 

            std::cout << "введите число который отвечает за количество строк и столбцов " << std::endl;

            try
            {
                matrix1.m = getNum<int>(1); // matrix1.m это количество строк и столбцов    который хранит размер матрицы (количество строк и столбцов).
                matrix1.lines = new Line[matrix1.m]; //массив строк матрицы.  
                for (int i = 0; i < matrix1.m; i++) {
                    matrix1.lines[i].a = new int[(matrix1.m - i)];  //триугольник 
                }
            }
            catch (const std::bad_alloc& ba) // 
            {
                throw std::runtime_error("Ошибка выделения памяти для матрицы ");
            }

            for (int i = 0; i < matrix1.m; i++) { // ввод матрицы ( ввод только главной диагонали и то что выше него ) 
                for (int j = 0; j < (matrix1.m - i); j++) {   //перебирает элементы внутри текущей строки матрицы. j - индекс текущего элемента

                    std::cout << "Введите элемент  матрицы A" << i << "." << (j + i) << ":" << std::endl;
                    matrix1.lines[i].a[j] = getNum<int>();  //для ввода и сохранения элемента матрицы в массив matrix1.lines.
                }
            }

            return matrix1; 

        }

        int callback(const Matrix& matrix,int i,int callback) {
            int element=0;
            int j = 0;          //ля прохода по элементам матрицы.
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
                vector.a = new int[matrix.m]; // выдиления памяти вектору Б.масив размером 
                vector.n = matrix.m; // количество элементов вектора Б   .Установка значения vector.n равным количеству элементов вектора Б,
                std::cout << " какой цыфры не должно быть " << std::endl;
                int m = getNum<int>();
                for (int i = 0; i < vector.n; i++) {  // перебирать элементы вектора Б. 

                    vector.a[i] = callback(matrix,i,m);              //аполнение элементов вектора Б         
                }
                

            }
            catch (const std::bad_alloc& ba) // в случае любого исключения  при выделении динамической памяти.
            {
                throw std::runtime_error("Ошибка выделения памяти для матрицы ");
            }


            return vector;



        }

        void outputMatrix(const Matrix& matrix) { // вывод матрицы и вектора 
            std::cout << "Исходная матрица" << std::endl;
            for (int i = 0; i < matrix.m; i++) {

                for (int j = 0; j < (matrix.m - (matrix.m - i)); j++) {  //предназначен для вывода элементов над главной диагональю матрицы
                    std::cout << std::setw(6) << std::setprecision(8) << " A" << i << j << " = " << matrix.lines[j].a[(i - j)] << " ";

                }
                for (int j = 0; j < (matrix.m - i); j++) {  //предназначен для вывода элементов на главной диагонали и ниже нее.

                    std::cout << std::setw(6) << std::setprecision(8) << " A" << i << (j + i) << " = " << matrix.lines[i].a[j] << " ";
                    //setw устанавливает ширину поля  для каждого элемента setprecision устанавливает точность вывода 
                }   // чтобы матрица была приятной для глаз 
                std::cout << std::endl;
            }
        }

        void outputVectorB(const Line& vector) {
            std::cout << "Вектор Б" << std::endl;
            for (int i = 0; i < vector.n; i++) {     //перебирает элементы вектора B. 
                std::cout << std::setw(6) << std::setprecision(8) << " Б" << i << " = " << vector.a[i] << " ";  // ширину поля вывода равной 6 символам, 
            }
            std::cout << std::endl;
        }

        void freeMemoryMatrix(Matrix& matrix) {
            if (matrix.lines != nullptr) {     //проверка на выделение памяти 
                for (int i = 0; i < (matrix.m - i); i++)
                    delete[] matrix.lines[i].a;   // освобождает память для массива элементов строки a.
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

