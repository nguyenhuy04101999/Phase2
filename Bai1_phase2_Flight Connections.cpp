#include <iostream>
#include <vector>
#include <queue>

int getMinimumConnections(const std::vector<std::vector<bool>>& matrix)
{
	int n = matrix.size();
	std::vector<bool> visited(n, false);
	int count = 0;

	// BFS to find all reachable airports from each airport
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			std::queue<int> q;
			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int curr = q.front();
				q.pop();

				for (int j = 0; j < n; j++) {
					if (matrix[curr][j] && !visited[j]) {
						q.push(j);
						visited[j] = true;
					}
				}
			}

			count++;
		}
	}

	// The minimum number of flight connections needed is the number of connected components - 1
	return count - 1;
}

int main()
{
	std::vector<std::vector<bool>> matrix{
		{false, true, false, false, true},
		{true, false, false, false, false},
		{false, false, false, true, false},
		{false, false, true, false, false},
		{true, false, false, false, false}
	};

	std::cout << getMinimumConnections(matrix) << std::endl; // should print 1

	return 0;
}