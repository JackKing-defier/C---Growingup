#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
//

int main()
{
#ifndef ONLINE_JUDGE
	vector<char> operand, _operator;
	vector<bool> ans;
	string ss;
	int i, len;
	char ch, ch1;
	bool ans1, ans2;
	while (getline(cin, ss))
	{
		operand.clear();
		_operator.clear();
		ans.clear();
		string s(ss);
		len = s.size();
		// 中缀表达式转后缀表达式
		for (i = 0; i < len; i++)
		{
			ch = s.at(i);
			if (ch == '1' || ch == '0')
			{
				operand.push_back(ch);
			}
			else if (ch == '(')
			{
				_operator.push_back(ch);
			}
			else if (ch == '!')
			{
				_operator.push_back(ch);
			}
			else if (ch == '&' || ch == '|')
			{
				if (_operator.empty())
				{
					_operator.push_back(ch);
				}
				else if (_operator.back() == '(')
				{
					_operator.push_back(ch);
				}
				else
				{
					while (!_operator.empty() && _operator.back() != '(')
					{
						ch1 = _operator.back();
						operand.push_back(ch1);
						_operator.pop_back();
					}
					_operator.push_back(ch);
				}
			}
			else if (ch == ')')
			{
				while (_operator.back() != '(')
				{
					ch1 = _operator.back();
					operand.push_back(ch1);
					_operator.pop_back();
				}
				_operator.pop_back();
			}
		}
		while (!_operator.empty())
		{
			ch1 = _operator.back();
			_operator.pop_back();
			operand.push_back(ch1);
		}
		// 计算后缀表达式
		for (i = 0; i < operand.size(); i++)
		{
			ch = operand.at(i);
			if (ch == '1')
			{
				ans.push_back(true);
			}
			else if (ch == '0')
			{
				ans.push_back(false);
			}
			else if (ch == '!')
			{
				ans1 = ans.back();
				ans.pop_back();
				ans1 = !ans1;
				ans.push_back(ans1);
			}
			else if (ch == '&')
			{
				ans1 = ans.back();
				ans.pop_back();
				ans2 = ans.back();
				ans.pop_back();
				ans1 = ans1 && ans2;
				ans.push_back(ans1);
			}
			else if (ch == '|')
			{
				ans1 = ans.back();
				ans.pop_back();
				ans2 = ans.back();
				ans.pop_back();
				ans1 = ans1 || ans2;
				ans.push_back(ans1);
			}
		}
		cout << (ans.back() ? '1' : '0') << endl;
	}
#endif
}