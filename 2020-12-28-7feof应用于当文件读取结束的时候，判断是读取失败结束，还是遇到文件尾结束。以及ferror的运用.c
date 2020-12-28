//feof应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束。以及ferror的运用
#include<stdio.h>
int main()
{
	FILE* sp = fopen("F:\\c语言基础\\test1.txt","r");
	if (sp == NULL)
	{
		perror("test1.txt:");
		return 0;
	}
	//读文件
	int ch=0;
	while ((ch=fgetc(sp))!= EOF)
	{
		putchar(ch);//用putc报错
	}
	printf("\n");
	if (ferror(sp))//返回不是0，没有错，非零（为真）有错
	{
		printf("文件读取失败");
	}
	else if (feof(sp))
	{
		printf("end of file");
	}
	fclose(sp);
	sp = NULL;
	return 0;
}