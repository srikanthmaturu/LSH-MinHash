/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sequences.cpp
 * Author: Srikanth
 * 
 * Created on February 6, 2017, 10:37 PM
 */

#include "Sequences.h"
#include "Buckets.h"
#include "LambertW.h"

Sequences::Sequences() {
    this->sequences = NULL;
}

Sequences::Sequences(const Sequences& orig) {
}

Sequences::~Sequences() {
}

void Sequences::setSequences(vector<Sequence*> * sequences){
    this->sequences = sequences;
}

vector<Sequence *> * Sequences::getSequences(){
    return this->sequences;
}

void Sequences::appendSequences(vector< Sequence * > * sequences){
    this->sequences->insert(this->sequences->begin(), sequences->begin(), sequences->end());
}

void Sequences::indexSequences(){
    Sequence * sequence;
    for(int index = 0; index < this->sequences->size(); ++index){
       sequence = (*(this->sequences))[index];
       sequence->setIndex(index+1);
    }
}

void Sequences::readInputSequences(string filename, int sub_sequence_width, int number_of_sequences, int sequence_min_length , int type, int printMode){
    ifstream data_file;
    data_file.open (filename.c_str(), ifstream::in);
    char * input_char_sequence = new char [1024];
    if(this->sequences == NULL){
        this->sequences = new vector < Sequence * >();
    }
    Sequence * sequence = NULL;
    regex e ("^>");
    smatch m;

    data_file.getline(input_char_sequence, 1024, '\n');

    while(!data_file.eof()){
        if(type == 1){
            if(regex_search(input_char_sequence, e)){
                if(sequence != NULL){
                    if(sequence->getSequence().length() >= sequence_min_length){
                        sequence->computeSubSequencesSet(sub_sequence_width);
                        this->sequences->push_back(sequence);
                        if(printMode == 0){
                            //sequence->printSubSequences();
                            sequence->printSequence();
                        }
                        if(number_of_sequences != -1 && this->sequences->size() == number_of_sequences){
                            break;
                        }
                    }
                }
                sequence = new Sequence();
                sequence->setComment(input_char_sequence);
            }else{
                sequence->appendSequence(input_char_sequence);
            }
        }
        else if(type == 2){
            sequence = new Sequence();
            sequence->setComment("None");
            sequence->appendSequence(input_char_sequence);
            //cout << "here" << input_char_sequence << " " << filename << "\n";
            if(sequence->getSequence().length() >= sequence_min_length){
                sequence->computeSubSequencesSet(sub_sequence_width);
                this->sequences->push_back(sequence);
                if(printMode == 0){
                    //sequence->printSubSequences();
                    sequence->printSequence();
                }
                if(number_of_sequences != -1 && this->sequences->size() == number_of_sequences){
                    break;
                }
            }
        }
        data_file.getline(input_char_sequence, 1024, '\n'); 
    }
    return ;
}

void Sequences::readInputSequences(vector<string> *sequenceStrings, int sub_sequence_width){
    if(this->sequences == NULL){
        this->sequences = new vector < Sequence * >();
    }
    for(vector<string>::iterator ssit = sequenceStrings->begin(); ssit != sequenceStrings->end(); ++ssit){
        Sequence * sequence = new Sequence();
        sequence->appendSequence(*ssit);
        sequence->computeSubSequencesSet(sub_sequence_width);
        this->sequences->push_back(sequence);
    }
}

void Sequences::computeSubSequencesSetsUnion(){
    this->sub_sequences_sets_union = new SequencesSet();

    for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
        this->sub_sequences_sets_union->appendSequences((*seq_it)->getSubSequencesSet());
    }
    
    //this->sub_sequences_sets_union->printSequencesSet();
}

SequencesSet * Sequences::getSubSequencesSetsUnion(){
    return this->sub_sequences_sets_union;
}

void Sequences::computeSubSequencesSetsUnionMap(){
    this->sub_sequences_sets_union_map = new SequencesMap();
    int index = 1;
    for(SequencesSet::iterator seqs_it = this->sub_sequences_sets_union->begin(); seqs_it != this->sub_sequences_sets_union->end(); ++seqs_it, ++index){
        this->sub_sequences_sets_union_map->insert(pair<string, int> (*seqs_it, index));
    }
    
    //this->sub_sequences_sets_union_map->printSequencesMap();
}

SequencesMap * Sequences::getSubSequencesSetsUnionMap(){
    return this->sub_sequences_sets_union_map;
}

void Sequences::computeSequencesMaps(){
    for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
        (*seq_it)->computeSubSequencesMap(this->sub_sequences_sets_union_map);
        //(*seq_it)->getSubSequencesMap()->printSequencesMap();
    }
}

void Sequences::initializeSignatures(){
    Signature * signature;
    Sequence * sequence;
    for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
        signature = new Signature();
        sequence = *seq_it;
        signature->initializeSignature(this->signaturegenerator->get_signature_size());
        sequence->setSignature(signature);
    }
}

void Sequences::computeSequencesSignatures(){
    Sequence * sequence;
    for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
            sequence = *seq_it;
            this->signaturegenerator->computeSignature(sequence);
    }
}

void Sequences::printShinglesMatrix(){
    cout << "\n\n\n Printing Shingles Matrix: \n\n";
    int rows_size = this->sub_sequences_sets_union->size();
    string first_line = "    \t";
    for(int c = 1; c <= this->sequences->size(); ++c){
        first_line.append("Seq"+to_string(c)+"\t");
    }
    cout << "\n" << first_line << "\n";
    string print_string, sub_sequence;
    Sequence * sequence;
    for(SequencesMap::iterator it = this->sub_sequences_sets_union_map->begin(); it != this->sub_sequences_sets_union_map->end(); ++it){
        sub_sequence = (*it).first;
        print_string.append(sub_sequence+" \t");
        for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
            sequence = *seq_it;
            if(sequence->getSubSequencesMap()->find(sub_sequence)!= sequence->getSubSequencesMap()->end()){
                print_string.append("1\t");
            }
            else{
                print_string.append("0\t");
            }
        }
        cout << print_string << "\n";
        print_string.clear();
    }
}

void Sequences::printSignatures(){
    cout << "\n\n\nPrinting Signature Matrix: \n\n";
    int rows_size = this->sub_sequences_sets_union->size();
    string first_line = "        \t";
    for(int c = 1; c <= this->sequences->size(); ++c){
        first_line.append("Seq"+to_string(c)+"\t");
    }
    cout << "\n" << first_line << "\n";
    string print_string, sub_sequence;
    Sequence * sequence;
    
    for(int row_index = 1; row_index <= this->signaturegenerator->get_signature_size(); ++row_index){
        print_string.append("HashF:"+to_string(row_index)+" \t");
        for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
            sequence = *seq_it;
            print_string.append(to_string(sequence->getSignature()->getValueAt(row_index-1))+" \t");
        }
        cout << print_string << "\n";
        print_string.clear();
    }
}

void Sequences::initializeSequenceSignatureGenerator(int signature_size){
    this->signaturegenerator = new SequenceSignatureGenerator();
    this->signaturegenerator->set_signature_size(signature_size);
    this->signaturegenerator->setNumberOfSubSequences(this->sub_sequences_sets_union->size());
    this->signaturegenerator->setNumberOfSequences(this->sequences->size());
    this->signaturegenerator->initializePermutations();
    //permutations.printPermutations();
}

void Sequences::initializeBuckets(int number_of_buckets, int number_of_hashes, float min_signatures_similarity_ratio){
    this->buckets = new Buckets();
    this->buckets->setBucketsSize(number_of_buckets);

    this->buckets->setMinSigSimRatio(min_signatures_similarity_ratio);
    float a = 1/this->buckets->getMinSigSimRatio();
    /*
     * formula x = W(mlog(a))/log(a)
     * m = number_of_hashes
     * a = 1/min_signatures_similarity_ratio
     */
    float mloga = number_of_hashes*log(a), productLog = LambertW(mloga);
    int segments = (int)(productLog/log(a));

    int remainder = number_of_hashes % segments;
    number_of_hashes -= remainder;

    this->buckets->setSegmentSize(segments);
    this->buckets->setNumberOfSegments(number_of_hashes/segments);
    this->buckets->setNumberOfHashes(number_of_hashes);
    if(lsh_mode == 1){
        cout << "\nBuckets Configuration: \n";
        cout << "\nNo of segments: " << segments << " Number of hashes: " << number_of_hashes << " Segment size: " << (float)number_of_hashes/(float)segments << "\n";
    }
    this->buckets->setMode(this->lsh_mode);

    if(lsh_mode == 1){
        this->buckets->initializeBuckets();
    }
    else if(lsh_mode == 2){
        this->buckets->initializeBuckets(this->sequences);
    }
}

void Sequences::putSequencesToBuckets(){
    for(int index = 1; index <= this->sequences->size(); ++index){
        if(lsh_mode == 1){
            this->buckets->pushToBuckets(this->sequences->at(index - 1), index);
        }else if (lsh_mode == 2){
            this->buckets->pushToSequenceBuckets(this->sequences->at(index - 1), index);
        }
    }
}

void Sequences::computeSimilaritySets(){
    for(int index = 1; index <= this->sequences->size(); ++index){
        (*sequences)[index - 1]->setSimilaritySet(this->buckets->getSimilaritySet(index));
        //cout << index << "\n";
    }
}

void Sequences::printSimilaritySets(){
    Sequence * sequence;
    cout << "\n\n\nPrinting Similarity Sets:";
    for(vector< Sequence *>::iterator seq_it = this->sequences->begin(); seq_it != this->sequences->end(); ++seq_it){
        sequence = *seq_it;
        sequence->printSimilaritySet();
    }
}

void Sequences::computeSequencesSimilarityMatrix(){
    this->SequencesSimilarityMatrix = new vector< vector<float> * > ();
    for(int i = 1; i <= this->sequences->size(); ++i){
        vector< float > * bucketRatios = new vector< float >(this->sequences->size(), 0.0);
        this->SequencesSimilarityMatrix->push_back(bucketRatios);
    }

    for(vector< Bucket *>::iterator bit = this->buckets->buckets->begin(); bit != this->buckets->buckets->end(); ++bit){
        Bucket * b = * bit;
        vector< float > column;
        for(map< int, float>::iterator seqSims = b->sequences_to_bucket_sequence_similarity_ratios_map->begin();
            seqSims != b->sequences_to_bucket_sequence_similarity_ratios_map->end(); ++seqSims){
            (*((*(this->SequencesSimilarityMatrix))[b->getBucketSequence()->getIndex()-1]))[(*seqSims).first-1] = (*seqSims).second;
        }
    }
}

void Sequences::printSequencesSimilarityMatrix(){
    cout << " \n\n\nPrinting Sequences Similarity Matrix: \n\n ";
    string firstLine;
    firstLine.append("\t");
    for(int i=1; i <= this->sequences->size(); ++i){
        firstLine.append("Seq");
        firstLine.append(to_string(i));
        firstLine.append("\t");
    }
    cout << firstLine << "\n";
    for(int i = 1; i <= this->sequences->size(); ++i){
        cout << "\nSeq " << i << ":\t";
        for(int j = 1; j <= this->sequences->size(); ++j){
            cout << (*((*(this->SequencesSimilarityMatrix))[i-1]))[j-1]<<"\t";
        }
    }
}

vector< vector< float> * > * Sequences::getSequencesSimilarityMatrix(){
    return this->SequencesSimilarityMatrix;
}

void Sequences::computeActualSequencesSimilarityMatrix(){
    this->ActualSequencesSimilarityMatrix = new vector< vector<float> * > ();
    for(int i = 1; i <= this->sequences->size(); ++i){
        vector< float > * bucketRatios = new vector< float >(this->sequences->size(), 0.0);
        this->ActualSequencesSimilarityMatrix->push_back(bucketRatios);
    }

    for(int i = 1; i <= this->sequences->size(); ++i){
        (*((*(this->ActualSequencesSimilarityMatrix))[i-1]))[i-1] = 1;
        for(int j = i + 1; j <= this->sequences->size(); ++j){
            Sequence * firstSequence, * secondSequence;
            firstSequence = (*(this->sequences))[i-1];
            secondSequence = (*(this->sequences))[j-1];
            float ratio = firstSequence->getActualSimilarityRatio(this->sub_sequences_sets_union, secondSequence);
            (*((*(this->ActualSequencesSimilarityMatrix))[i-1]))[j-1] = ratio;
            (*((*(this->ActualSequencesSimilarityMatrix))[j-1]))[i-1] = ratio;
        }
    }
}

void Sequences::printActualSequencesSimilarityMatrix(){
    cout << " \n\n\nPrinting Sequences Actual Similarity Matrix: \n\n ";
    string firstLine;
    firstLine.append("\t");
    for(int i=1; i <= this->sequences->size(); ++i){
        firstLine.append("Seq");
        firstLine.append(to_string(i));
        firstLine.append("\t");
    }
    cout << firstLine << "\n";
    for(int i = 1; i <= this->sequences->size(); ++i){
        cout << "\nSeq " << i << ":\t";
        for(int j = 1; j <= this->sequences->size(); ++j){
            cout << (*((*(this->ActualSequencesSimilarityMatrix))[i-1]))[j-1]<<"\t";
        }
    }
}


vector< vector< float> * > * Sequences::getActualSequencesSimilarityMatrix(){
    return this->ActualSequencesSimilarityMatrix;
}

void Sequences::setLSHMode(int mode){
    this->lsh_mode = mode;
}

int Sequences::getLSHMode(){
    return this->lsh_mode;
}

void Sequences::printSimilarSequences(int numberOfSequences){
    if(numberOfSequences > this->sequences->size()){
        return;
    }
    Sequence * firstSequence, * secondSequence;
    for(int i=1; i <= numberOfSequences; ++i){
        firstSequence = (*(this->sequences))[i-1];
        cout << "\n\n\n\nQuerySequence: \t";
        firstSequence->printRawSequence();
        cout << endl;
        cout << "\n\nSimilar sequences:\n";
        SimilaritySet * similaritySet = firstSequence->getSimilairtySet();
        for(set<int>::iterator it = similaritySet->begin(); it != similaritySet->end(); ++it){
            if(*it <= numberOfSequences){
                continue;
            }
            secondSequence =  (*(this->sequences))[*it-1];
            cout << "\t\t";
            secondSequence->printRawSequence();
            cout << "\n";
        }
    }
}


