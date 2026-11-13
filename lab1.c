// Эта строка разрешает обычный scanf в Visual Studio.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf и scanf
#include <limits.h>  // границы целых типов
#include <float.h>   // границы float и double

int main(void)
{
    char c;
    short s;
    int n, input;
    float f;
    double d;
    unsigned char uc;
    unsigned short us;
    unsigned int u;
    int stage, start;
    unsigned int start_u;

    // ЗАДАНИЕ 1. Вводим число и сразу показываем его.
    printf("TASK 1\n");
    printf("Enter char numeric value [%d..%d]: ", CHAR_MIN, CHAR_MAX);
    // Вводим код символа как int, затем сохраняем в char.
    if (scanf("%d", &input) != 1) {
        printf("Input error\n");
        return 1;
    }
    if (input < CHAR_MIN || input > CHAR_MAX) {
        printf("Value is outside char range\n");
        return 1;
    }
    c = (char)input;
    printf("char = %d\n", c);
    printf("Enter int: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("int = %d\n", n);
    printf("Enter float (decimal point): ");
    if (scanf("%f", &f) != 1) return 1;
    printf("float = %f\n", f);
    printf("Enter double (decimal point): ");
    if (scanf("%lf", &d) != 1) return 1;
    printf("double = %f\n", d);

    // Например, %12.3f: поле шириной 12, после точки 3 цифры.
    printf("Formatted: char=%5d int=%12d float=%12.3f double=%16.6f\n",
           c, n, f, d);
    // Для %o и %x передаём беззнаковое число.
    printf("char: symbol=%c dec=%d oct=%o hex=%x\n", c, c,
           (unsigned int)(unsigned char)c, (unsigned int)(unsigned char)c);
    printf("int:  symbol=%c dec=%d oct=%o hex=%x\n",
           n, n, (unsigned int)n, (unsigned int)n);
    printf("Scientific: float=%e double=%e\n", f, d);
    printf("Bytes: char=%zu short=%zu int=%zu float=%zu double=%zu\n",
           sizeof(c), sizeof(s), sizeof(n), sizeof(f), sizeof(d));

    // ЗАДАНИЕ 2. Печатаем константы из заголовочных файлов.
    printf("\nTASK 2\n");
    printf("CHAR_MIN=%d CHAR_MAX=%d\n", CHAR_MIN, CHAR_MAX);
    printf("UCHAR_MIN=0 UCHAR_MAX=%u\n", (unsigned int)UCHAR_MAX);
    printf("INT_MIN=%d INT_MAX=%d\n", INT_MIN, INT_MAX);
    printf("UINT_MIN=0 UINT_MAX=%u\n", UINT_MAX);
    printf("float: lowest=%e max=%e min_positive_normal=%e\n",
           -FLT_MAX, FLT_MAX, FLT_MIN);
    printf("double: lowest=%e max=%e min_positive_normal=%e\n",
           -DBL_MAX, DBL_MAX, DBL_MIN);

    // ЗАДАНИЕ 3. Четыре набора чисел, одни и те же цепочки.
    // 1: максимумы; 2: минимумы; 3 и 4: свои примеры.
    printf("\nTASK 3\n");
    for (stage = 1; stage <= 4; stage++) {
        if (stage == 1) {
            printf("\nStage 1 MAX\n");
            c = CHAR_MAX;
            uc = UCHAR_MAX;
            start = INT_MAX;
            start_u = UINT_MAX;
        } else if (stage == 2) {
            printf("\nStage 2 MIN\n");
            c = CHAR_MIN;
            uc = 0;
            start = INT_MIN;
            start_u = 0;
        } else if (stage == 3) {
            printf("\nStage 3 example A\n");
            c = 65;
            uc = 200;
            start = 70000;
            start_u = 70000;
        } else {
            printf("\nStage 3 example B\n");
            c = -65;
            uc = 255;
            start = -70000;
            start_u = 65535;
        }
        // Цепочка 1: char -> short -> int.
        s = c;
        n = s;
        printf("char -> short -> int: %d -> %d -> %d\n", c, s, n);
        // Цепочка 2: unsigned char -> unsigned short -> unsigned int.
        us = uc;
        u = us;
        printf("unsigned char -> unsigned short -> unsigned int: ");
        printf("%u -> %u -> %u\n", (unsigned int)uc, (unsigned int)us, u);
        // Цепочка 3: int -> short -> char.
        n = start;
        s = (short)n;
        c = (char)s;
        printf("int -> short -> char: %d -> %d -> %d\n", n, s, c);
        // Цепочка 4: unsigned int -> unsigned short -> unsigned char.
        u = start_u;
        us = (unsigned short)u;
        uc = (unsigned char)us;
        printf("unsigned int -> unsigned short -> unsigned char: ");
        printf("%u -> %u -> %u\n", u, (unsigned int)us, (unsigned int)uc);
    }

    // ЗАДАНИЕ 4. Печатаем границу, потом изменяем число.
    // Переполнение signed int не определено стандартом C!
    // Здесь оно выполнено только как эксперимент по заданию.
    printf("\nTASK 4: signed overflow is undefined in standard C\n");
    n = INT_MAX;
    printf("signed MAX: %d", n);
    n = n + 1;
    printf(" -> %d\n", n);
    u = UINT_MAX;
    printf("unsigned MAX: %u", u);
    u = u + 1;
    printf(" -> %u\n", u);
    n = INT_MIN;
    printf("signed MIN: %d", n);
    n = n - 1;
    printf(" -> %d\n", n);
    u = 0;
    printf("unsigned MIN: %u", u);
    u = u - 1;
    printf(" -> %u\n", u);

    return 0;
}
