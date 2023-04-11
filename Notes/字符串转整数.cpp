string s = "458";

int n = 0;

for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    n = 10 * n + (c - '0');// 这个括号不能省，否则可能整形溢出
}

printf("%d", n); // n is now 458