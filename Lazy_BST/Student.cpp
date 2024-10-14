/*
Alex Cannizzaro
Student ID: 2421315
acannizzaro@chapman.edu
CPSC-350-01
Programming Assignment 5: Lazy BST
File contains function definitions for the Student class
*/
#include "Student.h"

//default constructor
Student::Student(){
    m_ID = 0;
    m_name = "unknown";
    m_level = "unknown";
    m_major = "unknown";
    m_GPA = 0.0;
    m_advisorID = 0;
}

//overloaded constructor - assigns member variables to the corresponding arguments
Student::Student(int numID, std::string name, std::string level, std::string major, double gpa, int advisor){
    m_ID = numID;
    m_name = name;
    m_level = level;
    m_major = major;
    m_GPA = gpa;
    m_advisorID = advisor;
}

//destructor
Student::~Student(){}

//overloaded operator - compares students based on ID number
bool Student::operator < (const Student& other) const{
    return m_ID < other.m_ID;
}

//overloaded operator - compares students based on ID number
bool Student::operator > (const Student& other) const{
    return m_ID > other.m_ID;
}

//overloaded operator - compares students based on ID number
bool Student::operator == (const Student& other) const{
    return m_ID == other.m_ID;
}

//overloaded operator - compares students based on ID number
bool Student::operator != (const Student& other) const{
    return m_ID != other.m_ID;
}

//overloaded operator - compares students based on ID number
bool Student::operator <= (const Student& other) const{
    return m_ID <= other.m_ID;
}

//overloaded operator - compares students based on ID number
bool Student::operator >= (const Student& other) const{
    return m_ID >= other.m_ID;
}

//accessor for the m_ID member variable
int Student::getID(){
    return m_ID;
}

//mutator for the m_ID member variable
void Student::setID(int newID){
    m_ID = newID;
}

//accessor for the m_name member variable
std::string Student::getName(){
    return m_name;
}

//mutator for the m_name member variable
void Student::setName(std::string newName){
    m_name = newName;
}

//accessor for the m_level member variable
std::string Student::getLevel(){
    return m_level;
}

//mutator for the m_level member variable
void Student::setLevel(std::string newLevel){
    m_level = newLevel;
}

//accessor for the m_major member variable
std::string Student::getMajor(){
    return m_major;
}

//mutator for the m_major member variable
void Student::setMajor(std::string newMajor){
    m_major = newMajor;
}

//accessor for the m_GPA member variable
double Student::getGPA(){
    return m_GPA;
}

//mutator for the m_GPA member variable
void Student::setGPA(double newGPA){
    m_GPA = newGPA;
}

//accessor for the m_advisorID member variable
int Student::getAdvisorID(){
    return m_advisorID;
}

//mutator for the m_advisorID member variable
void Student::setAdvisorID(int newAdvisorID){
    m_advisorID = newAdvisorID;
}