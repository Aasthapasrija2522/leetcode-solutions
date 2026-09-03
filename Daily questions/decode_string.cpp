stack<int>nums;
stack <string>strs;
int num=0;
int curr="";
for(char c:s){
    if(isdigit(c)){
        num=num*10+(c-'0');
    }
    else if(c=='['){
        nums.push(num);
        strs.push(curr);
        num=0;
        curr="";
    }
    else if(c==']'){
        int repeat=nums.top();
        nums.pop();
        int previous=strs.top();
        strs.pop();
        int temp="";
        for(int i=0;i<repeat;i++){
            temp+=curr;

        }
        curr=prev+temp;
    }
    else{
        curr+=c;
    }
}
return curr;