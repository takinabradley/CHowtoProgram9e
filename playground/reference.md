# Arithmatic Types

## Int
- minimum of 16 bits (2 bytes).

- Can hold values from at least -32,786 to 32,786 (65536 possible values in 16 
bits)

- This computer has 32 bit integers (4 bytes) that hold values between 
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

