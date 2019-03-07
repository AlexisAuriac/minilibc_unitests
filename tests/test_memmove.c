/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests memmove.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_memmove, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_memmove)(void *, void *, size_t) = dlsym(lib, "memmove");
    char str[100];

    memset(str, 'z', 100);
    cr_assert_neq(my_memmove, NULL);
    my_memmove(str, "abcdef", 6);
    cr_assert_eq(strncmp(str, "abcdefz", 7), 0);
    str[6] = '\0';
    my_memmove(str, "def", 4);
    cr_assert_str_eq(str, "def");
    my_memmove(str, "abcde", 6);
    cr_assert_str_eq(str, "abcde");
    cr_assert_str_eq(my_memmove(str + 1, str, 3), "abce");
    dlclose(lib);
}
