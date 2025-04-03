#include "tweet.h"
#include "chrono"

//Ece Nil Kombak 820220330 31.10.2024

int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file> <sortBy> <ascending> <sort algorithm>"
                  << std::endl;
        return -1;
    }

    //please give 'ascending' value as 1 or 0

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string sortBy = argv[3];
    bool ascending = std::stoi(argv[4]);
    std::string sortAlgorithm = argv[5];


    std::vector<Tweet> tweets = readTweetsFromFile(inputFile);

    if (sortAlgorithm == "bubble") {
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(tweets, sortBy, ascending);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Bubble sort's execution time is: " << elapsed.count() << "s" << std::endl;
    } else if (sortAlgorithm == "insertion") {
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(tweets, sortBy, ascending);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Insertion sort's execution time is: " << elapsed.count() << "s" << std::endl;
    } else if (sortAlgorithm == "merge") {
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(tweets, 0, tweets.size() - 1, sortBy, ascending);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Merge sort's execution time is: " << elapsed.count() << "s" << std::endl;
    } else {
        std::cerr << "Invalid sorting algorithm" << std::endl;
        exit(-1);
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        binarySearch(tweets, 1773335, sortBy);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Binary search's execution time is: " << elapsed.count() << "s" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(tweets, "favoriteCount", 250);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Count above threshold's execution time is: " << elapsed.count() << "s" << std::endl;
    }

    writeTweetsToFile(outputFile, tweets);

    return 0;
}