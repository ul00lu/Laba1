#include "Function.h"

using namespace Lab1;

int main() {
	setlocale(LC_ALL, "Russian");
	Matrix matrix;  //�������� ������� 
	Line vectorB;
	while (true) {
		
		try
		{
			int menu;
			std::cout << "������� 1 ����� ������� �������\n" <<
				"������� 2 ����� ������� ������\n"<<
				"������ 0 ����� �����"<< std::endl;
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

		catch (const std::exception& e) { // � ������ ������ ����������
			std::cerr << e.what() << std::endl;
			freeMemoryMatrix(matrix);
			freeMemoryVector(vectorB);
			return 1;
		}
	}
		
	
	

}