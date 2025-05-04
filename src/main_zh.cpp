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
const int MAX_STU_NUM = 10000; //�ܹ�¼������ѧ����Ŀ
const int MAX_STRLEN = 1024; //��ϵͳ�г��ֵ��ַ�����󳤶�
const std::string College[47] = { //Ժϵ���
	"����ϵ", // 0
	"����ѧԺ", // 1
	"��ľϵ", // 2
	"ˮ��ϵ", // 3
	"����ѧԺ", // 4
	"��еϵ", // 5
	"����ϵ", // 6
	"�ܶ�ϵ", // 7
	"����ѧԺ", // 8
	"��ҵ����ϵ", // 9
	"���ϵ", // 10
	"�����ϵ", // 11
	"�Զ���ϵ", // 12
	"���ѧԺ", // 13
	"���ɵ�·ѧԺ", // 14
	"��Ժ", // 15
	"��������ϵ", // 16
	"����ϵ", // 17
	"����ѧԺ", // 18
	"��ѧϵ", // 19
	"����ϵ", // 20
	"��ѧϵ", // 21
	"����ѧԺ", // 22
	"��ѧϵ", // 23
	"������ϢԺ", // 24
	"����ѧԺ", // 25
	"����ѧԺ", // 26
	"����ѧԺ", // 27
	"����ϵ", // 28
	"��ѧԺ", // 29
	"����ѧԺ", // 30
	"���˼����ѧԺ", // 31
	"����ѧԺ", // 32
	"���ѧԺ", // 33
	"����ѧԺ", // 34
	"����ѧԺ", // 35
	"ҽѧԺ", // 36
	"ҩѧԺ", // 37
	"����ϵ", // 38
	"�����о�Ժ", // 39
	"��������", // 40
	"������Ժ", // 41
	"δ����Ժ", // 42
	"������Ժ", // 43
	"������Ժ", // 44
	"�н���Ժ", // 45
	"Ϊ����Ժ", // 46
};
const std::string Grade[13] = { "A+","A","A-","B+","B","B-","C+","C","C-","D+","D","P","F" };
//����ʼ����ʱ���ļ��ж�ȡ��Ϣ���������У�����ʱ���µ���Ϣд���ļ��б���
const std::string STUDENT_FILE_PATH = "D:\\ASUS\\Desktop\\stu_info.csv";
const std::string TEACHER_FILE_PATH = "D:\\ASUS\\Desktop\\tch_info.csv";


//�����ࣺ��Ա
class Person
{
public:
	virtual void displayInfo()const = 0;
	virtual ~Person() {};
private:
	std::string name = "\0";
	std::string id = "\0";;
};


//��¼ѧ��������Ϣ��Student��
class Student :virtual public Person
{
private:
	std::string stu_name;//����
	std::string stu_id;//ѧ��
	int stu_class;//�༶
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
	void displayInfo()const override//��ӡѧ����Ϣ
	{
		std::cout << "\t\tѧ����Ϣ���£�" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  ������" << stu_name << "  ѧ�ţ�" << stu_id << std::endl;
		std::cout << "\t\t*  �༶��" << stu_class << std::endl;
		std::cout << "\t\t***************************************************\n\n";
		return;
	}
	void setStudentInfo(std::string stu_name = "\0", std::string stu_id = "\0", int stu_class = 0)
	{
		this->stu_name = stu_name;
		this->stu_id = stu_id;
		this->stu_class = stu_class;
		return;
	}//�޸�ȫ����Ϣ
	void setStudentName(std::string new_name = "\0") {
		this->stu_name = new_name;
		return;
	} //�޸�ѧ������
	void setStudentID(std::string new_id = "\0") {
		this->stu_id = new_id;
		return;
	} //�޸�ѧ��ѧ��
	void setStudentClass(const int new_class = 0) {
		this->stu_class = new_class;
		return;
	} //�޸�ѧ���༶
	std::string getStudentName()const { return this->stu_name; }
	std::string getStudentID()const { return this->stu_id; }
	int getStudentClass()const { return this->stu_class; }
};


//��¼��ʦ������Ϣ��Teacher��
class Teacher :virtual public Person
{
private:
	std::string tch_name;//��ʦ����
	std::string tch_id;//��ʦ����
	int tch_college;//��ʦԺϵ���
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
	void displayInfo()const override//��ӡ��ʦ��Ϣ
	{
		std::cout << "\t\t��ʦ��Ϣ���£�" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  ������" << tch_name << "  ���ţ�" << tch_id << std::endl;
		std::cout << "\t\t*  Ժϵ��" << College[tch_college] << std::endl;
		std::cout << "\t\t***************************************************\n\n";
	}
	void setTeacherInfo(std::string tch_name = "\0", std::string tch_id = "\0", int tch_college = 0)
	{
		this->tch_name = tch_name;
		this->tch_id = tch_id;
		this->tch_college = tch_college;
	} //�޸Ľ�ʦ��Ϣ
	void setTeacherName(std::string new_name = "\0") {
		this->tch_name = new_name;
		return;
	} //�޸Ľ�ʦ����
	void setTeacherID(std::string new_id = "\0") {
		this->tch_id = new_id;
		return;
	} //�޸Ľ�ʦ����
	void setTeacherCollege(int new_college = 0) {
		this->tch_college = new_college;
		return;
	} //�޸Ľ�ʦԺϵ
	std::string getTeacherName()const { return this->tch_name; }
	std::string getTeacherID()const { return this->tch_id; }
	int getTeacherCollege()const { return this->tch_college; }
};


//��¼�γ̻�����Ϣ��Course��
class Course :public Teacher
{
private:
	std::string crs_name;//�γ���
	int crs_credit;//�γ�ѧ��
	bool isPF;//�Ƿ��PF
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
		std::cout << "\t\t�γ���Ϣ���£�" << std::endl;
		std::cout << "\t\t***************************************************\n";
		std::cout << "\t\t*  �γ����ƣ�" << crs_name << "  ���ν�ʦ��" << Teacher::getTeacherName() << std::endl;
		std::cout << "\t\t*  �γ�ѧ�֣�" << crs_credit << "  ѧʱ��" << crs_credit * 16 << std::endl;
		std::cout << "\t\t*  �Ƿ�ΪP/F��" << (isPF ? "�ǣ�Yes��" : "��No��") << std::endl;
		std::cout << "\t\t***************************************************\n\n";
	}
	void setCourseInfo(const Teacher& tch, std::string crs_name = "\0", int crs_credit = 0, bool isPF = false)
	{
		Teacher::operator=(tch);
		this->crs_name = crs_name;
		this->crs_credit = crs_credit;
		this->isPF = isPF;
	} //�޸Ŀγ���Ϣ
	void setCourseName(std::string new_name = "\0") {
		this->crs_name = new_name;
		return;
	} //�޸Ŀγ�����
	void setCourseCredit(const int new_credit = 0) {
		this->crs_credit = new_credit;
		return;
	} //�޸Ŀγ�ѧ��
	void setCourseIsPF(const bool new_isPF = false) {
		this->isPF = new_isPF;
		return;
	} //�޸Ŀγ��Ƿ��PF
	//�޸Ļ����еĳ�Ա
	void setTeacherName(std::string new_name) { Teacher::setTeacherName(new_name); }
	void setTeacherID(std::string new_id) { Teacher::setTeacherID(new_id); }
	void setTeacherCollege(int new_college) { Teacher::setTeacherCollege(new_college); }
	//��ȡ��Ա��Ϣ
	std::string getCourseName()const { return this->crs_name; }
	int getCourseCredit()const { return this->crs_credit; }
	bool getCourseIsPF()const { return this->isPF; }
	//���������л�ȡ�������Ϣ
	std::string getTeacherName()const { return Teacher::getTeacherName(); }
	std::string getTeacherID()const { return Teacher::getTeacherID(); }
	int getTeacherCollege()const { return Teacher::getTeacherCollege(); }
};


//��¼ѧ��+�γ̵ĳɼ���
class StudentCourse :public Student, public Course
{
private:
	std::string crs;//�γ�����
	int score;//�ٷ��Ƴɼ�
	double gpa;//�γ̼���
	int grade;//�γ̵ȼ�
public:
	StudentCourse(std::string crs = "\0", int score = 0, double gpa = 0, int grade = 0)
	{
		this->crs = crs;
		this->score = score;
		if (Course::getCourseIsPF() == true) {
			if (60 <= score && score <= 100) {
				this->gpa = 4.0;//4.0����P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0����F
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
		std::cout << "\t\t" << crs << "�ɼ���" << score << "  ѧ�֣�" << Course::getCourseCredit() << std::endl;
		std::cout << "\t\t" << "GPA=" << gpa << "  �ȼ���" << Grade[grade] << std::endl;
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
				this->gpa = 4.0;//4.0����P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0����F
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
				this->gpa = 4.0;//4.0����P
				this->grade = 11;//"P"
			}
			else {
				this->gpa = 0.0;//0����F
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
	//�����������޸Ļ������Ϣ
	void setStudentName(std::string new_name) { Student::setStudentName(new_name); }
	void setStudentID(std::string new_id) { Student::setStudentID(new_id); }
	void setStudentClass(int new_class) { Student::setStudentClass(new_class); }
	void setTeacherName(std::string new_name) { Teacher::setTeacherName(new_name); }
	void setTeacherID(std::string new_id) { Teacher::setTeacherID(new_id); }
	void setTeacherCollege(int new_college) { Teacher::setTeacherCollege(new_college); }
	void setCourseName(std::string new_name) { Course::setCourseName(new_name); }
	void setCourseCredit(int new_credit) { Course::setCourseCredit(new_credit); }
	void setCourseIsPF(bool new_isPF) { Course::setCourseIsPF(new_isPF); }
	//���������л�ȡ�������Ϣ
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


struct StudentResults //�ṹ�壬��¼����ѧ������Ϣ�����ſγ̡�����������
{
	Student stu;
	std::vector<StudentCourse> stu_crs;
	double GPA = 0;
	int ranking = 1;
	//���ѧ���Ƿ�PF��һ�ſΣ���û�����Զ���ʼΪ-1��������ֵΪ�ÿγ���stu_crs�е��±�
	int PF_flag = -1;
};

struct ClassInfo
{
	int class_num;//���
	int stu_amount;//ѧ������
	double aver_GPA;//�༶����
};


//ȫ�ֱ���
std::vector<StudentResults> res_vec;
std::vector<Teacher> tch_vec;
std::vector<Course> crs_vec;
std::vector<ClassInfo> class_vec;

int stu_obj = 0;//��λ��Ӧѧ��
int tch_obj = 0;//��λ��Ӧ��ʦ
int crs_obj = 0;//��λ��Ӧ�γ�
int class_obj = 0;



//��������
void readFromStudentInfoFile(const std::string& file_name, std::vector<StudentResults>& res_vec);
void readFromTeacherInfoFile(const std::string& file_name, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec);
void writeIntoStudentInfoFile(const std::string& file_name, const std::vector<StudentResults>& res_vec);
void wrtieIntoTeacherInfoFile(const std::string& file_name, const std::vector<Course>& crs_vec);
void initialiseSystem(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec);
void shutDownSystem(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec);
void showMainMenu();//��ʾ��ҳ��˵�
void returnToMainMenu();//�������˵�

int showStudentLogInMenu(const std::vector<StudentResults>& res_vec, int& stu_obj);//��ʾѧ����½����
void showStudentMenu(const std::vector<StudentResults>& res_vec, const int& stu_obj);//��ʾѧ���˵�����
void studentMenuOperate(std::vector<StudentResults>& res_vec, const int& stu_obj);//ѧ�����в���
void studentInquireSingleResult(const std::vector<StudentResults>& res_vec, const int& stu_obj);//��ѯ���Ƴɼ�
void studentInquireAllResults(const std::vector<StudentResults>& res_vec, const int& stu_obj);//��ѯ���гɼ�
void studentSelectOneToPF(std::vector<StudentResults>& res_vec, const int& stu_obj);//ѡ��һ��PF
void studentInquireClassRanking(const std::vector<StudentResults>& res_vec, const int& stu_obj);//��ѯ�༶����
void updateStudentResults(std::vector<StudentResults>& res_vec, const int& stu_obj);//����ѧ���ɼ�
void updateClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec, const int& class_num);
void updateAllClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec);

int showTeacherLogInMenu(const std::vector<Teacher>& tch_vec, int& tch_obj);//��ʾ��ʦ��½����
void showTeacherMenu(const std::vector<Teacher>& tch_vec, const int& tch_obj);//��ʾ��ʦ�˵�����
void teacherMenuOperate(const std::vector<Teacher>& tch_vec, const int& tch_obj);//��ʦ���в���
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

//���������
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
//������������



//��������
// 
// 
//���ļ��ж�ȡѧ����Ϣ
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
			//�ַ���������Ҫת��Ϊ�������������Ͳ���ֵ
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
		//�ַ���������Ҫת��Ϊ�������������Ͳ���ֵ
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

//��ʼ������
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
	std::cout << "\t\t*            ϵͳ��ʼ����ɣ�            *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t";
	return;
}

//�ػ�����
void shutDownSystem(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec)
{
	writeIntoStudentInfoFile(STUDENT_FILE_PATH, res_vec);
	wrtieIntoTeacherInfoFile(TEACHER_FILE_PATH, crs_vec);
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*              ϵͳ�ѹرգ�              *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t*                                        *" << std::endl;
	std::cout << "\t\t******************************************" << std::endl;
	std::cout << "\t\t";
	return;
}

//������
int main(int argc, const char* argv[])
{
	int select_num;//�û����ݲ˵�������Ӧ�������������
	initialiseSystem(res_vec, tch_vec, crs_vec, class_vec);
	system("pause");
	system("cls");
	while (true)
	{
		showMainMenu();
		std::cout << "\t\t�����룺";
		std::cin >> select_num;
		if (select_num == 1)
		{
			std::cout << "\n\t\t��ѡ��������ǣ�1" << std::endl;
			std::cout << "\t\t�����������������ʦҳ�桪������" << std::endl << "\t\t";
			system("pause");
			if (showTeacherLogInMenu(tch_vec,tch_obj) != -1) {
				teacherMenuOperate(tch_vec, showTeacherLogInMenu(tch_vec, tch_obj));
			}
		}
		else if (select_num == 2)
		{
			std::cout << "\n\t\t��ѡ��������ǣ�2" << std::endl;
			std::cout << "\t\t����������������ѧ��ҳ�桪������" << std::endl << "\t\t";
			system("pause");
			if (showStudentLogInMenu(res_vec,stu_obj) != -1) {
				studentMenuOperate(res_vec, showStudentLogInMenu(res_vec, stu_obj));
			}
		}
		else if (select_num == 0) {
			std::cout << "\n\t\t******��ʾ��ȷ��Ҫ�˳�ѧ���ɼ�����ϵͳ��******" << std::endl;
			std::cout << "\t\t******1---�ǣ��˳�    0---�񣬼���ʹ��******" << std::endl;
			int isExit;
			while (true)
			{
				std::cout << "\t\t������ 1 �� 0 ��";
				std::cin >> isExit;
				if (isExit == 1)
				{
					std::cout << "\t\t******���ѳɹ��˳�ѧ���ɼ�����ϵͳ����ӭ�´�ʹ�ã�******" << std::endl << "\t\t";
					system("pause");
					system("cls");
					shutDownSystem(res_vec, tch_vec, crs_vec);
					system("pause");
					return 0;
					break;
				}
				else if (isExit == 0)
				{
					std::cout << "\t\t����ȡ���˳��������ʹ��\n\t\t";
					system("pause");
					system("cls");
					break;
				}
				else std::cout << "\t\t�������������� 1 �� 0 ��" << std::endl;
			}
		}
		else {
			std::cout << "\n\t\t������Ч���������������� 1 �� 2��" << std::endl << "\t\t";
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}


//��ѧ���Ƿ��Ѵ��ڣ������ڷ���-1�����ڷ�����res_vec�е��±�
int isStudentExist(const std::vector<StudentResults>& res_vec, const std::string& name, const std::string& id)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentName() == name && res_vec[i].stu.getStudentID() == id) {
			return i;
		}
	}
	return -1;
}

//��ѧ�������Ƿ����(ѧ�����ܴ���ͬ��)
bool isStudentNameExist(const std::vector<StudentResults>& res_vec, const std::string& name)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentName() == name)
			return true;
	}
	return false;
}

//��ѧ���Ƿ���ڣ������ڷ���-1�����ڷ�����res_vec�е��±�
int isStudentIDExist(const std::vector<StudentResults>& res_vec, const std::string& id)
{
	for (int i = 0; i < res_vec.size(); i++) {
		if (res_vec[i].stu.getStudentID() == id)
			return i;
	}
	return -1;
}

//����ʦ�Ƿ���ڣ������ڷ���-1�����ڷ�����tch_vec�е��±�
int isTeacherExist(const std::vector<Teacher>& tch_vec, const std::string& name, const std::string& id)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherName() == name && tch_vec[i].getTeacherID() == id)
			return i;
	}
	return -1;
}

//����ʦ�����Ƿ���ڣ������ڷ���-1�����ڷ�����tch_vec�е��±꣬Ĭ����ʦ������ͬ��
int isTeacherNameExist(const std::vector<Teacher>& tch_vec, const std::string& name)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherName() == name)
			return i;
	}
	return -1;
}

//����ʦ�����Ƿ���ڣ������ڷ���-1�����ڷ�����tch_vec�е��±�
int isTeacherIDExist(const std::vector<Teacher>& tch_vec, const std::string& id)
{
	for (int i = 0; i < tch_vec.size(); i++) {
		if (tch_vec[i].getTeacherID() == id)
			return i;
	}
	return -1;
}

//�ÿγ��Ƿ���ڣ�δѡ����-1��ѡ�˷�����crs_vec�е��±�
int isCourseExist(const std::vector<Course>& crs_vec, const std::string& name)
{
	for (int i = 0; i < crs_vec.size(); i++) {
		if (crs_vec[i].getCourseName() == name)
			return i;
	}
	return -1;
}

//ѧ���Ƿ�ѡ�����ſ�,δѡ����-1��ѡ�˷�����stu_crs�е��±�
int isStudentSelectCourse(const std::vector<StudentResults>& res_vec, const int& stu_obj, std::string& name)
{
	for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++) {
		if (res_vec[stu_obj].stu_crs[i].getStudentCourseName() == name)
			return i;
	}
	return -1;
}


//����StudentResults�����������
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


//����StudentCourse�����������
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

//�˳���ǰҳ��,�������˵�
void returnToMainMenu()
{
	std::cout << "\n\t\t******��ʾ��ȷ��Ҫ�˳���ǰҳ�桢�������˵���******" << std::endl;
	std::cout << "\t\t******1---�ǣ��˳�    0---�񣬼���ʹ��******" << std::endl;
	int isExit;
	while (true)
	{
		std::cout << "\t\t";
		std::cin >> isExit;
		if (isExit == 1)
		{
			std::cout << "\t\t���ѳɹ��������˵���" << std::endl;
			break;
		}
		else if (isExit == 0)
		{
			std::cout << "\t\t����ȡ���˳��������ʹ��" << std::endl;
			break;
		}
		else std::cout << "\t\t�������������� 1 �� 0 ��" << std::endl;
	}
	return;
}

//��ʾ���˵�
void showMainMenu()
{
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                ��ӭʹ��               *" << std::endl;
	std::cout << "\t\t*            ѧ���ɼ�����ϵͳ           *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t��ѡ��������ݣ����ڼ����ϰ����� 1 �� 2�������߰�0�˳�ϵͳ" << std::endl;
	std::cout << "\t\t1---������ʦ    2---����ѧ��    0---�˳�ϵͳ" << std::endl;
	return;
}


//
// 
//ѧ������
//
// 
//��ʾѧ����¼����
int showStudentLogInMenu(const std::vector<StudentResults>& res_vec, int& stu_obj)
{
	system("cls");
	std::string name, id;
	int flag = 0;
	std::cout << "\t\t******����ѧ����½���桪��******\n\n";
	std::cout << "\t\t���������������ѧ�ţ����߾���ȷ��ƥ����ܳɹ���¼����" << std::endl;
	while (true)
	{
		std::cout << "\t\t������";
		std::cin >> name;
		std::cout << "\t\t���������ѧ�ţ�";
		std::cin >> id;
		if (isStudentNameExist(res_vec, name) == true && isStudentIDExist(res_vec, id) != -1 && isStudentIDExist(res_vec, id) == isStudentExist(res_vec, name, id))
		{
			stu_obj = isStudentExist(res_vec, name, id);
			std::cout << "\t\t��½�ɹ�����ӭ�㣬" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ��" << std::endl;
			std::cout << "\t\t******������������ѧ���������桪��******\n" << std::endl;
			std::cout << "\t\t";
			system("pause");
			return stu_obj;
			break;
		}
		else std::cout << "\t\t��½ʧ�ܣ��������������ѧ���Ƿ�������ȷ�����߶����Ƿ�ƥ��\n" << std::endl;
	}
	std::cout << "\t\t";
	system("pause");
	return -1;
}

//��ʾ�ض�ѧ���˵�����
void showStudentMenu(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ�����ã�" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*  1����ѯ�γ̳ɼ�                       *" << std::endl;
	std::cout << "\t\t*  2����ѯ�ܳɼ���                       *" << std::endl;
	std::cout << "\t\t*  3��ѡ��һ�ſγ̼�P/F                  *" << std::endl;
	std::cout << "\t\t*  4���鿴�༶ƽ���ɼ�������              *" << std::endl;
	std::cout << "\t\t*  0���˳�ѧ������                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t��ѡ������Ҫ���еĲ������ڼ����������ض����ܶ�Ӧ�����֣���" << std::endl;
	return;
}

//��ʾѧ����������
void studentMenuOperate(std::vector<StudentResults>& res_vec, const int& stu_obj)//��ѧ��������еĲ���
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
			std::cout << "\t\t����������������ȷ������ 0-4 ��" << std::endl;
			break;
		}
		std::cout << "\t\t";
		system("pause");
	}
	std::cout << "\t\t";
	system("pause");
	return;
}

//��ѯ���Ƴɼ�
void studentInquireSingleResult(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::string crs_name;//�γ�����
	int stu_crs_obj = 0;//��λ�γ���ѧ����ѡ��λ��
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ��" << std::endl;
	while (true)
	{
		std::cout << "\t\t��������Ҫ��ѯ�Ŀγ����ƣ�";
		std::cin >> crs_name;
		if (isCourseExist(crs_vec, crs_name) != -1 && isStudentSelectCourse(res_vec, stu_obj, crs_name) != -1) {
			stu_crs_obj = isStudentSelectCourse(res_vec, stu_obj, crs_name);
			break;
		}
		else if (isCourseExist(crs_vec, crs_name) != -1 && isStudentSelectCourse(res_vec, stu_obj, crs_name) == -1) {
			std::cout << "\t\t��δѡ��γ̣� " << crs_name << " ��������������";
		}
		else {
			std::cout << "\t\t������Ŀγ̣� " << crs_name << " �����ڣ�������������";
		}

	}
	const auto& s_c = res_vec[stu_obj].stu_crs[stu_crs_obj];
	std::cout << "\t\t��ѯ�ɹ���" << std::endl;
	std::cout << "\t\t*******************************" << std::endl;
	std::cout << "\t\t�γ̣� " << crs_name << std::endl;
	std::cout << "\t\t������ " << s_c.getStudentCourseScore() << std::endl;
	std::cout << "\t\t�ȼ��� " << Grade[s_c.getStudentCourseGrade()] << std::endl;
	std::cout << "\t\t���㣺 " << s_c.getStudentCourseGPA() << std::endl;
	std::cout << "\t\t*******************************" << std::endl;
	return;
}

//��ѯ���гɼ�
void studentInquireAllResults(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	double sum_gpa = 0;//��ѧ�ּ�
	double sum_credit = 0;//��ѧ����
	double sum_credit_in_gpa = 0;//����GPAѧ����
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ��" << std::endl;
	std::cout << "\t\t����ѡ��ȫ���γ̳ɼ����£�" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	for (const auto& s_c : res_vec[stu_obj].stu_crs) {
		if (s_c.getCourseIsPF() == false) {
			sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
			sum_credit += (double)s_c.getCourseCredit();
			sum_credit_in_gpa += (double)s_c.getCourseCredit();
			std::cout << "\t\t�γ̣� " << s_c.getStudentCourseName() << std::endl;
			std::cout << "\t\t������ " << s_c.getStudentCourseScore();
			std::cout << "  �ȼ��� " << Grade[s_c.getStudentCourseGrade()];
			std::cout << "  ���㣺 " << s_c.getStudentCourseGPA() << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
		}
		else {
			sum_credit += (double)s_c.getCourseCredit();
			std::cout << "\t\t�γ̣� " << s_c.getStudentCourseName() << std::endl;
			std::cout << "\t\t������ " << s_c.getStudentCourseScore();
			std::cout << "  �ȼ��� " << Grade[s_c.getStudentCourseGrade()];
			std::cout << "  ���㣺 " << s_c.getStudentCourseGPA() << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
		}
	}
	//res_vec[stu_obj].GPA = sum_gpa / sum_credit;
	std::cout << "\t\t��GPA�� " << res_vec[stu_obj].GPA << std::endl;
	std::cout << "\t\t��ѧ������ " << sum_credit << " ����GPA��ѧ������ " << sum_credit_in_gpa << " ��ѧ�ּ��� " << sum_gpa << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	return;
}

//ѡ��һ�ſγ̼�PF
void studentSelectOneToPF(std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	system("cls");
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ��" << std::endl;
	if (res_vec[stu_obj].PF_flag != -1) {
		std::cout << "\t\t���Ѿ�P/F��һ�ſγ̣�����Ҫ��" << std::endl;
		std::cout << "\t\t1---�޸ģ�����ѡ��P/Fһ�ſγ�" << std::endl;
		std::cout << "\t\t0---�����޸ģ�ά��ԭP/F�γ�ѡ�񲻱�" << std::endl;
		int input_num;
		while (true)
		{
			std::cout << "\t\t������ 1 �� 0 ��";
			std::cin >> input_num;
			if (input_num == 1) {
				res_vec[stu_obj].stu_crs[res_vec[stu_obj].PF_flag].setCourseIsPF(false);
				res_vec[stu_obj].PF_flag = -1;
				updateStudentResults(res_vec, stu_obj);
				updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
				updateAllClassInfo(res_vec, class_vec);
				std::cout << "\t\t���ѳɹ����γ̣�  " << "ȡ��P/F������������һ��������������ѡ��P/F\n\t\t" << std::endl;
				system("pause");
				break;
			}
			else if (input_num == 0) {
				std::cout << "\t\t���ѷ����ò�����ԭP/F�γ�ѡ�񲻱䣬�����˳���ҳ�桪��\n\t\t";
				system("pause");
				return;
				break;
			}
			else std::cout << "\t\t��Ч���������ֲ��� 1 �� 0" << std::endl;
		}
	}
	std::cout << "\t\t���ڣ�������ѡ��һ�ſγ̣��������۷�ʽ��ΪP/F������������ѡ��Ŀγ̣�" << std::endl;
	std::cout << "\t\t���ѣ���ѡ���Դ�P/F�Ŀγ̣���ò���������Ӱ��" << std::endl;
	std::cout << "\t\t******************************" << std::endl;
	for (int i = 0; i < res_vec[stu_obj].stu_crs.size(); i++) {
		std::cout << "\t\t" << i + 1 << "�� " << res_vec[stu_obj].stu_crs[i].getCourseName() << std::endl;
	}
	std::cout << "\t\t******************************" << std::endl;
	std::cout << "\t\t��ѡ��һ�ſγ̣�����γ���ǰ��Ӧ����ţ�������0���˳�ѡ�񣩣�";
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (1 <= choice && choice <= res_vec[stu_obj].stu_crs.size()) {
			std::cout << "\t\t��ѡ��Ŀγ��ǣ�" << choice << "��" << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << std::endl;
			int sure_num;
			while (true) {
				std::cout << "\t\t��ȷ��Ҫ���伴ΪP/F�𣿣��ÿγ̵ĵȼ���������GPA�Լ��༶����������֮���£�" << std::endl;
				std::cout << "\t\t1---�ǵģ���ȷ��   0---����" << "\n\t\t";
				std::cin >> sure_num;
				if (sure_num == 1) {
					res_vec[stu_obj].stu_crs[sure_num - 1].setCourseIsPF(true);
					res_vec[stu_obj].PF_flag = sure_num - 1;
					updateStudentResults(res_vec, stu_obj);//����
					updateClassInfo(res_vec, class_vec, res_vec[stu_obj].stu.getStudentClass());
					updateAllClassInfo(res_vec, class_vec);
					std::cout << "\t\t���ѳɹ����γ̣� " << res_vec[stu_obj].stu_crs[choice - 1].getCourseName() << "  ��ΪP/F" << std::endl;
					std::cout << "\t\t�������ڸÿγ̵İٷ��Ƴɼ�Ϊ�� " << res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore();
					if (res_vec[stu_obj].stu_crs[choice - 1].getStudentCourseScore() < 60)
						std::cout << "  ��˸ÿγ̽�����Ϊ��F\n\t\t";
					else std::cout << "  ��˸ÿγ̽�����Ϊ��P\n\t\t";
					system("pause");
					return;
				}
				else if (sure_num == 0) {
					std::cout << "\t\t����ȡ��ѡ�񣡼����˳���ҳ�桪��\n\t\t";
					system("pause");
					return;
				}
				else std::cout << "\t\t������Ч����������������1��0��" << std::endl;
			}
		}
		else if (choice == 0) {
			std::cout << "\t\t���ѷ���ѡ�񣡼����˳���ҳ�桪��\n\t\t";
			system("pause");
			return;
		}
		else {
			std::cout << "\t\t�������������ٴ�������ȷ������:  1����" << res_vec[stu_obj].stu_crs.size() << std::endl;
		}
	}
	return;
}

//��ѯ�༶����
void studentInquireClassRanking(const std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	std::cout << "\t\t" << res_vec[stu_obj].stu.getStudentName() << "  ͬѧ��" << std::endl;
	std::cout << "\t\t******************************" << std::endl;
	std::cout << "\t\t�����ڵİ༶��  " << res_vec[stu_obj].stu.getStudentClass() << "  ��" << std::endl;
	std::cout << "\t\t�༶��������  " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].stu_amount << std::endl;
	std::cout << "\t\t�༶ƽ��GPA��  " << class_vec[res_vec[stu_obj].stu.getStudentClass() - 1].aver_GPA << std::endl;
	std::cout << "\t\t������GPA��  " << res_vec[stu_obj].GPA << std::endl;
	std::cout << "\t\t���İ༶������  " << res_vec[stu_obj].ranking << std::endl;
	std::cout << "\t\t******************************\n\t\t";
	system("pause");
	return;
}


//���¸��Ƴɼ��������Ͱ༶����
void updateStudentResults(std::vector<StudentResults>& res_vec, const int& stu_obj)
{
	int class_num = res_vec[stu_obj].stu.getStudentClass();
	double sum_gpa = 0;//��ѧ�ּ�
	double sum_credit = 0;//��ѧ��
	for (auto& s_c : res_vec[stu_obj].stu_crs) {
		s_c.setStudentCourseScore(s_c.getStudentCourseScore());
		sum_credit += (double)s_c.getCourseCredit();
		if (s_c.getCourseIsPF() == false) {
			sum_gpa += s_c.getCourseCredit() * s_c.getStudentCourseGPA();
		}
	}
	res_vec[stu_obj].GPA = sum_gpa / sum_credit;//���¸�ѧ������
	return;
}


//���¸ð༶����ѧ�������Ͱ༶����
void updateClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec, const int& class_num)
{
	double sum_gpa = 0;
	int amount = 0;//�༶����
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


//�������а༶��Ϣ
void updateAllClassInfo(std::vector<StudentResults>& res_vec, std::vector<ClassInfo>& class_vec)
{
	for (int i = 0; i < class_vec.size(); i++) {
		updateClassInfo(res_vec, class_vec, i + 1);
	}
	return;
}


//�Ƚ�ѡͬһ�ſε�����ѧ���ĳɼ�������
bool compareStudentCourseByScore(const StudentCourse& lhs, const StudentCourse& rhs)
{
	return lhs.getStudentCourseScore() < rhs.getStudentCourseScore();
}

//�Ƚ�����ͬ���ѧ����GPA�����ڰ�������������
bool compareStudentByGPA(const StudentResults& lhs, const StudentResults& rhs)
{
	return lhs.GPA < rhs.GPA;
}


//
// 
//��ʦ����
// 
//
//��ʾ��ʦ��½����
int showTeacherLogInMenu(const std::vector<Teacher>& tch_vec, int& tch_obj)
{
	system("cls");
	std::string name, id;
	int flag = 0;
	std::cout << "\t\t******������ʦ��½���桪��******\n\n";
	std::cout << "\t\t���������������͹��ţ����߾���ȷ��ƥ����ܳɹ���¼����" << std::endl;
	while (true)
	{
		std::cout << "\t\t������";
		std::cin >> name;
		std::cout << "\t\t��������빤�ţ�";
		std::cin >> id;
		if (isTeacherIDExist(tch_vec, id) != -1 && isTeacherIDExist(tch_vec, id) == isTeacherNameExist(tch_vec, name) && isTeacherIDExist(tch_vec, id) == isTeacherExist(tch_vec, name, id))
		{
			tch_obj = isTeacherExist(tch_vec, name, id);
			std::cout << "\t\t��½�ɹ�����ӭ����" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ��" << std::endl;
			std::cout << "\t\t******�������������ʦ�������桪��******\n" << std::endl;
			std::cout << "\t\t";
			system("pause");
			return tch_obj;
			break;
		}
		else std::cout << "\t\t��½ʧ�ܣ�������������򹤺��Ƿ�������ȷ�����߶����Ƿ�ƥ��\n" << std::endl;
	}
	std::cout << "\t\t";
	system("pause");
	return -1;
}

//��ʾ��ʦ����˵�
void showTeacherMenu(const std::vector<Teacher>& tch_vec, const int& tch_obj)
{
	system("cls");
	std::cout << tch_vec[tch_obj].getTeacherName() << "  ��ʦ�����ã�" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*  1��¼��γ̳ɼ�                       *" << std::endl;
	std::cout << "\t\t*  2���޸Ŀγ̳ɼ�                       *" << std::endl;
	std::cout << "\t\t*  3���鿴�γ̳ɼ����                   *" << std::endl;
	std::cout << "\t\t*  4���鿴ѧ���ɼ�                       *" << std::endl;
	std::cout << "\t\t*  5���鿴�༶�ɼ�                       *" << std::endl;
	std::cout << "\t\t*  0���˳���ʦ����                       *" << std::endl;
	std::cout << "\t\t*                                       *" << std::endl;
	std::cout << "\t\t*****************************************" << std::endl;
	std::cout << "\t\t��ѡ������Ҫ���еĲ������ڼ����������ض����ܶ�Ӧ�����֣���" << std::endl;
}

//��ʦ��������
void teacherMenuOperate(const std::vector<Teacher>& tch_vec, const int& stu_obj)//��ʦ������еĲ���
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
			std::cout << "\t\t����������������ȷ������ 0-5 ��" << std::endl;
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

//¼��γ̳ɼ�
void teacherEnterResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ���������ڵĿγ��ǣ�  " << crs_vec[tch_obj].getCourseName() << std::endl;
	int choice;
	std::cout << "\t\t�����԰����������ַ�ʽ¼��ɼ���" << std::endl;
	std::cout << "\t\t1---����ѡ��ѧ��������¼��  2---�½�һ��ѡ��ѧ����¼��" << std::endl;
	while (true)
	{
		std::cout << "\t\t����������ѡ��1 / 2����";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "\t\t��������ѡ�ÿε�ѧ��������" << std::endl;
			int num = 0;
			for (auto& res : res_vec) {
				for (auto& s_c : res.stu_crs) {
					if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName()) {
						int score;
						num++;
						std::cout << "\t\t" << num << "��" << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << std::endl;
						while (true)
						{
							std::cout << "\t\t�������ѧ���ĳɼ���";
							std::cin >> score;
							if (0 <= score && score <= 100) {
								s_c.setStudentCourseScore(score);
								std::cout << "\t\t���ѳɹ�¼���ѧ���ĳɼ���" << score << std::endl;
								std::cout << "\t\t���潫������һλѧ���ĳɼ�¼�롪��" << std::endl;
								std::cout << "\t\t";
								system("pause");
								break;
							}
							else std::cout << "\t\t�ɼ���Ч��������������" << std::endl;
						}
						break;
					}
				}
			}
			std::cout << "\t\t������ɶ�����ѧ���ĳɼ�¼�룡" << std::endl;
			return;
		}

		else if (choice == 2) {
			std::cout << "\t\t���棬��������һ���µ�ѡ��ѧ������ѧ����Ĭ��ѡ�����Ŀγ̣�" << std::endl;
			std::string name, id;
			int class_num;
			while (true)
			{
				StudentResults temp_res;
				StudentCourse temp_sc;
				std::cout << "\t\t������ѧ��������";
				std::cin >> name;
				std::cout << "\t\t������ѧ��ѧ��";
				std::cin >> id;
				if (isStudentExist(res_vec, name, id) == -1 || isStudentIDExist(res_vec, id) == -1) {
					std::cout << "\t\t��ѧ���Ѵ��ڻ�ѧ���ѱ�ռ�ã�����������";
					continue;
				}
				std::cout << "\t\t������ѧ���༶���ð༶������ʱ�����Զ������°༶����";
				std::cin >> class_num;
				if (1 <= class_num && class_num <= class_vec.size()) {
					class_vec[class_num - 1].stu_amount++;
				}
				else {
					std::cout << "\t\t�������ڹ���  " << class_vec.size() << "  ���༶��������������һ���µİ༶�� " << class_vec.size() + 1;
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
					std::cout << "\t\t�������ѧ���Ŀγ̳ɼ���";
					std::cin >> score;
					if (0 <= score && score <= 100) {
						temp_sc.setStudentCourseScore(score);
						temp_res.PF_flag = -1;
						res_vec.push_back(temp_res);
						updateStudentResults(res_vec, res_vec.size() - 1);//��ʱѧ�������һ��
						updateClassInfo(res_vec, class_vec, class_num - 1);
						updateAllClassInfo(res_vec, class_vec);
						std::cout << "\t\t���ѳɹ�¼���ѧ���ĳɼ�������" << score << std::endl;
						int next;
						std::cout << "\t\t��Ҫ����¼�룬�밴 1 �������˳�¼�룺";
						std::cin >> next;
						if (next == 1) {
							std::cout << "\t\t����ѡ�����¼�룡" << std::endl;
							std::cout << "\t\t";
							system("pause");
							break;
						}
						else {
							std::cout << "\t\t�������˳�¼�룡" << std::endl;
							std::cout << "\t\t";
							system("pause");
							return;
						}
					}
					else std::cout << "\t\t�ɼ�������Ч������0����100�ڣ���������������" << std::endl;
				}
			}
		}

		else {
			std::cout << "\t\t������Ч����Ҫ����¼�룬�밴 1 �������˳�¼�룺";
			int next;
			std::cin >> next;
			if (next == 1) {
				std::cout << "\t\t����ѡ�����¼�룡" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t�������˳�¼�룡" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}
	}
	return;
}

//�޸Ŀγ̳ɼ�
void teacherModifyResults(std::vector<StudentResults>& res_vec, std::vector<Teacher>& tch_vec, std::vector<Course>& crs_vec, std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ���������ڵĿγ��ǣ�  " << crs_vec[tch_obj].getCourseName() << std::endl;
	std::cout << "\t\t��������ѡ�ÿε�ѧ�����ɼ�������" << std::endl;
	int num = 0;
	std::vector<StudentCourse> temp_vec;
	temp_vec.clear();
	for (const auto& res : res_vec) {
		for (const auto& s_c : res.stu_crs) {
			if (s_c.getCourseName() == crs_vec[tch_obj].getCourseName()) {
				temp_vec.push_back(s_c);
				num++;
				std::cout << "\t\t" << num << "��" << res.stu.getStudentName() << "\t" << res.stu.getStudentID() << "\t" << res.stu.getStudentName() << std::endl;
				break;
			}
		}
	}
	int choice;
	while (true)
	{
		std::cout << "\t\t��ѡ��ѧ������ǰ����ţ�Ȼ��Գɼ������޸ģ�";
		std::cin >> choice;
		if (1 <= choice && choice <= num) {
			std::cout << "\t\t��ѡ���ˣ�" << choice << "��" << temp_vec[choice - 1].getStudentName() << std::endl;
			std::cout << "\t\t��ѧ��Ŀǰ�ĳɼ�Ϊ��" << temp_vec[choice - 1].getStudentCourseScore();
			int score;
			int stuobj = isStudentExist(res_vec, temp_vec[choice - 1].getStudentName(), temp_vec[choice - 1].getStudentID());
			int crsobj = isStudentSelectCourse(res_vec, stuobj, temp_vec[choice - 1].getStudentCourseName());
			while (true)
			{
				std::cout << "\t\t���������޸ĺ�ĳɼ���0����100����";
				std::cin >> score;
				if (0 <= score && score <= 100) {
					int sure;
					std::cout << "\t\t��ȷ��Ҫ���ɼ���" << temp_vec[choice - 1].getStudentCourseScore() << "�޸�Ϊ��" << score << "��" << std::endl;
					std::cout << "\t\t1---ȷ��  0---ȡ��:";
					std::cin >> sure;
					while (true) {
						if (sure == 1) {
							std::cout << "\t\t�޸ĳɹ������ѽ���ɼ��ɣ�" << temp_vec[choice - 1].getStudentCourseScore() << "�޸�Ϊ��" << score << std::endl;
							res_vec[stuobj].stu_crs[crsobj].setStudentCourseScore(score);
							updateStudentResults(res_vec, stuobj);
							updateClassInfo(res_vec, class_vec, res_vec[stuobj].stu.getStudentClass());
							updateAllClassInfo(res_vec, class_vec);
							break;
						}
						else if (sure == 0) {
							std::cout << "\t\t����ȡ�������޸ģ�" << std::endl;
							break;
						}
						else std::cout << "\t\t��Ч������������" << std::endl;
					}
					int next;
					std::cout << "\t\t��Ҫ�����޸ĳɼ��밴 1 �������˳��޸ģ�";
					std::cin >> next;
					if (next == 1) {
						std::cout << "\t\t����ѡ������޸ģ�" << std::endl;
						std::cout << "\t\t";
						system("pause");
						break;
					}
					else {
						std::cout << "\t\t�������˳��޸ģ�" << std::endl;
						std::cout << "\t\t";
						system("pause");
						return;
					}
				}
				else std::cout << "\t\t��������0����100�ڣ���Ч��" << std::endl;
			}
		}
		else std::cout << "\t\t��Ч������������" << std::endl;
	}
	return;
}

//�鿴�γ�����ѧ���ɼ�,��ʦֻ�ܿ����Լ��̵Ŀεĳɼ�
void teacherInquireCourseResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ���������ڵĿγ��ǣ�  " << crs_vec[tch_obj].getCourseName() << std::endl;
	std::cout << "\t\t�����Ǹÿγ̵ĳɼ���������������˳��" << std::endl;
	std::cout << "\t\t����\t�ɼ�\t�ȼ�\t����" << std::endl;
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
		std::cout << "\t\t" << num << "��" << s_c.getStudentName() << "\t" << s_c.getStudentCourseScore() << "\t";
		std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
		num++;
	}
	std::cout << "\t\t-----------------------------------" << std::endl;
	std::cout << "\t\t�����޸ĳɼ�����ǰ������ 2 " << std::endl;
	return;
}

//�鿴ĳ��ѧ�����ųɼ�����ʦ�ܿ�������ѧ���ĳɼ�
void teacherInquireStudentResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ�����ã�" << std::endl;
	std::cout << "\t\t�����԰�������ѧ�Ų鿴����ѧ���ĳɼ�" << std::endl;
	std::cout << "\t\t��������ѯ�밴 1 ����ѧ�Ų�ѯ�밴 2 ��������ѯ������ܲ�Ψһ��ѧ�Ų�ѯ���Ψһ����Ҫ�˳���ѯ�밴 0" << std::endl;
	int choice, isexit;
	while (true)
	{
		std::cout << "\t\t����������ѡ��";
		std::cin >> choice;
		if (choice == 1) {
			std::string name;
			std::cout << "\t\t������ѧ��������";
			std::cin >> name;
			std::cout << "\t\t��Ϊ���ҵ�����ѧ����" << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
			for (const auto& res : res_vec) {
				if (res.stu.getStudentName() == name) {
					std::cout << "\t\t������" << name << "  ѧ�ţ�" << res.stu.getStudentID() << "  �༶��" << res.stu.getStudentClass() << std::endl;
					std::cout << "\t\t��GPA��" << res.GPA << "  �༶������" << res.ranking << std::endl;
					std::cout << "\t\t�����Ǹ��ſγ̳ɼ���" << std::endl;
					std::cout << "\t\t�γ�����\t�γ̳ɼ�\t����\t�ȼ�" << std::endl;
					std::cout << "\t\t---------------------------------" << std::endl;
					for (const auto& s_c : res.stu_crs) {
						std::cout << "\t\t" << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
						std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
					}
					std::cout << "\t\t---------------------------------" << std::endl;
				}
			}
			std::cout << "\t\t*****************************************\n\n";
			std::cout << "\t\t��Ҫ������ѯ���밴 1��";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t����ѡ�������ѯ��" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t��ѡ����ǣ�" << isexit << std::endl;
				std::cout << "\t\t******�����������˳���ѯ����******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}

		else if (choice == 2) {
			std::string id;
			std::cout << "\t\t������ѧ��ѧ�ţ�";
			std::cin >> id;
			std::cout << "\t\t��Ϊ���ҵ�����ѧ����" << std::endl;
			std::cout << "\t\t*****************************************" << std::endl;
			for (const auto& res : res_vec) {
				if (res.stu.getStudentID() == id) {
					std::cout << "\t\t������" << res.stu.getStudentName() << "  ѧ�ţ�" << id << "  �༶��" << res.stu.getStudentClass() << std::endl;
					std::cout << "\t\t��GPA��" << res.GPA << "  �༶������" << res.ranking << std::endl;
					std::cout << "\t\t�����Ǹ��ſγ̳ɼ���" << std::endl;
					std::cout << "\t\t�γ�����\t�γ̳ɼ�\t����\t�ȼ�" << std::endl;
					std::cout << "\t\t---------------------------------" << std::endl;
					for (const auto& s_c : res.stu_crs) {
						std::cout << "\t\t" << s_c.getStudentCourseName() << "\t" << s_c.getStudentCourseScore() << "\t";
						std::cout << s_c.getStudentCourseGPA() << "\t" << Grade[s_c.getStudentCourseGrade()] << std::endl;
					}
					std::cout << "\t\t---------------------------------" << std::endl;
				}
			}
			std::cout << "\t\t*****************************************\n\n";
			std::cout << "\t\t��Ҫ������ѯ���밴 1��";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t����ѡ�������ѯ��" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t��ѡ����ǣ�" << isexit << std::endl;
				std::cout << "\t\t******�����������˳���ѯ����******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}

		else if (choice == 0) {
			std::cout << "\t\t��ѡ���ˣ� 0 " << std::endl;
			std::cout << "\t\t******�����������˳���ѯ������******" << std::endl;
			std::cout << "\t\t";
			system("pause");
			break;
			return;
		}
		else {
			std::cout << "\t\t������Ч��" << std::endl;
		}
	}
	return;
}

//�鿴�༶�ɼ�����ʦ�ܲ鿴���а༶�ĳɼ�
void teacherInquireClassResults(const std::vector<StudentResults>& res_vec, const std::vector<Teacher>& tch_vec, const std::vector<Course>& crs_vec, const std::vector<ClassInfo>& class_vec, const int& tch_obj)
{
	std::cout << "\t\t" << tch_vec[tch_obj].getTeacherName() << "  ��ʦ�����ã�" << std::endl;
	std::cout << "\t\t���鿴���а༶��ѧ���ɼ�״��" << std::endl;
	while (true)
	{
		std::cout << "\t\t��ѡ��༶��1����" << class_vec.size() << " : " << std::endl;
		int class_num;
		std::cin >> class_num;
		if (1 <= class_num && class_num <= class_vec.size()) {
			std::cout << "\t\t��ѡ���˰༶��" << class_num;
			std::cout << "\t\t������" << class_num << "������ѧ����GPA������" << std::endl;
			std::cout << "\t\t����\tGPA\t����" << std::endl;
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
			std::cout << "\t\t�༶��������  " << class_vec[class_num - 1].stu_amount << "  ƽ��GPA��  " << class_vec[class_num - 1].aver_GPA << "\n\n";
			int isexit;
			std::cout << "\t\t��Ҫ������ѯ�������� 1 �������˳���ѯ";
			std::cin >> isexit;
			if (isexit == 1) {
				std::cout << "\t\t����ѡ�������ѯ��" << std::endl;
				std::cout << "\t\t";
				system("pause");
			}
			else {
				std::cout << "\t\t��ѡ����ǣ�" << isexit << std::endl;
				std::cout << "\t\t******�����������˳���ѯ����******" << std::endl;
				std::cout << "\t\t";
				system("pause");
				return;
			}
		}
		else
			std::cout << "\t\t������Ч�����ڷ�Χ 1����" << class_vec.size() << "�ڣ�������ѡ��" << std::endl;
	}
	return;
}
