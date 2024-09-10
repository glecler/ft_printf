# ft_printf

## Project Overview

`ft_printf` is a custom implementation of the standard `printf` function from the C standard library. The goal of this project is to replicate the core functionality of `printf` while managing various format specifiers, flags, width, and precision controls.

## Features

The `ft_printf` function supports the following features:
  
- **Handled Conversions**: 
  - `%s` (string)
  - `%p` (pointer)
  - `%d`, `%i` (signed integers)
  - `%o` (octal)
  - `%u` (unsigned integers)
  - `%x`, `%X` (hexadecimal, lowercase and uppercase)
  - `%c` (character)
  - `%C` (wide character)

- **Special Case**:
  - Handling of `%%` to print a literal `%`.

- **Flags**:
  - `#` : For octal, hexadecimal conversions, prefixes `0` or `0x`/`0X`.
  - `0` : Zero padding instead of space padding.
  - `-` : Left-justify within the field width.
  - `+` : Show the plus sign for positive numbers.
  - (space) : Prefix positive numbers with a space.
  
- **Field Width**:
  Supports defining a minimum field width for output.

- **Precision**:
  Controls the precision for floating-point, integer, and string conversions.

- **Length Modifiers**:
  - `hh`, `h`, `l`, `ll`, `j`, `z` : Modifiers for specifying the size of the argument (e.g., `short`, `long`, etc.).

## Not Supported

- No internal buffer management as found in the standard library's `printf`.

## Installation

To include `ft_printf` in your project

```bash
make
```

## Usage

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Hex: %#x\n", 255);
    ft_printf("Integer with padding: %05d\n", 42);
    return 0;
}
```

---
