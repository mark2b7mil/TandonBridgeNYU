#include <iostream>
#include <vector>

using namespace std;

// Templated function to allow us to use any type as needed.
template <typename T>
vector<T> minmax(const vector<T>& vec, int start, int end);

template <typename T>
vector<T> minmax(const vector<T>& vec);

int main(int argc, char const *argv[]) {
	vector<int> example = {4, 2, 6, 9, 4, 5, 3, -2, 7, 8, 11, 6, 3, 9, 13, 2, 4, -5, 15, 3, 7};
	auto res = minmax<int>(example);
	std::cout << "Min: " << res[0] << " & Max: " << res[1] << endl;
	return 0;
}

template <typename T>
vector<T> minmax(const vector<T>& vec) {
	return minmax(vec, 0, vec.size() - 1);
}

template <typename T>
vector<T> minmax(const vector<T>& vec, int start, int end) {
	int middle = (end + start) / 2;

	vector<T> t_left(2), t_right(2), t_minmax(2);

	if(end == start) {
		t_minmax[0] = vec[start];
		t_minmax[1] = vec[end];
		return t_minmax;
	}
	
	if(end - start == 1) {
		if(vec[start] <= vec[end]) {
			t_minmax[0] = vec[start];
			t_minmax[1] = vec[end];
		} else {
			t_minmax[1] = vec[start];
			t_minmax[0] = vec[end];
		}
		return t_minmax;
	}

	t_left = minmax<T>(vec, start, middle);
	t_right = minmax<T>(vec, middle + 1, end);

	t_minmax[0] = std::min(t_left[0], t_right[0]);
	t_minmax[1] = std::max(t_left[1], t_right[1]);


	return t_minmax;
}