## Leading Question 
We are interested in learning about the “musical quality” of an image. The question we are interested in answering is that given any image file, can we produce a melodic sequence of notes out of the image data?

Given an image and its grid of pixel data, we want to convert each pixel based on its HSLA values into a designated note on the chromatic scale (on the scale, there are 12 possible notes in an octave and 10 octave ranges audible to the human ear, so 120 possible values). This will produce a rectangular-shaped weighted graph where the vertices are the notes and the edges are the number of intervals between two notes.

For example, if we have a node of note C connected to a node of note G, the absolute difference between the two notes is 6, because there are 6 notes on the chromatic scale between C and G.

By using Dijkstra's algorithm and the A* algorithm on this weighted graph, we will produce two shortest path trees. Using a BFS/DFS traversal method for each tree, we can add a sequence of notes into a MIDI file and compare them. Since we know that Dijkstra's algorithm is greedy and A* is more informed, we hypothesize that the MIDI file produced out of Dijkstra’s SPT will have a longer length than the file produced from the A* SPT. We can then learn from the output and perhaps do further processing with the MIDI files to compose a melodic and somewhat aurally-pleasing "song".

**Note**: to create and export MIDI files, we will use [Midifile](https://midifile.sapp.org/), a C++ library to write MIDI files with.

## Dataset Acquisition
Our dataset consists of images, which are widespread and flexible as a data format. We expect any acceptable image file to work as an input for our program. In the repository, we will provide a suite of publicly available test images to use on the program.

## Data Format
Our input images will be accepted as PNG files. The source of the image can be anywhere, so long as it is in PNG format. The size of the image is variable. We are planning to form a graph from the entire grid of pixels, so we will use all the input data to do so.

## Data Correction
The images are usually preprocessed and will not consist of error entry. However, we will be limiting the resolution of the image as a larger resolution could make the construction of the graph difficult, since we are thinking of using an adjacency matrix, which is better optimized for a smaller dataset. Thus, we will likely impose image resolution constraints in order to ensure that the image is of fair size to work with, not too large or too small.

## Data Storage
We will be using a nested for-loop to transfer the image pixels into a graph, and for that we will have an estimate of $O(n^2)$ as the Big O efficiency for time. We will be using the heap for Dijkstra’s algorithms, and it’s time complexity will be $O((|V| + |E|) log V)$ and space will be $O(|V| + |E|)$.

## Algorithm
TBD

## Timeline
- [x] Data acquisition
- [ ] Environment setup (files, libraries, git)
- [ ] Image processing functionality
- [ ] Dijkstra’s algorithm
- [ ] A* algorithm
- [ ] BFS/DFS traversal of SPT
- [ ] Cumulative function testing
- [ ] Possible improvement for current output
- [ ] Final tests
- [ ] Submission/presentation
