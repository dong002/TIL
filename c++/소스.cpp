////범위기반 for문
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int arr[10] = { 3,1,4,2,5,9,2,6,5,3 };
//
//	for (int n : arr) {
//		cout << n << ' ';
//	}
//	cout << endl;
//}
//오버로딩
#include <iostream>
//void swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void swap(double &a, double &b) {
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//void swap(int*& a, int*& b) {
//	int* tmp = a;
//	a = b;
//	b = tmp;
//}
//int main() {
//	int a = 20, b = 30;
//	double da = 2.222, db = 3.333;
//	int* pa = &a, * pb = &b;
//	swap(a, b);
//	swap(da, db);
//	swap(pa, pb);
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << da << std::endl;
//	std::cout << db << std::endl;
//	std::cout << *pa << std::endl;
//	std::cout << *pb << std::endl;
//}
#include <iostream>
using namespace std;
int inventory[64] = { 0 };
int score = 0;
/*void getItem(int itemId) {
	inventory[itemId]++;
}
void getItem(int itemid, int cnt) {
	inventory[itemid] += cnt;
}
void getItem(int itemId, int cnt, int sc) {
	inventory[itemId] += cnt;
	score += sc;
}*/
void getItem(int itemId, int cnt=1, int sc=0) {
	inventory[itemId] += cnt;
	score += sc;
}
int main() {
	getItem(6, 5);
	getItem(3, 2);
	getItem(3);
	getItem(11, 34, 7000);

	cout << score << endl;
	for (int i = 0; i < 16; i++) {
		cout << inventory[i] << ' ';
	}
	cout << endl;
}