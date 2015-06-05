//В строке удалить слова, заключённые в круглые скобки.

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	char s[50], sl[50], sl1[50], sl2[50];
	int sk1, sk2, n;
	cout << "Введите строку: ";
	gets_s(s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			sk1 = i;
			for (int i = sk1; i < n; i++) {
				if (s[i + 1] == ')') {
					sk2 = i + 1;
					for (int j = 0; j < sk1; j++) {
						sl1[j] = s[j];
						if (j == sk1 - 1) {
							sl1[j + 1] = '\0';
						}
					}

					for (int j = 0; j < n - sk2; j++) {
						sl2[j] = s[j + sk2 + 1];
						if (j == n - sk2 - 1) {
							sl2[j + 1] = '\0';
						}
					}
				}
			}
		}
	}

	strcat_s(sl1, sl2);
	cout << sl1 << endl;
	system("pause");
	return 0;
}
void menu(){


}