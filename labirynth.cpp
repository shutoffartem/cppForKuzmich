/**
 * @file labirynth.cpp
 * 
 * This program solves a labirynth problem by using depth-first search algorithm. 
 * All logic is implemented in the is_path_exists function.
 */

#include <iostream>
#include <vector>
#include <set>
#include <boost/program_options.hpp>
//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
#include <fstream>

namespace po = boost::program_options;
//namespace logging = boost::log;

using field = std::vector<std::vector<char>>;
using point = std::pair<int, int>;
using set_of_points = std::set<point>;

const char corridor = ' ';
const char wall = 'X';
const char start = 'A';
const char end = 'B';

std::ostream& operator<<(std::ostream& out, const field& labirynth);
std::istream& operator>>(std::istream& in, field& labirynth);
char get_cell_value(const field& labirynth, const point& p);
std::vector<point> neighbors(const field& labirynth, const point& p);
bool is_path_exists(const field& labirynth, const point& current, set_of_points& visited);
point find_point(const field& labirynth, char ch);
//void init_logging(const po::variables_map& vm);
field create_labirynth(const po::variables_map& vm);
po::variables_map read_program_options(int argc, char* argv[]);
std::unique_ptr<std::istream> get_input_stream(const po::variables_map& vm);

int main(int argc, char* argv[])
{
    try
    {
        auto vm = read_program_options(argc, argv);
//        init_logging(vm);

        auto input_stream = get_input_stream(vm);
        field labirynth;
        *input_stream >> labirynth;
       // BOOST_LOG_TRIVIAL(debug) << "Labirynth read successfully";
        //BOOST_LOG_TRIVIAL(debug) << labirynth;

        auto start_point = find_point(labirynth, start);
        auto visited = set_of_points();
        std::cout << 
            (
                is_path_exists(labirynth, start_point, visited)?
                    "Path exists" 
                    : "Path does not exist"
            ) << std::endl;
        return 0;
    }
    catch (const std::exception& e)
    {
        //BOOST_LOG_TRIVIAL(error) << e.what();
        return 1;
    }    
}

/*
 * Get input stream. Helper function.
 * 
 * @param vm Program options variables map
 * @return Input stream
 */
std::unique_ptr<std::istream> get_input_stream(const po::variables_map& vm)
{
    
    if (vm.count("filename"))
    {
        auto filename = vm["filename"].as<std::string>();
        auto in = std::make_unique<std::ifstream>(filename);
        if (!in->is_open())
            throw std::runtime_error("Cannot open file");
       // BOOST_LOG_TRIVIAL(debug) << "Reading labirynth from file...";
        return in;
    }
    return std::make_unique<std::istream>(std::cin.rdbuf());
}

/*
 * Read program options. Helper function.
 * 
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Program options
 */
po::variables_map read_program_options(int argc, char* argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("filename", po::value<std::string>(), "input labirynth filename")
        ("verbose", "produce verbose output");
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        throw std::runtime_error("Help requested");
    }
    return vm;
}


/*
 * Initialize logging. Helper function.
 * 
 * @param vm Program options variables map
 */
/*void init_logging(const po::variables_map& vm)
{
    if (vm.count("verbose"))
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::debug
        );
    else
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::info
        );
}*/


/*
 * Create labirynth. Helper function.
 * 
 * @param vm Program options variables map
 * @return Labirynth
 */
field create_labirynth(const po::variables_map& vm)
{
    field labirynth;
        
    if (vm.count("filename"))
    {
        std::ifstream in(vm["filename"].as<std::string>());
        if (!in)
            throw std::runtime_error("Cannot open file");
       // BOOST_LOG_TRIVIAL(debug) << "Reading labirynth from file...";
        in >> labirynth;
    }
    else
    {
        //BOOST_LOG_TRIVIAL(debug) << "Reading labirynth from standard input...";
        std::cin >> labirynth;
    }
    //BOOST_LOG_TRIVIAL(debug) << "Labirynth read successfully";
    return std::move(labirynth);
}


/*
 * operator>> for field. Reads a labirynth from the input stream.
 * Spaces are corridors, X are walls; A is the starting point, B is the end.
 * If function meeets the empty line, it stops the reading and 
 * considers the labirynth read to the end.
 * Example of an input:
 * XXX XX
 * X A  X
 * XXX  X
 * X    X
 * X B  X
 * XX XXX
 * 
 * @param in The input stream.
 * @param labirynth The labirynth to be read.
 * @return The input stream.
 */
std::istream& operator>>(std::istream& in, field& labirynth)
{
    char ch;
    unsigned int width = 0;
    unsigned int row_index = 0;
    std::vector<char> current_row;
    bool met_a = false, met_b = false;
    while (in.get(ch))
    {
        if (ch == '\n')
        {
            if (current_row.size() == 0)
                break;
            if (row_index == 0)
                width = current_row.size();
            if (row_index > 0 && labirynth.back().size() != width)
                throw std::runtime_error(
                    "All rows must have the same width; Incorrect width at line "
                    + std::to_string(row_index));
            
            labirynth.push_back(current_row);
            current_row.clear();
            row_index++;
        }
        else if (ch == ' ' || ch == 'X' || ch == 'A' || ch == 'B')
        {
            current_row.push_back(ch);
            if (ch == 'A')
                met_a = true;
            else if (ch == 'B')
                met_b = true;
        }
        else
            throw std::runtime_error(
                "Invalid character in labirynth, at line "
                + std::to_string(row_index + 1)
                + ", column "
                + std::to_string(current_row.size()));
        
    }
    if (!met_a || !met_b)
    {
        throw std::runtime_error("Labirynth must contain both 'A' and 'B'");
    }
    return in;
}


/*
 * operator<< for field. Prints the labirynth.
 * Example of usage:
 * std::cout << labirynth << std::endl;
 * 
 * @param out The output stream.
 * @param labirynth The labirynth to be printed.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& out, const field& labirynth)
{
    out << "---\n";
    for (const auto& row : labirynth)
    {
        for (const auto& cell : row)
            out << cell;
        out << '\n';
    }
    return out;
}


/*
 * Returns the point of the first occurrence of the given character.
 * 
 * @param labirynth The labirynth.
 * @param ch The character.
 * @return The point of the first occurrence of the given character.
 */
point find_point(const field& labirynth, char ch)
{
    for (unsigned int i = 0; i < labirynth.size(); i++)
        for (unsigned int j = 0; j < labirynth[i].size(); j++)
            if (labirynth[i][j] == ch)
                return {i, j};
    throw std::runtime_error("Character " + std::string(1, ch) + " not found in labirynth");
}


/*
 * operator[] for field. Returns the character at the given point.
 * 
 * @param labirynth The labirynth.
 * @param p The point.
 * @return The character at the given point.
 */
char get_cell_value(const field& labirynth, const point& p)
{
    return labirynth[p.first][p.second];
}


/*
 * Returns the neighbors of the given point.
 * 
 * @param labirynth The labirynth.
 * @param p The point.
 * @return The neighbors of the given point.
 */
std::vector<point> neighbors(const field& labirynth, const point& p)
{
    std::vector<point> result;
    if (p.first > 0)
        result.push_back({p.first - 1, p.second});
    if (p.first < labirynth.size() - 1)
        result.push_back({p.first + 1, p.second});
    if (p.second > 0)
        result.push_back({p.first, p.second - 1});
    if (p.second < labirynth[0].size() - 1)
        result.push_back({p.first, p.second + 1});
    return std::move(result);
}


/*
 * Checks if a path exists from 'A' to 'B' in the labirynth.
 * Function demonstrates recursion, be careful.
 * 
 * @param labirynth The labirynth to check.
 * @return true if a path exists, false otherwise.
 */
bool is_path_exists(const field& labirynth, const point& current, set_of_points& visited)
{
    if (get_cell_value(labirynth, current) == end)
        return true;
    if (get_cell_value(labirynth, current) == wall || visited.count(current))
        return false;
    visited.insert(current);

    for (const auto& neighbor : neighbors(labirynth, current))
        if (is_path_exists(labirynth, neighbor, visited))
            return true;
    return false;
}
