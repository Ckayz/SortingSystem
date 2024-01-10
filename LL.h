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
    NutrientInfo* next;
};


void addNode(NutrientInfo*& head, NutrientInfo* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NutrientInfo* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

#endif 