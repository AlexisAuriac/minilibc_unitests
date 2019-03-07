/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests memcpy.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_memcpy, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_memcpy)(void *, void *, size_t) = dlsym(lib, "memcpy");
    char str[100];

    memset(str, 'z', 100);
    cr_assert_neq(my_memcpy, NULL);
    my_memcpy(str, "abcdef", 6);
    cr_assert_eq(strncmp(str, "abcdefz", 7), 0);
    str[6] = '\0';
    my_memcpy(str, "def", 4);
    cr_assert_str_eq(str, "def");
    my_memcpy(str, "abcde", 6);
    cr_assert_str_eq(str, "abcde");
    cr_assert_str_eq(my_memcpy(str + 1, str, 3), "aaae");
    dlclose(lib);
}
