//Justin Li
#include <iostream>
#include <vector>
using namespace std;

//#1
//Pre: n must be an int
//Post: returns vector of all the prime numbers between 2 and n
vector<int> findPrimes(int n){
  vector<int> primes;
  if (n <= 2) { return primes; }//if n <= 2, then has no prime number
  int a = 2;
  bool b[n];
  //setting b[0] and b[1] to false
  for (int i = 0; i < a; i++){
    b[i] = false;
  }
  for (int i = a; i < n; i++){
    b[i] = true;
  }

  //crossing off non-prime numbers
  //only traversing thru n/2
  /*Min limit: n^(1/2), bc all primes afterwards don't
  multiply to new non-primes in the range from a to n.*/
  int n2 = n / 2;
  while (a < n2){
    if (b[a]){
      for (int i = 2 * a; i < n; i += a){
        b[i] = false;
      }
    }
    a++;
  }

  //adding primes to vector "primes"
  for (int i = 0; i < n; i++){
    if (b[i] == true){
      primes.push_back(i);
    }
  }

  return primes;
}

//#2
struct StudentInfo{
  string name;
  int grade;
};

//sorts vector by name in alphebetical order
void sort(vector<StudentInfo> &students){
  for (int i = 0; i < students.size() - 1; i++){
    for (int j = i + 1; j < students.size(); j++){
      int n = 0;
      //while the letter at position (char) n of the names are the same
      while (students[i].name[n] - '0' == students[j].name[n] - '0'){
        n++;
      }
      if (students[i].name[n] - '0' > students[j].name[n] - '0'){
        StudentInfo temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }
}

//finds the max grade
void max(const vector<StudentInfo> &students){
  int max = students[0].grade;
  for (int i = 1; i < students.size(); i++){
    if (max < students[i].grade){
      max = students[i].grade;
    }
  }
  cout << "Max grade: " << max << endl;
}

//finds the min grade
void min(const vector<StudentInfo> &students){
  int min = students[0].grade;
  for (int i = 1; i < students.size(); i++){
    if (min > students[i].grade){
      min = students[i].grade;
    }
  }
  cout << "Min grade: " << min << endl;
}

//finds the avg grades
void avg(const vector<StudentInfo> &students){
  int avg = 0;
  for (StudentInfo s : students){
    avg += s.grade;
  }
  avg /= students.size();
  cout << "Avg grade: " << avg << endl << endl;
}

//prints class roll with grades
void print(const vector<StudentInfo> &students){
  for (StudentInfo s : students){
    cout << s.name << ": " << s.grade << endl;
  }
}

//#3
vector<StudentInfo> testForFailing(vector<StudentInfo> &p){
  vector<StudentInfo> f;
  for (int i = p.size() - 1; i >= 0; i--){
    if (p[i].grade < 60){
      f.push_back(p[i]);
      p.erase(p.begin() + i);
    }
  }
  return f;
}

int main(){
  //testing #1
  vector<int> v = findPrimes(1);
  for (int i : v){
    cout << i << " ";
  }
  cout << endl;

  v = findPrimes(10);
  for (int i : v){
    cout << i << " ";
  }
  cout << endl;

  v = findPrimes(30);
  for (int i : v){
    cout << i << " ";
  }
  cout << endl;

  v = findPrimes(100);
  for (int i : v){
    cout << i << " ";
  }
  cout << endl;

  v = findPrimes(300);
  for (int i : v){
    cout << i << " ";
  }
  cout << endl << endl;

  //testing #2
  //initializing vector of 4 StudentInfos
  vector<StudentInfo> students(4);
  for (int i = 0; i < students.size(); i++){
    cout << "Type in a name:" << endl;
    cin >> students[i].name;
    cout << "Type in a grade (int):" << endl;
    cin >> students[i].grade;
  }
  cout << endl;

  sort(students);
  max(students);
  min(students);
  avg(students);
  print(students);

  //testing #3
  vector<StudentInfo> failures = testForFailing(students);
  sort(students);
  sort(failures);

  //printing class rolls of passing & failing students with grades
  cout << "\nPassing students:\n";
  print(students);
  cout << "\nFailing students:\n";
  print(failures);

  return 0;
}
