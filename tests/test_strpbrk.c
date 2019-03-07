/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strpbrk.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strpbrk, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_strpbrk)(const char *, const char *) = dlsym(lib, "strpbrk");
    const char *str = "Hello, World!";

    cr_assert_neq(my_strpbrk, NULL);
    cr_assert_null(my_strpbrk(str, ""));
    cr_assert_eq(my_strpbrk(str, "H"), str);
    cr_assert_eq(my_strpbrk(str, "l"), str + 2);
    cr_assert_eq(my_strpbrk(str, "hello"), str + 1);
    cr_assert_null(my_strpbrk(str, "xwz"));
    dlclose(lib);
}
