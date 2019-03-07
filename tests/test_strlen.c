/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strlen.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strlen, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    size_t (*my_strlen)(const char *) = dlsym(lib, "strlen");

    cr_assert_neq(my_strlen, NULL);
    cr_assert_eq(my_strlen("hello"), 5);
    cr_assert_eq(my_strlen("world!"), 6);
    cr_assert_eq(my_strlen(""), 0);
    dlclose(lib);
}
