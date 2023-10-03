#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

class CSVReader
{
    /*
    Class that manages basic reads and operations with csv files. constructor arguments
    are such that one can choose thier own delimiters.

    Everything is constructed so that the data is read into the private datamember
    "vector<vector<string>> data", so first index decides row, and second wich element.
    */

    public:
        CSVReader(const std::string& file, char delimit = ',');

        bool    read();
        void    display_contents() const;
        long unsigned int get_nr_rows() const;
        long unsigned int get_nr_cols() const;
        
        void    stoi_on_col(long unsigned int col);
        int     col_sum(long unsigned int col) const;



        const std::vector<std::vector<std::string>>& getData() const;


    private:

        const char delimiter{};
        long unsigned int nr_rows{};
        long unsigned int nr_cols{};


        const std::string filename{};
        std::vector<std::vector<std::string>> data{};
};

#endif  //CSVREADER_H