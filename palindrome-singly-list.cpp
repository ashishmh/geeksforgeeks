// http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	char c;
	Node *next;
	Node(char c) {
		this->c = c;
		this->next = NULL;
	}
};

void checkPalindrome(char* str) {
	// creating a linked list of Node objects from passed array
	Node *head, *ptr, *ptr1;
    head = new Node(str[0]);
    ptr = ptr1 = head;
	for (int i = 1; str[i] != '\0'; i++) {
    	ptr1 = new Node(str[i]);
    	ptr->next = ptr1;
    	ptr = ptr->next;
	}
	// pushing each element of linked list onto stack
	stack<char> stack;
	ptr = head;
	while (ptr != NULL) {
		stack.push(ptr->c);
		ptr = ptr->next;
	}
	// comparing elements of stack and linked list
	ptr = head;
	while (!stack.empty() && ptr != NULL) {
		if (stack.top() != ptr->c) {
			cout<<"string is not a palindrome.."<<endl;
			return;
		}
		stack.pop();
		ptr = ptr->next;
	}
	cout<<"string is palindrome.."<<endl;
}

int main() {
    freopen("input.txt","r",stdin);

	char str[] = "abcba";
	checkPalindrome(str);
	char str1[] = "daddy";
	checkPalindrome(str1);
	return 0;
}