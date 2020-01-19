//
// Created by amitw on 19/01/2020.
//

#ifndef CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_TESTS_H
#define CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_TESTS_H

#include "encoding_algorithim.h"


void printVector(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    cout << endl;
}

void testCreateDelta1(){
    vector<int> index_i{1, 0, 0, 0};
    vector<int> index_j{1, 1, 1, 1};
    vector<int> test_padding{1, 0, 0, 1};
    vector<int> delta_1_binary;
    int M = 8;
    int e = 3;
    create_delta_1(index_i, index_j, delta_1_binary, e, M);
    printVector(delta_1_binary);
    delta_1_binary.clear();
    // test padding
    create_delta_1(index_i, test_padding, delta_1_binary, e, M);
    printVector(delta_1_binary);

}


void testCreateDelta2(){
    vector<int> data_i{1, 0, 0, 0, 1, 0, 0, 0};
    vector<int> data_j{1, 1, 1, 1, 1, 0, 0, 0};
    vector<int> test_padding{1, 0, 0, 0, 1, 1, 0, 0};
    vector<int> test_identical_padding{1, 0, 0, 0, 1, 0, 0, 0};
    int M = 8;
    int strand_data_length = 8;
    int t = 4;
    vector<int> delta_2_binary;
    create_delta_2(data_i, data_j, M, 8, t, delta_2_binary);
    printVector(delta_2_binary);
    delta_2_binary.clear();
    create_delta_2(data_i, test_padding, M, 8, t, delta_2_binary);
    printVector(delta_2_binary);
    delta_2_binary.clear();
    create_delta_2(data_i, test_identical_padding, M, 8, t, delta_2_binary);
    printVector(delta_2_binary);

}


#endif //CLUSTERING_CORRECTING_CODES_PROJECT_ENCODING_ALGORITHIM_TESTS_H
