#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "test.h"
int test::derivative = 0;
int test::deleted = 0;
/*
Sabit Özellik ve Deðiþken: 
	Sabit olarak bir deðiþken tanýmlandýðý zaman tanýmlandýðý anda deðer gözetmeksizin sabitlenir ram e yani program kapanana kadar ram de
sabit olarak kalýr ve baþka tanýmlamalar yapýlsa dahi umrunda olmaz.
Sabit Fonksiyon ve Metod:
	Sabit olarak tanýmlanan bir fonksiyon sýnýf içerisinde ise ve public durumda ise illa bir nesne üretip o nesne üzerinden eriþmemize
gerek yok yani sýnýf ismi test olsun test içerisinde de static a fonksiyonu var biz a fonksiyonunu çalýþtýrmak için test.a þeklinde 
yazabiliriz.
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(3, 5, 7, 8);
	test *t2 = new test;
	test *t3 = new test(t1);
	t1.Write_Info();
	delete t2;
	t1.Write_Info();
	delete t3;
	t1.Write_Info();
	return 0;
}




