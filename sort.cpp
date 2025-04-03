#include "tweet.h"

void bubbleSort(std::vector<Tweet> &tweets, const std::string &sortBy, bool ascending) {
    int n = tweets.size();

    if (sortBy == "retweetCount") {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (ascending) {
                    if (tweets[j].retweetCount > tweets[j + 1].retweetCount) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;

                    }
                } else {
                    if (tweets[j].retweetCount < tweets[j + 1].retweetCount) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;

                    }
                }

            }
        }
    } else if (sortBy == "favoriteCount") {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (ascending) {
                    if (tweets[j].favoriteCount > tweets[j + 1].favoriteCount) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;

                    }
                } else {
                    if (tweets[j].favoriteCount < tweets[j + 1].favoriteCount) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;

                    }
                }

            }

        }
    } else if (sortBy == "tweetID") {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (ascending) {
                    if (tweets[j].tweetID > tweets[j + 1].tweetID) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;

                    }
                } else {
                    if (tweets[j].tweetID < tweets[j + 1].tweetID) {
                        Tweet temp = tweets[j];
                        tweets[j] = tweets[j + 1];
                        tweets[j + 1] = temp;


                    }
                }

            }
        }
    } else {
        std::cout << "Invalid sorting parameter" << std::endl;
    }

}


void insertionSort(std::vector<Tweet> &tweets, const std::string &sortBy, bool ascending) {
    int n = tweets.size();

    if (sortBy != "retweetCount" && sortBy != "favoriteCount" && sortBy != "tweetID") {
        std::cout << "Invalid sorting parameter" << std::endl;
        exit(-1);
    }

    for (int i = 1; i < n; i++) {
        Tweet temp = tweets[i];
        int j = i - 1;

        if (sortBy == "retweetCount") {
            if (ascending) {
                while (j >= 0 && tweets[j].retweetCount > temp.retweetCount) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            } else {
                while (j >= 0 && tweets[j].retweetCount < temp.retweetCount) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            }

        } else if (sortBy == "favoriteCount") {
            if (ascending) {
                while (j >= 0 && tweets[j].favoriteCount > temp.favoriteCount) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            } else {
                while (j >= 0 && tweets[j].favoriteCount < temp.favoriteCount) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            }

        } else if (sortBy == "tweetID") {
            if (ascending) {
                while (j >= 0 && tweets[j].tweetID > temp.tweetID) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            } else {
                while (j >= 0 && tweets[j].tweetID < temp.tweetID) {
                    tweets[j + 1] = tweets[j];
                    j--;
                }
            }

        }

        tweets[j + 1] = temp;
    }

}

void merge(std::vector<Tweet> &tweets, int left, int mid, int right, const std::string &sortBy, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Tweet> Leftie(n1), Rightie(n2);


    for (int i = 0; i < n1; i++) {
        Leftie[i] = tweets[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Rightie[j] = tweets[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        bool condition;
        if (sortBy == "retweetCount") {
            if (ascending) {
                condition = Leftie[i].retweetCount <= Rightie[j].retweetCount;
            } else {
                condition = Leftie[i].retweetCount >= Rightie[j].retweetCount;
            }

        } else if (sortBy == "favoriteCount") {
            if (ascending) {
                condition = Leftie[i].favoriteCount <= Rightie[j].favoriteCount;
            } else {
                condition = Leftie[i].favoriteCount >= Rightie[j].favoriteCount;
            }

        } else {
            if (ascending) {
                condition = Leftie[i].tweetID <= Rightie[j].tweetID;
            } else {
                condition = Leftie[i].tweetID >= Rightie[j].tweetID;
            }

        }

        if (condition) {
            tweets[k++] = Leftie[i++];
        } else {
            tweets[k++] = Rightie[j++];
        }
    }


    while (i < n1) {
        tweets[k++] = Leftie[i++];
    }


    while (j < n2) {
        tweets[k++] = Rightie[j++];
    }
}

void mergeSort(std::vector<Tweet> &tweets, int left, int right, const std::string &sortBy, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(tweets, left, mid, sortBy, ascending);
        mergeSort(tweets, mid + 1, right, sortBy, ascending);

        merge(tweets, left, mid, right, sortBy, ascending);
    }
}