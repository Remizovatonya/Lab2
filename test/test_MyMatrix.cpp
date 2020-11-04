
#include "MyMatrix.h"
#include <gtest.h>



TEST(TMatrix, can_create_matrix)
{
    ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> A(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> A(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> A(5);

    ASSERT_NO_THROW(TMatrix<int> B(A));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> A(3), A1(A);
    EXPECT_EQ(A, A1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> A(3), A1(A);
    EXPECT_EQ(A, A1);
}

TEST(TMatrix, can_get_length)
{
    TMatrix<int> A(5);
    EXPECT_EQ(5, A.GetLength());
}

TEST(TMatrix, can_get_index)
{
    TMatrix<int> A(5);
    EXPECT_EQ(0, A.GetStartIndex());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> A(5);
    A[1][3] = 2;
    EXPECT_EQ(2, A[1][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> A(5);
    ASSERT_ANY_THROW(A[0][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> A(5);
    ASSERT_ANY_THROW(A[0][5]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> A(5);
    ASSERT_NO_THROW(A = A);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> A(5), B(5);
    ASSERT_NO_THROW(A = B);
}


TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> A(5), B(3);
    ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> A(5), B(A);
    ASSERT_EQ(A == B, true); 
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> A(5);
    ASSERT_EQ(A == A, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> A(5), B(3);
    ASSERT_EQ(A == B, false);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> A(5), B(5);
    ASSERT_NO_THROW(A + B);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> A(5), B(3);
    ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> A(5), B(5);
    ASSERT_NO_THROW(A - B);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> A(5), B(3);
    ASSERT_ANY_THROW(A - B);
}




//VECTOR
//VECTOR






TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> V(3));
}

TEST(TVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(Vector<int> V(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Vector<int> V(-3));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(Vector<int> V(5, -3));
}

TEST(TVector, can_create_copied_vector)
{
    Vector<int> V(10);

    ASSERT_NO_THROW(Vector<int> V1(V));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    Vector<int> V(10), V1(V);

    EXPECT_EQ(V, V1);

}

TEST(TVector, copied_vector_has_its_own_memory)
{
    Vector<int> V(5), V1(V);
    V1[0] = 10;

    EXPECT_NE(V[0], V1[0]);
}

TEST(TVector, can_get_length)
{
    Vector<int> V(4);

    EXPECT_EQ(4, V.GetLength());
}

TEST(TVector, can_get_start_index)
{
    Vector<int> V(6, 3);

    EXPECT_EQ(3, V.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
    Vector<int> V(5);
    V[0] = 5;

    EXPECT_EQ(5, V[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    Vector<int> V(5);

    ASSERT_ANY_THROW(V[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    Vector<int> V(5);

    ASSERT_ANY_THROW(V[10]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    Vector<int> V(5);

    ASSERT_NO_THROW(V = V);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    Vector<int> V(5), V1(5);

    ASSERT_NO_THROW(V = V1);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    Vector<int> V(5), V1(10);

    ASSERT_NO_THROW(V = V1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    Vector<int> V(5), V1(V);

    EXPECT_EQ(V == V1, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    Vector<int> V(5);

    EXPECT_EQ(V == V, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    Vector<int> V(5), V1(10);

    EXPECT_EQ(V == V1, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
    Vector<int> V(5);

    ASSERT_NO_THROW(V + 2);

}

TEST(TVector, can_add_vectors_with_equal_size)
{
    Vector<int> V(5), V1(5);

    ASSERT_NO_THROW(V + V1);
}

TEST(TVector, can_add_vectors_with_not_equal_size)
{
    Vector<int> V(5), V1(10);

    ASSERT_NO_THROW(V + V1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    Vector<int> V(5), V1(5);

    ASSERT_NO_THROW(V - V1);
}

TEST(TVector, can_subtract_vectors_with_not_equal_size)
{
    Vector<int> V(5), V1(10);

    ASSERT_NO_THROW(V - V1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    Vector<int> V(5), V1(5);

    ASSERT_NO_THROW(V * V1);
}

TEST(TVector, can_multiply_vectors_with_not_equal_size)
{
    Vector<int> V(5), V1(10);

    ASSERT_NO_THROW(V * V1);
}

TEST(TVector, can_add_scalar)
{
    Vector<int> V(5);
    int k = 3;
    ASSERT_NO_THROW(V + k);
}

TEST(TVector, can_subtract_scalar)
{
    Vector<int> V(5);
    int k = 4;
    ASSERT_NO_THROW(V - k);
}

TEST(TVector, can_multiply_scalar)
{
    Vector<double> V(5);
    double k = -1.5;
    ASSERT_NO_THROW(V * k);
}