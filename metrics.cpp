#include "tweet.h"

int binarySearch(const std::vector<Tweet> &tweets, long long key, const std::string &sortBy) {
    int left = 0;
    int right = tweets.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (sortBy == "tweetID") {
            if (tweets[mid].tweetID == key) {
                return mid;
            } else if (tweets[mid].tweetID < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (sortBy == "retweet_count") {
            if (tweets[mid].retweetCount == key) {
                return mid;
            } else if (tweets[mid].retweetCount < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (sortBy == "favorite_count") {
            if (tweets[mid].favoriteCount == key) {
                return mid;
            } else if (tweets[mid].favoriteCount < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;

}

int countAboveThreshold(const std::vector<Tweet> &tweets, const std::string &metric, int threshold) {

    int count = 0;

    if (metric == "retweetCount") {
        for (int i = 0; i < tweets.size(); i++) {
            if (tweets[i].retweetCount > threshold) {
                count++;
            }
        }
    } else if (metric == "favoriteCount") {
        for (int i = 0; i < tweets.size(); i++) {
            if (tweets[i].favoriteCount > threshold) {
                count++;
            }
        }
    } else {
        std::cerr << "Invalid metric" << std::endl;
        exit(-1);
    }

    return count;

}
