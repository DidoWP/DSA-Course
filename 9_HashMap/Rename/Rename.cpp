
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
	cin >> n;

	string name;
	unordered_set<string> allPrefixs;
	unordered_multiset<string> wholeNames;

	for (int j = 0; j < n; j++)
	{
		cin >> name;
		
		string pref = "";

		if (allPrefixs.count(name) > 0)
		{
			wholeNames.insert(name);

			if (wholeNames.count(name) == 1)
				cout << name << '\n';
			else
				cout << name << " " << wholeNames.count(name) << '\n';
		}
		else
		{
			for (unsigned i = 0; i < name.length(); i++)
			{
				bool flag = false;
				pref += name[i];

				if (allPrefixs.count(pref) == 0)
				{
					allPrefixs.insert(pref);
					if (pref == name)
						wholeNames.insert(name);
					cout << pref << '\n';
					flag = true;
				}

				if (flag == true)
				{
					i++;
					while (name[i] != '\0')
					{
						pref += name[i];
						allPrefixs.insert(pref);
						if (pref == name)
							wholeNames.insert(name);
						i++;
					}
				}
			}
		}
	}
}
