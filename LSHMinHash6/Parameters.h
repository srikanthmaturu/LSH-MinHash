#ifndef Parameters_H
#define Parameters_H

#include<vector>
#include <string>

using namespace std;

class Parameters
{
public:
    bool initialized = false;
    int printMode = 0;
    string mode;
    string * filenames;
    vector<string> * sequencesStrings = NULL;
    int file_type, number_of_files, number_of_sequences, sequence_min_length, sub_sequence_width,
        hash_type, number_of_buckets, toleranceLimit, number_of_hashes, number_of_query_sequences, number_of_input_sequences;
    float min_signatures_similarity_ratio;

    void setMode(string mode);
    void setFileNames(string * filenames);
    void setSequencesStrings(vector<string> * sequencesStrings);
    void setFileType(int file_type);
    void setNumberOfSequences(int number_of_sequences);
    void setSequenceMinLength(int sequence_min_length);
    void setSubSequenceWidth(int sub_sequence_width);
    void setHashType(int hash_type);
    void setNumberOfBuckets(int number_of_buckets);
    void setToleranceLimit(int toleranceLimit);
    void setNumberOfHashes(int number_of_hashes);
    void setMinSignaturesSimilarityRatio(float min_signatures_similarity_ratio);
    void setPrintMode(int printMode);

    Parameters();
    Parameters(string mode, string * filenames, int number_of_files, int file_type, int number_of_sequences, int sequence_min_length, int sub_sequence_width, int hash_type,
              int number_of_buckets, int toleranceLimit, int number_of_hashes, float min_signatures_similarity_ratio, int printMode);
    Parameters(vector<string> * sequencesStrings, int sub_sequence_width, int hash_type, int number_of_buckets, int toleranceLimit, int number_of_hashes, float min_signatures_similarity_ratio);
};

#endif // Parameters_H
