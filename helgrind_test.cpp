#include <set>

using namespace std;

int main()
{
    #pragma omp parallel for schedule(dynamic)
    for (int _ = 0; _ < set<int>().size(); _++);

    #pragma omp parallel
    {
        #pragma omp for
        for (int _ = 0; _ < set<int>().size(); _++);
    }
}
