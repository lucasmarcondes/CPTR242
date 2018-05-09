#include <iostream>
#include "GraphType.h"

template <class VertexType>
void BreadthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// Assumption: VertexType is a type for which the Ò==Ò and
//             "<<" operators are defined.
{
    using namespace std;
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;

    graph.ClearMarks();
    queue.Enqueue(startVertex);

    do {
        queue.Dequeue(vertex);

        if (vertex == endVertex) {
            cout << vertex;
            found = true;
        } else {
            if (!graph.IsMarked(vertex)) {
                graph.MarkVertex(vertex);
                cout << vertex;
                graph.GetToVertices(vertex, vertexQ);

                while (!vertexQ.IsEmpty()) {
                    vertexQ.Dequeue(item);
                    if (!graph.IsMarked(item))
                        queue.Enqueue(item);
                }
            }
        }
    } while (!queue.IsEmpty() && !found);
    if (!found)
        cout << "Path not found." << endl;
}
