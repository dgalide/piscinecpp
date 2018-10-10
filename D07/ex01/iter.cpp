#include <iostream>

template <typename F>
void iter(F *arr, unsigned int len, void (*f)(F)) {
  for (unsigned int i = 0; i < len;i++) {
      f(arr[i]);
  }
}

template <typename F>
void  display(F f) {
    std::cout<< f << std::endl;
}

int	main()
{
	int t0[] = { 10, 1, 42, 1995, 88, 666 };
	std::string t1[] = { "zaphod", "beeblebrox" };

	::iter(t0, 5, ::display);
	::iter(t1, 3, ::display);

	return 0;
}
