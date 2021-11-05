#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
struct liquid
{
	char name[10]; //出入量类型  name0=尿  name1=水  name2=药   name3=其他入量  
	char day[10]; //上午  中午  下午  晚上 
        int total_intake_and_output_num;  //出入量总量

}
liquid[30];
void input()
{
	FILE  *fp; //创建文件指针，根据指针返回值来确定是否完成文件操作过程 
	int i;
	if((fp=fopen("num.txt","w"))==NULL)   //通过fopen创建文件num.txt 文件，如果返回值为0，说明文件创建失败。 
   	{
      		printf("cannot open the file\n");
      		return;
   	}
	int input_number=10;
	printf("输入要记录的个数(0-%d):",input_number);
	scanf("%d",&N);
 	for(i=0;i<N;i++)
	{
		printf("出入量类型:");
		scanf("%s",liquid[i].name);
		printf("时间:");
		scanf("%s",liquid[i].day);
		printf("出入量总量:");
		scanf("%d",&liquid[i].total_intake_and_output_num);
	}
	for(i=0;i<N;i++)
	{
		if(fwrite(&liquid[i],sizeof(struct liquid),1,fp)!=1)
		{	
           		printf("file write error\n");
           		return;
           	}
           }
           fclose(fp);
        }
void read_form_file()
{
	int i;
	FILE *fp;
	if((fp=fopen("num.txt","rb"))==NULL)
    	{
      		printf("cannot open the file\n");

       		return;
    	}
	for(i=0;i<N;i++)
	{
		fread(&liquid[i],sizeof(struct liquid),1,fp);
    		fclose(fp);
	}
}

void  display_all() 
{ 
	int i; 
    	read_form_file(); 
 	printf("全部信息：\n"); 
 	for(i=0;i<N;i++) 
 	{	 
 		printf("出入量类型:%s  时间:%s 出入量总量:%d ", liquid[i].name, liquid[i].day, liquid[i].total_intake_and_output_num);  
     		printf("\n"); 
 } 
}



int main(void)
{
	input();
	display_all();
}

