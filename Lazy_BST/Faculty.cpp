/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 5: Lazy BST
File contains function definitions for the Faculty class
*/
#include "Faculty.h"

//default constructor
Faculty::Faculty(){
    Faculty(0, "unknown", "unknown", "unknown");
}

//overloaded constructor - assigns member variables to the corresponding arguments
Faculty::Faculty(int numID, std::string name, std::string level, std::string department){
    m_ID = numID;
    m_name = name;
    m_level = level;
    m_department = department;
    m_numAdvisees = 0;
    m_maxAdvisees = 10;
    m_adviseeList = new int[m_maxAdvisees];
}

//destructor
Faculty::~Faculty(){}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator < (const Faculty& other) const{
    return m_ID < other.m_ID;
}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator > (const Faculty& other) const{
    return m_ID > other.m_ID;
}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator == (const Faculty& other) const{
    return m_ID == other.m_ID;
}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator != (const Faculty& other) const{
    return m_ID != other.m_ID;
}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator <= (const Faculty& other) const{
    return m_ID <= other.m_ID;
}

//overloaded operator - compares faculty members based on ID number
bool Faculty::operator >= (const Faculty& other) const{
    return m_ID >= other.m_ID;
}

//returns true if this faculty member has no advisees
bool Faculty::listIsEmpty(){
    return m_numAdvisees == 0;
}

//accessor for the m_maxAdvisees member variable
int Faculty::getMaxAdvisees(){
    return m_maxAdvisees;
}

//accessor for the m_ID member variable
int Faculty::getID(){
    return m_ID;
}

//mutator for the m_ID member variable
void Faculty::setID(int newID){
    m_ID = newID;
}

//accessor for the m_name member variable
std::string Faculty::getName(){
    return m_name;
}

//mutator for the m_name member variable
void Faculty::setName(std::string newName){
    m_name = newName;
}

//accessor for the m_level member variable
std::string Faculty::getLevel(){
    return m_level;
}

//mutator for the m_level member variable
void Faculty::setLevel(std::string newLevel){
    m_level = newLevel;
}

//accessor for the m_department member variable
std::string Faculty::getDepartment(){
    return m_department;
}

//mutator for the m_department member variable
void Faculty::setDepartment(std::string newDepartment){
    m_department = newDepartment;
}

//returns a string with the values held in m_adviseeList
std::string Faculty::displayAdviseeList(){
    std::string ret = "";
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_adviseeList[i] > 0){
            ret += std::to_string(m_adviseeList[i]);
            ret += " ";
        }
    }
    return ret;
}

//adds the given ID number to m_adviseeList
void Faculty::addToList(int idNumber){
    if (m_numAdvisees == m_maxAdvisees){
        std::cout << "resizing" << std::endl;
        int* temp = new int[2*m_maxAdvisees];
        for(int i = 0; i < m_maxAdvisees; i++){
            temp[i] = m_adviseeList[i];
        }
        m_maxAdvisees *= 2;
        m_adviseeList = temp;
        delete[] temp;
    }
    for (int i = 0; i < m_maxAdvisees; i++){  //adds the new student to the first open space in the list
        if (m_adviseeList[i] == 0){
            m_adviseeList[i] = idNumber;
            m_numAdvisees++;
            return;
        }
    }
}

//removes the given ID number from m_adviseeList
void Faculty::removeFromList(int idNumber){
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_adviseeList[i] == idNumber){
            m_adviseeList[i] = 0;
            m_numAdvisees--;
            return;
        }
    }
}

//removes and returns the first student ID number in m_adviseeList
int Faculty::removeFrontStudent(){
    for (int i = 0; i < m_maxAdvisees; i++){
        if (m_adviseeList[i] != 0){
            int ret = m_adviseeList[i];
            removeFromList(ret);
            return ret;
        }
    }
    return 0;
}