#ifndef DATE_H
#define DATE_H
#endif // !DATE_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include"List.h"
using namespace std;

void UI()
{
	cout << "				****************************************************" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#              欢迎使用员工工资管理系统            #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                  1.创建员工链表                  #" << endl;
	cout << "				#                  2.输出员工链表                  #" << endl;
	cout << "				#                  3.查找员工信息                  #" << endl;
	cout << "				#                  4.删除员工信息                  #" << endl;
	cout << "				#                  5.修改员工信息                  #" << endl;
	cout << "				#                  6.读取员工信息                  #" << endl;
	cout << "				#                  7.发放工资                      #" << endl;
	cout << "				#                  0.退出系统                      #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				****************************************************" << endl;
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
		case 1:Cls(); H = CreateList(H);cout << "请按任意键返回菜单" << endl; Pas(); break;
		case 2:Cls(); PrintList(H); Pas(); break;
		case 3:Cls(); FindEmployee(H); Pas();  break;
		case 4:Cls(); DelEmployee(H); Pas();  break;
		case 5:Cls(); ChangeEmployee(H); Pas(); break;
		case 6:Cls(); Read(); Pas(); break;
		case 7:Cls(); Wages(H); Pas(); break;
		case 0:Cls();  Save(H); cout << "Thanks For Using!" << endl; Pas(); exit(0);
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