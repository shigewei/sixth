#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0,flag=0,end=0;
int main()
{
	void zero();
	void fraction();
	void kuohao();
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
    int sum,language,i,swit,j,total;
	srand((unsigned int)time(NULL)); //������������� 
	printf("��ӭʹ������������ϰ����\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("��ѡ������ʹ�õ�����/Please choose the language your use:\n1.����/Chinese     2.Ӣ��/English\n");
	scanf("%d",&language);  //�����л�
	if(language==1)
		printf("������������Ҫ����Ŀ����");
	else
		printf("Please input the number you need:");
	scanf("%d",&sum);
	for(i=1;i<=sum;)
	{
		total=i-1;
		swit=rand()%3+1;
		switch(swit)
		{
		   case 1:zero();break;  //�����0�����ŵ�ʽ��
		   case 2:fraction();break;   //�������������ʽ��
		   case 3:kuohao();break;     //�������һ�����ŵ�ʽ��
		}
		if(flag==0)
			i++;
		flag=0;        //��flag����Ƿ��������Ŀ
	
		if(end==1)     //�������ѭ���������Ƿ���Ҫ�������� 
		   break;
	}
	if(language==1)
	{
		printf("��������������Ϊ��%4d\n",total);
		printf("������ȷ����Ϊ��%4d\n",rig);
		printf("���Ĵ�������Ϊ��%4d\n",wro);
		printf("��ӭ�ٴ�ʹ�ã�\n");
	}
	else
	{
		printf("The number of questions you have done is:%4d\n",total);
		printf(" right is:%4d\n",rig);
		printf("The number of questions you did wrong is:%4d\n",wro);
		printf("Welcome to use again!\n");
	}
	return 0;
}


//�����0�����ŵ�ʽ�ӵĺ���
void zero()  
{
	srand((unsigned int)time(NULL)); //������������� 
	int input=-8,sign[4],i,test;
	float temp[5],arr[5];
	char sig[4];
	for(i=1;i<=4;i++)
	{
		arr[i]=rand()%10+0;
	}
	temp[1]=arr[1];
	sig[0]='*';
	temp[0]=1;
	for(i=1;i<=3;i++)
	{
		sign[i]=rand()%4+1;
		if(sign[i]==1)
		{
			sig[i]='+';
		    temp[i+1]=temp[i]+arr[i+1];
	    }
		if(sign[i]==2)
		{
			sig[i]='-';
			temp[i+1]=temp[i]-arr[i+1];
		}	
		if(sign[i]==3)
		{
			sig[i]='*';
			if(sig[i-1]=='-')
			temp[i+1]=temp[i-1]-arr[i]*arr[i+1];
			else if(sig[i-1]=='+')
	    	temp[i+1]=temp[i-1]+arr[i]*arr[i+1];
			else
			temp[i+1]=temp[i]*arr[i+1];
		}
		
		if(sign[i]==4)
		{
			sig[i]='/';
			if(sig[i-1]=='-')
			temp[i+1]=temp[i-1]-arr[i]/arr[i+1];
		    else if(sig[i-1]=='+')
	    	temp[i+1]=temp[i-1]+arr[i]/arr[i+1];
			else
			temp[i+1]=temp[i]/arr[i+1];
		}
	}
	test=temp[4];
	if(temp[4]==test&&temp[4]>=0)     //��test��Ϊ�������������ʽ�ӽ���Ƿ�Ϊ�Ǹ������������Ѷ�
	{
		printf("%.0f%c%.0f%c%.0f%c%.0f=",arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);

printf("%d",test);

		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(input==test)
			   rig++;
		    else
			   wro++;
	    }
	}
	else
		flag=1;     //��flag����Ƿ��������Ŀ
}


//��������������㺯�� 
void fraction()  
{
	srand((unsigned int)time(NULL)); //������������� 
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
	int mu1,zi1,mu2,zi2,com,sign,mu3,zi3,yue,input1=-8,input2=-8;
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
    }                        //�ó���һ����������
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
    }                       //�ó��ڶ�����������
	sign=rand()%4+1;        //�������
	if(sign==1)                                         //�ӷ�
	{	
		printf("(%d/%d)+(%d/%d)=",zi1,mu1,zi2,mu2);
		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1+zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;          //Լ�ּ���
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
		    if(input1<0)
		       end=1;
			else
			{	
			    if(input1==(zi3/mu3))
				   rig++;
			    else
				   wro++;
		    }
	    }
		else
		{
			scanf("%d/%d",&input1,&input2);
			if(input1<0)
			   end=1;
			else
			{
			    if(input1==zi3&&input2==mu3)
				   rig++;
			    else
				   wro++;
		    }
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==2)                                   //����
	{	

		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1-zi2;
		if(zi3<=0)        //������ָ����⣬���ǵ���ͬ�����������ûʲô̫�����壬һ��ɾȥ��
			flag=1;
		else
		{
			com=max(mu3,zi3);
			mu3=mu3/com;
			zi3=zi3/com;
			printf("(%d/%d)-(%d/%d)=",zi1/(yue/mu1),mu1,zi2/(yue/mu2),mu2);
			if(zi3%mu3==0)
			{
			scanf("%d",&input1);
			if(input1<0)
			   end=1;
			else
			{
			   if(input1==(zi3/mu3))
			    	rig++;
			    else
				    wro++;
		    }
			}
		   else
		   {
			scanf("%d/%d",&input1,&input2);
			if(input1<0)
			    end=1;
			else
			{
		    	if(input1==zi3&&input2==mu3)
			    	rig++;
		    	else
			    	wro++;
		    }
		   }
			printf("%d/%d\n",zi3,mu3);
		}
	}
	if(sign==3)                                //�˷�
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
			if(input1<0)
			    end=1;
			else
			{
	    		if(input1==(zi3/mu3))
			    	rig++;
		    	else
		    		wro++;
		    }
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
			if(input1<0)
	    		end=1;
	    	else
	    	{
			    if(input1==zi3&&input2==mu3)
			    	rig++;
    	    	else
			    	wro++;
		    }
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==4)                             //����
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
			if(input1<0)
			    end=1;
			else
			{
	    		if(input1==(zi3/mu3))
			    	rig++;
		    	else
		    		wro++;
		    }
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
			if(input1<0)
	    		end=1;
	    	else
	    	{
			    if(input1==zi3&&input2==mu3)
			    	rig++;
    	    	else
			    	wro++;
		    }
		}
		printf("%d/%d\n",zi3,mu3);
	}
}

int max(int a,int b)   //�����Լ������
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


int min(int a,int b)   //����С����������
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


//�������һ�����ŵ�ʽ�ӵĺ���
void kuohao()
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	void kuohao1(float big,float arr[5],char sig[4]);
	void kuohao2(float big,float arr[5],char sig[4]);
	void kuohao3(float big,float arr[5],char sig[4]);
	void kuohao4(float arr[5],char sig[4]);
	void kuohao5(float arr[5],char sig[4]);   
	int i,choose,symbol;
	float big,arr[5];
	char sig[4];
	for(i=1;i<=4;i++)
	{
		arr[i]=rand()%10+1;
	}
	symbol=rand()%4+1;
	switch(symbol)
	{
		case 1:sig[1]='+';big=arr[1]+arr[2];break;
		case 2:sig[1]='-';big=arr[1]-arr[2];break;
		case 3:sig[1]='*';big=arr[1]*arr[2];break;
		case 4:sig[1]='/';big=arr[1]/arr[2];break;
	}
	choose=rand()%5+1;
	switch(choose)
	{
		case 1:kuohao1(big,arr,sig);break;
		case 2:kuohao2(big,arr,sig);break;
		case 3:kuohao3(big,arr,sig);break;
		case 4:kuohao4(arr,sig);break;
		case 5:kuohao5(arr,sig);break;
	}
}





 //������磨1+2��*3+4=��ʽ�� 
void kuohao1(float big,float arr[5],char sig[4])  
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	float caculate(float big,float a,float b,char sig[4]);
	int test,input=-8;
	float temp;
	temp=caculate(big,arr[3],arr[4],sig);
	test=temp;
	if(test==temp&&test>=0)
	{
		printf("(%.0f%c%.0f)%c%.0f%c%.0f=",arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
		printf("%d",test);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
		        rig++;
		    else
		        wro++;
	    }
	}
	else
	   flag=1;
}


//�������1+(2+3)*4=��ʽ�� 
void kuohao2(float big,float arr[5],char sig[4])     
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	float caculate(float big,float a,float b,char sig[4]);
	int test,input=-8;
	float temp;
	temp=caculate(arr[3],big,arr[4],sig);
	test=temp;
	if(test==temp&&test>=0)
	{
		printf("%.0f%c(%.0f%c%.0f)%c%.0f=",arr[3],sig[2],arr[1],sig[1],arr[2],sig[3],arr[4]);
		printf("%d",test);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
		        rig++;
		    else
		        wro++;
	    }
	}
	else
	   flag=1;
}


//�������1+2*(3+4)=��ʽ��  
void kuohao3(float big,float arr[5],char sig[4])     
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	float caculate(float big,float a,float b,char sig[4]);
	int test,input=-8;
	float temp;
	temp=caculate(arr[3],arr[4],big,sig);
	test=temp;
	if(test==temp&&test>=0)
	{
		printf("%.0f%c%.0f%c(%.0f%c%.0f)=",arr[3],sig[2],arr[4],sig[3],arr[1],sig[1],arr[2]);
		printf("%d",test);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
		        rig++;
		    else
		        wro++;
	    }
	}
	else
	   flag=1;
}



//������磨1+2*3��+4=��ʽ�� 
void kuohao4(float arr[5],char sig[4])         
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	float caculate(float big,float a,float b,char sig[4]);
	int test,input=-8,fuhao;
	float temp;
	temp=caculate(arr[1],arr[2],arr[3],sig);
	fuhao=rand()%4+1;
	if(fuhao==1)
	{
		temp=temp+arr[4];
		sig[1]='+';
	}
	if(fuhao==2)
	{
		temp=temp-arr[4];
		sig[1]='-';
	}
	if(fuhao==3)
	{
		temp=temp*arr[4];
		sig[1]='*';
	}
	if(fuhao==4)
	{
		temp=temp/arr[4];
		sig[1]='/';
	}
	test=temp;
	if(test==temp&&test>=0)
	{
		printf("(%.0f%c%.0f%c%.0f)%c%.0f=",arr[1],sig[2],arr[2],sig[3],arr[3],sig[1],arr[4]);
		printf("%d",test);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
		        rig++;
		    else
		        wro++;
	    }
	}
	else
	   flag=1;
}


//�������1+��2+3*4��=��ʽ�� 
void kuohao5(float arr[5],char sig[4])         
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	float caculate(float big,float a,float b,char sig[4]);
	int test,input=-8,fuhao;
	float temp;
	temp=caculate(arr[2],arr[3],arr[4],sig);
	fuhao=rand()%4+1;
	if(fuhao==1)
	{
		temp=arr[1]+temp;
		sig[1]='+';
	}
	if(fuhao==2)
	{
		temp=arr[1]-temp;
		sig[1]='-';
	}
	if(fuhao==3)
	{
		temp=arr[1]*temp;
		sig[1]='*';
	}
	if(fuhao==4)
	{
		temp=arr[1]/temp;
		sig[1]='/';
	}
	test=temp;
	if(test==temp&&test>=0)
	{
		printf("%.0f%c(%.0f%c%.0f%c%.0f)=",arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
		printf("%d",test);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
		        rig++;
		    else
		        wro++;
	    }
	}
	else
	   flag=1;
}


//���㺬����������ʽ�ӽ���ĺ��� 
float caculate(float big,float a,float b,char sig[4])   
{
	srand((unsigned int)time(NULL));//���õ�ǰʱ��Ϊ����
	int sym1,sym2,i;
	float temp;
	sym1=rand()%4+1;
	if(sym1==1)
	{
		temp=big+a;
		sig[2]='+';
	}
	else if(sym1==2)
	{
		temp=big-a;
		sig[2]='-';
	}	
	else if(sym1==3)
	{
		temp=big*a;
		sig[2]='*';
	}	
	else
	{
		temp=big/a;
		sig[2]='/';
	}
			
	sym2=rand()%4+1;
	if(sym2==1)
	{
		temp=temp+b;
		sig[3]='+';
	}
	else if(sym2==2)
	{
		temp=temp-b;
		sig[3]='-';
	}
	else if(sym2==3)
	{
		if(sym1==1)
		{
			temp=big+a*b;
		}
		else if(sym1==2)
		{
			temp=big-a*b;
		}
		else
		{
			temp=temp*b;
		}
		sig[3]='*';
	}
	else
	{
		if(sym1==1)
		{
			temp=big+a/b;
		}
		else if(sym1==2)
		{
			temp=big-a/b;
		}
		else
		{
			temp=temp/b;
		}
		sig[3]='/';
	}
	return(temp);
}


