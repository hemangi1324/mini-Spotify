#include <iostream>
#include <string>
#include <unistd.h>
#include <stack>
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
    stack<Songs *> st;
    Songs *head;
    Songs *root;

    Library()
    {
        head = NULL;
        root = NULL;
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

    void insertSongPlaylist(string name)
    {
        int found = 0;
        Songs *nptr;
        nptr = head;
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

        // Songs* check = root;
        // while(check->next!=root){
        //     if(check->title==name){
        //         cout<<"SONG ALREADY EXISTS!!"<<endl;
        //         return;
        //     }
        //     check=check->next;
        // }

        if (found == 1)
        {
            Songs *userNode;
            userNode = new Songs(nptr->title, nptr->duration, nptr->singer);
            if (root == NULL)
            {
                root = userNode;
                userNode->next = root;
                userNode->prev = root;
                cout << "Added at 1st" << endl;
            }
            else
            {
                Songs *temp;
                temp = root->prev;

                temp->next = userNode;
                userNode->prev = temp;
                userNode->next = root;
                root->prev = userNode;
                cout << "Added!!" << endl;
            }
        }

        else
        {
            cout << "No such song found!!" << endl;
            return;
        }
    }

    void deleteSongFromPlaylist(string name, Songs *userPl)
    {
        Songs *currNode = userPl;
        int found = 0;

        // circular traversal (search)
        while (true)
        {
            if (currNode->title == name)
            {
                found = 1;
                break;
            }
            currNode = currNode->next;
            if (currNode == userPl)
                break; // full circle done
        }

        if (found == 1)
        {
            //  handle single-node playlist
            if (currNode->next == currNode)
            {
                root = NULL;
                delete currNode;
                cout << "FOUND AND DELETED (playlist now empty)" << endl;
                return;
            }

            //  deleting first node
            if (currNode == root)
            {
                root = currNode->next;
                root->prev = currNode->prev;
                currNode->prev->next = root;
                delete currNode;
                cout << "FOUND AND DELETED" << endl;
            }
            else
            { //  deleting middle/last node
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                delete currNode;
                cout << "FOUND AND DELETED" << endl;
            }
        }
        else
        {
            cout << "This song does not exist in your Playlist!" << endl;
        }
    }

    void playbackwardloop(string name)
    {
        Songs *nptr;
        nptr = root;
        while (nptr->title != name)
        {
            nptr = nptr->next;
        }
        Songs *curr = nptr->next;
        while (nptr != NULL && nptr != curr)
        {
            cout << "Playing the song :" << nptr->title << endl;
            sleep(nptr->duration);
            st.push(nptr);
            nptr = nptr->prev;
        }

        cout << "LOOP ENDEDD!!" << endl;
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

    void playforwardloop(string name)
    {
        Songs *nptr;
        nptr = root;
        while (nptr->title != name)
        {
            nptr = nptr->next;
        }
        Songs *curr = nptr->prev;
        while (curr != nptr)
        {
            cout << "Playing the song :" << nptr->title << endl;
            sleep(nptr->duration);
            st.push(nptr);
            nptr = nptr->next;
        }
    }

    void displayfromPlaylist()
    {
        Songs *currNode;
        currNode = root;
        while (true)
        {
            cout << currNode->title << "  ";
            currNode = currNode->next;
            if (currNode == root)
                break;
        }
        cout << endl;
    }

    void Recentsong()
    {
        Songs *recent = st.top();
        st.pop();
        cout << "The recent song you played is:" << recent->title << endl;
    }

    void NextSong()
    {
        Songs *nextS = st.top()->next;
        cout << "Playing " << nextS->title;
        sleep(nextS->duration);
    }

    void PreviousSong()
    {
        Songs *prevS = st.top()->prev;
        cout << "Playing " << prevS->title << endl;
        sleep(prevS->duration);
    }

    void play(string name)
    {
        Songs *tobeplayed = root;
        int found = 0;
        while (tobeplayed->next != root)
        {
            if (tobeplayed->title == name)
            {
                found = 1;
                cout << "Playingg " << tobeplayed->title << ".....";
                sleep(tobeplayed->duration);
                return;
            }
            tobeplayed=tobeplayed->next;
        }
        if (tobeplayed->title == name)
            {
                found = 1;
                cout << "Playingg " << tobeplayed->title << ".....";
                sleep(tobeplayed->duration);
                return;
            }
        if (found == 0)
        {
            cout << "No such song found to be played :(" << endl;
        }
    }
};

int main()
{
    // Library pl;
    Library u;
    // Library user;
    u.insertSongLibrary("Maand", 5.8, "Suhani");
    u.insertSongLibrary("Jhol", 6.1, "Maanu");
    u.insertSongLibrary("Sahiba", 5.2, "Aditya Rikhari");
    u.insertSongLibrary("Finding Her", 7.6, "Kushagra");
    u.insertSongLibrary("Paro", 6.65, "Aditya Rikhari");
    u.insertSongLibrary("Baarishein", 8.4, "Anuv Jain");
    u.insertSongLibrary("Jo Tum Mere Ho", 7.5, "Anuv Jain");
    u.insertSongLibrary("Husn", 3.8, "Anuv jain");
    u.insertSongLibrary("Line Without a Hook", 4.32, "Ricky Montgomery");
    u.insertSongLibrary("Mann Mera", 7.8, "Gajendra Verma");
    u.insertSongLibrary("Pal Pal Dil Ke Pass", 9.24, "Kishor Kumar");
    u.insertSongLibrary("Om Namo Bhagavate vasudevaya", 4.10, "Sam C.S.");
    u.insertSongLibrary("Tu hi tu hai", 4.10, "suh");
    cout << "-------------------------------------------------------------WELCOME TO OUR MINI SPOTIFY--------------------------------------------------------------" << endl;
    cout << "Good Vibes Start Here...." << endl;
    u.display();

    // u.insertSongPlaylist("Maand");
    // u.insertSongPlaylist("Husn");
    // u.insertSongPlaylist("Baarishein");
    // u.insertSongPlaylist("Paro");
    // u.insertSongPlaylist("Mann Mera");
    // u.insertSongPlaylist("Hero");
    // u.disp();
    // u.deleteSongFromPlaylist("Maand", u.root);
    // u.deleteSongFromPlaylist("herr",u.root);
    // u.disp();
    int choice;

    int n;
    cout << "\n\n--------------------------------CREATE YOUR OWN PLAYLIST FROM OUR SONGS--------------------------------------\n\n"
         << endl;
    cout << "Enter number of songs you want in your playlist:";
    cin >> n;
    cin.ignore();
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter song:";
        getline(cin, arr[i]);
        u.insertSongPlaylist(arr[i]);
    }

    cout << "\n\n-------------------------------------WHAT WOULD YOU LIKE TO DO---------------------------------" << endl;

    cout << endl
         << "1. Exit SPOTIFY" << endl
         << "2.ADD SONGS TO YOUR PLAYLIST" << endl
         << "3.DELETE SONGS FROM YOUR PLAYLIST" << endl
         << "4.VIEW SONGS IN YOUR PLAYLIST" << endl
         << "5.PLAY A SONG FROM PLAYLIST" << endl
         << "6.PLAY NEXT SONG" << endl
         << "7.PLAY PREVIOUS SONG" << endl
         << "8.PLAY SONGS FROM YOUR OWN PLAYLIST ON LOOP" << endl
         << "9.VIEW RECENTLY PLAYED SONGS" << endl;
    int flag = 1;
    
    while (flag)
    {
        cout << "Enter your choice number here:";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Exiting Spotify......" << endl;
            flag = 0;
            break;
        }

        case 2:
        {
            string s;
            cout << "Enter the song name you want to add:";
            getline(cin, s);
            u.insertSongPlaylist(s);
            break;
        }

        case 3:
        {

            string str;
            cout << "Enter a song name you want to delete:";
            getline(cin, str);
            u.deleteSongFromPlaylist(str, u.root);
            break;
        }

        case 4:
        {
            cout << "YOUR PLAYLIST!! :)" << endl;
            u.displayfromPlaylist();
            break;
        }

        case 5:
        {
            string song;
            cout << "Enter the song you want to play:";
            getline(cin, song);
            u.play(song);
            cout<<endl;
            break;
        }

        case 6:
        {
            cout << "Playing song previous to : " << u.st.top()->title << endl;
            u.PreviousSong();
            break;
        }

        case 7:
        {
            cout << "Playing song next to : " << u.st.top()->title << endl;
            u.NextSong();
            break;
        }

        case 8:
        {
            int n;
            cout << "Do you want to play the playlist 1.forward or 2.backward?";
            cin >> n;
            cin.ignore();
            string song;
            cout << "From which song do you want to play?";
            getline(cin, song);
            if (n == 1)
            {
                u.playforwardloop(song);
            }
            else
            {
                u.playbackwardloop(song);
            }
            break;
        }
        case 9:
        {
            u.Recentsong();
            break;
        }
        default:
        {
            cout << "Please enter a valid operaion!!!" << endl;
        }
        }
    }

    cout << "SPOTIFY TERMINATED!!!" << endl;
}
