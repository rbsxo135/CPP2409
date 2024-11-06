#include <vector>
#include <iostream>
using namespace std;

class Movie{
private:
    string name;
    double rating;
public:
    Movie(string name, double rating){
        this->name = name;
        this->rating = rating;
    }
    void Print(){
        cout << this->name << ": " << this->rating << endl;
    }
};

int main(){
    vector<Movie> v;

    v.push_back(Movie("terminator", 9.7));
    v.push_back(Movie("gone with the wind", 9.6));
    v.push_back(Movie("titiic", 9.9));

    for(auto& e : v){
        e.Print();
    }

    return 0;
}