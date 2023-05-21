#include <iostream>
using namespace std;

void RANDOM_NUMBERS(int A[], int n, int min, int max);
void insertion_sort(int A[], int n);
void selection_sort(int A[], int n);
void bubble_sort(int A[], int n);
void shaker_sort(int A[], int n);
//void merging(int low, int mid, int high);
//void sort(int low, int high);
void shell_sort(int A[], int n);
void build_heap(int A[], int n);
void  heapify(int A[], int n, int i);
void heap_sort(int A[], int n);

void linear_search(int A[], int n, int num);
void bsi(int A[], int num);
int bsrec(int A[], int n, int low, int high, int num);
int exponential(int A[], int n, int num);
int min(int a, int b);

void push(int stackarray[], int num);
void pop(int stackarray[]);
void showtop(int stackarray[]);

void Enqueue(int queue[], int num);
void Dequeue(int queue[]);
void Display(int queue[]);

void dispay(struct Node* head);
void initNode(struct Node* head, int n);
void AddNode(struct Node* head, int n);
void insertFront(struct Node** head, int n);
struct Node* searchNode(struct Node* head, int n);


//Random Numbers' values
const int n = 10;
const int mn = 0;
const int mx = 100;
int A[n];
const int range = mx - mn + 1;

//for STACK------
int stack[n];
int top = -1;
//for STACK------

//forQUEUE-------
int myqueue[n * 2];
int head = -1;
int tail = -1;
//forQUEUE-------

//for LINKED LIST---------
struct Node 
{
	int data;
	Node* next;
};
//for LINKED LIST---------


int main()
{
	srand(time(0));
	RANDOM_NUMBERS(A, n, mn, mx);
	cout << "RANDOM NUMBERS" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;


	insertion_sort(A, n);
	cout << "INSERTION SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	selection_sort(A, n);
	cout << "SELECTION SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;


	bubble_sort(A, n);
	cout << "BUBBLE SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;


	shaker_sort(A, n);
	cout << "SHAKER SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	/*cout << "Merge Sort " << endl;
	sort(0, n - 1);
	for (int i = 0; i <= n - 1; i++) cout << A[i] << " ";
	cout << endl;*/

	shell_sort(A, n);
	cout << "SHELL SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	heap_sort(A, n);
	cout << "HEAP SORT" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "LINEAR SEARCH" << endl;
	linear_search(A, n, 21);
	cout << endl;

	cout << "BINARY ITERATIVE SEARCH" << endl;
	bsi(A, 14);
	cout << endl;

	cout << "BINARY RECURSIVE SEARCH" << endl;
	cout << "The number is found at index " << bsrec(A, n, 0, n - 1, 4);
	cout << endl;

	cout << "EXPONENTIAL SEARCH" << endl;
	cout << "The number is found at index " << exponential(A, n, 18);
	cout << endl;

	cout << "STACK";
	push(stack, A[n - 1]);//the second argument can be a number(depends on a given requierment)
	cout << endl;
	showtop(stack);
	cout << endl;
	pop(stack);
	cout << endl;

	cout << "QUEUE" << endl;
	for (int i = 0; i < n; i++)
	{
		Enqueue(myqueue, A[i]);
	}
	Display(myqueue);
	Dequeue(myqueue);
	Dequeue(myqueue);
	Display(myqueue);
	cout << endl;

	cout << "LINKED LIST" << endl;
	struct Node* head = new Node;
	initNode(head, 10);
	AddNode(head, 20);
	AddNode(head, 30);
	dispay(head);
	cout << endl;
	searchNode(head, 30);
	cout << endl;

	return 0;
}


//RANDOM NUMBERS------------------------------
void RANDOM_NUMBERS(int A[], int n, int min, int max)
{
	int num = min + rand() % max;
	A[0] = num;
	bool used[range] = { false };
	used[num - min] = true;
	for (int i = 1; i < n; i++)
	{
		do
		{
			num = min + rand() % max;
		} while (used[num - min]);
		used[num - min] = true;
		A[i] = num;
	}
}

//INSERTION SORT-----------------------------
void insertion_sort(int A[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0)
		{
			if (A[j] > key)
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
			j--;
		}
	}
}

//SELECTION SORT------------------------
void selection_sort(int A[], int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min]) min = j;
		}
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

//BUBBLE SORT-----------------------------
void bubble_sort(int A[], int n)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i + 1] < A[i])
			{
				int temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

//SHAKER SORT-------------------------------
void shaker_sort(int A[], int n)
{
	int start = 0;
	int end = n - 1;
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = start; i < end; i++)
		{
			if (A[i + 1] < A[i])
			{
				int temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
				swapped = true;
			}
		}
		end--;

		for (int i = end; i >= start; i--)
		{
			if (A[i + 1] < A[i])
			{
				int temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
				swapped = true;
			}
		}
		start++;

	} while (swapped);
}

//MERGE SORT--------------------------------
//void merging(int low, int mid, int high)
//{
//	int l1, l2, i;
//	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
//	{
//		if (A[l1] <= A[l2])  b[i] = A[l1++];
//		else b[i] = A[l2++];
//	}
//	while (l1 <= mid)  b[i++] = A[l1++];
//	while (l2 <= high)  b[i++] = A[l2++];
//	for (i = low; i <= high; i++) A[i] = b[i];
//}
//void sort(int low, int high)
//{
//	int mid;
//	if (low < high)
//	{
//		mid = (low + high) / 2;
//		sort(low, mid);
//		sort(mid + 1, high);
//		merging(low, mid, high);
//	}
//	else { return; }
//}

//SHELL SORT--------------------------------
void shell_sort(int A[], int n)
{
	for (int interval = n / 2; interval > 0; interval = interval / 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = A[i];
			int j;
			for (j = i; j >= interval && A[j - interval] > temp; j = j - interval)
			{
				A[j] = A[j - interval];
				A[j - interval] = temp;
			}
		}
	}
}

//HEAP SORT-----------------------------------
void build_heap(int A[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		heapify(A, n, i);
	}
}

void  heapify(int A[], int n, int i)
{
	int L = i * 2 + 1;
	int R = i * 2 + 2;
	int large = i;
	if (L < n && A[L] > A[i])
	{
		large = L;
	}
	if (R < n && A[R] > A[large])
	{
		large = R;
	}
	if (large != i)
	{
		int temp = A[i];
		A[i] = A[large];
		A[large] = temp;
		heapify(A, n, large);
	}
}

void heap_sort(int A[], int n)
{
	build_heap(A, n);
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, i, 0);
	}
}


//SEARCHING ALGORITHMS++++++++++++++++++++++++++++++++
//LINEAR SEARCH--------------------------------------
void linear_search(int A[], int n, int num)
{
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (num == A[i])
		{
			index = i;
		}


	}
	if (index != -1)
		cout << " Found at index " << index;
	else cout << num << " Not found in the array";
}

//BINARY ITERATIVE SEARCH--------------------------
void bsi(int A[], int num)
{
	int low = 0;
	int high = n - 1;
	int index = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (num == A[mid])
		{
			index = mid;
			break;
		}
		else if (num < A[mid])
		{
			high = mid - 1;
		}
		else if (num > A[mid])
		{
			low = mid + 1;;
		}
	}
	if (index != -1)
	{
		cout << num << " is found at index " << index;
	}
	else
	{
		cout << num << " is not found in the array";
	}
}

// BINARY RECURSIVE SEARCH-------------------------------
int bsrec(int A[], int n, int low, int high, int num)
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}

	else if (num == A[mid])
	{
		return mid;
	}
	else if (num < A[mid])
	{
		high = mid - 1;
	}
	else if (num > A[mid])
	{
		low = mid + 1;
	}
	return bsrec(A, n, low, high, num);
}

//EXPONENTIAL SEARCH-----------------------------------
int exponential(int A[], int n, int num)
{
	if (A[0] == num)
	{
		return 0;
	}
	int bound = 1;
	while (bound <= n && A[bound] < num)
	{
		bound = bound * 2;
	}
	return bsrec(A, n, bound / 2, min(n, bound), num);
}

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//STACK-------------------------------------
void push(int stackarray[], int num) {
	if (top >= n) {
		cout << "Stack overflow";
	}
	else {
		top++;
		stackarray[top] = num;
	}
}
void pop(int stackarray[]) {
	if (top < 0) {
		cout << "Stack empty";
	}
	else {
		cout << "The popped element is " << stackarray[top];
		top--;
	}
}
void showtop(int stackarray[]) {
	if (top < 0) cout << "Stack empty";
	else cout << "The top element is " << stackarray[top];
}


//QUEUE---------------------------------------
void Enqueue(int queue[], int num) 
{
	if (tail == n - 1)
		cout << "Queue full" << endl;
	else
	{
		if (head == -1) head = 0;
		tail++;
		queue[tail] = num;
	}
}
void Dequeue(int queue[]) 
{
	if (tail == -1 && head == -1) {
		cout << "Queue empty" << endl;
		return;
	}
	else {
		cout << "Dequeued item is " << queue[head] << endl;
		head++;
	}
}
void Display(int queue[]) 
{
	if (tail == -1 && head == -1) {
		cout << "Queue empty" << endl;
		return;
	}
	else {
		for (int i = head; i <= tail; i++)
			cout << queue[i] << " ";
	}
	cout << endl;
}

//LINKED LIST---------------------------------
void dispay(struct Node* head) 
{
	Node* list = head;
	while (list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

void initNode(struct Node* head, int n)
{
	head->data = n;
	head->next = NULL;
}
void AddNode(struct Node* head, int n) 
{
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	Node* cur = head;
	while (cur) {
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
void insertFront(struct Node** head, int n) 
{
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}
struct Node* searchNode(struct Node* head, int n)
{
	Node* cur = head;
	while (cur) {
		if (cur->data == n)
		{
			cout << "Node " << n << " is in list" << endl;
			return cur;
		}
		cur = cur->next;
	}
	cout << n << " is not in the list" << endl;
}