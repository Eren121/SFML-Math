# SFML-Math
SFML Math &amp; Iterator utility (to easy debug Vector, Color, etc...)

- Print Vectors, and colors easely
- Math on Vector
- Iterate on these elements

```C++
#include <SFML/Math.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    sf::Vector3f myVec3(1, 1, 0);
    sf::Vector2f myVec2(1, 1);

    cout << myVec2 << endl;
    cout << length(myVec2) << ", " << length(myVec3) << endl;
    cout << length2(myVec2) << endl;
    cout << distance({1, 2}, myVec2) << endl;
    cout << dot(myVec3, {0, 0, 1}) << endl;

    for(float & f : myVec2) {
        f += 1;
    }

    cout << myVec2 << endl;

    return 0;
}
```
