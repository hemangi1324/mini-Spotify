#include <iostream>
#include <string>
using namespace std;

class Library{

};




class Playlist
{
public:
    struct AdminPl
    {
        string title;
        float duration;
        string singer;
        AdminPl *prev;
        AdminPl *next;
    };
    AdminPl *head;


    Playlist()
    {
        head = NULL;
    }

    void insertSong(string title, float duration, string singer)
    {
        AdminPl *newnode;
        newnode = new AdminPl;
        newnode->title = title;
        newnode->duration = duration;
        newnode->singer = singer;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            AdminPl *nptr;
            nptr=head;
            while (nptr->next != NULL)
            {
                nptr = nptr->next;
            }
            nptr->next = newnode;
        }
    }

    void display(){
        AdminPl* nptr;
        nptr=head;
        int cnt=1;
        while(nptr!=NULL){
            cout<<cnt<<" . "<<nptr->title<<endl;
            cnt++;
            nptr=nptr->next;
        }
    }
};
//hi suhani 
int main()
{
    Playlist pl;
    pl.insertSong("Maand",5.8,"Suhani");    
    pl.insertSong("Jhol",6.1,"Maanu");
    pl.insertSong("Sahiba",5.2,"Aditya Rikhari");
    pl.insertSong("Finding Her",7.6,"Kushagra");     
    pl.insertSong("Paro",6.65,"Aditya Rikhari");
    pl.insertSong("Baarishein",8.4,"Anuv Jain");
    pl.insertSong("Jo Tum Mere Ho",7.5,"Anuv Jain");
    pl.insertSong("Husn",3.8,"Anuv jain");
    pl.insertSong("Line Without a Hook",4.32,"Ricky Montgomery");
    pl.insertSong("Mann Mera",7.8,"Gajendra Verma");
    pl.insertSong("Pal Pal Dil Ke Pass",9.24,"Kishor Kumar");
    pl.insertSong("Om Namo Bhagavate vasudevaya",4.10,"Sam C.S.");
    cout<<"--------------------------------------------------------------WELCOME TO OUR MINI SPOTIFY--------------------------------------------------------------"<<endl;
    cout<<"Good Vibes Start Here...."<<endl;
    pl.display();


    int choice;
    cout<<"What would you like to do?"<<endl<<"1.CREATE YOUR OWN LIBRARY"<<endl<<"2.SEARCH FOR FAVOURITE SONG"<<endl<<"3.PLAY SONGS FROM YOUR OWN LIBRARY ON LOOP"<<endl;
    cin>>choice;
    switch (choice){
        case 1:{
            
        }

        case 2:{

        }

        case 3:{

        }

        case 4:{

        }


    }
     
}

// int main() {
//     Playlist pl;
//     cout<<"WELCOME TO MINI-SPOTIFY!!"<<endl;
//     cout<<"OUR PLAYLIST!"<<endl;
//     char role;
//     cout<<"What is your role?\n1.Enter 1 for Admin\n2.Enter 2 for User";
//     cin>>role;
//     switch(role){
//         case 'A':{
//             string Correctpassword="$suhani.31";
//             string password;
//             cout<<"Enter password";
//             cin>>password;
//             int i=1;
//             while(i<=3){
//             if(password==Correctpassword){

//                 break;
//             }
//             else{
//                 cout<<"Enter valid password!"<<endl;
//                 i++;
//             }
//         }
//         cout<<"SESSION SUSPENDED!!"<<endl;
//         }

//         case 'U':{

//         }
//     }

// }