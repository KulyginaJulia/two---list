#include "list1.h"
#include "node1.h"

#include <gtest.h>

TEST(List, Can_create_list){
	ASSERT_NO_THROW(List p);
}

TEST(List, Can_copy_list){
	List p;
	Node *f = new Node(2);
	p.InsertBeforeHead(f);

	List p1(p);
	EXPECT_EQ(p1.head->var, p.head->var);
}

TEST(List, Can_add_elem){
	List p;
	p.InsertOrdered(4);
	p.InsertOrdered(6);
	p.InsertOrdered(5);

	EXPECT_EQ(4, p.head->var);
	EXPECT_EQ(5, p.head->next->var);
	EXPECT_EQ(6, p.head->next->next->var);
}

TEST(List, Can_copy_list2){
	List p;
	p.InsertOrdered(4);
	p.InsertOrdered(6);
	p.InsertOrdered(5);

	List p1(p);
	EXPECT_EQ(4, p1.head->var);
	EXPECT_EQ(5, p1.head->next->var);
	EXPECT_EQ(6, p1.head->next->next->var);
}

TEST(List, Can_equal_list){
	List p;
	p.InsertOrdered(4);
	p.InsertOrdered(6);
	p.InsertOrdered(5);

	List p1 = p;

	EXPECT_EQ(4, p1.head->var);
	EXPECT_EQ(5, p1.head->next->var);
	EXPECT_EQ(6, p1.head->next->next->var);
}

TEST(List, Can_equal_list2){
	List p;
	p.InsertOrdered(4);
	p.InsertOrdered(6);
	p.InsertOrdered(5);

	List p1;

	p1.InsertOrdered(-1);
	p1.InsertOrdered(2);
	p1.InsertOrdered(-5);

	p1 = p;

	EXPECT_EQ(4, p1.head->var);
	EXPECT_EQ(5, p1.head->next->var);
	EXPECT_EQ(6, p1.head->next->next->var);
}

TEST(List, Can_delete_list){
	List p;
	ASSERT_NO_THROW(p.DeleteList());
}

TEST(List, Can_insert_node_first){
	Node n1(3);
	List p;
	Node* f = new Node(3);
	p.InsertBeforeHead(f);

	EXPECT_EQ(n1.var, p.head->var);
}

TEST(List, Can_insert_list_middle){
	List p;
	Node *f = new Node(58);

	p.InsertBeforeHead(f);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	EXPECT_EQ(f->var, p.head->next->next->var);
	EXPECT_EQ(11, p.head->next->var);
	EXPECT_EQ(3, p.head->var);
}


TEST(List, Can_search){
	List p;
	Node *f = new Node;

	p.InsertOrdered(58);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	f = p.Search(58);
	EXPECT_EQ(f->var, 58);
}

TEST(List, Can_delete_node){
	List p;

	p.InsertOrdered(58);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	Node* f = p.Search(58);
	p.Delete(f, p.head);

	EXPECT_EQ(3, p.head->var);
	EXPECT_EQ(11, p.head->next->var);
}

TEST(List, Can_delete_first_node){
	List p;

	p.InsertOrdered(58);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	p.DeleteFirst();

	EXPECT_EQ(11, p.head->var);
	EXPECT_EQ(58, p.head->next->var);
}
TEST(List, Can_delete_first_node_with_key){
	List p;

	p.InsertOrdered(58);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	p.DeleteKey(3);

	EXPECT_EQ(11, p.head->var);
	EXPECT_EQ(58, p.head->next->var);
}
TEST(List, Can_not_delete_node_with_key){
	List p;

	p.InsertOrdered(58);
	p.InsertOrdered(3);
	p.InsertOrdered(11);

	ASSERT_ANY_THROW(p.DeleteKey(-1));
}