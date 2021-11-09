#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class point
{
	private:
		float *x;
		float *y;
	public:
		point(){x = y = NULL;}
		~point(){free(x); free(y);}
		void SET_X(float inpx){free(x); x = (float *)malloc(sizeof(float)); *x = inpx;}
		void SET_Y(float inpy){free(y); y = (float *)malloc(sizeof(float)); *y = inpy;}
		void print()
		{
			if(x == NULL && y == NULL)
				std::cout << "x ve y deðeri atanmamýþ !" << std::endl;
			else if(x == NULL && y != NULL)
				std::cout << "x deðeri atanmamýþ !" << std::endl;
			else if(x != NULL && y == NULL)
				std::cout << "y deðeri atanmamýþ !" << std::endl;
			else
			{
				if(*x == 0 && *y == 0)
					std::cout << "Bu nokta origindedir." << std::endl;
				else
					std::cout << "Koordinatý: (" << *x << ", " << *y << ")" << std::endl;
			}
		}
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	point arrayobject[10];
	point *ptrarrayobject = new point[10];
	float inpx; float inpy;
	std::cout << "Düz dizi" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		inpx = rand() % 100; inpy = rand() % 100;
		arrayobject[i].SET_X(inpx); arrayobject[i].SET_Y(inpy);
		arrayobject[i].print();
	}
	std::cout << "Pointer dizi" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		inpx = rand() % 100; inpy = rand() % 100;
		(ptrarrayobject + i)->SET_X(inpx); (ptrarrayobject + i)->SET_Y(inpy);
		(ptrarrayobject + i)->print();
	}
	delete ptrarrayobject;
	return 0;
}









