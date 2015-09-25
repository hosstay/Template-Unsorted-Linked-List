/*****************************************************************************
   Taylor Hoss
   X432Z869
   Program #4

   This program implements a linked list class in which a users input
   is made into a node which is inserted at the end of the list. When
   given the command it goes through the nodes and outputs their data.
   This class has been implemented with templates to allow it to be used
   with any data types.

   Psuedo Code
      Class Name: Linked_list
      Data:
         head                 - pointer to the first item in the list
         tail                 - pointer to the last item in the list
      Mutator Functions:
         Linked_list          - defualt initialization of the pointers
         insert_node          - inserts a node to the end of the list
      Accessor Functions:
         traverse             - iterates through the list and gets data

*/

#include "node.hpp"

// Linked list class
template <class Type>
class Linked_list
{
   Node<Type> *head, *tail;
 public:
   Linked_list();
   bool insert_node(Type data); 
   void traverse();   
};

// Constructor to initialize the linked list.
template <class Type>
Linked_list<Type>::Linked_list()
{
   head = tail = NULL;

}

// Insert a node in the list.
template <class Type>
bool Linked_list<Type>::insert_node(Type data)
{
   // Create a node.
   Node<Type> *node_ptr = new Node<Type>(data);

   // If there are no entries in the linked list add it to the head.
   if (head == NULL)
   {
      tail = head = node_ptr;
   }
   else
   {
      //otherwise just add it to the end of the list.
      tail->set_link(node_ptr);
      tail = node_ptr;
   }
   
   return true;
}

// Go through the entire list. Call the node method to show the data.
template <class Type>
void Linked_list<Type>::traverse()
{
   Node<Type> *temp;
   temp = head;
   while (temp != NULL)
   {
      temp->show_data();
      temp = temp->get_link();
   }     
}

