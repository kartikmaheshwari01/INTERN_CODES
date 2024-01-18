#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure to store task details
struct Task 
{
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};
void addTask(vector<Task>& taskList, const string& description);
void viewTasks(const vector<Task>& taskList);
void markTaskAsCompleted(vector<Task>& taskList, int taskIndex);
void removeTask(vector<Task>& taskList, int taskIndex);

int main() 
{
    vector<Task> taskList;
    char choice;
    do {
        cout << "TO DO TASK  Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5):  ";
        cin >> choice;

        switch (choice) 
		{
            case '1': 
			{
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, taskDescription);
                addTask(taskList, taskDescription);
                break;
            }
            case '2':
                viewTasks(taskList);
                break;
            case '3': 
			{
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                markTaskAsCompleted(taskList, taskIndex);
                break;
            }
            case '4': 
			{
                int taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                removeTask(taskList, taskIndex);
                break;
            }
            case '5':
                cout << "Exiting Task Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != '5');

    return 0;
}
void addTask(vector<Task>& taskList, const string& description) 
{
    // Add a new task to the task list
    taskList.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& taskList) 
{
    // Display the list of tasks with their status
    cout << "Task List:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        cout << (taskList[i].completed ? "[X] " : "[ ] ");
        cout << taskList[i].description << endl;
    }
}
void markTaskAsCompleted(vector<Task>& taskList, int taskIndex) 
{
    // Mark a task as completed
    if (taskIndex >= 1 && static_cast<size_t>(taskIndex) <= taskList.size()) 
	{
        taskList[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}
void removeTask(vector<Task>& taskList, int taskIndex) 
{
    // Remove a task from the task list
    if (taskIndex >= 1 && static_cast<size_t>(taskIndex) <= taskList.size()) 
	{
        taskList.erase(taskList.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

