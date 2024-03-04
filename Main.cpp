//============================================================================
// Name        : Main.cpp
// Author      : Jacob Burchett
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//Define course structure to store course information//
struct Course {
    string courseNumber;
    string courseTitle;
    string prerequisite1;
    string prerequisite2;
    Course* left;
    Course* right;
};

//Define binary search tree to store course objects//
class BinarySearchTree {
public:
    BinarySearchTree() {
        root = nullptr;
    }
    void insert(Course* course) {
        root = insertHelper(root, course);
    }
    void inorderTraversal() {
        inorderTraversalHelper(root);
    }
    Course* search(string courseNumber) {
        return searchHelper(root, courseNumber);
    }
private:
    Course* root;
    Course* insertHelper(Course* node, Course* course) {
        if (node == nullptr) {
            node = course;
        }
        else if (node->courseNumber > course->courseNumber) {
            node->left = insertHelper(node->left, course);
        }
        else {
            node->right = insertHelper(node->right, course);
        }
        return node;
    }
    void inorderTraversalHelper(Course* node) {
        if (node != nullptr) {
            inorderTraversalHelper(node->left);
            cout << node->courseNumber << ", " << node->courseTitle << endl;
            inorderTraversalHelper(node->right);
        }
    }
    Course* searchHelper(Course* node, string courseNumber) {
        if (node == nullptr || node->courseNumber == courseNumber) {
            return node;
        }
        else if (node->courseNumber > courseNumber) {
            return searchHelper(node->left, courseNumber);
        }
        else {
            return searchHelper(node->right, courseNumber);
        }
    }
};

//Define array to store course objects//
class CourseArray {
public:
    CourseArray(int size) {
        capacity = size;
        courses = new Course * [capacity];
        numCourses = 0;
    }
    void add(Course* course) {
        courses[numCourses++] = course;
    }
    void sort() {
        std::sort(courses, courses + numCourses, [](const Course* a, const Course* b) {
            return a->courseNumber < b->courseNumber;
            });
    }
    void print() {
        for (int i = 0; i < numCourses; i++) {
            cout << courses[i]->courseNumber << ", " << courses[i]->courseTitle << endl;
        }
    }
    Course* search(string courseNumber) {
        for (int i = 0; i < numCourses; i++) {
            if (courses[i]->courseNumber == courseNumber) {
                return courses[i];
            }
        }
        return nullptr;
    }
private:
    Course** courses;
    int capacity;
    int numCourses;
};

//Define function to parse line input and create course object//
Course* parseCourse(string line) {
    Course* course = new Course;
    size_t commaPos1 = line.find(",");
    size_t commaPos2 = line.find(",", commaPos1 + 1);
    size_t commaPos3 = line.find(",", commaPos2 + 1);
    course->courseNumber = line.substr(0, commaPos1);
    course->courseTitle = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
    course->prerequisite1 = prerequisite1;
    course->prerequisite2 = prerequisite2;
    course->prerequisite3 = prerequisite3;
    courseBST.insert(course);
}
inputFile.close();
cout << "Data successfully loaded." << endl;
}

//Function to print alphanumeric course list//
void printCourseList(BST<Course>& courseBST)
{
    //Create vector to store courses//
    vector<Course> courses;

    //Traverse binary search tree and insert courses into vector//
    courseBST.inOrderTraversal([&](Course* course) {
        courses.push_back(*course);
        });

    //Sort vector alphanumerically//
    sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
        });

    //Print sorted course list//
    cout << "All courses in the Computer Science department:" << endl;
    for (const Course& course : courses) {
        cout << course.courseNumber << ", " << course.courseTitle << endl;
    }
}

//Function to print course information//
void printCourseInfo(BST<Course>& courseBST)
{
    string courseNumber;
    cout << "What course would you like want to know about? ";
    cin >> courseNumber;

    //Search for course in binary search tree//
    Course* course = courseBST.search(Course(courseNumber, ""));

    if (course != nullptr) {
        cout << course->courseNumber << ", " << course->courseTitle << endl;
        cout << "Prerequisites: ";
        if (!course->prerequisite1.empty()) {
            cout << course->prerequisite1;
            if (!course->prerequisite2.empty() || !course->prerequisite3.empty()) {
                cout << ", ";
            }
        }
        if (!course->prerequisite2.empty()) {
            cout << course->prerequisite2;
            if (!course->prerequisite3.empty()) {
                cout << ", ";
            }
        }
        if (!course->prerequisite3.empty()) {
            cout << course->prerequisite3;
        }
        cout << endl;
    }
    else {
        cout << "Course not found." << endl;
    }
}

//Function to display menu and handle input//
void displayMenu(BST<Course>& courseBST)
{
    int choice = 0;
    while (choice != 9) {
        cout << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            loadDataStructure(courseBST);
            break;
        case 2:
            printCourseList(courseBST);
            break;
        case 3:
            printCourseInfo(courseBST);
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }
}
}

int main()
{
    //Create binary search tree to store courses//
    BSTabcucourseplanner::Course courseBST;

    //Display menu and handle input//
    abcucourseplanner::displayMenu(courseBST);

    return 0;

}