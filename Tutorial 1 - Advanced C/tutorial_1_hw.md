**Submission deadline**: 21/10/2020 12:00 n.n. HKT

Author: Chalex (cwchanbm@connect.ust.hk)

Skeleton code is provided in the same folder containing this document.

# Tutorial 1 - Homework [Day Finder]

In this homework, you are going to write a program to find the day of a given date. The program should also be able to tell you whether the day is a holiday or not.

As a bonus task, your program may also export these dates into a .txt file and import them later on.

## Flow Chart of Tasks
![](https://i.imgur.com/of8sArr.png)

## Task 0: Implement the Menu ( 10 marks )
* When the program starts, the menu should be printed.
* In the menu, the program should allow the user to select a choice among the given options:
    * 'D' for the "date input" feature
    * 'I' for the "import from file" feature
    * 'S' for the "select saved data" feature
    * 'E' for ending the program immediately
* The input will consist of 1 character (i.e. 1 alphabet or symbol or digit).
* If the input is invalid, use `invalid_input_msg()` to inform the user, and let the user input the date again.
* Use the following `#define`s provided to validate the input:

```C
#define DATE_INPUT 'D'
#define IMPORT_FROM_FILE 'I'
#define SELECT_SAVED_DATA 'S'
#define END_PROGRAM 'E'
```

## Task 1: Separating the Input ( 10 marks )
* Read input in the format DD/MM/YYYY (e.g. 30/04/2019).
* The inputted date will be after 01/01/1800.
* Check if the input is valid, use the provided `invalid_input_msg()` function to inform the user of the invalid input and let the user input a date again.
	* Invalid input here means out-of-bound month or date.
* Separate the input into date, month, and year.
    * You should use the provided `MONTHS` enum to enumerate months:
    
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
	
* Assign the date, month, and year to the corresponding members of the provided `day_info` struct.

	```c
	typedef struct {
	    int date;
	    int month;
	    int year;
	    DAYS day;
	    char name_of_holiday[50];
	} day_info;
	```

## Task 2: Determine Whether the Day is Special ( 35 marks )
* Find the day of the inputted date that you acquired from task 1.
* Leap years should be considered.
* It is given that 01/01/1800 is a Wednesday.
* You should use the provided `DAYS` enum to enumerate days:

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

* Find whether the day is a holiday according to the table below. (Assume that each holiday happens on the same date annually.) 

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

* Sample I/O:

	```
	Please input a date (DD/MM/YYYY): 17/10/2020
	Day: Saturday
	Name of holiday: Not a holiday
	```
	
	```
	Please input a date (DD/MM/YYYY): 26/12/1994
	Day: Monday
	Name of holiday: Boxing Day
	```
	
	```
	Please input a date (DD/MM/YYYY): 31/03/2013
	Day: Sunday
	Name of holiday: World Backup Day, Sunday
	```

### Note
* You may verify your output with [timeanddate.com's weekday calculator](https://www.timeanddate.com/date/weekday.html).

## Task 3: Save the Day and Name of Holiday ( 5 marks )
 * Save the above information into a global `day_info` array of  size 30 for future usage.
 * If the date is not a holiday, then save `"Not a holiday"` into `name_of_holiday`.

### Note
* If you want to modify the struct, you are always welcome to do so.

## Task 4: Implement the Select Saved Data Feature ( 20 marks )
* Check whether there is saved data.
* If there is no saved data, tell the user to select another choice again.
* If there is saved data, then proceed and print the list of saved data out
* Please print the list of saved data in the following format:

	```C
	Here is the list of saved data:
	1. 30/01/2020
	2. 06/06/2004
	3. 01/01/1933
	```
* The user should choose one of the saved data by entering a number and the program should print out the corresponding item.
    * Sample I/O:
    
	```c
	Please select the saved data from the list:
	1
	Date: 30
	Month: January
	Year: 2020
	Day: Thursday
	Name of holiday: Not a holiday
	It is not a holiday... :(
	```

	```c
	Please select the saved data from the list:
	2
	Date: 06
	Month: June
	Year: 2004
	Day: Sunday
	Name of holiday: D-Day, Sunday
	It is a holiday! :)
	```
	
	```c
	Please select the saved data from the list:
	3
	Date: 01
	Month: January
	Year: 1931
	Day: Thursday
	Name of holiday: First day of January
	It is a holiday! :)
	```
* After printing the saved data, the program goes back to the menu state.

## Bonus Task: Add export and import function for the details ( 20 marks )
* Add a function for exporting the array of `day_info` to a .txt file.
* Add a function for importing `day_info` data from the .txt file into the array.

> Not only does this task test your technical skills, it tests your GOOGLE skills as well. Find out for yourself how to deal with files in C.

## FAQ
**Q:** What can I modify?  
**A:**  In `i_give_you.h`, you can add anything but you are not allowed to remove anything . 
In `main.c`, you can modify everything except for the `main()` function and the `#include` headers. This means that you cannot include additional libraries other than the ones already included.

## Homework Submission
Submit both `i_give_you.h` and `main.c`. Please push them to the Homework 1 folder in your homework repository.

For more information, please watch the video provided in tutorial 0.

## For Further Questions
Send an email to any software senior or ask in the WhatsApp group.
