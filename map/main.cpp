#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

std::map<int,int> countFrecunty(std::vector<int> input) {
    std::map<int,int> count{};
    for (int i = 0; i < input.size(); i++) {
        count[input[i]]++;
    }
    return count;
}

std::map<char, std::vector<std::string>> groupByFirstChar(std::vector<std::string>& input) {
    std::map<char, std::vector<std::string>> res;
    for (const auto& str : input) {
        res[str[0]].push_back(str);
    }
    return res;
}

std::map<std::string ,int> margeMaps(std::map<std::string,int>& m1,std::map<std::string,int>& m2){
    for (const auto& [key,value] : m2) {
        m1[key] +=value;
    }
    return m1;

    }
int firstUniqueChar(const std::string& st) {
    std::map<char,int> res;
    for(int i = 0 ; i < st.size(); i++) {
        res[st[i]]++;
    }
    int count = 0;

    for (int i = 0 ; i < res.size(); i++) {
        count = i;
        if (res[st[i]] == 1) break;
    }
    return count;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& vec) {
    std::map<std::string , std::vector<std::string>> res;
    for (auto& str : vec) {
        std::string newStr = str;
        std::sort(str.begin(), str.end());
        res[str].push_back(newStr);
    }
    std::vector<std::vector<std::string>> anagrams;
    for (const auto& [key,group] : res) {
        anagrams.push_back(group);
    }
    return anagrams;
}

std::vector<int> KFrequent(std::vector<int>& numers , int k) {
    std::map<int,int> freq;
    for (int i = 0 ; i < numers.size(); i++) {
        freq[numers[i]]++;
    }
    std::vector<std::pair<int,int>> res(freq.begin(), freq.end());

    std::sort(res.begin(), res.end(),[] (const auto& a, const auto& b){
        return a.second > b.second;
    });
    std::vector<int> result;
    for (int i = 0 ; i < k && i < res.size(); i++) {
        result.push_back(res[i].first);
    }
    return result;
}

bool isIsomorphic(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;

    std::map<char, char> s_to_t;
    std::map<char, char> t_to_s;

    for (size_t i = 0; i < s.size(); i++) {
        char c1 = s[i];
        char c2 = t[i];


        if (s_to_t.count(c1)) {
            // но оно не совпадает — плохо
            if (s_to_t[c1] != c2) return false;
        } else {
            s_to_t[c1] = c2;
        }
        if (t_to_s.count(c2)) {
            if (t_to_s[c2] != c1) return false;
        } else {
            t_to_s[c2] = c1;
        }
    }

    return true;
}

std::vector<int> arrayRankTransform(std::vector<int>& numbers) {
    std::map<int,int> res;
    for (int& x : numbers) {
        res[x] = 0;
    }
    int curr = 1;
    for (auto& [key,value] : res) {
        value = curr++;
    }
    std::vector<int> result;
    result.reserve(numbers.size());
    for (int& x : numbers) {
        result.push_back(res[x]);
    }
    return result;
}

int rangeSumMap(std::map<int,int>& num , int l , int r) {
    auto it_left = num.lower_bound(l);
    auto it_right = num.upper_bound(r);
    int sum = 0;
    for (auto it = it_left ; it != it_right; it++) {
        sum += it->second;
    }
    return sum;
}

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

template<typename K, typename V>
class BidirectionalMap {
private:
    std::map<K,V> keyToValue;
    std::map<V,K> valueToKey;

public:
    void insert(const K& key, const V& value) {

        if (keyToValue.count(key)) {
            valueToKey.erase(keyToValue[key]);
        }
        if (valueToKey.count(value)) {
            keyToValue.erase(valueToKey[value]);
        }

        keyToValue[key] = value;
        valueToKey[value] = key;
    }

    V getByKey(const K& key) const {
        auto it = keyToValue.find(key);
        if (it == keyToValue.end()) throw std::runtime_error("Key not found");
        return it->second;
    }


    K getByValue(const V& value) const {
        auto it = valueToKey.find(value);
        if (it == valueToKey.end()) throw std::runtime_error("Value not found");
        return it->second;
    }


    void removeByKey(const K& key) {
        auto it = keyToValue.find(key);
        if (it != keyToValue.end()) {
            V value = it->second;
            keyToValue.erase(it);
            valueToKey.erase(value);
        }
    }

    void removeByValue(const V& value) {
        auto it = valueToKey.find(value);
        if (it != valueToKey.end()) {
            K key = it->second;
            valueToKey.erase(it);
            keyToValue.erase(key);
        }
    }
};

std::string normalize(std::string& s) {
    std::string result;
    for (char& c : s) {
        if (std::isalnum(c)) {
            char x = tolower(c);
            result += x;
        }
    }
    return result;
}

std::string mostFrequentWord(std::string& text) {
    std::map<std::string,int> freq;
    std::istringstream ss(text);
    std::string word;
    while (ss >> word) {
        word = normalize(word);
        freq[word]++;
    }
    int max = 0;
    std::string mostFreqWord;
    for (auto& [key,value] : freq) {
        if (value > max) {
            max = value;
            mostFreqWord = key;
        }
    }
    return mostFreqWord;

}

int removeInfrequent(std::map<std::string, int>& freq, int threshold) {
    int removedCount = 0;

    for (auto it = freq.begin(); it != freq.end(); ) {
        if (it->second < threshold) {
            it = freq.erase(it);
            removedCount++;
        } else {
            ++it;
        }
    }

    return removedCount;
}



int main() {
    //1

    // std::vector<int> input{4,5,2,3,6,5,2,5,4,5,2,5,4,5,4};
    // std::map<int,int> count = countFrecunty(input);
    // for (const auto& [key, value] : count) {
    //     std::cout << key << " " << value << std::endl;
    // }
    //2

    // std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    // auto result = groupByFirstChar(words);
    //
    // for (const auto& [key, vec] : result) {
    //     std::cout << key << ": ";
    //     for (const auto& s : vec) std::cout << s << " ";
    //     std::cout << "\n";
    // }

    //3

    // std::map<std::string, int> map1 = {{"ab", 1}, {"b", 2}, {"c", 3}};
    // std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
    // auto result = margeMaps(map1, map2);
    // for (const auto& [key,value] : result) {
    //     std::cout << key << ":" << value << std::endl;
    // }
    // return 0;

    //4

    // std::string s = "leetcode";
    // std::cout << firstUniqueChar(s) << '\n';  // 0 ('l')
    //
    // std::string s2 = "loveleetcode";
    // std::cout << firstUniqueChar(s2) << '\n';  // 2 ('v')

    //5

    // std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // auto result = groupAnagrams(words);
    // for (auto& group : result) {
    //     for (auto& st : group) {
    //         std::cout << st << " ";
    //     }
    //     std:: cout << std::endl;
    // }
    //// result: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]

    //6

    // std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    // auto result = KFrequent(nums, 2);
    //
    // for (int& a : result) {
    //     std::cout << a << "" << std::endl;
    // }
    // // result: {1, 2}

    //7

    // std::cout << isIsomorphic("egg", "add") << '\n';     // 1 (true)
    // std::cout << isIsomorphic("foo", "bar") << '\n';     // 0 (false)
    // std::cout << isIsomorphic("paper", "title") << '\n'; // 1 (true)

    //8

    // std::vector<int> arr = {40, 10, 20, 30};
    // auto result = arrayRankTransform(arr);
    // // result: {4, 1, 2, 3}
    //
    // std::vector<int> arr2 = {100, 100, 100};
    // auto result2 = arrayRankTransform(arr2);
    // for (int& x : result2) {
    //     std::cout << x << std::endl;
    // }
    // // result2: {1, 1, 1}

    //9

    // std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
    // std::cout << rangeSumMap(m, 3, 7) << '\n';  // 90 (20 + 30 + 40)
    // std::cout << rangeSumMap(m, 2, 4) << '\n';  // 20 (только ключ 3)

    //10

    // BidirectionalMap<int, std::string> bm;
    // bm.insert(1, "one");
    // bm.insert(2, "two");
    // std::cout << bm.getByKey(1) << '\n';      // "one"
    // std::cout << bm.getByValue("two") << '\n'; // 2

    //11

    // std::string text = "Bob hit a ball, the Hit BALL flew far after it was HIT.";
    // std::cout << mostFrequentWord(text) << '\n';  // "hit"

    //12

    // std::map<std::string, int> freq = {{"apple", 5}, {"banana", 2}, {"cherry", 8}, {"date", 1}};
    // int removed = removeInfrequent(freq, 3);
    // std::cout << removed << '\n';  // 2:
    // // freq теперь содержит: {{"apple", 5}, {"cherry", 8}}



}
