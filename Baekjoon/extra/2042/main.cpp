/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2042
 * Created     : 2025-03-11 17:44:40
 * Updated     : 2025-03-11 23:19:47
 */

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
	private:
		vector<long long> tree;
		int n;

		void build(const long long * arr, int node, int start, int end)
		{
			if (start == end)
				tree[node] = arr[start];
			else
			{
				long long mid = (start + end) / 2;
				build(arr, node * 2, start, mid);
				build(arr, node * 2 + 1, mid + 1, end);
				tree[node] = tree[node * 2] + tree[node * 2 + 1];
			}
		}

	public:
		SegmentTree(const long long *arr, int size)
		{
			n = size;
			tree.resize(4 * n);
			build(arr, 1, 0, n - 1);
		}

		long long query(int node, int start, int end, int left, int right)
		{
			if (right < start || end < left)
				return 0;
			if (left <= start && end <= right)
				return tree[node];
			int mid = (start + end) / 2;
			return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
		}

		void update(int node, int start, int end, int idx, long long value)
		{
			if (idx < start || idx > end)
				return;
			if (start == end)
				tree[node] = value;
			else
			{
				int mid = (start + end) / 2;
				if (idx <= mid)
					update(node * 2, start, mid, idx, value);
				else
					update(node * 2 + 1, mid + 1, end, idx, value);
				tree[node] = tree[node * 2] + tree[node * 2 + 1];
			}
		}
};

long long n, m, k;
long long arr[1000001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for (long long i = 0; i < n; i++)
		cin >> arr[i];
	SegmentTree segTree(arr, n);
	long long a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			segTree.update(1, 1, n, b, c);
		else if (a == 2)
			cout << segTree.query(1, 1, n, b, c) << "\n";
	}

	return 0;
}
