// Student ID and Names:
// 1211306353 YII CHIN JOO
// 1211311786 NG JING WEI
// 1211100633 NUR MAISARAH BINTI MOHAMMAD SAIFROL
// 1211103698 UMMI SYAHIRAH BINTI MUHAMMAD ROZAIDEE @ ROZI
// 1211103754 Noor Alia Alisa Binti Kamal

// Assignment Title: Library Management System
// Program Description: This program allows students to view the library management system information and system print the qualified scholarship.

#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


//ADMIN
class admin{
	private:
		const string passwd;


	public:
		//variables
		char bookname[100],auname[50],bookid[20],id[20];
        int quantity,section,price;
       admin()
       {
           strcpy(bookname,"NO Book Name");
           //to specity can work if the input is string
           strcpy(auname,"No Author Name");
           strcpy(bookid,"No Book ID");
           strcpy(id,"Student ID");
           quantity=0;
           section=0;
           price=0;
       }
		//functions
		void addBook();
		void deleteBook();
		void updateBook();
		void searchBook(int);
		void viewBooks(int);
		void admin_run();
		void show(int);
		void login(string password);
		int branch(int);
		void issueBook();
		void viewIssueBook();
		void showIssue();
		void reissueBook();
        void student();
        void BorrowBook();
        void ReturnBook();
};

void admin :: BorrowBook(){

    admin al;
	char enterid[100];
        int sect, i, cont;
        char choice;
	do{
             system("cls");
                    sect=branch(2);
                    //choose one branch
                    ifstream borrowbook1("Booksdata.txt",ios::binary);
                    //read data
                    if(!borrowbook1)
                        //if not found the file
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        student();
                    }
                     borrowbook1.close();
                    //close the file
                     system("cls");
                     //clear screen
                    fflush(stdin);
                    //clear the output buffer of the stream
                       cout<<"Do you want borrow which book? \n";
                        cout<<"Please enter BOOKID -> ";

                        while(enterid == ""){
                            fflush(stdin);
                            //clear the output buffer of the stream
                            cout<<"Invalid, please enter BOOKID -> ";
                            cin.getline(enterid,100);
                            // read unformatted string
                        }
                                cin.getline(enterid,100);
                                system("cls");
                                fstream bobook("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                //reading or writing on the file system.
                                //ios::in allows input , ios::out allows output
                                //ios::binary  perform input and output in binary mode in txt file
                                //ios::ate sets the stream's position indicator to the end of the stream on opening."
                                //ios::app set the stream's position indicator to the end of the stream before each output operation.
                                bobook.seekg(0);
                                //seek to an arbitrary position in a file
                                bobook.read((char*)this,sizeof(*this));
                                //reads the data from the file

                                while(!bobook.eof())
                                    {
                                        for(i=0;sect==section&&bookid[i]!='\0'&&enterid[i]!='\0'&&enterid[i]==bookid[i];i++);
                                        //if enterbranch = branch and bookid != null character and input bookid != null character and input bookid == bookid
                                        if(bookid[i]=='\0'&&enterid[i]=='\0')
                                            //if bookid id == null character and enter id == null charater
                                            {
                                                cont++;
                                                int i;
                                                fflush(stdin);
                                                show(i);
                                                if (quantity >0 ){
                                                quantity --;
                                                }
                                                else {
                                                    cout << "The book quantity is already 0, cannot borrow this book";
                                                    cout<<"\n\t\tPress any key to continue.....";
                                                    getch();
                                                    system("cls");
                                                    student();
                                                }


                                            bobook.seekp(bobook.tellp()-sizeof(*this));
                                            //navigate the pointer to the desired location
                                            bobook.write((char*)this,sizeof(*this));
                                            //write the data from the file
                                                break;
                                            }

                                        bobook.read((char*)this,sizeof(*this));
                                         //print the data to the files
                                    }
                                bobook.close();
                                //close the file

                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            student();
                        }
                        else{
                            cout<<"\n\t\tBook Borrow Successful.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            student();
                        }

	}while(choice == 'y');

}

void admin :: ReturnBook(){

    admin al;
	char enterid[100];
    int sect, i, cont;
    char choice;
        do{
             system("cls");
                    sect=branch(2);
                    //choose one branch
                    ifstream returnbook1("Booksdata.txt",ios::binary);
                    //read data
                    if(!returnbook1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        student();
                    }
                     returnbook1.close();
                     system("cls");
                     fflush(stdin);
                       cout<<"Which book do you want borrow? \n";
                        cout<<"Please enter BOOKID -> ";
                        cin.getline(enterid,100);
                        while(enterid == ""){
                            fflush(stdin);
                            cout<<"Invalid, please enter BOOKID -> ";
                            cin.getline(enterid,100);
                        }

                                system("cls");
                                fstream rebook("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                //reading or writing on the file system.
                                rebook.seekg(0);
                                //seek to an arbitrary position in a file
                                rebook.read((char*)this,sizeof(*this));
                                //reads the data from the file

                                while(!rebook.eof())
                                    {
                                        for(i=0;sect==section&&bookid[i]!='\0'&&enterid[i]!='\0'&&enterid[i]==bookid[i];i++);
                                        if(bookid[i]=='\0'&&enterid[i]=='\0')
                                            {
                                                cont++;
                                                int i;
                                                fflush(stdin);
                                                show(i);
                                                quantity ++;


                                            rebook.seekp(rebook.tellp()-sizeof(*this));
                                            //navigate the pointer to the desired location
                                            rebook.write((char*)this,sizeof(*this));
                                            //write the data from the file
                                                break;
                                            }

                                        rebook.read((char*)this,sizeof(*this));
                                         //print the data to the files
                                    }

                                rebook.close();
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            student();
                        }
                        else{
                            cout<<"\n\t\tBook Return Successful.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            student();
                        }
	}while(choice == 'y');

}

int admin::branch(int x)
  {
      admin al;
      int i;
      cout<<">>Please Choose one Section :-\n";
      cout<<"\n1.COMPUTER\n\n2.ELECTRICAL\n\n3.CIVIL\n\n4.ELECTRONICS\n\n5.MECHANICAL\n\n6.ARCHITECTURAL\n\n7.Go to menu\n";
      cout<<"\nEnter your choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: if(x==1){
                    system("cls");
                  student();
          }
                  else
                    admin_run();
                    break;
          default : cout << "Invalid option!" << endl;
                    getch();
                    system("cls");
                    branch(x);
        }
        return 0;
  }

void admin :: addBook() {
    admin al;
    char choice;


    do{
        system("cls");
        //To choose which branch to add book to.
        section=branch(2);
        system("cls");
	     int i;

        fflush(stdin);
        //flushes any buffered data to the respective device
        //Buffered data is the temporary or application specific data stored in the physical memory of the computer until a certain time
        cout<<"\nEnter the book details :-\n";
        cout<<"\nEnter Book's Name : ";
        cin.getline(bookname,100);
        //if book not = 0
        for(i=0;bookname[i]!='\0';i++)
        {
            //bookname must a until z
            if(bookname[i]>='a'&&bookname[i]<='z')
            bookname[i]-=32;
        }
        cout<<"\nEnter Author's Name : ";
        cin.getline(auname,50);

        cout<<"\nEnter Book's ID : ";
        cin.getline(bookid,20);

        cout<<"\nEnter Book's Price : ";

        while(!(cin>>price)){
        cout << "\t\tERROR: a number must be entered "<<endl;
        cout<<"\nEnter Book's Price : ";
        cin.clear();
        cin.ignore(123, '\n');
        }
            while(price < 0){
                cout<<"\n\t\tInvalid Price, please reenter the valid price : ";
                cin>>price;
            }

        cout<<"\nEnter Book's Quantity : ";

            while(!(cin>>quantity)){
        cout << "\tERROR: a number must be entered "<<endl;
        cout<<"\tEnter Book's Quantity : ";
        cin.clear();
        cin.ignore(123, '\n');
        }
            while (quantity < 0)
            {
                cout<<"\n\t\tInvalid Quantity, please reenter the valid quantity : ";
                cin>>quantity;
            }

        fstream book("Booksdata.txt",ios::app|ios::binary);
	    //reading or writing on the file system
          book.write((char*)this,sizeof(*this));
          //write the data from the file
          book.close();
        cout<<"\n\t\tBook added Successfully.\n";


	    cout << endl;

	}while(choice == 'y');
}

void admin :: deleteBook() {
 char ch, bid[20];
    int i=0,sect,cont=0;
    char choice;
     do{
            system("cls");
            sect=branch(2);
            system("cls");
            fflush(stdin);
                    cout<<"\nEnter Book's ID that you would like to delete : ";
                        cin.getline(bid,20);
                                ofstream outf("temp.txt",ios::out|ios::binary);
                                //create an output file
                                ifstream intf("Booksdata.txt",ios::in|ios::binary);

                                while(!intf.eof())
                                    {
                                        intf.read((char*)this,sizeof(*this));
                                        for(i=0;sect==section&&bookid[i]!='\0'&&bid[i]!='\0'&&bid[i]==bookid[i];i++);
                                        if(bookid[i]=='\0'&&bid[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));

                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");

                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            deleteBook();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

	}while(choice == 'y');
}



void admin :: updateBook(){
    admin al;
	char choice;
    char ch,bid[100];
    int i=0,sect,cont=0;

    do{
             system("cls");
                    sect=branch(2);
                    ifstream upbook1("Booksdata.txt",ios::binary);
                    //read data
                    if(!upbook1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        admin_run();
                    }
                     upbook1.close();
                        system("cls");
                        fflush(stdin);
                        cout<<"\nEnter Book's ID for update: ";
                                cin.getline(bid,100);
                                system("cls");
                                fstream upbook("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                //reading or writing on the file system.
                                upbook.seekg(0);
                                //seek to an arbitrary position in a file
                                upbook.read((char*)this,sizeof(*this));
                                //reads the data from the file

                                while(!upbook.eof())
                                    {
                                        for(i=0;sect==section&&bookid[i]!='\0'&&bid[i]!='\0'&&bid[i]==bookid[i];i++);
                                        if(bookid[i]=='\0'&&bid[i]=='\0')
                                            {
                                                cont++;
                                                int i;
                                                fflush(stdin);
                                                cout<<"\nEnter the details :-\n";
                                                cout<<"\nEnter Book's Name : ";
                                                cin.getline(bookname,100);
                                        for(i=0;bookname[i]!='\0';i++)
                                        {
                                            if(bookname[i]>='a'&&bookname[i]<='z')
                                            bookname[i]-=32;
                                    }
                                        cout<<"\nEnter Author's Name : ";
                                        cin.getline(auname,50);
                                        cout<<"\nEnter Book's ID : ";
                                        cin.getline(bookid,20);
                                        cout<<"\nEnter Book's Price : ";

                                        while(!(cin>>price)){
                                            cout << "\t\tERROR: a number must be entered "<<endl;
                                            cout<<"Enter Book's Quantity : ";
                                            cin.clear();
                                            cin.ignore(123, '\n');
                                        }
                                        while (price < 0){
                                            cout<<"\n\t\tInvalid Quantity, please reenter the valid quantity : ";
                                            cin>>price;
                                        }
                                        cout<<"\nEnter Book's Quantity : ";

                                        while(!(cin>>quantity)){
                                            cout << "\t\tERROR: a number must be entered "<<endl;
                                            cout<<"Enter Book's Quantity : ";
                                            cin.clear();
                                            cin.ignore(123, '\n');
                                        }
                                        while (quantity < 0){
                                            cout<<"\n\t\tInvalid Quantity, please reenter the valid quantity : ";
                                            cin>>quantity;
                                        }

                                            upbook.seekp(upbook.tellp()-sizeof(*this));
                                            //navigate the pointer to the desired location
                                            upbook.write((char*)this,sizeof(*this));
                                            //write the data from the file
                                                break;
                                            }

                                        upbook.read((char*)this,sizeof(*this));
                                         //print the data to the files
                                    }

                                upbook.close();
                                //close the file
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            updateBook();
                        }
                        else{
                            cout<<"\n\t\tUpdate Successful.\n";
                        }
	}while(choice == 'y');

}

void admin :: searchBook(int x){
	int i,sect,cont=0;
      char ch[100];
      system("cls");
      sect=branch(x);

	ifstream sbook("Booksdata.txt",ios::binary);
	//read file
        if(!sbook)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            admin_run();
        }
    system("cls");
    fflush(stdin);

      sbook.read((char*)this,sizeof(*this));
       //reads the data from the file
     cout<<"\nEnter Book's ID that you would like to seacrh : ";
     cin.getline(ch,100);

          while(!sbook.eof())
          {

             for(i=0; sect==section && quantity !=0 && bookid[i]!='\0'&&ch[i]!='\0'&& ch[i]==bookid[i]; i++);
              //if branch is open and quantity != 0 and book id != 0 and the entered book id != 0 and entered book id = book id.
              if(bookid[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found \n";
                            cout<<"__________________________________________________\n";
                            //show the book
                            show(x);
                            cont++;
                            break;
                }
               sbook.read((char*)this,sizeof(*this));
               //reads the data from the file
            }
          sbook.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available / Not found \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
        student();
    else
        admin_run();
}

void admin :: viewBooks(int i){
	int sect,r=0;
                system("cls");
                sect=branch(i);
                system("cls");
                ifstream vbook("Booksdata.txt",ios::binary);
                //read file
                if(!vbook)
                    cout<<"\n\t\tFile Not Found.";
                else
                {    cout << "-----------------------------------" << endl;
                     cout << "           All Book List           " << endl;
                     cout << "-----------------------------------" << endl;
                    vbook.read((char*)this,sizeof(*this));
                    //reads the data from the file
                while(!vbook.eof())
                {
                    //sect = section
                    if(sect==section)
                    {

                        if(quantity==0 && i==1)
                        {
                            cout<<"Not available";
                        }
                        else
                            {
                                //number of book
                                r++;
                                cout << "_______________ "<<r<<". ________________ \n";
                                show(i);

                            }
                    }
                    vbook.read((char*)this,sizeof(*this));
                    //reads the data from the file
                }
                vbook.close();
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    admin_run();
    }

void admin :: issueBook()
{
    int b,i,j;
    system("cls");
    fflush(stdin);
    //Clearing input buffer
    cout<<"\n_______ Issue Book _______\n";
    cout<<"\nEnter Book Name : ";
    cin.getline(bookname,50);   //read a line of text from user
    cout<<"\nEnter Book ID : ";
    cin.getline(bookid,10);
    cout<<"\nEnter Student Name : ";
    cin.getline(auname,100);
    cout<<"\nEnter Student ID : ";
    cin.getline(id,20);

        ofstream outf("student.txt",ios::binary|ios::app);
        //output file streams // create ofstream object named as outf
        //ios::binary  perform input and output in binary mode in txt file
        //ios::app set the stream's position indicator to the end of the stream before each output operation.
        outf.write((char*)this,sizeof(*this));
        //write a block of binary data
        //[char*] is a pointer to a char.
        //[this] is a "pointer" to the current class, of whatever type.
        //[*this] gets the value of the pointer.
        outf.close();
        //close the outf file
        cout<<"\n\n\t Issue book successfully.\n";
}

void admin :: viewIssueBook()
{
    int i;
    ifstream vIssue("student.txt",ios::binary);
     //input file streams // create ifstream object named as vIssue
     //ios::binary  perform input in binary mode in student.txt file
    system("cls");
    fflush(stdin);
    //Clearing input buffer
    cout<<"\n\t\t ======= View Issue Book =======\n";
    vIssue.read((char*)this,sizeof(*this));
    //read a block of binary data
    i=0;
    while(!vIssue.eof()){  //as long as eof() is zero so the end of the file is not reached
    i++;
    cout<<endl;
    cout<<"\n\t\t========== "<<i<<". ========== \n";
    showIssue();
    //go to showIssue() function
    vIssue.read((char*)this,sizeof(*this));
    //read a block of binary data
    }
                vIssue.close();
                //close the outf file
                cout<<endl;
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                //requests for a single character, press any key in your keyboard
                admin_run();
}

void admin :: showIssue()
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook ID : "<<bookid<<endl;
    cout<<"\n\t\tStudent Name : "<<auname<<endl;
    cout<<"\n\t\tStudent ID : "<<id;
}

void admin :: reissueBook()
{
    char s[50],b[20];
    int i,j;
    system("cls");

    cout<<"\n_______ Reissue Book _______'\n";
    cout<<"\nEnter Book ID : ";
    cin.getline(b,20);
    cout<<"\n\nEnter Student ID : ";
    cin.getline(s,20);

    ofstream outfile("temp.txt",ios::app|ios::binary);
    ifstream rBook("student.txt",ios::binary);
    rBook.read((char*)this,sizeof(*this));
    //reading from a binary file
    while(!rBook.eof())
        {
            for(i=0;bookid[i]!='\0'&&b[i]!='\0'&&b[i]==bookid[i];i++);
            //bookid != null character and enter bookid != null charater and bookid  == enter bookid
            for(j=0;id[j]!='\0'&&s[j]!='\0'&&s[j]==id[j];j++);
            //bookid != null character and enter bookid != null charater and bookid  == enter bookid
            if(bookid[i]=='\0'&&id[j]=='\0'&&s[j]=='\0'&&b[i]=='\0')

                {
                    rBook.read((char*)this,sizeof(*this));
                    cout<<"\n\nReissue book successfully.\n";
                }
            else
                {
                    outfile.write((char*)this,sizeof(*this));
                    rBook.read((char*)this,sizeof(*this));
                }
        }
         rBook.close();
         outfile.close();

         remove("student.txt");
         rename("temp.txt","student.txt");
}


void admin::show(int i)
{
    cout<<"\nBook Name : "<<bookname<<endl;
    cout<<"\nBook's Author Name : "<<auname<<endl;
    cout<<"\nBook's ID : "<<bookid<<endl;
    if(i==2)
    {
        cout<<"\nBook's Price : "<<price<<endl;
        cout<<"\nBook's Quantity : "<<quantity<<endl;
    }
}

void admin :: admin_run() {

	admin al;

	int option;
    char choice;

    system("CLS");

    do{
	    cout << "-----------------------------------" << endl;
	    cout << "       ADMINISTRATION MENU         " << endl;
	    cout << "-----------------------------------" << endl;

	    cout << "What would you like to do.." << endl;
	    cout << "1. Add books" << endl;
	    cout << "2. Delete books" << endl;
	    cout << "3. Edit books" << endl;
	    cout << "4. Search books" << endl;
	    cout << "5. View all books" << endl;
	    cout << "6. Issue books" << endl;
	    cout << "7. View Issue books"<< endl;
	    cout << "8. Reissue books"<< endl;
	    cout << "9. Logout"<< endl<< endl;
	    cout << "Enter choice: ";
	    cin >> option;
	    cin.clear();
	    //used to get the maximum finite value representable by the numeric type T
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	    cout << endl;

	    switch(option){
	    	case 1:
	    		al.addBook();
	    		break;
	    	case 2:
	    		al.deleteBook();
	    		break;
	    	case 3:
	    		al.updateBook();
	    		break;
	    	case 4:
	    		al.searchBook(2);
	    		break;
	    	case 5:
				al.viewBooks(2);
	    		break;
	    	case 6:
	    		al.issueBook();
	    		break;
            case 7:
	    		al.viewIssueBook();
	    		break;
            case 8:
	    		al.reissueBook();
	    		break;
            case 9:
                exit(0);
	    		break;
	    	default:
	    		cout << "Invalid option!" << endl;
		}

	    cout << endl << "Would you like to continue to view the ADMIN MENU? (Y/N):";
	    cin >> choice;

		cout << endl;

	    choice = tolower(choice);

	    system("CLS");

    }while(choice == 'y');
}

void admin :: login(string passwd) {
    admin a1;
	passwd="123";
	string userpass;

    cout << "\nEnter password to view ADMIN MENU: ";
    cin >> userpass;

    if(userpass == passwd){

        a1.admin_run();
	}

	else{
        cout << "Invalid password!" << endl;

        //if fail for 3 times then will quit the entire program
        for(int i=0; i<2; i++){
            cout << "Re-enter password: ";
            cin >> userpass;
            if(userpass == passwd){
                a1.admin_run();
            }
        }
        exit(0);
	}
}

void admin :: student()
{
    admin al;
    int i;
    char choice;

        cout << "------------------------------" << endl;
	    cout << "         Student MENU         " << endl;
	    cout << "------------------------------" << endl;
        cout << "What would you like to do.."<< endl;
        cout<<"\n1. View BookList\n2. Search for a Book\n3. Borrow Book\n4. Return Book \n5. Close Application\n";
        cout<<"\nEnter your choice : ";
        cin>>i;
            if(i==1)
            {
                viewBooks(1);
            }

            else if(i==2)
            {
                searchBook(1);
            }
            else if(i==3){
                al.BorrowBook();
            }
            else if (i ==4){
                al.ReturnBook();
            }
            else if(i==5)
                exit(0);
            else
            {
                cout<<"\nInvalid Option. Please enter correct option ";
                getch();
                system("cls");
                student();
            }
}


//Main menu
int run() {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	int choice2;
	string password;

	cout << "---------- DEAR USER, WELCOME TO LIBRARY MANAGEMENT SYSTEM ----------" << endl;
	cout << "_____________________________________________________________________" << endl << endl;
	cout << "1. Student" << endl;
	cout << "2. Administrator" << endl;
	cout << "3. Exit" << endl;
	cout << "Choose one to continue: ";
	cin >> choice2;



	if(choice2==1) {
        system("cls");
        admin al;
		al.student();
	}
	else if(choice2==2) {
		admin a1;
		a1.login(password);
	}
	else if(choice2==3)
		exit(0);
	else
	cout << "Invalid input" << endl;

	return 0;
}

	int main() {
    admin al;
	char ans;

	do {
		system("CLS");

		run();

		cout << "\nDo you want to go back to MAIN MENU?: ";
		cin >> ans;

		ans = tolower(ans); // lower case
	}while(ans=='y');

	cout << endl << endl << "Thanks for using our system!" ; //if user input n

	return 0;
    }
