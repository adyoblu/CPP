#include <iostream>
#include <vector>
#define FOR(n) for(int i = 0; i < n; ++i)
#include <string>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(NULL) {}

      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

  };

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* s = new ListNode();
        ListNode* p = s;
            int i = 0;
            while(true){
                s->val += l1->val + l2->val + i;
                i = 0;
                if (s->val > 9){
                    i=1;
                    s->val -= 10;
                }
                l1 = l1->next;
                l2 = l2->next;
                if(l1 == NULL || l2==NULL) break;
                    s->next = new ListNode();
                    s = s->next;
            }

            while (l2 != NULL){
                s->next = new ListNode();
                s= s->next;
                s->val += l2->val + i;
                i=0;
                if(s->val > 9){
                    s->val -= 10;
                    i = 1;
                }
                l2 = l2->next;
            }
            while (l1 != NULL){
                s->next = new ListNode();
                s= s->next;
                s->val += l1->val + i;
                i=0;
                if(s->val > 9){
                    s->val -= 10;
                    i = 1;
                }
                l1 = l1->next;
            }
            if(i == 1) {s->next = new ListNode(); s= s->next; s->val = 1;}
            return p;
        }
};
int main(){
    ListNode *head, *second, *third, *fourth, *fifth, *sixth, *tail;
    ListNode *head1, *second1, *third1, *tail1, *sum1;
    Solution a;
    int x, y, z, x1, y1, z1, xx, yy, zz, xxx, a1;

    cout<<"Primul nod: "; cin>>x;
    cout<<"Al doilea nod: "; cin>>y;
    cout<<"al treilea nod: "; cin>>z;
    cout<<"al patrulea: "; cin>> xx;
    cout<<"Al 5-lea nod: "; cin>>yy;
    cout<<"Al 6-lea nod: "; cin>>zz;
    cout<<"Al 7-lea nod: "; cin>>xxx;

    cout<<endl;

    tail = new ListNode(xxx);
    sixth = new ListNode(zz, tail);
    fifth = new ListNode(yy, sixth);
    fourth = new ListNode(xx, fifth);
    third = new ListNode(z, fourth);
    second = new ListNode(y, third);
    head = new ListNode(x, second);

    cout<<"Primul nod: "; cin>>x1;
    cout<<"Al doilea nod: "; cin>>y1;
    cout<<"Al treilea nod: "; cin>>a1;
    cout<<"Ultimul nod: "; cin>>z1;


    cout<<endl;

    tail1 = new ListNode(z1);
    third1 = new ListNode(a1, tail1);
    second1 = new ListNode(y1, third1);
    head1 = new ListNode(x1, second1);


    sum1 = a.addTwoNumbers(head, head1);
    while (sum1 != NULL){
        cout << sum1->val;
        sum1 = sum1->next;
    }


    return 0;
}