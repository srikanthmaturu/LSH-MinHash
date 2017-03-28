#include "numberofhashesexperiment.h"
#include "Parameters.h"
#include "LSHHandler.h"
#include <iostream>

NumberOfHashesExperiment::NumberOfHashesExperiment()
{

}

NumberOfHashesExperiment::NumberOfHashesExperiment(string *originalSequence, string *remoteSequence, int subSequenceWidth, int maxHashes):
                            originalSequence(originalSequence), remoteSequence(remoteSequence), subSequenceWidth(subSequenceWidth), maxHashes(maxHashes){

}

vector< pair<float, float> * > * NumberOfHashesExperiment::run(){
    vector< pair<float, float> * > * datapoints = new vector< pair <float, float> * >();
    LSHHandler * tool;
    Parameters * parameters;
    vector< string> * sequenceStrings = new vector< string>();
    sequenceStrings->push_back(*(this->originalSequence));
    sequenceStrings->push_back(*(this->remoteSequence));
    pair<float, float> * p;

    for(int index = 1; index <= this->maxHashes; ++index){
        p = new pair<float, float>();
        parameters = new Parameters(sequenceStrings, this->subSequenceWidth, 2, 0, 0, index, 0);
        tool = new LSHHandler(parameters);
        tool->execute();
        vector< vector<float> * > * point = tool->getSequences()->getSequencesSimilarityMatrix();
        p->first = index;
        p->second = (*((*point)[0]))[1];
        datapoints->push_back(p);
    }
    return datapoints;
}

vector< vector< float > * > * NumberOfHashesExperiment::getActualSimilarityMatrix(){
    LSHHandler * tool;
    Parameters * parameters;
    vector< string> * sequenceStrings = new vector< string>();
    sequenceStrings->push_back(*(this->originalSequence));
    sequenceStrings->push_back(*(this->remoteSequence));

    parameters = new Parameters(sequenceStrings, this->subSequenceWidth, 2, 0, 0, 5, 0);
    tool = new LSHHandler(parameters);
    tool->execute();
    return tool->getSequences()->getActualSequencesSimilarityMatrix();
}
