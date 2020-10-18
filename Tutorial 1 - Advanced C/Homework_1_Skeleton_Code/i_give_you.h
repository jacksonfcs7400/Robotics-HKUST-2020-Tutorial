#define DATE_INPUT 'D'
#define IMPORT_FROM_FILE 'I'
#define SELECT_SAVED_DATA 'S'
#define END_PROGRAM 'E'

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} DAYS;

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} MONTHS;

typedef struct {
    int date;
    int month;
    int year;
    DAYS day;
    char name_of_holiday[50];
} day_info;

void opening(){
  printf("Welcome!\n");
  printf("This is Robotics Team Software Homework 1!\n");
  printf("Day Finder!\n");

}

void choice_menu(){
  printf("Please select your choice: \n");
  printf("D: Date Input \n");
  printf("I: Import From File \n");
  printf("S: Select Saved Data \n");
  printf("E: End Program \n");
}

void invalid_input_msg(){
  printf("Invalid input!\n");
  printf("Please input your choice again: \n");
}
