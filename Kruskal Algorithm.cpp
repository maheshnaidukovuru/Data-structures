#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Compare function used for sorting edges based on their weights
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find the parent of a node using path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Perform union of two subsets using rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Kruskal's algorithm to find MST
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];  // To store the result MST
    int resultIndex = 0;    // Index to store edges in the result MST

    // Step 1: Sort the edges in non-decreasing order by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Step 2: Iterate through sorted edges and add them to MST if they don't form a cycle
    for (int i = 0; resultIndex < V - 1 && i < E; ++i) {
        struct Edge nextEdge = edges[i];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; ++i) {
        printf("%d -- %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; ++i) {
        printf("Enter source, destination, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

    free(edges);

    return 0;
}

