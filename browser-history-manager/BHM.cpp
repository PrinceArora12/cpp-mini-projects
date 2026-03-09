#include <iostream>
#include <stack>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string current;

public:

    void visitPage(string url) {
        if (!current.empty()) {
            backStack.push(current);
        }

        current = url;

        while (!forwardStack.empty()) {
            forwardStack.pop();
        }

        cout << "Visited: " << current << endl;
    }

    void goBack() {
        if (backStack.empty()) {
            cout << "No previous page.\n";
            return;
        }

        forwardStack.push(current);
        current = backStack.top();
        backStack.pop();

        cout << "Went back to: " << current << endl;
    }

    void goForward() {
        if (forwardStack.empty()) {
            cout << "No forward page.\n";
            return;
        }

        backStack.push(current);
        current = forwardStack.top();
        forwardStack.pop();

        cout << "Went forward to: " << current << endl;
    }

    void currentPage() {
        if (current.empty()) {
            cout << "No page visited yet.\n";
        } else {
            cout << "Current Page: " << current << endl;
        }
    }

    void showHistory() {
        stack<string> temp = backStack;

        cout << "\n--- Browser History ---\n";

        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }

        if (!current.empty())
            cout << current << "  <-- Current Page\n";
    }

    void clearHistory() {
        while (!backStack.empty()) backStack.pop();
        while (!forwardStack.empty()) forwardStack.pop();
        current = "";

        cout << "History cleared.\n";
    }
};

int main() {

    BrowserHistory bh;
    int choice;
    string url;

    do {

        cout << "\n===== Browser History Manager =====\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Show History\n";
        cout << "6. Clear History\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter URL: ";
            cin >> url;
            bh.visitPage(url);
            break;

        case 2:
            bh.goBack();
            break;

        case 3:
            bh.goForward();
            break;

        case 4:
            bh.currentPage();
            break;

        case 5:
            bh.showHistory();
            break;

        case 6:
            bh.clearHistory();
            break;

        case 7:
            cout << "Exiting Browser History Manager.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}