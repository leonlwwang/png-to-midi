## Leading Question 
We are interested in learning about the “musical quality” of an image. The question we are interested in answering is that given any image file, can we produce a melodic sequence of notes out of the image data?

Given an image and its grid of pixel data, we want to convert each pixel based on its HSLA values into a designated note on the chromatic scale (on the scale, there are 12 possible notes in an octave and 10 octave ranges audible to the human ear, so 120 possible values). This will produce a rectangular-shaped weighted graph where the vertices are the notes and the edges are the number of intervals between two notes.

For example, if we have a node of note C connected to a node of note G, the absolute difference between the two notes is 6, because there are 6 notes on the chromatic scale between C and G.

By using Prim’s algorithm and the A* algorithm on this weighted graph, we will produce a minimum spanning tree and a shortest path tree respectively. Using a BFS/DFS traversal method for each tree, we can add a sequence of notes into a MIDI file and compare them. Since a minimum spanning tree connects every vertex to each other with the lowest cost and the shortest path tree creates a single path from start to end, we expect the MIDI file output for Prim’s algorithm to be larger. We can then learn from each output and perhaps do further processing with the MIDI files to compose a melodic and somewhat aurally-pleasing "song".

Note: to create and export MIDI files, we will use [Midifile](https://midifile.sapp.org/), a C++ library to write MIDI files with.

## Dataset Acquisition
Our dataset consists of images, which are widespread and flexible as a data format. We expect any acceptable image file to work as an input for our program. In the repository, we will provide a suite of publicly available test images to use on the program.

## Data Format
Our input images will be accepted as PNG files. The source of the image can be anywhere, so long as it is in PNG format. The size of the image is variable. We are planning to form a graph from the entire grid of pixels, so we will use all the input data to do so.

## Data Correction
The images are usually preprocessed and will not consist of error entry. However, we will be limiting the resolution of the image as a larger resolution could make the construction of the graph costly since we are using an adjacency matrix, which is better optimized for smaller images. However, we also do not want to work with an image of low resolution as this will not give much data to work with nor produce much of an interesting MIDI note sequence. Thus, we will likely impose image resolution constraints in order to ensure that the image is of fair size to work with, not too large or too small.

## Data Storage
Data Acquisition: $O(wh)$
We will be using a nested for-loop to convert the image’s pixels to notes row by row and insert them into a weighted graph represented as an adjacency matrix `M` where the cell `M[i, j]` holds the weight (interval) of the edge connecting vertices (notes) `i` and `j`. This matrix will elicit a time and space complexity of $O(wh)$, where $w$ and $h$ are the width and height of the image in pixels, respectively.

Algorithms: $O(wh)$
In terms of storage necessary for the two algorithms, Prim’s algorithm must output a minimum spanning tree represented as a new adjacency matrix, requiring a space complexity of $O(|V|)$ where $V$ is the number of vertices in the original matrix, and the A* algorithm requires a priority queue, which its worst case space complexity is also $O(|V|)$. The worst case space complexity for both algorithms combined comes out at $O(|V|) + O(|V|)$, which is just $O(|V|)$. The number of vertices in the original matrix, $V$, is equivalent to the number of pixels in the input image, w*h, so the space complexity can be rewritten as $O(wh)$.

Traversals: $O(V)$
We will run BFS/DFS traversals on the minimum spanning tree and shortest path trees produced by our algorithms, which (in its iterative implementation) requires the usage of a queue or stack respectively. BFS and DFS both elicit a space complexity of $O(|V|)$, where $V$ is the number of vertices in the minimum spanning tree or shortest path tree, depending on which one the traversal is being used on. This results in a general space complexity of $O(|V|)$, where $V$ is the number of vertices in whichever tree has more.

Total Space: $O(wh)$
Based on what we know, the total space complexity comes out to as: $O(wh) + O(wh) + O(V)$, where $V$ represents the number of vertices discovered by the BFS/DFS traversals. We know that $wh > V$ because the traversals are going through the minimum spanning tree and shortest path tree, which both are guaranteed to have fewer nodes than the weighted graph that they are based off of, which has $wh$ nodes. Therefore, the result is simplified to: $O(wh) + O(wh)$ which is $O(wh)$.

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