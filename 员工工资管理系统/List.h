#include"EmpType.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::internal;
using std::setw;

void InputTips() {
	system("cls");
	cout << "��������ȷѡ�" << endl;
}

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
		cout << "1.�̶�н��\n2.��ʱְԱ\n3.��ͨ����Ա\n4.��н����Ա\n";
		cin >> type;
		switch (type)
		{
		case 1:q = new Fixed; break;
		case 2:q = new Timing; break;
		case 3:q = new Salesman; break;
		case 4:q = new PaidSalesman; break;
		default:InputTips(); continue;
		}
		q->AddEmployee();
		switch (type)
		{
		case 1:q->SetType("�̶�н��"); break;
		case 2:q->SetType("��ʱְ��"); break;
		case 3:q->SetType("��ͨ����Ա"); break;
		case 4:q->SetType("��н����Ա"); break;
		}
		p->next = q;
		q->ptr = p;
		q->next = NULL;
		p = p->next;
		while (1)
		{
			cout << "�����������1�������������0:";
			cin >> c;
			if (c != 1 && c != 0) {
				InputTips();
				continue;
			}
			else
			{
				break;
			}

		}
	}
	return H;
}

void FormatOutput() {
	cout << internal << setw(5) << "����";
	cout << internal << setw(6) << "����";
	cout << internal << setw(6) << "�Ա�";
	cout << internal << setw(12) << "��������";
	cout << internal << setw(10) << "����";
	cout << internal << setw(13) << "����н��";
}

void PrintList(Employee *H) {
	Employee *p = H->next;
	cout << "******************************************�̶���н******************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "�̶�н��"
		<< internal << setw(10) << "�������"
		<< internal << setw(10) << "Ӧ�۹���"
		<< internal << setw(10) << "ʵ������"
		<< internal << setw(10) << "�Ƿ���ȡ"
		<< endl;
	while (p) {
		if (p->GetType() == "�̶�н��") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	p = H->next;
	cout << "******************************************��ʱְ��***************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "����ʱ��"
		<< internal << setw(10) << "ʱн"
		<< internal << setw(10) << "�Ӱ�ʱ��"
		<< internal << setw(10) << "ʵ������"
		<< internal << setw(10) << "�Ƿ���ȡ"
		<< endl;
	//cout << "���� ���� �Ա� �������� ���� ����н�� ����ʱ�� ʱн  �Ӱ�ʱ�� ʵ������ �Ƿ���ȡ" << endl;
	while (p) {
		if (p->GetType() == "��ʱְ��") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	p = H->next;
	cout << "****************************************��ͨ����Ա****************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "���۶�"
		<< internal << setw(10) << "��ɱ���"
		<< internal << setw(10) << "Ӧ�۹���"
		<< internal << setw(10) << "ʵ������"
		<< internal << setw(10) << "�Ƿ���ȡ"
		<< endl;
	//cout << "���� ���� �Ա� �������� ���� ����н�� ���۶� ��ɱ��� Ӧ�۹��� ʵ������ �Ƿ���ȡ" << endl;
	while (p) {
		if (p->GetType() == "��ͨ����Ա") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	p = H->next;
	cout << "*********************************************��н����Ա********************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "�̶���н"
		<< internal << setw(10) << "���۶�"
		<< internal << setw(10) << "��ɱ���"
		<< internal << setw(10) << "Ӧ�۹���"
		<< internal << setw(10) << "ʵ������"
		<< internal << setw(10) << "�Ƿ���ȡ"
		<< endl;
	//cout << "���� ���� �Ա� �������� ���� ����н�� �̶���н ���۶� ��ɱ��� Ӧ�۹��� ʵ������ �Ƿ���ȡ" << endl;
	while (p) {
		if (p->GetType() == "��н����Ա") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
}

Employee *FindEmployee(Employee *H) {
	int c;
	Employee *p = H->next;
	cout << "1.�����Ų���\n2.����������\n";
	cin >> c;
	if (c != 1 && c != 0) {
		InputTips();
		return NULL;
	}
	if (c) {
		int num;
		cout << "���빤��:";
		cin >> num;
		while (p) {
			if (p->GetId() == num)break;
			p = p->next;
		}
		if (p == NULL) {
			cout << "���޴���!\n";
			FindEmployee(H);
		}
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
				cout << "���޴���!\n";
				FindEmployee(H);
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
	if (c != 1 && c != 0) {
		InputTips();
		return;
	}
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
	if (c != 1 && c != 0) {
		InputTips();
		return;
	}
	if (c) {
		cout << "ѡ���޸ķ�ʽ:\n";
		cout << "1.�޸�Ա��������Ϣ;0.�޸�Ա������\n";
		cin >> x;
		if (x != 1 && x != 0) {
			InputTips();
			return;
		}
		if (x)p->ChangeEmployee();
		else {
			cout << "������Ҫ��Ա�������޸�Ϊ��\n1.�̶�н��\n2.��ʱְ��\n3.��ͨ����Ա\n4.��н����Ա\n";
			cin >> type;
			switch (type)
			{
			case 1: {
				q = new Fixed;
				q->SetType("�̶�н��");
				break;
			}
			case 2: {
				q = new Timing;
				q->SetType("��ʱְ��");
				break;
			}
			case 3: {
				q = new Salesman;
				q->SetType("��ͨ����Ա");
				break;
			}
			case 4: {
				q = new PaidSalesman;
				q->SetType("��н����Ա");
				break;
			}
			default:InputTips(); break;
			}
			q->Wages(p->GetIf_issue());
			q->SetID(p->GetId());
			q->ChangeAll();
			if(p->next)p->next->ptr = q;
			q->next = p->next;
			q->ptr = p->ptr;
			p->ptr->next = q;
		}
	}
	else {
		ChangeEmployee(H);
	}
}

void WageType(Employee *H,string x) {
	Employee *p = H->next;
	while (p)
	{
		if (p->GetType() == "�̶�н��") {
			p->Wages(1);
			p = p->next;
		}
		else p = p->next;
	}
}

void Wages(Employee *H) {
	Employee *p = H->next;
	Employee *q = NULL;
	int x;
	int type;
	cout << "ѡ�񷢹��ʷ�ʽ:\n";
	cout << "1.��Ա��������\n2.�����ͷ�����\n";
	cin >> x;
	if (x != 1 && x != 2) {
		InputTips();
		return;
	}
	if (x == 1) {
		p = FindEmployee(H);
		p->Wages(1);
	}
	else {
		cout << "���������һ��Ա�������ʣ�\n1.�̶�н��\n2.��ʱְ��\n3.��ͨ����Ա\n4.��н����Ա\n";
		cin >> type;
		switch (type)
		{
		case 1: {
			WageType(H, "�̶�н��");
			break;
		}
		case 2: {
			WageType(H, "��ʱְ��");
			break;
		}
		case 3: {
			WageType(H, "��ͨ����Ա");
			break;
		}
		case 4: {
			WageType(H, "��н����Ա");
			break;
		}
		default:InputTips(); break;
		}
	}
	cout << "���ʷ������!" << endl;
}