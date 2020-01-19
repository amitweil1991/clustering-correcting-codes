//
// Created by amitw on 18/01/2020.
//

#ifndef CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_BINARY_H
#define CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_BINARY_H
#include "strand.h"
class encoded_strand_binary {
    vector<int> encoded_data;
    bool brute_force;
public:
    encoded_strand_binary(vector<int> data, bool brute): encoded_data(data), brute_force(brute){};

    vector<int> get_encoded_data(){
        return encoded_data;
    }

    /// sets the last bit of the encoded data to 1.
    void setLastBit(int val){
        encoded_data.back() = val;
    }

    /// assign the first LogM bits of the encoded data to be the next node in the list of encoding.
    void setNextNodeInList(vector<int> index_in_binary){
        for(int i = 0; i < index_in_binary.size(); i++){
            encoded_data[i] = index_in_binary[i];
        }
    }

    /// gets last bit of the encoded data
    int getLastBit(){
        return encoded_data.back();
    }

    /*!
     * get the first logM bits of the data
     * @param first_LogM_bits - output
     * @param index_length - length of the index in binary (ceil(LogM))
     */
    void getFirstLogMBits(
            vector<int>& first_LogM_bits,
            int index_length){

            first_LogM_bits.insert(first_LogM_bits.begin(), encoded_data.begin(), encoded_data.begin() + index_length);
    }
    /*!
     * sets the given vector as the first logM bits of the encoded data
     * @param first_logM_bits - the vector we set as the first logM bits
     */
    void setfirstLogMBits(vector<int>& first_logM_bits){
        for(int i = 0; i < first_logM_bits.size(); i++){
            encoded_data[i] = first_logM_bits[i];
        }
    }

    /*!
     * takes the first logM bits, convert it to int and returns it.
     * @param index_length - length of the index in binary (ceil(LogM))
     * @return - the index of the next strand in the encoding list.
     */
    int getNextNodeIndex(int index_length){
        vector<int> first_LogM_bits;
        getFirstLogMBits(first_LogM_bits, index_length);
        return binaryToDec(first_LogM_bits);
    }
    /*!
     * function get extract the delta1 part out of the encoded data, its position depends
     * wether we encoded w_l with brute force or not.
     * @param delta_1_from_encoded_data - the output delta1 in binary.
     */
    void getDelta1FromEncodedData(vector<int>& delta_1_from_encoded_data){
        /// in case brute force == true, w_l = 3t + 2*logN
        if(brute_force){

        }
    }
    /*!
     * function that recives delta 1 in binary representation, and convert it to a vector of positions as ints
     * @param positions_as_ints - the output set, each element represent a position encoded in delta1,
     * i made it a set because of the padding, i dont want the same position repeat in the output.
     * @param delta1 - the given delta 1 binary vector
     * @param position_length - length of one position's binary representation.
     */
    void convertDelta1ToInt(
            set<int>& positions_as_ints,
            vector<int>& delta1,
            int position_length){

        for(int i = 0; i < delta1.size(); i += position_length){
            vector<int> curr_binary_position{delta1.begin() + i, delta1.begin() + i + position_length};
            int curr_position = binaryToDec(curr_binary_position);
            positions_as_ints.insert(curr_position);
        }
    }

    /*!
 * function get extract the delta2 part out of the encoded data, its position depends
 * wether we encoded w_l with brute force or not.
 * @param delta_1_from_encoded_data - the output delta1 in binary.
 */
    void getDelta2FromEncodedData(vector<int>& delta_2_from_encoded_data){
        /// in case brute force == true, w_l = 3t + 2*logN
        if(brute_force){

        }
    }

    /*!
  * function that recives delta 2 in binary representation, and convert it to a vector of positions as ints
    in case delta2 holds position in unordered way, means the data of the instance strand is identical to the data
     of the strand the intstance strand was encoded by, therefore positions_as_ints will be empty to denote that.
  * @param positions_as_ints - the output set, each element represent a position encoded in delta1,
  * i made it a set because of the padding, i dont want the same position repeat in the output.
  * @param delta1 - the given delta 1 binary vector
  * @param position_length - length of one position's binary representation.
  */
    void convertDelta2ToInt(
            set<int>& positions_as_ints,
            vector<int>& delta2,
            int position_length){

        int last_position = -1; // helper val to detect padding
        for(int i = 0; i < delta2.size(); i += position_length){
            vector<int> curr_binary_position{delta2.begin() + i, delta2.begin() + i + position_length};
            int curr_position = binaryToDec(curr_binary_position);
            /// unordered delta2 = padding
            if(curr_position < last_position){
                positions_as_ints.clear();
                return;
            }
            positions_as_ints.insert(curr_position);
            last_position = curr_position;
        }
    }

};


#endif //CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_BINARY_H
