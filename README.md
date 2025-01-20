Romain Polack 3SI3


# SQL project
A mini SQL-like program

# How to execute
- Go at the project's root
- Write `make run` and hit enter

## Documentation:

This file will serve as a documentation for my idea of the project, how I imagined it and how i planned to incorporate the solution

Firstly, before reading the subject, i didn't know anything about Trees or binary trees and i learned a lot by reading outside documentations whilst trying to do this project. 

Even before knowing about binary trees, I am not keen on C and i haven't had the occasion to dive into a project this big in the past. 

So i did the Makefile which, for some reason, only compiles the project if I compile the main file, but at least it works. 

Afterwards I made a meta command because i thought it was fun. Try typing `.help` in the prompt and you'll see.

Then I went on to create columns and a table for my program with a little prompt allowing you to create your table with the column names. 

This is where I had to make my brain function in order to incorporate the binary tree structure into the game. However this is where i got stuck (this early) and never got to keep on doing the project as it was really intense and i hadn't managed my time very well. 

However, I understood how binary trees work, storing data in a hierarchical way, along with balancing a sorting, allows for quick iterations when you want to use Select. 

When new data is inserted, the tree is rearranged in order to store the data at the right spot for smoother and faster commands. 

I was planning to implement the Select function this way : 

First, all of the command are parsed, you can see in the code I was able to parse commands and print them out after written. Once parsed, each argument was analysed, if it was a '*', then, the whole table would have to be printed. If the second argument was not a star, then, its value would have been compared with the names of the columns inside the table, if it corresponded, then, the column was printed, if it didn't correspond, then it returned an error. 

Second, I was planning to implement the Insert function like so : 

After parsing the command and the argument with the same function as before, same thing, if the name of the column corresponded to the name in the buffer, then, the command would execute, (for example Insert 5 into age). 
Afterwards, a node would be created with the data inside of it, then, i would have done a level order traversal to find the appropriate place in which to insert the data, if the right child of the given node is unoccupied, then put it here, if not and that the left child is unoccupied, then insert it here inside the tree. 

With these functions implemented, i would have had a good starting base.

Afterwards, had I had enough time, i would have implemented a self balancing tree system and a disk persistance feature. 

The disk persistance would have been performed by simply writing in a file the parsed data into a csv format file, then, on execution of the program, the data inside the file would have been unparsed to be integrated into the btree structure again. 

Regarding the self-balancing tree system, this would have functioned either at the end of every insert function, or with a job running in the background, whose job would have been to scan the tree at all time, and check if both branches stemming for the root node are balanced or not. If they aren't, the job would have stored the elements of the tree in an array using inorder traversal. Inorder traversal of the tree would make a sorted array. Once we have a sorted array, I would've recursively construct a balanced binary search tree by picking the middle element of the array as the root for each subtree.

Apart from that, this project has allowed me to use vim a lot and has allowed me to become better at handling it.

I am deeply sorry that I wasn't able to make it far into the project but i have tried to do it to the best of my ability and i hope this effort will be acknowledged 
