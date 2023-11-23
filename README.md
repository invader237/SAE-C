
# SAE-Super-Epic-Minigame

[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)
[![forthebadge](http://forthebadge.com/images/badges/powered-by-electricity.svg)](http://forthebadge.com)

## Installation


You clone the [source code](https://github.com/invader237/SAE-C) with the command:
```bash
https://github.com/invader237/SAE-C.git
```

Make sure you have the [SDL2](https://github.com/libsdl-org/SDL) and [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf) libraries installed on your machine :
```bash
sudo apt install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
```

### Start
To compile this shit use this command :
```bash
gcc -o window ../src/window.c ../src/hiddenNumber.c ../src/mysterySequence.c ../src/mastermind.c ../src/function.c ../src/file.c -lSDL2 -lSDL2_ttf
```

To execute enter the command `./window`. 

### Made with
Editor:
* VS Code
* NVIM
Compiler:
* gcc

### Note

* Graphical problems on the interface can occur, such as text not displaying well (due to a memory cleaning problem)

* The code and documentation are not uniform because it was done at different times and we are crappy developers

* If you have problems compiling the code (and you trust us :)), you can use the pre-compiled file


### Authors
Diego \
Guillaume
