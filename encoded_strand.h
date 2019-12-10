//
// Created by amitw on 06/12/2019.
//

#ifndef CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_H
#define CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_H

#include "strand.h"
using namespace std;

/*!
 * this class is representing the encoded strand's data containing all the relevant parts of the the encoded data
 * encoded_related_to_index - the index of the strand that the encoding was done in relation to.
 * delta_1 - the positions  that the indexes differ, (base 10).
 * delta_2 - the positions that the data differ, (base 10).
 * w_l - same as explained in the paper (the vector that make sure we hold the constraint).
 * last_bit - the last bit of the strand.
 * if_not_encoded - in case the strand is not suppose to be encoded, this field will contain the uncoded strand.
 */
class encoded_data{
    vector<int> encoded_related_to_index;
    vector<int> delta_1;
    vector<int> delta_2;
    vector<int> w_l;
    int last_bit;
    strand if_not_encoded;

public:
    const vector<int> &getEncodedRelatedToIndex() const {
        return encoded_related_to_index;
    }

    void setEncodedRelatedToIndex(const vector<int> &encodedRelatedToIndex) {
        encoded_related_to_index = encodedRelatedToIndex;
    }

    const vector<int> &getDelta1() const {
        return delta_1;
    }

    void setDelta1(const vector<int> &delta1) {
        delta_1 = delta1;
    }

    const vector<int> &getDelta2() const {
        return delta_2;
    }

    void setDelta2(const vector<int> &delta2) {
        delta_2 = delta2;
    }

    const vector<int> &getWL() const {
        return w_l;
    }

    void setWL(const vector<int> &wL) {
        w_l = wL;
    }

    int getLastBit() const {
        return last_bit;
    }

    void setLastBit(int lastBit) {
        last_bit = lastBit;
    }

    const strand &getIfNotEncoded() const {
        return if_not_encoded;
    }

    void setIfNotEncoded(const strand &ifNotEncoded) {
        if_not_encoded = ifNotEncoded;
    }


};
/*!
 * a class representing an encoded strand
 * index - the encoded index of the strand.
 * data - the encoded data of the strand (above there is an explanation regarding it).
 */
class encoded_strand{
    vector<int> index;
    encoded_data data;

};




#endif //CLUSTERING_CORRECTING_CODES_PROJECT_ENCODED_STRAND_H
