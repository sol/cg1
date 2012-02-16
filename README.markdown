## cg1

a simple OpenGL application written in C++ and featuring hierarchical
transformations

### Getting started

Make sure you have the following dependencies installed on your system:

    cmake
    libsdl-dev
    freeglut3-dev

[Re]build the `Makefile`:

    cmake -G "Unix Makefiles" .

Build and run:

    make && ./main

### Key bindings

    <space>      stop animation
    <1> .. <7>   switch scene
    <ESC>        quit


### Screenshots

![screenshot of a knight](screenshots/knight.png)

![screenshot of a sphere with two light sources](screenshots/lighting.png)

![screenshot of animated spheres](screenshots/spheres.png)


### History of cg1

`cg1` has been written by Markus Klinik and Simon Hengel for a cg-course at
[Georg-Simon-Ohm-Hochschule Nuernberg](http://www.fh-nuernberg.de/index.php) in
2003. We think it may be useful getting started with OpenGL. Please feel free
to use it for any purpose you like (in accordance with the license, see the
accompanying LICENSE file).

The following features may be implemented in the future (as we think
they are useful and fun):

- `LoadableMesh`, a `MeshObject` that gets its geometry definition from a file

- Additional materials like metal, plastic or glass

- Advanced scene management within the `World` class


`cg1` has been extended by Simon Hengel in 2004.  New features are:

- A `LoadableMesh` class


### Known bugs

- The hierarchical transformations do not work as intended, if
  the camera is a subobject.


### Authors
* Markus Klinik
* Simon Hengel

Bug reports and comments are welcome.
If you have implemented a feature or fixed a bug, please let us know.
