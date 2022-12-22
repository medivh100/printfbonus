Printf function w/ bonus

This is a simple recoding of the c printf function. It handles the %d %i %s %c %p %u %x %X %% format specifiers.

## Description

%c takes in a char, %s takes in a char *, %d & %i take in an int(they are essentially the same), %u takes in an unsigned int, %p takes
in a pointer, %x & %X take in a number in base 10 and print out it's representation in base 16, %% simply prints a % character and does not take a variable.
The function also handles extra formatting options like setting a minimum field width, more or less precision, printing of extra characters for hexadecimal results.
int i = 10;
i.e: ft_printf("Hello this is a sample %5d %x\n", i, i);
would output
>   10 0x10

## Getting Started

Use make all to create the libftprintf.a file. This is for the base version of the program.
Use make bonus to create the static library file for the bonus part.

### Dependencies

The project has been coded on and for macOS x86_64. I am aware of at least one issue on arm64 due to how va_args are handled.

### Executing program

Simply create a main of your liking and compile using the static library files. Voila! printf(sorta)

## Authors

Contributors names and contact info

Yannick St-laurent
yan_1731@hotmail.com
