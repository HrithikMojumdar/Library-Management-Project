// library.c
// Library Management Application
// Created By Mozammel Hoshen on 7/3/19
//Copyright @ Python's Group . All rights reserved

#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>



//-----------------------------Main Interface functions-----------------------------------------------------
int main()
{
    system("color F1");
    system("cls");
    SetConsoleTitle("Library Management Project By Python's Team v1.0");
    body();
    gotoxy(20,10);printf("1. Login");
    gotoxy(20,12);printf("2. User Mode");
    gotoxy(20,14);printf("3. Developer Info");
    gotoxy(20,16);
    printf("Enter Your Choise:");
    getch();
    switch(getch())
    {
        case '1':
            Password();
            break;
        case '2':
            usermode();
            break;
        case '3':
            developer();
            break;
        default :
            gotoxy(20,17);
            printf("Wrong Input! Please Try Again");
            getch();
            main();
    }

    return 0;

}

//-----------------------------Cordination Function-----------------------------------------------------

FILE *fp,*ft,*fs;
COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

 // Function for show Developer Info
int developer()
{
    system("cls");
    body();
    gotoxy(20,6);printf("Design and Developed by....");
    gotoxy(25,8);printf("\xB2\xB2\xB2\xB2\xB2   Mozammel Hoshen Chowdhury");
    gotoxy(25,10);printf("\xB2\xB2\xB2\xB2\xB2   Fahim Ahmed");
    gotoxy(25,12);printf("\xB2\xB2\xB2\xB2\xB2   Md. Tanbir Hasan");
    gotoxy(25,14);printf("\xB2\xB2\xB2\xB2\xB2   Syed Mominul Salehin");
    gotoxy(20,20);printf("Computer Sceince And Engineering Dept. DIU");
    getch(); main();
}
int mainmenu()
{

    system("cls");
    body();
    int i;
    gotoxy(30,6);
    printf("DASHBOARD");
    gotoxy(30,8);
    printf(" 1. Insert Books Details  ");
    gotoxy(30,10);
    printf(" 2. Edit Book's Details");
    gotoxy(30,12);
    printf(" 3. Search Books");
    gotoxy(30,14);
    printf(" 4. Show Book list");
    gotoxy(30,16);
    printf(" 5. Remove Books");
    gotoxy(30,18);
    printf(" 6. Log Out");

    gotoxy(30,24);
    t();
    gotoxy(30,25);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
            addbooks();
            break;
        case '2':
            editbooks();
            break;
        case '3':
            searchbooks();
            break;
        case '4':
            viewbooks();
            break;
        case '5':
            deletebooks();
            break;
        case '6':
            finish();
            break;
        default:
        {
            gotoxy(30,26);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
                mainmenu();
        }

    }
}
int usermode()
{
    system("cls");
    body();
    gotoxy(20,6);
    printf("1. Search Book");
    gotoxy(20,8);
    printf("2. View Book List");
    gotoxy(20,10);
    printf("3. Exit");

    gotoxy(20,12);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
            searchbook();
            break;
        case '2':
            viewbook();
            break;
        case '3':
            main();
        default:
        {
            gotoxy(20,26);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
                usermode();

        }


    }

}




//------------------------------------------------------Password Area--------------------------------------------
char password[10]={"python"};

int Password()
{
    system("cls");
    body();
    char ch,pass[10];
    int i=0,j;
    gotoxy(15,7);
    printf("Enter Password:");

 while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8){
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {

        gotoxy(15,9);
        printf("Correct Password");
        gotoxy(17,10);
        printf("Press Any Key To Continue");
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(15,16);
        printf("Password Wrong ! Please Try Again");
        getch();
        Password();
    }
}



char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
int  getdata();
int  checkid(int);
int t(void);
void loaderanim();
int s;
char findbook;

struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
};
struct books a;


int addbooks()    //funtion that add books
{
    system("cls");
    body();
    int i;
    gotoxy(30,5);
    printf("SELECT CATEGOIES");
    gotoxy(30,7);
    printf(" 1. Computer");
    gotoxy(30,9);
    printf(" 2. Electronics");
    gotoxy(30,11);
    printf(" 3. Electrical");
    gotoxy(30,13);
    printf(" 4. Civil");
    gotoxy(30,15);
    printf(" 5. Mechanical");
    gotoxy(30,17);
    printf(" 6. Architecture");
    gotoxy(30,19);
    printf(" 7. Back to main menu");

    gotoxy(30,22);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)

    mainmenu() ;
    system("cls");
    fp=fopen("record.dat","ab+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else
            system("cls");

        addbooks();
    }
}
int deletebooks()    //function that delete items from file fp
{
    system("cls");
    body();

    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        body();
        gotoxy(10,5);
        printf("Enter the Book ID to  delete:");
        scanf("%d",&d);
        fp=fopen("record.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {

                gotoxy(10,7);
                printf("The book record is available");
                gotoxy(10,8);
                printf("Book name is %s",a.name);
                gotoxy(10,9);
                printf("Self No. is %d",a.rackno);
                findbook='t';
            }
        }
        if(findbook!='t')
        {
            gotoxy(10,10);
            printf("No record is found modify the search");
            if(getch())
                mainmenu();
        }
        if(findbook=='t' )
        {
            gotoxy(10,9);
            printf("Do you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("record.dat");
                rename("test.dat","record.dat"); //copy all item from temporary file to fp except that
                fp=fopen("record.dat","rb+");    //we want to delete
                if(findbook=='t')
                {
                    gotoxy(10,10);
                    printf("The record is sucessfully deleted");
                    gotoxy(10,11);
                    printf("Delete another record?(Y/N)");
                }
            }
            else
                mainmenu();
            fflush(stdin);
            another=getch();
        }
    }
    gotoxy(10,15);
    mainmenu();
}
int searchbooks()
{
    system("cls");
    body();
    int d;
    gotoxy(20,8);
    printf("Search Books");
    gotoxy(20,10);
    printf(" 1. Press 1 To Search Book\n");
    fp=fopen("record.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
        case '1':
        {
            system("cls");
            body();
            gotoxy(20,6);
            printf("Enter the book tracking ID:");
            scanf("%d",&d);
            gotoxy(20,8);
            printf("Searching........");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(a.id==d)
                {
                    Sleep(2);
                    gotoxy(20,7);
                    printf("The Book is available");
                    gotoxy(20,9);
                    printf(" ID:%d",a.id);gotoxy(47,9);
                    gotoxy(20,10);
                    printf(" Name:%s",a.name);gotoxy(47,10);
                    gotoxy(20,11);
                    printf(" Author:%s ",a.Author);gotoxy(47,11);
                    gotoxy(20,12);
                    printf(" Qantity:%d ",a.quantity);gotoxy(47,12);
                    gotoxy(20,13);
                    printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
                    gotoxy(20,14);
                    printf(" Self No:%d ",a.rackno);gotoxy(47,14);

                    findbook='t';
                }

            }
            if(findbook!='t')  //checks whether conditiion enters inside loop or not
            {

                gotoxy(22,9);printf("\aSorry Book Isnot Available");
            }
            gotoxy(20,17);
            printf("Want To search Another ?(Y/N)");
            if(getch()=='y')
                searchbooks();
            else
                mainmenu();
            break;
        }
        default :
            getch();
            searchbooks();
    }
    fclose(fp);
}


int searchbook()
{
    system("cls");
    body();
    int d;
    gotoxy(20,8);
    printf("Search Books");
    gotoxy(20,10);
    printf(" 1. Press 1 To Search Book\n");
    fp=fopen("record.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
        case '1':
        {
            system("cls");
            body();
            gotoxy(20,6);
            printf("Enter the book tracking ID:");
            scanf("%d",&d);
            gotoxy(20,8);
            printf("Searching........");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(a.id==d)
                {
                    Sleep(2);
                    gotoxy(20,7);
                    printf("The Book is available");
                    gotoxy(20,9);
                    printf(" ID:%d",a.id);gotoxy(47,9);
                    gotoxy(20,10);
                    printf(" Name:%s",a.name);gotoxy(47,10);
                    gotoxy(20,11);
                    printf(" Author:%s ",a.Author);gotoxy(47,11);
                    gotoxy(20,12);
                    printf(" Qantity:%d ",a.quantity);gotoxy(47,12);
                    gotoxy(20,13);
                    printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
                    gotoxy(20,14);
                    printf(" Self No:%d ",a.rackno);gotoxy(47,14);

                    findbook='t';
                }

            }
            if(findbook!='t')  //checks whether conditiion enters inside loop or not
            {

                gotoxy(22,9);printf("\aSorry Book Isnot Available");
            }
            gotoxy(20,17);
            printf("Want To search Another ?(Y/N)");
            if(getch()=='y')
                searchbook();
            else
                usermode();
            break;
        }
        default :
            getch();
            searchbook();
    }
    fclose(fp);
}



int viewbooks()
{
    int i=0,j;
    system("cls");
    body();
    gotoxy(2,6);
    printf(" CATEGORY     BOOK ID    BOOK NAME     AUTHOR NAME       BOOK AMOUNT     BOOK PRICE     Self NO ");
    j=8;
    fp=fopen("record.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(20,j);
        printf("%d",a.id);
        gotoxy(28,j);
        printf("%s",a.name);
        gotoxy(42,j);
        printf("%s",a.Author);
        gotoxy(62,j);
        printf("%d",a.quantity);
        gotoxy(75,j);
        printf("%.2f",a.Price);
        gotoxy(95,j);
        printf("%d",a.rackno);
        printf("\n\n");
        j++;
        i=i+a.quantity;
    }
    gotoxy(3,25);
    printf("Total Books =%d",i);
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}
int editbooks()  //edit information about book
{
    system("cls");
    body();
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("Edit Books");
    char another='y';
    while(another=='y')
    {
        system("cls");
        body();
        gotoxy(15,6);
        printf("Enter Book Trackig No:");
        scanf("%d",&d);
        fp=fopen("record.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(15,7);
                printf("The book is availble");
                gotoxy(15,8);
                printf("Tracking No:%d",a.id);
                gotoxy(15,9);
                printf("Enter new name:");scanf("%s",a.name);
                gotoxy(15,10);
                printf("Enter new Author:");scanf("%s",a.Author);
                gotoxy(15,11);
                printf("Enter new quantity:");scanf("%d",&a.quantity);
                gotoxy(15,12);
                printf("Enter new price:");scanf("%f",&a.Price);
                gotoxy(15,13);
                printf("Enter new rackno:");scanf("%d",&a.rackno);
                gotoxy(15,14);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    returnfunc();
}



int viewbook()  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    body();
    gotoxy(2,6);
    printf(" CATEGORY     BOOK ID    BOOK NAME     AUTHOR NAME       BOOK AMOUNT     BOOK PRICE     Self NO ");
    j=8;
    fp=fopen("record.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(20,j);
        printf("%d",a.id);
        gotoxy(28,j);
        printf("%s",a.name);
        gotoxy(42,j);
        printf("%s",a.Author);
        gotoxy(62,j);
        printf("%d",a.quantity);
        gotoxy(75,j);
        printf("%.2f",a.Price);
        gotoxy(95,j);
        printf("%d",a.rackno);
        printf("\n\n");
        j++;
        i=i+a.quantity;
    }
    gotoxy(3,25);
    printf("Total Books =%d",i);
    fclose(fp);
    gotoxy(35,25);
    spacefunc();
}


int spacefunc()
{
    {

        printf("Press Space To Return Main Menu");
    }
a:
    if(getch()==32) //allow only use of enter
        usermode();
    else
        goto a;
}



int returnfunc()
{
    {

        printf("Press Enter To Return Main Menu");
    }
a:
    if(getch()==13) //allow only use of enter
        mainmenu();
    else
        goto a;
}
int getdata()
{
    body();
    int t;
    gotoxy(20,5);printf("Enter the Information Below");
    gotoxy(21,7);
    printf("Category:");
    gotoxy(31,7);
    printf("%s",catagories[s-1]);
    gotoxy(21,8);
    printf("Book Tracking No:\t");
    gotoxy(40,8);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe book tracking no is already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(21,9);
    printf("Book Name:");gotoxy(33,9);
    scanf("%s",a.name);
    gotoxy(21,10);
    printf("Author:");gotoxy(30,10);
    scanf("%s",a.Author);
    gotoxy(21,11);
    printf("Quantity:");gotoxy(31,11);
    scanf("%d",&a.quantity);
    gotoxy(21,12);
    printf("Price:");gotoxy(28,12);
    scanf("%f",&a.Price);
    gotoxy(21,13);
    printf("Rack No:");gotoxy(30,13);
    scanf("%d",&a.rackno);
    return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));

    return 0 ;
}



int body(){
    gotoxy(40,1); printf(" LIBRARY MANAGEMENT APPLICATION ");
    gotoxy(50,2);printf("CSE, DIU");
    gotoxy(18,3);printf("______________________________________________________________________");

 }


 int finish(){          // function to Exit Message
    system("cls");
    body();
    gotoxy(16,11);
    printf("Are you sure wanna Exit (Y/N): ");
    getch();
    if(getch() == 'n' || getch() == 'N'){
    system("cls");
    body();
    main();
    }
    else{
    system("cls");
    body();
    gotoxy(15,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(21,12);printf("Department of Computer Sceince & Enginnering");
    gotoxy(21,21);printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
    }
}

