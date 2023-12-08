#include "s21_string.h"

START_TEST(test_case_s21_strchr) {
  const char *str_1 = "1234";
  int symbol_1 = '2';
  const char *str_2 = "PEPEGA";
  int symbol_2 = 'E';
  const char *str_3 = "PEPEGA";
  int symbol_3 = 'A';
  const char *str_4 = "52@*^&";
  int symbol_4 = '1';
  const char *str_5 = "PEPEGA";
  int symbol_5 = '\0';

  ck_assert_int_eq(s21_strchr_test(str_1, symbol_1), 1);
  ck_assert_int_eq(s21_strchr_test(str_2, symbol_2), 1);
  ck_assert_int_eq(s21_strchr_test(str_3, symbol_3), 1);
  ck_assert_int_eq(s21_strchr_test(str_4, symbol_4), 1);
  ck_assert_int_eq(s21_strchr_test(str_5, symbol_5), 1);
}
END_TEST

START_TEST(test_case_s21_strncpy) {
  char dest_1[20] = "";
  char *src_1 = "STAREGA";
  s21_size_t n_1 = 5;

  char dest_2[20] = "PEPEGA";
  char *src_2 = "STAREGA";
  s21_size_t n_2 = 1;

  char dest_3[20] = "PEPEGA";
  char *src_3 = "\0";
  s21_size_t n_3 = 0;

  char dest_4[20] = "PEPEGA";
  char *src_4 = "STAREGA";
  s21_size_t n_4 = 8;

  char dest_5[5] = "123";
  char *src_5 = "STAREGA";
  s21_size_t n_5 = 3;

  ck_assert_int_eq(s21_strncpy_test(dest_1, src_1, n_1), 1);
  ck_assert_int_eq(s21_strncpy_test(dest_2, src_2, n_2), 1);
  ck_assert_int_eq(s21_strncpy_test(dest_3, src_3, n_3), 1);
  ck_assert_int_eq(s21_strncpy_test(dest_4, src_4, n_4), 1);
  ck_assert_int_eq(s21_strncpy_test(dest_5, src_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_memset) {
  char str_1[20] = "PEPEGA";
  int c_1 = 83;
  s21_size_t n_1 = 5;

  char str_2[20] = "PEPEGA";
  int c_2 = 10;
  s21_size_t n_2 = 1;

  char str_3[20] = "ПЕПЕГА";
  int c_3 = 0;
  s21_size_t n_3 = 8;

  char str_4[20] = "PEPEGA";
  int c_4 = 8;
  s21_size_t n_4 = 3;

  char str_5[20] = "";
  int c_5 = 128;
  s21_size_t n_5 = 3;

  ck_assert_int_eq(s21_memset_test(str_1, c_1, n_1), 1);
  ck_assert_int_eq(s21_memset_test(str_2, c_2, n_2), 1);
  ck_assert_int_eq(s21_memset_test(str_3, c_3, n_3), 1);
  ck_assert_int_eq(s21_memset_test(str_4, c_4, n_4), 1);
  ck_assert_int_eq(s21_memset_test(str_5, c_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_memmove) {
  char dest_1[20] = "";
  const void *src_1 = "STAREGA";
  s21_size_t n_1 = 1;

  char dest_2[20] = "PEPEGA";
  const void *src_2 = "STAREGA";
  s21_size_t n_2 = 6;

  char dest_3[20] = "PEPEGA";
  const void *src_3 = "STAREGA";
  s21_size_t n_3 = 2;

  char dest_4[20] = "PEPEGA";
  const void *src_4 = "СТАРЕГА";
  s21_size_t n_4 = 0;

  char dest_5[20] = "12345";
  const void *src_5 = "STAREGA";
  s21_size_t n_5 = 50;

  ck_assert_int_eq(s21_memmove_test(dest_1, src_1, n_1), 1);
  ck_assert_int_eq(s21_memmove_test(dest_2, src_2, n_2), 1);
  ck_assert_int_eq(s21_memmove_test(dest_3, src_3, n_3), 1);
  ck_assert_int_eq(s21_memmove_test(dest_4, src_4, n_4), 1);
  ck_assert_int_eq(s21_memmove_test(dest_5, src_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_memcpy) {
  char dest_1[20] = "PEPEGA";
  const void *src_1 = "      ";
  s21_size_t n_1 = 4;

  char dest_2[20] = "PEPEGA";
  const void *src_2 = "   ///    ";
  s21_size_t n_2 = 8;

  char dest_3[20] = "PEPEGA";
  const void *src_3 = "12345";
  s21_size_t n_3 = 2;

  char dest_4[20] = "PEPEGA";
  const void *src_4 = "$%#%@^@!^&#^#&!";
  s21_size_t n_4 = 6;

  char dest_5[20] = "PEPEGA";
  const void *src_5 = "STAREGA";
  s21_size_t n_5 = 3;

  ck_assert_int_eq(s21_memcpy_test(dest_1, src_1, n_1), 1);
  ck_assert_int_eq(s21_memcpy_test(dest_2, src_2, n_2), 1);
  ck_assert_int_eq(s21_memcpy_test(dest_3, src_3, n_3), 1);
  ck_assert_int_eq(s21_memcpy_test(dest_4, src_4, n_4), 1);
  ck_assert_int_eq(s21_memcpy_test(dest_5, src_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_strrchr) {
  char str_1[20] = "0163456769";
  int c_1 = '8';

  char str_2[20] = "$%@^@&!^&@#^!&^";
  int c_2 = '%';

  char str_3[20] = "ПЕПЕГА";
  int c_3 = L'\u041F';  //Буква П в кодировке Unicode

  char str_4[20] = "PEPEGA STAREGA";
  int c_4 = ' ';

  char str_5[20] = "PEPEGA STAREGA";
  int c_5 = 'S';

  ck_assert_int_eq(s21_strrchr_test(str_1, c_1), 1);
  ck_assert_int_eq(s21_strrchr_test(str_2, c_2), 1);
  ck_assert_int_eq(s21_strrchr_test(str_3, c_3), 1);
  ck_assert_int_eq(s21_strrchr_test(str_4, c_4), 1);
  ck_assert_int_eq(s21_strrchr_test(str_5, c_5), 1);
}
END_TEST

START_TEST(test_case_s21_strpbrk) {
  char str_1[20] = "PEPEGA";
  char str_2[20] = "LEGA";

  char str_3[20] = "PEPEGA";
  char str_4[20] = "PE";

  char str_5[20] = "PEPEGA";
  char str_6[20] = "PEP";

  char str_7[20] = "PEPEGA";
  char str_8[20] = "E";

  char str_9[20] = "PEPEGA";
  char str_10[20] = "SU";

  ck_assert_int_eq(s21_strpbrk_test(str_1, str_2), 1);
  ck_assert_int_eq(s21_strpbrk_test(str_3, str_4), 1);
  ck_assert_int_eq(s21_strpbrk_test(str_5, str_6), 1);
  ck_assert_int_eq(s21_strpbrk_test(str_7, str_8), 1);
  ck_assert(s21_strpbrk(str_9, str_10) == S21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str_9, str_10),
                    (unsigned long)strpbrk(str_9, str_10));
}
END_TEST

START_TEST(test_case_s21_memchr) {
  char str_1[20] = "PEPEGA";
  int c_1 = 'P';
  s21_size_t n_1 = 7;

  char str_2[20] = "12345";
  int c_2 = '2';
  s21_size_t n_2 = 6;

  char str_3[20] = "PEPEGA";
  int c_3 = 'L';
  s21_size_t n_3 = 7;

  char str_4[20] = "12345";
  int c_4 = '5';
  s21_size_t n_4 = 6;

  char str_5[20] = "PEPEGA";
  int c_5 = '5';
  s21_size_t n_5 = 7;

  ck_assert_int_eq(s21_memchr_test(str_1, c_1, n_1), 1);
  ck_assert_int_eq(s21_memchr_test(str_2, c_2, n_2), 1);
  ck_assert_int_eq(s21_memchr_test(str_3, c_3, n_3), 1);
  ck_assert_int_eq(s21_memchr_test(str_4, c_4, n_4), 1);
  ck_assert_int_eq(s21_memchr_test(str_5, c_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_strstr) {
  char haystack_1[20] = "PEPEGA";
  char needle_1[20] = "PEGA";

  char haystack_2[20] = "PEPEGA";
  char needle_2[20] = "5";

  char haystack_3[20] = "STAREGA";
  char needle_3[20] = "PEGA";

  char haystack_4[20] = "ПЕПЕГА";
  char needle_4[20] = "PEGA";

  char haystack_5[20] = "PEPEGA";
  char needle_5[20] = "123456";

  ck_assert_int_eq(s21_strstr_test(haystack_1, needle_1), 1);
  ck_assert_int_eq(s21_strstr_test(haystack_2, needle_2), 1);
  ck_assert_int_eq(s21_strstr_test(haystack_3, needle_3), 1);
  ck_assert_int_eq(s21_strstr_test(haystack_4, needle_4), 1);
  ck_assert_int_eq(s21_strstr_test(haystack_5, needle_5), 1);
}
END_TEST

START_TEST(test_case_s21_strcspn) {
  char str_1[20] = "PEPEGA";
  char str_2[20] = "EGA";

  char str_3[20] = "PEPEGA";
  char str_4[20] = "L";

  char str_5[20] = "PEPEGA";
  char str_6[20] = "PATREGO";

  char str_7[20] = "PEPEGA";
  char str_8[20] = "SEL";

  char str_9[20] = "PEPEGA";
  char str_10[20] = "123";

  ck_assert_int_eq(s21_strcspn_test(str_1, str_2), 1);
  ck_assert_int_eq(s21_strcspn_test(str_3, str_4), 1);
  ck_assert_int_eq(s21_strcspn_test(str_5, str_6), 1);
  ck_assert_int_eq(s21_strcspn_test(str_7, str_8), 1);
  ck_assert_int_eq(s21_strcspn_test(str_9, str_10), 1);
}
END_TEST

START_TEST(test_case_s21_strncmp) {
  char str_1[20] = "PEPEGA";
  char str_2[20] = "PEGA";
  s21_size_t n_1 = 3;

  char str_3[20] = "PEPEGA";
  char str_4[20] = "LEGA";
  s21_size_t n_2 = 4;

  char str_5[20] = "PEPEGA";
  char str_6[20] = "pega";
  s21_size_t n_3 = 4;

  char str_7[20] = "PEPEGA";
  char str_8[20] = "1234";
  s21_size_t n_4 = 6;

  char str_9[20] = "PEPEGA";
  char str_10[20] = "SEGA";
  s21_size_t n_5 = 5;

  ck_assert_int_eq(s21_strncmp_test(str_1, str_2, n_1), 1);
  ck_assert_int_eq(s21_strncmp_test(str_3, str_4, n_2), 1);
  ck_assert_int_eq(s21_strncmp_test(str_5, str_6, n_3), 1);
  ck_assert_int_eq(s21_strncmp_test(str_7, str_8, n_4), 1);
  ck_assert_int_eq(s21_strncmp_test(str_9, str_10, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_strncat) {
  char dest_1[20] = "PEPEGA";
  char src_1[20] = "ПЕГА";
  s21_size_t n_1 = 3;

  char dest_2[20] = "PEPEGA";
  char src_2[20] = "12345";
  s21_size_t n_2 = 6;

  char dest_3[20] = "";
  char src_3[20] = "PEGA";
  s21_size_t n_3 = 3;

  char dest_4[20] = "PEPEGA";
  char src_4[20] = ":%,№.";
  s21_size_t n_4 = 3;

  char dest_5[20] = "PEPEGA";
  char src_5[20] = "pega";
  s21_size_t n_5 = 2;

  ck_assert_int_eq(s21_strncat_test(dest_1, src_1, n_1), 1);
  ck_assert_int_eq(s21_strncat_test(dest_2, src_2, n_2), 1);
  ck_assert_int_eq(s21_strncat_test(dest_3, src_3, n_3), 1);
  ck_assert_int_eq(s21_strncat_test(dest_4, src_4, n_4), 1);
  ck_assert_int_eq(s21_strncat_test(dest_5, src_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_memcmp) {
  char dest_1[20] = "PEPEGA";
  char src_1[20] = "PEGA";
  s21_size_t n_1 = 5;

  char dest_2[20] = "PEPEGA";
  char src_2[20] = "PEPA";
  s21_size_t n_2 = 3;

  char dest_3[20] = "PEPEGA";
  char src_3[20] = "ПЕПА";
  s21_size_t n_3 = 4;

  char dest_4[20] = "PEPEGA";
  char src_4[20] = "12345";
  s21_size_t n_4 = 6;

  char dest_5[20] = "PEPEGA";
  char src_5[20] = " ";
  s21_size_t n_5 = 3;

  ck_assert_int_eq(s21_memcmp_test(dest_1, src_1, n_1), 1);
  ck_assert_int_eq(s21_memcmp_test(dest_2, src_2, n_2), 1);
  ck_assert_int_eq(s21_memcmp_test(dest_3, src_3, n_3), 1);
  ck_assert_int_eq(s21_memcmp_test(dest_4, src_4, n_4), 1);
  ck_assert_int_eq(s21_memcmp_test(dest_5, src_5, n_5), 1);
}
END_TEST

START_TEST(test_case_s21_strlen) {
  char str_1[20] = "PEPEGA";
  char str_2[20] = "ПЕПЕГА";
  char str_3[20] = "123456";
  char str_4[20] = "    ";
  char str_5[20] = "";

  ck_assert_int_eq(s21_strlen_test(str_1), 1);
  ck_assert_int_eq(s21_strlen_test(str_2), 1);
  ck_assert_int_eq(s21_strlen_test(str_3), 1);
  ck_assert_int_eq(s21_strlen_test(str_4), 1);
  ck_assert_int_eq(s21_strlen_test(str_5), 1);
}
END_TEST

START_TEST(test_case_s21_strerror) {
  int error_num_1 = 0;
  int error_num_2 = 106;
  int error_num_3 = 2147483647;
  int error_num_4 = -214748364;
  int error_num_5 = 65;

  ck_assert_int_eq(s21_strerror_test(error_num_1), 1);
  ck_assert_int_eq(s21_strerror_test(error_num_2), 1);
  ck_assert_int_eq(s21_strerror_test(error_num_3), 1);
  ck_assert_int_eq(s21_strerror_test(error_num_4), 1);
  ck_assert_int_eq(s21_strerror_test(error_num_5), 1);
}
END_TEST

START_TEST(test_case_s21_to_upper) {
  char str_1[] = "pepega";

  char *new_str = s21_to_upper(str_1);

  if (new_str) {
    ck_assert_str_eq(new_str, "PEPEGA");
    free(new_str);
  }
}
END_TEST

START_TEST(test_case_s21_to_lower) {
  char str_1[] = "PEPEGA";

  char *new_str = s21_to_lower(str_1);

  if (new_str) {
    ck_assert_str_eq(new_str, "pepega");
    free(new_str);
  }
}
END_TEST

START_TEST(test_case_s21_insert) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }
}
END_TEST

START_TEST(test_case_s21_trim) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(s21_sprintf_f_test) {
  char str[1000];
  char str_orig[1000];

  double b = 12.11;

  int res_1_orig = sprintf(str_orig, "%.f", b);

  int res_1 = s21_sprintf(str, "%.f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.002345;

  int res_2_orig = sprintf(str_orig, "%+-10.3f", b_2);
  int res_2 = s21_sprintf(str, "%+-10.3f", b_2);
  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  double b_7 = 1234523459.123456789;
  int res_7 = s21_sprintf(str, "%.5f", b_7);
  int res_7_orig = sprintf(str_orig, "%.5f", b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_8 = 1;
  int res_8 = s21_sprintf(str, "%f", b_8);
  int res_8_orig = sprintf(str_orig, "%f", b_8);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_9 = 0.00345;
  int res_9 = s21_sprintf(str, "%f", b_9);
  int res_9_orig = sprintf(str_orig, "%f", b_9);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 0.00345;
  int res_10 = s21_sprintf(str, "%f", b_10);
  int res_10_orig = sprintf(str_orig, "%f", b_10);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 1234567.00345;
  int res_11 = s21_sprintf(str, "%.11f", b_11);
  int res_11_orig = sprintf(str_orig, "%.11f", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_g_test) {
  char str[1000];
  char str_orig[1000];

  double b_1 = -22.25600;
  int res_1 = s21_sprintf(str, "%+-10.3G", b_1);
  int res_1_orig = sprintf(str_orig, "%+-10.3G", b_1);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.00000000000001;
  int res_2 = s21_sprintf(str, "%#G", b_2);
  int res_2_orig = sprintf(str_orig, "%#G", b_2);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int a = -10;
  long double b_3 = 1234567.2345678;
  int res_3 = s21_sprintf(str, "%+30.*Lg", a, b_3);
  int res_3_orig = sprintf(str_orig, "%+30.*Lg", a, b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int width = -10, precision = 2;
  double b_4 = 0;
  int res_4 = s21_sprintf(str, "%-#*.*g", width, precision, b_4);
  int res_4_orig = sprintf(str_orig, "%-#*.*g", width, precision, b_4);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  double b_5 = -0.000000654;
  int res_5 = s21_sprintf(str, "%+-25g", b_5);
  int res_5_orig = sprintf(str_orig, "%+-25g", b_5);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  double b_6 = 320.0;
  int res_6 = s21_sprintf(str, "%+-25g%g", b_5, b_6);
  int res_6_orig = sprintf(str_orig, "%+-25g%g", b_5, b_6);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  double b_7 = -120.0001;
  int res_7 = s21_sprintf(str, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);
  int res_7_orig = sprintf(str_orig, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 5.0, b_8 = 0.0000000012345, b_9 = 1.0;
  int res_8 = s21_sprintf(str, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  int res_8_orig = sprintf(str_orig, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 0.001;
  int res_11 = s21_sprintf(str, "%0.g", b_11);
  int res_11_orig = sprintf(str_orig, "%0.g", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  double b_12 = 0.00000000001;
  int res_12 = s21_sprintf(str, "%.10g", b_12);
  int res_12_orig = sprintf(str_orig, "%.10g", b_12);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_prc_test) {
  char str[1000];
  char str_orig[1000];

  int res_1 = s21_sprintf(str, "%%");
  int res_1_orig = sprintf(str_orig, "%%");
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10%");

  ck_assert_int_eq(res_2, 10);
  ck_assert_str_eq(str, "         %");

  int a_prc = 14;
  int res_3 = s21_sprintf(str, "hhhh%0*%", a_prc);

  ck_assert_int_eq(res_3, 18);
  ck_assert_str_eq(str, "hhhh0000000000000%");

  int width_prc = 30;
  int res_4 = s21_sprintf(str, "%-*%12345", width_prc);

  ck_assert_int_eq(res_4, 35);
  ck_assert_str_eq(str, "%                             12345");

  int res_5 = s21_sprintf(str, "abc%%defg");
  int res_5_orig = sprintf(str_orig, "abc%%defg");

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_n_test) {
  char str[1000];
  char str_orig[1000];

  int c_1, c_1_orig;
  int res_1 = s21_sprintf(str, "%n", &c_1);
  int res_1_orig = sprintf(str_orig, "%n", &c_1_orig);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_int_eq(c_1, c_1_orig);
  ck_assert_str_eq(str, str_orig);

  int c_2, c_2_orig;
  int res_2 = s21_sprintf(str, "12345%n678910", &c_2);
  int res_2_orig = sprintf(str_orig, "12345%n678910", &c_2_orig);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_int_eq(c_2, c_2_orig);
  ck_assert_str_eq(str, str_orig);

  int c_3 = 0, c_3_orig = 0;
  int res_3 = s21_sprintf(str, "%nqwerty", &c_3);
  int res_3_orig = sprintf(str_orig, "%nqwerty", &c_3_orig);
  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_int_eq(c_3, c_3_orig);
  ck_assert_str_eq(str, str_orig);

  int c_4, c_4_orig;
  int res_4 = s21_sprintf(str, "hhhhh%n%%", &c_4);
  int res_4_orig = sprintf(str_orig, "hhhhh%n%%", &c_4_orig);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_int_eq(c_4, c_4_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_f_g_n_prc_test) {
  char str[1000];

  int n_1, n_2;
  double f_1 = 1.0, f_2 = -0.1234567890;

  int res_1 =
      s21_sprintf(str, "qwerty%n %10.5f %#.4g %08% %n", &n_1, f_1, f_2, &n_2);

  ck_assert_int_eq(res_1, 35);
  ck_assert_int_eq(n_1, 6);
  ck_assert_int_eq(n_2, 35);
  ck_assert_str_eq(str, "qwerty    1.00000 -0.1235 0000000% ");

  long double f_3 = 0.1234500;
  double f_4 = 12300000.0;
  int n_3;
  int res_2 = s21_sprintf(str, "%-20% %#0 Lf %n %-.10G g%010%", f_3, &n_3, f_4);

  ck_assert_int_eq(res_2, 52);
  ck_assert_int_eq(n_3, 31);
  ck_assert_str_eq(str, "%                     0.123450  12300000 g000000000%");
}
END_TEST

START_TEST(s21_sprintf_test) {
  char str[1000];
  char str_origin[1000];
  const char *format_str1 = "Hello";
  char c = 'X';
  char d = 'Y';
  int result1 = s21_sprintf(str, format_str1, c);
  int result_origin1 = sprintf(str_origin, format_str1, c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "Hello, %c %c";
  int result2 = s21_sprintf(str, format_str2, c, d);
  int result_origin2 = sprintf(str_origin, format_str2, c, d);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  char *s1 = "world!";
  char *s2 = "Hello world!";
  const char *format_str3 = "Hello, %10s %10.15s";
  int result3 = s21_sprintf(str, format_str3, s1, s2);
  int result_origin3 = sprintf(str_origin, format_str3, s1, s2);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_e_test) {
  char str[1000];
  char str_origin[1000];
  const char *format_str1 = "% 10.15LE yo";
  long double mantissa1 = 0.0000003044058697058435;
  int result1 = s21_sprintf(str, format_str1, mantissa1);
  int result_origin1 = sprintf(str_origin, format_str1, mantissa1);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "%-20.7e yo";
  double mantissa2 = -4044050;
  int result2 = s21_sprintf(str, format_str2, mantissa2);
  int result_origin2 = sprintf(str_origin, format_str2, mantissa2);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  const char *format_str3 = "%-.5E yo";
  double mantissa3 = -0.00;
  int result3 = s21_sprintf(str, format_str3, mantissa3);
  int result_origin3 = sprintf(str_origin, format_str3, mantissa3);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);

  const char *format_str4 = "Hello %+020.15E %LE yo";
  double mantissa4 = 1.004554367;
  long double mantissa5 = -432432455454;
  int result4 = s21_sprintf(str, format_str4, mantissa4, mantissa5);
  int result_origin4 = sprintf(str_origin, format_str4, mantissa4, mantissa5);
  ck_assert_int_eq(result4, result_origin4);
  ck_assert_str_eq(str, str_origin);

  const char *format_str5 = "This is infinite: %-20.5e and this is nan: %20e";
  double infinite = 1.0 / 0.0;
  double not_a_number = infinite * 0.0;
  int result5 = s21_sprintf(str, format_str5, infinite, not_a_number);
  int result_origin5 = sprintf(str_origin, format_str5, infinite, not_a_number);
  ck_assert_int_eq(result5, result_origin5);
  ck_assert_str_eq(str, str_origin);

  const char *format_str6 = "% -10.15E yo";
  double mantissa6 = 0.00003044058697058435;
  int result6 = s21_sprintf(str, format_str6, mantissa6);
  int result_origin6 = sprintf(str_origin, format_str6, mantissa6);
  ck_assert_int_eq(result6, result_origin6);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_p_test) {
  char str[1000];
  char str_origin[1000];
  int a = 10;
  char *format_str1 = "This is the pointer: %p\n";
  int result1 = s21_sprintf(str, format_str1, &a);
  int result_origin1 = sprintf(str_origin, format_str1, &a);

  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  char *pointer = "Test";
  double double_pointer = 84759375969;

  char *format_str2 = "To the left: %-20p!\nTo the right %20p!";

  int result2 = s21_sprintf(str, format_str2, pointer, &double_pointer);
  int result_origin2 =
      sprintf(str_origin, format_str2, pointer, &double_pointer);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  int *empty_pointer = S21_NULL;
  char *format_str3 = "This is empty pointer %p\n";
  int result3 = s21_sprintf(str, format_str3, empty_pointer);
  int result_origin3 = sprintf(str_origin, format_str3, empty_pointer);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[1000];
  char str1[1000];
  int res = s21_sprintf(str, "%o", arr1[0]);
  int res1 = sprintf(str1, "%o", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-12.3lo", (unsigned long)arr1[4]);
  res1 = sprintf(str1, "%-12.3lo", (unsigned long)arr1[4]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%010.5o", arr1[5]);
  ck_assert_str_eq(str, "37777775231");
  ck_assert_int_eq(res, 11);

  res = s21_sprintf(str, "%0#3.7o gterth", arr1[6]);
  ck_assert_str_eq(str, "0022253 gterth");
  ck_assert_int_eq(res, 14);

  res = s21_sprintf(str, "%-.4o gterth", arr1[6]);
  res1 = sprintf(str1, "%-.4o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#.9o gterth", arr1[6]);
  res1 = sprintf(str1, "%-#.9o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %0.o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello 22253 gterth");
  ck_assert_int_eq(res, 18);

  res = s21_sprintf(str, "hello %#o gterth", arr1[6]);
  res1 = sprintf(str1, "hello %#o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %*.o gterth", 5, arr1[6]);
  res1 = sprintf(str1, "hello %*.o gterth", 5, arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %010.7o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello    0022253 gterth");
  ck_assert_int_eq(res, 23);

  res = s21_sprintf(str, "%010.7ho", (unsigned short)arr1[6]);
  ck_assert_str_eq(str, "   0022253");
  ck_assert_int_eq(res, 10);
}
END_TEST

START_TEST(s21_sprintf_x_X_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[1000];
  char str1[1000];
  int res = s21_sprintf(str, "%x", arr1[0]);
  int res1 = sprintf(str1, "%x", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7hx", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%#10.7hx", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3lx", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%-#10.3lx", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%X", arr1[0]);
  res1 = sprintf(str1, "%X", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7lX", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%#10.7lX", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3hX", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#10.3hX", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  char str[1000];
  char str1[1000];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str[1000];
  char str1[1000];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%-11.10s", x);
  int res1 = sprintf(str1, "%-11.10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%11.8s", x);
  res1 = sprintf(str1, "%11.8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[1000];
  char str_orig[1000];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[1000];
  char str_orig[1000];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);
  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_2) {
  char str[1000];
  char str_orig[1000];
  int a = -23454546;

  int res_1 = s21_sprintf(str, "%10.*d", 5, a);
  int res_1_orig = sprintf(str_orig, "%10.*d", 5, a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%0*d", 5, a);
  int res_10_orig = sprintf(str_orig, "%0*d", 5, a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_3) {
  char str[1000];
  char str_orig[1000];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_4) {
  char str[1000];
  char str_orig[1000];
  int a = 23;
  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_5) {
  char str[1000];
  char str_orig[1000];
  int a = 2344;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_6) {
  char str[1000];
  char str_orig[1000];
  int a = -23;
  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%+0d", a);
  int res_5_orig = sprintf(str_orig, "%+0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-+d", a);
  int res_6_orig = sprintf(str_orig, "%-+d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-+5d", a);
  int res_11_orig = sprintf(str_orig, "%-+5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-+10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-+10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-+3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-+3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_0) {
  char str[1000];
  char str_orig[1000];
  int a = 0;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%05d", a);
  int res_5_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%d", a);
  int res_7_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%5d", a);
  int res_12_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%10.5d", a);
  int res_20_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%05d", a);
  int res_26_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_string");

  tc_core = tcase_create("Core");

  //Тесты основных функций
  tcase_add_test(tc_core, test_case_s21_strchr);
  tcase_add_test(tc_core, test_case_s21_strncpy);
  tcase_add_test(tc_core, test_case_s21_memset);
  tcase_add_test(tc_core, test_case_s21_memmove);
  tcase_add_test(tc_core, test_case_s21_memcpy);
  tcase_add_test(tc_core, test_case_s21_strrchr);
  tcase_add_test(tc_core, test_case_s21_strpbrk);
  tcase_add_test(tc_core, test_case_s21_memchr);
  tcase_add_test(tc_core, test_case_s21_strstr);
  tcase_add_test(tc_core, test_case_s21_strcspn);
  tcase_add_test(tc_core, test_case_s21_strncmp);
  tcase_add_test(tc_core, test_case_s21_strncat);
  tcase_add_test(tc_core, test_case_s21_memcmp);
  tcase_add_test(tc_core, test_case_s21_strlen);
  tcase_add_test(tc_core, test_case_s21_strerror);

  //Тесты функций в стиле C#
  tcase_add_test(tc_core, test_case_s21_to_upper);
  tcase_add_test(tc_core, test_case_s21_to_lower);
  tcase_add_test(tc_core, test_case_s21_insert);
  tcase_add_test(tc_core, test_case_s21_trim);

  //Тесты sprintf
  tcase_add_test(tc_core, s21_sprintf_f_test);
  tcase_add_test(tc_core, s21_sprintf_g_test);
  tcase_add_test(tc_core, s21_sprintf_prc_test);
  tcase_add_test(tc_core, s21_sprintf_n_test);
  tcase_add_test(tc_core, s21_sprintf_f_g_n_prc_test);
  tcase_add_test(tc_core, s21_sprintf_test);
  tcase_add_test(tc_core, s21_sprintf_e_test);
  tcase_add_test(tc_core, s21_sprintf_p_test);
  tcase_add_test(tc_core, s21_sprintf_o_test);
  tcase_add_test(tc_core, s21_sprintf_x_X_test);
  tcase_add_test(tc_core, s21_sprintf_c_test);
  tcase_add_test(tc_core, s21_sprintf_s_test);
  tcase_add_test(tc_core, s21_sprintf_u_test);
  tcase_add_test(tc_core, s21_sprintf_d_test);
  tcase_add_test(tc_core, s21_sprintf_d_test_2);
  tcase_add_test(tc_core, s21_sprintf_d_test_3);
  tcase_add_test(tc_core, s21_sprintf_d_test_4);
  tcase_add_test(tc_core, s21_sprintf_d_test_5);
  tcase_add_test(tc_core, s21_sprintf_d_test_6);
  tcase_add_test(tc_core, s21_sprintf_d_test_0);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int s21_strchr_test(const char *str, int symbol) {
  int result = 0;
  char *s21_func = s21_strchr(str, symbol);
  char *orig_func = strchr(str, symbol);
  if (s21_func == orig_func) {
    result = 1;
  }
  // printf("%s %s\n", s21_func, orig_func);
  return result;
}

int s21_strncpy_test(char *dest, const char *src, size_t n) {
  int result = 1;
  char *s21_func = s21_strncpy(dest, src, n);
  char *orig_func = strncpy(dest, src, n);
  for (size_t i = 0; i < n; i++) {
    if (s21_func[i] != orig_func[i]) {
      result = 0;
      break;
    }
  }
  return result;
}

int s21_memset_test(void *str, int c, s21_size_t n) {
  int result = 0;
  char *s21_func = s21_memset(str, c, n);
  char *orig_func = memset(str, c, n);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}

int s21_memmove_test(void *dest, const void *src, s21_size_t n) {
  int result = 0;
  char *s21_func = s21_memmove(dest, src, n);
  char *orig_func = memmove(dest, src, n);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}

int s21_memcpy_test(void *dest, const void *src, s21_size_t n) {
  int result = 0;
  char *s21_func = s21_memcpy(dest, src, n);
  char *orig_func = memcpy(dest, src, n);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}

int s21_strrchr_test(const char *str, int c) {
  int result = 0;
  char *s21_func = s21_strrchr(str, c);
  char *orig_func = strrchr(str, c);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strpbrk_test(const char *str1, const char *str2) {
  int result = 0;
  char *s21_func = s21_strpbrk(str1, str2);
  char *orig_func = strpbrk(str1, str2);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}

int s21_memchr_test(const void *str, int c, s21_size_t n) {
  int result = 0;
  char *s21_func = s21_memchr(str, c, n);
  char *orig_func = memchr(str, c, n);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strstr_test(const char *haystack, const char *needle) {
  int result = 0;
  char *s21_func = s21_strstr(haystack, needle);
  char *orig_func = strstr(haystack, needle);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strcspn_test(const char *str1, const char *str2) {
  int result = 0;
  s21_size_t s21_func = s21_strcspn(str1, str2);
  s21_size_t orig_func = strcspn(str1, str2);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strncmp_test(const char *str1, const char *str2, size_t n) {
  int result = 0;
  int s21_func = s21_strncmp(str1, str2, n);
  int orig_func = strncmp(str1, str2, n);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strncat_test(char *dest, const char *src, s21_size_t n) {
  int result = 0;
  char *s21_func = s21_strncat(dest, src, n);
  char *orig_func = strncat(dest, src, n);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}

int s21_memcmp_test(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  int s21_func = s21_memcmp(str1, str2, n);
  int orig_func = memcmp(str1, str2, n);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strlen_test(const char *str) {
  int result = 0;
  int s21_func = s21_strlen(str);
  int orig_func = strlen(str);
  if (s21_func == orig_func) {
    result = 1;
  }
  return result;
}

int s21_strerror_test(int errornum) {
  int result = 0;
  char *s21_func = s21_strerror(errornum);
  char *orig_func = strerror(errornum);
  if (strcmp(s21_func, orig_func) == 0) {
    result = 1;
  }
  return result;
}
