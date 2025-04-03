# Analysis of Algorithms – Sorting & Metrics Project

This project implements and compares various sorting algorithms and search metrics on a synthetic tweet dataset, providing insights into algorithmic efficiency under different data permutations and sizes.

## Overview

The project explores:
- **Sorting Algorithms:** Bubble Sort, Insertion Sort, and Merge Sort.
- **Searching & Metrics:** Binary Search and a threshold-based counting function.
- **Performance Analysis:** Detailed execution times for each algorithm on datasets with varying sizes and arrangements, highlighting the efficiency differences among the algorithms.

The goal is to understand how algorithm complexity affects performance on real-world data, such as tweet engagement metrics, and to report the findings clearly for further analysis.

## Project Structure

- **bin/**: Contains the compiled binary files.
- **data/**: Holds the input datasets.
- **include/**: Contains header files with structure definitions and function prototypes.
- **lib/**: Includes external libraries (e.g., the Munit testing framework).
- **src/**: Contains the source code implementation.
- **tests/**: Holds unit tests to validate functionality.
- **Makefile**: Automates compiling and linking the C++ code.

## Getting Started

### Prerequisites

- [Docker Desktop](https://www.docker.com/get-started)
- [Visual Studio Code](https://code.visualstudio.com/download)
- A C++ compiler (e.g., g++)

### Setup & Build

1. **Clone the Repository:**
   ```bash
   git clone <repository-url>
   cd <repository-folder>
   ```
2. **Open in Visual Studio Code:**

    Open the folder in VS Code.
    When prompted, choose to "Reopen in Container" to set up the Docker environment.

 Build the Project:
    Via terminal:
   ```bash
   make build
   make run
   make tests
   ```

3. Implementation Details

    Bubble Sort & Insertion Sort: Implemented for both ascending and descending order, demonstrating performance variations with different input permutations.

    Merge Sort: Utilized for its efficiency on larger datasets with a consistent O(n log n) time complexity.

    Binary Search: Used on sorted datasets to quickly locate specific tweet engagement counts.

    Threshold Function: Counts the number of tweets exceeding a given favorite or retweet count, showing performance scalability with data size.

The project follows the guidelines outlined in the assignment instructions and report, ensuring clarity, correctness, and efficient coding practices.
Performance Analysis

The performance metrics for each algorithm were collected and analyzed:

 Different Permutations: Bubble Sort shows significantly slower performance on unsorted or reverse-sorted data, while Insertion Sort performs better on nearly sorted datasets. Merge Sort consistently outperforms both.

 Different Data Sizes: Merge Sort maintains stable performance even as dataset sizes increase, making it the ideal choice for large-scale data processing.

Detailed execution times and comparisons are provided in the project report.
