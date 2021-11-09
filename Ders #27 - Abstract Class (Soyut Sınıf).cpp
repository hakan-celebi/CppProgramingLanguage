#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <locale>

class shapes
{
	protected:
		double area;
		double perimeter;
	public:
		/*Soyut sýnýf bu þekilde yapýlýr peki bu ne demek yani shapes sýnýfý soyuttur nesne üretilemez ve
		bu sýnýftan miras alan bir sýnýf soyut olarak belirlenen metodlarýn gövdesini belirtmek zorundadýr.*/
		virtual void Who_Are_You() = 0;
		virtual void CALCULATE_AREA() = 0;
		virtual void CALCULATE_PERIMETER() = 0;
		virtual double GET_AREA() = 0;
		virtual double GET_PERIMETER() = 0;
};

class square : public shapes
{
	private:
		double *width;
		double *height;
	public:
		square(double *, double *);
		~square()
		{
			if(width != NULL)
				delete width; 
			 if(height != NULL)
		 		delete height;
		}
		void Who_Are_You()
		{std::cout << "I'm Square !" << std::endl;}
		void CALCULATE_AREA()
		{
			if(width == NULL || height == NULL)
				std::cout << "Width or height not assigned !" << std::endl;
			else
				area = (*width) * (*height);
		}
		void CALCULATE_PERIMETER()
		{
			if(width == NULL || height == NULL)
				std::cout << "Width or height not assigned !" << std::endl;
			else
				perimeter = 2 * (*width + *height);	
		}
		double GET_AREA()
		{return area;}
		double GET_PERIMETER()
		{return perimeter;}	
};

square::square(double *width = NULL, double *height = NULL)
{
	if(width != NULL)
		this->width = new double(*width);
	if(height != NULL)
		this->height = new double(*height);
}

class circle : public shapes
{
	private:
		double *radius;
	public:
		circle(double *);
		~circle()
		{
			std::cout << "<a>" << std::endl;
			if(radius != NULL)
				delete radius;
		}
		void Who_Are_You()
		{std::cout << "I'm Circle !" << std::endl;}
		void CALCULATE_AREA()
		{
			if(radius == NULL)
				std::cout << "Radius not assigned !" << std::endl;
			else
				area = M_PI * pow(*radius, 2);
		}
		void CALCULATE_PERIMETER()
		{
			if(radius == NULL)
				std::cout << "Width or height not assigned !" << std::endl;
			else
				perimeter = 2 * M_PI * *(radius);
		}
		double GET_AREA()
		{return area;}
		double GET_PERIMETER()
		{return perimeter;}	
};

circle::circle(double *radius = NULL)
{
	if(radius != NULL)
		this->radius = new double(*radius);
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	shapes *ary[2];
	double w = 15; double h = 10; double r = 2;
	ary[0] = new square(&w, &h);
	ary[1] = new circle(&r);
	for(int i = 0; i < 2; i++)
		ary[i]->CALCULATE_AREA();
	for(int i = 0; i < 2; i++)
		ary[i]->CALCULATE_PERIMETER();
	for(int i = 0; i < 2; i++)
		std::cout << ary[i]->GET_AREA() << std::endl;
	for(int i = 0; i < 2; i++)
		std::cout << ary[i]->GET_PERIMETER() << std::endl;
	for(int i = 0; i < 2; i++)
		delete ary[i];
	return 0;
}