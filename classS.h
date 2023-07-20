class category
{
protected:
    char book_number[30];
    char book_name[50];
    char author_name[20];
    int num_copies;
public:
    category() : num_copies(0) {} //book_number(""),book_name(""),author_name(""),   //constructor
};
class book : public category
{
public:
    double price;
    void get_book_details()
    {
        cout<<"\nENTER DETAILS ABOUT BOOK U WANT TO PURCHASE\n";
        cout<<"\nEnter The Book Number: ";
        cin>>book_number;
        cout<<"\nEnter The Name of The Book: ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nEnter The Author's Name: ";
        cin.ignore();
        cin.getline(author_name,50);
        fflush(stdin);
        cout<<"\nEnter No. Of Copies : ";
        cin>>num_copies;
        cout<<"\nEnter the price : ";
        cin>> price;
    }

    void show_book()
    {
        cout<<"\nBook Number: "<<book_number;
        cout<<"\nBook Name: "<<book_name;
        cout<<"\nAuthor's Name: "<<author_name;
        cout<<"\nCopies : "<<num_copies;
        cout<<"\nprice : "<<price;
    }
    void modify_book()
    {
        cout<<"\nBook number : "<<book_number;
        cout<<"\nModify Book Name : ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nModify Author's Name: ";
        cin.ignore();
        cin.getline(author_name,50);
        fflush(stdin);
        cout<<"\nEnter No. Of Copies : ";
        cin>>num_copies;
        cout<<"\nEnter the price : ";
        cin>>price;
    }
    char* getbooknumber()
    {
        return book_number;
    }
    void report()
    {
        cout<<book_number<<setw(30)<<book_name<<setw(30)<<author_name<<setw(30)<<num_copies<<setw(30)<<price<<endl;
    }
};
class income
{
public:
    double in;
    income() : in(0.0){}
    income(double a) : in(a) {}
    income operator +(double l)
    {
        income r;
        r.in+=l;
        return r;
    }
};
