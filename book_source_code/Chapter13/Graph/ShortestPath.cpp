#include <iostream>
#include "GraphType.h"

template <class VertexType>
struct ItemType {
    bool operator<(ItemType otherItem);
    // Ò<Ò means greater distance
    bool operator==(ItemType otherItem);
    bool operator<=(ItemType otherItem);
    VertexType fromVertex;
    VertexType toVertex;
    int distance;
};

template <class VertexType>
void ShortestPath(GraphType<VertexType> graph, VertexType startVertex) {
    using namespace std;
    ItemType item;
    int minDistance;
    PQType<VertexType> pq(10);  // Assume at most 10 vertices
    QueType<VertexType> vertexQ;
    VertexType vertex;

    graph.ClearMarks();
    item.fromVertex = startVertex;
    item.toVertex = startVertex;
    item.distance = 0;
    pq.Enqueue(item);
    cout << "Last Vertex  Destination   Distance" << endl;
    cout << "-------------------------------------" << endl;

    do {
        pq.Dequeue(item);
        if (!graph.IsMarked(item.toVertex)) {
            graph.MarkVertex(item.toVertex);
            cout << item.fromVertex;
            cout << "  ";
            cout << item.toVertex;
            cout << "  " << item.distance << endl;
            item.fromVertex = item.toVertex;
            minDistance = item.distance;
            graph.GetToVertices(item.fromVertex, vertexQ);

            while (!vertexQ.IsEmpty()) {
                vertexQ.Dequeue(vertex);
                if (!graph.IsMarked(vertex)) {
                    item.toVertex = vertex;
                    item.distance = minDistance + graph.WeightIs(item.fromVertex, vertex);
                    pq.Enqueue(item);
                }
            }
        }
    } while (!pq.IsEmpty());
}
