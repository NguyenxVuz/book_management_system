#include <iostream>
#include <string>

using namespace std;

class Book {
private:
  string title;
  string author;
  string isbn;
  float price;
  int quantity;

public:
  Book();
  Book(string title, string author, string isbn, float price, int quantity);
  string getTitle();
  string getAuthor();
  string getIsbn();
  float getPrice();
  int getQuantity();
  void setTitle(string title);
  void setAuthor(string author);
  void setIsbn(string isbn);
  void setPrice(float price);
  void setQuantity(int quantity);
  virtual void Addbook() = 0;
  virtual void DisplayBook() = 0;
};

Book ::Book() {
  title = "";
  author = "";
  isbn = "";
  price = 0.0;
  quantity = 0;
}

Book ::Book(string title, string author, string isbn, float price,
            int quantity) {
  this->title = title;
  this->author = author;
  this->isbn = isbn;
  this->price = price;
  this->quantity = quantity;
}

string Book ::getTitle() { return title; }

string Book ::getAuthor() { return author; }

string Book ::getIsbn() { return isbn; }

float Book ::getPrice() { return price; }

int Book ::getQuantity() { return quantity; }

void Book ::setTitle(string title) { this->title = title; }

void Book ::setAuthor(string author) { this->author = author; }

void Book ::setIsbn(string isbn) { this->isbn = isbn; }

void Book ::setPrice(float price) { this->price = price; }

void Book ::setQuantity(int quantity) { this->quantity = quantity; }

void Book ::Addbook() {
  cout << "enter the title of the book: ";
  getline(cin, title);
  cout << "enter the author of the book: ";
  getline(cin, author);
  cout << "enter the isbn of the book: ";
  getline(cin, isbn);
  cout << "enter the price of the book: ";
  cin >> price;
  cout << "enter quantity: ";
  cin >> quantity;
}

void Book ::DisplayBook() {
  cout << "============================" << endl;
  cout << "title: " << title << endl;
  cout << "author: " << author << endl;
  cout << "isbn: " << isbn << endl;
  cout << "price: " << price << endl;
  cout << "quantity: " << quantity << endl;
}

class Ebook : public Book {
private:
  float filesize;
  string fileformat;

public:
  Ebook();
  Ebook(string title, string author, string isbn, float price, int quantity,
        float filesize, string fileformat);
  float getFilesize();
  string getFileformat();
  void setFilesize(float filesize);
  void setFileformat(string fileformat);
  virtual void Addbook() override;
  virtual void DisplayBook() override;
};

Ebook ::Ebook() {
  filesize = 0.0;
  fileformat = "";
}

Ebook ::Ebook(string title, string author, string isbn, float price,
              int quantity, float filesize, string fileformat)
    : Book(title, author, isbn, price, quantity) {
  this->filesize = filesize;
  this->fileformat = fileformat;
}

float Ebook ::getFilesize() { return filesize; }

string Ebook ::getFileformat() { return fileformat; }

void Ebook ::setFilesize(float filesize) { this->filesize = filesize; }

void Ebook ::setFileformat(string fileformat) { this->fileformat = fileformat; }

void Ebook ::Addbook() {
  Book ::Addbook();
  cin.ignore();
  cout << "enter file size of book: ";
  cin >> filesize;
  cin.ignore();
  cout << "enter file format og book: ";
  getline(cin, fileformat);
}

void Ebook ::DisplayBook() {
  Book ::DisplayBook();
  cout << "file size: " << filesize << endl;
  cout << "file format: " << fileformat << endl;
}

class PrintedBook : public Book {
private:
  float weight;

public:
  PrintedBook();
  PrintedBook(string title, string author, string isbn, float price,
              int quantity, float weight);
  float getWeight();
  void setWeight(float weight);
  virtual void Addbook() override;
  virtual void DisplayBook() override;
};
PrintedBook::PrintedBook() : Book() { weight = 0.0; }

PrintedBook::PrintedBook(string title, string author, string isbn, float price,
                         int quantity, float weight)
    : Book(title, author, isbn, price, quantity) {
  this->weight = weight;
}

float PrintedBook::getWeight() { return weight; }
void PrintedBook::setWeight(float weight) { this->weight = weight; }

void PrintedBook::Addbook() {
  Book::Addbook();
  cout << "Enter weight of book (kg): ";
  cin >> weight;
  cin.ignore(); //
}

void PrintedBook::DisplayBook() {
  Book::DisplayBook();
  cout << "Weight: " << weight << " kg" << endl;
}

int main() {

  int n;

  cout << "Enter the number of books: ";
  cin >> n;
  cin.ignore();

  Book *books[n];

  for (int i = 0; i < n; ++i) {
    int type;
    cout << "Enter 1 for Ebook or 2 for PrintedBook: ";
    cin >> type;
    cin.ignore();

    if (type == 1) {
      books[i] = new Ebook();
    } else if (type == 2) {
      books[i] = new PrintedBook();
    }

    books[i]->Addbook();
  }

  for (int i = 0; i < n; ++i) {
    books[i]->DisplayBook();
    cout << "============================" << endl;
  }
  for (int i = 0; i < n; ++i) {
    delete books[i];
  }

  return 0;
}
