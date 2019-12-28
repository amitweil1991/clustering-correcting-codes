#include <iostream>
#include "strand.h"
#include "encoding_algorithim.h"

using namespace std;

/*!
 * testing binaryToDec function
 */

void testBinaryToDec(){
    vector<int> fiftheen;
    fiftheen.resize(4, 1);
    cout << binaryToDec(fiftheen) << endl;
    vector<int> seven;
    seven.resize(4, 1);
    seven.front() = 0;
    cout << binaryToDec(seven) << endl;
}


/*!
 * testing decToBinary function.
 * @return nothing
 */
void testDecToBinary(){
    int four = 4;
    int five = 5;
    int eight = 8;
    int thirty_two = 32;
    vector<int> output_four;
    vector<int> output_five;
    vector<int> output_eight;
    vector<int> output_thirty_two;
    decToBinary(four, output_four);
    decToBinary(five, output_five);
    decToBinary(eight, output_eight);
    decToBinary(thirty_two, output_thirty_two);
    for(auto it = output_four.begin(); it != output_four.end(); it++){
        cout << *it;
    }
    cout << endl;
    for(auto it = output_five.begin(); it != output_five.end(); it++){
        cout << *it;
    }
    cout << endl;
    for(auto it = output_eight.begin(); it != output_eight.end(); it++){
        cout << *it;
    }
    cout << endl;
    for(auto it = output_thirty_two.begin(); it != output_thirty_two.end(); it++){
        cout << *it;
    }
    cout << endl;

}


void testingDeltaOne() {
    int four = 4;
    int five = 5;
    int eight = 8;
    int ten = 10;
    int fiftheen = 15;
    int thirty_two = 32;
    vector<int> output_four;
    vector<int> output_five;
    vector<int> output_eight;
    vector<int> output_ten;
    vector<int> output_fiftheen;
    decToBinary(four, output_four);
    decToBinary(five, output_five);
    decToBinary(eight, output_eight);
    decToBinary(ten, output_ten);
    decToBinary(fiftheen, output_fiftheen);
    vector<int> positions_one;
    vector<int> positions_two;
    vector<int> positions_three;
    delta_1(output_four, output_five, positions_one);
    delta_1(output_eight, output_ten, positions_two);
    delta_1(output_fiftheen, output_eight, positions_three);
    for (auto it = positions_one.begin(); it != positions_one.end(); it++) {
        cout << *it;
    }
    cout << endl;
    for (auto it = positions_two.begin(); it != positions_two.end(); it++) {
        cout << *it;
    }
    cout << endl;
    for (auto it = positions_three.begin(); it != positions_three.end(); it++) {
        cout << *it;
    }
}


void creatingStrands(unordered_map<int, vector<int>>& strands){
    int one = 1;
   int two = 2;
   int three = 3;
   int four = 4;
   int five = 5;
   int six = 6;
   int seven = 7;
   int eight = 8;
//    decToBinary(8, eight);
//    decToBinary(9 , nine);
//    decToBinary(10, ten);
//    decToBinary(11, eleven);
//    decToBinary(12, twelve);
//    decToBinary(13, thirteen);
//    decToBinary(14, fourtheen);
//    decToBinary(15, fiftheen);

    /// data

    int thirty_two = 32;
    int thirty_three = 33;
    int forthy = 40;
    int forthy_one = 41;
//    int forthy_two = 42;
//    int forthy_three = 43;
//    int forthy_four = 44;
//    int forthy_five = 45;

    vector<int> output_thirty_two;
    vector<int> output_thirty_three;
    vector<int> output_fourthy;
    vector<int> output_fourthy_one;
//    vector<int> output_fourthy_two;
//    vector<int> output_fourthy_three;
//    vector<int> output_fourthy_four;
//    vector<int> output_fourthy_five;
    decToBinary(thirty_two, output_thirty_two);
    decToBinary(thirty_three, output_thirty_three);
    decToBinary(forthy, output_fourthy);
    decToBinary(forthy_one, output_fourthy_one);
//    decToBinary(forthy_two, output_fourthy_two);
//    decToBinary(forthy_three, output_fourthy_three);
//    decToBinary(forthy_four, output_fourthy_four);
//    decToBinary(forthy_five, output_fourthy_five);

    /// inserting strands;
    strands[one] = output_thirty_two;
    strands[two] = output_thirty_three;
    strands[three] = output_fourthy;
    strands[four] = output_fourthy_one;
//    strands[twelve] = output_fourthy_two;
//    strands[thirteen] = output_fourthy_three;
//    strands[fourtheen] = output_fourthy_four;
//    strands[fiftheen] = output_fourthy_five;
//    strands.insert(eight, output_thirty_two);
//    strands.insert(nine , output_thirty_three);
//    strands.insert(ten, output_fourthy);
//    strands.insert(eleven,output_fourthy_one);
//    strands.insert(twelve , output_fourthy_two);
//    strands.insert(thirteen , output_fourthy_three);
//    strands.insert(fourtheen , output_fourthy_four);
//    strands.insert(fiftheen , output_fourthy_five);



}



void testS_e_i() {
    unordered_map<int, vector<int>> strands;
    vector<vector<int>> output;
    vector<int> output2;
    creatingStrands(strands);
    S_e_i(strands, 2, 8, output);
    for (auto it = output2.begin(); it != output2.end(); it++) {
        cout << *it << endl;

    }

}


void testW_l_S_t_BruteForce(){
    unordered_map<int, vector<int>> strands;
    creatingStrands(strands);
    vector<vector<int>> strands_data;
    vector<int> output;
    for(auto it = strands.begin(); it != strands.end(); it++){
        strands_data.push_back(it->second);
    }
    W_l_S_t_BruteForce(strands_data, 4, output, HammingDistance);
    cout << "the output of W_l_S_t is " << endl;
    for(auto i: output){
        cout << i;

    }
    cout << endl;

}


void testW_l_S_t_NoBruteForce(){
    unordered_map<int, vector<int>> strands;
    creatingStrands(strands);
    vector<vector<int>> strands_data;
    vector<int> output;
    for(auto it = strands.begin(); it != strands.end(); it++){
        strands_data.push_back(it->second);
    }
    W_l_S_t_NoBruteForce(strands_data, 2, output, HammingDistance);
    cout << "the output of W_l_S_t is " << endl;
    for(auto i: output){
        cout << i;

    }
    cout << endl;

}

void testDistanceByOne(){
    set<vector<int>> indexes;
    vector<int> binary_representation;
    decToBinary(8, binary_representation);
    distanceByOne(binary_representation, indexes);
    for (auto it = indexes.begin(); it != indexes.end(); it++) {
        for (int j = 0; j < it->size(); j++) {
            cout << it->operator[](j);
        }
        cout << endl;
    }
}


void printStrandsIndexAndData(unordered_map<int, vector<int>> & strands){
    for(auto it = strands.begin(); it != strands.end(); it++){
        vector<int> index;
        decToBinary(it->first, index);
        for(int i = 0; i < index.size(); i++){
            cout << index[i];
        }
        cout << " , ";
        for(int i = 0; i < it->second.size(); i++){
            cout << it->second[i];
        }
        cout << endl;
    }
}


void testCreateBSet(){
    unordered_map<int, vector<int>> strands;
    creatingStrands(strands);
    vector<tuple<int,int>> B_set;
    unordered_map<int, encoded_strand> encoded_strands;
    printStrandsIndexAndData(strands);
    createBset(strands, 3, 2, HammingDistance, B_set, encoded_strands);
    for(int i = 0; i < B_set.size(); i++){
        cout << "(" << get<0>(B_set[i]) << " , " << get<1>(B_set[i]) << ")" << endl;
    }
    cout << "encoded_strands:" << endl;
    for(int i = 0; i < encoded_strands.size(); i++){
        cout << encoded_strands.find(i)->second.getIfNotEncoded() << endl;
    }

}

void printBset(vector<tuple<int,int>>& B_set){
    for(int i = 0; i < B_set.size(); i++){
        cout << "(" << get<0>(B_set[i]) << " , " << get<1>(B_set[i]) << ")" << endl;
    }
}

void testUpdateBSet(){
    unordered_map<int, vector<int>> strands;
    creatingStrands(strands);
    vector<tuple<int,int>> B_set;
    unordered_map<int, encoded_strand> encoded_strands;
    printStrandsIndexAndData(strands);
    createBset(strands, 3, 2, HammingDistance, B_set, encoded_strands);
    printBset(B_set);
    cout << "encoded_strands:" << endl;
    for(int i = 0; i < encoded_strands.size(); i++){
        cout << encoded_strands.find(i)->second.getIfNotEncoded() << endl;
    }
    vector<int>w_l(2);
    w_l[0] = 1;
    w_l[1] = 1;
    vector<int> delta_one(2);
    delta_one[0] = 0;
    delta_one[1] = 0;
    vector<int> delta_two(2);
    delta_two[0] = 0;
    delta_two[1] = 0;
    encoded_strand new_strand(delta_one, delta_two, w_l, 9);
    updateBSet(strands, B_set, 9, new_strand, HammingDistance, 2);
    printBset(B_set);


}

void testEncodingAlgorithim(){
    unordered_map<int, vector<int>> strands;
    creatingStrands(strands);
    unordered_map<int, encoded_strand> encoded_strands;
        encoding_algorithm(strands, 2, 2, HammingDistance, encoded_strands, true);
    return;
}



int main(){
  //  testDecToBinary();
  //  testingDeltaOne();
//  testS_e_i();
//    testW_l_S_t();
//    testCreateBSet();
  //  testCreateReplVector();
//    testBinaryToDec();
//    vector<string> DP[K][K];
//    findBitCombinations(4,DP,2);
   // testDistanceByOne();
  //  testS_e_i();
 // testW_l_S_t_BruteForce();
// testW_l_S_t_NoBruteForce();
testEncodingAlgorithim();


}


















