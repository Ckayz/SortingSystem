#include <iostream>
#include <fstream>
#include <sstream>
#include "LL.h"
#include <chrono>

using namespace std::chrono;


int main() {
    auto start = high_resolution_clock::now();
    NutrientInfo* head = nullptr;
    int count = 0;
    ifstream file("Nutrients_Info.csv");
    string line, word;
    getline(file, line);
    while (getline(file, line)) {
        stringstream s(line);
        NutrientInfo* newNode = new NutrientInfo;
        newNode->next = nullptr;

        try {
            getline(s, newNode->food, ',');
            getline(s, newNode->measure, ',');
            getline(s, word, ','); newNode->grams = stoi(word);
            getline(s, newNode->calories, ',');
            getline(s, word, ','); newNode->protein = stoi(word);
            getline(s, word, ','); newNode->fat = stoi(word);
            getline(s, word, ','); newNode->satFat = stoi(word);
            getline(s, word, ','); newNode->fiber = stof(word);
            getline(s, word, ','); newNode->carbs = stof(word);
            getline(s, newNode->category, ',');

            addNode(head, newNode);
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
            delete newNode; 
            continue; 
        }
        catch (const out_of_range& e) {
            cerr << "Out of range: -----------------------------------------" << e.what() << endl;
            delete newNode; 
            continue; 
        }
    }

    file.close();

    NutrientInfo* temp = head;
    while (temp != nullptr) {
        cout << temp->food << " - " << temp->fat << " fat" << endl;
        temp = temp->next;
        count++;
    }
    cout << count << endl;


    while (head != nullptr) {
        NutrientInfo* temp = head;
        head = head->next;
        delete temp;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
