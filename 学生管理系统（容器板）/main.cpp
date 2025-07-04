#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ================= 用户管理系统 =================
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

    // 从文件加载用户数据
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

    // 保存用户数据到文件
    void m_saveToFile(bool overwrite = false) {
        ofstream file;
        if (overwrite) {
            file.open(filename, ios::trunc); // 覆盖模式
        }
        else {
            file.open(filename, ios::app);   // 追加模式
        }

        if (file.is_open()) {
            for (const auto& user : v) {
                file << user.Username << " " << user.password << endl;
            }
            file.close();
        }
    }

    // 查看所有用户
    void displayAllUsers() {
        if (v.empty()) {
            cout << "暂无注册用户" << endl;
            return;
        }
        cout << "当前注册用户列表：" << endl;
        for (size_t i = 0; i < v.size(); ++i) {
            cout << i + 1 << ". " << v[i].Username << endl;
        }
    }
};

// 用户管理菜单
void mangermenu() {
    cout << "============ 用户管理系统 ============" << endl;
    cout << "*****1.注册*****" << endl;
    cout << "*****2.登录*****" << endl;
    cout << "---3.查看当前已有用户---" << endl;
    cout << "*****0.退出*****" << endl;
    cout << "=====================================" << endl;
}

// 用户注册
void Enroll(UsersManger& manager) {
    string username, password;
    cout << "请输入用户名：";
    cin >> username;

    // 检查用户名是否已存在
    for (const auto& user : manager.v) {
        if (user.Username == username) {
            cout << "该用户名已被注册，请选择其他用户名" << endl;
            return;
        }
    }

    cout << "请输入密码：";
    cin >> password;

    manager.v.push_back(Users(password, username));
    manager.m_saveToFile(true); // 保存所有用户
    cout << "注册成功！" << endl;
}

// 用户登录
bool Login(UsersManger& manager) {
    if (manager.v.empty()) {
        cout << "当前没有注册用户" << endl;
        return false;
    }

    string username, password;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;

    for (const auto& user : manager.v) {
        if (user.Username == username && user.password == password) {
            cout << "登录成功！欢迎使用学生管理系统" << endl;
            return true;
        }
    }

    cout << "用户名或密码错误！" << endl;
    return false;
}

// ================= 学生管理系统 =================
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

    // 从文件加载数据
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
        cout << "已加载 " << stu.size() << " 条学生记录" << endl;
    }

    // 保存数据到文件
    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "无法打开文件进行保存" << endl;
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
        cout << "数据已保存 (" << stu.size() << " 条记录)" << endl;
    }

    // 查看文件数据
    void viewFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "无法打开文件" << endl;
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

            cout << "姓名：" << s.m_name
                << " 年龄：" << s.m_age
                << " 学号：" << s.m_id
                << " 计算机：" << s.m_score.sc_Computer
                << " 英语：" << s.m_score.sc_Eng
                << " 数学：" << s.m_score.sc_Math
                << " 总分：" << s.m_score.sum
                << " 平均分：" << s.m_score.avg << endl;
            count++;
        }
        inFile.close();
        cout << "共查看 " << count << " 条记录" << endl;
    }
};

// 系统菜单
void menu() {
    cout << "\n============ 学生管理系统 ============" << endl;
    cout << "*****1.添加学生*****" << endl;
    cout << "*****2.删除学生*****" << endl;
    cout << "*****3.查找学生*****" << endl;
    cout << "*****4.修改数据*****" << endl;
    cout << "*****5.总成绩排序*****" << endl;
    cout << "*****6.平均成绩排序*****" << endl;
    cout << "*****7.全部学生展示*****" << endl;
    cout << "*****8.保存到文件*****" << endl;
    cout << "*****9.查看文件信息*****" << endl;
    cout << "*****0.退出程序*****" << endl;
    cout << "=====================================" << endl;
}

// 检查ID是否重复
bool checkId(Studata& base, int id) {
    for (const auto& s : base.stu) {
        if (s.m_id == id) return false;
    }
    return true;
}

// 添加学生ID
void addId(Studata& base, int& id) {
    cout << "请输入学号：";
    cin >> id;
    while (!checkId(base, id)) {
        cout << "学号重复，请重新输入：";
        cin >> id;
    }
}

// 添加学生成绩
Score addScore() {
    Score sc;
    cout << "计算机成绩：";
    cin >> sc.sc_Computer;
    cout << "英语成绩：";
    cin >> sc.sc_Eng;
    cout << "数学成绩：";
    cin >> sc.sc_Math;
    sc.calculate();
    return sc;
}

// 添加学生
void addStudent(Studata& base) {
    int count;
    cout << "要添加的学生数量：";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "\n学生 #" << i + 1 << endl;
        Student s;
        cout << "姓名：";
        cin >> s.m_name;
        cout << "年龄：";
        cin >> s.m_age;
        addId(base, s.m_id);
        s.m_score = addScore();
        base.stu.push_back(s);
    }
    base.saveToFile();
}

// 删除菜单
void deleteMenu() {
    cout << "\n--- 删除方式 ---" << endl;
    cout << "1.按姓名删除" << endl;
    cout << "2.按学号删除" << endl;
    cout << "0.返回主菜单" << endl;
}

// 删除学生
void deleteStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "没有学生数据" << endl;
        return;
    }

    deleteMenu();
    int choice;
    cout << "请选择：";
    cin >> choice;

    if (choice == 0) return;

    if (choice == 1) {
        string name;
        cout << "输入要删除的学生姓名：";
        cin >> name;

        bool found = false;
        for (auto it = base.stu.begin(); it != base.stu.end(); ) {
            if (it->m_name == name) {
                it = base.stu.erase(it);
                found = true;
                cout << "删除成功" << endl;
            }
            else {
                ++it;
            }
        }
        if (!found) cout << "未找到学生" << endl;
        else base.saveToFile();
    }
    else if (choice == 2) {
        int id;
        cout << "输入要删除的学生学号：";
        cin >> id;

        bool found = false;
        for (auto it = base.stu.begin(); it != base.stu.end(); ) {
            if (it->m_id == id) {
                it = base.stu.erase(it);
                found = true;
                cout << "删除成功" << endl;
                break;
            }
            else {
                ++it;
            }
        }
        if (!found) cout << "未找到学生" << endl;
        else base.saveToFile();
    }
    else {
        cout << "无效选择" << endl;
    }
}

// 查找学生
void findStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "没有学生数据" << endl;
        return;
    }

    cout << "\n--- 查找方式 ---" << endl;
    cout << "1.按姓名查找" << endl;
    cout << "2.按学号查找" << endl;
    cout << "0.返回主菜单" << endl;

    int choice;
    cout << "请选择：";
    cin >> choice;

    if (choice == 0) return;

    if (choice == 1) {
        string name;
        cout << "输入学生姓名：";
        cin >> name;

        bool found = false;
        for (const auto& s : base.stu) {
            if (s.m_name == name) {
                found = true;
                cout << "姓名：" << s.m_name << " 年龄：" << s.m_age
                    << " 学号：" << s.m_id << " 总分：" << s.m_score.sum << endl;
            }
        }
        if (!found) cout << "未找到学生" << endl;
    }
    else if (choice == 2) {
        int id;
        cout << "输入学生学号：";
        cin >> id;

        bool found = false;
        for (const auto& s : base.stu) {
            if (s.m_id == id) {
                found = true;
                cout << "姓名：" << s.m_name << " 年龄：" << s.m_age
                    << " 学号：" << s.m_id << " 总分：" << s.m_score.sum << endl;
                break;
            }
        }
        if (!found) cout << "未找到学生" << endl;
    }
    else {
        cout << "无效选择" << endl;
    }
}

// 修改学生信息
void modifyStudent(Studata& base) {
    if (base.stu.empty()) {
        cout << "没有学生数据" << endl;
        return;
    }
    //因为姓名有可能不唯一，所以这里用学号查找
    int id;
    cout << "输入要修改的学生学号：";
    cin >> id;

    bool found = false;
    for (auto& s : base.stu) {
        if (s.m_id == id) {
            found = true;
            cout << "新姓名：";
            cin >> s.m_name;
            cout << "新年龄：";
            cin >> s.m_age;

            int newId;
            cout << "新学号：";
            cin >> newId;
            if (newId != id && !checkId(base, newId)) {
                cout << "学号已存在，修改失败" << endl;
                return;
            }
            s.m_id = newId;

            cout << "新计算机成绩：";
            cin >> s.m_score.sc_Computer;
            cout << "新英语成绩：";
            cin >> s.m_score.sc_Eng;
            cout << "新数学成绩：";
            cin >> s.m_score.sc_Math;
            s.m_score.calculate();

            cout << "修改成功" << endl;
            base.saveToFile();
            break;
        }
    }
    if (!found) cout << "未找到学生" << endl;
}

// 排序比较函数
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

// 显示学生列表
void displayStudents(Studata& base) {
    if (base.stu.empty()) {
        cout << "没有学生数据" << endl;
        return;
    }

    cout << "\n学生列表 (" << base.stu.size() << " 人):" << endl;
    for (const auto& s : base.stu) {
        cout << "姓名：" << s.m_name << " 学号：" << s.m_id
            << " 总分：" << s.m_score.sum << " 平均分：" << s.m_score.avg << endl;
    }
}

// 主系统逻辑
void runStudentSystem() {
    Studata database;
    database.loadFromFile();

    int choice;
    do {
        menu();
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(database); break;
        case 2: deleteStudent(database); break;
        case 3: findStudent(database); break;
        case 4: modifyStudent(database); break;
        case 5:
            database.stu.sort(compareSumDesc);
            cout << "按总成绩降序排序" << endl;
            displayStudents(database);
            break;
        case 6:
            database.stu.sort(compareAvgDesc);
            cout << "按平均成绩降序排序" << endl;
            displayStudents(database);
            break;
        case 7: displayStudents(database); break;
        case 8: database.saveToFile(); break;
        case 9: database.viewFromFile(); break;
        case 0:
            database.saveToFile();
            cout << "系统已退出，数据已保存" << endl;
            exit(0);
        default: cout << "无效选择，请重试" << endl;
        }
    } while (choice != 0);
}

// ================= 主函数 =================
int main() {
    UsersManger userManager;
    userManager.m_loadFromFile();

    int choice;
    bool loggedIn = false;

    do {
        mangermenu();
        cout << "请选择操作：";
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
            cout << "系统已退出" << endl;
            return 0;
        default:
            cout << "无效选择，请重试" << endl;
        }
    } while (true);

    return 0;
}