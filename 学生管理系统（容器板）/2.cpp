//备份 没有添加用户类
// 还有成绩具体类
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<sstream>
//#include<list>//双向链表
//
//void menu()
//{
//	cout << "------------------------------" << endl;
//	cout << "*****1.添加人数*****" << endl;
//	cout << "*****2.删除人数*****" << endl;
//	cout << "*****3.查找某人*****" << endl;
//	cout << "*****4.修改数据*****" << endl;
//	cout << "*****5.成绩升序*****" << endl;
//	cout << "*****6.成绩降序*****" << endl;
//	cout << "***7.全部元素展示***" << endl;
//	cout << "*****8.保存到文件*****" << endl;
//	cout << "****9.查看文件信息*****" << endl;
//	cout << "*****0.退出程序*****" << endl;
//	cout << "------------------------------" << endl;
//}
//
//class student
//{
//public:
//	string m_name;
//	int m_age;
//	int m_id;
//	double m_score;
//};
//
//
//class studata
//{
//public:
//	list<student>stu;
//
//	void savetoFinle()
//	{
//		const string finename = "student_data.txt";
//		ofstream outFile(finename);
//		if (!outFile)
//		{
//			cerr << "无法打开文件" << endl;
//		}
//		for (const auto& it : stu)
//		{
//			outFile << it.m_name << ","
//				<< it.m_age << ","
//				<< it.m_id << ","
//				<< it.m_score << endl;
//		}
//		outFile.close();
//		cout << "数据已经保存到文件中" << endl;
//	}
//
//	void viewFromFile() {
//		const string filename = "student_data.txt";
//		ifstream inFile(filename);
//		if (!inFile) {
//			cerr << "无法打开文件进行读取: " << filename << " (将创建新文件)" << endl;
//			return;
//		}
//
//		int count = 0;
//		string line;
//		while (getline(inFile, line)) {
//			stringstream ss(line);
//			string token;
//			student s;
//
//			// 解析每行数据
//			if (getline(ss, token, ',')) s.m_name = token;
//			if (getline(ss, token, ',')) s.m_age = stoi(token);
//			if (getline(ss, token, ',')) s.m_id = stoi(token);
//			if (getline(ss, token, ',')) s.m_score = stod(token);
//
//			stu.push_back({ s.m_name,s.m_age,s.m_id,s.m_score });
//			cout << "姓名：" << s.m_name
//				<< " 年龄：" << s.m_age
//				<< " 学号：" << s.m_id
//				<< " 分数：" << s.m_score << endl;
//			count++;
//		}
//		inFile.close();
//		cout << "总共查看了" << count << "条信息" << endl;
//		cout << "-----------------------------------" << endl;
//	}
//};
//
////重复id的处理
//bool checkId(studata& base, int id)
//{
//	for (auto& it : base.stu)
//	{
//		if (it.m_id == id)
//		{
//			return false;
//		}
//	}
//	return true;
//}
////添加id
//void addid(studata& base, int& id)
//{
//	cout << "请输入id：";
//	cin >> id;
//	while (!checkId(base, id))
//	{
//		cout << "id重复，请重新输入id：";
//		cin >> id;
//	}
//}
//
////增加
//void Addstu(studata& base)
//{
//	int sumstu;
//	cout << "请输入加入学生的数量：";
//	cin >> sumstu;
//
//	string name; int age; int id; double score;
//
//
//	for (int i = 0; i < sumstu; i++)
//	{
//		cout << "请输入姓名：";
//		cin >> name;
//
//		cout << "请输入年龄：";
//		cin >> age;
//
//		//添加id
//		addid(base, id);
//
//		cout << "请输入分数：";
//		cin >> score;
//
//		cout << endl;
//
//		base.stu.push_back({ name,age,id,score });
//
//	}
//	cout << "输入成功" << endl;
//
//}
//
////删除
//void deletemenu()
//{
//	cout << "*****1.按姓名删除*****" << endl;
//	cout << "*****2.按学号删除*****" << endl;
//	cout << "*****0.返回主菜单*****" << endl;
//}
//
//void Deletestu(studata& base)
//{
//	if (base.stu.empty())
//	{
//		cout << "没有数据元素，无法删除" << endl;
//	}
//
//	else
//	{
//		deletemenu();
//		int choice = -1;
//		cout << "请输入删除的方式：";
//		cin >> choice;
//		if (choice == 0)
//		{
//			return;
//		}
//		if (choice == 1)
//		{
//			cout << "请输入要删除学生姓名：";
//			string name;
//			cin >> name;
//
//			bool found = false;
//
//			for (auto it = base.stu.begin(); it != base.stu.end(); )
//			{
//				if (it->m_name == name)
//				{
//					it = base.stu.erase(it);
//					found = true;
//					cout << "删除成功" << endl;
//				}
//
//				else
//				{
//					++it;
//				}
//			}
//			if (!found)
//			{
//				cout << "查无此人" << endl;
//			}
//		}
//
//		else if (choice == 2)
//		{
//			cout << "请输入要删除学生的id：";
//			int id;
//			cin >> id;
//			bool found2 = false;
//			for (auto it2 = base.stu.begin(); it2 != base.stu.end(); )
//			{
//				if (it2->m_id == id)
//				{
//					it2 = base.stu.erase(it2);
//					found2 = true;
//					cout << "删除成功" << endl;
//					break;
//				}
//				else
//				{
//					++it2;
//				}
//
//			}
//			if (!found2)
//			{
//				cout << "没有这id的学生" << endl;
//			}
//		}
//
//		else
//		{
//			cout << "输入无效" << endl;
//		}
//	}
//
//}
//
////查
//void CheckStu(studata base)
//{
//	if (base.stu.empty())
//	{
//		cout << "*****当前数据为空*****" << endl;
//		return;
//	}
//
//	cout << "*****1.按姓名查找*****" << endl;
//	cout << "*****2.按学号查找*****" << endl;
//	cout << "*****0.返回主菜单*****" << endl;
//
//	int choice = -1;
//	cout << "请输入查找的方式：";
//	cin >> choice;
//
//	if (choice == 0) return;
//
//	if (choice == 1)
//	{
//		string name;
//		cout << "请输入姓名：";
//		cin >> name;
//
//		bool found = false;
//		auto it = base.stu.begin();
//		while (it != base.stu.end())
//		{
//			if (it->m_name == name)
//			{
//				found = true;
//				cout << "姓名：" << it->m_name
//					<< " 年龄：" << it->m_age
//					<< " 学号：" << it->m_id
//					<< " 成绩：" << it->m_score << endl;
//			}
//			++it;
//		}
//		if (!found)
//		{
//			cout << "查无此人" << endl;
//		}
//
//	}
//
//	else if (choice == 2)
//	{
//		int id;
//		cout << "请输入id:";
//		cin >> id;
//
//		bool found = false;
//		auto it = base.stu.begin();
//		while (it != base.stu.end())
//		{
//			if (it->m_id == id)
//			{
//				found = true;
//				cout << "姓名：" << it->m_name
//					<< " 年龄：" << it->m_age
//					<< " 学号：" << it->m_id
//					<< " 成绩：" << it->m_score << endl;
//				break;
//			}
//			else
//			{
//				++it;
//			}
//		}
//		if (!found)
//		{
//			cout << "查无此人" << endl;
//		}
//	}
//
//	else
//	{
//		cout << "输入无效" << endl;
//	}
//
//}
//
//
////改
//void Rebuild(studata& base)
//{
//	if (base.stu.empty())
//	{
//		cout << "当前元素为空,没有元素进行修改" << endl;
//		return;
//	}
//
//	/*string name;
//	cout << "请输入你要修改学生姓名：";
//	cin >> name;*/
//	//因为姓名有重复 所以用学号
//
//	string name = "abs"; int age = 0; int id = 0; double score = 0;
//
//	int Id = 0;
//	cout << "请输入你要修改学生的学号：";
//	cin >> Id;
//	bool found = false;
//
//	for (auto it = base.stu.begin(); it != base.stu.end();)
//	{
//		if (it->m_id == Id)
//		{
//			found = true;
//			cout << "请输入修改后的姓名：";
//			cin >> name;
//			cout << "请输入修改后的年龄：";
//			cin >> age;
//			cout << "请输入修改后的学号：";
//			cin >> id;
//			cout << "请输入修改后的分数：";
//			cin >> score;
//
//			it->m_name = name;
//			it->m_age = age;
//			it->m_id = id;
//			it->m_score = score;
//			break;
//		}
//
//		it++;
//	}
//	if (!found)
//	{
//		cout << "查无此人" << endl;
//	}
//
//}
//
////成绩降序
//bool Downcompare(const student& a, const student& b)
//{
//	return a.m_score > b.m_score;
//}
//void printStu(studata list);
//void downSort(studata& base)
//{
//	base.stu.sort(Downcompare);
//	cout << "*****降序排序：******" << endl;
//	printStu(base);
//
//}
//
////成绩升序
//bool upCompare(const student& a, const student& b)
//{
//	return a.m_score < b.m_score;
//}
//void printStu(studata list);
//void upSort(studata& base)
//{
//	base.stu.sort(upCompare);
//	cout << "*****升序排序：******" << endl;
//	printStu(base);
//}
//
//
//
////8.打印全部数据
//void printStu(studata list)
//{
//	if (list.stu.empty())
//	{
//		cout << "*****当前没有元素*****" << endl;
//	}
//	for (auto it = list.stu.begin(); it != list.stu.end(); it++)
//	{
//		cout << "姓名：" << it->m_name << " "
//			<< "年龄：" << it->m_age << " "
//			<< "学号：" << it->m_id << " "
//			<< "分数：" << it->m_score << endl;
//	}
//}
//
//// case 0 的选择 保存还是不保存
//void Protectnum(studata& L)
//{
//	if (L.stu.empty())
//	{
//		cout << "因为文件为空，所以直接退出程序" << endl;
//		return;
//	}
//
//	cout << "退出程序，是否要保存数据？（0是否 1是保存）:";
//	int sel = -1;
//	cin >> sel;
//	if (sel == 0)
//	{
//		system("pause");
//		return;
//	}
//	else if (sel == 1)
//	{
//		L.savetoFinle();
//		cout << "数据已保存到文件中" << endl;
//		return;
//	}
//	else
//	{
//		while (1)
//		{
//			cout << "输入无效，请重新输入：" << endl;
//			cin >> sel;
//			if (sel == 0 || sel == 1)
//			{
//				break;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//
//	studata L;
//	int choice = -1;
//	menu();
//	while (true)
//	{
//		cout << "你的选择：";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://加
//			Addstu(L);
//			break;
//		case 2://删
//			Deletestu(L);
//			break;
//		case 3://查
//			CheckStu(L);
//			break;
//		case 4://改
//			Rebuild(L);
//			break;
//		case 5://升序
//			upSort(L);
//			break;
//		case 6://降序
//			downSort(L);
//			break;
//		case 7://查全部人
//			printStu(L);
//			break;
//		case 8:
//			L.savetoFinle();
//			break;
//		case 9:
//			L.viewFromFile();
//			break;
//		case 0:
//			Protectnum(L);
//			return 0;
//			break;
//		default:
//			cout << "******输入错误*****" << endl;
//
//		}
//	}
//
//	system("pause");
//	return 0;
//}