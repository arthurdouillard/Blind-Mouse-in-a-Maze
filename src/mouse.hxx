#include "mouse.hh"

namespace maze
{

inline void
Mouse::solve_maze()
{
    std::vector<Direction> path;
    std::vector<std::pair<int, int>> path_coords = {this->coords};
    this->solve_maze_rec(path, path_coords);
    for (auto dir : path)
        std::cout << this->dir2str(dir) << " ";
    std::cout << std::endl;
}

inline bool
Mouse::solve_maze_rec(std::vector<Direction>& path,
                      std::vector<std::pair<int, int>>& path_coords)
{
    if (this->is_success())
        return true;

    for (auto dir : directions)
    {
        auto next_coords = this->get_next_coords(dir);
        if (std::find(path_coords.begin(), path_coords.end(), next_coords) != path_coords.end())
            continue;
        
        int curr = path.size();
        if (this->move(dir)) // If next direction is not a wall.
        {            
            path.push_back(dir);
            path_coords.push_back(this->coords);
            if (this->solve_maze_rec(path, path_coords))
                return true;
            else
                this->clearn(path, path_coords, path.size() - curr);
        }
    }

    return false;
}

inline std::string
Mouse::dir2str(Direction& dir) const
{
    switch (dir)
    {
        case UP     : return "UP";
        case RIGHT  : return "RIGHT";
        case DOWN   : return "DOWN";
        case LEFT   : return "LEFT";
    }
}

inline void
Mouse::clearn(std::vector<Direction>& path,
              std::vector<std::pair<int, int>>& path_coords,
              int n)
{
    for (int i = 0; i < n && path.size() > 0; i++)
    {
        auto last = this->invert_direction(path.back());
        this->move(last);
        path.pop_back();
        path_coords.pop_back();
    }
}

inline bool
Mouse::is_success() const
{
    return map->at(this->coords.second).at(this->coords.first) == Tile::CHEESE;
}

inline bool
Mouse::move(Direction& dir)
{
    auto next_coords = this->get_next_coords(dir);
    if (map->at(next_coords.second).at(next_coords.first) == Tile::WALL)
        return false;
    
    this->coords = next_coords;
    return true;
}

inline std::pair<int, int>
Mouse::get_next_coords(Direction& dir) const
{
    auto next_coords = this->coords;
    switch (dir)
    {
        case UP     : next_coords.second--; break;
        case RIGHT  : next_coords.first++;  break;
        case DOWN   : next_coords.second++; break;
        case LEFT   : next_coords.first--;  break;
    }

    return next_coords;
}

inline Direction
Mouse::invert_direction(Direction& dir) const
{
    switch (dir)
    {
        case UP     :   return DOWN;
        case RIGHT  :   return LEFT;
        case DOWN   :   return UP;
        case LEFT   :   return RIGHT;
    }
}

inline bool
Mouse::read_map(std::string& path)
{
    int x, y = 0;
    std::ifstream stream(path);
    
    if (!stream.is_open())
        return false;

    this->map = std::make_shared<std::vector<std::vector<Tile>>>();
    for (std::string line; std::getline(stream, line); )
    {
        std::cout << line << std::endl;
        std::vector<Tile> row;

        for (auto c : line)
        {
            x++;

            if (c == 'o')
                row.push_back(Tile::WALL);
            else if (c == 'm')
            {
                this->coords = std::make_pair(x, y);
                row.push_back(Tile::ROAD);
            }
            else if (c == ' ')
                row.push_back(Tile::ROAD);
            else if (c == 'c')
                row.push_back(Tile::CHEESE);
            else
                return false;
        }

        this->map->push_back(row);
        y++;
        x = 0;
    }

    return true;
}

}