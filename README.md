# gandalf-lib
A Game Boy emulation library.

## Accuracy
The emulator is fairly accurate, passing the majority of test ROMs. The PPU implementation requires work, but finding accurate documentation is difficult. 

## Performance
Compiling in Release mode is recommended. The STL containers used by the emulator can be extremely slow in Debug mode because of iterator debugging. 

## Building
Generate the build system files using cmake
```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Now compile the code:
```
cmake --build .
```

If you are compiling on Windows using MSVC, you should use the following instead:
```
cmake --build . --config Release
```

### Building examples and tests
External dependencies are required to build the examples and tests. These have been added as git submodules. Clone the repository as follows in order to build these:

```
git clone --recurse-submodules https://github.com/stan-roelofs/gandalf-lib.git
```

Or use the following command to pull the submodules if you have already cloned this repository:

```
git submodule update --init --recursive
```