
#include<bits/stdc++.h>
using namespace std;
#include"classS.h"

fstream fp;
book bk;
income total, amount;
void write_book()
{
    system("cls||@clr");
    int more_or_main;
    fp.open("book.txt",ios::out|ios::app);
    do
    {
        bk.get_book_details();
        fp.write((char*)&bk,sizeof(book));

        cout<<"\nPress 1 to add more books.";
        cout<<"\nPress 2 to return to main menu.\n";
        cout<<"Enter: ";
        cin>>more_or_main;
    }
    while(more_or_main == 1);
    fp.close();
}

void display_a_book(char n[])
{
    system("cls||@clr");
    cout<<"\nBOOK DETAILS\n";
    int check=0;
    fp.open("book.txt",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.getbooknumber(),n)==0)
        {
            bk.show_book();
            check=1;
        }
    }
    fp.close();
    if(check==0)
    {
        cout<<"\n\nBook does not exist";
    }
    getchar();
}

void modify_book()
{
    system("cls||@clr");
    char n[20];
    int found=0;
    cout<<"\n\n\tMODIFY BOOK";
    cout<<"\n\n\tEnter The book number: ";
    cin>>n;
    fp.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmp(bk.getbooknumber(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
    fp.close();
    if(found==0)
    {
        cout<<"\n\n Record Not Found ";
    }
    getchar();
}

void delete_book()
{
    system("cls||@clr");
    char n[20];
    int flag=0;
    cout<<"\n\n\n\tDELETE BOOK";
    cout<<"\n\nEnter The Book's number You Want To Delete: ";
    cin>>n;
    fp.open("book.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.getbooknumber(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
        else{
            flag=1;
            total = total + bk.price;
            amount.in +=total.in;
        }
    }
    fp2.close();
    fp.close();
    remove("book.txt");
    rename("Temp.txt","book.txt");
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
    else
        cout<<"\n\nRecord not found";
    getchar();
}

void display_allb()
{
    system("cls||@clr");
    fp.open("book.txt",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getchar();
        return;
    }
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"===========================================================================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(30)<<"Author"<<setw(30)<<"Price"<<setw(30)<<"Copies"<<endl;
    cout<<"===========================================================================================================================\n";
    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getchar();
}
int main()
{
    int option = 0;
    while(true)
    {
        cout<<"\n\t\tPress 1 to TO ADD A BOOK";
        cout<<"\n\t\tPress 2 to SHOW ALL BOOKS";
        cout<<"\n\t\tPress 3 to CHECK AVAILABILITY";
        cout<<"\n\t\tPress 4 to MODIFY BOOKS";
        cout<<"\n\t\tPress 5 to DELETE BOOKS";
        cout<<"\n\t\tPress 6 to show income";
        cout<<"\n\t\tPress 7 to Exit";
        cout<<"\n\t\t----------------------------------------\n";
        cout<<"\n\t\tOption: ";
        cin>>option;
        switch(option)
        {
        case 1:
            system("cls||@clr");
            write_book();
            break;
        case 2:
            system("cls||@clr");
            display_allb();
            break;
        case 3:
            char num[20];
            system("cls||@clr");
            cout<<"\n\n\tPlease Enter The book No. ";
            cin>>num;
            display_a_book(num);
            break;
        case 4:
            modify_book();
            break;
        case 5:
            delete_book();
            break;
        case 6:
            //cout<<total.in<<"\n";
            cout<<"Today\'s income :  "<<amount.in<<endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"\a";
        }
    }
    return 0;
}
