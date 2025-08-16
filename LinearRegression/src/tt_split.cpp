#include <random>
#include <algorithm>
#include <chrono>
#include "tt_split.h"

pvp tt_split(const vp& dataset, int test_ratio){

    vp data_shuffled = dataset;

    auto seed = static_cast<std::mt19937::result_type>(
    std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 rng(seed);

    std::shuffle(data_shuffled.begin(), data_shuffled.end(), rng);
    
    double total_size = static_cast<double>(data_shuffled.size());
    double double_split_point = total_size * (100.0 - test_ratio) / 100.0;
    auto split_point = static_cast<vp::iterator::difference_type>(double_split_point);

    vp train_set(data_shuffled.begin(), data_shuffled.begin() + split_point);
    vp test_set(data_shuffled.begin() + split_point, data_shuffled.end());

    return {train_set, test_set};
}
