#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};//build a struct containing four elements

struct Person *Person_create(char *name, int age, int height, int weight)//initialize the struct, return address of struct
{
    struct Person *who = malloc(sizeof(struct Person));//便于传递参数
    assert(who != NULL);

    who->name = strdup(name);//使用strdup来复制字符串name，是为了确保结构体真正拥有它。strdup的行为实际上类似malloc但是它同时会将原来的字符串复制到新创建的内存
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

/*
struct Person Person_create2(char *name, int age, int height, int weight)
{
    struct Person who = {0};

    who.name = strdup(name);
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}*/

void Person_destroy(struct Person *who)//free space in heap, containing struct and name
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)//print the information of struct
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);//initialize the first structure

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);//initialize the second structure
            
    printf("The size of each structure is: %lu",sizeof(struct Person));

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);
    Person_destroy(NULL);

    return 0;
}
