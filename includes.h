//
// Created by amitw on 18/01/2020.
//

#ifndef CLUSTERING_CORRECTING_CODES_PROJECT_INCLUDES_H
#define CLUSTERING_CORRECTING_CODES_PROJECT_INCLUDES_H
#include <math.h>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#endif //CLUSTERING_CORRECTING_CODES_PROJECT_INCLUDES_H

using namespace std;

/*!
 * function that convert binary number represented as a vector to its decimal representation
 * @param input - the binary number as a vector
 * @param
 * @return output - the output decimal number as an int.
 */
int binaryToDec(vector<int> input){
    int decimal = 0;
    int length = input.size();
    for(int i = 0; i < input.size(); i++){
        if(input[i] == 1){
            decimal += pow(2, length - 1 - i);
        }
    }
    return decimal;
}


int HammingDistance(
        vector<int> one,
        vector<int> two){

    if(one.size() != two.size()){
        cout << "Hamming distance is defined only for vectors from the same size" << endl;
        return -1;
    }
    int distance = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] != two[i]){
            distance++;
        }
    }
    return distance;

}



/*!
 * function to convert decimal to binary
 * @param n - the decimal number to be converted
 * @param output - an output vector containing the binary representation of the number
 */
void decToBinary(int n, vector<int>& output) {
    int i = 0;
    if(n == 0){
        output.push_back(0);
        return;
    }
    while (n > 0) {

        // storing remainder in binary array
        output.push_back(n % 2);
        n = n / 2;
        i++;
    }
    reverse(output.begin(), output.end());
}

/*!
 * function to convert decimal to binary
 * @param n - the decimal number to be converted
 * @param output - an output vector containing the binary representation of the number
 */
void decToBinaryWithSize(int n, vector<int>& output, int size) {
    int i = 0;
    if(n == 0){
        output.push_back(0);
        size--;
    }
    while (n > 0) {
        size--;
        // storing remainder in binary array
        output.push_back(n % 2);
        n = n / 2;
        i++;
    }
    //
    while(size > 0){
        output.push_back(0);
        size--;
    }
    reverse(output.begin(), output.end());
}

/*!
 * function for converting a char vec into int vec so '1001' will become 1001.
 * @param char_vec - char vec
 * @param int_vec - output int vec.
 */
void convertCharVecToIntVec(
        vector<char>& char_vec,
        vector<int>& int_vec){

        for(int i = 0; i < char_vec.size(); i++){
            int_vec.push_back(char_vec[i] - '0');
        }
}

/*!
 * function for converting a int vec into char vec so 1001 will become '1001'.
 * @param char_vec - char vec
 * @param int_vec - output int vec.
 */
void convertIntVecToCharVec(
        vector<char>& char_vec,
        vector<int>& int_vec){

    for(int i = 0; i < int_vec.size(); i++){
        char_vec.push_back(int_vec[i] + '0');
    }
}