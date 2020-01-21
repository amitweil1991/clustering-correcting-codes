#include <iostream>
#include "strand.h"
#include "encoding_algorithim.h"
#include "files.h"
#include "decoding_algorithim_tests.h"
#include "encoding_algorithim_tests.h"

using namespace std;

/*!
 * testing binaryToDec function
 */
//
//void testBinaryToDec(){
//    vector<int> fiftheen;
//    fiftheen.resize(4, 1);
//    cout << binaryToDec(fiftheen) << endl;
//    vector<int> seven;
//    seven.resize(4, 1);
//    seven.front() = 0;
//    cout << binaryToDec(seven) << endl;
//}
//
//
///*!
// * testing decToBinary function.
// * @return nothing
// */
//void testDecToBinary(){
//    int four = 4;
//    int five = 5;
//    int eight = 8;
//    int thirty_two = 32;
//    vector<int> output_four;
//    vector<int> output_five;
//    vector<int> output_eight;
//    vector<int> output_thirty_two;
//    decToBinary(four, output_four);
//    decToBinary(five, output_five);
//    decToBinary(eight, output_eight);
//    decToBinary(thirty_two, output_thirty_two);
//    for(auto it = output_four.begin(); it != output_four.end(); it++){
//        cout << *it;
//    }
//    cout << endl;
//    for(auto it = output_five.begin(); it != output_five.end(); it++){
//        cout << *it;
//    }
//    cout << endl;
//    for(auto it = output_eight.begin(); it != output_eight.end(); it++){
//        cout << *it;
//    }
//    cout << endl;
//    for(auto it = output_thirty_two.begin(); it != output_thirty_two.end(); it++){
//        cout << *it;
//    }
//    cout << endl;
//
//}
//
//
//void testingDeltaOne() {
//    int four = 4;
//    int five = 5;
//    int eight = 8;
//    int ten = 10;
//    int fiftheen = 15;
//    int thirty_two = 32;
//    vector<int> output_four;
//    vector<int> output_five;
//    vector<int> output_eight;
//    vector<int> output_ten;
//    vector<int> output_fiftheen;
//    decToBinary(four, output_four);
//    decToBinary(five, output_five);
//    decToBinary(eight, output_eight);
//    decToBinary(ten, output_ten);
//    decToBinary(fiftheen, output_fiftheen);
//    vector<int> positions_one;
//    vector<int> positions_two;
//    vector<int> positions_three;
//    delta_1(output_four, output_five, positions_one);
//    delta_1(output_eight, output_ten, positions_two);
//    delta_1(output_fiftheen, output_eight, positions_three);
//    for (auto it = positions_one.begin(); it != positions_one.end(); it++) {
//        cout << *it;
//    }
//    cout << endl;
//    for (auto it = positions_two.begin(); it != positions_two.end(); it++) {
//        cout << *it;
//    }
//    cout << endl;
//    for (auto it = positions_three.begin(); it != positions_three.end(); it++) {
//        cout << *it;
//    }
//}
//
//

////    strands.insert(eight, output_thirty_two);
////    strands.insert(nine , output_thirty_three);
////    strands.insert(ten, output_fourthy);
////    strands.insert(eleven,output_fourthy_one);
////    strands.insert(twelve , output_fourthy_two);
////    strands.insert(thirteen , output_fourthy_three);
////    strands.insert(fourtheen , output_fourthy_four);
////    strands.insert(fiftheen , output_fourthy_five);
//
//
//
//}
//
//
//
//void testS_e_i() {
//    unordered_map<int, vector<int>> strands;
//    unordered_map<int, encoded_strand> encoded_strands;
//    vector<vector<int>> output;
//    vector<int> output2;
//    creatingStrands(strands);
//    S_e_i(strands, 2, 2,  8, output, encoded_strands, true);
//    for (auto it = output2.begin(); it != output2.end(); it++) {
//        cout << *it << endl;
//
//    }
//
//}
//
//
//void testW_l_S_t_BruteForce(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    vector<vector<int>> strands_data;
//    vector<int> output;
//    for(auto it = strands.begin(); it != strands.end(); it++){
//        strands_data.push_back(it->second);
//    }
//    W_l_S_t_BruteForce(strands_data, 4, output, HammingDistance);
//    cout << "the output of W_l_S_t is " << endl;
//    for(auto i: output){
//        cout << i;
//
//    }
//    cout << endl;
//
//}
//
//
//void testW_l_S_t_NoBruteForce(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    vector<vector<int>> strands_data;
//    vector<int> output;
//    for(auto it = strands.begin(); it != strands.end(); it++){
//        strands_data.push_back(it->second);
//    }
//    W_l_S_t_NoBruteForce(strands_data, 2, output, HammingDistance);
//    cout << "the output of W_l_S_t is " << endl;
//    for(auto i: output){
//        cout << i;
//
//    }
//    cout << endl;
//
//}
//
//void testDistanceByOne(){
//    set<vector<int>> indexes;
//    vector<int> binary_representation;
//    decToBinary(8, binary_representation);
//    distanceByOne(binary_representation, indexes);
//    for (auto it = indexes.begin(); it != indexes.end(); it++) {
//        for (int j = 0; j < it->size(); j++) {
//            cout << it->operator[](j);
//        }
//        cout << endl;
//    }
//}
//
//
//void printStrandsIndexAndData(unordered_map<int, vector<int>> & strands){
//    for(auto it = strands.begin(); it != strands.end(); it++){
//        vector<int> index;
//        decToBinary(it->first, index);
//        for(int i = 0; i < index.size(); i++){
//            cout << index[i];
//        }
//        cout << " , ";
//        for(int i = 0; i < it->second.size(); i++){
//            cout << it->second[i];
//        }
//        cout << endl;
//    }
//}
//
//
//void testCreateBSet(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    vector<tuple<int,int>> B_set;
//    unordered_map<int, encoded_strand> encoded_strands;
//    printStrandsIndexAndData(strands);
//    createBset(strands, 3, 2, HammingDistance, B_set, encoded_strands);
//    for(int i = 0; i < B_set.size(); i++){
//        cout << "(" << get<0>(B_set[i]) << " , " << get<1>(B_set[i]) << ")" << endl;
//    }
//    cout << "encoded_strands:" << endl;
//    for(int i = 0; i < encoded_strands.size(); i++){
//        cout << encoded_strands.find(i)->second.getIsEncoded() << endl;
//    }
//
//}
//
//void printBset(vector<tuple<int,int>>& B_set){
//    for(int i = 0; i < B_set.size(); i++){
//        cout << "(" << get<0>(B_set[i]) << " , " << get<1>(B_set[i]) << ")" << endl;
//    }
//}
//
//void testUpdateBSet(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    vector<tuple<int,int>> B_set;
//    unordered_map<int, encoded_strand> encoded_strands;
//    printStrandsIndexAndData(strands);
//    createBset(strands, 3, 2, HammingDistance, B_set, encoded_strands);
//    printBset(B_set);
//    cout << "encoded_strands:" << endl;
//    for(int i = 0; i < encoded_strands.size(); i++){
//        cout << encoded_strands.find(i)->second.getIsEncoded() << endl;
//    }
//    vector<int>w_l(2);
//    w_l[0] = 1;
//    w_l[1] = 1;
//    vector<int> delta_one(2);
//    delta_one[0] = 0;
//    delta_one[1] = 0;
//    vector<int> delta_two(2);
//    delta_two[0] = 0;
//    delta_two[1] = 0;
//    encoded_strand new_strand(delta_one, delta_two, w_l, 9);
//    updateBSet(strands, B_set, 9, new_strand, HammingDistance, 2);
//    printBset(B_set);
//
//
//}
//
//
//
//
//
//void testCreateBinaryFromDelta1(){
//    // test no padding
//    int zero = 0;
//    int seven = 7;
//    vector<int> zero_binary;
//    vector<int> seven_binary;
//    decToBinaryWithSize(zero, zero_binary,log2(8));
//    decToBinaryWithSize(seven, seven_binary,log2(8));
//    vector<int> delta1;
//    delta_1(zero_binary, seven_binary, delta1);
//    for(int i = 0; i < delta1.size(); i++){
//        cout << delta1[i] << endl;
//    }
//    vector<int> padding;
//    vector<int> delta_1_binary;
//    encoded_strand strand(0, delta1);
//    strand.createBinaryVectorFromDelta1(delta1, 8, 3,  padding, delta_1_binary);
//    delta1.clear();
//    delta_1_binary.clear();
//    /// test with padding
//    int one = 1;
//    int two = 2;
//    vector<int> one_binary;
//    vector<int> two_binary;
//    decToBinaryWithSize(one, one_binary,log2(8));
//    decToBinaryWithSize(two, two_binary,log2(8));
//    delta_1(one_binary, two_binary, delta1);
//    strand.createBinaryVectorFromDelta1(delta1, 8, 3,  padding, delta_1_binary);
//
//}
//
//
//void testCreateBinaryFromDelta2() {
//    /// no padding
//    vector<int> thirty_two_binary;
//    vector<int> sixty_three;
//    decToBinaryWithSize(32, thirty_two_binary, 5);
//    decToBinaryWithSize(63, sixty_three, 5);
//    vector<int> delta2;
//    vector<int> delta_2_binary;
//    vector<int> padding;
//    delta_2(thirty_two_binary, sixty_three, delta2);
//    encoded_strand strand(0, delta2);
//    strand.createBinaryVectorFromDelta2(delta2, 8, 9, 6, padding, delta_2_binary);
//    delta2.clear();
//    delta_2_binary.clear();
//
//    /// padding of last entry
//    vector<int> thirty_three_binary;
//    vector<int> thirty_four_binary;
//    decToBinaryWithSize(33, thirty_three_binary, 6);
//    decToBinaryWithSize(34, thirty_four_binary, 6);
//    delta_2(thirty_three_binary, thirty_four_binary, delta2);
//    strand.createBinaryVectorFromDelta2(delta2, 8, 9, 6, padding, delta_2_binary);
//    delta2.clear();
//    delta_2_binary.clear();
//    padding.clear();
//    /// with the data is the same
//    strand.createBinaryVectorFromDelta2(delta2, 8, 9, 6, padding, delta_2_binary);
//}
//
//void testCreateOneBinaryVectorFromEncodedData(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    /// delta 1
//    int zero = 0;
//    int seven = 7;
//    vector<int> zero_binary;
//    vector<int> seven_binary;
//    decToBinaryWithSize(zero, zero_binary,log2(8));
//    decToBinaryWithSize(seven, seven_binary,log2(8));
//    vector<int> delta1;
//    delta_1(zero_binary, seven_binary, delta1);
//
//    /// delta 2
//    vector<int> thirty_two_binary;
//    vector<int> sixty_three;
//    decToBinaryWithSize(32, thirty_two_binary, 5);
//    decToBinaryWithSize(63, sixty_three, 5);
//    vector<int> delta2;
//    vector<int> delta_2_binary;
//    vector<int> padding;
//    delta_2(thirty_two_binary, sixty_three, delta2);
//
//    /// w_L
//    vector<int> w_l;
//    w_l.push_back(1);
//    w_l.push_back(1);
//    w_l.push_back(0);
//    w_l.push_back(0);
//    w_l.push_back(0);
//    w_l.push_back(1);
//
//    /// encoded_strand
//
//    encoded_strand strand(delta1, delta2, w_l, 0);
//    vector<int> binary_data;
//    strand.createOneBinaryVectorFromEncodedData(binary_data, 8,  45, 3, 6);
//
//}
//
//void testFindPairToBeFixed(){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    unordered_map<int, encoded_strand> encoded_strands;
//
//    /// initilize p
//    int p = strands.size() - 1;
//    vector<tuple<int, int>> B;
//    int index_length = ceil(log2(strands.size()));
//
//    /// add the last strand to the encoded_strand map
//    encoded_strand last_strand(p, strands.find(p)->second);
//    pair<int, encoded_strand> last_strand_pair(p, last_strand);
//    encoded_strands.insert(last_strand_pair);
//    vector<tuple<int,int>> output;
//    find_pair_to_be_fixed(strands,  0,   4, 2, HammingDistance, output, encoded_strands);
//
//}
//
//
//
//void testEncodingAlgorithim(unordered_map<int, encoded_strand> &encoded_strands){
//    unordered_map<int, vector<int>> strands;
//    creatingStrands(strands);
//    encoding_algorithm(strands, 2, 2, 6,  HammingDistance, encoded_strands, true);
//    return;
//}
//
//
//
//void testcreateDecodingOrderList(){
//    unordered_map<int, encoded_strand> encoded_strands;
//    testEncodingAlgorithim(encoded_strands);
//    vector<int> decoding_list;
//    createDecodingOrderList(encoded_strands, decoding_list);
//    return;
//
//}

void testConvertCharVecToIntVec(){
    vector<char> f({'1', '0', '0', '1'});
    vector<int> t;
    convertCharVecToIntVec(f, t);
    for(int i = 0; i < t.size(); i++){
        cout << t[i] << endl;
    }
}


void TestsetNextNodeInList(vector<int> index_in_binary){
    vector<int> encoded_data{1, 1, 0};
    encoded_data.insert(encoded_data.begin(), index_in_binary.begin(), index_in_binary.end());
    for(int i = 0; i < encoded_data.size(); i++){
        cout << encoded_data[i] << endl;
    }

}

void testConvertIntVecToCharVec(){
    vector<char> f;
    vector<int> t{1, 0, 0, 1};
    convertIntVecToCharVec(f, t);
    for(int i = 0; i < f.size(); i++){
        cout << f[i] << endl;
    }
}

    int main(){

    ///testCreateDelta1();
   /// testCreateDelta2();
  /// testW_lBruteForce();
  /// testW_lNoBruteForce();
  /// testCreateReplVector();
  ///testCreateS_e_i();
  ///testAddEncodedVersion();
/// testEncodingAlgorithim();
///  testCreateDecodingOrderList();
///testDecodeIndex();
    testDecodeData();










//    testDecToBinary();
//    testingDeltaOne();
//    testS_e_i();
//    testW_l_S_t();
//    testCreateBSet();
//    testCreateReplVector();
//    testBinaryToDec();
//    vector<string> DP[K][K];
//    findBitCombinations(4,DP,2);
//    testDistanceByOne();
//    testS_e_i();
//    testW_l_S_t_BruteForce();
//    testW_l_S_t_NoBruteForce();
//    testCreateBinaryFromDelta1();
//    testCreateBinaryFromDelta2();
//    testCreateOneBinaryVectorFromEncodedData();
//    testFindPairToBeFixed();
//        unordered_map<int, encoded_strand> encoded_strands;
//testEncodingAlgorithim(encoded_strands);
//    unordered_map<int, vector<int>> strands;
//    ParseDataToEncoding("test_file.txt", 10, strands);




//testEncodingAlgorithim();
  //  testcreateDecodingOrderList();



}


















