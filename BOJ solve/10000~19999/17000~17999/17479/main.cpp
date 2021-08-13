#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> menu_price;
map<string, string> menu_type;
map<string, int> order_type;
map<string, long long> order_price;
int a, b, c;
int price;
string menu;
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	for (int i = 0; i < a; i++) {
		cin >> menu >> price;
		menu_price[menu] = price;
		menu_type[menu] = "normal";
	}
	for (int i = 0; i < b; i++) {
		cin >> menu >> price;
		menu_price[menu] = price;
		menu_type[menu] = "special";
	}
	for (int i = 0; i < c; i++) {
		cin >> menu;
		menu_price[menu] = price;
		menu_type[menu] = "service";
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> menu;
		string rank = menu_type[menu];
		order_type[rank] += 1;
		if (rank != "service") {
			int pric = menu_price[menu];
			order_price[rank] += pric;
		}
	}
	if (order_type["special"]) {
		if (order_price["normal"] < 20000) {
			cout << "No" << '\n';
			return 0;
		}
	}
	if (order_type["service"]) {
		if (order_price["normal"] + order_price["special"] < 50000) {
			cout << "No" << '\n';
			return 0;
		}
	}
	if (order_type["service"] > 1) {
		cout << "No" << '\n';
		return 0;
	}
	cout << "Okay" << '\n';
	return 0;
}