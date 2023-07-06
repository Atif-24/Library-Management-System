#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
using std::string;


class Book{

public:

std::string title;
std::string author;
std::string yearPublished;
std::string genre;
std::string ISBN;




};

std::vector<std::string> read_titles(){
        std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> bookTitles; 
    std::string line;
        std::string line2;
        std::string title;
        

    while(std::getline(file2,line)){
        std::istringstream iss(line);
        getline(iss,title,',');
        if(title != "Book Title"){
        bookTitles.push_back(title);

        }



    }



file2.close();


return bookTitles;
}

std::vector<std::string> read_authors(){
        std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> Authors; 
    std::string line;
        std::string line2;
        std::string Bookauthor;
        

    while(std::getline(file2,line)){
        std::istringstream iss(line);
        getline(iss,Bookauthor,',');
        getline(iss >> std::ws, Bookauthor, ',');
        if(Bookauthor != "Author"){
        Authors.push_back(Bookauthor);

        }



    }



file2.close();


return Authors;
}

std::vector<std::string> read_genres(){

        std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> Genres; 
    std::string line;
        std::string line2;
        std::string Bookgenre;
        

    while(std::getline(file2,line)){
        std::istringstream iss(line);
        getline(iss,Bookgenre,',');
        getline(iss,Bookgenre,',');
        getline(iss,Bookgenre,',');
        getline(iss >> std::ws, Bookgenre, ',');
        if(Bookgenre != "Genre"){
        Genres.push_back(Bookgenre);

        }



    }



file2.close();


return Genres;


}

std::vector<std::string> read_file(){

  std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> Books; 
    std::string line;
   
    while(!file2.eof()){
        getline(file2,line);
        Books.push_back(line);
 




    }



file2.close();
return Books;

}

void show_specific(int identifier){
     std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> books; 
    std::string line;
    int linenum = 0;
    while(!file2.eof()){
        getline(file2,line);
        if(linenum == identifier){
            std::cout << linenum << ": " << line << std::endl;

        }
        linenum++;




    }



file2.close();
}


std::vector<std::string> show_books(){

    std::string text;
    std::ifstream file2("library.csv");
    std::vector<std::string> books; 
    std::string line;
    int linenum = 0;
    while(!file2.eof()){
        getline(file2,line);
        books.push_back(line);
        std::cout << linenum << ": " << line << std::endl;
        std:: cout << "\n";
        linenum++;




    }



file2.close();
return books;
    }

void delete_empty(){

    std::string text;
    std::ofstream file("Library2.csv");
    std::ifstream file2("Library.csv");
    std::string line;
    int linenum = 0;
    while(!file2.eof()){
        getline(file2,line);
        if(line.length() != 0){
            file << line << "\n";
        }
        }


file2.close();
file.close();

std::string line2;
std::ifstream ini_file("Library2.csv");
std::ofstream out_file("Library.csv");

while(getline(ini_file,line2)){
    out_file << line2 << "\n";
}

ini_file.close();
out_file.close();

    }

void remove_book(){

    int row_num;
    int current = 0;
   

    std::vector<std::string> books = show_books();
    std::cout << "\nEnter the row number of the book you want to remove: ";
    std::cin >> row_num;
    
      std::ofstream file;

    file.open("Library.csv");

    for(auto element: books){
        if(current != row_num){
            file << element << "\n";
            
        }
        current++;
    }
    


file.close();
delete_empty();

show_books();


}




void add_book(){

Book newbook;
std::string hi;
std::cout << "Enter the Book's Title: ";
std::cin.ignore();
getline(std::cin,newbook.title);


std::cout << "Enter the Book's Author: ";
getline(std::cin,newbook.author);


std::cout << "Enter the Year it was  Originally published: ";
getline(std::cin,newbook.yearPublished);

std::cout << "Enter the Genre: ";
getline(std::cin,newbook.genre);

std::cout << "Enter the ISBN-13: ";
getline(std::cin,newbook.ISBN);


    std::ofstream file;

    file.open("Library.csv",std::ios_base::app);
    file << newbook.title << ", " << newbook.author << ", " << newbook.yearPublished << ", " << newbook.genre << ", " << newbook.ISBN << "\n";
    file.close();






}

void book_search(){

std::cout << "What Criteria do you want to search by?" << std::endl;
std::cout << "1.) Title" << std::endl;
std::cout << "2.) Author" << std::endl;
std::cout << "3.) Genre" << std::endl;
int found = 0;
int choice;
std::cin >> choice;

if(choice == 1){
    std::string title;
    std::cout << "Enter the Book's Title: " << std::endl;
    std::cin >> title;

    int identifier = 1;
    int matches = 0;
    std::vector<std::string> Books = read_titles();

for(auto book: Books){

if(book == title){

show_specific(identifier);

found = 1;
}

identifier++;

}

if(found == 0){
    std::cout << "Sorry, Book Not Found, Please Check Spelling and Capitalization" << std::endl;

}


}

else if(choice == 2){
    std::string bookauthor;
    std::vector<std::string> Authors = read_authors();
    int identifier = 1;
    std::cout << "Enter the Book's Author: " << std::endl;
    std::cin.ignore();
    getline(std::cin, bookauthor);
    for(auto Author: Authors){

if(Author == bookauthor ){
    show_specific(identifier);
    found = 1;
    
}
identifier++;
    }
if(!found){
    std::cout << "Sorry Author not Found, Please Check Spelling and Capitaliaziton." << std::endl;
}


}

else if(choice == 3){

    std::string bookgenre;
    std::vector <std::string> Genres = read_genres();
    int identifier = 1;
    std::cout << "Enter a Genre: " << std::endl;
        
        std::cin.ignore();
        getline(std::cin, bookgenre);
        
    for(auto Genre: Genres){
if(Genre == bookgenre ){
    show_specific(identifier);
    found = 1;
    
}
identifier++;
    }
if(!found){
    std::cout << "Sorry No Books of that Genre Found." << std::endl;
}
}


}


bool menu(){
std::cout << "\n";

    int selection;

std::cout << "1.) Add a Book" << std::endl;
std::cout << "2.) Remove a Book" << std::endl;
std::cout << "3.) Search for a Book" << std::endl;
std::cout << "4.) View all Books" << std::endl;
std::cout << "5.) Quit" << std::endl;
std::cout << "Enter your selection: ";
std::cin >> selection;

if(selection == 1){
    add_book();
    return true;
    
}


if(selection == 2){
    remove_book();
    return true;

}

if(selection == 3){
    book_search();
    return true;

}

if(selection == 4){
    show_books();
    return true;

}

return false;
}






int main() {

  while(menu());


return 0;

}






