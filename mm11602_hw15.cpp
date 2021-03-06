#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


template <class T, class S> 
class Pair {
public:
	T first;
	S second;
};


class Employee {
private:
	int _id, _hours;
	double _payrate;
	string _name;
	
public:

	Employee(int id = 0, double payrate = 0.00, string name = "", int hours = 0) : _id{id}, _payrate{payrate}, _name{name}, _hours{hours} {}

	void increase_hours(int hours) {
		this->_hours += hours;
	}

	double get_pay() const { 
		return (this->_payrate * this->_hours); 
	}

	int get_id() const { 
		return _id;
	}

	string get_name() const { 
		return _name; 
	}
};

template <class T>
class LList; 

template <class T>
class LListNode {
	T data;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
	LListNode<T>* get_next() { return next; }

	T* get_data() { return &data; }

	friend class LList<T>;
};

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	
public:
	LList();
	~LList();
	LList(const LList<T>& rhs);
	LList<T>& operator=(const LList<T>& rhs);

	void clear() { while (!isEmpty()) pop_front(); }
	void push_back(const T& data) { tail->prev = new LListNode<T>(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
	LListNode<T>* get_front() { return head; }

	T pop_front();
	bool isEmpty() { return head->next == tail; }
};

void trim(string& input); 

bool open_file(fstream& file_stream, string filename); // Open a filestream

template <class T>
void swap(T& a, T& b);


void sort(LListNode<Employee>* start);

int main(int argc, char const *argv[]) {
	fstream employee_input, payroll_input;
	string filename1, filename2;
	cout << "Please enter employee list filename with extension: ";
	cin >> filename1;
	cout << "Please enter payroll list filename with extension: ";
	cin >> filename2;

	if(!open_file(employee_input, filename1) || !open_file(payroll_input, filename2)) {
		exit(1); // Failure
	}

	int id, hours;
	double payrate;
	string name;

	// Create a doubly linked list of all employees.
	LList<Employee> employees;
	// Payroll list vector
	vector<Pair<int, int>> payroll;

	while(!employee_input.eof()) {
		employee_input >> id >> payrate;
		getline(employee_input, name);
		trim(name);
		employees.push_back({id, payrate, name}); // Add a new employee to list. 
	}

	while(!payroll_input.eof()) {
		payroll_input >> id >> hours;
		payroll.push_back({id, hours}); // Add the hours to the vector
	}

	employee_input.close();
	payroll_input.close();

	// Start looping through list of employees.
	LListNode<Employee>* curr = employees.get_front()->get_next(); 
	while(curr->get_next() != nullptr) {

		for(const auto& p : payroll) {
			if(curr->get_data()->get_id() == p.first) {
				curr->get_data()->increase_hours(p.second);
			}
		}
		curr = curr->get_next(); 
	}


	sort(employees.get_front()->get_next());


	curr = employees.get_front()->get_next();
	while(curr->get_next() != nullptr) {
		cout << curr->get_data()->get_name() << ", $" << (curr->get_data()->get_pay()) << endl;
		curr = curr->get_next(); // Go to next node in list.
	}

	curr = nullptr;

	return 0;
}

template <class T>
void mySwap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

void sort(LListNode<Employee>* start) {
	bool swapped = false;
	LListNode<Employee> *left, *right = nullptr;

	if(start == nullptr) { 
		return; 
	}

	do {
		swapped = false;
		left = start;
		while(left->get_next() != right) {
			if(left->get_data()->get_pay() < left->get_next()->get_data()->get_pay()) { 
				mySwap(*left->get_data(), *left->get_next()->get_data());
				swapped	= true;
			}
			left = left->get_next();
		}
		right = left;
	} while(swapped);
}

bool open_file(fstream& file_stream, string filename) {
	file_stream.open(filename, std::ios::in);
	if(!file_stream) {
		cout << "Failed to open " << filename << "!" << endl;
		return false;
	}
	return true;
}

void trim(string& input) { 
    if (input.empty()) return;
    while (input.find(" ") == 0 || input.find("\t") == 0)
    {
        input.erase(0, 1);
    }
    auto len = input.size();
    while (input.rfind(" ") == --len || input.rfind("\t") == --len)
    {
        input.erase(len, len + 1);
    }
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	LListNode<T>* ptr = rhs.head->next;
	while (ptr != rhs.tail) {
		push_back(ptr->data);
	}
	return *this;
}

template <class T>
T LList<T>::pop_front() {
	if (tail->prev == head) 
		return T(); 
	T retval = head->next->data;
	LListNode<T>* nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}

template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}

template <class T>
LList<T>::LList(const LList<T>& rhs) {
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
	*this = rhs; 
}

template <class T>
LList<T>::LList() { 
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
}