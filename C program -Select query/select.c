#include <stdio.h>
#include <string.h>






struct Employee
{
   char Fname[15];char Mname[15];char Lname[15];
   char SSN[15];char Bdate[15];char Address[40];char Sex[2];
   char Salary[15];char SuperSSN[15];char DeptNo[4];char MobileNo[15];
};


 struct Employee E;


 void select(char a[25],char b[25])
 {

 	//int index=1;


    if(strcmp(a,"Fname")==0)
    	if(strcmp(E.Fname,b)==0)
    	  {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
      //   index++;
       }
        

    if(strcmp(a,"Mname")==0)
    	if(strcmp(E.Mname,b)==0)
           {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
        // index++;
       }

    if(strcmp(a,"Lname")==0)
        if(strcmp(E.Lname,b)==0)
           {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }

    if(strcmp(a,"SSN")==0)
       if(strcmp(E.SSN,b)==0)
       {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
       }
   
    if(strcmp(a,"Bdate")==0)
       if(strcmp(E.Bdate,b)==0)
         {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }

    if(strcmp(a,"Address")==0)
       if(strcmp(E.Address,b)==0)
          {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }
   
    if(strcmp(a,"Sex")==0)
       if(strcmp(E.Sex,b)==0)
          {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }

    if(strcmp(a,"Salary")==0)
       if(strcmp(E.Salary,b)==0)
         {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }

    if(strcmp(a,"SuperSSN")==0)
       if(strcmp(E.SuperSSN,b)==0)
          {
        
       printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }
   
    if(strcmp(a,"DeptNo")==0)
       if(strcmp(E.DeptNo,b)==0)
          {
        
       printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }

    if(strcmp(a,"MobileNo")==0)
       if(strcmp(E.MobileNo,b)==0)
          {
        
        printf("fname :%s  \nmname :%s \nlname : %s \nSSN : %s \nBdate : %s \naddress : %s \nsex : %s \nsalary : %s\nsuperssn :  %s\ndeptno :  %s\nmobile no : %s\n",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo);
         //index++;
       }
    }







int main(int c,char *a[])
{
  
  FILE * fptr;
  if(strcmp(a[1],"select")==0 || strcmp(a[1],"SELECT")==0||strcmp(a[1],"Select")==0)
  {
    fptr=fopen(a[5],"r");
    while(fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo)==11)
        {
        	
        	select(a[2],a[4]);
        	
        }
    



  }

  fclose(fptr);
} 

 





