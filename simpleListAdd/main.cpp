#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* _firstNode = NULL;

    ListNode* addNode(ListNode* curNode, ListNode* newNode)
    {
        if(_firstNode == NULL)
        {
            _firstNode = newNode;
            return _firstNode;
        }

        curNode->next = newNode;

        return newNode;
    }

    ListNode* addNodes(ListNode* l1, ListNode* l2)
    {
        bool gtt = false;
        ListNode* node = NULL;

        while(l1 != NULL || l2 != NULL)
        {
            int res = gtt ? 1 : 0;
            gtt = false;

            if(l1 != NULL)
            {
                res += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                res += l2->val;
                l2 = l2->next;
            }

            if(res >= 10)
            {
                gtt = true;
                res -= 10;
            }

            node = addNode(node, new ListNode(res));
        }

        if(gtt) addNode(node, new ListNode(1));

        return _firstNode;
    }

    int readNumber(ListNode* l1)
    {
        int i = 1;
        int res = 0;

        while(l1 != NULL)
        {
            res += l1->val * i;

            l1 = l1->next;
            i *= 10;
        }

        return res;
    }

    ListNode* createNode(const std::string& str, int n)
    {
        if(n < 1) return nullptr;

        ListNode* node = new ListNode(int(str[n - 1]) - 48);

        node->next = createNode(str, n - 1);

        return node;
    }

    ListNode* writeNumber(int val)
    {
        std::string str = std::to_string(val);

        return createNode(str, str.size());
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int a = readNumber(l1);
        int b = readNumber(l2);

        return writeNumber(a + b);
    }
};

int main()
{
    Solution sol;

    ListNode* l1 = sol.createNode("123", 3);
    ListNode* l2 = sol.createNode("321", 3);
    ListNode* l3 = sol.addNodes(l1, l2);
    int a = sol.readNumber(l3);

    cout << a << endl;

    return 0;
}
