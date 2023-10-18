# Binary Visualization

Binary Visualization based on Christopher Domas talk: https://www.youtube.com/watch?v=4bM3Gut1hIk

## x86_64 ELF executables

![xkbprint](./demos/exec/xkbprint.binviz.png)
![xournal](./demos/exec/xournal.binviz.png)
![x-terminal-emulator](./demos/exec/x-terminal-emulator.binviz.png)

## RGBA32 Raw Images

![forsen1](./demos/imgs/forsen1.png.raw.binviz.png)
![jebaited](./demos/imgs/jebaited.png.raw.binviz.png)
![kkoooooona](./demos/imgs/kkoooooona.png.raw.binviz.png)

## Quick Start

```console
$ cc -o nob nob.c
$ ./nob binviz ./nob.c
$ feh ./nob.c.binviz.png
```
