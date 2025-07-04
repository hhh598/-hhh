//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<sstream>
//#include<list>//双向链表
//#include<algorithm>
//
//void menu()
//{
//	cout << "------------------------------" << endl;
//	cout << "*****1.添加人数*****" << endl;
//	cout << "*****2.删除人数*****" << endl;
//	cout << "*****3.查找某人*****" << endl;
//	cout << "*****4.修改数据*****" << endl;
//	cout << "*****5.总成绩排序*****" << endl;
//	cout << "*****6.平均成绩排序*****" << endl;
//	cout << "***7.全部元素展示***" << endl;
//	cout << "*****8.保存到文件*****" << endl;
//	cout << "****9.查看文件信息*****" << endl;
//	cout << "*****0.退出程序*****" << endl;
//	cout << "------------------------------" << endl;
//}
//
//
//
//class Score
//{
//public:
//	double sc_Computer;
//	double sc_Eng;
//	double sc_Math;
//	double sum ;
//	double avg;
//
//	void calculate()
//	{
//		sum = sc_Computer + sc_Eng + sc_Math;
//		avg = sum / 3.0;
//	}
//};
//
//class student
//{
//public:
//	string m_name;
//	int m_age;
//	int m_id;
//	Score m_score;
//};
//
//bool isSave = false;//因为有两次存档0 和 8 ，0是因为用户可能忘记存档
//
//class studata
//{
//public:
//	list<student>stu;
//	
//	// 智能保存（首次覆盖，后续追加）
//	void savetoFinle() {
//		isSave = true;
//		const string finename = "student_data.txt";
//
//		// 判断文件是否为空
//		bool isFileEmpty = false;
//		ifstream checkFile(finename);
//		if (checkFile.is_open()) {
//			// 文件存在，检查是否为空
//			isFileEmpty = checkFile.peek() == ifstream::traits_type::eof();
//			checkFile.close();
//		}
//		else {
//			// 文件不存在，首次创建
//			isFileEmpty = true;
//		}
//
//		// 首次保存或文件为空时覆盖，否则追加
//		ofstream outFile(finename, isFileEmpty ? ios::trunc : ios::app);
//		if (!outFile) {
//			cerr << "无法打开文件" << endl;
//			return;
//		}
//
//		if (isFileEmpty) {
//			// 首次保存，写入全部数据
//			for (const auto& it : stu) {
//				outFile << it.m_name << ","
//					<< it.m_age << ","
//					<< it.m_id << ","
//					<< it.m_score.sc_Computer << ","
//					<< it.m_score.sc_Eng << ","
//					<< it.m_score.sc_Math << ","
//					<< it.m_score.sum << ","
//					<< it.m_score.avg << endl;
//			}
//			cout << "首次保存，已覆盖文件内容" << endl;
//		}
//		else {
//			// 非首次保存，仅追加最新数据
//			if (!stu.empty()) {
//				const auto& lastStudent = stu.back();
//				outFile << lastStudent.m_name << ","
//					<< lastStudent.m_age << ","
//					<< lastStudent.m_id << ","
//					<< lastStudent.m_score.sc_Computer << ","
//					<< lastStudent.m_score.sc_Eng << ","
//					<< lastStudent.m_score.sc_Math << ","
//					<< lastStudent.m_score.sum << ","
//					<< lastStudent.m_score.avg << endl;
//			}
//			cout << "数据已追加到文件" << endl;
//		}
//
//		outFile.close();
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
//			if (getline(ss, token, ',')) s.m_score.sc_Computer = stod(token);
//			if (getline(ss, token, ',')) s.m_score.sc_Eng = stod(token);
//			if (getline(ss, token, ',')) s.m_score.sc_Math = stod(token);
//			if (getline(ss, token, ',')) s.m_score.sum = stod(token);
//			if (getline(ss, token, ',')) s.m_score.avg = stod(token);
//
//			
//			cout << "姓名：" << s.m_name
//				<< " 年龄：" << s.m_age
//				<< " 学号：" << s.m_id
//				<< " 计算机分数：" << s.m_score.sc_Computer
//				<< " 英语分数：" << s.m_score.sc_Eng
//				<< " 数学分数：" << s.m_score.sc_Math
//				<< " 总分数：" << s.m_score.sum
//				<< " 平均分数：" << s.m_score.avg
//				<< endl;
//			count++;
//		}
//		inFile.close();
//		cout << "总共查看了" << count << "条信息" << endl;
//		cout << "-----------------------------------" << endl;
//	}
//
//
//};
//
//void printStu(studata& list);
//
//
////重复id的处理
//bool checkId(studata&base,int id)
//{
//	for (auto& it : base.stu)
//	{
//		if (it.m_id == id)
//		{
//			return false;
//		}
//	}
//	
//	// 检查文件中的数据
//	const string filename = "student_data.txt";
//	ifstream inFile(filename);
//	if (!inFile) {
//		return true; // 文件不存在，视为无冲突
//	}
//
//	string line;
//	while (getline(inFile, line)) {
//		stringstream ss(line);
//		string token;
//
//		// 提取文件中的ID
//		for (int i = 0; i < 3 && getline(ss, token, ','); i++) {
//			if (i == 2) { // 第三个字段是ID
//				if (stoi(token) == id) {
//					inFile.close();
//					return false;
//				}
//			}
//		}
//	}
//	inFile.close();
//	return true;
//}
////添加id
//void addid(studata&base,int &id)
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
////添加分数
//Score addScore( )
//{
//	double Com, Eng, Math;
//	cout << "请输入计算机方面得分：";
//	cin >> Com;
//	cout << "请输入英语方面得分：";
//	cin >> Eng;
//	cout << "请输入数学方面得分：";
//	cin >> Math;
//
//	Score sc;
//	sc.sc_Computer = Com;
//	sc.sc_Eng = Eng;
//	sc.sc_Math = Math;
//	sc.calculate();
//	return sc;
//}
//
////增加
//void Addstu(studata&base)
//{
//	int sumstu;
//	cout << "请输入加入学生的数量：";
//	cin >> sumstu;
//
//	string name; int age; int id;
//	double Com = 0, Eng = 0, Math = 0;
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
//		addid(base,id);
//
//		//添加分数
//		Score sc=addScore();
//
//		cout << endl;
//		
//		base.stu.push_back({ name,age,id,sc });
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
//void Deletestu(studata&base)
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
//		cout << "请输入删除的方式：" ;
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
//					it=base.stu.erase(it);
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
//					it2=base.stu.erase(it2);
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
//					<< "  年龄：" << it->m_age
//					<< "  学号：" << it->m_id
//					<< "  计算机成绩：" << it->m_score.sc_Computer
//					<< "  英语成绩：" << it->m_score.sc_Eng
//					<< "  数学成绩：" << it->m_score.sc_Math
//					<< endl;
//			}
//				++it;
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
//					<< "  年龄：" << it->m_age
//					<< "  学号：" << it->m_id
//					<< "  计算机成绩：" << it->m_score.sc_Computer
//					<< "  英语成绩：" << it->m_score.sc_Eng
//					<< "  数学成绩：" << it->m_score.sc_Math
//					<< endl;
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
//void Rebuild(studata&base)
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
//	string name = "abs"; int age = 0; int id = 0; 
//	double Comscore = 0; double Engscore = 0; double Mathscore = 0;
//	
//	int Id=0;
//	cout << "请输入你要修改学生的学号：";
//	cin >> Id;
//	bool found = false;
//
//	for (auto it=base.stu.begin();it!=base.stu.end();)
//	{
//		if (it->m_id==Id)
//		{
//			found = true;
//			cout << "请输入修改后的姓名：";
//			cin >> name;
//			cout << "请输入修改后的年龄：";
//			cin >> age;
//			cout << "请输入修改后的学号：";
//			cin >> id;
//			cout << "请输入修改后的计算机的成绩：";
//			cin >> Comscore;
//			cout << "请输入修改后英语的成绩：";
//			cin >> Engscore;
//			cout << "请输入修改后数学的成绩：";
//			cin >> Mathscore;
//
//			it->m_name = name;
//			it->m_age = age;
//			it->m_id = id;
//			it->m_score.sc_Computer = Comscore;
//			it->m_score.sc_Eng = Engscore;
//			it->m_score.sc_Math = Mathscore;
//			it->m_score.sum = (Comscore + Engscore + Mathscore);
//			it->m_score.avg = (Comscore + Engscore + Mathscore) / 3.0;
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
//
////总成绩降序
//bool DowncompareSum(const student&a,const student&b)
//{
//	return a.m_score.sum > b.m_score.sum;
//}
////总成绩升序
//bool upCompareSum(const student& a, const student& b)
//{
//	return a.m_score .sum< b.m_score.sum;
//}
//
//void Sumdown(studata &base)
//{
//	base.stu.sort(DowncompareSum);
//	cout << "*****总成绩降序：******" << endl;
//	printStu(base);
//
//}
//
//void Sumup(studata&base)
//{
//	base.stu.sort(upCompareSum);
//	cout << "*****总成绩升序：******" << endl;
//	printStu(base);
//}
//
//
////总成绩排序
//void SumSort(studata&L)
//{
//	if (L.stu.empty())
//	{
//		cout << "当前没有数据" << endl;
//		return;
//	}
//	int choice = -1;
//	cout << "------------------" << endl;
//	cout << "1.总成绩升序" << endl;
//	cout << "2.总成绩降序" << endl;
//	cout << "0.返回主菜单" << endl;
//	cout << "------------------" << endl;
//	
//	
//	while (1)
//	{
//		cout << "请输入排序的方式：";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://升序
//			Sumup(L);
//			break;
//		case 2:
//			//降序
//			Sumdown(L);
//			break;
//		case 0:
//			return;
//			break;
//
//		}
//	}
//}
//
//
//
////平均成绩排序
//bool DowncompareAvg(const student& a, const student& b)
//{
//	return a.m_score.avg > b.m_score.avg;
//}
//bool upCompareAvg(const student& a, const student& b)
//{
//	return a.m_score.avg < b.m_score.avg;
//}
//
//void Avgdown(studata& base)
//{
//	base.stu.sort(DowncompareAvg);
//	cout << "*****平均成绩降序：******" << endl;
//	printStu(base);
//
//}
//
//void Avgup(studata& base)
//{
//	base.stu.sort(upCompareAvg);
//	cout << "*****平均成绩升序：******" << endl;
//	printStu(base);
//}
//
//void AvgSort(studata& L)
//{
//	if (L.stu.empty())
//	{
//		cout << "当前没有数据" << endl;
//		return;
//	}
//	int choice = -1;
//	cout << "------------------" << endl;
//	cout << "1.平均成绩升序" << endl;
//	cout << "2.平均成绩降序" << endl;
//	cout << "0.返回主菜单" << endl;
//	cout << "------------------" << endl;
//
//
//	while (1)
//	{
//		cout << "请输入排序的方式：";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://升序
//			Avgup(L);
//			break;
//		case 2:
//			//降序
//			Avgdown(L);
//			break;
//		case 0:
//			return;
//			break;
//
//		}
//	}
//}
//
////8.打印全部数据
//void printStu(studata &list)
//{
//	if (list.stu.empty())
//	{
//		cout << "*****当前没有元素*****" << endl;
//	}
//	for ( auto it = list.stu.begin(); it != list.stu.end(); it++)
//	{
//		
//		cout << "姓名：" << it->m_name << " "
//			<< " 年龄：" << it->m_age << " "
//			<< " 学号：" << it->m_id << " "
//			<< " 计算机成绩：" << it->m_score.sc_Computer
//			<< " 英语成绩：" << it->m_score.sc_Eng
//			<< " 数学机成绩：" << it->m_score.sc_Math
//			<< " 总成绩：" << it->m_score.sum
//			<< " 平均成绩：" << it->m_score.avg
//			<< endl;
//	}
//}
//
//// case 0 的选择 保存还是不保存
//void Protectnum(studata&L)
//{
//	if (L.stu.empty())
//	{
//		cout << "因为文件为空，所以直接退出程序" << endl;
//		return;
//	}
//	if (!isSave)
//	{
//		cout << "已经存档过，直接退出程序" << endl;
//		return;
//	}
//	
//
//	cout << "退出程序，是否要保存数据？（0是否 1是保存）:";
//	int sel=-1;
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
//	int choice=-1;
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
//		case 5://总成绩排序
//			SumSort(L);
//			break;
//		case 6://平均成绩排序
//			AvgSort(L);
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