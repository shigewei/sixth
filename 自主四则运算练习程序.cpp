#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0;
int main()
{
    int sum,language,i,swit;
	printf("欢迎使用四则运算练习程序！\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("请选择您所使用的语言：中文请输入1，英文请输入0。\n");
	printf("please choose the language your use:input '1' for the Chinese,input '0' for the English.\n");
	scanf("%d",&language);
	if(language==1)
		printf("请输入您所需要的题目数：");
	else
		printf("Please input the number you need:");
	scanf("%d",&sum);
	for(i=1;i<=sum;i++)
	{
		swit=rand()%1+10;
		switch(swit)
		{
		   case'1':   ;break;
		}
	}
	if(language==1)
	{
		printf("您的正确题数为：%4d\n",rig);
		printf("您的错误题数为：%4d\n",wro);
		printf("欢迎再次使用！\n");
	}
	else
	{
		printf("The number of questions you did right is:%4d\n",rig);
		printf("The number of questions you did wrong is:%4d\n",wro);
		printf("Welcome to use again!\n");
	}
	return 0;
}