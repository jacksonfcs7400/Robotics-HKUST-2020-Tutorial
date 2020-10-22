Author: Danny Lau (kkdlau@connect.ust.hk)  
Feedback from: Various Mentors

# Contents

* Answers
	* [Q1](#q1-factorial-function)
	* [Q2](#q2-taylor-series-of-sinx)
	* [Q3](#q3-roman-numeral-converter)
	* [Q4](#q4-reverse-integer)
	* [Q5](#q5bonus-question-social-distancing)
* [Feedback](#general-general-feedback)

# Tutorial 0 - Suggested Answer

Please note that the answers can be shortened. But I think readability is more important :laughing: 

Feel free to discuss with software mentors or me if you encounter any difficulty~

## Q1: Factorial function
### Using for loop
```c
uint64_t factorial(uint32_t f) {
    uint64_t result = 1;
    for (; f > 1; f = f - 1) {
        result = result * f;
    }
    return result;
}
```

### Using recursion
```c
uint64_t factorial(uint32_t f) {
    return f > 1? factorial(f - 1) * f: 1;
}
```

Please note that you need handle a special case `0! = 1`.

Usually we handle negative numbers by returning `-1`, however, since the paramemter is `uint64_t`, we can assume no negative numbers are passed into the function.

### General Factorial Function
```c
uint64_t factorial(int f) {
    if (f < 0)    // special case: neative integer
        return -1;
    if (f == 0)   // or if (!f),
        return 1; // but f == 0 is more readable
    
    return f > 1? factorial(f - 1) * f: 1; 
}
```

### General Feedback

Most people did fine with this question.

The major trip-up was using a smaller integer type, such as `int`, to store the result. However, the largest factorial a 32-bit int could hold is 12!. The fix was using a larger type (e.g. `uint64_t`) instead.

## Q2: Taylor series of sin(x)

```c
#include <stdint.h>
#include <stdio.h>

uint64_t factorial(uint32_t f) {
    uint64_t result = 1;
    for (; f > 1; f = f - 1) {
        result = result * f;
    }
    return result;
}

float _pow(float x, int y) {
    float result = 1.0f;

    // for (; y > 0; y--, result *= x); is also valid
    for (; y > 0; y = y - 1) {
        result = result * x;
    }

    return result;
}

float taylor_series_sin(float radian) {
    float result = 0.0f;  // actually .0f is the same
    for (int x = 0; x <= 6; x = x + 1) {
        if (x % 2 == 1) {
            result = result - _pow(radian, 2 * x + 1) /
            factorial(2 * x + 1);
        } else {
            result = result + _pow(radian, 2 * x + 1) /
            factorial(2 * x + 1);
        }
    }
    return result;
}

int main() {
    const float PI = 3.14159265f;
    float radian = PI / 3.0f;
    printf("sin(%f) = %lf", radian, taylor_series_sin(radian));
    return 0;
}
```

### Using tenary operator to simplify taylor_series_sin
```c
float taylor_series_sin(float radian) {
    float result = .0f;
    for (int x = 0; x <= 6; x = x + 1) {
        result += (x % 2? -1 : 1) * 
            _pow(radian, 2 * x + 1) / factorial(2 * x + 1);
    }
    return result;
}
```

#### Observation

Some people try to use `_pow` instead of `if` / `tenary operator` to simplify statements:

```c
result += _pow(-1, x) * 
            _pow(radian, 2 * x + 1) / factorial(2 * x + 1);
```

Although it may be a good idea, however, in terms of efficiency, using `_pow` is not the best solution. It's because `_pow` **consume more computation power** (`_pow` is implemented by iteration!) than `if` and `tenary operator`. 

### General Feedback
Most people did well on this. Those who used `int` instead of `uint64_t` in Q1 failed some test cases due to 13! messing up the sum.

## Q3: Roman Numeral Converter

### Using function
```c
int letter_to_int(const char letter) {
    // of course use switch is ok
    if (letter == 'I')
        return 1;
    if (letter == 'V')
        return 5;
    if (letter == 'X')
        return 10;
    if (letter == 'L')
        return 50;
    if (letter == 'C')
        return 100;
    if (letter == 'D')
        return 500;
    if (letter == 'M')
        return 1000;
    return 0; // handle exception
}

int roman_to_int(const char s[], int length) {
    int sum = 0;
    int end = length - 1;
    
    /**
     * Please note that, length - 1 is assigned to end.
     * It looks silly but actually it is an optimization.
     * If you replace 'i < end' by 'i < length - 1',
     * then the program computes length - 1 every iteration.
     * But the value of length is constant, so the value of 
     * length - 1 is constant as well.
     * 
     * So, it is redundant to compute length - 1 
     * in every iteration.
     */
    for (int i = 0; i < end; i++) {
        if (letter_to_int(s[i + 1]) > letter_to_int(s[i]))
            sum -= letter_to_int(s[i]);
        else
            sum += letter_to_int(s[i]);
    }
    return sum + letter_to_int(s[length - 1]);
}
```

### Using array
```c
/**
 * The size of letter_value array is 'X' + 1.
 * It's because the value of 'X' is largest
 * among the letters in terms of ASCII value.
 */
const int letter_value[] = {
    ['I'] = 1,
    ['V'] = 5,
    ['X'] = 10,
    ['L'] = 50,
    ['C'] = 100,
    ['D'] = 500,
    ['M'] = 1000
};

int roman_to_int(const char s[], int length) {
    int sum = 0;
    int end = length - 1;
    for (int i = 0; i < end; i++) {
        if (letter_value[s[i + 1]] > letter_value[s[i])]
            sum -= letter_value[s[i]];
        else
            sum += letter_value[s[i]];
    }
    return sum + letter_value[s[length - 1]];
}
```

### General Feedback
Most people did well here.

Just like the samples above, it's a good idea to separate the letter-to-value mapping from the function in order to make your code more [*self-documenting*](https://en.wikipedia.org/wiki/Self-documenting_code).

## Q4: Reverse Integer

```c
int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10; // decimal places are discarded
    }
    return reversed;
}
```

### General Feedback
The majority did well here as well. The common issues were:

1. Not initialising the `reversed` variable.
2. Not handling negative numbers.

Some approached this problem by treating `int x` as an array of individual digits and reusing the `_pow` function from Q2.

This is fine, but by realising that you can "pop" the last digit from one int and "push" them to another int, you can write more efficient code.

## Q5(Bonus Question): Social Distancing

```c
int max(int a, int b) {
    return a > b? a: b;
}

int max_distance(int seats[], int length){
    int last_person = -1;
    int dis = 0;
    for (int i = 0; i < length; i++) {
        if (seats[i]) {
            dis = last_person < 0? i:
                  max(dis, (i - last_person) / 2);
            last_person = i;
        }
    }
    
    return max(dis, length - 1 - last_person);
}
```

### General Feedback
This question tripped up a lot of people. There are three cases to consider:

1. the longest sequence is on the left
2. the longest sequence is on the right
3. the longest sequence is in the middle

For the first two cases, the length of the sequence of 0s is the answer, since Danny can sit at the very edge. For the last case, we need to divide by 2 (and round appropriately), since Danny has to sit in the middle.

Some divided by 2 at the end of the function, right before returning. The problem with this approach is that you would still compare your `max_distance` variable with the sequence from the first two cases. One workaround for this is to use an additional variable to keep track of which case `max_distance` came from, and divide if needed. But that would definitely complicate the code.

# General General Feedback

For most of you, this might have been the first time writing C code—or writing code at all. Here's some general feedback to improve your approach and skills in programming.


## Initialise your variables.
A lot of people lost marks due to *undefined behaviour* from uninitialised variables. In C, most local variables should be initialised.

```
int i;	//	Not guaranteed to be 0...
char c; // Not guaranteed to be '\0'...
	
int a[] = {1, 2, 3};
printf("%d\n", a[i]); // Might crash the program!!!
```

This example *might* compile, but isn't guaranteed to work. It may print 1, 2, or 3, or might even crash the program. To make your code reliable, remember to initialise your variables.

## Array Bounds
```
int array[5];
array[5] = 100;  // 🤯
```
Accessing an array out of bounds. Another type of undefined behaviour. Your program may crash... or it may just carry on.

This is more commonly seen while iterating.

```
int length = 10;
int nums[length] = {...};

for (int i = 0; i < length; i++) {
	if (nums[i] > nums[i + 1])  // 🤯 nums[i + 1] is UB for i = length - 1 
		...
}
```

## Naming
Good variable names communicate your intention better. This is beneficial to both *yourself* and the people reading your code (e.g. teammates, mentors).

Consider:

```
int funnyFunction(int what[], int haha) {
	int x = 0;
	for (int i = 0; i < haha; i++) {
		if (what[i] % 2 == 0)
			x++;
	}
	return x;
}
```
vs.

```
int countEven(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0)
			sum++;
	}
	return sum;
}
```

## Indentation
Consistency allows you to spot irregularities a lot faster, and hence reduce time spent debugging. Indentation is no exception.

Find the bug:

```
int countEven(int arr[], int n) {
		int sum = 0;
	int i = 0;
		while (i < n) {
			if (arr[i] % 2 == 0)
	i++;
				sum++;			
	}
	return sum;
	}
```
It's more obvious here:

```
int countEven(int arr[], int n) {
	int sum = 0;
	int i = 0;
	while (i < n) {
		if (arr[i] % 2 == 0)
			i++;
		sum++;			
	}
	return sum;
}
```
Most IDEs/environments have an auto-indent/auto-format option. We recommend you look for it and use it.

## Submitting the Correct File

A couple people submitted empty files or files which could not compile at all (due to missing symbols and whatnot). Please make sure you submit the correct file. Remember to save, remember to push, and check that the file on Github is correct.