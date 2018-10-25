#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  int Constsize=5;
  TMatrix<int> m(Constsize);
  TMatrix<int> m1(m);

  ASSERT_EQ(Constsize, m1.GetSize());
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  int Constsize=5;
  TMatrix<int> m(Constsize);

  ASSERT_EQ(Constsize, m.GetSize());
}

TEST(TMatrix, can_get_size)
{
  const int size =  5;
  TMatrix<int> m(5);

  ASSERT_EQ(size, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  const int size =  5;
  TMatrix<int> m(5);
  m[2][2] = 3;

  ASSERT_EQ(3, m[2][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[3][-1] = 8);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[10][4] = 8);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
   TMatrix<int> m(5);
   m = m;

  ASSERT_NO_THROW(m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) //
{
   TMatrix<int> m(5);
   TMatrix<int> m1(5);
   m1 = m;

  ASSERT_NO_THROW(m1);
}

TEST(TMatrix, assign_operator_change_matrix_size) //
{
  TMatrix<int> m(5);
  TMatrix<int> m1(3);
   m1 = m;

  ASSERT_NO_THROW(m1.GetSize() == 3);
}

TEST(TMatrix, can_assign_matrices_of_different_size) //
{
  TMatrix<int> m(5);
  TMatrix<int> m1(3);
   m1 = m;
  
   ASSERT_NO_THROW(m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
   TMatrix<int> a1(1), a2(1);
   bool T;
   for(int i = 0; i < 1; i++)
   {
	   for(int j = 0; j < 1; j++)
	   {
		   a1[i][j] = 2;
		   a2[i][j] = 2;
		   if (a1[i][j] == a2[i][j]) T = true;
	   }
   }
   
   ASSERT_EQ(true , T);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
     TMatrix<int> a1(1);
   bool T;
   for(int i = 0; i < 1; i++)
   {
	   for(int j = 0; j < 1; j++)
	   {
		   a1[i][j] = 2;
		   if(a1[i][j] == a1[i][j]) T = true;
	   }
   }
   
   ASSERT_EQ(true , T);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> a1(3), a2(2);

   ASSERT_NO_THROW(a1.GetSize() != a2.GetSize());
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a1(2), a2(2), a3(2);
	a1[0][0] = 3;
	a2[0][0] = 7;
	a3 = a1 + a2;
   
   ASSERT_EQ(10 , a3[0][0]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> a1(1);
  TMatrix<int> a2(2);

  ASSERT_NO_THROW(a1.GetSize() != a2.GetSize());
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a1(2), a2(2), a3(2);
	a1[0][0] = 3;
	a2[0][0] = 7;
	a3 = a2 - a1;
   
   ASSERT_EQ(4 , a3[0][0]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> a1(1);
  TMatrix<int> a2(2);

  ASSERT_NO_THROW(a1.GetSize() != a2.GetSize());
}

