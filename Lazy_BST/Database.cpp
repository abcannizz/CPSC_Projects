/*
Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 5: Lazy BST
File contains function definitions for the Database class
*/
#include "Database.h"

//overloaded operator - outputs student data in string form
std::ostream& operator << (std::ostream &os, Student &s){
    return (os << "Student: " << s.getName() << "; Student ID: " << s.getID() << "; Level: " << s.getLevel() 
    << "; Major: " << s.getMajor() << "; GPA: " << s.getGPA() << "; Advisor ID: " << s.getAdvisorID() << std::endl);
}

//overloaded operator - outputs faculty data in string form
std::ostream& operator << (std::ostream &os, Faculty &f){
    return (os << "Faculty Member: " << f.getName() << "; Faculty ID: " << f.getID() << "; Level: " << f.getLevel()
    << "; Department: " << f.getDepartment() << "; Advisees: " << f.displayAdviseeList() << std::endl);
}

//default constructor
Database::Database(){
   m_studentTree = new LazyBST<Student>;
   m_facultyTree = new LazyBST<Faculty>;
}

//default destructor
Database::~Database(){
    delete m_studentTree;
    delete m_facultyTree;
}

/* 
method that executes all functions of the database
repreatedly prompts the user to build and change the database until they exit 
*/
void Database::run(){
    int choice = -1;
    int tempSID = -1;
    int tempFID = -1;
    std::string tempLvl = "";
    std::string tempName = "";
    std::string tempMajor = "";
    double tempGPA = 0.0;
    std::string tempDepartment = "";
    prompt();
    std::cin >> choice;
    while (choice != 11){
        switch (choice)
        {
        case 1:
            printAllStudents();
            break;
        case 2:
            printAllFaculty();
            break;
        case 3:
            std::cout << "What is the ID of the student you would like to search for: " << std::endl;
            std::cin >> tempSID;
            findStudent(tempSID);
            break;
        case 4:
            std::cout << "What is the ID of the faculty member you would like to search for: " << std::endl;
            std::cin >> tempFID;
            findFaculty(tempFID);
            break;
        case 5:
            std::cout << "What is the student ID: " << std::endl;
            std::cin >> tempSID;
            std::cout << "What is the student's name: " << std::endl;
            std::getline(std::cin >> std::ws, tempName);
            std::cout << "What is the student's grade level: " << std::endl;
            std::getline(std::cin >> std::ws, tempLvl);
            std::cout << "What is the student's major: " << std::endl;
            std::getline(std::cin >> std::ws, tempMajor);
            std::cout << "What is the student's GPA: " << std::endl;
            std::cin >> tempGPA;
            std::cout << "What is the ID of the student's advisor: " << std::endl;
            std::cin >> tempFID; 
            addStudent(tempSID,tempName,tempLvl,tempMajor,tempGPA,tempFID);
            break;
        case 6:
            std::cout << "What is the ID of the student you want to remove: " << std::endl;
            std::cin >> tempSID;
            deleteStudent(tempSID);
            break;
        case 7:
            std::cout << "What is the faculty ID: " << std::endl;
            std::cin >> tempFID;
            std::cout << "What is the faculty member's name: " << std::endl;
            std::getline(std::cin >> std::ws, tempName);
            std::cout << "What is the faculty member's level: " << std::endl;
            std::getline(std::cin >> std::ws, tempLvl);
            std::cout << "What is the faculty member's department: " << std::endl;
            std::getline(std::cin >> std::ws, tempDepartment);
            addFaculty(tempFID,tempName,tempLvl,tempDepartment);
            break;
        case 8:
            std::cout << "What is the ID of the faculty member you want to remove: " << std::endl;
            std::cin >> tempFID;
            deleteFaculty(tempFID);
            break;
        case 9:
            std::cout << "What is the ID of the student you wish to change: " << std::endl;
            std::cin >> tempSID;
            std::cout << "What is the new advisor's ID: " << std::endl;
            std::cin >> tempFID;
            changeAdvisor(tempSID,tempFID);
            break;
        case 10:
            std::cout << "What is the ID of the faculty member: " << std::endl;
            std::cin >> tempFID;
            std::cout << "What is the ID of the advisee you wish to remove: " << std::endl;
            std::cin >> tempSID;
            removeAdvisee(tempSID,tempFID);
            break;
        default:
            break;
        }
        prompt();
        std::cin >> choice;
    }
    std::cout << "Exiting" << std::endl;
    outputLog();
}

//outputs a text message with the user's options
void Database::prompt(){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "1. Print all students and their information (sorted by ascending id #)" << std::endl;
    std::cout << "2. Print all faculty and their information (sorted by ascending id #)" << std::endl;
    std::cout << "3. Find and display student information" << std::endl;
    std::cout << "4. Find and display faculty information" << std::endl;
    std::cout << "5. Add a new student" << std::endl;
    std::cout << "6. Delete a student" << std::endl;
    std::cout << "7. Add a new faculty member" << std::endl;
    std::cout << "8. Delete a faculty member" << std::endl;
    std::cout << "9. Change a student's advisor"<< std::endl;
    std::cout << "10. Remove an advisee from a faculty member"<< std::endl;
    std::cout << "11. Exit" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

//outputs all students in the database in text form
void Database::printAllStudents(){
    if (m_studentTree->getSize() == 0){
        std::cout << "No students in database." << std::endl;
        return;
    }
    m_studentTree->printTreeInOrder();
}

//outputs all faculty members in the database in text form
void Database::printAllFaculty(){
    if (m_facultyTree->getSize() == 0){
        std::cout << "No faculty in database." << std::endl;
        return;
    }
    m_facultyTree->printTreeInOrder();
}

/*
searches the student tree for a student with an ID number that matches the parameter
prints out the student's information if found
*/
void Database::findStudent(int idNumber){
    Student tempStudent(idNumber, "temp", "temp", "temp", 0.0, 0);
    TreeNode<Student>* tempNode = m_studentTree->search(tempStudent);
    if (tempNode == NULL){
        std::cout << "Student not found." << std::endl;
    }
    else {
        std::cout << tempNode->m_data << std::endl;
    }
}

/*
searches the faculty tree for a faculty member with an ID number that matches the parameter
prints out the faculty member's information if found
*/
void Database::findFaculty(int idNumber){
    Faculty tempFaculty(idNumber, "temp", "temp", "temp");
    TreeNode<Faculty>* tempNode = m_facultyTree->search(tempFaculty);
    if (tempNode == NULL){
        std::cout << "Faculty member not found." << std::endl;
    }
    else {
        std::cout << tempNode->m_data << std::endl;
    }
}

//adds a student to the student tree with attributes that correspond to the given parameters
void Database::addStudent(int idNumber, std::string name, std::string level, std::string major, double gpa, int advisorID){
    std::cout << "Student added." << std::endl;
    Faculty tempFaculty(advisorID, "temp", "temp", "temp");
    TreeNode<Faculty>* tempFNode = m_facultyTree->search(tempFaculty);
    if (tempFNode == NULL){
        if (m_facultyTree->getSize() == 0){
            std::cout << "No advisors exist in the database at this time. Student has no advisor." << std::endl;
            m_studentTree->insert(Student(idNumber, name, level, major, gpa, -1));
            return;
        }
        else{
            Faculty newAdvisor = m_facultyTree->getMin();
            std::cout << "Advisor ID is vacant at this time. Student is assigned to advisor " << newAdvisor.getName() << "." << std::endl;
            m_studentTree->insert(Student(idNumber, name, level, major, gpa, newAdvisor.getID()));
            tempFNode = m_facultyTree->search(newAdvisor);
            tempFNode->m_data.addToList(idNumber);
            return;
        }
    }
    //if the advisor does exist:
    m_studentTree->insert(Student(idNumber, name, level, major, gpa, advisorID));
    tempFNode->m_data.addToList(idNumber);
}

//deletes the student with the given ID number from the student tree, if found
void Database::deleteStudent(int idNumber){
    Student tempStudent(idNumber, "temp", "temp", "temp", 0.0, 0);
    TreeNode<Student>* tempSNode = m_studentTree->search(tempStudent);
    if (tempSNode == NULL){
        std::cout << "Student ID not found. Cannot delete." << std::endl;
        return;
    }
    if (tempSNode->m_data.getAdvisorID() != -1){  //if the student has an advisor
        Faculty tempFaculty(tempSNode->m_data.getAdvisorID(), "temp", "temp", "temp");
        TreeNode<Faculty>* tempFNode = m_facultyTree->search(tempFaculty);
        tempFNode->m_data.removeFromList(idNumber);
    }
    m_studentTree->remove(tempStudent);
    std::cout << "Student deleted." << std::endl;
}

//adds a faculty member to the faculty tree with attributes that correspond to the given parameters
void Database::addFaculty(int idNumber, std::string name, std::string level, std::string department){
    m_facultyTree->insert(Faculty(idNumber, name, level, department));
}

//deletes the faculty member with the given ID number from the faculty tree, if found
void Database::deleteFaculty(int idNumber){
    Faculty tempFaculty(idNumber, "temp", "temp", "temp");
    TreeNode<Faculty>* tempFNode = m_facultyTree->search(tempFaculty);
    if (tempFNode == NULL){
        std::cout << "Faculty member not found - cannot delete." << std::endl;
        return;
    }
    int numReassigned = tempFNode->m_data.getMaxAdvisees();
    int* studentIDs = new int[numReassigned];
    for (int i = 0; i < numReassigned; i++){
        studentIDs[i] = tempFNode->m_data.removeFrontStudent();
    }
    m_facultyTree->remove(tempFaculty);
    std::cout << "Faculty member deleted." << std::endl;
    TreeNode<Student>* tempSNode;
    for (int i = 0; i < numReassigned; i++){
        if (studentIDs[i] > 0){ //if there is a student
            tempSNode = m_studentTree->search(Student(studentIDs[i], "temp", "temp", "temp", 0.0, 0));
            tempSNode->m_data.setAdvisorID(-1);     //assign all of the old advisor's students a blank advisor
        }
    }
    if (m_facultyTree->getSize() == 0){ 
        std::cout << "No more faculty in databse. All students now have no advisor." << std::endl;
        return;
    }
    //if there are still advisors in the tree, assign old advisor's students to a different advisor
    Faculty newAdvisor = m_facultyTree->getMin();  
    for (int i = 0; i < numReassigned; i++){
        if (studentIDs[i] > 0){ //if there is a student
            changeAdvisor(studentIDs[i], newAdvisor.getID());
        }
    }
}

//changes the advisor of the student with the given ID number to the advisor with the corresponding faculty ID
void Database::changeAdvisor(int studentID, int facultyID){
    //find student
    Student tempStudent(studentID, "temp", "temp", "temp", 0.0, 0);
    TreeNode<Student>* tempSNode = m_studentTree->search(tempStudent);
    if (tempSNode == NULL){
        std::cout << "Student not found." << std::endl;
        return;
    }
    //find current advisor (if student has an advisor)
    if (tempSNode->m_data.getAdvisorID() != -1){
        Faculty currFaculty(tempSNode->m_data.getAdvisorID(), "temp", "temp", "temp");
        TreeNode<Faculty>* tempFNode = m_facultyTree->search(currFaculty);
        tempFNode->m_data.removeFromList(studentID);  //remove from current advisor's list
    }
    //find new advisor
    Faculty newFaculty(facultyID, "temp", "temp", "temp");
    TreeNode<Faculty>* tempFNodeNew = m_facultyTree->search(newFaculty);
    if (tempFNodeNew == NULL){
        std::cout << "Advisor not found." << std::endl;
        return;
    }
    tempSNode->m_data.setAdvisorID(facultyID);  //change student's advisor ID
    tempFNodeNew->m_data.addToList(studentID);  //add student to new advisor's list
    std::cout << "Student with ID " << studentID << " is now assigned to advisor " << tempFNodeNew->m_data.getName() << "." << std::endl;
}

/*
removes the student with the given ID number from the advisee list of the faculty member with the given ID number
the student is left with no advisor until the user assigns them a new one
*/
void Database::removeAdvisee(int studentID, int facultyID){
    Student tempStudent(studentID, "temp", "temp", "temp", 0.0, 0);
    TreeNode<Student>* tempSNode = m_studentTree->search(tempStudent);
    if (tempSNode == NULL){
        std::cout << "Student not found." << std::endl;
        return;
    }
    Faculty tempFaculty(facultyID, "temp", "temp", "temp");
    TreeNode<Faculty>* tempFNode = m_facultyTree->search(tempFaculty);
    if (tempFNode == NULL){
        std::cout << "Advisor not found." << std::endl;
        return;
    }
    std::cout << "Removing " << tempSNode->m_data.getName() << " from " << tempFNode->m_data.getName() << "'s advisee list." << std::endl;
    tempFNode->m_data.removeFromList(studentID);
    tempSNode->m_data.setAdvisorID(-1);
    std::cout << "Student " << tempSNode->m_data.getName() << " now has no advisor." << std::endl;
}

//outputs the content of the student and faculty trees to a text file (called when the run() method is exited)
void Database::outputLog(){
    m_studentTree->printToFile("studentLog.txt");
    m_facultyTree->printToFile("facultyLog.txt");
    std::ofstream oFS;
    oFS.open("runLog.txt");
    std::ifstream inFS;
    std::string temp;
    inFS.open("studentLog.txt");
    while (std::getline(inFS, temp)){
        oFS << temp << std::endl;
    }
    inFS.close();
    inFS.open("facultyLog.txt");
    while (std::getline(inFS, temp)){
        oFS << temp << std::endl;
    }
    inFS.close();
    oFS.close();
}