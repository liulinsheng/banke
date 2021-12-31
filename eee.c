#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h> 
// #include <windows.h>
// #pragma comment(lib, "winmm.lib")

struct data{
	char id[20];
	char name[20];
};


struct data information[110];//普通人员信息
struct data information0[110];//滚动人员信息
struct data prize[110];//总获奖人员信息 
struct data winner1[110],winner2[110],winner3[110];//内幕人员信息 

int grade1=0,grade2=0,grade3=0;//内幕一等奖、二等奖、三等奖的人数 
int ms=60;//初始滚动时间间隔 
int count=0;//滚动人员总数
int people=0;//普通人员总数
int people1=0,people2=0,people3=0;//普通一等奖、二等奖、三等奖的人数 
char strid[20];

void Function_introduction();//功能介绍
void Print_menu();//打印菜单 
void Set_award();//设置奖项
void Read_information();//从文件中读取信息，放到普通人员信息中 
void Read_information0();//从文件中读取信息，放到滚动人员信息中 
void Roll_information0();//滚动信息，该信息是滚动人员的信息


void Set_speed();//设置滚动时间间隔
void Set_colour();//颜色设置
void Set_grade();//设置必中奖等级
void Set_winner1();//设置一等奖信息
void Set_winner2();//设置二等奖信息
void Set_winner3();//设置三等奖信息
void Set_awards();//设置奖项人数 

void Delet_function();//删除功能
void Delet_number();//按学号删除
void Delet_name();//按姓名删除
void Delet_information();//删除普通人员的信息
void Delet_information0();//删除内幕人员信息
void Add_function();//添加功能
void Begin_luck();//开始抽奖 
void Roll_speed(int ms);//滚动速度 
void Developer();//开发人员介绍

int main()
{

	Read_information();
	Read_information0();
	system("color 07");
	Print_menu();
	
	return 0;
}

void Function_introduction()//功能介绍
{
	system("cls");
	printf("\n\t\t\t抽奖小程序功能介绍\n");
	printf("\t\t\t1、设置中奖人员\n");
	printf("\t\t\t2、设置内幕人员\n");
	printf("\t\t\t3、添加功能\n");
	printf("\t\t\t4、删除功能\n");
	printf("\t\t\t5、颜色设置\n");
	printf("\t\t\t6、开发人员介绍\n");
	printf("\t\t\t按任意键返回");
	getch();

}

void Print_menu()//打印菜单 
{
	int choose;
	while(1)
	{
		system("cls"); 
		printf("\n\n");
		printf("\t*********************************************************\n");

		printf("\t*\t\t<-欢迎来到抽奖小程序->\t\t\t*\n");
		printf("\t*\t\t\t\t\t\t\t*\n");

		printf("\t*\t\t开始抽奖请按1\t\t\t\t*\n");
		printf("\t*\t\t设置奖项请按2\t\t\t\t*\n");
		printf("\t*\t\t滚动设置请按3\t\t\t\t*\n");
		printf("\t*\t\t颜色设置请按4\t\t\t\t*\n");
		printf("\t*\t\t添加功能请按5\t\t\t\t*\n");
		printf("\t*\t\t删除功能请按6\t\t\t\t*\n");
		printf("\t*\t\t人员介绍请按7\t\t\t\t*\n");
		printf("\t*\t\t功能介绍请按8\t\t\t\t*\n");
		printf("\t*\t\t结束程序请按0\t\t\t\t*\n");
		printf("\t*\t\t\t\t\t\t\t*\n");
		printf("\t*********************************************************\n");

		printf("\n\n\t\t\t请输入选项:");
		scanf("%d",&choose);

		switch(choose)
		{
			case 0:
				return;
			case 1:
				Begin_luck();//开始抽奖
				break;
			case 2:
				Set_award();//设置奖项
				break;
			case 3:
				Set_speed();//设置滚动时间间隔
				break;
			case 4:
				Set_colour();//颜色设置
				break;
			case 5:
				Add_function();//添加功能
		 		break; 
			case 6:
				Delet_function();//删除功能
				break;
			case 7:
				Developer();//开发人员介绍
				break;
			case 8:
				Function_introduction();//功能介绍
				break;
		} 	
	}
}

void Set_award()//设置奖项
{
	int choose;
	while(1)
	{
		system("cls"); 
		printf("\n\n");
		printf("\t*********************************************************\n");
		printf("\t*\t\t\t\t\t\t\t*\n");
		printf("\t*\t\t设置奖项人数请按1\t\t\t*\n");
		printf("\t*\t\t设置内幕人员请按2\t\t\t*\n");
		printf("\t*\t\t返回上一层请按0\t\t\t\t*\n");
		printf("\t*\t\t\t\t\t\t\t*\n");
		printf("\t*********************************************************\n");

		printf("\n\n\t\t\t请输入选项:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				return;
			case 1:
				Set_awards();//设置奖项人数
				
				break;
			case 2:
				Set_grade();//设置内幕人员
				break;
		} 
	}
}

void Set_colour()//颜色设置
{
	char choose[20];
	int i;
	system("cls");
	printf("\n\n\t0 = 黑色       8 = 灰色\n");
	printf("\t1 = 蓝色       9 = 淡蓝色\n");
	printf("\t2 = 绿色       A = 淡绿色\n");
	printf("\t3 = 浅绿色     B = 淡浅绿色\n");
	printf("\t4 = 红色       C = 淡红色\n");
	printf("\t5 = 紫色       D = 淡紫色\n");
	printf("\t6 = 黄色       E = 淡黄色\n");
	printf("\t7 = 白色       F = 亮白色\n\n");
	printf("\t请输入字体颜色对应的代码：");
	scanf("%s",choose);
	if(strcmp(choose,"0")==0)
		system("color 00");
	else if(strcmp(choose,"1")==0)
		system("color 01");
	else if(strcmp(choose,"2")==0)
		system("color 02");
	else if(strcmp(choose,"3")==0)
		system("color 03");
	else if(strcmp(choose,"4")==0)
		system("color 04");
	else if(strcmp(choose,"5")==0)
		system("color 05");
	else if(strcmp(choose,"6")==0)
		system("color 06");
	else if(strcmp(choose,"7")==0)
		system("color 07");
	else if(strcmp(choose,"8")==0)
		system("color 08");
	else if(strcmp(choose,"9")==0)
		system("color 09");
	else if(strcmp(choose,"A")==0)
		system("color 0A");
	else if(strcmp(choose,"B")==0)
		system("color 0B");
	else if(strcmp(choose,"C")==0)
		system("color 0C");
	else if(strcmp(choose,"D")==0)
		system("color 0D");
	else if(strcmp(choose,"E")==0)
		system("color 0E");
	else if(strcmp(choose,"F")==0)
		system("color 0F");
	else
	{
		printf("输入错误按任意键返回上一层\n");
		getch();
		return;
	}
	printf("\t设置完毕按任意键返回");
	getch();
	
}

void Delet_function()//删除功能
{
	int choose;
	while(1)
	{
		system("cls"); 
		printf("\n\n");
		printf("\t*********************************************************\n");
		printf("\t*\t\t\t\t\t\t\t*\n");
		printf("\t*\t\t按姓名删除请按1\t\t\t\t*\n");
		printf("\t*\t\t按学号删除请按2\t\t\t\t*\n");
		printf("\t*\t\t返回上一层请按0\t\t\t\t*\n");
		printf("\t*\t\t\t\t\t\t\t*\n");
		printf("\t*********************************************************\n");

		printf("\n\n\t\t\t请输入选项:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				return;
			case 1:
				Delet_name();//按姓名删除
				break;
			case 2:
				Delet_number();//按学号删除
				break;
		} 
	}
}

void Read_information()//从文件中读取信息
{
	FILE *fp=fopen("17计科2.txt","r");
	while(!feof(fp))
	{
		//存储该信息到普通人员信息中，便于设置内幕人员
		fscanf(fp,"%s%s",information[people].id,information[people].name);
		people++;
	} 
	fclose(fp);
}

void Read_information0()//读取滚动人员的信息
{
	FILE *fp=fopen("17计科2.txt","r");
	while(!feof(fp))
	{
		//存储信息到滚动人员信息中，用于滚动时打印在显示屏幕中											     	
		fscanf(fp,"%s%s",information0[count].id,information0[count].name);
		count++;
	} 
	fclose(fp);
}

void Roll_information0()//滚动信息，该信息是滚动人员的信息
{
	int i=0;
	system("cls");
	printf("按任意键开始抽奖,按任意键停止抽奖\n");
	getch(); 
	// PlaySound (TEXT("C:中国人民解放军军乐团-国际歌.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
	while(1)
	{
		system("cls");
		if(kbhit()!=0)
			break;
		i=rand()%count;
		printf("%s",information0[i].name);//显示滚动信息
		//i++;
		//if(i==count)
			//i=0;
		Roll_speed(ms);
	} 
	// PlaySound (0, NULL, SND_ASYNC | SND_NODEFAULT);
}

void Begin_luck()//开始抽奖
{
	int i,j,choose,t;
	system("cls");
	if(grade3==0&&grade2==0&&grade3==0&&people1==0&&people2==0&&people3==0)
	{
		
		printf("请先设置奖项人数按任意键返回\n");
		getch();
		return;
	}
	printf("下面开始抽取三等奖人员,按任意键继续\n"); 
	getch();
	j=0;//代表各奖项人员的总数包括内幕人员
	while(grade3--)//内幕三等奖人员
	{
		if(grade3<0)
			break;
		Roll_information0();
		printf("%s",winner3[grade3].name);
		prize[j++]=winner3[grade3];
		strcpy(strid,winner3[grade3].id);
		Delet_information0();//删除该成员在滚动信息中的信息
		getch();
		getch();
	}
	while(people3--)//普通三等奖人员
	{
		if(people3<0)
			break;
		Roll_information0();
		srand((unsigned)time(0));
		t=rand()%people;
		printf("%s",information[t].name);
		prize[j++]=information[t];

		strcpy(strid,information[t].id);
		Delet_information();//删除该成员在普通信息中的信息
		Delet_information0();//删除该成员在滚动信息中的信息
		//printf("\n\n\n");
		//for(i=0;i<count;i++)
			//printf("%s ",information0[i].name);
		getch();
		getch();
	}
	system("cls");
	printf("以下是三等奖名单,按任意键继续\n");
	for(i=0;i<j;i++)
		printf("%s\n",prize[i].name);
	getch();
	

	system("cls");	
	printf("下面开始抽取二等奖人员,按任意键继续\n"); 
	getch();
	j=0;
	while(grade2--)
	{
		if(grade2<0)
			break;
		Roll_information0();//显示滚动人员信息
		printf("%s",winner2[grade2].name);
		prize[j++]=winner2[grade2];
		strcpy(strid,winner2[grade2].id);
		Delet_information0();//删除该成员在滚动信息中的信息
		getch();
		getch();
	}

	while(people2--)
	{
		if(people2<0)
			break;
		Roll_information0();
		srand((unsigned)time(0));
		t=rand()%people;
		printf("%s",information[t].name);
		prize[j++]=information[t];
		strcpy(strid,information[t].id);
		Delet_information();//删除该成员在普通信息中的信息
		Delet_information0();//删除该成员在滚动信息中的信息
		getch();
		getch();
	}
	system("cls");
	printf("以下是二等奖名单,按任意键继续\n");
	for(i=0;i<j;i++)
		printf("%s\n",prize[i].name); 
	getch();
		
	system("cls");
	printf("下面开始抽取一等奖人员,按任意键继续\n"); 
	getch();
	j=0;
	while(grade1--)//内幕一等奖人员
	{
		if(grade1<0)
			break;
		Roll_information0();
		printf("%s",winner1[grade1].name);
		prize[j++]=winner1[grade1];
		strcpy(strid,winner1[grade1].id);
		Delet_information0();//删除该成员在滚动信息中的信息
		getch();
		getch();
	}
	while(people1--)
	{
		if(people1<0)
			break;
		Roll_information0();
		srand((unsigned)time(0));
		t=rand()%people;
		printf("%s",information[t].name);
		prize[j++]=information[t];
		
		strcpy(strid,information[t].id);
		Delet_information();//删除该成员在普通信息中的信息
		Delet_information0();//删除该成员在滚动信息中的信息
		getch();
		getch();
	}
	system("cls");
	printf("以下是一等奖名单,按任意键继续\n");
	for(i=0;i<j;i++)
		printf("%s\n",prize[i].name);
	
	printf("抽奖完毕按任意键返回\n");
	getch();
} 


void Set_speed()//滚动速度 
{
	char choose[20];
	int i,t=0;
	system("cls");
	printf("请输入滚动时间间隔\n"); 
	scanf("%s",choose);
	for(i=0;choose[i]!='\0';i++)
		if(choose[i]<'0'||choose[i]>'9')
		{
			printf("输入有误按任意键返回");
			getch();
			return;
		}
		else
			t=10*t+choose[i]-'0';
	ms=t;	
	printf("设置完毕按任意键返回\n");
	getch();
} 

void Roll_speed(int ms)
{
	clock_t t1,t2;
	t1=clock();
	while(1)
	{
		t2=clock();
		if(t2-t1>=ms)
			return;
	}
} 

void Set_awards()//设置奖项人数
{
	int choose,t;
	while(1)
	{
		system("cls");
		printf("请输入三等奖人数(正整数)：\n");
		scanf("%d",&t);
		if(t<0||t>count)
		{
			printf("输入不合法，请输入1到%d之内的数字",count);
			getch();
		}
		else
		{
			people3+=t;
			break;
		}
		
	}		
	while(1)
	{
		system("cls");
			printf("请输入二等奖人数：\n");
			scanf("%d",&t);
			if(t<1||t>count)
			{
				printf("输入不合法，请输入1到%d之内的数字",count);
				getch();
				
			}
			else
			{
				people2+=t;
				break;
			}
			
			
	}
	while(1)
	{
		system("cls");
		printf("请输入一等奖人数：\n"); 
		scanf("%d",&t); 
		if(t<0||t>count)
		{
			printf("输入不合法，请输入1到%d之内的数字",count);
			getch();
		}
		else
		{
			people1+=t;
			break;
		}
	}
	printf("设置完毕按任意键返回\n");
	getch();
	return;
} 

void Set_grade()//设置内幕中奖等级
{
	char grade[20];
		system("cls");
		printf("请输入中奖等级,返回上一层请按0\n");
		scanf("%s",grade);
		if(strcmp(grade,"0")==0)
			return;
			
		else if(strcmp(grade,"1")==0)
			Set_winner1();
		else if(strcmp(grade,"2")==0)
			Set_winner2();
		else if(strcmp(grade,"3")==0)
			Set_winner3();
		else
		{
			printf("请输入1到3等级按任意键返回\n");
			getch();
			return;
		}
}

void Set_winner1()//设置内幕一等奖信息
{
	int i,j;
	system("cls");
	printf("请输入必中奖人员学号和姓名：\n");
	scanf("%s%s",winner1[grade1].id,winner1[grade1].name);
	for(i=0;i<count;i++)
		if(strcmp(winner1[grade1].id,information0[i].id)==0)
			break;
	for(j=0;j<count;j++)
		if(strcmp(winner1[grade1].name,information0[i].name)==0)
			break;
	if(i==count||j==count)
	{
		printf("抽奖名单中无此信息按任意键返回");
		getch();
		return;
		
	}
	printf("设置成功按任意键继续");
	getch();
	strcpy(strid,winner1[grade1].id);
	Delet_information();//普通总成员减1
	grade1++;//内幕一等奖成员加1
	people1--;//普通一等奖成员减1
	return;
}

void Set_winner2()//设置内幕二等奖信息
{
	int i,j;
	system("cls");
	printf("请输入必中奖人员学号和姓名：\n");
	scanf("%s%s",winner2[grade2].id,winner2[grade2].name);
	for(i=0;i<count;i++)
		if(strcmp(winner2[grade2].id,information0[i].id)==0)
			break;
	for(j=0;j<count;j++)
		if(strcmp(winner2[grade2].name,information0[i].name)==0)
			break;
	if(i==count||j==count)
	{
		printf("抽奖名单中无此信息按任意键返回");
		getch();
		return;
	}
	printf("设置成功按任意键继续");
	getch();
	strcpy(strid,winner2[grade2].id);
	Delet_information();//普通总人员减1
	grade2++;//内幕二等奖人员加1
	people2--;//普通二等奖人员减1
	return;
}

void Set_winner3()//设置内幕三等奖信息
{
	int i,j;
	system("cls");
	printf("请输入必中奖人员学号和姓名：\n");
	scanf("%s%s",winner3[grade3].id,winner3[grade3].name);
	for(i=0;i<count;i++)
		if(strcmp(winner3[grade3].id,information0[i].id)==0)
			break;
	for(j=0;j<count;j++)
		if(strcmp(winner3[grade3].name,information0[i].name)==0)
			break;
	if(i==count||j==count)
	{
		printf("抽奖名单中无此信息按任意键返回");
		getch();
		return;
	}
	printf("设置成功按任意键继续");
	getch();
	strcpy(strid,winner3[grade3].id);
	Delet_information();//普通总人员减1
	grade3++;//内幕三等奖人员加1
	people3--;//普通三等奖人员减1
	return;
}

void Delet_number()//按学号删除
{
	int i;
	system("cls");
	while(1)
	{

		printf("请输入要删除人的学号\n");
		scanf("%s",strid);
		for(i=0;i<count;i++)
			if(strcmp(strid,information[i].id)==0)
				break;
		if(i==count)
		{
			printf("未找到该学号，请重新输入\n");
			getch();
			return;
		}
		else
			break;
	}
	Delet_information();
	Delet_information0();
	printf("删除成功按任意键返回上一层\n");
	getch();
}

void Delet_name()//按姓名删除
{
	int i;
	
	while(1)
	{
		system("cls");
		printf("请输入要删除人的姓名\n");
		scanf("%s",&strid);
		for(i=0;i<count;i++)
			if(strcmp(strid,information0[i].name)==0)
			{
				strcpy(strid,information0[i].id);
				break;
			}
		if(i==count)
		{
			printf("未找到该人员按任意键返回上一层\n");
			getch();
			return;
		}
		else
			break;
	}
	
	Delet_information();
	Delet_information0();
	printf("删除成功按任意键返回上一层\n");
	getch();
}

void Delet_information()//删除该学号人员在普通人员中的信息
{
	int i,j;
	for(i=0;i<people;i++)
		if(strcmp(information[i].id,strid)==0)
		{
			people--;
			for(j=i;j<people;j++)
				information[j]=information[j+1];
			return;
		}
}

void Delet_information0()//删除该成员在滚动信息中的信息
{
	int i,j;
	//printf("\n\n*********%s\n\n",strid);
	for(i=0;i<count;i++)
		if(strcmp(information0[i].id,strid)==0)
		{
			count--;
			//printf("\n\n*********%s\n\n",information0[i].name);
			for(j=i;j<count;j++)
				information0[j]=information0[j+1];
			return;
		}
}
void Add_function()//添加功能
{
	int i;
	system("cls");
	char id[20],name[20];
	printf("请输入添加人员的学号和姓名\n");
	scanf("%s%s",&id,&name);
	for(i=0;i<count;i++)
		if(strcmp(information0[i].id,id)==0)
		{
			printf("该学号已存在按任意键返回");
			getch();
			return;
		}		
	for(i=0;i<count;i++)
		if(strcmp(information0[i].name,name)==0)
		{
			printf("该姓名已存在按任意键返回");
			getch();
			return;
		}	
	strcpy(information0[count].id,id);
	strcpy(information0[count].name,name);
	information[people]=information0[count];
	count++;
	people++;
	printf("添加成功，按任意键返回");
	getch();
}

void Developer()
{

	system("cls");
	printf("\n\n\t\t\t组长：公众号【贺贺学编程】");
	printf("\n\n\t\t\t组员：贺志营");
	printf("\n\n\t\t\t组员：贺贺");
	printf("\n\n\t\t      按任意键返回上一层");
	getch();

}



