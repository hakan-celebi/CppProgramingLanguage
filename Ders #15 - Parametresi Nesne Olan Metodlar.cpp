#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <locale>

class coordinate
{
	private:
		int x;
		int y;
	public:
		coordinate(int, int);
		void SET_COORDINATE(int, int);
		int GET_X(){return x;}
		int GET_Y(){return y;}
		/*tavsiye edilen coordinate baþýna const yani sabit konulmasýdýr çünkü bir hacker sisteme bu sayede etki edebilir ve gönderilen
		nesnenin özelliklerini deðiþtirebilir.*/
		double GET_DISTANCE(coordinate &);	
};

coordinate::coordinate(int x = 0, int y = 0) : x(x), y(y){}

void coordinate::SET_COORDINATE(int x = 0, int y = 0)
{this->x = x; this->y = y;}

double coordinate::GET_DISTANCE(coordinate &c)
{
	int x_distance; int y_distance;
	x_distance = this->x - c.x;
	y_distance = this->y - c.y;
	int distance = pow(x_distance, 2) + pow(y_distance, 2);
	return sqrt(distance);
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	coordinate c1(6, 6);
	coordinate c2(3, 2);
	std::cout << "Bu iki nokta arasýndaki uzaklýk = " << c1.GET_DISTANCE(c2) << std::endl;
	return 0;
}
