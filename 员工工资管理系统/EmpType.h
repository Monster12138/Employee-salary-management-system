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
	void Wages();
	void ChangeAll();
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
	if (Wage < 0)Wage = 0;
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
	if (Wage < 0)Wage = 0;
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
		Fixed::ChangeAll();
	}
}

void Fixed::ChangeAll() {
	Employee::ChangeEmployee();
	Fixed::SetFixed();
}

void Fixed::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << FixedWage << " " << LeaveDays << " " << Deduction << " " << Wage << " " << if_issue << endl;
}

void Fixed::Wages() {
	if_issue = 1;
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
	void Wages();
	void ChangeAll();
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
	if (Wage < 0)Wage = 0;
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
	if (Wage < 0)Wage = 0;
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
		Timing::ChangeAll();
	}
}

void Timing::ChangeAll() {
	Employee::ChangeEmployee();
	Timing::SetEmployee();
}

void Timing::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << Time << " " << HourWage << " " << OverTime << " " << Wage << " " << if_issue << endl;
}

void Timing::Wages() {
	if_issue = 1;
}

Timing ::~Timing() {
	cout << "����" << endl;
}

class Salesman :virtual public Employee {
private:
	float bonus;
	float Sale;
	float Reward;
	float Deduction;
	float Wage;
	int if_issue;
public:
	void AddEmployee();
	void PrintEmployee();
	void ChangeEmployee();
	void SetEmployee();
	void ChangeAll();
	~Salesman();
};

void Salesman::AddEmployee() {
	Employee::AddEmployee();
	cout << "����Ա�����۶";
	cin >> Sale;
	cout << "����Ա����ɱ���(�磺���Ϊ20%������0.2)��";
	cin >> Reward;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = 0;
	if (Sale < 30000) {
		Deduction = (30000 - Sale) * 0.002;
		Wage = Sale*Reward - Deduction + bonus;
	}
	else {
		Wage = Sale*Reward + bonus;
	}
	if (Wage < 0)Wage = 0;
	if_issue = 0;
	cout << "Ա����ӳɹ���\n";
}

void Salesman::SetEmployee() {
	cout << "����Ա�����۶";
	cin >> Sale;
	cout << "����Ա����ɱ���(�磺���Ϊ20%������0.2)��";
	cin >> Reward;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = 0;
	if (Sale < 30000) {
		Deduction = (30000 - Sale)*0.002;
		Wage = Sale*Reward - Deduction + bonus;
	}
	else {
		Wage = Sale*Reward + bonus;
	}
	if (Wage < 0)Wage = 0;
}

void Salesman::ChangeEmployee() {
	int c;
	int type;
	Employee *q;
	cout << "1.�޸�Ա��������Ϣ\n2.�޸�Ա��������Ϣ\n3.�޸�Ա��ȫ����Ϣ\n";
	cin >> c;
	if (c == 1)Employee::ChangeEmployee();
	else if (c == 2)Salesman::SetEmployee();
	else if (c == 3) {
		Salesman::ChangeAll();
	}
}

void Salesman::ChangeAll() {
	Employee::ChangeEmployee();
	Salesman::SetEmployee();
}

void Salesman::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << Sale << " " << Reward << " " << Deduction << " " << Wage << " " << if_issue << endl;
}

Salesman ::~Salesman() {
	cout << "����" << endl;
}

class PaidSalesman :virtual public Employee {
private:
	float bonus;
	float FixedWage;
	float Sale;
	float Reward;
	int Leavedays;
	float Deduction;
	float Wage;
	int if_issue;
public:
	void AddEmployee();
	void PrintEmployee();
	void ChangeEmployee();
	void SetEmployee();
	void ChangeAll();
	~PaidSalesman();
};

void PaidSalesman::AddEmployee() {
	Employee::AddEmployee();
	cout << "����Ա���̶�н��";
	cin >> FixedWage;
	cout << "����Ա�����۶";
	cin >> Sale;
	cout << "����Ա����ɱ���(�磺���Ϊ20%������0.2)��";
	cin >> Reward;
	cout << "����Ա�����������";
	cin >> Leavedays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = Leavedays * 30;
	if (Sale < 30000) Deduction += (30000 - Sale) * 0.002;
	Wage = FixedWage + Sale*Reward - Deduction + bonus;
	if (Wage < 0)Wage = 0;
	if_issue = 0;
	cout << "Ա����ӳɹ���\n";
}

void PaidSalesman::SetEmployee() {
	cout << "����Ա���̶�н��";
	cin >> FixedWage;
	cout << "����Ա�����۶";
	cin >> Sale;
	cout << "����Ա����ɱ���(�磺���Ϊ20%������0.2)��";
	cin >> Reward;
	cout << "����Ա�����������";
	cin >> Leavedays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = Leavedays * 30;
	if (Sale < 30000) Deduction += (30000 - Sale) * 0.002;
	Wage = FixedWage + Sale*Reward - Deduction + bonus;
	if (Wage < 0)Wage = 0;
}

void PaidSalesman::ChangeEmployee() {
	int c;
	int type;
	Employee *q;
	cout << "1.�޸�Ա��������Ϣ\n2.�޸�Ա��������Ϣ\n3.�޸�Ա��ȫ����Ϣ\n";
	cin >> c;
	if (c == 1)Employee::ChangeEmployee();
	else if (c == 2)PaidSalesman::SetEmployee();
	else if (c == 3) {
		PaidSalesman::ChangeAll();
	}
}

void PaidSalesman::ChangeAll() {
	Employee::ChangeEmployee();
	PaidSalesman::SetEmployee();
}

void PaidSalesman::PrintEmployee() {
	Employee::PrintEmployee();
	cout << bonus << " " << FixedWage <<" "<< Sale << " " << Reward << " " <<Leavedays <<" " << Deduction << " " << Wage << " " << if_issue << endl;
}

PaidSalesman ::~PaidSalesman() {
	cout << "����" << endl;
}