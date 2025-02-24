#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);//声明了一种函数类型。只要被调用者符合这个函数声明，即可被使用。

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));//从源数组拷贝到目标数组

    for(i = 0; i < count; i++) {//最多需要count-1次
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {//decouple，将函数的声明与实现分开，提供了更多的选择性，可以传递任何符合声明的函数名
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;//冒泡排序，左右互换位置
            }
        }
    }

    return target;//返回排序好的新数组
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)//传递比较函数，可以实现不同的排序方法
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);//进行冒泡排序

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");//打印排序结果

    free(sorted);
    unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++) {
    	printf("%02x:", data[i]);
	}

	printf("\n");
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}
