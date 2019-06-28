#pragma once
template <typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& n) { head = new Node<T>(n, head); }

	// 모든 컨테이너 제작자는 자신의 반복자 클래스 이름을 iterator라는 미리 약속된 이름으로 외부에 노출한다.
	typedef slist_iterator<T> iterator;

	// 모든 컨테이너 (list, vector 등)의 설계자는 자신의 시작과 마지막 요소 다음을 가르키는 반복자를 리턴하는 2개의 함수를 제공하기로 약속한다.
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};