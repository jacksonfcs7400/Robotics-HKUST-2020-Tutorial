Author: Danny Lau (kkdlau@connect.ust.hk)

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

## Q2: Taylor series of $\sin(x)$, at $a = 0$

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
