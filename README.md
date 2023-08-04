# Final Project- OpenFlights

### Group members:
* rshah267
* bct6
* jprokop2
* coroz2

# How does our project work?
Our program uses data from [Open Flights](https://openflights.org/data.html) to analyze the connectedness of the world via air travel.
We use BFS to traverse every single node and to see which airports are reachable from a certain airport. Our Dijkstra's algorithim finds the shortest path based on haversine distance between two airports. Kosaraju's algorithim partitions our graph into subgraphs which are strongly connected; in other words, within each strongly connected component identified by our function there exists a sequence of flight routes between any two airports

# Organization
Code:
- Three Algorithms 
    - The BFS traversal code is contained within the BFS.h and BFS.cpp files
        - The BFS traversal is run within main.cpp using the created graph and user inputs
    - The Dijkstra's Algorithm traversal code is contained within the Dijkstra.h and Dijkstra.cpp files
        - The Dijkstra's Algorithm traversal is run within main.cpp using the created graph and user inputs
    - The Kosaraju traversal code is contained within the airports_kosaraju.h and airports_kosaraju.cpp files
        - The IDDFS traversal is run within main.cpp using the created graph and user inputs

- Graph
    - The Airport class is contained within the airport.h and airport.cpp files
        - Contains IATA, airport ID, country, city, latitude, and longtidue information for each airport
        - This is located within airport.cpp and airport.h
    - The Edge class is contained within the edge.h and edge.cpp files
        - Contains airport's destination, and weight for each route using the haversine function
        - This is located within edge.cpp and edge.h
    - The AirportsGraph class is contained within the airports_graph.h and airports_graph.cpp files
        - Contains functions for creating, adjusting, and gaining information for the graph created from the OpenSource airport and routes data.
        - Run in main.cpp using provided and modified data files
        - This is located within airports_graph.cpp and airports_graph.h
 
- Written Report and Presentation
    - The written report is named results.md and is located within the results directory
        
    - The presentation will be found within the google drive folder
        
   
- Testing and Data
    - Testing
        - Tests are located in their own directory `/tests`
        - Within this directory we have our own testing data
        - The actual tests are within the file tests_graph.cpp
    - Data
        - Our data files are found within the '/src' directory
        - The data for our airports is found within airports.dat
        - The data for our routes is found within routes.dat


# Running and Building Executables

To download our program, please copy and paste this line to your terminal:

```
https://github.com/rohanshah22/flights-traversal/archive/refs/heads/main.zip
```
Once the repository is copied into your local cs225 virtual machine, run the following commands in the terminal to create executable files.
First navigate to the project_flights directory.
- mkdir build
- cd build
- cmake ..
- make

At this point the program is ready to be executed from the terminal. To execture the following programs it is important to know that an IATA represents an airport's specific identification code. The following commands are available:
- To execute a MakeGraph
    - Full construction, output to terminal
        - ./main MakeGraph_toCout
    - Full construction, write to file
        - ./main Kosaraju_toFile

- To execute a BFS
    - Full traversal, output to terminal
        - ./main BFS_toCout
    - Full traversal, write to file
        - ./main BFS_toFile
    - Single traversal from given starting node, output to terminal
        - ./main BFS_toCout IATA
    - Single traversal from given starting node, write to file
        - ./main BFS_toFile IATA

- To execute a Dijkstra
    - Single traversal from given starting node to destination node, output to terminal
        - ./main Dijkstra_toCout IATA1 IATA2
    - Single traversal from given starting node, write to file
        - ./main Dijkstra_toFile IATA1 IATA2

- To execute a Kosaraju
    - Full traversal, output to terminal
        - ./main Kosaraju_toCout
    - Full traversal, write to file
        - ./main Kosaraju_toFile

# Building and Running Tests 

Building:
- To build the test suite, please input `make test` in the console.
- To run all of the test suites, please input `./test` in the console
- To run specific tests, please try any of the following keywords in the console:
    - ./test "[parser]"
        - Tests if our data was correctly parsed
    - ./test "[AirportsGraph]"
        - Tests if our graph was correctly built
    - ./test "[Dijkstras]"
        - Tests that our graph is correctly traversed using Dijkstra's algorithim
    - ./test "[Kosaraju]" 
        - Tests that our graph is correctly traversed using Kosaraju
    - ./test "[BFS]"
        - Tests that our graph is correctly traversed using BFS