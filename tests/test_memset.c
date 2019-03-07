/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests memset.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_memset, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_memset)(void *, int, size_t) = dlsym(lib, "memset");
    const char *str[100];

    cr_assert_neq(my_memset, NULL);
    cr_assert_str_eq(my_memset(str, 0, 100), "");
    cr_assert_str_eq(my_memset(str, 'a', 10), "aaaaaaaaaa");
    cr_assert_str_eq(my_memset(str, 'b', 5), "bbbbbaaaaa");
    cr_assert_str_eq(my_memset(str, '\0', 100), "");
    cr_assert_str_eq(my_memset(str, 'c', 1), "c");
    cr_assert_str_eq(my_memset(str + 1, 'c', 2), "cc");
    dlclose(lib);
}
