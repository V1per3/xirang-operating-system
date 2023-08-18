**This is an operation system based on C++**
***
The project is developed based on Viktor Engelmann's tutorial(http://www.algorithman.de/Algorithmen/kayos), using a combination of assembly language and C++. The objective is to create an operating system that is capable of running on a virtual machine (while Viktor used VirtualBox, this project employs VMware).

The project has successfully accomplished various tasks, including the implementation of interrupt handling, keyboard and mouse control, PCI, desktop environment, multitasking, dynamic memory management, and partial networking functionality.

The directory structure of this project is as follows:

```
#   ├── include
#   │	├── common
#   │	├── drivers
#   │	├── gui
#   │	├── hardwarecommunication
#   │	├── memorymanagement.h
#   │	├── multitasking.h
#   │	└── gdt.h
#   ├── src
#   │	├── common
#   │	├── drivers
#   │	├── gui
#   │	├── hardwarecommunication
#   │	├── gdt.cpp
#   │	├── loader.s
#   │	├── memorymanagement.cpp
#   │	├── multitasking.cpp
#   │   └── kernel.cpp
#   ├── linker.ld
#   ├── Makefile
#   └── README.md
```
