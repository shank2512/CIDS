#include <iostream>
#include <windows.h>
#include <mysql.h>
#include<iomanip>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
     MYSQL* conn;
     MYSQL_ROW row;
     MYSQL_RES* res;

     int qstate;

     conn = mysql_init(0);
     if(conn)
        cout<<"connection to object ok "<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;

     conn = mysql_real_connect(conn,"localhost","root","","cids",0,NULL,0);
      if(conn)
       {
         cout<<"Connection established\n"<<endl;

         //qstate = mysql_query(conn,"insert into sample values(5,6,7,8)");
         while(TRUE){
         qstate = mysql_query(conn,"SELECT * FROM `criminal table` ");

         if(!qstate)
         {
             res=mysql_store_result(conn);
             cout<<"\n"<<setw(3)<<"Criminal_ID"<<setw(10)<<"Name"<<setw(20)<<"Type_of_Crime"<<setw(25)<<"Year_of_Imprisonment"<<setw(10)<<"Prison";
             while(row=mysql_fetch_row(res))
             {
                 cout<<"\n"<<setw(3)<<row[0]<<setw(18)<<row[1]<<setw(15)<<row[2]<<setw(20)<<row[3]<<setw(20)<<row[4];
             }

         }
         cout<<"\n\t"<<"1.New";
         cout<<"\n\t"<<"2.Update\n";
         string na;
         string cr,yi,p;
         string s;
         int ch,cid=1;
         s="SELECT * FROM `criminal table` ";
              qstate = mysql_query(conn,s.c_str());
             if(!qstate)
             { res=mysql_store_result(conn);
               while(row=mysql_fetch_row(res))
             {
                  cid++;
             }
             }
         cin>>ch;
         char buf[10];
         if(ch==1)
            {
             itoa(cid,buf,10);
             string buff=buf;
             cout<<"\nEnter Name:";
             getline(cin,na);
             getline(cin,na);

             cout<<"\nType_of_Crime:";
             getline(cin,cr);
             cout<<"\nYear_of_Imprisonment (yyyy-mm-dd):";
             getline(cin,yi);
             cout<<"\nPrison:";
             getline(cin,p);
             s="insert into `criminal table` values("+buff+",'"+na+"','"+cr+"','"+yi+"','"+p+"')";
             qstate = mysql_query(conn,s.c_str());
         }
         else if(ch==2)
         {
            cout<<"\nEnter the criminal ID: ";
            int cd;
            cin>>cd;
            itoa(cd,buf,10);
            string buff=buf;
            cout<<"\nName edit?(y/n): ";
            char x;
            cin>>x;
            if(x=='y')
            {
                getline(cin,na);
                getline(cin,na);
                s = "UPDATE `criminal table` SET `Name`='"+na+"' WHERE CriminalID="+buff;
                qstate = mysql_query(conn,s.c_str());
            }
            cout<<"\nType of crime edit?(y/n): ";
            cin>>x;
            if(x=='y')
            {
                getline(cin,na);
                getline(cin,na);
                s = "UPDATE `criminal table` SET `Crimetype`='"+na+"' WHERE CriminalID="+buff;
                qstate = mysql_query(conn,s.c_str());
            }
            cout<<"\nYear of Imprisonment edit?(y/n): ";
            cin>>x;
            if(x=='y')
            {
                getline(cin,na);
                getline(cin,na);
                s = "UPDATE `criminal table` SET `YoI`='"+na+"' WHERE CriminalID="+buff;
                qstate = mysql_query(conn,s.c_str());
            }
            cout<<"\nPrison edit?(y/n): ";
            cin>>x;
            if(x=='y')
            {
                getline(cin,na);
                getline(cin,na);
                s = "UPDATE `criminal table` SET `Prison`='"+na+"' WHERE CriminalID="+buff;
                qstate = mysql_query(conn,s.c_str());
            }
         }
         cout<<"\nRedo?(y/n): ";
         char y;
         cin>>y;
         if(y=='n')
         break;
       }
           qstate = mysql_query(conn,"SELECT * FROM `criminal table` ");

         if(!qstate)
         {
             res=mysql_store_result(conn);
             cout<<"\n"<<setw(3)<<"Criminal_ID"<<setw(10)<<"Name"<<setw(20)<<"Type_of_Crime"<<setw(25)<<"Year_of_Imprisonment"<<setw(10)<<"Prison";
             while(row=mysql_fetch_row(res))
             {
                 cout<<"\n"<<setw(3)<<row[0]<<setw(18)<<row[1]<<setw(15)<<row[2]<<setw(20)<<row[3]<<setw(20)<<row[4];
             }

         }
        exit(1);
       }
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
     return 0;
}

