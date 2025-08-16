#ifndef READCSV_H
#define READCSV_H

#include <string>
#include "types.h"

class ReadCSV{
    private:
        vp data;
        std::string file_name;
        void load_csv();

    public:
        ReadCSV() = default;
        ReadCSV(const std::string& fname);
        const vp& get_data() const;

        void print_csv() const;
 };

#endif