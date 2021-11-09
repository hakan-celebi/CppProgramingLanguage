#include <iostream>
#include <string>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Turkish");
	int i = 0;
	for(i; i > 10; i--)
	{
		std::cout << i << std::endl;
		i++;
	}
	return 0;
}
