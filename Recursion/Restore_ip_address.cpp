class Solution {
public:
    vector<string> ans;

    bool isValid(string &part) {

        // Leading zero
        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void solve(int idx, int parts, string &s,
               vector<string> &path) {

        // Successfully formed an IP
        if (parts == 4 && idx == s.size()) {

            string ip = path[0];

            for (int i = 1; i < 4; i++)
                ip += "." + path[i];

            ans.push_back(ip);
            return;
        }

        if (parts == 4 || idx == s.size())
            return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {

            string part = s.substr(idx, len);

            if (!isValid(part))
                continue;

            path.push_back(part);

            solve(idx + len, parts + 1, s, path);

            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> path;

        solve(0, 0, s, path);

        return ans;
    }
};