/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strcasecmp.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strcasecmp, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    int (*my_strcasecmp)(const char *, const char *) =
    dlsym(lib, "strcasecmp");

    cr_assert_neq(my_strcasecmp, NULL);
    cr_assert_eq(my_strcasecmp("paragraph", "Paragraph"), 0);
    cr_assert_eq(my_strcasecmp("paragrapH", "parAgRaph"), 0);
    cr_assert_lt(my_strcasecmp("paragraph", "paraLyzed"), 0);
    cr_assert_gt(my_strcasecmp("paraLyzed", "paragraph"), 0);
    cr_assert_lt(my_strcasecmp("para", "paragraph"), 0);
    cr_assert_gt(my_strcasecmp("paragraph", "para"), 0);
    cr_assert_lt(my_strcasecmp("\311mile", "\351mile"), 0);
    cr_assert_gt(my_strcasecmp("\351mile", "\311mile"), 0);
    cr_assert_gt(my_strcasecmp("\303\266zg\303\274r", "\303\226ZG\303\234R"),
        0);
    cr_assert_lt(my_strcasecmp("\303\226ZG\303\234R", "\303\266zg\303\274r"),
        0);
    cr_assert_lt(my_strcasecmp("turkish", "TURK\304\260SH"), 0);
    cr_assert_gt(my_strcasecmp("TURK\304\260SH", "turkish"), 0);
    dlclose(lib);
}
