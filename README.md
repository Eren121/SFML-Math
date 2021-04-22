# SFML-Math
SFML Math utility (to easy debug Vector, Color, etc...)

- Header only
- Print Vectors, and colors easely
- Math on Vector
- Simple algebra
- Mixed types with appropriate conversions

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
    cout << dot(myVec3, {0, 0, 1}) << endl;

    cout << myVec2 << endl;

    sf::Vector3f x{};
    sf::Vector3i y{};
    
    // Not possible in standard SFML
    sf::Vector3f z = x + y;
    
    return 0;
}
```

You can also define macros to disable some functionalities, if you already have some implementations:
All these macro are not defined by default.

| Macro        | If defined            |
| ------------- |:-------------:|
| SFML_MATH_DISABLE_ALL      | Disable all |
| SFML_MATH_DISABLE_ARITHMETIC      | Disable operators `+`, `-`, `*` and `/`     |
| SFML_MATH_DISABLE_STRING_CONVERSION | Disable `to_string()`      ||
| SFML_MATH_DISABLE_STREAM_OUTPUT | Disable `operator<<`      |
| SFML_MATH_DISABLE_ALGEBRA | Disable algebra (`dot`, `length`, ...) |

This disable integration in namespace `sf`. But the functions are always accessible using in namespace `sfmath`.
So even when disabled, you can always use `using namespace sfmath` to use these functionalities.

