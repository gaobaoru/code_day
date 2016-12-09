题目描述


Clone an undirected graph. Each node in the graph contains alabeland a list of itsneighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use#as a separator for each node, and,as a separator for node label and each neighbor of the node.


As an example, consider the serialized graph{0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by#.

    First node is labeled as0. Connect node0to both nodes1and2.
    Second node is labeled as1. Connect node1to node2.
    Third node is labeled as2. Connect node2to node2(itself), thus forming a self-cycle.


Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //时间复杂度O(n),空间复杂度Ｏ(n)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        unordered_map<const UndirectedGraphNode*,UndirectedGraphNode*> copied;
        clone(node, copied);
        return copied[node];
    }
private:
    static UndirectedGraphNode* clone(const UndirectedGraphNode* node,
           unordered_map<const UndirectedGraphNode*,
                                      UndirectedGraphNode*> &copied){
        if(copied.find(node) != copied.end()) return copied[node];
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copied[node] = new_node;
        for(auto nbr : node->neighbors){
            new_node->neighbors.push_back(clone(nbr, copied));
        }
        return new_node;
    }
};
