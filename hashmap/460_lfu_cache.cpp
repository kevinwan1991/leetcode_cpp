class LFUCache 
{
public:
    LFUCache(int capacity):_cap(capacity),_size(0),_minFreq(0){}
    
    int get(int key)
    {
        if (!_map.count(key))
            return -1;
        
        int value = _map[key].first;
        int& freq  = _map[key].second;
        
        _mFreq[freq].erase(_mItr[key]);
        ++freq;
        _mFreq[freq].push_back(key);
        _mItr[key] = --_mFreq[freq].end();
        
        if (_mFreq[_minFreq].empty())
            ++_minFreq;
        
        return value;
    }
    
    void put(int key, int value)
    {
        if (_cap <= 0)
            return;
        
        if (get(key) != -1)
        {
            _map[key].first = value;
            return;
        }
        
        if (_size >= _cap)
        {
            int minKey = _mFreq[_minFreq].front();
            _map.erase(minKey);
            _mItr.erase(minKey);
            _mFreq[_minFreq].pop_front();
            --_size;
        }
        
        _map[key] = {value,1};
        _mFreq[1].push_back(key);
        _mItr[key] = --_mFreq[1].end();
        _minFreq = 1;
        ++_size;
    }
    
private:
    int _cap;
    int _size;
    int _minFreq;
    unordered_map<int,pair<int,int>>       _map; //(value, freq)
    unordered_map<int,list<int>::iterator> _mItr; 
    unordered_map<int,list<int>>           _mFreq;    
};
