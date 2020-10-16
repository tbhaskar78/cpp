/****************************************

* File Name : employeeInfo.cpp

* Creation Date : 16-10-2020

* Last Modified : Friday 16 October 2020 05:39:10 PM

* Created By :  Bhaskar Tallamraju

* Note:
* 1. Company has many departments. 
* 2. Each department has employees
* 3. Engineering, Finance HR is-a type of Department
* 4. Employee has-a set of basic information, finance info, Job role
*****************************************/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class BasicInfo
{
public:
    string m_Fname;
    string m_Lname;
    int m_Age;
    void GetInfo()
    {
        cout << "First Name: " << m_Fname << "\nLast Name: " << m_Lname << "\nAge:  " << m_Age << endl;
    }
};

class FinanceInfo
{
public:
    double m_Salary;
    int m_SalaryBand;
    void GetInfo()
    {
        cout << "Employee Salary: " << m_Salary << "\nSalary Band: " << m_SalaryBand << endl;
    }
};

class JobRole
{
public:
    int m_YearsOfService;
    string m_Designation;
    void GetInfo()
    {
        cout << "Employee Designation: " << m_Designation << "\nYears of Servicd: " << m_YearsOfService << endl;
    }
};

class Employee
{
public:
    JobRole jobRole;
    BasicInfo basicInfo;
    FinanceInfo financeInfo;

    Employee(const string& fname, const string& lname, const string& desig, 
             const double sal, const int age, const int yos, const int band)
    { 
        cout << "    Employee constructor called " << endl; 
        basicInfo.m_Fname = fname;
        basicInfo.m_Lname = lname; 
        basicInfo.m_Age = age; 
        jobRole.m_Designation=desig; 
        jobRole.m_YearsOfService = yos; 
        financeInfo.m_Salary = sal;
        financeInfo.m_SalaryBand = band; 

    }
    void GetInfo()
    {
        basicInfo.GetInfo();
        jobRole.GetInfo();
        financeInfo.GetInfo();
    }
};

class Department
{
private:
    string m_DepartmentName;
    string m_DepartmentHead;
    int m_NumberOfEmployees;
    unordered_map<string, Employee*> employee;
public:
    Department() {}
    Department(const string& dept, const string& head, int numEmp)
        : m_DepartmentName(dept), m_DepartmentHead(head), m_NumberOfEmployees(numEmp) 
    { 
        string fname; 
        string lname; 
        int age;
        string desig; 
        int yos; 
        double sal; 
        int band;
        cout << "    Department constructor called " << endl; 
        // Get employee Info
        for (int count = 0; count < m_NumberOfEmployees; count++)
        {
            cout << " Employee First Name: ";
            cin >> fname;
            cout << " Employee Last Name: ";
            cin >> lname;
            cout << " Employee Age: ";
            cin >> age;
            cout << " Employee Designation: ";
            cin >> desig;
            cout << " Employee years of Serice: ";
            cin >> yos;
            cout << " Employee Salary: ";
            cin >> sal;
            cout << " Employee Salary Band (5-13): ";
            cin >> band;
            Employee *emp = new Employee(fname, lname, desig, sal, age, yos, band);
            employee.insert({lname, emp});
        }
        for (auto [name, emp]: employee)
        {
            cout << "Employee Inserted : " << name << endl;
        }
    }
    void FindEmployee(const string& lname)
    {
        cout << "Trying to findEmployee " << lname << endl;
        unordered_map<string, Employee*>::iterator got = employee.find(lname);

        if ( got == employee.end() )
        {
            std::cout << "Employee not found";
        }
        else
        {
            // print employee information
            got->second->GetInfo();
        }
    }
    void GetInfo()
    {
        for (auto [name, emp]: employee)
        {
            emp->GetInfo();
            cout << " ********************************** " << endl;
        }
    }


    ~Department() 
    { 
        cout << "    Department Destructor called " << endl; 
        // iterate over employees and delete them
        for (auto [name, emp]: employee)
        {
            cout << "    Deleting employee: " << name << endl;
            delete emp;
        }

    }
};

class Company
{
private:
    Department *Engineering = nullptr;
public:
    Company() 
    { 
        string deptName;
        string deptHeadName;
        int deptNumEmp;
        cout << "Company Constructor " << endl; 
        cout << "Enter Department Name: ";
        cin >> deptName;
        cout << "Enter Department Head's name: ";
        cin >> deptHeadName;
        cout << "Enter Department's Number of Employees: ";
        cin >> deptNumEmp;
        Engineering = new Department(deptName, deptHeadName, deptNumEmp);

    }
    void GetInfo()
    {
        cout << "*********** LISTING ALL EMPLOYEES : " << endl;
        Engineering->GetInfo();
    }
    void findEmployee(const string& lname)
    {
        cout << "*********** TRYING TO FIND EMPLOYEE " << lname << endl;
        Engineering->FindEmployee(lname);
    }
    ~Company() 
    { 
        cout << "Company Destructor " << endl; 
        delete Engineering;
    }
};


int main (int argc, char *argv[])
{
    Company cp;

    cout << "Trying to find employee Tallamraju " << endl;
    cp.findEmployee("Tallamraju");

    cp.GetInfo();

}

