#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Payment
{
    double rate;
    double salary;
};

struct Date
{
    int day;
    int month;
    int year;
    int total;
};

struct Employee
{
    string surname;
    string name;
    string patronymic;
    int dbirth;
    int mbirth;
    int ybirth;
    int age;
    string department;
    string position;
    struct Date d;
};

struct User
{
    string username;
    string password;
};

string encryptPassword(const string& password, const string& key);
string decryptPassword(const string& encryptedPassword, const string& key);
void ChangeUsers(vector<User>& users);
void ChangeAdmins(vector<User>& admins);
void checkRequests(vector<User>& requests, vector<User>& admins);
void request(vector<User>& user, vector<User>& admins);
void check_users(vector<User> users); // ������� ��������� ������ �������������
void sort_surname(vector<Employee>& employees, vector<Payment>& payments); // ���������� �� �������
void sort_age(vector<Employee>& employees, vector<Payment>& payments);// ���������� �� ��������
void sort_total(vector<Employee>& employees, vector<Payment>& payments);// ���������� �� �����
void sort_department(vector<Employee>& employees, vector<Payment>& payments);// ���������� �� ������
void printTableHeader(); // ����� ������ �������
void printTableFooter(); // ����� ����� �������
bool proverka(int choose); // �������� �� ���������� ����
void gl_menu();// ������� ����
void adm_menu();// ���� ��������������
void user_menu(); // ���� ������������
void change(vector<Employee>& employees); // ������� �������������� �������
void find_surname(vector<Employee> employees, vector<Payment> payments); //������� ��� ������ �� �������
void find_department(vector<Employee> employees, vector<Payment> payments); // ������� ��� ������ �� ������
void find_position(vector<Employee> employees, vector<Payment> payments); // ������� ��� ������ �� ���������
void del_employee(vector<Employee>&, vector<Payment>& payments); // ������� ��� �������� ����������
void OutEmployee(vector<Employee>& employees, vector<Payment>& payments); // ������� ������ ���� ����������� �� �����.
void out_pv(vector<Employee>); // ������� ������ ����������� ����������� ��������.
bool adminExists(vector<User> admins, string username); // ������� ��� �������� ������������� ������� � ������
bool userExists(vector<User> users, string username); //������� ��� �������� ������������� ������������� � ������
void ChangeEmployee(vector<Employee>& employee, vector<Payment>& payments);
void registerEmployee(vector<Employee>& employees); // ������� ��� ����������� ���������� 
void registerAdmin(vector<User>& admins);  // ������� ����������� ��������������
void registerUser(vector<User>& users); // ������� ����������� ������������
bool loginAdmin(vector<User> admins);   // ������� �����������(��� ��������������)
bool loginUser(vector<User> users); // ������� �����������(��� ������������)
vector<User> readAdmins(); // ������� ��� ������ ��������������� �� �����
vector<User> readUsers(); // ������� ��� ������ ������������� �� �����
vector<Employee> readEmployees(); // ������� ��� ������ ����������� �� �����
vector<Payment> readPayments(); 
vector<User> readRequests();