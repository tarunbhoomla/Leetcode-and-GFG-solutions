class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"");
        for(int i=0,fizz=0,buzz=0;i<n;i++){
            fizz++;
            buzz++;
            if(fizz==3 && buzz==5) {
                fizz=0;
                buzz=0;
                ans[i]="FizzBuzz";
            }
            else if(fizz==3) {
                fizz=0;
                ans[i]="Fizz";
            }
            else if(buzz==5) {
                buzz=0;
                ans[i]="Buzz";
            }
            else {
                ans[i]=to_string(i+1);
            }
        }
        return ans;
    }
};