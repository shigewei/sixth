#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0,flag=0,end=0,language,test0=0,tihao=1;
int main()
{
	void zero();
	void fraction();
	void kuohao();
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
    int sum,i,swit,total,total2,style;
	float right,sum2;
	srand((unsigned int)time(NULL)); //������������� 
	printf("��ӭʹ������������ϰ����\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("��ѡ������ʹ�õ�����/Please choose the language your use:\n1.����/Chinese     2.Ӣ��/English\n");
	scanf("%d",&language);  //�����л�
	if(language==1)
	{
		printf("˵����1.��Ŀ�г����������ŵ�Ϊ�������㣬������������𰸵������ʽ��\n      2.����;��ֹͣ���������롰e����\n");
		printf("      3.�ó������н�Ϊ�����������ĵȴ���\n\n");
		printf("��ѡ������Ҫ�ļ�������\n1.��������    2.��������    3.���϶���\n");
		scanf("%d",&style);
		printf("������������Ҫ����Ŀ����");
	}
	else
	{
		printf("Instructions:\n1.The question has two brackets is fractional calculation,please input the simplest answer;\n");
		printf("2.If you want to stop the program before the end,please input 'e'\n");
		printf("3.The program is running slowly,please be patient.\n\n");
		printf("Please select the type of calculation you want:\n1.Integer calculation.    2.Fractional calculation.    3.both.\n");
		scanf("%d",&style);
		printf("Please input the number you need:");
	}
	scanf("%d",&sum);
	for(i=1;i<=sum;)
	{
		total=i-1;
		if(style==1)
		{
			swit=rand()%2+1;
		}
		else if(style==2)
		{
			swit=3;
		}
		else
		{
			swit=rand()%3+1;
		}
		switch(swit)
		{
		   case 1:zero();break;  //�����0�����ŵ�ʽ��
		   case 2:kuohao();break;     //�������һ�����ŵ�ʽ��
		   case 3:fraction();break;   //�������������ʽ��
		}
		total2=i;
		if(flag==0)
			i++;
		flag=0;        //��flag����Ƿ��������Ŀ
		test0=0;       //�������ʽ����ĳ����Ƿ�Ϊ0

		if(end==1)     //�������ѭ���������Ƿ���Ҫ�������� 
		   break;

	}
	if(total2==sum)
		total=sum;
	sum2=sum;
	right=rig;        //�������ʱ����ȷ�ʼ���
	printf("\n");
	if(language==1)
	{
		if(sum!=total)
			printf("��־���ʤ�����´������ȫ����Ŀ��\n");
		else
		{
			if(rig==0&&wro==sum)
				printf("ʧ���ǳɹ�֮ĸ�������ϰһ�����н����ģ�\n");
			else if(right/sum2<0.6)
				printf("�����٣��ټӰѾ����ܳɹ��ˣ�\n");
			else if(right/sum2>=0.6&&right/sum<0.8)
				printf("״̬�����������ͣ�\n");
			else if(right/sum<0.8&&rig!=sum)
				printf("�ӽ������ˣ�����������ͣ�\n");
			else if(rig==sum)
				printf("ȫ����ԣ��������֣�\n");
			else
			    printf("״̬�����������ͣ�\n");
		}
		printf("��������������Ϊ��%4d\n",total);
		printf("�����ȷ����Ϊ��%4d\n",rig);
		printf("��Ĵ�������Ϊ��%4d\n",wro);
		printf("��ӭ�ٴ�ʹ�ã�\n");
	}
	else
	{
		if(sum!=total)
			printf("Success belongs to the persevering��complete all questions next time!\n");
		else
		{
			if(rig==0&&wro==sum)
				printf("Failure is the mother of success,practice makes perfect!\n");
			else if(right/sum2<0.6)
				printf("Don't be discouraged,work harder for success.\n");
			else if(right/sum2>=0.6&&right/sum<0.8)
				printf("Good��keep trying!\n");
			else if(right/sum<0.8&&rig!=sum)
				printf("Nearly perfect,be careful next time!\n");
			else if(rig==sum)
				printf("perfect!Keep on!\n");
			else 
			    printf("Good!\n");
		}
		printf("The number of questions you have done is:%4d\n",total);
		printf("The number of questions you did right is:%4d\n",rig);
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
			if(arr[i+1]==0)
			{
				test0=1;
				break;
			}
			sig[i]='/';
			if(sig[i-1]=='-')
			temp[i+1]=temp[i-1]-arr[i]/arr[i+1];
		    else if(sig[i-1]=='+')
	    	temp[i+1]=temp[i-1]+arr[i]/arr[i+1];
			else
			temp[i+1]=temp[i]/arr[i+1];
		}
	}
	if(sign[2]+sign[3]==7&&sign[1]==1)     //����1+2*3/4��ʽ���ڸú����޷����㣬�������Ͳ�����һ���������1+(2+3*4)������ 
	{
		flag=1;
	}
	else if(sign[2]+sign[3]==7&&sign[1]==2)
	{
		flag=1;
	}
	else
	{
		test=temp[4];
		if(temp[4]==test&&temp[4]>=0&&test0==0&&sig[3]+sig[4]!=7)     //��test��Ϊ�������������ʽ�ӽ���Ƿ�Ϊ�Ǹ������������Ѷ�
		{                                      
	    	printf("%d. %.0f%c%.0f%c%.0f%c%.0f=",tihao++,arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
    		scanf("%d",&input);
	    	if(input<0)
	    	    end=1;
    		else
			{
    		    if(test==input)
				{
 	    			rig++;
	    			if(language==1)
					{
			    		printf("����ȷ��\n");
					}
		    		else
					{
				    	printf("Correct!\n");
					}
				}
    		    else
				{
			    	wro++;
				    if(language==1)
					{
					    printf("�𰸴�����ȷ����%d��\n",test);
					}
				    else
					{
					    printf("Wrong!The correct answer is %d.\n",test);
					}
				}
			}
		}
    	else
	    	flag=1;     //��flag����Ƿ��������Ŀ
	}
}





//��������������㺯�� 
void fraction()  
{
	srand((unsigned int)time(NULL)); //������������� 
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
	int mu1,zi1,mu2,zi2,com,sign,mu3,zi3,yue,input1=-8,input2=-8;    //mu�Ƿ�ĸ��zi�Ƿ��ӣ��벻���߶������� 
	for(;;)
	{
		mu1=rand()%10+1;		      //���ǵ���ĸ����Ϊ0������Ϊ0Ҳû̫������壬���Է��ӷ�ĸȡֵ��Χ��Ϊ1-10 
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
		printf("%d. (%d/%d)+(%d/%d)=",tihao++,zi1,mu1,zi2,mu2);
		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1+zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;          //����׼��Լ�ֳ������ʽ 
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
		    if(input1<0)
		       end=1;                      //�жϳ����Ƿ�Ӧ��ֹͣ�����½�ͬ 
			else
			{	
			    if(input1==(zi3/mu3))
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
			    else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d��\n",zi3/mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d.\n",zi3/mu3);
					}
				}
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
			    else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d/%d��\n",zi3,mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d/%d.\n",zi3,mu3);
					}
				}
		    }
		}
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
			printf("%d. (%d/%d)-(%d/%d)=",tihao++,zi1/(yue/mu1),mu1,zi2/(yue/mu2),mu2);
			if(zi3%mu3==0)
			{
			scanf("%d",&input1);
			if(input1<0)
			   end=1;
			else
			{
			   if(input1==(zi3/mu3))
			   {
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
			   }
			    else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d��\n",zi3/mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d.\n",zi3/mu3);
					}
				}
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
		    	else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d/%d��\n",zi3,mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d/%d.\n",zi3,mu3);
					}
				}
		    }
		   }
		}
	}
	if(sign==3)                                //�˷�
	{
		printf("%d. (%d/%d)*(%d/%d)=",tihao++,zi1,mu1,zi2,mu2);
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
		    	else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d��\n",zi3/mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d.\n",zi3/mu3);
					}
				}
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
    	    	else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d/%d��\n",zi3,mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d/%d.\n",zi3,mu3);
					}
				}
		    }
		}
	}
	if(sign==4)                             //����
	{
		printf("%d. (%d/%d)/(%d/%d)=",tihao++,zi1,mu1,zi2,mu2);
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
		    	else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d��\n",zi3/mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d.\n",zi3/mu3);
					}
				}
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
				{
					rig++;
					if(language==1)
					{
						printf("����ȷ��\n");
					}
					else
					{
						printf("Correct!\n");
					}
				}
    	    	else
				{
					wro++;
					if(language==1)
					{
						printf("�𰸴�����ȷ����%d/%d��\n",zi3,mu3);
					}
					else
					{
						printf("Wrong!The correct answer is %d/%d.\n",zi3,mu3);
					}
				}
		    }
		}
	}
}



//�����Լ������
int max(int a,int b)  
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



 //����С����������
int min(int a,int b)  
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
	void kuohao5(float arr[5],char sig[4]);              //������������ 
	int i,choose,symbol;
	float big,arr[5];
	char sig[4];
	for(i=1;i<=4;i++)
	{
		arr[i]=rand()%10+0;
	}
	arr[2]=rand()%10+1;       //������һ���ĳ����г���0 
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
	if(test==temp&&test>=0&&test0==0)
	{
		printf("%d. (%.0f%c%.0f)%c%.0f%c%.0f=",tihao++,arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
			{
				rig++;
				if(language==1)
				{
					printf("����ȷ��\n");
				}
				else
				{
					printf("Correct!\n");
				}
			}
		    else
			{
				wro++;
				if(language==1)
				{
					printf("�𰸴�����ȷ����%d��\n",test);
				}
				else
				{
					printf("Wrong!The correct answer is %d.\n",test);
				}
			}
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
	if(test==temp&&test>=0&&test0==0)
	{
		printf("%d. %.0f%c(%.0f%c%.0f)%c%.0f=",tihao++,arr[3],sig[2],arr[1],sig[1],arr[2],sig[3],arr[4]);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
			{
				rig++;
				if(language==1)
				{
					printf("����ȷ��\n");
				}
				else
				{
					printf("Correct!\n");
				}
			}
		    else
			{
				wro++;
				if(language==1)
				{
					printf("�𰸴�����ȷ����%d��\n",test);
				}
				else
				{
					printf("Wrong!The correct answer is %d.\n",test);
				}
			}
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
	if(test==temp&&test>=0&&test0==0)
	{
		printf("%d. %.0f%c%.0f%c(%.0f%c%.0f)=",tihao++,arr[3],sig[2],arr[4],sig[3],arr[1],sig[1],arr[2]);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
			{
				rig++;
				if(language==1)
				{
					printf("����ȷ��\n");
				}
				else
				{
					printf("Correct!\n");
				}
			}
		    else
			{
				wro++;
				if(language==1)
				{
					printf("�𰸴�����ȷ����%d��\n",test);
				}
				else
				{
					printf("Wrong!The correct answer is %d.\n",test);
				}
			}
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
		if(arr[4]==0)
			test0=1;
		else
		{
			temp=temp/arr[4];
			sig[1]='/';
		}
	}
	test=temp;
	if(test==temp&&test>=0&&test0==0)
	{
		printf("%d. (%.0f%c%.0f%c%.0f)%c%.0f=",tihao++,arr[1],sig[2],arr[2],sig[3],arr[3],sig[1],arr[4]);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
			if(test==input)
			{
				rig++;
				if(language==1)
				{
					printf("����ȷ��\n");
				}
				else
				{
					printf("Correct!\n");
				}
			}
		    else
			{
				wro++;
				if(language==1)
				{
					printf("�𰸴�����ȷ����%d��\n",test);
				}
				else
				{
					printf("Wrong!The correct answer is %d.\n",test);
				}
			}
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
	int test,input=-8,fuhao,tixing;
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
		if(temp==0)
		{
			test0=1;
		}
		else
		{
			temp=arr[1]/temp;
			sig[1]='/';
		}
	}
	test=temp;
	if(test==temp&&test>=0&&test0==0)
	{
		if(sig[2]+sig[3]==89)
		{
			tixing=rand()%2+1;
			if(tixing==1)
			    printf("%d. %.0f%c%.0f%c%.0f%c%.0f=",tihao++,arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);  //��0�����ź�����Ĺ���������
			else
			    printf("%d. %.0f%c(%.0f%c%.0f%c%.0f)=",tihao++,arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
		}
		printf("%d. %.0f%c(%.0f%c%.0f%c%.0f)=",tihao++,arr[1],sig[1],arr[2],sig[2],arr[3],sig[3],arr[4]);
		scanf("%d",&input);
		if(input<0)
		    end=1;
		else
		{
		    if(test==input)
			{
				rig++;
				if(language==1)
				{
					printf("����ȷ��\n");
				}
				else
				{
					printf("Correct!\n");
				}
			}
		    else
			{
				wro++;
				if(language==1)
				{
					printf("�𰸴�����ȷ����%d��\n",test);
				}
				else
				{
					printf("Wrong!The correct answer is %d.\n",test);
				}
			}
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
		if(a==0)
		{
			test0=1;
		}
		else
		{
			temp=big/a;
		    sig[2]='/';
		}
	}
	if(test0!=1)
	{
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
			if(b==0)
				test0=1;
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
	    }
	}
	    return(temp);
}


