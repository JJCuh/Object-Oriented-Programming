//Justin Li

#include <iostream>
#include <vector>
using namespace std;

//#1
//a)
/*
class Figure {
  public:
  void draw(){
    cout << "Function draw() is being called by this figure.\n";
  }

  void erase(){
    cout << "Function erase() is being called by this figure.\n";
  }

  void center(){
    cout << "Function center() is being called by this figure.\n";
    erase();
    draw();
  }

};

class Rectangle : public Figure {
  public:
  void draw(){
    cout << "Function draw() is being called by this rectangle.\n";
  }

  void erase(){
    cout << "Function erase() is being called by this rectangle.\n";
  }

  void center(){
    cout << "Function center() is being called by this rectangle.\n";
    erase();
    draw();
  }

};

class Triangle: public Figure {
  public:
  void draw(){
    cout << "Function draw() is being called by this triangle.\n";
  }

  void erase(){
    cout << "Function erase() is being called by this triangle.\n";
  }

  void center(){
    cout << "Function center() is being called by this triangle.\n";
    erase();
    draw();
  }

};
*/

//b
class Figure {
  public:
  virtual void draw(){
    cout << "Function draw() is being called by this figure.\n";
  }

  virtual void erase(){
    cout << "Function erase() is being called by this figure.\n";
  }

  virtual void center(){
    cout << "Function center() is being called by this figure.\n";
    erase();
    draw();
  }

};

class Rectangle : public Figure{
  public:
  void draw(){
    cout << "Function draw() is being called by this rectangle.\n";
  }

  void erase(){
    cout << "Function erase() is being called by this rectangle.\n";
  }

  void center(){
    cout << "Function center() is being called by this rectangle.\n";
    erase();
    draw();
  }

};

class Triangle: public Figure{
  public:
  void draw(){
    cout << "Function draw() is being called by this triangle.\n";
  }

  void erase(){
    cout << "Function erase() is being called by this triangle.\n";
  }

  void center(){
    cout << "Function center() is being called by this triangle.\n";
    erase();
    draw();
  }

};

//c
/*Diff between a & b
1st one is "redefined" (non-virtual) while 2nd one is "overridden" (virtual)
Also, virtual uses late binding whereas non-virtual doesn't
*/

//#2
class Simulation;
class Organism;
class Doodlebug;
class Ant;

typedef Organism* OrgPtr;
typedef Simulation* SimPtr;

class Simulation {
  friend class Organism;
  friend class Ant;
  friend class Doodlebug;

private:
  OrgPtr grid[20][20];
  int timeStepCount;

public:
  Simulation();
  int genRandInt(int start, int end) const;
  void startGame();
  void timeStep();
  void printGrid() const;

};

class Organism {
protected:
  SimPtr sim;
  int x;
  int y;
  int timeBreed;
  int timeStepCount;

public:
  Organism();
  Organism(SimPtr sim, int x, int y);
  //Pre: x & y are coords of a cell
  //Post: returns a list of valid moves to adjacent cells that are empty
  vector<int> emptyCheck(int x, int y) const;
  bool isValidCoords(int x, int y) const;
  //Pre: x & y are coords of a cell, 1 <= move <= 4
  //1 == up, 2 == down, 3 == left, 4 == right
  //Post: updates x & y based on move
  void getCoords(int &x, int &y, int move) const;
  virtual void move();
  virtual void breed() = 0;
  virtual char getType() = 0;
  virtual bool starve() { return false; }

};

class Ant : public Organism {
public:
  Ant() : Organism(){}
  Ant(SimPtr, int x, int y);
  void breed();
  char getType(){ return 'O'; }

};

class Doodlebug : public Organism {
private:
  int timeStarve;

public:
  Doodlebug() : Organism(), timeStarve(0){}
  Doodlebug(SimPtr sim, int x, int y);
  //Pre: x & y are coords of a cell
  //Post: returns a list of valid moves to adjacent cells that have ants
  vector<int> antCheck(int x, int y) const;
  void breed();
  void move();
  bool starve() { return timeStarve == 3; }
  char getType() { return 'X'; }

};

//Method Definitions:
Simulation::Simulation(){
  srand(time(NULL)); //Randomizes each time program is executed
  timeStepCount = 0;
  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      grid[x][y] = nullptr;
    }
  }
}

int Simulation::genRandInt(int start, int end) const{
  return rand() % (end - start + 1) + start;
}

void Simulation::startGame(){
  int x, y;
  int doodlebugCount = 0;
  int antCount = 0;

  while (doodlebugCount < 5){
    x = genRandInt(0, 19);
    y = genRandInt(0, 19);
    if (grid[x][y] == nullptr){
      grid[x][y] = new Doodlebug(this, x, y);
      doodlebugCount++;
    }
  }

  while (antCount < 100){
    x = genRandInt(0, 19);
    y = genRandInt(0, 19);
    if (grid[x][y] == nullptr){
      grid[x][y] = new Ant(this, x, y);
      antCount++;
    }
  }
}

void Simulation::timeStep(){
  timeStepCount++;

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (grid[x][y] != nullptr){
        if (grid[x][y] -> getType() == 'X'){
          grid[x][y] -> move();
        }
      }
    }
  }

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (grid[x][y] != nullptr){
        if (grid[x][y] -> getType() == 'O'){
          grid[x][y] -> move();
        }
      }
    }
  }

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (grid[x][y] != nullptr){
        grid[x][y] -> breed();
        if (grid[x][y] -> getType() == 'X'){
          if (grid[x][y] -> starve()){
            delete grid[x][y];
            grid[x][y] = nullptr;
          }
        }
      }
    }
  }
}

void Simulation::printGrid() const{
  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (grid[x][y] == nullptr){
        cout << '-';
      }
      else {
        cout << grid[x][y] -> getType();
      }
    }
    cout << endl;
  }
}

Organism::Organism(){
  sim = nullptr;
  x = 0;
  y = 0;
  timeBreed = 0;
  timeStepCount = 0;
}

Organism::Organism(SimPtr sim, int x, int y){
  this -> sim = sim;
  this -> x = x;
  this -> y = y;
  timeBreed = 0;
  timeStepCount = sim -> timeStepCount;
}

vector<int> Organism::emptyCheck(int x, int y) const{
  vector<int> emptyCells;
  int tempX, tempY;
  for (int move = 1; move <= 4; move++){
    tempX = x;
    tempY = y;
    getCoords(tempX, tempY, move);
    if (isValidCoords(tempX, tempY)){
      if (sim -> grid[tempX][tempY] == nullptr){
        emptyCells.push_back(move);
      }
    }
  }
  return emptyCells;
}

bool Organism::isValidCoords(int x, int y) const{
  return (x >= 0 && x < 20 && y >= 0 && y < 20);
}

//1 == up, 2 == down, 3 == left, 4 == right
void Organism::getCoords(int &x, int &y, int move) const{
  switch (move){
    case 1:
      x--;
      break;
    case 2:
      x++;
      break;
    case 3:
      y--;
      break;
    case 4:
      y++;
      break;
  }
}

void Organism::move(){
  if (timeStepCount < sim -> timeStepCount){
    timeStepCount++;
    timeBreed++;
    int randMove = sim -> genRandInt(1, 4);
    int newX = x;
    int newY = y;
    getCoords(newX, newY, randMove);
    if (isValidCoords(newX, newY)){
      if (sim -> grid[newX][newY] == nullptr){
        sim -> grid[x][y] = nullptr;
        sim -> grid[newX][newY] = this;
        x = newX;
        y = newY;
      }
    }
  }
}

Doodlebug::Doodlebug(SimPtr sim, int x, int y) : Organism(sim, x, y){
  timeStarve = 0;
}

vector<int> Doodlebug::antCheck(int x, int y) const{
  vector<int> ants;
  int tempX, tempY;
  for (int move = 1; move <= 4; move++){
    tempX = x;
    tempY = y;
    getCoords(tempX, tempY, move);
    if (isValidCoords(tempX, tempY)){
      if (sim -> grid[tempX][tempY] != nullptr){
        if (sim -> grid[tempX][tempY] -> getType() == 'O'){
          ants.push_back(move);
        }
      }
    }
  }
  return ants;
}

void Doodlebug::move(){
  if (timeStepCount < sim -> timeStepCount){
    vector<int> ants = antCheck(x, y);
    if (ants.size() == 0){
      Organism::move();
      timeStarve++;
    }
    else {
      timeStepCount++;
      timeBreed++;
      timeStarve = 0;
      int randMove = ants[sim -> genRandInt(0, ants.size() - 1)];
      int antX = x;
      int antY = y;
      getCoords(antX, antY, randMove);
        delete sim -> grid[antX][antY];
        sim -> grid[antX][antY] = this;
        sim -> grid[x][y] = nullptr;
        x = antX;
        y = antY;
    }
  }
}

void Doodlebug::breed(){
  if (timeBreed == 8){
    vector<int> moves = emptyCheck(x, y);
    if (moves.size() > 0){
      int randMove = moves[sim -> genRandInt(0, moves.size() - 1)];
      int newX = x;
      int newY = y;
      getCoords(newX, newY, randMove);
      sim -> grid[newX][newY] = new Doodlebug(sim, newX, newY);
    }
    timeBreed = 0;
  }
}

Ant::Ant(SimPtr sim, int x, int y) : Organism(sim, x, y){}

void Ant::breed(){
  if (timeBreed == 3){
    vector<int> moves = emptyCheck(x, y);
    if (moves.size() > 0){
      int randMove = moves[sim -> genRandInt(0, moves.size() - 1)];
      int newX = x;
      int newY = y;
      getCoords(newX, newY, randMove);
      sim -> grid[newX][newY] = new Ant(sim, newX, newY);
    }
    timeBreed = 0;
  }
}

int main(){
//#1
  Triangle tri;
  tri.draw();
  tri.center();

  Rectangle rect;
  rect.draw();
  rect.center();

  cout << endl;

//#2
  char userInput;
  Simulation s;

  cout << "Welcome to Doodlebugs vs. Ants Simulator!" << endl;
  cout << "Press enter to start the game, and type anything else to end it." << endl;

  cin.get(userInput);
  if (userInput != '\n'){
    cout << "The Program has ended." << endl;
    exit(0);
  }

  s.startGame();

  cout << "This is the randomly generated game board:" << endl << endl;
  s.printGrid();
  cout << endl;

  cout << "Press enter to pass a timestep, and type anything else to quit:" << endl;
  cin.get(userInput);

  while (userInput == '\n'){
    s.timeStep();
    s.printGrid();
    cout << endl;
    cout << "Press enter to pass a timestep, and type anything else to quit:" << endl;
    cin.get(userInput);
  }

  cout << "The Program has ended." << endl;

  return 0;
}
