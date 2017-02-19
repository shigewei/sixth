#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0,flag=0;
int main()
{
	void fraction();
	int max(int a,int b);  //最大公约数函数声明
	int min(int a,int b);  //最小公倍数函数声明
    int sum,language,i,swit,num[4],j;
	srand((unsigned int)time(NULL)); //设置随机数种子 
	printf("欢迎使用四则运算练习程序！\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("请选择您所使用的语言/Please choose the language your use:\n1.中文/Chinese     2.英文/English\n");
	scanf("%d",&language);  //语言切换
	if(language==1)
		printf("请输入您所需要的题目数：");
	else
		printf("Please input the number you need:");
	scanf("%d",&sum);
	for(i=1;i<=sum;)
	{
		for(j=1;j<=4;j++)
		{
			num[j]=rand()%10+1;
		}
		swit=1;
		switch(swit)
		{
		   case 1:fraction();break;   //输出真分数计算的式子
		}
		if(flag==0)
			i++;
		flag=0;   //用flag检测是否输出了题目
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



//真分数的四则运算 
void fraction()  
{
	srand((unsigned int)time(NULL)); //设置随机数种子 
	int max(int a,int b);  //最大公约数函数声明
	int min(int a,int b);  //最小公倍数函数声明
	int mu1,zi1,mu2,zi2,com,sign,mu3,zi3,yue,input1,input2;
	for(;;)
	{
		mu1=rand()%10+1;		
		zi1=rand()%10+1;		
		if(mu1<=zi1)
		    continue;
		else
		{
			com=max(mu1,zi1);
			mu1=mu1/com;
			zi1=zi1/com;
		    break;
		}
    }                        //得出第一个最简真分数
	for(;;)
	{
		mu2=rand()%10+1;		
		zi2=rand()%10+1;		
		if(mu2<=zi2)
		    continue;
		else
		{
			com=max(mu2,zi2);
			mu2=mu2/com;
			zi2=zi2/com;
		    break;
		}
    }                       //得出第二个最简真分数
	sign=rand()%4+1;        //随机符号
	if(sign==1)                                         //加法
	{	
		printf("%d/%d+%d/%d=",zi1,mu1,zi2,mu2);
		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1+zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;          //约分计算
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
			if(input1==zi3&&input2==mu3)
				rig++;
			else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==2)                                   //减法
	{	

		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1-zi2;
		if(zi3<=0)        //避免出现负数题，考虑到相同的两分数相减没什么太大意义，一并删去了
			flag=1;
		else
		{
			com=max(mu3,zi3);
			mu3=mu3/com;
			zi3=zi3/com;
			printf("%d/%d-%d/%d=",zi1/(yue/mu1),mu1,zi2/(yue/mu2),mu2);
			if(zi3%mu3==0)
			{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
			}
		   else
		   {
			scanf("%d/%d",&input1,&input2);
			if(input1==zi3&&input2==mu3)
				rig++;
			else
				wro++;
		   }
			printf("%d/%d\n",zi3,mu3);
		}
	}
	if(sign==3)                                //乘法
	{
		printf("(%d/%d)*(%d/%d)=",zi1,mu1,zi2,mu2);
		mu3=mu1*mu2;
		zi3=zi1*zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
		if(input1==zi3&&input2==mu3)
				rig++;
		else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==4)                             //除法
	{
		printf("(%d/%d)/(%d/%d)=",zi1,mu1,zi2,mu2);
		mu3=mu1*zi2;
		zi3=zi1*mu2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
		if(input1==zi3&&input2==mu3)
				rig++;
		else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
}

int max(int a,int b)   //求最大公约数函数
{
	int i,temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	for(i=b;i>=1;i--)
	{
		if(a%b==0)
		{
			return(b);
			break;
		}
		if(a%i==0&&b%i==0)
		{
			return(i);
			break;
		}
	}
}


int min(int a,int b)   //求最小公倍数函数
{
	int i,temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	for(i=a;;i++)
	{
		if(a%b==0)
		{
			return(a);
			break;
		}
		if(i%a==0&&i%b==0)
		{
			return(i);
			break;
		}
	}
}
