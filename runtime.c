#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *runtime_malloc(long long s) { return malloc(s); }
void runtime_free(void *p) { free(p); }

void println_i64(long long v) { printf("%lld\n", v); fflush(stdout); }

long long putchar_impl(long long c) { putchar((int)c); fflush(stdout); return c; }
