#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Songs
{
public:
    string title;
    float duration;
    string singer;
    Songs *prev;
    Songs *next;

    Songs(string name, float time, string singerr)
    {
        title = name;
        duration = time;
        singer = singerr;
        prev = NULL;
        next = NULL;
    }
};

class Library
{
public:
    Songs *head;
    Songs *root;

    Library()
    {
        head = NULL;
        root = NULL;
    }

    Songs *getHead()
    {
        return head;
    }

    void insertSongLibrary(string title, float duration, string singer)
    {
        Songs *newnode;
        newnode = new Songs(title, duration, singer);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Songs *nptr;
            nptr = head;
            while (nptr->next != NULL)
            {
                nptr = nptr->next;
            }
            nptr->next = newnode;
            newnode->prev = nptr;
        }
    }

    void insertSongPlaylist(string name, Songs *main)
    {
        int found = 0;
        Songs *nptr;
        nptr = main;
        while (nptr != NULL)
        {
            if (nptr->title == name)
            {
                found = 1;
                break;
            }
            else
            { // a
                found = 0;
            }
            nptr = nptr->next;
        }
        if (found == 1)
        {
            Songs *userNode;
            userNode = new Songs(nptr->title, nptr->duration, nptr->singer);
            if (root == NULL)
            {
                root = userNode;
                userNode->next=root;
                cout << "Added at 1st" << endl;
            }
            else
            {
                Songs *temp;
                temp = root;
                while (temp->next != root)
                {
                    temp = temp->next;
                }

                userNode->prev = temp;
                userNode->next = temp->next;
                nptr->next->prev=userNode;
                temp->next=userNode;
                cout << "Added!!" << endl;
            }
        }

        else
        {
            cout << "No such song found!!";
        }
    }

    void deleteSongFromPlaylist(string name, Songs* userPl){
        Songs* currNode;
        currNode=userPl;
        int found=0;
        while(currNode!=NULL){
            if(currNode->title==name){
                found=1;
                break;
            }
        }

        if(found=1){
            currNode->prev->next=currNode->next;
            currNode->next->prev=currNode->prev;
            delete(currNode);
            cout<<"Found and deleted!!"<<endl;
        }
        else{
            cout<<"This song does not exist in your Playlist!"<<endl;
        }
    }




    void display()
    {
        Songs *nptr;
        nptr = head;
        int cnt = 1;
        while (nptr != NULL)
        {
            cout << cnt << " . " << nptr->title << endl;
            cnt++;
            nptr = nptr->next;
        }
    }

    void playforwardloop(string name){
        Songs *nptr;
        nptr = root;
        while(nptr->title!=name){
            nptr=nptr->next;
        }
        Songs *curr = nptr->prev;
        while(nptr != NULL && nptr!=curr){
            cout<<"Playing the song :"<<nptr->title<<endl;
            sleep(nptr->duration);
            nptr = nptr->next;
        }
    }

    void playbackwardloop(string name){
        Songs *nptr;
        nptr = root;
        while(nptr->title!=name){
            nptr=nptr->next;
        }
        Songs *curr = nptr->next;
        while(nptr != NULL && nptr!=curr){
            cout<<"Playing the song :"<<nptr->title<<endl;
            sleep(nptr->duration);
            nptr = nptr->prev;
        }
    }
};

int main()
{
    Library pl;
    Library u;
    Library user;
    pl.insertSongLibrary("Maand", 5.8, "Suhani");
    pl.insertSongLibrary("Jhol", 6.1, "Maanu");
    pl.insertSongLibrary("Sahiba", 5.2, "Aditya Rikhari");
    pl.insertSongLibrary("Finding Her", 7.6, "Kushagra");
    pl.insertSongLibrary("Paro", 6.65, "Aditya Rikhari");
    pl.insertSongLibrary("Baarishein", 8.4, "Anuv Jain");
    pl.insertSongLibrary("Jo Tum Mere Ho", 7.5, "Anuv Jain");
    pl.insertSongLibrary("Husn", 3.8, "Anuv jain");
    pl.insertSongLibrary("Line Without a Hook", 4.32, "Ricky Montgomery");
    pl.insertSongLibrary("Mann Mera", 7.8, "Gajendra Verma");
    pl.insertSongLibrary("Pal Pal Dil Ke Pass", 9.24, "Kishor Kumar");
    pl.insertSongLibrary("Om Namo Bhagavate vasudevaya", 4.10, "Sam C.S.");
    pl.insertSongLibrary("Tu hi tu hai", 4.10, "suh");
    cout << "--------------------------------------------------------------WELCOME TO OUR MINI SPOTIFY--------------------------------------------------------------" << endl;
    cout << "Good Vibes Start Here...." << endl;
    pl.display();
    u.insertSongPlaylist("Maand", pl.head);
    u.insertSongPlaylist("Husn", pl.head);
    u.insertSongPlaylist("Hero", pl.head);
    int choice;
    cout << "What would you like to do?" << endl
         << "1.CREATE YOUR OWN PLAYLIST" << endl
         << "2.ADD SONGS TO YOUR PLAYLIST" << endl
         << "3.DELETE SONGS FROM YOUR PLAYLIST" << endl
         << "4.VIEW SONGS IN YOUR PLAYLIST" << endl
         << "5.PLAY A SONG FROM PLAYLIST" << endl
         << "6.PLAY NEXT SONG" << endl
         << "7.PLAY PREVIOUS SONG" << endl
         << "8.PLAY SONGS FROM YOUR OWN PLAYLIST ON LOOP"<<endl
         << "9.VIEW RECENTLY PLAYED SONGS" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int n;
        cout<<"Enter number of songs you want in your playlist:";
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            u.insertSongPlaylist(arr[i],pl.head);
        }
    }

    case 2:
    {
        string s;
        cout<<"Enter the song name you want to add:";
        cin>>s;
        u.insertSongPlaylist(s,pl.head);
    }

    case 3:
    {
        string str;
        cout<<"Enter a song name you want to delete:";
        cin>>str;
        u.deleteSongFromPlaylist(str,u.root);
    }

    case 4:
    {

    }

    case 5:
    {

    }

    case 6:
    {

    }

    case 7:
    {

    }

    case 8:
    {
        int n;
        cout<<"Do you want to play the playlist 1.forward or 2.backward?";
        cin>>n;
        string song;
        cout<<"From which song do you want to play?";
        cin>>song;
        if(n==1){
            u.playforwardloop(song);
        }else{
            u.playbackwardloop(song);
        }
    }
    case 9:
    {
        
    }
    }
}
