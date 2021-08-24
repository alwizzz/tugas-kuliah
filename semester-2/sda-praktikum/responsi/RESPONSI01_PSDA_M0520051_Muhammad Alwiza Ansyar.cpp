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

typedef struct Part{
	string desc;
	string trait;
} part;

void createTree( node** root );
void createMap( map<string, part>& desc );
void whatIsMMORPG();
string guessRole( node* ptr );
void result( string role, map<string, part>& exp, bool mode );

int main( void ){
	
	node* root = NULL;
	createTree( &root );
	
	map<string, part> explanation;
	createMap( explanation );
	
	cout << "==>> MMORPG ROLE's GUESSER <<==" << endl << endl;
	cout << "This program will ask you several YES/NO questions and then it will guess your role based on your answers." << endl;
	cout << "The roles are based on MMORPG games's role." << endl;
	
	cout << "::Type 1 for YES and other for NO::" << endl << endl;
	
	string ans;
	bool familiar = true;
	cout << "Beforehand, are you familiar with MMORPG games?" << endl;
	cout << "? ";
	cin >> ans;
	cout << endl;
	if( ans!= "1" ){
		familiar = false;
		whatIsMMORPG();
	}
	
	cout << "!!! Questions !!!" << endl << endl;
	
	string role = guessRole( root );
	
	result( role, explanation, familiar );

	
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
	(*root)->L->R->L->content = "[SUMMONER]";
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

void createMap( map<string, part>& d ){
	
	part warrior;
	warrior.desc = " is a melee character that can deal significant physical damage, usually wear a full set of armor";
	warrior.trait = "You are a simple person. You prefer being straightforward if possible.";
	
	part assassin;
	assassin.desc = " is a melee character that can deal massive physical damage but usually hard to play and can easily be killed";
	assassin.trait = "You like being swift. You don't like monotonous pattern.";
	
	part summoner;
	summoner.desc = " is a character that can summon minion (can be animal or monster) and command them to fight";
	summoner.trait = "You somewhat adore a \"boss\" position. You find \"killing without touching\" is elegant.";
	
	part spellcaster;
	spellcaster.desc = " is a ranged character that cast magic for her use, usually position himself/herself at the back of fight";
	spellcaster.trait = "You are a stylish person. You somewhat appreciate art";
	
	part tank;
	tank.desc = " is a character that has a lot of Health Point (HP) pool, able to withstand lot of damage from enemies, and hard to be killed";
	tank.trait = "You are a friendly person. You like the feeling of being relied by your friend";
	
	part buffer;
	buffer.desc = " is a character that has a lot of skills that can give positive buff for allies and negative buff for enemies";
	buffer.trait = "You are a critical thinker. You love to utilize your skills to get the best impact for your team";
	
	part healer;
	healer.desc = " is a character that has skillset focused to heal allies, usually weak and easy to be killed";
	healer.trait = "You care about people. You are willing to sacrifice yourself for team's sake if you had to.";
	
	
	d.insert( pair <string, part> ("[WARRIOR]", warrior) );
	d.insert( pair <string, part> ("[ASSASSIN]", assassin) );
	d.insert( pair <string, part> ("[SUMMONER]", summoner) );
	d.insert( pair <string, part> ("[SPELLCASTER]", spellcaster) );
	d.insert( pair <string, part> ("[TANK]", tank) );
	d.insert( pair <string, part> ("[BUFFER]", buffer) );
	d.insert( pair <string, part> ("[HEALER]", healer) );
	
}

void whatIsMMORPG(){
	cout << "MMORPG is the short of Massive Multiplayer Online Role Playing Game" << endl
		 << "Basically, you play a character with many other player and you build your character in such a way " << endl
		 << "that you will be having a role. The role is used as classification of what will you do in combat. " << endl
		 << "Players usually teamed up in a party to fight monsters and bosses and there the role is used." << endl << endl;
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

void result( string role, map<string, part>& exp, bool mode ){
	
	map<string, part>::iterator itr;
	bool found = false;
	for( itr = exp.begin(); itr != exp.end(); itr++){
		if( itr->first==role ){
			found = true;
			break;
		}
	}
	
	if( found ){
		cout << "================================================================================================================" << endl;
		cout << "Your role is " << role << endl;
		if( !mode )
			cout << "Desc\t: " << role << (itr->second).desc << endl;
		cout << "Trait\t: " << (itr->second).trait << endl;
		cout << "================================================================================================================" << endl;
	}
	else
		cout << "Error occured (no matching role" << endl;
	
}
