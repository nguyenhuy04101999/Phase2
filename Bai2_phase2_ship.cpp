#include <vector>
#include <unordered_map>
#include <iostream>

int minPieces(const std::vector<int>& original, const std::vector<int>& desired) {
	std::unordered_map<int, int> pos;
	for (int i = 0; i < desired.size(); i++) {
		pos[desired[i]] = i;
	}
	int res = 0, i = 0;
	while (i < original.size()) {
		int j = i + 1;
		while (j < original.size() && pos[original[j]] > pos[original[j - 1]]) {
			j++;
		}
		res++;
		i = j;
	}
	return res;
}

int main() {
	std::vector<int> original = { 1, 4, 3, 2 };
	std::vector<int> desired = { 1, 2, 4, 3 };
	std::cout << minPieces(original, desired) << std::endl; // expected output: 3

	std::vector<int> original2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> desired2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::cout << minPieces(original2, desired2) << std::endl; // expected output: 1

	std::vector<int> original3(100000);
	std::vector<int> desired3(100000);
	for (int i = 0; i < 100000; i++) {
		original3[i] = i + 1;
		desired3[i] = 100000 - i;
	}
	std::cout << minPieces(original3, desired3) << std::endl; // expected output: 1
}