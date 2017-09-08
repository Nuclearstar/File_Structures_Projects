Both the files are the codes implementing index on secondary key for a file of student objects.

First file is the code written in C++ whereas the second one is implemented using C.

ALGORITHM:
Secondary indexing

1)	Open 3 files, to store primary index, secondary index and the data.
Data file has 5 fields, name, roll number and 3 subjects’ marks. Secondary index file has name and roll number fields. Primary index file has roll number and relative record number fields.

2)	To add records, user enters the details. Copy the respective details to each of the respective files.

3)	To search for a record based on secondary index, user enters the name of the student whose record is to be retrieved.

4)	Search for the name entered in the secondary index file. If found, and if duplicate names exist, roll number of the student also to be entered. With the help of corresponding roll number, retrieve the RRN from the primary index file. Display the data on the output console corresponding to the RRN retrieved.

5)	To delete a record from the data file.

6) Update the index file to reflect the changes in the data file.
