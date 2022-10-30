#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<errno.h>

int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");	// 打开文件
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));	// 输出错误信息
	}
	fputc('J', pf);
	fputc('O', pf);	// 写内容到文件中
	fputc('Y', pf);
	fputc('C', pf);
	fputc('E', pf);

	int ch = fgetc(pf); // 读文件
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);  // 输出文件内容

	fgets(buf, 1024, pf);
	printf("%s", buf);
	puts(buf);	//  会自动换行
	fgets(buf, 1024, pf);
	printf("%s", buf);
	puts(buf);	

	fclose(pf);	// 关闭文件
	pf = NULL;

	return 0;
}

int main()
{
	char buf[1024] = { 0 };

	FILE* pf = fopen("test.txt", "w");	// 打开文件
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));	// 输出错误信息
	}
	fputs("I love you.\n", pf);//需要加\n 手动换行，一次一行
	fputs("Tatina.", pf);

	fclose(pf);
	pf = NULL;
}

int main()
{
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);	// 从标准输入流读取
	fputs(buf, stdout);		// 从标准输出流输出
	gets(buf);	// 与上面2行等价
	puts(buf);
	return 0;
}

struct S
{
	char name[1024];
	int age;
	char sex[20];
	char tele[12];
	float height;
};
int main()
{
	struct S s = { "Joyce",21,"male","19906932001",181.5f };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));
	}
	fprintf(pf, "%s %d %s %s %f", s.name, s.age, s.sex, s.tele, s.height);
		格式化的输出数据到文件

	fclose(pf);
	pf = NULL;
	return 0;
}

struct S
{
	char name[1024];
	int age;
	char sex[20];
	char tele[12];
	float height;
};
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));
	}
	fscanf(pf, "%s %d %s %s %f", &(s.name), &(s.age), &(s.sex), &(s.tele), &(s.height));
		格式化的从文件输入文件到屏幕
	printf("%s %d %s %s %f", s.name, s.age, s.sex, s.tele, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}

struct S
{
	char name[1024];
	int age;
	char sex[20];
	char tele[12];
	float height;
};
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));
	}
	fscanf(stdin, "%s %d %s %s %f", &(s.name), &(s.age), &(s.sex), &(s.tele), &(s.height));
		格式化的从文件输入文件到屏幕
	fprintf(stdout,"%s %d %s %s %.2f", s.name, s.age, s.sex, s.tele, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}