#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Todo {
private:
    int ID;
    string Title;
    string Description;

public:
    Todo(const int id, const string& title, const string& description)
        : ID(id), Title(title), Description(description) {}

    int getID() const {
        return ID;
    }

    string getTitle() const {
        return Title;
    }

    string getDescription() const {
        return Description;
    }

    void SetID(int id) {
        ID = id;
    }

    void SetTitle(const string& title) {
        Title = title;
    }

    void SetDescription(const string& description) {
        Description = description;
    }

    void Display() const {
        cout << "  ID          : " << ID << endl;
        cout << "  Title       : " << Title << endl;
        cout << "  Description : " << Description << endl;
    }
};

class TodoList {
private:
    vector<Todo> todos;

public:
    void DisplayMenu() const {
        cout << "\n";
        cout << "  ====================================\n";
        cout << "             TODO MANAGER             \n";
        cout << "  ====================================\n";
        cout << "\n";
        cout << "    [1]  Add Todo\n";
        cout << "    [2]  Display Todos\n";
        cout << "    [3]  Edit Todo\n";
        cout << "    [4]  Delete Todo\n";
        cout << "    [5]  Exit\n";
        cout << "\n";
        cout << "  ====================================\n";
        cout << "\n";
    }

    void addTodo(const Todo& todo) {
        todos.push_back(todo);
    }

    void DeleteTodo(int id) {
        for (vector<Todo>::iterator it = todos.begin(); it != todos.end(); ++it) {
            if (it->getID() == id) {
                todos.erase(it);
                cout << "\n  [+] Todo #" << id << " deleted successfully!\n";
                cout << "  ------------------------------------\n";
                return;
            }
        }
        cout << "\n  [!] Todo #" << id << " not found.\n";
    }

    void displayTodos() const {
        cout << "\n";
        cout << "  ====================================\n";
        cout << "              YOUR TODOS              \n";
        cout << "  ====================================\n";

        if (todos.empty()) {
            cout << "\n  No todos available.\n";
        }

        for (vector<Todo>::const_iterator it = todos.begin(); it != todos.end(); ++it) {
            cout << "\n  ------------------------------------\n";
            it->Display();
            cout << "  ------------------------------------\n";
        }

        cout << "\n  Total Todos: " << todos.size() << "\n";
        cout << "  ====================================\n";
    }

    void EditTodo(int id, const string& newtitle, const string& newdescription) {
        for (vector<Todo>::iterator it = todos.begin(); it != todos.end(); ++it) {
            if (it->getID() == id) {
                it->SetTitle(newtitle);
                it->SetDescription(newdescription);
                cout << "\n  [+] Todo #" << id << " updated successfully!\n";
                cout << "  ------------------------------------\n";
                return;
            }
        }
        cout << "\n  [!] Todo #" << id << " not found.\n";
    }

    void run() {
        int choice;
        do {
            DisplayMenu();
            cout << "  >> Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int id;
                    string title, description;
                    cout << "\n  ========== ADD NEW TODO ==========\n\n";
                    cout << "  >> Enter ID: ";
                    cin >> id;
                    cin.ignore();

                    cout << "  >> Enter Title: ";
                    getline(cin, title);

                    cout << "  >> Enter Description: ";
                    getline(cin, description);

                    addTodo(Todo(id, title, description));

                    cout << "\n  [+] Todo added successfully!\n";
                    cout << "  ==================================\n";
                    break;
                }
                case 2:
                    displayTodos();
                    break;
                case 3: {
                    int Id;
                    string newTitle, newDescription;

                    cout << "\n  ============ EDIT TODO ============\n\n";
                    cout << "  >> Enter Todo ID: ";
                    cin >> Id;
                    cin.ignore();

                    cout << "  >> Enter new Title: ";
                    getline(cin, newTitle);
                    cout << "  >> Enter new Description: ";
                    getline(cin, newDescription);

                    EditTodo(Id, newTitle, newDescription);
                    break;
                }
                case 4: {
                    int id;
                    cout << "\n  =========== DELETE TODO ===========\n\n";
                    cout << "  >> Enter Todo ID to delete: ";
                    cin >> id;

                    DeleteTodo(id);
                    continue;
                }
                case 5:
                    cout << "\n";
                    cout << "  ====================================\n";
                    cout << "       Thank you for using TODO!      \n";
                    cout << "  ====================================\n";
                    break;
                default:
                    cout << "\n  [!] Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    TodoList todoList;
    todoList.run();
    return 0;
}