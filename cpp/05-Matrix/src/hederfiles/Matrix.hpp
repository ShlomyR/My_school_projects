#include <iostream>

struct Index{
    Index(int i, int j){}
};

class Matrix {
public:
    Matrix();
    //Matrix() : m_rows(0), m_cols(0) ,m_init(0) {}
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double init);
    //~dtor
    int n;
    
    //   at(const Matrix* this, int, int)
    const int& at(int i, int j) const;
    //   at(Matrix* this, int, int)
    int& at(int i, int j);

    const int& operator[](int i) const;
    int& operator[](int i);    

    const int& operator[](Index i) const;   
    int& operator[](Index i);

    int count(double x);

    void getNum(int x)
    {
        n = x;
    }

    void dispNum(void)
    {
        std::cout << "Number is: " << n << "\n";
    }
    
    // Overload the + operator
    Matrix operator+ (const Matrix& obj);

private:
    int* m_data;    
    const int m_rows;
    const int m_cols;
    const double m_init;
    int m_count = 0;
};
