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
	cout << "				#              ��ӭʹ��Ա�����ʹ���ϵͳ            #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                                                  #" << endl;
	cout << "				#                  0.����Ա������                  #" << endl;
	cout << "				#                  1.���Ա������                  #" << endl;
	cout << "				#                  2.����Ա����Ϣ                  #" << endl;
	cout << "				#                  3.ɾ��Ա����Ϣ                  #" << endl;
	cout << "				#                  4.�޸�Ա����Ϣ                  #" << endl;
	cout << "				#                  5.�˳�ϵͳ                      #" << endl;
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
		cout << "������ѡ��:";
		cin >> c;
		switch (c) {
		case 0:Cls(); H = CreateList(H); Pas(); break;
		case 1:Cls(); PrintList(H); Pas(); break;
		case 2:Cls(); FindEmployee(H); Pas();  break;
		case 3:Cls(); DelEmployee(H); Pas();  break;
		case 4:Cls(); ChangeEmployee(H); Pas(); break;
		case 5:Cls(); cout << "Thanks For Using!" << endl; Pas(); exit(0);
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