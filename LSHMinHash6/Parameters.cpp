#include "Parameters.h"

Parameters::Parameters()
{

}

Parameters::Parameters(string mode, string * filenames, int number_of_files, int file_type, int number_of_sequences, int sequence_min_length, int sub_sequence_width, int hash_type,
            int number_of_buckets, int toleranceLimit, int number_of_hashes, float min_signatures_similarity_ratio, int printMode):
            mode(mode), filenames(filenames), number_of_files(number_of_files), file_type(file_type), number_of_sequences(number_of_sequences), sequence_min_length(sequence_min_length),
            sub_sequence_width(sub_sequence_width), hash_type(hash_type), number_of_buckets(number_of_buckets), toleranceLimit(toleranceLimit), number_of_hashes(number_of_hashes),
            min_signatures_similarity_ratio(min_signatures_similarity_ratio), printMode(printMode)
{

}

Parameters::Parameters(vector<string> * sequencesStrings, int sub_sequence_width, int hash_type, int number_of_buckets, int toleranceLimit, int number_of_hashes, float min_signatures_similarity_ratio):
            sequencesStrings(sequencesStrings), sub_sequence_width(sub_sequence_width), hash_type(hash_type), number_of_buckets(number_of_buckets), toleranceLimit(toleranceLimit), number_of_hashes(number_of_hashes),
            min_signatures_similarity_ratio(min_signatures_similarity_ratio)
{
    this->number_of_files = 0;
}

void Parameters::setSequencesStrings(vector<string> * sequencesStrings){
    this->sequencesStrings = sequencesStrings;
}

void Parameters::setMode(string mode){
    this->mode = mode;
}

void Parameters::setFileNames(string * filenames){
    this->filenames = filenames;
}

void Parameters::setFileType(int file_type){
    this->file_type = file_type;
}

void Parameters::setNumberOfSequences(int number_of_sequences){
    this->number_of_sequences = number_of_sequences;
}

void Parameters::setSequenceMinLength(int sequence_min_length){
    this->sequence_min_length = sequence_min_length;
}

void Parameters::setSubSequenceWidth(int sub_sequence_width){
    this->sub_sequence_width = sub_sequence_width;
}

void Parameters::setHashType(int hash_type){
    this->hash_type = hash_type;
}

void Parameters::setNumberOfBuckets(int number_of_buckets){
    this->number_of_buckets = number_of_buckets;
}

void Parameters::setToleranceLimit(int toleranceLimit){
    this->toleranceLimit = toleranceLimit;
}

void Parameters::setNumberOfHashes(int number_of_hashes){
    this->number_of_hashes = number_of_hashes;
}

void Parameters::setMinSignaturesSimilarityRatio(float min_signatures_similarity_ratio){
    this->min_signatures_similarity_ratio = min_signatures_similarity_ratio;
}

void Parameters::setPrintMode(int printMode){
    this->printMode = printMode;
}
