#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <list>
#include <forward_list>
#include <iterator>
#include <algorithm>


template<typename K, typename V>
struct SPHashTable {
    typedef std::pair<K,V> Item;
    typedef std::pair<const K,V> ConstKeyItem;
    typedef std::forward_list<Item> Bucket;
    typedef std::vector<Bucket> Table;

    typedef typename Table::iterator table_iterator;
    typedef typename Bucket::iterator bucket_iterator;


    Table table;
    const float MAX_LOAD_FACTOR = 0.7f;
    int count = 0;

    SPHashTable() {
        table.resize(16);
    }
    struct iterator {
    private:
        table_iterator bucket;
        bucket_iterator element;
        table_iterator end;
        void findNextValid() {
            while(bucket != end &&  element == bucket->end()) {
                ++bucket;
                if(bucket != end) {
                    element = bucket->begin();
                }
                
            }
        }
        iterator(table_iterator b, bucket_iterator e, table_iterator end) 
                : bucket(b), element(e), end(end){}
    public:
        std::pair<const K, V> &operator*() {
            return reinterpret_cast<std::pair<const K, V>&>(*element);
        }

        std::pair<const K, V> *operator->() {
            return &(reinterpret_cast<std::pair<const K, V>&>(*element));
        }

        iterator &operator++() {
            ++element;
            findNextValid();
            return *this;
        }
        iterator operator++(int) {
            iterator copy(*this);
            ++element;
           findNextValid();
            return copy;
        }
        bool operator==(const iterator &other) const {
            return bucket == other.bucket && element == other.element;
        }
        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }
    };
    

    iterator begin() {
        return iterator(table.begin(), table.front().begin(), table.end());
    }

    iterator end() {
        return iterator(table.end(), table.back().end(), table.end());
    }

    int getIndex(const K &key)const {
        return std::hash<K>()(key) % table.size();
    }

    table_iterator getBucket(const K &key) const {
        return table.begin() + getIndex(key);
    }

    float getLoadFactor() const {
        return float(count) / float(table.size()) ;
    }

    bool shouldResize() const {
        return getLoadFactor() > MAX_LOAD_FACTOR; 
    }

    void resize() {
        Table oldTable(table.size()*2);
        oldTable.swap(this->table);
        count = 0;

        for (table_iterator bucket = oldTable.begin();bucket != oldTable.end(); ++bucket ) {
            for (bucket_iterator element = bucket.begin();element != bucket.end(); ++element ) {
                insert(element->first, element->second); 
            }  
        }
        
        
    }


    void insert(const K &key, const V &value) {
        if(shouldResize()) {
            resize();
        }
        table_iterator  bucket = getBucket(key);
        for (bucket_iterator it =  bucket->begin(); it !=  bucket->end(); ++it) {
            if(it->first == key) {
                it->second = value;
                return;
            }
        }
         bucket->push_front(Item(key, value));
        ++count;
        
    }

    void erase(const K &key) {
        table_iterator bucket = getBucket(key);
         for (bucket_iterator it = bucket->before_begin(); it != bucket->end(); ) {
             bucket_iterator prev= it++;
            if(it != bucket->end() && it->first  == key ) {
                bucket.erase_after(prev); 

                return;
            }
        }
    }


    int size() const {
        return count;
    }


    V &operator[](const K &key) {  
        table_iterator bucket = getBucket(key);
        for (bucket_iterator it = bucket->begin(); it != bucket->end(); ++it) {
            if(it->first == key) {
               return it->second;
            }
        }
        if(shouldResize()) {
            resize();
        }
        bucket->push_front(Item(key, V()));
        ++count;
        return bucket->front().second;

    }
};

int main() {
    SPHashTable<std::string, int> t1;
    t1.insert("Ivan", 24);
    std::cout << t1.size();
    return 0;
}

