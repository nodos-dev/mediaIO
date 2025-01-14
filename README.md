# Media IO Plugin for Nodos

![build-badge](https://github.com/nodos-dev/mediaio/actions/workflows/build.yml/badge.svg)

This folder contains the Nodos plugin & subsystem for media I/O workflows. It delivers the core functionality for other video I/O devices such as AJA, Bluefish, webcam and other future video development.

## What functionality does MediaIO deliver?
1. **Gamma conversions:** Gamma node creates 1D LUTs (Lookup Tables) for Gamma_Encoded->linear and linear->Gamma_Encoded conversions.
2. **Pixel format conversions:** Inside MediaIO, there are pixel format conversion nodes (mostly Compute shaders, but can also be fragment shaders), which handle YCbCr->RGB and RGB->YCbCr conversions. The pixel formats such as YUV8 or v210 are currently supported, but the list is growing every day.
3. **Color space matrix:** MediaIO also delivers color space conversion matrices such as rec601, rec709, rec2020 color spaces. The **ColorMatrix** node supports also FullRange and LegalRange (a.k.a. Broadcast Legal, Narrow Range) signal levels.

## Build Instructions
1. Download latest Nodos release from [nodos.dev](https://nodos.dev)
2. Clone the repository under Nodos workspace Module directory
```bash
git clone https://github.com/nodos-dev/mediaio.git --recurse-submodules Module/mediaio
```
3. Generate project files from workspace root directory using CMake:
```bash
cmake -S ./Toolchain/CMake -B Build
```
4. Build the project:
```bash
cmake --build Build
```

