class Solution {
  private:
  void number(int i,int a)
  {
    if(i>a) return ;
    cout << i << endl;
    number(i+1,a);
  }
  public:
    void printNumbers(int n) {
        // Your code goes here
        number(1,n);
    }
};