//
//  main.cpp
//  NumRecogniser
//
//  Created by Alex on 7/24/16.
//  Copyright © 2016 Alex. All rights reserved.
//

#include "header.h"                                                             // Importing all libraries in header

int data_In[30][30];                                                            // Input data array
int DB[10][30][30];                                                             // Data from DB
int sameless_arr[10];                                                           // Arr of sameless values
int true_Number;                                                                // True num

void load_Data_In();                                                            // To load input data
void load_DB(int number);                                                       // To load DB
void check_Mono_Array(int arr[10]);                                             //   Functions
void check_Dual_Array(int arr[30][30]);                                         //   for printing
void check_Triple_Array(int arr[10][30][30], int elem);                         //   arrays to the terminal
void check_Sameless(int number);                                                // To check sameless
int detect_number();                                                            // To detect true number
void save_Changes_To_DB(int number);                                            // To save learning process


int main() {
    
    load_Data_In();                                                             // Load input data
    //check_Dual_Array(data_In);
    
    for (int number = 0; number < 10; number++) {                               // Load DB data
        load_DB(number);
        //check_Triple_Array(DB, number);
        cout << endl;
    }
    
    for (int number = 0; number < 10; number++) {                               // run check function in the loop
        check_Sameless(number);
    }
    
    check_Mono_Array(sameless_arr);
    true_Number = detect_number();
    cout << "Looks like it is number: " << true_Number << endl;
    
    cout << "Is it true? [Yes/Something else]" << endl;
    string reply;
    cin >> reply;
    if (reply == "Yes") {
        save_Changes_To_DB(true_Number);
    } else {
        cout << "What number is it?" << endl;
        cin >> true_Number;
        save_Changes_To_DB(true_Number);
    }
    
    cout << "Learning finished! Changes saved to database!" << endl;
    
    return 0;
}



// --------------- Changes Saving Functions ---------------

void save_Changes_To_DB(int number) {                                           // Save all changes to the DB bitmap
    
    ofstream SaveData;
    SaveData.open("DATA/" + to_string(number) + ".txt");
    
    for (int m = 0; m < 30; m++) {
        for (int n = 0; n < 30; n++) {
            if (data_In[m][n] != 0 ) {
                SaveData << DB[number][m][n]+1 << " ";
            } else {
                SaveData << DB[number][m][n] << " ";
            }
        }
        SaveData << endl;
    }
    
    SaveData.close();
    
}



// --------------- Checking Sameless Functions ---------------

void check_Sameless(int number) {                                               // Check the sameless
    for (int m = 0; m < 30; m++) {
        for (int n = 0; n < 30; n++) {
            sameless_arr[number] += data_In[m][n]*DB[number][m][n];
        }
    }
}

int detect_number() {                                                           // Check what number looks like the same
    int maxEl = sameless_arr[0];
    int maxI = 0;
    for (int i = 0; i < 10; i++) {
        if (sameless_arr[i] > maxEl) {
            maxI = i;
        }
    }
    return maxI;
}



// --------------- Data Loading Functions ---------------

void load_DB(int number) {                                                      // Load all database into the array
    ifstream LoadDB;
    LoadDB.open("DATA/" + to_string(number) + ".txt");
    string num;
    int i = 0;
    int j = 0;
    while (LoadDB >> num) {
        DB[number][j][i] = atoi(num.c_str());
        i++;
        if (i == 30) {
            i = 0;
            j++;
        }
    }
    LoadDB.close();
}

void load_Data_In() {                                                           // Load image data into the array
    ifstream LoadImage;
    LoadImage.open("in.txt");
    string num;
    int i = 0;
    int j = 0;
    while (LoadImage >> num) {
        data_In[j][i] = atoi(num.c_str());
        i++;
        if (i == 30) {
            i = 0;
            j++;
        }
    }
    LoadImage.close();
}



// --------------- Debug Functions ---------------

void check_Mono_Array(int arr[10]) {                                            // print 1-dimm array
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
}

void check_Dual_Array(int arr[30][30]) {                                        // print 2-dimm array
    for (int m = 0; m < 30; m++) {
        for (int n = 0; n < 30; n++) {
            cout << arr[m][n];
        }
        cout << endl;
    }
}

void check_Triple_Array(int arr[10][30][30], int elem) {                        // print 3-dimm array
    for (int m = 0; m < 30; m++) {
        for (int n = 0; n < 30; n++) {
            cout << arr[elem][m][n];
        }
        cout << endl;
    }
}


