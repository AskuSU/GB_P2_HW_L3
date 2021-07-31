#include<iostream>
#include<windows.h>
#include"MyLib.h"
//#include"Task1.h"
//#include"Task2.h"
//#include"Task3.h"
#include"Task4.h"

using namespace std;
using namespace myLib;

#define SIZE_ARRAY 100

void Task1()
{
	cout << "Создаем студента:" << endl << endl;
	cout << "Введите Имя: ";		
}

void Task2()
{
	cout << "Работа с классом Фрукты:" << endl << endl;
	
}

void Task3()
{
	
}

void Task4()
{
	cout << "Работа с классом Колоды карт:" << endl << endl;

	Deck deck;
}


int main()
{
	setlocale(LC_ALL, "RU");
	//srand(time(0));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned short taskNumber = 0;
	while (true)
	{
		taskNumber = getUserSelectedTask(4);
		switch (taskNumber)
		{
		case 1: Task1();
			break;
		case 2: Task2();
			break;
		case 3: Task3();
			break;
		case 4: Task3();
			break;
		}
		cout << endl;
	}
}