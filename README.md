# Serde for Zeta

**Official Zorb serialization/deserialization framework built in Zeta.**

Serialization and deserialization framework for Zeta, inspired by Rust's serde. 
Provides a structured way to convert Zeta types to and from interchange formats like JSON.

## Status

MVP — working JSON serialization via manual character-level output.
Full derive macros and automatic type serialization will follow as Zeta's comptime macro system matures.

## Architecture

```
serde/
├── src/
│   ├── serde.z    — Core JSON data model and helper functions
│   ├── json.z     — JSON format serialization
│   ├── impls.z    — Primitive type serialization
│   └── macros.z   — Derive macros (future)
├── zorb.toml      — Package manifest
└── README.md
```

## Features

- ✅ JSON object serialization (`{}`)
- ✅ JSON array serialization (`[]`)  
- ✅ Integer value output
- ✅ String value output (with JSON escaping)
- ✅ Boolean/null support
- 🔄 JSON parsing (in progress)
- 🔄 Derive macros (waiting on compiler comptime reflection)

## Usage

```zeta
// Build a JSON object manually
putchar(123);               // {
putchar(34); putchar(115);  // "s" (key)
putchar(34); putchar(58);   // ":
println_i64(42);            // 42 (value)
putchar(125);               // }
```

Helper functions in `src/serde.z` wrap these primitives for cleaner usage.

## Building

```bash
# Ensure zeta_runtime_c.o is in your build directory
gcc -O2 -c runtime.c -o zeta_runtime_c.o

# Compile tests
zetac test_integration.z -o test_integration
./test_integration
```

## Roadmap

1. **v0.1** — Manual JSON construction helpers (✅ done)
2. **v0.2** — JSON parser (string → IR)
3. **v0.3** — Comptime derive macros for Serialize/Deserialize
4. **v0.4** — Format plugins (TOML, YAML, CBOR)

## License

MIT
