#pragma once
template <typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& n) { head = new Node<T>(n, head); }

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� Ŭ���� �̸��� iterator��� �̸� ��ӵ� �̸����� �ܺο� �����Ѵ�.
	typedef slist_iterator<T> iterator;

	// ��� �����̳� (list, vector ��)�� �����ڴ� �ڽ��� ���۰� ������ ��� ������ ����Ű�� �ݺ��ڸ� �����ϴ� 2���� �Լ��� �����ϱ�� ����Ѵ�.
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};