# PNG-to-MIDI...?

by Leon Wang, Johnson Chiang, Patrick Han

## About

For the CS 225 Final Project, we wanted to test the “musical quality” of an image. The question we are interested in answering is that given a .png file, can we produce a melodic sequence of notes out of the image data?

Full project details and overview can be found in `team_proposal.md`. A visual walkthrough of the algorithms used and project findings can be found in `results.md` (the report).

**// ADD VIDEO HERE //**

## Instructions

To build the project, navigate to the `./build` directory and run `make` to build the project. 

A complete demonstration of all algorithms and traversals used in this project is provided in `./entry/main.cpp`. To see the output, after making the project simply run `./main`. 

If you'd like to switch out the .png file used, you can replace it by modifying the filepath name passed in as a string to the new file inside of the `NoteGraph()` constructor on line **13**. For example: `NoteGraph("../images/mynewimage.png")`.

A test suite of .png files have been provided in the `./images` directory. The images are split into three folders, `basic/`, `small/`, and `large/` (the `markdown/` directory is for the images in `results.md` and is unrelated).

:warning: **Please use images from `basic/` and `small/` only. You will likely get a "killed" process in main if you try running the `large/` images because the codebase can only manage to process images of up to roughly 200x200 in resolution, depending on your system. This is due to memory inefficiency in the current implementation.**

If you use a your own custom .png file and recieve a `PNG error` in the terminal, you specified the incorrect filepath. Make sure the path starts at the root `../`.

To run our test suite, in the terminal `make test` in the `./build` directory and then run `./test`.

## File Structure

### Codebase

We used [midifile](https://github.com/craigsapp/midifile), [lodepng](https://github.com/lvandeve/lodepng), and the [CS225 PNG/HSLAPixel libraries](https://github.com/cs225-illinois/release-f22/tree/main/mp_stickers/lib) to provide infrastructure for our codebase. These libraries can be accessed in `./lib`.

All major files in our codebase are located in `./src`. The weighted graph and data-parsing details are located in `Key.h`, `Note.h`, `NoteGraph.cpp`, and `NoteGraph.h`. The algorithms and traversals are located in `./src/algorithms/`. 

### Tests

Our test suite is located in `./tests`. There are six .cpp files inside that test each part of our code.
