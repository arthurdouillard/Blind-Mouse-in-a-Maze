# Blind Mouse in a Maze

This is an interview question, that I've screwed up, but I wanted to try to do
it with more time. Here is my solution:

## The problem

A blind mouse has lost its cheese in a maze. Help it find its food!

* You do not know neither mouse's coordinates nor cheese's.
* You do not have a global view of the map (which is at most 100x100).
* You only have a handful usable functions:

```
bool move(const Direction& dir);
```

Returns `false` if the mouse stumble on a wall, returns `true` otherwise and move
the mouse.

```
bool is_success() const;
```

Returns `true` if the mouse is on the cheese, `false` otherwise.

## The solution

To solve a maze, a **breath-first-search** would have been the most advisable.
However because to know the adjacent tiles, the mouse has to *actually move*.
It would have needed an annoying move-tracker.

Thus I've decided to simply use an **depth-first-search** with backtracking.
The path found is not always the shortest one, it is simply the first one found.

## Map

Maps are stored in a text file with:

* `o` being a wall.
* A space being a *road*.
* `m` being the mouse.
* `c` being the cheese.

## Example

```
$ ./mouse tests/test1.txt
oooooooooooooooooo
oom     o       co
ooooooo o oooooooo
ooooooo   oooooooo
oooooooooooooooooo
RIGHT RIGHT RIGHT RIGHT RIGHT DOWN DOWN RIGHT RIGHT UP UP RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT
```


```
$ ./mouse tests/test3.txt
ooo
omo
o o
o o
oco
ooo
DOWN DOWN DOWN
```

```
$ ./mouse tests/test2.txt
oooooooooooooooooooo
om      o         co
o oooo  o ooooo oooo
o o     o   ooo oooo
o ooooooooo o   o
o  oo     o ooooo
oo oo o   o o
o     ooooo o
o ooooo     o
o       ooooo
oooooooooo
DOWN DOWN DOWN DOWN RIGHT DOWN DOWN LEFT DOWN DOWN RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT UP RIGHT RIGHT RIGHT RIGHT UP UP UP UP UP LEFT LEFT UP UP RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT RIGHT
```
