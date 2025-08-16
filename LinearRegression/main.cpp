#include <iostream>
#include "ReadCSV.h"
#include "LinReg.h"
#include "tt_split.h"

int main(){

    int ratio{20}; // must be between 1 to 99
    std::string user_dataset;

    std::cout << "---SIMPLE LINEAR REGRESSION CALCULATOR---\n \n";
    std::cout << "Enter the full path to your dataset or just file name if it's in the current directory: \n";
    std::cin >> user_dataset;
    std::cout << "Enter the test split ratio (e.g., 25 for 25percent test data):\n";
    std::cin >> ratio;

    ReadCSV dataset(user_dataset);
    const vp& data = dataset.get_data();
    
    pvp train_test = tt_split(data, ratio);
    vp train_set = train_test.first;
    vp test_set = train_test.second;

    LinReg model(train_set);
    float mse = model.evaluate(test_set);
    
    std::cout << "mse is: " << mse << '\n';
    std::cout << "slope: " << model.get_slope() << "    intercept: " << model.get_intercept() << '\n';

    while (true) {
        std::cout << "\nEnter a value for x to predict y (or type 'q' to quit): ";
        std::string input;
        std::cin >> input;

        if (input == "q" || input == "Q") break;

        try {
            float x = std::stof(input);
            std::cout << "Predicted y: " << model.predict(x) << '\n';
        } catch (...) {
            std::cout << "Invalid input. Please enter a number or 'q' to quit.\n";
        }
    }


    return 0;
}