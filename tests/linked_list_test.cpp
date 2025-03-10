#include <gtest/gtest.h>
#include <root/util/linked_list.hpp>

#define LinkedList corvine::LinkedList

struct TestClass
{
    int value;

    TestClass(int value) : value(value) {}
};

class LinkedListTest : public testing::Test
{

protected:
    LinkedListTest()
    {
        node0_.next = &node1_;
        node1_.next = &node2_;

        list0_ = LinkedList<TestClass>();
        list1_ = LinkedList<TestClass>(&node2_);
        list2_ = LinkedList<TestClass>(&node1_);
        list3_ = LinkedList<TestClass>(&node0_);
    }

    LinkedList<TestClass>::Node node0_ = LinkedList<TestClass>::Node(TestClass(0));
    LinkedList<TestClass>::Node node1_ = LinkedList<TestClass>::Node(TestClass(1));
    LinkedList<TestClass>::Node node2_ = LinkedList<TestClass>::Node(TestClass(2));

    LinkedList<TestClass> list0_;
    LinkedList<TestClass> list1_;
    LinkedList<TestClass> list2_;
    LinkedList<TestClass> list3_;
};

TEST_F(LinkedListTest, TestSize)
{
    EXPECT_EQ(list0_.size(), 0);
    EXPECT_EQ(list1_.size(), 1);
    EXPECT_EQ(list2_.size(), 2);
    EXPECT_EQ(list3_.size(), 3);
}

TEST_F(LinkedListTest, TestGet)
{
    EXPECT_EQ(list3_.get(0).value, 0);
    EXPECT_EQ(list3_.get(1).value, 1);
    EXPECT_EQ(list3_.get(2).value, 2);

    EXPECT_THROW(list0_.get(-1), LinkedList<TestClass>::IndexOutOfBoundsException);
    EXPECT_THROW(list0_.get(1), LinkedList<TestClass>::IndexOutOfBoundsException);
}

TEST_F(LinkedListTest, TestAdd)
{
    list0_.add(TestClass(0));
    EXPECT_EQ(list0_.size(), 1);
    EXPECT_EQ(list0_.get(0).value, 0);

    list0_.add(TestClass(1));
    EXPECT_EQ(list0_.size(), 2);
    EXPECT_EQ(list0_.get(1).value, 1);

    list0_.add(2, TestClass(2));
    EXPECT_EQ(list0_.size(), 3);
    EXPECT_EQ(list0_.get(2).value, 2);

    list0_.add(0, TestClass(69));
    EXPECT_EQ(list0_.size(), 4);
    EXPECT_EQ(list0_.get(0).value, 69);
    EXPECT_EQ(list0_.get(1).value, 0);
    EXPECT_EQ(list0_.get(2).value, 1);
    EXPECT_EQ(list0_.get(3).value, 2);

    list0_.add(1, TestClass(420));
    EXPECT_EQ(list0_.size(), 5);
    EXPECT_EQ(list0_.get(0).value, 69);
    EXPECT_EQ(list0_.get(1).value, 420);
    EXPECT_EQ(list0_.get(2).value, 0);
    EXPECT_EQ(list0_.get(3).value, 1);
    EXPECT_EQ(list0_.get(4).value, 2);
}