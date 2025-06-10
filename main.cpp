#include <iostream>
#include <array>
#include <string>
#include <cstdlib>//Library for for random generator
#include <time.h>//Library for setting the seed

using namespace std;
//Initializing functions
void display_menu();
void show_books();
void choise(int option);
void exit();
void shopping_cart();
void buy_menu();
void search();
void shop_cart_count();

int shop[5];
string author[] = {"George Orwell","Harper Lee","Ray Bradbury","Miguel De Cervantes Saavedra","Leo Tolstoy"};
string title[] = {"1984","To Kill a Mockingbird","Fahrenheit 451","Don Quixote","War and Peace"};
const int cost[] = {20, 13, 34, 45, 10};

int option, shop_cart_counti = 0;

int main()
{
    display_menu(); //first menu calling
    int l = 1;
    while (l > 0) //infinitive loop to restart menu choises
    {
        choise(option);//Calling function for user to input his choice
    }
    option = 0;
}

void display_menu()//Function to call menu
{
    cout << "---------------------------------------\n";
    cout << "                 MENU\n";
    cout << "---------------------------------------\n";
    cout << "1 - View available books\n";
    cout << "2 - Search for books by title or author\n";
    cout << "3 - Shopping cart\n";
    cout << "4 - Exit\n";
    cout << "Enter your option: ";
}

void choise(int option)//Function to input and call menu choises
{
    cin >> option;//Inputting user choice
    if (option == 1)
    {
        system("clear");//Cleaning screen for the new output
        show_books();//Calling function to output books in stock
    }
    else if (option == 2)
    {
        system("clear");//Cleaning screen for the new output
        search();//Calling function which is responsible for searching by title and author
    }
    else if (option == 3)
    {
        system("clear");//Cleaning screen for the new output
        shopping_cart();//Calling fuction for displaying books that were added to shopping cart
    }
    else if (option == 4)
    {
        exit();//Calling function to exit the program
    }
    else//Output for user input error
    {
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << "         Inncorect menu choise" << endl;
        cout << "---------------------------------------\n";
        display_menu();//Calling main menu
    }
    option = 0;
}

void show_books()//Function to show books in stock
{
    int book;
    for (int j = 0; j < 5; j++) // loop for outputting books
    {
        cout << j+1 << ") " << author[j] << " | ";
        cout << title[j] << " | ";
        cout << "RM" << cost[j] << endl;
    }
    cout << "1 - Add book to shopping cart" << endl;
    cout << "2 - Back to the menu" << endl;
    cout << "3 - Exit" << endl;
    cout << "Enter your option: ";
    cin >> option;//Inputting user choice
    if (option == 1)
    {
        cout << "Enter book number: ";
        cin >> book;//Inputting book number
        if (book > 0 && book < 6)//Check if the book number is in range
        {
            shop[shop_cart_counti] = book - 1;//Saving in shop array book number
            shop_cart_count();//Calling function that stores number of book that been added to shopping cart
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "      Book added to shopping cart!\n";
            cout << "---------------------------------------\n";
            display_menu();//Calling main menu
        }
        else//Output for user input error
        {
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "           Wrong book number" << endl;
            cout << "---------------------------------------\n";
            show_books();//Restarting show books function
        }
    }
    else if (option == 2)
    {
        system("clear");//Cleaning screen for the new output
        display_menu();//Calling main menu
    }
    else if (option == 3)
    {
        exit();//Calling function to exit the program
    }
    else//Output for user input error
    {
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << "         Inncorect menu choise" << endl;
        cout << "---------------------------------------\n";
        show_books();//Restarting show books function
    }
    option = 0;
}

void shopping_cart()//Fuction for displaying books that were added to shopping cart
{
    int total = 0, f = 0;
    if (shop_cart_counti !=  0)//Checking if there is any book added to shopping cart
    {
        cout << "In shopping cart: " << endl;
        for (int j = shop_cart_counti ; j > 0; j--)//Outputting books that are in shopping cart
        {
            cout << author[shop[f]] << " | ";//calling element from author array with the number that is stored in shop array
            cout << title[shop[f]] << " | ";//the loop starts with the first element in shop array and execute as many times as values in shop array
            cout << "RM" << cost[shop[f]] << endl;
            total += cost[shop[f]]; // calculate the total cost in shopping cart
            f++;
        }
        cout << "Total price is: RM" << total << endl;
        cout << "1 - Finish purchase" << endl;
        cout << "2 - Clean shopping cart" << endl;
        cout << "3 - Back to the menu" << endl;
        cout << "Enter your option: ";
        cin >> option;//Inputting user choice
        if (option == 1)
        {
            system("clear");//Cleaning screen for the new output
            buy_menu();//Calling function that simulate byuing process
        }
        else if (option == 2)
        {
            shop_cart_counti = 0;//Cleaning shopping cart
            system("clear");//Cleaning screen for the new output
            shopping_cart();//Restarting shopping cart function
        }
        else if (option == 3)
        {
            system("clear");//Cleaning screen for the new output
            display_menu();//Calling main menu
        }
        else//Output for user input error
        {
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "         Inncorect menu choise" << endl;
            cout << "---------------------------------------\n";
            shopping_cart();//Restarting shopping cart function
        }
    }
    else
    {
        cout << "There is nothing in shopping cart" << endl;//Output if there are no books in shopping cart
        cout << "1 - Back to the menu" << endl;
        cout << "2 - Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;//Inputting user choice
        if (option == 1)
        {
            system("clear");//Cleaning screen for the new output
            display_menu();//Outputting main menu
        }
        else if (option == 2)
        {
            exit();//Calling function to exit the program
        }
        else//Output for user input error
        {
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "         Inncorect menu choise" << endl;
            cout << "---------------------------------------\n";
            shopping_cart();//Restarting shopping cart function
        }
    }
    option = 0;
}

void buy_menu()//Simulating byuing process
{
    srand(time(0));//Setting seed for random generator for a new sequence of numbers
    long card = 0;
    int cvv = 0, order, N = 10000;
    char first_name[100], second_name[100], address[100];
    order = rand() % N;//Generating random number for order and getting 4 signed number by returning division remainder
    cout << "Enter your card number: ";
    cin >> card;
    cout << "Enter your card cvv number: ";
    cin >> cvv;
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> second_name;
    cout << "Enter your address: ";
    cin >> address;
    cout << "Successful order!\n";
    cout << "Your order number is: " << order << endl;
    shop_cart_counti = 0;//Resseting value that stores amount of books in shopping cart
    exit();
}

void search()//Function for searching books by title or author and adding them to shopping cart
{
    int book_number = 10;
    string request;
    cout << "To search for a book write it's title or author: ";
    cin.ignore();//Clearing the input buffer
    getline(cin, request);//Inputting whole line for search

    for (int i = 0; i < 5; i++)
    {
        size_t search = author[i].find(request);//Searching requested line in the Author array
        size_t search_title = title[i].find(request);//Searching requested line in the Title array
        if (search >= 0 && search < 100)//Checking if the searching position is in range of the array
        {
            book_number = i;//Setting the number of book that was found
        }
        else if (search_title >= 0 && search_title < 100)//Checking if the searching position is in range of the array
        {
            book_number = i;//Setting the number of book that was found
        }
    }
    
    if (book_number != 10)//Checking if the book was found
    {
        system("clear");//Cleaning screen for the new output
        cout << author[book_number] << endl;//Outputting info about book that was found
        cout << title[book_number] << endl;
        cout << "RM" << cost[book_number] << endl;
    }
    else//Output if there no book found
    {
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << "   No book with that author or title\n";
        cout << "---------------------------------------\n";
        search();//Restarting search function
    }
    //Outputting menu of choices
    cout << "1 - Add to shopping cart" << endl;
    cout << "2 - Search again" << endl;
    cout << "3 - Back to the menu" << endl;
    cout << "Enter your option: ";
    cin >> option;//Inputting user choice
    if (option == 1)
    {
        shop[shop_cart_counti] = book_number;//Saving number of book in Shop array
        shop_cart_count();//Calling counter of books in shopping cart
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << "      Book added to shopping cart!\n";
        cout << "---------------------------------------\n";
        display_menu();//Outputting main menu
    }
    else if (option == 2)
    {
        system("clear");//Cleaning screen for the new output
        search();//Calling search function again
    }
    else if (option == 3)
    {
        system("clear");//Cleaning screen for the new output
        display_menu();//Outputting main menu
    }
    else//Output for user input error
    {
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << "         Inncorect menu choise" << endl;
        cout << "---------------------------------------\n";
        search();//Restarting search function
    }
option = 0;
}

void shop_cart_count()//Function that counting how many books are in shopping cart
{
    shop_cart_counti++;//Adding one more to count when function is called
}

void exit()//Function to exit the program
{
    if (shop_cart_counti == 0)//Checking if there any books in shopping cart
    {
        cout << "---------------------------------------\n";
        cout << "             Thank youuu....\n";
        cout << "---------------------------------------\n";
        exit(0);//Exiting the program
    }
    else//If there are books in shopping cart, suggesting to return to shopping cart
    {
        system("clear");//Cleaning screen for the new output
        cout << "---------------------------------------\n";
        cout << " You have books in your shopping cart!\n";
        cout << "---------------------------------------\n";
        cout << "1 - Return to shopping cart" << endl;
        cout << "2 - Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;//Inputting user choice
        if (option == 1)
        {
            shopping_cart();//Calling function for shopping cart
        }
        else if (option == 2)
        {
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "             Thank youuu....\n";
            cout << "---------------------------------------\n";
            exit(0);//Exiting the program
        }
        else//Output for user input error
        {
            system("clear");//Cleaning screen for the new output
            cout << "---------------------------------------\n";
            cout << "         Inncorect menu choise" << endl;
            cout << "---------------------------------------\n";
            exit();//Calling exit function again
        }
    }
}
