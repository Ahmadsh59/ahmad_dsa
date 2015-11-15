#ifndef __HEADER_H__
#define __HEADER_H__

typedef struct fir {
        int serial_num;
        char *date_of_register;
        char *date_of_event;
        char *time_of_event;
        char *victims;
        char *criminals;
        char *witness;
        char *details;
        char *registrar_name;
}fir;
typedef struct fir1 {
        int serial_num;
        char date_of_register[32];
        char date_of_event[32];
        char time_of_event[32];
        char victims[1024];
        char criminals[1024];
        char witness[1024];
        char details[1024];
        char registrar_name[1024];
}fir1;

typedef struct criminal {
        char *first_name;
	char *middle_name;
	char *surname;
        int age;
        int height;
        char *identification_marks;
        int total_crimes;
        char *details;
        char *curr_status;
}criminal;
typedef struct criminal1 {
        char first_name[32];
	char middle_name[32];
	char surname[32];
        int age;
        int height;
        char identification_marks[1064];
        int total_crimes;
        char details[1064];
        char curr_status[1064];
}criminal1;

int register_fir();
int search_criminal();
int search_fir();
int update_information();
int update_fir();
int update_criminal_profile();
int show_all_records();
int show_all_criminal();

#endif
