# MBI5025 Device

Device implementation for the LED Driver MBI5025.

# Documents

- [Datasheet](./doc/MBI5025%20Datenblatt%20-%20Datasheet.pdf)


# Getting started

After initialization, set pins values with `dev_mbi5025_set_pin`.
Changes made this way won't reflect on IC outputs until `dev_mbi5025_update` is called.

