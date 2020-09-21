#include<iostream>
#include<math.h>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int result;
	int power;
	void utilityFunc(ListNode* node) {
		if (!node) {
			return;
		}
		utilityFunc(node->next);
		this->result += (node->val * pow(2, this->power));
		this->power++;
	}
	int getDecimalValue(ListNode* head) {
		if (!head) {
			return 0;
		}
		
		this->result = 0;
		this->power = 0;
		utilityFunc(head);
		return this->result;
	}
};