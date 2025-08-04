// Prob. 1 Given a undirected Graph of N vertices 1 to N and M edges in form of 2D array arr[][] whose every
// row consists of two numbers X and Y which denotes that there is an edge between X and Y, now write a
// program to create Laplacian matrix.
// The Laplacian matrix (also known as graph Laplacian, admittance matrix, Kirchhoff matrix or discrete
// Laplacian) is a matrix representation of a graph. To find the Laplacian matrix first, find adjacency matrix
// and degree matrix of a graph as the formula for the Laplacian matrix is as follows:
// Laplacian matrix = Degree matrix – Adjacency matrix
// Input: N = 5, M = 4, arr[][] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5 } } 


import java.util.Arrays;

public class Graph {

    int[][] laplacianMatrix(int[][] edges) {

        int[][] adjacencyMatrix = adjacencyMatrix(edges);
        int n = adjacencyMatrix.length;
        int[][] laplacian = new int[n][n];
        int[][] degreeMatrix = degreeMatrix(adjacencyMatrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                laplacian[i][j] = degreeMatrix[i][j] - adjacencyMatrix[i][j];
            }
        }
        return laplacian;
    }

    int[][] degreeMatrix(int[][] adjacencyMatrix) {
        int n = adjacencyMatrix.length;
        int[][] degreeMatrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                degree += adjacencyMatrix[i][j];
            }
            degreeMatrix[i][i] = degree;
        }
        return degreeMatrix;
    }

    int[][] adjacencyMatrix(int[][] edges) {
        int n = edges.length;

        // Find the maximum vertex number to determine the size of the adjacency matrix
        int maxVertex = 0;

        for (int[] edge : edges) {
            maxVertex = Math.max(maxVertex, Math.max(edge[0], edge[1]));
        }

        int[][] adjacencyMatrix = new int[maxVertex + 1][maxVertex + 1];

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[edges[i][0]][edges[i][1]] = 1;
            adjacencyMatrix[edges[i][1]][edges[i][0]] = 1;
        }

        System.out.println("Adjacency Matrix: " + Arrays.deepToString(adjacencyMatrix));
        return adjacencyMatrix;
    }   

    
    public static void main(String[] args) {
        int[][] edges = { 
            {0,1},
            {0,2},
            {1,2}
        };

        Graph graph = new Graph();

        int[][] laplacianMatrix = graph.laplacianMatrix(edges);
        System.out.println(Arrays.deepToString(laplacianMatrix));
    }    
}