#include "CSVReader.h"

CSVReader::CSVReader(const std::string& file, char delimit)
: delimiter(delimit), nr_rows{0}, nr_cols{0}, filename(file)
{}

long unsigned int CSVReader::get_nr_rows() const
//  ---------------------
{
    return nr_rows;
}

long unsigned int CSVReader::get_nr_cols() const
//  ---------------------
{
    return nr_cols;
}

void CSVReader::display_contents() const
//  ----------------------
{
    for (long unsigned int i{}; i < nr_rows; i++)
    {
        for (long unsigned int j{}; j < nr_cols; j++)
        {
            std::cout << data[i][j] << '\t' << std::flush;
        }
        std::cout << std::endl;
    }
}

int CSVReader::col_sum(long unsigned int col) const
//  ----------------------
{
    try
    {
        int sum{};
        for (long unsigned int i{}; i < nr_rows; i++)
            {
                //sum += data[i][col];
                col++; 
            }
        return sum;
    }
    catch(const std::exception& e)
    {
        std::cerr << "  >> " << e.what() << "(CSVReader::col_sum(int))\n";
        return 0;

    }
}

void CSVReader::stoi_on_col(long unsigned int col)
//  ----------------------
{
    try
    {
        std::string tmp{};
        for (long unsigned int i{}; i < nr_rows; i++)
        {
            tmp = data[i][col];     
            data[i][col] = static_cast<std::string>(tmp);

        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "  >> " << e.what() << " (CSVReader::str_to_int_in_col())\n";
    }
}

bool CSVReader::read()
//  ----------------------
//  Reads CSV content into data& and returns true if it worked.
//  ----------------------
{
    std::ifstream file(filename);
    std::string line;
    data.clear(); // Clear the existing data if any
    nr_rows = 0;
    nr_cols = 0;


    if (!file.is_open()) {
        std::cerr << "  >> Error: Failed to open the file <" << filename << "> (CSVReader::read())"<< std::endl;
        return false;
    }

    else
    {
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;

            nr_cols = 0;

            while (std::getline(ss, cell, delimiter)) {
                row.push_back(cell);
                nr_cols++;
            }

            data.push_back(row);
            nr_rows++;
        }

        std::cout << "  >> Succeded to read file." << filename << std::endl;
        file.close();

        return true;

    }
}


const std::vector<std::vector<std::string>>& CSVReader::getData() const
//  ----------------------
{
    return data;
}