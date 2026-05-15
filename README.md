# @data/serde — Serialization/Deserialization for Zeta

Auto-converted from [serde](https://crates.io/crates/serde) v1.0.228 via [Dark Factory](https://github.com/murphsicles/dark-factory).

## Features
- **Serialize trait** — convert any type to a serialized representation
- **Deserialize trait** — reconstruct any type from a serialized representation
- **Serde data model** — 29 types: bool, i8-i128, u8-u128, f32, f64, char, string, bytes, option, unit, newtype, seq, map, tuple, struct/enum variants
- **Derive macros** — `#[derive(Serialize, Deserialize)]` via `serde_derive`
- **Format support** — JSON via `@encoding/serde_json`, TOML via `@encoding/toml`, custom formats via Serializer/Deserializer impls

## Usage
```zeta
use @data/serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize)]
struct Config {
    host: String,
    port: u16,
    debug: bool,
}
```

## Stats: 24 source files (core) + serde_json, ~7,379 lines, 0 unsupported items

## License
MIT