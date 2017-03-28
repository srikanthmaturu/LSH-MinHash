#ifndef NUMBEROFHASHESEXPERIMENT_H
#define NUMBEROFHASHESEXPERIMENT_H

#include <string>
#include <utility>
#include <vector>

using namespace std;

class NumberOfHashesExperiment
{
public:
    string * originalSequence;
    string * remoteSequence;
    int subSequenceWidth;
    int maxHashes;

    NumberOfHashesExperiment();
    NumberOfHashesExperiment(string * originalSequence, string * remoteSequence, int subSequenceWidth, int maxHashes);
    vector< pair<float, float>* > * run();
    vector< vector< float > * > * getActualSimilarityMatrix();
};

#endif // NUMBEROFHASHESEXPERIMENT_H
