# Interval

Arduino library for the Interval datatype.

## Description

This experimental library provides basic math when you do not know a quantity.
The only thing you do know is the value is in a certain interval. 
After doing some math you want to know the interval of possible outcomes.

An interval exist of a pair of floats, low and high, the borders of the interval. 

*footnote:*
*The datatype Interval was created to do some experiments.
It was inspired by the frink language which has an interval datatype.
Frink itself is not investigated, so semantics are not necesary similar.*

## Interface

The Interval class implements the public interface of Printable.
This allows you to print an Interval in human readable form.

```cpp
    Interval x(3, 4);
    x.setDecimals(2);
    Serial.println(x); // will print [3.00, 4.00]
```

### Basic functions

The basic functions are used to get and set some core attributes.

- **setDecimals()**
- **value()**
- **range()**
- **high()**
- **low()**

### Math Operators

Math operators

- **addition + +=** 
- **subtraction - -=**  
- **multiplication \* \*=**  
- **quotient \/ \/=**  


### Functions 

Functions are not implemented yet as these need **to be investigated**.
For a monotonous function it is relative easy

```
Interval v = F( [a, b] );         ==> [ F(a), F(b)]
e.g.
Interval f = exp( [a, b]);        ==> [exp(a), exp(b)]
Interval g = log( [a, b]);        ==> [log(a), log(b)]    a > 0!!
```
The math for non monotonous functions is more complex
as one cannot use the function values as above.

```
Interval p = sin( [0, PI] );      ==> [0, 1]
Interval q = sin( [0, -PI] );     ==> [-1, 0]
Interval r = sin( [0, 10 * PI] ); ==> [-1, 1]

Interval s = sqr( [-5, -3] ) ;    ==> [9, 25]
Interval t = sqr( [-5,  3] ) ;    ==> [0, 25]

```


### Comparison operators

**To be investigated**. The semantics make at least a difference between when
an interval is Certainly Less Equal or Probably Less or Equal.
The Certainly group will be boolean math as we know it.
The Probably group will be more like fuzzy logic so a float between 0..100%.

### Set operators

**To be investigated** include:
- If you have two or more intervals, what is the 'super interval' that includes all?
- How to subtract elements of an interval from another Interval?  
This is different than the subtraction above,  
think of it as " I know the number I look for is in [1, 4] but it is not in [3, 5]  
so it is in [1,3]

### Other

- a known problem is difference between border inclusive \[ \] and  
border exclusive \< \>. How to deal with that? 
- 1/\[-1, 1\]  ==> ?? singularity for 0?
- infinity as border? In math we have \[0, \->> for all positive floats.


## Operation

See example
