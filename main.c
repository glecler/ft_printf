#include <stdio.h>
#include <limits.h>
#include "./srcs/ft_printf.h"

int main() {
    // Variables to hold return values of ft_printf and printf
    int ret_ft;
    int ret_std;

    // 1. Basic string test
    printf("\nTest 1: Basic string test\n");
    ret_ft = ft_printf("Hello %s!\n", "World");
    ret_std = printf("Hello %s!\n", "World");
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 2. Integer test with positive and negative numbers
    printf("\nTest 2: Integer test (positive and negative)\n");
    ret_ft = ft_printf("Positive: %d, Negative: %d\n", 42, -42);
    ret_std = printf("Positive: %d, Negative: %d\n", 42, -42);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 3. Hexadecimal test with and without 0x prefix
    printf("\nTest 3: Hexadecimal test with and without 0x\n");
    ret_ft = ft_printf("Hex: %#x, No Prefix: %x\n", 255, 255);
    ret_std = printf("Hex: %#x, No Prefix: %x\n", 255, 255);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 4. Octal test with and without 0 prefix
    printf("\nTest 4: Octal test with and without 0 prefix\n");
    ret_ft = ft_printf("Octal: %#o, No Prefix: %o\n", 42, 42);
    ret_std = printf("Octal: %#o, No Prefix: %o\n", 42, 42);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 5. Pointer address test
    printf("\nTest 5: Pointer address test\n");
    void *ptr = (void *)0xdeadbeef;
    ret_ft = ft_printf("Pointer: %p\n", ptr);
    ret_std = printf("Pointer: %p\n", ptr);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 6. Character test with normal and wide character
    printf("\nTest 6: Character test\n");
    ret_ft = ft_printf("Char: %c, Percent: %%\n", 'A');
    ret_std = printf("Char: %c, Percent: %%\n", 'A');
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 7. Field width and padding with zeros
    printf("\nTest 7: Field width and zero padding\n");
    ret_ft = ft_printf("Padded: %05d\n", 42);
    ret_std = printf("Padded: %05d\n", 42);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 8. Left justification with field width
    printf("\nTest 8: Left justification with field width\n");
    ret_ft = ft_printf("Left: %-10dEnd\n", 42);
    ret_std = printf("Left: %-10dEnd\n", 42);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 9. Precision test with floating-point numbers
    printf("\nTest 9: Precision test with floating-point numbers\n");
    ret_ft = ft_printf("Float: %.2f\n", 3.14159);
    ret_std = printf("Float: %.2f\n", 3.14159);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    // 10. Testing unsigned integer with length modifier
    printf("\nTest 10: Unsigned integer with length modifier\n");
    ret_ft = ft_printf("Unsigned long long: %llu\n", ULLONG_MAX);
    ret_std = printf("Unsigned long long: %llu\n", ULLONG_MAX);
    printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

	// 11. Test with multiple flags, width, and precision for integers
	printf("\nTest 11: Multiple flags, width, and precision for integers\n");
	ret_ft = ft_printf("Pos: |%+08.5d|, Neg: |% 08.5d|\n", 42, -42);
	ret_std = printf("Pos: |%+08.5d|, Neg: |% 08.5d|\n", 42, -42);
	printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

	// Test with pointer, hexadecimal with # flag, and length modifiers
	printf("\nTest 12: Pointer, hexadecimal with # flag, and length modifiers\n");
	unsigned long long ull = 0x123456789ABCDEF;
	ptr = &ull;
	ret_ft = ft_printf("Pointer: %p, Hex: %#llx\n", ptr, ull);
	ret_std = printf("Pointer: %p, Hex: %#llx\n", ptr, ull);
	printf("Return ft_printf: %d, printf: %d\n", ret_ft, ret_std);

    return 0;
}

