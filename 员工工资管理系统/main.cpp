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
	cout << "				#              ��ӭʹ��Ա�����ʹ���ϵͳ            #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                  1.����Ա������                  #" << endl;
	cout << "				#                  2.���Ա������                  #" << endl;
	cout << "				#                  3.����Ա����Ϣ                  #" << endl;
	cout << "				#                  4.ɾ��Ա����Ϣ                  #" << endl;
	cout << "				#                  5.�޸�Ա����Ϣ                  #" << endl;
	cout << "				#                  6.��ȡԱ����Ϣ                  #" << endl;
	cout << "				#                  7.���Ź���                      #" << endl;
	cout << "				#                  0.�˳�ϵͳ                      #" << endl;
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
		cout << "������ѡ��:";
		cin >> c;
		switch (c) {
		case 1:Cls(); H = CreateList(H);cout << "�밴��������ز˵�" << endl; Pas(); break;
		case 2:Cls(); PrintList(H); Pas(); break;
		case 3:Cls(); FindEmployee(H); Pas();  break;
		case 4:Cls(); DelEmployee(H); Pas();  break;
		case 5:Cls(); ChangeEmployee(H); Pas(); break;
		case 6:Cls(); Read(); Pas(); break;
		case 7:Cls(); Wages(H); Pas(); break;
		case 0:Cls();  Save(H); cout << "Thanks For Using!" << endl; Pas(); exit(0);
		default:Cls(); cout << "��������ȷѡ�" << endl; Pas(); continue;
		}
	}
}

int main()
{
	Employee *Head = NULL;
	menu(Head);
	return 0;
}