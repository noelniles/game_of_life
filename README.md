## Conway's game of Life
### By Noel Niles 
Inspired by: _Data Structures and Program Design in C_ by Robert L. Kruse

#### About

The current implementation is limited to a 60x20 grid. Right now the
grid is bounded by a "sentinal hedge" which is just a bunch of dead
cells. This is because we need a new data structure.

#### Rules

1. Any live cell with > 2 live neighbors dies from under-population.
2. Any live cell with 2 or 3 live neighbors lives on to the next generation.
3. Any live cell with > 3 live neighbors dies from overcrowding.
4. Any dead cell with exactly 3 live neighbors becomes a live cell by reproduction.

#### How to Use
1. After cloning just run `make`. Running `make clean` will remove
   all of the object files and the executable.
2. Run the program with `./gol`
3. At the prompt, enter a list of coordinates that should be alive
   in the initial configuration. The first coordinate entered will
   the row and the next will be the column. To end the list enter `-1
   -1`. For example:
    ```
    # ./gol
    # 2 3 2 4 3 2 3 3 4 3 -1 -1
    ```
    will set the following coordinates as alive:
    ```
              (2,3) (2,4)
        (3,2) (3,3) (3,4)
              (4,3)
    ```
    Which will produce the following output:
    ```
        The current Life configuration is
                                                                    
          **                                                        
         **                                                         
          * 
    ```
    **I know this is tedious and inconvenient. Fixes are in progress.**

4. To step forward through the generations answer `y` when prompted.
5. When sufficiently entertained enter `n` to stop.
    * I plan to implement a way to save the current configuration to
      a file and then restart from the saved generation.

