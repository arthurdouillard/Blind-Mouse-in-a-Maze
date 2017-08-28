#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <memory>
#include <string>


namespace maze
{

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

const std::vector<Direction> directions = {UP, RIGHT, DOWN, LEFT};

enum Tile
{
    WALL,
    ROAD,
    CHEESE
};


class Mouse
{
public:
    Mouse() {};
    Mouse(std::string& path)
    {
        read_map(path);
    }

    bool read_map(std::string&);
    void solve_maze();
    
private:
    std::pair<int, int> coords;
    std::shared_ptr<std::vector<std::vector<Tile>>> map;
    
    bool move(const Direction&);
    bool is_success() const;
    bool solve_maze_rec(std::vector<Direction>&, std::vector<std::pair<int, int>>&);
    void clearn(std::vector<Direction>&, std::vector<std::pair<int, int>>&, int);
    std::string dir2str(const Direction&) const;
    std::pair<int, int> get_next_coords(const Direction&) const;
    Direction invert_direction(const Direction&) const;    
};

}

#include "mouse.hxx"