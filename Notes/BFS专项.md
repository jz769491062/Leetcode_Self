1 在图中，由于 图中存在环，和深度优先遍历一样，广度优先遍历也需要在遍历的时候记录已经遍历过的结点。特别注意：将结点添加到队列以后，一定要马上标记为「已经访问」，否则相同结点会重复入队.

2 广度优先遍历可以用于「树」和「图」的问题的遍历；
广度优先遍历作用于「无权图」，得到的是「最短路径」。如果题目有让求「最小」、「最短」、「最少」，可以考虑这个问题是不是可以建立成一个「图形结构」或者「树形结构」，用「广度优先遍历」的思想求得「最小」、「最短」、「最少」的数值；
广度优先遍历作用于图论问题的时候，结点在加入队列以后标记为已经访问，否则会出现结点重复入队的情况。

3 这些加权图的算法，思想也基于BFS：
带权有向图、且所有权重都非负的单源最短路径问题：使用 Dijkstra 算法；
带权有向图的单源最短路径问题：Bellman-Ford 算法；
一个图的所有结点对的最短路径问题：Floy-Warshall 算法。

4 BFS中，每次遍历同深度的所有节点，齐头并进，循环末尾更新距离，这样只要到达了终点，当前的距离就一定是最短距离了，也不需要再max, min。这是BFS的性质。
1091. 二进制矩阵中的最短路径

5 只有在求最短距离的时候，需要齐头并进，同时推进sz个节点。只是普通的遍历，没有相关题目需求的话，就不需要用sz循环。

6 既然BFS可以找最短、最近路径，那么也可以用于一些DP问题，只要能把问题建图然后BFS找最优结果的话。
322. 零钱兑换  690. 员工的重要性.cpp

7 拓扑排序用于 有向无环图。 拓扑排序的目的不是比大小，而是为了给出先后顺序。
每个节点只输出一次，u -> v 的 u 必须在 v 的前面。
课程和任务安排，用到拓扑排序。
拓扑排序的结果不唯一。
拓扑排序可以用DFS或BFS实现。DFS拓扑冷门（遍历时还要检查环），主要还是BFS（遍历结束后就知道是否有环）。

8 BFS拓扑排序思路：
1. 入度0的节点放在最前，输出
2. 利用入度数组，依次删除剩余的有向边。回到步骤1，不断重复。
3. 如果存在环，环中的节点就不会输出，因为每个环中的节点都有入度。
需要queue用于BFS，vector<unordered_set<int>> adjList用于邻接表快速找邻居(顺便防止重复添加邻居)，还有数组存储节点(index)对应的入度（更新入度也用这个）。

9 BFS拓扑排序的细节： 269.火星词典
建图，建立邻接表，即「顶点」和它的 所有 「后继」结点的对应关系，题目中说：「你可以默认输入的全部都是小写字母」，因此可以使用数组或者哈希表，这里推荐使用哈希表，理由是 ① 哈希表有去重、判重的功能；② 有遍历所有在输入字符串数组中出现的字符的需求，遍历哈希表中的所有键，是相对方便的；
针对特殊测试用例，["abc", "ab"]，按照字典序的定义，长度较短的字符串在前，应该为 ["ab", "abc"]，在建图的时候需要考虑到这种特殊的情况；
建图的时候，需要找到找到位置相邻的一对单词，从左至右依次比较，直到找到不一样的字符，得到有向图的一条边，后面就不可以再比较下去（回顾上述字典序的定义）；
题目中说：「你可以默认输入的全部都是小写字母」，因此在拓扑排序中使用的入度数组的长度可以只设置为 
26。注意：在输入的字符串数组中，
26个字符不一定都会出现，不会出现的字符在入度数组里的入度也为 
0，在编码的时候需要考虑到这种情况；
构建图的时候，有向边的可以被重复添加，因为哈希表可以去重，但是被指向顶点的入度不可以重复增加，为此需要做特殊判断；
拓扑排序以后，需要判断：所有的顶点都输出了，才是说明通过输入字符串数组构建的图结构是有向无环图，此时才输出拓扑排序的结果。
