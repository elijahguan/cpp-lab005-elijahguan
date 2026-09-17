#include "frequency.h"

#include <stdexcept>
#include <unordered_map>

namespace algorithm_lab {

int mostFrequentNaive(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }

    int best_value = values.front();
    int best_count = 0;

    for (std::size_t i = 0; i < values.size(); ++i) {
        int current = values[i];
        int count = 0;
        for (std::size_t j = 0; j < values.size(); ++j) {
            if (values[j] == current) {
                ++count;
            }
        }

        if (count > best_count || (count == best_count && current < best_value)) {
            best_count = count;
            best_value = current;
        }
    }

    return best_value;
}

int mostFrequentEfficient(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }
    std::unordered_map<int, int> frequency;
    for (int value : values) {
        ++frequency[value];
    }
	int best_value = values.front();
    int best_count = frequency[best_value];
	for (const auto& every : frequency) {
		if (every.second > best_count || (every.second == best_count && every.first < best_value)) {
			best_count = every.second;
			best_value = every.first;
		}
	}
    return best_value;
}
