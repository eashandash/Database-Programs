#include<stdio.h>
#include<string.h>






struct Employee
{
   char Fname[15];char Mname[15];char Lname[15];
   char SSN[15];char Bdate[15];char Address[40];char Sex[2];
   char Salary[15];char SuperSSN[15];char DeptNo[4];char MobileNo[15];
};


 struct Employee E;


 void project(char a[25])
 {

  //int index=1;


    if(strcmp(a,"Fname")==0)
        printf("fname :%s  \n",E.Fname);
      //   index++;
       
        

    if(strcmp(a,"Mname")==0)
      printf("Mname :%s  \n",E.Mname);
        // index++;
       

    if(strcmp(a,"Lname")==0)
       printf("Lname : %s \n",E.Lname); 
         //index++;
       

    if(strcmp(a,"SSN")==0)
       printf("ssn : %s \n",E.SSN); 
         //index++;
       
   
    if(strcmp(a,"Bdate")==0)
      printf("bday : %s \n",E.Bdate);
         //index++;
       

    if(strcmp(a,"Address")==0)
       printf("address : %s  \n",E.Address);
         //index++;
       
   
    if(strcmp(a,"Sex")==0)
       printf("sex : %s \n",E.Sex); 
         //index++;
       

    if(strcmp(a,"Salary")==0)
        printf("salary : %s \n",E.Salary); 
         //index++;
       

    if(strcmp(a,"SuperSSN")==0)
       printf("super ssn : %s \n",E.SuperSSN);
         //index++;
       
   
    if(strcmp(a,"DeptNo")==0)
       printf("dept no : %s \n",E.DeptNo); 
         //index++;
       

    if(strcmp(a,"MobileNo")==0)
        printf("mobile no :  %s \n",E.MobileNo); 
         //index++;
       
    }




































int main(int c,char *a[])
{
  
  FILE * fptr;
  if(strcmp(a[1],"project")==0 || strcmp(a[1],"PROJECT")==0||strcmp(a[1],"Project")==0)
  {
    fptr=fopen(a[3],"r");
    while(fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s",E.Fname,E.Mname,E.Lname,E.SSN,E.Bdate,E.Address,E.Sex,E.Salary,E.SuperSSN,E.DeptNo,E.MobileNo)==11)
        {
        	
        	project(a[2]);
        	
        }
    



  }

  fclose(fptr);
} 
