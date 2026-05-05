# Serde for Zeta

**Official Zorb serialization/deserialization framework built in Zeta.**

Serialization and deserialization framework for Zeta, inspired by Rust's serde.

## Status

| Version | Feature | Status |
|---------|---------|--------|
| v0.1 | JSON serialization (manual construction) | ✅ Released |
| v0.2 | JSON parser (validation + extern storage) | ✅ Released |
| v0.3 | Parse into structured IR | 🔄 In progress |
| v0.4 | Format plugins (TOML, YAML, CBOR) | 📋 Planned |

## Architecture

```
serde/
├── src/
│   ├── serde.z     — Core data model and helper functions
│   ├── json.z      — JSON format serialization helpers
│   ├── parser.z    — JSON parser (extern-backed validation)
│   ├── impls.z     — Primitive type serialization
│   └── macros.z    — Derive macros (future, pending compiler comptime)
├── runtime.c       — C runtime bridge (I/O, storage)
├── zorb.toml       — Package manifest
└── README.md
```

## Using the Parser (v0.2)

The parser validates JSON structure and stores parsed nodes in an extern C storage
array, avoiding Zeta's current array-in-function-parameter limitations.

```zeta
extern fn serde_read_char() -> i64;
extern fn serde_set_input(ptr: i64);
extern fn serde_store(idx: i64, val: i64);

fn main() -> i64 {
    // Input is set up in C layer before calling
    let valid = validate_json();
    // valid = 1 if JSON is well-formed
}
```

## Building

```bash
gcc -O2 -c runtime.c -o zeta_runtime_c.o
zetac your_program.z -o your_program
./your_program
```

## Compiler Notes

The current Zeta compiler has some limitations that affect serde:
- Array access across function boundaries generates `map_get`/`map_insert` calls
- Large array literals (>10 elements) may not initialize correctly
- Workaround: extern C functions for I/O and storage

These limitations are being addressed in ongoing compiler development.

## License

MIT
