# GPIO Interface

Allows Generic control to GPIO pins.

## Implementation Guidelines

- Output pins should allow Read/Write functionalities.
- Input pins should can only operate in Read mode.
- Pins should not enable any pull resistor (No-Pull)
- Trying to access invalid pins should not result in errors.
  - Requests should be ignored.
  - Functions that return values should return `0`.


