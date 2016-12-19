/**
*	Version: 1.0
*	Author: Kieran
*	Description: To associate a generic key with a generic value
**/
#pragma once
#include <map>

template<typename K, typename V>
class GenericMap
{
public:
	GenericMap();
	~GenericMap();

	void add(K key, V value);
	void remove(K key);
	bool contains(K key);
	V get(K key);
	std::map<K, V> map;

private:
	
	
};

template<typename K, typename V>
inline GenericMap<K, V>::GenericMap()
{
}

template<typename K, typename V>
inline GenericMap<K, V>::~GenericMap()
{
}

template<typename K, typename V>
inline void GenericMap<K, V>::add(K key, V value)
{
	map[key] = value;
	//std::pair<K, V> pair;
	//pair.first = key;
	//pair.second = value;
	//map.insert(pair);
}

template<typename K, typename V>
inline void GenericMap<K, V>::remove(K key)
{
	map.erase[key];
}

template<typename K, typename V>
inline bool GenericMap<K, V>::contains(K key)
{
	for (auto iter : map) {
		if (iter.first == key) {
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
inline V GenericMap<K, V>::get(K key)
{
	return (V)map[key];
}

