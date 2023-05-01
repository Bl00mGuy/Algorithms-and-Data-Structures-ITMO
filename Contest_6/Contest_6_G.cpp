#include <iostream>
#include <vector>

int sum (std::vector<int>& tree, int n, int left, int right)
{
	int answer = 0;
	left += n;
	right += n;
	while (true)
	{
		if (left == right)
		{
			break;
		}
		if (left & 1)
		{
			answer += tree[left];
			left ++;
		}

		if (right & 1)
		{
			right --;
			answer += tree[right];
		}
		left /= 2;
		right /= 2;
	}
	return answer;
}



void Update(std::vector<int>& tree, std::vector<int>& keys, int left, int right, char command, int  q) // обновление
{
	if (command == '-')
	{
		if (keys[left - 1] >= right)
		{
			keys[left - 1] -= right;
		}
		else
		{
			keys[left - 1] = 0;
		}
		int value = keys[left - 1];
		int root = left - 1;
		root += q;
		tree[root] = value;
		int i = root;
		while (i > 1)
		{
			tree[i / 2] = tree[i] + tree[i ^ 1];
			i /= 2;
		}
	}
	else if (command == '+')
	{
		keys [left - 1] += right;
		int value = keys[left - 1];
		int root = left - 1;
		root += q;
		tree[root] = value;
		int i = root;
		while (i > 1)
		{
			tree[i / 2] = tree[i] + tree[i ^ 1];
			i /= 2;
		}
	}
}

int main ()
{
	int q, number_of_commands, left, right;
	char command;
	std::cin >> q >> number_of_commands;
	std::vector<int> tree ((q * 2));
	std::vector<int> keys (q);
	for (int i = 0; i < number_of_commands; i ++)
	{
		std::cin >> command >> left >> right;
		{
			if (command == '?')
			{
				std::cout << (sum (tree, q, left - 1, right)) << "\n";
			}
			else
			{
				Update(tree, keys, left, right, command, q);
			}
		}
	}
	return 0;
}
