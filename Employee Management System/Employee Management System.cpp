// This program aims to design an object oriented model for a software development company's employee management system.
// Language: C++
// It will create various abstract data types to model the relationships among these occupations.
// This program will be based on my python object oriented model as shown in my cpp-fundamentals repository. (19. OOP in Python Exercise)
// ChatGPT sourced for giving me ideas for potential properties of each of the given classes, it also helped give me pointers in the right direction if I was confused on something (like the addition of dynamic memory and polymorphism)
// The program will have a set amount of employees instantiated as soon as it runs
/* This project will be updated periodically in the future to implement the following features in full functionality 

- Fully functional menu which allows the user to add, remove, edit, and display existing employees using an EmployeeManager class
- Using File Operation to have a file of all employees in the system to be exported neatly into a txt file with a click from the menu option.

*/

#include <iostream>
#include <string> // Ensures the program includes the definition of the std::string class
#include <vector> // This will be crucial in the EmployeeManager class which aims to add, remove, edit, or display employees if the user wishes to do so.
#include <limits> // Import for error checking and quality control on invalid user inputs
#include <memory> // Import for the use of smart pointers like unique_ptr (mainly for working with vectors as new employees are instantiated by the user)
using namespace std;

// 1. Employee class
class Employee {

    // Can only be accessed in the Employee class and it's derived classes (given you arent using methods)
    protected:
        string address; // Address property will be private
        int social_sec; // Social security number will be private
        int zipcode; // Zipcode will be protected

    // Can be accessed anywhere
    public:
        static int total_employees; // A static variable which will keep count of the total number of employees added to the system.
        string name; // Name will be public
        int age; // Age will be public
        int telephone; // Telephone will be public
        int yrs_of_exp; // Years of experience in given field


    // Employee Constructor
    Employee(string name, int age, int telephone, string address, int zipcode, int social_sec, int yrs_of_exp) : name(name), age(age), telephone(telephone), address(address), zipcode(zipcode), social_sec(social_sec), yrs_of_exp(yrs_of_exp) {
        total_employees++; // post incrementation of total_count variable each time an employee object (or subclass of employee) is instantiated
    }

    // Destructor (removes objects from the class)
    virtual ~Employee() { // The destructor here will be virtual because we want to ensure that deleting an object in a subclass will call the base class destructor as well.
        total_employees--; // When an object is destroyed the total_count will decrement accordingly
    }

    // Getters (allows us to recieve a given object's information using methods whether it is public, private, or protected)

    string get_name() { // Adding const is an indication that these methods do not modify the state of the object.
        return this->name;
    }

    int get_age()  {
        return this->age;
    }

    int get_telephone()  {
        return this->telephone;
    }

    string get_address()  {
        return this->address;
    }

    int get_zipcode()  {
        return this->zipcode;
    }

    virtual int get_social_sec()  { 
        return this->social_sec;
    }

    int get_yrs_of_exp() {
        return this->yrs_of_exp;
    }

    // Setters (allows us to edit and change an existing object's properties after instantiation)

    void set_name(string new_name) {
        this->name = new_name;
    }

    void set_age(int new_age) {
        this->age = new_age;
    }

    void set_telephone(int new_telephone) {
        this->telephone = new_telephone;
    }

    void set_address(string new_address) { 
        this->address = new_address;
    }

    void set_zipcode(int new_zipcode) {
        this->zipcode = new_zipcode;
    }

    virtual void set_social_sec(int new_social_sec) { // We want to make sure the employee's social security stays confidential to other developers without proper authorization
        this->social_sec = new_social_sec;
    }

    void set_yrs_of_exp(int new_yrs_of_exp) {
        this->yrs_of_exp = new_yrs_of_exp;
    }

};

int Employee::total_employees = 0; // Defining total_employees

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 2. Software Developer class which will inherit from the Employee class
class Software_Developer : public Employee {

    public:
        static int total_swdevs; // A static variable which will keep count of the total number of software developer employees added to the system.
        string programming_language; // Programming Language employee specializes in
        int completed_projects; // Number of Completed Projects
        string current_project; // Current Project in which the Employee is working on

    // Since we are inheriting from the Employee class, we will already have the getters and setters for the Employee class' properties, I will be making some method overrides in this class to protect sensitive information
    Software_Developer(string name, int age, int telephone, string address, int zipcode, int social_sec, int yrs_of_exp, string programming_language, int completed_projects, string current_project)
    : Employee(name, age, telephone, address, zipcode, social_sec, yrs_of_exp), programming_language(programming_language),completed_projects(completed_projects), current_project(current_project){
        total_swdevs++; // post incrementation of total_swe variable each time a software developer is instantiated
    }

    // Destructor
    ~Software_Developer() {
        total_swdevs--; // Decrementation of Software Developer count when an object is destroyed
    }

    // Getters

     string get_programming_language()  {
        return this->programming_language;
     }

     int get_completed_projects()  {
         return this->completed_projects;
     }

     string get_current_project()  {
         return this->current_project;
     }

     // Setters

     void set_programming_language(string new_programming_language) {
         this->programming_language = new_programming_language;
     }

     void set_completed_projects(int new_completed_projects) {
         this->completed_projects = new_completed_projects;
     }

     void set_current_project(string new_current_project) {
         this->current_project = new_current_project;
     }

};

int Software_Developer::total_swdevs = 0; // Defining total_swdevs

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 3.Network Engineer Class which will inherit from the Employee class
class Network_Engineer : public Employee {

    public:
        static int total_network_engineers; // A static variable which will keep count of the total number of network engineer employees added to the system.
        string IT_certifications; // Certifications owned by employee
        int num_of_networks; // Number of networks being maintained/monitored by employee
        int num_of_subnets; // Number of sub-networks being maintained/monitored by employee (if any)

    Network_Engineer(string name, int age, int telephone, string address, int zipcode, int social_sec, int yrs_of_exp, string IT_certifications, int num_of_networks, int num_of_subnets)
    : Employee(name, age, telephone, address, zipcode, social_sec, yrs_of_exp), IT_certifications(IT_certifications), num_of_networks(num_of_networks), num_of_subnets(num_of_subnets) {
        total_network_engineers++; // post incrementation of total_network_engineers each time a network engineer is instantiated
    }

    // Deconstructor
    ~Network_Engineer() {
        total_network_engineers--; // Decrementation of total_network_engineers
    }

    // Getters
    
    string get_IT_certifications() {
        return this->IT_certifications;
    }

    int get_num_of_networks() {
        return this->num_of_networks;
    }

    int get_num_of_subnets() {
        return this->num_of_subnets;
    }

    // Setters

    void set_IT_certifications(string new_IT_certifications) {
        new_IT_certifications = IT_certifications;
    }

    void set_num_of_networks(int new_num_of_networks) {
        new_num_of_networks = num_of_networks;
    }

    void set_num_of_subnets(int new_num_of_subnets) {
        new_num_of_subnets = num_of_subnets;
    }

};

int Network_Engineer::total_network_engineers; // Defining total_network_engineers

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 4. Quality Assurance Engineer Class will inherit from the Employee class
class QA_Engineer : public Employee {

    public:
        static int total_QA_engineers;
        string software_being_tested; // Software being tested by employee
        string testing_tool; // Software Testing tool being used by employee
        int problems_found; // Number of problems found by employee

    QA_Engineer(string name, int age, int telephone, string address, int zipcode, int social_sec, int yrs_of_exp, string software_being_tested, string testing_tool, int problems_found)
    : Employee(name, age, telephone, address, zipcode, social_sec, yrs_of_exp), software_being_tested(software_being_tested), testing_tool(testing_tool), problems_found(problems_found) {
        total_QA_engineers++; // post incrementation of total_QA_engineers variable each time a quality assurance engineer is instantiated
    }

    // Deconstructor
    ~QA_Engineer() {
        total_QA_engineers--; // Decrementation of total_QA_engineers
    }

    // Getters

    string get_software_being_tested() {
        return this->software_being_tested;
    }

    string get_testing_tool() {
        return this->testing_tool;
    }

    int get_problems_found() {
        return this->problems_found;
    }

    // Setters

    void set_software_being_tested(string new_sw_being_tested) {
        new_sw_being_tested = software_being_tested;
    }

    void set_testing_tools(string new_testing_tool) {
        new_testing_tool = testing_tool;
    }

    void set_problems_found(int new_problems_found) {
        new_problems_found = problems_found;
    }

};

int QA_Engineer::total_QA_engineers; // Defining total_QA_engineers

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 5. Project Manager class which will inherit from the Employee class
 class Project_Manager : public Employee {

    public:
        static int total_project_managers; // A static variable which will keep count of the total number of project manager employees added to the system.
        int num_of_employees; // Number of total Employees being managed by Employee
        int num_of_projects; // Number of Projects Employee is Managing
        string management_certifications; // Management Certification held by Employee

    Project_Manager(string name, int age, int telephone, string address, int zipcode, int social_sec, int yrs_of_exp, int num_of_employees, int num_of_projects, string management_certifications)
    : Employee(name, age, telephone, address, zipcode, social_sec, yrs_of_exp), num_of_employees(num_of_employees), num_of_projects(num_of_projects), management_certifications(management_certifications){
        total_project_managers++; // post incrementation of total_project_managers variable each time a project manager is instantiated 
    }

    // Deconstructor
    ~Project_Manager() {
        total_project_managers--; // Decrementation of total_project_managers
    }

    // Getters

    int get_num_of_employees() {
        return this->num_of_employees;
    }

    int get_num_of_projects() {
        return this->num_of_projects;
    }

    string get_management_certification() {
        return this->management_certifications;
    }

    // Setters

    void set_num_of_employees(int new_num_of_employees) {
        this->num_of_employees = new_num_of_employees;
    }

    void set_num_of_projects(int new_num_of_projects) {
        this->num_of_projects = new_num_of_projects;
    }

    void set_management_certification(string new_management_certifications) {
        this->management_certifications = new_management_certifications;
    }

};

int Project_Manager::total_project_managers; // Defining total_project_managers

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {

    // I want the program to already have 20 prexisting employees at the start

     /* I want the program to have 20 prexisting employees as soon as it starts, as I plan on first creating a functioning menu which can take advantage
    of the prexisting getters and setters within the classes. */

    // Here is an example of the menu which will be utilized and the features it will have.
    cout << "--------------------------------------------" << endl;
    cout << " Welcome to the Employee Management System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << "1. Add Employee " << endl; // Adds an employee (user specifies occ -> user adds new employee after filling in required info to instantiate)
    cout << "2. Remove Employee" << endl; // Removes an employee (user specifies occ -> user removes employee after typing name)
    cout << "3. Edit Employee Info" << endl; // Will edit a prexisting employee's information (user specifies occ -> user types employee name -> displays emplyoee info -> user chooses what to edit) 
    cout << "4. View Employee Info" << endl; // Will display all of an employee's information  (user specifies occ -> user types employee name -> all employee information is presented)
    cout << "5. Export Employees" << endl; // Will export all the current employee's in the system into an txt file. (with all of the properties) 
    cout << "6. Exit" << endl; // Exits program
    cout << endl;

    // Adding sample software developers
    Software_Developer DRoberts("Daniel Roberts", 23, 2394392345, "294 Austin Road", 12495, 348392, 5, "Python", 2, "Customer Data Analytics");
    Software_Developer JForger("Jessica Forger", 30, 3943943944, "304 Forest Hills", 64324, 858439, 7, "Python", 5, "Risk Management Detection");
    Software_Developer PGaven("Philip Gaven", 26, 9503452345, "203 Pacific Street", 23456, 392653, 3, "C++", 1, "Payment Processing System");
    Software_Developer KTurner("Keven Turner", 19, 8574839283, "32 Lincoln Ave", 85654, 123425, 1, "C++", 0, "Cloud and Infrastructure Management");
    Software_Developer AAustine("Amanda Austine", 34, 4343256432, "694 Fisher Hills", 32356, 594834, 4, "Java", 6, "Cybersecurity Solutions");

    // Adding sample network engineers
    Network_Engineer CFinn("Chester Finn", 24, 3829389448, "808 Heart Street", 12367, 859495, 2, "A+, Network+, Sec+, Cloud+", 2, 6);
    Network_Engineer KDaniels("Kim Daniels", 43, 2949548934, "940 Beverly Hills", 96443, 483924, 7, "CCNP, CCNA, MS Tech Associate, ISACA", 5, 10);
    Network_Engineer BBerkman("Barry Berkman", 22, 4939439584, "40 Sidney Ave", 43245, 493205, 1, "Bachelor in CIS", 1, 2);
    Network_Engineer LFuches("Linda Fuches", 36, 238495495, "204 Luper Street", 23452, 984384, 5, "Google IT Partner", 4, 12);
    Network_Engineer PWong("Pally Wong", 25, 3948549345, "403 First Ave", 34524, 548394, 3, "CCNA, A+, Network+", 2, 4);

    // Adding sample QA engineers
    QA_Engineer MCooman("Mary Cooman", 21, 2934895659, "605 Fletcher Road", 12043, 594034, 1, "Data Analytics", "ChatGPT 4o", 3);
    QA_Engineer LJinkins("Lester Jinkins", 24, 4324322345, "959 Compton Street", 65432, 584394, 2, "Risk Management Detection", "Zed Attack Proxy", 5);
    QA_Engineer ELarson("Emma Larson", 34, 4832934859, "120 Dentrick Ave", 58493, 293059, 5, "Customer Data Analytics", "Visual Studio Debugger", 4);
    QA_Engineer NParker("Noah Parker", 43, 6985969857, "395 Tenth Street", 96584, 849349, 9, "Cloud and Infrastructure Management", "GNU Debugger", 2);
    QA_Engineer ABennet("Ava Bennet", 26, 3859489485, "493 Portland Road", 45985, 398495, 3, "Payment Processing System", "CppUnit", 3);

    // Adding sample project managers
    Project_Manager LMorgan("Luces Morgan", 23, 4959540934, "395 Runner Street", 58943, 209345, 2, 5, 4, "Bachelors in Business Management");
    Project_Manager LCaldwell("Liam Caldwell", 36, 3848399283, "546 Oriental Ave", 68531, 859234, 5, 7, 6, "Certified ScrumMaster");
    Project_Manager JTiller("Jackson Tiller", 21, 4959349283, "943 Lake Road", 58493, 934843, 1, 2, 1, "Project+");
    Project_Manager IJones("Indiana Jones", 44, 8439839834, "359 Rameon Road", 85433, 483912, 2, 10, 12, "Bachelors in CIS");
    Project_Manager ORomen("Olivia Romen", 25, 4385483495, "25 Creston Ave", 52393, 930485, 3, 6, 5, "PMP");

    // Printing out total number of employees along with the count of each employee within a given occupation
    cout << "In total there are currently " << Employee::total_employees << " working at the company." << endl;
    cout << "There are a total of " << Software_Developer::total_swdevs << " Software Developers." << endl;
    cout << "There are a total of " << Network_Engineer::total_network_engineers << " Network Engineers." << endl;
    cout << "There are a total of " << QA_Engineer::total_QA_engineers << " Quality Assurance Engineers." << endl;
    cout << "There are a total of " << Project_Manager::total_project_managers << " Project Managers." << endl;

    return 0;
}
