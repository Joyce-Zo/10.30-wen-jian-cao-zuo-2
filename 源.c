#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<errno.h>

int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");	// ���ļ�
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));	// ���������Ϣ
	}
	fputc('J', pf);
	fputc('O', pf);	// д���ݵ��ļ���
	fputc('Y', pf);
	fputc('C', pf);
	fputc('E', pf);

	int ch = fgetc(pf); // ���ļ�
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);
	ch = fgetc(pf);
	printf("%c", ch);  // ����ļ�����

	fgets(buf, 1024, pf);
	printf("%s", buf);
	puts(buf);	//  ���Զ�����
	fgets(buf, 1024, pf);
	printf("%s", buf);
	puts(buf);	

	fclose(pf);	// �ر��ļ�
	pf = NULL;

	return 0;
}

int main()
{
	char buf[1024] = { 0 };

	FILE* pf = fopen("test.txt", "w");	// ���ļ�
	if (pf == NULL)
	{
		printf("%s ", strerror(errno));	// ���������Ϣ
	}
	fputs("I love you.\n", pf);//��Ҫ��\n �ֶ����У�һ��һ��
	fputs("Tatina.", pf);

	fclose(pf);
	pf = NULL;
}

int main()
{
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);	// �ӱ�׼��������ȡ
	fputs(buf, stdout);		// �ӱ�׼��������
	gets(buf);	// ������2�еȼ�
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
		��ʽ����������ݵ��ļ�

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
		��ʽ���Ĵ��ļ������ļ�����Ļ
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
		��ʽ���Ĵ��ļ������ļ�����Ļ
	fprintf(stdout,"%s %d %s %s %.2f", s.name, s.age, s.sex, s.tele, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}