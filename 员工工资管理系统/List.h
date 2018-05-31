#include"EmpType.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

Employee *CreateList(Employee *H) {
	Employee *p, *q;
	H = new Employee;
	H->ptr = NULL;
	H->next = NULL;
	int c = 1;
	int type = 0;
	p = H;
	while (c)
	{
		cout << "������Ҫ��ӵ�Ա�����֣�" << endl;
		cout << "1.�̶�н��\n2.��ʱְԱ\n";
		cin >> type;
		switch (type)
		{
		case 1:q = new Fixed; break;
		case 2:q = new Timing; break;
		}
		q->AddEmployee();
		switch (type)
		{
		case 1:q->SetType("�̶�н��"); break;
		case 2:q->SetType("��ʱְ��"); break;
		}
		p->next = q;
		q->ptr = p;
		q->next = NULL;
		p = p->next;
		cout << "�����������1�������������0:";
		cin >> c;
	}
	return H;
}

void PrintList(Employee *H) {
	Employee *p = H->next;
	cout << "���� ���� �Ա� �������� ���� ����н�� �̶�н�� ������� Ӧ�۹��� ʵ������ �Ƿ���ȡ" << endl;
	while (p) {
		p->PrintEmployee();
		p = p->next;
	}
}

Employee *FindEmployee(Employee *H) {
	int c;
	Employee *p = H->next;
	cout << "1.�����Ų���\n2.����������\n";
	cin >> c;
	if (c) {
		int num;
		cout << "���빤��:";
		cin >> num;
		while (p) {
			if (p->GetId() == num)break;
			p = p->next;
		}
		if (p == NULL)cout << "���޴���!";
	}
	else {
		if (c) {
			string n;
			cout << "��������:";
			cin >> n;
			while (p) {
				if (p->GetName() == n)break;
				p = p->next;
			}
			if (p == NULL) {
				cout << "���޴���!";
			}
		}
	}
	cout << "���ҵ�Ա��:\n";
	p->PrintEmployee();
	return p;
}

void DelEmployee(Employee *H) {
	Employee *p = H->next;
	cout << "ѡ��ɾ����ʽ:\n";
	p = FindEmployee(H);
	cout << "ȷ��Ҫɾ����Ա�����˲������ɻָ���\n0.��\n1.��\n";
	int c;
	cin >> c;
	if (c) {
		p->ptr->next = p->next;
		if(p->next)p->next->ptr = p->ptr;
		cout << "ɾ���ɹ���\n";
	}
	else {
		DelEmployee(H);
	}
}

void ChangeEmployee(Employee *H) {
	Employee *p = H->next;
	Employee *q = NULL;
	p = FindEmployee(H);
	cout << "ȷ��Ҫ�޸Ĵ�Ա����Ϣ���˲������ɻָ���\n0.��\n1.��\n";
	int c;
	int x;
	int type;
	cin >> c;
	if (c) {
		cout << "ѡ���޸ķ�ʽ:\n";
		cout << "1.�޸�Ա��������Ϣ;0.�޸�Ա������\n";
		cin >> x;
		if (x)p->ChangeEmployee();
		else {
			cout << "������Ҫ��Ա�������޸�Ϊ��\n1.�̶�н��\n2.��ʱְ��\n";
			cin >> type;
			switch (type)
			{
			case 1: {
				q = new Fixed;
				q->SetType("�̶�н��");
				q->AddEmployee();
				p->next->ptr = q;
				q->next = p->next;
				q->ptr = p->ptr; 
				p->ptr->next = q;
				break;
			}
			case 2: {
				q = new Timing;
				q->SetType("��ʱְ��");
				q->AddEmployee();
				p->next->ptr = q;
				q->next = p->next;
				q->ptr = p->ptr;
				p->ptr->next = q;
				break;
			}
			}
		}
	}
	else {
		ChangeEmployee(H);
	}
}