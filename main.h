#ifndef MAIN_H
#define MAIN_H

#define TEST(TEST_FN)                            \
    {                                            \
        printf("running \"%s\" ... ", #TEST_FN); \
        TEST_FN();                               \
        printf("ok\n");                          \
    }

#endif // MAIN_H
