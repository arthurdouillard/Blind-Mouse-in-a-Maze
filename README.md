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
