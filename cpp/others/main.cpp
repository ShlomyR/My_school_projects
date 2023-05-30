// #include <iostream>
// #include <fstream>
// #include <algorithm>
using namespace std;

// void initializeFile(){
//     // Check if the file exists
//     ifstream file_in("scores.txt");
//     if (!file_in.good()) {
//         // Open file for writing
//         ofstream file_out("scores.txt");

//         // Initialize the data with the initial values
//         for (int i = 0; i < 10; i++) {
//             file_out << i+1 << " " << "00000" << " " << 0 << endl;
//         }

//         file_out.close();
//     } else {
//         file_in.close();
//     }
// }

// struct Data
// {
//     int lineNumber;
//     string name;
//     int score;
// };

// int main()
// {
//     initializeFile();

//     Data data[10];
//     string givenName;
//     int givenScore;

//     fstream file("scores.txt", ios::in | ios::out);

//     if (file.is_open()) {
//         // read from the file
//         for (int i = 0; i < 10; i++) {
//             file >> data[i].lineNumber >> data[i].name >> data[i].score;
//         }

//         // Ask user for name and score
//         cout << "Enter a name: ";
//         cin >> givenName;
//         cout << "Enter a score: ";
//         cin >> givenScore;

//         // Check if the given score is greater than the lowest score in the file
//         if (givenScore > data[9].score) {
//             data[9].name = givenName;
//             data[9].score = givenScore;

//             // sort the data array in descending order
//             sort(data, data + 10, [](Data a, Data b)
//                  { return a.score > b.score; });
//         }

//         // Write all data to the file
//         file.seekp(0);
//         for (int i = 0; i < 10; i++) {
//             file << data[i].lineNumber << " " << data[i].name << " " << data[i].score << endl;
//         }
//         file.close();
//     } else {
//         cout << "Unable to open the file" << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;

// struct Data{
//     int lineNumber;
//     string name;
//     int score;
// };

// int main() {
//     Data data[10];
//     string givenName;
//     int givenScore;

//     // Open file for reading
//     ifstream file_in("scores.txt");

//     // Check if the file exists
//     if (!file_in.good()) {
//         // Open file for writing
//         ofstream file_out("scores.txt");

//         // Initialize the data with the initial values
//         for (int i = 0; i < 10; i++) {
//             data[i].lineNumber = i+1;
//             data[i].name = "00000";
//             data[i].score = 0;
//             file_out << data[i].lineNumber << " " << data[i].name << " " << data[i].score << endl;
//         }

//         file_out.close();
//     } else {
//         file_in.close();
//     }

//     // Open file for reading and writing
//     fstream file("scores.txt", ios::in | ios::out);

//     if(file.is_open()){
//         // read from the file
//         for(int i=0;i<10;i++){
//             file>>data[i].lineNumber>>data[i].name>>data[i].score;
//         }

//         // Ask user for name and score
//         cout << "Enter a name: ";
//         cin >> givenName;
//         cout << "Enter a score: ";
//         cin >> givenScore;

//         // Check if the given score is greater than any score in the array
//         // check if the new score is greater than the lowest score in the file
//         if(givenScore > data[9].score) {
//             data[9].name = givenName;
//             data[9].score = givenScore;
//             // sort the data array in descending order
//             for(int i = 0; i < 9; i++) {
//                 for(int j = i+1; j < 10; j++) {
//                     if(data[i].score < data[j].score) {
//                         swap(data[i], data[j]);
//                     }
//                 }
//             }
//         }

//         // Write all data to the file
//         file.seekp(0);
//         for (int i = 0; i < 10; i++) {
//             file << data[i].lineNumber << " " << data[i].name << " " << data[i].score << endl;
//         }
//         file.close();
//     }else{
//         cout<<"Unable to open the file"<<endl;
//     }
//     return 0;
// }

// #include <SFML/Graphics.hpp>
// #include <fstream>
// #include <iostream>

// int main() {
//     // Create a window
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Scores");

//     // Create a font
//     sf::Font font;
//     font.loadFromFile("rexlia_rg.otf");

//     // Create a text object to display the scores
//     sf::Text scoresText;
//     scoresText.setFont(font);
//     scoresText.setCharacterSize(24);
//     scoresText.setFillColor(sf::Color::White);
//     scoresText.setPosition(10, 10);

//     // Read the scores from the file
//     std::ifstream scoresFile("scores.txt");
//     std::string scores;
//     while (std::getline(scoresFile, scores)) {
//         scoresText.setString(scoresText.getString() + scores + "\n");
//     }
//     scoresFile.close();

//     // Main loop
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         window.clear();
//         window.draw(scoresText);
//         window.display();
//     }
//     return 0;
// }

// #include <SFML/Graphics.hpp>
// #include <fstream>
// #include <iostream>

// struct Data{
//     string name;
//     int score;
// };

// void initializeFile(){
//     // Check if the file exists
//     ifstream file_in("scores.txt");
//     if (!file_in.good()) {
//         // Open file for writing
//         ofstream file_out("scores.txt");

//         // Initialize the data with the initial values
//         for (int i = 0; i < 10; i++) {
//             file_out <<" " << "00000" << " " << 0 << endl;
//         }

//         file_out.close();
//     } else {
//         file_in.close();
//     }
// }

// int main() {
//     initializeFile();
//     Data data[10];
//     string givenName;
//     int givenScore;

//     // Open file for reading and writing
//     fstream file("scores.txt", ios::in | ios::out);

//     if(file.is_open()){
//         // read from the file
//         for(int i=0;i<10;i++){
//             file>>data[i].name>>data[i].score;
//         }

//         // Ask user for name and score
//         cout << "Enter a name: ";
//         cin >> givenName;
//         cout << "Enter a score: ";
//         cin >> givenScore;

//         // Check if the given score is greater than any score in the array
//         // check if the new score is greater than the lowest score in the file
//         if(givenScore > data[9].score) {
//             data[9].name = givenName;
//             data[9].score = givenScore;
//             // sort the data array in descending order
//             for(int i = 0; i < 9; i++) {
//                 for(int j = i+1; j < 10; j++) {
//                     if(data[i].score < data[j].score) {
//                         swap(data[i], data[j]);
//                     }
//                 }
//             }
//         }

//         // Write all data to the file
//         file.seekp(0);
//         for (int i = 0; i < 10; i++) {
//             file <<" " << data[i].name << " " << data[i].score << endl;
//         }
//         file.close();
//     }else{
//         cout<<"Unable to open the file"<<endl;
//     }

//     // Create a window
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Scores");

//     // Create a font
//         sf::Font font;
//     if (!font.loadFromFile("rexlia_rg.otf")) {
//         cout << "Error loading font" << endl;
//         return -1;
//     }

//     // Create text objects for displaying the scores
//     sf::Text text[10];
//     for (int i = 0; i < 10; i++) {
//         text[i].setFont(font);
//         text[i].setCharacterSize(24);
//         text[i].setFillColor(sf::Color::White);
//         text[i].setPosition(50, 50 + i * 50);
//     }

//     // Main loop
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         // Update the text objects with the data from the file
//         for (int i = 0; i < 10; i++) {
//             text[i].setString(" " + data[i].name + " " + std::to_string(data[i].score));
//         }

//         // Clear the screen
//         window.clear(sf::Color::Black);

//         // Draw the text objects
//         for (int i = 0; i < 10; i++) {
//             window.draw(text[i]);
//         }

//         // Display the changes
//         window.display();
//     }

//     return 0;
// }

#include <iostream>
// #include <fstream>
// #include <SFML/Graphics.hpp>
// using namespace std;

// struct Data{
//     string name;
//     int score;
// };

// int main() {
//     Data data[10];
//     string givenName;
//     int givenScore;

//     // Open file for reading
//     ifstream file_in("scores.txt");

//     // Check if the file exists
//     if (!file_in.good()) {
//         // Open file for writing
//         ofstream file_out("scores.txt");

//         // Initialize the data with the initial values
//         for (int i = 0; i < 10; i++) {
//             data[i].name = "00000";
//             data[i].score = 0;
//             file_out << data[i].name << " " << data[i].score << endl;
//         }

//         file_out.close();
//     } else {
//         file_in.close();
//     }

//     // Create the SFML window
//     sf::RenderWindow window(sf::VideoMode(800, 600), "High Scores");
//     sf::Font font;
//     font.loadFromFile("rexlia_rg.otf");

//     // Read the scores from the file
//     ifstream file_in2("scores.txt");
//     for(int i=0;i<10;i++){
//         file_in2 >> data[i].name >> data[i].score;
//     }
//     file_in2.close();

//     // Text for displaying the scores
//     sf::Text scoresText;
//     scoresText.setFont(font);
//     scoresText.setCharacterSize(30);
//     scoresText.setFillColor(sf::Color::White);
//     scoresText.setPosition(50, 50);

//     // Text for displaying the instructions
//     sf::Text instructionsText;
//     instructionsText.setFont(font);
//     instructionsText.setCharacterSize(30);
//     instructionsText.setFillColor(sf::Color::White);
//     instructionsText.setPosition(50, 500);
//     instructionsText.setString("Enter your name and score using the keyboard and press 'Enter' to submit");

//     // Text for displaying the input field
//     sf::Text inputField;
//     inputField.setFont(font);
//     inputField.setCharacterSize(30);
//     inputField.setFillColor(sf::Color::White);
//     inputField.setPosition(50, 550);

//     // Main event loop
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//             if (event.type == sf::Event::TextEntered) {
//                 if (event.text.unicode < 128 && event.text.unicode != '\b' && event.text.unicode != '\r') {
//                     if (givenName.length() < 10) {
//                         givenName += static_cast<char>(event.text.unicode);
//                         inputField.setString(givenName);
//                     }
//                 }
//                 if (event.text.unicode == '\b') {
//                     if (givenName.length() > 0) {
//                         givenName.pop_back();
//                         inputField.setString(givenName);
//                     }
//                 }
//                 if (event.text.unicode == '\r') {
//                     cout << "Enter a score: ";
//                     cin >> givenScore;

//                     // Check if the given score is greater than any score in the array
//                     int index = -1;
//                     for(int i=0;i<10;i++){
//                         if(data[i].score < givenScore){
//                             if(index==-1) index = i; // first occurrence
//                             else if(givenScore > data[index].score) index = i;
//                         }
//                     }

//                     // Update the score and name in the array
//                     if(index != -1){
//                         data[index].score = givenScore;
//                         data[index].name = givenName;
//                     }

//                     // sort the data array in descending order
//                     for(int i = 0; i < 9; i++) {
//                         for(int j = i+1; j < 10; j++) {
//                             if(data[i].score < data[j].score) {
//                                 swap(data[i], data[j]);
//                             }
//                         }
//                     }

//                     // Open the file for writing
//                     ofstream file_out("scores.txt");
//                     for (int i = 0; i < 10; i++) {
//                         file_out << data[i].name << " " << data[i].score << endl;
//                     }
//                     file_out.close();

//                     std::string scoresString = "";
//                     for (int i = 0; i < 10; i++) {
//                         scoresString += std::to_string(i+1) + ". " + data[i].name + " " + std::to_string(data[i].score) + "\n";
//                     }
//                     scoresText.setString(scoresString);

//                 } // Clear the input field and name variable

//             }

//         }
//         // Clear the window
//         window.clear();

//         // Draw the scores text and input field
//         window.draw(scoresText);
//         window.draw(inputField);

//         // Display the window
//         window.display();
//     }
//     return 0;
// }

// #include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Text Example");
//     sf::Text text;
//     sf::Font font;
//     text.setString("Hello, SFML!");
//     font.loadFromFile("rexlia_rg.otf");
//     text.setFont(font);
//     text.setCharacterSize(24);
//     text.setFillColor(sf::Color::White);
//     text.setPosition(sf::Vector2f(200, 200));
//     sf::Clock clock;
//     sf::Time elapsed;
//     const sf::Time displayTime = sf::seconds(1);
//     bool isTextDisplayed = true;

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         if (isTextDisplayed) {
//             elapsed += clock.restart();
//             if (elapsed >= displayTime) {
//                 elapsed = sf::Time::Zero;
//                 isTextDisplayed = false;
//             }
//             window.draw(text);
//         }
//         else {
//             elapsed += clock.restart();
//             if (elapsed >= sf::seconds(1)) {
//                 elapsed = sf::Time::Zero;
//                 isTextDisplayed = true;
//             }
//         }
//         window.display();
//     }
//     return 0;
// }

// #include <iostream>
// #include <boost/filesystem.hpp>

// int main() {
//     boost::filesystem::path dir("/home/shlomy/Desktop/m/m05.shlomiro/cpp/22-bricks/src/script");
//     int file_count = 0;
//     boost::filesystem::directory_iterator end_iter;
//     for (boost::filesystem::directory_iterator iter(dir); iter != end_iter; ++iter) {
//         if (boost::filesystem::is_regular_file(iter->status())) {
//             ++file_count;
//         }
//     }
//     std::cout << "Number of files: " << file_count << std::endl;
//     return 0;
// }
// void foo(int x,int z)
// {
//     if (x == z) {
//         return;
//     }
//     foo(x--,z+1);
//     std::cout << x << "," << z << "\n";

// }

// void recursiveFunction(int x, int y) {
//     if (x > 0 && y != 0) {
//         recursiveFunction(x--, y - 1);
//     }
//     std::cout << "x: " << x << ", y: " << y << std::endl;
// }

// void print_numbers(int n)
// {
//     if (n <= 0) {
//         return;
//     }
//     print_numbers(--n);
//     std::cout << n << "\n";
// }

// int main()
// {
//     foo(8,4);
//     // recursiveFunction(8,4);
//     //print_numbers(5);
//     return 0;
// }

// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <string>

// const int WIDTH = 800;
// const int HEIGHT = 600;

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Enter Name Prompt");

//     int currentScore = 100;
//     int oldScore = 50;

//     // Check if current score is greater than old score
//     if (currentScore > oldScore)
//     {
//         // Create a text object to display the prompt
//         sf::Text promptText;
//         sf::Font font;
//         font.loadFromFile("rexlia_rg.otf");
//         promptText.setFont(font); // Replace "font" with your actual font object
//         promptText.setCharacterSize(30);
//         promptText.setPosition(WIDTH / 2 - 50, HEIGHT / 2);
//         promptText.setString("Enter Your Name:");

//         // Create an input box to capture the name
//         sf::RectangleShape inputBox;
//         inputBox.setSize(sf::Vector2f(200, 50));
//         inputBox.setPosition(WIDTH / 2 - 100, HEIGHT / 2 + 50);

//         std::string playerName;
//         bool isTyping = true;

//         while (window.isOpen())
//         {
//             sf::Event event;
//             while (window.pollEvent(event))
//             {
//                 if (event.type == sf::Event::Closed)
//                 {
//                     window.close();
//                 }
//                 else if (event.type == sf::Event::TextEntered)
//                 {
//                     if (event.text.unicode == '\b')
//                     {
//                         if (playerName.length() > 0)
//                         {
//                             playerName.pop_back();
//                         }
//                     }
//                     else if (event.text.unicode == '\r')
//                     {
//                         isTyping = false;
//                     }
//                     else
//                     {
//                         playerName += static_cast<char>(event.text.unicode);
//                     }
//                 }
//             }

//             window.clear();

//             window.draw(promptText);
//             window.draw(inputBox);

//             if (isTyping)
//             {
//                 sf::Text playerNameText;
//                 playerNameText.setFont(font); // Replace "font" with your actual font object
//                 playerNameText.setCharacterSize(30);
//                 playerNameText.setPosition(WIDTH / 2 - 95, HEIGHT / 2 + 55);
//                 playerNameText.setString(playerName);

//                 window.draw(playerNameText);
//             }
//             else
//             {
//                 // Save the player's name and score to a file or database, etc.
//                 // ...

//                 // Close the window
//                 window.close();
//             }

//             window.display();
//         }
//     }

//     return 0;
// }

class Rectangle
{
public:
    Rectangle(int w, int h) : m_width(w), m_height(h) {}
    int area() { return m_width * m_height; }
    int getW() { return this->m_width; }
    int getH() { return this->m_height; }

private:
    int m_width;
    int m_height;
};

class Square : public Rectangle
{
public:
    Square(int side) : Rectangle(side, side) {}
    int area() { return getW() * getW(); }
};

class Riv : public Rectangle
{
public:
    Riv(int w, int h) : Rectangle(w, h) {}
    int area() { return getW() * getH(); }
};

// class MultiplyBy
// {
// public:
//     MultiplyBy(int factor)
//     : factor(factor)
//     {}
//     int operator()(int x) const {
//         return factor * x;
//     }

// private:
//     int factor;
// };

// int main()
// {
// MultiplyBy two(2);
// cout << two(3) + two(4) << "\n";
// Rectangle r(2,4);
// std::cout << r.area() << "\n";

// Square s(4);
// std::cout << s.area() << "\n";

// Rectangle a(3,4);
// std::cout << r.area() << "\n";

// Square b(3);
// std::cout << r.area() << "\n";

// Rectangle c(8,4);
// std::cout << r.area() << "\n";

//     return 0;
// }

// #include <iostream>
// #include <optional>

// std::optional<int> divide(int x, int y) {
//   if (y == 0) {
//     return {};
//   }
//   return x / y;
// }

// int main() {
//   auto result = divide(0, 5);
//   if (result.has_value()) {
//     std::cout << result.value() << std::endl; // outputs 2
//   }

//   result = divide(10, 0);
//   if (!result.has_value()) {
//     std::cout << "Division by zero." << std::endl;
//   }

//   return 0;
// }

// #include <iostream>
// #include <vector>
// #include <optional>

// template<typename Container>
// std::optional<int> find_first_even(Container& numbers) {
//     using Iter = typename Container::iterator;
//     Iter.begin();
//   for (Iter = numbers.begin(); Iter != numbers.end(); ++Iter) {
//     if (*Iter % 2 == 0) {
//       return *Iter;
//     }
//   }
//   return {};
// }

// int main() {
//   std::vector<int> numbers = {1, 3, 5, 7, 9};
//   auto result = find_first_even(numbers);
//   if (result.has_value()) {
//     std::cout << "First even number: " << result.value() << std::endl;
//   } else {
//     std::cout << "No even numbers found." << std::endl;
//   }
//   return 0;
// }
// #include <vector>

// namespace mt
// {
//     double squareRoot(double n)
//     {
//         double x = n;
//         double y = 1;
//         double e = 0.000001; // precision
//         while (x - y > e)
//         {
//             x = (x + y) / 2;
//             y = n / x;
//         }
//         return x;
//     }

//     class Matrix
//     {
//     public:
//         Matrix(int n)
//             : m_rows(n)
//             , m_cols(n)
//             , m_vec(n)
//         {
//         }

//         int &operator()(int row, int col)
//         {
//             return m_vec[row][row*m_cols+col];
//         }

//         const int &operator()(int row, int col) const
//         {
//             return m_vec[row][row*m_cols+col];
//         }

//         Matrix operator+(const Matrix &other) const
//         {
//             Matrix result(squareRoot(m_size));
//             for (int i = 0; i < m_size; ++i) {
//                 for (int j = 0;j < m_size; ++j) {
//                     result.m_vec[i][j] = m_vec[i][j] + other.m_vec[i][j];
//                 }
//             }
//             return result;
//         }

//         int rows() const { return m_rows; }
//         int cols() const { return m_cols; }

//     private:
//         int m_rows;
//         int m_cols;
//         int m_size;
//         std::vector<std::vector<int>> m_vec;
//     };

//     std::ostream &operator<<(std::ostream &out, const Matrix &m)
//     {
//         for (int i = 0; i < m.rows(); ++i)
//         {
//             for (int j = 0; j < m.cols(); ++j)
//             {
//                 out << m(i, j) << ' ';
//             }
//             out << '\n';
//         }
//         return out;
//     }
//     Matrix identity(int size)
//     {
//         Matrix result(size);
//         for (int i = 0; i < size; ++i) {
//             result(i, i) = 1;
//         }
//         return result;
//     }
// } // namespace mt

// int main()
// {
//     mt::Matrix m(3);
//     m(1, 1) = 4;
//     m(1, 1) *= 2;
//     m(0, 2) = 3;
//     m(1, 0) = 4;
//     m(1, 2) = 6;
//     std::cout << m(1, 1) << "\n";
//     //std::cout << m;

//     mt::Matrix u(3); // return 3x3 identity matrix
//     u(1, 1) = 1;
//     u(0, 2) = 1;
//     u(1, 0) = 1;
//     mt::Matrix r = m + u;
//     std::cout << r;

//     //   for (int i = 0; i < m.rows(); ++i) {
//     //     for (int j = 0; j < m.cols(); ++j) {
//     //       std::cout << m(i, j) << ' ';
//     //     }
//     //     std::cout << '\n';
//     //   }
//     return 0;
// }
// #include "Matrix.hpp"

#include <iostream>
// #include <vector>

// namespace mt
// {
    


// class Matrix
// {
// public:
//     explicit Matrix(int size)
//     :   m_size(size)
//     {
//         m_vec = std::vector<std::vector<int>>(size,std::vector<int>(size));
//     }

//     int& operator()(int i,int j)
//     {
//         return m_vec[i][j];
//     }

//     int getSize() const;
//     std::vector<std::vector<int>> getVec() const;

    

    
// private:
//     int m_size;
//     std::vector<std::vector<int>> m_vec;
// };

// Matrix operator+(const Matrix &m1,const Matrix &m2)
// {
//     if (m1.getSize() != m2.getSize()) {
//         throw std::runtime_error(" The matrixes have a different size!!! ");
//     }
    
//     Matrix result(m1.getSize());
//     for (size_t i = 0; i < m1.getSize(); ++i) {
//         for (size_t j = 0; j < m1.getSize(); ++j) {
//             result(i, j) = m1.getVec()[i][j] + m2.getVec()[i][j];
//         }
//     }
//     return result;
// }

// std::ostream& operator<<(std::ostream& os, const Matrix& m)
// {
//     for (size_t i = 0; i < m.getSize(); ++i) {
//         for (size_t j = 0; j < m.getSize(); ++j) {
//            os << m.getVec()[i][j] << " ";
//         }
//         os << "\n";
//     }
//     return os;
// }

// Matrix identity(int size)
// {
//     Matrix m(size);
//     for (size_t i = 0; i < m.getSize(); i++) {
//         m(i,i) = 1;
//     }
//     return m;
// }

// int Matrix::getSize() const
// {
//     return m_size;
// }

// std::vector<std::vector<int>> Matrix::getVec() const
// {
//     return m_vec;
// }

// } // namespace mt

// int main() {
//   mt::Matrix m(3);
//   m(1, 1) = 4;
//   m(1, 1) *= 2;
//   std::cout << m(1, 1) << std::endl;
//   mt::Matrix u = mt::identity(3);
//   mt::Matrix r = m + u;
//   std::cout << r << std::endl;
//   return 0;
// }
#include <vector>

template<typename C>
typename C::value_type sum(C &collection)
{
    typename C::iterator it = collection.begin(); 
    typename C::iterator end = collection.end() - 1;
    int total = *it;
    while (it != end) {
        total += *(++it);
    }
    return total;
}

void no_swap(int a, int b)
{
    int orgA = a;
    int orgB = b;
    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << a << "," << b << ".\n------------------\n";

    orgA = orgA^orgB;
    orgB = orgA^orgB;
    orgA = orgA^orgB;
    
    std::cout << orgA << "," << orgB << ".\n------------------\n";
}

int main()
{
    no_swap(5,3);
    // std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

    // std::cout << sum(vec) << "\n";

    return 0;
}