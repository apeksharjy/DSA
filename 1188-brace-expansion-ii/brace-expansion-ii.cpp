class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> result;
        bruteForce(expression, result);
        return vector<string>(result.begin(), result.end());
    }
    void bruteForce(string exp, set<string>& result) {
        int l = -1, r = -1;
        for (int i = 0; i < exp.size(); i++) {
            if (exp[i] == '{') l = i;
            if (exp[i] == '}') { r = i; break; }
        }
        if (l == -1) { 
            result.insert(exp);
            return;
        }
        string prefix = exp.substr(0, l);
        string suffix = exp.substr(r + 1);
        string inside = exp.substr(l + 1, r - l - 1);

        stringstream ss(inside);
        string token;
        while (getline(ss, token, ',')) {
            bruteForce(prefix + token + suffix, result);
        }
    }
};
