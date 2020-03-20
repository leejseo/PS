import sys
raw_input = sys.stdin.readline
def augment(adj, u, visited, match):
    for v in range(len(adj[0])):
        if adj[u][v] and not visited[v]:
            visited[v] = True
            if match[v] == -1:
                match[v] = u
                return True
            augmented = augment(adj, match[v], visited, match)
            if augmented:
                match[v] = u
                return True
    return False

def find_max_matching(adj):
    match = [-1]*len(adj)
    for u in range(len(adj)):
        visited = [False]*len(adj[0])
        augment(adj, u, visited, match)
    return match

def size(adj):
    match = find_max_matching(adj)
    ans = 0
    for i in xrange(len(match)): ans += 1 if match[i] != -1 else 0
    return ans

def main():
    T = int(raw_input())
    for case in xrange(T):
        n, m = map(int, raw_input().split())
        adj = [ [False]*n for i in xrange(n) ]
        for i in xrange(m):
            u, v = map(int, raw_input().split())
            adj[u][v] = True
        print size(adj)
main()
