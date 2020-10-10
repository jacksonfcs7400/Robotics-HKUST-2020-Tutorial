
> If you feel that the homework is too hard, do the [in-class exercise](https://hackmd.io/xwpeswfZTp6_oDtg8KrhFQ) first.
> 
> Also, feel free to dicuss with any mentors or me if you encounter any difficulties.

**Submission deadline**: 14/10 12:00

Author: Danny Lau (kkdlau@connect.ust.hk)

## Submissions and questions:
Please refer to the video.

# Tutorial 0 - Homework

## Q1: Factorial function（10 marks）
Factorial is the multiplication of all positive integers less than or equal to n, where n is a positive integer.

For example, `factorial(5)` returns 120, because `5 * 4 * 3 * 2 * 1 = 120`.

Use any looping technique to edit the code below, so that `uint64_t factorial(uint32_t f)` returns the proper result.

```c
#include <stdint.h>
#include <stdio.h>

// uint64_t = unsigned 64-bit integer
uint64_t factorial(uint32_t f) {
    // Please complete the function body
    return 0;
}

int main() {
    // You can modify main function for testing purpose
    for (int i = 0; i < 15; i++) {
        printf("%d! = %lu\n", i, factorial(i));
    }
    return 0;
}
```

### Note
* You cannot include `<math.h>`.
* Input of `uint64_t factorial(uint32_t f)` is guaranteed to be within [0, 15).

## Q2: Taylor series of sin(x), at a = 0 (15 marks)
In this task, you need to implement a sine function.

In math, the `sin` function can be expanded using the Taylor Series:

![](https://i.imgur.com/FMW41vY.png)

The more terms in the expansion, the more precise the value. In this task, we expand the series to the 7<sup>th</sup> term:

![](https://i.imgur.com/sJjwC2r.png)

Use the above series to edit the code below so that `float taylor_series_sin(float radian)` can return the value of sine properly.

```C
#include <stdint.h>
#include <stdio.h>

uint64_t factorial(uint32_t f) {
    // you can use your code from the previous task
    return 0;
}

float _pow(float x, int y) {
    // Please complete the function body
    return 0.0f;
}

float taylor_series_sin(float radian) {
    // Please complete the function body
    return 0.0f;
}

int main() {
    const float PI = 3.14159265f;
    float radian = PI / 3.0f;
    printf("sin(%f) = %f", radian, taylor_series_sin(radian));
    return 0;
}
```

### Note
* You cannot include `<math.h>`.
* You may not use the `pow()` function provided by the C standard library.

## Q3: Roman Numeral Converter (25 marks)

Roman numerals are a system that use letters to represent integers.

The table below lists the letters and their corresponding numerical value:


| Letter | Value  |
| ------ |:------:|
| `I`    |  `1`   |
| `V`    |  `5`   |
| `X`    |  `10`  |
| `L`    |  `50`  |
| `C`    | `100`  |
| `D`    | `500`  |
| `M`    | `1000` |

Let's take a look at some examples:
* `II`: 2 (`1 + 1`)
* `MDC`: 1600 (`1000 + 500 + 100`)
* `IV`: 4 (`5 - 1`)

For `II` and `MDC`, the result can be obtained by summing up the values. However, for `IV`, the value isn't `6`. This is because Roman Numerals consider the position of the letters. If a smaller value (e.g. `I`) appears before a larger value (e.g. `V`), the result is the larger value subtracted by the smaller value.

One more example:
* `CMXCIV`: 994 (`1000 - 100 + 100 - 10 + 5 - 1`)
    * `CM = 1000 - 100`, `XC = 100 - 10`, `IV = 5 - 1`

Edit the code below, so that `roman_to_int` converts a roman numeral (represented as a char array) to an integer.

```C
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int roman_to_int(const char s[], int length) {
    // Please complete the function body
    return 0;
}

int main() {
    char roman_num[] = "III";
    char roman_num_2[] = "CXXIII";
    char roman_num_3[] = "MMMCDLIX";

    printf("roman_to_int(%s) = %d\n", roman_num,
           roman_to_int(roman_num, strlen(roman_num)));
    printf("roman_to_int(%s) = %d\n", roman_num_2,
           roman_to_int(roman_num_2, strlen(roman_num_2)));
    printf("roman_to_int(%s) = %d\n", roman_num_3,
           roman_to_int(roman_num_3, strlen(roman_num_3)));
}
```

### Note

* You only need to decode roman numerals with values `< 4000`.
* **HINT**: A useful function used to find the length of a char array is `strlen`. For example, `strlen("HKUST")` returns `5` (`\n` is excluded!).

## Q4: Reverse Integer (20 marks)

In this task, you are requested to reverse the digits of a 32-bit signed integer.

Example:
```C
Given: 123456
Reverse: 654321
```

```C
Given: -902
Reverse: -209
```

Modify the code below, so that `int reverse(int x)` returns the proper result.
```C
#include <stdio.h>

int reverse(int x) {
    // Please complete the function body
    return 0;
}

int main() {
    int to_reverse = 123;
    printf("reverse %d = %d", to_reverse, reverse(to_reverse));
    return 0;
}
```

### Note

* Assume that the reversed value won't exceed `INT_MAX` (the maximum value of `int`s).

## Q5 (Bonus Question): Social Distancing (30 marks)

Danny wants to watch a movie in a cinema. To prevent the spread of coronavirus, staff require him to pick a seat that maximizes the distance between him and the closest person.

An array is used to describe the seating arrangement at the time Danny enters the cinema:
```c
int seats[] = {0, 1, 1, 0, 0, 0, 0, 0, 1};
```
`0` means the seat is empty, `1` means the seat is occupied.

Danny decides take a seat on `seats[5]`, because he will be 3 seats away from the closest neighbors on the left and right respectively.

Complete the code below such that the maximum distance is returned. (In the arrangement above, 3 is returned.) 
```c
#include <stdio.h>

int max_distance(int seats[], int length) {
    return 0;
}

int main() {
    int seats[] = {0, 1, 1, 0, 0, 0, 0, 0, 1};
    int length = sizeof(seats) / sizeof(seats[0]);
    printf("max_distance = %d", max_distance(seats, length));
    return 0;
}
```

### Test Cases
```c
int seats[] = {0, 1, 0, 0, 0};
```
```c
int seats[] = {0, 0, 0, 1, 0};
```
```c
int seats[] = {0, 1, 0, 0, 0, 0, 0, 1};
```
```c
int seats[] = {0, 1};
```
```c
int seats[] = {1, 0};
```
```c
int seats[] = {1, 0, 0, 1, 0, 0, 1};
```
### Note
* This is a bonus question. Bonus marks will be given if you can complete this task.
* Assume that there is at least one occupied seat and one empty seat.
* Danny is a poor guy, he watches films alone :cry: 
