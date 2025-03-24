#include <gtest/gtest.h>
#include <root/util/linked_list.hpp>

using namespace corvine;

struct TestClass {
    TestClass() {}
};

class LinkedListTest : public testing::Test
{

protected:
    LinkedListTest() {

        object0_ = TestClass();
        object1_ = TestClass();
        object2_ = TestClass();
    
        node0_ = LinkedList<TestClass>::Node(object0_);
        node1_ = LinkedList<TestClass>::Node(object1_);
        node2_ = LinkedList<TestClass>::Node(object2_);
    
        // linking nodes together
        node0_.next = &node1_;
        node1_.next = &node2_;

        list0_ = LinkedList<TestClass>();
        list1_ = LinkedList<TestClass>(node2_);
        list2_ = LinkedList<TestClass>(node1_);
        list3_ = LinkedList<TestClass>(node0_);
    }

    TestClass object0_ ;
    TestClass object1_;
    TestClass object2_;

    LinkedList<TestClass>::Node node0_;
    LinkedList<TestClass>::Node node1_;
    LinkedList<TestClass>::Node node2_;

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

TEST_F(LinkedListTest, TestHead)
{
    EXPECT_EQ(list0_.getHead(), nullptr);
    EXPECT_EQ(list1_.getHead(), &node2_);
    EXPECT_EQ(list2_.getHead(), &node1_);
    EXPECT_EQ(list3_.getHead(), &node0_);
}

TEST_F(LinkedListTest, TestGet)
{
    EXPECT_EQ(list1_.get(0), &object2_);

    EXPECT_EQ(list2_.get(0), &object1_);
    EXPECT_EQ(list2_.get(1), &object2_);

    EXPECT_EQ(list3_.get(0), &object0_);
    EXPECT_EQ(list3_.get(1), &object1_);
    EXPECT_EQ(list3_.get(2), &object2_);

    EXPECT_THROW(list0_.get(0), IndexOutOfBoundsException);

    EXPECT_THROW(list1_.get(-1), IndexOutOfBoundsException);
    EXPECT_THROW(list1_.get(1), IndexOutOfBoundsException);
}

TEST_F(LinkedListTest, TestAdd)
{
    list0_.add(object0_);
    EXPECT_EQ(list0_.size(), 1);
    EXPECT_EQ(list0_.getHead()->data, &object0_);

    TestClass *n = new TestClass();

    list0_.add(*n);
    EXPECT_EQ(list0_.size(), 2);
    EXPECT_EQ(list0_.getHead()->next->data, n);

    delete n;
    n = new TestClass();

    list0_.add(2, *n);
    EXPECT_EQ(list0_.size(), 3);
    EXPECT_EQ(list0_.getHead()->next->next->data, n);

    delete n;
    n = new TestClass();

    list0_.add(0, *n);
    EXPECT_EQ(list0_.size(), 4);
    EXPECT_EQ(list0_.getHead()->data, n);
    EXPECT_EQ(list0_.getHead()->next->data, &object0_);

    delete n;
    n = new TestClass();

    list0_.add(1, *n);
    EXPECT_EQ(list0_.size(), 5);
    EXPECT_EQ(list0_.getHead()->next->data, n);
    EXPECT_EQ(list0_.getHead()->next->next->data, &object0_);

    delete n;
}