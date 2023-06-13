#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int comparePeople(const void* a, const void* b) {
    return strcmp(((Person*)a)->name, ((Person*)b)->name);
}

int searchPerson(Person array[], int size, const char* name) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        int comparison = strcmp(array[mid].name, name);
        
        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    Person people[] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Carlos", 40},
        {"Daniel", 35},
        {"Eva", 28},
        {"Fernanda", 32},
        {"Gustavo", 45}
    };
    
    int size = sizeof(people) / sizeof(people[0]);
    
    char searchName[50];
    printf("Enter the name of the person you want to search for: ");
    scanf("%s", searchName);
    
    int index = searchPerson(people, size, searchName);
    
    if (index != -1) {
        printf("Person found!\n");
        printf("Name: %s\n", people[index].name);
        printf("Age: %d\n", people[index].age);
    } else {
        printf("Person not found.\n");
    }
    
    return 0;
}
