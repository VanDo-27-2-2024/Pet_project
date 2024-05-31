#include <iostream>



using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
    public:
        // support: insert a node in any valid position
        // idea to implement: link (n - 1)node to new node, and link new node to (n + 1)node
        void insert(int _data, int pos)
        {
            node* temp = new node;
            temp->data = _data;
            temp->next = NULL;

            if (pos == 1)
            {
                temp->next = head;
                head = temp;
                return;
            }

            node* temp1 = head;
            // position: [1] [2] [..x..] [4]
            for (int i = 1; i < (pos - 1); i++)
            {
                temp1 = temp1->next;
            }
            temp->next = temp1->next;
            temp1->next = temp;
        }

        // Remove element in any position
        void remove(int index)
        {
            node* temp = head;
            if (index == 1)
            {
                head = temp->next;
                delete (temp);
                return;
            }
            for (int i = 1; i < (index - 1); i++)
            {
                temp = temp->next;
            }
            node*temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }

        // Reverse linked list - Iterrative method
        void reverse()
        {
            node* temp = nullptr;
            node* current = head;
            node* prev = nullptr;
            node* next = nullptr;
            while(current != nullptr)
            {
                next  = current->next;
                current->next = prev;

                prev = current;
                current = next;
            }
            head = prev;
        }

        void reverse_recursive(node* temp)
        {
            // to do stop recursive
            if (temp->next == nullptr)
            {
                head = temp;
                return;
            }

            reverse_recursive(temp->next);
            temp->next->next = temp;
            temp->next =nullptr;
        }

        // Print linked list using recursive
        void print_recursive(node* tmp)
        {
            if (tmp == nullptr)
            {
                cout << endl;
                return;
            }

            cout << tmp->data << "->";
            print_recursive(tmp->next);
        }

        void print()
        {
            node* temp = head;

            cout << "List: " ;
            while (temp != NULL)
            {
                cout << " " << temp->data;
                temp = temp->next;
            }
            cout << "\n";
        }

        node* get_head()
        {
            return head;
        }

    private:
        node* head = NULL;
};


int main()
{
    linked_list list;
    list.insert(1, 1);
    list.insert(3, 2);
    list.insert(5, 3);
    list.insert(7, 4);
    list.insert(9, 5);

    node* tmp = list.get_head();
    list.reverse_recursive(tmp);

    //get new head after reverse list
    tmp = list.get_head();
    list.print();
    list.print_recursive(tmp);


    // list.reverse();
    // list.print();

    return 0;
}