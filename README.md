# 6-meter-Rx-with-Arduino-RDA5807-and-LCD1602

This is more of a proof of concept. The radio module RDA5807M knows to go down to 50 MHz but the library that is used for such radio modules does not have this option, that the hardware knows. The radio library made by Matthias Hertel did not look into this kind of use of the hardware it supports.
The solution was to lie the RDA5807M it is something else, something that does not require the selection of the band for which it will be used. I declared it as TEA5767, which is pin by pin compatible, but does not know so many things. Since I did not declare it as a radio for a specific band (no need for TEA5767), the module RDA5807M let me use it with its full frequency capabilities.
The schematics uses 3 buttons:
- menu - 4 choices, steps of 1 KHz, 10 KHz, 100 KHz and 1 MHz
- frequency up
- frequency down

The audio is enough for headphones. It is possible to use headphones/earbuds with inline potentiometer.

As stated in the .ino file, it requires the #include <TEA5767Radio.h> line, calling a separate library made specifically for the TEA5767 module, not for RDA5807M.

Again, this project is more of a proof of concept than a real hiugh level Rx for the 6 meter amateur radio band.
