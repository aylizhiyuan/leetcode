# 算法导论


##  算法分析 | 渐进分析

给出两个任务的算法，我们如何找到哪一个更好?

通常对于我们来说，一个最简单的方法是实现这两种算法，在计算中运行两个程序以获得不同的输入，并查看哪一个花费更少的事件。这种算法分析方法存在很多问题

1. 对于某些输入，第一种算法可能会比第二种算法更好，然而对于另外一种输入，第二种算法可能比第一种算法性能更好
2. 对于一些输入，第一种算法在一台机器上表现更好，而另一种输入则在其他机器上运行的更好

渐进分析就是为了解决上述问题的重要思想。在渐进分析中，我们会根据输入大小来评估算法的性能(我们不测量实际的运行时间)。我们计算算法的时间(或者)空间如何随输入大小而增加。例如，让我们考虑在已排序数组中的搜索问题(搜索给定的项)。搜索的一种方法是线性搜索(增长顺序是线性的)，而另一种是二进制搜索(增长顺序是对数)

为了了解渐近分析如何解决上述分析算法中的问题，现在我们假设在快速计算机上运行线性搜索和在较慢速是计算机上运行二进制搜索。

对于输入数组大小为很小的值的时候，快速计算机可能需要更少的时间。但是，在输入数组大小的某个值之后，即使二进制搜索在慢速计算机上运行，​​二进制搜索很明显地会比线性搜索花费更少的时间。

原因是二进制搜索在输入大小对数方面的增长顺序，而线性搜索的增长顺序是线性的。因此，在输入值的某些值之后，总是可以忽略与机器相关的常量。


## 算法分析 | 最差、平均和最佳

我们可以有三种情况来分析算法：

1. 最差情况
2. 平均情况
3. 最佳情况

示例代码:

    #include <stdio.h>
    
    // Linearly search x in arr[].  If x is present then return the index,
    // otherwise return -1
    int search(int arr[], int n, int x)
    {
        int i;
        for (i=0; i<n; i++)
        {
        if (arr[i] == x)
            return i;
        }
        return -1;
    }
    
    /* Driver program to test above functions*/
    int main()
    {
        int arr[] = {1, 10, 30, 15};
        int x = 30;
        int n = sizeof(arr)/sizeof(arr[0]);
        printf("%d is present at index %d", x, search(arr, n, x));
    
        getchar();
        return 0;
    }　

最坏情况分析(通常完成)

在最坏的情况分析中，我们计算算法运行时间的上限。我们必须知道可以执行最大操作数的情况。在线性搜索，最糟糕的情况就是当要搜索的元素不存在数组中的时候，当x不存在的时候,search函数会将它与arr[]的所有元素逐一比较，因此，线性搜索的最差情况将为Θ(n)

平均情况分析(有时完成)

在平均案例分析中，我们采取所有可能的输入并计算所有输入的计算时间。将所有计算值求和，并将综合除以总输入数。

最佳案例分析

在最佳案例分析中，我们计算算法运行时间的下限。我们必须知道导致执行最少操作数的情况。在线性搜索问题中，当x存在于第一位置时，出现最佳情况。在最佳情况下的操作次数是常数（不依赖于n）。所以在最好的情况下，时间复杂度将是Θ（1）

大多数时候，我们做最坏的情况分析来分析算法。在最差的分析中，我们保证算法运行时间的上限是一个很好的信息。
平均案例分析在大多数实际案例中是不容易的，很少做到。在平均案例分析中，我们必须知道（或预测）所有可能输入的数学分布。
最佳案例分析是假的。确保算法的下限不提供任何信息，如在最坏的情况下，算法可能需要多年才能运行。

对于一些算法，所有情况都是渐近相同的，即没有最差和最好的情况。例如，合并排序。合并排序在所有情况下都执行Θ（nLogn）操作。大多数其他排序算法具有最差和最佳的情况。例如，在快速排序的典型实现（其中将枢轴作为角元素选择）中，最糟糕的情况是当输入数组已经被排序并且当枢轴元素总是将数组分成两半时发生。对于插入排序，最坏情况发生在数组反向排序时，最好的情况发生在数组以与输出相同的顺序排序时。

## 算法分析 | 渐进符号

渐近分析的主要思想是对不依赖与机器特定常数的算法的效率进行测量，并且不需要执行算法和程序进行比较的时间

渐进符号是用于表示渐近分析的算法的时间复杂度的数学工具

1. Θ表示法：Θ符号界定上下一个函数，因此它定义了精确的渐近行为，获取表达式的theta符号的一个简单方法就是降低低阶项，忽略顶点常量

例如考虑下面的表达式

    3n^3 + 6n^2 + 6000 = Θ(n^3)

删除低阶项总是很好，因为不管涉及的常数的情况下，总是会有一个n0,在Θ(n^3)具有比Θ(n^2)更大的值

对于给定的函数g(n),我们表示Θ(g(n))是以下函数的集合

    Θ(g(n)) = {f(n)}:存在正常数c1,c2和n0等，对于所有n>=n0,0 <= c1 * g(n) <= c2 * g(n)

上述定义意味着，如果f(n)是g(n)的Θ，则对于大的n(n>=n0),值f(n)总是在c1 * g(n)和c2 * g(n0).Θ的定义还要求对于n大于n0的值,f(n)必须是非负的

![](./images/thetanotation.png)

2. 大O表示法：大O表示法定义了算法的上限，它仅从上面界定了一个函数

例如考虑插入排序的情况

在最坏的情况下，在最佳情况和二次时间内需要线性时间。我们可以安全的说，插入排序的时间复杂度是O(n^2)

如果我们使用Θ表示法表示插入排序的时间复杂度，我们必须使用两条语句来实现最佳和最差情况：

- 插入排序的最差时间复杂度为Θ(n^2)
- 插入排序的最佳时间复杂度为Θ(n)

当我们只有一个算法的时间复杂度上限的时候，大O符号是有用的

很多事件，我们很容易找到一个上限，只需要简单的看一下算法

    O(g(n)) = {f(n)} :存在正常常数c和n0,使得 0 <= f(n) <= cg(n),全部n>=n0

![](./images/BigO.png)

3. Ω符号：正如大O表示法在函数上提供渐近上界，Ω表示法提供渐近下界。

当我们对算法的时间复杂度有较低的限制时，可以使用Ω表示法。

如前一篇文章所讨论的，算法的最佳情况一般不是很有用，在这三种渐近符号中，使用的符号最少的就是Ω。

对于给定的函数g（n），我们用Ω（g（n））表示函数集合。

    Ω（g（n））= {f（n））：存在正常常数c和
                    n0，使得0 <= cg（n）<= f（n）
                    所有n> = n0}。


让我们在这里考虑相同的插入排序示例。插入排序的时间复杂度可以写为Ω（n），但它不是关于插入排序的非常有用的信息，因为我们通常对最坏情况感兴趣，有时在平均情况下有兴趣。

![](./images/BigOmega.png)

## 算法分析 | 循环分析

1. O(1)：如果一个函数(或一组语句)不包含循环，递归和调用任何其它非常数时间函数，则将其视为O(1)的时间复杂度

例如下面循环就是O(1)

        for(int i=1;i<=c;i++){
            //some O(1) expressions
        }

2. O(n):时间如果循环变量递增/递减一个常数，则循环的复杂度被认为是O(n)

        for(int i=1;i<=n;i+=c){
            //some O(1) expressions
        }
        for(int i=n;i>0;i-=c){
            //some O(1) expressions
        }

3. O(n^c):嵌套循环的时间复杂度等于最内层语句的执行次数

例如，一下循环为O(n^2)的时间复杂度

    for(int i=1;i<=n;i+=c){
        for(in j=1;j<=n;j+=c){
            //some O(1) expressions
        }
    }
    for(int i=n;i>0;i+=c){
        for(int j=i+1;j<=n;j+=c){
            //some O(1) expressions
        }
    }

4. O(logn)时间如果循环变量被分割/乘以恒定量，则将循环的复杂度视为O(logn)

        for(int i=1;i<=n;i*=c){
            //some O(1) expressions
        }
        for(int i=n;i>0;i/=c){
            //some O(1) expressions
        }

5. O(loglogn)时间如果循环变量以指数规律减小/增加，则循环的复杂度为O(loglogn)

        // Here c is a constant greater than 1   
        for (int i = 2; i <=n; i = pow(i, c)) { 
            // some O(1) expressions
        }
        //Here fun is sqrt or cuberoot or any other constant root
        for (int i = n; i > 0; i = fun(i)) { 
            // some O(1) expressions
        }

> 如何组合连续循环的时间复杂度？

        for (int i = 1; i <=m; i += c) {  
                // some O(1) expressions
        }
        for (int i = 1; i <=n; i += c) {
                // some O(1) expressions
        }
        Time complexity of above code is O(m) + O(n) which is O(m+n)
        If m == n, the time complexity becomes O(2n) which is O(n). 

## 算法分析 | 递归分析

在前一篇文章中，我们讨论了循环的分析。许多算法本质上是递归的。当我们分析它们时，我们得到时间复杂度的递归关系。我们得到的运行时间是大小为n的输入作为n的函数，以及较小大小的输入的运行时间。

例如在“ 合并排序”中，为了对给定的数组进行排序，我们将其分成两半，并递归地重复两个进程。最后我们合并结果。合并排序的时间复杂度可以写为T（n）= 2T（n / 2）+ cn。还有很多其他算法，如二进制搜索，汉罗塔问题等。

1. 替代方法：猜测解，然后使用数学归纳来证明猜测是正确的或者不正确

        For example consider the recurrence T(n) = 2T(n/2) + n

        We guess the solution as T(n) = O(nLogn). Now we use induction
        to prove our guess.

        We need to prove that T(n) <= cnLogn. We can assume that it is true
        for values smaller than n.

        T(n) = 2T(n/2) + n
            <= cn/2Log(n/2) + n
            =  cnLogn - cnLog2 + n
            =  cnLogn - cn + n
            <= cnLogn

2. 重复树法：在这种方法中，我们绘制一个重复树，并计算每个级别的树所花费的时间。最后，我们总结了各级的工作。为了绘制递推树，我们从给定的复现开始，继续绘制，直到我们在各个层次之间找到一个模式。该图案通常是算术或几何系列

            For example consider the recurrence relation 
            T(n) = T(n/4) + T(n/2) + cn2

                    cn2
                    /      \
                T(n/4)     T(n/2)

            If we further break down the expression T(n/4) and T(n/2), 
            we get following recursion tree.

                            cn2
                    /           \      
                c(n2)/16      c(n2)/4
                /      \          /     \
            T(n/16)     T(n/8)  T(n/8)    T(n/4) 
            Breaking down further gives us following
                            cn2
                        /            \      
                c(n2)/16          c(n2)/4
                /      \            /      \
            c(n2)/256   c(n2)/64  c(n2)/64    c(n2)/16
            /    \      /    \    /    \       /    \  

            To know the value of T(n), we need to calculate sum of tree 
            nodes level by level. If we sum the above tree level by level, 
            we get the following series
            T(n)  = c(n^2 + 5(n^2)/16 + 25(n^2)/256) + ....
            The above series is geometrical progression with ratio 5/16.

            To get an upper bound, we can sum the infinite series. 
            We get the sum as (n2)/(1 - 5/16) which is O(n2)

3. 主方法仅适用于一下类型的复现或可以转化为以下类型的重复

        T(n) = aT(n/b) + f(n) where a >= 1 and b > 1

有以下三种情况：

1. 如果f（n）=Θ（n c）其中c <Log b a    则T（n）=Θ（n Log b a）

2. 如果F（N）=Θ（n c）其中c =Log b a 则T（N）=Θ（NÇlog n）

3. 如果F（N）=Θ（n c）其中c>=Log b a 则T（N）=Θ（f（n））

主方法主要来源于递归树法。如果我们绘制T（n）= aT（n / b）+ f（n）的递归树，我们可以看到在根处完成的是f（n），所有叶子的都是Θ（n c） c是logba。而递归树的高度为Log bn .

在递归树方法中，我们计算完成的总工作量。如果在叶子上完成的工作多数多，那么叶子是主要的部分，我们的结果就成为树叶上（情况1）。

如果在叶子和根部的工作是渐进的，那么我们的结果就变成了高度乘以任何级别的工作（情况2）。

如果在根处完成的工作是更多的，那么我们的结果就会在根上（情况3）。

![](./images/Master-Theorem.jpg)

使用主方法

合并排序：T（n）= 2T（n / 2）+Θ（n）可以评估其时间复杂度的一些标准算法的示例。它属于情况2，其中c=1，Log b a=1.因此解为Θ（n Logn）

二进制搜索：T（n）= T（n / 2）+Θ（1）。它也属于情况2，其中c=0且Log b a=0的情况下出现。因此解为Θ（Logn）

注意：

1）使用主定理可以解决形式T（n）= aT（n / b）+ f（n）的复现。给定的三例在他们之间有一些差距。例如，使用主方法不能求解重复T（n）= 2T（n / 2）+ n / Logn。

2）情况2可以扩展为f（n）=Θ（ncLogkn）
如果f（n）=Θ（ncLogkn）对于一些常数k> = 0，c = Logba，则T（n）=Θ（nc Log k+1 n）

# 链表题

## 1. 链表逆序 LeetCode 206. Reverse Linked List

整体思路:遍历原链表，采用头插法的方式将原链表中的每一个节点插入到新创建的链表中

        //传入一个链表，返回一个逆序的新的链表
        ListNode *reverseList(ListNode *head){
            ListNode *new_head = NULL;
            while(head){
                ListNode *next = head->next;
                head->next = new_head;
                new_head = head;
                head = next;
            }
            return new_head;
        }
## 2. 链表逆序2 LeetCode 92. Reverse Linked List II

整理思路:这次是链表的范围逆序，在给定的范围内逆序链表的一部分.思路是创建两个指针，一个指向逆序范围的开始，一个指向逆序范围的结束，同时逆序完成后要将逆序后的链表再直接跟原链表相连。

要找到四个指针，一个是逆序段头结点的前驱，一个是逆序的头节点，一个是逆序的尾节点，最后一个是逆序段尾节点的后继，找到这四个指针即可利用链表逆序的第一种方法解题

先找头结点，再继续找尾结点，在找尾结点的遍历过程中，通过new_head逆序后，调整了头结点和尾结点的位置，然后再将他们跟前驱和后继连接起来即可。看起来挺复杂，实际上，只要掌握好了思路，给一定的时间就可以完成这道题了

        ListNode* reverseBetween(ListNode*head,int m,int n){
            ListNode *pre_head = NULL;
            ListNode *next_head = NULL;
            ListNode *new_head = NULL;//存放逆序的一段链表
            //你会发现我们无需存储最后的后继，head会遍历到那个位置
            //ListNode *end_head = NULL;
            ListNode *result = head;//存放最终结果的链表
            int change_len = n - m + 1;//步长
            while(head && --m){
                pre_head = head;//逆序的前驱
                head = head->next;
            }
            next_head = head;//指向逆序的头节点
            //下面开始找逆序的尾结点和逆序的后继
            while(head && change_len--){
                //head指向逆序的头结点
                //我们在遍历的同时，进行逆序
                ListNode *next = head->next;
                head->next = new_head;
                new_head = head;
                head = next;
            }
            //逆序完成后,head指向逆序的后继,new_head变成了头节点，那么尾节点
            //自然就是next_head,它从头节点变成了尾节点了
            //最后我们来连接
            next_head->next = head;
            if(pre_head){
                pre_head->next = new_head;
            }else{
                result = new_head;
            }
            return result;
        } 
## 3. 求两个链表的交点   LeetCode 160.Intersection of Two LinkedLists

解题思路:可以利用set集合元素来判断是否有相同的节点，遍历链表A，将A中的节点指针插入set，遍历链表B,将B中的节点地址在set中查找，如果找到，则为交点

        ListNode *geIntersectionNode(ListNode* headA,ListNode* headB){
            std::set<ListNode*> node_set;
            while(headA){
                node_set.insert(headA);
                headA = headA->next;
            }
            while(headB){
                if(node_set.find(headB) != node_set.end()){
                    return headB;
                }
                headB = headB->next;
            }
            return NULL;
        }

## 4.链表求环  LeetCode 142. Linked List Cycle

解题思路:设计两个指针，一个快，每次走两步，一个慢，每次走一步，两个指针如果能够相遇的话，则证明是有环的。并且，从head出发与从相遇的地方出发，两指针速度一样，相遇后即为环的起点

        ListNode *detectCycle(ListNode *head){
            ListNode *fast = head;//快指针
            ListNode *slow = head;//慢指针
            ListNode *meet = NULL;
            while(fast){
                slow = slow->next;
                fast = fast->next;
                if(!fast){
                    return NULL;
                }
                fast = fast->next; //fast再走一步
                if(fast == slow){
                    meet = fast;
                    break;
                }
            }
            if(meet == NULL){
                return NULL;
            }
            while(head && meet){
                if(head == meet){
                    return head;
                }
                head = head->next;
                meet = meet->next;
            }
            return NULL;
        }

## 5. 链表划分 LeetCode 86.Partition List

整理思路:我觉得这个题其实就是送分题，感觉只要把思路理清楚了很容易就可以实现代码，首先，设置两个链表，分别存储小于某个数的节点，再用一个链表存储大于等于某个数的节点，最后再将两个节点连接起来即可。

        ListNode * patition(ListNode* head,int x){
            ListNode less_head(0);
            ListNode more_head(0);
            ListNode *less_ptr = &less_head;
            ListNode *more_ptr = &more_head;
            //注意这里用的是尾插法
            //注意跟头插法的区别
            while(head){
                if(head->val < x){
                    less_ptr->next = head;
                    less_ptr = head;
                }else{
                    more_ptr->next  = head;
                    more_ptr = head;
                }
                head = head->next;
            }
            less_ptr->next = more_head.next;
            more_ptr->next = NULL;
            return less_head.next;
        }


## 6. 合并两个链表  LeetCode 21.Merge Two Sorted Lists

整体思路:合并两个有序的链表思路也简单，两个指针分别遍历两个链表，每遍历一次，比较两个链表节点的值大小，将较小的值先放入最终结果的链表，随后，拥有较小值得链表指针前移，继续跟下一个节点比较，直到比较到链表的末尾，如果这时候有某个链表还每遍历完，则在最后加入到尾部即可

        ListNode *mergeTwoList(ListNode *l1,ListNode *l2){
            ListNode temp_head(0);//临时链表
            ListNode *pre = &temp_head;
            while(l1 && l2){
                if(l1->val < l2->val){
                    //如果第二个链表的值比较大
                    pre->next = l1;
                    l1 = l1->next;
                }else{
                    pre->next = l2;
                    l2 = l2->next;
                }
                pre = pre->next;
            }
            //最后别忘了如果还有链表没有遍历完毕的话
            if(l1){
                pre->next = l1;
            }
            if(l2){
                pre->next = l2;
            }
            return temp_head.next;
        }

## 7. 合并多个链表 LeetCode 23.Merge k Sorted Lists

整体思路:其实如果直接暴力合并的话肯定是超时的，合并多个不能用简单的思维来看，其实方法有很多种，我个人更倾向于最简单的那种，那就是遍历所有的链表，将链表中的元素放入一个容器中进行排序，排序后再变成链表

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::vector<ListNode *> node_vec;        
        for (int i = 0; i < lists.size(); i++){
        	ListNode *head = lists[i];
        	while(head){
        		node_vec.push_back(head);
	        	head = head->next;
	        }
        }
        if (node_vec.size() == 0){
        	return NULL;
        }        
        std::sort(node_vec.begin(), node_vec.end(), cmp);
        for (int i = 1; i < node_vec.size(); i++){
        	node_vec[i-1]->next = node_vec[i];
        }
        node_vec[node_vec.size()-1]->next = NULL;
        return node_vec[0];
    }

    



