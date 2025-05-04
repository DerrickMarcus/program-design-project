#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <windows.h>           //调用休眠函数
const int MAX_STU_NUM = 10000; // 能够录入的最大学生数目
const int MAX_STRLEN = 1024;   // 该系统中出现的字符串最大长度
const std::string College[48] = {
    // 院系编号
    "电子系",         // 0
    "建筑学院",       // 1
    "土木系",         // 2
    "水利系",         // 3
    "环境学院",       // 4
    "机械系",         // 5
    "精仪系",         // 6
    "能动系",         // 7
    "车辆学院",       // 8
    "工业工程系",     // 9
    "电机系",         // 10
    "计算机系",       // 11
    "自动化系",       // 12
    "软件学院",       // 13
    "集成电路学院",   // 14
    "航院",           // 15
    "工程物理系",     // 16
    "化工系",         // 17
    "材料学院",       // 18
    "数学系",         // 19
    "物理系",         // 20
    "化学系",         // 21
    "生命学院",       // 22
    "地学系",         // 23
    "交叉信息院",     // 24
    "经管学院",       // 25
    "公管学院",       // 26
    "金融学院",       // 27
    "外文系",         // 28
    "法学院",         // 29
    "新闻学院",       // 30
    "马克思主义学院", // 31
    "人文学院",       // 32
    "社科学院",       // 33
    "美术学院",       // 34
    "卫健学院",       // 35
    "医学院",         // 36
    "药学院",         // 37
    "天文系",         // 38
    "网络研究院",     // 39
    "语言中心",       // 40
    "新雅书院",       // 41
    "未央书院",       // 42
    "致理书院",       // 43
    "日新书院",       // 44
    "行健书院",       // 45
    "为先书院",       // 46
    "秀钟书院",       // 47
};
const std::string Grade[13] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "P", "F"};
// 程序开始运行时从文件中读取信息存入容器中，结束时将新的信息写入文件中保存
const std::string STUDENT_FILE_PATH = "D:\\ASUS\\Desktop\\stu_info.csv";
const std::string TEACHER_FILE_PATH = "D:\\ASUS\\Desktop\\tch_info.csv";

// 抽象类：人员
class Person
{
public:
    virtual void displayInfo() const = 0;
    virtual ~Person(){};

private:
    std::string name;
    std::string id;
};

// 记录学生基本信息的Student类
class Student : virtual public Person
{
private:
    std::string stu_name; // 姓名
    std::string stu_id;   // 学号
    int stu_class;        // 班级
public:
    Student(std::string stu_name = "N/A", std::string stu_id = "N/A", int stu_class = 0)
    {
        this->stu_name = stu_name;
        this->stu_id = stu_id;
        this->stu_class = stu_class;
    }
    Student(const Student &other)
    {
        this->stu_name = other.stu_name;
        this->stu_id = other.stu_id;
        this->stu_class = other.stu_class;
    }
    virtual ~Student(){};
    void displayInfo() const override // 打印学生信息
    {
        std::cout << "Information of the student: " << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "*  Name: " << stu_name << std::endl;
        std::cout << "*  Student ID: " << stu_id << std::endl;
        std::cout << "*  Class: " << stu_class << std::endl;
        std::cout << "****************************\n"
                  << std::endl;
        return;
    }
    void setStudentInfo(const std::string stu_name = "N/A", const std::string stu_id = "N/A", const int stu_class = 0)
    {
        this->stu_name = stu_name;
        this->stu_id = stu_id;
        this->stu_class = stu_class;
        return;
    } // 修改全部信息
    void setStudentName(const std::string new_name = "N/A")
    {
        this->stu_name = new_name;
        return;
    } // 修改学生姓名
    void setStudentID(const std::string new_id = "N/A")
    {
        this->stu_id = new_id;
        return;
    } // 修改学生学号
    void setStudentClass(const int new_class = 0)
    {
        this->stu_class = new_class;
        return;
    } // 修改学生班级
    std::string getStudentName() const { return this->stu_name; }
    std::string getStudentID() const { return this->stu_id; }
    int getStudentClass() const { return this->stu_class; }
};

// 记录老师基本信息的Teacher类
class Teacher : virtual public Person
{
private:
    std::string tch_name; // 老师姓名
    std::string tch_id;   // 老师工号
    int tch_college;      // 老师院系编号
public:
    Teacher(std::string tch_name = "N/A", std::string tch_id = "N/A", int tch_college = 10)
    {
        this->tch_name = tch_name;
        this->tch_id = tch_id;
        this->tch_college = tch_college;
    }
    Teacher(const Teacher &other)
    {
        this->tch_name = other.tch_name;
        this->tch_id = other.tch_id;
        this->tch_college = other.tch_college;
    }
    virtual ~Teacher(){};
    void displayInfo() const override // 打印教师信息
    {
        std::cout << "Information of the Teacher: " << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "*  Name: " << tch_name << std::endl;
        std::cout << "*  Teacher ID: " << tch_id << std::endl;
        std::cout << "*  College: " << College[tch_college] << std::endl;
        std::cout << "****************************\n"
                  << std::endl;
    }
    void setTeacherInfo(const std::string tch_name = "N/A", const std::string tch_id = "N/A", const int tch_college = 0)
    {
        this->tch_name = tch_name;
        this->tch_id = tch_id;
        this->tch_college = tch_college;
    } // 修改教师信息
    void setTeacherName(const std::string new_name = "N/A")
    {
        this->tch_name = new_name;
        return;
    } // 修改教师姓名
    void setTeacherID(const std::string new_id = "N/A")
    {
        this->tch_id = new_id;
        return;
    } // 修改教师工号
    void setTeacherCollege(const int new_college = 0)
    {
        this->tch_college = new_college;
        return;
    } // 修改教师院系
    std::string getTeacherName() const { return this->tch_name; }
    std::string getTeacherID() const { return this->tch_id; }
    int getTeacherCollege() const { return this->tch_college; }
};

// 记录课程基本信息的Course类
class Course : virtual public Teacher
{
private:
    std::string crs_name; // 课程名
    int crs_credit;       // 课程学分
    bool isPF;            // 是否记PF
public:
    Course(std::string crs_name = "N/A", int crs_credit = 0, bool isPF = false)
    {
        this->crs_name = crs_name;
        this->crs_credit = crs_credit;
        this->isPF = isPF;
    }
    Course(const Course &other) : Teacher(other), crs_name(other.crs_name), crs_credit(other.crs_credit), isPF(other.isPF){};
    virtual ~Course(){};
    void displayInfo() const override
    {
        std::cout << "Information of the course: " << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "*  Course: " << crs_name << std::endl;
        std::cout << "*  Teacher: " << Teacher::getTeacherName() << "      College: " << College[Teacher::getTeacherCollege()] << std::endl;
        std::cout << "*  Credit: " << crs_credit << "      Hours: " << crs_credit * 16 << std::endl;
        std::cout << "*  Record as P/F itself or not: " << (isPF ? "Yes" : "No") << std::endl;
        std::cout << "********************************************\n"
                  << std::endl;
    }
    void setCourseInfo(const std::string tch_name = "N/A", const std::string id = "N/A", const int college = 0, const std::string crs_name = "N/A", const int crs_credit = 0, const bool isPF = false)
    {
        Teacher::setTeacherInfo(tch_name, id, college);
        this->crs_name = crs_name;
        this->crs_credit = crs_credit;
        this->isPF = isPF;
    } // 修改课程信息
    void setCourseName(const std::string new_name = "N/A")
    {
        this->crs_name = new_name;
        return;
    } // 修改课程名称
    void setCourseCredit(const int new_credit = 0)
    {
        this->crs_credit = new_credit;
        return;
    } // 修改课程学分
    void setCourseIsPF(const bool new_isPF = false)
    {
        this->isPF = new_isPF;
        return;
    } // 修改课程是否记PF
    // 修改基类中的成员
    void setTeacherName(const std::string new_name = "N/A") { Teacher::setTeacherName(new_name); }
    void setTeacherID(const std::string new_id = "N/A") { Teacher::setTeacherID(new_id); }
    void setTeacherCollege(const int new_college = 0) { Teacher::setTeacherCollege(new_college); }
    // 获取成员信息
    std::string getCourseName() const { return this->crs_name; }
    int getCourseCredit() const { return this->crs_credit; }
    bool getCourseIsPF() const { return this->isPF; }
    // 在派生类中获取基类的信息
    std::string getTeacherName() const { return Teacher::getTeacherName(); }
    std::string getTeacherID() const { return Teacher::getTeacherID(); }
    int getTeacherCollege() const { return Teacher::getTeacherCollege(); }
};

// 记录学生+课程的成绩类
class StudentCourse : public Student, public Course
{
private:
    std::string crs; // 课程名称
    int score;       // 百分制成绩
    double gpa;      // 课程绩点
    int grade;       // 课程等级
public:
    StudentCourse(std::string crs = "N/A", int score = 0, double gpa = 0.0, int grade = 0)
    {
        this->crs = crs;
        this->score = score;
        if (Course::getCourseIsPF() == true)
        {
            if (60 <= score && score <= 100)
            {
                this->gpa = 4.0;  // 4.0代替P
                this->grade = 11; //"P"
            }
            else
            {
                this->gpa = 0.0;  // 0代替F
                this->grade = 12; //"F"
            }
        }
        else
        {
            if (score == 100)
            {
                this->gpa = 4.0;
                this->grade = 0;
            }
            else if (95 <= score && score <= 99)
            {
                this->gpa = 4.0;
                this->grade = 1;
            }
            else if (90 <= score && score <= 94)
            {
                this->gpa = 4.0;
                this->grade = 2;
            }
            else if (85 <= score && score <= 89)
            {
                this->gpa = 3.6;
                this->grade = 3;
            }
            else if (80 <= score && score <= 84)
            {
                this->gpa = 3.3;
                this->grade = 4;
            }
            else if (77 <= score && score <= 79)
            {
                this->gpa = 3.0;
                this->grade = 5;
            }
            else if (73 <= score && score <= 76)
            {
                this->gpa = 2.6;
                this->grade = 6;
            }
            else if (70 <= score && score <= 72)
            {
                this->gpa = 2.3;
                this->grade = 7;
            }
            else if (67 <= score && score <= 69)
            {
                this->gpa = 2.0;
                this->grade = 8;
            }
            else if (63 <= score && score <= 66)
            {
                this->gpa = 1.6;
                this->grade = 9;
            }
            else if (60 <= score && score <= 62)
            {
                this->gpa = 1.3;
                this->grade = 10;
            }
            else
            {
                this->gpa = 0.0;
                this->grade = 12;
            }
        }
    }
    StudentCourse(const StudentCourse &other) : Student(other), Teacher(other), Course(other)
    {
        this->crs = other.crs;
        this->score = other.score;
        this->gpa = other.gpa;
        this->grade = other.grade;
    }
    virtual ~StudentCourse(){};
    void displayInfo() const override
    {
        std::cout << "*  Course: " << crs << std::endl;
        std::cout << "*  Score: " << score << "\tCredit: " << Course::getCourseCredit() << std::endl;
        std::cout << "*  GPA: " << gpa << "\tGrade: " << Grade[grade] << std::endl;
        return;
    }
    void setStudentCourseInfo(const std::string name1 = "N/A", const std::string id1 = "N/A", const int class1 = 0, const std::string name2 = "N/A", const std::string id2 = "N/A", const int college = 0, const std::string name3 = "N/A", const int credit = 0, const bool isPF = false, const int score = 0)
    {
        Student::setStudentInfo(name1, id1, class1);
        Teacher::setTeacherInfo(name2, id2, college);
        Course::setCourseInfo(name2, id2, college, name3, credit, isPF);
        this->crs = name3;
        this->score = score;
        if (Course::getCourseIsPF() == true)
        {
            if (60 <= score && score <= 100)
            {
                this->gpa = 4.0;  // 4.0代替P
                this->grade = 11; //"P"
            }
            else
            {
                this->gpa = 0.0;  // 0代替F
                this->grade = 12; //"F"
            }
        }
        else
        {
            if (score == 100)
            {
                this->gpa = 4.0;
                this->grade = 0;
            }
            else if (95 <= score && score <= 99)
            {
                this->gpa = 4.0;
                this->grade = 1;
            }
            else if (90 <= score && score <= 94)
            {
                this->gpa = 4.0;
                this->grade = 2;
            }
            else if (85 <= score && score <= 89)
            {
                this->gpa = 3.6;
                this->grade = 3;
            }
            else if (80 <= score && score <= 84)
            {
                this->gpa = 3.3;
                this->grade = 4;
            }
            else if (77 <= score && score <= 79)
            {
                this->gpa = 3.0;
                this->grade = 5;
            }
            else if (73 <= score && score <= 76)
            {
                this->gpa = 2.6;
                this->grade = 6;
            }
            else if (70 <= score && score <= 72)
            {
                this->gpa = 2.3;
                this->grade = 7;
            }
            else if (67 <= score && score <= 69)
            {
                this->gpa = 2.0;
                this->grade = 8;
            }
            else if (63 <= score && score <= 66)
            {
                this->gpa = 1.6;
                this->grade = 9;
            }
            else if (60 <= score && score <= 62)
            {
                this->gpa = 1.3;
                this->grade = 10;
            }
            else
            {
                this->gpa = 0.0;
                this->grade = 12;
            }
        }
    }
    void setStudentCourseName(const std::string new_name = "N/A")
    {
        this->crs = new_name;
    }
    void setStudentCourseScore(const int new_score = 0)
    {
        this->score = new_score;
        if (Course::getCourseIsPF() == true)
        {
            if (60 <= score && score <= 100)
            {
                this->gpa = 4.0;  // 4.0代替P
                this->grade = 11; //"P"
            }
            else
            {
                this->gpa = 0.0;  // 0代替F
                this->grade = 12; //"F"
            }
        }
        else
        {
            if (score == 100)
            {
                this->gpa = 4.0;
                this->grade = 0;
            }
            else if (95 <= score && score <= 99)
            {
                this->gpa = 4.0;
                this->grade = 1;
            }
            else if (90 <= score && score <= 94)
            {
                this->gpa = 4.0;
                this->grade = 2;
            }
            else if (85 <= score && score <= 89)
            {
                this->gpa = 3.6;
                this->grade = 3;
            }
            else if (80 <= score && score <= 84)
            {
                this->gpa = 3.3;
                this->grade = 4;
            }
            else if (77 <= score && score <= 79)
            {
                this->gpa = 3.0;
                this->grade = 5;
            }
            else if (73 <= score && score <= 76)
            {
                this->gpa = 2.6;
                this->grade = 6;
            }
            else if (70 <= score && score <= 72)
            {
                this->gpa = 2.3;
                this->grade = 7;
            }
            else if (67 <= score && score <= 69)
            {
                this->gpa = 2.0;
                this->grade = 8;
            }
            else if (63 <= score && score <= 66)
            {
                this->gpa = 1.6;
                this->grade = 9;
            }
            else if (60 <= score && score <= 62)
            {
                this->gpa = 1.3;
                this->grade = 10;
            }
            else
            {
                this->gpa = 0.0;
                this->grade = 12;
            }
        }
    }
    std::string getStudentCourseName() const { return this->crs; }
    int getStudentCourseScore() const { return this->score; }
    double getStudentCourseGPA() const { return this->gpa; }
    int getStudentCourseGrade() const { return this->grade; }
    // 在派生类中修改基类的信息
    void setStudentName(const std::string new_name = "N/A") { Student::setStudentName(new_name); }
    void setStudentID(const std::string new_id = "N/A") { Student::setStudentID(new_id); }
    void setStudentClass(const int new_class = 0) { Student::setStudentClass(new_class); }
    void setTeacherName(const std::string new_name = "N/A") { Teacher::setTeacherName(new_name); }
    void setTeacherID(const std::string new_id = "N/A") { Teacher::setTeacherID(new_id); }
    void setTeacherCollege(const int new_college = 0) { Teacher::setTeacherCollege(new_college); }
    void setCourseName(const std::string new_name = "N/A") { Course::setCourseName(new_name); }
    void setCourseCredit(const int new_credit = 0) { Course::setCourseCredit(new_credit); }
    void setCourseIsPF(const bool new_isPF = false) { Course::setCourseIsPF(new_isPF); }
    // 在派生类中获取基类的信息
    std::string getStudentName() const { return Student::getStudentName(); }
    std::string getStudentID() const { return Student::getStudentID(); }
    int getStudentClass() const { return Student::getStudentClass(); }
    std::string getTeacherName() const { return Teacher::getTeacherName(); }
    std::string getTeacherID() const { return Teacher::getTeacherID(); }
    int getTeacherCollege() const { return Teacher::getTeacherCollege(); }
    std::string getCourseName() const { return Course::getCourseName(); }
    int getCourseCredit() const { return Course::getCourseCredit(); }
    bool getCourseIsPF() const { return Course::getCourseIsPF(); }
};

// 结构体，记录单个学生的信息、多门课程、均绩、排名
struct StudentResults
{
    Student stu;
    std::vector<StudentCourse> stu_crs;
    double GPA = 0.0;
    int ranking = 1;
    // 标记学生是否PF了一门课，若没有则自动初始为-1，若有则赋值为该课程在stu_crs中的下标
    int PF_flag = -1;
};

// 结构体，记录班级人数和均绩
struct ClassInfo
{
    int class_num;   // 班号
    int stu_amount;  // 学生数量
    double aver_GPA; // 班级均绩
};

// 全局变量
std::vector<StudentResults> res_vec;
std::vector<Teacher> tch_vec;
std::vector<Course> crs_vec;
std::vector<ClassInfo> class_vec;
int stu_obj = 0;   // 定位对应学生
int tch_obj = 0;   // 定位对应教师
int crs_obj = 0;   // 定位对应课程
int class_obj = 1; // 定位对应班级
int class_max = 1; // 最大班级序号

// 函数声明
void readFromStudentInfoFile(const std::string &file_name, std::vector<StudentResults> &res_vec);
void readFromTeacherInfoFile(const std::string &file_name, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec);
void writeIntoStudentInfoFile(const std::string &file_name, const std::vector<StudentResults> &res_vec);
void wrtieIntoTeacherInfoFile(const std::string &file_name, const std::vector<Course> &crs_vec);
void initialiseSystem(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec);
void shutDownSystem(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec);
void showMainMenu();    // 显示主页面菜单
int returnToMainMenu(); // 返回主菜单

int showStudentLoginMenu(const std::vector<StudentResults> &res_vec, int &stu_obj);              // 显示学生登陆界面
void showStudentMenu(const std::vector<StudentResults> &res_vec, const int &stu_obj);            // 显示学生菜单界面
void studentMenuOperate(std::vector<StudentResults> &res_vec, const int &stu_obj);               // 学生进行操作
void studentInquireSingleResult(const std::vector<StudentResults> &res_vec, const int &stu_obj); // 查询单科成绩
void studentInquireAllResults(std::vector<StudentResults> &res_vec, const int &stu_obj);         // 查询所有成绩
void studentSelectOneToPF(std::vector<StudentResults> &res_vec, const int &stu_obj);             // 选择一门PF
void studentInquireClassRanking(const std::vector<StudentResults> &res_vec, const int &stu_obj); // 查询班级排名
void studentCheckInfo(const std::vector<StudentResults> &res_vec, const int &stu_obj);           // 查看个人信息
void updateStudentResults(std::vector<StudentResults> &res_vec, const int &stu_obj);             // 更新学生成绩
void updateClassInfo(std::vector<StudentResults> &res_vec, std::vector<ClassInfo> &class_vec, const int &class_num);
void updateAllClassInfo(std::vector<StudentResults> &res_vec, std::vector<ClassInfo> &class_vec);

int showTeacherLoginMenu(const std::vector<Teacher> &tch_vec, int &tch_obj);                                                                                                       // 显示教师登陆界面
void showTeacherMenu(const std::vector<Teacher> &tch_vec, const int &tch_obj);                                                                                                     // 显示教师菜单界面
void teacherMenuOperate(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj); // 教师进行操作
void teacherEnterResults(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj);
void teacherModifyResults(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj);
void teacherInquireCourseResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj);
void teacherInquireStudentResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj);
void teacherInquireClassResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const std::vector<ClassInfo> &class_vec, const int &tch_obj);
void teacherCheckInfo(const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj);

int isStudentExist(const std::vector<StudentResults> &res_vec, const std::string &name, const std::string &id);
bool isStudentNameExist(const std::vector<StudentResults> &res_vec, const std::string &name);
int isStudentIDExist(const std::vector<StudentResults> &res_vec, const std::string &id);
int isTeacherExist(const std::vector<Teacher> &tch_vec, const std::string &name, const std::string &id);
int isTeacherNameExist(const std::vector<Teacher> &tch_vec, const std::string &name);
int isTeacherIDExist(const std::vector<Teacher> &tch_vec, const std::string &id);
int isCourseExist(const std::vector<Course> &crs_vec, const std::string &name);
int isStudentSelectCourse(const std::vector<StudentResults> &res_vec, const int &stu_obj, const std::string &name);

// 运算符重载
bool operator>(const StudentResults &lhs, const StudentResults &rhs);
bool operator>=(const StudentResults &lhs, const StudentResults &rhs);
bool operator<(const StudentResults &lhs, const StudentResults &rhs);
bool operator<=(const StudentResults &lhs, const StudentResults &rhs);
bool operator==(const StudentResults &lhs, const StudentResults &rhs);
bool operator!=(const StudentResults &lhs, const StudentResults &rhs);

bool operator>(const StudentCourse &lhs, const StudentCourse &rhs);
bool operator>=(const StudentCourse &lhs, const StudentCourse &rhs);
bool operator<(const StudentCourse &lhs, const StudentCourse &rhs);
bool operator<=(const StudentCourse &lhs, const StudentCourse &rhs);
bool operator==(const StudentCourse &lhs, const StudentCourse &rhs);
bool operator!=(const StudentCourse &lhs, const StudentCourse &rhs);

bool compareStudentCourseByScore(const StudentCourse &lhs, const StudentCourse &rhs);
bool compareStudentByGPA(const StudentResults &lhs, const StudentResults &rhs);
// 函数声明结束

// 函数定义
//
//
// 从文件中读取学生信息
void readFromStudentInfoFile(const std::string &file_name, std::vector<StudentResults> &res_vec)
{
    std::ifstream stu_file(file_name, std::ios_base::in);
    std::vector<StudentCourse> sc_vec;
    std::vector<Student> stu_vec;
    std::string line;
    res_vec.clear();
    class_vec.clear();

    if (!stu_file.is_open())
    {
        std::cerr << "The initialising process ran into a problem and the system needs to restart" << std::endl;
        std::cerr << "Details: Failed to open the file " << file_name << std::endl;
        exit(1);
    }
    while (std::getline(stu_file, line))
    {
        std::stringstream ss(line);
        std::string stu_name, stu_id, stu_class, tch_name, tch_id, tch_college;
        std::string crs_name, crs_credit, isPF, score;
        if (std::getline(ss, stu_name, ',') &&
            std::getline(ss, stu_id, ',') &&
            std::getline(ss, stu_class, ',') &&
            std::getline(ss, tch_name, ',') &&
            std::getline(ss, tch_id, ',') &&
            std::getline(ss, tch_college, ',') &&
            std::getline(ss, crs_name, ',') &&
            std::getline(ss, crs_credit, ',') &&
            std::getline(ss, isPF, ',') &&
            std::getline(ss, score, ','))
        {
            // 字符串类型需要转换为整数、浮点数和布尔值
            int stu_class0 = std::stoi(stu_class);
            int tch_college0 = std::stoi(tch_college);
            int crs_credit0 = std::stoi(crs_credit);
            bool isPF0 = (isPF == "1");
            int score0 = std::stoi(score);

            StudentCourse sc;
            sc.setStudentCourseInfo(stu_name, stu_id, stu_class0, tch_name, tch_id, tch_college0, crs_name, crs_credit0, isPF0, score0);

            int flag = 0;
            for (const auto &res : res_vec)
            {
                flag++;
                if (res.stu.getStudentName() == stu_name && res.stu.getStudentID() == stu_id)
                {
                    break;
                }
            }
            flag--; // flag定位出该学生在res_vec中的下标，如果没有新建
            if (flag < (res_vec.size() - 1))
            {
                res_vec[flag].stu_crs.push_back(sc);
            }
            else
            {
                StudentResults new_res;
                new_res.stu.setStudentInfo(stu_name, stu_id, stu_class0);
                new_res.ranking = 1;
                new_res.PF_flag = -1;
                new_res.stu_crs.push_back(sc);
                res_vec.push_back(new_res);
            }
        }
    }
    for (int i = 0; i < res_vec.size(); i++)
    {
        updateStudentResults(res_vec, i);
    }
    updateAllClassInfo(res_vec, class_vec);
    // 创建班级
    for (const auto &res : res_vec)
    {
        if (res.stu.getStudentClass() > class_max)
        {
            class_max = res.stu.getStudentClass();
        }
    }
    for (int i = 0; i < class_max; i++)
    {
        ClassInfo ci;
        ci.class_num = i + 1;
        int amount = 0;
        double sum_gpa = 0;
        for (const auto &res : res_vec)
        {
            if (res.stu.getStudentClass() == i + 1)
            {
                amount++;
                sum_gpa += res.GPA;
            }
        }
        ci.stu_amount = amount;
        ci.aver_GPA = sum_gpa / amount;
        class_vec.push_back(ci);
    }
    for (int i = 0; i < res_vec.size(); i++)
    {
        updateStudentResults(res_vec, i);
    }
    updateAllClassInfo(res_vec, class_vec);
    stu_file.close();
    return;
}

void readFromTeacherInfoFile(const std::string &file_name, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec)
{
    std::ifstream tch_file(file_name, std::ios_base::in);
    std::string line;
    tch_vec.clear();
    crs_vec.clear();
    if (!tch_file.is_open())
    {
        std::cerr << "The initialising process ran into a problem and the system needs to restart" << std::endl;
        std::cerr << "Details: Failed to open the file: " << file_name << std::endl;
        exit(1);
    }
    while (std::getline(tch_file, line))
    {
        std::stringstream ss(line);
        std::string tch_name, tch_id, tch_college, crs_name, crs_credit, isPF;
        if (std::getline(ss, tch_name, ',') &&
            std::getline(ss, tch_id, ',') &&
            std::getline(ss, tch_college, ',') &&
            std::getline(ss, crs_name, ',') &&
            std::getline(ss, crs_credit, ',') &&
            std::getline(ss, isPF))
        {
            // 字符串类型需要转换为整数、浮点数和布尔值
            int tch_college0 = std::stoi(tch_college);
            int crs_credit0 = std::stoi(crs_credit);
            bool isPF0 = (isPF == "1");

            tch_vec.emplace_back(tch_name, tch_id, tch_college0);
            Course crs;
            crs.setCourseInfo(tch_name, tch_id, tch_college0, crs_name, crs_credit0, isPF0);
            crs_vec.push_back(crs);
        }
    }
    tch_file.close();
    return;
}

void writeIntoStudentInfoFile(const std::string &file_name, const std::vector<StudentResults> &res_vec)
{
    std::ofstream stu_file(file_name, std::ios_base::out | std::ios_base::trunc);
    if (!stu_file.is_open())
    {
        std::cerr << "The shutdown process ran into a problem" << std::endl;
        std::cerr << "Failed to open the file: " << file_name << std::endl;
        exit(1);
    }
    for (const auto &res : res_vec)
    {
        for (const auto &sc : res.stu_crs)
        {
            std::ostringstream line;
            line << sc.getStudentName() << ',' << sc.getStudentID() << ',' << std::to_string(sc.getStudentClass()) << ',';
            line << sc.getTeacherName() << ',' << sc.getTeacherID() << ',' << std::to_string(sc.getTeacherCollege()) << ',';
            line << sc.getCourseName() << ',' << std::to_string(sc.getCourseCredit()) << ',' << (sc.getCourseIsPF() ? "1" : "0") << ',';
            line << std::to_string(sc.getStudentCourseScore()) << std::endl;
            stu_file << line.str();
        }
    }
    stu_file.close();
    return;
}

void wrtieIntoTeacherInfoFile(const std::string &file_name, const std::vector<Course> &crs_vec)
{
    std::ofstream tch_file(file_name, std::ios_base::out | std::ios_base::trunc);
    if (!tch_file.is_open())
    {
        std::cerr << "The shutdown process ran into a problem" << std::endl;
        std::cerr << "Failed to open the file: " << file_name << std::endl;
        exit(1);
    }
    for (const auto &crs : crs_vec)
    {
        std::ostringstream line;
        line << crs.getTeacherName() << ',' << crs.getTeacherID() << ',' << std::to_string(crs.getTeacherCollege()) << ',';
        line << crs.getCourseName() << ',' << std::to_string(crs.getCourseCredit()) << ',' << (crs.getCourseIsPF() ? "1" : "0") << std::endl;
        tch_file << line.str();
    }
    tch_file.close();
    return;
}

// 初始化函数
void initialiseSystem(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec)
{
    readFromStudentInfoFile(STUDENT_FILE_PATH, res_vec);
    readFromTeacherInfoFile(TEACHER_FILE_PATH, tch_vec, crs_vec);
    for (int i = 0; i < res_vec.size(); i++)
    {
        updateStudentResults(res_vec, i);
    }
    updateAllClassInfo(res_vec, class_vec);
    std::cout << "******         System initializing...         ******" << std::endl;
    Sleep(1314); // 休眠1.314秒
    std::cout << "****************************************************" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "*      The system initialization is complete!      *" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "*                                                  *" << std::endl;
    std::cout << "****************************************************" << std::endl;
    return;
}

// 关机函数
void shutDownSystem(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec)
{
    writeIntoStudentInfoFile(STUDENT_FILE_PATH, res_vec);
    wrtieIntoTeacherInfoFile(TEACHER_FILE_PATH, crs_vec);
    std::cout << "******     System shuting down...     ******" << std::endl;
    Sleep(1314); // 休眠1.314秒
    std::cout << "********************************************" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "*      The system has been shut down!      *" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "********************************************" << std::endl;
    return;
}

// 主函数
int main(int argc, const char *argv[])
{
    int select_num; // 用户根据菜单界面相应功能输入的数字
    initialiseSystem(res_vec, tch_vec, crs_vec, class_vec);
    system("pause");
    system("cls");
    while (true)
    {
        showMainMenu();
        std::cout << "Input a number: 1 or 2 or 0 : ";
        std::cin >> select_num;
        if (select_num == 1)
        {
            std::cout << "\nYou choose : 1" << std::endl;
            std::cout << "------ You are about to enter the teacher interface ------" << std::endl;
            system("pause");
            int isLogIn = showTeacherLoginMenu(tch_vec, tch_obj);
            if (isLogIn != -1)
            {
                teacherMenuOperate(res_vec, tch_vec, crs_vec, class_vec, isLogIn);
            }
        }
        else if (select_num == 2)
        {
            std::cout << "\nYou choose : 2" << std::endl;
            std::cout << "------ You are about to enter the student interface ------" << std::endl;
            system("pause");
            int isLogIn = showStudentLoginMenu(res_vec, stu_obj);
            if (isLogIn != -1)
            {
                studentMenuOperate(res_vec, isLogIn);
            }
        }
        else if (select_num == 0)
        {
            std::cout << std::endl;
            std::cout << "****** Are you sure to exit the Student Performance Management System? ******" << std::endl;
            std::cout << "******                  1---Yes    0---No, keep using                  ******" << std::endl;
            int isExit;
            std::cout << "Input number 1 or 0 : ";
            while (true)
            {
                std::cin >> isExit;
                if (isExit == 1)
                {
                    std::cout << std::endl;
                    std::cout << "****** You have successfully exited the Student Performance Management System! ******" << std::endl;
                    std::cout << "******                          Welcome to use again!                          ******" << std::endl;
                    system("pause");
                    system("cls");
                    shutDownSystem(res_vec, tch_vec, crs_vec);
                    stu_obj = tch_obj = crs_obj = class_obj = 0;
                    system("pause");
                    return 0;
                    break;
                }
                else if (isExit == 0)
                {
                    std::cout << "****** You canceled to exit the Student Performance Management System! ******" << std::endl;
                    std::cout << "******                    Please continue to use...                    ******" << std::endl;
                    system("pause");
                    system("cls");
                    break;
                }
                else
                    std::cout << "\nInvalid input! Please input number 1 or 0 : ";
            }
        }
        else
        {
            std::cout << "\nInvalid input! Please input number 1 or 2 or 0 : " << std::endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");
    return 0;
}

// 该学生是否已存在，不存在返回-1，存在返回在res_vec中的下标
int isStudentExist(const std::vector<StudentResults> &res_vec, const std::string &name, const std::string &id)
{
    for (int i = 0; i < res_vec.size(); i++)
    {
        if (res_vec[i].stu.getStudentName() == name && res_vec[i].stu.getStudentID() == id)
        {
            return i;
        }
    }
    return -1;
}

// 该学生姓名是否存在(学生可能存在同名)
bool isStudentNameExist(const std::vector<StudentResults> &res_vec, const std::string &name)
{
    for (int i = 0; i < res_vec.size(); i++)
    {
        if (res_vec[i].stu.getStudentName() == name)
            return true;
    }
    return false;
}

// 该学号是否存在，不存在返回-1，存在返回在res_vec中的下标
int isStudentIDExist(const std::vector<StudentResults> &res_vec, const std::string &id)
{
    for (int i = 0; i < res_vec.size(); i++)
    {
        if (res_vec[i].stu.getStudentID() == id)
            return i;
    }
    return -1;
}

// 该老师是否存在，不存在返回-1，存在返回在tch_vec中的下标
int isTeacherExist(const std::vector<Teacher> &tch_vec, const std::string &name, const std::string &id)
{
    for (int i = 0; i < tch_vec.size(); i++)
    {
        if (tch_vec[i].getTeacherName() == name && tch_vec[i].getTeacherID() == id)
            return i;
    }
    return -1;
}

// 该老师姓名是否存在，不存在返回-1，存在返回在tch_vec中的下标，默认老师不存在同名
int isTeacherNameExist(const std::vector<Teacher> &tch_vec, const std::string &name)
{
    for (int i = 0; i < tch_vec.size(); i++)
    {
        if (tch_vec[i].getTeacherName() == name)
            return i;
    }
    return -1;
}

// 该老师工号是否存在，不存在返回-1，存在返回在tch_vec中的下标
int isTeacherIDExist(const std::vector<Teacher> &tch_vec, const std::string &id)
{
    for (int i = 0; i < tch_vec.size(); i++)
    {
        if (tch_vec[i].getTeacherID() == id)
            return i;
    }
    return -1;
}

// 该课程是否存在，未选返回-1，选了返回在crs_vec中的下标
int isCourseExist(const std::vector<Course> &crs_vec, const std::string &name)
{
    for (int i = 0; i < crs_vec.size(); i++)
    {
        if (crs_vec[i].getCourseName() == name)
            return i;
    }
    return -1;
}

// 学生是否选了这门课,未选返回-1，选了返回在stu_crs中的下标
int isStudentSelectCourse(const std::vector<StudentResults> &res_vec, const int &stu_obj, const std::string &name)
{
    for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++)
    {
        if (res_vec[stu_obj].stu_crs[i].getCourseName() == name)
            return i;
    }
    return -1;
}

// 关于StudentResults的运算符重载
bool operator<(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA < rhs.GPA;
}

bool operator>(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA > rhs.GPA;
}

bool operator<=(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA <= rhs.GPA;
}

bool operator>=(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA >= rhs.GPA;
}

bool operator==(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA == rhs.GPA;
}

bool operator!=(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA != rhs.GPA;
}

// 关于StudentCourse的运算符重载
bool operator<(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() < rhs.getStudentCourseScore();
}

bool operator>(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() > rhs.getStudentCourseScore();
}

bool operator<=(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() <= rhs.getStudentCourseScore();
}

bool operator>=(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() >= rhs.getStudentCourseScore();
}

bool operator==(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() == rhs.getStudentCourseScore();
}

bool operator!=(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() != rhs.getStudentCourseScore();
}

// 退出当前页面,返回主菜单
int returnToMainMenu()
{
    std::cout << "\n****** Are you sure to exit the current page and return to the main menu? ******" << std::endl;
    std::cout << "******              1---Yes, return    Else---No, keep using                ******" << std::endl;
    int exit;
    std::cout << "Please input: ";
    std::cin >> exit;
    if (exit == 1)
    {
        std::cout << "------ You are about to return to the main interface... ------" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "****** You canceled to return to the main interface! ******" << std::endl;
        std::cout << "******           Please continue to use...           ******" << std::endl;
        return 0;
    }
}

// 显示主菜单
void showMainMenu()
{
    std::cout << "***************************************************" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "*                  Welcome to the                 *" << std::endl;
    std::cout << "*      Student Performance Management System      *" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "***************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "To select your identity, press 1 or 2. To exit the system, press 0." << std::endl;
    std::cout << "1---I'm a teacher    2---I'm a student    0---exit the system" << std::endl;
    return;
}

//
//
// 学生部分
//
//
// 显示学生登录介面
int showStudentLoginMenu(const std::vector<StudentResults> &res_vec, int &stu_obj)
{
    system("cls");
    std::string name, id;
    int flag = 0;
    std::cout << "------ Student Login Interface ------\n"
              << std::endl;
    std::cout << "Please input your name and student ID" << std::endl;
    std::cout << "Attention: only when they are correct and match can you successfully login\n"
              << std::endl;
    while (true)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Student ID: ";
        std::cin >> id;
        if (isStudentNameExist(res_vec, name) == true && isStudentIDExist(res_vec, id) != -1 && isStudentIDExist(res_vec, id) == isStudentExist(res_vec, name, id))
        {
            stu_obj = isStudentExist(res_vec, name, id);
            std::cout << "\nSuccessful login! Welcome, " << res_vec[stu_obj].stu.getStudentName() << "!" << std::endl;
            std::cout << "------ You are about to enter student interface... ------\n"
                      << std::endl;
            system("pause");
            return stu_obj;
            break;
        }
        else
            std::cout << "Login failed! Please check your name or student ID, or whether the two match\n"
                      << std::endl;
    }
    system("pause");
    return -1;
}

// 显示特定学生菜单界面
void showStudentMenu(const std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    std::cout << "Dear " << res_vec[stu_obj].stu.getStudentName() << ":" << std::endl;
    std::cout << "************************************************************" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      1. Query a course grade                             *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      2. Query all courses grades                         *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      3. Select a course to record it as P/F              *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      4. Query class average grades and your ranking      *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      5. Query your personal information                  *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*      0. Exit the student interface                       *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "************************************************************" << std::endl;
    std::cout << "\nPlease select the operation you want (press the number corresponding to the specific function):" << std::endl;
    return;
}

// 显示学生操作界面
void studentMenuOperate(std::vector<StudentResults> &res_vec, const int &stu_obj) // 在学生界面进行的操作
{
    int select;
    int ret;
    while (true)
    {
        showStudentMenu(res_vec, stu_obj);
        std::cin >> select;
        switch (select)
        {
        case 1:
            studentInquireSingleResult(res_vec, stu_obj);
            system("pause");
            break;
        case 2:
            studentInquireAllResults(res_vec, stu_obj);
            system("pause");
            break;
        case 3:
            studentSelectOneToPF(res_vec, stu_obj);
            system("pause");
            break;
        case 4:
            studentInquireClassRanking(res_vec, stu_obj);
            system("pause");
            break;
        case 5:
            studentCheckInfo(res_vec, stu_obj);
            system("pause");
            break;
        case 0:
            ret = returnToMainMenu();
            system("pause");
            system("cls");
            if (ret == 1)
            {
                return;
                break;
            }
            else
                break;
        default:
            std::cout << "Invalid input! Please input number again (0--5)" << std::endl;
            system("pause");
            break;
        }
    }
    return;
}

// 查询单科成绩
void studentInquireSingleResult(const std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    std::string crs_name; // 课程名称
    int stu_crs_obj = 0;  // 定位课程在学生所选的位置
    std::cout << "Dear " << res_vec[stu_obj].stu.getStudentName() << "," << std::endl;
    std::cout << "All courses you selected are as follows:\n"
              << std::endl;
    std::cout << "******************************************" << std::endl;
    int num = 0;
    for (const auto &s_c : res_vec[stu_obj].stu_crs)
    {
        std::cout << "*  " << num + 1 << ".  " << s_c.getCourseName() << std::endl;
        num++;
    }
    std::cout << "******************************************" << std::endl;
    while (true)
    {
        std::cout << "Please input the number before the course you want to query: ";
        std::cin >> num;
        if (1 <= num && num <= res_vec[stu_obj].stu_crs.size())
        {
            const auto &s_c = res_vec[stu_obj].stu_crs[num - 1];
            std::cout << "Search successful!\n"
                      << std::endl;
            std::cout << "Your grade:" << std::endl;
            std::cout << "********************" << std::endl;
            std::cout << "*  Course: " << crs_name << std::endl;
            std::cout << "*  Score: " << s_c.getStudentCourseScore() << std::endl;
            std::cout << "*  Grade: " << Grade[s_c.getStudentCourseGrade()] << std::endl;
            std::cout << "*  GPA: " << s_c.getStudentCourseGPA() << std::endl;
            std::cout << "********************\n"
                      << std::endl;
            s_c.Course::displayInfo();

            int exit;
            std::cout << "Press 1 to continue query, otherwise you will exit: ";
            std::cin >> exit;
            if (exit == 1)
            {
                std::cout << "You have chose to continue query!" << std::endl;
                system("pause");
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You have chose: " << exit << std::endl;
                std::cout << "------ You are about to exit ------" << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Invalid input! Not between 1--" << res_vec[stu_obj].stu_crs.size();
        }
    }
    return;
}

// 查询所有成绩
void studentInquireAllResults(std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    double sum_gpa = 0;           // 总学分绩
    double sum_credit = 0;        // 总学分数
    double sum_credit_in_gpa = 0; // 计入GPA学分数
    std::cout << "Dear " << res_vec[stu_obj].stu.getStudentName() << "," << std::endl;
    std::cout << "All courses you selected are as follows:\n"
              << std::endl;
    std::cout << "******************************************" << std::endl;
    for (const auto &s_c : res_vec[stu_obj].stu_crs)
    {
        s_c.displayInfo();
        std::cout << "*  ---------------------------------------" << std::endl;
        sum_credit += (double)s_c.getCourseCredit();
        if (s_c.getCourseIsPF() == false)
        {
            sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
            sum_credit_in_gpa += (double)s_c.getCourseCredit();
        }
    }
    res_vec[stu_obj].GPA = sum_gpa / sum_credit;
    std::cout << "*  Your GPA: " << sum_gpa / sum_credit << std::endl;
    std::cout << "*  Total credits: " << sum_credit << std::endl;
    std::cout << "*  Total credits count towards GPA: " << sum_credit_in_gpa << std::endl;
    std::cout << "*  Total GPA: " << sum_gpa << std::endl;
    std::cout << "******************************************\n"
              << std::endl;
    return;
}

// 选择一门课程记PF
void studentSelectOneToPF(std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    std::cout << "Dear " << res_vec[stu_obj].stu.getStudentName() << ", remember that you can ONLY record ONE course as P/F" << std::endl;
    if (res_vec[stu_obj].PF_flag != -1)
    {
        std::cout << "You have already recorded a course as P/F! You choose:" << std::endl;
        std::cout << "1---Modify and record another course as P/F" << std::endl;
        std::cout << "0---Keep the original P/F course selection unchanged" << std::endl;
        int select;
        std::cout << "Please input number 1 or 0 : ";
        while (true)
        {
            std::cin >> select;
            if (select == 1)
            {
                std::cout << "You have canceled P/F to the course: " << res_vec[stu_obj].stu_crs[res_vec[stu_obj].PF_flag].getCourseName() << std::endl;
                res_vec[stu_obj].stu_crs[res_vec[stu_obj].PF_flag].setCourseIsPF(false);
                res_vec[stu_obj].PF_flag = -1;
                updateStudentResults(res_vec, stu_obj);
                updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
                updateAllClassInfo(res_vec, class_vec);
                system("pause");
                break;
            }
            else if (select == 0)
            {
                std::cout << "You have abandoned the modification! The original P/F choice keeps unchanged.\n"
                          << std::endl;
                std::cout << "------ You are about to exit and return to student interface ------" << std::endl;
                return;
                break;
            }
            else
                std::cout << "Invalid input! Please input number 1 or 0 : ";
        }
    }
    std::cout << "Now, you can record a course as P/F. Here are the courses you can select." << std::endl;
    std::cout << "Attention: This operation does not affect the courses with their own P/F\n"
              << std::endl;
    std::cout << "******************************" << std::endl;
    for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++)
    {
        std::cout << i + 1 << ". " << res_vec[stu_obj].stu_crs[i].getCourseName() << std::endl;
    }
    std::cout << "******************************" << std::endl;
    std::cout << "Please select a course (Enter the number corresponding to the course or 0 to exit):" << std::endl;
    int choice;
    while (true)
    {
        std::cin >> choice;
        if (1 <= choice && choice <= res_vec[stu_obj].stu_crs.size())
        {
            std::cout << "You select: " << choice << ". " << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << std::endl;
            int sure_num;
            std::cout << "Are you sure to record it as P/F? (Your grades will update automatically)" << std::endl;
            std::cout << "1---Yes    0---NO" << std::endl;
            while (true)
            {
                std::cin >> sure_num;
                if (sure_num == 1)
                {
                    res_vec[stu_obj].stu_crs[sure_num - 1].setCourseIsPF(true);
                    res_vec[stu_obj].PF_flag = sure_num - 1;
                    updateStudentResults(res_vec, stu_obj); // 更新
                    updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
                    updateAllClassInfo(res_vec, class_vec);
                    std::cout << "You have successfully record " << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << " as P/F!" << std::endl;
                    std::cout << "You get score: " << res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore() << " in the course";
                    if (res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore() < 60)
                        std::cout << " so the grade will be: F" << std::endl;
                    else
                        std::cout << " so the grade will be: P" << std::endl;
                    return;
                }
                else if (sure_num == 0)
                {
                    std::cout << "You have abandoned the P/F selection.\n"
                              << std::endl;
                    std::cout << "------ You are about to exit and return to student interface ------" << std::endl;
                    return;
                }
                else
                    std::cout << "Invalid input! Please input number 1 or 0" << std::endl;
            }
        }
        else if (choice == 0)
        {
            std::cout << "You have abandoned the P/F selection.\n"
                      << std::endl;
            std::cout << "------ You are about to exit and return to student interface ------" << std::endl;
            return;
        }
        else
        {
            std::cout << "Invalid input! Please input number 1--" << res_vec[stu_obj].stu_crs.size() << std::endl;
        }
    }
    return;
}

// 查询班级排名
void studentInquireClassRanking(const std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    double min_gpa = res_vec[stu_obj].GPA, max_gpa = res_vec[stu_obj].GPA;
    for (const auto &res : res_vec)
    {
        if (res > res_vec[stu_obj])
            max_gpa = res.GPA;
        if (res.GPA < res_vec[stu_obj].GPA)
            min_gpa = res.GPA;
    }
    std::cout << "Dear " << res_vec[stu_obj].stu.getStudentName() << ",\n"
              << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*  Your class: " << res_vec[stu_obj].stu.getStudentClass() << std::endl;
    std::cout << "*  Class size: " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].stu_amount << std::endl;
    std::cout << "*  Average GPA in your class: " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].aver_GPA << std::endl;
    std::cout << "*  Maximum GPA in your class: " << max_gpa << std::endl;
    std::cout << "*  Minimum GPA in your class: " << min_gpa << std::endl;
    std::cout << "*  Your GPA: " << res_vec[stu_obj].GPA << std::endl;
    std::cout << "*  Your class ranking: " << res_vec[stu_obj].ranking << std::endl;
    std::cout << "***************************************\n"
              << std::endl;
    return;
}

// 查看个人信息
void studentCheckInfo(const std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    system("cls");
    res_vec[stu_obj].stu.displayInfo();
    return;
}

// 更新该学生各科成绩、均绩和班级排名
void updateStudentResults(std::vector<StudentResults> &res_vec, const int &stu_obj)
{
    int class_num = res_vec[stu_obj].stu.getStudentClass();
    double sum_gpa = 0;    // 总学分绩
    double sum_credit = 0; // 总学分
    for (auto &s_c : res_vec[stu_obj].stu_crs)
    {
        s_c.setStudentCourseScore(s_c.getStudentCourseScore());
        sum_credit += (double)s_c.getCourseCredit();
        if (s_c.getCourseIsPF() == false)
        {
            sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
        }
    }
    res_vec[stu_obj].GPA = sum_gpa / sum_credit; // 更新均绩

    int ranking = 1;
    for (const auto &res : res_vec)
    {
        if (class_num == res.stu.getStudentClass() && res_vec[stu_obj] < res)
            ranking++;
    }
    res_vec[stu_obj].ranking = ranking; // 更新班级排名
    return;
}

// 更新该班级所有学生排名和班级均绩，class_obj是班级数，不是班级在class_vec中的下标
void updateClassInfo(std::vector<StudentResults> &res_vec, std::vector<ClassInfo> &class_vec, const int &class_obj)
{
    double sum_gpa = 0;
    int amount = 0; // 班级人数
    int flag = 0;
    for (auto &res : res_vec)
    {
        if (res.stu.getStudentClass() == class_obj)
        {
            updateStudentResults(res_vec, flag);
            sum_gpa += res.GPA;
            amount++;
        }
        flag++;
    }
    class_vec[class_obj - 1].aver_GPA = sum_gpa / class_vec[class_obj - 1].stu_amount;
    class_vec[class_obj - 1].stu_amount = amount;
    return;
}

// 更新所有班级信息
void updateAllClassInfo(std::vector<StudentResults> &res_vec, std::vector<ClassInfo> &class_vec)
{
    for (int i = 0; i < class_vec.size(); i++)
    {
        updateClassInfo(res_vec, class_vec, i + 1);
    }
    return;
}

// 比较选同一门课的两个学生的成绩，降序
bool compareStudentCourseByScore(const StudentCourse &lhs, const StudentCourse &rhs)
{
    return lhs.getStudentCourseScore() > rhs.getStudentCourseScore();
}

// 比较两个同班的学生的GPA，用于班内排名，升序
bool compareStudentByGPA(const StudentResults &lhs, const StudentResults &rhs)
{
    return lhs.GPA > rhs.GPA;
}

//
//
// 教师部分
//
//
// 显示教师登陆界面
int showTeacherLoginMenu(const std::vector<Teacher> &tch_vec, int &tch_obj)
{
    system("cls");
    std::string name, id;
    int flag = 0;
    std::cout << "------ Teacher Login Interface ------\n"
              << std::endl;
    std::cout << "Please input your name and teacher ID" << std::endl;
    std::cout << "Attention: only when they are correct and match can you successfully login\n"
              << std::endl;
    while (true)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Teacher ID: ";
        std::cin >> id;
        if (isTeacherIDExist(tch_vec, id) != -1 && isTeacherIDExist(tch_vec, id) == isTeacherNameExist(tch_vec, name) && isTeacherIDExist(tch_vec, id) == isTeacherExist(tch_vec, name, id))
        {
            tch_obj = isTeacherExist(tch_vec, name, id);
            std::cout << "\nSuccessful login! Welcome, " << tch_vec[tch_obj].getTeacherName() << "!" << std::endl;
            std::cout << "------ You are about to enter teacher interface... ------\n"
                      << std::endl;
            system("pause");
            return tch_obj;
            break;
        }
        else
            std::cout << "Login failed! Please check your name or teacher ID, or whether the two match\n"
                      << std::endl;
    }
    system("pause");
    return -1;
}

// 显示教师界面菜单
void showTeacherMenu(const std::vector<Teacher> &tch_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ":" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      1. Enter course grades                       *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      2. Modify course grades                      *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      3. Query your course grades                  *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      4. Query students grades                     *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      5. Query class grades                        *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      6. Query your personal information                     *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*      0. Exit the teacher interface                *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*                                                   *" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::cout << "\nPlease select the operation you want (press the number corresponding to the specific function):" << std::endl;
    return;
}

// 教师操作界面
void teacherMenuOperate(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj) // 教师界面进行的操作
{
    int select;
    int ret;
    while (true)
    {
        showTeacherMenu(tch_vec, tch_obj);
        std::cin >> select;
        switch (select)
        {
        case 1:
            teacherEnterResults(res_vec, tch_vec, crs_vec, class_vec, tch_obj);
            system("pause");
            break;
        case 2:
            teacherModifyResults(res_vec, tch_vec, crs_vec, class_vec, tch_obj);
            system("pause");
            break;
        case 3:
            teacherInquireCourseResults(res_vec, tch_vec, crs_vec, tch_obj);
            system("pause");
            break;
        case 4:
            teacherInquireStudentResults(res_vec, tch_vec, crs_vec, tch_obj);
            system("pause");
            break;
        case 5:
            teacherInquireClassResults(res_vec, tch_vec, crs_vec, class_vec, tch_obj);
            system("pause");
            break;
        case 6:
            teacherCheckInfo(tch_vec, crs_vec, tch_obj);
            system("pause");
            break;
        case 0:
            ret = returnToMainMenu();
            system("pause");
            system("cls");
            if (ret == 1)
            {
                return;
                break;
            }
            else
                break;
        default:
            std::cout << "Invalid input! Please input number again (0--6)" << std::endl;
            system("pause");
            break;
        }
    }
    return;
}

// 录入课程成绩
void teacherEnterResults(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ", you teach the course: " << crs_vec[tch_obj].getCourseName() << std::endl;
    int choice;
    std::cout << "You can enter grades in TWO ways:" << std::endl;
    std::cout << "1---Enter grades of student that select your course" << std::endl;
    std::cout << "2---Add new students to select your course and enter their grades" << std::endl;
    while (true)
    {
        std::cout << "Please input your choice (1 or 2): ";
        std::cin >> choice;
        if (choice == 1)
        {
            std::cout << "Here are students that select your course" << std::endl;
            int num = 0;
            for (auto &res : res_vec)
            {
                for (auto &s_c : res.stu_crs)
                {
                    if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName())
                    {
                        int score;
                        num++;
                        std::cout << num << ".  " << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << std::endl;
                        while (true)
                        {
                            std::cout << "Please input his/her course score (0--100): ";
                            std::cin >> score;
                            if (0 <= score && score <= 100)
                            {
                                s_c.setStudentCourseScore(score);
                                std::cout << "You have successfully entered his/her course score: " << score << std::endl;
                                std::cout << "--- Next student ---" << std::endl;
                                system("pause");
                                break;
                            }
                            else
                                std::cout << "Invalid input! Please input again" << std::endl;
                        }
                        break;
                    }
                }
            }
            std::cout << "You have completed entry of grades for all students!" << std::endl;
            return;
        }

        else if (choice == 2)
        {
            std::cout << "Next, you will add a new student to select your course..." << std::endl;
            std::string name, id;
            int class_num;
            while (true)
            {
                StudentResults temp_res;
                StudentCourse temp_sc;
                std::cout << "Please input student name: ";
                std::cin >> name;
                std::cout << "Please input student ID: ";
                std::cin >> id;
                if (isStudentIDExist(res_vec, id) != -1)
                {
                    std::cout << "This student ID have already existed! Please input again" << std::endl;
                    continue;
                }
                std::cout << "Please input student class (A new class will be created if not exist): ";
                std::cin >> class_num;
                if (1 <= class_num && class_num <= class_vec.size())
                {
                    class_vec[class_num - 1].stu_amount++;
                }
                else
                {
                    std::cout << "There are " << class_vec.size() << " classes, now a new class " << class_vec.size() + 1 << " will be created" << std::endl;
                    class_num = class_vec.size() + 1;
                    ClassInfo temp_class = {class_num, 1, 0};
                    class_vec.push_back(temp_class);
                }
                auto &tch = tch_vec[tch_obj];
                auto &crs = crs_vec[tch_obj];
                temp_sc.setStudentCourseInfo(name, id, class_num, tch.getTeacherName(), tch.getTeacherID(), tch.getTeacherCollege(), crs.getCourseName(), crs.getCourseCredit(), crs.getCourseIsPF(), 100);
                temp_res.stu.setStudentInfo(name, id, class_num);
                temp_res.PF_flag = -1;
                temp_res.GPA = 0;
                temp_res.ranking = 1;
                temp_res.stu_crs.push_back(temp_sc);
                int score;
                while (true)
                {
                    std::cout << "Please input his/her course score (0--100): ";
                    std::cin >> score;
                    if (0 <= score && score <= 100)
                    {
                        temp_res.stu_crs[0].setStudentCourseScore(score);
                        res_vec.push_back(temp_res);
                        updateStudentResults(res_vec, res_vec.size() - 1); // 此时学生是最后一个
                        updateClassInfo(res_vec, class_vec, class_num - 1);
                        updateAllClassInfo(res_vec, class_vec);
                        std::cout << "You have successfully entered his/her course score: " << score << std::endl;
                        int next;
                        std::cout << "Press 1 to continue entering, otherwise you will exit: ";
                        std::cin >> next;
                        if (next == 1)
                        {
                            std::cout << "You have chose to continue entering!\n"
                                      << std::endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            std::cout << "------ You are about to exit ------" << std::endl;
                            return;
                        }
                    }
                    else
                        std::cout << "Invalid score! Not between 0 and 100" << std::endl;
                }
            }
        }

        else
        {
            int next;
            std::cout << "Invalid input! Press 1 to continue entering, otherwise you will exit: ";
            std::cin >> next;
            if (next == 1)
            {
                std::cout << "You have chose to continue entering!" << std::endl;
                system("pause");
                std::cout << std::endl;
            }
            else
            {
                std::cout << "------ You are about to exit ------" << std::endl;
                return;
            }
        }
    }
    return;
}

// 修改课程成绩
void teacherModifyResults(std::vector<StudentResults> &res_vec, std::vector<Teacher> &tch_vec, std::vector<Course> &crs_vec, std::vector<ClassInfo> &class_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ", you teach the course: " << crs_vec[tch_obj].getCourseName() << std::endl;
    std::cout << "Here are student that select your course and their grades:\n"
              << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "number\tName\tStudent ID\tClass" << std::endl;
    int num = 0;
    std::vector<StudentCourse> temp_vec;
    temp_vec.clear();
    for (const auto &res : res_vec)
    {
        for (const auto &s_c : res.stu_crs)
        {
            if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName())
            {
                temp_vec.push_back(s_c);
                num++;
                std::cout << num << ".\t" << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << "\t\t" << res.stu.getStudentClass() << std::endl;
                break;
            }
        }
    }
    std::cout << "-------------------------------------" << std::endl;
    int choice;
    while (true)
    {
        std::cout << "Please select the number before the student's name, and then modify grades: ";
        std::cin >> choice;
        if (1 <= choice && choice <= num)
        {
            std::cout << "You select " << choice << ".  " << temp_vec[choice - 1].getStudentName() << std::endl;
            std::cout << "His/Her current course score is: " << temp_vec[choice - 1].getStudentCourseScore() << std::endl;
            int score;
            int stuobj = isStudentExist(res_vec, temp_vec[choice - 1].getStudentName(), temp_vec[choice - 1].getStudentID());
            int crsobj = isStudentSelectCourse(res_vec, stuobj, temp_vec[choice - 1].getStudentCourseName());
            while (true)
            {
                std::cout << "Please input the modified score: ";
                std::cin >> score;
                if (0 <= score && score <= 100)
                {
                    int sure;
                    std::cout << "Are you sure to modify from " << temp_vec[choice - 1].getStudentCourseScore() << " to " << score << "?" << std::endl;
                    std::cout << "1---Yes  0---No: ";
                    std::cin >> sure;
                    while (true)
                    {
                        if (sure == 1)
                        {
                            std::cout << "Successful modification! You have modified it from " << temp_vec[choice - 1].getStudentCourseScore() << " to " << score << std::endl;
                            res_vec[stuobj].stu_crs[crsobj].setStudentCourseScore(score);
                            updateStudentResults(res_vec, stuobj);
                            updateClassInfo(res_vec, class_vec, res_vec[stuobj].stu.getStudentClass());
                            updateAllClassInfo(res_vec, class_vec);
                            break;
                        }
                        else if (sure == 0)
                        {
                            std::cout << "You have canceled the modification!" << std::endl;
                            break;
                        }
                        else
                            std::cout << "Invalid input! Please input again" << std::endl;
                    }
                    int next;
                    std::cout << "Press 1 to continue modifying, otherwise you will exit: ";
                    std::cin >> next;
                    if (next == 1)
                    {
                        std::cout << "You have chose to continue modifying!" << std::endl;
                        system("pause");
                        std::cout << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "------ You are about to exit ------" << std::endl;
                        return;
                    }
                }
                else
                    std::cout << "Invalid score! Not between 0 and 100" << std::endl;
            }
        }
        else
            std::cout << "Invalid input! Please input again" << std::endl;
    }
    return;
}

// 查看该课程所有学生成绩,老师只能看见自己教的课的成绩
void teacherInquireCourseResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ", you teach the course: " << crs_vec[tch_obj].getCourseName() << std::endl;
    std::cout << "Here are this course grades: (non-ranking order)\n"
              << std::endl;
    std::cout << "Ranking\tName\tID\tScore\tGrade\tGPA" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::vector<StudentCourse> temp_vec;
    temp_vec.clear();
    for (const auto &res : res_vec)
    {
        for (const auto &sc : res.stu_crs)
        {
            if (sc.getCourseName() == crs_vec[tch_obj].getCourseName())
            {
                temp_vec.push_back(sc);
            }
        }
    }
    std::sort(temp_vec.begin(), temp_vec.end(), compareStudentCourseByScore);
    int num = 1;
    for (const auto &s_c : temp_vec)
    {
        std::cout << num << "\t" << s_c.getStudentName() << "\t" << s_c.getStudentID() << "\t" << s_c.getStudentCourseScore() << "\t";
        std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
        num++;
    }
    std::cout << "-------------------------------------------\n"
              << std::endl;
    std::cout << "To modify grades, please go to function 2" << std::endl;
    return;
}

// 查看某个学生各门成绩，老师能看见所有学生的成绩
void teacherInquireStudentResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ", you teach the course: " << crs_vec[tch_obj].getCourseName() << std::endl;
    std::cout << "You can view the grades of all students by name or student ID." << std::endl;
    std::cout << "To query by name, press 1. To query by student ID, press 2. To exit, press 0" << std::endl;
    std::cout << "The name query results may not be unique, but the student ID query result is unique." << std::endl;
    int choice, exit;
    while (true)
    {
        std::cout << "\nPlease input you choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            std::string name;
            std::cout << "Please input student name: ";
            std::cin >> name;
            std::cout << "Here are the students you want:\n"
                      << std::endl;
            std::cout << "*********************************************" << std::endl;
            for (const auto &res : res_vec)
            {
                if (res.stu.getStudentName() == name)
                {
                    std::cout << "*  Name: " << name << "      Student ID: " << res.stu.getStudentID() << "      Class: " << res.stu.getStudentClass() << std::endl;
                    std::cout << "*  GPA: " << res.GPA << "      Class ranking: " << res.ranking << std::endl;
                    std::cout << "*  Here are his/her all course grades:" << std::endl;
                    std::cout << "*  " << std::endl;
                    std::cout << "*  Course\tScore\tGrade\tGPA" << std::endl;
                    std::cout << "*  ---------------------------" << std::endl;
                    for (const auto &s_c : res.stu_crs)
                    {
                        std::cout << "*  " << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
                        std::cout << Grade[s_c.getStudentCourseGrade()] << "\t" << s_c.getStudentCourseGPA() << "\t" << std::endl;
                    }
                    std::cout << "*  ---------------------------" << std::endl;
                }
            }
            std::cout << "*  " << std::endl;
            std::cout << "**********************************************\n"
                      << std::endl;
            std::cout << "Press 1 to continue query, otherwise you will exit: ";
            std::cin >> exit;
            if (exit == 1)
            {
                std::cout << "You have chose to continue query!" << std::endl;
                system("pause");
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You have chose: " << exit << std::endl;
                std::cout << "------ You are about to exit ------" << std::endl;
                return;
            }
        }

        else if (choice == 2)
        {
            std::string id;
            std::cout << "Please input student ID: ";
            std::cin >> id;
            std::cout << "Here are the students you want:\n"
                      << std::endl;
            std::cout << "*****************************************" << std::endl;
            for (const auto &res : res_vec)
            {
                if (res.stu.getStudentName() == id)
                {
                    std::cout << "Name: " << res.stu.getStudentName() << "      Student ID: " << id << "      Class: " << res.stu.getStudentClass() << std::endl;
                    std::cout << "GPA: " << res.GPA << "      Class ranking: " << res.ranking << std::endl;
                    std::cout << "Here are his/her all course grades: " << std::endl;
                    std::cout << "Course\tScore\tGrade\tGPA" << std::endl;
                    std::cout << "---------------------------" << std::endl;
                    for (const auto &s_c : res.stu_crs)
                    {
                        std::cout << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
                        std::cout << Grade[s_c.getStudentCourseGrade()] << "\t" << s_c.getStudentCourseGPA() << "\t" << std::endl;
                    }
                    std::cout << "---------------------------\n"
                              << std::endl;
                }
            }
            std::cout << "*****************************************\n"
                      << std::endl;
            std::cout << "Press 1 to continue query, otherwise you will exit: ";
            std::cin >> exit;
            if (exit == 1)
            {
                std::cout << "You have chose to continue query!" << std::endl;
                system("pause");
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You have chose: " << exit << std::endl;
                std::cout << "------ You are about to exit ------" << std::endl;
                return;
            }
        }

        else if (choice == 0)
        {
            std::cout << "You have chose: 0" << std::endl;
            std::cout << "------ You are about to exit ------" << std::endl;
            break;
            return;
        }
        else
        {
            std::cout << "Invalid input! Please input again" << std::endl;
        }
    }
    return;
}

// 查看班级成绩，老师能查看所有班级的成绩
void teacherInquireClassResults(const std::vector<StudentResults> &res_vec, const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const std::vector<ClassInfo> &class_vec, const int &tch_obj)
{
    system("cls");
    std::cout << "Dear " << tch_vec[tch_obj].getTeacherName() << ", you teach the course: " << crs_vec[tch_obj].getCourseName() << std::endl;
    std::cout << "You can view the grades of all classes." << std::endl;
    while (true)
    {
        int class_num;
        std::cout << "Please select class: 1--" << class_vec.size() << " : ";
        std::cin >> class_num;
        if (1 <= class_num && class_num <= class_vec.size())
        {
            std::cout << "\nYou select class: " << class_num << std::endl;
            std::cout << "Here are the students grades of class " << class_num << "\n\n";
            std::cout << "Name\tGPA\tClass ranking" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::vector<StudentResults> temp_vec;
            temp_vec.clear();
            for (const auto &res : res_vec)
            {
                if (res.stu.getStudentClass() == class_num)
                    temp_vec.push_back(res);
            }
            std::sort(temp_vec.begin(), temp_vec.end(), compareStudentByGPA);
            for (const auto &temp : temp_vec)
            {
                std::cout << temp.stu.getStudentName() << "\t" << temp.GPA << "\t" << temp.ranking << std::endl;
            }
            std::cout << "-----------------------------\n"
                      << std::endl;
            std::cout << "Class size: " << class_vec[class_num - 1].stu_amount << "  average GPA: " << class_vec[class_num - 1].aver_GPA << "\n\n";
            int exit;
            std::cout << "Press 1 to continue query, otherwise you will exit: ";
            std::cin >> exit;
            if (exit == 1)
            {
                std::cout << "You have chose to continue query!" << std::endl;
                system("pause");
                std::cout << std::endl;
            }
            else
            {
                std::cout << "You have chose: " << exit << std::endl;
                std::cout << "------ You are about to exit ------" << std::endl;
                return;
            }
        }
        else
            std::cout << "Invalid input! Not between 1--" << class_vec.size() << std::endl;
    }
    return;
}

void teacherCheckInfo(const std::vector<Teacher> &tch_vec, const std::vector<Course> &crs_vec, const int &tch_obj)
{
    system("cls");
    tch_vec[tch_obj].displayInfo();
    crs_vec[tch_obj].displayInfo();
    return;
}