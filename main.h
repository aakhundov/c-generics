#ifndef MAIN_H_
#define MAIN_H_

#define TEST(TEST_FN)                            \
    {                                            \
        printf("running \"%s\" ... ", #TEST_FN); \
        TEST_FN();                               \
        printf("ok\n");                          \
    }

#endif  // MAIN_H_
