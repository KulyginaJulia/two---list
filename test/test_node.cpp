#include "node1.h"

#include <gtest.h>
TEST(Node, Can_create_node){
	ASSERT_NO_THROW(Node m(5));
}

TEST(Node, Can_copy_node){
	Node n1(3);
	ASSERT_NO_THROW(Node n2(n1));
}

TEST(Node, can_set_and_get) {
 	int c = 3;
	Node n(c);
 	n.SetVar(10);
 	EXPECT_EQ(10, n.GetVar());
}