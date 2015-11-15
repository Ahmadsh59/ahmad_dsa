Title-Register FIR
Name-Ahmad Shaikh
Mis-111308059
-----------------------------------------------------------------------------------------------------------------------------------------------
1. How to keep on incrementing the value of count even if the program keeps terminating. One possible solution is to maintain a file and to write the updated value of count to it by opening it in w mode each time we want to overwrite its contents once they have been read.
2. Instead of using fir use the new fir1 as it is better in all aspects.
3. Instead of saving the files of fir and criminal profiles in the current folder, use the system() command to create a new folder for the first time and then cd to the folder to save the files of that type.
4. Include a title field for each fir and you can use the title also in the name of the file stored as fir.
5. When the name of the file is decided, then why does a question mark appear after using strcat?
6. Make minimum possible use of fgets. You can see some of the blank lines when you open the files in gedit. This is due to the Enter character stored in stdin and which causes an additional of one line to be stored.
7. Make minimum possible use of fgets. As it causes a lot of errors.
8. When displaying the information about a criminal, specify that this is age, this is height etc
9. When we enter text with spaces in between then fgets is giving some errors.
10. Wherever we have used the struct criminal and fir replace it with criminal1 and fir1 respectively.
11. When we tried to change the contents of the criminal, a '\n' is added to the file and hence we cannot read the further data. To avoid this add a check for '\n' before each data is taken from file .

