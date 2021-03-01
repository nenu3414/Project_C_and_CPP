#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char ans=0;
int ok;
int b, valid=0;

void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list();
void Search_rec(void);
void Edit_rec(void);
void ex_it(void);
void delete_rec(void);

struct employee
{
  int age;
  char empID[5];
  char Gender;
  char First_Name[20];
  char Last_Name[20];
  char Contact_no[15];
  char Address[30];
  char Email[30];
  char Department[20];
  char Position[20];
};

struct employee  p,temp_c;



int main(void)
{

  WelcomeScreen();
  Title();
  LoginScreen();




}
void WelcomeScreen(void)
{

  printf("\n\t\t+++++++++++++++++++++++++++++++++++++++++++++++");
  printf("\n\t\t    WELCOME TO EMPLOYEE MANAGEMENT SYSTEM");
  printf("\n\t\t+++++++++++++++++++++++++++++++++++++++++++++++");
  printf("\n\t\t         Data Structure and Algorithm ");
  printf("\n\t\t                   TAE_2");
  printf("\n\nExecuted by:");
  printf("\nRitika Kalia (B-24)");
  printf("\nNeenad Sahasrabuddhe (B-37)");
  printf("\n\n\t\t\tPress any key to Enter|->");
  getch();
  system("cls");

}

void Title(void)
{
  printf("\n\t-------------------------------------------------------");
  printf("\n\t               EMPLOYEE MANAGEMENT SYSTEM        ");
  printf("\n\t-------------------------------------------------------");
}

void MainMenu(void)
{
  system("cls");
  int choose;
  Title();
  printf("\n1. Add Employee Record\n");
  printf("\n2. List Employee Record\n");
  printf("\n3. Search Employee Record\n");
  printf("\n4. Edit Employee Record\n");
  printf("\n5. Delete Employee Record\n");
  printf("\n6. Exit\n");
  printf("\nChoose from 1 to 6:");
  scanf("%i", &choose);

  switch(choose)
  {

  case 1:
  Add_rec();
  break;
  case 2:
  func_list();
  break;
  case 3:
  Search_rec();
  break;
  case 4:
  Edit_rec();
  break;
  case 5:
  delete_rec();
  break;
  case 6:
  ex_it();
  break;
  default:
  printf("\t\t\tInvalid entry. Please enter correct option :)");
  getchar();
  MainMenu();
  }
}

void ex_it(void)
{
  system("cls");
  Title();
  printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
  getchar();

}

void LoginScreen(void)
{
int e=0,i=0;
char Username[15];
char Password[15],c=' ';
char original_Username[25]="Ritika";
char original_username[25]="Neenad";
char original_Password[15]="Ritika@123";
char original_password[15]="Neenad@123";

do
{
  printf("\n\n\t\t* Admin Login:");
  printf("\n\n\n\t\tEnter Username and Password ->");
  printf("\n\n\t\tUSERNAME:");
  scanf("%s",Username);

  printf("\t\tPASSWORD:");
  while(i<10)
	{
	    Password[i]=getch();
	    c=Password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	Password[i]='\0';
	i = 0;

  if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
  {
    printf("\n\n\t\t\tHello Ritika! ^_^");
    printf("\n\n\t\t\tLogin Successfull....\n");

    getchar();
    MainMenu();
    break;
  }
  if (strcmp(Username,original_username)==0 && strcmp(Password,original_password)==0)
  {
    printf("\n\n\t\t\tHello Neenad! ^_^");
    printf("\n\n\t\t\tLogin Successfull....");

    getchar();
    MainMenu();
    break;
  }
  else
  {
    printf("\n\t\t\tPassword in incorrect:( Try Again :)");
    e++;
    getchar();
  }

}
while(e<=2);
  if(e>2)
  {
  printf("You have cross the limit. You cannot login. :( :(");
  getchar();
  ex_it();
  }

system("cls");
}


void Add_rec(void)
{
  system("cls");
  Title();
  char ans;
  FILE*f;
  f=fopen("employee.txt","a");
	if(f==0)
	{   f=fopen("employee.txt","w");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
  printf("\n\n\t   !!!!!!!!!!!! Add Employee Record !!!!!!!!!!!!\n");

  printf("\n\t    Employee ID: ");
  scanf("%s",p.empID);

  B:
  printf("\n\t    First Name: ");
  scanf("%s",p.First_Name);
  p.First_Name[0]=toupper(p.First_Name[0]);
  if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
  {
    printf("\n\t Invalid :( The max range for first name is 20 and min range is 2 :)");
    goto B;
  }
  else
  {
    for (b=0;b<strlen(p.First_Name);b++)
    {
      if (isalpha(p.First_Name[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t First name contain Invalid character :( Enter again :)");
      goto B;
    }
  }

  C:
  printf("\n\t    Last Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
  {
    printf("\n\t Invalid :( The max range for last name is 20 and min range is 2 :)");
    goto C;
  }
  else
  {
    for (b=0;b<strlen(p.Last_Name);b++)
    {
      if (isalpha(p.Last_Name[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t Last name contain Invalid character :(  Enter again :)");
      goto C;
    }
  }

  do
  {
      printf("\n\t    Gender[F/M]: ");
    scanf(" %c",&p.Gender);
    if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
    {
      ok =1;
    }
    else
    {
    ok =0;
    }
        if(!ok)
      {
        printf("\n\t Gender contain Invalid character :( Enter either F or M :)");
      }
   }  while(!ok);
    printf("\n\t    Age:");
    scanf(" %i",&p.age);

    do
    {
    D:
    printf("\n\t    Address: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
  {
    printf("\n\t Invalid :( The max range for address is 20 and min range is 4 :)");
    goto D;
  }

}while(!valid);

do
{
  E:
    printf("\n\t    Contact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
  {
    printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
    goto E;
  }
  else
  {
    for (b=0;b<strlen(p.Contact_no);b++)
    {
      if (!isalpha(p.Contact_no[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t Contact no. contain Invalid character :( Enter again :)");
      goto E;
    }
  }
}while(!valid);

do
{
    printf("\n\t    Email: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( The max range for email is 30 and min range is 8 :)");
  }
}while(strlen(p.Email)>30||strlen(p.Email)<8);

    F:
    printf("\n\t    Position: ");
    scanf("%s",p.Position);
    p.Position[0]=toupper(p.Position[0]);
    if(strlen(p.Position)>15||strlen(p.Position)<3)
  {
    printf("\n\t Invalid :( The max range for first name is 15 and min range is 3 :)");
    goto F;
  }
  else
  {
    for (b=0;b<strlen(p.Position);b++)
    {
      if (isalpha(p.Position[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t Position contain Invalid character :( Enter again :)");
      goto F;
    }
  }

    G:
    printf("\n\t    Department:");
    scanf("%s",&p.Department);
    p.Department[0]=toupper(p.Department[0]);
    if(strlen(p.Department)>30||strlen(p.Department)<3)
  {
    printf("\n\t Invalid :( The max range for first name is 30 and min range is 3 :)");
    goto G;
  }
  else
  {
    for (b=0;b<strlen(p.Department);b++)
    {
      if (isalpha(p.Department[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t Department name contain Invalid character :( Enter again :)");
      goto G;
    }
  }
    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\n\n\t.......... Information Record Successful ..........");
    fclose(f);
    break;
	}
    sd:
    getchar();
    printf("\n\n\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
  {
      Add_rec();
  }
    else if(toupper(ans)=='N')
  {
    printf("\n\t\t Thank you :) :)");
      getchar();
      MainMenu();
  }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

void func_list()
{
  system("cls");
  Title();
  FILE *f;
  f=fopen("employee.txt","r");
  printf("\n\n\t\t!!!!!!!!!!!!!! List Employee Record !!!!!!!!!!!!!\n");
    while(fread(&p,sizeof(p),1,f)==1)
    {
      printf("%s\n",p.empID);
      printf("%s %s\n",p.First_Name, p.Last_Name);
      printf("%c\n",p.Gender);
      printf("%i\n",p.age);
      printf("%s\n",p.Address);
      printf("%s\n",p.Contact_no);
      printf("%s\n",p.Email);
      printf("%s\n",p.Position);
      printf("%s\n\n",p.Department);
    }
    fclose(f);
    getch();
    MainMenu();
}
void Search_rec(void)
{
  char name[20];
  system("cls");
  Title();// call Title function
  FILE *f;
  f=fopen("employee.txt","r+");
  printf("\n!!!!!!!!!!!!!!! Search Employee Record !!!!!!!!!!!!!!\n");
  printf("\nEnter Employee ID to be viewed:");
  scanf("%s",name);
  fflush(stdin);
  while(fread(&p,sizeof(p),1,f)==1)
  {
    if(strcmp(p.empID,name)==0)
    {
      printf("\n%s\n",p.empID);
      printf("%s %s\n",p.First_Name, p.Last_Name);
      printf("%c\n",p.Gender);
      printf("%i\n",p.age);
      printf("%s\n",p.Address);
      printf("%s\n",p.Contact_no);
      printf("%s\n",p.Email);
      printf("%s\n",p.Position);
      printf("%s\n\n",p.Department);
      break;
    }
     }
     if(strcmp(p.empID,name)!=0)
     {
    printf("Record not found!");
    getchar();
     }
  fclose(f);
  L:
  getchar();
  printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
  else if(toupper(ans)=='N')
  {
    printf("\n\t\t Thank you :) :)");
      getchar();
    MainMenu();
    }
  else
    {
      printf("\n\tInvalid Input.\n");
      goto L;
    }
}

void Edit_rec(void)
{
  FILE *f, *t;
  int valid=0;
  int ch;
  char name[20];

  system("cls");
    Title();
     t=fopen("temp.txt","w");
     f=fopen("employee.txt","r");
     printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Employee Record !!!!!!!!!!!!!\n");
     printf("Enter the ID of the Employee : ");
     scanf(" %s",name);
     fflush(stdin);

    if(f==NULL)
    {
      printf("\n Can not open file");
      getchar();
      MainMenu();
    }
    while(fread(&p, sizeof(p), 1,f)==1)
    {
      if(strcmp(p.empID, name)==0)
      {
        printf("* Existing Record *\n");
        printf("\n%s \n%s \n%s \n%c \n%i \n%s \n%s \n%s \n%s \n%s\n",p.empID,p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Position,p.Department);
        valid=1;
        printf("\n\t1. Update First Name of Employee ID %s", name);
        printf("\n\t2. Update Last Name of Employee ID %s", name);
        printf("\n\t3. Update Gender of Employee ID %s", name);
        printf("\n\t4. Update Age of Employee ID %s", name);
        printf("\n\t5. Update Address of Employee ID %s", name);
        printf("\n\t6. Update Contact Number of Employee ID %s", name);
        printf("\n\t7. Update Email ID of Employee ID %s", name);
        printf("\n\t8. Update Position ID of Employee ID %s", name);
        printf("\n\t9. Update Department ID of Employee ID %s", name);
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter First Name:");
            scanf("%s", p.First_Name);
            break;
            case 2:
            printf("Enter Last Name:");
            scanf("%s", p.Last_Name);
            break;
            case 3:
            printf("Enter Gender:");
            scanf("%c", p.Gender);
            break;
            case 4:
            printf("Enter Age:");
            scanf("%i", p.age);
            break;
            case 5:
            printf("Enter Address:");
            scanf("%s", p.Address);
            break;
            case 6:
            printf("Enter Contact Number:");
            scanf("%s", p.Contact_no);
            break;
            case 7:
            printf("Enter Email ID: ");
            scanf("%s", p.Email);
            break;
            case 8:
            printf("Enter Position:");
            scanf("%s", p.Position);
            break;
            case 9:
            printf("Enter Department:");
            scanf("%s", p.Department);
            break;
            default:
            printf("Invalid Selection");
            break;
        }
        fwrite(&p, sizeof(p), 1,t);
      }
      else
        {
            fwrite(&p, sizeof(p), 1,t);
        }
    }
    fclose(f);
    fclose(t);
    f = fopen("employee.txt", "w");
    t = fopen("temp.txt", "r");
    while (fread(&p, sizeof(p), 1,t))
        {
            fwrite(&p, sizeof(p), 1,f);
        }
        if(valid==0)
        {
            printf("\n\tRequested Employee could not be found!");
        }
  fclose(f);
  fclose(t);
  printf("\n\n\t\t\tEmployee record updated successfully...");
  getch();
  MainMenu();
}

void delete_rec()
{
	FILE *f,*t;
	int i=1;
	char name[20];
	t=fopen("temp.txt","w");
	f=fopen("employee.txt","r");
	if(f==NULL)
    {
      printf("\n Can not open file");
      getchar();
      MainMenu();
    }
	system("cls");
	printf("Enter the Employee ID to be deleted from the database: ");
	fflush(stdin);
	scanf("%s",name);
	while(fread(&p,sizeof(p),1,f)==1)
	{
		if(strcmp(p.empID,name)==0)
		{
		    i=0;
			continue;
		}
		else
            fwrite(&p,sizeof(p),1,t);
	}
	if(i==1)
	{
		printf("\n\n Record of Employee not found!!");
		getch();
		fclose(f);
		fclose(t);
	}
	fclose(f);
	fclose(t);
	remove("employee.txt");
	rename("temp.txt","employee.txt");
	printf("\n\nThe Employee information is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
	MainMenu();
}
