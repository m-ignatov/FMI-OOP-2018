#include <iostream>
#include "Stack.h"

int main()
{
	Stack st;
	const char* ans = (st.isEmpty() ? "Yes" : "No");

	std::cout << "Is the stack empty: " << ans << std::endl;

	st.push(3);
	st.push(1);
	st.push(-3);
	st.pop();
	st.pop();

	std::cout << "Top of stack: " << st.top() << std::endl;
}