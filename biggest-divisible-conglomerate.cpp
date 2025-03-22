// Programmer: Walter Cordero
// This is my 7th c++ program

#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm> // sorting

using namespace std;


// converts a vector of integers into strings
string vec_to_string(vector<int> v) {
    if (v.empty()) {  //handles an empty case 
        return "{}";
    }

    string result = "{";
    for (size_t i = 0; i < v.size(); i++) {
        result += to_string(v[i]);     // int to string

        if (i != v.size() - 1){
            result += ", ";
        }
    }
    result += "}";

    return result;

}

// function that uses recursion to find the largest %=0 subset 
vector<int> find_largest_conglomerate(vector<int>& nums, size_t index, vector<int>& current) {
    if (index == nums.size()){ // base case 
        return current;
    }
    // moving through the given list
    vector<int> without = find_largest_conglomerate(nums, index + 1, current);

    bool can_add = true;
    for (int num : current) {
        if ((nums[index] % num != 0) && (num % nums[index] != 0)) {
            can_add = false;
            break;
        }
    }


    vector<int> with = current;
    //calculating ^ ->
    if (can_add) {
        with.push_back(nums[index]);
        with = find_largest_conglomerate(nums, index + 1, with);
    }

    if (with.size() > without.size()) {
        return with;
    } else {
        return without;
}

}

// function to find main bdc
vector<int> biggest_divisible_conglomerate(vector<int> input) {

    if (input.empty()) {
    return {};
    }

    sort(input.begin(), input.end()); // Sorting for smoothness

    vector<int> current;
    return find_largest_conglomerate(input, 0, current);
}