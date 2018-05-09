#include "GraphType.h"
template <class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices.  numVertices is set to 0;
//       maxVertices is set to 50.
{
    numVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    marks = new bool[50];
}

template <class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for
//       marks and vertices.
//       numVertices is set to 0; maxVertices is set to maxV.
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    marks = new bool[maxV];
}

template <class VertexType>
// Post: arrays for vertices and marks have been deallocated.
GraphType<VertexType>::~GraphType() {
    delete[] vertices;
    delete[] marks;
}
const int NULL_EDGE = 0;

template <class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set
//       to NULL_EDGE.
//       numVertices has been incremented.
{
    vertices[numVertices] = vertex;

    for (int index = 0; index < numVertices; index++) {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template <class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
// Post: Returns the index of vertex in vertices.
{
    int index = 0;

    while (!(vertex == vertices[index]))
        index++;
    return index;
}

template <class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
    int row;
    int col;

    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex) edges[row][col] = weight;
}

template <class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
// Post: Returns the weight associated with the edge
//       (fromVertex, toVertex).
{
    int row;
    int col;

    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return edges[row][col];
}
template <class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjVertices)
// Post:
{
    int fromIndex;
    int toIndex;

    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}
