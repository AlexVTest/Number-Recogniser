//
//  header.h
//  NumRecogniser
//
//  Created by Alex on 7/25/16.
//  Copyright © 2016 Alex. All rights reserved.
//

#ifndef header_h
#define header_h

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

#endif /* header_h */
