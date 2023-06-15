#include <iostream>
#include <vector>
#define scanner std::cin;

unsigned int tmp;
unsigned int u;
unsigned int v;
unsigned int last;

std::vector<bool> flag;
unsigned int n, m;

std::vector<std::pair<unsigned int, std::pair<unsigned int, std::pair<unsigned int, unsigned int>>>> edges;
std::vector<std::pair<unsigned int, std::pair<unsigned int, std::pair<unsigned int, unsigned int>>>> edges1;

const int N = 500001;
unsigned int parent[N], Rank[N];
std::vector<std::pair<unsigned long, unsigned long>> adj[N];

unsigned int par[N][53], d[N], weight[N];
unsigned int ans = 0;
unsigned int cost = 0;


struct BitField{
	unsigned long W : 16;
	unsigned long U : 16;
	unsigned long V : 16;
};

BitField field;

namespace dsu
{
	template<typename T>
	void make_set(T v)
	{
		parent[v] = v;
		Rank[v] = 0;
	}

	template<typename T>
	unsigned int find_set(T v)
	{
		if (v == parent[v])
		{
			return v;
		}
		return parent[v] = find_set(parent[v]);
	}

	template<typename T>
	void union_sets(T a, T b)
	{
		a = find_set(a);
		b = find_set(b);

		if (a != b)
		{
			if (Rank[a] < Rank[b])
			{
				std::swap(a, b);
			}
			parent[b] = a;
			if (Rank[a] == Rank[b]) Rank[a]++;
		}
	}

	auto pred(std::pair<unsigned int,
			std::pair<unsigned int,
					std::pair<unsigned int, unsigned int>>> a,
	          std::pair<unsigned int,
			          std::pair<unsigned int,
					          std::pair<unsigned int, unsigned int>>> b)
	{
		return a.second.first < b.second.first;
	}

	auto pred_dsu()
	{
		return find_set(field.U) != find_set(field.V);
	}

	void dsu_init()
	{
		for (int i = 1; i <= n; i++)
		{
			make_set(i);
		}
	}
}

namespace kruskal
{
	void kruskal_help(auto &edge);

	void kruskal_mst();

	void kruskal();
}

namespace dfs
{
	bool pred_dfs(auto &v, unsigned int parent);

	void Par(auto &v);

	void dfs(unsigned int u, unsigned int parent);
}

namespace Lca
{
	bool pred_lca(unsigned int u, unsigned int v, bool fl, int i);

	auto lca(bool fl1, bool fl, unsigned int u, unsigned int v);

	unsigned int LCA(unsigned int u, unsigned int v);
}

namespace max
{
	bool pred_max(unsigned int u, unsigned int l);

	auto max(unsigned int u, unsigned int l);

	void maxEdge(unsigned int u, unsigned int v);
}

namespace Main
{
	void cin();

	void cout(auto min_cost);
}

int main()
{

	unsigned int min = 0;

	std::cin >> n >> m;

	Main::cin();

	flag.resize(edges.size(), false);

	kruskal::kruskal();

	min = cost;

	dfs::dfs(1, 0);

	Main::cout(min);

	return 0;
}

void Main::cout(auto min)
{
	for (int i = 0; i < m; i++)
	{
		if (flag[i])
		{
			std::cout << min << std::endl;
		}
		else
		{
			u = edges1[i].second.second.first;
			v = edges1[i].second.second.second;

			max::maxEdge(u, v);

			tmp = min + edges1[i].second.first - ans;

			std::cout << tmp << std::endl;
		}
	}
}

void Main::cin()
{
	for (auto i = 0; i < m; i++)
	{
		unsigned int u, v, w;
		std::cin >> u >> v >> w;
		edges.push_back({ i, { w, {u, v} } });
		edges1.push_back({ i, { w, {u, v} } });
	}
}

auto max::max(unsigned int u, unsigned int l)
{
	while (pred_max(u, l))
	{
		ans = std::max(ans, weight[u]);
		u = par[u][0];
	}
	return u;
}

bool max::pred_max(unsigned int u, unsigned int lc)
{
	return u != lc;
}

void max::maxEdge(unsigned int u, unsigned int v)
{
	unsigned int lс = Lca::LCA(u, v);
	ans = 0;

	u = max(u, lс);

	v = max(v, lс);
}

bool Lca::pred_lca(unsigned int u, unsigned int v, bool fl, int i)
{
	if (fl) return d[u] < d[v];
	return d[par[u][i]] >= d[v];
}

auto Lca::lca(bool fl1, bool fl, unsigned int u, unsigned int v)
{
	for (int i = 52; i >= 0; i--)
	{
		if (pred_lca(u, v, fl, i))
		{
			u = par[u][i];
		}
	}
	return u;
}

unsigned int Lca::LCA(unsigned int u, unsigned int v)
{
	bool fl = true;
	bool fl1 = true;
	int tr = 0;

	if (pred_lca(u, v, fl, tr))
	{
		std::swap(u, v);
	}

	fl = false;

	u = lca(fl1, fl, u, v);

	if (u == v)
	{
		return u;
	}

	for (int i = 52; i >= 0; i--)
	{
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

bool dfs::pred_dfs(auto &v, unsigned int parent)
{
	return v.first == parent;
}

void dfs::Par(auto &v)
{
	for (int i = 1; i < 53; i++)
	{
		par[v.first][i] = par[par[v.first][i - 1]][i - 1];
	}
}

void dfs::dfs(unsigned int u, unsigned int parent)
{
	for (auto v : adj[u])
	{
		if (pred_dfs(v, parent))
		{
			continue;
		}

		d[v.first] = d[u];
		d[v.first]++;
		weight[v.first] = v.second;
		par[v.first][0] = u;

		Par(v);

		dfs(v.first, u);
	}
}

void kruskal::kruskal_help(auto &edge)
{
	if (dsu::pred_dsu())
	{
		cost += field.W;

		dsu::union_sets(field.U, field.V);

		flag[edge.first] = 1;

		auto vv = field.V;
		auto uu = field.U;
		auto ww = field.W;

		adj[field.U].push_back({vv, ww});
		adj[field.V].push_back({uu, ww});
	}
}

void kruskal::kruskal_mst()
{
	for (auto edge : edges)
	{
		field.U = edge.second.second.first;
		field.V = edge.second.second.second;
		field.W = edge.second.first;

		kruskal_help(edge);
	}
}

void kruskal::kruskal()
{
	cost = 0;

	dsu::dsu_init();

	sort(edges.begin(), edges.end(), dsu::pred);

	kruskal_mst();
}
