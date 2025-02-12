#include <stdio.h>

int main()
{
	FILE *file = fopen("Makefile", "a"); // 以追加模式打开文件
	
	if (file == NULL) {
        	perror("无法打开文件");
        	return 1;
    	}
    	int i;
    	for(i=0;i<48;i++){
    		fprintf(file,"ex%d: ex%d.c\n\tgcc -g -Wall ex%d.c -o ex%d\n\n",i,i,i,i);
    	}
    	
    	return 0;


}
