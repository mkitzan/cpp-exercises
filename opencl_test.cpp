#include <iostream>
#include <vector>

#include <CL/cl2.hpp>

//g++ -I/opt/intel/system_studio_2020/opencl-sdk/include -L/opt/intel/system_studio_2020/opencl-sdk/lib64 -lOpenCL -o test opencl_test.cpp

int main()
{
    std::vector<cl::Platform> platforms{};
    cl::Platform::get(&platforms);

    if (platforms.size() == 0)
	{
        std::cout << "No platforms found. Check OpenCL installation!\n";
    }
	else
	{
		cl::Platform p{ platforms[0] };
    	std::cout << "Using platform: " << p.getInfo<CL_PLATFORM_NAME>() << '\t'
			<< p.getInfo<CL_PLATFORM_VERSION>() << '\n';
	}
 
	return 0;
}
