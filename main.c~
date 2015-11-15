#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main () {	
	int choice;
	while (1) {
		printf("Please enter any one of the choices from below\n");
		printf("1. Register FIR\n");
		printf("2. Search Criminal\n");
		printf("3. Search FIR\n");
		printf("4. Create criminal profile\n");
		printf("5. Update FIR\n");
		printf("6. Update Criminal profile\n");
		printf("7. Show all records\n");
		printf("8. Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case (1):
				register_fir();
				break;
			case (2):
				search_criminal();
				break;
			case (3):
				search_fir();
				break;		
			case (4):
				create_criminal_profile();
				break;	
			case (5):
				update_fir();
				break;	
			case (6):
				update_criminal_profile();
				break;	
			case (7): 
				show_all_records();
				break;	
			case (8):
				return 0;
			default :
				printf("Please enter valid input\n");
		}
	}
}

