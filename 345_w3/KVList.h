#include <iostream>
#include <cstring>

#ifndef _H_KVLIST_H_
#define _H_KVLIST_H_

template <typename K, typename V, int N>
class KVList
{
	K k[N];//!<KEY
	V v[N];//!<VALUE
	size_t count;

public:

	KVList()//!<sets variables to safe empty state
	{
		count = 0;
	};

	size_t size() const//!<returns the number of entires in the key - value list
	{
		return count;
	};

	const K& key(int i) const//!<returns an unmodifiable reference to the key of element i in the list
							 //!<
	{
		return k[i];
	};

	const V& value(int i) const //!<returns an unmodifiable reference to the value of element i in the list	
	{
		return v[i];
	};

	KVList& add(const K& kk, const V& vv) //!<adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
	{
		if (count < N) 
		{
				k[count] = kk;
				v[count] = vv;
			count++;
		}
		return *this;
		
	};

	int find(const K& kk) const//!<returns the index of the first element in the list with a key equal to k - defaults to 0
	{
		for (int i = 0; i < count; i++) 
		{
			if (k[i] == kk)
			{
				return i;
			}
		}
		return 0;
	};

	KVList& replace(int i, const K& kk, const V& vv) //!<replaces element i in the list with the key and value received and returns a reference to the current object
	{
	 	if(i < count)
		{
			k[i] = kk;
			v[i] = vv;
		}
		return *this;
	};

};
#endif // !_H_KVLIST_H_


