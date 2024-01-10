#include <iostream>
#include <fstream>
#include <sstream>
#include "Array.h"
#include <chrono>
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    NutrientInfo* nutrients = nullptr; 
    int nutrientCount = 0;

  
    ifstream file("Nutrients_Info.csv");
    string line;

 
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

   
    getline(file, line);

    
    while (getline(file, line)) {
        nutrientCount++;
    }

    
    nutrients = new NutrientInfo[nutrientCount];

   
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, line); 

   
    int index = 0;
    while (getline(file, line)) {
        stringstream s(line);
        getline(s, nutrients[index].food, ',');
        getline(s, nutrients[index].measure, ',');
        getline(s, line, ','); nutrients[index].grams = stoi(line);
        getline(s, nutrients[index].calories, ',');
        getline(s, line, ','); nutrients[index].protein = stoi(line);
        getline(s, line, ','); nutrients[index].fat = stoi(line);
        getline(s, line, ','); nutrients[index].satFat = stoi(line);
        getline(s, line, ','); nutrients[index].fiber = stof(line);
        getline(s, line, ','); nutrients[index].carbs = stof(line);
        getline(s, nutrients[index].category);
        index++;
    }

    file.close();

   
    for (int i = 0; i < nutrientCount; ++i) {
        cout << nutrients[i].food << " - " << nutrients[i].grams << " grams" << endl;
    }

  
    delete[] nutrients;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;


    return 0;
}
