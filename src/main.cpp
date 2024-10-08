// Task Management System
// This program allows users to manage tasks by creating, viewing, editing, and deleting them.
// Users can interact with tasks through a menu-driven interface, where they can perform various operations.
// The program utilizes the TaskManager class to manage tasks and provides functionalities to interact with tasks stored in a file.
// It includes options to view tasks sorted by date, priority, or category, edit task details, and delete tasks by their IDs.

#include <iostream>
#include "TaskManager.cpp" // Include the TaskManager class implementation

using namespace std;

// Function to print the main menu options
void printMainMenu()
{
    cout << "Main Menu:" << endl;
    cout << "1. Create Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Edit Task" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit Program" << endl;
    cout << endl
         << "Enter your choice (1-5): ";
}

// Function to print the view options
void printViewOptions()
{
    cout << "View Options:" << endl;
    cout << "1. View by Date" << endl;
    cout << "2. View by Priority" << endl;
    cout << "3. View by Category" << endl;
    cout << "Enter your choice (1-3): ";
}

// Main function
int main()
{
    // Create an instance of the TaskManager class
    TaskManager taskManager;
    int choice;

    // Display welcome message
    cout << "Welcome To The Task Management System" << endl
         << endl;

    // Main program loop
    do
    {
        try
        {
            // Print main menu options
            printMainMenu();

            // Get user choice
            cin >> choice;
            cout << endl;

            // Process user choice
            switch (choice)
            {
            case 1:
            {
                // Create a new task
                taskManager.createTask();
                break;
            }
            case 2:
            {
                int viewChoice;
                // Print view options
                printViewOptions();
                // Get view choice
                cin >> viewChoice;

                // Validate view choice input
                if (viewChoice < 1 || viewChoice > 3)
                {
                    throw invalid_argument("Invalid view option. Please enter a number between 1 and 3.\n");
                }

                cout << endl;
                // View tasks based on user choice
                taskManager.viewTask(viewChoice);

                break;
            }
            case 3:
            {
                int taskId;
                // Prompt user for task ID to update
                cout << "Enter the task ID you want to update: ";
                cin >> taskId;

                // Validate task ID input
                if (taskId < 0)
                {
                    throw invalid_argument("Invalid task ID. Please enter a positive integer.\n");
                }

                // Edit task priority and status
                taskManager.editTaskPriorityAndStatus(taskId);
                break;
            }
            case 4:
            {
                int taskIdToDelete;
                // Prompt user for task ID to delete
                cout << "Enter the task ID you want to delete: ";
                cin >> taskIdToDelete;

                // Validate task ID input
                if (taskIdToDelete < 0)
                {
                    throw invalid_argument("Invalid task ID. Please enter a positive integer.\n");
                }

                // Delete task by ID
                taskManager.deleteTask("project.txt", taskIdToDelete);
                break;
            }
            case 5:
            {
                // Exit the program
                cout << "Thank you for using our system! Have a nice day." << endl;
                break;
            }
            default:
                // Handle invalid choice
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
            }
            cout << endl;
        }
        catch (const exception &ex)
        {
            // Handle exceptions and display error message
            cerr << "Error: " << ex.what() << endl;
            cin.clear();  // Clear error flags
            cin.ignore(); // Discard invalid input
        }
    } while (choice != 5); // Continue loop until user chooses to exit

    return 0; // Exit program
}
