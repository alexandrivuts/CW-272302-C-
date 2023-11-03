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
void check_users(vector<User> users); // Функция просмотра данных пользователей
void sort_surname(vector<Employee>& employees, vector<Payment>& payments); // Сортировка по фамилии
void sort_age(vector<Employee>& employees, vector<Payment>& payments);// Сортировка по возрасту
void sort_total(vector<Employee>& employees, vector<Payment>& payments);// Сортировка по стажу
void sort_department(vector<Employee>& employees, vector<Payment>& payments);// Сортировка по отделу
void printTableHeader(); // Вывод головы таблицы
void printTableFooter(); // Вывод конца таблицы
bool proverka(int choose); // Проверка на правильный ввод
void gl_menu();// Главное меню
void adm_menu();// Меню администратора
void user_menu(); // Меню пользователя
void change(vector<Employee>& employees); // Функция редактирования записей
void find_surname(vector<Employee> employees, vector<Payment> payments); //Функция для поиска по фамилии
void find_department(vector<Employee> employees, vector<Payment> payments); // Функция для поиска по отделу
void find_position(vector<Employee> employees, vector<Payment> payments); // Функция для поиска по должности
void del_employee(vector<Employee>&, vector<Payment>& payments); // Функция для удаления сотрудника
void OutEmployee(vector<Employee>& employees, vector<Payment>& payments); // функция вывода всех сотрудников на экран.
void out_pv(vector<Employee>); // Функция вывода сотрудников пенсионного возраста.
bool adminExists(vector<User> admins, string username); // функция для проверки существования админов в списке
bool userExists(vector<User> users, string username); //функция для проверки существования пользователей в списке
void ChangeEmployee(vector<Employee>& employee, vector<Payment>& payments);
void registerEmployee(vector<Employee>& employees); // функция для регистрации сотрудника 
void registerAdmin(vector<User>& admins);  // функция регистрации администратора
void registerUser(vector<User>& users); // функция регистрации пользователя
bool loginAdmin(vector<User> admins);   // функция авторизации(как администратора)
bool loginUser(vector<User> users); // функция авторизации(как пользователя)
vector<User> readAdmins(); // функция для чтения администраторов из файла
vector<User> readUsers(); // функция для чтения пользователей из файла
vector<Employee> readEmployees(); // функция для чтения сотрудников из файла
vector<Payment> readPayments(); 
vector<User> readRequests();