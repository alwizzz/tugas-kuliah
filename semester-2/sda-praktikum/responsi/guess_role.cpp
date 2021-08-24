#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

typedef struct Node{
	string content;
	Node* L;
	Node* R;
} node;

void createTree( node** root );
void createMap( map<string, string>& desc );
string guessRole( node* ptr );
string searchMap( map<string, string>& desc, string key );

int main( void ){
	
	node* root = NULL;
	createTree( &root );
	
	map<string, string> description;
	createMap(description);
	
	cout << "==>> MMORPG ROLE's GUESSER <<==" << endl << endl;
	cout << "This program will ask you several YES/NO questions and then it will guess your role based on your answers." << endl;
	cout << "The roles are based on MMORPG games's role." << endl;
	
	cout << "\n::Type 1 for YES and other for NO::" << endl << endl;
	
	string role = guessRole( root );
	
	cout << "================================================================================================================" << endl;
	cout << "Your role is " << role << endl;
	cout << "Description: " << searchMap( description, role ) << endl;
	cout << "================================================================================================================" << endl;
	
}

void createTree( node** root ){
	
	(*root) = new node;
	(*root)->content = "Do you like being highlighted?";
	
	(*root)->L = new node;
	(*root)->L->content = "Do you like to fight enemies head-on?";
	(*root)->R = new node;
	(*root)->R->content = "Are you willing to carry burden for your team?";
	
	(*root)->L->L = new node;
	(*root)->L->L->content = "Do you like being agile and get an advantageous position?";
	(*root)->L->R = new node;
	(*root)->L->R->content = "Do you like to outnumber the enemies?";
	(*root)->R->L = new node;
	(*root)->R->L->content = "[TANK]";
	(*root)->R->L->L = NULL;
	(*root)->R->L->R = NULL;
	(*root)->R->R = new node;
	(*root)->R->R->content = "Do you like complicated mechanic?";
	
	(*root)->L->L->L = new node;
	(*root)->L->L->L->content = "[ASSASSIN]";
	(*root)->L->L->L->L = NULL;
	(*root)->L->L->L->R = NULL;
	(*root)->L->L->R = new node;
	(*root)->L->L->R->content = "[WARRIOR]";
	(*root)->L->L->R->L = NULL;
	(*root)->L->L->R->R = NULL;
	(*root)->L->R->L = new node;
	(*root)->L->R->L->content = "[SUMMONNER]";
	(*root)->L->R->L->L = NULL;
	(*root)->L->R->L->R = NULL;
	(*root)->L->R->R = new node;
	(*root)->L->R->R->content = "[SPELLCASTER]";
	(*root)->L->R->R->L = NULL;
	(*root)->L->R->R->R = NULL;
	(*root)->R->R->L = new node;
	(*root)->R->R->L->content = "[BUFFER]";
	(*root)->R->R->L->L = NULL;
	(*root)->R->R->L->R = NULL;
	(*root)->R->R->R = new node;
	(*root)->R->R->R->content = "[HEALER]";
	(*root)->R->R->R->L = NULL;
	(*root)->R->R->R->R = NULL;	
	
}

void createMap( map<string, string>& desc ){
	
	desc.insert( pair <string, string> ("[WARRIOR]", "You are a simple person. You prefer being straightforward if possible.") );
	desc.insert( pair <string, string> ("[ASSASSIN]", "You like being swift. You don't like monotonous pattern.") );
	desc.insert( pair <string, string> ("[SUMMONNER]", "You somewhat adore a \"boss\" position. You find \"killing without touching\" is elegant.") );
	desc.insert( pair <string, string> ("[SPELLCASTER]", "You are a stylish person. You somewhat appreciate art") );
	desc.insert( pair <string, string> ("[TANK]", "You are a friendly person. You like the feeling of being relied by your friend") );
	desc.insert( pair <string, string> ("[BUFFER]", "You are a critical thinker. You love to utilize your skills to get the best impact for your team") );
	desc.insert( pair <string, string> ("[HEALER]", "You care about people. You are willing to sacrifice yourself for team's sake if you had to.") );
	
}

string guessRole( node* ptr ){
	
	string answer;
	string product;
	if( ptr->L != NULL && ptr->R != NULL ){
		cout << ptr->content << endl;
		cout << "? ";
		cin >> answer;
		cout << endl;
		
		if( answer=="1" )
			product = guessRole( ptr->L );
		else
			product = guessRole( ptr->R );
		
		return product;
	}
	
	else
		return ptr->content;
	
}

string searchMap( map<string, string>& desc, string key ){
	
	map<string, string>::iterator itr;
	
	bool found = 0;
	for( itr = desc.begin(); itr != desc.end(); itr++){
		if( itr->first==key ){
			found = 1;
			break;
		}
	}
	
	if( found )
		return itr->second;
	else
		return "No matching role";
}
