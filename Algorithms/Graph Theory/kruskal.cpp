#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/* Define an edge struct to handle edges more easily.*/
struct edge {
	int first, second, weight;
};

/* Needed to typedef to reduce keystrokes or copy/paste */
typedef std::vector< std::vector< std::pair<int,int> > > adj_list;

void kruskal(const adj_list& graph);
int find_in_tree(int vertex, const std::vector<int>& pred);

int main() {
	int n,m; std::cin >> n >> m;
	
	adj_list graph(n);
	int f,s,w;
	while (m-- > 0) {
		std::cin >> f >> s >> w;
		if (f == s) continue; /* avoid loops */
		graph[ f-1 ].push_back( std::make_pair( s-1 , w ) );
	}
    
    int start; std::cin >> start;

    kruskal(graph);

	return 0;
}

void kruskal(const adj_list& graph) {
	std::vector<edge> edges, in_tree;

	/*
		`pred` will represent our Disjointed sets by naming a set head.
		In the beginning, each node is its own head in its own set.
		We merge sets in the while loop.
	*/
	std::vector<int> pred(graph.size());

	for (int i = 0, n = graph.size(); i < n; i++) {
		for (auto& _edge : graph[i])
			edges.push_back( { i, _edge.first, _edge.second } );
		pred[i] = i;
	}

	/*
		Let's reverse-sort our edge vector
		so that we can just pop off the last (smallest)
		element.
	*/
	auto comp = [&](edge left, edge right) { return left.weight > right.weight; };
	std::sort(edges.begin(), edges.end(), comp);

	while(!edges.empty()) {
		/* get shortest/least-heavy edge */
		edge shortest = edges.back();
		edges.pop_back();

		int f_head,s_head; /* first_head, second... */
		f_head = find_in_tree(shortest.first, pred);
		s_head = find_in_tree(shortest.second, pred);

		/*
			If the nodes making up a certain edge are
			not already in the same set...
		*/
		if (f_head != s_head) {
			/* Add that edge to the Min. Span. Tree*/
			in_tree.push_back(shortest);

			/*
				Merge the sets by setting
				the head of one set to the head
				of the other set.

				If the head of one set is A and the other is C,
				as long as we point C to A, all nodes part of the
				set once headed by C will find A in O(x + 1) time.
			*/
			if (f_head < s_head)
				pred[s_head] = f_head;
			else
				pred[f_head] = s_head;
		}
	}
    int sum = 0;
    for (auto& _edge : in_tree) sum += _edge.weight;
	std::cout << sum << std::endl;
}

int find_in_tree(int vertex, const std::vector<int>& pred) {
	/*
		We stop when a node/vertex is its own predecessor.
		This means we have found the head of the set.
	*/
	while(pred[vertex] != vertex)
		vertex = pred[vertex];
	return vertex;
}