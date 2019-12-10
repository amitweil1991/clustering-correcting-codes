//
// Created by amitw on 22/11/2019.
//

#ifndef CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_H
#define CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_H

#include <assert.h>
#include "strand.h"
#include <math.h>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>







/*!
 * function to convert decimal to binary
 * @param n - the decimal number to be converted
 * @param output - an output vector containing the binary representation of the number
 */
void decToBinary(int n, vector<int>& output) {
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        output.push_back(n % 2);
        n = n / 2;
        i++;
    }
    reverse(output.begin(), output.end());
}

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


/*!
 * this function is calculating all the binary numbers that are far from a given number by one bit (in hamming distance)
 * @param num - the given number
 * @param numbers - the output set of all the numbers that are far in one bit.
 */
void distanceByOne(vector<int> num,  set<vector<int>>& numbers){
    for(int i = 0; i < num.size(); i++){
        vector<int> index_j;
        index_j = num;
        if(num[i] == 0){
            index_j[i] = 1;
        }
        else{
            index_j[i] = 0;
        }
        numbers.insert(index_j);
    }
}
/*!
 * this function will helps us calculating S(e,i),  for each number in the given input_number set
 * we're calculating all the binary numbers that are far from him in one bit (hamming distance) and
 * inserting it into the output_numbers set (which eventually will contain all the numbers).
 * @param numbers - the set of the input binary numbers
 * @param output_numbers - the output set containing all the numbers that are far in one bit from a number
 * in the input set.
 */
void distanceByOneFromSet(set<vector<int>>& input_numbers, set<vector<int>>& output_numbers){
    for(auto it = input_numbers.begin(); it != input_numbers.end(); it++){
        distanceByOne(*it, output_numbers);
    }
}


/*!
 * this function is for creating the set : S(e,i) = {Uj | d(hamming, edit) (ind_i, ind_j) <= e}
 * means returning all the data of the strands which their hamming or edit distance between their indexes and the given
 * index is smaller than e
 * @param strands - the strands in the DNA system
 * @param e - the parameter for the distance
 * @param i - a number representing the i'th strand we're checknig by its index.
 * @param distanceMetric- a pointer to a function of distance metric (hamming or edit)
 * @param output_data - the output strands data
 */

void S_e_i(unordered_map<vector<int>, vector<int>>& strands, const int e, const int i, vector<vector<int>>& output_data) {
    vector<int> binary_representation;
    decToBinary(i, binary_representation);
    /// we're going to create a set of all the indexes such that each one of them is diffrent from i in at most e bits,
    /// and its not i.
    int count_till_e = 1;
    set<vector<int>> relevant_indexes;
    set<vector<int>> output_indexes;
    set<vector<int>> union_of_all;
    distanceByOne(binary_representation, relevant_indexes);
    union_of_all = relevant_indexes;
    count_till_e++;
    while(count_till_e <= e){
        distanceByOneFromSet(relevant_indexes, output_indexes);
        relevant_indexes = output_indexes;
        union_of_all.insert(output_indexes.begin(), output_indexes.end());
        count_till_e++;
    }
    vector<int> dec_indexes;
    for(auto it = union_of_all.begin(); it != union_of_all.end(); it++){
        int check = binaryToDec(*it);
        if(check == i) {
            union_of_all.erase(it);
        }
        output_data.push_back(strands.find(*it)->second);

    }
}


//void S_e_i(vector<strand>& strands, const int e, const int i, int (*distanceMetric)(vector<int>, vector<int>),
//           vector<vector<int>>* output_data) {
//    vector<int> strand_i_index = strands[i].getIndex();
//    for(int j = 0; j < strands.size(); j++){
//        if(j == i){
//            continue;
//        }
//        vector<int> strand_j_index = strands[j].getIndex();
//        if(distanceMetric(strand_i_index, strand_j_index) <= e) {
//            vector<int> strand_j_data = strands[j].getData();
//            output_data->push_back(strand_j_data);
//        }
//
//    }
//
//}


int HammingDistance(vector<int> one, vector<int> two){
    int distance = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] != two[i]){
            distance++;
        }
    }
    return distance;

}




/*!
 * the delta1 function from the article, encodes the diffrence between two indexes (i, j) in a distance metric(hamming)
 * by using e * [log(log(M))] (round up) bits, where every log(log(M)) (round up) bits
 * represent a position in the index where the indexes are diffrent
 * @param index_i - the i index
 * @param index_j - the j index
 * @param positions - a vector of the positions, every log(log(M)) (round up) bits represent a position
 * where the two indexes are diffrent, we will save the positions as  bits.
 *
 */
//void delta_1_hamming(vector<int> index_i, vector<int> index_j, vector<int>& positions){
//    vector<int> binary_num;
//    /// if their size is diffrent then hamming distance is not defined.
//    if(index_i.size() != index_j.size()){
//        return;
//    }
//    for(int i = 0; i < index_i.size(); i++){
//        if(index_i[i] != index_j[i]){
//            decToBinary(i, binary_num);
//            positions.insert(positions.end(), binary_num.begin(), binary_num.end());
//            binary_num.clear();
//        }
//    }
//}




/*!
 * the delta1 function from the article, encodes the diffrence between two indexes (i, j)
 * by saving the positions where they are differ.
 * @param index_i - the i index
 * @param index_j - the j index
 * @param positions - a vector of the positions where the two indexes differ.
 *
 */
void delta_1_hamming(vector<int> index_i, vector<int> index_j, vector<int>& positions){
    vector<int> binary_num;
    /// if their size is diffrent then hamming distance is not defined.
    if(index_i.size() != index_j.size()){
        return;
    }
    for(int i = 0; i < index_i.size(); i++){
        if(index_i[i] != index_j[i]){
            positions.push_back(i);
        }
    }
}

/*!
 *  The function ∆2(ui,uj ) encodes the difference betweenthe two data fields ui,uj
     of Hamming distance at most t−1 using (t−1) log(LM) bits which mark
t   he positions where they differ, we will represent the positions as base 10 numbers
 * @param data_u_i - the data of u_i
 * @param data_u_j - the data of u_j
 * @param positions - vector of ints where every number represent a position where the to vectors differ.
 */
void delta_2_hamming(vector<int>& data_u_i, vector<int>& data_u_j, vector<int>& positions){
    delta_1_hamming(data_u_i, data_u_j, positions);
}

/*!
 * this two functions will create all the binary strings of a given length and insert it to the binary_Strings vector
 * @param binary_strings - output vector of vectors, where each element will represent a binary number
 * @param length - the length of the binary strings we want to generate
 *
 */
void CreateAllBinaryStringsAux(vector<vector<int>>& binary_strings, vector<int> current, int length){
    if(current.size() == length){
        binary_strings.push_back(current);
    }
    else{
        current.push_back(0);
        CreateAllBinaryStringsAux(binary_strings, current, length);
        current.pop_back();
        current.push_back(1);
        CreateAllBinaryStringsAux(binary_strings, current, length);
    }
}

void CreateAllBinaryStrings(vector<vector<int>>& binary_strings, int length){
    vector<int> current;
    CreateAllBinaryStringsAux(binary_strings, current, length);

}

/*!
 * this function checks for a given distance metric if a is far from b in more then t (according to the given distance metric)
 * @param a - vector of ints
 * @param b - vector of ints
 * @param t - the given number we want the distance to be greater then
 * @param distanceMetric - the given distance metric we're checking the distance by.
 * @return - true or false according if they holds the constraint.
 */

bool checkConstraint(vector<int> a, vector<int> b, int t, int (*distanceMetric)(vector<int>, vector<int>)){
    if(distanceMetric(a, b) > t){
        return true;
    }
    else return false;
}

/*!
 * the function Wl(S,t) , returns a vector w which satisfies the following condition:
 *  For all v ∈ S, dH(w, v[log(M),l]) > t.
 *  we will find the suitable vector in a brute force manner.
 * @param strands - the strands in the system
 * @param t - the  distance parameter
 * @param w_output - the output vector that satisfies the condition
 */
void W_l_S_t_BruteForce(vector<vector<int>>& strands_data, int t, vector<int>& w_output, int (*distanceMetric)(vector<int>, vector<int>)){
    /// first we create all the binary strings from length t.
    vector<vector<int>> binary_strings;
    CreateAllBinaryStrings(binary_strings, t);
    int flag = 0;
    for(int i = 0; i < binary_strings.size(); i++){
        for(int j = 0; j < strands_data.size(); j++){
            if(!checkConstraint(binary_strings[i], strands_data[j], t,  distanceMetric)){
                flag = 1;
            }
        }
        if(flag == 0){
            w_output = binary_strings[i];
            return;
        }
        else{
            flag = 0;
        }
    }


}







/*!
 * Function for creating B set which is : B = {(i, j) | i < j, dH(indi, indj ) <= 1 ∧ dH(ui,uj ) < t}
 * @param strands - the strands in the system
 * @param t
 * @param distanceMetric - the distance metric we're checking (hamming or edit)
 * @param B - the output set.
 */
void createBset(vector<strand>& strands, int t, int (*distanceMetric)(vector<int>, vector<int>), vector<tuple<int, int>>& B){
    for(int i = 0; i < strands.size(); i++){
        for(int j = i + 1; j < strands.size(); j++){
            vector<int> index_i = strands[i].getIndex();
            vector<int> index_j = strands[j].getIndex();
            vector<int> data_i = strands[i].getData();
            vector<int> data_j = strands[j].getData();
            if(distanceMetric(index_i, index_j) <= 1 && distanceMetric(data_i, data_j) < t){
                tuple<int,int> pair(i,j);
                B.push_back(pair);
            }
        }
    }
}

/*!
 * function for concatentating three vectors and making repl vector as mentioned in the algorithim.
 * @param repl - repl the output vector
 * @param w_l - w_l vector
 * @param delta_1 - delta1 vector
 * @param delta_2 - delta2 vector
 */
void createReplVector(vector<int>& repl, vector<int>& w_l, vector<int>& delta_1, vector<int>& delta_2){
    repl.insert(repl.end(), w_l.begin(), w_l.end());
    repl.insert(repl.end(), delta_1.begin(), delta_1.end());
    repl.insert(repl.end(), delta_2.begin(), delta_2.end());

}



void encoding_algorithm(vector<strand>& strands, int t, int (*distanceMetric)(vector<int>, vector<int>) ){
    /// initilize p
    int p = strands.size() - 1;
    vector<tuple<int,int>>B;
    int index_length = log(strands.size()) + 1;
    /// creating the B set
    createBset(strands, t, distanceMetric, B);
    ///  while B != empty
    while(B.size() > 0) {
        tuple<int, int> current_i_j = B.front();
        int i = get<0>(current_i_j);
        int j = get<1>(current_i_j);
//        vector<int> u_p = strands[p].getData();
        vector<int>::iterator it = strands[p].getData().end();
        /// (up)LM−1 = 1
        *it = 1;
        /// this is for  (up)[0,log(M)] = ind_i
        for (int index = 0; index < index_length; index++) {
            strands[p].getData()[index] = strands[i].getIndex()[index];
        }
        p = i;
        vector<vector<int>> S_e_i_output;
        /// creating the S(1,t) set.
//        S_e_i(strands, 1, i,S_e_i_output);
        vector<int> w_l;
        W_l_S_t_hamming(S_e_i_output, t, w_l);
        /// calculating delta_1 **** in HAMMING *****
        vector<int> delta_1_output;
        delta_1_hamming(strands[i].getIndex(), strands[j].getIndex(), delta_1_output);
        vector<int> delta_2_output;
        delta_2_hamming(strands[i].getData(), strands[j].getData(), delta_2_output);
        vector<int> repl;
        /// concatenating wl, delta1 and delta 2 into repl.
        createReplVector(repl, w_l, delta_1_output, delta_2_output);
        ///  (ui)[log(M),len] = repl
        for (int index = index_length; index < strands[i].getData().size(); i++) {
            strands[i].getData()[index] = repl[index];
        }
        /// updating B such that B = {(i, j) | (i, j) ∈ B ∧ dH(ui,uj) < t}
        for (vector<tuple<int, int>>::iterator it = B.begin(); it != B.end(); it++) {
            int index_i = get<0>(*it);
            int index_j = get<1>(*it);
            if (distanceMetric(strands[index_i].getData(), strands[index_j].getData()) >= t) {
                B.erase(it);
            }
        }
    }
    int index_data_length = strands[0].getData().size() + strands[0].getIndex().size();
    strands[p].getData()[index_data_length - 1] = 0;
    for(int i = 0; i < index_length; i++){
        strands[p].getData()[i] = strands[strands.size() - 1].getIndex()[i];
    }
}






#endif //CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_H



