/* 
 * File:   mylinkedlist.h
 * Author: transformer
 *
 * Created on June 27, 2015, 8:54 PM
 */

#ifndef MYLINKEDLIST_H
#define	MYLINKEDLIST_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<tr1/unordered_set>
using namespace std;
struct node
{
    int info;
    struct node *next;
}*start;

class single_linked_list
{
public:
    node* create_node(int);
    void insert_begin(int);
    void insert_last(int);
    void mingle_list();
    void print_list();
    node* get_middle();
    void remove_duplicates();
    void remove_duplicates_without_buffer();
    single_linked_list()
    {
	start = NULL;
    }

};

node* single_linked_list::create_node(int data)
{
    struct node *temp = new(struct node);
    temp->info = data;
    temp->next = NULL;
    return temp;
}

void single_linked_list::insert_begin(int data) 
{
    struct node *newnode = create_node(data);
    if(start == NULL)
    {
	start = newnode;
    }
    else
    {
	newnode->next = start;
	start = newnode;
    }
    
}

void single_linked_list::insert_last(int data)
{
    struct node *newnode = create_node(data);     
    if(start == NULL)
    {
	start = newnode;
    }
    else
    {
	struct node *temp = start;
	while(temp->next)
	{
	    temp = temp->next;
	}
	temp->next = newnode;
    }
}


void single_linked_list::print_list()
{
    if(start==NULL) return;
    struct node* temp = start;
    while(temp)
    {
	cout << temp->info << " ";
	temp=temp->next;
    }
}

node* single_linked_list::get_middle()
{
    //assuming the list has even number of elements;
    if(start == NULL)
	return NULL; 
    struct node *fast_runner = start;
    struct node *slow_runner = start;
    while(fast_runner && fast_runner->next)
    {
	fast_runner = fast_runner->next->next;
	slow_runner = slow_runner->next;
    }
    return slow_runner;
}

void single_linked_list::mingle_list()
{
    if(start == NULL)
	return;
    struct node* middle_element = get_middle();
    struct node *start_element  = start;
    struct node *next_start, *next_middle;
    while(middle_element)
    {
	next_start = start_element->next; 
	next_middle = middle_element->next;
	start_element->next = middle_element;
	middle_element->next = next_start;
	start_element = next_start;
	if(!next_middle)
	    break;
	middle_element = next_middle;
    }
    middle_element->next = NULL;
}

void single_linked_list::remove_duplicates()
{
    if(!start) return;
    node *temp1 = start;
    std::tr1::unordered_set<int> myset;
    myset.insert(temp1->info);
    while(temp1 && temp1->next) 
    {
	if(myset.find(temp1->next->info) == myset.end())
	{
	    myset.insert(temp1->next->info);
	    temp1 = temp1->next;
	    continue;
	}
	node *temp2 = temp1->next;
	while(temp2 && myset.find(temp2->info) != myset.end())
	{
	    temp2 = temp2->next;
	}
	temp1->next = temp2;
	temp1 = temp2;
    }
}

void single_linked_list::remove_duplicates_without_buffer()
{
    if(!start) return;
    node *temp1 = start;
    while(temp1)
    {
	node *temp2 = temp1;
	while(temp2)
	{
	    while(temp2->next && temp2->next->info == temp1->info)
	    {

		temp2->next = temp2->next->next;
	    }
	    temp2 = temp2->next;

	}
	temp1 = temp1->next;
    }
}
#endif	/* MYLINKEDLIST_H */

