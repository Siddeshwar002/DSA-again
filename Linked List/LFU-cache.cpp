#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
private:
    int capacity;
    int minFreq;
    
    // key -> {value, freq}
    unordered_map<int, pair<int, int>> data;
    
    // freq -> {list of nodes which are present at that frequency}
    unordered_map<int, list<int>> freqData;
    
    // key -> {adddress of the node}
    unordered_map<int, list<int>::iterator> keyAddress;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key)
    {
        if (data.find(key) == data.end())
            return -1;

        auto cur = data[key];
        int value = cur.first;
        auto addr = keyAddress[key];
        int curFreq = cur.second;

        freqData[curFreq].erase(addr);
        data[key] = {value, curFreq + 1};
        freqData[curFreq + 1].push_front(key);
        keyAddress[key] = freqData[curFreq + 1].begin();

        if (freqData[curFreq].empty())
        {
            freqData.erase(curFreq);
            if (minFreq == curFreq)
                minFreq++;
        }
        return value;
    }

    void put(int key, int value)
    {
        if (data.find(key) != data.end())
        {

            auto cur = data[key];
            auto addr = keyAddress[key];
            // int value = cur.first;
            int curFreq = cur.second;
            freqData[curFreq].erase(addr);
            data[key] = {value, curFreq + 1};
            freqData[curFreq + 1].push_front(key);
            keyAddress[key] = freqData[curFreq + 1].begin();

            if (freqData[curFreq].empty())
            {
                freqData.erase(curFreq);
                if (minFreq == curFreq)
                    minFreq++;
            }
        }
        else
        {
            if (data.size() >= capacity)
            {
                int evictKey = freqData[minFreq].back();
                freqData[minFreq].pop_back();
                data.erase(evictKey);
                keyAddress.erase(evictKey);
            }

            data[key] = {value, 1};
            freqData[1].push_front(key);
            keyAddress[key] = freqData[1].begin();
            minFreq = 1;
        }
    }
};