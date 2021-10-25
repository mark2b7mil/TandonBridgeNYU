#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validityChecker(fstream& fs);

int main(int argc, char const *argv[]) {
	string filename;
	fstream fs;
	bool valid = false;
	cout << "Please enter the file name: ";
	cin >> filename;
	fs.open(filename);
	if(fs.fail()) {
		cout << "File \"" << filename << "\" does not exist" << endl;
		exit(1);
	} else {
		valid = validityChecker(fs);
		if(valid) {
			cout << "The symbols in this file are balanced." << endl;
		 } else {
			cout << "The symbols in this file are not balanced." << endl;
		 }
	}
	fs.close();
	return 0;
}

bool validityChecker(fstream& fs) {
	stack<string> s; 
	string l, r; 
	while(fs >> r) { 
		if(r == "BEGIN" || r == "begin") {
			s.push(r);
		} else if(r == "END;" || r == "end;" || r == "END." || r == "end." || r == "END" ||  r == "end") {
			if(s.empty()) {
				return false;
			} else {
				l = s.top();
				s.pop();
				if(l != "BEGIN" && l != "begin") {
					return false;
				}
			}
		}  else {
			for(const auto& c : r) {
				string y = string(1, c);
				if(y == "(" || y == "{" || y == "[") {
					s.push(y);
				} else if(y == ")" || y == "}" || y == "]") {
					if(s.empty()) {
						return false;
					} else if(y == ")") {
						l = s.top();
						s.pop();
						if(l != "(") {
							return false;
						}
					} else if(y == "}") {
						l = s.top();
						s.pop();
						if(l != "{") {
							return false;
						}
					} else if(y == "]") {
						l = s.top();
						s.pop();
						if(l != "[") {
							return false;
						}
					} else {
						s.pop();
					}
				}
			}
		}
	}
	if(s.empty()) {
		return true;
	} else { 
		return false;
	}
}