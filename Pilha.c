#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int studentID;
} Student;

typedef struct {
    Student** stack;
    int top;
    int capacity;
} StudentStack;

Student* createStudent(char* name, int studentID) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->name = name;
    newStudent->studentID = studentID;
    return newStudent;
}

StudentStack* createStudentStack(int capacity) {
    StudentStack* stack = (StudentStack*)malloc(sizeof(StudentStack));
    stack->stack = (Student**)malloc(capacity * sizeof(Student*));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(StudentStack* stack, Student* student) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->stack[++stack->top] = student;
}

Student* pop(StudentStack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->stack[stack->top--];
}

int main() {
    StudentStack* studentStack = createStudentStack(3);
    
    Student* student1 = createStudent("John", 1001);
    Student* student2 = createStudent("Maria", 1002);
    Student* student3 = createStudent("Peter", 1003);
    
    push(studentStack, student1);
    push(studentStack, student2);
    push(studentStack, student3);
    
    printf("Stack size: %d\n", studentStack->top + 1);
    
    Student* removedStudent = pop(studentStack);
    if (removedStudent != NULL) {
        printf("Removed student: %s\n", removedStudent->name);
    }
    
    printf("Stack size after removal: %d\n", studentStack->top + 1);
    
    return 0;
}
