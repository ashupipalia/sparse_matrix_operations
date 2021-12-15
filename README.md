# sparse_matrix_operations
Introduction-
If most of the elements in the matrix are zero, then the matrix is called a sparse matrix.
Here I implement in code addition transpose and multiplication operations.
I used a compressed sparse row (CSR) for solving the problem.

![image](https://user-images.githubusercontent.com/76839986/132803355-0da8fb56-4ce3-4c57-8bd9-51837938576b.png)

I used data structure for storing the row, column, and matrix values stored in Adjacency List form where a row is a vector and each row contains the vector of pairs where each pair is column and value.
random_gen_matrix() -> this method give random coordinates and and each have random values.

#Sparse Matrix Addition and multiplication Result:

![image](https://user-images.githubusercontent.com/76839986/132906989-53958067-00eb-44c5-8481-105fec67405f.png)

#Conclusions:
Space complexity - O(n+m+x+y) -- Here x and y respectively are the total numbers of matrix A and matrix B. 
time complexity of addition is  - O(n(k)) -- where k <= x+y-x∩y .
time complexity of multiplication - O(n(p*(k)) -- where k <= x+y-x∩y 
