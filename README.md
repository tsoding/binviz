# Binary Visualization

Binary Visualization based on Christopher Domas talk: https://www.youtube.com/watch?v=4bM3Gut1hIk

## Main Idea

- Scan the pairs of bytes of a file with a sliding window. (`AA BB CC DD ...` -> `(AA, BB) (BB, CC) (CC, DD) ...`);
- Interpret the pairs of bytes as coordinates on a 256x256 2D plain;
- Place a dot for each pair on the plain;
- The more frequent the dot, the brighter it is;
- Different patterns emerge depending on the type of the data of the file.

## Demo

### x86_64 ELF executables

![xkbprint](./demos/exec/xkbprint.binviz.png)
![xournal](./demos/exec/xournal.binviz.png)
![x-terminal-emulator](./demos/exec/x-terminal-emulator.binviz.png)

### RGBA32 Raw Images

![forsen1](./demos/imgs/forsen1.png.raw.binviz.png)
![jebaited](./demos/imgs/jebaited.png.raw.binviz.png)
![kkoooooona](./demos/imgs/kkoooooona.png.raw.binviz.png)

### Ogg Files with Chiptune

![1.ogg](./demos/oggs/1.ogg.binviz.png)
![2.ogg](./demos/oggs/2.ogg.binviz.png)
![3.ogg](./demos/oggs/3.ogg.binviz.png)

### Wav Files with Chiptune

![1.wav](./demos/wavs/1.wav.binviz.png)
![2.wav](./demos/wavs/2.wav.binviz.png)
![3.wav](./demos/wavs/3.wav.binviz.png)

## Quick Start

```console
$ cc -o nob nob.c
$ ./nob binviz ./nob.c
$ feh ./nob.c.binviz.png
```
