//To install mysql header files -> apt-get install libmysqlclient-dev
//To run embedded sql in c -> gcc test1.c `mysql_config --cflags --libs`
	      
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   unsigned long *lengths;
   unsigned int num_fields;


   char *server = "localhost"; // localhost for accessing local mysql
   char *user = "root";// root for students
   char *password = "123"; /* set me first - pwd : iiitdm123 */ 
   char *database = "EU"; // Here you need to enter the database name if you have already other wise leave it free.
 
   int i; 

void ShowTables()
{
	if (mysql_query(conn,"show tables")) 
       {
         fprintf(stderr, "%s\n", mysql_error(conn));
         exit(1);
       }
       res = mysql_use_result(conn);
  int j=1;
  while ((row = mysql_fetch_row(res)) != NULL)
  {
       num_fields = mysql_num_fields(res);
      lengths = mysql_fetch_lengths(res);
      for(i = 0; i < num_fields; i++)
         printf("%d--%12.*s|",j++, (int) lengths[i],row[i] ? row[i] : "NULL");
      printf("\n");
  }
  mysql_free_result(res);
}
void ShowSpecificTables(char table_name[])
{
  char Query[100]="select *from ";
  strcat(Query,table_name);
  if (mysql_query(conn,Query)) 
       {
         fprintf(stderr, "%s\n", mysql_error(conn));
         exit(1);
       }
       res = mysql_use_result(conn);
  while ((row = mysql_fetch_row(res)) != NULL)
  {
       num_fields = mysql_num_fields(res);
      lengths = mysql_fetch_lengths(res);
      for(i = 0; i < num_fields; i++)
         printf("%12.*s--", (int) lengths[i],row[i] ? row[i] : "NULL");
      printf("\n");
  }
  mysql_free_result(res);
}
void Insert()
{
	ShowTables();
	printf("\nEnter the table into which values have to be entered:");
    int val;
	scanf("%d",&val);
    printf("\n\n");
	int flag=1;
	
	char salary[100];
	char ID[100],name[200],dept_name[200]; 

	char building[200],room_number[200],capacity[200];

	char tot_cred[200];
	
	char budget[200];

	char course_id[200],title[400];
	char credits[200];

  char Query[500];

	while(flag)
	{
		switch(val)
		{
			case 2:
              printf("\nEnter building,room_number,capacity:");
               scanf("%s %s %s",building,room_number,capacity);
               char Query2[500]="insert into classroom values (";
               strcat(Query2,strcat(building,strcat(room_number,strcat(capacity,")"))));
               printf("%s",Query2);
               if (mysql_query(conn, Query2))
                 fprintf(stderr, "%s\n", mysql_error(conn));
               printf("\n");
              break;			      	
      case 3:
    		   printf("\nEnter course_id,title,dept_name,credits:");
               scanf("%s %s %s %s",course_id,title,dept_name,credits);
               char Query3[500]="insert into course values (";
               strcat(Query3,strcat(course_id,strcat(title,strcat(dept_name,strcat(credits,")")))));
               printf("%s",Query3);
               if (mysql_query(conn, Query3))
                 fprintf(stderr, "%s\n", mysql_error(conn));
               printf("\n");
               break;              
    	case 4:
	    	   printf("\nEnter dept_name,building,budget:");
               scanf("%s %s %s",dept_name,building,budget);
               char Query5[500]="insert into department values (";
               strcat(Query5,strcat(dept_name,strcat(building,strcat(budget,")"))));
               printf("%s",Query5);
               if (mysql_query(conn, Query5 ))
                 fprintf(stderr, "%s\n", mysql_error(conn));
               printf("\n"); 
               break;
    	case 5:
              printf("\nEnter ID,name,dept_name,salary:");
              scanf("%s %s %s %s",ID, name, dept_name, salary);
              char Query1[500]="insert into instructor values (";
              strcat(Query1,strcat(ID,strcat(name,strcat(dept_name,strcat(salary,")")))));
              printf("%s",Query1);
                if (mysql_query(conn, Query1))
                 fprintf(stderr, "%s\n", mysql_error(conn));
              printf("\n");
              break; 
      case 7:
              printf("\nEnter ID,name,dept_name,tot_cred:");
               scanf("%s %s %s %s",ID,name,dept_name,tot_cred);
               char Query4[500]="insert into student values (";
               strcat(Query4,strcat(ID,strcat(name,strcat(dept_name,strcat(tot_cred,")")))));
               printf("%s",Query4);
               if (mysql_query(conn, Query4))
                 fprintf(stderr, "%s\n", mysql_error(conn));
               printf("\n"); 
               break;    

     default:printf("\nEnter a valid table\n");                  
    }
      
      printf("\nDo you want to Enter next set of values\nIf Yes (enter 1)");
    	int x;
    	scanf("%d",&x);
    	if (x!=1)
    		flag=0;
	
   }
}
void DescribeTable(char Table_Name[])
{
	char Q[30]="desc ";	   			
     if (mysql_query(conn,strcat(Q,Table_Name))) 
               {
                 fprintf(stderr, "%s\n", mysql_error(conn));
                  exit(1);
               }
               res = mysql_use_result(conn);
              while ((row = mysql_fetch_row(res)) != NULL)
               {
                  num_fields = mysql_num_fields(res);
                 lengths = mysql_fetch_lengths(res);
                  for(i = 0; i < num_fields; i++)
                    printf("%12.*s|", (int) lengths[i],row[i] ? row[i] : "NULL");
                 printf("\n");
               }
              mysql_free_result(res);
}
void DeleteRecord()
{

	char  Attribute[20], New_Value[20],Table_Name[20];;
	ShowTables();
    printf("\nEnter the name of the table: ");
    scanf(" %s",Table_Name);
    char Query[80]="delete from ";
    strcat(Query,Table_Name);
    strcat(Query," where ");
    DescribeTable(Table_Name);
    printf("\nEnter the number of conditions:");
    int cond;
    scanf("%d",&cond);
    while(cond--)
    {
     printf("\nEnter the attribute name:");
     scanf("%s",Attribute);
     strcat(Query,Attribute);
     strcat(Query,"=");
     printf("\nEnter the it's value:");
     scanf("%s",New_Value);
     strcat(Query,New_Value);
     if(cond>=1)
     strcat(Query," and ");
     else
     strcat(Query,";");
    }
	 if (mysql_query(conn, Query))
             fprintf(stderr, "%s\n", mysql_error(conn));
           printf("\n");
          ShowSpecificTables(Table_Name);
}
void UpdateRecord()
{

	char Attribute[20], New_Value[20],Table_Name[20];;
	ShowTables();
    printf("\nEnter the name of the table: ");
    scanf(" %s",Table_Name);
    char Query[80]="update ";
    strcat(Query,Table_Name);
    strcat(Query," set ");
    DescribeTable(Table_Name);
    printf("\nEnter the number of attributes you want to update:");
    int nou;
    scanf("%d",&nou);
    while(nou--)
    {
     printf("\nEnter the attribute name:");
     scanf(" %s",Attribute);
     strcat(Query,Attribute);
     strcat(Query,"=");
     printf("\nEnter it's new value:");
     scanf(" %19[^\n]",New_Value);
     strcat(Query,New_Value);
     if(nou>=1)
     strcat(Query,",");
     else
     strcat(Query," where ");
    }
	 
	printf("\nEnter the number of conditions:");
    int cond;
    scanf("%d",&cond);
    while(cond--)
    {
     printf("\nEnter the attribute name:");
     scanf("%s",Attribute);
     strcat(Query,Attribute);
     strcat(Query,"=");
     printf("\nEnter it's value:");
     scanf(" %19[^\n]",New_Value);
     strcat(Query,New_Value);
     if(cond>=1)
     strcat(Query," and ");
    }
    printf("%s",Query);
    if (mysql_query(conn, Query))
             fprintf(stderr, "%s\n", mysql_error(conn));
           printf("\n");
          ShowSpecificTables(Table_Name);
}
void Greaterthan()
{
	char statement[512], *my_str = "MyString";
	printf("\nEnter the value:");
         int v;
         scanf("%d",&v);                 
         snprintf(statement, 512, "select *from instructor where salary>%d",v);
         if (mysql_query(conn, statement))
           fprintf(stderr, "%s\n", mysql_error(conn));
            printf("\n");
             res=mysql_use_result(conn);
         int i=0;
     	 while ((row = mysql_fetch_row(res)) != NULL)
      	 {
          num_fields = mysql_num_fields(res);
          lengths = mysql_fetch_lengths(res);
          for(i = 0; i < num_fields; i++)
             printf("%-15.*s|", (int) lengths[i],row[i] ? row[i] : "NULL");
          printf("\n");
      	 }
         if (i==0)
         {
          printf("Empty Set..\n");
         }
          mysql_free_result(res);
}
void PreCourse()
{
	printf("\nEnter the course for which you want to find the prerequisite courses:");
    char courseN[100];
    scanf(" %99[^\n]",courseN);
    char statement[512], *my_str = "MyString";
    snprintf(statement, 512, "select B.title from course as B where B.course_id In(select A.prereq_id from prereq as A,course as C where C.title ='%s' and C.course_id=A.course_id)",courseN);
    if (mysql_query(conn, statement))
          fprintf(stderr, "%s\n", mysql_error(conn));
        printf("\n");
        res=mysql_use_result(conn);
    
  int j=1;
  while ((row = mysql_fetch_row(res)) != NULL)
   {
     num_fields = mysql_num_fields(res);
     lengths = mysql_fetch_lengths(res);
     for(i = 0; i < num_fields; i++)
        printf("%d---%-15.*s|", j++,(int) lengths[i],row[i] ? row[i] : "NULL");
     printf("\n");
   }
    if (i==0)
    {
     printf("Empty Set..\n");
    }
    mysql_free_result(res);
}

void No_of_Students()
{
	printf("\nEnter the instructor for which you want to find the number of students:");
    char instructor[100];
    scanf("%s",instructor);
    char statement[512], *my_str = "MyString";
    snprintf(statement, 512,"select Count(*) as Count from advisor where i_ID in(select A.ID from instructor as A where A.name='%s')",instructor);
    if (mysql_query(conn, statement))
          fprintf(stderr, "%s\n", mysql_error(conn));
        printf("\n");
        res=mysql_use_result(conn);
    
  while ((row = mysql_fetch_row(res)) != NULL)
   {
     num_fields = mysql_num_fields(res);
     lengths = mysql_fetch_lengths(res);
     for(i = 0; i < num_fields; i++)
        printf("%-15.*s|",(int) lengths[i],row[i] ? row[i] : "NULL");
     printf("\n");
   }
    if (i==0)
    {
     printf("Empty Set..\n");
    }
    mysql_free_result(res);
}

void main(int argc, char const *argv[])
{
	conn = mysql_init(NULL);
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

    char  Attribute[20], r_Table_Name[20], New_Value[20];
    char Table_Name[20];
	int option;
	int opt;
	char Query[1000];
    while(1)
    {
	   printf("\n1.Insert new records into tables\n2.Find the prerequisite courses\n3.Find instructors whose salary > x\n");
	   printf("4.Update records\n5.Delete a record\n6.Count no of students under an Instructor\n7.Exit\n");
	   printf("\n\t-------->Enter the option you want to perform:<----------\n");
	   scanf("%d",&opt);
	   printf("\n");	   
	   switch(opt)
	   {
	   		case 1://Insert into Tables
                    Insert();
	   			    break;	
	   		case 2://Enter the course to find their prerequisite courses Function2  
                    PreCourse();   
                    break;		
	   		case 3://Find all those instructors whose salary is greator than x Function1
                    Greaterthan();
                    break;		   
	   	    case 4://Update Table
	   			    UpdateRecord();
	   			    break;
	   		case 5://Delete a record
	   		        DeleteRecord();
                    break;			   			
	   		case 6://Count the number of students
                    No_of_Students();
                    break;
	   		case 7: //To Exit
	   			    exit(1);
	   			    break;

	     
	   		default://Enter a right option
	   			    printf("\nEnter a valid option:\n");
	   			    printf("\n\n");
	   }	
	}
   mysql_close(conn);
}

