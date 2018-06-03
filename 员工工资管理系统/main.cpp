#ifndef DATE_H
#define DATE_H
#endif // !DATE_H

#include<iostream>
#include"List.h"
using namespace std;

void UI()
{
	cout << "				****************************************************" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#              欢迎使用员工工资管理系统            #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                  0.创建员工链表                  #" << endl;
	cout << "				#                  1.输出员工链表                  #" << endl;
	cout << "				#                  2.查找员工信息                  #" << endl;
	cout << "				#                  3.删除员工信息                  #" << endl;
	cout << "				#                  4.修改员工信息                  #" << endl;
	cout << "				#                  5.退出系统                      #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				****************************************************" << endl;
}

void Cls() {
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "				----------------------------------------------------"<<endl;
}

void Pas() {
	system("pause");
}

void  menu(Employee *H){
	int c;
	while (1) {
		Cls();
		UI();
		cout << "请输入选项:";
		cin >> c;
		switch (c) {
		case 0:Cls(); H = CreateList(H); Pas(); break;
		case 1:Cls(); PrintList(H); Pas(); break;
		case 2:Cls(); FindEmployee(H); Pas();  break;
		case 3:Cls(); DelEmployee(H); Pas();  break;
		case 4:Cls(); ChangeEmployee(H); Pas(); break;
		case 5:Cls(); cout << "Thanks For Using!" << endl; Pas(); exit(0);
		default:Cls(); cout << "请输入正确选项！" << endl; Pas(); continue;
		}
	}
}

int main()
{
	Employee *Head = NULL;
	menu(Head);
	return 0;
}