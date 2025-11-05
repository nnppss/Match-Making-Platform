# DATING_PLATFORM_C/C++_SEM2PROJ
# Basic C++ project that reflects the learning in Semester 2

# FEATURES 
1. TIME LIBRARY: The ctime() function in C++ converts the given time since epoch to a calendar local time and then to a character representation 
2. STRING: A string is a data type used in programming, such as an integer and floating point unit, but is used to represent text rather than numbers. 
3. OBJECTS: An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated. 
4. CLASS: A Class is a user-defined data type that has data members and member functions. 
5. INHERITANCE: The ability of objects in one class to inherit properties of another class which implements the reusability concept. 
6. VECTOR: Vectors are the same as dynamic arrays with the ability to resize themselves automatically when an element is inserted or deleted, with their storage being handled automatically by the container. 
7. CHAT: We use a chat class that contains functions like view chat messages, view chat history, and clear chat . 
8. FILE HANDLING: File handling provides a mechanism to store the output of a program in a file and perform various operations on it.

# STRUCTURE 
1. MAIN MENU: A catchy main menu that consists of 12 different Tabs to perform 12 different functions. 
![1](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/00f278e3-5218-44bf-8590-c5b9ccb8a4a6)

2. CLASSES: Three Classes have been used: 
● Profile 
● Match 
● Chat 
Profile has been INHERITED by Match which in turn has been INHERITED by Chat. 

# FUNCTIONS USED (FEATURES) 
A) Insert a new profile: It inserts the data of a new person.
![2](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/63364778-46a0-4272-9c5d-b890d1e0f290)

B) View Matches: It lists all the profiles of the opposite gender. 
![3](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/7204efdf-4e5c-43bf-bf02-abb34a13bba5)

C) Search profiles: It searches a particular profile using the name. It shows a NOT FOUND message if the profile doesn’t exist.
![4](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/387f35c5-dea1-4a75-b6c1-6b35ffff4677)

D) Edit profile: It edits the information of any existing profile. It also prints NOT FOUND if the profile of that name doesn’t exist. 
![5](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/f0ed5f48-d3be-48f3-86cf-a58692401582)

E) Edit preferences: It edits the preference section of any profile entered by the user. 

F) Delete profile: It deletes a particular profile entered by the user.
![6](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/707b975d-b618-4af7-8b74-4276bcab59fd)

G) Send chat message: It sends a chat message. 
![7](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/e9620b2f-c75a-4ef8-a55f-64815818e00b)

H) View chat history: It shows the chat history of the users entered. 
![8](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/f42e72b2-b8de-4119-a8c2-47df954ed655)

I) Clear all chats: It clears all the chat history in the database.

J) View all profiles: It lists all the profiles and their details in the database.
![9](https://github.com/idraakk/DATING_PLATFORM_C-C-_SEM2PROJ/assets/73667258/ecdcc44e-a97a-4d6b-8c74-92976f16eb6a)

K) Delete all profiles: It clears all the database (file) of the profiles from the file.

L) Exit: It exits from the Match-Making Platform.

# Headers
iostream
fstream
string
vector
sstream
algorithm
stdio.h
conio.h
ctype.h
time.h

(note: conio.h works fine in winows but sometimes linux based distros and macOs don't support the library)




