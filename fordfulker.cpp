int res[MAX_V][MAX_V], mf, f, s, t; // global variables vi p; // p stores the BFS spanning tree from s

void augment(int v, int minEdge)
{
    // traverse BFS spanning tree from s->t

    if (v == s) { f = minEdge; return; }        // record minEdge in a global var f
      else if (p[v] != -1)

      {
        augment(p[v], min(minEdge, res[p[v]][v]));
       res[p[v]][v] -= f; res[v][p[v]] += f;
        }
      }
     // inside int main(): set up �res�, �s�, and �t� with appropriate values
 mf = 0;        // mf stands for max_flow
 while (1)
 {
        // O(VE^2) (actually O(V^3 E) Edmonds Karp�s algorithm
  f = 0;    // run BFS, compare with the original BFS
 vi dist(MAX_V, INF);
 dist[s] = 0; queue<int> q;
  q.push(s); p.assign(MAX_V, -1);  // record the BFS spanning tree, from s to t!

 while (!q.empty())
    {
    int u = q.front(); q.pop(); if (u == t) break;   // immediately stop BFS if we already reach sink t
 for (int v = 0; v < MAX_V; v++)    // note: this part is slow
    if (res[u][v] > 0 && dist[v] == INF) dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1! }
 augment(t, INF);    // find the min edge weight �f� in this path, if any
 if (f == 0) break;    // we cannot send any more flow
 (�f� = 0), terminate mf += f;   // we can still send a flow, increase the max flow!
 }
 printf("%d\n", mf);    // this is the max flow value
