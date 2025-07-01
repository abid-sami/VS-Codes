/* Create a base class called Device with an attribute deviceName and a constructor 
that sets deviceName. Derive two classes from Device: 
• Phone, which has additional attributes like phoneModel. 
• Tablet, which has additional attributes like tabletModel. 
Now, create a class called Phablet that inherits from both Phone and Tablet, resulting 
in a diamond structure. Use virtual inheritance for Device to avoid the diamond 
problem and ambiguity in accessing deviceName.  */

#include <iostream>
using namespace std;

class 
