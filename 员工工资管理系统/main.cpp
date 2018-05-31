#ifndef DATE_H
#define DATE_H
#endif // !DATE_H

#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	Employee *Head = NULL;
	Head = CreateList(Head);
	PrintList(Head);
	ChangeEmployee(Head);
	PrintList(Head);
	system("pause");
	return 0;
}