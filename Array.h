#ifndef NUTRIENTINFO_H
#define NUTRIENTINFO_H

#include <string>
using namespace std;

struct NutrientInfo {
    string food;
    string measure;
    int grams;
    string calories;
    int protein;
    int fat;
    int satFat;
    float fiber;
    float carbs;
    string category;
};

#endif 
