**Submission deadline**: 21/10/2020 12:00n.n.

Author: Chalex (cwchanbm@connect.ust.hk)

Skeleton Code is provided, you should be able to find it in the same folder

# Tutorial 1 - Homework [Day Finder]

In this homework, you are going to write a program to find the day of a given date. The program should also be able to tell you whether the day is special or not.


As a bonus task, you may export these dates into a .txt file and import them for future use.

## Brief flow chart of what the program should do
![](https://i.imgur.com/of8sArr.png)


## Task 0: Validating Your choice of input
* Get the input of choice using the `scanf` function
* The input will be using 1 character (i.e. 1 alphabet or 1 symbol or 1 numeric number)
* There will be 4 valid inputs in total
    * 'D' for the date input feature
    * 'F' for the import from file feature
    * 'S' for the select saved data feature
    * 'E' for ending the program immediately
* Validate the input before moving forward to other tasks
    * Use the following `#define` for validating

```C
#define DATE_INPUT 'D'
#define IMPORT_FROM_FILE 'F'
#define SELECT_SAVED_DATA 'S'
#define END_PROGRAM 'E'
```


## Task 1: Separating the Input
* Get input using the `scanf` function.
* The input will be in the format DD/MM/YYYY (e.g. 30/04/2019).
* Separate the input into a date, month and year.
    * You should use the following code to enumerate months.
```c
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
```
* Assign the date, month, and year to the given struct. (Except for the day and name_of_special_day[30])
```c
typedef struct {
    int date;
    int month;
    int year;
    DAYS day;
    char name_of_special_day[30];
} day_info;
```
* Check if the input is valid, output the dedicated output message and let the user input the date again


## Task 2: Show the information
* Find the day of the inputted date. (Given: 01/01/0001 is a Saturday)
    * You should use the following code to enumerate days.
```c
typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} DAYS;
```
* Find whether the day is a holiday according to the table below. (Assume that holidays happen on the same date every year.) ~~[These holidays are randomly assigned]~~


| Date         | Holiday                       |
|:------------ |:----------------------------- |
| 01/01        | First Day of January          |
| 29/01        | Birthday of the Great Tim Woo |
| 10/03        | Mario Day                     |
| 31/03        | World Backup Day              |
| 10/04        | Whatever Day                  |
| 13/04        | Easter                        |
| 11/05        | National Technology Day       |
| 06/06        | D-Day                         |
| 25/12        | Christmas                     |
| 26/12        | Boxing Day                    |
| Every Sunday | Sunday                        |
> If a day is both a Sunday and another holiday, please output both.


## Task 3: Save the information
Save the above information into an array of `day_info` (in the format below) for future usage. (Save it to the `day` and `name_of_special_day`)
```c
typedef struct {
    int date;
    int month;
    int year;
    DAYS day;
    char name_of_special_day[30];
} day_info;
```

## Task 4: Implement the select saved data function
* Check whether there is saved data
* If there is no saved data, tell the user to select another choice again
* If there is saved data, then proceed and list all the saved data out
* The user should choose one of the saved data and the program should print it out
* After printing the saved data, the program goes back to the select choice state

## Bonus Task: Add export and import function for the details
* Add a function for exporting the array of day_info to a .txt file
* Add a function for importing the .txt file and import the array from the file as well
> Not only does this task test your technical skills, it tests your GOOGLE skills as well. Please find how to deal with files from the Internet yourself.



## Homework Submission
1. Fork the repository from `HKUST-Robotics-Team` Github account (hkustroboticsteam@gmail.com) and push the code into the file HW for tutorial 1
2. Add `HKUST-Robotics-Team` on Github as an outside collaborator

For more information please watch the video provided in tutorial 0.

## For Further Questions
Send an email to any software senior's email or ask it in the Whatsapp grouop


