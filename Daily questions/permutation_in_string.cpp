if(s1.length()>s2.length()){
    return false;
}
vector<int>freq1(26,0);
vector<int>freq2(26,0);
for(char c:s1){
    freq1[c-'a']++;
}
int windowsize=s1.length();
for(int i=0;i<windowsze;i++){
    freq2[s2[i]-'a'];
}
if(freq1==freq2){
    return true;
}

for(int right=windosize;right<s2.size();right++){
    freq2[s2[right]-'a']++;
    int left=right-windowsize;
    freq2[s2[left]-'a']--;
    if(freq1==fre2){
        return true;
 
    }
    return false;
}