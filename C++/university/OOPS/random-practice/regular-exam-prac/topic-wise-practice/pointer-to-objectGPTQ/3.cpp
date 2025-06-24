#include <iostream>
using namespace std;

class Movie {
  string title, rating;

public:
  Movie(string t, string r) : title(t), rating(r) {}
  void printDetails() {
    cout << "Movie Title: " << title << ", Ratings: " << rating << endl;
  }
};

int main() {
  Movie *ptr = new Movie("tur mur tu", "baaaaaaddddddd");
  ptr->printDetails();

  return 0;
}