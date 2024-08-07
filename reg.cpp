#include<bits/stdc++.h>
using namespace std;

void login();
void registration();
void forget();

int main()
{
    int c;
    cout<<"\t\t\t_______________________________________\n\n\n";
    cout<<"\t\t\t       Welcome to the Login page        \n\n\n";
    cout<<"\n\n";
    cout<<"\t| Press 1 to Login            |"<<endl;
    cout<<"\t| Press 2 to Register         |"<<endl;
    cout<<"\t| Press 3 to Forgot Password  |"<<endl;
    cout<<"\t| Press 4 to Exit             |"<<endl;
    cout<<"\n\t\t\t Please enter your choice :";
    cin>>c;
    cout<<endl;

    switch(c)
    {
    case 1:
        login();
        break;

    case 2:
       registration();
       break;

    case 3:
        forget();
        break;

    case 4:
        cout<<"\t\t\t Thank You! \n\n";
        break;

    default:
        system("cls");
        cout<<"\t\t\t Please select from the options given above \n"<<endl;
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the user name and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1)
    {
       cout<<userId<<"\n Your Login is successful \n";
       main();
    }
    else
    {
       cout<<"\n Login Error \n Please Check Your User name and password\n ";
       main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Enter the user name : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();

}

void forget()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forget the password? No worries \n";
    cout<<"Press 1 to search your id by user name "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice :";
    cin>>option;

    switch(option)
    {
        case 1:
            {
      int count=0;
      string suserId, sId, spass;
      cout<<"\n\t\t\t Enter the user name which you remembered : ";
      cin>>suserId;

      ifstream f2("records.txt");
      while(f2>>sId>>spass)
      {
          if(sId==suserId)
          {
              count=1;
          }
      }
      f2.close();
      if(count==1)
      {
          cout<<"\n\n Your account is found! \n";
          cout<<"\n\n Your password is : "<<spass;
          main();
      }
      else
        {
        cout<<"\n\t Sorry! Your account is not found! \n";
        main();
        }
        break;
    }
        case 2:
            {
              main();
            }
        default:
            cout<<"\t\t\t Wrong Choice! Please try again "<<endl;
            forget();
    }
}
