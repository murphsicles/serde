# @data/serde — Serialization/Deserialization for Zeta

Auto-converted from [serde](https://crates.io/crates/serde) v1.0.228 via [Dark Factory](https://github.com/murphsicles/dark-factory).

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

## Features

- `Serialize` trait — convert data to serialized form
- `Deserialize` trait — parse data from serialized form
- Full serde data model (29 types): bool, i8-u128, f32/f64, char, string, bytes,
  option, unit, newtype, seq, map, tuple, struct, enum variants
- Derive macros via `serde_derive`
- JSON, MessagePack, and custom format support through format crates

## License

MIT
