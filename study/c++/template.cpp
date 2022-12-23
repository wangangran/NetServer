#include <iostream>
#include <functional>
#include <tuple>
#include <map>

 //原型
template<typename T>
struct function_traits;

template<typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> 
{
	enum { arity = sizeof...(Args) };
	using return_type = ReturnType;
	using function_type = ReturnType(Args...);
	using stl_function_type = std::function<function_type>;
	using pointer_type = ReturnType(*) (Args...);

	using tuple_type = std::tuple<std::remove_cv_t<std::remove_reference_t<Args>>...>;
};

// 函数指针
template<typename ReturnType, typename... Args>
struct function_traits<ReturnType(*)(Args...)> : function_traits<ReturnType(Args...)> {};


int add(int a, int b)
{
	return a + b;
}

template<typename Fun>
void setFunc(Fun f) {
	typename function_traits<Fun>::stl_function_type fun(f);
	using Args = function_traits<Fun>::tuple_type;
	constexpr auto size = std::tuple_size<typename std::decay<Args>::type>::value;
	int ret = fun(1, 2);
	std::cout << "ret:" << ret << "size:" << size << std::endl;
}

struct People {
	std::string name;
	int age;
	int id;
	
	People& operator=(const People& rhs) {
		name = rhs.name;
		age = rhs.age;
		id = rhs.id;
		return *this;
	}

	bool operator==(const People& rhs) {
		return name == rhs.name && age == rhs.age && id == rhs.id;
	}

	bool operator<(const People& rhs) {
		if (name < rhs.name) {
			return true;
		} else if (name > rhs.name) {
			return false;
		}

		if (age < rhs.age) {
			return true;
		} else if (age > rhs.age) {
			return false;
		}

		if (id < rhs.id) {
			return true;
		} else if (id > rhs.id) {
			return false;
		}

		return false;
	}

    friend bool operator<(const struct People& lhs, const struct People& rhs) {
	if (lhs.name < rhs.name) {
			return true;
		} else if (lhs.name > rhs.name) {
			return false;
		}

		if (lhs.age < rhs.age) {
			return true;
		} else if (lhs.age > rhs.age) {
			return false;
		}

		if (lhs.id < rhs.id) {
			return true;
		} else if (lhs.id > rhs.id) {
			return false;
		}

		return false;
    }

	bool operator>(const People& rhs) {
		if (name > rhs.name) {
			return true;
		}
		else if (name < rhs.name) {
			return false;
		}

		if (age > rhs.age) {
			return true;
		}
		else if (age < rhs.age) {
			return false;
		}

		if (id > rhs.id) {
			return true;
		}
		else if (id < rhs.id) {
			return false;
		}

		return false;
	}
};


int main()
{
	//setFunc(add);
	People p1("xiaoming", 17, 1);
	People p2("xiaohao", 18, 2);
	People p3("war", 10, 0);

	std::map<People, int> p;
	//p[p1] = 0;
	//p[p2] = 1;
	//p[p3] = 2;
	p.insert(std::pair<People, int>(p1, 0));
}

// int main()
// {
// 	setFunc(add);
// }
