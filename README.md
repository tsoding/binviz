# Binary Visualization

Binary Visualization based on Christopher Domas talk: https://www.youtube.com/watch?v=4bM3Gut1hIk

## x86_64 ELF executables

![xkbprint](./demos/xkbprint.binviz.png)
![xmlpatternsvalidator](./demos/xmlpatternsvalidator.binviz.png)
![xournal](./demos/xournal.binviz.png)
![x-terminal-emulator](./demos/x-terminal-emulator.binviz.png)
![x-window-manager](./demos/x-window-manager.binviz.png)

## Quick Start

```console
$ cc -o nob nob.c
$ ./nob binviz ./nob.c
$ feh ./nob.c.binviz.png
```
