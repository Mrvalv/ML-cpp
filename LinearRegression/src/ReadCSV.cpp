#include <fstream>
#include <sstream>
#include <iostream>
#include "ReadCSV.h"

ReadCSV::ReadCSV(const std::string& fname) : file_name(fname) {
    load_csv();
}

void ReadCSV::load_csv(){
    data.clear();
    std::ifstream file(file_name);
    if (!file.is_open()){
        std::cout<<"Failed to open the file \n";
        return;
    }

    std::string line;
    while(std::getline(file, line)){
        std::stringstream ss(line);
        float x, y;
        char comma;
        if (ss >> x >> comma >> y && comma == ','){
        data.emplace_back(x, y);
        }
    } 
    file.close();
}


const vp& ReadCSV::get_data() const{
    return data;
}


void ReadCSV::print_csv() const{
    for (const auto& p : data) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }
}
