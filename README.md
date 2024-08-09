# Media IO Plugin for Nodos

![build-badge](https://github.com/nodos-dev/mediaio/actions/workflows/release.yml/badge.svg)

This folder contains the Nodos plugin for media I/O workflows.

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

