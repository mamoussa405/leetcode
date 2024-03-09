class WordDictionary {
    private:
        vector<string> _v;
    public:
        WordDictionary() {

        }
        
        void addWord(string word) {
            _v.push_back(word); 
        }
        
        bool search(string word) {
           for (size_t i = 0; i < _v.size(); ++i) 
           {
                if (_v[i].size() != word.size())
                    continue;
                int j;

                j = 0;
                while (j < _v[i].size()) {
                    if (_v[i][j] != word[j] && word[j] != '.')
                        break;
                    ++j;
                }
                if (j == _v[i].size())
                    return true;
           }
           return false;
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */