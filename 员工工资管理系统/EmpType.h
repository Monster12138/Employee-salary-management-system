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

void Fixed::SetFixedWage()
{
	cout << "输入固定薪资:";
	cin >> FixedWage;
	cout << "固定薪资修改成功!" << endl;
}

void Fixed::SetLeaveDays() {
	cout << "输入请假天数:";
	cin >> LeaveDays;
	cout << "请假天数修改成功!" << endl;
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
	cout << bonus << " " << FixedWage << " " << LeaveDays << " " << Deduction << " " << Wage << " " << if_issue << endl;
}

void Fixed::Wages() {
	if_issue = 1;
}

Fixed::~Fixed() {
	cout << "析构" << endl;
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

void Timing::SetHourWage()
{
	cout << "输入员工时薪:";
	cin >> HourWage;
	cout << "员工时薪修改成功!" << endl;
}

void Timing::SetTiming() {
	cout << "输入员工工作时长:";
	cin >> Time;
	cout << "工作时长修改成功!" << endl;
}

void Timing::SetRatio() {
	cout << "输入员工加班工资倍率:";
	cin >> Ratio;
	cout << "加班工资倍率修改成功!" << endl;
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
	cout << bonus << " " << Time << " " << HourWage << " " << OverTime << " " << Wage << " " << if_issue << endl;
}

void Timing::Wages() {
	if_issue = 1;
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
	cout << bonus << " " << Sale << " " << Reward << " " << Deduction << " " << Wage << " " << if_issue << endl;
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
	cout << bonus << " " << FixedWage <<" "<< Sale << " " << Reward << " " <<Leavedays <<" " << Deduction << " " << Wage << " " << if_issue << endl;
}

PaidSalesman ::~PaidSalesman() {
	cout << "析构" << endl;
}