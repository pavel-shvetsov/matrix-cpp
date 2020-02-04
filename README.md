## Simple C++ Matrix impementation

### Testing environment
* Ubuntu 18.04
* CMake 2.10.2
* g++ 7.4.0
* git 2.17.1

### Build and run demo app
```shell script
sudo apt-get update
sudo apt-get install build-essential git cmake
cd ~/
git clone https://github.com/pavel-shvetsov/matrix-cpp.git
mkdir matrix-cpp/build && cd matrix-cpp/build
cmake .. && make
./matrix
```

### Class usage
Basic usage example could be seen in `main.cpp` source file

#### Instantiation
There are two classes `test::mat` and `test::vec` for matrix and vector objects respectively.
* Rows/Cols number for mat (zero-initialization): `test::mat m(2,3)`
* Elements number for vec (zero-initialization): `test::vec v(8)`
* 2d Initializer list for matrices: `test::mat m{ {1, 2, 3}, {4, 5, 6} }`
* 1d Initializer list for matrices: `test::vec v{1, 2, 3, 4, 5, 6}`
* Copy constructor: `test::mat B(test::mat &A)`

#### Supported features
* Matrix-matrix, matrix-vector multiplication: `mat3 = mat1 * mat2`, `mat2 = mat1 * vec1`
* Matrix-matrix addition: `mat3 = mat1 + mat2`
* Scalar multiplication for both matrix and vector: `mat2 = scalar * mat1`, `vec2 = vec1 * scalar`
* Subscript read/write: `mat[row][col]`, `vec[idx]`
* Standard output: `std::cout << mat;`

#### Limitations
* Vectors are by default vertical
* No `transpose` operation is supported
* No linear algebra functions are supported, like `inverse`, `determinant`, `svd`, etc.