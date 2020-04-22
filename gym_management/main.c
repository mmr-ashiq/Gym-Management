#include<stdio.h>
#include<conio.h>   //getch(),
#include <stdlib.h> //system("CLS"),
#include<windows.h> //gotoxy(),
#include<string.h>
#include<time.h>    //time

//pre-function declaration
void main_menu();
void receptionist_registration();
void receptionist_authentication();
double BMI();
int Loading_Animator();
void equipment();
void Receptionist_Section();
void addstaff();
int getdata();
void deletestaff();
void searchstaff();
void viewstaff();
void editstaff();
int checkid();
void equipment();
void Trainer();
void admin_registration();
void admin_authentication();
void admin_section();
void returnfunc();
void date_time();

//global variable and structure
int i,s;
FILE *fp,*ft,*fs;
char catagories[][15]= {"New Member","Coach","Staff"};

char findstaff;

//main function start
int main()
{
    main_menu();
    getch();
}

//Main menu
void main_menu(void)
{
    system("color F2");
    system("CLS");
    int chose_in_1st_step,chose_in_2nd_step;

    date_time();

    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** W E L C O M E    T O    \"M M R G Y M\" **                      %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();
    printf("\n\n\n\n\t\t\t1)Receptionist Section\n");
    printf("\t\t\t2)Authority Section\n");
    printf("\t\t\t3)BMI Calculator\n");
    printf("\t\t\t4)Quit\n");
    printf("\n\t\t\tEnter your choice: ");
    scanf("%d",&chose_in_1st_step);
    switch(chose_in_1st_step)
    {
    case 1:
    {
        system("CLS");
        design_LINE();
        printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
        printf("\n\t\t\t%c \t\t   ** R E C E P T I O N I S T    S I G N    I N **                  %c",178,178);
        printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
        design_LINE();
        receptionist_authentication();
        break;
    }
    case 2:
    {
        system("CLS");
        design_LINE();
        printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
        printf("\n\t\t\t%c \t\t   ** A U T H O R I T Y    S I G N    I N **                        %c",178,178);
        printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
        design_LINE();
        gotoxy(20,7);
        admin_authentication();
        break;
    }
    case 3:
        {
            double height,weight;
            system("CLS");
            design_LINE();
            printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
            printf("\n\t\t\t%c \t\t   ** B M I    C A L C U L A T O R **                               %c",178,178);
            printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
            design_LINE();
            system("color F5");
            gotoxy(24,11);
            printf("Enter you Height(meter): ");
            scanf("%lf",&height);
            gotoxy(24,13);
            printf("Enter your Weight: ");
            scanf("%lf",&weight);
            BMI(height,weight);
        }
    case 4:
        {
            exit(1);
        }
    default:
    {
        printf("\t\t\twrong input\n");
        printf("\t\t\tEnter any key to try again...");
        getch();
        system("CLS");
        main_menu();
    }
    }
}

//for adding members information
struct staff
{
    int id;
    char name[20];
    char Address[20];
    char membersince[10];
    int contact;
    char *cat;

};
struct staff a;

//cursor console
COORD coord= {0,0}; // this is global variable, COORD is predefined structure
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//receptionist registration
struct login
{
    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
};
struct login l;
void receptionist_registration(void)
{
    FILE *log;
    log=fopen("receptionist-login.txt","w");
    printf("Enter first name: ");
    scanf("%s",l.fname);
    printf("Enter last name: ");
    scanf("%s",l.lname);
    printf("Enter Username: ");
    scanf("%s",l.username);
    printf("Enter password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\nyour user name is userID\n");
    printf("Now login with user id and password\n");
    printf("\npress any key to continue.......");
    getch();
    system("CLS");
    receptionist_authentication();
}
//receptionist user name & password
void receptionist_authentication(void)
{
    char username[200],password[20];
    FILE *log;
    log=fopen("receptionist-login.txt","r");
    struct login l;
    printf("\n\n\n\t\t\tUserID: ");
    scanf("%s",&username);
    printf("\n\t\t\tpassword: ");
    char ch;
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            password[i] = ch;
            i++;
        }
    }
    password[i] = '\0';

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            Loading_Animator();
            printf("\n\n\t\t\tSuccessfully login...\n");
            Receptionist_Section();
        }
        else
        {
            system ("CLS");
            printf ("\n\t\t\t   \xDB\xDB Sorry ! Access Not Granted \xDB\xDB ");
            printf ("\n\n\t\t\t      !!! T R Y   A G A I N  !!!");
            getch();
            break;
        }
    }
    main_menu();
    fclose(log);
}

//Receptionist section
void Receptionist_Section(void)
{
    system("color F2");
    system("CLS");

    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** R E C E P T I O N I S T    S E C T I O N **                   %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();

    printf("\n\n\t\t\t1)Add Staff");
    printf("\n\t\t\t2)Remove Membership");
    printf("\n\t\t\t3)Search Member");
    printf("\n\t\t\t4)View Member");
    printf("\n\t\t\t5)Edit Members Record");
    printf("\n\t\t\t6)View package");
    printf("\n\t\t\t7)View Equipment");
    printf("\n\t\t\t8)Our Trainers");
    printf("\n\t\t\t9)Back to main menu");
    int Receptionist_Section_choice;
    printf("\n\n\t\t\tEnter your choice: ");
    scanf("%d",&Receptionist_Section_choice);
    system("CLS");
    switch(Receptionist_Section_choice)
    {
    case 1:
    {
        addstaff();
        break;
    }
    case 2:
    {
        deletestaff();
        break;
    }
    case 3:
    {
        searchstaff();
        break;
    }
    case 4:
    {
        viewstaff();
        break;
    }
    case 5:
    {
        editstaff();
        break;
    }
    case 6:
    {
        printf("\n\t\t3-month package (without admission fee)");
        printf("\n\t\t\t\t-Member will get a gym bag as a gift.");
        returnfunc();
        break;
    }
    case 7:
    {
        int a_m_c_7_choice;
        //gotoxy(24,11);
        equipment();

        printf("Enter '0/1' for go to Respectively main menu/Receptionist section: ");
        scanf("%d",&a_m_c_7_choice);
        if(a_m_c_7_choice == 0)
        {
            main_menu();
        }
        else if(a_m_c_7_choice == 1)
        {
            Receptionist_Section();
        }
        else
        {
            //gotoxy(24,11);
            printf("wrong input\n");
            printf("Enter any key to go back Receptionist Section\n");
            getch();
            system("CLS");
            Receptionist_Section();
        }
        break;
    }
    case 8:
    {
        Trainer();
        printf("\n\n\tEnter any key to go back Receptionist_Section..");
        getch();
        Receptionist_Section();
        break;
    }
    case 9:
    {
        returnfunc();
        break;
    }
    default:
        printf("\t\t\twrong input");
        break;
    }
}

//Receptionist section - Add members section
void addstaff(void)
{
    system("CLS");
    int i;
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** W E L C O M E    T O    \"M M R G Y M\" **                      %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();
    gotoxy(20,9);
    printf("\xDB\xB2  SELECT CATEGORIES  \xB2\xDB");
    gotoxy(20,11);
    printf("1) New Member");
    gotoxy(20,13);
    printf("2) Coach");
    gotoxy(20,15);
    printf("3) Staff");
    gotoxy(20,17);
    printf("4) Back to main menu");
    gotoxy(20,19);
    printf("Enter your choice: ");
    scanf("%d",&s);
    if(s==4)
        main_menu();
    system("CLS");
    fp=fopen("staff_information.txt","a+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];

        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(20,23);
        printf("The record is Successfully saved");
        gotoxy(20,25);
        printf("Save any more?(Y / N):");
        if(getch()=='n' || 'N')
        {
            system("CLS");
            main_menu();
        }
        else
        {
            system("CLS");
            addstaff();
        }
    }
}

//get data function
int getdata(void)
{
    int t;
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** M E M B E R S    I N F O R M A T I O N  **                    %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xB2  Enter the Information Below  \xB2\xDB\xDB\xDB");
    gotoxy(20,11);
    printf("Category: ");
    printf("%s",catagories[s-1]);
    gotoxy(20,13);
    printf("ID: ");
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(20,15);
        printf("\aThe id already exists\a");
        getch();
        main_menu();
        return 0;
    }
    a.id=t;
    gotoxy(20,15);
    printf("Name: ");
    scanf("%s",a.name);
    gotoxy(20,17);
    printf("Address: ");
    scanf("%s",a.Address);
    gotoxy(20,19);
    printf("Contact: +880");
    scanf("%i",&a.contact);
    gotoxy(20,21);
    printf("Member Since: ");
    scanf("%s",&a.membersince);
}

//this above function is for deleting a member
void deletestaff(void)
{
    system("CLS");
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** R E M O V E    A    M E M B E R **                            %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();

    int d;
    char another='y';

    while(another=='y')
    {
        gotoxy(20,7);

        printf("Enter the ID to  remove: ");
        scanf("%d",&d);
        fp=fopen("staff_information.txt","r");

        rewind(fp);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                gotoxy(20,9);

                printf("The record is available");

                gotoxy(20,11);

                printf("Name is %s",a.name);

                gotoxy(20,13);

                findstaff='t';

            }

        }

        if(findstaff!='t')

        {
            gotoxy(20,10);

            printf("No record is found modify the search\n");

            if(getch())
                main_menu();
        }

        if(findstaff=='t' )
        {
            gotoxy(20,15);

            printf("Do you want to delete it?(Y/N):");

            if(getch()=='y')

            {
                ft=fopen("test.txt","w");

                rewind(fp);

                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);

                        fwrite(&a,sizeof(a),1,ft);
                    }
                }
                fclose(ft);
                fclose(fp);

                remove("staff_information.txt");

                rename("test.txt","staff_information.txt");

                fp=fopen("staff_information.txt","r");

                if(findstaff=='t')
                {
                    gotoxy(20,17);

                    printf("The record is Successfully deleted");

                    gotoxy(20,19);

                    printf("\n\tDelete another record?(Y/N)");

                }
            }
            else
                main_menu();

            fflush(stdin);
            another=getch();

        }
    }
    gotoxy(20,20);
    Receptionist_Section();

}

//function for checking id
int checkid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}

//This above function for edit member's information
void editstaff(void)
{
    system("cls");
    int c=0;
    int d,e;
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   **  E D I T    A    M E M B E R \' S    I N F O  **               %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();
    gotoxy(20,7);
    char another='y';
    while(another=='y')
    {
        printf("Enter Id to be edited: ");
        scanf("%d",&d);
        fp=fopen("staff_information.txt","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(20,9);
                printf("This Member is Available==>");
                gotoxy(20,11);
                printf("The ID:%d",a.id);
                gotoxy(20,12);
                printf("Enter new name: ");
                scanf("%s",a.name);
                gotoxy(20,13);
                printf("Enter new Address: ");
                scanf("%s",a.Address);
                gotoxy(20,14);
                printf("Enter new Contact: +880");
                scanf("%i",&a.contact);
                gotoxy(20,15);
                printf("Enter New Membership date: ");
                scanf("%s",&a.membersince);
                gotoxy(20,17);
                printf("The record is modified!");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(20,11);

                printf("No record found!");
            }
        }

        gotoxy(20,19);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        if(getch()=='Y' || 'y')
        {
            system("CLS");
            editstaff;
        }
        else
            break;
    }
    returnfunc();
}

//Admin Registration
void admin_registration(void)
{
    FILE *log;
    log=fopen("adminlogin.txt","w");

    printf("Enter first name: ");
    scanf("%s",l.fname);
    printf("Enter last name: ");
    scanf("%s",l.lname);
    printf("Enter Username: ");
    scanf("%s",l.username);
    printf("Enter password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\nyour user name is userID\n");
    printf("Now login with user id and password\n");
    printf("\npress any key to continue.......");
    getch();
    system("CLS");
    receptionist_authentication();
}

//checking admin user name & password
void admin_authentication()
{
    char username[200],password[20];
    FILE *log;
    log=fopen("adminlogin.txt","r");
    struct login l;
    printf("\n\t\t\tUserID: ");
    scanf("%s",&username);
    printf("\n\t\t\tpassword: ");
    char ch;
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            password[i] = ch;
            i++;
        }
    }
    password[i] = '\0';

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\n\n\t\t\tSuccessfully login\n");
            Loading_Animator();
            admin_section();
        }
        else
        {
            system ("CLS");
            printf ("\n\t\t\t   \xDB\xDB Sorry ! Access Not Granted \xDB\xDB ");
            printf ("\n\n\t\t\t      !!! T R Y   A G A I N  !!!");
            getch();
            main_menu();
        }
    }

    fclose(log);
}

//Calculate BMI
double BMI(double hight,double weight)
{
    double percentage=(weight)/(hight* hight);
    if(percentage<16 && percentage<18.5)
    {
        printf("\n\t\t\tBMI index is : %.2lf\n",percentage);
        printf("\n\t\t\t-Thinness");
    }
    else if(percentage>18.5 && percentage<25)
    {
        printf("\n\t\t\tBMI index is : %.2lf",percentage);
        printf("\n\t\t\t-Normal");
    }
    else if(percentage>25 && percentage<30)
    {
        printf("\n\t\t\tBMI index is : %.2lf",percentage);
        printf("\n\t\t\t-Overweight");
    }
    else if(percentage>30 && percentage<40)
    {
        printf("\n\t\t\tBMI index is : %.2lf",percentage);
        printf("\n\t\t\t-Obese");
    }
    else
    {
        printf("\n\t\t\tsomething is wrong!\b");
    }
    printf("\n\n\t\t\twant to go main menu ? (0/1): ");
    int choice_bmi;
    scanf("%d",&choice_bmi);
    if(choice_bmi == 1)
        main_menu();

    else if(choice_bmi == 0)
        exit(1);

    else
    {
        printf("\t\t\tWrong input!\n");
        getch();
        main_menu();
    }
}

//Loading Animator function(for design purpose
int Loading_Animator()
{
    printf("\n");
    int k;
    int c=1,d=1;
    printf("\n\t\t\t");
    for(k=1; k<=60; k++)
    {
        printf("%c",220);
        for(c=1; c<=25000/8; c++)
            for(d=1; d<=25000/8; d++)
            {

            }
    }
    printf("\n\t\t\t\t\t\t\n");
    return 0;
}

//for design purpose
void design_LINE()
{
    printf("\n");
    printf("\t\t\t%c",178,178);
    int designerA;
    for (designerA=1; designerA<=84; designerA++)
    {
        printf("%c",178);
    }
}

//Date and Time
int time_date(void)
{
    time_t t;

    time(&t);

    printf("\n\n\t\t\tDate and time:%s\n",ctime(&t));

    return 0 ;
}

//Return function as if we need to use go back to main menu frequently
void returnfunc(void)
{
    {
        gotoxy(20,10);
        printf("Press ENTER to return to main menu");
    }
a:
    if(getch()==13)
        main_menu();
    else
        goto a;
}

//Trainer
void Trainer(void)
{
    system("color F4");
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** O U R    T R A I N E R **                                     %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();

    gotoxy(24,7);
    printf("\n\n\t06.00AM - 11.59AM: Mr. jhon & Mr. Cena\n");
    printf("\t12.00PM - 05.59PM: Mr. Roman & Mr. Rings\n");
    printf("\t06.00PM - 11.59PM: Mr. Brock & Mr. Lesner\n");

    printf("\n\tPersonal Trainers(VIP):");
    printf("\n\t\t1)Mr. Rock");
    printf("\n\t\t2)Mr. matt");
}

//equipment function
void equipment()
{
    system("color F4");

    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** E Q U I P M E N T    W E    H A V E **                        %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();

    FILE* fp;
    char a[100];
    fp = fopen("equipment.txt","r");
    if(fp == NULL)
        printf("file not found\n");
    else
    {
        while(!feof(fp))
        {
            fgets(a,40,fp);
            printf("\n%s \n",a);
        }
    }

}

//date and time function for design and view trainer purpose
void date_time(void)
{
    printf("\n\t\t\t\t\t\tDate and Time: %s",__DATE__);
    printf("\t%s\n",__TIME__);
}

//Admin section
void admin_section(void)
{
    system("CLS");
    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** A D M I N   P A N E L **                                      %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();
    printf("\n\n\n\t\t\t1)Change Receptionist id & pass\n");
    printf("\t\t\t2)Change Admin id & pass\n");
    printf("\t\t\t3)View Members\n");
    printf("\t\t\t4)quit\n");
    printf("\n\t\t\tEnter your choice: ");
    int admin_section_choice;
    scanf("%d",&admin_section_choice);
    switch(admin_section_choice)
    {
    case 1:
    {
        system("CLS");
        gotoxy(24,1);
        receptionist_registration();
        break;
    }
    case 2:
    {
        system("CLS");
        printf("\n\n\t\t\tAre you sure? 0/1 : ");
        int s;
        scanf("%d",&s);
        if(s==1)
        {
            printf("\t\t\tEnter your previous id and password\n");
            receptionist_authentication();
        }
        else if(s==0)
        {
            admin_section();
        }
        else
            printf("\t\t\tSomething Wrong!\n");
    }
    }

}

void searchstaff(void)
{
    system("CLS");

    int d;

    design_LINE();
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    printf("\n\t\t\t%c \t\t   ** S E A R C H    A    M E M B E R **                            %c",178,178);
    printf("\n\t\t\t%c \t\t                                                                    %c",178,178);
    design_LINE();

    gotoxy(20,9);

    printf("1) Search By ID");

    gotoxy(20,11);

    printf("2) Search By Name");

    gotoxy( 20,13);

    printf("Enter Your Choice: ");

    fp=fopen("staff_information.txt","rb+");

    rewind(fp);

    switch(getch())
    {
    case '1':
    {
        system("CLS");
        gotoxy(25,2);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2  Search By Id  \xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(20,6);

        printf("Enter the id: ");
        scanf("%d",&d);

        gotoxy(20,8);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {

                Sleep(2);
                gotoxy(20,6);
                printf("The Record is available\n");
                gotoxy(20,8);
                printf("ID:%d",a.id);
                gotoxy(20,9);
                printf("Category:%s",a.cat);
                gotoxy(20,10);
                printf("Name:%s",a.name);
                gotoxy(20,11);
                printf("Address:%s ",a.Address);
                gotoxy(20,12);
                printf("Contact:%i ",a.contact);
                gotoxy(20,13);
                printf("Member Since:%s",a.membersince);
                findstaff='t';
            }

        }

        if(findstaff!='t')

        {

            printf("\aNo Record Found");

        }

        gotoxy(20,17);

        printf("Try another search?(Y/N)");

        if(getch()=='y')
        {
            system("CLS");
            searchstaff();
        }

        else
            Receptionist_Section();

        break;
    }

    case '2':
    {
        char s[15];
        system("CLS");

        gotoxy(25,4);

        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2  Search Record By Name  \xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(20,5);

        printf("Enter the Name:");
        scanf("%s",s);

        int d=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.name,(s))==0)
            {
                gotoxy(20,d+7);

                printf("The Staff is available");

                gotoxy(20,d+8);

                printf("ID:%d",a.id);

                gotoxy(20,d+10);

                printf("Name:%s",a.name);

                gotoxy(20,d+11);

                printf("Address:%s",a.Address);

                gotoxy(20,d+12);

                printf("Contact:%i",a.contact);

                gotoxy(20,d+13);

                printf("Member Since:%s",a.membersince);

                gotoxy(20,d+14);

                getch();

                d+=6;

            }
        }

        if(d==0)

            printf("\aNo Record Found");

        gotoxy(20,d+11);

        printf("Try another search?(Y/N)");

        if(getch()=='y')
            searchstaff();

        else
            main_menu();

        break;
    }

    default :
        getch();
        searchstaff();

    }

    fclose(fp);

}

//Function for view member list
void viewstaff(void)
{
    int i=0;
    system("CLS");

    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2    M E M B E R \' S    L I S T    \xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
    gotoxy(2,3);
    printf("\n CATEGORY === ID ==== NAME ======== ADDRESS ===== CONTACT ===== MEMBER SINCE \n");

    fp=fopen("staff_information.txt","r");

    int j = 5;
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(1,j);
        printf("%s",a.cat);
        gotoxy(14,j);
        printf("%d",a.id);
        gotoxy(22,j);
        printf("%s",a.name);
        gotoxy(36,j);
        printf("%s",a.Address);
        gotoxy(50,j);
        printf("%i",a.contact);
        gotoxy(67,j);
        printf("%s",a.membersince);
        gotoxy(68,j);
        printf("\n\n");
        j++;
    }

    fclose(fp);
    printf("\n\n\nEnter any key go back to Receptionist Section: ");
    if(getch())
        Receptionist_Section();
}
//End of this project
