# Serde for Zeta

**Official Zorb serialization/deserialization framework built in Zeta.**

## Status

| Version | Feature | Status |
|---------|---------|--------|
| v0.1 | JSON manual construction | ✅ |
| v0.2 | JSON parser architecture | ✅ |
| v0.3 | JSON serializer with array APIs | ✅ |
| **v0.4** | **Struct field serialization** | **✅ Released** |

## Quick Start

```zeta
struct Person { age: i64, score: i64 }

fn serialize(p: Person) {
    putchar(123); // {
    print_str("age"); putchar(58); println_i64(p.age);
    putchar(44);
    print_str("score"); putchar(58); println_i64(p.score);
    putchar(125); // }
}
```

Requires zetac v0.10.2+ (struct field access fix).

## License

MIT
