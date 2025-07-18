class Solution {
  private:
  void number(int i, int a)
  {
    if(a<i) return;
    cout << a <<endl;
number(i,a-1);
  }
  public:
    void printNumbers(int n) {
        // Your code goes here
        number(1,n);
    }
};