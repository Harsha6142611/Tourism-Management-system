#include <iostream>
#include <string.h>
#include <fstream>
#include<stdbool.h>
#include<windows.h>
#define password 123456
using namespace std;
class visitor;
class driverdatabase
{
public:
    string driverfilename[30];
    friend ofstream & operator<<(ofstream &ofs,driverdatabase s);
    friend ifstream & operator>>(ifstream &ifs,driverdatabase &s);
};
ofstream & operator<<(ofstream &ofs,driverdatabase s)
{
    for(int i=0;i<30;i++)
        ofs<<s.driverfilename[i]<<endl;
    return ofs;
}
ifstream & operator>>(ifstream &ifs,driverdatabase &s)
{
    for(int i=0;i<30;i++)
        ifs>>s.driverfilename[i];
    return ifs;
}
void driverdt(string usr)
{
    driverdatabase dt;

}
class employee
{
  public:
    string usr, pass, name, dept="Driver", dob, mn;
    friend ofstream & operator<<(ofstream &ofs,employee s);
    friend ifstream & operator>>(ifstream &ifs,employee &s);
};
ofstream & operator<<(ofstream &ofs,employee s)
{
  ofs<<s.usr<<endl;
  ofs<<s.pass<<endl;
  ofs<<s.name<<endl;
  ofs<<s.dept<<endl;
  ofs<<s.dob<<endl;
  ofs<<s.mn<<endl;
  return ofs;
}
ifstream & operator>>(ifstream &ifs,employee &s)
{
  ifs>>s.usr;
  ifs>>s.pass;
  ifs>>s.name;
  ifs>>s.dept;
  ifs>>s.dob;
  ifs>>s.mn;
  return ifs;
}
class visitor
{
  public:
  string usr, pass, name, dob, mn;
  int bus_no;
  int no_of_seats_booked;
  int seats_booked[24];
  friend ofstream & operator<<(ofstream &ofs,visitor s);
  friend ifstream & operator>>(ifstream &ifs,visitor &s);
};
ofstream & operator<<(ofstream &ofs,visitor s)
{
  ofs<<s.usr<<endl;
  ofs<<s.pass<<endl;
  ofs<<s.name<<endl;
  ofs<<s.dob<<endl;
  ofs<<s.mn<<endl;
  ofs<<s.bus_no<<endl;
  ofs<<s.no_of_seats_booked<<endl;
  for(int i=0;i<24;i++)
  {
    ofs<<s.seats_booked[i]<<endl;
  }
  return ofs;
}
ifstream & operator>>(ifstream &ifs,visitor &s)
{
  ifs>>s.usr;
  ifs>>s.pass;
  ifs>>s.name;
  ifs>>s.dob;
  ifs>>s.mn;
  ifs>>s.bus_no;
  ifs>>s.no_of_seats_booked;
  for(int i=0;i<24;i++)
  {
    ifs>>s.seats_booked[i];
  }
  return ifs;
}
class bus
{
  public:
  string bus_number,driver_name,boarding_time,departure_time,from,to;
  int seats_full,vacant_seats;
  string bus_seats[24];
};
ofstream & operator<<(ofstream &ofs,bus s)
{
  ofs<<s.bus_number<<endl;
  ofs<<s.driver_name<<endl;
  ofs<<s.boarding_time<<endl;
  ofs<<s.departure_time<<endl;
  ofs<<s.from<<endl;
  ofs<<s.to<<endl;
  ofs<<s.seats_full<<endl;
  ofs<<s.vacant_seats<<endl;
  for(int i=0;i<24;i++)
  {
    ofs<<s.bus_seats[i]<<endl;
  }
  return ofs;
}
ifstream &operator>>(ifstream &ifs,bus &s)
{
  ifs>>s.bus_number;
  ifs>>s.driver_name;
  ifs>>s.boarding_time;
  ifs>>s.departure_time;
  ifs>>s.from;
  ifs>>s.to;
  ifs>>s.seats_full;
  ifs>>s.vacant_seats;
  for(int i=0;i<24;i++)
  {
    ifs>>s.bus_seats[i];
  }
  return ifs;
}
void reg(employee &v)
{
    int opt;
    string hp;
     cout<<"\t\t\t-------------------------------------------------------------------\n";
    cout<<"Enter Driver's details:\n\n";
    cout << "Enter Name: ";
    cin >>v.name;
    cout << "Enter DOB in dd-mm-yy: ";
    cin >> v.dob;
    cout << "Enter mobile number (It will be password) : ";
    cin >> v.mn;
    v.pass=v.mn;
    v.usr = (v.name.substr(0, 6)) + (v.dob.substr(0, 2)) + "-driver@srmap.edu.in";
    cout << "Driver's Username is  " << v.usr << endl;
    cout << "Registered Successfully" << endl;
    ofstream file; // ofstream creates a file
    driverdatabase dt;
    ofstream ofs;
    ifstream ifs;

    file.open(v.usr+".txt");
    file<<v;
    file.close();
    ifs.open("driverdatabase.txt");
    ifs>>dt;
    for(int i=0;i<30;i++)
    {
        if(dt.driverfilename[i]=="not_assigned")
        {
            dt.driverfilename[i]=v.usr;
            break;
        }
    }
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    return;
    ifs.close();
}
void removes()
{
  ifstream ifs;
  ofstream ofs;
  ifs.open("driverdatabase.txt");
  driverdatabase dt;
    ifs>>dt;
    int d=0;
    for(int i=0;i<30;i++)
    {
        if(dt.driverfilename[i]!="not_assigned")
        {
        d++;
        cout<<"\n"<<dt.driverfilename[i];
        }
    }
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    ifs.close();
    ofs.close();
    if(d==0)
    {
    cout<<"There is no one in your database\nRecruit some staff as soon as possible\n";
    return;
    }
    string pq;
    cout<<"\n\nPlease enter the username of the driver you want to fire:\n";
    cin>>pq;

    ifs.open("driverdatabase.txt");
    ifs>>dt;
    for(int i=0;i<30;i++)
    {
        if(dt.driverfilename[i]==pq)
        {
        dt.driverfilename[i]="not_assigned";
        break;
        }
    }
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    ifs.close();
    ofs.close();
     ofstream file;
     file.open(pq+".txt");
     file<<"";
     file.close();
     cout<<"Selected employee fired successfully\n";
}
void view()
{
  ifstream ifs;
  ofstream ofs;
  ifs.open("driverdatabase.txt");
  driverdatabase dt;
    ifs>>dt;
    int d=0;
    for(int i=0;i<30;i++)
    {
        if(dt.driverfilename[i]!="not_assigned")
        {
        cout<<"\n"<<dt.driverfilename[i];
        d+=1;
        }
    }
    if(d==0)
        cout<<"\n\t\tThere are no drivers\n\n";
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    ifs.close();
}
int viewcount()
{
  ifstream ifs;
  ofstream ofs;
  ifs.open("driverdatabase.txt");
  driverdatabase dt;
    ifs>>dt;
    int count=-1;
    for(int i=0;i<30;i++)
    {
        if(dt.driverfilename[i]!="not_assigned")
        {
        count++;
        }
    }
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    ifs.close();
    if(count>=5)
        return 1;
    else
        return 0;
}
void reg(visitor &v)
{
    int opt;
    cout << "Enter Your Name: ";
    cin >>v.name;
    cout << "Enter Your DOB in dd-mm-yy: ";
    cin >> v.dob;
    cout << "Enter Your mobile number (It will be your password) : ";
    cin >> v.mn;
    v.pass = v.mn;
    v.bus_no=-1;
    v.no_of_seats_booked=0;
    for(int i=0;i<24;i++)
      v.seats_booked[i]=0;

    v.usr = (v.name.substr(0, 6)) + (v.dob.substr(0, 2)) + "@srmap.edu.in";
    cout << "Your Username is  " << v.usr << endl;
    cout << "Registered Successfully" << endl;
    ofstream file; // ofstream creates a file
    file.open(v.usr + ".txt");
    file<<v;
    file.close();
}
visitor login()
{
    visitor v,visit;
    string usrnm, passd;
    cout << "Enter Username : ";
    cin >> usrnm;
    // usr = usrnm;
    cout << "Enter Password : ";
    cin >> passd;
    ifstream ifs;
    ifs.open(usrnm + ".txt");

    if(!ifs)
    {
      cout<<"\t\tyou are Not Registered yet\n";
      int hjb;
      cout<<"Enter 1 to register now else enter 2 to exit\n";
      cin>>hjb;
      if(hjb==1)
      reg(visit);
      else
        exit(0);
      return v;
    }
    ifs>>v;
    if (v.usr == usrnm && v.pass == passd)
    {
        int opt;
        cout << "Login Successfully" << endl;
        cout << "Welcome to SRM" << endl;
        return v;
    }
    else if(v.usr == usrnm)
    {
        int opt;
        cout << "Login Failed" << endl;
        cout << "If Forgot Password, Press 1 : ";
        cin >> opt;
        if (opt == 1)
        {
        string sname, sdob;
        cout << " Enter Username :";
        cin >> sname;
        cout << "Enter DOB : ";
        cin >> sdob;
        if (v.usr == sname && v.dob == sdob)
        {
        cout << "Your Password is : " << v.pass << endl;
        cout<<"\nLogged in successfully\n";
        }
        else
        {
            cout << "Invalid Input, Please try again " << endl;
        }
        return v;
        }
        return v;
    }
    else
      return v;
}
void reset(visitor &v)
{
    string ppass, a;
    cout << "Enter Previous Password : ";
    cin >> ppass;

    if (ppass == v.pass)
    {
        cout << "Create new password : ";
        cin >> v.pass;
        ofstream ofs;
        ofs.open(v.usr + ".txt");
        ofs<<v;
        cout << "Password Changed Sucessfully" << endl;
    }
    else
    {
        cout << "wrong password Try again" << endl;
    }
}
void install_bus_info()
{
  bus bus1;
  employee emp;
  string pq[6],st;
  ifstream ifs;
  ofstream ofs;
  ifs.open("driverdatabase.txt");
  driverdatabase dt;
    ifs>>dt;
    int coun=0;
    for(int num1=0;num1<30;num1++)
    {
        if((dt.driverfilename[num1])!="not_assigned"){
          st=dt.driverfilename[num1];
          ifs.open(st+".txt");
          ifs>>emp;
          pq[num1]=emp.name;
          ifs.close();
          coun++;
        }
    }

  for(int i=0;i<5;i++)
  {
  cout<<"\n\nEnter bus no(1-5): ";
  cin>>bus1.bus_number;
  bus1.driver_name=pq[i+1];
  cout<<"\nDriver name:"<<bus1.driver_name<<"\n";
  cout<<"\nArrival time: ";
  cin>>bus1.boarding_time;

  cout<<"\nDeparture: ";
  cin>>bus1.departure_time ;

  cout<<"\nFrom: \t\t\t";
  cin>>bus1.from;

  cout<<"\nTo: \t\t\t";
  cin>>bus1.to;
  bus1.seats_full=0;
  bus1.vacant_seats=24;
  for(int i=0;i<24;i++)
  {
    bus1.bus_seats[i]="vacant";
  }
  ifstream ifs;
  ofstream ofs;
  ofs.open("bus" + bus1.bus_number + ".txt");
  ofs<<bus1;
  cout<<"Bus Registered successfully\n\n";
  }
  ifs.close();
  return ;
}
void reservation(visitor &s)
{
  ofstream ofs;
  ifstream ifs;
  cout<<"User Name = "<<s.name<<endl<<endl;
  bus buses[5];
  int se_num=s.no_of_seats_booked;
  cout<<"Number of seats Booked: "<<se_num<<endl<<"\n\n";
  for(int i=0;i<5;i++)
  {
    string temp=("bus" + to_string(i+1) + ".txt");
    ifs.open(temp);
    ifs>>buses[i];
    cout<<"Bus Number: "<<i+1<<endl;
    cout<<"Driver Name: "<<buses[i].driver_name<<endl;
    cout<<"Boarding Time: "<<buses[i].boarding_time<<endl;
    cout<<"Departure Time: "<<buses[i].departure_time<<endl;
    cout<<"Starting From: "<<buses[i].from<<endl;
    cout<<"End at: "<<buses[i].to<<endl;
    cout<<"Number of Seats Vacant: "<<buses[i].vacant_seats<<endl<<endl;
    ifs.close();
  }
  int num;
  cout<<"Enter Bus no(1-5): ";
  cin>>num;
  num=num-1;
  int n,p=buses[num].vacant_seats;

  for(int j=0;j<6;j++)
  {
    int temp=4*j;
    if(buses[num].bus_seats[temp]=="vacant")
      cout<<temp+1<<"\t";
    else
      cout<<" \t";

    if(buses[num].bus_seats[temp+1]=="vacant")
      cout<<temp+2<<"\t\t";
    else
      cout<<" \t\t";

    if(buses[num].bus_seats[temp+2]=="vacant")
      cout<<temp+3<<"\t";
    else
      cout<<" \t";

    if(buses[num].bus_seats[temp+3]=="vacant")
      cout<<temp+4<<"\t";
    else
      cout<<" \t";
      cout<<endl;
  }
  x:cout<<"Enter Number of Seats you wanna book: ";
  cin>>n;
  if(n>p || n>=(24-se_num))
  {
    cout<<"Limit exceeded\n";
    goto x;
  }
  else
  {
    s.bus_no=num+1;
    s.no_of_seats_booked+=n;
    buses[num].seats_full+=n;
    buses[num].vacant_seats=24-buses[num].seats_full;
    cout<<"Enter Seat Numbers one by one:"<<endl;
    for(int j=0;j<n;j++)
    {
      int temp;
      string mer;
      cout<<"Enter seat number :\n";
      cin>>temp;
      s.seats_booked[se_num]=temp;
      cout<<"Enter the passenger's name:";
      cin>>mer;
      buses[num].bus_seats[temp-1]=(mer);
      se_num++;
    }
    ofs.open(s.usr+".txt");
    ofs<<s;
    ofs.close();
    ofs.open("bus" + to_string(num+1) + ".txt");
    ofs<<buses[num];
    ofs.close();
    cout<<"Your Tickets are booked Successfully"<<endl;
  }
}
void viewpassenger()
{
   ofstream ofs;
  ifstream ifs;
  bus buses[5];
  for(int i=0;i<5;i++)
  {
    string temp=("bus" + to_string(i+1) + ".txt");
    ifs.open(temp);
    ifs>>buses[i];
    cout<<"Bus Number: "<<i+1<<endl;
    cout<<"Driver Name: "<<buses[i].driver_name<<endl;
    cout<<"Boarding Time: "<<buses[i].boarding_time<<endl;
    cout<<"Departure Time: "<<buses[i].departure_time<<endl;
    cout<<"Starting From: "<<buses[i].from<<endl;
    cout<<"End at: "<<buses[i].to<<endl;
    cout<<"Number of Seats Vacant: "<<buses[i].vacant_seats<<endl;
    cout<<"Number of Seats booked: "<<24-buses[i].vacant_seats<<"\n\n\n";
    cout<<"Seatnumber\t\tPassenger Name\n";
    int cou=0;
    for(int j=0;j<24;j++)
    {
        if(buses[i].bus_seats[j]!="vacant")
            {
                cout<<j+1<<"\t\t"<<buses[i].bus_seats[j]<<"\n";
                cou++;
            }
    }
    if(cou==0)
        cout<<("\nNo passengers in this Bus\n\n\n");
    ifs.close();
  }
  Sleep(5000);
}
void cancellation_reservation(visitor &s)
{
    int a=s.bus_no;
    bus bobby;
    int b;
    ofstream ofs;
    ifstream ifs;
    ifs.open("bus"+to_string(a)+".txt");
    ifs>>bobby;
    cout<<"Bus details:\n\n";
    cout<<bobby.driver_name;
    cout<<"Bus Number: "<<a<<endl;
    cout<<"Driver Name: "<<bobby.driver_name<<endl;
    cout<<"Boarding Time: "<<bobby.boarding_time<<endl;
    cout<<"Departure Time: "<<bobby.departure_time<<endl;
    cout<<"Starting From: "<<bobby.from<<endl;
    cout<<"End at: "<<bobby.to<<endl;
    cout<<"Number of Seats Vacant: "<<bobby.vacant_seats<<endl<<endl<<endl;x:;
    cout<<"Enter the no. of seats you want to cancel:\n";
    cin>>b;
    if(s.no_of_seats_booked<b)
    {
        cout<<"Limit exceeded\n\n";
        goto x;
    }
    else
    {
    int c;
        for(int j=0;j<b;j++)
        {
            cout<<"Enter the seat no. you wanna cancel from the seats you booked\n";
             cin>>c;
              //seats_booked[24]
                 for(int k=0;k<24;k++)
                 {
                     if(s.seats_booked[k]==c)
                        {s.seats_booked[k]=0;}
                 }
                 s.no_of_seats_booked-=1;
                 bobby.bus_seats[c-1]="vacant";
        }
    bobby.seats_full-=b;
    bobby.vacant_seats+=b;
    cout<<"\nTickets selected cancelled successfully\n";
    ofs.open("bus" +to_string(a)+ ".txt");
    cout<<"\n";
    ofs<<bobby;
    ofs.close();
    ofs.open(s.usr+".txt");
    ofs<<s;
    ofs.close();
    }
}
void show_reservation_info(visitor &s)
{
  int c=0;
  cout<<"User Name: "<<s.usr<<endl;
  cout<<"No of Seats Booked: "<<s.no_of_seats_booked<<endl;
  cout<<"Seats are booked in Bus Number - "<<s.bus_no<<endl;
  cout<<"Seats booked are: "<<endl;
  for(int i=0;i<24;i++)
  {
    if(s.seats_booked[i]!=0)
      {cout<<s.seats_booked[i]<<"\t";
       c++;}
  }
  if(c==0)
    cout<<"0";
  cout<<endl;
}
void waits(){
    cout<<"\n\n\t\tLoading...";
    Sleep(5000);
    system("cls");
}
int main()
{
    system("cls");
    cout<<"PLEASE DON'T GIVE SPACES WHILE INPUTTING DATA INSTEAD USE ANY SPECIAL SYMBOLS UNDERSCORE IS PREFERABLE\n\n\n\n\n\n\n\n\n";

    cout<<"\t\t\t\t\tWELCOME TO  TRAVEL AGENCY\n\n\n";

FILE *fp = fopen("driverdatabase.txt", "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
if(is_exist==false)
    {
     driverdatabase dt;
     for(int i=0;i<30;i++)
     dt.driverfilename[i]="not_assigned";
     ifstream ifs;
     ofstream ofs;
    ofs.open("driverdatabase.txt");
    ofs<<dt;
    }
  int choice;
  employee sam;
  visitor visit;
  //admin sam1;
  byek:;
  cout<<"\n\n\n\n\n\n";
  cout<<"\t\t\t===================================================================";
  cout << "\n\n\t\t\t\t\tPlease enter Valid Choices only\n"<< endl;
  cout<<"\t\t\t===================================================================\n";
  cout <<"\t\t\t\t\t1.Visitor" << endl;
  cout <<"\t\t\t\t\t2.Manager" << endl;
  cout<<"\t\t\t\t\t3.Exit"<<endl;
  cout<<"\n\t\t\t===================================================================\n";
  cout <<"\t\t\t\tEnter Your Option: ";
  cin>>choice;
if(choice==1)
{
    int i=viewcount();
    if (i==0)
     {
         cout<<"\n\t\t\t===================================================================\n";
         cout<<"\t\t    Sorry,for the inconvenience as we are not providing bus services right now\n\t\t    It may take a while for manager to get some staff\n";
         exit(0);
     }
  int o1;
  cout << "1.Register" << endl;
  cout << "2.Login" << endl;

  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>o1;
  switch(o1)
  {
 case 1:
      reg(visit);
      waits();
      break;
    case 2:
      visit=login();
      waits();
      break;
  }

  int o2;
  while(1)
    {
    cout<<"\t\t\t1.Reservation\n\t\t\t"<<"2.Show Reservation Information\n\t\t\t3.Cancel reserved seats";
    cout<<"\n\t\t\t4.Logout\n\t\t\t5.Exit"<<endl;
    cout<<"\n\t\t\tEnter your choice:- ";
    cin>>o2;
    switch(o2)
    {
      case 1:
        reservation(visit);
        waits();
        break;

      case 2:
        show_reservation_info(visit);
        waits();
        break;
      case 3:
          show_reservation_info(visit);
        cancellation_reservation(visit);
        waits();
        break;
      case 4:
        goto byek;
        break;
      case 5:
        exit(0);
        break;
    }
  }
}
if(choice==2)
{
    cout<<"\n\t\t\t----------------Enter your details to login as MANAGER-------------\n\n";
    int i=viewcount();
    if(i==0)
        {
        cout<<"\t\t\t    Recruit some drivers as soon as possible to open the agency\n";
        cout<<"\t\t\t-------------------------------------------------------------------\n";
        }
  int c;
  int man;
  cout<<"\t\t\tGreetings Manager please enter your password : \n\n";
  cout<<"\t\t\tEnter your password : ";
  cin>>man;
  if(1)
  {
    if(man==password)
    {
     cout<<"\n\t\t\t------------------------Login Successfully-------------------------\n";

                         //Admin name is Saiteja and password is 420

int o3;
while(1){
   if(viewcount()==0)
        {
        cout<<"\n\n\t\t\t    Recruit some drivers as soon as possible to open the agency\n";
        cout<<"\t\t\t-------------------------------------------------------------------\n";
        }
 cout<<"\t\t\t\n\t\t\t";
 cout<<"\t\t1.To install Info of Buses\n\t\t\t\t\t2.Logout\n\t\t\t\t";
      cout<<"\t3.Add staff\n\t\t\t\t\t4.Remove staff\n\t\t\t\t\t5.view staff\n\t\t\t\t\t6.View passenger list of all buses\n\t\t\t\t\t7.Exit\n";
 cout<<"\t\tEnter your choice:- ";
 cin>>o3;
 switch(o3){
  case 1:
      install_bus_info();
      cout<<"\n\n";
      waits();
       case 2:
        goto byek;
      break;
       case 3:
        reg(sam);
        waits();
        break;
       case 4:
        removes();
        waits();
        break;
       case 5:
        view();
        waits();
        break;
       case 6:
        viewpassenger();
        waits();
        break;
        default: exit(0);

      }
     }
    }
    else
    {
    cout<<"Invalid Credentials";
    goto byek;
    }
  }
 }
 if(choice==3);
 return 0;
}
