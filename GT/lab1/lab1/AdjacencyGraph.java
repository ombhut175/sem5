import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class AdjacencyGraph {

    public static void main(String[] args) {
        int[][] arr1 = {{0, 1}, {1, 2}, {2, 0}};
        int[][] arr2 = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 0} ,{4,5} , {5,4} ,{6,7},{7,6}};
        Graph g = new Graph();

        Map<Integer, ArrayList<Integer>> graph2 = g.getAdjacencyListInMap(arr2);
        System.out.println(graph2);
        // g.bfs(graph2);
        // g.dfs(graph2);
        // g.countInOutDegree(graph2);
        System.out.println(g.numberOfComponents(graph2));
    }
}

class Graph {

    Map<Integer, ArrayList<Integer>> getAdjacencyListInMap(int[][] arr) {
        Map<Integer, ArrayList<Integer>> graph = new HashMap<>();

        // for (type variable : arrayOrCollection) {
        //     // use variable here
        // }
        for (int[] edge : arr) {
            int node1 = edge[0];
            int node2 = edge[1];

            if (!graph.containsKey(node1)) {
                graph.put(node1, new ArrayList<>());
            }

            ArrayList<Integer> list = graph.get(node1);
            list.add(node2);
            graph.put(node1, list);

        }

        return graph;
    }

    void bfs(Map<Integer, ArrayList<Integer>> graph) {
        boolean[] visited = new boolean[graph.size()];

        Queue<Integer> q = new LinkedList<>();

        q.add(0);
        visited[0] = true;

        while (!q.isEmpty()) {
            int node = q.remove();

            System.out.println(node);

            for (int neighbour : graph.get(node)) {
                if (!visited[neighbour]) {
                    q.add(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

    }

    int numberOfComponents(Map<Integer, ArrayList<Integer>> graph){
        boolean[] visited = new boolean[graph.size()];
        int count = 0;
        for (int key : graph.keySet()) {
            if (!visited[key]) {
             count++;
             dfsHelper(graph, visited, key);   
            }
        }

        return count;
    }

    void dfs(Map<Integer, ArrayList<Integer>> graph) {
        boolean[] visited = new boolean[graph.size()];
        System.out.println("::: DFS ::::");
        dfsHelper(graph, visited, 0);
    }

    void dfsHelper(Map<Integer, ArrayList<Integer>> graph, boolean visited[], int node) {
        // System.out.println(node);
        visited[node] = true;

        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) {
                dfsHelper(graph, visited, neighbour);
            }
        }
    }

    Map<Integer, int[]> countInOutDegree(Map<Integer, ArrayList<Integer>> graph) {
        Map<Integer, int[]> nodeWithDegrees = new HashMap<>();
        System.out.println("::: countInOutDegree ::::");
        graph.forEach((key, value) -> {
            countInOutDegreeHelper(key, value, nodeWithDegrees);
        });

        for (int i = 0; i < graph.size(); i++) {
            System.out.println("for " + i + " in degree is " + nodeWithDegrees.get(i)[0] + " out degree is " + nodeWithDegrees.get(i)[1]);
        }
        
        return nodeWithDegrees;
    }

    void countInOutDegreeHelper(Integer node, ArrayList<Integer> neighbours, Map<Integer, int[]> nodeWithDegrees) {
        int[] inOutDegree = new int[2];
        inOutDegree[0] = nodeWithDegrees.getOrDefault(node, inOutDegree)[0];
        inOutDegree[1] = neighbours.size();
        nodeWithDegrees.put(node, inOutDegree);

        for (int neighbour : neighbours) {
            int[] inOutDegreeNeighbour = nodeWithDegrees.getOrDefault(neighbour, new int[2]);
            inOutDegreeNeighbour[0]++;
            nodeWithDegrees.put(neighbour, inOutDegreeNeighbour);
        }
    }
}
