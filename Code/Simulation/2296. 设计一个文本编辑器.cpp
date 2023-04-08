class TextEditor {
    list<char> l;
    list<char>::iterator cursor;

    string getLeftText() {
        string s;
        auto it = cursor;
        for (int i = 10; i > 0 && it != l.begin(); i--) {
            --it;
            s += *it;
        }
        reverse(s.begin(), s.end());
        return s;
    }
public:
    TextEditor() {
        cursor = l.begin();
    }
    
    void addText(string text) {
        for (char c : text) {
            l.insert(cursor, c);
        }
    }
    
    int deleteText(int k) {
        int kcopy = k;
        for (; k > 0 && cursor != l.begin(); k--) {
            cursor = l.erase(prev(cursor));
        }
        return kcopy - k;
    }
    
    string cursorLeft(int k) {
        for (; k > 0 && cursor != l.begin(); k--) {
            cursor--;
        }
        return getLeftText();
    }
    
    string cursorRight(int k) {
        for (; k > 0 && cursor != l.end(); k--) {
            cursor++;
        }
        return getLeftText();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */