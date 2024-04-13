import heapq

# TLE
class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:

        # Create an adjacency list to represent the graph
        graph = {i: [] for i in range(n)}
        for u, v, length in edges:
            graph[u].append((v, length))
            graph[v].append((u, length))
        
        # Initialize distances array with -1 (unreachable)
        distances = [-1] * n
        distances[0] = 0  # Distance from node 0 to itself is 0
        
        # Priority queue to store nodes to visit
        pq = [(0, 0)]  # (distance, node)
        
        while pq:
            dist, node = heapq.heappop(pq)
            
            # If the node has disappeared, skip it
            if disappear[node] <= dist:
                continue
            
            for neighbor, length in graph[node]:
                # If the neighbor has disappeared, continue
                if disappear[neighbor] <= dist + length:
                    continue
                
                # If the neighbor is reachable or has never been visited
                if distances[neighbor] == -1 or distances[neighbor] > dist + length:
                    distances[neighbor] = dist + length
                    heapq.heappush(pq, (dist + length, neighbor))
        
        return distances


class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        # Create an adjacency list to represent the graph
        graph = {i: [] for i in range(n)}
        for u, v, length in edges:
            graph[u].append((v, length))
            graph[v].append((u, length))

        # Initialize distances array with -1 (unreachable)
        distances = [-1] * n
        distances[0] = 0  # Distance from node 0 to itself is 0

        # Priority queue to store nodes to visit
        pq = [(0, 0)]  # (distance, node)

        # Set to store visited nodes
        visited = set()

        while pq:
            dist, node = heapq.heappop(pq)

            # If the node has disappeared or is already visited, skip it
            if disappear[node] <= dist or node in visited:
                continue

            visited.add(node)

            for neighbor, length in graph[node]:
                # If the neighbor has disappeared or is already visited, continue
                if disappear[neighbor] <= dist + length or neighbor in visited:
                    continue

                # If the neighbor is reachable or has never been visited
                if distances[neighbor] == -1 or distances[neighbor] > dist + length:
                    distances[neighbor] = dist + length
                    heapq.heappush(pq, (dist + length, neighbor))

        return distances