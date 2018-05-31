#include"employee.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Timing ;

class Fixed :virtual public Employee {
private:
	float bonus;
	float FixedWage;
	int LeaveDays;
	float Deduction;
	float Wage;
	int if_issue;
public:
	void AddEmployee();
	void SetFixed();
	void PrintEmployee();
	void ChangeEmployee();
	void SetFixedWage();
	void SetLeaveDays();
	~Fixed();
};

void Fixed::AddEmployee() {
	Employee::AddEmployee();
	cout << "����Ա���̶�н�ʣ�";
	cin >> FixedWage;
	cout << "����Ա�����������";
	cin >> LeaveDays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = LeaveDays * 30.0;
	Wage = FixedWage + bonus - Deduction;
	if_issue = 0;
	cout << "Ա����ӳɹ���\n";
}

void Fixed::SetFixed() {
	cout << "����Ա���̶�н�ʣ�";
	cin >> FixedWage;
	cout << "����Ա�����������";
	cin >> LeaveDays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = LeaveDays * 30.0;
	Wage = FixedWage + bonus - Deduction;
}

void Fixed::SetFixedWage()
{
	cout << "����̶�н��:";
	cin >> FixedWage;
	cout << "�̶�н���޸ĳɹ�!" << endl;
}

void Fixed::SetLeaveDays() {
	cout << "�����������:";
	cin >> LeaveDays;
	cout << "��������޸ĳɹ�!" << endl;
}

void Fixed::ChangeEmployee() {
	int c;
	int type;
	Employee *q;
	cout << "1.�޸�Ա��������Ϣ\n2.�޸�Ա��������Ϣ\n3.�޸�Ա��ȫ����Ϣ\n";
	cin >> c;
	if (c == 1)Employee::ChangeEmployee();
	else if (c == 2)Fixed::SetFixed();
	else if (c == 3) {
		Employee::ChangeEmployee();
		Fixed::SetFixed();
	}
}


void Fixed::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << FixedWage << " " << LeaveDays << " " << Deduction << " " << Wage << " " << if_issue << endl;
}

Fixed::~Fixed() {
	cout << "����" << endl;
}


class Timing :virtual public Employee {
private:
	float bonus;
	float Time;
	float HourWage;
	float OverTime;
	float Ratio;
	float Wage;
	int if_issue;
public:
	void AddEmployee();
	void SetTiming();
	void PrintEmployee();
	void ChangeEmployee();
	void SetHourWage();
	void SetEmployee();
	void SetRatio();
	~Timing();
};

void Timing::AddEmployee() {
	Employee::AddEmployee();
	cout << "����Ա������ʱ����";
	cin >> Time;
	cout << "����Ա��ʱн��";
	cin >> HourWage;
	cout << "����Ա���Ӱ๤�ʱ��ʣ�";
	cin >> Ratio;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	if (Time > 160) {
		OverTime = Time - 160;
		Wage = 160 * HourWage + OverTime*HourWage*Ratio + bonus;
	}
	else {
		OverTime = 0;
		Wage = Time * HourWage + bonus;
	}
	if_issue = 0;
	cout << "Ա����ӳɹ���\n";
}

void Timing::SetEmployee() {
	cout << "����Ա������ʱ����";
	cin >> Time;
	cout << "����Ա��ʱн��";
	cin >> HourWage;
	cout << "����Ա���Ӱ๤�ʱ��ʣ�";
	cin >> Ratio;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	if (Time > 160) {
		OverTime = Time - 160;
		Wage = 160 * HourWage + OverTime*HourWage*Ratio + bonus;
	}
	else {
		OverTime = 0;
		Wage = Time * HourWage + bonus;
	}
}

void Timing::SetHourWage()
{
	cout << "����Ա��ʱн:";
	cin >> HourWage;
	cout << "Ա��ʱн�޸ĳɹ�!" << endl;
}

void Timing::SetTiming() {
	cout << "����Ա������ʱ��:";
	cin >> Time;
	cout << "����ʱ���޸ĳɹ�!" << endl;
}

void Timing::SetRatio() {
	cout << "����Ա���Ӱ๤�ʱ���:";
	cin >> Ratio;
	cout << "�Ӱ๤�ʱ����޸ĳɹ�!" << endl;
}

void Timing::ChangeEmployee() {
	int c;
	int type;
	Employee *q;
	cout << "1.�޸�Ա��������Ϣ\n2.�޸�Ա��������Ϣ\n3.�޸�Ա��ȫ����Ϣ\n";
	cin >> c;
	if (c == 1)Employee::ChangeEmployee();
	else if (c == 2)Timing::SetEmployee();
	else if (c == 3) {
		Employee::ChangeEmployee();
		Timing::SetEmployee();
	}
}

void Timing::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << Time << " " << HourWage << " " << OverTime << " " << Wage << " " << if_issue << endl;
}

Timing ::~Timing() {
	cout << "����" << endl;
}