#include"EmpType.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::internal;
using std::setw;
using std::ofstream;
using std::ifstream;

void InputTips() {											//输入错误时提示函数
	system("cls");
	cout << "\n\n\n\n\n\n";
	cout << "请输入正确选项！" << endl;
}						

void Cls() {												//清屏，对齐函数
	system("cls");
	cout << "\n\n\n\n\n\n";
}
	
void Save(Employee *H) {									//保存员工信息函数
	if (!H)return;
	ofstream f("d://data.txt");
	f.close();
	Employee *p = H->next;
	while (p) {
		p->Employee::SaveEmp();								//调用父类中的保存函数
		p->SaveEmp();										//调用子类中的保存函数
		p = p->next;
	}
	cout << "存储成功！" << endl;
}

void Read() {												//读取员工信息函数
	ifstream fin;
	char c;
	fin.open("d://data.txt");
	do {
		fin.get(c);
		if (fin.eof())break;
		cout << c;
	} while (!fin.eof());
	fin.close();
}

Employee *CreateList(Employee *H) {							//创建链表函数
	Employee *p, *q;
	H = new Employee;
	H->ptr = NULL;
	H->next = NULL;
	int c = 1;
	int type = 0;
	p = H;
	while (c)
	{
		cout << "请输入要添加的员工工种：" << endl;
		cout << "1.固定薪资\n2.计时职员\n3.普通销售员\n4.带薪销售员\n";
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
		case 1:q->SetType("固定薪资"); break;
		case 2:q->SetType("计时职工"); break;
		case 3:q->SetType("普通销售员"); break;
		case 4:q->SetType("带薪销售员"); break;
		}
		p->next = q;
		q->ptr = p;
		q->next = NULL;
		p = p->next;
		while (1)
		{
			cout << "继续添加输入1，结束添加输入0:";
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
		Cls();
	}
	return H;
}

void FormatOutput() {									//格式化对齐输出函数
	cout << internal << setw(5) << "工号";
	cout << internal << setw(6) << "姓名";
	cout << internal << setw(8) << "性别";
	cout << internal << setw(12) << "出生日期";
	cout << internal << setw(10) << "工种";
	cout << internal << setw(13) << "奖励薪金";
}

void PrintList(Employee *H) {							//链表输出函数
	Employee *p = H->next;
	cout << "***********************************************固定月薪***********************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "固定薪金"
		<< internal << setw(10) << "请假天数"
		<< internal << setw(10) << "应扣工资"
		<< internal << setw(10) << "实发工资"
		<< internal << setw(10) << "是否领取"
		<< endl;
	while (p) {
		if (p->GetType() == "固定薪资") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	cout << "------------------------------------------------------------------------------------------------------\n" << endl;
	p = H->next;
	cout << "***********************************************计时职工***********************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "工作时长"
		<< internal << setw(10) << "时薪"
		<< internal << setw(10) << "加班时长"
		<< internal << setw(10) << "实发工资"
		<< internal << setw(10) << "是否领取"
		<< endl;
	while (p) {
		if (p->GetType() == "计时职工") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	cout << "------------------------------------------------------------------------------------------------------\n" << endl;
	p = H->next;
	cout << "***********************************************普通销售员*********************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "销售额"
		<< internal << setw(10) << "提成比例"
		<< internal << setw(10) << "应扣工资"
		<< internal << setw(10) << "实发工资"
		<< internal << setw(10) << "是否领取"
		<< endl;
	while (p) {
		if (p->GetType() == "普通销售员") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	cout << "------------------------------------------------------------------------------------------------------\n" << endl;
	p = H->next;
	cout << "****************************************************带薪销售员**************************************************" << endl;
	FormatOutput();
	cout << internal << setw(10) << "固定月薪"
		<< internal << setw(10) << "销售额"
		<< internal << setw(10) << "提成比例"
		<< internal << setw(10) << "应扣工资"
		<< internal << setw(10) << "实发工资"
		<< internal << setw(10) << "是否领取"
		<< endl;
	while (p) {
		if (p->GetType() == "带薪销售员") {
			p->PrintEmployee();
			p = p->next;
		}
		else p = p->next;
	}
	cout << "----------------------------------------------------------------------------------------------------------------\n" << endl;
}

Employee *FindEmployee(Employee *H) {								//查找员工函数
	int c;
	Employee *p = H->next;
	cout << "1.按工号查找\n2.按姓名查找\n";
	cin >> c;
	if (c != 1 && c != 2) {
		InputTips();
		return NULL;
	}
	if (c == 1) {
		int num;
		cout << "输入工号:";
		cin >> num;
		while (p) {
			if (p->GetId() == num)break;
			p = p->next;
		}
		if (p == NULL) {
			cout << "查无此人!\n";
			return NULL;
		}
	}
	else {
		string n;
		cout << "输入姓名:";
		cin >> n;
		while (p) {
			if (p->GetName() == n)break;
			p = p->next;
		}
		if (p == NULL) {
			cout << "查无此人!\n";
			return NULL;
		}
	}
	cout << "查找到员工:\n";
	FormatOutput();
	if (p->GetType() == "固定薪资") {
		cout << internal << setw(10) << "固定薪金"
			<< internal << setw(10) << "请假天数"
			<< internal << setw(10) << "应扣工资"
			<< internal << setw(10) << "实发工资"
			<< internal << setw(10) << "是否领取"
			<< endl;
	}
	else if (p->GetType() == "计时职工") {
		cout << internal << setw(10) << "工作时长"
			<< internal << setw(10) << "时薪"
			<< internal << setw(10) << "加班时长"
			<< internal << setw(10) << "实发工资"
			<< internal << setw(10) << "是否领取"
			<< endl;
	}
	else if (p->GetType() == "普通销售员") {
		cout << internal << setw(10) << "销售额"
			<< internal << setw(10) << "提成比例"
			<< internal << setw(10) << "应扣工资"
			<< internal << setw(10) << "实发工资"
			<< internal << setw(10) << "是否领取"
			<< endl;
	}
	else if (p->GetType() == "带薪销售员") {
		cout << internal << setw(10) << "固定月薪"
			<< internal << setw(10) << "销售额"
			<< internal << setw(10) << "提成比例"
			<< internal << setw(10) << "应扣工资"
			<< internal << setw(10) << "实发工资"
			<< internal << setw(10) << "是否领取"
			<< endl;
	}
	p->PrintEmployee();
	return p;
}

void DelEmployee(Employee *H) {								//删除员工函数
	Employee *p = H->next;
	cout << "选择删除方式:\n";
	p = FindEmployee(H);
	if (!p)return;
	cout << "确定要删除此员工？此操作不可恢复！\n0.否\n1.是\n";
	int c;
	cin >> c;
	if (c != 1 && c != 0) {
		InputTips();
		return;
	}
	if (c) {
		p->ptr->next = p->next;
		if(p->next)p->next->ptr = p->ptr;
		cout << "删除成功！\n";
	}
	else {
		DelEmployee(H);
	}
}

void ChangeEmployee(Employee *H) {							//修改员工信息函数
	Employee *p = H->next;
	Employee *q = NULL;
	p = FindEmployee(H);
	if (!p)return;
	cout << "确定要修改此员工信息？此操作不可恢复！\n0.否\n1.是\n";
	int c;
	int x;
	int type;
	cin >> c;
	if (c != 1 && c != 0) {
		InputTips();
		return;
	}
	if (c) {
		cout << "选择修改方式:\n";
		cout << "1.修改员工其他信息;0.修改员工工种\n";
		cin >> x;
		if (x != 1 && x != 0) {
			InputTips();
			return;
		}
		if (x)p->ChangeEmployee();
		else {
			cout << "请输入要将员工工种修改为：\n1.固定薪资\n2.计时职工\n3.普通销售员\n4.带薪销售员\n";
			cin >> type;
			switch (type)
			{
			case 1: {
				q = new Fixed;
				q->SetType("固定薪资");
				break;
			}
			case 2: {
				q = new Timing;
				q->SetType("计时职工");
				break;
			}
			case 3: {
				q = new Salesman;
				q->SetType("普通销售员");
				break;
			}
			case 4: {
				q = new PaidSalesman;
				q->SetType("带薪销售员");
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

void WageType(Employee *H,string x) {						//按员工类型发工资函数			
	Employee *p = H->next;
	while (p)
	{
		if (p->GetType() == x) {
			p->Wages(1);
			p = p->next;
		}
		else p = p->next;
	}
}

void Wages(Employee *H) {									//员工发工资函数
	Employee *p = H->next;
	Employee *q = NULL;
	int x;
	int type;
	cout << "选择发工资方式:\n";
	cout << "1.按员工发工资\n2.按类型发工资\n";
	cin >> x;
	if (x != 1 && x != 2) {
		InputTips();
		return;
	}
	if (x == 1) {
		p = FindEmployee(H);
		if (!p)return;
		p->Wages(1);
	}
	else {
		cout << "请输入给哪一类员工发工资：\n1.固定薪资\n2.计时职工\n3.普通销售员\n4.带薪销售员\n";
		cin >> type;
		switch (type)
		{
		case 1: {
			WageType(H, "固定薪资");
			break;
		}
		case 2: {
			WageType(H, "计时职工");
			break;
		}
		case 3: {
			WageType(H, "普通销售员");
			break;
		}
		case 4: {
			WageType(H, "带薪销售员");
			break;
		}
		default:InputTips(); break;
		}
	}
	cout << "工资发放完成!" << endl;
}