#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
class Solution {
public:
	vector<pair<int,int>> kth_closest(std::vector<std::pair<int, int>> restaurants, int k)
	{
		auto cmp = [](const pair<int,int>& lhs, const pair<int,int>& rhs){
			return (lhs.first*lhs.first + lhs.second*lhs.second) > (rhs.first*rhs.first + rhs.second*rhs.second);
		};
		std::priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> queue(cmp);

		for (const auto& item : restaurants)
			queue.emplace(item);

		vector<pair<int,int>> result;
		for (int i = 0; i < k; ++i)
		{
			result.emplace_back(queue.top());
			queue.pop();
		}

		return result;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& output, std::pair<T,T> const& pair)
{
	output << "(" << pair.first << "," << pair.second << ")";
	return output;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, std::vector<T> const& values)
{
	output << "[";

	if (values.size() > 0)
	{
		output << values[0];
	}

	for (size_t i = 1; i < values.size(); ++i)
	{
		output << ", " << values[i];
	}

	output << "]";
	return output;
}

int main()
{
	Solution s;
	std::vector<std::pair<int,int>> v = {{1,1}, {3, 3}, {4, 4}, {2,4}, {2,3}};
	auto result = s.kth_closest(v,4);
	std::cout << "final: " << result << std::endl;
}