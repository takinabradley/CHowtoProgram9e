# Arithmatic Types

## Int
- minimum of 16 bits (2 bytes).

- Short int is at least 16bits (2 bytes), int is at least 16bits, long int is at least 32bit (4 bytes), long long int is at least 64bit (8 bytes).

- Can hold values from at least -32,786 to 32,786 (65536 possible values in 16 
bits)

- This computer has 32 bit ints (4 bytes) that hold values between 
-2147483648 and 2147483647 (4294967296 possible values in 32 bits)


## Float
- typically takes up 32 bits (4 bytes).

- decimal values with at most 6 significant digits can be converted to a float 
  and back safely(?)

  ( Does that mean that 9999.99, a number with 6 significant digits, is the 
    maximum safe monatary amount you can convert between decimal and float
    formats? )
 
- A float value converted to a decimal value of at least 9 significant digits 
  will be able to be converted back to it's original float representation(?)
 
- A float value can be a maximum of 3.40282347e+38 and a minimum of 
  1.17549435e-38. This is provided that the number you're trying to represent 
  is has a maximum of 6-9 significant digits.


## Double
- typically takes up 64bits (8 bytes).

- decimal values with at most 15 significant digits can be converted to a 
  double and back safely(?)

- A double value converted to a decimal value of at least 17 significant 
  digits will be able to be converted back to it's original double 
  representation(?). 

- A double value can be a maximum of 1.7976931348623157e+308 and a minimum of 
  2.2250738585072014e-308. This is provided that the number you're trying to 
  represent has a maximum of 15-17 significant digits.


# Understanding pointers, starting from the basics

## Variables
Variables represent a place in memory where values may be stored.
Variables have:
- A name/identifier (such as `num`)
- A type (such as `int`)
- A value (such as  `1`)
- A memory address, where the value is stored (such as 0x7ffe57c837a4)

## Identifiers and types
Both an identifier and a type are required to create (initialize) a
variable, demonstrated in the code block below:

```c
int num; // create variable `num`
```

Here, variable named `num` is created with an integer type. That means it should only save integer values to it's memory address. It is not given a specific value. In C, variables initialized without a value have a random 'garbage' value.

Other types in C include `char` (a single ascii character), `float` (a small precision floating point number), `double` (a higher precision floating point number), `bool` (a boolean value), and pointer types. You can also create your own object types via "structs".


## Values
Identifiers are primarily used as a way to refer to their corresponding values. The example below shows how you might use the `printf` function to printthe value of the `num` variable to the command line:

```c
/* The \"%d\" flag tells the `printf` function that the value it's\n\
recieving is a number. It may be ignored, for the time being. */
printf("%d", num); // print `num`'s value
```

You may give `num` your own value using the assignment operator (`=`):

```c
num = 1; // assign the value `1` to `num` (the value you give `num` must be an integer)
printf("%d", num); // prints `1`
```

## Memory Addresses
Values are stored in chunks of physical memory. A memory address in C signifies the place in memory where a value starts. The size of the chunk of memory can depend on the type of the value. Languages like C know where
to stop reading from the starting point, because you tell them what the type is.

You can access the memory address of a variable using the `&` operator:

```c
/* The \"%p\" here tells `printf` that the type of the value it's printing is a memory address. Please, bear ignoring this a little longer. */
printf("%p", &num); // print the memory address to the user.
```

To assign a memory address to a variable, the variable should be of a pointer type. 

## Pointers
Using a pointer type is similar to using other types like `int`. Using a pointer type simply tells C that the value you're saving to a variable will be a memory address. It's called 'pointer', becuase it 'points' to somewhere in memory.

The pointer type is special because C not only wants to know that the value is a memory address, it also wants to know what type of value should be at the given memory address. Variables of pointer types are simply called \"pointers\" by C programmers.

Below demonstrates how you'd make a pointer to the `num` variable in C:

```c
// `int *` -- specifies that this is a pointer to an integer value
// `numPointer` -- the new variable
// `&num`` -- the memory address of the `num` variable
int * numPointer = &num; // make numPointer point to the address `num` uses to store values.

/* We use %p to tell `printf` that the `numPointer`s value is a memory address, and insert it into the message */
printf("The value of `num` is stored at: %p", numPointer); // print memory address
```

The `*` character is used to denote pointer types. The type `int *` signifies that the value of this variable (often called a 'pointer') is the memory address of an integer.

C allows you to do more than just store memory address values with pointers, though. Pointers also allow you to read and manipulate the values at the memory address they point to by **dereferencing** their values. This means that you can take the memory address a pointer holds, and grab the value at that address on the fly. 

You may 'dereference' a pointer by using the `*` symbol.

```c
// use %d to tell `printF` the value we're printing will be a integer
printf("The value at the memory address `numPointer` points to is: %d", *numPointer); // print the value of `num` to the console
```

Re-assigning the value of a variable through a pointer looks a lot like normal assignment:

```c
*numPointer = 1;
printf("The new value of `num` is: %d", num) // prints `1` to the user.
```

The expression `*numPointer = 1;` means "change the value at the address this pointer references to `1`".

> Why is it called 'dereferencing'?
>
> Pointers hold a numerical value that stand for a memory address, they are not the the memory address themselves. In other words, the numbers pointers hold are just a reference value we can use to find the *actual* value of an address in a sea of bytes. 
>
>Imagine you have an inventory room. In this room is a reference book, and each entry in the book listed:
> A) A shelf number, and 
> B) The type of things that shelf number holds. 
>
> Each entry is a pointer, and it's just a reference value. It doesn't make any guarauntees about what is actually on that shelf. In order to find that out, you have to go look at the shelf it's pointing to. When you get there, you're no longer looking at the reference, but the actual contents of the shelf. So, if you take a reference then un-reference/de-reference/follow it, you get the actual value from the reference. 

### Generic Pointers
In C, generic pointers are also allowed, meaning that the type of the value at the address the pointer holds to is unknown. This is denoted by the `void *` type. Pointers on modern machines are often 64bit or 8-byte values. You can assign any 32-bit value to a pointer, as long as you don't leave the memory space allocated by your program (that'd cause a segmentation fault!).

```c
// create a variable
int num = 1;

// assign it's address to a 32-bit unsigned integer (to convince you we're really using an int)
unsigned long long int numAddressAsInt = (unsigned long long int)&num;

// create a pointer using that integer 
// (convince C that it's allowed by typecasting it to any kind of pointer)
void * pVoid = (void *)numAddressAsInt;

// all three values are indeed the correct memory address to `num` 
// (represented in base 10, instead of hexadecimal):
printf("Address of num %llu\n", (unsigned long long int)&num);
printf("value of numAddressAsInt %llu\n", numAddressAsInt);
printf("Value of pVoid %llu\n", pVoid);

// You can convince C that you know the type of the dereferenced value of pVoid 
// by typecasting it to an integer pointer before dereferencing it.
*(int *)pVoid = 2;
printf("new num value %d\n", num);

int num2 = *(int*)pVoid;
num2 = 1;
printf("new num value %d\n", num);
```

## Character arrays and string literals

So, we know about variables, types, pointers, values, memory addresses, and all that good stuff. Let's try to explain how a string works. 

```c
// 
const char * string = "hello";
char charArray[] = {'h', 'e', 'l', 'l', 'o', '\0'};



// These are the same thing
printf("%c", *string);
printf("%c", charArray[0]);
printf("%s", string);
printf("%s", charArray);
```