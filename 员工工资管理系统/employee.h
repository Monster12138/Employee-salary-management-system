#include<string>
#include"Date.h"

using std::setw;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::internal;
using std::ofstream;
using std::ifstream;
using std::ios;

class Employee {
private:
	static int num;				
	int id;						
	string name;
	string sex;
	Date brithday;
	string Type;
public:
	class Employee *ptr = NULL;
	class Employee *next = NULL;
	virtual void AddEmployee();			//添加员工信息（虚）
	string GetName();					//获取姓名
	string GetSex();					//获取性别
	int GetId();						//获取工号
	virtual void PrintEmployee();		//输出员工基本信息（虚）
	Date GetBrithday();					//获取生日
	void SetName();						//设置姓名
	void SetSex();						//设置性别
	void SetBrithday();					//设置生日
	virtual void ChangeEmployee();		//修改员工基本信息（虚）
	void SetID(int x);					//设置工号
	string GetType();					//获取员工类型
	void SetType(string T);				//设置员工类型
	virtual void Wages(int x);			//发工资（虚）
	virtual void ChangeAll();			//修改所有员工信息（虚）
	virtual int GetIf_issue();			//获取是否领取工资（虚）
	virtual void SaveEmp();				//保存员工信息（虚）
	~Employee();						//析构
};

int Employee::num = 0;

void Employee::AddEmployee() {
	string n,s;
	int y, m, d;
	cout << "输入员工姓名：";
	cin >> n;
	cout << "输入员工性别：";
	cin >> s;
	cout << "输入员工出生日期：(年 月 日，中间用空格隔开)";
	cin >> y>>m>>d;
	num++;
	id = num;
	name = n;
	sex = s;
	brithday.SetDate(y, m, d);
}

void Employee::ChangeEmployee() {
	string n, s;
	int y, m, d;
	cout << "输入员工姓名：";
	cin >> n;
	cout << "输入员工性别：";
	cin >> s;
	cout << "输入员工出生日期：";
	cin >> y >> m >> d;
	name = n;
	sex = s;
	brithday.SetDate(y, m, d);
}

string Employee::GetName() {
	return name;
}

string Employee::GetSex() {
	return sex;
}

void Employee::SetName() {
	cout << "输入员工姓名:";
	cin >> name;
	cout << "姓名修改完成！\n";
}

void Employee::SetSex() {
	cout << "输入员工性别:";
	cin >> sex;
	cout << "性别修改完成！\n";
}

void Employee::SetBrithday() {
	int y, m, d;
	cout << "输入员工出生日期:";
	cin >> y >> m >> d;
	brithday.SetDate(y,m,d);
	cout << "出生日期修改成功!";
}

int Employee::GetId() {
	return id;
}

Date Employee::GetBrithday() {
	return brithday;
}

void Employee::PrintEmployee() {
	cout <<internal <<setw(4)<< id 
		<< internal <<setw(8)<< name 
		<< internal <<setw(6)<< sex 
		<< internal <<setw(8)<< brithday.GetYear() <<"-"
		<< internal << setw(2) << brithday.GetMonth() << "-"
		<< internal << setw(2) << brithday.GetDay() 
		<< internal << setw(12) << Type;
}

void Employee::Wages(int x) {

}

int Employee::GetIf_issue() {
	return -1;
}

void ::Employee::ChangeAll() {

}

void Employee::SetID(int x) {
	id = x;
}

string Employee::GetType() {
	return Type;
}

void Employee::SetType(string T) {
	Type = T;
}

void Employee::SaveEmp() {
	ofstream fout;
	fout.open("d:\\data.txt",ios::app);
	if (!fout) {
		cout << "不能打开文件！" << endl;
		exit(0);
	}
	else {
			fout << id << " "
				<< name << " "
				<< sex << " "
				<< brithday.GetYear()<< "-" 
				<< brithday.GetMonth()<<"-"
				<< brithday.GetDay() << " "
				<< Type << " ";
	}
	fout.close();
}


Employee::~Employee() {
	cout << "析构！" << endl;
}

