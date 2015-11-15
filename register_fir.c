#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* TRY TO MAKE MAXIMUM USE OF VARIOUS DATA STRUCTURES, AS THE PROJECT IS OF DATA STRUCTURES AND NOT DATA BASE MANAGEMENT */

/* MUCH OF THE PART OF THIS CODE IS WRITTEN IN NOTEPAD, S0 YOU NEED TO MAKE CHANGES IN THE QUOTES USED, AS NOTEPAD USES SPECIAL QUOTES */
// FREE ALL THE MEMORTY AT THE END OF THE FUNCTION WHICH WAS ALLOCATED DYNAMICALLY USING MALLOC

int register_fir () {
	/*
	 *   Get all the details as input from user
	 * Store them in a data structure
	 * Write this data structure in a file
	 * Maintain the format while writing to the file so that it will be easier to retrieve *    the data
	 * Update the criminal profile 
	 * Free the memory used to create data structure

	 */
	//MALLOC IS NEEDED TO BE DONE AS IN STRUCT WE JUST HAVE //CREATED POINTERS AND NOT RESERVED
	//IN EACH CASE AS WE TAKE THE INPUT WE NEED TO CHECK IF THE INPUT IS VALID. SO ADD THE CONDITION FOR CHECKING THE VALIDITY OF THE INPUT
	/* EACH TIME A MALLOC IS DONE ENSURE THAT A CORRESPONDING FREE IS WRITTEN FOR IT AT THE END */
	static int count = 0;
	FILE *fp;
	fir *tmp;
	char string[1024], filename[32];
	if ((fp = fopen("count.txt", "r")) == NULL ) {
		printf("Creating the count.txt file\n");
		fp = fopen("count.txt", "w");
		fprintf(fp, "%d", 1);
		fclose(fp);
	}
	else {
		fscanf(fp, "%d", &count);
		fclose(fp);
		fp = fopen("count.txt", "w");
		fprintf(fp, "%d", count + 1);
		fclose(fp);
	}
	tmp = (fir *)malloc(sizeof(fir));
	tmp->serial_num = count;
	/* Using the memory very carefully to avoid unnecessary allocation*/
	// Here you can specify to enter the day first, scan it and then take the next field. so that each time a value is taken as input we can immediately check if the data is valid or not.
	printf("Enter today’s date (day-month-yea)r\n");
	scanf("%s", string);
	tmp->date_of_register = (char *)malloc(strlen(string));
	strcpy(tmp->date_of_register, string);
	printf("\ndate of register = %s\n", tmp->date_of_register);

	printf("Enter date of event\n");
	scanf("%s", string);
	tmp->date_of_event = (char *)malloc(strlen(string));
	strcpy(tmp->date_of_event, string);
	printf("\ndate of event = %s\n", tmp->date_of_event);

	printf("Enter time of event(hours-minutes (in  24 hour format))\n");
	scanf("%s", string);
	tmp->time_of_event = (char *)malloc(strlen(string));
	strcpy(tmp->time_of_event, string);

	getchar();	
	
	printf("enter names of victims\n");
	fgets(string, 1024, stdin);
	tmp->victims = (char *)malloc(strlen(string));
	strcpy(tmp->victims, string);
	printf("victims = %s", tmp->victims);
	
	printf("enter names of criminals\n");
	fgets(string, 1024, stdin);
	tmp->criminals = (char*)malloc(strlen(string));
	strcpy(tmp->criminals, string);
	printf("criminals = %s\n", tmp->criminals);

	printf("enter names of witness\n");
	fgets(string, 1024,stdin);
	tmp->witness = (char *)malloc(strlen(string));
	strcpy(tmp->witness, string);
	printf("witness  = %s", tmp->witness);
	
	printf("enter the details of the event\n");
	fgets(string, 1024, stdin);
	tmp->details = (char *)malloc(strlen(string));
	strcpy(tmp->details, string);
	printf("details = %s", tmp->details);

	
	printf("please enter your name (the name of the person registering the fir)\n");
	fgets(string, 1024, stdin);
	tmp->registrar_name = (char *)malloc(strlen(string));
	strcpy(tmp->registrar_name, string);
	printf("registrar name = %s", tmp->registrar_name);
	
	sprintf(filename, "%d", count);
	strcat(filename, ".txt");
	if((fp = fopen(filename, "a+")) == NULL ) {
		printf("Error in opening file:");
		return -11;
	}	
		
	
	fprintf(fp, "%d\n", count);
	fprintf(fp, "%s\n", tmp->date_of_register);
	fprintf(fp, "%s\n", tmp->date_of_event);
	fprintf(fp, "%s\n", tmp->time_of_event);
	fprintf(fp, "%s\n", tmp->victims);
	fprintf(fp, "%s\n", tmp->criminals);
	fprintf(fp, "%s\n", tmp->witness);
	fprintf(fp, "%s\n", tmp->details);
	fprintf(fp, "%s\n", tmp->registrar_name);
	fclose(fp);
	printf("All the information has been successfully saved\n");
	return 0;
}


int search_criminal() {
	char filename[64], tmp1[32], tmp2[32], tmp3[32], tmp[1024];
	printf("Enter the name of the criminal whose information is needed\n");
	
	criminal1 *p;
	FILE *fp;
	char ch;
	int i = 0;
	p = (criminal1 *)malloc(sizeof(criminal1));
	
	printf("Enter the first name of the criminal\n");
	scanf("%s", tmp1);
	printf("Enter the middle name of the criminal\n");
	scanf("%s", tmp2);
	printf("Enter the surname name of the criminal\n");
	scanf("%s", tmp3);
	
	/* NOW FIRST CHECK IF SPACES ARE ALLOWES IN FILE NAME 
	   IF YES, THEN SET string AS THE FILE NAME
	   IF NO, THEN USE STRTOK, SPLIT THE NAME AND PUT A UNDERSCORE BETWEEN EACH NAME AND USE IT AS THE FILE NAME 
	*/
	strcpy(filename, tmp1);
	strcat(filename, tmp2);
	strcat(filename, tmp3);
	
	printf("The file to be opened is %s\n", filename);
	
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Cannot open %s file. Please check the name of criminal again\n", filename);
		return -1;
	}
	//READING THE DATA FROM FILE USING CHAR SCANF
	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->first_name, tmp);
	
		
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->middle_name, tmp);

	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->surname, tmp);
	
	fscanf(fp, "%d", &(p->age));
	fscanf(fp, "%d", &(p->height));
	
	fscanf(fp, "%c", &ch);
	
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->identification_marks, tmp);
	
	fscanf(fp, "%d", &(p->total_crimes));
	
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->details, tmp);
	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->curr_status, tmp);
	
	//THE INPUT FUNCTION ENDS HERE
	//DO NOT USE FSCANF AS IT READS UNTIL A SPACE IS OCCURED BUT WE WANT TO READ TILL \n IS FOUND		
	
	
	//Closing the file
	fclose(fp);
	printf("All the information has been successfully retrieved\n");
	
	//Printing the information to the screen	
	printf("First name = %s\n", p->first_name);
	printf("Middle name = %s\n", p->middle_name);
	printf("Surname = %s\n", p->surname);
	printf("Age = %d\n", p->age);
	printf("Height = %d\n", p->height);
	printf("Identification marks = %s\n", p->identification_marks);
	printf("Total number of crimes registered = %d\n", p->total_crimes);
	printf("Details = %s\n", p->details);
	printf("Current status of criminal = %s\n", p->curr_status);
	//Releasing the memory allocated during malloc
	free(p); //shift this free to the end of the block
	return 0;
}


int search_fir() {
	int count;
	fir1 *p;
	FILE *fp;
	char filename[32];
	p = (fir1 *)malloc(sizeof(fir1));
	printf("Enter the serial number of FIR to be viewed");
	scanf("%d", &count);
	sprintf(filename, "%d", count);
	strcat(filename, ".txt");
	printf("The file to be opened is %s\n", filename);
	if((fp = fopen(filename, "r")) == NULL) {
		printf("Cannot open %s file\n", filename);
		return -1;
	}
	fscanf(fp, "%d", &(p->serial_num));
	fscanf(fp, "%s", p->date_of_register);
	fscanf(fp, "%s", p->date_of_event);
	fscanf(fp, "%s", p->time_of_event);
	fscanf(fp, "%s", p->victims);
	fscanf(fp, "%s", p->criminals);
	fscanf(fp, "%s", p->witness);
	fscanf(fp, "%s", p->details);
	fscanf(fp, "%s", p->registrar_name);
	


	printf("\n\n\n");
	printf("The details of the FIR are as follows\n");
	printf("Serial number: %d\n", p->serial_num);
	printf("Date of register of fir: %s\n", p->date_of_register);
	printf("Date of event: %s\n", p->date_of_event);
	printf("Time of event: %s\n", p->time_of_event);
	printf("Name of victims: %s\n", p->victims);
	printf("Name of criminals: %s\n", p->criminals);
	printf("Name of witnesses %s\n", p->witness);
	printf("Details of the FIR: %s\n", p->details);
	printf("Registrar name: %s\n", p->registrar_name);

	return 0;
}



create_criminal_profile() {
	/*
	HERE THE VALUES ARE NOT GETTING STORED IN THE PROPER VARIABLES GETCHAR IS NEEDED TO BE USED AFTER EVERY INPUT FIND OUT THE REASON FOR IT */
	criminal *p;
	char tmp[1024], tmp1[32], tmp2[32], tmp3[32], filename[64];
	char ch;
	int i = 0;	
	FILE *fp;
	p = (criminal *)malloc(sizeof(criminal));
	getchar(); 	
	printf("Enter the name of the criminal\n");
	
	printf("Enter the first name of the criminal\n");
	scanf("%s", tmp1);
	p->first_name = (char *)malloc(strlen(tmp1));
	strcpy(p->first_name, tmp1);
	
	printf("Enter the middle name of the criminal\n");
	scanf("%s", tmp2);
	p->middle_name = (char *)malloc(strlen(tmp2));
	strcpy(p->middle_name, tmp2);
	
	printf("Enter the surname of the criminal\n");
	scanf("%s", tmp3);
	p->surname = (char *)malloc(strlen(tmp3));
	strcpy(p->surname, tmp3);	

	printf("Enter the age of the criminal\n");
	scanf("%d", &(p->age));
	
	printf("Enter the height (in centimeters)) of the criminal\n");
	scanf("%d", &(p->height));

	getchar(); 	
	printf("Enter the identification marks (if any) of the criminal\n");

	//THE CODE BELOW IS TO TAKE THE INPUT FROM THE USER
	//ALSO CHECK SEPARATELY USING ANOTHER CODE THAT CAN STRCPY COPY STRINGS THAT CONTAIN SPACES BETWEEN THEM. IF NOT THEN WRITE THE FUNCTION FOR COPYING THE STRINGS
	strcpy(tmp, "");	
	ch = getchar();	
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		ch = getchar();		
	}
	tmp[i] = '\0';
	printf("tmp = %s\n", tmp);
	
	p->identification_marks = (char *)malloc (strlen(tmp));
	strcpy(p->identification_marks, tmp);
	printf("p->identification = %s\n", p->identification_marks);	
	printf("Enter the total number of crimes registered on the name of the criminal\n");
	scanf("%d", &(p->total_crimes));
	
	getchar();	
	printf("Enter any specific details about the criminal\n");
	strcpy(tmp, "");	
	ch = getchar();
	i = 0;	
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		ch = getchar();		
	}
	tmp[i] = '\0';
	printf("tmp = %s\n", tmp);	
	p->details = (char *)malloc(strlen(tmp));
	strcpy(p->details, tmp);
	printf("details = %s\n", p->details);
	printf("p->details = %s\n", p->details);

	printf("Enter the current status of the criminal\n");
	strcpy(tmp, "");	
	ch = getchar();
	i = 0;	
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		ch = getchar();		
	}
	tmp[i] = '\0';
	printf("tmp = %s\n", tmp);	

	p->curr_status = (char *)malloc(strlen(tmp));
	strcpy(p->curr_status, tmp);
	printf("p->curr = %s", p->curr_status);	
	printf("tmp1 = '%s'\n", tmp1);
	printf("tmp2 = '%s'\n", tmp2);
	printf("tmp3 = '%s'\n", tmp3);	
	
	
	strcpy(tmp, tmp1);
	strcat(tmp, tmp2);
	strcat(tmp, tmp3);
	printf("tmp = %s\n", tmp);
	strcpy(filename, tmp);
	
	
	//Opening the file in write mode	
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Cannot open %s file. Please check if sufficient memory is available\n", filename);
		return -1;
	}
	
	//Writing the data to the file	
	fprintf(fp, "%s\n", p->first_name);
	fprintf(fp, "%s\n", p->middle_name);
	fprintf(fp, "%s\n", p->surname);
	fprintf(fp, "%d\n", p->age);
	fprintf(fp, "%d\n", p->height);
	fprintf(fp, "%s\n", p->identification_marks);
	fprintf(fp, "%d\n", p->total_crimes);
	fprintf(fp, "%s\n", p->details);
	fprintf(fp, "%s\n", p->curr_status);	
	
	fclose(fp);
	printf("All the information has been successfully saved\n");
	
	free(p); 
	return 0;
}


int update_fir() {
	int count;
	char filename[32], tmp[1024];
	FILE *fp;
	fir1 *p;
	p = (fir1 *)malloc (sizeof(fir1));
	printf("Enter the serial number of fir to be searched\n");
	scanf("%d", &count);
	sprintf(filename, "%d", count);
	strcat(filename, ".txt");
	if ((fp = fopen(filename, "r")) == NULL ) {
		printf("Cannot open file %s\n", filename);
		return -1;
	}
	fscanf(fp, "%d", &(p->serial_num));
	fscanf(fp, "%s", p->date_of_register);
	fscanf(fp, "%s", p->date_of_event);
	fscanf(fp, "%s", p->time_of_event);
	fscanf(fp, "%s", p->victims);
	fscanf(fp, "%s", p->criminals);
	fscanf(fp, "%s", p->witness);
	fscanf(fp, "%s", p->details);
	fscanf(fp, "%s", p->registrar_name);
	fclose(fp);
	/* CLOSE THE FILE AS SOON AS INPUT IS TAKEN FROM IT */
		
	printf("\n\n\n");
	printf("The details of the FIR are as follows\n");
	printf("Serial number: %d\n", p->serial_num);
	printf("Date of register of fir: %s\n", p->date_of_register);
	printf("Date of event: %s\n", p->date_of_event);
	printf("Time of event: %s\n", p->time_of_event);
	printf("Name of victims: %s\n", p->victims);
	printf("Name of criminals: %s\n", p->criminals);
	printf("Name of witnesses %s\n", p->witness);
	printf("Details of the FIR: %s\n", p->details);
	printf("Registrar name: %s\n", p->registrar_name);
	
	printf("Select any one of the option from below\n");
	printf("Choose which field of the FIR do you wish to modify\n");
	printf("1. Date of event\n");
	printf("2. Time of event\n");
	printf("3. Name of victims\n");
	printf("4. Name of criminals\n");
	printf("5. Name of witnesses\n");
	printf("6. Details of the FIR\n");
	printf("7. Name of registrar\n");
	
	scanf("%d", &count);
	switch (count) {
		case 1:
				printf("\nWould you like to append or change the contents \nEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->date_of_event, tmp);
					printf("%s\n", p->date_of_event);
				}
				else {
					printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->date_of_event, tmp);
					printf("%s\n", p->date_of_event);
				}					
					
				break;

		case 2:
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->time_of_event, tmp);
					printf("%s\n", p->time_of_event);
				}
				else {
					printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->time_of_event, tmp);
					printf("%s\n", p->time_of_event);
				}
				break;
		case 3:
				
				printf("Would you like to append or change the contents\tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->victims, tmp);
					printf("%s\n", p->victims);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->victims, tmp);
					printf("%s\n", p->victims);
				}

				break;
		case 4:	
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();				
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->criminals, tmp);
					printf("%s\n", p->criminals);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->criminals, tmp);
					printf("%s\n", p->criminals);
				}

				break;
		case 5:	
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->witness, tmp);
					printf("%s\n", p->witness);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->witness, tmp);
					printf("%s\n",p->witness);
				}

				break;
		case 6:
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar(); 
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->details, tmp);
					printf("%s\n", p->details);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->details, tmp);
					printf("%s\n", p->details);
				}
				break;
		case 7:	
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->registrar_name, tmp);
					printf("%s\n", p->registrar_name);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->registrar_name, tmp);
					printf("%s\n", p->registrar_name);
				}

				break;
		default:
				break;
	}	
				
	/* NOW WRITE THE MODIFIED STRUCTURE BACK TO THE FILE */
	/* OPENING THE FILE IN WRITE MODE SO THAT THE PREVIOUS CONTENTS ARE OVERWRITTEN */
	if ((fp = fopen(filename, "w")) == NULL ) {
		printf("Error in opening file:");
		return -11; 
	}	
	fprintf(fp, "%d\n", count);
	fprintf(fp, "%s\n", p->date_of_register);
	fprintf(fp, "%s\n", p->date_of_event);
	fprintf(fp, "%s\n", p->time_of_event);
	fprintf(fp, "%s\n", p->victims);
	fprintf(fp, "%s\n", p->criminals);
	fprintf(fp, "%s\n", p->witness);
	fprintf(fp, "%s\n", p->details);
	fprintf(fp, "%s\n", p->registrar_name);
	fclose(fp);
	printf("Modifications saved to the file successfully\n");

return 0;
}


int update_criminal_profile() {

	
	char filename[128], tmp[1024],  tmp1[32], tmp2[32], tmp3[32], query[128];
	FILE *fp;
	int count = 0;
	criminal1 *p;
	int i = 0;
	char ch;
	p = (criminal1 *)malloc (sizeof(criminal1));
	//Use the part from search criminal here to formulate the file name from the criminal name
	// Also use it to display the current information stored in the file
		
	printf("Enter the first name of the criminal\n");
	scanf("%s", tmp1);
	printf("Enter the middle name of the criminal\n");
	scanf("%s", tmp2);
	printf("Enter the surname name of the criminal\n");
	scanf("%s", tmp3);
	strcpy(filename, tmp1);
	strcat(filename, tmp2);
	strcat(filename, tmp3);
	if ((fp = fopen(filename, "r")) == NULL ) {
		printf("Cannot open file %s\n", filename);
		return -1;
	}
	
	//Reading the data from the file	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->first_name, tmp);
	
		
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->middle_name, tmp);

	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->surname, tmp);
	
	fscanf(fp, "%d", &(p->age));
	fscanf(fp, "%d", &(p->height));
	
	fscanf(fp, "%c", &ch);
	
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->identification_marks, tmp);
	
	fscanf(fp, "%d", &(p->total_crimes));
	
	if (ch == '\n') {
		printf("\n detected after height");
		fscanf(fp, "%c", &ch);
	}
	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->details, tmp);
	
	fscanf(fp, "%c", &ch);
	i = 0;
	while (ch != '\n') {
		tmp[i] = ch;
		i++;
		fscanf(fp, "%c", &ch);
	}
	tmp[i] = '\0';
	strcpy(p->curr_status, tmp);
	

	//Closing the file
	fclose(fp);
	printf("All the information has been successfully retrieved\n");
	
	//Printing the information to the screen	
	printf("First name = %s\n", p->first_name);
	printf("Middle name = %s\n", p->middle_name);
	printf("Surname = %s\n", p->surname);
	printf("Age = %d\n", p->age);
	printf("Height = %d\n", p->height);
	printf("Identification marks = %s\n", p->identification_marks);
	printf("Total number of crimes registered = %d\n", p->total_crimes);
	printf("Details = %s\n", p->details);
	printf("Current status of criminal = %s\n", p->curr_status);
	
	//The part used from search criminal ends here.

	//USE A WHILE (1) HERE
	printf("Select any one of the option from below\n");
	printf("Choose which field of the FIR do you wish to modify\n");
	printf("1. First name\n");
	printf("2. Middle name\n");
	printf("3. Surname\n");
	printf("4. Age\n");
	printf("5. Height\n");
	printf("6. Identification Marks\n");
	printf("7. Total number of crimes\n");
	printf("8. Details\n");
	printf("9. Curret status\n");
	
	scanf("%d", &count);
	//VERY IMP
	//For cases 1, 2, and 3 as the name changes we also have to change the name of the file. So make provision for it also.
	//So if the name changes then delete the previous file and and change string filename accordingly	
	/* INCLUDE WHILE (1) HERE */
	switch (count) {
		case 1:
				printf("\nWould you like to append or change the contents \nEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  //this is used to flush the contents of the stdin buffer
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					scanf("%s", tmp);					
					strcat(p->first_name, tmp);
					printf("%s\n", p->first_name);
				}
				else {
					printf("Enter the contents to be replaced\n");					
					scanf("%s", tmp);					
					strcpy(p->first_name, tmp);
					printf("%s\n", p->first_name);
				}					 
				strcpy(query, "rm ");
				strcat(query, filename);
				system(query);				
				strcpy(filename, p->first_name);
				strcat(filename, tmp2);
				strcat(filename, tmp3);
				break;

		case 2:
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					scanf("%s", tmp);					
					strcat(p->middle_name, tmp);
					printf("%s\n", p->middle_name);
				}
				else {
					printf("Enter the contents to be replaced\n");					
					scanf("%s", tmp);		
					strcpy(p->middle_name, tmp);
					printf("%s\n", p->middle_name);
				}				
				strcpy(query, "rm ");
				strcat(query, filename);
				system(query);				
				strcpy(filename, tmp1);
				strcat(filename, p->middle_name);
				strcat(filename, tmp3);
				break;
		case 3:
			
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					scanf("%s", tmp);
					strcat(p->surname, tmp);
					printf("%s\n", p->surname);
				}
				else {
				
				 	printf("Enter the contents to be replaced\n");					
					scanf("%s", tmp);
					strcpy(p->surname, tmp);
					printf("%s\n", p->surname);
				}

				//This part is to change the filename				
				strcpy(query, "rm ");
				strcat(query, filename);
				system(query);				
				strcpy(filename, tmp1);
				strcat(filename, tmp2);
				strcat(filename, p->surname);

				break;
		case 4:	
				
				
				printf("You can only change the contents here\n");
				printf("Enter the contents to be replaced\n");					
				scanf("%d", &count);
				p->age = count;
				printf("%d\n", p->age);
				break;
		
		case 5:	
				printf("You can only change the contents here\n");
				printf("Enter the contents to be replaced\n");					
				scanf("%d", &count);
				p->age = count;
				printf("%d\n", p->age);
	
				break;
		case 6:
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  //this is used to flush the contents of the stdin buffer
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->identification_marks, tmp);
					printf("%s\n", p->identification_marks);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->identification_marks, tmp);
					printf("%s\n", p->identification_marks);
				}
				break;
		case 7:	
				printf("You can only change the contents here\n");
				printf("Enter the contents to be replaced\n");					
				scanf("%d", &count);
				p->age = count;
				printf("%d\n", p->age);
	
		
				break;
		
		case 8:
				
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  //this is used to flush the contents of the stdin buffer
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->details, tmp);
					printf("%s\n", p->details);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->details, tmp);
					printf("%s\n", p->details);
				}
				break;
		
		case 9:
			
				
				printf("Would you like to append or change the contents \tEnter your choice\n");
				printf("1. Append\n");
				printf("2. Change\n");
				scanf("%d", &count);
				getchar();  //this is used to flush the contents of the stdin buffer
				if (count == 1) {
					printf("Enter the contents to be appended\n");
					fgets(tmp, 1024, stdin);
					strcat(p->curr_status, tmp);
					printf("%s\n", p->curr_status);
				}
				else {
				 	printf("Enter the contents to be replaced\n");					
					fgets(tmp,1024, stdin);
					strcpy(p->curr_status, tmp);
					printf("%s\n", p->curr_status);
				}
				break;

		default:
				printf("Please Enter a valid choice\n");				
				break;
	}	
				
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Cannot open %s file. Please check if sufficient memory is available\n", filename);
		return -1;
	}
	//Writing the data to the file	
	fprintf(fp, "%s\n", p->first_name);
	fprintf(fp, "%s\n", p->middle_name);
	fprintf(fp, "%s\n", p->surname);
	fprintf(fp, "%d\n", p->age);
	fprintf(fp, "%d\n", p->height);
	fprintf(fp, "%s\n", p->identification_marks);
	fprintf(fp, "%d\n", p->total_crimes);
	fprintf(fp, "%s\n", p->details);
	fprintf(fp, "%s\n", p->curr_status);	
	
	//Closing the file
	fclose(fp);
	printf("All the information has been successfully saved\n");
	
	free(p); 
	

	return 0;
}


int show_all_records() {
	
	int count = 0;
	fir1 *p;
	FILE *fp;
	char filename[32];
	p = (fir1 *)malloc(sizeof(fir1));
	sprintf(filename, "%d", count);
	strcat(filename, ".txt");
	printf("The file to be opened is %s\n", filename);
	if((fp = fopen(filename, "r")) == NULL) {
		printf("Cannot open %s file\n", filename);
		return -1;
	}
	while (fp != NULL) {


	/* READING THE CONTENTS OF FILE INTO A STRUCTURE ADD 	\n AT THE END OF EACH PRINTF AND FPRITNTF*/
	
		fscanf(fp, "%d", &(p->serial_num));
		fscanf(fp, "%s", p->date_of_register);
		fscanf(fp, "%s", p->date_of_event);
		fscanf(fp, "%s", p->time_of_event);
		fscanf(fp, "%s", p->victims);
		fscanf(fp, "%s", p->criminals);
		fscanf(fp, "%s", p->witness);
		fscanf(fp, "%s", p->details);
		fscanf(fp, "%s", p->registrar_name);
		fclose(fp);
	
		printf("\n\n\n");
		printf("The details of the FIR are as follows\n");
		printf("Serial number: %d\n", p->serial_num);
		printf("Date of register of fir: %s\n", p->date_of_register);
		printf("Date of event: %s\n", p->date_of_event);
		printf("Time of event: %s\n", p->time_of_event);
		printf("Name of victims: %s\n", p->victims);
		printf("Name of criminals: %s\n", p->criminals);
		printf("Name of witnesses %s\n", p->witness);
		printf("Details of the FIR: %s\n", p->details);
		printf("Registrar name: %s\n", p->registrar_name);
		
		//opening a new file
		sprintf(filename, "%d", ++count);
		strcat(filename, ".txt");
		printf("The file to be opened is %s\n", filename);
		fp = fopen(filename, "r");
	


	}	
	return 0;
}


