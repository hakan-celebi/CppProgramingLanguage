#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <locale>

/*
	Ýki adet nesneyi toplamak isteyebiliriz fakat bu nesnenin hangi özelliklerini topluyacaðýný program bilemez bu yüzden bir metod yazmak
zorundayýz ve bu metod dan sonra ise toplam nesneyi döndürmemiz gerekir.
*/

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
		const coordinate GET_COLLECTION(const coordinate &);
		double GET_DISTANCE(coordinate &);	
};

coordinate::coordinate(int x = 0, int y = 0) : x(x), y(y){}

void coordinate::SET_COORDINATE(int x = 0, int y = 0)
{this->x = x; this->y = y;}

const coordinate coordinate::GET_COLLECTION(const coordinate &c)
{coordinate total; int x = this->x + c.x; int y = this->y + c.y; total.SET_COORDINATE(x, y); return total;}

double coordinate::GET_DISTANCE(coordinate &c)
{
	int x_distance; int y_distance;
	x_distance = this->x - c.x;
	y_distance = this->y - c.y;
	int distance = pow(x_distance, 2) + pow(y_distance, 2);
	return sqrt(distance);
}

class line
{
	private:
		coordinate startposition;
		coordinate finishposition;
	public:
		line(coordinate, coordinate);
		void SET_LOCATION(coordinate, coordinate);
		coordinate GET_STARTPOSITION(){return startposition;}
	    coordinate GET_FINISHPOSITION(){return finishposition;}
	    double GET_LENGHT(){return startposition.GET_DISTANCE(finishposition);}
};

line::line(coordinate startposition, coordinate finishposition) : startposition(startposition), finishposition(finishposition){}

void line::SET_LOCATION(coordinate startposition, coordinate finishposition)
{this->startposition = startposition; this->finishposition = finishposition;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	coordinate c1(3, 5);
	coordinate c2(4, 8);
	coordinate total = c1.GET_COLLECTION(c2);
	std::cout << "Toplam x: " << total.GET_X() << "\nToplam y: " << total.GET_Y() << std::endl;
	line l1(coordinate(5, 8), coordinate(8, 12));
	coordinate start = l1.GET_STARTPOSITION();
	coordinate finish = l1.GET_FINISHPOSITION();
	std::cout << "Çizginin baþlangýç noktasý: (" << l1.GET_STARTPOSITION().GET_X() << ", " << l1.GET_STARTPOSITION().GET_Y() << ")"
	<< "\nÇizginin bitiþ Noktasý: (" << l1.GET_FINISHPOSITION().GET_X() << ", " << l1.GET_FINISHPOSITION().GET_Y() << ")" 
	<< "\nUzunluðu: " << l1.GET_LENGHT() << std::endl;
	return 0;
}
