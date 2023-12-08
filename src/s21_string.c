#include "s21_string.h"

//Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

//Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
//указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)str)[i] = (char)c;
  }
  return str;
}

//	Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char str_temp[100] = {0};

  s21_memcpy(str_temp, src, n);
  s21_memcpy(dest, str_temp, n);
  return dest;
}

//Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(((char *)dest) + i) = *(((char *)src) + i);
  }
  return dest;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  unsigned char pc = c;
  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == pc) {
      return (void *)(p + i);
    }
  }
  return S21_NULL;
}

//Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *str_1 = (unsigned char *)str1;
  unsigned char *str_2 = (unsigned char *)str2;
  int result = 0;

  for (s21_size_t i = 0; result == 0 && str_1[i] != '\0' && i < n; i += 1)
    result = str_1[i] - str_2[i];

  return result;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int len1, len2, i = 0, j = 0;
  s21_size_t result = 0;
  len1 = strlen(str1);
  len2 = strlen(str2);
  while (i < len1) {
    j = 0;
    while (j < len2) {
      if (str1[i] == str2[j]) break;
      j++;
    }
    if (j != len2) break;
    result++;
    i++;
  }

  return result;
}

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0, length;
  int result = 0;
  length = strlen(str1);

  if (strlen(str2) < length) length = strlen(str2);
  while (i < length && i < n) {
    result = str1[i] - str2[i];
    if (result != 0) break;
    i++;
  }

  return result;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i, j;
  s21_size_t length = s21_strlen(dest);

  for (i = length, j = 0; i < (length + n) && src[j] != '\0'; i++, j++) {
    dest[i] = src[j];
  }

  return dest;
}

#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRLIST_SIZE 107
#else
#define S21_ERRLIST_SIZE 134
#endif

#if defined(__APPLE__) || defined(__MACH__)

static const char *const s21_sys_errlist[S21_ERRLIST_SIZE] = {
    [0] = "Undefined error: 0",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "Device not configured",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource deadlock avoided",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Resource busy",
    [17] = "File exists",
    [18] = "Cross-device link",
    [19] = "Operation not supported by device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [28] = "No space left on device",
    [29] = "Illegal seek",
    [30] = "Read-only file system",
    [31] = "Too many links",
    [32] = "Broken pipe",
    [33] = "Numerical argument out of domain",
    [34] = "Result too large",
    [35] = "Resource temporarily unavailable",
    [36] = "Operation now in progress",
    [37] = "Operation already in progress",
    [38] = "Socket operation on non-socket",
    [39] = "Destination address required",
    [40] = "Message too long",
    [41] = "Protocol wrong type for socket",
    [42] = "Protocol not available",
    [43] = "Protocol not supported",
    [44] = "Socket type not supported",
    [45] = "Operation not supported",
    [46] = "Protocol family not supported",
    [47] = "Address family not supported by protocol family",
    [48] = "Address already in use",
    [49] = "Can't assign requested address",
    [50] = "Network is down",
    [51] = "Network is unreachable",
    [52] = "Network dropped connection on reset",
    [53] = "Software caused connection abort",
    [54] = "Connection reset by peer",
    [55] = "No buffer space available",
    [56] = "Socket is already connected",
    [57] = "Socket is not connected",
    [58] = "Can't send after socket shutdown",
    [59] = "Too many references: can't splice",
    [60] = "Operation timed out",
    [61] = "Connection refused",
    [62] = "Too many levels of symbolic links",
    [63] = "File name too long",
    [64] = "Host is down",
    [65] = "No route to host",
    [66] = "Directory not empty",
    [67] = "Too many processes",
    [68] = "Too many users",
    [69] = "Disc quota exceeded",
    [70] = "Stale NFS file handle",
    [71] = "Too many levels of remote in path",
    [72] = "RPC struct is bad",
    [73] = "RPC version wrong",
    [74] = "RPC prog. not avail",
    [75] = "Program version wrong",
    [76] = "Bad procedure for program",
    [77] = "No locks available",
    [78] = "Function not implemented",
    [79] = "Inappropriate file type or format",
    [80] = "Authentication error",
    [81] = "Need authenticator",
    [82] = "Device power is off",
    [83] = "Device error",
    [84] = "Value too large to be stored in data type",
    [85] = "Bad executable (or shared library)",
    [86] = "Bad CPU type in executable",
    [87] = "Shared library version mismatch",
    [88] = "Malformed Mach-o file",
    [89] = "Operation canceled",
    [90] = "Identifier removed",
    [91] = "No message of desired type",
    [92] = "Illegal byte sequence",
    [93] = "Attribute not found",
    [94] = "Bad message",
    [95] = "EMULTIHOP (Reserved)",
    [96] = "No message available on STREAM",
    [97] = "ENOLINK (Reserved)",
    [98] = "No STREAM resources",
    [99] = "Not a STREAM",
    [100] = "Protocol error",
    [101] = "STREAM ioctl timeout",
    [102] = "Operation not supported on socket",
    [103] = "Policy not found",
    [104] = "State not recoverable",
    [105] = "Previous owner died",
    [106] = "Interface output queue is full"};
#endif

#if defined(__linux__)

static const char *const s21_sys_errlist[S21_ERRLIST_SIZE] = {
    [0] = "Success",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "No such device or address",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource temporarily unavailable",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Device or resource busy",
    [17] = "File exists",
    [18] = "Invalid cross-device link",
    [19] = "No such device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [29] = "No space left on device",
    [30] = "Illegal seek",
    [31] = "Read-only file system",
    [32] = "Too many links",
    [33] = "Broken pipe",
    [34] = "Numerical argument out of domain",
    [35] = "Numerical result out of range",
    [36] = "Resource deadlock avoided",
    [37] = "File name too long",
    [38] = "No locks available",
    [39] = "Function not implemented",
    [40] = "Directory not empty",
    [41] = "Too many levels of symbolic links",
    [42] = "Unknown error 41",
    [43] = "No message of desired type",
    [44] = "Identifier removed",
    [45] = "Channel number out of range",
    [46] = "Level 2 not synchronized",
    [47] = "Level 3 halted",
    [48] = "Level 3 reset",
    [49] = "Link number out of range",
    [50] = "Protocol driver not attached",
    [51] = "No CSI structure available",
    [52] = "Level 2 halted",
    [53] = "Invalid exchange",
    [54] = "Invalid request descriptor",
    [55] = "Exchange full",
    [56] = "No anode",
    [57] = "Invalid request code",
    [58] = "Invalid slot",
    [59] = "Unknown error 58",
    [60] = "Bad font file format",
    [61] = "Device not a stream",
    [62] = "No data available",
    [63] = "Timer expired",
    [64] = "Out of streams resources",
    [65] = "Machine is not on the network",
    [66] = "Package not installed",
    [67] = "Object is remote",
    [68] = "Link has been severed",
    [69] = "Advertise error",
    [70] = "Srmount error",
    [71] = "Communication error on send",
    [72] = "Protocol error",
    [73] = "Multihop attempted",
    [74] = "RFS specific error",
    [75] = "Bad message",
    [76] = "Value too large for defined data type",
    [77] = "Name not unique on network",
    [78] = "File descriptor in bad state",
    [79] = "Remote address changed",
    [80] = "Can not access a needed shared library",
    [81] = "Accessing a corrupted shared library",
    [82] = ".lib section in exrcutable file is corrupted",
    [83] = "Attempting to link in too many shared libraries",
    [84] = "Invalid or incomplete multibyte or wide character",
    [85] = "Interrupted system call should be restarted",
    [86] = "Streams pipe error",
    [87] = "Too many users",
    [88] = "Socket operation on non-socket",
    [89] = "Destination address required",
    [90] = "Message too long",
    [91] = "Protocol wrong type for socket",
    [92] = "Protocol not available",
    [93] = "Protocol not supported",
    [94] = "Socket type not supported",
    [95] = "Operation not supported",
    [96] = "Protocol family not supported",
    [97] = "Address family not supported by protocol",
    [98] = "Address already in use",
    [99] = "Cannot assign requested address",
    [100] = "Network is down",
    [101] = "Network is unreachable",
    [102] = "Network dropped connection on reset",
    [103] = "Software caused connection abort",
    [104] = "Connection reset by peer",
    [105] = "No buffer space available",
    [106] = "Transport endpoint is already connected",
    [107] = "Transport endpoint is not connected",
    [108] = "Cannot send after transport endpoint shutdown",
    [109] = "Too many references: cannot splice",
    [110] = "Connection timed out",
    [111] = "Connection refused",
    [112] = "Host is down",
    [113] = "No route to host",
    [114] = "Operation already in progress",
    [115] = "Operation now in progress",
    [116] = "Stale file handle",
    [117] = "Structure needs cleaning",
    [118] = "Not a XENIX named type file",
    [119] = "No XENIX semaphores available",
    [120] = "Is a named type file",
    [121] = "Remote I/O error",
    [122] = "Disk quota exceeded",
    [123] = "No medium found",
    [124] = "Wrong medium type",
    [125] = "Operation canceled",
    [126] = "Required key not available",
    [127] = "Key has expired",
    [128] = "Key has been revoked",
    [129] = "Key was rejected by service",
    [130] = "Owner died",
    [131] = "State not recoverable",
    [132] = "Operation not possible due to RF-kill",
    [133] = "Memory page has hardware error",
};
#endif

// res статический массив с размером BUFF_SIZE 512 байт

char *s21_strerror(int errnum) {
  static char res[BUFF_SIZE] = {'\0'};

  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE)
    sprintf(res, "Unknown error: %d", errnum);
  else
    strcpy(res,
           s21_sys_errlist[errnum]);  // strcpy надо поставить на нашу строку

  return res;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  int lenght = s21_strlen(str);

  char *result = (char *)malloc(lenght + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (int i = 0; i < lenght; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 'a' + 'A';
    } else {
      result[i] = str[i];
    }
  }

  result[lenght] = '\0';
  return result;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  int lenght = s21_strlen(str);

  char *result = (char *)malloc(lenght + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (int i = 0; i < lenght; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] - 'A' + 'a';
    } else {
      result[i] = str[i];
    }
  }

  result[lenght] = '\0';
  return result;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == S21_NULL || str == S21_NULL || start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = str_len = s21_strlen(str);
  s21_size_t result_len = src_len + str_len;

  char *result = (char *)malloc(result_len + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_strncpy(result, src, start_index);
  s21_strncpy(result + start_index, str, str_len);
  strcpy(result + start_index + str_len, src + start_index);

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) {
    return S21_NULL;
  }

  size_t src_len = strlen(src);
  size_t start_index = 0;
  size_t end_index = src_len - 1;

  while (start_index < src_len &&
         s21_strchr(trim_chars, src[start_index]) != S21_NULL) {
    start_index++;
  }

  while (end_index > start_index &&
         s21_strchr(trim_chars, src[end_index]) != S21_NULL) {
    end_index--;
  }

  s21_size_t result_len =
      (start_index <= end_index) ? (end_index - start_index + 1) : 0;

  char *result = (char *)malloc(result_len + 1);
  if (result == S21_NULL) {
    return S21_NULL;  // Ошибка выделения памяти
  }

  s21_strncpy(result, src + start_index, result_len);
  result[result_len] = '\0';

  return result;
}

void *memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  unsigned char pc = c;
  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == pc) {
      return (void *)(p + i);
    }
  }
  return NULL;
}

// Функции Люды

char *s21_strchr(const char *str, int c) {
  unsigned char *pstr = (unsigned char *)str;
  int length = s21_strlen(str);
  for (int i = 0; i <= length; i++) {
    if (*pstr == (unsigned char)c) {
      return (char *)pstr;
    }
    pstr++;
  }
  return S21_NULL;
}

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  int str1_len = s21_strlen(str1);
  int str2_len = s21_strlen(str2);

  for (int i = 0; i < str1_len; i++) {
    for (int j = 0; j < str2_len; j++) {
      if (str1[i] == str2[j]) {
        return (char *)&str1[i];
      }
    }
  }
  return S21_NULL;
}

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  const char *p = str;
  const char *last_occurrence = 0;
  while (*p != '\0') {
    if (*p == c) {
      last_occurrence = p;
    }
    p++;
  }
  return (char *)last_occurrence;
}

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  int haystack_len = s21_strlen(haystack);
  int needle_len = s21_strlen(needle);

  for (int i = 0; i <= haystack_len - needle_len; i++) {
    int j;
    for (j = 0; j < needle_len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == needle_len) {
      return (char *)&haystack[i];
    }
  }
  return S21_NULL;
}
