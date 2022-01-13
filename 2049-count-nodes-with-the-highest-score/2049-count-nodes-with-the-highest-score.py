class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        graph = collections.defaultdict(list)
        for node, parent in enumerate(parents):
            graph[parent].append(node)
        n = len(parents)
        d = collections.Counter()
        
        def count_nodes(node):
            prod = 1
            summ = 0
            for child in graph[node]:
                res = count_nodes(child)
                prod *= res
                summ += res
            prod *= max(1, n - 1 - summ)
            d[prod] += 1
            return summ + 1
        
        count_nodes(0)
        return d[max(d.keys())]

        