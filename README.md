# Sidewinder File Editor (sfe)

Hi everyone!

This is simple program type of "proof of concept".

This program will be show my progress with learning and understanding C++ and QT library.

Target of this project is creation of simple file editor



*** BUILD INSTRUCTION ***

*This project require: Qt library, make and gcc tool.*

*This program has been tested on ArchLinux (x86_64).*


1. Prepare source:
  ```bash
  $ git clone https://gitlab.com/Sidewinder22/SideFileEditor.git
  $ cd SideFileEditor
  $ git checkout preint/dev_sop
  ```

2. Build the source:

  Remember to use qmake for QT5!
  ```bash
  $ mkdir build && cd build
  $ qmake ..         // qmake-qt5
  $ make
  ```

3. Run project:
  ```bash
  $ ./SideFileEditor
  ```
