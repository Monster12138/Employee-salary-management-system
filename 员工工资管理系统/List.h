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
		cout << "请输入要添加的员工工种：" << endl;
		cout << "1.固定薪资\n2.计时职员\n";
		cin >> type;
		switch (type)
		{
		case 1:q = new Fixed; break;
		case 2:q = new Timing; break;
		}
		q->AddEmployee();
		switch (type)
		{
		case 1:q->SetType("固定薪资"); break;
		case 2:q->SetType("计时职工"); break;
		}
		p->next = q;
		q->ptr = p;
		q->next = NULL;
		p = p->next;
		cout << "继续添加输入1，结束添加输入0:";
		cin >> c;
	}
	return H;
}

void PrintList(Employee *H) {
	Employee *p = H->next;
	cout << "工号 姓名 性别 出生日期 工种 奖励薪金 固定薪金 请假天数 应扣工资 实发工资 是否领取" << endl;
	while (p) {
		p->PrintEmployee();
		p = p->next;
	}
}

Employee *FindEmployee(Employee *H) {
	int c;
	Employee *p = H->next;
	cout << "1.按工号查找\n2.按姓名查找\n";
	cin >> c;
	if (c) {
		int num;
		cout << "输入工号:";
		cin >> num;
		while (p) {
			if (p->GetId() == num)break;
			p = p->next;
		}
		if (p == NULL)cout << "查无此人!";
	}
	else {
		if (c) {
			string n;
			cout << "输入姓名:";
			cin >> n;
			while (p) {
				if (p->GetName() == n)break;
				p = p->next;
			}
			if (p == NULL) {
				cout << "查无此人!";
			}
		}
	}
	cout << "查找到员工:\n";
	p->PrintEmployee();
	return p;
}

void DelEmployee(Employee *H) {
	Employee *p = H->next;
	cout << "选择删除方式:\n";
	p = FindEmployee(H);
	cout << "确定要删除此员工？此操作不可恢复！\n0.否\n1.是\n";
	int c;
	cin >> c;
	if (c) {
		p->ptr->next = p->next;
		if(p->next)p->next->ptr = p->ptr;
		cout << "删除成功！\n";
	}
	else {
		DelEmployee(H);
	}
}

void ChangeEmployee(Employee *H) {
	Employee *p = H->next;
	Employee *q = NULL;
	p = FindEmployee(H);
	cout << "确定要修改此员工信息？此操作不可恢复！\n0.否\n1.是\n";
	int c;
	int x;
	int type;
	cin >> c;
	if (c) {
		cout << "选择修改方式:\n";
		cout << "1.修改员工其他信息;0.修改员工工种\n";
		cin >> x;
		if (x)p->ChangeEmployee();
		else {
			cout << "请输入要将员工工种修改为：\n1.固定薪资\n2.计时职工\n";
			cin >> type;
			switch (type)
			{
			case 1: {
				q = new Fixed;
				q->SetType("固定薪资");
				q->AddEmployee();
				p->next->ptr = q;
				q->next = p->next;
				q->ptr = p->ptr; 
				p->ptr->next = q;
				break;
			}
			case 2: {
				q = new Timing;
				q->SetType("计时职工");
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