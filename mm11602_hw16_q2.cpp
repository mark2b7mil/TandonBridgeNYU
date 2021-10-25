#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue {
public:
	// Constructor
	Queue() : _sidx {0}, _eidx {0} {}

	T front() const {
		return _data[_sidx];
	}

	T back() const {
		return _data[_eidx];
	}

	// Capacity 
	int size() const {
		return _data.size() - _sidx;
	}

	bool empty() const {
		return _data.empty();
	}

	// Modifiers.
	void push(T t) {
		_data.push_back(t);
		_eidx = _data.size() - 1;
	}

	void pop() {
		if(!_data.empty()) {
			_sidx += 1;
			if(_eidx + 1 == _sidx) {
				_data.clear();
				_sidx = 0;
				_eidx = 0;
			}
		}
	}
	
	void printQueue() {
		for(auto const& e : _data) {
			cout << e << " " << endl;
		}
	}

private:
	int _sidx, _eidx;
	vector<T> _data;
};

int main(int argc, char const *argv[]) {
	// Testing/driver code.
	Queue<int> queue; 

	// Perform a size check.
	std::cout << "Size: " << queue.size() << std::endl << std::endl;


	queue.push(5);
	queue.push(3);
	queue.push(6);
	queue.push(2);

	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;


	queue.pop();
	queue.pop();

	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;
	

	queue.pop();
	queue.pop();

	std::cout << "Size: " << queue.size() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl << std::endl;

	// more testing.
	queue.push(3);
	queue.push(6);
	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;

	// Final set.
	queue.pop();
	queue.pop();

	std::cout << "Size: " << queue.size() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl << std::endl;

	queue.pop();

	return 0;
}