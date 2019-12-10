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
    delta_1_hamming(output_four, output_five, positions_one);
    delta_1_hamming(output_eight, output_ten, positions_two);
    delta_1_hamming(output_fiftheen, output_eight, positions_three);
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






    /// indexes
    int eight = 8;
    int nine = 9;
    int ten = 10;
    int eleven = 11;
    int twelve = 12;
    int thirteen = 13;
    int fourtheen = 14;
    int fiftheen = 15;

    /// data

    int thirty_two = 32;
    int thirty_three = 33;
    int forthy = 40;
    int forthy_one = 41;
    int forthy_two = 42;
    int forthy_three = 43;
    int forthy_four = 44;
    int forthy_five = 45;

    vector<int> output_thirty_two;
    vector<int> output_thirty_three;
    vector<int> output_fourthy;
    vector<int> output_fourthy_one;
    vector<int> output_fourthy_two;
    vector<int> output_fourthy_three;
    vector<int> output_fourthy_four;
    vector<int> output_fourthy_five;
    decToBinary(thirty_two, output_thirty_two);
    decToBinary(thirty_three, output_thirty_three);
    decToBinary(forthy, output_fourthy);
    decToBinary(forthy_one, output_fourthy_one);
    decToBinary(forthy_two, output_fourthy_two);
    decToBinary(forthy_three, output_fourthy_three);
    decToBinary(forthy_four, output_fourthy_four);
    decToBinary(forthy_five, output_fourthy_five);

    /// inserting strands;

    strands[eight] = output_thirty_two;
    strands[nine] = output_thirty_three;
    strands[ten] = output_fourthy;
    strands[eleven] = output_fourthy_one;
    strands[twelve] = output_fourthy_two;
    strands[thirteen] = output_fourthy_three;
    strands[fourtheen] = output_fourthy_four;
    strands[fiftheen] = output_fourthy_five;



}



void testS_e_i() {
    unordered_map<vector<int>,vector<int>> strands;
    vector<vector<int>> output;
    vector<int> output2;
    creatingStrands(strands);
    S_e_i(strands, 2, 8, output);
    for (auto it = output2.begin(); it != output2.end(); it++) {
        cout << *it << endl;

    }
}



void testW_l_S_t(){
    unordered_map<int, vector<int>> strands;
    vector<vector<int>> output;
    creatingStrands(strands);
    for(int i = 0; i < strands.size(); i++){
        output.push_back(strands[i].getData());
    }
    vector<int> w_output;
    W_l_S_t_hamming(output, 2,w_output);
    for(int i = 0; i < w_output.size(); i++){
        cout << w_output[i];
    }

}

void testCreateBSet(){
    vector<strand> strands;
    vector<tuple<int, int>> output;
    creatingStrands(strands);
    createBset(strands, 2, HammingDistance, output);
    for(int i = 0; i < output.size(); i++){
        cout << "(" << get<0>(output[i]) << ", " << get<1>(output[i]) << ")" << endl;
    }
}

void testCreateReplVector(){
    vector<strand> strands;
    creatingStrands(strands);
    vector<int> repl;
    createReplVector(repl, strands[0].getIndex(), strands[0].getData(), strands[1].getIndex());
    for(int i = 0; i < repl.size(); i ++){
        cout << repl[i];
    }

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
    testS_e_i();

}


















