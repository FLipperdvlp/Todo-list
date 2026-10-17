#include <iostream>
#include <vector>
using namespace std;

class Todo{
    private:
    int ID;
    string Title;
    string Description;
public:
    Todo(const int id, const string& title, const string& description) : ID(id), Title(title), Description(description) {}

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
        cout << "Title: " << Title << endl;
        cout << "Description: " << Description << endl;
    }
};

class TodoList{
private:
    vector<Todo> todos;
public:
    void DisplayMenu() const {
        cout << "1. Add Todo" << endl;
        cout << "2. Display Todos" << endl;
        cout << "3. Exit" << endl;
    }

    void addTodo(const Todo& todo) {
        todos.push_back(todo);
    }

    void DeleteTodo(int id) {
        for (auto it = todos.begin(); it != todos.end(); ++it) {
            if (it->getID() == id) {
                todos.erase(it);
                cout << "Todo with ID " << id << " deleted." << endl;
                return;
            }
        }
        cout << "Todo with ID " << id << " not found." << endl;
    }

    void displayTodos() const {
        for (const auto& todo : todos) {
            cout << "------------------------" << endl;
            todo.Display();
            cout << "------------------------" << endl;
        }
    }

    void EditTodo(int id, const string& newTitle, const string& newDescription) {
        for (auto& todo : todos) {
            if (todo.getID() == id) {
                todo.SetTitle(newTitle);
                todo.SetDescription(newDescription);
                cout << "Todo with ID " << id << " updated." << endl;
                return;
            }
        }
        cout << "Todo with ID " << id << " not found." << endl;
    }

    void run(){
        int choice;
        do {
            DisplayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int id;
                    string title, description;
                    cout << "Enter ID: ";
                    cin >> id;
                    cin.ignore(); // Ignore the newline character left in the buffer
                    cout << "Enter Title: ";
                    getline(cin, title);
                    cout << "Enter Description: ";
                    getline(cin, description);
                    addTodo(Todo(id, title, description));
                    break;
                }
                case 2:
                    displayTodos();
                    break;
                case 3:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }while (choice != 3);
    }
};


int main(){
    TodoList todoList;
    todoList.run();
    return 0;
}