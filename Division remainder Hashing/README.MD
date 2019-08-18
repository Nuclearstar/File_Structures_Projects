# Division remainder Hashing

Both the files are codes implementing division remainder hashing.
1. The file hash2.c is a very simple implementation of division remainder hashing.
2. The file hashing_master.c is a menu driven program of division remainder hashing which shows the detailed implementation of it.

## ALGORITHM:

1)	Set the size of the hash table to a fixed number (n).

2)	User enters the number (k) to be stored.

3)	Calculate (k mod m). Result will be the location of the number to be stored, if location does not contain any valid data. Else, error!

4)	To search for the existence of a number, let he user enter the number to be searched. Apply the formula (k mod n), if the location contains valid number, the number is found. Else the entered number doesn’t exist.
