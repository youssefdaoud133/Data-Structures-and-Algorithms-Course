#include <iostream>
using namespace std;

class stack {
    private:
        int arr[1000];
        int size;
    public :
        stack() {
            this->size = 0;
        }
        int top() {
            if (size >0) {
                return arr[size - 1];
            }
            return -1;
        }
        void push(int d) {
            if (size < 1000) {
                arr[size] = d;
                this->size++;
            }
        }
        void pop() {
            if (size > 0) {
                arr[size - 1] = 0;
                this->size--;
            }
        }
        bool is_equal(stack * s2){
            int backup_s2 = s2->size;
            int backup_s1 = this->size;
            if(this->size == s2->size){

                if(this->size ==0){
                    return true;
                }
                else
                {
                    while (size)
                    {
                        if(this->top() == s2->top()){
                            this->size--;
                            s2->size--;
                        }
                        else
                        {
                            this->size = backup_s1;
                            s2->size = backup_s2;
                            return 0;
                        }
                    }
                    this->size = backup_s1;
                    s2->size = backup_s2;
                    return 1;
                }
            }
            else {
                return false;
            }
        }

};

int main()
{
    stack s1;
    s1.push(5);
    s1.push(6);
 
    stack s2;
    s2.push(5);
    s2.push(7);


    cout << s1.is_equal(&s2);
    cout << s1.top();
   
}
