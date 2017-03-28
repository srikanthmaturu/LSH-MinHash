#include "commandrun.h"
#include "LSHHandler.h"
#include "Parameters.h"


CommandRun::CommandRun()
: Command()
{
    useOption("help");
    useOption("inputFile");
    useOption("outputFile");
    useOption("queryFile");
    useOption("kmerSize");
    useOption("maxIncorrectCharactersSize");
    useOption("numberOfHashes");
}

int CommandRun::run() const{
    Parameters * lshParameters = new Parameters();
    lshParameters = NULL;

    string inputFile, queryFile, outputFile;
    int hashType = 1, file_type = 2, KMERsize, number_of_sequences,
            sequence_minimum_length, number_of_buckets, toleranceLimit, numberOfHashes;
    float min_signatures_similarity_ratio;
    inputFile = getOption("inputFile").argument;
    queryFile = getOption("queryFile").argument;
    outputFile = getOption("outputFile").argument;\
    KMERsize = getOption("kmerSize").argumentAsNumber;
    hashType = 2;
    number_of_sequences = -1;
    sequence_minimum_length = 1;
    number_of_buckets = 1;
    toleranceLimit = getOption("maxIncorrectCharactersSize").argumentAsNumber;
    numberOfHashes = getOption("numberOfHashes").argumentAsNumber;
    min_signatures_similarity_ratio = 1;

    int number_of_files = 2;
    string * filenames = new string[number_of_files];
    filenames[0] = queryFile;
    filenames[1] = inputFile;

    ofstream out(outputFile);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    lshParameters = new Parameters("remote", filenames, number_of_files, file_type, number_of_sequences,
                                   sequence_minimum_length, KMERsize, hashType,
                                        number_of_buckets, toleranceLimit, numberOfHashes, min_signatures_similarity_ratio,
                                   1);
    lshParameters->initialized = true;

    LSHHandler * lsh_handler = new LSHHandler(lshParameters);
    lsh_handler->execute();

    return 1;
}

