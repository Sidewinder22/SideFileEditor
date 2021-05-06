# Sidewinder File Editor (SFe)

![C/C++ CI](https://github.com/Sidewinder22/SideFileEditor/workflows/C/C++%20CI/badge.svg?branch=master)

## Description

This is a simple application created for learning purposes.  
I create it to learn more about C++ (14/17/20) and QT5 library.

### Project goals

* learning how to design software in C++ (with QT library),
* learning new C++ standards (17/20),
* gaining knowledge about the QT5 library.

### Features

* open / show content / close files,
* creating and saving new text files,
* saving changes in the existing files,
* dock containing open files / buffers.

In this editor, everything is buffer. Open and new files are stored in buffers. Only when a save is requested, the content is stored in the file.  
All communication between components is implemented using slots and signals from the QT5 library.

## Build instruction

### Build

Build source using script:

    ./build.sh

Or build it manually:

    mkdir build && cd build
    qmake ..
    make -j $(nproc)

### Run

To run project:

    cd build
    ./SFe

![Screenshot](images/screenshot_2.png)
