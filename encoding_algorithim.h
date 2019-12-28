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
#include "encoded_strand.h"






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
void delta_1(vector<int> index_i, vector<int> index_j, vector<int>& positions){
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
void delta_2(vector<int>& data_u_i, vector<int>& data_u_j, vector<int>& positions){
    delta_1(data_u_i, data_u_j, positions);
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

void S_e_i(unordered_map<int, vector<int>>& strands, const int e, const int i, vector<vector<int>>& output_data) {
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
    /// inserting the data of the relevant indexes.
    for(auto it = union_of_all.begin(); it != union_of_all.end(); it++){
        int check = binaryToDec(*it);
        if(check == i) {
            continue;
        }
        auto iterator = strands.find(check);
        if(iterator != strands.end()) {
            output_data.push_back(strands.find(check)->second);
        }

    }
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
    if(distanceMetric(a, b) >= t){
        return true;
    }
    else return false;
}

/*!
 * the function Wl(S,t) , returns a vector w which satisfies the following condition:
 *  For all v ∈ S, d(w, v[log(M),l]) > t. (the distance in the data part is at least t)
 *  we will find the suitable vector in a brute force manner.
 * @param strands - the strands in the system
 * @param t - the  distance parameter
 * @param w_output - the output vector that satisfies the condition
 */
void W_l_S_t_BruteForce(vector<vector<int>>& strands_data, int t, vector<int>& w_output, int (*distanceMetric)(vector<int>, vector<int>)){
    /// first we create all the binary strings from length t.
    vector<vector<int>> binary_strings;
    CreateAllBinaryStrings(binary_strings, 3 * t +  2 * log2(strands_data.size()));
    int constraint_approved_fo_all = 1;
    for(int i = 0; i < binary_strings.size(); i++){
        for(int j = 0; j < strands_data.size(); j++){
            if(!checkConstraint(binary_strings[i], strands_data[j], t,  distanceMetric)){
                constraint_approved_fo_all = 0;
            }
        }
        if(constraint_approved_fo_all == 1){
            w_output = binary_strings[i];
            return;
        }
        else{
            constraint_approved_fo_all = 1;
        }
    }


}
/*!
 * this function is a helper function, it gets two vectors and it checks if the binary string distance is at least one
 * from the strand data vector[start_index - start_index + Log(N+1)], it helps us in w_l_s_T function (the one without the brute force)
 * @param binary_string - the binary string we check if the constraint applies.
 * @param strand_data - the strand's data, as a vector
 * @param start_index - the starting index we're checking from
 * @param N - number of strands in the system (this is for Log(N+1)
 * @param distanceMetric - the distance metric we're checking by.
 * @return - true - the constraint applies, otherwise false.
 */
bool checkConstraintFromStrtTillLogN(vector<int>& binary_string, vector<int>& strand_data, int start_index, int N, int (*distanceMetric)(vector<int>, vector<int>)){
        vector<int> relevant_part_of_data(strand_data.begin() + start_index, strand_data.begin() + start_index + log2(N + 1) - 1);
        return checkConstraint(binary_string, relevant_part_of_data, 1, distanceMetric);
}

/*!
 * the second function for finding Wl(S,t) , returns a vector w which satisfies the following condition:
 *  For all v ∈ S, d(w, v[log(M),l]) > t. (the distance in the data part is at least t)
 *  this time we look every time on a Log(N+1) size window, finding a binary string that are diffrent from all the strand's data
 *  in this window by at least one bit (we check that in a brture force manner, for each window), then we do it t times
 *  and at the end we combine the t binary strings and that will be our output vector.
 * @param strands_data - the strand's data
 * @param t - the number of bits we want our vector to be diffrent at.
 * @param w_output - the output vector
 * @param distanceMetric - the distance metric we're checking with.
 */
void W_l_S_t_NoBruteForce(vector<vector<int>>& strands_data, int t, vector<int>& w_output, int (*distanceMetric)(vector<int>, vector<int>)) {
    vector<vector<int>> binary_strings;

    CreateAllBinaryStrings(binary_strings, log2(strands_data.size() + 1));
    int constraint_approved_fo_all = 1;
    for (int i = 0, j = 0; i < t && j < strands_data[0].size(); i++, j += log2(strands_data.size() + 1)) {
        for (int index = 0; index < binary_strings.size(); index++) {
            for (int data_index = 0; data_index < strands_data.size(); data_index++) {
                if (!checkConstraintFromStrtTillLogN(binary_strings[i], strands_data[data_index], j, strands_data.size(), distanceMetric)) {
                    constraint_approved_fo_all = 0;
                    break;
                }

            }
            /// if the constraint is approved we concatenate the vectors.
            if (constraint_approved_fo_all == 1) {
                w_output.insert(w_output.end(), binary_strings[i].begin(), binary_strings[i].end());
                break;
            }
            constraint_approved_fo_all = 1;
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
void createBset(unordered_map<int, vector<int>>& strands, int t, int e, int (*distanceMetric)(vector<int>, vector<int>), vector<tuple<int, int>>& B,
                vector<encoded_strand>& encoded_strands) {
    /// this is a flag helping us to determine if the curretn strand need to be encoded or not,
    /// if he holds the constraint for all the other strands in the system it dosent need to be encoded
    /// and then we should add it to the encoded_strand vector with a pointer to himself and not encoded version.

    bool needed_to_be_encoded = false;
    for (auto iterator = strands.begin(); iterator != strands.end(); iterator++) {
        for (auto iterator_two = strands.begin(); iterator_two != strands.end(); iterator_two++) {
            if (iterator_two->first <= iterator->first) {
                continue;
            }
            vector<int> index_i;
            decToBinary(iterator->first, index_i);
            vector<int> index_j;
            decToBinary(iterator_two->first, index_j);
            if (distanceMetric(index_i, index_j) <= e && distanceMetric(iterator->second, iterator_two->second) < t) {
                tuple<int, int> pair(iterator->first, iterator_two->first);
                B.push_back(pair);
                needed_to_be_encoded = true;
            }

        }
        /// in case the strand dosent need to be encoded, we add encoded strand with the index of the strand
        /// in the strand data structure, so we could find it later in the decode part.
        if(needed_to_be_encoded == false){
            encoded_strand current(iterator->first);
            encoded_strands.insert(encoded_strands.begin(), current);

        }
    }
}


/*!
 * function for creating new encoded strand and pushing it into the encoded strand vector
 * @param index_of_encoded_by - the index of the strand that we're encoding the current strand by.
 * @param w_l - w_l vector
 * @param delta_1 - delta1 vector
 * @param delta_2 - delta2 vector
 */
void createReplVector(vector<int>& w_l, vector<int>& delta_1, vector<int>& delta_2, vector<encoded_strand>& encoded_strands){
    encoded_strand new_encoded_strand( delta_1, delta_2, w_l);
    encoded_strands.push_back(new_encoded_strand);

}

/*!
 * function for creating one vector from the encoded strand class:
 * encoded vector =  = (w`(S(e, i), t), ∆1(indi, indj ), ∆2(ui,uj )
 * @param encoded_vector - the vector we create
 * @param strand - the encoded strand we're concatinating its fields
 */
void CreateOneVectorFromEncodedStrand(vector<int>& encoded_vector, encoded_strand& strand){
    encoded_vector.insert(encoded_vector.end(), strand.getWL().begin(), strand.getWL().end());
    encoded_vector.insert(encoded_vector.end(), strand.getDelta1().begin(), strand.getDelta1().end());
    encoded_vector.insert(encoded_vector.end(), strand.getDelta2().begin(), strand.getDelta2().end());


}
/*!
 * helper function of updating B set everytime we encoding a strand we need to remove all the (i,j) that are now
 * holds the constraint, therefore they should be removed from the B set
 *  B = {(i, j) | (i, j) ∈ B ∧ dH(ui ,uj ) < t}
 * @param strands - the strands in the system
 * @param B - the B set
 * @param i - the index of the strand that was encoded
 * @param strand - the encoded strand
 * @param distanceMetric  the distance metric we're checking by
 * @param t - the distance of the strand's data, the t in the condition.
 */
void updateBSet(unordered_map<int, vector<int>>& strands, vector<tuple<int,int>>& B, int i, encoded_strand& strand, int (*distanceMetric)(vector<int>, vector<int>),
        int t){
    vector<int> i_encoded_data;
    CreateOneVectorFromEncodedStrand(i_encoded_data, strand);
    for(auto j = 0; j < B.size(); j++){
       if(get<0>(B[j]) == i){
           if(distanceMetric(strands.find(get<1>(B[j]))->second, i_encoded_data) >= t){
               B.erase(B.begin() + j);
           }
       }
    }
}

/*!
 * the encoding algorithim as it was described in psuedo code in the papaer.
 * @param strands - the strands inthe system
 * @param e - the distance constraint of the indexes
 * @param t - the distance constraint of the data of the strands
 * @param distanceMetric - the distance metric we're using (hamming \ edit)
 * @param encoded_strands - data structure that will hold all of the encoded strands.
 * @param BruteForceOrNot - a flag that tells us if we should find w_l in brute force manner or not
 * @param index_of_last_strand - the index of the last strand in the system
 */
void encoding_algorithm(unordered_map<int, vector<int>>& strands, int e,  int t, int (*distanceMetric)(vector<int>, vector<int>), vector<encoded_strand >& encoded_strands,
                        bool BruteForceOrNot, int index_of_last_strand) {
    /// initilize p
    int p = strands.size() - 1;
    vector<tuple<int, int>> B;
    int index_length = log2(strands.size()) + 1;
    /// creating the B set
    createBset(strands, t, e,  distanceMetric, B, encoded_strands);
    ///  while B != empty
    while (!B.empty()) {
        tuple<int, int> current_i_j = B.front();
        int i = get<0>(current_i_j);
        int j = get<1>(current_i_j);
        vector<vector<int>> data_of_potential_strands;
        vector<int> w_l;
        vector<int> delta_1_positions;
        vector<int> delta_2_positions;
        vector<int> index_i_in_binary;
        vector<int> index_j_in_binary;
        S_e_i(strands, e, i, data_of_potential_strands);
        if (BruteForceOrNot) {
            W_l_S_t_BruteForce(data_of_potential_strands, t, w_l, distanceMetric);
        } else {
            W_l_S_t_NoBruteForce(data_of_potential_strands, t, w_l, distanceMetric);
        }
        decToBinary(i, index_i_in_binary);
        decToBinary(j, index_j_in_binary);
        /// creating delta1
        delta_1(index_i_in_binary, index_j_in_binary, delta_1_positions);
        /// creating delta2
        delta_2(strands.find(i)->second, strands.find(j)->second, delta_2_positions);
        /// creating the encoded strand a.k.a repl vector and adding it to the vector of encoded strands.
        createReplVector(w_l, delta_1_positions, delta_2_positions, encoded_strands);
        /// (up)LM−1 = 1
        encoded_strands.back().setLastBit(1);
        /// this is for  (up)[0,log(M)] = ind_i
        encoded_strands.back().setEncodedRelatedToIndex(index_i_in_binary);
        updateBSet(strands, B, i, encoded_strands.back(), distanceMetric, t);
    }
    encoded_strands.back().setLastBit(0);
    vector<int> index_of_last_strand_binary;
    decToBinary(index_of_last_strand, index_of_last_strand_binary);
    encoded_strands.back().setEncodedRelatedToIndex(index_of_last_strand_binary);
}








#endif //CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_H



