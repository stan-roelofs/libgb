# libgb
A Game Boy emulation library.

## Accuracy
The emulator is fairly accurate, passing the majority of test ROMs. The PPU implementation requires work, but finding accurate documentation is difficult. 

## Performance
Compiling in Release mode is recommended. The STL containers used by the emulator can be extremely slow in Debug mode because of iterator debugging. 