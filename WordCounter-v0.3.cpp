#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <iostream>
#define IN 1
#define OUT 0
using namespace std;
 
int main() 
{
    while(1) 
    {

	FILE *fp;
    int length;
    char name[99];
	int mode;
    char a[9];
    cin >> a >> mode >> name;
    fp = fopen(name, "r");//��Ҫ�������ļ�
    if (fp == NULL)
	{

        printf("can not open file");
        exit(0);
	}
        fseek(fp, 00, SEEK_END);
        length = ftell(fp); //�����ո���ַ��� 
        rewind(fp);
        char str[100000], c;
        fread(str, sizeof(char), length, fp);//���ļ��ж�ȡ���е��ַ���str����
        int i, num1 = 1, num2 = 0, num3, num4=0, num5=0 , word = OUT;
        
        for (i = 0; (c = str[i]) != '\0'; i++)
		{

            if (c == ' ')//��һ�ո񵥴�����һ 
			{
                  num2++;
                  word = OUT;
			}
			//else if (c == ',')//��һ���ŵ�������һ 
			//{
            //      num4++;
            //      word = OUT;
			//}
			else if (c == '.'  || c == '?' || c == '!' )//�о��ӽ�β�ַ�  
			{
                  num5++; //������ 
                  word = OUT;
			}
            else
			{
                  if (word == OUT)
				  {
                        word = IN;

				  }
			}
            if ( (c = str[i]) == '\n') //��һ���� ������һ 
			{
                  num1++;
			}
		}
        num3 = length - num2 - 2*num1;//���㲻�����ո� ���ַ��� 
        fclose(fp);
        
        if ( mode == 1 )
        printf("�ַ��������ո�Ϊ%d\n�ַ����������ո�Ϊ%d\n", length-2*num1, num3);
        else if ( mode == 2 )
        printf("������Ϊ%d\n", num2+num1);
        else if ( mode == 3 )
		printf("������Ϊ%d\n", num5);
		else if ( mode == 4 )
		printf("����Ϊ%d\n", num1);
		else
		printf("�����������\n"); 
	}
}
