#include <iostream>
#include <vector>

namespace mt {

    class Matrix {
    public:
        Matrix(int size) 
        : m_size(size)
        {
            m_vec = std::vector<std::vector<double>>(size
                            , std::vector<double>(size)
                            );
        }
        double& operator()(int i, int j);
        double operator()(int i, int j) const;
        int getSize() const;
        std::vector<std::vector<double>> getVec() const;

    private:
        int m_size;
        std::vector<std::vector<double>> m_vec;
    };

    std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int i = 0; i < m.getSize(); ++i) {
        for (int j = 0; j < m.getSize(); ++j) {
            os << m.getVec()[i][j] << " ";
        }
        os << "\n";
        }
        return os;
    }


    Matrix identity(int size) {
    Matrix m(size);
    for (int i = 0; i < size; ++i) {
        m(i, i) = 1;
    }
    return m;
    }

}  // namespace mt
