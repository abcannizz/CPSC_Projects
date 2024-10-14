Alex Cannizzaro
alexcannizzaro16@gmail.com
Course: CPSC-350-01 (Data Structures and Algorithms)
Programming Assignment 5: Lazy BST

Description:
    Includes a version of a self-balancing binary search tree (LazyBST.h) 
    This BST is implemented within a student/faculty database, where 
    students can be assigned to advisors, switched to other advisors, etc.
    All available actions are displayed to consol upon running the program.
    Actions are chosen based on integer input (integers 1-11).

Source files included:
    TreeNode.h
    LazyBST.h
    Student.h 
    Student.cpp 
    Faculty.h 
    Faculty.cpp 
    Database.h 
    Database.cpp 
    main.cpp

Instructions:
    Compile:
        g++ *.cpp -o bst
    Run:
        ./bst 
    Note:
    - no command line arguments needed
    - assumes that the expected data types are entered when prompted
        ex) enter ints when ID numbers are requested

References:
    https://www.tutorialspoint.com/balance-a-binary-search-tree-in-cplusplus
        - inspiration for fillTreeHelper method in LazyBST.h 
    https://www.nextptr.com/question/a403244152/how-to-implement-lessthan-comparison-operator
        - helped with overloading the comparison operators in the Student and Faculty classes
    https://stackoverflow.com/questions/53211020/making-my-own-tostring-method-on-c-struct
        - helped with overriding the operator << in order to print students in the tree
    https://stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int
        - displaying the faculty's list of advisors
    https://www.geeksforgeeks.org/problem-with-getline-after-cin/
        - using std::getline and cin consecutively
    I collaborated with Ross Ziegler on this project