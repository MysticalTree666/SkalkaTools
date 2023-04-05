#include "SkalkaTools.h"

int get_from_to(int min, int max) {
    int n, error_message;

    do {
        error_message = 1;
        printf("[ZH (%i - %i)]: ", min, max);

        while (!(scanf("%d", &n))) {
            clear_buffer();
            if (error_message)printf("[Zadej spravny datovy typ (int32)!]: ");
            error_message = 0;
        }

    } while (n < min || n > max);

    return n;
}

int compare_str(const char *str1, const char *str2) {
    while (*str1 || *str2) {
        if (*str1 != *str2)
            return 0;
        str1++, str2++;
    }

    return 1;
}

void array_rng(int *array, int size, int range) {
    srand(time(NULL));

    int i = 0;

    while (i < size) {
        array[i++] = rand() % range;
    }
}

int rng(int range) {
    srand(time(NULL));
    return rand() % range;
}

void array_print(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("[%d] ", array[i]);
    }
}

void array_print_reverse(int *array, int size) {
    for (int i = --size; i >= 0; --i) {
        printf("[%d] ", array[i]);
    }
}

int array_sum(const int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int array_min(int *array, int size) {
    int min = 2147483647;

    for (int i = 0; i < size; ++i) {
        if (min > array[i])min = array[i];
    }

    return min;
};

int array_max(int *array, int size) {
    int max = -2147483647;

    for (int i = 0; i < size; ++i) {
        if (max < array[i])max = array[i];
    }

    return max;
}

void bubble_sort(int *array, int size) {

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int foo = array[j];
                array[j] = array[j + 1];
                array[j + 1] = foo;
            }
        }
    }
}

int is_even(int number) {
    return !(number % 2);
}

int factorial(int number) {
    int n = 1;

    for (int i = 2; i <= number; ++i) {
        n *= i;
    }

    return n;
}

float average_value(const int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i)
        sum += array[i];

    return (float) sum / (float) size;
}

int bin_to_dec(const int *array, int size) {
    int n = 1, dec = 0;

    for (int i = size - 1; i >= 0; --i) {
        dec += array[i] * n;
        n *= 2;
    }

    return dec;
}

void bin_to_hex(const int *array, int size) {
    int dec = 0, n = 1;

    for (int i = size - 1; i >= 0; --i) {
        dec += array[i] * n;
        n *= 2;
    }

    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, out[16] = {0};
    int i = 15;

    while (dec) {
        out[i--] = hex[dec % 16];
        dec /= 16;
    }

    for (int j = 0; j < 16; ++j) {
        if (out[j])printf("%c", out[j]);
    }
}

void dec_to_bin(int number) {
    for (int i = 31; i >= 0; i--) {
        printf("%i", (number >> i) & 1);
        if (!(i % 4))printf(" ");
    }
}

void dec_to_hex(int number) {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, out[16] = {0};
    int i = 15;

    while (number) {
        out[i--] = hex[number % 16];
        number /= 16;
    }

    for (int j = 0; j < 16; ++j) {
        if (out[j])printf("%c", out[j]);
    }
}

int hex_to_dec(const char *array, int size) {
    int dec = 0, n = 1, hex[6] = {10, 11, 12, 13, 14, 15};

    for (int i = size - 1; i >= 0; --i) {
        if (array[i] >= 'A' && array[i] <= 'F') {
            dec += hex[array[i] - 'A'] * n;
        }

        if (array[i] >= '0' && array[i] <= '9') {
            dec += (array[i] - '0') * n;
        }
        n *= 16;
    }
    return dec;
}

void hex_to_bin(const char *array, int size) {
    int dec = 0, n = 1, hex[6] = {10, 11, 12, 13, 14, 15};

    for (int i = size - 1; i >= 0; --i) {
        if (array[i] >= 'A' && array[i] <= 'F') {
            dec += hex[array[i] - 'A'] * n;
        }

        if (array[i] >= '0' && array[i] <= '9') {
            dec += (array[i] - '0') * n;
        }
        n *= 16;
    }

    for (int i = 31; i >= 0; --i) {
        printf("%i", (dec >> i) & 1);
        if (!(i % 4))printf(" ");
    }
}

void array_copy(const int *current_array, int current_size, int *new_array, int new_size, int offset) {
    for (int i = 0; i < new_size && i < current_size; ++i) {
        if (i + offset >= current_size || offset < 0) return;
        new_array[i] = current_array[i + offset];
    }
}

int samohlasky(char *string) {
    char *samohlasky = "aeiouyAEIOUY";
    int samo = 0;

    for (char *i = string; *i; i++)
        for (char *j = samohlasky; *j; j++)
            if (*i == *j)samo++;

    return samo;
}

int souhlasky(char *string) {
    char *souhlasky = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int sou = 0;

    for (char *i = string; *i; i++)
        for (char *j = souhlasky; *j; j++)
            if (*i == *j)sou++;

    return sou;
}

int words_in_sentence(char *string) {

    int words = 0;

    for (char *i = string; *i; i++) {
        if (isspace(*i))words++;
    }

    return ++words;
};

void square(int x, char c) {
    for (int i = 1; i <= x * x; ++i) {
        printf("%c ", c);
        if (!(i % x))printf("\n");
    }
}

void rectangle(int x, int y, char c) {
    for (int i = 1; i <= y; ++i) {
        for (int j = 1; j <= x; ++j) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void triangle(int x, char c) {
    int space = x - 1, character = 1;

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= space; ++j) {
            printf(" ");
        }

        for (int j = 1; j <= character; ++j) {
            printf("%c", c);
        }

        character += 2;
        space--;
        printf("\n");
    }
}

float bmi(int vyska, int vaha) {
    return 10000 * (float) vaha / (float) (vyska * vyska);
}

void rodne_cislo(int number) {
    int rok = number / 10000;
    int mesic = number % 10000 / 100;
    int den = number % 100;

    printf("%02d.%02d.%02d", rok, mesic, den);
}

