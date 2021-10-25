#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Type {
	ANT = 1,
	DOODLEBUG = 2
};

class Organism {
public:
	Organism(Type type) : Type{ type }, Breed{ 0 }, RecentlyMoved{ false} {};
	virtual ~Organism() = default; 
	virtual void move() = 0; 
	virtual Type getType() const = 0; 
	virtual bool getMoved() const = 0; 
	virtual void resetMoveState() = 0; 
	virtual void resetBreed() = 0;
	virtual int getBreed() const = 0;
	virtual	int getStarve() const { return 0; };
	virtual void resetStarve() {}; 

protected:
	Type Type; 
	int Breed; 
	bool RecentlyMoved; 
};

class Ant : public Organism {
public:
	Ant() : Organism(Type::ANT) {} 
	void move(); 
	bool getMoved() const;
	void resetMoveState();
	void resetBreed();
	int getBreed() const;
	Type getType() const;
};

class Doodlebug : public Organism {
public:
	Doodlebug() : Organism(Type::DOODLEBUG), _starve{ 0 } {} 
	void move(); 
	bool getMoved() const;
	void resetMoveState();
	void resetBreed();
	int getBreed() const;
	int getStarve() const;
	void resetStarve();
	Type getType() const;

private:
	int _starve;
};
	
class World {
public:
	World(int width, int height, int n, int m) : _width{ width }, _height{ height }, _timestep{ 0 } { 
		_world.resize(width * height, nullptr); 
		placeOrganisms(m, Type::ANT); 
		placeOrganisms(n, Type::DOODLEBUG); 
	}

	~World() { // Clean up the world.
		for(auto& location : _world) {
			if(location != nullptr) {
				delete location;
				location = nullptr;
			}
		}
	}

	void display(int width, int height); // Print out the current-state of the world, taking in the width/height of the world.
	void timeStep(); // Perform one singular time-step in our world.
	void setBugStarveTime(int n);
	void setOrganismBreedTimes(int m, int n);

private:
	int getIndex(int x, int y); // Convert an x/y coordinate into an index for the vector.
	void placeOrganisms(int n, Type type); // Amount and type to place into the world.
	void moveDoodlebugs(); // Move all the doodle-bugs according to rules.
	void moveAnts(); // Move all ants randomly.
	void resetMovementFlags(); // Reset movement flag for everything
	void breedOrganisms(); // Breed all organisms 
	void starveOrganisms(); // Starve/kill off any doodlebugs that don't win the darwin award.

	vector<Organism*> _world; // A single dimensional vector that we simply use our coordinate system to check if it is out of bounds or not.
	int _width, _height;
	int _timestep;
	int _ant_breed, _doodlebug_breed, _doodlebug_starve;
};

int main(int argc, char const* argv[]) {
	srand(time(NULL)); 
	const int W_WIDTH = 20, W_HEIGHT = 20, ANTS = 100, DOODLEBUGS = 5, ANT_BREED = 3, DOODLEBUG_BREED = 8, DOODLEBUG_STARVE = 3; 
	World camelot(W_WIDTH, W_HEIGHT, DOODLEBUGS, ANTS); 
	camelot.setBugStarveTime(DOODLEBUG_STARVE); 
	camelot.setOrganismBreedTimes(ANT_BREED, DOODLEBUG_BREED);
	camelot.display(W_WIDTH, W_HEIGHT);
	cout << "Please hit enter for next time-step, or any other key to exit!" << endl;
	while(cin.get() == '\n') {
		camelot.timeStep();
		camelot.display(W_WIDTH, W_HEIGHT);
		cout << "Please hit enter for next time-step, or any other key and then enter to exit!" << endl;
	}
	return 0;
}

int Ant::getBreed() const {
	return Breed;
}

void Ant::resetBreed() {
	Breed = 0; 
}

void Ant::move() {
	Breed += 1; 
	RecentlyMoved = true;
}

bool Ant::getMoved() const {
	return RecentlyMoved; 
}

Type Ant::getType() const {
	return Type;
}

void Ant::resetMoveState() {
	RecentlyMoved = false;
}

int Doodlebug::getStarve() const {
	return _starve; 
}

void Doodlebug::resetStarve() {
	_starve = 0;
}

int Doodlebug::getBreed() const {
	return Breed;
}

void Doodlebug::resetBreed() {
	Breed = 0;	
}

bool Doodlebug::getMoved() const {
	return RecentlyMoved;
}

void Doodlebug::move() {
	Breed += 1;
	_starve += 1;
	RecentlyMoved = true;
}

Type Doodlebug::getType() const {
	return Type;
}

void Doodlebug::resetMoveState() {
	RecentlyMoved = false;
}

void World::setBugStarveTime(int n) {
	_doodlebug_starve = n;
}

void World::setOrganismBreedTimes(int m, int n) {
	_ant_breed = m;
	_doodlebug_breed = n;
}

void World::breedOrganisms() { 
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			if(_world[getIndex(x, y)] == nullptr) {
				continue;
			}
			bool breed = false;
			std::vector<int> nxy = { x + 1, y, x - 1, y, x, y + 1, x, y - 1 }; // Vector for places to check.
			for (int i = 0, j = 1; i < 8; i += 2, j += 2) { // Loop through the four possibilities.
				if ((nxy[i] < 0) || (nxy[i] > _width) || (nxy[j] < 0) || (nxy[j] >= _height) || breed) {
					continue; // If our spot next to us is out of bounds, check next spot.
				} else if (_world[getIndex(nxy[i], nxy[j])] == nullptr && _world[getIndex(x, y)]->getType() == Type::ANT &&  _world[getIndex(x, y)]->getBreed() >= _ant_breed) {
					_world[getIndex(nxy[i], nxy[j])] = new Ant(); // If that spot is empty, create a new ant in that location.
					_world[getIndex(x, y)]->resetBreed(); // Reset this particular ant back to 0. Doesn't reset if it didn't breed.
					breed = true;
				}  else if (_world[getIndex(nxy[i], nxy[j])] == nullptr && _world[getIndex(x, y)]->getType() == Type::DOODLEBUG &&  _world[getIndex(x, y)]->getBreed() >= _doodlebug_breed) {
					_world[getIndex(nxy[i], nxy[j])] = new Doodlebug();
					_world[getIndex(x, y)]->resetBreed();
					breed = true;
				}
			}
		}
	}
}

void World::resetMovementFlags() {
	for(auto& location : _world) {
		if(location != nullptr) {
			location->resetMoveState(); 
		}
	}
}

void World::moveDoodlebugs() { 
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			int random = rand() % 4; // 0 to 3.
			int delta_x = 0, delta_y = 0;
			if(random == 0) {
				delta_x += 1;
			} else if (random == 1) {
				delta_x -= 1;
			} else if (random == 2) {
				delta_y += 1;
			} else if (random == 3) {
				delta_y -= 1;
			}
			if (_world[getIndex(x, y)] == nullptr) {
				continue;
			}
			bool exists = (_world[getIndex(x, y)]->getType() == Type::DOODLEBUG);
			if(!exists || _world[getIndex(x, y)]->getMoved()) {
				continue;
			}
			std::vector<int> nxy = { x + 1, y, x - 1, y, x, y + 1, x, y - 1 };
			bool ate_something = false;
			for (int i = 0, j = 1; i < 8; i += 2, j += 2) {
				if(ate_something) {
					continue;
				} else if ((nxy[i] < 0) || (nxy[i] > _width) || (nxy[j] < 0) || (nxy[j] >= _height)) {
					continue;
				} else if(_world[getIndex(nxy[i], nxy[j])] == nullptr || _world[getIndex(nxy[i], nxy[j])]->getType() == Type::DOODLEBUG) {
					continue;
				} else if(_world[getIndex(nxy[i], nxy[j])]->getType() == Type::ANT) {
					delete _world[getIndex(nxy[i], nxy[j])]; 
					_world[getIndex(nxy[i], nxy[j])] = _world[getIndex(x, y)]; // Move doodlebug to that specific new position.
					_world[getIndex(x, y)] = nullptr; // Mark old position as nullptr.
					_world[getIndex(nxy[i], nxy[j])]->move();
					_world[getIndex(nxy[i], nxy[j])]->resetStarve(); // Since we ate we reset starving
					ate_something = true;
				}
			}
			if(!ate_something) { // If we have not eaten anything, then we do the following:
				int new_x = x + delta_x;
				int new_y = y + delta_y;
				if ((new_x < 0) || (new_x > _width) || (new_y < 0) || (new_y >= _height)) {
					continue; // Skip to next cell.
				}
				bool next_square = (_world[getIndex(new_x, new_y)] == nullptr);
				if(exists && next_square) {
					_world[getIndex(new_x, new_y)] = _world[getIndex(x, y)];
					_world[getIndex(x, y)] = nullptr;
					_world[getIndex(new_x, new_y)]->move();
				}
			}
		}
	}
}

void World::moveAnts() {
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			int random = rand() % 4; // 0 to 3.
			int delta_x = 0, delta_y = 0;
			if(random == 0) { 
				delta_x += 1;
			} else if (random == 1) {
				delta_x -= 1;
			} else if (random == 2) {
				delta_y += 1;
			} else if (random == 3) {
				delta_y -= 1;
			}
			if (_world[getIndex(x, y)] == nullptr) {
				continue;
			}
			bool exists = (_world[getIndex(x, y)]->getType() == Type::ANT);
			int new_x = x + delta_x;
			int new_y = y + delta_y;
			if ((new_x < 0) || (new_x > _width) || (new_y < 0) || (new_y >= _height) || _world[getIndex(x, y)]->getMoved()) {
				continue; // Skip to next cell.
			}
			bool next_square = (_world[getIndex(new_x, new_y)] == nullptr);
			if (exists && next_square) {
				_world[getIndex(new_x, new_y)] = _world[getIndex(x, y)];
				_world[getIndex(x, y)] = nullptr;
				_world[getIndex(new_x, new_y)]->move();
			}
		}
	}
}

void World::timeStep() {
	_timestep += 1; 
	moveDoodlebugs();
	moveAnts();
	breedOrganisms();
	starveOrganisms();
	resetMovementFlags();
}

void World::starveOrganisms() {
	for(auto& creature : _world) {
		if(creature != nullptr && creature->getType() == Type::DOODLEBUG && creature->getStarve() >= _doodlebug_starve) { 
			delete creature;
			creature = nullptr;
		}
	}
}

void World::placeOrganisms(int n, Type type) {
	while(n) {
		int x = rand() % _width;
		int y = rand() % _height;
		if (_world[getIndex(x, y)] == nullptr) {
			n -= 1;
			if(type == Type::DOODLEBUG) {
				_world[getIndex(x, y)] = new Doodlebug(); 
			} else if(type == Type::ANT) {
				_world[getIndex(x, y)] = new Ant(); 
			}
		}
	}
}

void World::display(int width, int height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (_world[getIndex(x, y)] == nullptr) { 
				cout << '-' << ' '; 
			} else {
				if (_world[getIndex(x, y)]->getType() == Type::ANT) {
					cout << 'o' << ' ';
				} else if (_world[getIndex(x, y)]->getType() == Type::DOODLEBUG) {
					cout << 'X' << ' '; 
				}
			}
		}
		cout << endl;
	}
}

int World::getIndex(int x, int y) {
	return (_width * y) + x; 
}