#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>



//function declarations for various opreations.


void Update_table(char table_name[], char attribute[], char new_value[], int opt);
int startQuery(char Query[]);
void Insert_table(int opt);
void Create_table();
int display_Tables(int option);
void ShowTables(char table_name[]);
void Greaterthan();
void economy(char small[]);
void employee();
void halts(int i, char source[], char dest[]);
void Delete();
void CruisingEmployee();










MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   unsigned long *lengths;
   unsigned int num_fields;


   char *server = "localhost"; // localhost for accessing local mysql
   char *user = "root";// root for students
   char *password = "dash@1508"; /* set me first - pwd : iiitdm123 */ 
   char *database = "E_F"; // Here you need to enter the database name if you have already other wise leave it free.





void main(int argc, char const *argv[])
{
	conn = mysql_init(NULL);
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

    char  attribute[20], r_table_name[20], r_attribute[20];
    char table_name[20];
	int option;
	int opt;
	char Query[1000];
	printf("\t\t\t\t\t\n\nWELCOME TO DATABASE 'E_F' ");
	int y;
    do
    {
	   printf("\n1.table creation\n\t2.describe tables\n\t\t3.show tables\n\t\t\t4.Insertion of  values into tables\n\t\t\t\t5.Updatation of a table\n\t\t\t\t\t6.Enter a Query\n\t\t\t\t\t\t7.find aircrafts wrt cruisingrange\n\t\t\t\t\t8.economy(Sort wrt cheapest price)\n\t\t\t\t9.find Employees wrt salary\n\t\t\t10.delete record\n\t\t11.find your flights wrt halts\n\t12.find employees wrt cruising range\n13.find Journey duration for available flights \n14.EXIT");
	   scanf("%d",&opt);
	   
	   switch(opt)
	   {
	   		case 1:
	   		    printf("\nYou have entered table creation\n");
	   			Create_table();





	   			


	   			break;




	   		case 2:
	   		    
	   		    printf("describe tables \n");
	   		    printf("1.Flights \n");
	   		    printf("2.Aircrafts \n");
	   		    printf("3.Certified \n");
	   		    printf("4.Employees \n");

	   		    printf("enter your choice\n");
	   		    int y;
	   		    scanf("%d",&y);


	   		    display_Tables(y);

	   		    break;




                   
	   		case 3:

	   		    printf("show tables \n");
	   		    printf("1.Flights \n");
	   		    printf("2.Aircrafts \n");
	   		    printf("3.Certified \n");
	   		    printf("4.Employees \n");

	   		    printf("enter your choice\n");
	   		    char s[15];
	   		    scanf("%s",s);
	   		    


	   		   ShowTables(s);
	   		   break;




	   		case 4:

	   		    printf("\nYou have entered insertion of values into the tables\n");
	   			printf("Enter the table into which values have to be entered\n1.Flights\n2.Aircrafts\n3.Certified\n4.Employees");
	   			scanf("%d",&option); 
	   			Insert_table(option);
	   			printf("\n\n");
	   			break;




	   		case 5:
	   		    printf("\nYou have entered updation of the tables\n");
	   			printf("Enter the name of the table: ");
	   			scanf(" %s",table_name);
	   			printf("Enter the name of the primary attribute: ");
	   			scanf(" %s",attribute);
	   			printf("Enter new value for %s (with double quotes if required): ", attribute);
	   			scanf(" %s",r_attribute);
	   			printf("Enter no of conditions : ");
	   			scanf("%d",&option);
	   			Update_table(table_name, attribute, r_attribute, option);   //for and or cases
	   			printf("\n\n");
	   			break;



	   		case 6:
	   		    printf("\nYou have entered Quering\n");
	   			printf("Enter the Query\nmysql> ");
	   			scanf(" %999[^\n]",Query);
	   			startQuery(Query);
	   			printf("\n\n");
	   			break;



	   		case 7:
	   		        Greaterthan();
                    break;		   

	   		case 8: 
	   		    printf("Enter the number of consraints: ");
	   	        int z;
	   			scanf("%d",&z);
	   			char small[100]="";
	   			char mul[100];
	   			while(z--)
	   			{
	   				printf("Enter the constraints:");
	   				scanf(" %s",mul);
	   				if (z>0)
	   				{
	   					strcat(mul,",");
	   				}
	   				strcat(small,mul);
	   			}
	   			economy(small);
	   			break;	
	   		    


	   	    case 9:
	   	       employee();
                    break;		

	   		case 10:
	   	        Delete();
	   			break;

	   		case 11:
	   	        
	   	        
	   			printf("Enter source: ");
	   			char so[10],de[10];
		   		scanf(" %19[^\n]",so);
		   		printf("Enter the destination: ");
		   		scanf(" %19[^\n]",de);

		   		printf("Choose the no of halts desired by you: ");
		   		int choice;
		   		scanf("%d", &choice);
		   		while(choice--)
		   		{
	   				halts(choice+2,so,de);
	   			}
	   			break;


	   		case 12:

	   		    CruisingEmployee();
	   	       
	   			
	   			break;


	   		case 13:
                printf("the source and the destination of the available flights and their corresponding durations :\n");
	   		    startQuery("select source,destination ,abs(timediff(arrives,departs)) from Flights");

	   			
	   			break;	


            case 14:
	   	         printf("\nYou have entered Exits\n");
	   			exit(1);
	   			break;						


	   			
	   		default:
	   			printf("Enter a valid option:\n");
	   			printf("\n\n");
	   }
	   printf("do u wanna continue ?\n");
	   scanf("%d",&y);		
	}while(y==1);

   mysql_close(conn);
}








void Create_table()
{
	char Query[500];
	int opt;
	printf("Select the  table you want to create:\n");
	printf("1.Flights\n2.Aircrafts\n3.Certified\n4.Employees\n");
	   scanf("%d",&opt);
	   switch(opt)
	   {
	   		case 1:
	   			strcpy(Query,"create table Flights (flno int, source varchar(20), destination varchar(20), distance int, departs time, arrives time, price int)");
	   			break;
	   		case 2:
	   			strcpy(Query,"create table Aircrafts (aid int, aname varchar(20), cruisingrange int)");
	   			break;
	   		case 3:
	   			strcpy(Query,"create table Certified (eid int, aid int)");
	   			break;
	   		case 4:
	   			strcpy(Query,"create table Employees (eid int, ename varchar(20), salary int)");
	   			break;
	   		default:
	   			printf("Enter a valid option\n");
	   			break;

	   }
	   if (mysql_query(conn, Query)) 
	   {
       fprintf(stderr, "%s\n", mysql_error(conn));
       
   }	
}		



void Insert_table(int opt)
{
	int flag=1;
	char flno[100],price[100],distance[100],source[200],destination[200],departs[200],arrives[200]; 
	char aid[100],aname[200], cruisingrange[100];
	char eid[100];
	char ename[300], salary[100];
	while(flag)
	{
		printf("%d\n", opt);
		switch(opt)
		{


			//flight table
			case 1:
				printf("Enter flno, source, destination, distance, departs, arrives, price: \n");
                scanf("%s%s%s%s%s%s%s",flno, source, destination, distance, departs, arrives, price);
                char Query1[500]="insert into Flights values (";
                strcat(flno,",\"");
                strcat(Query1, flno);
                strcat(source,"\",\"");
                strcat(Query1, source);
                strcat(destination,"\",");
                strcat(Query1, destination);
                strcat(distance,",\"");
                strcat(Query1, distance);
                strcat(departs,"\",\"");
                strcat(Query1, departs);
                strcat(arrives,"\",");
                strcat(Query1, arrives);
                strcat(Query1, price);
                strcat(Query1,")");
    			if (mysql_query(conn, Query1))
    			{
    				fprintf(stderr, "%s\n", mysql_error(conn));
     				
    			}printf("\n\n");
    			break;



             //aircraft table
    		case 2:
    			printf("Enter aid, aname, cruisingrange\n");
	            scanf("%s%s%s",aid,aname,cruisingrange);
	            char Query2[500]="insert into Aircrafts values (";
	            strcat(aid,"\",\"");
                strcat(Query2, aid);
                strcat(aname,"\",");
                strcat(Query2, aname);
                strcat(Query2, cruisingrange);
                strcat(Query2,")");
    			if (mysql_query(conn, Query2))
    			{
    				fprintf(stderr, "%s\n", mysql_error(conn));
     				
    			}
    			printf("\n\n");
    			break;



               //certified table


    		case 3:
	    		printf("Enter aid and eid\n");
	            scanf("%s%s", aid, eid);
	            char Query3[500]="insert into Certified values (";
	            strcat(aid,",");
	            strcat(Query3,aid);
	            strcat(Query3,eid);
	            strcat(Query3,")");
	             printf("%s\n", Query3);
    			if (mysql_query(conn, Query3))
    			{
    				fprintf(stderr, "%s\n", mysql_error(conn));
     				
    			}
    			printf("\n\n");
    			break;





                //employee table

    		case 4:
    			printf("Enter eid, ename, salary\n");
               scanf("%s%s%s", eid, ename, salary);
               char Query4[500]="insert into Employees values (";
               strcat(eid,",\"");
               strcat(Query4,eid);
               strcat(ename,"\",");
               strcat(Query4,ename);
               strcat(Query4,salary);
               strcat(Query4,")");
    			if (mysql_query(conn, Query4))
    			{
    				fprintf(stderr, "%s\n", mysql_error(conn));
    			}
    			printf("\n\n");
    			break;
    		default:
    			printf("\n\n");
    			flag=0;
    			break;
    	}
    	printf("Enter next set of values (or) to exit enter 5\n");
    	int x;
    	scanf("%d",&x);
    	if (x==5)
    	{
    		flag=0;
    	}
	}
}


int startQuery(char Query[])
{
	printf("\n\n");
	if (mysql_query(conn,Query));
         {
            fprintf(stderr, "%s\n\n", mysql_error(conn));
            //return(1);
         }
        res=mysql_use_result(conn);
        int i=0;
     	while ((row = mysql_fetch_row(res)) != NULL)
      	{
         num_fields = mysql_num_fields(res);
         lengths = mysql_fetch_lengths(res);
         for(i = 0; i < num_fields; i++)
         {
            printf("|%-15.*s |", (int) lengths[i],row[i] ? row[i] : "NULL");

         }
         printf("\n");
      	}
           if (i==0)
           {
            printf("Empty Set\n");
           }
           printf("\n\n");
   mysql_free_result(res);
   return(0);
}


void Update_table(char table_name[], char attribute[], char new_value[], int opt)
{
	char Query[500]="update ";
	char condition[200];
	strcat(table_name," set ");
	strcat(Query,table_name);
	strcat(attribute,"=");
	strcat(attribute,new_value);
	strcat(Query,attribute);
	int and;
	if (opt>0)
	{
		strcat(Query," where ");
	}
	while(opt--)
	{
		printf("Enter the condition\n");
		scanf(" %999[^\n]",condition);               
		if (opt!=0)
		{
			printf("Enter 1 for AND and 0 for OR\n");
			scanf("%d",&and);
			if(and==1)
				strcat(condition," and");
			else
				strcat(condition," or");
		}
		strcat(Query, condition);
	}
	//printf("Query -************ %s\n", Query);
	if (mysql_query(conn, Query))
    {
    	fprintf(stderr, "%s\n", mysql_error(conn));

    }
}

int display_Tables(int option)
{
	char Query[500];
	switch(option)
	{
		case 1:
			strcpy(Query,"show columns from Flights");
			break;
		case 2:
			strcpy(Query,"show columns from Aircrafts");
			break;
		case 3:
			strcpy(Query,"show columns from Certified");
			break;
		case 4:
			strcpy(Query,"show columns from Employees");
			break;
	}
	if (mysql_query(conn, Query))
    {
    	fprintf(stderr, "%s\n", mysql_error(conn));

    }
        res=mysql_use_result(conn);
        int i=0;
     	while ((row = mysql_fetch_row(res)) != NULL)
      	{
         	num_fields = mysql_num_fields(res);
         	lengths = mysql_fetch_lengths(res);
            printf("|%-15.*s |", (int) lengths[i],row[i] ? row[i] : "NULL");
     	}
   mysql_free_result(res);

}







void ShowTables(char table_name[])
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
  	int i;
       num_fields = mysql_num_fields(res);
      lengths = mysql_fetch_lengths(res);
      for(i = 0; i < num_fields; i++)
         printf("%12.*s", (int) lengths[i],row[i] ? row[i] : "NULL");
      printf("\n");
  }
  mysql_free_result(res);
}




void Greaterthan()
{
	char statement[512], *my_str = "MyString";
	printf("\nEnter the value:");
         int v;
         scanf("%d",&v);                 
         snprintf(statement, 512, "select *from Aircrafts where cruisingrange>%d",v);
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

void CruisingEmployee()
{
	char statement[512], *my_str = "MyString";
	printf("\nEnter the value:");
         int v;
         scanf("%d",&v);                 
         snprintf(statement, 512, " select distinct(a.ename) from Employees as a,Certified as c,Aircrafts as b where b.cruisingrange>%d and b.aid=c.aid and c.eid=a.eid;",v);
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


void economy(char small[])
{
	char Query[500]="select no,source,destination,distance,departs,arrives,price from Flights order by ";
	strcat(Query,small);
	printf("Query-%s\n", Query);
	startQuery(Query);
	
}





void halts(int i, char source[], char dest[])
{
	int k=2;
	char Part1[600]="select f1.source, f1.destination, ";

	while(k<=i)
	{	
		char f[200]="";
		char destination[100]=".destination";
		sprintf(f,"f%d",k);
		strcat(f,destination);
		if(k!=i)
		{
			strcat(f,", ");
			strcat(Part1,f);
		}
		else
		{
			strcat(f," ");
			strcat(Part1,f);
		}
		k++;
	}
	k=1;
	strcat(Part1,"from ");
	while(k<=i)
	{
		char f[200]="";
		sprintf(f,"Flights f%d",k);
		if(k!=i)
		{
			strcat(f,", ");
			strcat(Part1,f);
		}
		else
		{
			strcat(f," ");
			strcat(Part1,f);
		}
		k++;
	}
	strcat(Part1,"where ");
	char cond1[100];
	sprintf(cond1,"f1.source=\"%s\"",source);
	strcat(Part1,cond1);
	char cond2[100];
	sprintf(cond2,"and f%d.destination=\"%s\" and ",i,dest);
	strcat(Part1,cond2);
	k=1;
	while(k<i)
	{
		char f[200]="";
		sprintf(f,"f%d.destination=f%d.source",k,k+1);
		if(k!=i-1)
		{
			strcat(f," and ");
			strcat(Part1,f);
		}
		else
		{
			strcat(f," ");
			strcat(Part1,f);
		}
		k++;
	}
	printf("%s\n", Part1);
	startQuery(Part1);
}



void employee()
{
	char statement[512], *my_str = "MyString";
	printf("\nEnter the value:");
         int v;
         scanf("%d",&v);                 
         snprintf(statement, 512, "select *from Employees where salary>%d",v);
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




void Delete()
{

	char  Attribute[20], New_Value[20],Table_Name[20];
	
    printf("\nEnter the name of the table: ");
    scanf(" %s",Table_Name);
    char Query[80]="delete from ";
    strcat(Query,Table_Name);
    strcat(Query," where ");
  
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
          
}


