#include <iostream>
#include <string>
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
        while (nptr != main)
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
};
// hi suhani
int main()
{
    Library pl;
    Library u;
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
    }

    case 2:
    {
    }

    case 3:
    {
    }

    case 4:
    {
    }
    }
}
