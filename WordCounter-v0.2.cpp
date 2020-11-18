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
    fp = fopen(name, "r");//打开要计数的文件
    if (fp == NULL)
	{

        printf("can not open file");
        exit(0);
	}
        fseek(fp, 00, SEEK_END);
        length = ftell(fp); //包含空格的字符数 
        rewind(fp);
        char str[100000], c;
        fread(str, sizeof(char), length, fp);//从文件中读取所有的字符到str序列
        int i, num1 = 1, num2 = 0, num3, num4=0, num5=0 , word = OUT;
        
        for (i = 0; (c = str[i]) != '\0'; i++)
		{

            if (c == ' ')//有一空格单词数加一 
			{
                  num2++;
                  word = OUT;
			}
			//else if (c == ',')//有一逗号单词数加一 
			//{
            //      num4++;
            //      word = OUT;
			//}
			else if (c == '.'  || c == '?' || c == '!' )//有句子结尾字符  
			{
                  num5++; //句子数 
                  word = OUT;
			}
            else
			{
                  if (word == OUT)
				  {
                        word = IN;

				  }
			}
            if ( (c = str[i]) == '\n') //有一换行 行数加一 
			{
                  num1++;
			}
		}
        num3 = length - num2 - 2*num1;//计算不包含空格 的字符数 
        fclose(fp);
        
        if ( mode == 1 )
        printf("字符数（含空格）为%d\n字符数（不含空格）为%d\n", length-2*num1, num3);
        else if ( mode == 2 )
        printf("单词数为%d\n", num2+num1);
        else if ( mode == 3 )
		printf("句子数为%d\n", num5);
		else if ( mode == 4 )
		printf("行数为%d\n", num1);
		else
		printf("参数输入错误\n"); 
	}
}
