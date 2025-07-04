#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ================= �û�����ϵͳ =================
class Users {
public:
    string password;
    string Username;
    Users(string pas, string Uname) : password(pas), Username(Uname) {};
};

class UsersManger {
public:
    vector<Users> v;
    const string filename = "users.txt";

    // ���ļ������û�����
    void m_loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            string username, password;
            while (file >> username >> password) {
                v.push_back(Users(password, username));
            }
            file.close();
        }
    }

    // �����û����ݵ��ļ�
    void m_saveToFile(bool overwrite = false) {
        ofstream file;
        if (overwrite) {
            file.open(filename, ios::trunc); // ����ģʽ
        }
        else {
            file.open(filename, ios::app);   // ׷��ģʽ
        }

        if (file.is_open()) {
            for (const auto& user : v) {
                file << user.Username << " " << user.password << endl;
            }
            file.close();
        }
    }

    // �鿴�����û�
    void displayAllUsers() {
        if (v.empty()) {
            cout << "����ע���û�" << endl;
            return;
        }
        cout << "��ǰע���û��б�" << endl;
        for (size_t i = 0; i < v.size(); ++i) {
            cout << i + 1 << ". " << v[i].Username << endl;
        }
    }
};

// �û�����˵�
void mangermenu() {
    cout << "============ �û�����ϵͳ ============" << endl;
    cout << "*****1.ע��*****" << endl;
    cout << "*****2.��¼*****" << endl;
    cout << "---3.�鿴��ǰ�����û�---" << endl;
    cout << "*****0.�˳�*****" << endl;
    cout << "=====================================" << endl;
}

// �û�ע��
void Enroll(UsersManger& manager) {
    string username, password;
    cout << "�������û�����";
    cin >> username;

    // ����û����Ƿ��Ѵ���
    for (const auto& user : manager.v) {
        if (user.Username == username) {
            cout << "���û����ѱ�ע�ᣬ��ѡ�������û���" << endl;
            return;
        }
    }

    cout << "���������룺";
    cin >> password;

    manager.v.push_back(Users(password, username));
    manager.m_saveToFile(true); // ���������û�
    cout << "ע��ɹ���" << endl;
}

// �û���¼
bool Login(UsersManger& manager) {
    if (manager.v.empty()) {
        cout << "��ǰû��ע���û�" << endl;
        return false;
    }

    string username, password;
    cout << "�������û�����";
    cin >> username;
    cout << "���������룺";
    cin >> password;

    for (const auto& user : manager.v) {
        if (user.Username == username && user.password == password) {
            cout << "��¼�ɹ�����ӭʹ��ѧ������ϵͳ" << endl;
            return true;
        }
    }

    cout << "�û������������" << endl;
    return false;
}

// ================= ѧ������ϵͳ =================
class Score {
public:
    double sc_Computer;
    double sc_Eng;
    double sc_Math;
    double sum;
    double avg;

    void calculate() {
        sum = sc_Computer + sc_Eng + sc_Math;
        avg = sum / 3.0;
    }
};

class Student {
public:
    string m_name;
    int m_age;
    int m_id;
    Score m_score;
};

class Studata {
public:
    list<Student> stu;
    const string filename = "student_data.txt";

    // ���ļ���������
    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) return;

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            Student s;

            getline(ss, token, ','); s.m_name = token;
            getline(ss, token, ','); s.m_age = stoi(token);
            getline(ss, token, ','); s.m_id = stoi(token);
            getline(ss, token, ','); s.m_score.sc_Computer = stod(token);
            getline(ss, token, ','); s.m_score.sc_Eng = stod(token);
            getline(ss, token, ','); s.m_score.sc_Math = stod(token);
            getline(ss, token, ','); s.m_score.sum = stod(token);
            getline(ss, token, ','); s.m_score.avg = stod(token);

            stu.push_back(s);
        }
        inFile.close();
        cout << "�Ѽ��� " << stu.size() << " ��ѧ����¼" << endl;
    }

    // �������ݵ��ļ�
    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "�޷����ļ����б���" << endl;
            return;
        }

        for (const auto& s : stu) {
            outFile << s.m_name << ","
                << s.m_age << ","
                << s.m_id << ","
                << s.m_score.sc_Computer << ","
                << s.m_score.sc_Eng << ","
                << s.m_score.sc_Math << ","
                << s.m_score.sum << ","
                << s.m_score.avg << endl;
        }
        outFile.close();
        cout << "�����ѱ��� (" << stu.size() << " ����¼)" << endl;
    }

    // �鿴�ļ�����
    void viewFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "�޷����ļ�" << endl;
            return;
        }

        int count = 0;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            Student s;

            getline(ss, token, ','); s.m_name = token;
            getline(ss, token, ','); s.m_age = stoi(token);
            getline(ss, token, ','); s.m_id = stoi(token);
            getline(ss, token, ','); s.m_score.sc_Computer = stod(token);
            getline(ss, token, ','); s.m_score.sc_Eng = stod(token);
            getline(ss, token, ','); s.m_score.sc_Math = stod(token);
            getline(ss, token, ','); s.m_score.sum = stod(token);
            getline(ss, token, ','); s.m_score.avg = stod(token);

            cout << "������" << s.m_name
                << " ���䣺" << s.m_age
                << " ѧ�ţ�" << s.m_id
                << " �������" << s.m_score.sc_Computer
                << " Ӣ�" << s.m_score.sc_Eng
                << " ��ѧ��" << s.m_score.sc_Math
                << " �ܷ֣�" << s.m_score.sum
                << " ƽ���֣�" << s.m_score.avg << endl;
            count++;
        }
        inFile.close();
        cout << "���鿴 " << count << " ����¼" << endl;
    }
};

// ϵͳ�˵�
void menu() {
    cout << "\n============ ѧ������ϵͳ ============" << endl;
    cout << "*****1.���ѧ��*****" << endl;
    cout << "*****2.ɾ��ѧ��*****" << endl;
    cout << "*****3.����ѧ��*****" << endl;
    cout << "*****4.�޸�����*****" << endl;
    cout << "*****5.�ܳɼ�����*****" << endl;
    cout << "*****6.ƽ���ɼ�����*****" << endl;
    cout << "*****7.ȫ��ѧ��չʾ*****" << endl;
    cout << "*****8.���浽�ļ�*****" << endl;
    cout << "*****9.�鿴�ļ���Ϣ*****" << endl;
    cout << "*****0.�˳�����*****" << endl;
    cout << "=====================================" << endl;
}

// ���ID�Ƿ��ظ�
bool checkId(Studata& base, int id) {
    for (const auto& s : base.stu) {
        if (s.m_id == id) return false;
    }
    return true;
}

// ���ѧ��ID
void addId(Studata& base, int& id) {
    cout << "������ѧ�ţ�";
    cin >> id;
    while (!checkId(base, id)) {
        cout << "ѧ���ظ������������룺";
        cin >> id;
    }
}

// ���ѧ���ɼ�
Score addScore() {
    Score sc;
    cout << "������ɼ���";
    cin >> sc.sc_Computer;
    cout << "Ӣ��ɼ���";
    cin >> sc.sc_Eng;
    cout << "��ѧ�ɼ���";
    cin >> sc.sc_Math;
    sc.calculate();
    return sc;
}

// ���ѧ��
void addStudent(Studata& base) {
    int count;
    cout << "Ҫ��ӵ�ѧ��������";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "\nѧ�� #" << i + 1 << endl;
        Student s;
        cout << "������";
        cin >> s.m_name;
        cout << "���䣺";
        cin >> s.m_age;
        addId(base, s.m_id);
        s.m_score = addScore();
        base.stu.push_back(s);
    }
    base.saveToFile();
}

// ɾ���˵�
void deleteMenu() {
    cout << "\n--- ɾ����ʽ ---" << endl;
    cout << "1.������ɾ��" << endl;
    cout << "2.��ѧ��ɾ��" << endl;
    cout << "0.�������˵�" << endl;
}

// ɾ��ѧ��
void deleteStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "û��ѧ������" << endl;
        return;
    }

    deleteMenu();
    int choice;
    cout << "��ѡ��";
    cin >> choice;

    if (choice == 0) return;

    if (choice == 1) {
        string name;
        cout << "����Ҫɾ����ѧ��������";
        cin >> name;

        bool found = false;
        for (auto it = base.stu.begin(); it != base.stu.end(); ) {
            if (it->m_name == name) {
                it = base.stu.erase(it);
                found = true;
                cout << "ɾ���ɹ�" << endl;
            }
            else {
                ++it;
            }
        }
        if (!found) cout << "δ�ҵ�ѧ��" << endl;
        else base.saveToFile();
    }
    else if (choice == 2) {
        int id;
        cout << "����Ҫɾ����ѧ��ѧ�ţ�";
        cin >> id;

        bool found = false;
        for (auto it = base.stu.begin(); it != base.stu.end(); ) {
            if (it->m_id == id) {
                it = base.stu.erase(it);
                found = true;
                cout << "ɾ���ɹ�" << endl;
                break;
            }
            else {
                ++it;
            }
        }
        if (!found) cout << "δ�ҵ�ѧ��" << endl;
        else base.saveToFile();
    }
    else {
        cout << "��Чѡ��" << endl;
    }
}

// ����ѧ��
void findStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "û��ѧ������" << endl;
        return;
    }

    cout << "\n--- ���ҷ�ʽ ---" << endl;
    cout << "1.����������" << endl;
    cout << "2.��ѧ�Ų���" << endl;
    cout << "0.�������˵�" << endl;

    int choice;
    cout << "��ѡ��";
    cin >> choice;

    if (choice == 0) return;

    if (choice == 1) {
        string name;
        cout << "����ѧ��������";
        cin >> name;

        bool found = false;
        for (const auto& s : base.stu) {
            if (s.m_name == name) {
                found = true;
                cout << "������" << s.m_name << " ���䣺" << s.m_age
                    << " ѧ�ţ�" << s.m_id << " �ܷ֣�" << s.m_score.sum << endl;
            }
        }
        if (!found) cout << "δ�ҵ�ѧ��" << endl;
    }
    else if (choice == 2) {
        int id;
        cout << "����ѧ��ѧ�ţ�";
        cin >> id;

        bool found = false;
        for (const auto& s : base.stu) {
            if (s.m_id == id) {
                found = true;
                cout << "������" << s.m_name << " ���䣺" << s.m_age
                    << " ѧ�ţ�" << s.m_id << " �ܷ֣�" << s.m_score.sum << endl;
                break;
            }
        }
        if (!found) cout << "δ�ҵ�ѧ��" << endl;
    }
    else {
        cout << "��Чѡ��" << endl;
    }
}

// �޸�ѧ����Ϣ
void modifyStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "û��ѧ������" << endl;
        return;
    }
    //��Ϊ�����п��ܲ�Ψһ������������ѧ�Ų���
    int id;
    cout << "����Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    cin >> id;

    bool found = false;
    for (auto& s : base.stu) {
        if (s.m_id == id) {
            found = true;
            cout << "��������";
            cin >> s.m_name;
            cout << "�����䣺";
            cin >> s.m_age;

            int newId;
            cout << "��ѧ�ţ�";
            cin >> newId;
            if (newId != id && !checkId(base, newId)) {
                cout << "ѧ���Ѵ��ڣ��޸�ʧ��" << endl;
                return;
            }
            s.m_id = newId;

            cout << "�¼�����ɼ���";
            cin >> s.m_score.sc_Computer;
            cout << "��Ӣ��ɼ���";
            cin >> s.m_score.sc_Eng;
            cout << "����ѧ�ɼ���";
            cin >> s.m_score.sc_Math;
            s.m_score.calculate();

            cout << "�޸ĳɹ�" << endl;
            base.saveToFile();
            break;
        }
    }
    if (!found) cout << "δ�ҵ�ѧ��" << endl;
}

// ����ȽϺ���
bool compareSumDesc(const Student& a, const Student& b) {
    return a.m_score.sum > b.m_score.sum;
}
bool compareSumAsc(const Student& a, const Student& b) {
    return a.m_score.sum < b.m_score.sum;
}
bool compareAvgDesc(const Student& a, const Student& b) {
    return a.m_score.avg > b.m_score.avg;
}
bool compareAvgAsc(const Student& a, const Student& b) {
    return a.m_score.avg < b.m_score.avg;
}

// ��ʾѧ���б�
void displayStudents(Studata& base) {
    if (base.stu.empty()) {
        cout << "û��ѧ������" << endl;
        return;
    }

    cout << "\nѧ���б� (" << base.stu.size() << " ��):" << endl;
    for (const auto& s : base.stu) {
        cout << "������" << s.m_name << " ѧ�ţ�" << s.m_id
            << " �ܷ֣�" << s.m_score.sum << " ƽ���֣�" << s.m_score.avg << endl;
    }
}

// ��ϵͳ�߼�
void runStudentSystem() {
    Studata database;
    database.loadFromFile();

    int choice;
    do {
        menu();
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(database); break;
        case 2: deleteStudent(database); break;
        case 3: findStudent(database); break;
        case 4: modifyStudent(database); break;
        case 5:
            database.stu.sort(compareSumDesc);
            cout << "���ܳɼ���������" << endl;
            displayStudents(database);
            break;
        case 6:
            database.stu.sort(compareAvgDesc);
            cout << "��ƽ���ɼ���������" << endl;
            displayStudents(database);
            break;
        case 7: displayStudents(database); break;
        case 8: database.saveToFile(); break;
        case 9: database.viewFromFile(); break;
        case 0:
            database.saveToFile();
            cout << "ϵͳ���˳��������ѱ���" << endl;
            exit(0);
        default: cout << "��Чѡ��������" << endl;
        }
    } while (choice != 0);
}

// ================= ������ =================
int main() {
    UsersManger userManager;
    userManager.m_loadFromFile();

    int choice;
    bool loggedIn = false;

    do {
        mangermenu();
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
        case 1:
            Enroll(userManager);
            break;
        case 2:
            loggedIn = Login(userManager);
            if (loggedIn) runStudentSystem();
            break;
        case 3:
            userManager.displayAllUsers();
            break;
        case 0:
            userManager.m_saveToFile(true);
            cout << "ϵͳ���˳�" << endl;
            return 0;
        default:
            cout << "��Чѡ��������" << endl;
        }
    } while (true);

    return 0;
}