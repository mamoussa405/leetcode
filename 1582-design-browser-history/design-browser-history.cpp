class BrowserHistory {
    vector<string> visPage;
    int curr_page; 
public:
    BrowserHistory(string homepage) {
       visPage.push_back(homepage);
       curr_page = 0;
    }
    
    void visit(string url) {
        vector<string> tmp(visPage.begin(), visPage.begin() + curr_page + 1);

        visPage.resize(tmp.size() + 1);
        for (int i = 0; i < tmp.size(); ++i) 
            visPage[i] = tmp[i];
        visPage[++curr_page] = url;
    }
    
    string back(int steps) {
        curr_page = max(curr_page - steps, 0);
        return visPage[curr_page];
    }
    
    string forward(int steps) {
       curr_page = min(curr_page + steps, (int)visPage.size() - 1);
       return  visPage[curr_page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */