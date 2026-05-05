#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long runtime_malloc(long long s) { return (long long)malloc((size_t)s); }
void runtime_free(long long p) { free((void*)p); }
void println_i64(long long v) { printf("%lld\n", v); fflush(stdout); }
void print_i64(long long v) { printf("%lld", v); fflush(stdout); }
long long putchar_impl(long long c) { putchar((int)c); fflush(stdout); return c; }
void print_str(const char *s) { if (s) { printf("%s", s); fflush(stdout); } }
long long host_str_len(const char *s) { return s ? (long long)strlen(s) : 0; }
long long get_time_us(void) { struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts); return ts.tv_sec * 1000000LL + ts.tv_nsec / 1000LL; }
long long serde_read_char(void) { return 0; }
void serde_store(long long i, long long v) {}
long long serde_load(long long i) { return 0; }
