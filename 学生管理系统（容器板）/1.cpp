//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<sstream>
//#include<list>//˫������
//#include<algorithm>
//
//void menu()
//{
//	cout << "------------------------------" << endl;
//	cout << "*****1.�������*****" << endl;
//	cout << "*****2.ɾ������*****" << endl;
//	cout << "*****3.����ĳ��*****" << endl;
//	cout << "*****4.�޸�����*****" << endl;
//	cout << "*****5.�ܳɼ�����*****" << endl;
//	cout << "*****6.ƽ���ɼ�����*****" << endl;
//	cout << "***7.ȫ��Ԫ��չʾ***" << endl;
//	cout << "*****8.���浽�ļ�*****" << endl;
//	cout << "****9.�鿴�ļ���Ϣ*****" << endl;
//	cout << "*****0.�˳�����*****" << endl;
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
//bool isSave = false;//��Ϊ�����δ浵0 �� 8 ��0����Ϊ�û��������Ǵ浵
//
//class studata
//{
//public:
//	list<student>stu;
//	
//	// ���ܱ��棨�״θ��ǣ�����׷�ӣ�
//	void savetoFinle() {
//		isSave = true;
//		const string finename = "student_data.txt";
//
//		// �ж��ļ��Ƿ�Ϊ��
//		bool isFileEmpty = false;
//		ifstream checkFile(finename);
//		if (checkFile.is_open()) {
//			// �ļ����ڣ�����Ƿ�Ϊ��
//			isFileEmpty = checkFile.peek() == ifstream::traits_type::eof();
//			checkFile.close();
//		}
//		else {
//			// �ļ������ڣ��״δ���
//			isFileEmpty = true;
//		}
//
//		// �״α�����ļ�Ϊ��ʱ���ǣ�����׷��
//		ofstream outFile(finename, isFileEmpty ? ios::trunc : ios::app);
//		if (!outFile) {
//			cerr << "�޷����ļ�" << endl;
//			return;
//		}
//
//		if (isFileEmpty) {
//			// �״α��棬д��ȫ������
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
//			cout << "�״α��棬�Ѹ����ļ�����" << endl;
//		}
//		else {
//			// ���״α��棬��׷����������
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
//			cout << "������׷�ӵ��ļ�" << endl;
//		}
//
//		outFile.close();
//	}
//
//	void viewFromFile() {
//		const string filename = "student_data.txt";
//		ifstream inFile(filename);
//		if (!inFile) {
//			cerr << "�޷����ļ����ж�ȡ: " << filename << " (���������ļ�)" << endl;
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
//			// ����ÿ������
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
//			cout << "������" << s.m_name
//				<< " ���䣺" << s.m_age
//				<< " ѧ�ţ�" << s.m_id
//				<< " �����������" << s.m_score.sc_Computer
//				<< " Ӣ�������" << s.m_score.sc_Eng
//				<< " ��ѧ������" << s.m_score.sc_Math
//				<< " �ܷ�����" << s.m_score.sum
//				<< " ƽ��������" << s.m_score.avg
//				<< endl;
//			count++;
//		}
//		inFile.close();
//		cout << "�ܹ��鿴��" << count << "����Ϣ" << endl;
//		cout << "-----------------------------------" << endl;
//	}
//
//
//};
//
//void printStu(studata& list);
//
//
////�ظ�id�Ĵ���
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
//	// ����ļ��е�����
//	const string filename = "student_data.txt";
//	ifstream inFile(filename);
//	if (!inFile) {
//		return true; // �ļ������ڣ���Ϊ�޳�ͻ
//	}
//
//	string line;
//	while (getline(inFile, line)) {
//		stringstream ss(line);
//		string token;
//
//		// ��ȡ�ļ��е�ID
//		for (int i = 0; i < 3 && getline(ss, token, ','); i++) {
//			if (i == 2) { // �������ֶ���ID
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
////���id
//void addid(studata&base,int &id)
//{
//	cout << "������id��";
//	cin >> id;
//	while (!checkId(base, id))
//	{
//		cout << "id�ظ�������������id��";
//		cin >> id;
//	}
//}
//
////��ӷ���
//Score addScore( )
//{
//	double Com, Eng, Math;
//	cout << "��������������÷֣�";
//	cin >> Com;
//	cout << "������Ӣ�﷽��÷֣�";
//	cin >> Eng;
//	cout << "��������ѧ����÷֣�";
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
////����
//void Addstu(studata&base)
//{
//	int sumstu;
//	cout << "���������ѧ����������";
//	cin >> sumstu;
//
//	string name; int age; int id;
//	double Com = 0, Eng = 0, Math = 0;
//
//	for (int i = 0; i < sumstu; i++)
//	{
//		cout << "������������";
//		cin >> name;
//
//		cout << "���������䣺";
//		cin >> age;
//
//		//���id
//		addid(base,id);
//
//		//��ӷ���
//		Score sc=addScore();
//
//		cout << endl;
//		
//		base.stu.push_back({ name,age,id,sc });
//
//	}
//	cout << "����ɹ�" << endl;
//	
//}
//
////ɾ��
//void deletemenu()
//{
//	cout << "*****1.������ɾ��*****" << endl;
//	cout << "*****2.��ѧ��ɾ��*****" << endl;
//	cout << "*****0.�������˵�*****" << endl;
//}
//
//void Deletestu(studata&base)
//{
//	if (base.stu.empty())
//	{
//		cout << "û������Ԫ�أ��޷�ɾ��" << endl;
//	}
//
//	else
//	{
//		deletemenu();
//		int choice = -1;
//		cout << "������ɾ���ķ�ʽ��" ;
//		cin >> choice;
//		if (choice == 0)
//		{
//			return;
//		}
//		if (choice == 1)
//		{
//			cout << "������Ҫɾ��ѧ��������";
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
//					cout << "ɾ���ɹ�" << endl;
//				}
//				
//				else
//				{
//					++it;
//				}
//			}
//			if (!found)
//			{
//				cout << "���޴���" << endl;
//			}
//		}
//
//		else if (choice == 2)
//		{
//			cout << "������Ҫɾ��ѧ����id��";
//			int id;
//			cin >> id;
//			bool found2 = false;
//			for (auto it2 = base.stu.begin(); it2 != base.stu.end(); )
//			{
//				if (it2->m_id == id)
//				{
//					it2=base.stu.erase(it2);
//					found2 = true;
//					cout << "ɾ���ɹ�" << endl;
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
//				cout << "û����id��ѧ��" << endl;
//			}
//		}
//
//		else
//		{
//			cout << "������Ч" << endl;
//		}
//	}
//	
//}
//
////��
//void CheckStu(studata base)
//{
//	if (base.stu.empty())
//	{
//		cout << "*****��ǰ����Ϊ��*****" << endl;
//		return;
//	}
//
//	cout << "*****1.����������*****" << endl;
//	cout << "*****2.��ѧ�Ų���*****" << endl;
//	cout << "*****0.�������˵�*****" << endl;
//
//	int choice = -1;
//	cout << "��������ҵķ�ʽ��";
//	cin >> choice;
//
//	if (choice == 0) return;
//
//	if (choice == 1)
//	{
//		string name;
//		cout << "������������";
//		cin >> name;
//		
//		bool found = false;
//		auto it = base.stu.begin();
//		while (it != base.stu.end())
//		{
//			if (it->m_name == name)
//			{
//				found = true;
//				cout << "������" << it->m_name
//					<< "  ���䣺" << it->m_age
//					<< "  ѧ�ţ�" << it->m_id
//					<< "  ������ɼ���" << it->m_score.sc_Computer
//					<< "  Ӣ��ɼ���" << it->m_score.sc_Eng
//					<< "  ��ѧ�ɼ���" << it->m_score.sc_Math
//					<< endl;
//			}
//				++it;
//		}
//		if (!found)
//		{
//			cout << "���޴���" << endl;
//		}
//
//	}
//
//	else if (choice == 2)
//	{
//		int id;
//		cout << "������id:";
//		cin >> id;
//
//		bool found = false;
//		auto it = base.stu.begin();
//		while (it != base.stu.end())
//		{
//			if (it->m_id == id)
//			{
//				found = true;
//				cout << "������" << it->m_name
//					<< "  ���䣺" << it->m_age
//					<< "  ѧ�ţ�" << it->m_id
//					<< "  ������ɼ���" << it->m_score.sc_Computer
//					<< "  Ӣ��ɼ���" << it->m_score.sc_Eng
//					<< "  ��ѧ�ɼ���" << it->m_score.sc_Math
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
//			cout << "���޴���" << endl;
//		}
//	}
//
//	else
//	{
//		cout << "������Ч" << endl;
//	}
//
//}
//
//
////��
//void Rebuild(studata&base)
//{
//	if (base.stu.empty())
//	{
//		cout << "��ǰԪ��Ϊ��,û��Ԫ�ؽ����޸�" << endl;
//		return;
//	}
//
//	/*string name;
//	cout << "��������Ҫ�޸�ѧ��������";
//	cin >> name;*/
//	//��Ϊ�������ظ� ������ѧ��
//
//	string name = "abs"; int age = 0; int id = 0; 
//	double Comscore = 0; double Engscore = 0; double Mathscore = 0;
//	
//	int Id=0;
//	cout << "��������Ҫ�޸�ѧ����ѧ�ţ�";
//	cin >> Id;
//	bool found = false;
//
//	for (auto it=base.stu.begin();it!=base.stu.end();)
//	{
//		if (it->m_id==Id)
//		{
//			found = true;
//			cout << "�������޸ĺ��������";
//			cin >> name;
//			cout << "�������޸ĺ�����䣺";
//			cin >> age;
//			cout << "�������޸ĺ��ѧ�ţ�";
//			cin >> id;
//			cout << "�������޸ĺ�ļ�����ĳɼ���";
//			cin >> Comscore;
//			cout << "�������޸ĺ�Ӣ��ĳɼ���";
//			cin >> Engscore;
//			cout << "�������޸ĺ���ѧ�ĳɼ���";
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
//		cout << "���޴���" << endl;
//	}
//
//}
//
//
////�ܳɼ�����
//bool DowncompareSum(const student&a,const student&b)
//{
//	return a.m_score.sum > b.m_score.sum;
//}
////�ܳɼ�����
//bool upCompareSum(const student& a, const student& b)
//{
//	return a.m_score .sum< b.m_score.sum;
//}
//
//void Sumdown(studata &base)
//{
//	base.stu.sort(DowncompareSum);
//	cout << "*****�ܳɼ�����******" << endl;
//	printStu(base);
//
//}
//
//void Sumup(studata&base)
//{
//	base.stu.sort(upCompareSum);
//	cout << "*****�ܳɼ�����******" << endl;
//	printStu(base);
//}
//
//
////�ܳɼ�����
//void SumSort(studata&L)
//{
//	if (L.stu.empty())
//	{
//		cout << "��ǰû������" << endl;
//		return;
//	}
//	int choice = -1;
//	cout << "------------------" << endl;
//	cout << "1.�ܳɼ�����" << endl;
//	cout << "2.�ܳɼ�����" << endl;
//	cout << "0.�������˵�" << endl;
//	cout << "------------------" << endl;
//	
//	
//	while (1)
//	{
//		cout << "����������ķ�ʽ��";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://����
//			Sumup(L);
//			break;
//		case 2:
//			//����
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
////ƽ���ɼ�����
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
//	cout << "*****ƽ���ɼ�����******" << endl;
//	printStu(base);
//
//}
//
//void Avgup(studata& base)
//{
//	base.stu.sort(upCompareAvg);
//	cout << "*****ƽ���ɼ�����******" << endl;
//	printStu(base);
//}
//
//void AvgSort(studata& L)
//{
//	if (L.stu.empty())
//	{
//		cout << "��ǰû������" << endl;
//		return;
//	}
//	int choice = -1;
//	cout << "------------------" << endl;
//	cout << "1.ƽ���ɼ�����" << endl;
//	cout << "2.ƽ���ɼ�����" << endl;
//	cout << "0.�������˵�" << endl;
//	cout << "------------------" << endl;
//
//
//	while (1)
//	{
//		cout << "����������ķ�ʽ��";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://����
//			Avgup(L);
//			break;
//		case 2:
//			//����
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
////8.��ӡȫ������
//void printStu(studata &list)
//{
//	if (list.stu.empty())
//	{
//		cout << "*****��ǰû��Ԫ��*****" << endl;
//	}
//	for ( auto it = list.stu.begin(); it != list.stu.end(); it++)
//	{
//		
//		cout << "������" << it->m_name << " "
//			<< " ���䣺" << it->m_age << " "
//			<< " ѧ�ţ�" << it->m_id << " "
//			<< " ������ɼ���" << it->m_score.sc_Computer
//			<< " Ӣ��ɼ���" << it->m_score.sc_Eng
//			<< " ��ѧ���ɼ���" << it->m_score.sc_Math
//			<< " �ܳɼ���" << it->m_score.sum
//			<< " ƽ���ɼ���" << it->m_score.avg
//			<< endl;
//	}
//}
//
//// case 0 ��ѡ�� ���滹�ǲ�����
//void Protectnum(studata&L)
//{
//	if (L.stu.empty())
//	{
//		cout << "��Ϊ�ļ�Ϊ�գ�����ֱ���˳�����" << endl;
//		return;
//	}
//	if (!isSave)
//	{
//		cout << "�Ѿ��浵����ֱ���˳�����" << endl;
//		return;
//	}
//	
//
//	cout << "�˳������Ƿ�Ҫ�������ݣ���0�Ƿ� 1�Ǳ��棩:";
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
//		cout << "�����ѱ��浽�ļ���" << endl;
//		return;
//	}
//	else
//	{
//		while (1)
//		{
//			cout << "������Ч�����������룺" << endl;
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
//		cout << "���ѡ��";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1://��
//			Addstu(L);
//			break;
//		case 2://ɾ
//			Deletestu(L);
//			break;
//		case 3://��
//			CheckStu(L);
//			break;
//		case 4://��
//			Rebuild(L);
//			break;
//		case 5://�ܳɼ�����
//			SumSort(L);
//			break;
//		case 6://ƽ���ɼ�����
//			AvgSort(L);
//			break;
//		case 7://��ȫ����
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
//			cout << "******�������*****" << endl;
//
//		}
//	}
//
//	system("pause");
//	return 0;
//}