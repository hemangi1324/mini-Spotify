**Title: Mini - Spotify** 

**Problem Statement:** Implement a mini Spotify using doubly circular linked list and stack.

**Objectives:**
1.	To design and implement a Mini Spotify application using C++ that allows song management and playback simulation.
2.	To utilize Doubly Circular Linked Lists for efficient navigation (forward/backward) through songs.
3.	To demonstrate object-oriented programming concepts such as classes, objects, encapsulation, and modular design.
4.	To integrate stack data structure for tracking recently played songs.
   
**Outcomes:**
1.	Successfully created a functional mini music player using C++ that supports playlist creation and song management.
2.	Implemented Doubly Circular Linked List for the playlist, enabling both forward and backward traversal.
3.	Designed operations like insert, delete, search, play next/previous, loop play, and display songs.
4.	Incorporated a stack-based recent songs list to store and display recently played tracks.
   
**Design :**
The main aim of this project is to design a Mini Spotify application using C++ which allows the user to:
1.	Create a personal playlist from a library of songs
2.	Add or delete songs
3.	Traverse forward or backward through songs
4.	Play songs in loop (forward/backward)
5.	View recently played songs
This project focuses on mastering the concept of Doubly Circular Linked Lists and Stack for real-world data handling.


**Architecture (With diagram):
Overview:**
The program has two major components:
**Library:**
Contains all available songs (stored using a singly linked list).

**User Playlist:**
Created by the user from songs in the library, implemented using a Doubly Circular Linked List for smooth forward and backward navigation.
Additionally, a Stack data structure is used to store and retrieve recently played songs.
 
**Data structure used:**

**Doubly Circular Linked List**
Used to store the playlist songs, where each node contains:
1.	Song title
2.	Duration
3.	Singer
4.	Pointer to next song (next)
5.	Pointer to previous song (prev)
   
**Advantages in this project:**
1.	Easy traversal in both directions (forward/backward play)
2.	Circular nature allows looping playback without needing to restart manually
   
**Stack**
Used to maintain a history of recently played songs.
The LIFO property helps retrieve the most recently played song efficiently.

**Algorithm:**
Key Functionalities and Logic
1.	Insert Song into Library
    •	Create a new Songs node.
    •	Append it at the end of the singly linked list.
3.	Add Song to Playlist
    •	Search the song in the library.
    •	If found, create a duplicate node and insert it into the doubly circular playlist.
    •	Adjust both next and prev pointers to maintain circular links.
4.	Delete Song from Playlist
    •	Search by title in the circular playlist.
    •	Handle 3 cases:
        	Deleting the only song → playlist becomes empty
        	Deleting the first song → update root
        	Deleting any middle/last song → adjust neighboring links
5.	Play Song
    	Traverse the playlist circularly
    	Use sleep(duration) to simulate playback time.
    	Push played song onto the stack.
6.	Play Next Song
    	Access next node of top of stack
    	Use sleep(duration) to simulate playback time.
7.	Play Previous Song
    	Access previous node of top of stack
    	Use sleep(duration) to simulate playback time.
8.	Play Songs (Forward or Backward Loop)
    •	Traverse the playlist circularly.
    •	Use sleep(duration) to simulate playback time.
    •	Push each played song onto the stack.
9.	Recently Played Song
    •	Pop the top element from the stack to display the most recently played track.

	

**Class Diagram**

          Songs
 - title: string        
 - duration: float      
 - singer: string       
 - prev: Songs*         
 - next: Songs*
 + Songs(name,time, s)
   
                   ▲
                   │
                   │ contains
                   ▼
   
           **Library**
- head: Songs*             
- root: Songs*             
- st: stack<Songs*>
+insertSongLibrary()
+insertSingPlaylist()
+deleteSongFromPlaylist()
+display()
+displayfromPlaylist()
+playForwardloop()
+playbackwardloop()
+RecentSong()
+Nextsong()
+Previoussong()
+Play()

**Test cases:**
**No.	--	Input / Operation		       --                      Expected Output	**
					
TC1	 --	Add 3 songs to library		        --                 Songs added successfully	
					
TC2	 --	Create playlist of 2 songs ("Maand", "Husn")	--	   Playlist displays both songs circularly	
					
TC3	 -- 	Delete song "Husn" from playlist		   --            Song deleted, list updates correctly	
					
TC4	 --	Play playlist forward		        --                   Songs play in sequence with delay	
TC5		Play playlist backward		                         Songs play in reverse order	
					
TC6	--	Play recent song		              --                 Displays last played track	
					
TC7	 -- 	Delete non-existent song		      --                 Displays error message "This song does not exist in your Playlist!"	
					

**Application:**

1.	Music Playlist Simulation: Mimics Spotify-like functionality at console level.
2.	Educational Use: Demonstrates the real-world use of Doubly Circular Linked Lists and Stacks.
3.	Modular Design: Can be extended with file handling, GUI, or real music files.
4.	Practical Learning: Helps in understanding node manipulation and circular navigation.
   
**Conclusion:**

This project successfully demonstrates how Doubly Circular Linked Lists can be applied in real-world systems like music players where bidirectional and continuous traversal is required.
The additional use of Stack for recently played songs enhances user experience by storing playback history.
By completing this project, we gained:
•	Strong understanding of linked list operations.
•	Practical exposure to data structure integration.
•	Problem-solving and debugging experience in C++.




Screen shots of outputs:     

