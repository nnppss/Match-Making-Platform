#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

using namespace std;

// forward declaration of classes
class Profile;
class Match;
class Chat;

// structure for user profile
struct UserProfile {
    string name;
    string age;
    string gender;
    string preferences;
    string bio;
};
// Class definitions
class Profile {
    public:

        //vector
        vector<UserProfile> getAllProfiles()
        {
        vector<UserProfile> profiles;
        ifstream profileFile("profiles.txt");
        string line;

        while (getline(profileFile, line))
            {
            UserProfile userProfile1;
            stringstream ss(line);
            string token;

            getline(ss, userProfile1.name, ',');
            getline(ss, userProfile1.age, ',');
            getline(ss, userProfile1.gender, ',');
            getline(ss, userProfile1.preferences, ',');
            getline(ss, userProfile1.bio, ',');

            profiles.push_back(userProfile1);
            }

        profileFile.close();
        return profiles;
        }


        //display function
        void displayProfile(UserProfile &userProfile) {
        cout << "\n\t\t\t\t\t\tName: " << userProfile.name << endl;
        cout << "\t\t\t\t\t\tAge: " << userProfile.age << endl;
        cout << "\t\t\t\t\t\tGender: " << userProfile.gender << endl;
        cout << "\t\t\t\t\t\tPreferences: " << userProfile.preferences << endl;
        cout << "\t\t\t\t\t\tBio: " << userProfile.bio << endl;
        }



        void createNewProfile()
        {

        system("cls");
        UserProfile userProfile;
        ofstream profileFile("profiles.txt", ios::app);

        cout << "\t\t\tEnter your name: ";
        cin>>userProfile.name;
        cout << "\t\t\tEnter your age: ";
        cin>>userProfile.age;
        cout << "\t\t\tEnter your gender (M/F): ";
        cin>>userProfile.gender;
        cout << "\t\t\tEnter your preferences: ";
        cin>>userProfile.preferences;
        cout << "\t\t\tEnter your bio: ";
        cin>>userProfile.bio;

        profileFile << userProfile.name << "," << userProfile.age << "," << userProfile.gender << "," << userProfile.preferences << "," << userProfile.bio << endl;
        profileFile.close();


            cout<<"\n\n\t\t\t-----------------------------------------------------------------\n";
            cout <<"\t\t\t"<<userProfile.name<<"'s Profile has been put into the Database for MATCHMAKING\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            displayProfile(userProfile);
            cout<<"\n\t\t\t-----------------------------------------------------------------\n";
            cout<<"\t\t\t                   Press any key to continue\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            getch();
            system("cls");
        }



        void viewMatches()
        {
            // implementation goes here
            vector<UserProfile> profiles = getAllProfiles();
            string currentUserGender;
            cout << "Enter your gender (M/F): ";
            cin >> currentUserGender;

            for (UserProfile &profile : profiles) {
                if (profile.gender != currentUserGender) {
                    displayProfile(profile);
                    }
            }

            cout<<"\n\n\t\t\t                     All Matches displayed\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            cout<<"\t\t\t                   Press any key to continue\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            getch();
            system("cls");

        }


        void viewAllProfiles()
        {
            // implementation goes here
            vector<UserProfile> profiles = getAllProfiles();

            for (UserProfile &profile : profiles)
                {
                    displayProfile(profile);
                }

            cout<<"\n\n\t\t\t                     All Profiles displayed\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            cout<<"\t\t\t                   Press any key to continue\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            getch();
            system("cls");

        }

        void updateProfile()
         {
            // implementation goes here

            int f=0,i;
            string oldUsername;
            cout << "Enter your old name: ";
            cin>>oldUsername;


        string searchName;
        searchName=oldUsername;

        vector<UserProfile> profiles = getAllProfiles();
        bool found = false;
        for (UserProfile &profile : profiles)
            {
            if (profile.name == searchName)
                {
                found = true;
                displayProfile(profile);
                cout << "Enter your new name: ";
                cin>>profile.name;
                cout << "Enter your new age: ";
                cin>> profile.age;
                cout << "Enter your new gender: ";
                cin>>profile.gender;
                cout << "Enter your new preferences: ";
                cin>>profile.preferences;
                cout << "Enter your new bio: ";
                cin>>profile.bio;
                f=1;
                }
            if(f==1) break;
            }

            if (found)
                {
                // Update the profiles.txt file
                ofstream profileFile("profiles.txt", ios::trunc);
                for (UserProfile &profile : profiles)
                    {
                    profileFile << profile.name << "," << profile.age << "," << profile.gender << "," << profile.preferences << "," << profile.bio << endl;
                    }
                profileFile.close();
                cout<<"\n\n\t\t\t                  PROFILE EDITED SUCCESSFULLY\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }
            else {
                cout<<"\n\n\t\t\t                  PROFILE NOT FOUND\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }

         }


        void deleteAllProfiles()
        {
            string deleteline;
            string line;

            ifstream fin;
            fin.open("profiles.txt");
            ofstream temp;
            temp.open("temp.txt");

            temp.close();
            fin.close();
            remove("profiles.txt");
            rename("temp.txt","profiles.txt");
            cout<<"\n\n\t\t\t                  ALL PROFILES DELETED SUCCESSFULLY\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
           // ifstream inputFile("profiles.txt");
           // ofstream tempFile("temp.txt", ios::out);
           // remove("profiles.txt");
           // rename("temp.txt", "profiles.txt");
        }


        void deleteProfile()
        {
            // implementation goes here

            string searchName;
            cout << "Enter the name of the profile to delete: ";
            cin.ignore();
            getline(cin, searchName);

            vector<UserProfile> profiles = getAllProfiles();
            auto it = remove_if(profiles.begin(), profiles.end(), [&searchName](UserProfile &profile) {
            return profile.name == searchName;
            });

            if (it != profiles.end())
                {
                profiles.erase(it);

                // Update the profiles.txt file
                ofstream profileFile("profiles.txt", ios::trunc);
                for (UserProfile &profile : profiles)
                    {
                    profileFile << profile.name << "," << profile.age << "," << profile.gender << "," << profile.preferences << "," << profile.bio << endl;
                    }
                profileFile.close();
                cout<<"\n\n\t\t\t                  PROFILE DELETED SUCCESSFULLY\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");

                }
            else
                {
                cout<<"\n\n\t\t\t                     PROFILE NOT FOUND\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");

                }

        }




        void editPreferences()
        {
            // implementation goes here
        int f=0;
        string searchName;
        cout << "Enter the name of the profile to edit preferences: ";
        cin>>searchName;

        vector<UserProfile> profiles = getAllProfiles();
        bool found = false;
        for (UserProfile &profile : profiles)
            {
            if (profile.name == searchName)
                {
                found = true;
                displayProfile(profile);
                cout << "Enter new preferences: ";
                cin>>profile.preferences;
                f=1;
                }
            if(f==1) break;
            }

            if (found)
                {
                // Update the profiles.txt file
                ofstream profileFile("profiles.txt", ios::trunc);
                for (UserProfile &profile : profiles)
                    {
                    profileFile << profile.name << "," << profile.age << "," << profile.gender << "," << profile.preferences << "," << profile.bio << endl;
                    }
                profileFile.close();
                cout<<"\n\n\t\t\t                  PREFERENCES EDITED SUCCESSFULLY\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }
            else {
                cout<<"\n\n\t\t\t                  PROFILE NOT FOUND\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }
        }

};

class Match : public Profile
{
    public:
        void searchForMatches()
        {
            int f=0;
            // implementation goes here
            string searchName;
            cout << "Enter the name of the profile to search: ";
            cin>>searchName;

            vector<UserProfile> profiles = getAllProfiles();
            for (UserProfile &profile : profiles)
            {
                if (profile.name == searchName)
                    {
                        cout<<"\n\n\t\t\t\t\t\t"<<profile.name<<" FOUND\n\n";
                        displayProfile(profile);
                        cout<<"\t\t\t-----------------------------------------------------------------\n";
                        cout<<"\t\t\t                   Press any key to continue\n";
                        cout<<"\t\t\t-----------------------------------------------------------------\n";
                        getch();
                        system("cls");

                        f=1;
                        break;
                    }
            }
            if(f!=1)
            {
                cout<<"\n\n\t\t\t                        NO MATCH FOUND!\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
            }
        }

};

class Chat : public Match
{
    public:

        void sendChatMessage(const string &sender, const string &recipient, const string &message)
        {
            ofstream chatFile("chats.txt", ios::app);

            if (!chatFile.is_open())
                {
                cout<<"\t\t\t              Error: Unable to open chat history file\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                return;
                }

            chatFile << sender << "\n" << recipient << "\n" << message << "\n";
            chatFile.close();
                cout<<"\t\t\t                            CHAT SENT\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
        }

        void viewChatHistory(const string &sender, const string &recipient)
        {
            ifstream chatFile("chats.txt");
            string chatSender, chatRecipient, message;

            if (!chatFile.is_open())
                {
                cout<<"\n\n\t\t\t         Error: Unable to open chat history file\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                return;
                }

            cout << "\nChat history between " << sender << " and " << recipient << ":\n\n";
            while (getline(chatFile, chatSender) && getline(chatFile, chatRecipient) && getline(chatFile, message))
                {
                if ((chatSender == sender && chatRecipient == recipient) || (chatSender == recipient && chatRecipient == sender))
                    {
                    cout << chatSender << " to " << chatRecipient << ": " << message << endl;
                    }
                }
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            cout<<"\t\t\t                   Press any key to continue\n";
            cout<<"\t\t\t-----------------------------------------------------------------\n";
            getche();
            system("cls");

            chatFile.close();
        }



        void clearAllChat()
        {
        ofstream chatFile("chats.txt", ios::trunc);

        if (!chatFile)
            {
            cerr<<"\n\n\n\t\t\t                Error: Unable to open chat file\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
            return;
            }

        chatFile.close();
        system("cls");
                cout<<"\n\n\n\t\t\t                All chat history has been cleared!\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
        }
};

// main function
int main()
{
    string sender, recipient, message;
    time_t t;
	time(&t);
    char choice;
    Profile profile;
    Match match;
    Chat chat;

do {
        // display the menu
        cout << "======================================================================================================================\n";
        cout << "||                            W E L C O M E     T O     I N K     D A T I N G     P L A T F O R M                   ||\n";
        cout << "======================================================================================================================\n\n";
        cout << "|| ************************************************  |MAIN MENU|  **********************************************    ||\n\n";
        cout << "======================================================================================================================\n";
        cout << "||                                               Please select an option                                            ||\n";
        cout << "======================================================================================================================\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 A) Insert a new profile               ||                 G) Send chat message                    ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 B) View matches                       ||                 H) View chat history                    ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 C) Search profiles                    ||                 I) Clear all chats                      ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 D) Edit profile                       ||                 J) View all profile                     ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 E) Edit preferences                   ||                 K) Delete all profiles                  ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "||                 F) Delete profile                     ||                 L) Exit                                 ||\n";
        cout << "||                                                       ||                                                         ||\n";
        cout << "======================================================================================================================\n";
        printf("                                                                      Current date and time : %s",ctime(&t));

        // read user input
        choice=getche();
        choice=toupper(choice);
        char ch;

        switch(choice)
        {
            case 'A':
                system("cls");
                profile.createNewProfile();
                break;

            case 'B':
                system("cls");
                profile.viewMatches();
                break;
            case 'C':
                system("cls");
                match.searchForMatches();
                break;

            case 'D':
                system("cls");
                profile.updateProfile();
                break;

            case 'E':
                system("cls");
                profile.editPreferences();
                break;
            case 'F':
                system("cls");
                profile.deleteProfile();
                break;

            case 'G':
                system("cls");
                cout << "Enter your name: ";
                cin>>sender;

                cout << "Enter the recipient's name: ";
                cin>>recipient;

                cout << "Enter your message: ";
                cin>>message;

                chat.sendChatMessage(sender, recipient, message);
                break;

            case 'H':
                system("cls");
                cout << "Enter your name: ";
                cin>>sender;

                cout << "Enter the recipient's name: ";
                cin>>recipient;

                chat.viewChatHistory(sender, recipient);
                break;

            case 'I':
                system("cls");
                cout<<"\n\n\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t              ARE YOU SURE YOU WANT TO DELETE ALL CHATS?\n";
                cout<<"\t\t\t                                Y/N\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                ch=getche();
                ch=toupper(ch);
                system("cls");
                if(ch=='Y')
                {
                chat.clearAllChat();
                }
                else
                {
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                        CHATS NOT DELETED\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }
                break;

            case 'J':
                system("cls");
                profile.viewAllProfiles();
                break;

            case 'K':
                system("cls");
                cout<<"\n\n\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t           ARE YOU SURE YOU WANT TO DELETE ALL PROFILE DATA?\n";
                cout<<"\t\t\t                                Y/N\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                ch=getche();
                ch=toupper(ch);
                system("cls");
                if(ch=='Y')
                {
                profile.deleteAllProfiles();
                }
                else
                {
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                       PROFILES NOT DELETED\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
                }
                break;

            case 'L':
                system("cls");
                cout<<"\n\n\n\t\t\t              Thank you for using the Dating Platform!\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");

                break;

            default:
                system("cls");
                cout<<"\n\n\n\t\t\t            Invalid choice. Please try again\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                cout<<"\t\t\t                   Press any key to continue\n";
                cout<<"\t\t\t-----------------------------------------------------------------\n";
                getch();
                system("cls");
            }
        } while (choice != 'L');

return 0;
}

