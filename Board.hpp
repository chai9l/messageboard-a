#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel {

    class Board {
        
        public:
        // Attributes:
        unsigned int row;
        unsigned int coll;
        vector<vector<char>> board;
        
        //Given Functions:
        void post(unsigned int,unsigned int,Direction,string const&);
        string read(unsigned int,unsigned int,Direction,unsigned int);
        void show();

        //Getters & Setters:
        // const int getRow() {return this->row;}
        // void setRow(unsigned int new_row) {this->row = new_row;}
        // const int getColl() {return this->coll;}
        // void setColl(unsigned int new_coll) {this->coll = new_coll;}

    };
};