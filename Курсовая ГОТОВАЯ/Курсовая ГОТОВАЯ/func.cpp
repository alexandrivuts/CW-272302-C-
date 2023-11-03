#include "Header.h"

using namespace std;

vector<Employee> employees = readEmployees();
vector<User> users = readUsers();
vector<User> admins = readAdmins();
vector<Payment> payments = readPayments();
vector<User> requests = readRequests();

// ������� �������� � ���� ������ �� ����� ������
void ChangeRequests(vector<User>& requests)
{
    ofstream file("requests.txt", ios::trunc);
    for (int i = 0; i < requests.size(); i++)
    {
        file << requests[i].username << " " << requests[i].password << endl;
    }
    file.close();
}

// ������� ��� �������� � ���� �������������
void ChangeUsers(vector<User>& users)
{
    ofstream file("users.txt", ios::trunc);
    for (int i = 0; i < users.size(); i++)
    {
        file << users[i].username << " " << users[i].password << endl;
    }
    file.close();
}

// ������� ��� �������� � ���� �������
void ChangeAdmins(vector<User>& admins)
{
    ofstream file("admins.txt", ios::trunc);
    for (int i = 0; i < admins.size(); i++)
    {
        file << admins[i].username << " " << admins[i].password << endl;
    }
    file.close();
}

// ������� ��� ��������� ������ �� ����� ������
void checkRequests(vector<User>& requests, vector<User>& admins)
{
    system("cls");
    cout << "===== �������� ������ �� ����� �������������� =====" << endl;
    cout << endl << endl;
    if (requests.empty())
    {
        cout << "������ ���." << endl;
        cout << "===============================================" << endl;
        system("pause");
    }
    else
    {
        cout << "| No. |   �����   |   ������   |" << endl;
        for (int i = 0; i < requests.size(); i++)
        {
            cout << "|  " << i + 1 << "  |  " << requests[i].username << "       " << requests[i].password << endl;
            /*printf("| %d  |     %5s  |    %5s    |\n", i + 1 , requests[i].username, requests[i].password);*/
        }
        cout << "+----------------------------+" << endl;
        system("pause");
        cout << "������� �� ����-������ ��������?" << endl;
        cout << "1 - ��" << endl;
        cout << "2 - ���" << endl;
        int ch;
        cin >> ch;
        if (proverka(ch))
        {
            switch (ch)
            {
            case 1:
            {
                cout << "������� ����� ������." << endl;
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
                    cout << "������ ��������." << endl;
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
                cout << "������������ ����!" << endl;
                return adm_menu();
            }
            }
        }
        else
        {
            cout << "������������ ����!" << endl;
            return adm_menu();
        }
    }
}

// ������� ������ ������ �� ����� ������
void request(vector<User>& user, vector<User>& admins)
{
    system("cls");
    cout << "===== ������ ������ �� ����� �������������� =====" << endl;
    string login, password;
    cout << "������� �����." << endl;
    cin >> login;
    cout << "������� ������." << endl;
    cin >> password;
    ofstream file("requests.txt", ios::app);
    if (file.is_open())
    {
        file << login << " " << password << endl;
    }
    file.close();
    cout << "������ ������� ������." << endl;
}

// �������� �� ���������� ����
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

// ������� ��������� ������ �������������
void check_users(vector<User> users)
{
    cout << "========== �������� ������ ������������� ==========" << endl;
    if (users.empty())
    {
        cout << "������������ �����������." << endl;
    }
    else
    {
        cout << endl << endl;
        cout << "|�����:    |    ������:   |" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            printf("| %7s  |   %7s    |\n", users[i].username.c_str(), users[i].password.c_str());
        }
    }
    system("pause");
}

// ���������� �� ��������( �������)
void sort_surname(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "����������..." << endl;
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
    cout << "���������� ������������� �� ��������." << endl << endl;
}

// ���������� �� ������
void sort_department(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "����������..." << endl;
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
    cout << "���������� ������������� �� ������." << endl << endl;
}

// ���������� �� ��������
void sort_age(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "����������..." << endl;
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
    cout << "���������� ������������� �� ��������(�� �����������)." << endl << endl;
}

// ���������� �� �����
void sort_total(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    cout << "����������..." << endl;
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
    cout << "���������� ������������� �� �������� �����." << endl << endl;
}

// �������������� ����������
void change(vector<Employee>& employees)
{
    system("cls");
    string surname3;
    int ch4;
    int l = 0;
    cout << "=============== �������������� ���������a ===============" << endl;
    cout << "������� ������� ����������" << endl;
    cin >> surname3;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].surname == surname3)
        {
            l++;
            cout << "��������� " << employees[i].surname << " " << employees[i].name << " " << employees[i].patronymic << " ������.��� ������ �������� ? " << endl;
            cout << "1 - �������." << endl;
            cout << "2 - ���." << endl;
            cout << "3 - ��������." << endl;
            cout << "4 - ���� ��������." << endl;
            cout << "5 - ����� ��������." << endl;
            cout << "6 - ��� ��������." << endl;
            cout << "7 - ���� ������ ������." << endl;
            cout << "8 - ����� ������ ������." << endl;
            cout << "9 - ��� ������ ������." << endl;
            cout << "0 - �����." << endl;
            cout << "��������..." << endl;
            cin >> ch4;
            if (proverka(ch4))
            {
                switch (ch4)
                {
                case 1:
                {
                    string nsurname;
                    cout << "������� ����� �������." << endl;
                    cin >> nsurname;
                    employees[i].surname = nsurname;
                    cout << "������� ��������." << endl;
                    return adm_menu();
                }
                case 2:
                {
                    string nname;
                    cout << "������� ����� ���." << endl;
                    cin >> nname;
                    employees[i].name = nname;
                    cout << "��� ��������." << endl;
                    return adm_menu();
                }
                case 3:
                {
                    string npatronymic;
                    cout << "������� ����� ��������." << endl;
                    cin >> npatronymic;
                    employees[i].patronymic = npatronymic;
                    cout << "�������� ��������." << endl;
                    return adm_menu();
                }
                case 4:
                {
                    int nday;
                    cout << "������� ����� ���� ��������." << endl;
                    cin >> nday;
                    if (nday >= 1 && nday <= 31)
                    {
                        employees[i].dbirth = nday;
                        cout << "���� �������� �������." << endl;
                        employees[i].age = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 5:
                {
                    int nmonth;
                    cout << "������� ����� ����� ��������." << endl;
                    cin >> nmonth;
                    if (nmonth >= 1 && nmonth <= 12)
                    {
                        employees[i].mbirth = nmonth;
                        cout << "����� �������� �������." << endl;
                        employees[i].age = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 6:
                {
                    int nyear;
                    cout << "������� ����� ��� ��������." << endl;
                    cin >> nyear;
                    if (nyear < 2024 && nyear>1900 && nyear < employees[i].d.year)
                    {
                        employees[i].ybirth = nyear;
                        employees[i].age = ((2023 * 365) - (nyear * 365 + employees[i].d.month * 31 + employees[i].d.day)) / 365;
                        cout << "��� �������� �������." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 7:
                {
                    int day0;
                    cout << "������� ����� ���� ������ ������." << endl;
                    cin >> day0;
                    if (day0 <= 31 && day0 >= 1)
                    {
                        employees[i].d.year = day0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "��� ������ ������ �������." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 8:
                {
                    int month0;
                    cout << "������� ����� ����� ������ ������." << endl;
                    cin >> month0;
                    if (month0 <= 12 && month0 >= 1)
                    {
                        employees[i].d.month = month0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "����� ������ ������ �������." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 9:
                {
                    int year0;
                    cout << "������� ����� ��� ������ ������." << endl;
                    cin >> year0;
                    if (year0 > 1900 && year0 < 2024 && year0>employees[i].ybirth)
                    {
                        employees[i].d.year = year0;
                        employees[i].d.total = (2023 * 365 - (employees[i].d.year * 365 + employees[i].d.month * 31 + employees[i].d.day));
                        cout << "��� ������ ������ �������." << endl;
                        return adm_menu();
                    }
                    else
                    {
                        cout << "������������ ����..." << endl;
                        return adm_menu();
                    }
                }
                case 0:
                {
                    system("cls");
                    cout << "�� �������� ��� �������." << endl;
                    return adm_menu();
                }
                default:
                {
                    cout << "�������� ����. ��������� ������� �����." << endl;
                    return adm_menu();
                }
                }
            }
        }
    }
    if (l == 0)
    {
        cout << "����������� � �������� " << surname3 << " �� �������." << endl << endl;
    }
}

// ������� ������ ����������� ����������� ��������
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
        cout << "���������� ����������� ��������: " << endl;
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
        cout << "��� ����������� ����������� ��������." << endl;
    }
}

// ���� ��������������
void adm_menu()
{
    while (true)
    {
        int ch;
        cout << "=============== ���� �������������� ===============" << endl;
        cout << "1 - ���������������� ������ ������������." << endl;
        cout << "2 - �������� ������ ����������." << endl;
        cout << "3 - ������� �����������." << endl;
        cout << "4 - ����� ����������." << endl;
        cout << "5 - ������� ����������." << endl;
        cout << "6 - ���������� �����������." << endl;
        cout << "7 - ������������� ����������." << endl;
        cout << "8 - ����������� ������ �������������(����� � ������)." << endl;
        cout << "9 - �������� ������ �� ����� ��������������." << endl;
        cout << "0 - ����� �� �������." << endl;
        cout << "=============== =================== ===============" << endl << endl << endl;
        cout << "��������: ";
        cin >> ch;
        if (!proverka(ch))
        {
            cout << "�������� ����. ���������..." << endl;
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
                cout << "========== ����� ���������� ==========" << endl;
                cout << "1 - �� �������." << endl;
                cout << "2 - �� ������." << endl;
                cout << "3 - �� ���������." << endl;
                cout << "======================================" << endl << endl << endl;
                cout << "��������..." << endl;
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
                    cout << "������ �����, ��������� �������..." << endl;
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
                cout << "========== ���������� ==========" << endl;
                cout << "1 - �� �������(�� ��������)" << endl;
                cout << "2 - �� ��������(�� �����������)" << endl;
                cout << "3 - �� ������(�� ��������)" << endl;
                cout << "4 - �� �����(�� ��������)" << endl;
                cout << "0 - ������." << endl;
                cout << "================================" << endl;
                cout << "��������..." << endl;
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
                        cout << "�� �������� ��� �������." << endl;
                        return adm_menu();
                    }
                    default:
                    {
                        cout << "�������� ����. ��������� ������� �����." << endl;
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
                cout << "�� ����� �� �������..." << endl; return gl_menu();
            }
            default:
            {
                cout << "�������� ����. ��������� ������� �����." << endl;
                return adm_menu();
            }
            }
        }
    }
}

//  ���� ������������
void user_menu()
{
    while (true)
    {
        cout << "=============== ���� ������������ ===============" << endl;
        cout << "1 - ����������� ���� �����������." << endl;
        cout << "2 - ���������� �����������." << endl;
        cout << "3 - ����� ����������." << endl;
        cout << "4 - ������� ����������� ����������� ��������." << endl;
        cout << "5 - ������ ������ �� ��������������." << endl;
        cout << "0 - ����� �� �������." << endl;
        cout << "=============== ================= ===============" << endl;
        cout << endl << endl << endl;
        cout << "��������: " << endl;
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
                cout << "========== ���������� ==========" << endl;
                cout << "1 - �� �������(�� ��������)" << endl;
                cout << "2 - �� ��������(�� �����������)" << endl;
                cout << "3 - �� ������(�� ��������)" << endl;
                cout << "4 - �� �����(�� ��������)" << endl;
                cout << "0 - ������." << endl;
                cout << "================================" << endl;
                cout << "��������..." << endl;
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
                        cout << "�� �������� ��� �������." << endl;
                        return user_menu();
                    }
                    default:
                    {
                        cout << "�������� ����. ��������� ������� �����." << endl;
                        return user_menu();
                    }
                    }
                }
            }
            case 3:
            {
                cout << "========== ����� ���������� ==========" << endl;
                cout << "1 - �� �������." << endl;
                cout << "2 - �� ������." << endl;
                cout << "3 - �� ���������." << endl;
                cout << "0 - ������." << endl;
                cout << "======================================" << endl << endl << endl;
                cout << "��������..." << endl;
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
                cout << "�� ����� �� �������..." << endl;
                system("pause");
                return gl_menu();
            }
            default:
            {
                cout << "�������� ����, ��������� �������..." << endl;
                return user_menu();
            }
            }
        }
        else
        {
            cout << "�������� ����, ��������� �������..." << endl;
            return user_menu();
        }
    }
}

// ������� ����
void gl_menu()
{
    while (true)
    {
        int ch;
        cout << "=============== ������� ���� ===============" << endl;
        cout << "1 - ����� � �������(��� ������������)." << endl;
        cout << "2 - ����� � �������(��� �������������)." << endl;
        cout << "3 - ����������� ������������." << endl;
        cout << "0 - �����." << endl;
        cout << "============================================";
        cout << endl << endl << endl;
        cout << "��������:" << endl;
        cin >> ch;
        if (proverka(ch))
        {
            switch (ch)
            {
            case 1:
            {
                if (loginUser(users))
                {
                    cout << "����������� ������ �������.\n" << endl << endl << endl;
                    system("pause");
                    system("cls");
                    user_menu();
                }

                else
                {
                    cout << "������ �����������. �������� ��� ������������ ��� ������.\n";
                }
                break;
            }
            case 2:
            {
                if (loginAdmin(admins))
                {
                    cout << "����������� ������ �������.\n" << endl << endl << endl;
                    system("pause");
                    system("cls");
                    adm_menu();
                }

                else
                {
                    cout << "������ �����������. �������� ��� ������������ ��� ������.\n";
                }
                break;
            }
            case 3: {registerUser(users); break; }
            case 0: { 
                system("cls");
                cout << "�� ����� �� �������." << endl;
                system("pause");
                ChangeEmployee(employees, payments);
                
                ChangeUsers(users);
                
                exit(0); 
            }
            default:
            {
                cout << "�������� ����. ��������� �������." << endl;
                return gl_menu();
            }
            }
        }
        else
        {
            cout << "�������� ����. ��������� �������." << endl;
            return gl_menu();
        }
    }
}

// ������� �������� ����������
void del_employee(vector<Employee>& employees, vector<Payment>& payments)
{
    system("cls");
    string surname;
    int k = 0;
    cout << "========== �������� ���������� ==========" << endl;
    cout << endl << endl << endl;
    cout << "������� ������� ����������." << endl;
    cin >> surname;
    for (int i = 0; i < employees.size() && i < payments.size(); i++)
    {
        if (employees[i].surname == surname)
        {
            k++;
            employees.erase(employees.begin() + i);
            payments.erase(payments.begin() + i);
            cout << "��������� �����." << endl;
            break;
        }
    }
    if (k == 0)
    {
        cout << "��������� �� ������." << endl;
    }
    k = 0;
}

// ������� ������ �� �������
void find_surname(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string surname;
    system("cls");
    cout << "========== ����� �� ������� ==========" << endl;
    cout << "������� �������." << endl;
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
        cout << "�� ������� �����������." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// ������� ������ �� ������
void find_department(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string department;
    system("cls");
    cout << "========== ����� �� ������ ==========" << endl;
    cout << "������� �����." << endl;
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
        cout << "�� ������� �����������." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// ������� ������ �� ���������
void find_position(vector<Employee> employees, vector<Payment> payments)
{
    int k = 0;
    string position;
    system("cls");
    cout << "========== ����� �� ��������� ==========" << endl;
    cout << "������� ���������." << endl;
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
        cout << "�� ������� �����������." << endl;
    }
    else
    {
        printTableFooter();
    }
}

// ����� ������ �������
void printTableHeader()
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
    cout << "|    �������    |    ���    |   ��������   | ���� �������� | �������(���) |   �����   |   ���������   | ���� ������ ������ |  ����(����)  |  ������ |  ��������(���) |\n";
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
}

// ����� ������ �������
void printTableFooter()
{
    cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n";
}

// ����� �����������
void OutEmployee(vector<Employee>& employees, vector<Payment>& payments)
{
    if (employees.empty())
    {
        system("cls");
        cout << "���������� �����������." << endl;
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

// ������� ��� �������� ������������� ������������� � ������
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

// ������� ��� �������� ������������� ������������ � ������
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

// ������� ��� �������� �� ������� � ���� �����������
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

//������� ��� ���������� ������ ����������
void registerEmployee(vector<Employee>& employees)
{
    cout << "========== ���������� ������ ���������� ==========" << endl;
    string surname, name, patronymic, department, position;
    int day, month, year, age, total, dbirth, mbirth, ybirth;
    double rate, salary;
    cout << "������� �������." << endl;
    cin >> surname;
    cout << "������� ���." << endl;
    cin >> name;
    cout << "������� ��������." << endl;
    cin >> patronymic;
    cout << "������� ���� ��������." << endl;
    cout << "����: ";
    cin >> dbirth;
    if (proverka(dbirth))
    {
        if (dbirth < 1 || dbirth>31)
        {
            cout << "�������� ����. ��������� �������." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
    cout << "�����: ";
    cin >> mbirth;
    if (proverka(mbirth))
    {
        if (mbirth < 1 || mbirth>12)
        {
            cout << "�������� ����. ��������� �������." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
    cout << "���: ";
    cin >> ybirth;
    if (proverka(ybirth))
    {
        if (ybirth > 2023)
        {
            cout << "�������� ����. ��������� �������." << endl << endl << endl;
            return adm_menu();
        }
    }
    else
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }

    age = (2024 * 365 - (ybirth * 365 + mbirth * 31 + dbirth)) / 365;

    cout << "������� �����." << endl;
    cin >> department;
    cout << "������� ���������." << endl;
    cin >> position;
    cout << "������� ����� ������ ������." << endl;
    cin >> day;
    if (!proverka(day))
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
    cout << "������� ����� ������ ������." << endl;
    cin >> month;
    if (!proverka(month))
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
         cout << "������� ��� ������ ������." << endl;
         cin >> year;
    if (!proverka(year))
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
    total = (2023 * 365 - (year * 365 + month * 31 + day));
    cout << "������� ���������� ������." << endl;
    cin >> rate;
    if (!proverka(rate))
    {
        cout << "�������� ����. ��������� �������." << endl;
        return adm_menu();
    }
    cout << "������� ���������� �����(� ������)" << endl;
    cin >> salary;
    if (!proverka(salary))
    {
        cout << "�������� ����. ��������� �������." << endl;
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
    cout << "��������� ������ � ���� ������." << endl;
}

// ������� ��� ����������� ������ ������������
//void registerUser(vector<User>& users)
//{
//    cout << "=============== ����������� ������ ������������ ===============" << endl;
//    string username, password;
//    cout << "������� ��� ������������: ";
//    cin >> username;
//    if (userExists(users, username))
//    {
//        cout << "������������ � ����� ������ ��� ����������.\n";
//        return;
//    }
//    cout << "������� ������: ";
//    cin >> password;
//    users.push_back({ username, password });
//    ofstream file("users.txt", ios::app);
//    file << username << " " << password << endl;
//    file.close();
//    cout << "������������ ������� ���������������." << endl;
//}

void registerUser(vector<User>& users)
{
    cout << "=============== ����������� ������ ������������ ===============" << endl;
    string username, password;
    cout << "������� ��� ������������: ";
    cin >> username;
    if (userExists(users, username))
    {
        cout << "������������ � ����� ������ ��� ����������.\n";
        return;
    }
    cout << "������� ������: ";
    cin >> password;
    string encryptedPassword = encryptPassword(password, "my-secret-key");
    users.push_back({ username, encryptedPassword });
    ofstream file("users.txt", ios::app);
    file << username << " " << encryptedPassword << endl;
    file.close();
    cout << "������������ ������� ���������������." << endl;
}

// ������� ��� ����������� ��������������
void registerAdmin(vector<User>& admins)
{
    cout << "=============== ����������� ������ �������������� ===============" << endl;
    string username, password;
    cout << "������� ����� ��������������: ";
    cin >> username;
    if (adminExists(admins, username))
    {
        cout << "������������� � ����� ������ ��� ����������.\n";
        return;
    }
    cout << "������� ������: ";
    cin >> password;
    admins.push_back({ username, password });
    ofstream file("admins.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "������������� ������� ���������������.\n";
}

// ������� ��� ����������� ������������
//bool loginUser(vector<User> users)
//{
//    system("cls");
//    string username, password;
//    cout << "=====   ����� � ������� ��� ������������   =====" << endl << endl << endl;
//    cout << "������� ����� ������������." << endl;
//    cin >> username;
//    cout << "������� ������." << endl;
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
    cout << "=====   ����� � ������� ��� ������������   =====" << endl << endl << endl;
    cout << "������� ����� ������������." << endl;
    cin >> username;
    cout << "������� ������." << endl;
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
// ������� ��� ����������� ��������������
bool loginAdmin(vector<User> admins)
{
    system("cls");
    string username, password;
    cout << "=====   ����� � ������� ��� �������������   =====" << endl << endl << endl;
    cout << "������� ����� ��������������." << endl;
    cin >> username;
    cout << "������� ������." << endl;
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

// ������� ��� ������ ������ ����������� �� �����
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

// ������� ��� ������ ������ ������������� �� �����
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

// ������� ��� ������ ������ ��������������� �� �����
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
