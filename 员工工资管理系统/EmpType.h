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
	cout << "输入员工固定薪资：";
	cin >> FixedWage;
	cout << "输入员工请假天数：";
	cin >> LeaveDays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = LeaveDays * 30.0;
	Wage = FixedWage + bonus - Deduction;
	if (Wage < 0)Wage = 0;
	if_issue = 0;
	cout << "员工添加成功！\n";
}

void Fixed::SetFixed() {
	cout << "输入员工固定薪资：";
	cin >> FixedWage;
	cout << "输入员工请假天数：";
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
	cout << "1.修改员工基本信息\n2.修改员工工作信息\n3.修改员工全部信息\n";
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
		cout << "不能打开文件！" << endl;
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
	cout << "析构" << endl;
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
	cout << "输入员工工作时长：";
	cin >> Time;
	cout << "输入员工时薪：";
	cin >> HourWage;
	cout << "输入员工加班工资倍率：";
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
	cout << "员工添加成功！\n";
}

void Timing::SetEmployee() {
	cout << "输入员工工作时长：";
	cin >> Time;
	cout << "输入员工时薪：";
	cin >> HourWage;
	cout << "输入员工加班工资倍率：";
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
	cout << "1.修改员工基本信息\n2.修改员工工作信息\n3.修改员工全部信息\n";
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
		cout << "不能打开文件！" << endl;
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
	cout << "析构" << endl;
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
	cout << "输入员工销售额：";
	cin >> Sale;
	cout << "输入员工提成比例(如：提成为20%则输入0.2)：";
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
	cout << "员工添加成功！\n";
}

void Salesman::SetEmployee() {
	cout << "输入员工销售额：";
	cin >> Sale;
	cout << "输入员工提成比例(如：提成为20%则输入0.2)：";
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
	cout << "1.修改员工基本信息\n2.修改员工工作信息\n3.修改员工全部信息\n";
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
		cout << "不能打开文件！" << endl;
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
	cout << "析构" << endl;
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
	cout << "输入员工固定薪金：";
	cin >> FixedWage;
	cout << "输入员工销售额：";
	cin >> Sale;
	cout << "输入员工提成比例(如：提成为20%则输入0.2)：";
	cin >> Reward;
	cout << "输入员工请假天数：";
	cin >> Leavedays;
	if (GetBrithday().if_brithmonth())bonus = 200;
	else bonus = 0;
	Deduction = Leavedays * 30;
	if (Sale < 30000) Deduction += (30000 - Sale) * 0.002;
	Wage = FixedWage + Sale*Reward - Deduction + bonus;
	if (Wage < 0)Wage = 0;
	if_issue = 0;
	cout << "员工添加成功！\n";
}

void PaidSalesman::SetEmployee() {
	cout << "输入员工固定薪金：";
	cin >> FixedWage;
	cout << "输入员工销售额：";
	cin >> Sale;
	cout << "输入员工提成比例(如：提成为20%则输入0.2)：";
	cin >> Reward;
	cout << "输入员工请假天数：";
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
	cout << "1.修改员工基本信息\n2.修改员工工作信息\n3.修改员工全部信息\n";
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
		cout << "不能打开文件！" << endl;
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
	cout << "析构" << endl;
}