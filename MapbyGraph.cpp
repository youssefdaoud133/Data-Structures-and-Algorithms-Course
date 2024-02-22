#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

// Function to search if a number exists in the vector
bool searchNumber(const std::vector<int>& vec, int num) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == num) {
            return true; // Number found
        }
    }
    return false; // Number not found
}

vector<int> vec;


struct Country {
    string CountryName;
    int index;
    list<Country *> Countries ;
    // Constructor
    Country(const string& name = "", int idx = 0) : CountryName(name), index(idx) {}

    
 
};

class Graph {
private:
    int v;
    Country** ArrayOfCountries;
public:
    Graph(int v) {
        this->v = v;
        ArrayOfCountries = new Country * [v];
    }

    void AddEdge(Country* c1, Country* c2) {
        this->ArrayOfCountries[c1->index] = c1;
        this->ArrayOfCountries[c2->index] = c2;
        c1->Countries.push_back(c2);
        c2->Countries.push_back(c1);
    }
    void test() {
        cout << this->ArrayOfCountries[0]->CountryName << endl;
        std::cout << "List of countries:" << std::endl;
        for (auto it = this->ArrayOfCountries[0]->Countries.begin(); it != this->ArrayOfCountries[0]->Countries.end(); ++it) {
            std::cout << (*it)->CountryName << std::endl;
        }

        // Don't forget to deallocate memory for dynamically allocated countries
        for (auto it = this->ArrayOfCountries[0]->Countries.begin(); it != this->ArrayOfCountries[0]->Countries.end(); ++it) {
            delete* it;
        }
    }
    void PrintAllMap() {
        for (int i = 0; i < this->v; i++) {
            cout << "Countries that are related to " << ArrayOfCountries[i]->CountryName << "{";
            for (auto it = this->ArrayOfCountries[i]->Countries.begin(); it != this->ArrayOfCountries[i]->Countries.end(); ++it) {
                std::cout << (*it)->CountryName << " , ";
            }   
            cout << " }" << endl;
        }
    }

    string Get_Path(Country * CS , Country* CD) {
        vec.push_back(CS->index);
        string path = "";
        if(CS->CountryName == CD->CountryName){
            path += CS->CountryName;
            return path;
        }
        for (auto it = this->ArrayOfCountries[CS->index]->Countries.begin(); it != this->ArrayOfCountries[CS->index]->Countries.end(); ++it) {
            if(searchNumber(vec , (*it) ->index)){
                continue;
            }
            string che = Get_Path((*it), CD);
            if(che.length() > 0) {
                path = CS->CountryName + " -> " + che;
                break;
            }
        }
        return path;


    }

};

int main()
{
    Graph Map(6);
    Country* Italy = new Country("Italy", 0);
    Country* Egypt = new Country("Egypt", 1);
    Country* Libya = new Country("Libya",2);
    Country* Sudan = new Country("Sudan", 3);
    Country* SouthAfrica = new Country("SouthAfrica", 4);
    Country* Tunisia = new Country("Tunisia", 5);

    Map.AddEdge(Italy, Egypt);
    Map.AddEdge(Italy, Libya);
    Map.AddEdge(Tunisia, Libya);
    Map.AddEdge(Egypt, Libya);
    Map.AddEdge(Sudan, Egypt);
    Map.AddEdge(Sudan, SouthAfrica);
    //Map.PrintAllMap();
    //Map.test();
    cout << Map.Get_Path(Tunisia, Italy);


   
}