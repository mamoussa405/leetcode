class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
       int memory_bits = 1;

       while (memory_bits <= memory1 || memory_bits <= memory2)
       {
            if (memory1 >= memory2)
                memory1 -= memory_bits;
            else
                memory2 -= memory_bits;
            ++memory_bits;
       }
       return {memory_bits, memory1, memory2};
    }
};