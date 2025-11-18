#include <stdio.h>
#define MAX 100
int parent[MAX];
int rankArr[MAX];   
void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;      
        rankArr[i] = 0;     
    }
}
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   
    return parent[x];
}
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return; 
    if (rankArr[rootX] < rankArr[rootY]) {
        parent[rootX] = rootY;
    }
    else if (rankArr[rootX] > rankArr[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        rankArr[rootX]++;   
    }
}
int main() {
    int n = 6;
    makeSet(n);
    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);
    printf("Find(3) = %d\n", find(3));
    printf("Find(5) = %d\n", find(5));
    if (find(1) == find(3))
        printf("1 and 3 are in the same set\n");
    else
        printf("1 and 3 are NOT in the same set\n");

    if (find(1) == find(5))
        printf("1 and 5 are in the same set\n");
    else
        printf("1 and 5 are NOT in the same set\n");

    return 0;
}