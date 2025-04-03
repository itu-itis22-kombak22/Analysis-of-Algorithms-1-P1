#include "tweet.h"
#include "fstream"

std::vector<Tweet> readTweetsFromFile(const std::string &filename) {
    std::vector<Tweet> tweets;
    std::ifstream tweetfile(filename);

    if (!tweetfile.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        exit(-1);
    }


    std::string line;

    getline(tweetfile, line);

    while (getline(tweetfile, line)) {
        std::stringstream ss(line);
        std::string tweetID, retweetCount, favoriteCount;
        getline(ss, tweetID, ',');
        getline(ss, retweetCount, ',');
        getline(ss, favoriteCount, ',');
        Tweet tweet;
        tweet.tweetID = std::stoll(tweetID);
        tweet.retweetCount = std::stoi(retweetCount);
        tweet.favoriteCount = std::stoi(favoriteCount);
        tweets.push_back(tweet);
    }

    tweetfile.close();
    return tweets;


}

void writeTweetsToFile(const std::string &filename, const std::vector<Tweet> &tweets) {

    std::ofstream testresults(filename);

    if (!testresults.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        exit(-1);
    }

    testresults << "tweet_id,retweetcount,favoritecount\n";

    for (const auto &tweet: tweets) {
        testresults << tweet.tweetID << ',';
        testresults << tweet.retweetCount << ',';
        testresults << tweet.favoriteCount << '\n';
    }

    testresults.close();
}