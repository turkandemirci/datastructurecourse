#include <cstdlib>
#include <iostream>

using namespace std;

namespace ceng112{

template <typename T>
class Stack {
public:
        Stack (){m_size=0;m_head=0;}
        ~Stack(){ delete m_head;}
        void push(const T& data);
        T pop();
        size_t size()  {  return m_size; }
       
        
        
private:
        struct Node{
        T data;
        Node *next;
        };
        Node *m_head;
        size_t m_size;
};

template <typename T>
void Stack<T>::push(const T& data)
{
        Node *new_node=new Node;
        new_node-> data=data;
        if(m_head==0){
        m_head=new_node;
        new_node->next=0;
 
        }else{
         new_node->next=m_head;
         m_head=new_node;
        }
        m_size++;  
}

template <typename T>
T Stack<T>::pop() {
        if (m_head==0) {
                std::cerr << "Can not pop from an empty stack!" << std::endl;
                std::exit(EXIT_FAILURE);
        }
        T result=m_head->data;
        Node *temp;
        temp=m_head;
        m_head=m_head->next;
        delete temp;
        m_size--;
        return result;
      }
}




