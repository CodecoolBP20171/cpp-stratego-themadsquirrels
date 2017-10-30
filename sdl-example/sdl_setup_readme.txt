SDL2 installation
-----------------

sudo apt-get install libsdl2-2.0
sudo apt-get install libsdl2-dev

If something goes wrong ó, stop and tell me!

If the install finished OK go on.


There is an error in the SDL2 cmake file (sdl2-config.cmake).
Fire up gedit with this command:
/usr/lib/x86_64-linux-gnu/cmake/SDL2/sudo gedit sdl2-config.cmake


This is the last row:
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 ")

That last space is the error. Delete it! It should look like this:
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")

Woo! You have SDL2 installed!


SDL_Image
---------

sudo apt-get install libsdl2-image-2.0-0
sudo apt-get install libsdl2-image-dev

If something goes wrong ó, stop and tell me!

If the install finished fire up the CLion project and run it!
