#define _CRT_SECURE_NO_WARNINGS
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
const int MAX_STU_NUM = 10000; //能够录入的最大学生数目
const int MAX_STRLEN = 1024; //该系统中出现的字符串最大长度
const std::string College[47] = { //院系编号
	"电子系", // 0
	"建筑学院", // 1
	"土木系", // 2
	"水利系", // 3
	"环境学院", // 4
	"机械系", // 5
	"精仪系", // 6
	"能动系", // 7
	"车辆学院", // 8
	"工业工程系", // 9
	"电机系", // 10
	"计算机系", // 11
	"自动化系", // 12
	"软件学院", // 13
	"集成电路学院", // 14
	"航院", // 15
	"工程物理系", // 16
	"化工系", // 17
	"材料学院", // 18
	"数学系", // 19
	"物理系", // 20
	"化学系", // 21
	"生命学院", // 22
	"地学系", // 23
	"交叉信息院", // 24
	"经管学院", // 25
	"公管学院", // 26
	"金融学院", // 27
	"外文系", // 28
	"法学院", // 29
	"新闻学院", // 30
	"马克思主义学院", // 31
	"人文学院", // 32
	"社科学院", // 33
	"美术学院", // 34
	"卫健学院", // 35
	"医学院", // 36
	"药学院", // 37
	"天文系", // 38
	"网络研究院", // 39
	"语言中心", // 40
	"新雅书院", // 41
	"未央书院", // 42
	"致理书院", // 43
	"日新书院", // 44
	"行健书院", // 45
	"为先书院", // 46
};
const std::string Grade[13] = { "A+","A","A-","B+","B","B-","C+","C","C-","D+","D","P","F" };
//程序开始运行时从文件中读取信息存入容器中，结束时将新的信息写入文件中保存
const std::string STUDENT_FILE_PATH = "D:\\ASUS\\Desktop\\stu_info.csv";
const std::string TEACHER_FILE_PATH = "D:\\ASUS\\Desktop\\tch_info.csv";


//抽象类：人员
class Person
{
public:
	virtual void displayInfo()const = 0;
	virtual ~Person() {};
private:
	std::string name = "\0";
	std::string id = "\0";;
};


//记录学生基本信息的Student类
class Student :virtual public Person
{
private:
	std::string stu_name;//姓名
	std::string stu_id;//学号
	int stu_class;//班级
public:
	Student(std::string stu_name = "\0", std::string stu_id = "\0", int stu_class = 0)
	{
		this->stu_name = stu_name;
		this->stu_id = stu_id;
		this->stu_class = stu_class;
	}
	Student(const Student& other)
	{
		this->stu_name = other.stu_name;
		this->stu_id = other.stu_id;
		this->stu_class = other.stu_class;
	}
	virtual ~Student() {};
	void displayInfo()const override//打印学生信息
	{
		std::cout << "\t\t学生信息如下：" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  姓名：" << stu_name << "  学号：" << stu_id << std::endl;
		std::cout << "\t\t*  班级：" << stu_class << std::endl;
		std::cout << "\t\t***************************************************\n\n";
		return;
	}
	void setStudentInfo(std::string stu_name = "\0", std::string stu_id = "\0", int stu_class = 0)
	{
		this->stu_name = stu_name;
		this->stu_id = stu_id;
		this->stu_class = stu_class;
		return;
	}//修改全部信息
	void setStudentName(std::string new_name = "\0") {
		this->stu_name = new_name;
		return;
	} //修改学生姓名
	void setStudentID(std::string new_id = "\0") {
		this->stu_id = new_id;
		return;
	} //修改学生学号
	void setStudentClass(const int new_class = 0) {
		this->stu_class = new_class;
		return;
	} //修改学生班级
	std::string getStudentName()const { return this->stu_name; }
	std::string getStudentID()const { return this->stu_id; }
	int getStudentClass()const { return this->stu_class; }
};


//记录老师基本信息的Teacher类
class Teacher :virtual public Person
{
private:
	std::string tch_name;//老师姓名
	std::string tch_id;//老师工号
	int tch_college;//老师院系编号
public:
	Teacher(std::string tch_name = "\0", std::string tch_id = "\0", int tch_college = 0)
	{
		this->tch_name = tch_name;
		this->tch_id = tch_id;
		this->tch_college = tch_college;
	}
	Teacher(const Teacher& other)
	{
		this->tch_name = other.tch_name;
		this->tch_id = other.tch_id;
		this->tch_college = other.tch_college;
	}
	virtual ~Teacher() {};
	void displayInfo()const override//打印教师信息
	{
		std::cout << "\t\t老师信息如下：" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  姓名：" << tch_name << "  工号：" << tch_id << std::endl;
		std::cout << "\t\t*  院系：" << College[tch_college] << std::endl;
		std::cout << "\t\t***************************************************\n\n";
	}
	void setTeacherInfo(std::string tch_name = "\0", std::string tch_id = "\0", int tch_college = 0)
	{
		this->tch_name = tch_name;
		this->tch_id = tch_id;
		this->tch_college = tch_college;
	} //修改教师信息
	void setTeacherName(std::string new_name = "\0") {
		this->tch_name = new_name;
		return;
	} //修改教师姓名
	void setTeacherID(std::string new_id = "\0") {
		this->tch_id = new_id;
		return;
	} //修改教师工号
	void setTeacherCollege(int new_college = 0) {
		this->tch_college = new_college;
		return;
	} //修改教师院系
	std::string getTeacherName()const { return this->tch_name; }
	std::string getTeacherID()const { return this->tch_id; }
	int getTeacherCollege()const { return this->tch_college; }
};


//记录课程基本信息的Course类
class Course :public Teacher
{
private:
	std::string crs_name;//课程名
	int crs_credit;//课程学分
	bool isPF;//是否记PF
public:
	Course(std::string crs_name = "\0", int crs_credit = 0, bool isPF = false)
	{
		this->crs_name = crs_name;
		this->crs_credit = crs_credit;
		this->isPF = isPF;
	}
	Course(const Course& other) :crs_name(other.crs_name), crs_credit(other.crs_credit), isPF(other.isPF) {};
	virtual ~Course() {};
	void displayInfo()const override
	{
		std::cout << "\t\t课程信息如下：" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  课程名称：" << crs_name << "  开课教师：" << Teacher::getTeacherName() << std::endl;
		std::cout << "\t\t*  课程学分：" << crs_credit << "  学时：" << crs_credit * 16 << std::endl;
		std::cout << "\t\t*  是否为P/F：" << (isPF ? "是（Yes）" : "否（No）") << std::endl;
		std::cout << "\t\t***************************************************\n\n";
	}
	void setCourseInfo(const Teacher& tch, std::string crs_name = "\0", int crs_credit = 0, bool isPF = false)
	{
		Teacher::operator=(tch);
		this->crs_name = crs_name;
		this->crs_credit = crs_credit;
		this->isPF = isPF;
	} //修改课程信息
	void setCourseName(std::string new_name = "\0") {
		this->crs_name = new_name;
		return;
	} //修改课程名称
	void setCourseCredit(const int new_credit = 0) {
		this->crs_credit = new_credit;
		return;
	} //修改课程学分
	void setCourseIsPF(const bool new_isPF = false) {
		this->isPF = new_isPF;
		return;
	} //修改课程是否记PF
	//修改基类中的成员
	void setTeacherName(std::string new_name) { Teacher::setTeacherName(new_name); }
	void setTeacherID(std::string new_id) { Teacher::setTeacherID(new_id); }
	void setTeacherCollege(int new_college) { Teacher::setTeacherCollege(new_college); }
	//获取成员信息
	std::string getCourseName()const { return this->crs_name; }
	int getCourseCredit()const { return this->crs_credit; }
	bool getCourseIsPF()const { return this->isPF; }
	//在派生类中获取基类的信息
	std::string getTeacherName()const { return Teacher::getTeacherName(); }
	std::string getTeacherID()const { return Teacher::getTeacherID(); }
	int getTeacherCollege()const { return Teacher::getTeacherCollege(); }
};


//记录学生+课程的成绩类
class StudentCourse :public Student, public Course
{
private:
	std::string crs;//课程名称
	int score;//百分制成绩
	double gpa;//课程绩点
	int grade;//课程等级
public:
	StudentCourse(std::string crs = "\0", int score = 0, double gpa = 0, int grade = 0)
	{
		this->crs = crs;
		this->score = score;
		if (Course::getCourseIsPF() == true) {
			if (60 <= score && score <= 100) {
				this->gpa = 4.0;//4.0代替P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0代替F
				this->grade = 12;//"F"
			}
		}
		else {
			if (score == 100) {
				this->gpa = 4.0;
				this->grade = 0;
			}
			else if (95 <= score && score <= 99) {
				this->gpa = 4.0;
				this->grade = 1;
			}
			else if (90 <= score && score <= 94) {
				this->gpa = 4.0;
				this->grade = 2;
			}
			else if (85 <= score && score <= 89) {
				this->gpa = 3.6;
				this->grade = 3;
			}
			else if (80 <= score && score <= 84) {
				this->gpa = 3.3;
				this->grade = 4;
			}
			else if (77 <= score && score <= 79) {
				this->gpa = 3.0;
				this->grade = 5;
			}
			else if (73 <= score && score <= 76) {
				this->gpa = 2.6;
				this->grade = 6;
			}
			else if (70 <= score && score <= 72) {
				this->gpa = 2.3;
				this->grade = 7;
			}
			else if (67 <= score && score <= 69) {
				this->gpa = 2.0;
				this->grade = 8;
			}
			else if (63 <= score && score <= 66) {
				this->gpa = 1.6;
				this->grade = 9;
			}
			else if (60 <= score && score <= 62) {
				this->gpa = 1.3;
				this->grade = 10;
			}
			else {
				this->gpa = 0.0;
				this->grade = 12;
			}
		}
	}
	StudentCourse(const StudentCourse& other)
	{
		this->crs = other.crs;
		this->score = other.score;
		this->gpa = other.gpa;
		this->grade = other.grade;
	}
	virtual ~StudentCourse() {};
	void displayInfo()const override
	{
		std::cout << "\t\t" << crs << "成绩：" << score << "  学分：" << Course::getCourseCredit() << std::endl;
		std::cout << "\t\t" << "GPA=" << gpa << "  等级：" << Grade[grade] << std::endl;
		return;
	}
	void setStudentCourseInfo(const Student& stu, const Course& crs0, std::string crs = "\0", int score = 0, double gpa = 0, int grade = 0)
	{
		Student::operator=(stu);
		Course::operator=(crs0);
		this->crs = crs;
		this->score = score;
		if (Course::getCourseIsPF() == true) {
			if (60 <= score && score <= 100) {
				this->gpa = 4.0;//4.0代替P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0代替F
				this->grade = 12;//"F"
			}
		}
		else {
			if (score == 100) {
				this->gpa = 4.0;
				this->grade = 0;
			}
			else if (95 <= score && score <= 99) {
				this->gpa = 4.0;
				this->grade = 1;
			}
			else if (90 <= score && score <= 94) {
				this->gpa = 4.0;
				this->grade = 2;
			}
			else if (85 <= score && score <= 89) {
				this->gpa = 3.6;
				this->grade = 3;
			}
			else if (80 <= score && score <= 84) {
				this->gpa = 3.3;
				this->grade = 4;
			}
			else if (77 <= score && score <= 79) {
				this->gpa = 3.0;
				this->grade = 5;
			}
			else if (73 <= score && score <= 76) {
				this->gpa = 2.6;
				this->grade = 6;
			}
			else if (70 <= score && score <= 72) {
				this->gpa = 2.3;
				this->grade = 7;
			}
			else if (67 <= score && score <= 69) {
				this->gpa = 2.0;
				this->grade = 8;
			}
			else if (63 <= score && score <= 66) {
				this->gpa = 1.6;
				this->grade = 9;
			}
			else if (60 <= score && score <= 62) {
				this->gpa = 1.3;
				this->grade = 10;
			}
			else {
				this->gpa = 0.0;
				this->grade = 12;
			}
		}
	}
	void setStudentCourseName(std::string new_name = "\0")
	{
		this->crs = new_name;
	}
	void setStudentCourseScore(int new_score = 0)
	{
		this->score = new_score;
		if (Course::getCourseIsPF() == true) {
			if (60 <= score && score <= 100) {
				this->gpa = 4.0;//4.0代替P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0代替F
				this->grade = 12;//"F"
			}
		}
		else {
			if (score == 100) {
				this->gpa = 4.0;
				this->grade = 0;
			}
			else if (95 <= score && score <= 99) {
				this->gpa = 4.0;
				this->grade = 1;
			}
			else if (90 <= score && score <= 94) {
				this->gpa = 4.0;
				this->grade = 2;
			}
			else if (85 <= score && score <= 89) {
				this->gpa = 3.6;
				this->grade = 3;
			}
			else if (80 <= score && score <= 84) {
				this->gpa = 3.3;
				this->grade = 4;
			}
			else if (77 <= score && score <= 79) {
				this->gpa = 3.0;
				this->grade = 5;
			}
			else if (73 <= score && score <= 76) {
				this->gpa = 2.6;
				this->grade = 6;
			}
			else if (70 <= score && score <= 72) {
				this->gpa = 2.3;
				this->grade = 7;
			}
			else if (67 <= score && score <= 69) {
				this->gpa = 2.0;
				this->grade = 8;
			}
			else if (63 <= score && score <= 66) {
				this->gpa = 1.6;
				this->grade = 9;
			}
			else if (60 <= score && score <= 62) {
				this->gpa = 1.3;
				this->grade = 10;
			}
			else {
				this->gpa = 0.0;
				this->grade = 12;
			}
		}
	}
	std::string getStudentCourseName()const { return this->crs; }
	int getStudentCourseScore()const { return this->score; }
	double getStudentCourseGPA()const { return this->gpa; }
	int getStudentCourseGrade()const { return this->grade; }
	//在派生类中修改基类的信息
	void setStudentName(std::string new_name) { Student::setStudentName(new_name); }
	void setStudentID(std::string new_id) { Student::setStudentID(new_id); }
	void setStudentClass(int new_class) { Student::setStudentClass(new_class); }
	void setTeacherName(std::string new_name) { Teacher::setTeacherName(new_name); }
	void setTeacherID(std::string new_id) { Teacher::setTeacherID(new_id); }
	void setTeacherCollege(int new_college) { Teacher::setTeacherCollege(new_college); }
	void setCourseName(std::string new_name) { Course::setCourseName(new_name); }
	void setCourseCredit(int new_credit) { Course::setCourseCredit(new_credit); }
	void setCourseIsPF(bool new_isPF) { Course::setCourseIsPF(new_isPF); }
	//在派生类中获取基类的信息
	std::string getStudentName()const { return Student::getStudentName(); }
	std::string getStudentID()const { return Student::getStudentID(); }
	int getStudentClass()const { return Student::getStudentClass(); }
	std::string getTeacherName()const { return Teacher::getTeacherName(); }
	std::string getTeacherID()const { return Teacher::getTeacherID(); }
	int getTeacherCollege()const { return Teacher::getTeacherCollege(); }
	std::string getCourseName()const { return Course::getCourseName(); }
	int getCourseCredit()const { return Course::getCourseCredit(); }
	bool getCourseIsPF()const { return Course::getCourseIsPF(); }
};


struct StudentResults //结构体，记录单个学生的信息、多门课程、均绩、排名
{
	Student stu;
	std::vector<StudentCourse> stu_crs;
	double GPA = 0;
	int ranking = 1;
	//标记学生是否PF了一门课，若没有则自动初始为-1，若有则赋值为该课程在stu_crs中的下标
	int PF_flag = -1;
};

struct ClassInfo
{
	int class_num;//班号
	int stu_amount;//学生数量
	double aver_GPA;//班级均绩
};


//全局变量
std::vector<StudentResults> res_vec;
std::vector<Teacher> tch_vec;
std::vector<Course> crs_vec;
std::vector<ClassInfo> class_vec;

int stu_obj = 0;//定位对应学生
int tch_obj = 0;//定位对应教师
int crs_obj = 0;//定位对应课程
int class_obj = 0;



//函数声明
void readFromStudentInfoFile(const std::string& file_name, std::vector<StudentResults>& res_vec);
void readFromTeacherInfoFile(const std::string& file_name, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec);
void writeIntoStudentInfoFile(const std::string& file_name, const std::vector<StudentResults>& res_vec);
void wrtieIntoTeacherInfoFile(const std::string& file_name, const std::vector<Course>& crs_vec);
void initialiseSystem(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec);
void shutDownSystem(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec);
void showMainMenu();//显示主页面菜单
void returnToMainMenu();//返回主菜单

int showStudentLogInMenu(const std::vector<StudentResults>& res_vec, int& stu_obj);//显示学生登陆界面
void showStudentMenu(const std::vector<StudentResults>& res_vec, const int& stu_obj);//显示学生菜单界面
void studentMenuOperate(std::vector<StudentResults>& res_vec, const int& stu_obj);//学生进行操作
void studentInquireSingleResult(const std::vector<StudentResults>& res_vec, const int& stu_obj);//查询单科成绩
void studentInquireAllResults(const std::vector<StudentResults>& res_vec, const int& stu_obj);//查询所有成绩
void studentSelectOneToPF(std::vector<StudentResults>& res_vec, const int& stu_obj);//选择一门PF
void studentInquireClassRanking(const std::vector<StudentResults>& res_vec, const int& stu_obj);//查询班级排名
void updateStudentResults(std::vector<StudentResults>& res_vec, const int& stu_obj);//更新学生成绩
void updateClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec, const int& class_num);
void updateAllClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec);

int showTeacherLogInMenu(const std::vector<Teacher>& tch_vec, int& tch_obj);//显示教师登陆界面
void showTeacherMenu(const std::vector<Teacher>& tch_vec, const int& tch_obj);//显示教师菜单界面
void teacherMenuOperate(const std::vector<Teacher>& tch_vec, const int& tch_obj);//教师进行操作
void teacherEnterResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj);
void teacherModifyResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj);
void teacherInquireCourseResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj);
void teacherInquireStudentResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj);
void teacherInquireClassResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const std::vector<ClassInfo>& class_vec, const int& tch_obj);

int isStudentExist(const std::vector<StudentResults>& res_vec, const std::string& name, const std::string& id);
bool isStudentNameExist(const std::vector<StudentResults>& res_vec, const std::string& name);
int isStudentIDExist(const std::vector<StudentResults>& res_vec, const std::string& id);
int isTeacherExist(const std::vector<Teacher>& tch_vec, const std::string& name, const std::string& id);
int isTeacherNameExist(const std::vector<Teacher>& tch_vec, const std::string& name);
int isTeacherIDExist(const std::vector<Teacher>& tch_vec, const std::string& id);
int isCourseExist(const std::vector<Course>& crs_vec, const std::string& name);
int isStudentSelectCourse(const std::vector<StudentResults>& res_vec, const int& stu_obj, const std::string& name);

//运算符重载
bool operator>(const StudentResults& lhs, const StudentResults& rhs);
bool operator>=(const StudentResults& lhs, const StudentResults& rhs);
bool operator<(const StudentResults& lhs, const StudentResults& rhs);
bool operator<=(const StudentResults& lhs, const StudentResults& rhs);
bool operator==(const StudentResults& lhs, const StudentResults& rhs);
bool operator!=(const StudentResults& lhs, const StudentResults& rhs);

bool operator>(const StudentCourse& lhs, const StudentCourse& rhs);
bool operator>=(const StudentCourse& lhs, const StudentCourse& rhs);
bool operator<(const StudentCourse& lhs, const StudentCourse& rhs);
bool operator<=(const StudentCourse& lhs, const StudentCourse& rhs);
bool operator==(const StudentCourse& lhs, const StudentCourse& rhs);
bool operator!=(const StudentCourse& lhs, const StudentCourse& rhs);

bool compareStudentCourseByScore(const StudentCourse& lhs, const StudentCourse& rhs);
bool compareStudentByGPA(const StudentResults& lhs, const StudentResults& rhs);
//函数声明结束



//函数定义
// 
// 
//从文件中读取学生信息
void readFromStudentInfoFile(const std::string& file_name, std::vector<StudentResults>& res_vec)
{
	std::ifstream stu_file(file_name, std::ios_base::in);
	std::vector<StudentCourse> sc_vec;
	std::vector<Student> stu_vec;

	res_vec.clear();
	std::string line;
	if (!stu_file.is_open()) {
		std::cerr << "\t\tThe initialising process ran into a problem and the system needs to restart" << std::endl;
		std::cerr << "\t\tDetails: Failed to open the file " << file_name << std::endl;
		exit(1);
	}
	while (std::getline(stu_file, line)) {
		std::stringstream ss(line);
		std::string stu_name, stu_id, stu_class, tch_name, tch_id, tch_college;
		std::string crs_name, crs_credit, isPF, score, gpa, grade;

		if (std::getline(ss, stu_name, ',') &&
			std::getline(ss, stu_id, ',') &&
			std::getline(ss, stu_class, ',') &&
			std::getline(ss, tch_name, ',') &&
			std::getline(ss, tch_id, ',') &&
			std::getline(ss, tch_college, ',') &&
			std::getline(ss, crs_name, ',') &&
			std::getline(ss, crs_credit, ',') &&
			std::getline(ss, isPF, ',') &&
			std::getline(ss, score, ',') &&
			std::getline(ss, gpa, ',') &&
			std::getline(ss, grade))
		{
			//字符串类型需要转换为整数、浮点数和布尔值
			int stu_class0 = std::stoi(stu_class);
			int tch_college0 = std::stoi(tch_college);
			int crs_credit0 = std::stoi(crs_credit);
			bool isPF0 = (isPF == "1");
			int score0 = std::stoi(score);
			double gpa0 = std::stod(gpa);
			int grade0 = std::stoi(grade);

			Student stu(stu_name, stu_id, stu_class0);
			Teacher tch(tch_name, tch_id, tch_college0);
			Course crs;
			crs.setCourseInfo(tch, crs_name, crs_credit0, isPF0);
			StudentCourse s_c;
			s_c.setStudentCourseInfo(stu, crs, crs_name, score0, gpa0, grade0);
			int flag = 0;
			for (const auto& temp : stu_vec) {
				if (temp.getStudentName() == stu_name && temp.getStudentID() == stu_id)
					flag = 1;
			}
			if (flag == 0) {
				stu_vec.push_back(stu);
			}
			sc_vec.push_back(s_c);
		}
	}
	for (const auto& temp : stu_vec) {
		StudentResults res;
		res.stu.operator=(temp);
		for (const auto& temp0 : sc_vec) {
			if (temp.getStudentName() == temp0.getStudentName() && temp.getStudentID() == temp0.getStudentID()) {
				res.stu_crs.push_back(temp0);
			}
		}
		res.PF_flag = -1;
		res_vec.push_back(res);
	}
	stu_file.close();
	return;
}


void readFromTeacherInfoFile(const std::string& file_name, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec)
{
	std::ifstream tch_file(file_name, std::ios_base::in);
	std::string line;
	std::stringstream ss(line);
	std::string tch_name, tch_id, tch_college, crs_name, crs_credit, isPF;
	tch_vec.clear();
	crs_vec.clear();

	if (!tch_file.is_open()) {
		std::cerr << "\t\tThe initialising process ran into a problem and the system needs to restart" << std::endl;
		std::cerr << "\t\tDetails: Failed to open the file: " << file_name << std::endl;
		exit(1);
	}
	if (std::getline(ss, tch_name, ',') &&
		std::getline(ss, tch_id, ',') &&
		std::getline(ss, tch_college, ',') &&
		std::getline(ss, crs_name, ',') &&
		std::getline(ss, crs_credit, ',') &&
		std::getline(ss, isPF, ','))
	{
		//字符串类型需要转换为整数、浮点数和布尔值
		int tch_college0 = std::stoi(tch_college);
		int crs_credit0 = std::stoi(crs_credit);
		bool isPF0 = (isPF == "true" || isPF != "0");
		Teacher tch(tch_name, tch_id, tch_college0);
		Course crs;
		crs.setCourseInfo(tch, crs_name, crs_credit0, isPF0);
		tch_vec.push_back(tch);
		crs_vec.push_back(crs);
	}
	tch_file.close();
	return;
}


void writeIntoStudentInfoFile(const std::string& file_name, const std::vector<StudentResults>& res_vec)
{
	std::ofstream stu_file(file_name, std::ios_base::out | std::ios_base::trunc);
	if (!stu_file.is_open()) {
		std::cerr << "\t\tThe shutdown process ran into a problem" << std::endl;
		std::cerr << "\t\tFailed to open the file: " << file_name << std::endl;
		exit(1);

	}
	for (const auto& res : res_vec) {
		for (const auto& s_c : res.stu_crs) {
			std::ostringstream line;
			line << s_c.getStudentName() << ',' << s_c.getStudentID() << ',' << std::to_string(s_c.getStudentClass()) << ',';
			line << s_c.getTeacherName() << ',' << s_c.getTeacherID() << ',' << std::to_string(s_c.getTeacherCollege()) << ',';
			line << s_c.getCourseName() << ',' << std::to_string(s_c.getCourseCredit()) << ',' << (s_c.getCourseIsPF() ? "1" : "0") << ',';
			line << std::to_string(s_c.getStudentCourseScore()) << ',' << std::to_string(s_c.getStudentCourseGPA()) << ',' << std::to_string(s_c.getStudentCourseGrade()) << std::endl;
			stu_file << line.str();
		}
	}
	stu_file.close();
	return;
}


void wrtieIntoTeacherInfoFile(const std::string& file_name, const std::vector<Course>& crs_vec)
{
	std::ofstream tch_file(file_name, std::ios_base::out | std::ios_base::trunc);
	if (!tch_file.is_open()) {
		std::cerr << "\t\tThe shutdown process ran into a problem" << std::endl;
		std::cerr << "\t\tFailed to open the file: " << file_name << std::endl;
		exit(1);
	}
	for (const auto& crs : crs_vec) {
		std::ostringstream line;
		line << crs.getTeacherName() << ',' << crs.getTeacherID() << ',' << std::to_string(crs.getTeacherCollege()) << ',';
		line << crs.getCourseName() << ',' << std::to_string(crs.getCourseCredit()) << ',' << (crs.getCourseIsPF() ? "1" : "0") << std::endl;
		tch_file << line.str();
	}
	tch_file.close();
	return;
}

//初始化函数
void initialiseSystem(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec)
{
	readFromStudentInfoFile(STUDENT_FILE_PATH, res_vec);
	readFromTeacherInfoFile(TEACHER_FILE_PATH, tch_vec, crs_vec);
	for (int i = 0; i < res_vec.size(); i++) {
		updateStudentResults(res_vec, i);
	}
	updateAllClassInfo(res_vec, class_vec);
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*            系统初始化完成！            *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t";
	return;
}

//关机函数
void shutDownSystem(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec)
{
	writeIntoStudentInfoFile(STUDENT_FILE_PATH, res_vec);
	wrtieIntoTeacherInfoFile(TEACHER_FILE_PATH, crs_vec);
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*              系统已关闭！              *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t";
	return;
}

//主函数
int main(int argc, const char* argv[])
{
	int select_num;//用户根据菜单界面相应功能输入的数字
	initialiseSystem(res_vec, tch_vec, crs_vec, class_vec);
	system("pause");
	system("cls");
	while (true)
	{
		showMainMenu();
		std::cout << "\t\t请输入：";
		std::cin >> select_num;
		if (select_num == 1)
		{
			std::cout << "\n\t\t您选择的数字是：1" << std::endl;
			std::cout << "\t\t————即将进入教师页面————" << std::endl << "\t\t";
			system("pause");
			if (showTeacherLogInMenu(tch_vec,tch_obj) != -1) {
				teacherMenuOperate(tch_vec, showTeacherLogInMenu(tch_vec, tch_obj));
			}
		}
		else if (select_num == 2)
		{
			std::cout << "\n\t\t您选择的数字是：2" << std::endl;
			std::cout << "\t\t————即将进入学生页面————" << std::endl << "\t\t";
			system("pause");
			if (showStudentLogInMenu(res_vec,stu_obj) != -1) {
				studentMenuOperate(res_vec, showStudentLogInMenu(res_vec, stu_obj));
			}
		}
		else if (select_num == 0) {
			std::cout << "\n\t\t******提示：确定要退出学生成绩管理系统吗？******" << std::endl;
			std::cout << "\t\t******1---是，退出    0---否，继续使用******" << std::endl;
			int isExit;
			while (true)
			{
				std::cout << "\t\t请输入 1 或 0 ：";
				std::cin >> isExit;
				if (isExit == 1)
				{
					std::cout << "\t\t******您已成功退出学生成绩管理系统！欢迎下次使用！******" << std::endl << "\t\t";
					system("pause");
					system("cls");
					shutDownSystem(res_vec, tch_vec, crs_vec);
					system("pause");
					return 0;
					break;
				}
				else if (isExit == 0)
				{
					std::cout << "\t\t您已取消退出！请继续使用\n\t\t";
					system("pause");
					system("cls");
					break;
				}
				else std::cout << "\t\t输入有误！请输入 1 或 0 ：" << std::endl;
			}
		}
		else {
			std::cout << "\n\t\t输入无效！请重新输入数字 1 或 2：" << std::endl << "\t\t";
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}


//该学生是否已存在，不存在返回-1，存在返回在res_vec中的下标
int isStudentExist(const std::vector<StudentResults>& res_vec, const std::string& name, const std::string& id)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentName() == name && res_vec[i].stu.getStudentID() == id) {
			return i;
		}
	}
	return -1;
}

//该学生姓名是否存在(学生可能存在同名)
bool isStudentNameExist(const std::vector<StudentResults>& res_vec, const std::string& name)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentName() == name)
			return true;
	}
	return false;
}

//该学号是否存在，不存在返回-1，存在返回在res_vec中的下标
int isStudentIDExist(const std::vector<StudentResults>& res_vec, const std::string& id)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentID() == id)
			return i;
	}
	return -1;
}

//该老师是否存在，不存在返回-1，存在返回在tch_vec中的下标
int isTeacherExist(const std::vector<Teacher>& tch_vec, const std::string& name, const std::string& id)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherName() == name && tch_vec[i].getTeacherID() == id)
			return i;
	}
	return -1;
}

//该老师姓名是否存在，不存在返回-1，存在返回在tch_vec中的下标，默认老师不存在同名
int isTeacherNameExist(const std::vector<Teacher>& tch_vec, const std::string& name)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherName() == name)
			return i;
	}
	return -1;
}

//该老师工号是否存在，不存在返回-1，存在返回在tch_vec中的下标
int isTeacherIDExist(const std::vector<Teacher>& tch_vec, const std::string& id)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherID() == id)
			return i;
	}
	return -1;
}

//该课程是否存在，未选返回-1，选了返回在crs_vec中的下标
int isCourseExist(const std::vector<Course>& crs_vec, const std::string& name)
{
	for (int i = 0; i < crs_vec.size(); i++) {
		if (crs_vec[i].getCourseName() == name)
			return i;
	}
	return -1;
}

//学生是否选了这门课,未选返回-1，选了返回在stu_crs中的下标
int isStudentSelectCourse(const std::vector<StudentResults>& res_vec, const int& stu_obj, std::string& name)
{
	for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++) {
		if (res_vec[stu_obj].stu_crs[i].getStudentCourseName() == name)
			return i;
	}
	return -1;
}


//关于StudentResults的运算符重载
bool operator<(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA < rhs.GPA;
}

bool operator>(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA > rhs.GPA;
}

bool operator<=(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA <= rhs.GPA;
}

bool operator>=(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA >= rhs.GPA;
}

bool operator==(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA == rhs.GPA;
}

bool operator!=(const StudentResults& lhs, const StudentResults& rhs) {
	return lhs.GPA != rhs.GPA;
}


//关于StudentCourse的运算符重载
bool operator<(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() < rhs.getStudentCourseScore();
}

bool operator>(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() > rhs.getStudentCourseScore();
}

bool operator<=(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() <= rhs.getStudentCourseScore();
}

bool operator>=(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() >= rhs.getStudentCourseScore();
}

bool operator==(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() == rhs.getStudentCourseScore();
}

bool operator!=(const StudentCourse& lhs, const StudentCourse& rhs) {
	return lhs.getStudentCourseScore() != rhs.getStudentCourseScore();
}

//退出当前页面,返回主菜单
void returnToMainMenu()
{
	std::cout << "\n\t\t******提示：确定要退出当前页面、返回主菜单吗？******" << std::endl;
	std::cout << "\t\t******1---是，退出    0---否，继续使用******" << std::endl;
	int isExit;
	while (true)
	{
		std::cout << "\t\t";
		std::cin >> isExit;
		if (isExit == 1)
		{
			std::cout << "\t\t您已成功返回主菜单！" << std::endl;
			break;
		}
		else if (isExit == 0)
		{
			std::cout << "\t\t您已取消退出！请继续使用" << std::endl;
			break;
		}
		else std::cout << "\t\t输入有误！请输入 1 或 0 ：" << std::endl;
	}
	return;
}

//显示主菜单
void showMainMenu()
{
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                欢迎使用               *" << std::endl;
	std::cout << "\t\t*            学生成绩管理系统           *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t请选择您的身份：（在键盘上按数字 1 或 2），或者按0退出系统" << std::endl;
	std::cout << "\t\t1---我是老师    2---我是学生    0---退出系统" << std::endl;
	return;
}


//
// 
//学生部分
//
// 
//显示学生登录介面
int showStudentLogInMenu(const std::vector<StudentResults>& res_vec, int& stu_obj)
{
	system("cls");
	std::string name, id;
	int flag = 0;
	std::cout << "\t\t******——学生登陆界面——******\n\n";
	std::cout << "\t\t请输入你的姓名和学号（两者均正确且匹配才能成功登录）：" << std::endl;
	while (true)
	{
		std::cout << "\t\t姓名：";
		std::cin >> name;
		std::cout << "\t\t请继续输入学号：";
		std::cin >> id;
		if (isStudentNameExist(res_vec, name) == true && isStudentIDExist(res_vec, id) != -1 && isStudentIDExist(res_vec, id) == isStudentExist(res_vec, name, id))
		{
			stu_obj = isStudentExist(res_vec, name, id);
			std::cout << "\t\t登陆成功！欢迎你，" << res_vec[stu_obj].stu.getStudentName() << "  同学！" << std::endl;
			std::cout << "\t\t******——即将进入学生操作界面——******\n" << std::endl;
			std::cout << "\t\t";
			system("pause");
			return stu_obj;
			break;
		}
		else std::cout << "\t\t登陆失败！请您检查姓名或学号是否输入正确，或者二者是否匹配\n" << std::endl;
	}
	std::cout << "\t\t";
	system("pause");
	return -1;
}

//显示特定学生菜单界面
void showStudentMenu(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  同学：您好！" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*  1、查询课程成绩                       *" << std::endl;
	std::cout << "\t\t*  2、查询总成绩单                       *" << std::endl;
	std::cout << "\t\t*  3、选择一门课程记P/F                  *" << std::endl;
	std::cout << "\t\t*  4、查看班级平均成绩及排名              *" << std::endl;
	std::cout << "\t\t*  0、退出学生界面                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t请选择您的要进行的操作（在键盘上输入特定功能对应的数字）：" << std::endl;
	return;
}

//显示学生操作界面
void studentMenuOperate(std::vector<StudentResults>& res_vec, const int& stu_obj)//在学生界面进行的操作
{
	int select_num;
	while (true)
	{
		showStudentMenu(res_vec, stu_obj);
		std::cout << "\t\t";
		std::cin >> select_num;
		switch (select_num)
		{
		case 1:
			studentInquireSingleResult(res_vec, stu_obj);
			std::cout << "\t\t";
			system("pause");
			break;
		case 2:
			studentInquireAllResults(res_vec, stu_obj);
			std::cout << "\t\t";
			system("pause");
			break;
		case 3:
			studentSelectOneToPF(res_vec, stu_obj);
			std::cout << "\t\t";
			system("pause");
			break;
		case 4:
			studentInquireClassRanking(res_vec, stu_obj);
			std::cout << "\t\t";
			system("pause");
			break;
		case 0:
			returnToMainMenu();
			std::cout << "\t\t";
			system("pause");
			return;
			break;
		default:
			std::cout << "\t\t输入有误，请输入正确的数字 0-4 ：" << std::endl;
			break;
		}
		std::cout << "\t\t";
		system("pause");
	}
	std::cout << "\t\t";
	system("pause");
	return;
}

//查询单科成绩
void studentInquireSingleResult(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::string crs_name;//课程名称
	int stu_crs_obj = 0;//定位课程在学生所选的位置
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  同学：" << std::endl;
	while (true)
	{
		std::cout << "\t\t请输入您要查询的课程名称：";
		std::cin >> crs_name;
		if (isCourseExist(crs_vec, crs_name) != -1 && isStudentSelectCourse(res_vec, stu_obj, crs_name) != -1) {
			stu_crs_obj = isStudentSelectCourse(res_vec, stu_obj, crs_name);
			break;
		}
		else if (isCourseExist(crs_vec, crs_name) != -1 && isStudentSelectCourse(res_vec, stu_obj, crs_name) == -1) {
			std::cout << "\t\t您未选择课程： " << crs_name << " ！请您重新输入";
		}
		else {
			std::cout << "\t\t您输入的课程： " << crs_name << " 不存在！请您重新输入";
		}

	}
	const auto& s_c = res_vec[stu_obj].stu_crs[stu_crs_obj];
	std::cout << "\t\t查询成功！" << std::endl;
	std::cout << "\t\t*******************************" << std::endl;
	std::cout << "\t\t课程： " << crs_name << std::endl;
	std::cout << "\t\t分数： " << s_c.getStudentCourseScore() << std::endl;
	std::cout << "\t\t等级： " << Grade[s_c.getStudentCourseGrade()] << std::endl;
	std::cout << "\t\t绩点： " << s_c.getStudentCourseGPA() << std::endl;
	std::cout << "\t\t*******************************" << std::endl;
	return;
}

//查询所有成绩
void studentInquireAllResults(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	double sum_gpa = 0;//总学分绩
	double sum_credit = 0;//总学分书
	double sum_credit_in_gpa = 0;//计入GPA学分数
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  同学：" << std::endl;
	std::cout << "\t\t您所选的全部课程成绩如下：" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	for (const auto& s_c : res_vec[stu_obj].stu_crs) {
		if (s_c.getCourseIsPF() == false) {
			sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
			sum_credit += (double)s_c.getCourseCredit();
			sum_credit_in_gpa += (double)s_c.getCourseCredit();
			std::cout << "\t\t课程： " << s_c.getStudentCourseName() << std::endl;
			std::cout << "\t\t分数： " << s_c.getStudentCourseScore();
			std::cout << "  等级： " << Grade[s_c.getStudentCourseGrade()];
			std::cout << "  绩点： " << s_c.getStudentCourseGPA() << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
		}
		else {
			sum_credit += (double)s_c.getCourseCredit();
			std::cout << "\t\t课程： " << s_c.getStudentCourseName() << std::endl;
			std::cout << "\t\t分数： " << s_c.getStudentCourseScore();
			std::cout << "  等级： " << Grade[s_c.getStudentCourseGrade()];
			std::cout << "  绩点： " << s_c.getStudentCourseGPA() << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
		}
	}
	//res_vec[stu_obj].GPA = sum_gpa / sum_credit;
	std::cout << "\t\t总GPA： " << res_vec[stu_obj].GPA << std::endl;
	std::cout << "\t\t总学分数： " << sum_credit << " 计入GPA总学分数： " << sum_credit_in_gpa << " 总学分绩： " << sum_gpa << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	return;
}

//选择一门课程记PF
void studentSelectOneToPF(std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  同学：" << std::endl;
	if (res_vec[stu_obj].PF_flag != -1) {
		std::cout << "\t\t您已经P/F过一门课程！您将要：" << std::endl;
		std::cout << "\t\t1---修改，重新选择P/F一门课程" << std::endl;
		std::cout << "\t\t0---放弃修改，维持原P/F课程选择不变" << std::endl;
		int input_num;
		while (true)
		{
			std::cout << "\t\t请输入 1 或 0 ：";
			std::cin >> input_num;
			if (input_num == 1) {
				res_vec[stu_obj].stu_crs[res_vec[stu_obj].PF_flag].setCourseIsPF(false);
				res_vec[stu_obj].PF_flag = -1;
				updateStudentResults(res_vec, stu_obj);
				updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
				updateAllClassInfo(res_vec, class_vec);
				std::cout << "\t\t您已成功将课程：  " << "取消P/F！即将进行下一步操作——重新选择P/F\n\t\t" << std::endl;
				system("pause");
				break;
			}
			else if (input_num == 0) {
				std::cout << "\t\t您已放弃该操作！原P/F课程选择不变，即将退出该页面——\n\t\t";
				system("pause");
				return;
				break;
			}
			else std::cout << "\t\t无效！输入数字不是 1 或 0" << std::endl;
		}
	}
	std::cout << "\t\t现在，您可以选择一门课程，将其评价方式记为P/F。以下是您可选择的课程：" << std::endl;
	std::cout << "\t\t提醒：若选择自带P/F的课程，则该操作不产生影响" << std::endl;
	std::cout << "\t\t******************************" << std::endl;
	for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++) {
		std::cout << "\t\t" << i + 1 << "、 " << res_vec[stu_obj].stu_crs[i].getCourseName() << std::endl;
	}
	std::cout << "\t\t******************************" << std::endl;
	std::cout << "\t\t请选择一门课程（输入课程名前对应的序号，若输入0则退出选择）：";
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (1 <= choice && choice <= res_vec[stu_obj].stu_crs.size()) {
			std::cout << "\t\t您选择的课程是：" << choice << "、" << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << std::endl;
			int sure_num;
			while (true) {
				std::cout << "\t\t您确定要将其即为P/F吗？（该课程的等级、您的总GPA以及班级排名将会随之更新）" << std::endl;
				std::cout << "\t\t1---是的，我确定   0---放弃" << "\n\t\t";
				std::cin >> sure_num;
				if (sure_num == 1) {
					res_vec[stu_obj].stu_crs[sure_num - 1].setCourseIsPF(true);
					res_vec[stu_obj].PF_flag = sure_num - 1;
					updateStudentResults(res_vec, stu_obj);//更新
					updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
					updateAllClassInfo(res_vec, class_vec);
					std::cout << "\t\t您已成功将课程： " << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << "  记为P/F" << std::endl;
					std::cout << "\t\t由于您在该课程的百分制成绩为： " << res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore();
					if (res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore() < 60)
						std::cout << "  因此该课程将被记为：F\n\t\t";
					else std::cout << "  因此该课程将被记为：P\n\t\t";
					system("pause");
					return;
				}
				else if (sure_num == 0) {
					std::cout << "\t\t您已取消选择！即将退出该页面——\n\t\t";
					system("pause");
					return;
				}
				else std::cout << "\t\t输入无效！请重新输入数字1或0：" << std::endl;
			}
		}
		else if (choice == 0) {
			std::cout << "\t\t您已放弃选择！即将退出该页面——\n\t\t";
			system("pause");
			return;
		}
		else {
			std::cout << "\t\t输入有误！请您再次输入正确的数字:  1——" << res_vec[stu_obj].stu_crs.size() << std::endl;
		}
	}
	return;
}

//查询班级排名
void studentInquireClassRanking(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  同学：" << std::endl;
	std::cout << "\t\t******************************" << std::endl;
	std::cout << "\t\t您所在的班级：  " << res_vec[stu_obj].stu.getStudentClass() << "  班" << std::endl;
	std::cout << "\t\t班级总人数：  " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].stu_amount << std::endl;
	std::cout << "\t\t班级平均GPA：  " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].aver_GPA << std::endl;
	std::cout << "\t\t您的总GPA：  " << res_vec[stu_obj].GPA << std::endl;
	std::cout << "\t\t您的班级排名：  " << res_vec[stu_obj].ranking << std::endl;
	std::cout << "\t\t******************************\n\t\t";
	system("pause");
	return;
}


//更新各科成绩、均绩和班级排名
void updateStudentResults(std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	int class_num = res_vec[stu_obj].stu.getStudentClass();
	double sum_gpa = 0;//总学分绩
	double sum_credit = 0;//总学分
	for (auto& s_c : res_vec[stu_obj].stu_crs) {
		s_c.setStudentCourseScore(s_c.getStudentCourseScore());
		sum_credit += (double)s_c.getCourseCredit();
		if (s_c.getCourseIsPF() == false) {
			sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
		}
	}
	res_vec[stu_obj].GPA = sum_gpa / sum_credit;//更新该学生均绩
	return;
}


//更新该班级所有学生排名和班级均绩
void updateClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec, const int& class_num)
{
	double sum_gpa = 0;
	int amount = 0;//班级人数
	int flag = 0;
	for (auto& res : res_vec) {
		if (res.stu.getStudentClass() == class_num) {
			updateStudentResults(res_vec, flag);
			int this_ranking = 1;
			for (const auto& res2 : res_vec) {
				if (res2.stu.getStudentClass() == res.stu.getStudentClass() && res2 > res)
				{
					this_ranking++;
				}
			}
			res.ranking = this_ranking;
			sum_gpa += res.GPA;
			amount++;
		}
		flag++;
	}
	class_vec[class_num - 1].aver_GPA = sum_gpa / class_vec[class_num - 1].stu_amount;
	class_vec[class_num - 1].stu_amount = amount;
	return;
}


//更新所有班级信息
void updateAllClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec)
{
	for (int i = 0; i < class_vec.size(); i++) {
		updateClassInfo(res_vec, class_vec, i + 1);
	}
	return;
}


//比较选同一门课的两个学生的成绩，降序
bool compareStudentCourseByScore(const StudentCourse& lhs, const StudentCourse& rhs)
{
	return lhs.getStudentCourseScore() < rhs.getStudentCourseScore();
}

//比较两个同班的学生的GPA，用于班内排名，升序
bool compareStudentByGPA(const StudentResults& lhs, const StudentResults& rhs)
{
	return lhs.GPA < rhs.GPA;
}


//
// 
//教师部分
// 
//
//显示教师登陆界面
int showTeacherLogInMenu(const std::vector<Teacher>& tch_vec, int& tch_obj)
{
	system("cls");
	std::string name, id;
	int flag = 0;
	std::cout << "\t\t******——教师登陆界面——******\n\n";
	std::cout << "\t\t请输入您的姓名和工号（两者均正确且匹配才能成功登录）：" << std::endl;
	while (true)
	{
		std::cout << "\t\t姓名：";
		std::cin >> name;
		std::cout << "\t\t请继续输入工号：";
		std::cin >> id;
		if (isTeacherIDExist(tch_vec, id) != -1 && isTeacherIDExist(tch_vec, id) == isTeacherNameExist(tch_vec, name) && isTeacherIDExist(tch_vec, id) == isTeacherExist(tch_vec, name, id))
		{
			tch_obj = isTeacherExist(tch_vec, name, id);
			std::cout << "\t\t登陆成功！欢迎您，" << tch_vec[tch_obj].getTeacherName() << "  老师！" << std::endl;
			std::cout << "\t\t******——即将进入教师操作界面——******\n" << std::endl;
			std::cout << "\t\t";
			system("pause");
			return tch_obj;
			break;
		}
		else std::cout << "\t\t登陆失败！请您检查姓名或工号是否输入正确，或者二者是否匹配\n" << std::endl;
	}
	std::cout << "\t\t";
	system("pause");
	return -1;
}

//显示教师界面菜单
void showTeacherMenu(const std::vector<Teacher>& tch_vec, const int& tch_obj)
{
	system("cls");
	std::cout << tch_vec[tch_obj].getTeacherName() << "  老师：您好！" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*  1、录入课程成绩                       *" << std::endl;
	std::cout << "\t\t*  2、修改课程成绩                       *" << std::endl;
	std::cout << "\t\t*  3、查看课程成绩情况                   *" << std::endl;
	std::cout << "\t\t*  4、查看学生成绩                       *" << std::endl;
	std::cout << "\t\t*  5、查看班级成绩                       *" << std::endl;
	std::cout << "\t\t*  0、退出教师界面                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t请选择您的要进行的操作（在键盘上输入特定功能对应的数字）：" << std::endl;
}

//教师操作界面
void teacherMenuOperate(const std::vector<Teacher>& tch_vec, const int& stu_obj)//教师界面进行的操作
{
	int select_num;
	while (true)
	{
		showTeacherMenu(tch_vec, tch_obj);
		std::cin >> select_num;
		switch (select_num)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			returnToMainMenu();
			std::cout << "\t\t";
			system("pause");
			return;
			break;
		default:
			std::cout << "\t\t输入有误，请输入正确的数字 0-5 ：" << std::endl;
			break;
		}
		std::cout << "\t\t";
		system("pause");
		system("cls");
	}
	std::cout << "\t\t";
	system("pause");
	return;
}

//录入课程成绩
void teacherEnterResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  老师，您所教授的课程是：  " << crs_vec[tch_obj].getCourseName() << std::endl;
	int choice;
	std::cout << "\t\t您可以按照以下两种方式录入成绩：" << std::endl;
	std::cout << "\t\t1---从已选课学生中依次录入  2---新建一个选课学生并录入" << std::endl;
	while (true)
	{
		std::cout << "\t\t请输入您的选择（1 / 2）：";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "\t\t以下是已选该课的学生名单：" << std::endl;
			int num = 0;
			for (auto& res : res_vec) {
				for (auto& s_c : res.stu_crs) {
					if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName()) {
						int score;
						num++;
						std::cout << "\t\t" << num << "、" << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << std::endl;
						while (true)
						{
							std::cout << "\t\t请输入该学生的成绩：";
							std::cin >> score;
							if (0 <= score && score <= 100) {
								s_c.setStudentCourseScore(score);
								std::cout << "\t\t您已成功录入该学生的成绩：" << score << std::endl;
								std::cout << "\t\t下面将进行下一位学生的成绩录入——" << std::endl;
								std::cout << "\t\t";
								system("pause");
								break;
							}
							else std::cout << "\t\t成绩无效！请您重新输入" << std::endl;
						}
						break;
					}
				}
			}
			std::cout << "\t\t您已完成对所有学生的成绩录入！" << std::endl;
			return;
		}

		else if (choice == 2) {
			std::cout << "\t\t下面，您将创建一个新的选课学生（该学生将默认选修您的课程）" << std::endl;
			std::string name, id;
			int class_num;
			while (true)
			{
				StudentResults temp_res;
				StudentCourse temp_sc;
				std::cout << "\t\t请输入学生姓名：";
				std::cin >> name;
				std::cout << "\t\t请输入学生学号";
				std::cin >> id;
				if (isStudentExist(res_vec, name, id) == -1 || isStudentIDExist(res_vec, id) == -1) {
					std::cout << "\t\t该学生已存在或学号已被占用！请重新输入";
					continue;
				}
				std::cout << "\t\t请输入学生班级（该班级不存在时将会自动创建新班级）：";
				std::cin >> class_num;
				if (1 <= class_num && class_num <= class_vec.size()) {
					class_vec[class_num - 1].stu_amount++;
				}
				else {
					std::cout << "\t\t由于现在共有  " << class_vec.size() << "  个班级，下面您将创建一个新的班级： " << class_vec.size() + 1;
					class_num = class_vec.size() + 1;
					ClassInfo temp_class = { class_num,1,0 };
					class_vec.push_back(temp_class);
				}
				temp_res.stu.Student::Student(name, id, class_num);
				temp_sc.Student::Student(name, id, class_num);
				temp_sc.Teacher::Teacher(tch_vec[tch_obj]);
				temp_sc.Course::Course(crs_vec[tch_obj]);
				temp_sc.setStudentCourseName(crs_vec[tch_obj].getCourseName());
				int score;
				while (true)
				{
					std::cout << "\t\t请输入该学生的课程成绩：";
					std::cin >> score;
					if (0 <= score && score <= 100) {
						temp_sc.setStudentCourseScore(score);
						temp_res.PF_flag = -1;
						res_vec.push_back(temp_res);
						updateStudentResults(res_vec, res_vec.size() - 1);//此时学生是最后一个
						updateClassInfo(res_vec, class_vec, class_num - 1);
						updateAllClassInfo(res_vec, class_vec);
						std::cout << "\t\t您已成功录入该学生的成绩分数：" << score << std::endl;
						int next;
						std::cout << "\t\t若要继续录入，请按 1 ，否则将退出录入：";
						std::cin >> next;
						if (next == 1) {
							std::cout << "\t\t您已选择继续录入！" << std::endl;
							std::cout << "\t\t";
							system("pause");
							break;
						}
						else {
							std::cout << "\t\t您即将退出录入！" << std::endl;
							std::cout << "\t\t";
							system("pause");
							return;
						}
					}
					else std::cout << "\t\t成绩分数无效（不在0——100内）！请您重新输入" << std::endl;
				}
			}
		}

		else {
			std::cout << "\t\t输入无效！若要继续录入，请按 1 ，否则将退出录入：";
			int next;
			std::cin >> next;
			if (next == 1) {
				std::cout << "\t\t您已选择继续录入！" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t您即将退出录入！" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}
	}
	return;
}

//修改课程成绩
void teacherModifyResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  老师，您所教授的课程是：  " << crs_vec[tch_obj].getCourseName() << std::endl;
	std::cout << "\t\t以下是已选该课的学生及成绩名单：" << std::endl;
	int num = 0;
	std::vector<StudentCourse> temp_vec;
	temp_vec.clear();
	for (const auto& res : res_vec) {
		for (const auto& s_c : res.stu_crs) {
			if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName()) {
				temp_vec.push_back(s_c);
				num++;
				std::cout << "\t\t" << num << "、" << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << "\t" << res.stu.getStudentName() << std::endl;
				break;
			}
		}
	}
	int choice;
	while (true)
	{
		std::cout << "\t\t请选择学生姓名前的序号，然后对成绩进行修改：";
		std::cin >> choice;
		if (1 <= choice && choice <= num) {
			std::cout << "\t\t您选择了：" << choice << "、" << temp_vec[choice - 1].getStudentName() << std::endl;
			std::cout << "\t\t该学生目前的成绩为：" << temp_vec[choice - 1].getStudentCourseScore();
			int score;
			int stuobj = isStudentExist(res_vec, temp_vec[choice - 1].getStudentName(), temp_vec[choice - 1].getStudentID());
			int crsobj = isStudentSelectCourse(res_vec, stuobj, temp_vec[choice - 1].getStudentCourseName());
			while (true)
			{
				std::cout << "\t\t请您输入修改后的成绩（0——100）：";
				std::cin >> score;
				if (0 <= score && score <= 100) {
					int sure;
					std::cout << "\t\t您确定要将成绩由" << temp_vec[choice - 1].getStudentCourseScore() << "修改为：" << score << "吗？" << std::endl;
					std::cout << "\t\t1---确定  0---取消:";
					std::cin >> sure;
					while (true) {
						if (sure == 1) {
							std::cout << "\t\t修改成功！您已将其成绩由：" << temp_vec[choice - 1].getStudentCourseScore() << "修改为：" << score << std::endl;
							res_vec[stuobj].stu_crs[crsobj].setStudentCourseScore(score);
							updateStudentResults(res_vec, stuobj);
							updateClassInfo(res_vec, class_vec, res_vec[stuobj].stu.getStudentClass());
							updateAllClassInfo(res_vec, class_vec);
							break;
						}
						else if (sure == 0) {
							std::cout << "\t\t您已取消本次修改！" << std::endl;
							break;
						}
						else std::cout << "\t\t无效！请重新输入" << std::endl;
					}
					int next;
					std::cout << "\t\t若要继续修改成绩请按 1 ，否则将退出修改：";
					std::cin >> next;
					if (next == 1) {
						std::cout << "\t\t您已选择继续修改！" << std::endl;
						std::cout << "\t\t";
						system("pause");
						break;
					}
					else {
						std::cout << "\t\t您即将退出修改！" << std::endl;
						std::cout << "\t\t";
						system("pause");
						return;
					}
				}
				else std::cout << "\t\t分数不在0——100内，无效！" << std::endl;
			}
		}
		else std::cout << "\t\t无效！请重新输入" << std::endl;
	}
	return;
}

//查看课程所有学生成绩,老师只能看见自己教的课的成绩
void teacherInquireCourseResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  老师，您所教授的课程是：  " << crs_vec[tch_obj].getCourseName() << std::endl;
	std::cout << "\t\t以下是该课程的成绩名单：（非排名顺序）" << std::endl;
	std::cout << "\t\t姓名\t成绩\t等级\t绩点" << std::endl;
	std::cout << "\t\t-----------------------------------" << std::endl;
	std::vector<StudentCourse> temp_vec;
	temp_vec.clear();
	for (const auto& res : res_vec) {
		for (const auto& sc : res.stu_crs) {
			if (sc.getCourseName() == crs_vec[tch_obj].getCourseName()) {
				temp_vec.push_back(sc);
			}
		}
	}
	//std::sort(temp_vec.begin(), temp_vec.end(), [](const StudentCourse& lhs, const StudentCourse& rhs)
	//	{
	//		return lhs.getStudentCourseScore() > rhs.getStudentCourseScore();
	//	});
	std::sort(temp_vec.begin(), temp_vec.end(), compareStudentCourseByScore);
	int num = 1;
	for (const auto& s_c : temp_vec) {
		std::cout << "\t\t" << num << "、" << s_c.getStudentName() << "\t" << s_c.getStudentCourseScore() << "\t";
		std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
		num++;
	}
	std::cout << "\t\t-----------------------------------" << std::endl;
	std::cout << "\t\t如需修改成绩，请前往功能 2 " << std::endl;
	return;
}

//查看某个学生各门成绩，老师能看见所有学生的成绩
void teacherInquireStudentResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  老师，您好！" << std::endl;
	std::cout << "\t\t您可以按姓名或学号查看所有学生的成绩" << std::endl;
	std::cout << "\t\t按姓名查询请按 1 ，按学号查询请按 2 。姓名查询结果可能不唯一，学号查询结果唯一。若要退出查询请按 0" << std::endl;
	int choice, isexit;
	while (true)
	{
		std::cout << "\t\t请输入您的选择：";
		std::cin >> choice;
		if (choice == 1) {
			std::string name;
			std::cout << "\t\t请输入学生姓名：";
			std::cin >> name;
			std::cout << "\t\t已为您找到以下学生：" << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
			for (const auto& res : res_vec) {
				if (res.stu.getStudentName() == name) {
					std::cout << "\t\t姓名：" << name << "  学号：" << res.stu.getStudentID() << "  班级：" << res.stu.getStudentClass() << std::endl;
					std::cout << "\t\t总GPA：" << res.GPA << "  班级排名：" << res.ranking << std::endl;
					std::cout << "\t\t以下是各门课程成绩：" << std::endl;
					std::cout << "\t\t课程名称\t课程成绩\t绩点\t等级" << std::endl;
					std::cout << "\t\t---------------------------------" << std::endl;
					for (const auto& s_c : res.stu_crs) {
						std::cout << "\t\t" << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
						std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
					}
					std::cout << "\t\t---------------------------------" << std::endl;
				}
			}
			std::cout << "\t\t*****************************************\n\n";
			std::cout << "\t\t若要继续查询，请按 1：";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t您已选择继续查询！" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t您选择的是：" << isexit << std::endl;
				std::cout << "\t\t******——您即将退出查询——******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}

		else if (choice == 2) {
			std::string id;
			std::cout << "\t\t请输入学生学号：";
			std::cin >> id;
			std::cout << "\t\t已为您找到以下学生：" << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
			for (const auto& res : res_vec) {
				if (res.stu.getStudentID() == id) {
					std::cout << "\t\t姓名：" << res.stu.getStudentName() << "  学号：" << id << "  班级：" << res.stu.getStudentClass() << std::endl;
					std::cout << "\t\t总GPA：" << res.GPA << "  班级排名：" << res.ranking << std::endl;
					std::cout << "\t\t以下是各门课程成绩：" << std::endl;
					std::cout << "\t\t课程名称\t课程成绩\t绩点\t等级" << std::endl;
					std::cout << "\t\t---------------------------------" << std::endl;
					for (const auto& s_c : res.stu_crs) {
						std::cout << "\t\t" << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
						std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
					}
					std::cout << "\t\t---------------------------------" << std::endl;
				}
			}
			std::cout << "\t\t*****************************************\n\n";
			std::cout << "\t\t若要继续查询，请按 1：";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t您已选择继续查询！" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t您选择的是：" << isexit << std::endl;
				std::cout << "\t\t******——您即将退出查询——******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}

		else if (choice == 0) {
			std::cout << "\t\t您选择了： 0 " << std::endl;
			std::cout << "\t\t******——您即将退出查询！——******" << std::endl;
			std::cout << "\t\t";
			system("pause");
			break;
			return;
		}
		else {
			std::cout << "\t\t输入无效！" << std::endl;
		}
	}
	return;
}

//查看班级成绩，老师能查看所有班级的成绩
void teacherInquireClassResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  老师，您好！" << std::endl;
	std::cout << "\t\t您查看所有班级的学生成绩状况" << std::endl;
	while (true)
	{
		std::cout << "\t\t请选择班级：1——" << class_vec.size() << " : " << std::endl;
		int class_num;
		std::cin >> class_num;
		if (1 <= class_num && class_num <= class_vec.size()) {
			std::cout << "\t\t您选择了班级：" << class_num;
			std::cout << "\t\t以下是" << class_num << "班所有学生的GPA及排名" << std::endl;
			std::cout << "\t\t姓名\tGPA\t排名" << std::endl;
			std::cout << "\t\t------------------------------" << std::endl;
			std::vector<StudentResults> temp_vec;
			temp_vec.clear();
			for (const auto& res : res_vec) {
				if (res.stu.getStudentClass() == class_num)
					temp_vec.push_back(res);
			}
			//std::sort(temp_vec.begin(), temp_vec.end(), [](const StudentResults& lhs, const StudentResults& rhs)
			//	{
			//		return lhs.GPA > rhs.GPA;
			//	});
			std::sort(temp_vec.begin(), temp_vec.end(), compareStudentByGPA);
			for (const auto& temp : temp_vec) {
				std::cout << "\t\t" << temp.stu.getStudentName() << "\t" << temp.GPA << "\t" << temp.ranking << std::endl;
			}
			std::cout << "\t\t------------------------------" << std::endl;
			std::cout << "\t\t班级总人数：  " << class_vec[class_num - 1].stu_amount << "  平均GPA：  " << class_vec[class_num - 1].aver_GPA << "\n\n";
			int isexit;
			std::cout << "\t\t若要继续查询，请输入 1 ，否则将退出查询";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t您已选择继续查询！" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t您选择的是：" << isexit << std::endl;
				std::cout << "\t\t******——您即将退出查询——******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}
		else
			std::cout << "\t\t输入无效！不在范围 1——" << class_vec.size() << "内，请重新选择" << std::endl;
	}
	return;
}
