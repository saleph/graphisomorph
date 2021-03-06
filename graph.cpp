#include "graph.h"

Graph::Graph(std::ifstream file) {

        int vertexNo;
        file >> vertexNo;
        for (int i = 0; i < vertexNo; ++i)
            vertexes.push_back(i);


    while (file.good()) {
        int first = vertexNo, second = vertexNo;
        file >> first;
        file >> second;
        if (first >= vertexNo || second >= vertexNo)
            break;
        edges.emplace_back(&vertexes[first], &vertexes[second]);
    }
    //std::sort(vertexes.begin(),vertexes.end());
}

void Graph::checkIsomorphism(Graph &other) {
    if (vertexes.size() != other.vertexes.size() || edges.size() != other.edges.size()) {
        std::cout << "Nieizomorficzne\n";
        return;
    }
    if (edges.size() == 0) {
        std::cout << "Izomorficzne\n";
        for (int i=0; i < other.vertexes.size(); ++i) {
            std::cout << i << " --> " << other.vertexes[i] << '\n';
        }
        return;
    }
    for (;;) {
        if (std::is_permutation(edges.begin(), edges.end(), other.edges.begin())) {
            std::cout << "Izomorficzne\n";
            for (int i=0; i<other.vertexes.size(); ++i) {
                std::cout << i << " --> " << other.vertexes[i] << '\n';
            }
            return;
        }

        if(!std::next_permutation(other.vertexes.begin(), other.vertexes.end())) {
            std::cout << "Nieizomorficzne\n";
            return;
        }
    }
}
