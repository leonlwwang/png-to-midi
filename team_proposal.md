## Leading Question 
We are interested in learning about the “musical quality” of an image. The question we are interested in answering is that given any image file, can we produce a melodic sequence of notes out of the image data?

Given an image and its grid of pixel data, we want to convert each pixel based on its HSLA values into a designated note on the chromatic scale (on the scale, there are 12 possible notes in an octave and 10 octave ranges audible to the human ear, so 120 possible values). This will produce a rectangular-shaped weighted graph where the vertices are the notes and the edges are the number of intervals between two notes.

For example, if we have a node of note C connected to a node of note G, the absolute difference between the two notes is 6, because there are 6 notes on the chromatic scale between C and G.

By using Prim’s algorithm and the A* algorithm on this weighted graph, we will produce a minimum spanning tree and a shortest path tree respectively. Using a BFS/DFS traversal method for each tree, we can add a sequence of notes into a MIDI file and compare them. Since a minimum spanning tree connects every vertex to each other with the lowest cost and the shortest path tree creates a single path from start to end, we expect the MIDI file output for Prim’s algorithm to be larger. We can then learn from each output and perhaps do further processing with the MIDI files to compose a melodic and somewhat aurally-pleasing "song".

**Note:** to create and export MIDI files, we will use [Midifile](https://midifile.sapp.org/), a C++ library to write MIDI files with.

## Dataset Acquisition
Our dataset consists of images, which are widespread and flexible as a data format. We expect any acceptable image file to work as an input for our program. In the repository, we will provide a suite of publicly available test images to use on the program.

## Data Format
Our input images will be accepted as PNG files. The source of the image can be anywhere, so long as it is in PNG format. The size of the image is variable. We are planning to form a graph from the entire grid of pixels, so we will use all the input data to do so.

## Data Correction
The images are usually preprocessed and will not consist of error entry. However, we will be limiting the resolution of the image as a larger resolution could make the construction of the graph costly since we are using an adjacency matrix, which is better optimized for smaller images. However, we also do not want to work with an image of low resolution as this will not give much data to work with nor produce much of an interesting MIDI note sequence. Thus, we will likely impose image resolution constraints in order to ensure that the image is of fair size to work with, not too large or too small.

## Data Storage (Space Complexity)
**Data Acquisition:** $O(wh)$

We will be using a nested for-loop to convert the image’s pixels to notes row by row and insert them into a weighted graph represented as an adjacency matrix `M` where the cell `M[i, j]` holds the weight (interval) of the edge connecting vertices (notes) `i` and `j`. This matrix will elicit a time and space complexity of $O(wh)$, where $w$ and $h$ are the width and height of the image in pixels, respectively.

**Algorithms:** $O(wh)$

In terms of the memory necessary for the two algorithms, Prim’s algorithm must output a minimum spanning tree represented as a new adjacency matrix, requiring a space complexity of $O(|V|)$ where $V$ is the number of vertices in the original matrix, and the A* algorithm requires a priority queue, which its worst case space complexity is also $O(|V|)$. The worst case space complexity for both algorithms combined comes out at $O(|V|) + O(|V|)$, which is just $O(|V|)$. The number of vertices in the original matrix, $V$, is equivalent to the number of pixels in the input image, w*h, so the space complexity can be rewritten as $O(wh)$.

**Traversals:** $O(V)$

We will run BFS/DFS traversals on the minimum spanning tree and shortest path trees produced by our algorithms, which (in its iterative implementation) requires the usage of a queue or stack respectively. BFS and DFS both elicit a space complexity of $O(|V|)$, where $V$ is the number of vertices in the minimum spanning tree or shortest path tree, depending on which one the traversal is being used on. This results in a general space complexity of $O(|V|)$, where $V$ is the number of vertices in whichever tree has more.

**Total Space:** $O(wh)$

Based on what we know, the total space complexity comes out to as: $O(wh) + O(wh) + O(V)$, where $V$ represents the number of vertices discovered by the BFS/DFS traversals. We know that $wh > V$ because the traversals are going through the minimum spanning tree and shortest path tree, which both are guaranteed to have fewer nodes than the weighted graph that they are based off of, which has $wh$ nodes. Therefore, the result is simplified to: $O(wh) + O(wh)$ which is $O(wh)$.

## Graph Algorithms
As detailed above, we will use Prim’s algorithm and the A* algorithm. 

## Function Inputs
For both algorithms, the input data will be the adjacency matrix produced from a weighted graph, that of which is produced from mapping the HSLA pixels in an image to notes as nodes. We convert our dataset, the image, into a usable input for the algorithms by converting it into a graph, which is passed into the functions. A* search requires a heuristic, and we will we using **Manhattan distance** as the heuristic to create a more informed search because the graph is a grid where we can only move in four possible directions, meaning that Euclidean distance will not work for our purposes.

## Function Outputs
Prim’s algorithm will produce a minimum spanning tree, which we will save as another adjacency matrix. A* search will produce a shortest path tree (SPT), which we could also save as an adjacency matrix or adjacency list. We will “hear” our outcome by searching through these two trees with BFS/DFS and load each node (or note) visited into a MIDI file. The file can then be exported to music production software like FL Studio or Ableton Live and used in composition.

## Function Efficiency (Time Complexity)
**Data Acquisition:** $O(wh)$

As detailed earlier, we will access the HSLA pixels of the image row by row to construct our adjacency matrix, which requires a nested for loop to complete. This produces a time complexity of $O(wh)$, where $w$ is the width of the image and $h$ is the height of the image.

**Algorithms:** $O((wh)^2) + O(E)$

Prim’s algorithm, when searching an adjacency matrix (our graph), has a time complexity of $O(|V|^2)$, where $V$ is the number of vertices in the matrix. Once again, $V$ is equivalent to the number of pixels in the image, wh, so the complexity can be represented as $O(wh)$. A* search time complexity is dependent on our Manhattan distance heuristic and how well it works, but the worst case performance is $O(|E|)$, where $E$ is the number of edges in the graph. This gives us a total time complexity of $O((wh)^2) + O(E)$.

**Traversals:** $O(wh)$

Both BFS and DFS have a time complexity of $O(|V|)$ which again is just $O(wh)$. We run the traversal twice, once for each algorithm, which is $O(wh) + O(wh)$ which is just $O(wh)$.

**Total Time:** $O((wh)^2) + O(E)$

The total time complexity comes out to: $O((wh)^2) + O(E) + O(wh) + O(wh)$, which is simplified to 
$O((wh)^2) + O(E)$. Depending on which is larger, the number of edges in the weighted graph, $O(E)$, or the dimension of the image squared, $O((wh)^2)$, the larger value will take precedence.

## Further Improvements
As we know, Prim's algorithm minimizes the total weight of all edges in the graph. And we also know that A* search minimizes the total cost of the path from vertex A to B. Recall that we are defining the weight of an edge to be the interval of notes between two vertices (remember that vertices are notes). If we minimize this edge weight, then we can expect the resulting MIDI files to have sequences of notes that are closer to each other within the chromatic scale. But this doesn't necessarily sound good. What if we aren't interested in minimizing the weight, but we're interested in having the most melodic-sounding interval between notes? Minimization of the cost path is done when the weights have to do with things such as distance, or money, or some unit of measure that we want to optimize the cost of. But in this case, we're interested in finding the best interval between two notes that sound good in sequence -- this way, we can construct a proper melody.

Perhaps we can somehow redefine the "lowest cost" path in Prim's and A* to be the "most melodic" path and run a modified version of the two algorithms.

## Timeline
- [x] Data acquisition
- [x] Environment setup (files, libraries, git)
- [x] Image processing functionality
- [x] Prim’s algorithm **at least finish this by mid-project check in**
- [x] A* algorithm
- [x] BFS/DFS traversal of minimum spanning tree and SPT
- [x] Cumulative function testing
- [x] Possible improvement for current output (Leon discussed with Abhilash about graph efficiency improvements)
- [x] Final tests
- [x] Submission/presentation
