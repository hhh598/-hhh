//���� û������û���
// ���гɼ�������
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<sstream>
//#include<list>//˫������
//
//void menu()
//{
//	cout << "------------------------------" << endl;
//	cout << "*****1.�������*****" << endl;
//	cout << "*****2.ɾ������*****" << endl;
//	cout << "*****3.����ĳ��*****" << endl;
//	cout << "*****4.�޸�����*****" << endl;
//	cout << "*****5.�ɼ�����*****" << endl;
//	cout << "*****6.�ɼ�����*****" << endl;
//	cout << "***7.ȫ��Ԫ��չʾ***" << endl;
//	cout << "*****8.���浽�ļ�*****" << endl;
//	cout << "****9.�鿴�ļ���Ϣ*****" << endl;
//	cout << "*****0.�˳�����*****" << endl;
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
//			cerr << "�޷����ļ�" << endl;
//		}
//		for (const auto& it : stu)
//		{
//			outFile << it.m_name << ","
//				<< it.m_age << ","
//				<< it.m_id << ","
//				<< it.m_score << endl;
//		}
//		outFile.close();
//		cout << "�����Ѿ����浽�ļ���" << endl;
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
//			if (getline(ss, token, ',')) s.m_score = stod(token);
//
//			stu.push_back({ s.m_name,s.m_age,s.m_id,s.m_score });
//			cout << "������" << s.m_name
//				<< " ���䣺" << s.m_age
//				<< " ѧ�ţ�" << s.m_id
//				<< " ������" << s.m_score << endl;
//			count++;
//		}
//		inFile.close();
//		cout << "�ܹ��鿴��" << count << "����Ϣ" << endl;
//		cout << "-----------------------------------" << endl;
//	}
//};
//
////�ظ�id�Ĵ���
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
////���id
//void addid(studata& base, int& id)
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
////����
//void Addstu(studata& base)
//{
//	int sumstu;
//	cout << "���������ѧ����������";
//	cin >> sumstu;
//
//	string name; int age; int id; double score;
//
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
//		addid(base, id);
//
//		cout << "�����������";
//		cin >> score;
//
//		cout << endl;
//
//		base.stu.push_back({ name,age,id,score });
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
//void Deletestu(studata& base)
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
//		cout << "������ɾ���ķ�ʽ��";
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
//					it = base.stu.erase(it);
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
//					it2 = base.stu.erase(it2);
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
//					<< " ���䣺" << it->m_age
//					<< " ѧ�ţ�" << it->m_id
//					<< " �ɼ���" << it->m_score << endl;
//			}
//			++it;
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
//					<< " ���䣺" << it->m_age
//					<< " ѧ�ţ�" << it->m_id
//					<< " �ɼ���" << it->m_score << endl;
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
//void Rebuild(studata& base)
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
//	string name = "abs"; int age = 0; int id = 0; double score = 0;
//
//	int Id = 0;
//	cout << "��������Ҫ�޸�ѧ����ѧ�ţ�";
//	cin >> Id;
//	bool found = false;
//
//	for (auto it = base.stu.begin(); it != base.stu.end();)
//	{
//		if (it->m_id == Id)
//		{
//			found = true;
//			cout << "�������޸ĺ��������";
//			cin >> name;
//			cout << "�������޸ĺ�����䣺";
//			cin >> age;
//			cout << "�������޸ĺ��ѧ�ţ�";
//			cin >> id;
//			cout << "�������޸ĺ�ķ�����";
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
//		cout << "���޴���" << endl;
//	}
//
//}
//
////�ɼ�����
//bool Downcompare(const student& a, const student& b)
//{
//	return a.m_score > b.m_score;
//}
//void printStu(studata list);
//void downSort(studata& base)
//{
//	base.stu.sort(Downcompare);
//	cout << "*****��������******" << endl;
//	printStu(base);
//
//}
//
////�ɼ�����
//bool upCompare(const student& a, const student& b)
//{
//	return a.m_score < b.m_score;
//}
//void printStu(studata list);
//void upSort(studata& base)
//{
//	base.stu.sort(upCompare);
//	cout << "*****��������******" << endl;
//	printStu(base);
//}
//
//
//
////8.��ӡȫ������
//void printStu(studata list)
//{
//	if (list.stu.empty())
//	{
//		cout << "*****��ǰû��Ԫ��*****" << endl;
//	}
//	for (auto it = list.stu.begin(); it != list.stu.end(); it++)
//	{
//		cout << "������" << it->m_name << " "
//			<< "���䣺" << it->m_age << " "
//			<< "ѧ�ţ�" << it->m_id << " "
//			<< "������" << it->m_score << endl;
//	}
//}
//
//// case 0 ��ѡ�� ���滹�ǲ�����
//void Protectnum(studata& L)
//{
//	if (L.stu.empty())
//	{
//		cout << "��Ϊ�ļ�Ϊ�գ�����ֱ���˳�����" << endl;
//		return;
//	}
//
//	cout << "�˳������Ƿ�Ҫ�������ݣ���0�Ƿ� 1�Ǳ��棩:";
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
//	int choice = -1;
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
//		case 5://����
//			upSort(L);
//			break;
//		case 6://����
//			downSort(L);
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