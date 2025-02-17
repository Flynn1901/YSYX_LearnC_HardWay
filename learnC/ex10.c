#include <stdio.h>

//向main函数传递参数的时候不需要声明参数个数，直接写参数就好了
int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings，原来也可以这么写字符串数组的数组
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    argv[0] = "123";
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
