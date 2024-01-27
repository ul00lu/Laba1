#include "Function.h"

using namespace Lab1;

int main() {
	setlocale(LC_ALL, "Russian");
	Matrix matrix;  //исходная матрица 
	Line vectorB;
	while (true) {
		
		try
		{
			int menu;
			std::cout << "Нажмите 1 чтобы создать матрицу\n" <<
				"Нажмите 2 чтобы создать вектор\n"<<
				"Нжмите 0 чтобы выйти"<< std::endl;
			menu = getNum<int>(0);

			switch (menu)
			{

			case 1:
				matrix = input();				
				outputMatrix(matrix);
				break;
			case 2:
				vectorB = GenerateVector_B(matrix);
				outputVectorB(vectorB);
				break;
			case 0:
				freeMemoryMatrix(matrix);
				freeMemoryVector(vectorB);
				return 1;
			}
		}
		catch (const std::bad_alloc& ba)
		{
			std::cerr << ba.what() << std::endl;
			freeMemoryMatrix(matrix);
			freeMemoryVector(vectorB);
			return 1;
		}

		catch (const std::exception& e) { // в случае прочих исключений
			std::cerr << e.what() << std::endl;
			freeMemoryMatrix(matrix);
			freeMemoryVector(vectorB);
			return 1;
		}
	}
		
	
	

}