#pragma once
using namespace std;
template <class T>

struct TNode {
	TNode<T>* pNext;
	T val;
};
template <class T>

class TList {
protected:
	TNode<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int pos, len;
public:
	TList() {
		len = 0;
		pFirst = pLast = pCurr = pPrev = pStop = nullptr;
		pos = 0;
	}
	~TList() {
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;

		}
	}
	TList(const TList<T>& l) {

	}

	T GetCurrEl() {
		if (len != 0){
			return (pCurr->val);
		}
	}

	void InsFirst(const T& a) {

		TNode<T>* tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		if (pFirst == pStop) {
			pLast = pFirst = tmp;
		}
		else {
			pFirst = tmp;
		}
			len++;
		}
	
	void DelFirst() {
		if (len != 0) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			delete tmp;
			len--;

		}
	};
	void InsLast(const T& a) {

		TNode<T>* tmp;
		tmp = new TNode<T>;
		tmp->pNext = pStop;
		tmp->val = a;
		if (pLast != pStop) {
			pLast->pNext = tmp;
			pLast = tmp;
		}
		else
		{
			pFirst = pLast = tmp;
		}
		len++;
	}
	void InsCurr(const T& a) {
		if (pCurr == pFirst) {
			InsFirst(a);
		}
		else if (pCurr == pStop) {
			throw "Error InsCurr: Stop";
		}
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp->val = a;
			pPrev->pNext = tmp;
			tmp->pNext = pCurr;
			pCurr = tmp;
			len++;
		}
	}
	void DelCurr() {
		if (pCurr == pFirst) {
			DelFirst();
		}
		else if (pCurr == pStop) {
			throw "Error InsCurr: Stop";
		}
		else {
			TNode<T>* tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			pCurr = pCurr->pNext;
			delete tmp;
			len--;
		}
	}

	void Reset(){
		pCurr = pFirst;
		pPrev = pStop;
}
	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;

	}
	bool IsEnd() {
		return pCurr == pStop;
	}

	void InsInOrder(const T& a) {
		if (pFirst == pStop) InsFirst(a);
		else if (pFirst->val < a) InsFirst(a);
		else if (pLast->val > a) InsLast(a);
		else {
			for (Reset(); !IsEnd(); GoNext()) {
				if (a > pCurr->val) {
					InsCurr(a);
					break;
				}
			}
		}
	}
};