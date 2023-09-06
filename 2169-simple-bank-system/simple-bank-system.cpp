class Bank {
    vector<long long> _balance;
    long long _n;
public:
    Bank(vector<long long>& balance) {
       this->_balance = balance; 
       this->_n  = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
       if (account1 < 1 || account1 > this->_n || account2 < 1 || account2 > this->_n
       || this->_balance[account1 - 1] < money) 
        return false;
        this->_balance[account1 - 1] -= money;
        this->_balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
       if (account < 1 || account > this->_n || money < 0) 
            return false;
        this->_balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
       if (account < 1 || account > this->_n || this->_balance[account - 1] < money) 
            return false;
        this->_balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */