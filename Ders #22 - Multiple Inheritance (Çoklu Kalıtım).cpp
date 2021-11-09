#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Çoklu Kalýtým - Multiple Inheritance
	Bir sýnýf iki farklý sýnýftan özellikler taþýyabilir bunun için çoklu kalýtým kullanýlýr.
*/

class printer
{
	public:
		printer(std::string);
		~printer(){std::cout << "Printer destructor worked !" << std::endl;}
		void Call_Printer(){std::cout << "Printer is called !" << std::endl;}	
};

printer::printer(std::string pws = "")
{std::cout << pws << "Printer constructor worked !" << std::endl;}

class scanner
{
	public:
		scanner(std::string);
		~scanner(){std::cout << "Scanner destructor worked !" << std::endl;}
		void Call_Scanner(){std::cout << "Scanner is called !" << std::endl;}	
};

scanner::scanner(std::string pws = "")
{std::cout << pws << "Scanner constructor worked !" << std::endl;}

class pws : public printer, public scanner /*printer with scanner*/
{
	public:
		pws() : printer("[PWS] "), scanner("[PWS] "){std::cout << "Printer with scanner constructor worked !" << std::endl;}
		~pws(){std::cout << "Printer with scanner destructor worked !" << std::endl;}
		void Call_Printer(){std::cout << "Printer with scanner is called !" << std::endl;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	std::cout << "PRINTER OBJECT" << std::endl;
	printer p;
	std::cout << std::endl;
	std::cout << "SCANNER OBJECT" << std::endl;
	scanner s;
	std::cout << std::endl;
	std::cout << "PRINTER WITH SCANNER OBJECT" << std::endl;
	pws ps;
	return 0;
}
