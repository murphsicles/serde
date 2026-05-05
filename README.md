# Serde for Zeta

**Official Zorb serialization/deserialization framework built in Zeta.**

## Status

| Version | Feature | Status |
|---------|---------|--------|
| v0.1 | JSON serialization (manual construction) | ✅ Released |
| v0.2 | JSON parser architecture | ✅ Released |
| v0.3 | JSON serializer with array APIs | ✅ Released |
| v0.4 | Comptime derive macros | 📋 Planned |

## Building

```bash
gcc -O2 -c runtime.c -o zeta_runtime_c.o
zetac your_program.z -o your_program
./your_program
```

Requires zetac v0.10.1+ (fixes array function parameter access).

## License

MIT
