#include "Header.h"

using namespace std;

vector<Employee> employees = readEmployees();
vector<User> users = readUsers();
vector<User> admins = readAdmins();
vector<Payment> payments = readPayments();
vector<User> requests = readRequests();

// Функция выгрузки в файл заявок на права админа
void ChangeRequests(vector<User>& requests)
{
    ofstream file("requests.txt", ios::trunc);
    for (int i = 0; i < requests.size(); i++)
    {
        file << requests[i].username << " " << requests[i].password << endl;
    }
    file.close();
}

// функция для выгрузки в файл пользователей
void ChangeUsers(vector<User>& users)
{
    ofstream file("users.txt", ios::trunc);
    for (int i = 0; i < users.size(); i++)
    {
        file << users[i].username << " " << users[i].password << endl;
    }
    file.close();
}

// функция для выгрузки в файл админов
void ChangeAdmins(vector<User>& admins)
{
    ofstream file("admins.txt", ios::trunc);
    for (int i = 0; i < admins.size(); i++)
    {
        file << admins[i].username << " " << admins[i].password << endl;
    }
    file.close();
}

// функция для просмотра заявок на права админа
void checkRequests(vector<User>& requests, vector<User>& admins)
{
    system("cls");
    cout << "===== Просмотр заявок на права администратора =====" << endl;
    cout << endl << endl;
    if (requests.empty())
    {
        cout << "Заявок нет." << endl;
        cout << "===============================================" << endl;
        system("pause");
    }
    else
    {
        cout << "| No. |   Логин   |   Пароль   |" << endl;
        for (int i = 0; i < requests.size(); i++)
        {
            cout << "|  " << i + 1 << "  |  " << requests[i].username << "       " << requests[i].password << endl;
            /*printf("| %d  |     %5s  |    %5s    |\n", i + 1 , requests[i].username, requests[i].password);*/
        }
        cout << "+----------------------------+" << endl;
        system("pause");
        cout << "Желаете ли кого-нибудь одобрить?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl;
        int ch;
        cin >> ch;
        if (proverka(ch))
        {
            switch (ch)
            {
            case 1:
            {
                cout << "Введите номер заявки." << endl;
                int req;
                cin >> req;
                if (proverka(req) && req > 0 && req <= requests.size())
                {
                    ofstream file("admins.txt", ios::app);
                    if (file.is_open())
                    {
                        file << requests[req - 1].username << " " << requests[req - 1].password << endl;
                    }
                    file.close();
                    admins.push_back({ requests[req - 1].username, requests[req - 1].password });
                    requests.erase(requests.begin() + req - 1 );
                    ChangeRequests(requests);
                    cout << "Заявка одобрена." << endl;
                    system("pause");
                }
            }
            case 2:
            {
                system("cls");
                return adm_menu();
            }
            default:
            {
                cout << "Некорректный ввод!" << endl;
                return adm_menu();
            }
            }
        }
        else
        {
            cout << "Некорректный ввод!" << endl;
            return adm_menu();
        }
    }
}

// функция подачи заявки на права админа
void request(vector<User>& user, vector<User>& admins)
{
    system("cls");
    cout << "===== Подача заявки на права администратора =====" << endl;
    string login, password;
    cout << "Введите логин." << endl;
    cin >> login;
    cout << "Введите пароль." << endl;
    cin >> password;
    ofstream file("requests.txt", ios::app);
    if (file.is_open())
    {
        file << login << " " << password << endl;
    }
    file.close();
    cout << "Заявка успешно подана." << endl;
}

// Проверка на корректный ввод
bool proverka(int choose)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    else
    {
        return true;
    }
}

// Функция просмотра данных пользователей
void check_users(vector<User> users)
{
    cout << "========== Просмотр данных пользователей ==========" << endl;
    if (users.empty())
    {
        cout << "Пользователи отсутствуют." << endl;
    }
    else
    {
        cout << endl << endl;
        cout << "|Логин:    |    Пароль:   |" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            printf("| %7s  |   %7s    |\n", users[i].username.c_str(), users[i].password.c_str());
        }
    }
    system("pause");
}

// Сортировка по алфавиту( фамилии)
void sort_surname(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "Сортировка..." << endl;
    Employee temp;
    int n = employees.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (employees[j].surname > employees[j + 1].surname)
            {
                swap(employees[j], employees[j + 1]);
                swap(payments[j], payments[j + 1]);
            }
        }
    }
    cout << "Сотрудники отсортированы по алфавиту." << endl << endl;
}

// Сортировка по отделу
void sort_department(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "Сортировка..." << endl;
    Employee temp;
    int n = employees.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (employees[j].department > employees[j + 1].department)
            {
                swap(employees[j], employees[j + 1]);
                swap(payments[j], payments[j + 1]);

            }
        }
    }
    cout << "Сотрудники отсортированы по отделу." << endl << endl;
}

// Сортировка по возрасту
void sort_age(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "Сортировка..." << endl;
    Employee temp;
    int n = employees.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (employees[j].age > employees[j + 1].age)
            {
                swap(employees[j], employees[j + 1]);
                swap(payments[j], payments[j + 1]);
            }
        }
    }
    cout << "Сотрудники отсортированы по возрасту(по возрастанию)." << endl << endl;
}

// Сортировка по стажу
void sort_total(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "Сортировка..." << endl;
    Employee temp;
    int n = employees.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (employees[j].d.total < employees[j + 1].d.total)
            {
                swap(employees[j], employees[j + 1]);
                swap(payments[j], payments[j + 1]);
            }
        }
    }
    cout << "Сотрудники отсортированы по убыванию стажа." << endl << endl;
}

// Редактирование сотрудника
void change(vector<Employee>& employees)
{
    system("cls");
    string surname3;
    int ch4;
    int l = 0;
    cout << "=============== Редактирование сотрудникa ===============" << endl;
    cout << "Введите фамилию сотрудника" << endl;
    cin >> surname3;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].surname == surname3)
        {
            l++;
            cout << "Сотрудник " << employees[i].surname << " " << employees[i].name << " " << employees[i].patronymic << " найден.Что хотите изменить ? " << endl;
            cout << "1 - Фамилию." << endl;
            cout << "2 - Имя." << endl;
            cout << "3 - Отчество." << endl;
            cout << "4 - День рождения." << endl;
            cout << "5 - Месяц рождения." << endl;
            cout << "6 - Год рождения." << endl;
            cout << "7 - День начала работы." << endl;
            cout << "8 - Месяц начала работы." << endl;
            cout << "9 - Год начала работы." << endl;
            cout << "0 - Выход." << endl;
            cout << "Выберите..." << endl;
            cin >> ch4;
            if (proverka(ch4))
            {
                switch (ch4)
                {
                case 1:
                {
                    string nsurname;
                    cout << "Введите новую фамилию." << endl;
                    cin >> nsurname;
                    employees[i].surname = nsurname;
                    cout << "Фамилия изменена." << endl;
                    return adm_menu();
                }
                case 2:
                {
                    string nname;
                    cout << "Введите новое имя." << endl;
                    cin >> nname;
                    employees[i].name = nname;
                    cout << "Имя изменено." << endl;
                    return adm_menu();
                }
                case 3:
                {
                    string npatronymic;
                    cout << "Введите новое отчество." << endl;
                    cin >> npatronymic;
                    employees[i].patronymic = npatronymic;
                    cout << "Отчество изменено." << endl;
                    return adm_menu();
                }
                case 4:
                {
                    int nday;
                    cout << "Введите новый день рождения." << endl;
                    cin >> nday;
                    if (nday >= 1 && nday <= 31)
                    {
                        employees[i].dbirth = nday;
                        cout << "День рождения изменен." << endl;
                        employees[i].age = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 5:
                {
                    int nmonth;
                    cout << "Введите новый месяц рождения." << endl;
                    cin >> nmonth;
                    if (nmonth >= 1 && nmonth <= 12)
                    {
                        employees[i].mbirth = nmonth;
                        cout << "Месяц рождения изменен." << endl;
                        employees[i].age = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 6:
                {
                    int nyear;
                    cout << "Введите новый год рождения." << endl;
                    cin >> nyear;
                    if (nyear < 2024 && nyear>1900 && nyear < employees[i].d.year)
                    {
                        employees[i].ybirth = nyear;
                        employees[i].age = ((2023 * 365) - (nyear * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        cout << "Год рождения изменен." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 7:
                {
                    int day0;
                    cout << "Введите новый день начала работы." << endl;
                    cin >> day0;
                    if (day0 <= 31 && day0 >= 1)
                    {
                        employees[i].d.year = day0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "Год начала работы изменен." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 8:
                {
                    int month0;
                    cout << "Введите новый месяц начала работы." << endl;
                    cin >> month0;
                    if (month0 <= 12 && month0 >= 1)
                    {
                        employees[i].d.month = month0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "Месяц начала работы изменен." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 9:
                {
                    int year0;
                    cout << "Введите новый год начала работы." << endl;
                    cin >> year0;
                    if (year0 > 1900 && year0 < 2024 && year0>employees[i].ybirth)
                    {
                        employees[i].d.year = year0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "Год начала работы изменен." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "Некорректный ввод..." << endl;
                        return adm_menu();
                    }
                }
                case 0:
                {
                    system("cls");
                    cout << "Вы отменили своё решение." << endl;
                    return adm_menu();
                }
                default:
                {
                    cout << "Неверный ввод. Повторите попытку позже." << endl;
                    return adm_menu();
                }
                }
            }
        }
    }
    if (l == 0)
    {
        cout << "Сотрудников с фамилией " << surname3 << " не найдено." << endl << endl;
    }
}

// Функция вывода сотрудников пенсионного возраста
void out_pv(vector<Employee> employees, vector<Payment>& payments)
{
    int p = 0;
    system("cls");
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].age > 65)
        {
            p++;
        }
    }
    if (p > 0)
    {
        cout << "Сотрудники пенсионного возраста: " << endl;
        printTableHeader();
        for (int i = 0; i < employees.size() && i < payments.size(); i++)
        {
            if (employees[i].age > 65)
            {
                printf("|%14s |%10s |%13s |%4d.%2d.%4d   |%9d     |%10s |%10s     | %5d.%2d.%4d      |%9d     | %5f , %5f\n", employees[i].surname.c_str(), employees[i].name.c_str(), employees[i].patronymic.c_str(), employees[i].dbirth, employees[i].mbirth, employees[i].ybirth, employees[i].age, employees[i].department.c_str(), employees[i].position.c_str(), employees[i].d.day, employees[i].d.month, employees[i].d.year, employees[i].d.total, payments[i].rate, payments[i].salary);
            }
        }
        printTableFooter();
    }
    else
    {
        cout << "Нет сотрудников пенсионного возраста." << endl;
    }
}

// Меню администратора
void adm_menu()
{
    while (true)
    {
        int ch;
        cout << "=============== Меню Администратора ===============" << endl;
        cout << "1 - Зарегистрировать нового пользователя." << endl;
        cout << "2 - Добавить нового сотрудника." << endl;
        cout << "3 - Вывести сотрудников." << endl;
        cout << "4 - Поиск сотрудника." << endl;
        cout << "5 - Удалить сотрудника." << endl;
        cout << "6 - Сортировка сотрудников." << endl;
        cout << "7 - Редактировать сотрудника." << endl;
        cout << "8 - Просмотреть данные пользователей(логин и пароль)." << endl;
        cout << "9 - Просмотр заявок на права администратора." << endl;
        cout << "0 - Выход из системы." << endl;
        cout << "=============== =================== ===============" << endl << endl << endl;
        cout << "Выберите: ";
        cin >> ch;
        if (!proverka(ch))
        {
            cout << "Неверный ввод. Повторите..." << endl;
            return adm_menu();
        }
        else
        {
            switch (ch)
            {
            case 1:
            {
                registerUser(users); return adm_menu();
            }
            case 2:
            {
                registerEmployee(employees); return adm_menu();
            }
            case 3:
            {
                OutEmployee(employees, payments); return adm_menu();
            }
            case 4:
            {
                cout << "========== Поиск сотрудника ==========" << endl;
                cout << "1 - по фамилии." << endl;
                cout << "2 - по отделу." << endl;
                cout << "3 - по должности." << endl;
                cout << "======================================" << endl << endl << endl;
                cout << "Выберите..." << endl;
                int ch1;
                cin >> ch1;
                if (proverka(ch1))
                {
                    switch (ch1)
                    {
                    case 1:
                    {
                        find_surname(employees, payments);
                        return adm_menu();
                    }
                    case 2:
                    {
                        find_department(employees, payments);
                        return adm_menu();
                    }
                    case 3:
                    {
                        find_position(employees, payments);
                        return adm_menu();
                    }
                    }
                }
                else
                {
                    cout << "Ошибка ввода, повторите попытку..." << endl;
                    return adm_menu();
                }
            }
            case 5:
            {
                del_employee(employees, payments);
                return adm_menu();
            }
            case 6:
            {
                system("cls");
                cout << "========== Сортировка ==========" << endl;
                cout << "1 - По фамилии(по алфавиту)" << endl;
                cout << "2 - По возрасту(по возрастанию)" << endl;
                cout << "3 - По отделу(по алфавиту)" << endl;
                cout << "4 - По стажу(по убыванию)" << endl;
                cout << "0 - Отмена." << endl;
                cout << "================================" << endl;
                cout << "Выберите..." << endl;
                int ch;
                cin >> ch;
                if (proverka(ch))
                {
                    switch (ch)
                    {
                    case 1:
                    {
                        sort_surname(employees, payments);
                        return adm_menu();
                    }
                    case 2:
                    {
                        sort_age(employees, payments);
                        return adm_menu();
                    }
                    case 3:
                    {
                        sort_department(employees, payments);
                        return adm_menu();
                    }
                    case 4:
                    {
                        sort_total(employees, payments);
                        return adm_menu();
                    }
                    case 0:
                    {
                        cout << "Вы отменили своё решение." << endl;
                        return adm_menu();
                    }
                    default:
                    {
                        cout << "Неверный ввод. Повторите попытку позже." << endl;
                        return adm_menu();
                    }
                    }
                }
            }
            case 7:
            {
                system("cls");
                change(employees);
                return adm_menu();
            }
            case 8:
            {
                system("cls");
                check_users(users);
                return adm_menu();
            }
            case 9:
            {
                checkRequests(requests, admins);
                return adm_menu();
            }
            case 0:
            {
                system("cls");
                cout << "Вы вышли из системы..." << endl; return gl_menu();
            }
            default:
            {
                cout << "Неверный ввод. Повторите попытку позже." << endl;
                return adm_menu();
            }
            }
        }
    }
}

//  Меню пользователя
void user_menu()
{
    while (true)
    {
        cout << "=============== Меню Пользователя ===============" << endl;
        cout << "1 - Просмотреть всех сотрудников." << endl;
        cout << "2 - Сортировка сотрудников." << endl;
        cout << "3 - Поиск сотрудника." << endl;
        cout << "4 - Вывести сотрудников пенсионного возраста." << endl;
        cout << "5 - Подать заявку на администратора." << endl;
        cout << "0 - Выход из системы." << endl;
        cout << "=============== ================= ===============" << endl;
        cout << endl << endl << endl;
        cout << "Выберите: " << endl;
        int ch;
        cin >> ch;
        if (proverka(ch))
        {
            switch (ch)
            {
            case 1:
            {
                OutEmployee(employees, payments);
                return user_menu();
            }
            case 2:
            {
                system("cls");
                cout << "========== Сортировка ==========" << endl;
                cout << "1 - По фамилии(по алфавиту)" << endl;
                cout << "2 - По возрасту(по возрастанию)" << endl;
                cout << "3 - По отделу(по алфавиту)" << endl;
                cout << "4 - По стажу(по убыванию)" << endl;
                cout << "0 - Отмена." << endl;
                cout << "================================" << endl;
                cout << "Выберите..." << endl;
                int ch;
                cin >> ch;
                if (proverka(ch))
                {
                    switch (ch)
                    {
                    case 1:
                    {
                        sort_surname(employees, payments);
                        return user_menu();
                    }
                    case 2:
                    {
                        sort_age(employees, payments);
                        return user_menu();
                    }
                    case 3:
                    {
                        sort_department(employees, payments);
                        return user_menu();
                    }
                    case 4:
                    {
                        sort_total(employees, payments);
                        return user_menu();
                    }
                    case 5:
                    {
                        request(users, admins);
                        return user_menu();
                    }
                    case 0:
                    {
                        cout << "Вы отменили своё решение." << endl;
                        return user_menu();
                    }
                    default:
                    {
                        cout << "Неверный ввод. Повторите попытку позже." << endl;
                        return user_menu();
                    }
                    }
                }
            }
            case 3:
            {
                cout << "========== Поиск сотрудника ==========" << endl;
                cout << "1 - по фамилии." << endl;
                cout << "2 - по отделу." << endl;
                cout << "3 - по должности." << endl;
                cout << "0 - Отмена." << endl;
                cout << "======================================" << endl << endl << endl;
                cout << "Выберите..." << endl;
                int ch2;
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                {
                    find_surname(employees, payments);
                    return user_menu();
                }
                case 2:
                {
                    find_department(employees, payments);
                    return user_menu();
                }
                case 3:
                {
                    find_position(employees, payments);
                    return user_menu();
                }
                case 0:
                {
                    system("cls");
                    return user_menu();
                }
                }
            }
            case 4:
            {
                out_pv(employees, payments);
                return user_menu();
            }
            case 5:
            {
                request(users, admins);
                return user_menu();
            }
            case 0:
            {
                system("cls");
                cout << "Вы вышли из системы..." << endl;
                system("pause");
                return gl_menu();
            }
            default:
            {
                cout << "Неверный ввод, повторите попытку..." << endl;
                return user_menu();
            }
            }
        }
        else
        {
            cout << "Неверный ввод, повторите попытку..." << endl;
            return user_menu();
        }
    }
}

// Главное меню
void gl_menu()
{
    while (true)
    {
        int ch;
        cout << "=============== Главное меню ===============" << endl;
        cout << "1 - Войти в систему(как пользователь)." << endl;
        cout << "2 - Войти в систему(как администратор)." << endl;
        cout << "3 - Регистрация пользователя." << endl;
        cout << "0 - Выход." << endl;
        cout << "============================================";
        cout << endl << endl << endl;
        cout << "Выберите:" << endl;
        cin >> ch;
        if (proverka(ch))
        {
            switch (ch)
            {
            case 1:
            {
                if (loginUser(users))
                {
                    cout << "Авторизация прошла успешно.\n" << endl << endl << endl;
                    system("pause");
                    system("cls");
                    user_menu();
                }

                else
                {
                    cout << "Ошибка авторизации. Неверное имя пользователя или пароль.\n";
                }
                break;
            }
            case 2:
            {
                if (loginAdmin(admins))
                {
                    cout << "Авторизация прошла успешно.\n" << endl << endl << endl;
                    system("pause");
                    system("cls");
                    adm_menu();
                }

                else
                {
                    cout << "Ошибка авторизации. Неверное имя пользователя или пароль.\n";
                }
                break;
            }
            case 3: {registerUser(users); break; }
            case 0: { 
                system("cls");
                cout << "Вы вышли из системы." << endl;
                system("pause");
                ChangeEmployee(employees, payments);
                
                ChangeUsers(users);
                
                exit(0); 
            }
            default:
            {
                cout << "Неверный ввод. Повторите попытку." << endl;
                return gl_menu();
            }
            }
        }
        else
        {
            cout << "Неверный ввод. Повторите попытку." << endl;
            return gl_menu();
        }
    }
}

// Функция удаления сотрудника
void del_employee(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    string surname;
    int k = 0;
    cout << "========== Удаление сотрудника ==========" << endl;
    cout << endl << endl << endl;
    cout << "Введите фамилию сотрудника." << endl;
    cin >> surname;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].surname == surname)
        {
            k++;
            employees.erase(employees.begin() + i);
            payments.erase(payments.begin() + i);
            cout << "Сотрудник удалён." << endl;
            break;
        }
    }
    if (k == 0)
    {
        cout << "Сотрудник не найден." << endl;
    }
    k = 0;
}

// Функция поиска по фамилии
void find_surname(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string surname;
    system("cls");
    cout << "========== Поиск по фамилии ==========" << endl;
    cout << "Введите фамилию." << endl;
    cin >> surname;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].surname == surname)
        {
            k++;
            if (k == 1)
            {
                printTableHeader();
            }
            printf("|%14s |%10s |%13s |%4d.%2d.%4d   |%9d     |%10s |%10s     | %5d.%2d.%4d      |%9d     | %5f , %5f\n", employees[i].surname.c_str(), employees[i].name.c_str(), employees[i].patronymic.c_str(), employees[i].dbirth, employees[i].mbirth, employees[i].ybirth, employees[i].age, employees[i].department.c_str(), employees[i].position.c_str(), employees[i].d.day, employees[i].d.month, employees[i].d.year, employees[i].d.total, payments[i].rate, payments[i].salary);
        }
    }
    if (k == 0)
    {
        cout << "Не найдено сотрудников." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// Функция поиска по отделу
void find_department(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string department;
    system("cls");
    cout << "========== Поиск по отделу ==========" << endl;
    cout << "Введите отдел." << endl;
    cin >> department;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].department == department)
        {
            k++;
            if (k == 1)
            {
                printTableHeader();
            }
            printf("|%14s |%10s |%13s |%4d.%2d.%4d   |%9d     |%10s |%10s     | %5d.%2d.%4d      |%9d     | %5f , %5f\n", employees[i].surname.c_str(), employees[i].name.c_str(), employees[i].patronymic.c_str(), employees[i].dbirth, employees[i].mbirth, employees[i].ybirth, employees[i].age, employees[i].department.c_str(), employees[i].position.c_str(), employees[i].d.day, employees[i].d.month, employees[i].d.year, employees[i].d.total, payments[i].rate, payments[i].salary);
        }
    }
    if (k == 0)
    {
        cout << "Не найдено сотрудников." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// Функция поиска по должности
void find_position(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string position;
    system("cls");
    cout << "========== Поиск по Должности ==========" << endl;
    cout << "Введите должность." << endl;
    cin >> position;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].position == position)
        {
            k++;
            if (k == 1)
            {
                printTableHeader();
            }
            printf("|%14s |%10s |%13s |%4d.%2d.%4d   |%9d     |%10s |%10s     | %5d.%2d.%4d      |%9d     | %5f , %5f\n", employees[i].surname.c_str(), employees[i].name.c_str(), employees[i].patronymic.c_str(), employees[i].dbirth, employees[i].mbirth, employees[i].ybirth, employees[i].age, employees[i].department.c_str(), employees[i].position.c_str(), employees[i].d.day, employees[i].d.month, employees[i].d.year, employees[i].d.total, payments[i].rate, payments[i].salary);
        }
    }
    if (k == 0)
    {
        cout << "Не найдено сотрудников." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// Вывод головы таблицы
void printTableHeader()
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    cout << "|    Фамилия    |    Имя    |   Отчество   | Дата рождения | Возраст(лет) |   Отдел   |   Должность   | Дата начала работы |  Стаж(дней)  |  Ставка |  Зарплата(руб) |\n";
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
}

// Вывод хвоста таблицы
void printTableFooter()
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
}

// Вывод сотрудников
void OutEmployee(vector<Employee>& employees, vector<Payment>& payments)
{
    if (employees.empty())
    {
        system("cls");
        cout << "Сотрудники отсутствуют." << endl;
    }
    else
    {
        printTableHeader();
        for (int i = 0; i < employees.size() && i < payments.size(); i++)
        {
            printf("|%14s |%10s |%13s |%4d.%2d.%4d   |%9d     |%10s |%10s     | %5d.%2d.%4d      |%9d     | %5.2f   |   %10.2f   |\n", employees[i].surname.c_str(), employees[i].name.c_str(), employees[i].patronymic.c_str(), employees[i].dbirth, employees[i].mbirth, employees[i].ybirth, employees[i].age, employees[i].department.c_str(), employees[i].position.c_str(), employees[i].d.day, employees[i].d.month, employees[i].d.year, employees[i].d.total, payments[i].rate, payments[i].salary);
        }
        printTableFooter();
    }
    system("pause");
}

// Функция для проверки существования адмнистратора в списке
bool adminExists(vector<User> admins, string username)
{
    for (int i = 0; i < admins.size(); i++)
    {
        if (admins[i].username == username)
        {
            return true;
        }
    }
    return false;
}

// Функция для проверки существования пользователя в списке
bool userExists(vector<User> users, string username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].username == username)
        {
            return true;
        }
    }
    return false;
}

// Функция для выгрузки из вектора в файл сотрудников
void ChangeEmployee(vector<Employee>& employees, vector<Payment>& payments)
{
    ofstream file("employees.txt", ios::trunc);
    for (int i = 0; i < employees.size(); i++)
    {
        file << employees[i].surname << " " << employees[i].name << " " << employees[i].patronymic << " " << employees[i].dbirth << " " << employees[i].mbirth << " " << employees[i].ybirth << " " << employees[i].age << " " << employees[i].department << " " << employees[i].position << " " << employees[i].d.day << " " << employees[i].d.month << " " << employees[i].d.year << " " << employees[i].d.total <<endl;
    }
    file.close();
    ofstream file1("payments.txt", ios::trunc);
    for (int i = 0; i < payments.size(); i++)
    {
        file1 << payments[i].rate << " " << payments[i].salary << endl;
    }
    file1.close();
}

//Функция для добавления нового сотрудника
void registerEmployee(vector<Employee>& employees)
{
    cout << "========== Добавление нового сотрудника ==========" << endl;
    string surname, name, patronymic, department, position;
    int day, month, year, age, total, dbirth, mbirth, ybirth;
    double rate, salary;
    cout << "Введите фамилию." << endl;
    cin >> surname;
    cout << "Введите имя." << endl;
    cin >> name;
    cout << "Введите отчество." << endl;
    cin >> patronymic;
    cout << "Введите дату рождения." << endl;
    cout << "День: ";
    cin >> dbirth;
    if (proverka(dbirth))
    {
        if (dbirth < 1 || dbirth>31)
        {
            cout << "Неверный ввод. Повторите попытку." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    cout << "Месяц: ";
    cin >> mbirth;
    if (proverka(mbirth))
    {
        if (mbirth < 1 || mbirth>12)
        {
            cout << "Неверный ввод. Повторите попытку." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    cout << "Год: ";
    cin >> ybirth;
    if (proverka(ybirth))
    {
        if (ybirth > 2023)
        {
            cout << "Неверный ввод. Повторите попытку." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }

    age = (2024 * 365 - (ybirth * 365 + mbirth * 31 + dbirth)) / 365;

    cout << "Введите отдел." << endl;
    cin >> department;
    cout << "Введите должность." << endl;
    cin >> position;
    cout << "Введите число начала работы." << endl;
    cin >> day;
    if (!proverka(day))
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    cout << "Введите месяц начала работы." << endl;
    cin >> month;
    if (!proverka(month))
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
         cout << "Введите год начала работы." << endl;
         cin >> year;
    if (!proverka(year))
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    total = (2023 * 365 - (year * 365 + month * 31 + day));
    cout << "Введите процентную ставку." << endl;
    cin >> rate;
    if (!proverka(rate))
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    cout << "Введите заработную плату(в рублях)" << endl;
    cin >> salary;
    if (!proverka(salary))
    {
        cout << "Неверный ввод. Повторите попытку." << endl;
        return adm_menu();
    }
    employees.push_back({ surname, name, patronymic, dbirth, mbirth, ybirth, age, department, position, day, month, year, total });
    payments.push_back({ rate, salary });
    ofstream file("employees.txt", ios::app);
    file << surname << " " << name << " " << patronymic << " " << dbirth << " " << mbirth << " " << ybirth << " " << age << " " << department << " " << position << " " << day << " " << month << " " << year << " " << total << endl;
    file.close();
    ofstream file1("payments.txt", ios::app);
    file1 << rate << " " << salary << endl;
    file1.close();
    cout << "Сотрудник занесён в базу данных." << endl;
}

// Функция для регистрации нового пользователя
//void registerUser(vector<User>& users)
//{
//    cout << "=============== Регистрация нового пользователя ===============" << endl;
//    string username, password;
//    cout << "Введите имя пользователя: ";
//    cin >> username;
//    if (userExists(users, username))
//    {
//        cout << "Пользователь с таким именем уже существует.\n";
//        return;
//    }
//    cout << "Введите пароль: ";
//    cin >> password;
//    users.push_back({ username, password });
//    ofstream file("users.txt", ios::app);
//    file << username << " " << password << endl;
//    file.close();
//    cout << "Пользователь успешно зарегистрирован." << endl;
//}

void registerUser(vector<User>& users)
{
    cout << "=============== Регистрация нового пользователя ===============" << endl;
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;
    if (userExists(users, username))
    {
        cout << "Пользователь с таким именем уже существует.\n";
        return;
    }
    cout << "Введите пароль: ";
    cin >> password;
    string encryptedPassword = encryptPassword(password, "my-secret-key");
    users.push_back({ username, encryptedPassword });
    ofstream file("users.txt", ios::app);
    file << username << " " << encryptedPassword << endl;
    file.close();
    cout << "Пользователь успешно зарегистрирован." << endl;
}

// Функция для регистрации администратора
void registerAdmin(vector<User>& admins)
{
    cout << "=============== Регистрация нового администратора ===============" << endl;
    string username, password;
    cout << "Введите логин администратора: ";
    cin >> username;
    if (adminExists(admins, username))
    {
        cout << "Администратор с таким именем уже существует.\n";
        return;
    }
    cout << "Введите пароль: ";
    cin >> password;
    admins.push_back({ username, password });
    ofstream file("admins.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Администратор успешно зарегистрирован.\n";
}

// Функция для авторизации пользователя
//bool loginUser(vector<User> users)
//{
//    system("cls");
//    string username, password;
//    cout << "=====   Войти в систему как пользователь   =====" << endl << endl << endl;
//    cout << "Введите логин пользователя." << endl;
//    cin >> username;
//    cout << "Введите пароль." << endl;
//    cin >> password;
//    cout << "=================================================" << endl;
//    for (int i = 0; i < users.size(); i++)
//    {
//        if (users[i].username == username && users[i].password == password)
//        {
//            return true;
//        }
//    }
//    return false;
//}


bool loginUser(vector<User> users)
{
    system("cls");
    string username, password;
    cout << "=====   Войти в систему как пользователь   =====" << endl << endl << endl;
    cout << "Введите логин пользователя." << endl;
    cin >> username;
    cout << "Введите пароль." << endl;
    cin >> password;
    cout << "=================================================" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].username == username && users[i].password == decryptPassword(password, "my-secret-key"))
        {
            return true;
        }
    }
    return false;
}
// Функция для авторизации администратора
bool loginAdmin(vector<User> admins)
{
    system("cls");
    string username, password;
    cout << "=====   Войти в систему как администратор   =====" << endl << endl << endl;
    cout << "Введите логин администратора." << endl;
    cin >> username;
    cout << "Введите пароль." << endl;
    cin >> password;
    cout << "=================================================" << endl;
    for (int i = 0; i < admins.size(); i++)
    {
        if (admins[i].username == username && admins[i].password == password)
        {
            return true;
        }
    }
    return false;
}

// Функция для чтения списка сотрудников из файла
vector<Employee> readEmployees()
{
    vector<Employee> employees;
    ifstream file("employees.txt");
    if (file.is_open())
    {
        string surname, name, patronymic, department, position;
        int day, month, year, age, total, dbirth, mbirth, ybirth;
        while (file >> surname >> name >> patronymic >> dbirth >> mbirth >> ybirth >> age >> department >> position >> day >> month >> year >> total)
        {
            employees.push_back({ surname, name, patronymic, dbirth, mbirth, ybirth, age, department, position, day, month, year, total });
        }
        file.close();
    }
    return employees;
}

// Функция для чтения списка пользователей из файла
vector<User> readUsers()
{
    vector<User> users;
    ifstream file("users.txt");
    if (file.is_open())
    {
        string username, password;
        while (file >> username >> password)
        {
            users.push_back({ username, password });
        }
        file.close();
    }
    return users;
}

// Функция для чтения списка администраторов из файла
vector<User> readAdmins()
{
    vector<User> admins;
    ifstream file("admins.txt");
    if (file.is_open())
    {
        string username, password;
        while (file >> username >> password)
        {
            admins.push_back({ username,password });
        }
        file.close();
    }
    return admins;
}

vector<Payment> readPayments()
{
    vector<Payment> payments;
    ifstream file("payments.txt");
    if (file.is_open())
    {
        double rate, salary;
        while (file >> rate >> salary)
        {
            payments.push_back({ rate, salary });
        }
        file.close();
    }
    return payments;
}

vector<User> readRequests()
{
    vector<User> requests;
    ifstream file("requests.txt");
    if (file.is_open())
    {
        string login, password;
        while (file >> login >> password)
        {
            requests.push_back({ login, password });
        }
        file.close();
    }
    return requests;
}


string encryptPassword(const string& password, const string& key)
{
    string encryptedPassword = password;
    for (int i = 0; i < password.size(); i++)
    {
        encryptedPassword[i] = password[i] ^ key[i % key.size()];
    }
    return encryptedPassword;
}

string decryptPassword(const string& encryptedPassword, const string& key)
{
    string decryptedPassword = encryptedPassword;
    for (int i = 0; i < encryptedPassword.size(); i++)
    {
        decryptedPassword[i] = encryptedPassword[i] ^ key[i % key.size()];
    }
    return decryptedPassword;
}
