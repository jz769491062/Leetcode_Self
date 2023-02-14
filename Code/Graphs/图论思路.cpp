/*
图和多叉树最大的区别是，图是可能包含环的，你从图的某一个节点开始遍历，有可能走了一圈又回到这个节点，
而树不会出现这种情况，从某个节点出发必然走到叶子节点，绝不可能回到它自身。
所以，如果图包含环，遍历框架就要一个 visited 数组进行辅助

拓扑排序：拉平后的有向图，箭头都朝一个方向。有拓扑排序意味着不能有环。

将后序遍历的结果进行反转，就是拓扑排序的结果。
我建的图中箭头方向是「被依赖」关系，比如节点 1 指向 2，含义是节点 1 被节点 2 依赖，即做完 1 才能去做 2，
如果你反过来，把有向边定义为「依赖」关系，那么整幅图中边全部反转，
就可以不对后序遍历结果反转。
具体来说，就是把我的解法代码中 graph[from].add(to); 改成 graph[to].add(from); 就可以不反转了。
之所以拓扑排序的基础是后序遍历，是因为一个任务必须等到它依赖的所有任务都完成之后才能开始开始执行。
https://labuladong.gitee.io/algo/images/%e6%8b%93%e6%89%91%e6%8e%92%e5%ba%8f/2.jpeg
https://labuladong.gitee.io/algo/images/%e6%8b%93%e6%89%91%e6%8e%92%e5%ba%8f/3.jpeg

二分图：分成两组，组内元素互不相连。或者说每个点涂两种颜色，同色点不相连。
二分图有啥用？
某些场景可以更高效存储数据：
    比如电影和演员的映射可以是map<string, list<string>>，那如果要找演员出演了哪些电影呢？自然就构成一幅二分图了。
高级算法中最大流有用
图遍历框架
void traverse(Graph graph, boolean[] visited, int v) {
    visited[v] = true;
    // 遍历节点 v 的所有相邻节点 neighbor
    for (int neighbor : graph.neighbors(v)) {
        if (!visited[neighbor]) {
            // 相邻节点 neighbor 没有被访问过
            // 那么应该给节点 neighbor 涂上和节点 v 不同的颜色
            traverse(graph, visited, neighbor);
        } else {
            // 相邻节点 neighbor 已经被访问过
            // 那么应该比较节点 neighbor 和节点 v 的颜色
            // 若相同，则此图不是二分图
        }
    }
}


*/