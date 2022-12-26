#define panic(x) { std::string a = "\e[1m\x1B[31m"; std::string b = "\x1B[0m\e[m"; std::string c = x; throw std::runtime_error(a + c + b); }

#define NO_INFOp

#ifndef NO_INFO
#define info(x, lvl) { std::string a; if(lvl) { a = "\x1B[35m"; } else { a = "\x1B[33m"; }; std::string b = "\x1B[0m"; std::string c = x; std::string msg = a + c + b; std::cout << msg << std::endl; }
#define vec3_info(str, my_vec) { std::string a = "\x1B[36m"; std::string b = "\x1B[0m"; std::cout << a << str << ": " << "( " << my_vec.x << ", " << my_vec.y << ", " << my_vec.z << " )" << b << std::endl; }
#else
#define info(x, lvl) {}
#define vec3_info(str, my_vec) {}
#endif
