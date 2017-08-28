#include "mouse.hh"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Give a map file in input!" << std::endl;
        exit(1);
    }
    auto path = std::string(argv[1]);

    auto mouse = maze::Mouse();
    if (!mouse.read_map(path))
    {
        std::cerr << "Something went wrong while building the map!" << std::endl;
        exit(1);
    }  
    mouse.solve_maze();  
}