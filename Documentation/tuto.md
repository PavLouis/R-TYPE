# Getting Started Tutorial/How-to's

## Content

- [Prerequisites](#prerequisites)
    - [Windows](#window)
    - [Linux](#linux)
- [How to clone](#how-to-clone)
- [How to compile](#how-to-compile)
- [How to play](#how-to-play)

=======
## Prerequisites
-------
To begin with the setup of the game you have to get things to make the game work :
### Window

1. We will start with the git installation. You have to go there in first. https://git-scm.com/download/win
Then choose the correct version for you computer
Launch the binary to setup git and then it will be done by itself.

2. Now, let's talk about SFML lib.
- To do that you have to clone this repo with Power Shell : 

    ```git clone git@github.com:SFML/SFML.git```
- Then go to environment value and set a new path wich is the adress of the SFML folder

3. Cmake is a mandatory too. To get it, you have to go there :
https://cmake.org/download/
- Install the source distribution Windows Source.
- After that, launch the binary setup who will install by itself the cmake binary. When you'll be front of the cmake application, you'll have to enter in the path the address of SFML lib. Once it's done, put the adress of the folder you want to compile (we will see that just after) in the source. And that's all. We can now see how we can do in Linux.
### Linux

- This guide is based on Ubuntu distributions

1. `sudo apt udpate`

2. Install GCC, make and other tools: `sudo apt install build-essential`

3. Download and install VSCode
 - <https://code.visualstudio.com/docs/setup/linux>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
  - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

4. Install SFML dependencies:
 - Note that this is only for linux, refer to <https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php>
 - `sudo apt install libx11-dev xorg-dev freeglut3-dev libudev-dev`
 - Other dependencies might be required depending on your distribution, refer to the link above.

5. Install CMake
- `sudo apt install cmake`

### How to clone
-------
We will start by seeing how to clone the repo. The way of doing is the in Windows and Linux so you don't have to worry about that. Enter that in you shell :

    git clone git@github.com:EpitechPromo2025/B-CPP-500-BDX-5-1-rtype-matheo.pons.git
Now that you have the repo, Cmake and SFML lib, you can compile all of that to get the game.

### How to compile
-------
Linux :
Go to the repository of the project, and enter that in your shell :

    mkdir build
    cd build
    cmake ..
    cd ..
    make
    ./binary_name

Now you can enjoy this wonderful game !

Windows :
So let's start with launching Visual Studio.
Open the project folder.
Setup your settings so that work
Lauch the compile and enjoy.

### How to play
-------
Now that you are in the game, let's how to play.
* Movement
    Press[Z] to move to the top of the screen
    Press[S] to move to the bottom of the screen
    Press[Q] to move to the left of the screen
    Press[D] to move to the right of the screen
* Shot
    Press[SPACE] to shoot
    Hold the shoot button to shoot a charged blast
