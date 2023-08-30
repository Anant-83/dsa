# Incubyte_Assessment_Chandrayaan3

## Problem Statement- Chandrayaan 3 Lunar Craft: Galactic Space Craft Control

### Description :

As a scientist at ISRO controlling the latest lunar spacecraft Chandrayaan 3, your task is to develop a program that translates commands sent from Earth into instructions understood by the spacecraft. The spacecraft navigates through the galaxy using galactic coordinates, represented by x, y, z coordinates (x for east or west location, y for north or south location, and z for distance above or below the galactic plane).

### Requirements :

You will be given the initial starting point (x, y, z) of the spacecraft and the direction it is facing (N, S, E, W, Up, Down). The spacecraft receives a character array of commands, and you are required to implement the following functionalities:

1. Move the spacecraft forward/backward (`f`, `b`): The spacecraft moves one step forward or backward based on its current direction.
2. Turn the spacecraft left/right (`l`, `r`): The spacecraft rotates 90 degrees to the left or right, changing its facing direction.
3. Turn the spacecraft up/down (`u`, `d`): The spacecraft changes its angle, rotating upwards or downwards.

### Usage :

To run the test file, execute the following command: `npm run test test.js`
