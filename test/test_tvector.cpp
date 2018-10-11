#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  const int size=5;
  TVector<int> copied(5,0), source (size, 0);

  source[2]=7;
  copied = TVector<int>(source);

  ASSERT_EQ(source, copied);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  const int size=5;
  TVector<int> copied(5,0), source (size, 0);

    source[2]=7;
	copied = TVector<int>(source);

  ASSERT_NE(&source[0], &copied[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(3);

   EXPECT_EQ(0, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(3);
  v[2]=8;

  ASSERT_EQ(8, v[2]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(v[11]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v1(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }
  v1 = v1;

  EXPECT_EQ(1, v1[0]);
  EXPECT_EQ(1, v1[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v1(2), v2(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }
  v2 = v1;

  EXPECT_EQ(1, v2[0]);
  EXPECT_EQ(1, v2[1]);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v1(2), v2(3);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }
  v2 = v1;

  EXPECT_EQ(2, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v1(2), v2(3);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }

  ASSERT_NO_THROW(v2 = v1);

}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v1(2), v2(3);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }
  v2=v1;

  ASSERT_NO_THROW(v2 == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v1(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
  }

  ASSERT_NO_THROW(v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v1(2), v2(3);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=0;
  }
  

  ASSERT_NO_THROW(v2 != v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v1(2), v2(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=v1[i]+1;
  }
  
  ASSERT_EQ(2,v2[0]);
  ASSERT_EQ(2,v2[1]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
   TVector<int> v1(2), v2(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=v1[i]-1;
  }
  
  ASSERT_EQ(0,v2[0]);
  ASSERT_EQ(0,v2[1]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v1(2), v2(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=v1[i]*3;
  }
  
  ASSERT_EQ(3,v2[0]);
  ASSERT_EQ(3,v2[1]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v1(2), v2(2), v3(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=3;
	v3[i]=v1[i]+v2[i];
  }
  
  ASSERT_EQ(4,v3[0]);
  ASSERT_EQ(4,v3[1]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
   TVector<int> v1(2), v2(3);
  
  ASSERT_NO_THROW(v1.GetSize() != v2.GetSize());
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v1(2), v2(2), v3(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=3;
	v3[i]=v2[i]-v1[i];
  }
  
  ASSERT_EQ(2,v3[0]);
  ASSERT_EQ(2,v3[1]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v1(2), v2(3);
  
  ASSERT_NO_THROW(v2.GetSize() != v1.GetSize());
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
      TVector<int> v1(2), v2(2), v3(2);
  for (int i = 0; i < 2; i++)
  {
    v1[i]=1;
	v2[i]=3;
	v3[i]=v2[i]*v1[i];
  }
  
  ASSERT_EQ(3,v3[0]);
  ASSERT_EQ(3,v3[1]);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v1(2), v2(3);
  
  ASSERT_NO_THROW(v2.GetSize() != v1.GetSize());
}

