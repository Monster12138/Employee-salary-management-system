#include<string>
#include"Date.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

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
	virtual void AddEmployee();
	string GetName();
	string GetSex();
	int GetId();
	virtual void PrintEmployee();
	Date GetBrithday();
	void SetName();
	void SetSex();
	void SetBrithday();
	virtual void ChangeEmployee();
	void SetID(int x);
	string GetType();
	void SetType(string T);
	virtual void Wages();
	~Employee();
};

int Employee::num = 0;

void Employee::AddEmployee() {
	string n,s;
	int y, m, d;
	cout << "����Ա��������";
	cin >> n;
	cout << "����Ա���Ա�";
	cin >> s;
	cout << "����Ա���������ڣ�";
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
	cout << "����Ա��������";
	cin >> n;
	cout << "����Ա���Ա�";
	cin >> s;
	cout << "����Ա���������ڣ�";
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
	cout << "����Ա������:";
	cin >> name;
	cout << "�����޸���ɣ�\n";
}

void Employee::SetSex() {
	cout << "����Ա���Ա�:";
	cin >> sex;
	cout << "�Ա��޸���ɣ�\n";
}

void Employee::SetBrithday() {
	int y, m, d;
	cout << "����Ա����������:";
	cin >> y >> m >> d;
	brithday.SetDate(y,m,d);
	cout << "���������޸ĳɹ�!";
}

int Employee::GetId() {
	return id;
}

Date Employee::GetBrithday() {
	return brithday;
}

void Employee::PrintEmployee() {
	cout << id << " " << name << " " << sex << " " << brithday.GetYear() << "-" << brithday.GetMonth() << "-" << brithday.GetDay() << " " << Type << " ";
}

void Employee::Wages() {

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

Employee::~Employee() {
	cout << "������" << endl;
}

