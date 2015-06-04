//
//  main.cpp
//  leetcodepractice
//
//  Created by Liang Dong on 5/18/15.
//  Copyright (c) 2015 Liang Dong. All rights reserved.
//

/*Definition for singly-linked list.*/
#include <iostream>
#include<set>
#include<string>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* temp,*tempnext;
        temp=head->next;
        head->next=NULL;
        while(temp!=NULL)
        {
            tempnext=temp->next;
            temp->next=head;
            head=temp;
            temp=tempnext;
        }
        return head;
    }
};

class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        uint32_t temp=n;
        while(temp!=0)
        {
            sum+=temp%2;
            temp/=2;
        }
        return sum;
    }
};

/*happy number*/

class Solution3 {
public:
    bool isHappy(int n) {
        //return true;
        //std::cout<<"what's wrong"<<std::endl;
        int temp[20];
        std::set<int> sumset;
        int i=0,j;
        int ns=n;
        int sum=0;
        while(ns!=0)
        {
            temp[i]=ns%10;
            ns/=10;
            i++;
        }
        for(j=0;j<i;j++)
            sum+=temp[j]*temp[j];
        
        while(sum!=1&&(sumset.find(sum)==sumset.end()))
        {
            //std::cout<<sum<<std::endl;
            sumset.insert(sum);
            ns=sum;
            i=0;
            sum=0;
            while(ns!=0)
            {
                temp[i]=ns%10;
                ns/=10;
                i++;
            }
  
            for(j=0;j<i;j++)
                sum+=temp[j]*temp[j];
        }
        if(sum==1)
        return true;
        else
            return false;
    }
};
//Roman to integar
class Solution4 {
public:
    int romanToInt(string s) {
        int sum=0;
        int j;
        int i;
        for (i = 0 ; i < s.length(); i++)
        {
            if(s[i]=='I')
            {
                j=i+1;
                if(j<s.length())
                {
                    if(s[j]=='V')
                    {
                        sum+=4;
                        i=j;
                    }
                     else
                     {
                         if(s[j]=='X')
                         {
                             sum+=9;
                             i=j;
                         }
                         else
                             sum+=1;
                     }
                }
                else
                    sum+=1;
               // cout<<sum<<endl;
                
            }
            else
            {
                if(s[i]=='X')
                {
                    j=i+1;
                    if(j<s.length())
                    {
                        if(s[j]=='L')
                        {
                            sum+=40;
                            i=j;
                        }
                        else
                        {
                            if(s[j]=='C')
                            {
                                sum+=90;
                                i=j;
                            }
                            else
                                sum+=10;
                        }

                    }
                    else
                        sum+=10;
                   // cout<<sum<<endl;
                }
                else
                {
                    if(s[i]=='C')
                    {
                        j=i+1;
                        if(j<s.length())
                        {
                            if(s[j]=='D')
                            {
                                sum+=400;
                                i=j;
                            }
                            else
                            {
                                if(s[j]=='M')
                                {
                                    sum+=900;
                                    i=j;
                                }
                                else
                                    sum+=100;
                            }
                            
                        }
                        else
                            sum+=100;
                       // cout<<sum<<endl;
                    }
                    else
                    {
                        switch(s[i])
                        {
                            case 'V':
                                sum+=5;
                                break;
                            case 'L':
                                sum+=50;
                                break;
                            case 'D':
                                sum+=500;
                                break;
                            case 'M':
                                sum+=1000;
                                break;
                        }
                      //  cout<<sum<<endl;
                    }

                }

            }
        }
        return sum;
    }
    
    string intToRoman(int num){
        string temp;
        if(num>=1000)
            temp='M'+intToRoman(num-1000);
        else
            if(num>=900)
                temp="CM"+intToRoman(num-900);
            else
                if(num>=500)
                    temp='D'+intToRoman(num-500);
                else
                    if(num>=400)
                        temp="CD"+intToRoman(num-400);
                    else
                        if(num>=100)
                            temp='C'+intToRoman(num-100);
                        else
                            if(num>=90)
                                temp="XC"+intToRoman(num-90);
                            else
                                if(num>=50)
                                    temp='L'+intToRoman(num-50);
                                else
                                    if(num>=40)
                                        temp="XL"+intToRoman(num-40);
                                    else
                                        if(num>=10)
                                            temp='X'+intToRoman(num-10);
                                        else
                                        {
                                            switch(num)
                                            {
                                                case 1:
                                                    temp='I';
                                                    break;
                                                case 2:
                                                    temp="II";
                                                    break;
                                                case 3:
                                                    temp="III";
                                                    break;
                                                case 4:
                                                    temp="IV";
                                                    break;
                                                case 5:
                                                    temp="V";
                                                    break;
                                                case 6:
                                                    temp="VI";
                                                    break;
                                                case 7:
                                                    temp="VII";
                                                    break;
                                                case 8:
                                                    temp="VIII";
                                                    break;
                                                case  9:
                                                    temp="IX";
                                                    
                                            }
                                        }
        return temp;
        
    }
};



int testsolution()
{
    ListNode a(1),b(2),c(3),d(4);
    ListNode *node=new ListNode(0);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    node->next=&a;
    
    Solution sol;
    ListNode * tempNode1=node;
    while(tempNode1!=NULL)
    {
        std::cout<<tempNode1->val<<std::endl;
        tempNode1=tempNode1->next;
    }
    
    ListNode * nodeh=sol.reverseList(node);
    ListNode * tempNode=nodeh;
    while(tempNode!=NULL)
    {
        std::cout<<tempNode->val<<std::endl;
        tempNode=tempNode->next;
    }
    
    return 1;

}

int testsolutionHappy()
{
    Solution3 solution;
    bool mytemp=solution.isHappy(19);
    if(mytemp==true)
    std::cout<<"true"<<std::endl;
    else
        std::cout<<"false"<<std::endl;
    return 1;
}

int testsolutionroman()
{
    Solution4 solution;
    int temp=solution.romanToInt("MCMXCVI");
    cout<<temp<<endl;
    string mystr=solution.intToRoman(1990);
    cout<<mystr<<endl;
    return 1;
}

//swappairs
class Solution5 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * temp=head;
        if(head==NULL||head->next==NULL)
            return temp;
        ListNode* tempnext=temp->next,*temprevious;
        temp->next=tempnext->next;
        tempnext->next=temp;
        head=tempnext;
        temprevious=temp;
        temp=temp->next;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
            tempnext=temp->next;
            temp->next=tempnext->next;
            tempnext->next=temp;
            temprevious->next=tempnext;
            temprevious=temp;
            temp=temp->next;
            }
            else
                break;
        }
        return head;
    }
};

void testSwap()
{
    ListNode a(1),b(2),c(3),d(4);
    ListNode *node=new ListNode(0);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    node->next=&a;
    
    Solution5 solution;
    ListNode* temp=solution.swapPairs(node);
    
    ListNode * tempNode=temp;
    while(tempNode!=NULL)
    {
        std::cout<<tempNode->val<<std::endl;
        tempNode=tempNode->next;
    }


}

class Solution5 {
public:
    int majorityElement(vector<int>& nums) {
        
    }
};

int main(int argc, const char * argv[]) {
    testSwap();
    return 1;
}
