#include <iostream>
#include <string>
using namespace std;

const int numSong = 150;
string titles[numSong];
string artists[numSong];
int savedSongs = 0;
string playlist; 
string name;

void createSong(){
    if (savedSongs < numSong){
        cout << "Enter song title: ";
        cin.ignore();
        getline(cin, titles[savedSongs]);
        cout << "Enter artist's name: ";
        getline(cin, artists[savedSongs]);
        savedSongs++;
        cout << "Added to " << playlist << endl;
    } else {	
        cout << "Oops! The playlist is full. Try deleting a song to make space." << endl;
    }
}

void readSong(){
    if(savedSongs == 0) {
        cout << "It looks like your playlist is empty. Add some songs to get started! \n";    
    } else {
        cout << "\n--- " << name << "'s " << playlist << " ---\n";
        for (int i = 0; i < savedSongs; i++) {
            cout << i + 1 << ". " << titles[i] << " by " << artists[i] << endl;
        }
    }
}

void updateSong(){
    int index;
    readSong();
    if(savedSongs == 0) return;
    
    cout << "Enter the number of the song you want to update: ";
    cin >> index;
    
    if(index > 0 && index <= savedSongs){
        index--;
        cout << "Enter new title: ";
        cin.ignore();
        getline(cin, titles[index]);
        cout << "Enter new artist: ";
        getline(cin, artists[index]);
        cout << "Song updated successfully!\n";
    } else {
        cout << "Song " << index + 1 << " does not exist.\n";
    }
}

void deleteSong(){
    int index;
    readSong();
    if(savedSongs == 0) return;
    
    cout << "Enter the number of the song you want to delete: ";
    cin >> index;
    
    if(index > 0 && index <= savedSongs){
        index--;
        cout << "Are you sure you want to delete \"" << titles[index] << "\" by " << artists[index] << "? (y/n): ";
        char confirm;
        cin >> confirm;
        if(confirm == 'y' || confirm == 'Y') {
            for(int i = index; i < savedSongs - 1; i++) {
                titles[i] = titles[i + 1];
                artists[i] = artists[i + 1];
            }
            savedSongs--;
            cout << "Song removed from playlist.\n";
        } else {
            cout << "Deletion canceled.\n";
        }
    } else {
        cout << "Song " << index + 1 << " does not exist.\n";
    }
}

void menu(){
    cout << "\n--- " << name << "'s " << playlist << " ---\n";
    cout << "1. Add a song to your playlist\n";
    cout << "2. View all songs\n";
    cout << "3. Update a song\n";
    cout << "4. Delete a song from your playlist\n";
    cout << "5. Exit\n";
    cout << "\nWhat would you like to do? ";
}

int main () {
    int option;
    
    cout << "Enter your username: ";
    getline(cin, name);
    
    cout << "Hello, " << name << "! What would you like to name your playlist? :) "; 
    getline(cin, playlist);
    
    do {
        menu();
        cin >> option;
        
        switch (option) {
            case 1:
                createSong();
                break;
            case 2:
                readSong();
                break;
            case 3:
                updateSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                cout << "Exiting playlist...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";    
        }
    } while(option != 5);
    
    return 0;
}

