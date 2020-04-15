# clustering-correcting-codes
the implementation of the algorithms specified in the article https://arxiv.org/pdf/1903.04122.pdf

Abstract— "A new family of codes, called clustering-correcting
codes, is presented in this paper. This family of codes is motivated
by the special structure of data that is stored in DNA-based storage systems. The data stored in these systems has the form of
unordered sequences, also called strands, and every strand is synthesized thousands to millions of times, where some of these copies
are read back during sequencing. Due to the unordered structure
of the strands, an important task in the decoding process is to
place them in their correct order. This is usually accomplished by
allocating a part of the strand for an index. However, in the presence of errors in the index field, important information on the
order of the strands may be lost.
Clustering-correcting codes ensure that if the distance between
the index fields of two strands is small, then there will be a large
distance between their data fields. It is shown how this property
enables to place the strands together in their correct clusters even
in the presence of errors. We present lower and upper bounds on
the size of clustering-correcting codes and an explicit construction
of these codes which uses only a single bit of redundancy".


to compile you need to use 'g++ -std=c++14 -o main main.cpp' command.

in order to run the test, you need to run it from CMD with the following command:
'./main 1 2 98 M false test_file_updated.txt'

arg 1 - raw

arg 2 - tao

arg 3 - strands data length

arg 4 - assumption (majority/dominance)

arg 5 - boolean denoting wether we're using brute force manner in the encoding algorithim (further explanation regarding this is in the paper).

arg 6 - the test input file (should be located within the project).

output files:

1. results_before_encoding.txt - the strands before the encoding algorithim (sorted by the index of the strand).

2. results_after_encoding.txt - the strands after the encoding algorithim (sorted by the index of the strand).

3. results_after_decoding.txt - the strands after the activating decoding algorithim straight after encoding (without error simulation, clustering, and error correction).

4. status_after_errors_simulations.txt - after encoding algorithim, we perform error simulations on the strands (duplicate each strands, insert diffrent error to each copy).

5. status_after_fix_errors.txt - the clusters situation after we've performed the idetification algorithim and the error correction algorithm.

6. status_to_fix_errors_output.txt - the majority vector from each cluster. (we go through all the vectors in a cluster, bit by bit, and we create a majority vector whom its bits are the most common bits from all the vecotrs in the cluster) e.g :


cluster 1 1000, 1011, 1000

cluster 2 1111, 1001, 1100

majority vector for cluster 1 : 1000
majority vector for cluster 2 : 1101        
        
        


