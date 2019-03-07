/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strcspn.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strcspn, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    size_t (*my_strcspn)(const char *, const char *) = dlsym(lib, "strcspn");

    cr_assert_neq(my_strcspn, NULL);
    cr_assert_eq(my_strcspn("hello", "abcdef"), 1);
    cr_assert_eq(my_strcspn("hello", "abc"), 5);
    cr_assert_eq(my_strcspn("hello", ""), 5);
    cr_assert_eq(my_strcspn("", ""), 0);
    cr_assert_eq(my_strcspn("", "abc"), 0);
    cr_assert_eq(my_strcspn("hello", "bro"), 4);
    dlclose(lib);
}
