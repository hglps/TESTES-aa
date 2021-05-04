#include <iostream>
#include <vector>
using namespace std;

int binSearchItem(vector<int> &a, int start, int end, int num)
{
    if(end >= start)
    {
        int n = start +(end - start) / 2;
        if(a[n] == num) return n;
        if(a[n] > num) return sb(a, start, n-1, num);
        if(a[n] < num) return sb(a,n + 1, end, num);
    }
    return -1;

}
int main()
{
  vector<int> array;
  int k, search, i;
  for(i=0; i<10; i++)
  {
    array.push_back(i);
  }
  while(true){
    cout << "Press -1 to exit.\n";
    cout << "To search: ";
    cin >> search;
    
    if(search == -1) break;
    cout << "POSIÇÃO NO ARRAY É = " << binSearchItem(array, 0, i-1, search) << "\n";
  }
  return 0;
}
