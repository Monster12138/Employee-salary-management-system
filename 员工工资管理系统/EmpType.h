#include"employee.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::internal;


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
	void Wages(int x);
	void ChangeAll();
	int GetIf_issue();
	void SaveEmp();
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
	cout << internal << setw(10) << bonus
		<< internal << setw(10) << FixedWage
		<< internal << setw(10) << LeaveDays
		<< internal << setw(10) << Deduction
		<< internal << setw(10) << Wage
		<< internal << setw(10) << if_issue
		<< endl;
}

void Fixed::Wages(int x) {
	if_issue = x;
}

int Fixed::GetIf_issue() {
	return if_issue;
}

void Fixed::SaveEmp() {
	ofstream fout;
	fout.open("d:\\data.txt", ios::app);
	if (!fout) {
		cout << "���ܴ��ļ���" << endl;
		exit(0);
	}
	else {
		fout << bonus << " "
			<< FixedWage << " "
			<< LeaveDays << " "
			<< Deduction << " "
			<< Wage << " "
			<< if_issue << "\n";
	}
	fout.close();
}

Fixed::~Fixed() {
	cout << "����" << endl;
}

//------------------------------------------------------------------------------------------------
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
	void PrintEmployee();
	void ChangeEmployee();
	void SetEmployee();
	void Wages(int x);
	void ChangeAll();
	int GetIf_issue();
	void SaveEmp();
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
	cout << internal << setw(10) << bonus
		<< internal << setw(10) << Time
		<< internal << setw(10) << HourWage
		<< internal << setw(10) << OverTime
		<< internal << setw(10) << Wage
		<< internal << setw(10) << if_issue
		<< endl;
}

void Timing::Wages(int x) {
	if_issue = x;
}

int Timing::GetIf_issue() {
	return if_issue;
}

void Timing::SaveEmp() {
	ofstream fout;
	fout.open("d:\\data.txt", ios::app);
	if (!fout) {
		cout << "���ܴ��ļ���" << endl;
		exit(0);
	}
	else {
		fout << bonus << " "
			<< Time << " "
			<< HourWage << " "
			<< OverTime << " "
			<< Ratio << " "
			<< Wage <<" "
			<<if_issue<<"\n";
	}
	fout.close();
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
	void Wages(int x);
	int GetIf_issue();
	void SaveEmp();
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
	cout << internal << setw(10) << bonus
		<< internal << setw(10) << Sale
		<< internal << setw(10) << Reward
		<< internal << setw(10) << Deduction
		<< internal << setw(10) << Wage
		<< internal << setw(10) << if_issue
		<< endl;
}

void Salesman::Wages(int x) {
	if_issue = x;
}

int Salesman::GetIf_issue() {
	return if_issue;
}

void Salesman::SaveEmp() {
	ofstream fout;
	fout.open("d:\\data.txt", ios::app);
	if (!fout) {
		cout << "���ܴ��ļ���" << endl;
		exit(0);
	}
	else {
		fout << bonus << " "
			<< Sale << " "
			<< Reward << " "
			<< Deduction << " "
			<< Wage << " "
			<< if_issue << "\n";
	}
	fout.close();
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
	void Wages(int x);
	int GetIf_issue();
	void SaveEmp();
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
	cout << internal << setw(10) << bonus
		<< internal << setw(10) << FixedWage
		<< internal << setw(10) << Sale
		<< internal << setw(10) << Reward
		<< internal << setw(10) << Deduction
		<< internal << setw(10) << Wage
		<< internal << setw(10) << if_issue
		<< endl;
}

void PaidSalesman::Wages(int x) {
	if_issue = x;
}

int PaidSalesman::GetIf_issue() {
	return if_issue;
}

void PaidSalesman::SaveEmp() {
	ofstream fout;
	fout.open("d:\\data.txt", ios::app);
	if (!fout) {
		cout << "���ܴ��ļ���" << endl;
		exit(0);
	}
	else {
		fout << bonus << " "
			<<FixedWage<<" "
			<< Sale << " "
			<< Reward << " "
			<< Leavedays << " "
			<< Deduction << " "
			<< Wage << " "
			<< if_issue << "\n";
	}
	fout.close();
}

PaidSalesman ::~PaidSalesman() {
	cout << "����" << endl;
}