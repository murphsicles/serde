#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ─── Zeta runtime bridge ─────────────────────────────────────────────────

long long runtime_malloc(long long s) { return (long long)malloc((size_t)s); }
void runtime_free(long long ptr) { free((void*)ptr); }

void println_i64(long long v) { printf("%lld\n", v); fflush(stdout); }
void print_i64(long long v) { printf("%lld", v); fflush(stdout); }

long long putchar_impl(long long c) { putchar((int)c); fflush(stdout); return c; }

long long get_time_us(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000LL + ts.tv_nsec / 1000LL;
}

// ─── Serde input buffer ─────────────────────────────────────────────────

static long long input_pos = 0;
static const char *input_buf = 0;

void serde_set_input(long long s) {
    input_buf = (const char*)s;
    input_pos = 0;
}

long long serde_read_char(void) {
    if (!input_buf) return 0;
    char c = input_buf[input_pos];
    if (c == 0) return 0;
    input_pos = input_pos + 1;
    return (long long)(unsigned char)c;
}

// ─── Serde storage ──────────────────────────────────────────────────────

static long long serde_storage[500];

void serde_store(long long idx, long long val) {
    if (idx >= 0 && idx < 500) {
        serde_storage[idx] = val;
    }
}

long long serde_load(long long idx) {
    if (idx >= 0 && idx < 500) {
        return serde_storage[idx];
    }
    return 0;
}

void serde_clear(void) {
    long long i = 0;
    while (i < 500) {
        serde_storage[i] = 0;
        i = i + 1;
    }
}
