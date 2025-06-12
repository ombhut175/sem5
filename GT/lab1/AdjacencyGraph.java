package lab1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class AdjacencyGraph {

    public static void main(String[] args) {
        int[][] arr1 = { {0, 1}, {1, 2}, {2, 0} };
        int[][] arr2 = {{0,1},{1,2},{1,3},{2,3},{3,0}};
        Graph g = new Graph();

        Map<Integer,ArrayList<Integer>> graph2 = g.getAdjacencyListInMap(arr2);
        System.out.println(graph2);
        g.bfs(graph2);
    }
}


class Graph {
    Map<Integer,ArrayList<Integer>> getAdjacencyListInMap(int[][] arr){
        Map<Integer,ArrayList<Integer>> graph = new HashMap<>();

        // for (type variable : arrayOrCollection) {
        //     // use variable here
        // }

        for(int[] edge : arr){
            int node1 = edge[0];
            int node2 = edge[1];

            if(!graph.containsKey(node1)){
                graph.put(node1, new ArrayList<>());
            }

            ArrayList<Integer> list = graph.get(node1);
            list.add(node2);
            graph.put(node1, list);

        }

        return graph;
    }  
    
    void bfs(Map<Integer,ArrayList<Integer>> graph){
        boolean[] visited = new boolean[graph.size()];

        Queue<Integer> q = new LinkedList<>();

        q.add(0);
        visited[0] = true;

        while (!q.isEmpty()) { 
            int node = q.remove();

            System.out.println(node);

            for(int neighbour : graph.get(node)){
                if (!visited[neighbour]) {
                    q.add(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

    }

    Map<Integer,ArrayList<Integer>>  countInOutDegree(Map<Integer,ArrayList<Integer>> graph){
        Map<Integer,ArrayList<Integer>> nodeWithDegrees = new HashMap<>();

        graph.forEach((key, value) -> {
            countInOutDegreeHelper(key, value ,nodeWithDegrees);
        });

        return nodeWithDegrees;

    }

    void countInOutDegreeHelper(Integer key, ArrayList<Integer> value,Map<Integer,ArrayList<Integer>> nodeWithDegrees){
        
    }

    // int[][] getAdjacencyListInArray(int[][] arr){
        
    // }
}