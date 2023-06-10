<img width="1050" alt="img" src="https://user-images.githubusercontent.com/69338674/207484685-bc6f1cfb-8847-454e-813a-8d575bcf61b8.png">

# About

This is a project exploring algorithm design for music composition purposes. It's an extension of my old CS 225 project, and with it, I plan to address a multitude of shortcomings in the old project (including actually finishing it) and provide more insight into the original leading question: 

**Given any .png image file, is it possible to produce a melodic sequence of notes out of the image data?**

Thank you to Johnson Chiang and Patrick Han for helping me out with writing the majority of the test cases in the old project, which let me patch a lot of holes in it.

## Codebase

I used [midifile](https://github.com/craigsapp/midifile), [lodepng](https://github.com/lvandeve/lodepng), and the [CS225 PNG/HSLAPixel libraries](https://github.com/cs225-illinois/release-f22/tree/main/mp_stickers/lib) to provide infrastructure for the codebase. These libraries can be accessed in `./lib`.

All major files in the codebase are located in `./src`. The algorithms and traversals are located in `./src/algorithms/`.
